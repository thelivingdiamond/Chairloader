include_guard()

#------------------------------------------------------------------------
# Compiler checks
#------------------------------------------------------------------------

# Check compiler version
if((NOT MSVC) OR (MSVC_TOOLSET_VERSION LESS 141))
	message(FATAL_ERROR "Chairloader must be built using Visual Studio 2017 or newer")
endif()

# Check target bits
if (NOT (CMAKE_SIZEOF_VOID_P EQUAL 8))
	message(FATAL_ERROR "Chairloader must be built for x64")
endif()

#------------------------------------------------------------------------
# C++ version
#------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#------------------------------------------------------------------------
# Configuration settings
#------------------------------------------------------------------------

# Create DebugChair configuration
# Debug CRT and Release CRT have different ABIs.
# Since Prey was linked with Release CRT, Chairloader must use it even in Debug.
# 
# vcpkg is hardcoded to use debug libraries for Debug and release for everything else.
# DebugChair is added to solve that. Debug is hidden to reduce confusion.
set(CMAKE_C_FLAGS_DEBUGCHAIR ${CMAKE_CXX_FLAGS_DEBUG} CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUGCHAIR ${CMAKE_CXX_FLAGS_DEBUG} CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS_DEBUGCHAIR ${CMAKE_EXE_LINKER_FLAGS_DEBUG} CACHE STRING "" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_DEBUGCHAIR ${CMAKE_SHARED_LINKER_FLAGS_DEBUG} CACHE STRING "" FORCE)

set(CMAKE_CONFIGURATION_TYPES DebugChair Release)
set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING "Configurations supported by Chairloader" FORCE)

set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreadedDLL)  # Always use Release CRT
set(CMAKE_MAP_IMPORTED_CONFIG_DEBUGCHAIR Release) # Use Release imported libs for DebugChair

# Compiler and linker flags
# Use Windows subsystem for DLLs
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

# Edit and Continue in Debug
string(REPLACE "/Zi" "/ZI" CMAKE_CXX_FLAGS_DEBUGCHAIR "${CMAKE_CXX_FLAGS_DEBUGCHAIR}")

# PDBs and optimizations in Release
set(RELEASE_LINKER_FLAGS "${RELEASE_LINKER_FLAGS} /debug")   # Generate PDB
set(RELEASE_LINKER_FLAGS "${RELEASE_LINKER_FLAGS} /OPT:REF") # Remove unreferenced functions and data
set(RELEASE_LINKER_FLAGS "${RELEASE_LINKER_FLAGS} /OPT:ICF") # Identical COMDAT folding

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi /Gy")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} ${RELEASE_LINKER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} ${RELEASE_LINKER_FLAGS}")

#------------------------------------------------------------------------
# Macros
#------------------------------------------------------------------------
# Add custom debug macro (_DEBUG is not available since linking with Releas libs)
add_compile_definitions(
	$<IF:$<OR:$<CONFIG:Debug>,$<CONFIG:DebugChair>>,DEBUG_BUILD,RELEASE_BUILD>
)
