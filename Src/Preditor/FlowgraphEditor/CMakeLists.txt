set(SOURCE_FILES
	CMakeLists.txt

	FlowgraphEditorWindow.cpp
	FlowgraphEditorWindow.h
	GraphTab.cpp
	GraphTab.h
	IFlowgraphEditor.cpp

	IO/XmlSerializer.cpp
	IO/XmlSerializer.h

	Model/Flowgraph.cpp
	Model/Flowgraph.h

	Registry/NodeRegistry.cpp
	Registry/NodeRegistry.h
	Registry/PrototypeNode.cpp
	Registry/PrototypeNode.h
)

add_library(Preditor.FlowgraphEditor STATIC
	${SOURCE_FILES}
)

target_include_directories(Preditor.FlowgraphEditor PRIVATE
	.
)

target_link_libraries(Preditor.FlowgraphEditor
	Preditor.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})