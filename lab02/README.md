# Lab-02 · ITC Club Hub (v1.0, 2026-11-03)

## (a) Files of this lab

| File | Description | Main Author |
|------|-------------|-------------|
| `lab02/context-diagram.mmd` & `.png` | Context diagram showing stakeholders and external systems | @bousocheat16-source |
| `lab02/architecture.mmd` & `.png` | 3-tier architecture diagram mapping components to folders | @bousocheat16-source |
| `lab02/quality-scenarios.md` | Six quality attribute scenarios (Availability, Performance, etc.) | @bousocheat16-source |
| `include/clubhub/event.hpp` | Core Event class interface and time parsing definitions | @bousocheat16-source |
| `include/clubhub/event_csv.hpp` | CSV loading interface and error struct definitions | @Sereyboth-cmd |
| `src/event.cpp` | Event constructor validation and time parsing implementation | @bousocheat16-source |
| `src/event_csv.cpp` | CSV parsing and error handling implementation | @bousocheat16-source |
| `src/cli/main.cpp` | Command-line interface for the `list-events` command | @Choulita |
| `CMakeLists.txt` | CMake build configuration for core library and executable | @Sereyboth-cmd|
| `data/events.csv` | Sample event data including one intentionally invalid row | @Choulita |
| `lab02/README.md` | Documentation, file manifest, and embedded diagrams | @bousocheat16-source |

## (b) Inputs reused

| Reused File Path | Description | Git Commit Hash |
| :--- | :--- | :--- |
| `lab01/team-charter.md` | Team communication agreements, norms, and roles | `git log -1 --format=%h -- lab01/team-charter.md` |
| `lab01/decisions.md` | Early architectural and technical decision logs | `git log -1 --format=%h -- lab01/decisions.md` |

## (c) Diagrams

### Context Diagram
![Club Hub Context Diagram](context-diagram.png)

### Architecture Diagram
![Club Hub Architecture Diagram](architecture.png)

## (d) Change log

| Date | Version | Change | Commit By |
|------|---------|--------|-----------|
| 2026-11-03 | v1.0 | Event core logic, CSV loading, CLI list-events, and architecture diagrams | longblackcoffee |

![Club Hub Context Diagram](context-diagram.png)
![Club Hub Architecture Diagram](architecture.png)
