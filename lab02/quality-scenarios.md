# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-11-02 · Reviewed by (Scrum Master): __

## QAS-01 · Availability · written by @bousocheat16-source
| Part             | Content |
|------------------|---------|
| Source           | System overload (sudden traffic spike)       |
| Stimulus         | the Club Hub main process crashes due to memory exhaustion       |
| Environment      | start of the semester club fair, heavy concurrent access        |
| Artifact         | Club Hub core service and file-based data store       |
| Response         | watchdog service detects the crash and restarts the process; client UI displays "Reconnecting, please wait..."; partially completed registrations are safely rolled back       |
| Response measure  |service restored in < 5 minutes; monthly availability >= 99.5 %; 0 corrupted club or user records      |

## QAS-02 · Performance of check-in at the door · written by __
...

## QAS-03 · Usability · written by @Choulita
| Part             | Content                                                    |
|------------------|------------------------------------------------------------|
| Source           | A student who has never used Club Hub before.              |
| Stimulus         | Wants to sign up for a club event they just heard about.   |
| Environment      | Registration has just opened; on their own phone over campus Wi-Fi; no tutorial, nobody to ask.       |
| Artifact         | The registration pages: event list, event page, confirmation screen.                                       |
| Response         | They find the event, register, and can tell straight away whether they got a seat or are on the waiting list.        |
| Response measure | >= 5 taps from home to registration complete, >= 60 seconds from start to finish; at least 9 out of 10 test students manage it first try without asking for help.      |

## QAS-06 · Portability · written by __

## Priorities
| Scenario | Business importance | Technical risk | Protects | First? |
|----------|---------------------|----------------|----------|--------|
| QAS-01   | High               |  Moderate             | Data/Time Logs       | Yes       |
| QAS-02   |                         |                     |                                 |           |
| QAS-03   | Moderate                | Low                 | Registration flow for students  | No        |

## QAS-05 · Modifiability · written by @lyfang519
| Part             | Content                                        |
|------------------|------------------------------------------------|
| Source           | a developer of the team                        |
| Stimulus         | adds the waiting list (a should feature): a full event puts new registations in status|
| Enviroment       | Design time, after Sprint1, core already tested |
| Artifact         | RegistrationService, Registration(include/clubhub/)|
| Response         | Change made is the core only, the user interface gains the waitlist display, existing behaviour unchanged |
| Response measure | done in less than 2 person-day, less than 4 files changed under core modules, 0 changes in UI/entry-point files |
