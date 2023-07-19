# Group projects in VS
set(CMAKE_FOLDER "Preditor")

# Common code
add_subdirectory(Common)

# Modules
add_subdirectory(Assets)
add_subdirectory(EditTools)
add_subdirectory(Engine)
add_subdirectory(GameEditor)
add_subdirectory(Input)
add_subdirectory(LevelEditor)
add_subdirectory(Main)
add_subdirectory(Viewport)

# EXEs and DLLs
add_subdirectory(Launcher)
