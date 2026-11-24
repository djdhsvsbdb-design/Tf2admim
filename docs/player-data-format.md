# Player roster import format

The external AdminPanel accepts a JSON array. Each entry may contain:

- `name`: display name (string)
- `team`: `RED` or `BLU`
- `class`: one of Scout, Soldier, Pyro, Demoman, Heavy, Engineer, Medic, Sniper, Spy
- `source`: optional label describing the authorized source

Example:

```json
[
  {"name":"Player A","team":"RED","class":"Soldier","source":"authorized-admin-feed"},
  {"name":"Player B","team":"BLU","class":"Medic","source":"authorized-admin-feed"}
]
```

Use only information supplied by a server-side admin integration you control or another permitted export. This panel does not read TF2 process memory, inject code, bypass anti-cheat, infer occluded positions, or display players through walls. The sample file contains placeholders only.
