set(SOURCE_FILES
        CMakeLists.txt
        #ImGuiStandalone
        UI.cpp
        UI.h
        #ModLoader
        ChairInstallWizard.cpp
        ChairInstallWizard.h
        ModLoader.cpp
        ModLoader.h
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
        ChairUninstallWizard.cpp
        ChairUninstallWizard.h
        BinaryVersionCheck.h
        BinaryVersionCheck.cpp XMLMerger.cpp XMLMerger.h ConfigManager.cpp ConfigManager.h)



set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc")

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/version.rc.in
        ${CMAKE_CURRENT_SOURCE_DIR}/version.rc
        @ONLY)

add_executable(ChairloaderModLoader WIN32 ${SOURCE_FILES})

target_link_libraries(ChairloaderModLoader
        version.lib
        CommonModLoader
        D3D11.lib
        libzip::zip
        ZLIB::ZLIB
        ${Boost_LIBRARIES}
        )

target_precompile_headers(ChairloaderModLoader PRIVATE pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
