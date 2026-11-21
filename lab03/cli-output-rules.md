# CLI Output Accessibility Rules · ITC Club Hub

## Rule 1: Never rely on colour alone
Status values must always print as explicit bracketed words so screen readers, monochrome terminals, and colour-blind users receive the exact same information.
```text
  bad : E-017  Git Workshop      (shown in red)
  good: E-017  Git Workshop      [CANCELLED]
```
## Rule 2: Honour NO_COLOR and the --no-color flag
When the NO_COLOR environment variable is set or the user passes --no-color, omit all ANSI escape sequences and output plain text.
```text
  bad : Always printing "\033[31m[CANCELLED]\033[0m" even when piped to a log file or with NO_COLOR=1
  good: Checking colourEnabled(noColorFlag) and outputting plain "[CANCELLED]" when colour is disabled
```
## Rule 3: Errors say what failed, why, and the next step
Every error message must explain the failed action, the exact cause, and a concrete recovery command.
```text
  bad : ERR_CAP
  good: Error: cannot register for E-017: the event is full (40 of 40 seats).
  Next step: clubhub waitlist E-017
```
## Rule 4: Return a non-zero exit code on error and write to stderr
Failed commands must write diagnostic messages to std::cerr and return a non-zero status code so scripts and assistive tools can detect failures reliably.
```text
  bad : Printing "cannot open file" to std::cout and returning 0
  good: Printing the error to std::cerr and returning exit code 1 or 2
```
## Rule 5: Prompts and usage messages state the expected format
Usage hints and interactive prompts must show exact argument names and expected formats rather than vague placeholders.
```text
  bad : Invalid input. Try again.
  good: usage: clubhub register <event-id> <student-id> (example: clubhub register E001 P20250046)
```
## Rule 6: Use unambiguous ISO dates and 24-hour times
Always format timestamps as YYYY-MM-DD HH:MM to avoid ambiguity between day-first and month-first locales.
```text
  bad : 10/12/26 5:30
  good: 2026-10-14 17:30
```