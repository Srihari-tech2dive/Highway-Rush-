# 🚗 Highway Rush

> A cross-platform endless highway racing game built from scratch using C and SDL2.

Highway Rush is an endless highway racing game focused on fast-paced lane switching, procedural road generation, dynamic events, power-ups, and adaptive difficulty.

The project is also designed as a learning project for understanding how a real C-based game engine works — from source code and compilation to memory management, game loops, rendering, procedural generation, and cross-platform deployment.

---

## 🎮 Project Status

**Version:** 1.0  
**Development Status:** 🚧 In Development  
**Primary Development Platform:** Linux  
**Game Language:** C  
**Graphics / Input:** SDL2  
**Browser Build:** WebAssembly via Emscripten

### Target Platforms

- 🐧 Linux
- 🪟 Windows
- 🌐 Web Browser
- 📱 Android — Planned for Version 2

---

# 🎯 Game Concept

Highway Rush is an endless highway runner.

The player controls a car moving continuously forward and uses only:

- `Left`
- `Right`

to change lanes.

The road continuously evolves as the player travels farther.

There is no traditional finish line.

The objective is to:

- Survive as long as possible
- Travel the greatest distance
- Collect coins
- Unlock new themes
- Survive special events
- Survive boss events
- Use Turbo and Ghost power-ups intelligently

The game continues until the player loses all three lives or encounters a game-over condition.

---

# 🕹️ Controls

## Desktop

| Key | Action |
|-----|--------|
| `←` | Move Left |
| `→` | Move Right |

## Browser / Mobile

The browser version supports:

- Keyboard controls
- Touch controls

Mobile gameplay is designed for **landscape orientation**.

```text
┌───────────────────────────────────────┐
│                                       │
│              HIGHWAY RUSH             │
│                                       │
│                                       │
│                                       │
│                                       │
│      [ LEFT ]             [ RIGHT ]   │
└───────────────────────────────────────┘
