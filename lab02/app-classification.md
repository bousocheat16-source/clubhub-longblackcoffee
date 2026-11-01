# Lab-02 · Classification of five applications
Version 1.0 · 2026-11-01 · Team: longblackcoffee

| # | Application | Kind | Type(s) | Where the code runs, how it is delivered | Architecture | Top 3 qualities (why) | Filled by |
|---|-------------|------|---------|------------------------------------------|--------------|-----------------------|-----------|
| 1 | Mobile banking app: __ | | | | | | |
| 2 | Telegram | | | | | | |
| 3 | ABS controller in a car (Ford Territory 2025) | System Software | Runs on an ECU (Electric Control Unit) programmed in the car. The program is installed directly from the car factory | Embedded control loop. Evidence: The software constantly loops to monitor wheel speed sensors and immediately adjusts brake pressure when it detects a slip. | Safety: If the software fails or calculates incorrectly during sudden braking, the vehicle could skid out of control and cause an accident. Performance: If the system is too slow to process the sensor data, it will not pulse the brakes fast enough to maintain traction. Availability: If the ABS controller unexpectedly goes offline while driving, the driver loses a critical anti-lock braking function during an emergency. | @bousocheat16-source |
| 4 | Moodle at ITC | | | | | | |
| 5 | Game: Roblox | Application Software | Game, Cross-platform, cloud SaaS | The app runs on a user's device (by downloading from App Store or Play Store or from the website) | Rely on client-server, must have internet to play games and interact with others | Performance: If the game has a high latency then most users' device won't be able to run Security: If the platform is breached, users may have their account stolen and loses a lot of their value items in-game Availability: If the game's server shut down, millions of users won't be able to play | @bousocheat16-source |

Biggest difference we found: __
