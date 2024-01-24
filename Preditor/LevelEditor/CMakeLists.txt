set(SOURCE_FILES
	CMakeLists.txt

	Components/AreaProxyComponent.cpp
	Components/AreaProxyComponent.h
	Components/BBoxComponent.cpp
	Components/BBoxComponent.h
	Components/Component.cpp
	Components/Component.h
	Components/ComponentList.cpp
	Components/ComponentList.h
	Components/EntityArchetypeComponent.cpp
	Components/EntityArchetypeComponent.h
	Components/EntityComponent.cpp
	Components/EntityComponent.h
	Components/EntityProxyComponent.cpp
	Components/EntityProxyComponent.h
	Components/EntityScriptComponent.cpp
	Components/EntityScriptComponent.h
	Components/Transform.cpp
	Components/Transform.h

	Objects/EntityObject.cpp
	Objects/EntityObject.h
	Objects/Object.cpp
	Objects/Object.h

	Utils/AffineParts.cpp
	Utils/AffineParts.h
	Utils/AuxGeomComponent.cpp
	Utils/AuxGeomComponent.h
	Utils/InspectorHelpers.cpp
	Utils/InspectorHelpers.h
	Utils/ScriptTableEditor.cpp
	Utils/ScriptTableEditor.h

	AuxGeomManager.cpp
	AuxGeomManager.h
	GlobalLevel.h
	LevelEditMode.cpp
	LevelEditMode.h
	LevelViewportHandler.cpp
	LevelViewportHandler.h
	ObjectManager.cpp
	ObjectManager.h
	ObjectManipulator.cpp
	ObjectManipulator.h
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
