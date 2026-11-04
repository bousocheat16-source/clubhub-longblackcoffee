# ADR-001 · Application types for ITC Club Hub
Version 1.0 · 2026-04-11· Status: Proposed· Deciders: @bousocheat16-source (Product Owner) , @Vathanabe (Scrum Master)

## User groups
| Group          | Device | Where | Connectivity | How often | Must never fail |
|----------------|--------|-------|--------------|-----------|-----------------|
| Students | Own phone, Android or iPhone (assumed) | Campus, home, between classes | Mobile data or campus Wi-Fi (assumed) | A few times a week, more before events (assumed) | Getting the schedule notification before an event, and registering for it |
| Organisers (club leaders + event organisers) | Own phone or tablet (assumed) | Club room, and the event door for QR check-in | Campus Wi-Fi may be weak at the door (assumed) | Several times a week while running events (assumed) | QR check-in at the door, so the attendance log is complete even without Wi-Fi |
| Administrators (ITC Administration) | Laptop or desktop (assumed) | Office | Stable (assumed) | Rarely: reports and oversight | Clean, correct analytics reports |

## Options
A. Native apps (Android + iOS)
B. PWA for students and organisers, the same web app opened on desktop by administrators
C. Responsive web app (no install, no offline support)
D. Cross-platform app (one codebase, e.g. Flutter or React Native)

## Weighted comparison (score 1-5 x weight)

| Criterion (weight) | why this weight | A. Native apps | B. PWA | C. Responsive web app | D. Cross-platform app |
|--------------------|-----------------|----------|-------|-------|------------------|
| Cost for our team in one semester (3) | 5 people; the C++ core takes most of our time, and the front ends must be designed now and buildable later | 1x3=3 | 4x3=12 | 5x3=15 | 2x3=6 |
| Reach (3) | Students are the main users and we reach them through Telegram channels and flyers, so no store install is a big plus | 3x3=9 | 5x3=15 | 5x3=15 | 3x3=9 |
| Offline check-in by student ID at the door (3) | The stakeholder list asks for automated attendance logs, and the door Wi-Fi may be unreliable, so the ID lookup must work from a cached roster | 5x3=15 | 4x3=12 | 1x3=3 | 4x3=12 |
| Reminders (2) | Students need schedule notifications, but e-mail can cover a weak push | 5x2=10 | 3x2=6 | 2x2=4 | 4x2=8 |
| Device flexibility for administrators (1) | 2-3 admins who use whatever device is at hand (office PC, laptop, phone), but only occasionally | 2x1=2 | 5x1=5 | 5x1=5 | 3x1=3 |
| **Total** | max possible = 5 x 12 = 60 | 3+9+15+10+2 = **39** | 12+15+12+6+5 = **50** | 15+15+3+4+5 = **42** | 6+9+12+8+3 = **38** |

Deal-breaker check: Option C (Responsive web app) fails the absolute deal-breaker because it cannot handle offline check-ins if campus Wi-Fi drops at the door. Option B (PWA) 
successfully passes because Service Workers can store a cached attendee roster locally on the phone.

## Decision
We choose **Option B: PWA for students and organisers, the same web app opened on desktop by administrators**. This satisfies our constraint for an offline roster while keeping our codebase unified.

## Consequences
+ One web-based codebase for students, organisers, and administrators drastically reduces engineering overhead for our 5-person team.
+ Service Workers allow gate controllers to run QR ticket lookups completely offline.
- iPhone users will only receive schedule reminders by push notification after manually installing the PWA; e-mail remain our fallback channel.
- Organisers must connect to local Wi-Fi to synchronize the fresh event manifest right before heading to disconnected door zones.

## Rejected options
* **A. Native apps:** Building three separate front ends (iOS, Android, desktop) is impossible for a 5-person team in one semester.
* **C. Responsive web app:** Offers zero offline capability, failing the door check-in constraint immediately when networks drop.
* **D. Cross-platform app:** Requires configuration overhead for mobile stores and a higher learning curve than straightforward web development.

## How the front ends reach the C++ core
The PWA and web dashboards will route actions to our application data logic via an **HTTP API (REST)**. While the production setup places the core behind a web framework layout, our current university lab constraints will utilize CLI calls to interact with the compiled C++ components directly.

