set(SOURCE_FILES
	CMakeLists.txt
	
	ImGui/imconfig.h
	ImGui/imgui.cpp
	ImGui/imgui.h
	ImGui/imgui_demo.cpp
	ImGui/imgui_draw.cpp
	ImGui/imgui_impl_dx11.cpp
	ImGui/imgui_impl_dx11.h
	ImGui/imgui_impl_win32.cpp
	ImGui/imgui_impl_win32.h
	ImGui/imgui_internal.h
	ImGui/imgui_stdlib.cpp
	ImGui/imgui_stdlib.h
	ImGui/imgui_tables.cpp
	ImGui/imgui_widgets.cpp
	ImGui/imstb_rectpack.h
	ImGui/imstb_textedit.h
	ImGui/imstb_truetype.h
	
	chairloaderModManager.h
	ChairLoaderXMLLoader.cpp
	Drawing.cpp
	Drawing.h
	UI.cpp
	UI.h
	zipconf.h
)

add_executable(ChairloaderXMLLoader WIN32 ${SOURCE_FILES})

target_link_libraries(ChairloaderXMLLoader
	D3D11.lib
	pugixml::pugixml
	libzip::zip
	${Boost_LIBRARIES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
