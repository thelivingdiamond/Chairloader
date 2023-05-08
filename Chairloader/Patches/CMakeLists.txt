set(SOURCE_FILES
	CMakeLists.txt

	SteamAPI/ChairSteamAPI.cpp
	SteamAPI/ChairSteamAPI.h
	
	ChairloaderPatches.cpp
	ChairloaderPatches.h
)

add_library(Chairloader.Patches STATIC ${SOURCE_FILES})
target_include_directories(Chairloader.Patches PRIVATE .)

target_link_libraries(Chairloader.Patches PUBLIC
	Chairloader.Common
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
