# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-11-02 · Reviewed by (Scrum Master): __

## QAS-01 · Availability · written by @bousocheat16-source
| Part             | Content |
|------------------|---------|
| Source           | Server Infrastructure        |
| Stimulus         | Main server or data storage crashes unexpectedly        |
| Environment      | App operation during busy days (eg. event registerations...)        |
| Artifact         | ITC Club Hub core and environment system       |
| Response         | The system logs the error, attempts to automatically restart, and displays a user-friendly "System In Maintenance" message rather than crashing the user's client.        |
| Response measure | System will only go down for less than 15 minutes, and all data will be restored 100%        |

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
| Response measure | Around 60 seconds from start to finish; at least 9 out of 10 test students manage it first try without asking for help.      |

## QAS-06 · Portability · written by __

## Priorities
| Scenario | Business importance | Technical risk | Protects | First? |
|----------|---------------------|----------------|----------|--------|
| QAS-01   | Important               |  Medium             | Data and Integrity logs         | Yes       |
| QAS-02   |                         |                     |                                 |           |
| QAS-03   | Moderate                | Low                 | Registration flow for students  |           |

## QAS-05 · Modifiability · written by @lyfang519
| Part             | Content                                        |
|------------------|------------------------------------------------|
| Source           | a developer of the team                        |
| Stimulus         | adds the waiting list (a should feature): a full event puts new registations in status|
| Enviroment       | Design time, after Sprint1, core already tested |
| Artifact         | RegistrationService, Registration(include/clubhub/)|
| Response         | Change made is the core only, the user interface gains the waitlist display, existing behaviour unchanged |
| Response measure | done in less than 2 person-day, less than 4 files changed under core modules, 0 changes in UI/entry-point files |
