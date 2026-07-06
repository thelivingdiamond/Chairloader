// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
//#include <CryEngine/crycommon/particleparams_typeinfo.h>
#include <Prey/Ark/iarkposteffectmanager.h>
#include <Prey/CrySystem/ITimer.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/GameDll/ark/ArkPostEffectManager.h>
#include <Prey/GameDll/ark/iface/IArkPostEffect.h>
#include <Prey/GameDll/ark/iface/IArkPostEffectManager.h>
#include <Prey/GameDll/ark/iface/IArkPostEffectOverrideParam.h>

class ArkPostEffectDefaultParam;
struct IArkPostEffectDefaultParam;

#if 0
// Header: Override
// Prey/GameDll/ark/ArkPostEffectManager.h
struct SPostEffectCurve // Id=8015E0B Size=16
{
	TCurve<TRangedType<float, 0, 2147483647, 0> > curve;
	float duration;
};

// Header: Override
// Prey/GameDll/ark/ArkPostEffectManager.h
struct SPostEffectCurveParam // Id=8015E0C Size=72
{
	SPostEffectCurve curves[4];
	float min;
	float max;
};

// Header: FromCpp
// Prey/GameDll/ark/arkposteffectmanager.h
class ArkPostEffectOverrideParam : public IArkPostEffectOverrideParam // Id=8015E0A Size=160
{
public:
	uint64_t m_id;
	uint64_t m_effectId;
	uint64_t m_paramId;
	uint64_t m_paramHandle;
	TArkPostEffectValue m_value;
	TArkPostEffectValue m_defaultValue;
	SPostEffectCurveParam m_curveParam;
	bool m_bForceSet;

	void Load(XmlNodeRef _node) { FLoad(this, _node); }
	void PushCurveValueToEngine(SPostEffectCurve const& _curve, float _time, ITimer::ETimer _timer) const { FPushCurveValueToEngine(this, _curve, _time, _timer); }

#if 0
	uint64_t GetEffectId() const;
	uint64_t GetParamId() const;
	uint64_t GetId() const;
	uint64_t GetParamHandle() const;
	TArkPostEffectValue const& GetValue() const;
	EArkPostEffectDataType GetType() const;
	bool IsOverridden() const;
	void PushToEngine(ITimer::ETimer arg0) const;
	void SetValue(TArkPostEffectValue const& arg0);
	void ResetToDefault();
	SPostEffectCurve const& GetCurve(EPostEffectCurve arg0) const;
#endif

	static inline auto FLoad = PreyFunction<void(ArkPostEffectOverrideParam* const _this, XmlNodeRef _node)>(0x13D25F0);
	static inline auto FPushCurveValueToEngine = PreyFunction<void(ArkPostEffectOverrideParam const* const _this, SPostEffectCurve const& _curve, float _time, ITimer::ETimer _timer)>(0x13D3390);
};
#endif

class ArkPostEffectOverrideParam;

// Header: FromCpp
// Prey/GameDll/ark/arkposteffectmanager.h
class ArkPostEffect : public IArkPostEffect // Id=8015E0D Size=96
{
public:
	uint64_t m_id;
	unsigned m_priority;
	ITimer::ETimer m_timer;
	float m_duration;
	float m_startTime;
	std::unordered_map<unsigned __int64, IArkPostEffectOverrideParam*> m_overrideParams;
	string m_displayName;

	void Load(XmlNodeRef _node) { FLoad(this, _node); }
	ArkPostEffectOverrideParam* GetOrCreateOverrideParam(uint64_t _overrideId, ArkPostEffectDefaultParam* _pDefaultParam) { return FGetOrCreateOverrideParam(this, _overrideId, _pDefaultParam); }

#if 0
	string const& GetDisplayName() const;
	std::unordered_map<unsigned __int64, IArkPostEffectOverrideParam*> const& GetOverrideParams() const;
	uint64_t GetId() const;
	unsigned GetPriority() const;
	ITimer::ETimer GetTimer() const;
	float GetDuration() const;
	ArkPostEffectOverrideParam* GetOverrideParamById(uint64_t arg0) const;
	void OnEnabled();
	bool HasExpired() const;
	void Update() const;
#endif

