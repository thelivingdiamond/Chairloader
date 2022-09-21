set(SOURCE_FILES
	CMakeLists.txt
	
	AuxGeom/D3DRenderAuxGeom.cpp
	AuxGeom/D3DRenderAuxGeom.h
	AuxGeom/RenderAuxGeom.cpp
	AuxGeom/RenderAuxGeomPatch.cpp
	AuxGeom/RenderAuxGeomPatch.h
	AuxGeom/TextMessages.cpp

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
	
	ChairRender.cpp
	ChairRender.h
	DebugMarkers.cpp
	DebugMarkers.h
	pch.h
	RenderDll.cpp
	RenderDll.h
)

if(RENDERDLL_DEBUG_MARKERS)
	set(RENDERDLL_DEBUG_MARKERS_DEFS RENDERDLL_DEBUG_MARKERS)
endif()

add_library(CryRenderD3D11 STATIC
	${SOURCE_FILES}
)

target_compile_definitions(CryRenderD3D11 PRIVATE
	${RENDERDLL_DEBUG_MARKERS_DEFS}
)

target_include_directories(CryRenderD3D11 PRIVATE
	.
)

target_link_libraries(CryRenderD3D11 PUBLIC
	Common
)

target_precompile_headers(CryRenderD3D11 PRIVATE pch.h)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
