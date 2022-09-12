// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once
#include "../DevBuffer.h"

class CGraphicsPipelineStateLocalCache;
class CDeviceResourceSet;

enum EHWShaderClass
{
	eHWSC_Vertex   = 0,
	eHWSC_Pixel    = 1,
	eHWSC_Geometry = 2,
	eHWSC_Compute  = 3,
	eHWSC_Domain   = 4,
	eHWSC_Hull     = 5,
	eHWSC_Num      = 6
};

//! This class provide all necessary resources to the shader extracted from material definition.
class CShaderResources : public IRenderShaderResources, public SBaseShaderResources
{
public:
	enum EFlags
	{
		eFlagInvalid = 1,
		eFlagRecreateResourceSet = 2,
	};

	stl::aligned_vector<Vec4, 256> m_Constants;
	SEfResTexture* m_Textures[15];
	SDeformInfo* m_pDeformInfo;
	CConstantBuffer* m_pCB;
	uint16_t m_Id;
	uint16_t m_IdGroup;
	volatile int m_nRefCounter;
	float m_fMinMipFactorLoad;
	int m_nFrameLoad;
	unsigned m_nUpdateFrameID;
	unsigned m_nUpdateFinishedFrameID;
	uint8_t m_flags;
	uint8_t m_nLastTexture;
	std::shared_ptr<CDeviceResourceSet> m_pCompiledResourceSet;
	std::shared_ptr<CGraphicsPipelineStateLocalCache> m_pipelineStateCache;

	void AddTextureMap(int Id) { FAddTextureMap(this, Id); }
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	CShaderResources();
	CShaderResources(SInputShaderResources* pSrc);
	CShaderResources& operator=(CShaderResources const& src) { return FoperatorEq(this, src); }
	void PostLoad(CShader* pSH) { FPostLoad(this, pSH); }
	void AdjustForSpec() { FAdjustForSpec(this); }
	void CreateModifiers(SInputShaderResources* pInRes) { FCreateModifiers(this, pInRes); }
	virtual void UpdateConstants(IShader* pISH);
	virtual void CloneConstants(IRenderShaderResources const* pISrc);
	virtual int GetResFlags();
	virtual void SetMaterialName(const char* szName);
	virtual float GetAlphaRef() const;
	virtual void SetAlphaRef(float alphaRef);
	virtual SEfResTexture* GetTexture(int nSlot) const;
	virtual DynArray<SShaderParam, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& GetParameters();
	void RT_UpdateConstants(IShader* pISH, bool _bForceUpdate) { FRT_UpdateConstants(this, pISH, _bForceUpdate); }
	virtual void ScaleDeformInfo(float _scale);
	bool NeedsConstantsUpdated() const { return FNeedsConstantsUpdated(this); }
	virtual void SetInputLM(CInputLightMaterial const& lm);
	virtual void ToInputLM(CInputLightMaterial& lm);
	virtual ColorF const& GetColorValue(EEfResTextures slot) const;
	virtual ColorF const& GetColorValue(EMaterialParamVec3 _param) const;
	virtual float GetStrengthValue(EEfResTextures slot) const;
	virtual float GetStrengthValue(EMaterialParamFloat _param) const;
	virtual void SetColorValue(EEfResTextures slot, ColorF const& color);
	virtual void SetColorValue(EMaterialParamVec3 _param, ColorF const& _color);
	virtual void SetStrengthValue(EEfResTextures slot, float value);
	virtual void SetStrengthValue(EMaterialParamFloat _param, float _value);
	float GetTimer() const { return FGetTimer(this); }
	virtual void SetInvalid();
	virtual bool IsValid();
	virtual ~CShaderResources();
	void RT_Release() { FRT_Release(this); }
	virtual void Release();
	virtual void AddRef();
	virtual void ConvertToInputResource(SInputShaderResources* pDst);
	virtual CShaderResources* Clone() const;
	virtual void SetShaderParams(SInputShaderResources* pDst, IShader* pSH);
	virtual uint64_t GetResourceMemoryUsage(ICrySizer* pSizer);
	void Cleanup() { FCleanup(this); }

#if 0
	int Size() const;
	ColorF GetFinalEmittance() const;
	void ReleaseConstants();
	void Reset();
	bool IsEmpty(int arg0) const;
	bool HasLMConstants() const;
#endif

