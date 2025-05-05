set(SOURCE_FILES)

# Options
option(RENDERDLL_DEBUG_MARKERS "Enables section markers for GPU profilers like RenderDoc" OFF)

set(RENDERDLL_DEFS)

if(RENDERDLL_DEBUG_MARKERS)
	set(RENDERDLL_DEFS ${RENDERDLL_DEFS} RENDERDLL_DEBUG_MARKERS)
endif()

set(SOURCE_FILES
	${SOURCE_FILES}
	CMakeLists.txt
	
	AuxGeom/D3DRenderAuxGeom.cpp
	AuxGeom/D3DRenderAuxGeom.h
	AuxGeom/RenderAuxGeom.cpp
	AuxGeom/RenderAuxGeom.h
	AuxGeom/RenderAuxGeomPatch.cpp
	AuxGeom/RenderAuxGeomPatch.h
	AuxGeom/TextMessages.cpp

	lzss/lzss.cpp
	lzss/lzss.h

	Shaders/D3DHWShaderCompiling.cpp
	Shaders/Parser.cpp
	Shaders/Parser.h
	Shaders/ParserBin.cpp
	Shaders/ResFile.cpp
	Shaders/ResLookupDataMan.cpp
	Shaders/ShaderCompilingPatch.cpp
	Shaders/ShaderCompilingPatch.h
	Shaders/ShaderManBin.cpp
	
	ChairloaderCryRender.cpp
	ChairloaderCryRender.h
	ChairRender.cpp
	ChairRender.h
	ChairloaderCryRenderServiceEnvironment.cpp
	DebugMarkers.cpp
	DebugMarkers.h
	pch.h
)

add_library(Chairloader.CryRender STATIC ${SOURCE_FILES})

target_compile_definitions(Chairloader.CryRender PRIVATE
	${RENDERDLL_DEFS}
	RENDERDLL_SHADER_COMPILER
)

target_include_directories(Chairloader.CryRender PRIVATE .)

target_link_libraries(Chairloader.CryRender PUBLIC
	Chairloader.Common
)

target_precompile_headers(Chairloader.CryRender PRIVATE pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
