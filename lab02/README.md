# Lab 02: Architectural Design, Core Data Structures, and CLI (03-11-2026)

## 1. File Table
List of files created or modified in lab 02:

| File Path | Description | Author |
| :--- | :--- | :--- |
| `lab02/app-classification.md` | Application type classification and rationale | @bousocheat16-source |
| `lab02/app-quadrant.mmd` | Mermaid quadrant chart for application classification | @bousocheat16-source |
| `lab02/adr-001-application-type.md` | Architectural Decision Record for chosen application type | @Vathanabe |
| `lab02/quality-scenarios.md` | Quality attribute scenarios and architectural tactics | @Vathanabe |
| `lab02/context-diagram.mmd` | C4 Context diagram source (Mermaid) | @bousocheat16-source |
| `lab02/context-diagram.png` | Exported C4 Context diagram graphic | @bousocheat16-source|
| `lab02/architecture.mmd` | C4 Component/Container diagram source (Mermaid) | @bousocheat16-source |
| `lab02/architecture.png` | Exported C4 architecture diagram graphic | @bousocheat16-source |
| `lab02/event.hpp` | Event entity core data structure declaration | @Sereyboth-cmd |
| `lab02/event_csv.hpp` | CSV parser header for Event entities | @Choulita |
| `lab02/event.cpp` | Event entity implementation | @Choulita |
| `lab02/event_csv.cpp` | CSV parser implementation for Event entities | @Sereyboth-cmd |
| `lab02/main.cpp` | List-events command-line interface driver | @Choulita |
| `lab02/events.csv` | Sample CSV data set for event execution | @sereyboth-cmd |
| `lab02/README.md` | Lab 02 summary, traceability, and changelog | @lyfang519 |

---

## 2. Inputs Reused Table
Lab 01 artifacts carried forward into Lab 02:

| Reused File Path | Description | Git Commit Hash |
| :--- | :--- | :--- |
| `lab01/team-charter.md` | Team communication agreements, norms, and roles | `git log -1 --format=%h -- lab01/team-charter.md` |
| `lab01/decisions.md` | Early architectural and technical decision logs | `git log -1 --format=%h -- lab01/decisions.md` |

---

## 3. Architecture Diagrams

### System Context Diagram
![C4 Context Diagram](context-diagram.png)

### Container / Component Diagram
![Architecture Diagram](architecture.png)

---

## 4. Change-Log
| Date | Version | Description | Author / Team |
| :--- | :--- | :--- | :--- |
| 2026-11-03 | 1.0 | Initial release of Lab 02 architecture, C4 diagrams, event core, and CLI | longblackcoffee |

