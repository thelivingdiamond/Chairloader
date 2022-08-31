set(SOURCE_FILES
	CMakeLists.txt
	ModLoader/BinDiff.cpp
	ModLoader/BinDiff.h
	ModLoader/SHA256.cpp
	ModLoader/SHA256.h
)

add_library(CommonModLoader STATIC
	${SOURCE_FILES}
	../Common/pugixml/pugixml.hpp
	../Common/pugixml/pugiconfig.hpp
	../Common/pugixml/pugixml.cpp
)

target_include_directories(CommonModLoader PUBLIC
	.
	../Common/pugixml
)

target_link_libraries(CommonModLoader PUBLIC
	
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
