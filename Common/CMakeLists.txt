# Grab all files in Common/Prey directory
file(GLOB_RECURSE PREY_HEADER_FILES
	LIST_DIRECTORIES false
	CONFIGURE_DEPENDS
	Prey/*.*
)

set(STEAM_API_FILES
	Chairloader/SteamAPI/IChairSteamAPI.h
	Chairloader/SteamAPI/isteamapplist.h
	Chairloader/SteamAPI/isteamapps.h
	Chairloader/SteamAPI/isteamappticket.h
	Chairloader/SteamAPI/isteamclient.h
	Chairloader/SteamAPI/isteamcontroller.h
	Chairloader/SteamAPI/isteamfriends.h
	Chairloader/SteamAPI/isteamgamecoordinator.h
	Chairloader/SteamAPI/isteamgameserver.h
	Chairloader/SteamAPI/isteamgameserverstats.h
	Chairloader/SteamAPI/isteamhtmlsurface.h
	Chairloader/SteamAPI/isteamhttp.h
	Chairloader/SteamAPI/isteaminventory.h
	Chairloader/SteamAPI/isteammasterserverupdater.h
	Chairloader/SteamAPI/isteammatchmaking.h
	Chairloader/SteamAPI/isteammusic.h
	Chairloader/SteamAPI/isteammusicremote.h
	Chairloader/SteamAPI/isteamnetworking.h
	Chairloader/SteamAPI/isteamps3overlayrenderer.h
	Chairloader/SteamAPI/isteamremotestorage.h
	Chairloader/SteamAPI/isteamscreenshots.h
	Chairloader/SteamAPI/isteamugc.h
	Chairloader/SteamAPI/isteamunifiedmessages.h
	Chairloader/SteamAPI/isteamuser.h
	Chairloader/SteamAPI/isteamuserstats.h
	Chairloader/SteamAPI/isteamutils.h
	Chairloader/SteamAPI/isteamvideo.h
	Chairloader/SteamAPI/LICENSE
	Chairloader/SteamAPI/matchmakingtypes.h
	Chairloader/SteamAPI/README.txt
	Chairloader/SteamAPI/steamclientpublic.h
	Chairloader/SteamAPI/steamencryptedappticket.h
	Chairloader/SteamAPI/steamhttpenums.h
	Chairloader/SteamAPI/steamps3params.h
	Chairloader/SteamAPI/steamtypes.h
	Chairloader/SteamAPI/steamuniverse.h
	Chairloader/SteamAPI/steam_api.h
	Chairloader/SteamAPI/steam_api_chairloader.cpp
	Chairloader/SteamAPI/steam_api_internal.h
	Chairloader/SteamAPI/steam_gameserver.h
)

set(SOURCE_FILES
	CMakeLists.txt
	${PREY_HEADER_FILES}
	${STEAM_API_FILES}

	Chairloader/Hooks/FunctionHook.cpp
	Chairloader/Hooks/FunctionHook.h
	Chairloader/Hooks/HookTransaction.cpp
	Chairloader/Hooks/HookTransaction.h

	Chairloader/ModSDK/ChairGlobalModName.cpp
	Chairloader/ModSDK/ChairGlobalModName.h
	Chairloader/ModSDK/ChairloaderModBase.cpp
	Chairloader/ModSDK/ChairloaderModBase.h

	Chairloader/ChairloaderEnv.h
	Chairloader/ChairVars.h
	Chairloader/ChairVars.cpp
	Chairloader/IChairloader.h
	Chairloader/IChairloaderConfigManager.h
	Chairloader/IChairloaderGui.h
	Chairloader/IChairloaderImGui.h
	Chairloader/IChairLogger.cpp
	Chairloader/IChairLogger.h
	Chairloader/IChairloaderMod.h
	Chairloader/IChairRender.h
	Chairloader/IChairSceneEditor.h
	Chairloader/IChairXmlUtils.h
	Chairloader/IModInterface.h
	Chairloader/IRenderAuxGeomEx.h
	Chairloader/IRenderAuxGeomImplD3D.h
	Chairloader/pch.h
	Chairloader/PreyFunction.cpp
	Chairloader/PreyFunction.h
	Chairloader/ValidateCompiler.h
	Chairloader/SemanticVersion.h
	Chairloader/IChairServiceCollection.h
	Chairloader/IChairServiceProvider.h
	Chairloader/IChairService.h

	pugixml/pugiconfig.hpp
	pugixml/pugixml.cpp
	pugixml/pugixml.hpp

	EntityUtils.cpp
	EntityUtils.h
	VTableHook.cpp
	VTableHook.h
	mem.cpp
	mem.h
	proc.cpp
	proc.h
)

add_library(Common STATIC
	${SOURCE_FILES} Prey/CryAction/flowsystem/nodes/flowbasenode.h)

target_include_directories(Common PUBLIC
	.
	pugixml
	${Boost_INCLUDE_DIRS}
)

target_link_libraries(Common PUBLIC
	Detours::Detours
	fmt::fmt-header-only
)

target_precompile_headers(Common PUBLIC Chairloader/pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

add_subdirectory(Chairloader.ImGui)
