# Accessibility checklist · ITC Club Hub (planned web and mobile UI)
Target: WCAG 2.2 level AA · Version 0.1 · 2026-11-17

## 1. WCAG 2.2 Level AA Checklist (POUR Principles)

| SC and Name | Level | Screen | How We Meet It | How We Test It |
|---|---|---|---|---|
| 1.1.1 Non-text Content (Perceivable) | A | QR ticket view | Alt text with student ID | Screen reader inspection |
| 1.4.1 Use of Color (Perceivable) | A | Event list | Text badge like Full | View in greyscale |
| 1.4.3 Contrast Minimum (Perceivable) | AA | All screens | Text contrast above 4.5:1 | WebAIM Contrast Checker |
| 2.1.1 Keyboard (Operable) | A | Event list | Full Tab and Enter navigation | Unplug mouse and test |
| 2.4.11 Focus Not Obscured Minimum (Operable) | AA | Event list | Sticky header offsets focus scroll | Tab forward and backward |
| 2.5.7 Dragging Movements (Operable) | AA | Organiser queue | Up and down tap buttons | Single pointer click test |
| 2.5.8 Target Size Minimum (Operable) | AA | Registration form | Buttons at least 44x44 px | DevTools box model check |
| 3.2.6 Consistent Help (Understandable) | A | All screens | Help link fixed in footer | Compare across all views |
| 3.3.2 Labels or Instructions (Understandable) | A | Registration form | Explicit format hints above inputs | Inspect visible form labels |
| 3.3.7 Redundant Entry (Understandable) | A | Registration form | Auto-fill profile from session | Register twice in one session |
| 3.3.8 Accessible Authentication Minimum (Understandable) | AA | Login screen | Allow password paste and SSO | Paste password from manager |
| 4.1.2 Name, Role, Value (Robust) | A | Check-in scanner | ARIA live status regions | Run axe DevTools audit |

## 2. Screen Design Decisions and Contrast Measurements

### Screen A: Event List Screen
* **Design Decision 1:** Every event card includes an explicit text status badge (`[OPEN]`, `[FULL]`, `[CANCELLED]`) alongside background colour coding.
* **Design Decision 2:** Filter chips and Register buttons maintain a minimum hit target of 44 by 44 CSS pixels with 8 px spacing between cards.
* **Design Decision 3:** Keyboard focus rings use a 3 px solid outline with `scroll-margin-top` so the sticky top bar never covers the focused card.
* **Contrast Ratios:**
  - Body text (`#1E293B` dark slate on `#FFFFFF` white background): **14.6:1** (passes 4.5:1 requirement).
  - Primary Register button (`#FFFFFF` white text on `#1D4ED8` royal blue fill): **6.7:1** (passes 4.5:1 requirement).
  - Cancelled status badge (`#991B1B` crimson text on `#FEE2E2` soft red fill): **7.4:1** (passes 4.5:1 requirement).

### Screen B: Event Registration Form
* **Design Decision 1:** Input fields reuse authenticated student directory data (`studentId`, name, email) so students never re-type known details.
* **Design Decision 2:** Every input has a permanent visible `<label>` and format example above the box rather than disappearing placeholder text.
* **Design Decision 3:** Validation errors appear inline via `aria-describedby` and state what failed, why, and how to fix it.
* **Contrast Ratios:**
  - Form label and input text (`#0F172A` navy on `#FFFFFF` white background): **17.4:1** (passes 4.5:1 requirement).
  - Input field border (`#475569` slate border against `#FFFFFF` white surface): **7.5:1** (passes 3:1 UI component requirement).
  - Inline error alert (`#7F1D1D` dark red text on `#FEF2F2` light rose background): **9.8:1** (passes 4.5:1 requirement).