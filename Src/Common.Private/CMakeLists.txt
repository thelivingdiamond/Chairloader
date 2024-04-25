set(SOURCE_FILES
	CMakeLists.txt

	# ChairManager
	Manager/AttributeWildcard.h
	Manager/BinDiff.cpp
	Manager/BinDiff.h
	Manager/ILogger.h
	Manager/LogEntry.h
	Manager/LuaUtils.cpp
	Manager/LuaUtils.h
	Manager/MergingPolicy.h
	Manager/ModConfig.h
	Manager/ModInfo.cpp
	Manager/ModInfo.h
	Manager/ModListConfig.cpp
	Manager/ModListConfig.h
	Manager/NameToIdMap.h
	Manager/PreditorFiles.h
	Manager/SHA256.cpp
	Manager/SHA256.h
	Manager/GamePath.cpp
	Manager/GamePath.h
	Manager/IChairManager.h
	Manager/ThreadPool.h
	Manager/WildcardResolver.cpp
	Manager/WildcardResolver.h
	Manager/PugiUtils.h
	Manager/XMLMerger2.cpp
	Manager/XMLMerger2.h

	GUIUtils.h
	pch.h
	version_info.rc.in
)

add_library(Common.Private STATIC
	${SOURCE_FILES}
)

target_include_directories(Common.Private PUBLIC
	.
)

target_link_libraries(Common.Private PUBLIC
	Common
)

target_precompile_headers(Common.Private PUBLIC pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
