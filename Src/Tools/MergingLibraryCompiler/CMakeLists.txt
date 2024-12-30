set(SOURCE_FILES
	CMakeLists.txt
	main.cpp
)

add_executable(MergingLibraryCompiler ${SOURCE_FILES})

cl_output_to_data(MergingLibraryCompiler)
cl_version_info(MergingLibraryCompiler "MergingLibraryCompiler.exe" "Chairloader Merging Library Compiler")

target_link_libraries(MergingLibraryCompiler
	Boost::program_options
	Common.Private
	ChairMerger
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
