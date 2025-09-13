Command Line Options
======================
This page lists all known command line options for Chairloader and Prey.

Chairloader
-------------
These options can be added to `Prey.exe` command line. In Steam, they can be set in Properties -> Launch Options.

`-nochair`

:  LDisable Chairloader and Mod DLLs.

`-nopatches`

:  LDisable optional patches for troubleshooting.

`-chair_mods_path \<path to a directory>`

:  LOverrides the path to Mods directory.

`-nodevmode`

:  LForcefully disables engine's developer mode, even in Debug builds. Overrides `-devmode`.

`-devmode`

:  LEnables the engine's developer mode. Automatically set in Debug builds. Enables asserts in Release builds.

`-trainer`

:  LEnables trainer functionality. Requires `-devmode`.

`-editor`

:  LEnables the In-Game Editor for mod development.

`-noaudio`

:  LDisables the engine's audio subsystem. Breaks all dialog triggers and hard-locks story progression. Reduces start up
time by 10 seconds.

`-renderdoc`

:  LThe engine will wait for 10 seconds until RenderDoc is injected.

`-shadersdebug <int>`

:  L(When shader compiler is enabled) Sets the value of `r_shadersdebug`.

`-shaderthreads <int>`

:  L(When shader compiler is enabled) Sets the number of threads to use to compile shaders.

`-lua_storedebug <int>`

:  LEnables (1) or disables (0) Lua debug output. Disabled by default in normal mode, enabled in dev mode.


Engine
--------
These can be used in the same way as Chairloader's options. Some of these were
found in CRYENGINE 5 source code and were not tested with Prey.



`+command_name command_arg`

!!! warning inline end "Not Tested"
: Executes the console command when the game is started.

`-epicuserid <string>`

: Set by Epic Games Store launcher. Influences the save game path.

`-nomouse`

!!! warning inline end "Not Tested"
: Disables mouse input, only leaving keyboard and gamepads.

`-autodetect`

!!! warning inline end "Not Tested"
: Forces the game to auto-adjust graphics settings to match the hardware.

`-norandom`

!!! warning inline end "Not Tested"
: Seeds all PRNGs with constant seed of 0.


Preditor
--------
In addition to the options listed below, it accepts everything the engine and Chairloader support after. Engine options
need to be set after `--`.

`--`

: Mark the end of Preditor options. The following will be passed to the engine.

`--extract`

: Enable Extraction Mode. It will load the engine and extract paks set in ExtractList.xml.

`--game-path <full path>`

: Path to the root game directory (where GameSDK is).

`--output-path <full path>`

: Path to the output directory.
