set(SOURCE_FILES
	CMakeLists.txt

	Chairloader/IChairloaderCore.h
	Chairloader/IChairloaderCryRender.h
	Chairloader/IChairloaderDll.h
	Chairloader/IChairloaderModule.h
	Chairloader/IChairloaderTools.h
	Chairloader/IModDllManager.h

	GUIUtils.h
	LibD3D11.h
	imgui_widget_flamegraph.cpp
	imgui_widget_flamegraph.h
)

add_library(Chairloader.Common STATIC ${SOURCE_FILES})
target_include_directories(Chairloader.Common PUBLIC .)

target_link_libraries(Chairloader.Common PUBLIC
	Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
