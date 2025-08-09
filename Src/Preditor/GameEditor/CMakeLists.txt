set(SOURCE_FILES
	CMakeLists.txt
	EntityManipulator.cpp
	EntityManipulator.h
	EntitySelectionManager.cpp
	EntitySelectionManager.h
	EntitySpawner.cpp
	EntitySpawner.h
	GameEditMode.cpp
	GameEditMode.h
	GameViewportHandler.cpp
	GameViewportHandler.h
)

add_library(Preditor.GameEditor STATIC
	${SOURCE_FILES}
)

target_include_directories(Preditor.GameEditor PRIVATE
	.
)

target_link_libraries(Preditor.GameEditor
	Preditor.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
