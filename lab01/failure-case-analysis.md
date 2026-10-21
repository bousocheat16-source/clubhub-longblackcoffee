# Failure case analysis · <Mars Climate Orbiter> (v1.0, 2026-10-20)
Authors: Bou Socheat, Leng Choulita, Be Sovanntheavathana, Sron Lyfang, Sarim Sereyboth

## 1. Context

In December, 11, 1998. Nasa launch a robotic space probe "Mars Climate Orbiter" in partnership with Lockheed Martin Astronautics 
to study Mars' climate, atmosphere, and surface changes and to act as a communication relay equipments that was already on mars.
The software that control the thruster output had calculation errors causing the probe to descend too close the the planet and destroyed 
by its atmosphere.
This engineering disaster cost the organization $327.6 billion dollars in losses and it raised global awareness about the critical need
for strict unit standardization, rigorous software validation, and cross-organizational communication in complex engineering projects.

## 2. Timeline
| Date | Event |
|------|-------|

## 3. What failed
The Mars Climate Orbiter was lost because of a units mismatch in its ground software. The Software Interface Specification required thruster impulse data in newton-seconds, but the file was produced in pound-force seconds, so the navigation software underestimated each thruster firing by a factor of 4.45. The firings were also far more frequent than the navigators expected, because the spacecraft’s solar array was asymmetrical, so the error added up during the cruise and the real trajectory ended up much lower than the estimated one. As a result, the spacecraft lost contact during orbit insertion on 23 September 1999 (NASA MIB, 1999, pp. 7, 13, 16).

```mermaid
flowchart TD
  A["Ground software output in pound-force seconds, not newton-seconds as the SIS required"] --> B["Navigation software reads the AMD file as newton-seconds"]
  B --> C["Each thruster firing underestimated by a factor of 4.45"]
  C --> D["Error accumulates overcruise; trajectory estimate drifts"]
  D --> E["Orbiter reaches Mars on a much lower path (about 57 km periapsis vs 226 km planned)"]
  E --> F["Spacecraft lost during orbit insertion"]
```

## 4. Root causes
| # | Root cause | Type | Essential difficulty | Why |
|---|------------|------|----------------------|-----|
| R1 |           | technical / process / organisational | | |

## 5. Practices that would have prevented or limited it
| Root cause | Practice | Chapter |
|------------|----------|---------|

## 6. Lessons for ITC Club Hub
1.
2.

## 7. Sources
1. <author or organisation, title, year, URL> (primary)
