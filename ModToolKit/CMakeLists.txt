set(SOURCE_FILES
	CMakeLists.txt
	
	App/AppImGui.cpp
	App/AppImGui.h
	App/Application.cpp
	App/Application.h
	App/AppStage.cpp
	App/AppStage.h
	
	GameModule.h
	LoadGameStage.cpp
	LoadGameStage.h
	MainConfig.cpp
	MainConfig.h
	ModToolKit.cpp
	ModToolKit.h
	pch.h
        FlowgraphEditor.cpp FlowgraphEditor.h)

add_executable(ModToolKit WIN32
	${SOURCE_FILES}

	# Some sources from Common
	../Common/Chairloader/FunctionHook.cpp
	../Common/Chairloader/PreyFunction.cpp
	../Common/Logging.cpp
	../Common/mem.cpp

	# This is horrible
	../Chairloader/DevConsoleDialog.cpp
	../Chairloader/DevConsoleDialog.h
)

target_include_directories(ModToolKit PRIVATE
	.
	../CommonModLoader # This must go first. Yes, it's all a huge mess.
	../Common # Can't link with Common since it conflicts with CommonModLoader. We only need the headers anyway.
)

target_compile_definitions(ModToolKit PRIVATE
	MODTOOLKIT
)

target_link_libraries(ModToolKit
	CommonModLoader
	D3D11.lib
	Detours::Detours
)

target_precompile_headers(ModToolKit PRIVATE pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
