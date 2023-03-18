# Grab all files in Common/Prey directory
file(GLOB_RECURSE PREY_HEADER_FILES
	LIST_DIRECTORIES false
	CONFIGURE_DEPENDS
	Prey/*.*
)

set(SOURCE_FILES
	CMakeLists.txt
	${PREY_HEADER_FILES}

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
	Chairloader/IRenderAuxGeomEx.h
	Chairloader/pch.h
	Chairloader/PreyFunction.cpp
	Chairloader/PreyFunction.h
	Chairloader/ValidateCompiler.h
	Chairloader/SemanticVersion.h

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
