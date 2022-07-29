// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Color.h>

struct IEntityRenderProxy;
struct IMaterial;

// Header: Override
// Prey/GameDll/ark/ArkEmissiveComponent.h
struct ArkParamOverride // Id=80141FD Size=8
{
	unsigned index;
	float value;
};

// Header: FromCpp
// Prey/GameDll/ark/ArkEmissiveComponent.h
class ArkEmissiveComponent // Id=80141F9 Size=64
{
public:
	_smart_ptr<IMaterial> m_pMaterial;
	ColorF m_cEmissiveScalar;
	float m_fOriginalEmissive;
	float m_fLastIntensity;
	int m_nEmissiveSubMatId;
	bool m_bInterfered;
	std::vector<ArkParamOverride> m_originalInterferenceValues;
	
	ArkEmissiveComponent();
	void Initialize(IEntityRenderProxy *_pRenderProxy, int _slot, IMaterial *_pMaterialOverride) { FInitialize(this,_pRenderProxy,_slot,_pMaterialOverride); }
	void Cleanup(IEntityRenderProxy *_pRenderProxy, int _slot) { FCleanup(this,_pRenderProxy,_slot); }
	void ChangeMaterial(IEntityRenderProxy *_pRenderProxy, int _slot, IMaterial *_pMaterialOverride) { FChangeMaterial(this,_pRenderProxy,_slot,_pMaterialOverride); }
	void UpdateIntensity(float _intensity) { FUpdateIntensity(this,_intensity); }
	void UpdateColor(ColorF const &_color) { FUpdateColor(this,_color); }
	void UpdateEmissiveTexture(const char *_szEmissiveTexture) { FUpdateEmissiveTexture(this,_szEmissiveTexture); }
	void SetGlitchOverrides(bool _bInterfered) { FSetGlitchOverrides(this,_bInterfered); }
	const char *GetEmissiveTexture() const { return FGetEmissiveTexture(this); }
	static void LoadInterferenceOverrides() { FLoadInterferenceOverrides(); }
	
#if 0
	void SetEmissiveScalar(ColorF const &arg0);
	void SetEmissiveSubMatId(int arg0);
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkEmissiveComponent *const _this, IEntityRenderProxy *_pRenderProxy, int _slot, IMaterial *_pMaterialOverride)>(0x1159590);
	static inline auto FCleanup = PreyFunction<void(ArkEmissiveComponent *const _this, IEntityRenderProxy *_pRenderProxy, int _slot)>(0x11594D0);
	static inline auto FChangeMaterial = PreyFunction<void(ArkEmissiveComponent *const _this, IEntityRenderProxy *_pRenderProxy, int _slot, IMaterial *_pMaterialOverride)>(0x1159320);
	static inline auto FUpdateIntensity = PreyFunction<void(ArkEmissiveComponent *const _this, float _intensity)>(0x1159D40);
	static inline auto FUpdateColor = PreyFunction<void(ArkEmissiveComponent *const _this, ColorF const &_color)>(0x1159AB0);
	static inline auto FUpdateEmissiveTexture = PreyFunction<void(ArkEmissiveComponent *const _this, const char *_szEmissiveTexture)>(0x1159BC0);
	static inline auto FSetGlitchOverrides = PreyFunction<void(ArkEmissiveComponent *const _this, bool _bInterfered)>(0x11598D0);
	static inline auto FGetEmissiveTexture = PreyFunction<const char *(ArkEmissiveComponent const *const _this)>(0x1159520);
	static inline auto FLoadInterferenceOverrides = PreyFunction<void()>(0x11596A0);
};