	static inline auto FLoad = PreyFunction<void(ArkPostEffect* const _this, XmlNodeRef _node)>(0x13D23F0);
	static inline auto FGetOrCreateOverrideParam = PreyFunction<ArkPostEffectOverrideParam* (ArkPostEffect* const _this, uint64_t _overrideId, ArkPostEffectDefaultParam* _pDefaultParam)>(0x13D2050);
};

// Header: FromCpp
// Prey/GameDll/ark/ArkPostEffectManager.h
class ArkPostEffectManager : public IArkPostEffectManager // Id=8015DB3 Size=256
{
public:
	std::vector<ArkPostEffect *> m_enabledEffects;
	std::unordered_set<unsigned __int64> m_activeParams;
	uint64_t m_lastPushedEffect;
	bool m_bPushActiveEffect;
	std::unordered_map<unsigned __int64,IArkPostEffectDefaultParam *> m_defaultParams;
	std::unordered_map<unsigned __int64,IArkPostEffect *> m_effects;
	static int CV_ark_PostEffectsDebug;
	
	struct SBlendOutInfo // Id=8015E44 Size=16
	{
		ArkPostEffect const *m_pEffect;
		float m_time;
	};

	std::vector<ArkPostEffectManager::SBlendOutInfo> m_blendingOutEffects;
	
