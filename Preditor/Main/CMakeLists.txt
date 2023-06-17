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
	Project/Project.h
	Project/UserProjectSettings.cpp
	Project/UserProjectSettings.h

	UI/PreditorUI.cpp
	UI/PreditorUI.h

	EntityHierarchyWindow.cpp
	EntityHierarchyWindow.h
	FlowgraphEditor.cpp
	FlowgraphEditor.h
	GameViewport.cpp
	GameViewport.h
	InspectorWindow.cpp
	InspectorWindow.h
	LookingGlass.cpp
	LookingGlass.h
	Preditor.cpp
	Preditor.h
	SceneViewport.cpp
	SceneViewport.h
	SimControlWindow.cpp
	SimControlWindow.h
)

add_library(Preditor.Main STATIC
	${SOURCE_FILES}
)

target_include_directories(Preditor.Main PRIVATE
	.
)

target_link_libraries(Preditor.Main
	Chairloader.Tools.Preditor
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
