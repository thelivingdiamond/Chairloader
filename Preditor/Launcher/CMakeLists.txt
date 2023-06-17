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
	ProjectHistory.cpp
	ProjectHistory.h
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
	Preditor.Common
	Preditor.Engine
	Preditor.Main
	D3D11.lib
)

set_target_properties(Preditor.Launcher PROPERTIES OUTPUT_NAME "Preditor")

set_target_properties(Preditor.Launcher PROPERTIES
	VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/ChairManager/Data"
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
