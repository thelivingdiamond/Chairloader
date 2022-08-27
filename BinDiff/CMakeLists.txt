set(SOURCE_FILES
	CMakeLists.txt
	main.cpp
)

add_executable(BinDiff ${SOURCE_FILES})

target_link_libraries(BinDiff
	CommonModLoader
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
