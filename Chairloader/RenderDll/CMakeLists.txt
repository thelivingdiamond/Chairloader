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
		Shaders/Parser.cpp
		Shaders/ParserBin.cpp
		Shaders/ResFile.cpp
		Shaders/ShaderCompilingPatch.cpp
		Shaders/ShaderCompilingPatch.h
		Shaders/ShaderFXParseBin.cpp
		Shaders/ShaderMan.cpp
		Shaders/ShaderPaths.cpp
		Shaders/ShaderPaths.h
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
	
	ChairRender.cpp
	ChairRender.h
	DebugMarkers.cpp
	DebugMarkers.h
	pch.h
	RenderDll.cpp
	RenderDll.h
)

add_library(CryRenderD3D11 STATIC
	${SOURCE_FILES}
)

target_compile_definitions(CryRenderD3D11 PRIVATE
	${RENDERDLL_DEFS}
)

target_include_directories(CryRenderD3D11 PRIVATE
	.
)

target_link_libraries(CryRenderD3D11 PUBLIC
	Common
)

target_precompile_headers(CryRenderD3D11 PRIVATE pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
