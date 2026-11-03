# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-11-02 · Reviewed by (Scrum Master): 2026-11-03

## QAS-01 · Availability · written by @bousocheat16-source
| Part             | Content |
|------------------|---------|
| Source           | System overload (sudden traffic spike)       |
| Stimulus         | the Club Hub main process crashes due to memory exhaustion       |
| Environment      | start of the semester club fair, heavy concurrent access        |
| Artifact         | Club Hub core service and file-based data store       |
| Response         | watchdog service detects the crash and restarts the process; client UI displays "Reconnecting, please wait..."; partially completed registrations are safely rolled back       |
| Response measure  |service restored in < 5 minutes; monthly availability >= 99.5 %; 0 corrupted club or user records      |

## QAS-02 · Performance of check-in at the door · written by @Vathanabe
| Part             | Content |
|------------------|---------|
| Source           | Club event organizer at the venue entrance |
| Stimulus         | Scans a student's QR code or digital ID to check them into the event |
| Environment      | Friday 18:00, peak door queue with 200 student arrivals in 10 minutes, single door entry point over venue Wi-Fi at 1 Mbps |
| Artifact         | The check-in handler component inside the registration service |
| Response         | Students status updates to CheckedIn, a green confirmation tick is displayed on the organizer's screen, and duplicate scans are automatically rejected with a clear warning message |
| Response measure | 95% of check-in requests are processed and confirmed within <= 1.0 seconds; sustained throughput >= 20 check-ins per minute per door (200 / 10 min = 20/min) |


## QAS-03 · Usability · written by @Choulita
| Part             | Content                                                    |
|------------------|------------------------------------------------------------|
| Source           | A student who has never used Club Hub before.              |
| Stimulus         | Wants to sign up for a club event they just heard about.   |
| Environment      | Registration has just opened; on their own phone over campus Wi-Fi; no tutorial, nobody to ask.       |
| Artifact         | The registration pages: event list, event page, confirmation screen.                                       |
| Response         | They find the event, register, and can tell straight away whether they got a seat or are on the waiting list.        |
| Response measure | >= 5 taps from home to registration complete, >= 60 seconds from start to finish; at least 9 out of 10 test students manage it first try without asking for help.      |

## QAS-04 · Security · written by @Sereyboth-cmd

| Part             | Content |
|------------------|---------|
| Source           | An authenticated but unauthorized ITC student operating an external automated script. |
| Stimulus         | The user attempts to scrape the full database of student phone numbers and attendance records by sending sequential, rapid API requests to the backend server endpoints. |
| Environment      | Normal operation, online during a high-traffic registration window on a mobile web connection. |
| Artifact         | The backend data store, specifically the `AttendanceRecord` and `StudentProfile` database entities containing Personally Identifiable Information (PII) (Full Names, ITC Student ID Numbers, and Phone Numbers). |
| Response         | The system detects the abnormal rate of sequential requests, blocks the malicious user's account session access token, refuses to reveal unauthorized query parameters, logs the unauthorized exposure attempt to an audit trail, and flags the account for administrator review. |
| Response Measure | 100% of unauthorized data requests are blocked; 0 student phone numbers or private data details are leaked to the client; the malicious account token is completely revoked within <= 1.5 seconds of detection; the system administrator receives a security notification alert in <= 5 minutes. |

## QAS-05 · Modifiability · written by @lyfang519
| Part             | Content                                        |
|------------------|------------------------------------------------|
| Source           | a developer of the team                        |
| Stimulus         | adds the waiting list (a should feature): a full event puts new registations in status|
| Enviroment       | Design time, after Sprint1, core already tested |
| Artifact         | RegistrationService, Registration(include/clubhub/)|
| Response         | Change made is the core only, the user interface gains the waitlist display, existing behaviour unchanged |
| Response measure | done in less than 2 person-day, less than 4 files changed under core modules, 0 changes in UI/entry-point files |

## QAS-06 · Portability · written by @bousocheat16-source
| Part             | Content |
|------------------|---------|
| Source           | ITC Administrator & Development Team     |
| Stimulus         | the Club Hub main process needs to compile the app and test run on a different OS      |
| Environment      | Switching from WindowsOS to MacOS or Ubuntu       |
| Artifact         | Club Hub C++ codebase and CMake building system       |
| Response         | Code can run natively on C++ codebase using CMake without needing any specific platform for source code rewrite       |
| Response measure  |successful build with 0 compilation errors;
             100% feature parity achieved on the new OS in < 2 hours      |

## Priorities
| Scenario | Business importance | Technical risk | Protects | First? |
|----------|---------------------|----------------|----------|--------|
| QAS-01   | High    |  Moderate   | Data/Time Logs       | NO      |
| QAS-02   | High   | High    |  Offline Attendance    | Yes          |
| QAS-03   | Moderate    | Low   | Registration flow for students  | No  |
| QAS-04   | High | Moderate | Data Privacy | Yes |
| QAS-05   | Moderate | Moderate | Developer Timeline | No | 
| QAS-06   | Low | Low | Operating System (OS) Flexibility | No |
