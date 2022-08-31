# Chairloader
#### By thelivingdiamond & tmp64
Chairloader is a modding framework built for Prey (2017) developed by Arkane. First and foremost chairloader is designed to enable modders to make mods for Prey on a scale never before seen. With realtime DLL injection modders are now given the ability to change not just the assets, but the code at the core of the game. There is a GUI built in with several functions to aid in modding (or messing around). Learn more below

*Licensed under GNU GPLv3*

Click on the headers to learn more about each!
## [Mod Manager](ChairloaderModLoader/README.md)
- Easy installation of Chairloader
- Control load order and state of mods
- Automatic merging, packing, and deploying of XML files and assets
- Modders now only need to include the elements that are new/edited in the mod files
- Works for all XML assets in the game


## [Chairloader Modules](ChairLoaderModules/README.md)
#### Built in trainer-like functions:
- Entity Manager
- Player Manager
- World Manager
- Full in-game console reimplemented
- Performance evaluation
- Full mod config manager


## API Functionality:
- Automatic injection of external DLL mods (when enabled in mod loader)
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

For information on how to setup and develop mods for Chairloader please see the wiki (WIP):
https://github.com/thelivingdiamond/ChairLoader/wiki

You can see the github.io website for a mod list and examples (WIP):
https://thelivingdiamond.github.io/ChairLoader/
