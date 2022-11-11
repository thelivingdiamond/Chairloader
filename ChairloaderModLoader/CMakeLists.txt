set(SOURCE_FILES
        CMakeLists.txt
        #IMGUI
        ImGui/imgui.h
        ImGui/imgui.cpp
        ImGui/imconfig.h
        ImGUi/imgui_internal.h
        ImGui/imgui_demo.cpp
        ImGui/imgui_draw.cpp
        ImGui/imgui_impl_dx11.cpp
        ImGui/imgui_impl_dx11.h
        ImGui/imgui_impl_win32.cpp
        ImGui/imgui_impl_win32.h
        ImGui/imgui_stdlib.cpp
        ImGui/imgui_stdlib.h
        ImGui/imgui_tables.cpp
        ImGui/imgui_widgets.cpp
        ImGui/imstb_rectpack.h
        ImGui/imstb_textedit.h
        ImGui/imstb_truetype.h

        #ImGuiFileDialog
        ImGuiFileDialog/ImGuiFileDialog.h
        ImGuiFileDialog/ImGuiFileDialog.cpp

        #ImGuiStandalone
        UI.cpp
        UI.h
        #ModLoader
        ChairInstallWizard.cpp
        ChairInstallWizard.h
        ModLoader.cpp
        ModLoader.h
        PathUtils.cpp
        PathUtils.h
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
        BinaryVersionCheck.cpp XMLMerger.cpp XMLMerger.h ConfigManager.cpp ConfigManager.h UpdateHandler.cpp UpdateHandler.h)



set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc")

message(STATUS "Version: ${_CHAIRLOADER_VERSION_STR}")
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
        unofficial::curlpp::curlpp
        ${Boost_LIBRARIES}
        )

target_precompile_headers(ChairloaderModLoader PRIVATE pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
