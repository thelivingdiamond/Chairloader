set(SOURCE_FILES
	CMakeLists.txt

	Lua/LuaModManager.cpp
	Lua/LuaModManager.h
	Lua/ScriptBind_Chairloader.cpp
	Lua/ScriptBind_Chairloader.h

	ModManager/ChairMod.cpp
	ModManager/ChairMod.h
	ModManager/ModApiComponent.cpp
	ModManager/ModApiComponent.h
	ModManager/ModComponent.cpp
	ModManager/ModComponent.h
	ModManager/ModDllComponent.cpp
	ModManager/ModDllComponent.h
	ModManager/ModManager.cpp
	ModManager/ModManager.h

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

target_sources(Chairloader.Core PRIVATE
	# I hate myself even more now
	${CMAKE_SOURCE_DIR}/CommonChairManager/Manager/ModInfo.cpp
	${CMAKE_SOURCE_DIR}/CommonChairManager/Manager/ModInfo.h
)

target_include_directories(Chairloader.Core PRIVATE .)

target_link_libraries(Chairloader.Core PUBLIC
	Chairloader.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
