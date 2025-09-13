# Architecture Overview
This article will focus on how Preditor is structured and how it implements certain things.

Preditor functions by patching and loading the game engine (`PreyDll.dll`).

## Modules
Preditor is split into quite a large number of modules. Each module is a static library that implements a set of interfaces. Interfaces themselves are declared in the Common module.

Preditor uses a primitive form of inversion of control via static factory methods, which are implemented in the module:

```cpp
// Common/Preditor/IExample.h
struct IExample
{
	//! @returns an instance of Example.
	static std::unique_ptr<IExample> CreateInstance();

	virtual ~IExample() {}
	virtual void ExampleMethod() = 0;
}

// Example/Example.cpp
std::unique_ptr<IExample> IExample::CreateInstance()
{
	return std::make_unique<Example>();
}
```

### List of modules
- Assets - Asset importing and merging (XML, textures, models, ...).
- Common - Code shared between all modules (mostly interfaces).
- EditTools - Editor tools (select, move, rotate, scale, ...).
- Engine - Patches for the engine.
- FGE - Flowgraph Editor.
- GameEditor - Scene Editor for runtime entity inspection and editing.
- Input - The Input System.
- Launcher - The executable that links all modules together and launches the game engine.
- LevelEditor - Scene Editor for level editing.
- Main - Main module with global managers and UI.
- Viewport - Game and Scene viewport windows.

## Global Environment
Each Preditor module has access to a global structure `SPreditorEnvironment* gPreditor` declared in `Common/Preditor/Environment.h`. This structure contains pointers to most interfaces. It is used in place of a proper dependency injection system.

The contents of this structure may only be set in Main and Launcher modules.
## Projects
Preditor implements a project system. Each project is assumed to be an individual mod for Chairloader. Preditor will create a `.user` directory in the project for temporary files. It should not be distributed to other users or checked into version control. Each project is loaded separately from each other or from the normal game. That means that no save or config files are shared between Preditor and normal game.

### Project Structure
- .user - Temporary Preditor files.
    - ImportedAssets - imported (converted) asset files.
    - MergedAssets - assets after merging. This is analogous to `patch_chairloader.pak`.
    - Mods - additional mods that can be enabled in Preditor `File -> Mod Manager`.
    - User - game's save directory.
- Data - assets for merging (just like in a Chairloader mod).
- .gitignore - List of ignored file for Git. By default, ignores `.user` and CMake build directory.
- .preditor_project - main project file.
- ModInfo.xml - Mod Info for Chairloader.

## Asset System
### Merging
Preditor supports asset merging without game restart. This is implemented using "MOD Paths" in `ICryPak`, the game's file system library. Instead of creating a `.pak` file and putting it into `GameSDK/Precache`, the files are copied on the disk to `.user/MergedAssets/GameSDK`. The game will use them instead of any files in `.pak`s.

### Import
Preditor additionally supports asset import. In this context, "import" means taking a source file (for example, a `.png` image) and converting it into a format that CryEngine understands (for example, a `.dds` texture).

At the moment, no importers are implemented.

### Metadata Files
Each mod asset may have a metadata file (for example, for `Example.xml` metadata file is `Example.xml.prey`). This is an XML file in the following format:

```xml
<?xml version="1.0"?>
<Metadata
	skipMerge="0"
	mergeSourceFile="1"
	importerName="">
</Metadata>
```

Metadata files specify how an asset should be imported and merged.

## Scene Editors
Preditor uses an abstraction called "Scene Editor" to manipulate the game world. There are currently two scene editors:
- Game Editor - runtime entity manipulation
- Level Editor - level editing. Instead of entities, level objects are manipulated.

Scene editors are instantiated by `SceneEditorManager` in the Main module when loading a level. Normal load will create GameEditor. To enter the LevelEditor mode, run the following console command:

```bash
map_edit path_to_the_map

# Example:
map_edit campaign/research/lobby
```

### Edit Tools
Edit Tools are actual tools used by the end-user to manipulate game objects and entities. They are implemented in the EditTools module. Each scene editor exposes `IObjectManipulator` interface for the edit tools.

## Engine Patches
To make Preditor possible, it needs apply a set of patches to the engine and then load it. This is handled by the Engine module.

It implements the following things:
- Console redirection to Visual Studio debugger
- Viewport window rendering
- Viewport window input
- ImGui implementation using CryEngine's renderer and D3D11
- Loading the engine
- Running the engine's update function with configurable flags
    - Flags are for pausing the game
- Patches for running the engine in minimal configuration
    - No renderer, no window, no game logic
    - Used when extracting PAK files

## Flowgraph Editor
Work In Progress

## Input System
Preditor implements its own input system instead of using CryEngine's (reason: CryEngine input doesn't work when paused).

### Actions and Action Sets
Each command (e.g. pause/unpause, switch to different edit tool) is represented by an *action* (`IKeyAction`). An action may have a number of key bindings that may trigger it.

An action may be a modifier (e.g. Shift to speed up the camera). In this case, it may be bound to left or right modifier key.

Actions are grouped into *sets* (`IKeyActionSet`). Individual sets may be toggled on or off (e.g. `viewport_camera` action set is only enabled when actively controlling the scene camera). Each set has a *priority*. If the same key is bound to multiple actions from different sets, in will only trigger the set with highest priority.

Actions and Action Sets are defined in `ChairManager/Data/Preditor/ActionSets.xml`.

### Key Bindings
Any key can be bound to any action. Key bindings may also contain modifier keys (Ctrl, Alt, Shift). All key names can be found in `ChairManager/Data/Preditor/KeyMap.xml`.

The input system doesn't distinguish left and right modifier keys. Available modifiers:
- `crtl`
- `alt`
- `shift`

Example key bindings: "`w`", "`f4`", "`lshift`", "`ctrl+f5`", "`ctrl+alt+shift+b`".

## Viewport Window
In Preditor game window content is redirected into a separate viewport window.

The viewport window has two modes (use `F4` to switch between them):
- Game Viewport
- Scene Viewport

### Game Viewport
In this mode the viewport window contains the game output. It is implemented by hooking the engine's swap-chain (`IDXGISwapChain`) and redirecting it into a render-texture. That texture is then rendered in an ImGui window.

### Scene Viewport
This mode functions as a free-cam mode. You can look around with the mouse and move the camera by right-clicking the viewport and pressing WASDQE+Shift. You can select objects by left-clicking. Shift+left-click will add the clicked object to current selection.

In Game Editor mode, you have the option between "Mesh" and "Physics" selection modes. "Mesh" mode lets you select any object by clicking on its 3D-model ("mesh"). It is currently limited to non-animated ("static") objects. "Physics" mode uses a physics raycast (RWI - ray-world intersection) and lets you select any object with a physics collider.
