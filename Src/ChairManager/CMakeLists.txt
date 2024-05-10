set(CMAKE_FOLDER "ChairManager")

set(SOURCE_FILES
	CMakeLists.txt

	UI.cpp
	UI.h
	
	ChairWizards/ChairInstallWizard.cpp
	ChairWizards/ChairInstallWizard.h
	ChairWizards/ChairUninstallWizard.cpp
	ChairWizards/ChairUninstallWizard.h
	ChairWizards/ChairUpdateWizard.cpp
	ChairWizards/ChairUpdateWizard.h
	ChairWizards/GamePathDialog.cpp
	ChairWizards/GamePathDialog.h
	
	Resources/appicon.rc

	BinaryVersionCheck.cpp
	BinaryVersionCheck.h
	ChairManager.cpp
	ChairManager.h
	CrashHandler.cpp
	CrashHandler.h
	GameVersion.cpp
	GameVersion.h
	main.cpp
	Mod.h
	Paths.h
	pch.h
	PreyFilesPatchProgressDialog.cpp 
	PreyFilesPatchProgressDialog.h
	UpdateHandler.cpp 
	UpdateHandler.h
	UpdateURL.h
	zipconf.h
)

add_executable(ChairManager WIN32
	${SOURCE_FILES}
)

target_include_directories(ChairManager PRIVATE .)

target_link_libraries(ChairManager
	Boost::json
	ChairManager.Common
	ChairMerger
	libzip::zip
	libzip::zip
	libzippp::libzippp
	StackWalker
	unofficial::curlpp::curlpp
	ZLIB::ZLIB

	Dbghelp.lib
	version.lib
)

target_precompile_headers(ChairManager PRIVATE pch.h)

cl_output_to_data(ChairManager)
cl_version_info(ChairManager "ChairManager.exe" "Chairloader Mod Manager")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
