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
	Manager/AttributeWildcard.h
	Manager/BinDiff.cpp
	Manager/BinDiff.h
	Manager/ConfigManager.cpp
	Manager/ConfigManager.h
	Manager/IconsMaterialDesign.h
	Manager/ILogger.h
	Manager/ImGuiFontList.cpp
	Manager/ImGuiFontList.h
	Manager/LogEntry.h
	Manager/LuaUtils.cpp
	Manager/LuaUtils.h
	Manager/MergingPolicy.h
	Manager/ModConfig.h
	Manager/ModListConfig.cpp
	Manager/ModListConfig.h
	Manager/NameToIdMap.h
	Manager/pch.h
	Manager/PreditorFiles.h
	Manager/SHA256.cpp
	Manager/SHA256.h
	Manager/GamePath.cpp
	Manager/GamePath.h
	Manager/IChairManager.h
	Manager/ThreadPool.h
	Manager/WildcardResolver.cpp
	Manager/WildcardResolver.h
	Manager/PugiUtils.h
	Manager/XMLMerger2.cpp
	Manager/XMLMerger2.h

	WinShell/WinShell.cpp
	WinShell/WinShell.h

	version_info.rc.in
)

add_library(CommonChairManager STATIC
	${SOURCE_FILES}
	../Common/pugixml/pugixml.hpp
	../Common/pugixml/pugiconfig.hpp
	../Common/pugixml/pugixml.cpp
)

target_include_directories(CommonChairManager PUBLIC
	.
	ImGui
	../Common/pugixml
)

target_link_libraries(CommonChairManager PUBLIC
	D3D11.lib
	fmt::fmt-header-only
	Common
)

target_precompile_headers(CommonChairManager PUBLIC Manager/pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
