set(SOURCE_FILES
	CMakeLists.txt

	Cache/MemoryXmlCacheTest.cpp

	ChairMergerTestBase.cpp
	ChairMergerTestBase.h
	HashUtilsTest.cpp
	LuaUtilsTest.cpp
	main.cpp
	ModMerging.cpp
	pch.h
	Wildcards.cpp
	XMLMerger2Test.cpp
	XmlTestUtils.cpp
	XmlTestUtils.h
	ZipUtilsTest.cpp
)

add_executable(ChairMerger.Tests ${SOURCE_FILES})

cl_output_to_data(ChairMerger.Tests)
cl_version_info(ChairMerger.Tests "ChairMerger.Tests.exe" "Chairloader Mod Merger Tests")

target_include_directories(ChairMerger.Tests PRIVATE
	.
	../Private
)

target_link_libraries(ChairMerger.Tests
	ChairMerger
	ChairManager.Common # TODO 2024-04-26: Remove once config is separate
	GTest::gtest
	GTest::gmock
)

target_precompile_headers(ChairMerger.Tests PRIVATE pch.h)

gtest_discover_tests(
	ChairMerger.Tests
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/Data
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
