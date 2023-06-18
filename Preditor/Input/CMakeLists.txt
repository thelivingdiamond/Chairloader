set(SOURCE_FILES
	CMakeLists.txt
	Action.cpp
	Action.h
	ActionBind.cpp
	ActionBind.h
	ActionSet.cpp
	ActionSet.h
	InputDebuggerWindow.cpp
	InputDebuggerWindow.h
	KeyMap.cpp
	KeyMap.h
	KeyboardInputSystem.cpp
	KeyboardInputSystem.h
	MouseInputSystem.cpp
	MouseInputSystem.h
	PreditorInput.cpp
	PreditorInput.h
)

add_library(Preditor.Input STATIC
	${SOURCE_FILES}
)

target_include_directories(Preditor.Input PRIVATE
	.
)

target_link_libraries(Preditor.Input
	Preditor.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
