set(SOURCE_FILES
	CMakeLists.txt

	# BinDiff
	BinDiff/BinDiff.cpp
	BinDiff/BinDiff.h

	# ChairManager
	Manager/ILogger.h
	Manager/LogEntry.h
	Manager/ModConfig.h
	Manager/ModInfo.cpp
	Manager/ModInfo.h
	Manager/ModListConfig.cpp
	Manager/ModListConfig.h
	Manager/PreditorFiles.h
	Manager/GamePath.cpp
	Manager/GamePath.h
	Manager/IChairManager.h
	Manager/ThreadPool.h
	Manager/PugiUtils.h
	Manager/SynchronizedData.h

	# SHA256
	SHA256/SHA256.cpp
	SHA256/SHA256.h

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
