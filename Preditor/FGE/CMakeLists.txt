set(SOURCE_FILES
	CMakeLists.txt
	Edge.h
	Flowgraph.cpp
	Flowgraph.h
	FlowgraphEditor.cpp
	FlowgraphEditor.h
	FlowgraphTab.cpp
	FlowgraphTab.h
	FlowgraphWindow.cpp
	FlowgraphWindow.h
	IChairFlowgraph.h
	Node.cpp
	Node.h
	pch.h
	Pin.h
	PreditorFlowgraph.cpp
	PreditorFlowgraph.h
	UniqueID.h
)

add_library(Preditor.FGE STATIC
	${SOURCE_FILES}
)

target_include_directories(Preditor.FGE PRIVATE
	.
)

target_link_libraries(Preditor.FGE
	Preditor.Common
)

target_precompile_headers(Preditor.FGE PRIVATE pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
