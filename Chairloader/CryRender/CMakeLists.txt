set(SOURCE_FILES)

# Options
option(RENDERDLL_DEBUG_MARKERS "Enables section markers for GPU profilers like RenderDoc" OFF)
option(RENDERDLL_SHADER_COMPILER "Restores engine's shader compiler. Unstable.'" OFF)

set(RENDERDLL_DEFS)

if(RENDERDLL_DEBUG_MARKERS)
	set(RENDERDLL_DEFS RENDERDLL_DEBUG_MARKERS)
endif()

if(RENDERDLL_SHADER_COMPILER)
	set(RENDERDLL_DEFS RENDERDLL_SHADER_COMPILER)
	set(SOURCE_FILES
		${SOURCE_FILES}
		lzss/lzss.cpp
		lzss/lzss.h
		
		Shaders/D3DHWShaderCompiling.cpp
		Shaders/ParserBin.cpp
		Shaders/ResFile.cpp
		Shaders/ShaderCompilingPatch.cpp
		Shaders/ShaderCompilingPatch.h
	)
else()
	set(SOURCE_FILES
		${SOURCE_FILES}
		Shaders/ShaderCompilingPatch.cpp
		Shaders/ShaderCompilingPatch.h
	)
endif()

set(SOURCE_FILES
	${SOURCE_FILES}
	CMakeLists.txt
	
	AuxGeom/D3DRenderAuxGeom.cpp
	AuxGeom/D3DRenderAuxGeom.h
	AuxGeom/RenderAuxGeom.cpp
	AuxGeom/RenderAuxGeomPatch.cpp
	AuxGeom/RenderAuxGeomPatch.h
	AuxGeom/TextMessages.cpp
	
	ChairloaderCryRender.cpp
	ChairloaderCryRender.h
	ChairRender.cpp
	ChairRender.h
	DebugMarkers.cpp
	DebugMarkers.h
	pch.h
)

add_library(Chairloader.CryRender STATIC ${SOURCE_FILES})
target_compile_definitions(Chairloader.CryRender PRIVATE ${RENDERDLL_DEFS})
target_include_directories(Chairloader.CryRender PRIVATE .)

target_link_libraries(Chairloader.CryRender PUBLIC
	Chairloader.Common
)

target_precompile_headers(Chairloader.CryRender PRIVATE pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