	ArkPostEffectManager();
	~ArkPostEffectManager();
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	void EnableEffect(uint64_t _effectId) { FEnableEffect(this,_effectId); }
	void DisableEffect(uint64_t _effectId, bool _bAllowBlendOut) { FDisableEffect(this,_effectId,_bAllowBlendOut); }
	bool SetOverrideParamValue(uint64_t _overrideId, TArkPostEffectValue const &_value) { return FSetOverrideParamValue(this,_overrideId,_value); }
	bool ResetOverrideParam(uint64_t _overrideId) { return FResetOverrideParam(this,_overrideId); }
	void Initialize() { FInitialize(this); }
	void Update(float _dt) { FUpdate(this,_dt); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void PreSerialize() { FPreSerialize(this); }
	ArkPostEffectOverrideParam *GetOverrideParamById(uint64_t _overrideId) const { return FGetOverrideParamById(this,_overrideId); }
	void DeleteAllDefaultParams() { FDeleteAllDefaultParams(this); }
	void DeleteAllEffects() { FDeleteAllEffects(this); }
	void LoadDefaultParams() { FLoadDefaultParams(this); }
	void LoadEffects() { FLoadEffects(this); }
	ArkPostEffectDefaultParam *GetOrCreateDefaultParam(uint64_t _paramId) { return FGetOrCreateDefaultParam(this,_paramId); }
	ArkPostEffect *GetOrCreateEffect(uint64_t _effectId) { return FGetOrCreateEffect(this,_effectId); }
	void OnEnabledEffectsUpdated() { FOnEnabledEffectsUpdated(this); }
	void PushActiveEffectToEngine() { FPushActiveEffectToEngine(this); }
	
#if 0
	void Reload();
	IArkPostEffectDefaultParam *GetDefaultParam(uint64_t arg0) const;
	IArkPostEffectOverrideParam *GetOverrideParam(uint64_t arg0) const;
	IArkPostEffect *GetEffect(uint64_t arg0) const;
	std::unordered_map<unsigned __int64,IArkPostEffectDefaultParam *> const &GetAllDefaultParams() const;
	std::unordered_map<unsigned __int64,IArkPostEffect *> const &GetAllEffects() const;
	bool GetOverrideParamValue(uint64_t arg0, TArkPostEffectValue &arg1) const;
	void DrawDebugInformation();
	bool IsValidDefaultParamId(uint64_t arg0) const;
	ArkPostEffectDefaultParam *GetDefaultParamById(uint64_t arg0) const;
	ArkPostEffect *GetEffectById(uint64_t arg0) const;
	void LoadAllXmlFiles();
	void CacheAllAssets();
	void PushDefaultParamsToEngine();
	bool IsEffectEnabled(ArkPostEffect const *arg0) const;
	void DebugDrawActiveEffects();
	void DebugDrawActiveParameters();
#endif
	
	static inline auto FBitNotArkPostEffectManager = PreyFunction<void(ArkPostEffectManager *const _this)>(0x13D0F60);
	static inline auto FReset = PreyFunction<void(ArkPostEffectManager *const _this, bool _bEnteringGameMode)>(0x13D3860);
	static inline auto FEnableEffect = PreyFunction<void(ArkPostEffectManager *const _this, uint64_t _effectId)>(0x13D1AF0);
	static inline auto FDisableEffect = PreyFunction<void(ArkPostEffectManager *const _this, uint64_t _effectId, bool _bAllowBlendOut)>(0x13D1A00);
	static inline auto FSetOverrideParamValue = PreyFunction<bool(ArkPostEffectManager *const _this, uint64_t _overrideId, TArkPostEffectValue const &_value)>(0x13D39C0);
	static inline auto FResetOverrideParam = PreyFunction<bool(ArkPostEffectManager *const _this, uint64_t _overrideId)>(0x13D3920);
	static inline auto FInitialize = PreyFunction<void(ArkPostEffectManager *const _this)>(0x13D2350);
	static inline auto FUpdate = PreyFunction<void(ArkPostEffectManager *const _this, float _dt)>(0x13D3C10);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkPostEffectManager *const _this)>(0x13D2E60);
	static inline auto FPreSerialize = PreyFunction<void(ArkPostEffectManager *const _this)>(0x13D2F10);
	static inline auto FGetOverrideParamById = PreyFunction<ArkPostEffectOverrideParam *(ArkPostEffectManager const *const _this, uint64_t _overrideId)>(0x13D2300);
	static inline auto FDeleteAllDefaultParams = PreyFunction<void(ArkPostEffectManager *const _this)>(0x13D1870);
	static inline auto FDeleteAllEffects = PreyFunction<void(ArkPostEffectManager *const _this)>(0x13D1960);
	static inline auto FLoadDefaultParams = PreyFunction<void(ArkPostEffectManager *const _this)>(0x13D27C0);
	static inline auto FLoadEffects = PreyFunction<void(ArkPostEffectManager *const _this)>(0x13D2BE0);
	static inline auto FGetOrCreateDefaultParam = PreyFunction<ArkPostEffectDefaultParam *(ArkPostEffectManager *const _this, uint64_t _paramId)>(0x13D1C10);
	static inline auto FGetOrCreateEffect = PreyFunction<ArkPostEffect *(ArkPostEffectManager *const _this, uint64_t _effectId)>(0x13D1E10);
	static inline auto FOnEnabledEffectsUpdated = PreyFunction<void(ArkPostEffectManager *const _this)>(0x13D2DF0);
	static inline auto FPushActiveEffectToEngine = PreyFunction<void(ArkPostEffectManager *const _this)>(0x13D2F80);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/iarkposteffectmanager.h>
#include <Prey/GameDll/ark/iface/IArkPostEffect.h>
#include <Prey/GameDll/ark/iface/IArkPostEffectManager.h>
#include <Prey/GameDll/ark/iface/IArkPostEffectOverrideParam.h>
#include <_unknown/ITimer.h>
#include <_unknown/TCurve.h>

class ArkPostEffectDefaultParam;
class ArkPostEffectOverrideParam;
enum class EArkPostEffectDataType;
enum EPostEffectCurve;
struct IArkPostEffectDefaultParam;
class XmlNodeRef;

// ArkPostEffect
// Header:  Prey/GameDll/ark/ArkPostEffectManager.h
class ArkPostEffect : public IArkPostEffect
{ // Size=96 (0x60)
public:
	uint64_t m_id;
	unsigned m_priority;
	ITimer::ETimer m_timer;
	float m_duration;
	float m_startTime;
	std::unordered_map<uint64_t, IArkPostEffectOverrideParam*> m_overrideParams;
	string m_displayName;

