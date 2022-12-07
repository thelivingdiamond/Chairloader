set(SOURCE_FILES
	CMakeLists.txt
	
	Resources/Preditor.rc

	LoadGameStage.cpp
	LoadGameStage.h
	ConfigManager.cpp
	ConfigManager.h
	Preditor.cpp
	Preditor.h
	pch.h
	FlowgraphEditor.cpp
	FlowgraphEditor.h
	Flowgraph/Flowgraph.cpp
	Flowgraph/Flowgraph.h
	Flowgraph/Pin.h
	Flowgraph/Node.h
	Flowgraph/Edge.h
	Flowgraph/UniqueID.h
	Flowgraph/Node.cpp
	Flowgraph/IChairFlowgraph.h
	ProjectManager.cpp
	ProjectManager.h
	Project.cpp
	Project.h
	ProjectStage.cpp
	ProjectStage.h
	ProjectSelectStage.cpp
	ProjectSelectStage.h
	ConfigValidationStage.cpp
	ConfigValidationStage.h
	LookingGlass.cpp
	LookingGlass.h
	LookingGlass/XMLReference.h
)

add_executable(Preditor.Exe WIN32
	${SOURCE_FILES}
)

target_include_directories(Preditor.Exe PRIVATE
	.
)

target_link_libraries(Preditor.Exe
	Preditor.Common
	Preditor.Engine
	D3D11.lib
)

target_precompile_headers(Preditor.Exe PRIVATE pch.h)
set_target_properties(Preditor.Exe PROPERTIES OUTPUT_NAME "Preditor")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
