set(SOURCE_FILES
	CMakeLists.txt
	
	App/AppImGui.cpp
	App/AppImGui.h
	App/Application.cpp
	App/Application.h
	App/AppStage.cpp
	App/AppStage.h
	
	GameModule.cpp
	GameModule.h
	LoadGameStage.cpp
	LoadGameStage.h
		ConfigManager.cpp
		ConfigManager.h
		Preditor.cpp
        Preditor.h
	pch.h
        FlowgraphEditor.cpp
		FlowgraphEditor.h
		Flowgraph/Flowgraph.cpp
		Flowgraph/Flowgraph.h
		Flowgraph/Pin.h
		Flowgraph/Node.h
		Flowgraph/Edge.h
		Flowgraph/UniqueID.h Flowgraph/Node.cpp Flowgraph/IChairFlowgraph.h ProjectManager.cpp ProjectManager.h Project.cpp Project.h ProjectSelectStage.cpp ProjectSelectStage.h App/AppModule.cpp App/AppModule.h ConfigValidationStage.cpp ConfigValidationStage.h LookingGlass.cpp LookingGlass.h LookingGlass/XMLReference.h)

add_executable(Preditor WIN32
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

target_include_directories(Preditor PRIVATE
	.
	../CommonModLoader # This must go first. Yes, it's all a huge mess.
	../Common # Can't link with Common since it conflicts with CommonModLoader. We only need the headers anyway.
)

target_compile_definitions(Preditor PRIVATE
	PREDITOR
)

target_link_libraries(Preditor
	CommonModLoader
	D3D11.lib
	Detours::Detours
)

target_precompile_headers(Preditor PRIVATE pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
