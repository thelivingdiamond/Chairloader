// Header test file for path CryEngine/renderdll/xrenderd3d9/arkd3dbinkrender.h
#include "arkd3dvideoinfo.h"
static_assert(sizeof(ArkVideoInfo) == 80);

#include "compiledrenderobject.h"
//static_assert(sizeof(CCompiledRenderObject) == 360);
//static_assert(sizeof(CCompiledRenderObject::SDrawParams) == 12);
static_assert(sizeof(CRenderObjectsPools) == 280);
//static_assert(sizeof(CRenderObjectsPools::PoolSyncCriticalSection) == 40);
//static_assert(sizeof(CPermanentRenderObject) == 624);
//static_assert(sizeof(CPermanentRenderObject::SPermanentRendItem) == 40);

#include "d3dhwshader.h"
static_assert(sizeof(CHWShader_D3D) == 176);
static_assert(sizeof(CHWShader_D3D::SHWSInstance) == 256);
static_assert(sizeof(SD3DShaderHandle) == 24);
static_assert(sizeof(CGParamManager) == 1);

#include "driverd3d.h"
static_assert(sizeof(CD3D9Renderer) == 46080);