	void Load(XmlNodeRef _node) { FLoad(this, _node); }
	ArkPostEffectOverrideParam* GetOrCreateOverrideParam(uint64_t _overrideId, ArkPostEffectDefaultParam* _pDefaultParam) { return FGetOrCreateOverrideParam(this, _overrideId, _pDefaultParam); }

#if 0
	ArkPostEffect(uint64_t _arg0_);
	~ArkPostEffect();
	const string& GetDisplayName() const;
	const std::unordered_map<uint64_t, IArkPostEffectOverrideParam*>& GetOverrideParams() const;
	uint64_t GetId() const;
	unsigned GetPriority() const;
	ITimer::ETimer GetTimer() const;
	float GetDuration() const;
	ArkPostEffectOverrideParam* GetOverrideParamById(uint64_t _arg0_) const;
	void OnEnabled();
	bool HasExpired() const;
	void Update() const;
#endif

	static inline auto FLoad = PreyFunction<void(ArkPostEffect* const _this, XmlNodeRef _node)>(0x14DE2E0);
	static inline auto FGetOrCreateOverrideParam = PreyFunction<ArkPostEffectOverrideParam* (ArkPostEffect* const _this, uint64_t _overrideId, ArkPostEffectDefaultParam* _pDefaultParam)>(0x14DDF40);
};

// ArkPostEffectManager
// Header:  Prey/GameDll/ark/ArkPostEffectManager.h
class ArkPostEffectManager : public IArkPostEffectManager
{ // Size=256 (0x100)
public:
	// ArkPostEffectManager::SBlendOutInfo
	// Header:  Prey/GameDll/ark/ArkPostEffectManager.h
	struct SBlendOutInfo
	{ // Size=16 (0x10)
		const ArkPostEffect* m_pEffect;
		float m_time;

	#if 0
		SBlendOutInfo(const ArkPostEffect* _arg0_);
	#endif
	};

	std::vector<ArkPostEffect*> m_enabledEffects;
	std::unordered_set<uint64_t> m_activeParams;
	uint64_t m_lastPushedEffect;
	bool m_bPushActiveEffect;
	std::unordered_map<uint64_t, IArkPostEffectDefaultParam*> m_defaultParams;
	std::unordered_map<uint64_t, IArkPostEffect*> m_effects;
	static inline auto CV_ark_PostEffectsDebug = PreyGlobal<int>(0x2D5ABB0);
	std::vector<ArkPostEffectManager::SBlendOutInfo> m_blendingOutEffects;

