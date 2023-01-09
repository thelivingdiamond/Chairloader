set(SHARED_SOURCE_FILES
	# Shared between Chairloader and Preditor
	CMakeLists.txt
	
	Components/EntityHierarchy.cpp
	Components/EntityHierarchy.h
	Components/EntityInspector.cpp
	Components/EntityInspector.h
	
	Editor/ModReloading.cpp
	Editor/ModReloading.h

	ChairToolsUtils.cpp
	ChairToolsUtils.h
	DevConsoleDialog.cpp
	DevConsoleDialog.h
	FileBrowser.cpp
	FileBrowser.h
	README.md
)

set(CHAIR_SOURCE_FILES
	# Only in Chairloader
	Editor/Editor.cpp
	Editor/Editor.h
	Editor/EditorView.cpp
	Editor/EditorView.h

	Trainer/EntityManager.cpp
	Trainer/EntityManager.h
	Trainer/PlayerManager.cpp
	Trainer/PlayerManager.h
	Trainer/WorldManager.cpp
	Trainer/WorldManager.h
	
	ChairloaderTools.cpp
	ChairloaderTools.h
	HeaderTestFile.cpp
	LocalizationUtil.cpp
	LocalizationUtil.h
	PerfOverlay.cpp
	PerfOverlay.h
)

set(PREDITOR_SOURCE_FILES
	# Only in Preditor
	ChairloaderToolsPreditor.cpp
	ChairloaderToolsPreditor.h
)

# Chairloader.Tools
add_library(Chairloader.Tools STATIC ${SHARED_SOURCE_FILES} ${CHAIR_SOURCE_FILES})
target_include_directories(Chairloader.Tools PRIVATE .)

target_link_libraries(Chairloader.Tools PUBLIC
	Chairloader.Common
)

# Chairloader.Tools.Preditor
add_library(Chairloader.Tools.Preditor STATIC ${SHARED_SOURCE_FILES} ${PREDITOR_SOURCE_FILES})
target_include_directories(Chairloader.Tools.Preditor PRIVATE .)

target_link_libraries(Chairloader.Tools.Preditor PUBLIC
	Chairloader.Common.Preditor
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SHARED_SOURCE_FILES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CHAIR_SOURCE_FILES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${PREDITOR_SOURCE_FILES})
