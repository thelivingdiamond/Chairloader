set(SOURCE_FILES
	CMakeLists.txt
	BackupDxState.cpp
	BackupDxState.h
	ChairImGui.cpp
	ChairImGui.h
	ChairloaderConfigManager.cpp
	ChairloaderConfigManager.h
	ChairloaderCore.cpp
	ChairloaderCore.h
	ChairloaderGui.cpp
	ChairloaderGui.h
	ChairLogger.cpp
	ChairLogger.h
	ImGuiDoubleBuffering.h
	ImGuiRendererD3D11.cpp
	ImGuiRendererD3D11.h
	LogManager.cpp
	LogManager.h
	ModDllManager.cpp
	ModDllManager.h
	OverlayLog.cpp
	OverlayLog.h
	Profiler.cpp
	Profiler.h
        ChairVarManager.cpp ChairVarManager.h)

add_library(Chairloader.Core STATIC ${SOURCE_FILES})
target_include_directories(Chairloader.Core PRIVATE .)

target_link_libraries(Chairloader.Core PUBLIC
	Chairloader.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