	ArkPostEffectManager();
	~ArkPostEffectManager();
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void EnableEffect(uint64_t _effectId) { FEnableEffect(this, _effectId); }
	void DisableEffect(uint64_t _effectId, bool _bAllowBlendOut) { FDisableEffect(this, _effectId, _bAllowBlendOut); }
	void DisableAllEffects(bool _bAllowBlendOut) { FDisableAllEffects(this, _bAllowBlendOut); }
	bool SetOverrideParamValue(uint64_t _overrideId, const TArkPostEffectValue& _value) { return FSetOverrideParamValue(this, _overrideId, _value); }
	bool ResetOverrideParam(uint64_t _overrideId) { return FResetOverrideParam(this, _overrideId); }
	void Initialize() { FInitialize(this); }
	void Update(float _dt) { FUpdate(this, _dt); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void PreSerialize() { FPreSerialize(this); }
	ArkPostEffectOverrideParam* GetOverrideParamById(uint64_t _overrideId) const { return FGetOverrideParamById(this, _overrideId); }
	void DeleteAllDefaultParams() { FDeleteAllDefaultParams(this); }
	void DeleteAllEffects() { FDeleteAllEffects(this); }
	void LoadDefaultParams() { FLoadDefaultParams(this); }
	void LoadEffects() { FLoadEffects(this); }
	ArkPostEffectDefaultParam* GetOrCreateDefaultParam(uint64_t _paramId) { return FGetOrCreateDefaultParam(this, _paramId); }
	ArkPostEffect* GetOrCreateEffect(uint64_t _effectId) { return FGetOrCreateEffect(this, _effectId); }
	void OnEnabledEffectsUpdated() { FOnEnabledEffectsUpdated(this); }
	void PushActiveEffectToEngine() { FPushActiveEffectToEngine(this); }

#if 0
	void Reload();
	IArkPostEffectDefaultParam* GetDefaultParam(uint64_t _arg0_) const;
	IArkPostEffectOverrideParam* GetOverrideParam(uint64_t _arg0_) const;
	IArkPostEffect* GetEffect(uint64_t _arg0_) const;
	const std::unordered_map<uint64_t, IArkPostEffectDefaultParam*>& GetAllDefaultParams() const;
	const std::unordered_map<uint64_t, IArkPostEffect*>& GetAllEffects() const;
	bool GetOverrideParamValue(uint64_t _arg0_, TArkPostEffectValue& _arg1_) const;
	void DrawDebugInformation();
	bool IsValidDefaultParamId(uint64_t _arg0_) const;
	ArkPostEffectDefaultParam* GetDefaultParamById(uint64_t _arg0_) const;
	ArkPostEffect* GetEffectById(uint64_t _arg0_) const;
	void LoadAllXmlFiles();
	void CacheAllAssets();
	void PushDefaultParamsToEngine(ITimer::ETimer _arg0_);
	bool IsEffectEnabled(const ArkPostEffect* _arg0_) const;
	void DebugDrawActiveEffects();
	void DebugDrawActiveParameters();
#endif

	static inline auto FArkPostEffectManagerOv1 = PreyFunction<void(ArkPostEffectManager* const _this)>(0x14DCCD0);
	static inline auto FBitNotArkPostEffectManager = PreyFunction<void(ArkPostEffectManager* const _this)>(0x14DCE00);
	static inline auto FReset = PreyFunction<void(ArkPostEffectManager* const _this, bool _bEnteringGameMode)>(0x14DF780);
	static inline auto FEnableEffect = PreyFunction<void(ArkPostEffectManager* const _this, uint64_t _effectId)>(0x14DD9E0);
	static inline auto FDisableEffect = PreyFunction<void(ArkPostEffectManager* const _this, uint64_t _effectId, bool _bAllowBlendOut)>(0x14DD8F0);
	static inline auto FDisableAllEffects = PreyFunction<void(ArkPostEffectManager* const _this, bool _bAllowBlendOut)>(0x14DD8A0);
	static inline auto FSetOverrideParamValue = PreyFunction<bool(ArkPostEffectManager* const _this, uint64_t _overrideId, const TArkPostEffectValue& _value)>(0x14DF8E0);
	static inline auto FResetOverrideParam = PreyFunction<bool(ArkPostEffectManager* const _this, uint64_t _overrideId)>(0x14DF840);
	static inline auto FInitialize = PreyFunction<void(ArkPostEffectManager* const _this)>(0x14DE240);
	static inline auto FUpdate = PreyFunction<void(ArkPostEffectManager* const _this, float _dt)>(0x14DFB30);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkPostEffectManager* const _this)>(0x14DED80);
	static inline auto FPreSerialize = PreyFunction<void(ArkPostEffectManager* const _this)>(0x14DEE30);
	static inline auto FGetOverrideParamById = PreyFunction<ArkPostEffectOverrideParam* (const ArkPostEffectManager* const _this, uint64_t _overrideId)>(0x14DE1F0);
	static inline auto FDeleteAllDefaultParams = PreyFunction<void(ArkPostEffectManager* const _this)>(0x14DD710);
	static inline auto FDeleteAllEffects = PreyFunction<void(ArkPostEffectManager* const _this)>(0x14DD800);
	static inline auto FLoadDefaultParams = PreyFunction<void(ArkPostEffectManager* const _this)>(0x14DE6C0);
	static inline auto FLoadEffects = PreyFunction<void(ArkPostEffectManager* const _this)>(0x14DEB10);
	static inline auto FGetOrCreateDefaultParam = PreyFunction<ArkPostEffectDefaultParam* (ArkPostEffectManager* const _this, uint64_t _paramId)>(0x14DDB00);
	static inline auto FGetOrCreateEffect = PreyFunction<ArkPostEffect* (ArkPostEffectManager* const _this, uint64_t _effectId)>(0x14DDD00);
	static inline auto FOnEnabledEffectsUpdated = PreyFunction<void(ArkPostEffectManager* const _this)>(0x14DED10);
	static inline auto FPushActiveEffectToEngine = PreyFunction<void(ArkPostEffectManager* const _this)>(0x14DEEA0);
};

// SPostEffectCurve
// Header:  Prey/GameDll/ark/ArkPostEffectManager.h
struct SPostEffectCurve
{ // Size=16 (0x10)
	TCurve<TRangedType<float,0,2147483647,0> > curve;
	float duration;

#if 0
	SPostEffectCurve();
#endif
};

// SPostEffectCurveParam
// Header:  Prey/GameDll/ark/ArkPostEffectManager.h
struct SPostEffectCurveParam
{ // Size=72 (0x48)
	SPostEffectCurve curves[4];
	float min;
	float max;

#if 0
	SPostEffectCurveParam();
#endif
};

// ArkPostEffectOverrideParam
// Header:  Prey/GameDll/ark/ArkPostEffectManager.h
class ArkPostEffectOverrideParam : public IArkPostEffectOverrideParam
{ // Size=160 (0xA0)
public:
	uint64_t m_id;
	uint64_t m_effectId;
	uint64_t m_paramId;
	uint64_t m_paramHandle;
	TArkPostEffectValue m_value;
	TArkPostEffectValue m_defaultValue;
	SPostEffectCurveParam m_curveParam;
	bool m_bForceSet;

