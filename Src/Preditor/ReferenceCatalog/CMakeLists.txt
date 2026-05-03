set(SOURCE_FILES
	CMakeLists.txt

	Catalog.cpp
	IReferenceCatalogUI.cpp
	KindRegistry.cpp
	Table.cpp

	Providers/XmlFileProvider.cpp

	UI/CatalogBrowserWindow.cpp
	UI/CatalogBrowserWindow.h
)

add_library(Preditor.ReferenceCatalog STATIC
	${SOURCE_FILES}
)

target_include_directories(Preditor.ReferenceCatalog PRIVATE
	.
)

target_link_libraries(Preditor.ReferenceCatalog
	Preditor.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
