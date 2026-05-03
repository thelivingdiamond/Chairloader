set(CMAKE_FOLDER "ChairManager")

set(SOURCE_FILES
	CMakeLists.txt
	
	# ImGui
	ImGui/imgui.h
	ImGui/imgui.cpp
	ImGui/imconfig.h
	ImGui/imgui_internal.h
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

	# ImGuiNodeEditor (thedmd/imgui-node-editor v0.9.4)
	ImGuiNodeEditor/crude_json.cpp
	ImGuiNodeEditor/crude_json.h
	ImGuiNodeEditor/imgui_bezier_math.h
	ImGuiNodeEditor/imgui_bezier_math.inl
	ImGuiNodeEditor/imgui_canvas.cpp
	ImGuiNodeEditor/imgui_canvas.h
	ImGuiNodeEditor/imgui_extra_math.h
	ImGuiNodeEditor/imgui_extra_math.inl
	ImGuiNodeEditor/imgui_node_editor.cpp
	ImGuiNodeEditor/imgui_node_editor.h
	ImGuiNodeEditor/imgui_node_editor_api.cpp
	ImGuiNodeEditor/imgui_node_editor_internal.h
	ImGuiNodeEditor/imgui_node_editor_internal.inl

	# ChairManager
	Manager/ConfigManager.cpp
	Manager/ConfigManager.h
	Manager/IconsMaterialDesign.h
	Manager/ImGuiFontList.cpp
	Manager/ImGuiFontList.h

	WinShell/WinShell.cpp
	WinShell/WinShell.h

	Wizard/ProgressWizardStage.cpp
	Wizard/ProgressWizardStage.h
	Wizard/WizardManager.cpp
	Wizard/WizardManager.h
	Wizard/WizardStage.cpp
	Wizard/WizardStage.h

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
