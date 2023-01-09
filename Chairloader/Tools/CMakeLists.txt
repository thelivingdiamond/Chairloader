set(SOURCE_FILES
	CMakeLists.txt
	
	Components/EntityHierarchy.cpp
	Components/EntityHierarchy.h
	Components/EntityInspector.cpp
	Components/EntityInspector.h

	Editor/Editor.cpp
	Editor/Editor.h
	Editor/EditorView.cpp
	Editor/EditorView.h
	Editor/ModReloading.cpp
	Editor/ModReloading.h

	Trainer/EntityManager.cpp
	Trainer/EntityManager.h
	Trainer/PlayerManager.cpp
	Trainer/PlayerManager.h
	Trainer/WorldManager.cpp
	Trainer/WorldManager.h

	ChairloaderTools.cpp
	ChairloaderTools.h
	DevConsoleDialog.cpp
	DevConsoleDialog.h
	FileBrowser.cpp
	FileBrowser.h
	HeaderTestFile.cpp
	PerfOverlay.cpp
	PerfOverlay.h
	README.md
		LocalizationUtil.cpp LocalizationUtil.h)

add_library(Chairloader.Tools STATIC ${SOURCE_FILES})
target_include_directories(Chairloader.Tools PRIVATE .)

target_link_libraries(Chairloader.Tools PUBLIC
	Chairloader.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
