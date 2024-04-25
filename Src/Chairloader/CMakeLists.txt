# Group projects in VS
set(CMAKE_FOLDER "Chairloader (Game)")

# Common code
add_subdirectory(Common)

# Chairloader modules
add_subdirectory(Core)
add_subdirectory(CryRender)
add_subdirectory(Patches)
add_subdirectory(Tools)

# Chairloader DLLs
add_subdirectory(Dll)
add_subdirectory(Loader)
