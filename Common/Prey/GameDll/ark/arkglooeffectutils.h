// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>

struct IArkGlooEffectObserver;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/arkglooeffectutils.h
class ArkGlooEffects // Id=8014231 Size=232
{
public:
	enum class State
	{
		notStarted = 0,
		slowing = 1,
		frozenHardening = 2,
		frozen = 3,
	};

	ArkSimpleTimer m_glooSlowFadeDuration;
	ArkSimpleTimer m_glooHardenDuration;
	ArkSimpleTimer m_glooFrozenDuration;
	ArkSimpleTimer m_glooOnHitCooldown;
	ArkFireAndForgetEffect m_glooBreakEffect;
	ArkFireAndForgetEffect m_glooOnHitEffect;
	ArkAudioTrigger m_glooBreakTrigger;
	ArkAudioTrigger m_glooStartTrigger;
	ArkAudioTrigger m_glooHardenTrigger;
	_smart_ptr<IMaterial> m_pGlooReplacementMaterial;
	Vec3 m_defaultDiffuseColor;
	Vec3 m_defaultSpecularColor;
	IArkGlooEffectObserver *m_pObserver;
	ArkGlooEffects::State m_state;
	float m_playbackScale;
	
	ArkGlooEffects();
	void Initialize(IEntity &_entity) { FInitialize(this,_entity); }
	void Deinitialize(IEntity &_entity) { FDeinitialize(this,_entity); }
	void Reset(IEntity &_entity) { FReset(this,_entity); }
	void Start(IEntity &_entity) { FStart(this,_entity); }
	void Update(IEntity &_entity, float _elapsedTime) { FUpdate(this,_entity,_elapsedTime); }
	virtual void Stop(IEntity &_entity, bool _bPlayEffects);
	void OnHit(IEntity &_entity, Vec3 const &_hitPos) { FOnHit(this,_entity,_hitPos); }
	void PostSerialize(IEntity &_entity) { FPostSerialize(this,_entity); }
	void UpdateGlooSkinAnimation(IEntity &_entity, float _keyTime) const { FUpdateGlooSkinAnimation(this,_entity,_keyTime); }
	void StartGlooHardening(IEntity &_entity) { FStartGlooHardening(this,_entity); }
	void CloneGlooSkinMaterial(IEntity &_entity) { FCloneGlooSkinMaterial(this,_entity); }
	void SetColorIntensity(float _intensity) const { FSetColorIntensity(this,_intensity); }
	
#if 0
	void Serialize(IEntity &arg0, TSerialize arg1);
	ArkGlooEffects::State GetState();
	bool IsHardeningInGloo() const;
	bool IsFrozenInGloo() const;
	void SetObserver(IArkGlooEffectObserver &arg0);
	void ClearObserver();
	float GetPlaybackScale() const;
	void StartGlooSkinAnimation(IEntity &arg0) const;
	void StopGlooSkinAnimation(IEntity &arg0) const;
	void ShowGlooSkin(IEntity &arg0) const;
	void HideGlooSkin(IEntity &arg0) const;
	void UpdateHardened(IEntity &arg0, float arg1);
	void StartFrozen(IEntity &arg0);
	void SetPlaybackScale(IEntity &arg0, float arg1);
	void SetHardenedBlendFactor(float arg0) const;
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkGlooEffects *const _this, IEntity &_entity)>(0x117D070);
	static inline auto FDeinitialize = PreyFunction<void(ArkGlooEffects *const _this, IEntity &_entity)>(0x117CED0);
	static inline auto FReset = PreyFunction<void(ArkGlooEffects *const _this, IEntity &_entity)>(0x117D2A0);
	static inline auto FStart = PreyFunction<void(ArkGlooEffects *const _this, IEntity &_entity)>(0x117DC40);
	static inline auto FUpdate = PreyFunction<void(ArkGlooEffects *const _this, IEntity &_entity, float _elapsedTime)>(0x117E3B0);
	static inline auto FStop = PreyFunction<void(ArkGlooEffects *const _this, IEntity &_entity, bool _bPlayEffects)>(0x117DF70);
	static inline auto FOnHit = PreyFunction<void(ArkGlooEffects *const _this, IEntity &_entity, Vec3 const &_hitPos)>(0x117D0C0);
	static inline auto FPostSerialize = PreyFunction<void(ArkGlooEffects *const _this, IEntity &_entity)>(0x117D150);
	static inline auto FUpdateGlooSkinAnimation = PreyFunction<void(ArkGlooEffects const *const _this, IEntity &_entity, float _keyTime)>(0x117E530);
	static inline auto FStartGlooHardening = PreyFunction<void(ArkGlooEffects *const _this, IEntity &_entity)>(0x117DE10);
	static inline auto FCloneGlooSkinMaterial = PreyFunction<void(ArkGlooEffects *const _this, IEntity &_entity)>(0x117CDA0);
	static inline auto FSetColorIntensity = PreyFunction<void(ArkGlooEffects const *const _this, float _intensity)>(0x117DAE0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkglooeffectutils.h
class ArkGlooEffectAccumulated : public ArkGlooEffects // Id=8014230 Size=248
{
public:
	float m_currentGlooEffectAccumulation;
	float m_currentMaxGlooEffectAccumulation;
	float m_glooFreezeThreshold;
	float m_glooEffectAccumulationAmountPerSecond;
	
	ArkGlooEffectAccumulated();
	~ArkGlooEffectAccumulated() { FBitNotArkGlooEffectAccumulated(this); }
	void Serialize(IEntity &_entity, TSerialize _ser) { FSerialize(this,_entity,_ser); }
	void Start(IEntity &_entity) { FStart(this,_entity); }
	void Update(IEntity &_entity, float _elapsedTime) { FUpdate(this,_entity,_elapsedTime); }
	virtual void Stop(IEntity &_entity, bool _bPlayEffects);
	void SkipToFrozen(IEntity &_entity) { FSkipToFrozen(this,_entity); }
	void SetCurrentMaxGlooEffectAccumulation(float _amount) { FSetCurrentMaxGlooEffectAccumulation(this,_amount); }
	void SetGlooEffectAccumulationAmountPerSecond(float _amount) { FSetGlooEffectAccumulationAmountPerSecond(this,_amount); }
	void SetGlooEffectFreezeThreshold(float _amount) { FSetGlooEffectFreezeThreshold(this,_amount); }
	bool IsGoingToFreeze() const { return FIsGoingToFreeze(this); }
	
#if 0
	void Reset(IEntity &arg0);
	void UpdateSlowing(IEntity &arg0, float arg1);
#endif
	
	static inline auto FBitNotArkGlooEffectAccumulated = PreyFunction<void(ArkGlooEffectAccumulated *const _this)>(0x117CCB0);
	static inline auto FSerialize = PreyFunction<void(ArkGlooEffectAccumulated *const _this, IEntity &_entity, TSerialize _ser)>(0x117D8A0);
	static inline auto FStart = PreyFunction<void(ArkGlooEffectAccumulated *const _this, IEntity &_entity)>(0x117DBE0);
	static inline auto FUpdate = PreyFunction<void(ArkGlooEffectAccumulated *const _this, IEntity &_entity, float _elapsedTime)>(0x117E1C0);
	static inline auto FStop = PreyFunction<void(ArkGlooEffectAccumulated *const _this, IEntity &_entity, bool _bPlayEffects)>(0x117DF10);
	static inline auto FSkipToFrozen = PreyFunction<void(ArkGlooEffectAccumulated *const _this, IEntity &_entity)>(0x117DBD0);
	static inline auto FSetCurrentMaxGlooEffectAccumulation = PreyFunction<void(ArkGlooEffectAccumulated *const _this, float _amount)>(0x1B210A0);
	static inline auto FSetGlooEffectAccumulationAmountPerSecond = PreyFunction<void(ArkGlooEffectAccumulated *const _this, float _amount)>(0x117DBB0);
	static inline auto FSetGlooEffectFreezeThreshold = PreyFunction<void(ArkGlooEffectAccumulated *const _this, float _amount)>(0x117DBC0);
	static inline auto FIsGoingToFreeze = PreyFunction<bool(ArkGlooEffectAccumulated const *const _this)>(0x117D0A0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkglooeffectutils.h
class ArkGlooEffectTimed : public ArkGlooEffects // Id=80152EE Size=240
{
public:
	ArkSimpleTimer m_glooSlowDuration;
	
	ArkGlooEffectTimed();
	~ArkGlooEffectTimed() { FBitNotArkGlooEffectTimed(this); }
	void Reset(IEntity &_entity) { FReset(this,_entity); }
	void Serialize(IEntity &_entity, TSerialize _ser) { FSerialize(this,_entity,_ser); }
	void Start(IEntity &_entity) { FStart(this,_entity); }
	void Update(IEntity &_entity, float _elapsedTime) { FUpdate(this,_entity,_elapsedTime); }
	virtual void Stop(IEntity &_entity, bool _bPlayEffects);
	float GetPlaybackScale() const { return FGetPlaybackScale(this); }
	
#if 0
	void SkipToFrozen(IEntity &arg0);
	void UpdateSlowing(IEntity &arg0, float arg1);
#endif
	
	static inline auto FBitNotArkGlooEffectTimed = PreyFunction<void(ArkGlooEffectTimed *const _this)>(0x117CCB0);
	static inline auto FReset = PreyFunction<void(ArkGlooEffectTimed *const _this, IEntity &_entity)>(0x117D190);
	static inline auto FSerialize = PreyFunction<void(ArkGlooEffectTimed *const _this, IEntity &_entity, TSerialize _ser)>(0x117D9F0);
	static inline auto FStart = PreyFunction<void(ArkGlooEffectTimed *const _this, IEntity &_entity)>(0x117DC00);
	static inline auto FUpdate = PreyFunction<void(ArkGlooEffectTimed *const _this, IEntity &_entity, float _elapsedTime)>(0x117E2C0);
	static inline auto FStop = PreyFunction<void(ArkGlooEffectTimed *const _this, IEntity &_entity, bool _bPlayEffects)>(0x117DF20);
	static inline auto FGetPlaybackScale = PreyFunction<float(ArkGlooEffectTimed const *const _this)>(0x117D040);
};

