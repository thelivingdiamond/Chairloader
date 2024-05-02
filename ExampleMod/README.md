Example Mod
============

This directory contains the example C++ mod that you can use as a template for
your C++ mods.

If you don't need to change the game's code, you don't need all this. Follow the
[XML Modding Guide](https://github.com/thelivingdiamond/Chairloader/wiki/XML-Modding-%E2%80%90-Basic-Mod)
on the wiki.


How to use
-----------

1. Follow [the guide on the wiki](https://github.com/thelivingdiamond/Chairloader/wiki/DLL-Modding-%E2%80%90-Mod-Project-Setup)
   until you need to copy the example files.
2. Let `$mod_name` be the name of your mod.
3. Copy the contents of the current directory (where *README.md* is) to your mod
   directory.
4. Look for `CHANGE ME` comments in the following files. Near them rename `ExampleMod` into `$mod_name`.
   - *CMakeLists.txt*
   - *vcpkg.json*
   - *Src/CMakeLists.txt*
   - *Src/ModMain.cpp*
6. Continue with the wiki guide

You can find some example code in `$mod_name`/ModMain.cpp.
