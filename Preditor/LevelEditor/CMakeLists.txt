set(SOURCE_FILES
	CMakeLists.txt

	Components/Component.cpp
	Components/Component.h
	Components/ComponentList.cpp
	Components/ComponentList.h
	Components/EntityArchetypeComponent.cpp
	Components/EntityArchetypeComponent.h
	Components/Transform.cpp
	Components/Transform.h

	Objects/EntityObject.cpp
	Objects/EntityObject.h
	Objects/Object.cpp
	Objects/Object.h

	Utils/InspectorHelpers.cpp
	Utils/InspectorHelpers.h

	GlobalLevel.h
	LevelEditMode.cpp
	LevelEditMode.h
	LevelViewportHandler.cpp
	LevelViewportHandler.h
	ObjectManager.cpp
	ObjectManager.h
	ObjectSelectionManager.cpp
	ObjectSelectionManager.h
	pch.h
	RayIntersectInfo.h
)

add_library(Preditor.LevelEditor STATIC
	${SOURCE_FILES}
)

target_include_directories(Preditor.LevelEditor PRIVATE
	.
)

target_link_libraries(Preditor.LevelEditor
	Preditor.Common
)

target_precompile_headers(Preditor.LevelEditor PRIVATE pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
