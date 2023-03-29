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
        ./Data/Montserrat-Regular.ttf
        Resources/appicon.rc
        Resources/version.rc.in
        Resources/version.rc
        ChairWizards/ChairUninstallWizard.cpp
        ChairWizards/ChairUninstallWizard.h
        BinaryVersionCheck.h
        BinaryVersionCheck.cpp XMLMerger.cpp XMLMerger.h ConfigManager.cpp ConfigManager.h UpdateHandler.cpp UpdateHandler.h ChairWizards/ChairUpdateWizard.cpp ChairWizards/ChairUpdateWizard.h UpdateURL.h LogEntry.h Mod.h)



set(APP_ICON_RESOURCE_WINDOWS "Resources/appicon.rc")

message(STATUS "Version: ${_CHAIRLOADER_VERSION_STR}")
configure_file(
        Resources/version.rc.in
        Resources/version.rc
        @ONLY)

add_executable(ChairManager WIN32 ${SOURCE_FILES})
target_include_directories(ChairManager PRIVATE .)

target_link_libraries(ChairManager
        version.lib
        CommonChairManager
        libzip::zip
        ZLIB::ZLIB
        unofficial::curlpp::curlpp
        ${Boost_LIBRARIES}
		GTest::gtest
		GTest::gmock
		)
gtest_discover_tests(ChairManager EXTRA_ARGS --gtest WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Data DISCOVERY_TIMEOUT 60)


target_precompile_headers(ChairManager PRIVATE pch.h)

set_target_properties(ChairManager PROPERTIES
	VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Data"
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
