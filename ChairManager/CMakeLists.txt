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
        GamePathDialog.cpp
        GamePathDialog.h
        GameVersion.cpp
        GameVersion.h
        pch.h
        main.cpp
        #Miscellaneous
        zipconf.h
        ./Data/Montserrat-Regular.ttf
        appicon.rc
        version.rc.in
        version.rc
        ChairWizards/ChairUninstallWizard.cpp
        ChairWizards/ChairUninstallWizard.h
        BinaryVersionCheck.h
        BinaryVersionCheck.cpp XMLMerger.cpp XMLMerger.h ConfigManager.cpp ConfigManager.h UpdateHandler.cpp UpdateHandler.h ChairWizards/ChairUpdateWizard.cpp ChairWizards/ChairUpdateWizard.h UpdateURL.h)



set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc")

message(STATUS "Version: ${_CHAIRLOADER_VERSION_STR}")
configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/version.rc.in
        ${CMAKE_CURRENT_SOURCE_DIR}/version.rc
        @ONLY)

add_executable(ChairManager WIN32 ${SOURCE_FILES})

target_link_libraries(ChairManager
        version.lib
        CommonChairManager
        libzip::zip
        ZLIB::ZLIB
        unofficial::curlpp::curlpp
        ${Boost_LIBRARIES}
        )

target_precompile_headers(ChairManager PRIVATE pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
