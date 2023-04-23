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
	
	Preditor/Engine/IPreditorEngine.h
	Preditor/Engine/ISimulationController.h

	Preditor/Project/Project.h
	Preditor/Project/ProjectManager.h
	Preditor/Project/UserProjectSettings.h

	Preditor/Environment.h
	Preditor/IChairloaderToolsPreditor.h
	Preditor/IGameViewport.h
	Preditor/pch.h
	Preditor/PreditorConfig.cpp
	Preditor/PreditorConfig.h
	Preditor/PreditorPaths.h
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
