set(CMAKE_FOLDER "ChairManager")

set(SOURCE_FILES
	CMakeLists.txt
	MergingProcess.d2
	MergingProcess.png
	MergingProcess.svg

	Private/ChairMerger.cpp
	Private/DllMain.cpp
	Private/HashUtils.cpp
	Private/LuaUtils.cpp
	Private/README.md
	Private/WildcardResolver.cpp
	Private/XMLMerger2.cpp
	Private/ZipUtils.cpp

	Public/ChairMerger/AttributeWildcard.h
	Public/ChairMerger/ChairMerger.h
	Public/ChairMerger/FileChecksum.h
	Public/ChairMerger/HashUtils.h
	Public/ChairMerger/LuaUtils.h
	Public/ChairMerger/MergingPolicy.h
	Public/ChairMerger/NameToIdMap.h
	Public/ChairMerger/WildcardResolver.h
	Public/ChairMerger/XMLMerger2.h
	Public/ChairMerger/ZipUtils.h
)

add_library(ChairMerger SHARED
	${SOURCE_FILES}
)

cl_output_to_data(ChairMerger)
cl_version_info(ChairMerger "ChairMerger.dll" "Chairloader Mod Merger")
cl_generate_export_header(ChairMerger "ChairMerger" "CHAIRMERGER")

target_include_directories(ChairMerger PRIVATE
	Private
)

target_include_directories(ChairMerger PUBLIC
	Public
	${LUABRIDGE_INCLUDE_DIRS}
	${LUA_INCLUDE_DIR}
)

target_link_libraries(ChairMerger PUBLIC
	Common.Private
	${LUA_LIBRARIES}
	libzip::zip
	libzippp::libzippp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
