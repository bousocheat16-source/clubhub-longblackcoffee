# AI feature proposal: "Recommended for you"
Version 0.1 · 2026-11-20 · Authors: Be Sovanntheavathana, Bou Socheat, Leng Choulita, Sron Lyfang, Sarim Sereyboth

## 1 Problem and non-personalised baseline

### User problem
As more student clubs publish workshops, competitions, and social meetups on **ITC Club Hub**, students face a crowded chronological list of upcoming events. Without filtering or prioritisation, students either miss relevant sessions hosted by clubs they have not joined yet or have to manually check individual club pages to find events matching their interests.

### Non-personalised baseline
Before building a personalised recommendation feature, a rule-based, non-personalised baseline can address much of this discovery problem without tracking individual attendance histories:
* **Events of my clubs (up to 3 slots):** Upcoming events from clubs in the student's active `clubMemberships` (`data/memberships.csv`), ordered chronologically by start date.
* **Popular this week (remaining slots, up to 5 total):** Upcoming events ranked by overall registration/RSVP volume across students over the past 7 days, excluding events the student has already registered for.

### What the baseline solves vs. what remains unsolved
* **Solved without personal profiling:** Surfaces active club events and campus-wide trending events using existing membership and aggregate registration counts rather than individual attendance tracking.
* **Remaining gap:** Does not surface relevant upcoming events from clubs outside the student's current memberships or infer topic preferences beyond explicit club joins.

---

## 2 Data needed

| Field | Source | In inventory? | New purpose / consent? | Minimisation |
|-------|--------|---------------|------------------------|--------------|
| `studentId` (pseudonymised / internal lookup only) | `data/students.csv` | Yes | **Yes** — currently used to identify students and block double registration; personalised recommendations require opt-in consent. | Never expose `name`, `email`, or `phone`; keep `studentId` masked in non-admin/non-self views and redact in logs. |
| `attendance` (individual check-ins / event history) | `data/registrations.csv` | Yes | **Yes** — currently used for room capacity planning and semester reports with individual check-ins purged at semester end; reuse for recommendations requires opt-in consent. | Restrict to a rolling **12-month** window (or current semester if semester-end purge is kept); do not use `name`, `email`, `phone`, `dateOfBirth`, or `photo`. |
| `clubMemberships` (active joined clubs) | `data/memberships.csv` | Yes | **Partial** — already powers *My clubs* and member-only event eligibility; using it in recommendation scoring is a secondary use covered by recommendation opt-in. | Read active memberships only; since memberships are deleted immediately when a student leaves a club, no stale membership history is retained. |
| Event & club catalog metadata (`eventId`, `clubId`, category/topic tags, event date, club member count) | Event & club catalog tables | Partial (catalog/club metadata outside student PII table) | **No** — public event and club listing metadata used to display and organise events. | Use structured category/topic tags and club size only; exclude free-text notes and keep personal contact details out. |
| `derivedInterestProfile` (category affinity weights per opted-in user) | Recommendation scoring process (new) | **No** (new derived data) | **Yes** — new personal preference profile created solely for "Recommended for you"; requires explicit opt-in. | Store only minimal category/club affinity weights; delete within **24 hours** when the student switches recommendations off. |

### Task 1 decisions that would change
If "Recommended for you" is approved, the following decisions in `data-inventory.md` (Version 2.0) would need to be updated
1. **`attendance` retention and aggregation rule:** Currently, individual check-ins in `data/registrations.csv` are purged at semester end and only club totals are kept for room capacity and semester reports. Supporting a 12-month attendance window for opted-in recommendations would require revising that retention/purge rule or limiting history to the active semester.
2. **Inventory & purpose scope:** Add `derivedInterestProfile` to the data inventory and record "Recommended for you" as an optional, opt-in purpose for `studentId`, `clubMemberships`, and eligible `attendance` data
3. **Deletion & log handling:** Add a deletion rule removing `derivedInterestProfile` within 24 hours of opting out, and ensure recommendation evaluation/debug logs follow the `redacted()` rule with no `name`, `email`, or `phone`

---

## 3 Bias risks

| Risk | Who is harmed | Mitigation | Fairness check (metric, threshold) |
|------|---------------|------------|------------------------------------|
| **1. Cold-start bias (no attendance or membership history)** | New students, first-year students, and students with no recorded check-ins receive blank, sparse, or irrelevant suggestions. | Fall back to the non-personalised baseline (`Events of my clubs` + `Popular this week`) when a student has no attendance history or few data points. | **Coverage & click parity:** 100% of opted-in zero-history users receive 5 valid upcoming events, and their click-through rate (CTR) is at least **75%** of returning users' CTR. |
| **2. Popularity feedback loop** | Smaller, newer, or niche clubs and less-hyped events get fewer views/RSVPs because high-RSVP events keep getting promoted. | Reserve **at least 2 of the 5 slots** for clubs the student has never attended and dampen raw RSVP popularity counts in ranking. | **Unvisited-club slot share:** At least **40%** (2 of 5 slots on average) of recommended items come from clubs the student has not previously attended. |
| **3. Attendance as a proxy for time, money, distance, or accessibility** | Students with part-time jobs, longer commutes, financial constraints, or accessibility needs who attend fewer events risk being treated as low-interest or getting poorer recommendations. | Do not penalise low attendance counts; surface accessible, free, and on-campus events fairly rather than assuming low attendance means disinterest. | **Low-activity group parity:** Opted-in students with 1–2 check-ins receive 5 valid recommendations (100% fill rate) with an RSVP/save rate within **20 percentage points** of more frequent attendees. |
| **4. Large clubs crowding out small clubs** | Small clubs (fewer than 20 members) are overshadowed by large clubs that run frequent or high-headcount events. | Limit recommendations to **at most 1 event per club** in a 5-item list and apply club-size balancing during ranking. | **Small-club exposure check:** Monthly check showing clubs with **fewer than 20 members** receive **at least 80% of their fair share** of recommendations relative to their share of events. |

