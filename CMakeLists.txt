cmake_minimum_required(VERSION 3.20)
project(Chairloader)
set(CHAIRLOADER TRUE)

if((NOT MSVC) OR (MSVC_TOOLSET_VERSION LESS 141))
	message(FATAL_ERROR "Chairloader must be built using Visual Studio 2017 or newer")
endif()

if (NOT (CMAKE_SIZEOF_VOID_P EQUAL 8))
	message(FATAL_ERROR "Chairloader must be built for x64")
endif()

list(APPEND CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_LIST_DIR}/ExampleMod/CMake"
)

# Set C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Prey was build in Release so mods must match it even in Debug
set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreadedDLL)
add_compile_definitions(
	$<IF:$<CONFIG:Debug>,DEBUG_BUILD,RELEASE_BUILD>
)

# Compiler and linker flags
string(REPLACE "/Zi" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}") # Remove /Zi
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /ZI") # /ZI Edit and Continue
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

# Game path
set(PREY_PATH "" CACHE PATH "(optional) Path to the game root directory (where Engine and GameSDK are) to automatically install built binaries")

# Macros and functions

# Sets target's output directory to a path in the game
# @param targetName Name of the target
# @param gamePath Path to a directory in the game root
function(cl_output_dir targetName gamePath)
	if(PREY_PATH)
		set(out_path "${PREY_PATH}/${gamePath}")
		set_target_properties(${targetName} PROPERTIES
			RUNTIME_OUTPUT_DIRECTORY ${out_path}
			RUNTIME_OUTPUT_DIRECTORY_DEBUG ${out_path}
			RUNTIME_OUTPUT_DIRECTORY_RELEASE ${out_path}
			RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${out_path}
			RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${out_path}
			LIBRARY_OUTPUT_DIRECTORY ${out_path}
			LIBRARY_OUTPUT_DIRECTORY_DEBUG ${out_path}
			LIBRARY_OUTPUT_DIRECTORY_RELEASE ${out_path}
			LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${out_path}
			LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL ${out_path}
		)
	endif()
endfunction()

# Third-party libraries
find_package(Boost REQUIRED COMPONENTS filesystem log)
find_package(Detours MODULE REQUIRED)
find_package(libzip REQUIRED)
find_package(pugixml REQUIRED)
# add_subdirectory(ThirdParty/ExampleLibrary)

# Project libraries
add_subdirectory(Common)

# DLLs
add_subdirectory(ChairLoader)
add_subdirectory(ChairLoaderLoader)

# Example Mod
unset(CHAIRLOADER_COMMON_PATH CACHE)
unset(EXAMPLE_MOD_DLL_PATH CACHE)

set(CHAIRLOADER_COMMON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Common" CACHE PATH "")

if(PREY_PATH)
	set(EXAMPLE_MOD_DLL_PATH "${PREY_PATH}/Mods/ExampleMod" CACHE PATH "")
endif()

add_subdirectory(ExampleMod)

unset(CHAIRLOADER_COMMON_PATH CACHE)
unset(EXAMPLE_MOD_DLL_PATH CACHE)

# Executables
# Executables don't need to use Prey ABI
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
#add_subdirectory(ChairLoaderXMLLoader)
add_subdirectory(ChairLoaderModLoader)
