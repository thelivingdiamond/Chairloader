#include <Prey/RenderDll/Common/CommonRender.h>
#include <Prey/RenderDll/XRenderD3D9/D3DHWShader.h>
#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <Prey/RenderDll/Common/ResFile.h>
#include <Prey/RenderDll/Common/Shaders/CShaderBin.h>
#include <mem.h>
#include "ShaderPaths.h"

CD3D9Renderer* gcpRendD3D = nullptr;

class CDeviceGraphicsPSODesc;
class CDeviceGraphicsCommandInterfaceImpl;

class CDeviceGraphicsPSO // Id=80004AA Size=16
{
public:
	bool m_bValid;
	unsigned m_nUpdateCount;

	virtual bool Init(CDeviceGraphicsPSODesc const& arg0) = 0;

#if 0
	bool IsValid() const;
	unsigned GetUpdateCount() const;
#endif
};

// Header: FromCpp
// CryEngine/renderdll/xrenderd3d9/devicemanager/d3d11/deviceobjects_d3d11.h
class CDeviceGraphicsPSO_DX11 : public CDeviceGraphicsPSO // Id=801110A Size=240
{
public:
	_smart_ptr<ID3D11RasterizerState> m_pRasterizerState;
	unsigned m_RasterizerStateIndex;
	_smart_ptr<ID3D11BlendState> m_pBlendState;
	_smart_ptr<ID3D11DepthStencilState> m_pDepthStencilState;
	_smart_ptr<ID3D11InputLayout> m_pInputLayout;
	std::array<void*, 6> m_pDeviceShaders;
	std::array<enum EShaderStage, 64> m_requestedSrvs;
	std::array<enum EShaderStage, 64> m_requestedSamplers;
	D3D_PRIMITIVE_TOPOLOGY m_PrimitiveTopology;

	virtual bool Init(CDeviceGraphicsPSODesc const& psoDesc);

	static inline auto FInit = PreyFunction<bool(CDeviceGraphicsPSO_DX11* const _this, CDeviceGraphicsPSODesc const& psoDesc)>(0xF38F40);
};

//-----------------------------------------------------------------------------------

void CShaderMan::mfInitLookups()
{
	m_ResLookupDataMan[CACHE_READONLY].Clear();
	string dirdatafilename(m_ShadersCache);
	dirdatafilename += "lookupdata.bin";
	m_ResLookupDataMan[CACHE_READONLY].LoadData(dirdatafilename.c_str(), true);

	m_ResLookupDataMan[CACHE_USER].Clear();
	dirdatafilename = m_szUserPath + m_ShadersCache;
	dirdatafilename += "lookupdata.bin";
	m_ResLookupDataMan[CACHE_USER].LoadData(dirdatafilename.c_str(), false);
}

//-----------------------------------------------------------------------------------

namespace RenderDll::Shaders
{

// This hepler class allows you to hook a PreyFunction to call a method of a class.
// Doesn't work with virtual functions.
// @tparam	pPreyFunc			Pointer to PreyFunction<>.
// @tparam	pOverrideMethod		Pointer to a method to call.
template<auto pPreyFunc, auto pOverrideMethod>
class PreyFuncOverride
{
public:
	//! PreyFunction<>
	using PreyFuncType = std::remove_pointer_t<decltype(pPreyFunc)>;

	//! Initializes the hook.
	static void Init()
	{
		m_Hook.SetHookFunc(&Wrapper);
	}

private:
	static inline auto m_Hook = pPreyFunc->MakeHook();

