# Lab 02: Architectural Design, Core Data Structures, and CLI

## 1. File Table
List of files created or modified in lab 02:

| File Path | Description | Author |
| :--- | :--- | :--- |
| `lab02/app-classification.md` | Application type classification and rationale | longblackcoffee |
| `lab02/app-quadrant.mmd` | Mermaid quadrant chart for application classification | longblackcoffee |
| `lab02/adr-001-application-type.md` | Architectural Decision Record for chosen application type | longblackcoffee |
| `lab02/quality-scenarios.md` | Quality attribute scenarios and architectural tactics | longblackcoffee |
| `lab02/context-diagram.mmd` | C4 Context diagram source (Mermaid) | longblackcoffee |
| `lab02/context-diagram.png` | Exported C4 Context diagram graphic | longblackcoffee |
| `lab02/architecture.mmd` | C4 Component/Container diagram source (Mermaid) | longblackcoffee |
| `lab02/architecture.png` | Exported C4 architecture diagram graphic | longblackcoffee |
| `lab02/event.hpp` | Event entity core data structure declaration | longblackcoffee |
| `lab02/event_csv.hpp` | CSV parser header for Event entities | longblackcoffee |
| `lab02/event.cpp` | Event entity implementation | longblackcoffee |
| `lab02/event_csv.cpp` | CSV parser implementation for Event entities | longblackcoffee |
| `lab02/main.cpp` | List-events command-line interface driver | longblackcoffee |
| `lab02/events.csv` | Sample CSV data set for event execution | longblackcoffee |
| `lab02/README.md` | Lab 02 summary, traceability, and changelog | longblackcoffee |

---

## 2. Inputs Reused Table
Lab 01 artifacts carried forward into Lab 02:

| Reused File Path | Description | Git Commit Hash |
| :--- | :--- | :--- |
| `lab01/team-charter.md` | Team communication agreements, norms, and roles | `<insert_commit_hash>` |
| `lab01/decisions.md` | Early architectural and technical decision logs | `<insert_commit_hash>` |

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
