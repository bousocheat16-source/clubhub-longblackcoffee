| Field | Trigger | Action | Who or what runs it | How to verify |
|---|---|---|---|---|
| studentId | Account deleted (student request or administrator) | Delete | Administrator, using `clubhub purge`; backups purged within 30 days | Search students.csv for the test ID and find nothing; check the backup purge log after 30 days |
| name | Account deleted | Delete | Same run as studentId | Search students.csv for the test name and find nothing |
| email | Account deleted | Delete | Same run as studentId | Search students.csv for the test email and find nothing |
| phone | 6 months without a registration or check-in | Delete | `clubhub purge`, run monthly | Run it on a test record with old activity; the phone column is blank afterwards |
| phone | 6 months after graduation | Delete | `clubhub purge`, run monthly by an administrator | Run it on a test record with an old graduation date; the phone column is blank afterwards |
| clubMemberships | Student leaves the club | Delete | The app, immediately | Leave a test club, then check the row is gone from memberships.csv |
| attendance | End of semester (week 15) | Aggregate | `clubhub purge`, run by an administrator | After the run, registrations.csv has no per-student check-ins for that semester, only per-event totals |
| facultyAndYear | Student clears it, or account deleted | Delete | The app on clearing; `clubhub purge` for deleted accounts | Clear it in a test profile, then check the column is blank in students.csv |
