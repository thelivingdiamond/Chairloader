# Chairloader
#### *By thelivingdiamond & tmp64*
Chairloader is a modding framework built for Prey (2017) developed by Arkane. First and foremost chairloader is designed to enable modders to make mods for Prey on a scale never before seen. With realtime mod DLL loading modders are now given the ability to change not just the assets, but the code at the core of the game. There is a GUI built in with several functions to aid in modding (or messing around). Learn more below

*Licensed under GNU GPLv3*

## Installation
- Download the latest Release
- Run ChairManager.exe
  - The mod manager will automatically install the DLLs and patch the game DLL if needed
 
 
#### To Install Mods:
  - Use the `install mod from file` button to install a mod from .7z or .zip. This will only work for mods that have a ModInfo.xml
  - Manual method:
    - Place any mod folder with a ModInfo.xml file into the Mods/ folder in your Prey game directory
    - For any mods made before Chairloader, or those without a ModInfo.xml place the mod folder inside Mods/Legacy/


## [Mod Manager](ChairManager/README.md)
- Easy installation of Chairloader
- Control load order and state of mods
- Automatic merging, packing, and deploying of XML files and assets
- Modders now only need to include the elements that are new/edited in the mod files
- Works for all XML assets in the game


## [Chairloader Editor] (Chairloader/Editor/README.md)
- Free cam
- Click on entities to inspect
- Entity editing
- Pause the game to explore with free cam

## [Chairloader Modules](ChairLoader/Tools/README.md)
#### Built-in trainer-like functions:
- Entity Manager
- Player Manager
- World Manager
- Full in-game console reimplemented
- Performance evaluation
- Full mod config manager


## API Functionality:
- Automatic loading of mod DLLs (when enabled in mod loader)
- Full game header decompilation
- Example mod code
- Wiki documentation (coming soon)


The Gui functionality is achieved via DX11 hooking and uses Dear ImGui.
## Resources used:
- vcpkg: https://github.com/Microsoft/vcpkg
- Boost Libraries: https://www.boost.org/
- Microsoft Detours: https://github.com/Microsoft/Detours
- Pugixml: https://github.com/zeux/pugixml
- Dear Imgui: https://github.com/ocornut/imgui
- ImGui Standalone: https://github.com/adamhlt/ImGui-Standalone
- ImGui Flame Graph https://github.com/bwrsandman/imgui-flame-graph
- ImGui File Dialog: https://github.com/aiekick/ImGuiFileDialog
- 7Zip: https://www.7-zip.org/ 

For information on how to set up and develop mods for Chairloader please see the wiki (WIP):
https://github.com/thelivingdiamond/ChairLoader/wiki

You can see the github.io website for a mod list and examples (WIP):
https://thelivingdiamond.github.io/Chairloader/
