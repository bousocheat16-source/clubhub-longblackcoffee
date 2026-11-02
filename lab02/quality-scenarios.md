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
## QAS-06 · Portability · written by __

## Priorities
| Scenario | Business importance | Technical risk | Protects | First? |
|----------|---------------------|----------------|----------|--------|
| QAS-01   |                     |                |          |        |