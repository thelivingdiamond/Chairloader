find_library(DETOURS_LIB_PATH detours.lib)
find_path(DETOURS_INCLUDE_DIR detours/detours.h)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Detours DEFAULT_MSG DETOURS_LIB_PATH DETOURS_INCLUDE_DIR)

if(Detours_FOUND)
	add_library(Detours::Detours STATIC IMPORTED)
	set_target_properties(Detours::Detours PROPERTIES
		IMPORTED_LOCATION ${DETOURS_LIB_PATH}
	)
	target_include_directories(Detours::Detours INTERFACE ${DETOURS_INCLUDE_DIR})
endif()
