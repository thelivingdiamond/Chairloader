set(SOURCE_FILES
	CMakeLists.txt
	main.cpp
	pch.h
	StringUtilsTest.cpp
)

add_executable(Common.Private.Tests ${SOURCE_FILES})

cl_output_to_data(Common.Private.Tests)
cl_version_info(Common.Private.Tests "Common.Private.Tests.exe" "Chairloader Common.Private Tests")

target_include_directories(Common.Private.Tests PRIVATE
	.
)

target_link_libraries(Common.Private.Tests
	Common.Private
	GTest::gtest
	GTest::gmock
)

target_precompile_headers(Common.Private.Tests PRIVATE pch.h)

gtest_discover_tests(
	Common.Private.Tests
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/Data
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
