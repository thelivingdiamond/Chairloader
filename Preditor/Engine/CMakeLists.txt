set(SOURCE_FILES
	CMakeLists.txt
	
	ArkUglySteamDlcSystem.cpp
	ArkUglySteamDlcSystem.h
	DebuggerConsoleOutput.cpp
	DebuggerConsoleOutput.h
	EngineSwapChainPatch.cpp
	EngineSwapChainPatch.h
	GameViewportPatch.cpp
	GameViewportPatch.h
	HardwareMousePatch.cpp
	HardwareMousePatch.h
	LevelEditorPatch.cpp
	LevelEditorPatch.h
	MainWindowResizePatch.cpp
	MainWindowResizePatch.h
	pch.h
	PreditorEngine.cpp
	PreditorEngine.h
	PreditorImGui.cpp
	PreditorImGui.h
	PreditorImGuiRenderer.cpp
	PreditorImGuiRenderer.h
	RendererGlobals.cpp
	RendererGlobals.h
	SimulationController.cpp
	SimulationController.h
)

add_library(Preditor.Engine STATIC ${SOURCE_FILES})
target_include_directories(Preditor.Engine PRIVATE .)
target_precompile_headers(Preditor.Engine PRIVATE pch.h)

target_link_libraries(Preditor.Engine PUBLIC
	Preditor.Common
	Chairloader.Common.Preditor
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
