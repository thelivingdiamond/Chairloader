# Chairloader
Chairloader is a modding framework built for Prey (2017) developed by Arkane. It is primarily built to enable real time code execution, injection, and hooking for the game. This includes things like spawning entities and items, manipulating entities, accessing internal game functions like free-cam, and much more. This repository isn't built to be a place to get mods, it's intended to hold the tools needed to make whatever mods your heart desires. 

*Licensed under GNU GPLv3*

**Be warned, this is extremely experimental code at the moment. I don't have much in terms of documentation or examples yet. This is the cutting edge of runtime modding for this game and as such, things will change sporadically and quickly. Many many things you can do will crash the game. This is very much a WIP project**

## Capabilities:
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

## Development Guide: (WIP, not ready yet)
Installing Boost:
- Use Visual Studio 2019 (potentially moving to 2022 in future)
- Download and place vcpkg in a low level directory as per the instructions on the github page
- Run the following commands from the directory where vcpkg is:

`./vcpkg.exe install boost` (Note, this command may take up to an hour to run, but only ever needs to be run once)

`./vcpkg.exe integrate install` 

Now the boost libraries are installed, which were used by the Prey developers, and additionally used with Chairloader for interprocess-communication to load mods. 

Other includes:
- Currently the ImGui, Detours, and PugiXML directories must be added in the Visual Studio Project settings under additional include directories. This will change in the near future because I am going to restructure the directories.

## Resources used:
- vcpkg: https://github.com/Microsoft/vcpkg
- Boost Libraries: https://www.boost.org/
- Microsoft Detours: https://github.com/Microsoft/Detours
- Pugixml: https://github.com/zeux/pugixml
- Dear Imgui: https://github.com/ocornut/imgui
- DX11 Hook: https://github.com/niemand-sec/DirectX11Hook
- Zip Library: https://libzip.org/

You can see the github.io website for a mod list, examples, and more documentation for modders:
https://thelivingdiamond.github.io/ChairLoader/
