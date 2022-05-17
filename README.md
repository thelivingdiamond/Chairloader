# Chairloader
Chairloader is a modding framework built for Prey (2017) developed by Arkane. It is primarily built to enable real time code execution, injection, and hooking for the game. This includes things like spawning entities and items, manipulating entities, accessing internal game functions like free-cam, and much more. This repository isn't built to be a place to get mods, it's intended to hold the tools needed to make whatever mods your heart desires. 

*Licensed under GNU GPLv3*

**Be warned, this is extremely experimental code at the moment. I don't have much in terms of documentation or examples yet. This is the cutting edge of runtime modding for this game and as such, things will change sporadically and quickly. Many many things you can do will crash the game. This is very much a WIP project**

## Capabilities:
### Mod Manager Functionality (coming soon)
- Automatic merging, packing, and deploying of XML files
- Injection and starting of DLL mods
- Modders only need to include the elements that are new/edited in the mod files
- Simple compatibility patches needed for pre-existing mods

### Api Functionality:
- NPC Spawning (fully functional)
- Entity Spawning (semi functional)
- NPC and Entity Manipulation (fully functional)
- Ability to execute internal console commands
- Ability to spawn custom NPCs and entities added to the XML files
- A mapped library of all pre-existing entity archetypes, classes, and 

### Gui Functionality:
- Entity Spawner
- Entity List
- Overlay style log in the corner
- Neuromod List with capability to give any neuromod
- Re-implement in-game console (WIP)
- Allow other mods to display elements in the GUI (Documentation coming soon)

*Pictures coming soon*

The Gui functionality is achieved via DX11 hooking and uses Dear ImGui.

## Resources used:
- vcpkg: https://github.com/Microsoft/vcpkg
- Boost Libraries: https://www.boost.org/
- Microsoft Detours: https://github.com/Microsoft/Detours
- Pugixml: https://github.com/zeux/pugixml
- Dear Imgui: https://github.com/ocornut/imgui
- ImGui Standalone: https://github.com/adamhlt/ImGui-Standalone
- DX11 Hook: https://github.com/niemand-sec/DirectX11Hook
- Zip Library: https://libzip.org/

You can see the github.io website for a mod list, examples, and more documentation for modders:
https://thelivingdiamond.github.io/ChairLoader/
