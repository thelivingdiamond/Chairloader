set(SOURCE_FILES
	CMakeLists.txt

	Import/AssetImporter.cpp
	Import/AssetImporter.h
	Import/AssetImportSystem.cpp
	Import/AssetImportSystem.h
	Import/CopyAssetImporter.cpp
	Import/CopyAssetImporter.h

	AssetMetadata.cpp
	AssetMetadata.h
	AssetsCommon.h
	AssetSystem.cpp
	AssetSystem.h
)

add_library(Preditor.Assets STATIC
	${SOURCE_FILES}
)

target_include_directories(Preditor.Assets PRIVATE
	.
)

target_link_libraries(Preditor.Assets
	Preditor.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
