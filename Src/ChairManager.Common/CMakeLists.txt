set(SOURCE_FILES
	CMakeLists.txt
	
	# ImGui
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

	# ImGuiFileDialog
	ImGuiFileDialog/ImGuiFileDialog.h
	ImGuiFileDialog/ImGuiFileDialog.cpp

	# ImNodes
	ImNodes/imnodes.cpp
	ImNodes/imnodes.h
	ImNodes/imnodes_internal.h

	# ChairManager
	Manager/ConfigManager.cpp
	Manager/ConfigManager.h
	Manager/IconsMaterialDesign.h
	Manager/ImGuiFontList.cpp
	Manager/ImGuiFontList.h

	WinShell/WinShell.cpp
	WinShell/WinShell.h

	pch.h
)

add_library(ChairManager.Common STATIC
	${SOURCE_FILES}
)

target_include_directories(ChairManager.Common PUBLIC
	.
	ImGui
)

target_link_libraries(ChairManager.Common PUBLIC
	D3D11.lib
	Common.Private
)

target_precompile_headers(ChairManager.Common PUBLIC pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
