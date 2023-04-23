set(SOURCE_FILES
	CMakeLists.txt

	Chairloader/ChairXmlUtils.cpp
	Chairloader/ChairXmlUtils.h
	Chairloader/IChairloaderCore.h
	Chairloader/IChairloaderCryRender.h
	Chairloader/IChairloaderDll.h
	Chairloader/IChairloaderModule.h
	Chairloader/IChairloaderTools.h
	Chairloader/IChairToPreditor.h
	Chairloader/IChairVarManager.h
	Chairloader/ILogManager.h
	Chairloader/IModDllManager.h
	Chairloader/IPreditorToChair.h
	Chairloader/PreditorAPI.h

	BackupDxState.cpp
	BackupDxState.h
	ConsoleColorParser.cpp
	ConsoleColorParser.h
	GUIUtils.h
	imgui_widget_flamegraph.cpp
	imgui_widget_flamegraph.h
	ImGuiDoubleBuffering.h
	ImGuiRendererD3D11.cpp
	ImGuiRendererD3D11.h
	LibD3D11.h
)

set(SOURCE_FILES_WINDOW_MANAGER
	# WindowManager needs ImGui
	../../Common/WindowManager/IManagedWindow.h
	../../Common/WindowManager/ManagedWindow.cpp
	../../Common/WindowManager/ManagedWindow.h
	../../Common/WindowManager/WindowManager.cpp
	../../Common/WindowManager/WindowManager.h
)

#-----------------------------------------------------------
# Chairloader.Common
#-----------------------------------------------------------
add_library(Chairloader.Common STATIC ${SOURCE_FILES} ${SOURCE_FILES_WINDOW_MANAGER})
target_include_directories(Chairloader.Common PUBLIC .)

target_link_libraries(Chairloader.Common PUBLIC
	Common
	Chairloader.ImGui
)

#-----------------------------------------------------------
# Chairloader.Common.Preditor
#-----------------------------------------------------------
add_library(Chairloader.Common.Preditor STATIC ${SOURCE_FILES} ${SOURCE_FILES_WINDOW_MANAGER})
target_include_directories(Chairloader.Common.Preditor PUBLIC .)

target_link_libraries(Chairloader.Common.Preditor PUBLIC
	Preditor.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/../../Common" FILES ${SOURCE_FILES_WINDOW_MANAGER})
