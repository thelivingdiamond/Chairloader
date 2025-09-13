# Mod Project Setup
This article will show you how to setup a C++ mod project.

## Prerequisites
1. [Build Chairloader](building-chairloader.md)
2. [Create an empty mod](../introduction.md)

## Step 1. Creating basic files
1. Open your mod folder.
2. Copy the contents of `Chairloader/ExampleMod` to your mod folder
3. Follow the guide in `Chairloader/ExampleMod/README.md` to set the name of the mod
4. Open `ModInfo.xml` and set `dllName` to `YourMod.dll`

## Step 2. Generating VS solution using CMake
1. Create folder named `_build` in your mod folder
2. Open CMake GUI
3. Configure CMake similarly to [Building Chairloader](building-chairloader.md) until you get an error
5. Set `CHAIRLOADER_COMMON_PATH` to `[path to Chairloader source code]/Common` and press "Configure"
4. Set `MOD_DLL_PATH` to the same folder as your mod. This will place the DLL file in there automatically.
6. Press "Configure", "Generate", "Open Project"

## Step 3. Configuring debugging settings
This is still WIP. Here's the basics.

1. Open the project in Visual Studio
2. Open mod project's properties
3. "Configuration Properties" -> "Debugging"
4. When using Preditor, set:
    - "Command": path to Preditor.exe
    - "Command Arguments": `-- -noaudio` (this will speed up loading considerably)
    - "Working directory": folder with Preditor.exe
5. When using normal game, set:
    - "Command": path to Prey.exe
    - "Command Arguments": `-noaudio` (this will speed up loading considerably)
    - "Working directory": folder with Prey.exe
6. Set the mod project as Startup Project
7. Debug -> Launch
