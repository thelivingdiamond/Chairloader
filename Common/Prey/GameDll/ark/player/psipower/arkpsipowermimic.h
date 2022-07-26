// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerMimicTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipower3dtargetingcomponent.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipoweralientargetingcomponent.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerfear.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerthermalblast.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblastmanager.h>
#include <_perforce/danielle/preybnet/code/arkane/arkcommon/reflect/arkreflectionaccessors.h>
#include <_unknown/IArkBreakableListener.h>

class ArkInputLegend;
class ArkPsiPowerTargetingComponent;
class CCryName;
struct IEntity;
struct SViewParams;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipowermimic.h
class CArkPsiPowerMimic : public CArkPsiPower<MimicPowerProperties>, public IArkBreakableListener // Id=80194CF Size=808
{
public:
	using BaseType = CArkPsiPower<MimicPowerProperties>;
	
	ArkPsiPowerMimicTargetingComponent m_targetingComponent;
	ArkSimpleTimer m_morphOutTimer;
	ArkSimpleTimer m_gameNoiseTimer;
	QuatT m_initialWorldTransform;
	Vec3 m_initialVelocity;
	Vec3 m_safeWorldPosition;
	std::vector<unsigned int> m_cameraOverlappingEntities;
	std::unique_ptr<IArkPlayerMimic> m_pPsiMimic;
	unsigned m_clonedEntityId;
	int m_persistentParticleEffectSlot;
	bool m_bMorphingIn;
	bool m_bMorphingOut;
	bool m_bPendingMorphIn;
	bool m_bDelayMorphInFrame;
	
	void CArkPsiPowerMimic();
	virtual void Cancel();
	virtual void OnReset();
	virtual void Update(const float _frameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual void RefreshTargets();
	virtual std::vector<IEntity *> GetSelectedTargets() const;
	virtual std::vector<IEntity *> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual ArkInputLegend const &GetModalLegend() const;
	virtual bool CanEnterFocusMode(EArkPsiPowers const &_equippedPower) const;
	virtual void ProcessInput(CCryName const &_actionId, int _activationMode, float _value);
	virtual void ProcessInputForTargeting(CCryName const &_actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _serializer);
	virtual void PostSerialize();
	virtual ArkPsiPowerTargetingComponent const *GetTargetingComponent() const;
	virtual EArkPsiPowers GetEnum() const;
	virtual bool ShouldGenerateGameNoises() const;
	virtual void OnBroken(IEntity const &_entity);
	bool MorphOut() { return FMorphOut(this); }
	void FinishMorphIn() { FFinishMorphIn(this); }
	void MorphInObject() { FMorphInObject(this); }
	bool IsInZeroG() const { return FIsInZeroG(this); }
	float GetMimicVisibility() const { return FGetMimicVisibility(this); }
	unsigned GetTargetedEntityId() const { return FGetTargetedEntityId(this); }
	unsigned GetMimickedEntityId() const { return FGetMimickedEntityId(this); }
	void CleanUp() { FCleanUp(this); }
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual bool GetCanCancel() const;
	void UpdateCamera(SViewParams &_params) { FUpdateCamera(this,_params); }
	virtual void SetLevel_Derived(const int _level);
	virtual EArkPsiPowerError GetExecutionError() const;
	bool PlayerCanFit(EStance _stance, Vec3 const &_position) const { return FPlayerCanFit(this,_stance,_position); }
	boost::optional<QuatT> ComputeInitialWorldTransform(IEntity const &_targetEntity) const { return FComputeInitialWorldTransform(this,_targetEntity); }
	bool FilterTarget(IEntity const &_entity) const { return FFilterTarget(this,_entity); }
	
#if 0
	bool QueueMorphInAction();
#endif
	
	static inline auto FCancel = PreyFunction<void(CArkPsiPowerMimic *const _this)>(0x159AF80);
	static inline auto FOnReset = PreyFunction<void(CArkPsiPowerMimic *const _this)>(0x159C780);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerMimic *const _this, const float _frameTime)>(0x159DC80);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerMimic *const _this)>(0x159D560);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerMimic *const _this, const float _fFrameTime)>(0x159E610);
	static inline auto FRefreshTargets = PreyFunction<void(CArkPsiPowerMimic *const _this)>(0x159D0F0);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity *>(CArkPsiPowerMimic const *const _this)>(0x15A2A60);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity *>(CArkPsiPowerMimic const *const _this)>(0x15A2A80);
	static inline auto FGetTargetPosition = PreyFunction<Vec3(CArkPsiPowerMimic const *const _this)>(0x159BFC0);
	static inline auto FGetModalLegend = PreyFunction<ArkInputLegend const &(CArkPsiPowerMimic const *const _this)>(0x159BEA0);
	static inline auto FCanEnterFocusMode = PreyFunction<bool(CArkPsiPowerMimic const *const _this, EArkPsiPowers const &_equippedPower)>(0x159AF60);
	static inline auto FProcessInput = PreyFunction<void(CArkPsiPowerMimic *const _this, CCryName const &_actionId, int _activationMode, float _value)>(0x159D020);
	static inline auto FProcessInputForTargeting = PreyFunction<void(CArkPsiPowerMimic *const _this, CCryName const &_actionId, int _activationMode, float _value)>(0xA13080);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerMimic *const _this, TSerialize _serializer)>(0x159D150);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerMimic *const _this)>(0x159CEF0);
	static inline auto FGetTargetingComponent = PreyFunction<ArkPsiPowerTargetingComponent const *(CArkPsiPowerMimic const *const _this)>(0x222910);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(CArkPsiPowerMimic const *const _this)>(0x1C4890);
	static inline auto FShouldGenerateGameNoises = PreyFunction<bool(CArkPsiPowerMimic const *const _this)>(0x159D4D0);
	static inline auto FOnBroken = PreyFunction<void(CArkPsiPowerMimic *const _this, IEntity const &_entity)>(0x159C700);
	static inline auto FMorphOut = PreyFunction<bool(CArkPsiPowerMimic *const _this)>(0x159C110);
	static inline auto FFinishMorphIn = PreyFunction<void(CArkPsiPowerMimic *const _this)>(0x159B850);
	static inline auto FMorphInObject = PreyFunction<void(CArkPsiPowerMimic *const _this)>(0x159C040);
	static inline auto FIsInZeroG = PreyFunction<bool(CArkPsiPowerMimic const *const _this)>(0x159C010);
	static inline auto FGetMimicVisibility = PreyFunction<float(CArkPsiPowerMimic const *const _this)>(0x159BD50);
	static inline auto FGetTargetedEntityId = PreyFunction<unsigned(CArkPsiPowerMimic const *const _this)>(0x159C000);
	static inline auto FGetMimickedEntityId = PreyFunction<unsigned(CArkPsiPowerMimic const *const _this)>(0x159BE80);
	static inline auto FCleanUp = PreyFunction<void(CArkPsiPowerMimic *const _this)>(0x159AF90);
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerMimic *const _this)>(0x159D8F0);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerMimic *const _this)>(0x159D590);
	static inline auto FGetCanCancel = PreyFunction<bool(CArkPsiPowerMimic const *const _this)>(0x159BB50);
	static inline auto FUpdateCamera = PreyFunction<void(CArkPsiPowerMimic *const _this, SViewParams &_params)>(0x159E4A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerMimic *const _this, const int _level)>(0x159D3F0);
	static inline auto FGetExecutionError = PreyFunction<EArkPsiPowerError(CArkPsiPowerMimic const *const _this)>(0x15A22E0);
	static inline auto FPlayerCanFit = PreyFunction<bool(CArkPsiPowerMimic const *const _this, EStance _stance, Vec3 const &_position)>(0x159C7A0);
	static inline auto FComputeInitialWorldTransform = PreyFunction<boost::optional<QuatT>(CArkPsiPowerMimic const *const _this, IEntity const &_targetEntity)>(0x159B150);
	static inline auto FFilterTarget = PreyFunction<bool(CArkPsiPowerMimic const *const _this, IEntity const &_entity)>(0x159B600);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipowermimic.h
class CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,1> : public CArkPsiPower<ThermalBlastPowerProperties> // Id=801C187 Size=696
{
public:
	using Properties = ThermalBlastPowerProperties;
	using BaseType = CArkPsiPower<ThermalBlastPowerProperties>;
	
	_smart_ptr<IParticleEffect> m_pTargetingEffect;
	CArkPsiPower3DTargetingComponent m_targetingComponent;
	CArkPsiBlastManager<CArkPsiThermalBlast> m_blastManager;
	
#if 0
	virtual void Cancel();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity *> GetSelectedTargets() const;
	virtual std::vector<IEntity *> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual ArkPsiPowerTargetingComponent const *GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(CCryName const &_actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipowermimic.h
class CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,3> : public CArkPsiPower<KineticBlastPowerProperties> // Id=801C8C9 Size=696
{
public:
	using Properties = KineticBlastPowerProperties;
	using BaseType = CArkPsiPower<KineticBlastPowerProperties>;
	
	_smart_ptr<IParticleEffect> m_pTargetingEffect;
	CArkPsiPower3DTargetingComponent m_targetingComponent;
	CArkPsiBlastManager<CArkPsiKineticBlast> m_blastManager;
	
#if 0
	virtual void Cancel();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity *> GetSelectedTargets() const;
	virtual std::vector<IEntity *> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual ArkPsiPowerTargetingComponent const *GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(CCryName const &_actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipowermimic.h
class CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0> : public CArkPsiPower<ElectrostaticBurstPowerProperties> // Id=801C8E6 Size=696
{
public:
	using Properties = ElectrostaticBurstPowerProperties;
	using BaseType = CArkPsiPower<ElectrostaticBurstPowerProperties>;
	
	_smart_ptr<IParticleEffect> m_pTargetingEffect;
	CArkPsiPower3DTargetingComponent m_targetingComponent;
	CArkPsiBlastManager<CArkPsiElectrostaticBurst> m_blastManager;
	
#if 0
	virtual void Cancel();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity *> GetSelectedTargets() const;
	virtual std::vector<IEntity *> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual ArkPsiPowerTargetingComponent const *GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(CCryName const &_actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipowermimic.h
class CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,8> : public CArkPsiPower<FearPowerProperties> // Id=801C907 Size=696
{
public:
	using Properties = FearPowerProperties;
	using BaseType = CArkPsiPower<FearPowerProperties>;
	
	_smart_ptr<IParticleEffect> m_pTargetingEffect;
	CArkPsiPowerAlienTargetingComponent m_targetingComponent;
	CArkPsiBlastManager<CArkPsiFearBlast> m_blastManager;
	
#if 0
	virtual void Cancel();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity *> GetSelectedTargets() const;
	virtual std::vector<IEntity *> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual ArkPsiPowerTargetingComponent const *GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(CCryName const &_actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
#endif
};

