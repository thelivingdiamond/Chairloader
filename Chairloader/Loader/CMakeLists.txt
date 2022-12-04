set(SOURCE_FILES
	CMakeLists.txt
	dllmain.cpp
	mswsock_proxy.cpp
	mswsock_proxy.h
)

add_library(Chairloader.Loader SHARED ${SOURCE_FILES})
set_target_properties(Chairloader.Loader PROPERTIES OUTPUT_NAME "mswsock")
cl_output_dir(Chairloader.Loader "Binaries/Danielle/x64/Release")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
