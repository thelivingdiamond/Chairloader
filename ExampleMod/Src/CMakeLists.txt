set(MOD_NAME ExampleMod) # CHANGE ME

set(SOURCE_FILES
	CMakeLists.txt
	ModMain.cpp
	ModMain.h
	pch.h
)

add_library(${MOD_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${MOD_NAME}
	CommonMod
)

target_precompile_headers(${MOD_NAME} PRIVATE pch.h)
mod_output_dir(${MOD_NAME} MOD)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
