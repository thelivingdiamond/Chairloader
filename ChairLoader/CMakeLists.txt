add_subdirectory(RenderDll)

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
	GUIUtils.h
	Header.h
	HeaderTestFile.cpp
	LibD3D11.h
	ModDllManager.cpp
	ModDllManager.h
	OverlayLog.cpp
	OverlayLog.h
	pch.cpp
	PerfOverlay.cpp
	PerfOverlay.h
	Profiler.cpp
	Profiler.h
	version.rc.in
	version.rc
)

configure_file(
		${CMAKE_CURRENT_SOURCE_DIR}/version.rc.in
		${CMAKE_CURRENT_SOURCE_DIR}/version.rc
		@ONLY)

add_library(Chairloader SHARED ${SOURCE_FILES})
target_link_libraries(Chairloader
	Common
	ChairloaderModules
	CryRenderD3D11
)

cl_output_dir(Chairloader "Binaries/Danielle/x64/Release")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
