set(SOURCE_FILES
	CMakeLists.txt
	ChairloaderLoader.cpp
	ChairloaderLoader.h
	dllmain.cpp
	GameModuleInfo.cpp
	GameModuleInfo.h
	GameVersionInfo.h
	mswsock_proxy.cpp
	mswsock_proxy.h
	pch.h
)

add_library(Chairloader.Loader SHARED ${SOURCE_FILES})

target_link_libraries(Chairloader.Loader PRIVATE
	Common
	Shell32.lib
)

set_target_properties(Chairloader.Loader PROPERTIES
	OUTPUT_NAME "mswsock"
)

target_precompile_headers(Chairloader.Loader PRIVATE pch.h)

cl_output_to_game_dir(Chairloader.Loader)
cl_set_debug_path(Chairloader.Loader)

cl_version_info(Chairloader.Loader "mswsock.dll" "Chairloader Mod Loader Loader")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
