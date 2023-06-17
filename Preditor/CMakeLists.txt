# Group projects in VS
set(CMAKE_FOLDER "Preditor")

# Common code
add_subdirectory(Common)

# Modules
add_subdirectory(Engine)
add_subdirectory(Main)
add_subdirectory(Viewport)

# EXEs and DLLs
add_subdirectory(Launcher)
