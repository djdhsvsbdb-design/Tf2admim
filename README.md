# TF2 Admin Tools

A Windows x64 companion utility for locating a Team Fortress 2 installation and managing this project's own configuration files.

## Scope

- Detect a Steam installation and a TF2 installation.
- Keep project files separate from the game's original binaries.
- Never replace, patch, inject into, or load code into the Steam game process.
- No wallhack, player tracking, hidden ESP, anti-cheat bypass, or other unfair-play features.

## Build

Requirements: Windows 10/11, CMake 3.20+, and Visual Studio 2022 with the C++ workload.

```powershell
cmake -S . -B build -A x64
cmake --build build --config Release
```

The first version is a detection-only installer scaffold. It does not modify the game.

## Project layout

- `Installer/` — Windows x64 installation utility.
- `Config/` — project configuration defaults.
