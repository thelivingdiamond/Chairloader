if (Detours_FOUND)
	return()
endif()

find_path(DETOURS_INCLUDE_DIR detours/detours.h)
get_filename_component(DETOURS_INSTALL_DIR ${DETOURS_INCLUDE_DIR} DIRECTORY)
set(DETOURS_RELEASE_DIR ${DETOURS_INSTALL_DIR}/lib)
find_library(DETOURS_LIB_PATH detours.lib PATHS ${DETOURS_RELEASE_DIR} NO_DEFAULT_PATH)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Detours DEFAULT_MSG DETOURS_LIB_PATH DETOURS_INCLUDE_DIR)

if(Detours_FOUND)
	add_library(Detours::Detours STATIC IMPORTED)
	set_target_properties(Detours::Detours PROPERTIES
		IMPORTED_LOCATION ${DETOURS_LIB_PATH}
		IMPORTED_LOCATION_RELEASE ${DETOURS_LIB_PATH}
	)
	target_include_directories(Detours::Detours INTERFACE ${DETOURS_INCLUDE_DIR})
endif()

unset(DETOURS_RELEASE_DIR)
