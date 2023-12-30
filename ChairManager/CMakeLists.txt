set(SOURCE_FILES
	CMakeLists.txt
	#ImGuiStandalone
	UI.cpp
	UI.h
	#ChairManager
	ChairWizards/ChairInstallWizard.cpp
	ChairWizards/ChairInstallWizard.h
	ChairManager.cpp
	ChairManager.h
	ChairWizards/GamePathDialog.cpp
	ChairWizards/GamePathDialog.h
	GameVersion.cpp
	GameVersion.h
	pch.h
	main.cpp
	#Miscellaneous
	zipconf.h
	Resources/appicon.rc
	ChairWizards/ChairUninstallWizard.cpp
	ChairWizards/ChairUninstallWizard.h
	BinaryVersionCheck.h
	BinaryVersionCheck.cpp
	UpdateHandler.cpp 
	UpdateHandler.h 
	ChairWizards/ChairUpdateWizard.cpp 
	ChairWizards/ChairUpdateWizard.h 
	UpdateURL.h
	Mod.h
	Paths.h
	Merging/ChairMerger.cpp
	Merging/ChairMerger.h
	Merging/ChairMergerTest.cpp
	Merging/XMLMerger2Test.cpp
	Merging/FileChecksum.h
	Merging/HashUtils.h
	Merging/HashUtils.cpp
	Merging/HashUtilsTest.cpp
	Merging/ZipUtils.h
	Merging/ZipUtils.cpp
	Merging/ZipUtilsTest.cpp
	LuaUtilsTest.cpp
	CrashHandler.h
	CrashHandler.cpp
)

set(INCLUDE_DIRECTORIES
	.
	${LUABRIDGE_INCLUDE_DIRS}
	${LUA_INCLUDE_DIR}
)

set(LINK_LIBRARIES
	version.lib
	CommonChairManager
	libzip::zip
	ZLIB::ZLIB
	unofficial::curlpp::curlpp
	${Boost_LIBRARIES}
	GTest::gtest
	GTest::gmock
	libzip::zip
	libzippp::libzippp
	${LUA_LIBRARIES}
	StackWalker
	Dbghelp.lib
)

set(APP_ICON_RESOURCE_WINDOWS "Resources/appicon.rc")
set(Boost_USE_STATIC_LIBS ON)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

#-------------------------------------------------------------------------
# ChairManager (user executable, linked in GUI mode)
#-------------------------------------------------------------------------
add_executable(ChairManager WIN32
	${SOURCE_FILES}
)

target_include_directories(ChairManager PRIVATE ${INCLUDE_DIRECTORIES})
target_link_libraries(ChairManager ${LINK_LIBRARIES})
target_precompile_headers(ChairManager PRIVATE pch.h)

set_target_properties(ChairManager PROPERTIES
	VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Data"
)

cl_version_info(ChairManager "ChairManager.exe" "Chairloader Mod Manager")

#-------------------------------------------------------------------------
# ChairManager.Tests (test executable, linked in console mode)
#-------------------------------------------------------------------------
add_executable(ChairManager.Tests ${SOURCE_FILES})
target_include_directories(ChairManager.Tests PRIVATE ${INCLUDE_DIRECTORIES})

target_compile_definitions(ChairManager.Tests PRIVATE
	CHAIRMANAGER_TESTS
)

target_link_libraries(ChairManager.Tests ${LINK_LIBRARIES})
target_precompile_headers(ChairManager.Tests PRIVATE pch.h)

set_target_properties(ChairManager.Tests PROPERTIES
	VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Data"
)

cl_version_info(ChairManager.Tests "ChairManager.Tests.exe" "Chairloader Mod Manager Tests")

gtest_discover_tests(
	ChairManager.Tests
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Data
)
