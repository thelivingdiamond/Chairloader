set(SOURCE_FILES
	CMakeLists.txt

	Project/Project.cpp
	Project/Project.h
	Project/UserProjectSettings.cpp
	Project/UserProjectSettings.h

	UI/FileViewers/FileFormats.cpp
	UI/FileViewers/FileFormats.h
	UI/FileViewers/HexViewer.cpp
	UI/FileViewers/HexViewer.h

	UI/ArkLibraryExplorer.cpp
	UI/ArkLibraryExplorer.h
	UI/FileBrowser.cpp
	UI/FileBrowser.h
	UI/HierarchyWindow.cpp
	UI/HierarchyWindow.h
	UI/InspectorWindow.cpp
	UI/InspectorWindow.h
	UI/PreditorUI.cpp
	UI/PreditorUI.h
	UI/SelectionWindow.cpp
	UI/SelectionWindow.h
	UI/SimControlWindow.cpp
	UI/SimControlWindow.h

	EntityHierarchyWindow.cpp
	EntityHierarchyWindow.h
	LookingGlass.cpp
	LookingGlass.h
	Preditor.cpp
	Preditor.h
	SceneEditorManager.cpp
	SceneEditorManager.h
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
