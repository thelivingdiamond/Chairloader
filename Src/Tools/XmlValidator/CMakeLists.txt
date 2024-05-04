set(SOURCE_FILES
	CMakeLists.txt
	main.cpp
)

add_executable(XmlValidator ${SOURCE_FILES})

cl_output_to_data(XmlValidator)
cl_version_info(XmlValidator "XmlValidator.exe" "Chairloader XML Validator")

target_link_libraries(XmlValidator
	Boost::program_options
	Common.Private
	ChairMerger
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
