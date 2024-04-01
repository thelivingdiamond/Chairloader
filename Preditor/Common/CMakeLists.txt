set(SOURCE_FILES
	CMakeLists.txt

	App/AppImGui.cpp
	App/AppImGui.h
	App/Application.cpp
	App/Application.h
	App/AppModule.cpp
	App/AppModule.h
	App/AppStage.cpp
	App/AppStage.h
	App/IAppImGui.h
	App/SingletonAppStage.h

	ImGuizmo/ImGuizmo.cpp
	ImGuizmo/ImGuizmo.h
	ImGuizmo/ImZoomSlider.h
	
	Preditor/Assets/Common.h
	Preditor/Assets/IAssetSystem.h

	Preditor/EditTools/IEditToolManager.h

	Preditor/Engine/IPreditorEngine.h
	Preditor/Engine/ISimulationController.h

	Preditor/Input/Common.h
	Preditor/Input/IKeyAction.h
	Preditor/Input/IKeyActionSet.h
	Preditor/Input/IKeyboardInputSystem.h
	Preditor/Input/IKeyMap.h
	Preditor/Input/IMouseInputSystem.h
	Preditor/Input/IPreditorInput.h
	
	Preditor/Main/IPreditor.h
	Preditor/Main/IProject.h
	Preditor/Main/IUserProjectSettings.h
	
	Preditor/SceneEditor/Common.h
	Preditor/SceneEditor/I3DCursor.h
	Preditor/SceneEditor/ILevelSceneEditor.h
	Preditor/SceneEditor/IObjectManipulator.h
	Preditor/SceneEditor/ISceneEditor.h
	Preditor/SceneEditor/ISceneEditorManager.h
	Preditor/SceneEditor/IViewportHandler.h
	Preditor/SceneEditor/SelectionManager.cpp
	Preditor/SceneEditor/SelectionManager.h

	Preditor/Viewport/IViewport.h
	Preditor/Viewport/IViewportWindow.h

	Preditor/Environment.h
	Preditor/FileHistory.cpp
	Preditor/FileHistory.h
	Preditor/IChairloaderToolsPreditor.h
	Preditor/IntrusiveList.hpp
	Preditor/ListenerSet.h
	Preditor/MouseGuard.h
	Preditor/pch.h
	Preditor/PreditorConfig.cpp
	Preditor/PreditorConfig.h
	Preditor/PreditorFonts.h
	Preditor/PreditorPaths.h
	Preditor/PreditorTime.h
)

add_library(Preditor.Common STATIC ${SOURCE_FILES})
target_include_directories(Preditor.Common PUBLIC .)

target_compile_definitions(Preditor.Common PUBLIC
	PREDITOR
)

target_precompile_headers(Preditor.Common PUBLIC Preditor/pch.h)

target_link_libraries(Preditor.Common PUBLIC
	Boost::program_options
	Common
	CommonChairManager
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
