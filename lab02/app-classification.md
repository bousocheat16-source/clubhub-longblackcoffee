# Lab-02 · Classification of five applications
Version 1.0 · 2026-11-01 · Team: longblackcoffee

| # | Application | Kind | Type(s) | Where the code runs, how it is delivered | Architecture | Top 3 qualities (why) | Filled by |
|---|-------------|------|---------|------------------------------------------|--------------|-----------------------|-----------|
| 1 | Mobile banking app: __ | | | | | | |
| 2 | Telegram | Application Software | Mobile native, desktop, web SPA, cloud SaaS, data-intensive |  IOS / Android (App Store / Google Play), desktop app (download from
|        telegram.org), browser SPA (web.telegram.org), Telegram servers in
|        data centres; chats cached on the device, so old messages still
|        open offline | client-server; phone, desktop and web clients call the same
|               back-end (new phone login shows the full chat history,
|               because it lives on the servers) | availability (when Telegram goes down, chats and groups go
|        quiet),
|        performance (if a message takes more than a second to show
|        up, the chat feels broken), security
|        (if someone gets hold of your login code, they can read your
|        private chats and message your friends pretending to be you) | @ |
| 3 | ABS controller in a car | | | | | | |
| 4 | Moodle at ITC | | | | | | |
| 5 | Game: Roblox | Application Software | Game, Cross-platform, cloud SaaS | The app runs on a user's device (by downloading from App Store or Play Store or from the website) | Rely on client-server, must have internet to play games and interact with others | Performance: If the game has a high latency then most users' device won't be able to run
Security: If the platform is breached, users may have their account stolen and loses a lot of their value items in-game
Availability: If the game's server shut down, millions of users won't be able to play | @bousocheat16-source |

Biggest difference we found: __
