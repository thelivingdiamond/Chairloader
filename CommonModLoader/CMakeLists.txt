set(SOURCE_FILES
	CMakeLists.txt
	
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

	ImGuiFileDialog/ImGuiFileDialog.h
	ImGuiFileDialog/ImGuiFileDialog.cpp
	
	ModLoader/BinDiff.cpp
	ModLoader/BinDiff.h
	ModLoader/SHA256.cpp
	ModLoader/SHA256.h
	ModLoader/PathUtils.cpp
	ModLoader/PathUtils.h

	#ImGui Node Editor
	NodeEditor/Include/imgui_node_editor.h
	NodeEditor/Source/crude_json.cpp
	NodeEditor/Source/crude_json.h
	NodeEditor/Source/imgui_bezier_math.h
	NodeEditor/Source/imgui_bezier_math.inl
	NodeEditor/Source/imgui_canvas.cpp
	NodeEditor/Source/imgui_canvas.h
	NodeEditor/Source/imgui_extra_math.h
	NodeEditor/Source/imgui_extra_math.inl
	NodeEditor/Source/imgui_node_editor_api.cpp
	NodeEditor/Source/imgui_node_editor_internal.h
	NodeEditor/Source/imgui_node_editor_internal.inl
	NodeEditor/Source/imgui_node_editor.cpp
	NodeEditor/Support/imgui_node_editor.natvis
		)

add_library(CommonModLoader STATIC
	${SOURCE_FILES}
	../Common/pugixml/pugixml.hpp
	../Common/pugixml/pugiconfig.hpp
	../Common/pugixml/pugixml.cpp
)

target_include_directories(CommonModLoader PUBLIC
	.
	../Common/pugixml
		NodeEditor/Include
		NodeEditor/Source
		ImGui/
)

target_link_libraries(CommonModLoader PUBLIC
	
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
