# Chairloader
Chairloader is a modding framework built for Prey (2017) developed by Arkane. It is primarily built to enable real time code execution, injection, and hooking for the game. This includes things like spawning entities and items, manipulating entities, accessing internal game functions like free-cam, and much more. This repository isn't built to be a place to get mods, it's intended to hold the tools needed to make whatever mods your heart desires. 

*Licensed under GNU GPLv3*

**Be warned, this is extremely experimental code at the moment. I don't have much in terms of documentation or examples yet. This is the cutting edge of runtime modding for this game and as such, things will change sporadically and quickly. Many many things you can do will crash the game. This is very much a WIP project**

## Capabilities:
### Mod Manager Functionality
- Automatic merging, packing, and deploying of XML file based mods (all pre-existing mods)
- Injection and starting of DLL mods (WIP Coming Soon)
- Modders now only need to include the elements that are new/edited in the mod files
- Simple compatibility patches needed for pre-existing mods
- Works for GameSDK xml files (Level files coming soon)

### API Functionality:
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
- Free Cam

Full GUI with support for other mods/threads writing to the GUI
![Chairloader Full Gui](https://user-images.githubusercontent.com/11778849/169223855-8bc2927c-c7bc-4a9d-9fcc-909d2a45c0f7.png)


The entity spawner: able to set position, entity name, and spawn any entity

![Chairloader Entity Spawner](https://user-images.githubusercontent.com/11778849/169223208-29e3e67f-8cef-4d91-b566-6e7051283f70.png)

The entity list: able to view and set position of every entity

![Chairloader Entity List](https://user-images.githubusercontent.com/11778849/169223201-fa357e04-2620-40be-824e-09facbbf6c0d.png)

The ability list: able to grant any neuromod in the game

![Chairloader Ability List](https://user-images.githubusercontent.com/11778849/169223185-419fe8f8-b48d-4dc5-b0cb-955cc761e1ce.png)



The Gui functionality is achieved via DX11 hooking and uses Dear ImGui.

## Resources used:
- vcpkg: https://github.com/Microsoft/vcpkg
- Boost Libraries: https://www.boost.org/
- Microsoft Detours: https://github.com/Microsoft/Detours
- Pugixml: https://github.com/zeux/pugixml
- Dear Imgui: https://github.com/ocornut/imgui
- ImGui Standalone: https://github.com/adamhlt/ImGui-Standalone
- ImGui Flame Graph https://github.com/bwrsandman/imgui-flame-graph
- Zip Library: https://libzip.org/

For information on how to setup and develop mods for Chairloader please see the wiki:
https://github.com/thelivingdiamond/ChairLoader/wiki

You can see the github.io website for a mod list and examples:
https://thelivingdiamond.github.io/ChairLoader/
