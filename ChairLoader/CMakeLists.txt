set(SOURCE_FILES
	CMakeLists.txt
	
	ImGui/imgui_widget_flamegraph.cpp
	ImGui/imgui_widget_flamegraph.h
	
	RenderDll/D3DRenderAuxGeom.cpp
	RenderDll/D3DRenderAuxGeom.h
	RenderDll/DebugMarkers.cpp
	RenderDll/DebugMarkers.h
	RenderDll/RenderAuxGeom.cpp
	RenderDll/RenderAuxGeomPatch.cpp
	RenderDll/RenderAuxGeomPatch.h
	RenderDll/RenderCommandHandler.cpp
	RenderDll/RenderCommandHook.asm
	RenderDll/TextMessages.cpp
	
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
	OverlayLog.cpp
	OverlayLog.h
	pch.cpp
	PerfOverlay.cpp
	PerfOverlay.h
	Profiler.cpp
	Profiler.h
	pugiconfig.hpp
	pugixml.cpp
	pugixml.hpp
        )

if(RENDERDLL_DEBUG_MARKERS)
	set(RENDERDLL_DEBUG_MARKERS_DEFS RENDERDLL_DEBUG_MARKERS)
endif()

add_library(Chairloader SHARED ${SOURCE_FILES})
target_link_libraries(Chairloader
	Common
	ChairloaderModules
)

target_compile_definitions(Chairloader PRIVATE
	${RENDERDLL_DEBUG_MARKERS_DEFS}
)

cl_output_dir(Chairloader "Binaries/Danielle/x64/Release")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
