set(SOURCE_FILES
	CMakeLists.txt

	# BinDiff
	BinDiff/BinDiff.cpp
	BinDiff/BinDiff.h

	# Chairloader
	Chairloader/Private/GTestMain.inl
	Chairloader/Private/ModPrefix.h
	Chairloader/Private/StringUtils.cpp
	Chairloader/Private/StringUtils.h
	Chairloader/Private/XmlUtils.cpp
	Chairloader/Private/XmlUtils.h

	# ChairManager
	Manager/FileHistory.cpp
	Manager/FileHistory.h
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
	Manager/XmlNamespaces.h

	# SHA256
	SHA256/SHA256.cpp
	SHA256/SHA256.h

	# Dependency Injection
	DependencyInjection/ServiceCollection.cpp
	DependencyInjection/ServiceCollection.h
	DependencyInjection/ServiceProvider.cpp
	DependencyInjection/ServiceProvider.h
	DependencyInjection/ServiceDescriptor.h
	DependencyInjection/ServiceLocator.h
	DependencyInjection/ServiceLocator.cpp

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
