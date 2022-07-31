# Grab all files in Common directory
file(GLOB_RECURSE SOURCE_FILES
	LIST_DIRECTORIES false
	CONFIGURE_DEPENDS
	*.*
)

# CommonMod static library
add_library(Common STATIC
	${SOURCE_FILES}
)

target_include_directories(Common PUBLIC
	.
	ImGui # FIXME: Remove from include path
	${Boost_INCLUDE_DIRS}
)

target_link_libraries(Common PUBLIC
	pugixml::pugixml
	detours
)

target_precompile_headers(Common PUBLIC Chairloader/pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
