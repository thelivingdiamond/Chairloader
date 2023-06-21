set(SOURCE_FILES
	CMakeLists.txt
	InputDebuggerWindow.cpp
	InputDebuggerWindow.h
	KeyAction.cpp
	KeyAction.h
	KeyActionBind.cpp
	KeyActionBind.h
	KeyActionSet.cpp
	KeyActionSet.h
	KeyBind.cpp
	KeyBind.h
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
	Dinput8.lib
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
