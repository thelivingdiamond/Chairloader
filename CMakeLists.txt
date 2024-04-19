cmake_minimum_required(VERSION 3.20)

project(Chairloader)
set(CHAIRLOADER TRUE)

# Search for libraries in ExampleMod's CMake
list(APPEND CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_LIST_DIR}/ExampleMod/CMake"
)

# Shared compiler config for Chairloader and mods
include(ExampleMod/CMake/CompilerConfig.cmake)

# Enable project folders in VS
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Chairloader Version
set(_CHAIRLOADER_VERSION_MAJOR 1)  # Increment when breaking changes are made
set(_CHAIRLOADER_VERSION_MINOR 1)  # Increment when new features are added
set(_CHAIRLOADER_VERSION_PATCH 0)  # Increment when bug fixes are made
set(_CHAIRLOADER_VERSION_BUILD 0)  # UNUSED
set(_CHAIRLOADER_VERSION_TYPE "")  # Indicates a pre-release version (e.g. "-alpha")

# Game path
set(PREY_DLL_DIR "" CACHE PATH "(optional) Path to the game binaries directory (where Prey.exe/.dll are) to automatically install built binaries")

if(PREY_DLL_DIR)
	get_filename_component(PREY_PATH "${PREY_DLL_DIR}/../../../../" ABSOLUTE)
	set(PREY_EXE_PATH "${PREY_DLL_DIR}/Prey.exe")
	
	if((NOT EXISTS "${PREY_EXE_PATH}"))
		message(FATAL_ERROR
			" PREY_DLL_DIR is not valid. Prey.exe not found.\n"
			" DLL directory: ${PREY_DLL_DIR}\n"
		)
	endif()
	
	if((NOT EXISTS "${PREY_PATH}/Engine") OR (NOT EXISTS "${PREY_PATH}/GameSDK"))
		message(FATAL_ERROR
			" PREY_DLL_DIR is not valid. Engine or GameSDK not found in the root.\n"
			" DLL directory: ${PREY_DLL_DIR}\n"
			" Game root directory: ${PREY_PATH}"
		)
	endif()
	
endif()

# Macros and functions

# Sets target's output directory to the argument.
# @param targetName Name of the target.
# @param outPath	Output directory path.
function(cl_set_output_dir targetName outPath)
	set_target_properties(${targetName} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${outPath}
		RUNTIME_OUTPUT_DIRECTORY_DEBUGCHAIR ${outPath}
		RUNTIME_OUTPUT_DIRECTORY_RELEASE ${outPath}
		LIBRARY_OUTPUT_DIRECTORY ${outPath}
		LIBRARY_OUTPUT_DIRECTORY_DEBUGCHAIR ${outPath}
		LIBRARY_OUTPUT_DIRECTORY_RELEASE ${outPath}
	)
endfunction()

# Sets target's output directory to the game binaries dir.
# @param targetName Name of the target.
function(cl_output_to_game_dir targetName)
	if(PREY_DLL_DIR)
		cl_set_output_dir(${targetName} "${PREY_DLL_DIR}")
	endif()
endfunction()

# Sets target's output directory to the Data dir.
# @param targetName Name of the target.
function(cl_output_to_data targetName)
	cl_set_output_dir(${targetName} "${CMAKE_SOURCE_DIR}/Data")
endfunction()

# Sets target's debugger command and workdir to the game.
# @param targetName Name of the target.
function(cl_set_debug_path targetName)
	if(PREY_EXE_PATH)
		set_target_properties(${targetName} PROPERTIES
			VS_DEBUGGER_COMMAND "${PREY_EXE_PATH}"
			VS_DEBUGGER_WORKING_DIRECTORY "${PREY_PATH}"
		)
	endif()
endfunction()

# Generates version_info.rc resource file for the target.
# @param target_name		Target name. Must be an EXE or a DLL.
# @param file_name			Output file name.
# @param file_description	Short file description.
function(cl_version_info target_name file_name file_description)
	get_target_property(target_type ${target_name} TYPE)

	if(target_type STREQUAL "EXECUTABLE")
		set(is_dll 0)
	elseif(target_type STREQUAL "SHARED_LIBRARY")
		set(is_dll 1)
	else()
		message(FATAL_ERROR "Target ${target_name} is neither EXE nor DLL, it's ${target_type}")
	endif()

	if(_CHAIRLOADER_VERSION_TYPE)
		set(is_prerelease 1)
	else()
		set(is_prerelease 0)
	endif()

	set(in_file_path "${CMAKE_SOURCE_DIR}/Src/CommonChairManager/version_info.rc.in")
	set(out_file_path "${CMAKE_CURRENT_BINARY_DIR}/generated/${target_name}/version_info.rc")

	configure_file(
		${in_file_path}
		${out_file_path}
		@ONLY
	)

	target_sources(${target_name} PRIVATE ${out_file_path})
endfunction()

# Third-party libraries
find_package(Boost REQUIRED COMPONENTS program_options json)
find_package(Detours MODULE REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(GTest REQUIRED)
find_package(libzip REQUIRED)
find_package(libzippp CONFIG REQUIRED)
find_package(Lua REQUIRED)
find_package(pugixml REQUIRED)
find_package(unofficial-curlpp CONFIG REQUIRED)

find_path(LUABRIDGE_INCLUDE_DIRS "LuaBridge/List.h")

add_subdirectory(ThirdParty/StackWalker)

# Enable CTest
enable_testing()

# Projects
add_subdirectory(Common)
add_subdirectory(Src/BinDiff)
add_subdirectory(Src/Chairloader)
add_subdirectory(Src/ChairManager)
add_subdirectory(Src/CommonChairManager)
add_subdirectory(Src/Preditor)

# Example Mod
# It is meant to be a standalone project so this mess of CMake code builds it as part of Chairloader

# Unset ExampleMod's variables (in case they were ever set before)
unset(CHAIRLOADER_COMMON_PATH CACHE)
unset(EXAMPLE_MOD_DLL_PATH CACHE)

# Set correct ExampleMod variables
set(CHAIRLOADER_COMMON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Common" CACHE PATH "")

if(PREY_PATH)
	set(EXAMPLE_MOD_DLL_PATH "${PREY_PATH}/Mods/TheChair.ExampleMod" CACHE PATH "")
endif()

set(CMAKE_FOLDER "Example Mod")
add_subdirectory(ExampleMod)
unset(CMAKE_FOLDER)

unset(CHAIRLOADER_COMMON_PATH CACHE)
unset(EXAMPLE_MOD_DLL_PATH CACHE)

# Set default VS project
set(VS_STARTUP_PROJECT "Chairloader.Dll")
