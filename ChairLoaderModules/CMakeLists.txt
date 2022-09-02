set(SOURCE_FILES
        CMakeLists.txt

        Editor/Editor.cpp
	    Editor/Editor.h
	    Editor/EditorView.cpp
	    Editor/EditorView.h

        EntityHierarchy.cpp
        EntityHierarchy.h
        EntityManager.cpp
        EntityManager.h
        PlayerManager.cpp
        PlayerManager.h
        WorldManager.cpp
        WorldManager.h
        FileBrowser.cpp FileBrowser.h)

# ChairloaderModules static library
add_library(ChairloaderModules STATIC
        ${SOURCE_FILES}
        )

target_include_directories(ChairloaderModules PUBLIC
        .
        ImGui # FIXME: Remove from include path
        ${Boost_INCLUDE_DIRS}
        )

target_link_libraries(ChairloaderModules PUBLIC
        Common
        )

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
