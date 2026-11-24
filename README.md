# TF2 Admin Tools

A Windows x64 companion utility and external player-roster panel for Team Fortress 2 administration.

## Features

- Detect a Steam installation and a TF2 installation.
- External RED / BLU roster panel with name and class filters.
- Import a JSON roster from an authorized server-side admin integration or another permitted export.
- Keep project files separate from the game's original binaries.

## Important limits

- The panel displays only data explicitly imported from an authorized source.
- It does not read TF2 process memory, inject code, patch game binaries, bypass anti-cheat, infer hidden player positions, or provide wallhack functionality.
- Example player records are placeholders, not live game data.
- The current panel is a standalone local HTML page, not an in-game overlay.

## Run the roster panel

Open `AdminPanel/index.html` in a browser, then choose **Import JSON** and select `Config/players.example.json` or a JSON export from an admin integration you control.

See [the player data format](docs/player-data-format.md) for the accepted structure.

## Build the Windows utility

Requirements: Windows 10/11, CMake 3.20+, and Visual Studio 2022 with the C++ workload.

```powershell
cmake -S . -B build -A x64
cmake --build build --config Release
```

The installer scaffold currently detects a Steam / TF2 installation and does not modify the game.

## Project layout

- `Installer/` — Windows x64 installation utility.
- `AdminPanel/` — external RED / BLU roster panel.
- `Config/` — project configuration and example roster.
- `docs/` — data format documentation.
