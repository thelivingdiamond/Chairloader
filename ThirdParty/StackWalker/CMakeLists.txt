set(CMAKE_FOLDER "Third-Party")

add_library(StackWalker STATIC
	CMakeLists.txt
	StackWalker.cpp
	StackWalker.h
)

target_include_directories(StackWalker PUBLIC .)
