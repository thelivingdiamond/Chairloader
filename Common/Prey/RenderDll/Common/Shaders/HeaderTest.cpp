// Header test file for path Prey/RenderDll/Common/Shaders/

#include "../CommonRender.h"
static_assert(sizeof(SResourceContainer) == 64);
static_assert(sizeof(CBaseResource) == 24);

#include "CShader.h"
static_assert(sizeof(SMacroFX) == 16);
static_assert(sizeof(CShaderParserHelper) == 792);
static_assert(sizeof(SParamDB) == 32);
static_assert(sizeof(SSamplerDB) == 24);
static_assert(sizeof(STextureDB) == 24);
static_assert(sizeof(CShaderMan) == 3768);
static_assert(sizeof(CShaderMan::SShaderMapNameFlagsContainerDelete) == 1);

#include "CShaderBin.h"
static_assert(sizeof(SShaderTechParseParams) == 56);
static_assert(sizeof(SShaderBinHeader) == 28);
static_assert(sizeof(SShaderBinParamsHeader) == 32);
static_assert(sizeof(SParamCacheInfo) == 112);
static_assert(sizeof(SShaderBin) == 120);
static_assert(sizeof(SShaderFXParams) == 112);
static_assert(sizeof(CShaderManBin) == 64);

#include "ParserBin.h"
#ifndef MOONCRASH
static_assert(sizeof(SFXTokenBin) == 4);
static_assert(sizeof(SMacroBinFX) == 32);
static_assert(sizeof(SParserFrame) == 12);
static_assert(sizeof(SCodeFragment) == 16);
static_assert(sizeof(SortByToken) == 1);
#endif
static_assert(sizeof(CParserBin) == 200);

#include "Shader.h"
static_assert(sizeof(SPair) == 24);
static_assert(sizeof(SFXSampler) == 88);
static_assert(sizeof(SFXTexture) == 112);
static_assert(sizeof(SFXParam) == 80);
static_assert(sizeof(STokenD) == 16);
static_assert(sizeof(SFXStruct) == 16);
static_assert(sizeof(SShaderCacheHeaderItem) == 12);
static_assert(sizeof(SShaderCacheHeaderItemVar) == 520);
static_assert(sizeof(SCompressedData) == 16);
static_assert(sizeof(SOptimiseStats) == 24);
static_assert(sizeof(CHWShader) == 128);
static_assert(sizeof(SLightMove) == 60);
static_assert(sizeof(SLightStyleKeyFrame) == 28);
static_assert(sizeof(CLightStyle) == 24);
#ifndef MOONCRASH
static_assert(sizeof(SShaderPass) == 56);
#endif
static_assert(sizeof(SShaderTechnique) == 80);
static_assert(sizeof(CShader) == 208);

#include "ShaderCache.h"
static_assert(sizeof(SPreprocessMasks) == 56);
static_assert(sizeof(SPreprocessNode) == 112);
static_assert(sizeof(SPreprocessFlagDesc) == 24);
static_assert(sizeof(SPreprocessTree) == 120);
#ifndef MOONCRASH
static_assert(sizeof(SShaderLevelPolicies) == 48);
#endif
static_assert(sizeof(UPipelineState) == 8);
static_assert(sizeof(SShaderCombIdent) == 40);
static_assert(sizeof(CResStreamDirCallback) == 8);
static_assert(sizeof(CResStreamCallback) == 8);
#ifndef MOONCRASH
static_assert(sizeof(SResStreamEntry) == 24);
static_assert(sizeof(SResStreamInfo) == 128);
#endif
static_assert(sizeof(SShaderDevCache) == 32);
static_assert(sizeof(SShaderCache) == 56);
static_assert(sizeof(SEmptyCombination) == 64);
static_assert(sizeof(SShaderCombination) == 32);
static_assert(sizeof(SCacheCombination) == 64);
static_assert(sizeof(SShaderGenComb) == 16);

#include "ShaderComponents.h"
static_assert(sizeof(SCGParamsPF) == 896);
static_assert(sizeof(SCGBind) == 24);
static_assert(sizeof(SParamData) == 64);
static_assert(sizeof(SParamData::UData) == 32);
static_assert(sizeof(SCGLiteral) == 4);
static_assert(sizeof(SCGParam) == 48);
static_assert(sizeof(SCGSampler) == 32);
static_assert(sizeof(SCGTexture) == 48);

#include "ShaderResources.h"
static_assert(sizeof(CShaderResources) == 304);
