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

| Criterion (weight) | why this weight | A. Native apps | B. PWA | C. Responsive web app | D. Cross-platform app |
|--------------------|-----------------|----------|-------|-------|------------------|
| Cost for our team in one semester (3) | 5 people; the C++ core takes most of our time, and the front ends must be designed now and buildable later | 1x3=3 | 4x3=12 | 5x3=15 | 2x3=6 |
| Reach (3) | Students are the main users and we reach them through Telegram channels and flyers, so no store install is a big plus | 3x3=9 | 5x3=15 | 5x3=15 | 3x3=9 |
| Offline check-in by student ID at the door (3) | The stakeholder list asks for automated attendance logs, and the door Wi-Fi may be unreliable, so the ID lookup must work from a cached roster | 5x3=15 | 4x3=12 | 1x3=3 | 4x3=12 |
| Reminders (2) | Students need schedule notifications, but e-mail can cover a weak push | 5x2=10 | 3x2=6 | 2x2=4 | 4x2=8 |
| Device flexibility for administrators (1) | 2-3 admins who use whatever device is at hand (office PC, laptop, phone), but only occasionally | 2x1=2 | 5x1=5 | 5x1=5 | 3x1=3 |
| **Total** | max possible = 5 x 12 = 60 | 3+9+15+10+2 = **39** | 12+15+12+6+5 = **50** | 15+15+3+4+5 = **42** | 6+9+12+8+3 = **38** |

Deal-breaker check: __

## Decision
## Consequences
+ __
+ __
- __
- __
## Rejected options
## How the front ends reach the C++ core
