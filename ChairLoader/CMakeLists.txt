set(SOURCE_FILES
	CMakeLists.txt
	
	ImGui/imgui_widget_flamegraph.cpp
	ImGui/imgui_widget_flamegraph.h
	
	ChairLoader.cpp
	ChairLoader.h
	ChairloaderConfigManager.cpp
	ChairloaderConfigManager.h
	ChairloaderGui.cpp
	ChairloaderGui.h
	ChairLoaderImGui.cpp
	ChairLoaderImGui.h
	CScriptableBase.h
	CScriptBind_Ark.h
	DevConsoleDialog.cpp
	DevConsoleDialog.h
	dllmain.cpp
	EntityManager.cpp
	EntityManager.h
	GUIUtils.h
	Header.h
	HeaderTestFile.cpp
	LibD3D11.h
	OverlayLog.cpp
	OverlayLog.h
	pch.cpp
	PerfOverlay.cpp
	PerfOverlay.h
	PlayerManager.cpp
	PlayerManager.h
	Profiler.cpp
	Profiler.h
	pugiconfig.hpp
	pugixml.cpp
	pugixml.hpp
        )

add_library(Chairloader SHARED ${SOURCE_FILES})
target_link_libraries(Chairloader
	Common
)

cl_output_dir(Chairloader "Binaries/Danielle/x64/Release")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
