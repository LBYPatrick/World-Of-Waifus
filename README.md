# World-Of-Waifus
Mod loader for World of Warships. 

## Usage

1. Download the latest [release](https://github.com/LBYPatrick/World-Of-Waifus/releases/latest).
2. Drag-and-drop ``World-Of-Waifus.exe`` to the root folder of the Wargaming game you want to use the mod loaded on (not under ``bin32`` or ``bin64`` but the folder containing them both).
3. create a folder called "mods" and create subfolders under it for different mods. For example:

```bash
  -- World-Of-Waifus.exe
  -- mods
  ---- MOD_1
  ------(mod content)
  ---- MOD_2
  ------(mod content)
```
4. Run ``World-Of-Waifus.exe`` and wait until it exits on its own.
5. Start playing as usual. Repeat step 4 if you added another mod after this game session.

## Build

Perequisite:
  - g++ (must be 9.x.x because C++17 features are used, and 8.x.x has bugs that would fail the compliation)

1. ``sh build.sh``
2. Done. Build is located under ``bin``.

## Troubleshooting

If you notice anything weird in-game and has already excluded the possibility of mod conflicts, delete everything under ``res_mods/(version number)``.

## LINCENSE

This project is using MIT License.

