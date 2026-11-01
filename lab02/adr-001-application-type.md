# ADR-001 · Application types for ITC Club Hub
Version 1.0 · 2026-__-__ · Status: Proposed | Accepted (date) · Deciders: __

## User groups
| Group          | Device | Where | Connectivity | How often | Must never fail |
|----------------|--------|-------|--------------|-----------|-----------------|
| Students | Own phone, Android or iPhone (assumed) | Campus, home, between classes | Mobile data or campus Wi-Fi (assumed) | A few times a week, more before events (assumed) | Getting the schedule notification before an event, and registering for it |
| Organisers (club leaders + event organisers) | Own phone or tablet (assumed) | Club room, and the event door for QR check-in | Campus Wi-Fi may be weak at the door (assumed) | Several times a week while running events (assumed) | QR check-in at the door, so the attendance log is complete even without Wi-Fi |
| Administrators (ITC Administration) | Laptop or desktop (assumed) | Office | Stable (assumed) | Rarely: reports and oversight | Clean, correct analytics reports |

## Options
A. Native apps (Android + iOS)   B. PWA for students and organisers, the same web app opened on desktop by administrators   C. Responsive web app (no install, no offline support)   D. Cross-platform app (one codebase, e.g. Flutter or React Native)

## Weighted comparison (score 1-5 x weight)
| Criterion (weight) | why this weight | A | B | C | D |
|--------------------|-----------------|---|---|---|---|
| Cost for our team in one semester (_) | | | | | |
| Reach (_)                             | | | | | |
| Offline check-in at the door (_)      | | | | | |
| Reminders (_)                         | | | | | |
| Device flexibility for administrators (_)             | | | | | |
| **Total**                             | | = | = | = | = |

Deal-breaker check: __

## Decision
## Consequences
+ __
+ __
- __
- __
## Rejected options
## How the front ends reach the C++ core
