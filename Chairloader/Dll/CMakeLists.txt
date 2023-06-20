set(SOURCE_FILES
	CMakeLists.txt
	
	LuaDbgRes/LUADBG.ico
	LuaDbgRes/small.ico
	LuaDbgRes/toolbar1.bmp
	LuaDbgRes/TreeView.bmp

	Chairloader.cpp
	Chairloader.h
	dllmain.cpp
	version.rc
	version.rc.in
	WinConsole.cpp
	WinConsole.h
	ImportantClass.h
	ImportantClass.cpp
	LuaDebugger.rc
	LuaDebuggerResource.h
)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/version.rc.in
	${CMAKE_CURRENT_SOURCE_DIR}/version.rc
	@ONLY
)

add_library(Chairloader.Dll SHARED ${SOURCE_FILES})
target_include_directories(Chairloader.Dll PRIVATE .)

target_link_libraries(Chairloader.Dll PRIVATE
	Chairloader.Common
	Chairloader.Core
	Chairloader.CryRender
	Chairloader.Patches
	Chairloader.Tools
)

set_target_properties(Chairloader.Dll PROPERTIES OUTPUT_NAME "Chairloader")
cl_output_dir(Chairloader.Dll)
cl_set_debug_path(Chairloader.Dll)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
