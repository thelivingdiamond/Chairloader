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
	
	Preditor/Project/Project.h
	Preditor/Project/ProjectManager.h
	Preditor/Project/UserProjectSettings.h

	Preditor/IPreditorEngine.h
)

add_library(Preditor.Common STATIC ${SOURCE_FILES})
target_include_directories(Preditor.Common PUBLIC .)

target_compile_definitions(Preditor.Common PUBLIC
	PREDITOR
)

target_link_libraries(Preditor.Common PUBLIC
	Common
	CommonChairManager
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
