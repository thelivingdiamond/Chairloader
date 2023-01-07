set(SOURCE_FILES
	CMakeLists.txt

	Flowgraph/Flowgraph.cpp
	Flowgraph/Flowgraph.h
	Flowgraph/Pin.h
	Flowgraph/Node.h
	Flowgraph/Edge.h
	Flowgraph/UniqueID.h
	Flowgraph/Node.cpp
	Flowgraph/IChairFlowgraph.h
	
	Project/Project.cpp
	Project/ProjectManager.cpp
	Project/UserProjectSettings.cpp

	Resources/Preditor.rc

	ConfigManager.cpp
	ConfigManager.h
	ConfigValidationStage.cpp
	ConfigValidationStage.h
	EntityHierarchyWindow.cpp
	EntityHierarchyWindow.h
	FlowgraphEditor.cpp
	FlowgraphEditor.h
	GameViewport.cpp
	GameViewport.h
	InspectorWindow.cpp
	InspectorWindow.h
	LoadGameStage.cpp
	LoadGameStage.h
	LookingGlass.cpp
	LookingGlass.h
	Preditor.cpp
	Preditor.h
	ProjectSelectStage.cpp
	ProjectSelectStage.h
	ProjectStage.cpp
	ProjectStage.h
	SceneViewport.cpp
	SceneViewport.h
	pch.h
)

add_executable(Preditor.Exe WIN32
	${SOURCE_FILES}
)

target_include_directories(Preditor.Exe PRIVATE
	.
)

target_link_libraries(Preditor.Exe
	Chairloader.Tools.Preditor
	Preditor.Common
	Preditor.Engine
	D3D11.lib
)

target_precompile_headers(Preditor.Exe PRIVATE pch.h)
set_target_properties(Preditor.Exe PROPERTIES OUTPUT_NAME "Preditor")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
