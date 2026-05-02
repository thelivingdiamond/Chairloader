set(SOURCE_FILES
	CMakeLists.txt

	FlowgraphEditorWindow.cpp
	FlowgraphEditorWindow.h
	GraphTab.cpp
	GraphTab.h
	IFlowgraphEditor.cpp

	Commands/AddNodeCmd.cpp
	Commands/AddNodeCmd.h
	Commands/AddTokenCmd.cpp
	Commands/AddTokenCmd.h
	Commands/CommandHistory.cpp
	Commands/CommandHistory.h
	Commands/CompositeCommand.cpp
	Commands/CompositeCommand.h
	Commands/ConnectPinsCmd.cpp
	Commands/ConnectPinsCmd.h
	Commands/ICommand.h
	Commands/ModifyTokenCmd.cpp
	Commands/ModifyTokenCmd.h
	Commands/MoveNodeCmd.cpp
	Commands/MoveNodeCmd.h
	Commands/RemoveEdgeCmd.cpp
	Commands/RemoveEdgeCmd.h
	Commands/RemoveNodeCmd.cpp
	Commands/RemoveNodeCmd.h
	Commands/RemoveTokenCmd.cpp
	Commands/RemoveTokenCmd.h
	Commands/RenameNodeCmd.cpp
	Commands/RenameNodeCmd.h
	Commands/SetPortDefaultCmd.cpp
	Commands/SetPortDefaultCmd.h

	IO/PathResolver.cpp
	IO/PathResolver.h
	IO/XmlSerializer.cpp
	IO/XmlSerializer.h

	Model/Flowgraph.cpp
	Model/Flowgraph.h

	Registry/NodeRegistry.cpp
	Registry/NodeRegistry.h
	Registry/PrototypeNode.cpp
	Registry/PrototypeNode.h

	UI/GraphBrowserWindow.cpp
	UI/GraphBrowserWindow.h
	UI/GraphTokensWindow.cpp
	UI/GraphTokensWindow.h
	UI/NodePaletteWindow.cpp
	UI/NodePaletteWindow.h
	UI/PropertyInspectorWindow.cpp
	UI/PropertyInspectorWindow.h
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