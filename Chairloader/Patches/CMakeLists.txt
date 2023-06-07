set(SOURCE_FILES
	CMakeLists.txt
	
	Lua/LuaDbgRes.cpp
	Lua/LuaDbgRes.h
	Lua/LuaWarnPatch.cpp
	Lua/LuaWarnPatch.h

	SteamAPI/ArkSteamDlcSystem.cpp
	SteamAPI/ArkSteamDlcSystem.h
	SteamAPI/ArkSteamRewardSystem.cpp
	SteamAPI/ArkSteamRewardSystem.h
	SteamAPI/ChairSteamAPI.cpp
	SteamAPI/ChairSteamAPI.h
	
	ArkFixedRewardSystem.cpp
	ArkFixedRewardSystem.h
	ChairloaderPatches.cpp
	ChairloaderPatches.h
)

add_library(Chairloader.Patches STATIC ${SOURCE_FILES})
target_include_directories(Chairloader.Patches PRIVATE .)

target_link_libraries(Chairloader.Patches PUBLIC
	Chairloader.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
