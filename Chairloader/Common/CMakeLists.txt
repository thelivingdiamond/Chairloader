set(SOURCE_FILES
	CMakeLists.txt

	Chairloader/ChairXmlUtils.cpp
	Chairloader/ChairXmlUtils.h
	Chairloader/IChairloaderCore.h
	Chairloader/IChairloaderCryRender.h
	Chairloader/IChairloaderDll.h
	Chairloader/IChairloaderModule.h
	Chairloader/IChairloaderPatches.h
	Chairloader/IChairloaderTools.h
	Chairloader/ILogManager.h
	Chairloader/IModDllManager.h

	ConsoleColorParser.cpp
	ConsoleColorParser.h
	GUIUtils.h
	LibD3D11.h
	imgui_widget_flamegraph.cpp
	imgui_widget_flamegraph.h
		Chairloader/IChairVarManager.h)

add_library(Chairloader.Common STATIC ${SOURCE_FILES})
target_include_directories(Chairloader.Common PUBLIC .)

target_link_libraries(Chairloader.Common PUBLIC
	Common
	Chairloader.ImGui
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
