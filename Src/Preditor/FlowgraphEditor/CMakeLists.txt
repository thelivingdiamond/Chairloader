set(SOURCE_FILES
	CMakeLists.txt

	FlowgraphEditorWindow.cpp
	FlowgraphEditorWindow.h
	IFlowgraphEditor.cpp
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