	void Load(XmlNodeRef _node) { FLoad(this, _node); }
	void PushCurveValueToEngine(const SPostEffectCurve& _curve, float _time, ITimer::ETimer _timer) const { FPushCurveValueToEngine(this, _curve, _time, _timer); }

#if 0
	ArkPostEffectOverrideParam(uint64_t _arg0_, uint64_t _arg1_, ArkPostEffectDefaultParam* _arg2_);
	~ArkPostEffectOverrideParam();
	uint64_t GetEffectId() const;
	uint64_t GetParamId() const;
	uint64_t GetId() const;
	uint64_t GetParamHandle() const;
	const TArkPostEffectValue& GetValue() const;
	EArkPostEffectDataType GetType() const;
	bool IsOverridden() const;
	void PushToEngine(ITimer::ETimer _arg0_) const;
	void SetValue(const TArkPostEffectValue& _arg0_);
	void ResetToDefault();
	const SPostEffectCurve& GetCurve(EPostEffectCurve _arg0_) const;
#endif

	static inline auto FLoad = PreyFunction<void(ArkPostEffectOverrideParam* const _this, XmlNodeRef _node)>(0x14DE4F0);
	static inline auto FPushCurveValueToEngine = PreyFunction<void(const ArkPostEffectOverrideParam* const _this, const SPostEffectCurve& _curve, float _time, ITimer::ETimer _timer)>(0x14DF2B0);
};
#endif // !MOONCRASH
