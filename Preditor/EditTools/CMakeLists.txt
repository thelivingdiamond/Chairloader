set(SOURCE_FILES
	CMakeLists.txt
	EditTool.cpp
	EditTool.h
	EditToolManager.cpp
	EditToolManager.h
	MoveTool.cpp
	MoveTool.h
	SelectTool.cpp
	SelectTool.h
	ToolSelectionWindow.cpp
	ToolSelectionWindow.h
)

add_library(Preditor.EditTools STATIC
	${SOURCE_FILES}
)

target_include_directories(Preditor.EditTools PRIVATE
	.
)

target_link_libraries(Preditor.EditTools
	Preditor.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
