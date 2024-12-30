set(SOURCE_FILES
	CMakeLists.txt
	main.cpp
)

add_executable(XsdGenerator ${SOURCE_FILES})

cl_output_to_data(XsdGenerator)
cl_version_info(XsdGenerator "XsdGenerator.exe" "Chairloader XML Schema Generator")

target_link_libraries(XsdGenerator
	Boost::program_options
	Common.Private
	ChairMerger
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