## 4 Transparency

### "Why am I seeing this?" example
Displayed when a student clicks the **Why this event?** info icon next to a recommended event:

> **Event:** `E-024 · Intro to Linux & Shell Scripting` (Open Source Club · 2026-11-28 17:30)
>
> **Why am I seeing this?**
> - You attended 2 recent events tagged **Software & Tools** this semester.
> - This event fills one of your **new-club discovery slots** (you have not attended an Open Source Club event yet).
> - Registration is currently open and free on campus.
>
> *Not interested or want to turn off personalisation? Manage this anytime in **My Profile → Privacy & Preferences**.*

### Ranking inputs (published by the Clubs Office)
The Clubs Office can publish the following plain-language summary on the Club Hub help page:

> **How "Recommended for you" works**
> When you turn on personalised recommendations, Club Hub picks 5 upcoming events using four inputs:
> 1. **Your club memberships:** Upcoming events from clubs you currently belong to.
> 2. **Your recent attendance topics:** Event category tags (such as *Robotics*, *Design*, or *Sports*) from check-ins you completed while opted in.
> 3. **Discovery & fairness balance:** At least 2 of the 5 slots are reserved for clubs you have not visited yet, with at most 1 event per club and a boost so smaller clubs are not crowded out.
> 4. **Weekly campus activity:** Aggregate registration counts from the past 7 days (used only as a tie-breaker and for new students without history).
>
> **What we never use:** Your name, email, phone number, academic grades, or personal demographics are never used to rank events.

---

## 5 Opt-in and opt-out design

### Default setting and justification
- **Default:** **Opt-in (OFF by default).**
- **Justification:** Consistent with our Lab-03 consent rules (`lab03/consent-flow.mmd`), optional data processing must never be pre-selected. Leaving personalisation OFF by default respects data minimisation and ensures no student's attendance history is profiled without clear agreement. Students who leave it OFF still receive the useful non-personalised baseline (*Events of my clubs* + *Popular this week*).

### Where the switch lives
- **Web / PWA:** `My Profile → Privacy & Preferences → Personalised event recommendations` (single toggle switch, OFF by default).
- **CLI:** `clubhub prefs --recommendations on|off` (and an optional prompt defaulting to `no` during `clubhub register`).

### What happens when a student switches it off
1. **Immediate UI fallback:** Personalised ranking stops immediately; the student's home screen switches back to the non-personalised baseline (*Events of my clubs* + *Popular this week*).
2. **Derived data deletion:** The student's `derivedInterestProfile` record is queued for deletion and permanently removed within **24 hours**.
3. **Raw attendance untouched for core service:** Existing attendance records in `data/registrations.csv` are no longer read by the recommender and continue following the standard semester-end purge rule.
4. **Confirmation:** The interface displays a plain-language confirmation stating that personalised recommendations are off and derived preference data is scheduled for deletion.

### Opt-out flow
```mermaid
flowchart LR
    A["My Profile: Privacy & Preferences<br/>(or CLI: clubhub prefs --recommendations off)"] --> B{"Recommendations<br/>switch"}
    B -- "ON (explicit opt-in)" --> C["Build/update derivedInterestProfile<br/>from opted-in history"]
    C --> D["Show 5 personalised events<br/>with 'Why am I seeing this?'"]
    B -- "OFF (default or withdrawn)" --> E["Stop personalised ranking immediately"]
    E --> F["Queue deletion of derivedInterestProfile<br/>(purged within 24 hours)"]
    F --> G["Fall back to non-personalised baseline<br/>(My clubs + Popular this week)"]
    G --> H["Show confirmation:<br/>'Personalisation off; profile data deleted'"]
  ```
## 6 Recommendation
**Decision:** **GO WITH CONDITIONS** (Phase 1: ship the non-personalised baseline first; Phase 2: enable personalised recommendations only after all conditions below are met).

### Conditions for release
1. **Baseline-first validation:** Launch the non-personalised baseline (*Events of my clubs* + *Popular this week*) for one month first; only build the personalised recommender if students still report difficulty discovering relevant events.
2. **Strict opt-in and 24-hour purge:** Keep recommendations **OFF by default**, update `lab03/data-inventory.md` and `lab03/retention-rules.md` to cover `derivedInterestProfile`, and verify automated deletion within 24 hours of opting out.
3. **Privacy-safe logging:** Ensure all recommendation and audit logs use `Student::redacted()` and never output `name`, `email`, or `phone`.
4. **Fairness guardrails in code:** Enforce all four bias mitigations (cold-start fallback, max 1 event per club, ≥ 2 unvisited-club slots, and no penalty for low attendance) with automated unit tests before launch.
5. **Kill switch on fairness failure:** If any monthly fairness metric falls below its threshold (e.g., small-club exposure < 80% of fair share or unvisited-club share < 40%) for two consecutive months, automatically revert to the non-personalised baseline until fixed.

### Ownership of the fairness check after release
- **Primary Owner (Governance & Go/Pause Authority):** **Clubs Office Coordinator** (Product Owner), who reviews the monthly fairness report and decides whether the feature stays enabled or pauses.
- **Technical Owner (Measurement & Fixes):** **ITC Club Hub Maintainer / Lead Developer**, who runs the automated monthly fairness check script on anonymised/aggregate logs and delivers ranking adjustments if any threshold is missed.