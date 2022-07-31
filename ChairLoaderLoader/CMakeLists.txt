set(SOURCE_FILES
	CMakeLists.txt
	dllmain.cpp
	mswsock_proxy.cpp
	mswsock_proxy.h
)

add_library(ChairloaderLoader SHARED ${SOURCE_FILES})

set_target_properties(ChairloaderLoader PROPERTIES OUTPUT_NAME "mswsock")
cl_output_dir(ChairloaderLoader "Binaries/Danielle/x64/Release")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
