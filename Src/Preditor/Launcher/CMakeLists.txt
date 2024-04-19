set(SOURCE_FILES
	CMakeLists.txt

	Resources/Preditor.rc

	ConfigValidationStage.cpp
	ConfigValidationStage.h
	ExtractionOptions.h
	ExtractionStage.cpp
	ExtractionStage.h
	LoadGameStage.cpp
	LoadGameStage.h
	MainStage.cpp
	MainStage.h
	PreditorApp.cpp
	PreditorApp.h
	ProjectCreateStage.cpp
	ProjectCreateStage.h
	ProjectSelectStage.cpp
	ProjectSelectStage.h
)

add_executable(Preditor.Launcher WIN32
	${SOURCE_FILES}
)

target_include_directories(Preditor.Launcher PRIVATE
	.
)

target_link_libraries(Preditor.Launcher
	Preditor.Assets
	Preditor.Common
	Preditor.EditTools
	Preditor.Engine
	Preditor.FGE
	Preditor.GameEditor
	Preditor.Input
	Preditor.LevelEditor
	Preditor.Main
	Preditor.Viewport
	D3D11.lib
	libzip::zip
	libzippp::libzippp
)

set_target_properties(Preditor.Launcher PROPERTIES OUTPUT_NAME "Preditor")

set_target_properties(Preditor.Launcher PROPERTIES
	VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/Data"
)

cl_output_to_data(Preditor.Launcher)
cl_version_info(Preditor.Launcher "Preditor.exe" "Preditor")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
