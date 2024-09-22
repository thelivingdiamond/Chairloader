set(SOURCE_FILES
	CMakeLists.txt
	main.cpp
)

add_executable(LegacyModConverter ${SOURCE_FILES})

cl_output_to_data(LegacyModConverter)
cl_version_info(LegacyModConverter "LegacyModConverter.exe" "Legacy -> Chairloader Mod Converter")

target_link_libraries(LegacyModConverter
	Boost::program_options
	Common.Private
	ChairMerger
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
