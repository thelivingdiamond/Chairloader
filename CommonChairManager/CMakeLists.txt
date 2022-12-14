set(SOURCE_FILES
	CMakeLists.txt
	Manager/BinDiff.cpp
	Manager/BinDiff.h
	Manager/SHA256.cpp
	Manager/SHA256.h
)

add_library(CommonChairManager STATIC
	${SOURCE_FILES}
	../Common/pugixml/pugixml.hpp
	../Common/pugixml/pugiconfig.hpp
	../Common/pugixml/pugixml.cpp
)

target_include_directories(CommonChairManager PUBLIC
	.
	../Common/pugixml
)

target_link_libraries(CommonChairManager PUBLIC
	
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