	static inline auto FAddTextureMap = PreyFunction<void(CShaderResources* const _this, int Id)>(0xEBEC60);
	static inline auto FGetMemoryUsage = PreyFunction<void(CShaderResources const* const _this, ICrySizer* pSizer)>(0xEBF5F0);
	static inline auto FoperatorEq = PreyFunction<CShaderResources& (CShaderResources* const _this, CShaderResources const& src)>(0xEBE770);
	static inline auto FPostLoad = PreyFunction<void(CShaderResources* const _this, CShader* pSH)>(0x101A870);
	static inline auto FAdjustForSpec = PreyFunction<void(CShaderResources* const _this)>(0xEBED10);
	static inline auto FCreateModifiers = PreyFunction<void(CShaderResources* const _this, SInputShaderResources* pInRes)>(0x1019CB0);
	static inline auto FUpdateConstants = PreyFunction<void(CShaderResources* const _this, IShader* pISH)>(0xEC1450);
	static inline auto FCloneConstants = PreyFunction<void(CShaderResources* const _this, IRenderShaderResources const* pISrc)>(0xEBF1B0);
	static inline auto FGetResFlags = PreyFunction<int(CShaderResources* const _this)>(0x85F800);
	static inline auto FSetMaterialName = PreyFunction<void(CShaderResources* const _this, const char* szName)>(0xEC1310);
	static inline auto FGetAlphaRef = PreyFunction<float(CShaderResources const* const _this)>(0xEBF520);
	static inline auto FSetAlphaRef = PreyFunction<void(CShaderResources* const _this, float alphaRef)>(0xEC1150);
	static inline auto FGetTexture = PreyFunction<SEfResTexture* (CShaderResources const* const _this, int nSlot)>(0xEBFA10);
	static inline auto FGetParameters = PreyFunction<DynArray<SShaderParam, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& (CShaderResources* const _this)>(0x12BDA70);
	static inline auto FRT_UpdateConstants = PreyFunction<void(CShaderResources* const _this, IShader* pISH, bool _bForceUpdate)>(0xEBFB50);
	static inline auto FScaleDeformInfo = PreyFunction<void(CShaderResources* const _this, float _scale)>(0xEC10F0);
	static inline auto FNeedsConstantsUpdated = PreyFunction<bool(CShaderResources const* const _this)>(0xEBFA70);
	static inline auto FSetInputLM = PreyFunction<void(CShaderResources* const _this, CInputLightMaterial const& lm)>(0xEC1240);
	static inline auto FToInputLM = PreyFunction<void(CShaderResources* const _this, CInputLightMaterial& lm)>(0xEC13D0);
	static inline auto FGetColorValueOv1 = PreyFunction<ColorF const& (CShaderResources const* const _this, EEfResTextures slot)>(0xEBF530);
	static inline auto FGetColorValueOv0 = PreyFunction<ColorF const& (CShaderResources const* const _this, EMaterialParamVec3 _param)>(0xEBF590);
	static inline auto FGetStrengthValueOv1 = PreyFunction<float(CShaderResources const* const _this, EEfResTextures slot)>(0xEBF930);
	static inline auto FGetStrengthValueOv0 = PreyFunction<float(CShaderResources const* const _this, EMaterialParamFloat _param)>(0xEBF9A0);
	static inline auto FSetColorValueOv1 = PreyFunction<void(CShaderResources* const _this, EEfResTextures slot, ColorF const& color)>(0xEC1160);
	static inline auto FSetColorValueOv0 = PreyFunction<void(CShaderResources* const _this, EMaterialParamVec3 _param, ColorF const& _color)>(0xEC11D0);
	static inline auto FSetStrengthValueOv1 = PreyFunction<void(CShaderResources* const _this, EEfResTextures slot, float value)>(0xEC1320);
	static inline auto FSetStrengthValueOv0 = PreyFunction<void(CShaderResources* const _this, EMaterialParamFloat _param, float _value)>(0xEC1370);
	static inline auto FGetTimer = PreyFunction<float(CShaderResources const* const _this)>(0xEBFA20);
	static inline auto FSetInvalid = PreyFunction<void(CShaderResources* const _this)>(0xEC12F0);
	static inline auto FIsValid = PreyFunction<bool(CShaderResources* const _this)>(0xEBFA60);
	static inline auto FRT_Release = PreyFunction<void(CShaderResources* const _this)>(0xEBFB20);
	static inline auto FRelease = PreyFunction<void(CShaderResources* const _this)>(0xEC10A0);
	static inline auto FAddRef = PreyFunction<void(CShaderResources* const _this)>(0xEBEC50);
	static inline auto FConvertToInputResource = PreyFunction<void(CShaderResources* const _this, SInputShaderResources* pDst)>(0xEBF300);
	static inline auto FClone = PreyFunction<CShaderResources* (CShaderResources const* const _this)>(0xEBEF00);
	static inline auto FSetShaderParams = PreyFunction<void(CShaderResources* const _this, SInputShaderResources* pDst, IShader* pSH)>(0x103B9D0);
	static inline auto FGetResourceMemoryUsage = PreyFunction<uint64_t(CShaderResources* const _this, ICrySizer* pSizer)>(0xEBF850);
	static inline auto FCleanup = PreyFunction<void(CShaderResources* const _this)>(0xEBEDA0);
};
typedef _smart_ptr<CShaderResources> CShaderResourcesPtr;
