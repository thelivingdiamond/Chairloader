Example Mod
============

This directory contains the example mod that you can use as a template for your mods.


Requirements
-------------

1. Visual Studio 2017/2019/2022
2. A bit of CMake skills


How to use
-----------

1. Let `$mod_name` be the name of your mod.
2. Copy current directory (where *README.md* is) somewhere else and rename it into `$mod_name`.
3. Look for `CHANGE ME` comments in the following files. Near them rename `ExampleMod` into `$mod_name`.
   - *CMakeLists.txt*
   - *vcpkg.json*
   - *Src/CMakeLists.txt*
   - *Src/ModMain.cpp*
4. Read `Common/README_ModSDK.txt` and choose one of the options.
5. Use CMake to generate a Visual Studio project.

You can find some example code in `$mod_name`/ModMain.cpp.
