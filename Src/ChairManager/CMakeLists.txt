set(CMAKE_FOLDER "ChairManager")

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
	LuaUtilsTest.cpp
	CrashHandler.h
	CrashHandler.cpp
)

set(INCLUDE_DIRECTORIES
	.
)

set(LINK_LIBRARIES
	version.lib
	ChairManager.Common
	ChairMerger
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

cl_output_to_data(ChairManager)
cl_version_info(ChairManager "ChairManager.exe" "Chairloader Mod Manager")
