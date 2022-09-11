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
)

target_link_libraries(CommonModLoader PUBLIC
	
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
