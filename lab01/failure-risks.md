# Failure risks · ITC Club Hub (v0.1, 2026-10-22)

| # | How the project could fail | Chapter 01 topic | Early warning sign | First countermeasure | Owner |
|---|----------------------------|------------------|--------------------|----------------------|-------|
| F1 | Scope creep from adding unnecessary features (like live chat or payment portals) delays core release. | Changing requirements and cost of change | Constant addition of new feature ideas in sprint planning meetings. | Freeze core feature set and establish a strict change request protocol. | Borith |
| F2 | Overly complex C++ data structures for club hierarchies cause frequent logic bugs and development bottlenecks. | Essential difficulties | Spaghetti code in file parsers and high bug rates during unit testing. | Draw full UML domain models and refactor into smaller, independent modules. | Sopheap |
| F3 | Poor team communication leads to integration conflicts between C++ backend and UI screen wireframes. | Scale and communication | Merge conflicts on Git and delayed module handoffs between developers. | Hold mandatory sync meetings twice a week and establish clear file interface contracts. | Cheata |
| F4 | CLI crashes or corrupts text/binary storage files when invalid input format is entered by users. | Reliability, security and safety | Unhandled exceptions and segfaults during boundary input testing. | Add strict input sanitization and try-catch blocks across all user input handlers. | Sothea |
| F5 | Rushing code delivery creates massive technical debt, making the C++ code unmaintainable by week 10. | Integration and technical debt | Accumulation of `// TODO` comments and skipped peer code reviews. | Set up mandatory peer pull request reviews and enforce clean code standards. | Visal |
