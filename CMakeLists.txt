cmake_minimum_required(VERSION 3.20)

project(Chairloader C CXX ASM_MASM)
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

# Enable project folders in VS
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Prey was build in Release so mods must match it even in Debug
set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreadedDLL)
set(CMAKE_MAP_IMPORTED_CONFIG_DEBUG Release)
add_compile_definitions(
	$<IF:$<CONFIG:Debug>,DEBUG_BUILD,RELEASE_BUILD>
)

# Compiler and linker flags
string(REPLACE "/Zi" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}") # Remove /Zi
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /ZI") # /ZI Edit and Continue
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

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

# Chairloader Version
set(_CHAIRLOADER_VERSION_MAJOR 1)  # Increment when breaking changes are made
set(_CHAIRLOADER_VERSION_MINOR 0)  # Increment when new features are added
set(_CHAIRLOADER_VERSION_PATCH 2)  # Increment when bug fixes are made
set(_CHAIRLOADER_VERSION_BUILD 0)  # UNUSED
set(_CHAIRLOADER_VERSION_TYPE "")  # Indicates a pre-release version (e.g. "-alpha")

# Macros and functions

# Sets target's output directory to the game binaries dir.
# @param targetName Name of the target.
function(cl_output_dir targetName)
	if(PREY_DLL_DIR)
		set(out_path "${PREY_DLL_DIR}")
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

# Third-party libraries
find_package(Boost REQUIRED COMPONENTS program_options)
find_package(Detours MODULE REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(libzip REQUIRED)
find_package(pugixml REQUIRED)
find_package(GTest REQUIRED)

# Enable CTest
enable_testing()


find_package(unofficial-curlpp CONFIG REQUIRED)

# Project libraries
add_subdirectory(Common)
add_subdirectory(Chairloader)

# Example Mod
unset(CHAIRLOADER_COMMON_PATH CACHE)
unset(EXAMPLE_MOD_DLL_PATH CACHE)

set(CHAIRLOADER_COMMON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Common" CACHE PATH "")

if(PREY_PATH)
	set(EXAMPLE_MOD_DLL_PATH "${PREY_PATH}/Mods/TheChair.ExampleMod" CACHE PATH "")
endif()

set(CMAKE_FOLDER "Example Mod")
add_subdirectory(ExampleMod)
unset(CMAKE_FOLDER)

unset(CHAIRLOADER_COMMON_PATH CACHE)
unset(EXAMPLE_MOD_DLL_PATH CACHE)

# Since ModToolKit interfaces with PreyDll.dll, everything must use Release ABI
# set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
add_subdirectory(ThirdParty/StackWalker)
add_subdirectory(CommonChairManager)
#add_subdirectory(ChairLoaderXMLLoader)
add_subdirectory(ChairManager)
add_subdirectory(BinDiff)
add_subdirectory(Preditor)

# Set default VS project
set(VS_STARTUP_PROJECT "Chairloader.Dll")
