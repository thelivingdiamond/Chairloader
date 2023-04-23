set(SOURCE_FILES
	CMakeLists.txt
	
	Project/Project.cpp
	Project/ProjectManager.cpp
	Project/UserProjectSettings.cpp

	Resources/Preditor.rc

	ConfigManager.cpp
	ConfigManager.h
	ConfigValidationStage.cpp
	ConfigValidationStage.h
	ExtractionOptions.h
	ExtractionStage.cpp
	ExtractionStage.h
	LoadGameStage.cpp
	LoadGameStage.h
	pch.h
	Preditor.cpp
	Preditor.h
	ProjectSelectStage.cpp
	ProjectSelectStage.h
	ProjectStage.cpp
	ProjectStage.h
)

add_executable(Preditor.Launcher WIN32
	${SOURCE_FILES}
)

target_include_directories(Preditor.Launcher PRIVATE
	.
)

target_link_libraries(Preditor.Launcher
	Preditor.Common
	Preditor.Engine
	Preditor.Main
	D3D11.lib
)

target_precompile_headers(Preditor.Launcher PRIVATE pch.h)
set_target_properties(Preditor.Launcher PROPERTIES OUTPUT_NAME "Preditor")

set_target_properties(Preditor.Launcher PROPERTIES
	VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/ChairManager/Data"
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
