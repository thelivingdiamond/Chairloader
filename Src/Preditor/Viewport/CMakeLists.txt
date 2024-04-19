set(SOURCE_FILES
	CMakeLists.txt
	BaseViewport.cpp
	BaseViewport.h
	GameViewport.cpp
	GameViewport.h
	SceneViewport.cpp
	SceneViewport.h
	ViewportWindow.cpp
	ViewportWindow.h
)

add_library(Preditor.Viewport STATIC
	${SOURCE_FILES}
)

target_include_directories(Preditor.Viewport PRIVATE
	.
)

target_link_libraries(Preditor.Viewport
	Preditor.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
