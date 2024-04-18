cmake_minimum_required(VERSION 3.20)
project(ExampleMod) # CHANGE ME

# Search for libraries in CMake
list(APPEND CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_LIST_DIR}/CMake"
)

# Chairloader functions
include(CMake/CompilerConfig.cmake)
include(CMake/ModConfig.cmake)

# vcpkg libraries
find_package(Boost REQUIRED)
find_package(Detours MODULE REQUIRED)
find_package(fmt CONFIG REQUIRED)

# Common path
set(CHAIRLOADER_COMMON_PATH "" CACHE PATH "Path to Chairloader/Common. See Common/README_ModSDK.txt.")

# Third-party libraries
# add_subdirectory(ThirdParty/ExampleLibrary)

# Project libraries
add_subdirectory(CommonMod)

# Mods
add_subdirectory(Src)
