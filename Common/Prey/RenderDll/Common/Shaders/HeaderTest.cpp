// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path CryEngine/renderdll/common/shaders/cshader.h
#include "../CommonRender.h"
#include "CShader.h"
static_assert(sizeof(CShaderParserHelper) == 792);
static_assert(sizeof(CShaderMan) == 3768);
static_assert(sizeof(CShaderMan::SShaderMapNameFlagsContainerDelete) == 1);

constexpr int asd = sizeof(CShaderMan);

#include "CShaderBin.h"
static_assert(sizeof(SShaderBin) == 120);
static_assert(sizeof(SParamCacheInfo) == 112);

#include "ParserBin.h"
//static_assert(sizeof(CParserBin) == 200);

#include "Shader.h"
static_assert(sizeof(CHWShader) == 128);
static_assert(sizeof(CShader) == 208);
static_assert(sizeof(SShaderTechnique) == 80);
//static_assert(sizeof(ArkBinkPlayer) == 32);
static_assert(sizeof(SFXParam) == 80);
static_assert(sizeof(SFXSampler) == 88);
static_assert(sizeof(SFXTexture) == 112);

#include "ShaderCache.h"
static_assert(sizeof(SShaderCombIdent) == 40);
static_assert(sizeof(SShaderGenComb) == 16);

#include "ShaderComponents.h"
static_assert(sizeof(SCGParam) == 48);
static_assert(sizeof(SParamData) == 64);
static_assert(sizeof(SParamData::UData) == 32);
static_assert(sizeof(SCGTexture) == 48);

//#include "shadercore.h"
static_assert(sizeof(CLightStyle) == 24);

//#include "shaderfxparsebin.h"
static_assert(sizeof(CShaderManBin) == 64);

#include "ShaderResources.h"
static_assert(sizeof(CShaderResources) == 304);
#else // MOONCRASH
// Header test file for path CryEngine/renderdll/common/shaders/
#include "ParserBin.h"
static_assert(sizeof(CParserBin) == 200);
static_assert(sizeof(SFXParam) == 80);
static_assert(sizeof(SFXSampler) == 88);

#include "Shader.h"
static_assert(sizeof(CHWShader) == 128);
static_assert(sizeof(CShader) == 208);
static_assert(sizeof(SFXTexture) == 112);
static_assert(sizeof(SShaderTechnique) == 80);

#include "ShaderResources.h"
static_assert(sizeof(CShaderResources) == 304);

#include "cshader.h"
static_assert(sizeof(CShaderMan) == 3768);
static_assert(sizeof(CShaderMan::SShaderMapNameFlagsContainerDelete) == 1);
static_assert(sizeof(CShaderParserHelper) == 792);

#include "cshaderbin.h"
static_assert(sizeof(SParamCacheInfo) == 112);
static_assert(sizeof(SShaderBin) == 120);

#include "shaderallocator.h"
static_assert(sizeof(STLShaderAllocator<SParamCacheInfo>) == 1);
static_assert(sizeof(STLShaderAllocator<SParamCacheInfo>::rebind<struct SParamCacheInfo>) == 1);
static_assert(sizeof(STLShaderAllocator<SParamCacheInfo>::rebind<struct std::_Container_proxy>) == 1);

#include "shadercache.h"
static_assert(sizeof(SShaderCombIdent) == 40);
static_assert(sizeof(SShaderGenComb) == 16);

#include "shadercomponents.h"
static_assert(sizeof(SCGParam) == 48);
static_assert(sizeof(SCGTexture) == 48);
static_assert(sizeof(SParamData) == 64);
static_assert(sizeof(SParamData::UData) == 32);

#include "shadercore.h"
static_assert(sizeof(CLightStyle) == 24);

#include "shaderfxparsebin.h"
static_assert(sizeof(CShaderManBin) == 64);
#endif // !MOONCRASH
