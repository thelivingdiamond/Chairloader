set(SOURCE_FILES
	CMakeLists.txt

	Import/AssetImporter.cpp
	Import/AssetImporter.h
	Import/AssetImportSystem.cpp
	Import/AssetImportSystem.h
	Import/CopyAssetImporter.cpp
	Import/CopyAssetImporter.h

	Merging/Mergers/AssetMerger.cpp
	Merging/Mergers/AssetMerger.h
	Merging/Mergers/SymlinkAssetMerger.cpp
	Merging/Mergers/SymlinkAssetMerger.h

	Merging/Sources/AssetMergeSource.cpp
	Merging/Sources/AssetMergeSource.h
	Merging/Sources/DirectoryAssetMergeSource.cpp
	Merging/Sources/DirectoryAssetMergeSource.h
	Merging/Sources/ImportMergeSource.cpp
	Merging/Sources/ImportMergeSource.h
	Merging/Sources/ProjectMergeSource.cpp
	Merging/Sources/ProjectMergeSource.h

	Merging/AssetMergeExecutor.cpp
	Merging/AssetMergeExecutor.h
	Merging/AssetMergeSystem.cpp
	Merging/AssetMergeSystem.h
	Merging/MergeCache.cpp
	Merging/MergeCache.h

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
