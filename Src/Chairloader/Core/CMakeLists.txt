set(SOURCE_FILES
	CMakeLists.txt

	Lua/LuaModManager.cpp
	Lua/LuaModManager.h
	Lua/ScriptBind_Chairloader.cpp
	Lua/ScriptBind_Chairloader.h

	ChairImGui.cpp
	ChairImGui.h
	ChairloaderConfigManager.cpp
	ChairloaderConfigManager.h
	ChairloaderCore.cpp
	ChairloaderCore.h
	ChairloaderGui.cpp
	ChairloaderGui.h
	ChairLogger.cpp
	ChairLogger.h
	ChairVarManager.cpp
	ChairVarManager.h
	LogManager.cpp
	LogManager.h
	ModDllManager.cpp
	ModDllManager.h
	OverlayLog.cpp
	OverlayLog.h
	Profiler.cpp
	Profiler.h
)

add_library(Chairloader.Core STATIC ${SOURCE_FILES})
target_include_directories(Chairloader.Core PRIVATE .)

target_link_libraries(Chairloader.Core PUBLIC
	Chairloader.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