	//! Wrapper function that calls the method. It's required because member function pointers
	//! can't be cast to an address.
	template <typename... Args>
	static typename PreyFuncType::FuncReturnType Wrapper(Args... args)
	{
		return std::invoke(pOverrideMethod, args...);
	}
};

//-----------------------------------------------------------------------------------

auto g_CHWShader_D3D_mfActivate_Hook = CHWShader_D3D::FmfActivate.MakeHook();
auto g_CShaderMan_mfInit_Hook = CShaderMan::FmfInit.MakeHook();
auto g_CShaderMan_mfReleaseSystemShaders_Hook = CShaderMan::FmfReleaseSystemShaders.MakeHook();
auto g_CShaderMan_mfReloadAllShaders_Hook = CShaderMan::FmfReloadAllShaders.MakeHook();

bool CHWShader_D3D_mfActivate_Hook(CHWShader_D3D* _this, CShader* pSH, uint32 nFlags, FXShaderToken* Table, TArray<uint32>* pSHData, bool bCompressedOnly)
{
	// Overload, can't use PreyFuncOverride here
	return _this->mfActivate(pSH, nFlags, Table, pSHData);
}

void CShaderMan_mfInit_Hook(CShaderMan* _this)
{
	if (!_this->m_bInitialized)
	{
		*CRenderer::CV_r_shadersediting = 1;
		*CRenderer::CV_r_shadersAllowCompilation = 1;

		//if (*CRenderer::CV_r_shadersAllowCompilation)
		{
			*CRenderer::CV_r_shadersasyncactivation = 0;
			*CRenderer::CV_r_shadersasynccompiling = 0;
			*CRenderer::CV_r_shadersdebug = 4;
		}
	}

	g_CShaderMan_mfInit_Hook.InvokeOrig(_this);
}

void CShaderMan_mfReleaseSystemShaders_Hook(CShaderMan* _this)
{
	static bool onlyRunOnceInmfInit = false;

	if (!onlyRunOnceInmfInit)
	{
		onlyRunOnceInmfInit = true;

		if (*CRenderer::CV_r_shadersAllowCompilation)
		{
			_this->mfInitShadersCache(false, NULL, NULL, 0);
		}
		else
		{
			// make sure we can write to the shader cache
			if (!_this->CheckAllFilesAreWritable((string(_this->m_ShadersCache) + "cgpshaders").c_str())
				|| !_this->CheckAllFilesAreWritable((string(_this->m_ShadersCache) + "cgvshaders").c_str()))
			{
				// message box causes problems in fullscreen
				//			MessageBox(0,"WARNING: Shader cache cannot be updated\n\n"
				//				"files are write protected / media is read only / windows user setting don't allow file changes","CryEngine",MB_ICONEXCLAMATION|MB_OK);
				gEnv->pLog->LogError("ERROR: Shader cache cannot be updated (files are write protected / media is read only / windows user setting don't allow file changes)");
			}
		}
	}

	g_CShaderMan_mfReleaseSystemShaders_Hook.InvokeOrig(_this);
}

bool CShaderMan_mfReloadAllShaders_Hook(CShaderMan* const _this, int nFlags, unsigned nFlagsHW)
{
	// Refresh file list on shader reload
	ShaderPaths::Get().RefreshFileList();
	return g_CShaderMan_mfReloadAllShaders_Hook.InvokeOrig(_this, nFlags, nFlagsHW);
}

auto g_CDeviceGraphicsPSO_DX11_Init = PreyFunction<bool(CDeviceGraphicsPSO_DX11* _this, const CDeviceGraphicsPSODesc& psoDesc)>(0xF38F40);
auto g_CDeviceGraphicsPSO_DX11_Init_Hook = g_CDeviceGraphicsPSO_DX11_Init.MakeHook();

auto g_CDeviceGraphicsCommandInterfaceImpl_SetPipelineStateImpl = PreyFunction<void(CDeviceGraphicsCommandInterfaceImpl* _this, const CDeviceGraphicsPSO* devicePSO)>(0xF39F80);
auto g_CDeviceGraphicsCommandInterfaceImpl_SetPipelineStateImpl_Hook = g_CDeviceGraphicsCommandInterfaceImpl_SetPipelineStateImpl.MakeHook();

std::map<CDeviceGraphicsPSO_DX11*, std::array<void*, 6>> g_OldShaders;

bool CDeviceGraphicsPSO_DX11_Init_Hook(CDeviceGraphicsPSO_DX11* _this, const CDeviceGraphicsPSODesc& psoDesc)
{
	bool res = g_CDeviceGraphicsPSO_DX11_Init_Hook.InvokeOrig(_this, psoDesc);

	for (int i = 0; i < _this->m_pDeviceShaders.size(); i++)
	{
		if (_this->m_pDeviceShaders[i])
		{
			ID3D11Resource* hack = (ID3D11Resource*)_this->m_pDeviceShaders[i];

			//int ref = hack->AddRef();
			//CRY_ASSERT(ref == 2);

			//ref = hack->Release();
			//CRY_ASSERT(ref == 1);

			void* vtbl = *(void**)_this->m_pDeviceShaders[i];
			CRY_ASSERT(!IsBadReadPtr(vtbl, 8));
		}
	}

	g_OldShaders[_this] = _this->m_pDeviceShaders;

	return res;
}

void CDeviceGraphicsCommandInterfaceImpl_SetPipelineStateImpl_Hook(CDeviceGraphicsCommandInterfaceImpl* _this, const CDeviceGraphicsPSO* devicePSO)
{
	const CDeviceGraphicsPSO_DX11* pDevicePSO = reinterpret_cast<const CDeviceGraphicsPSO_DX11*>(devicePSO);
	const std::array<void*, eHWSC_Num>& shaders = pDevicePSO->m_pDeviceShaders;

	auto it = g_OldShaders.find(const_cast<CDeviceGraphicsPSO_DX11*>(pDevicePSO));

	for (int i = 0; i < shaders.size(); i++)
	{
		if (shaders[i])
		{
			void* vtbl = *(void**)shaders[i];
			CRY_ASSERT(!IsBadReadPtr(vtbl, 8));
		}
	}

	g_CDeviceGraphicsCommandInterfaceImpl_SetPipelineStateImpl_Hook.InvokeOrig(_this, devicePSO);
}

//-----------------------------------------------------------------------------------

void InitHooks()
{
	g_CHWShader_D3D_mfActivate_Hook.SetHookFunc(&CHWShader_D3D_mfActivate_Hook);
	g_CShaderMan_mfInit_Hook.SetHookFunc(&CShaderMan_mfInit_Hook);
	g_CShaderMan_mfReleaseSystemShaders_Hook.SetHookFunc(&CShaderMan_mfReleaseSystemShaders_Hook);
	g_CShaderMan_mfReloadAllShaders_Hook.SetHookFunc(&CShaderMan_mfReloadAllShaders_Hook);

	g_CDeviceGraphicsPSO_DX11_Init_Hook.SetHookFunc(CDeviceGraphicsPSO_DX11_Init_Hook);
	g_CDeviceGraphicsCommandInterfaceImpl_SetPipelineStateImpl_Hook.SetHookFunc(&CDeviceGraphicsCommandInterfaceImpl_SetPipelineStateImpl_Hook);

#define INIT_OVERRIDE(className, funcName) PreyFuncOverride<&className::F##funcName, &className::funcName>::Init()

	INIT_OVERRIDE(CHWShader_D3D, mfGetDstFileName);
	//INIT_OVERRIDE(CHWShader_D3D, mfAddFXParameter); // Overload!
	INIT_OVERRIDE(CHWShader_D3D, mfCreateBinds);
	INIT_OVERRIDE(CHWShader_D3D, mfUpdateFXVertexFormat);
	//INIT_OVERRIDE(CHWShader_D3D, mfVertexFormat); // Overload!
	//INIT_OVERRIDE(CHWShader_D3D, mfSetDefaultRT); // Overload!
	INIT_OVERRIDE(CHWShader_D3D, mfStoreCacheTokenMap);
	INIT_OVERRIDE(CHWShader_D3D, mfGetTokenMap);
	INIT_OVERRIDE(CHWShader_D3D, mfGetCacheTokenMap);
	INIT_OVERRIDE(CHWShader_D3D, mfGetCacheItem);
	INIT_OVERRIDE(CHWShader_D3D, mfActivateCacheItem);
	INIT_OVERRIDE(CHWShader_D3D, mfOutputCompilerError);
	INIT_OVERRIDE(CHWShader_D3D, mfAsyncCompileReady);
	INIT_OVERRIDE(CHWShader_D3D, mfPrepareShaderDebugInfo);
	INIT_OVERRIDE(CHWShader_D3D, mfPrintCompileInfo);
	INIT_OVERRIDE(CHWShader_D3D, _OpenCacheFile);
	INIT_OVERRIDE(CHWShader_D3D, mfOpenCacheFile);
	INIT_OVERRIDE(CHWShader_D3D, mfInitCache);

	INIT_OVERRIDE(CShaderMan, mfForName);
	INIT_OVERRIDE(CShaderMan, mfCreateShaderGenInfo);
	INIT_OVERRIDE(CShaderMan, RT_ParseShader);
	INIT_OVERRIDE(CShaderMan, mfInitLookups);

	INIT_OVERRIDE(CResFile, mfGetEntry);
	INIT_OVERRIDE(CShaderManBin, GetBinShader);

#undef INIT_OVERRIDE

	ShaderPaths::Get().Init();
}

}
