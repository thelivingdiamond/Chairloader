// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/Ark/arksignalsystemdata.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleCharge.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/cystoid/ArkCystoidPotentialTarget.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry.h>
#include <_unknown/ArkGenericAttentionObject.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class ICrySizer;
struct IGameObject;
struct IMaterial;
struct SEntityEvent;
struct SGameObjectEvent;

// ArkTyphonNest
// Header:  Prey/GameDll/ark/environment/ArkTyphonNest.h
class ArkTyphonNest : public ArkEnvironmentalObject
{ // Size=512 (0x200)
public:
	ArkSimpleCharge m_nullWaveAccumulation;
	ArkFireAndForgetEffect m_spawnVfx;
	QuatT m_vfxLoc;
	EArkTyphonNestState m_state;
	unsigned m_chosenTarget;
	bool m_bDamagedByPlayer;
	bool m_bInZeroG;
	std::vector<ArkCystoidPotentialTarget> m_potentialTargets;
	ArkSimpleTimer m_timer;
	ArkSimpleTimer m_delayedActivation;
	ArkSimpleTimer m_activeDuration;
	ArkFireAndForgetEffect m_destroyedVfx;
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_TyphonNest> m_spatialManagerEntry;
	uint64_t m_randomValueSeed;
	int m_activateAnimId;
	int m_deactivateAnimId;
	int m_idleAnimId;
	int m_lastZeroGUpdateSlice;
	float m_monitorRadius;
	float m_targetSpeedThresholdSq;
	float m_playerSpeedThresholdSq;
	string m_primedMaterial;
	string m_destroyedModel;
	const ArkSignalSystem::Data::SignalGroupData* m_pDamagingSignalGroup;
	const ArkSignalSystem::Data::SignalGroupData* m_pTriggerSignalGroup;
	uint64_t m_nullWaveSignal;
	std::vector<uint64_t> m_tagsToIgnore;
	ArkAudioTrigger m_triggerExistStart;
	ArkAudioTrigger m_triggerTriggered;
	ArkAudioTrigger m_triggerExplode;
	ArkAudioTrigger m_triggerActivate;
	ArkAudioTrigger m_triggerDeactivate;
	ArkGenericAttentionObject<ArkTyphonNest> m_attentionObject;

	ArkTyphonNest();
	virtual ~ArkTyphonNest();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	void ForceTrigger(unsigned _forcedTarget) { FForceTrigger(this, _forcedTarget); }
	QuatT GetAttachmentLoc(const char* _attachmentName) { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FGetAttachmentLoc(this, reinterpret_cast<QuatT*>(_return_buf_), _attachmentName); }
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual void LoadGravityProperties();
	virtual void InitCachedPositionData();
	virtual void UpdateFromCystoidManager(const float _frameTime, const int _zeroGUpdateSlice, bool& _bDidZeroGTest);
	virtual bool SetState(EArkTyphonNestState _state, bool _bForce);
	virtual bool IsActive() const;
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);
	virtual void RegisterForSignals(bool _bRegister);
	virtual bool CanActivate() const;
	virtual bool SpawnTyphon() = 0;
	void SetMaterial(IMaterial* const _material) const { FSetMaterial(this, _material); }
	void PlayAnimation(int _animId, int _layer, bool _bLooping) { FPlayAnimation(this, _animId, _layer, _bLooping); }
	void LoadAnimIDs() { FLoadAnimIDs(this); }
	void EnableAttentionObject() { FEnableAttentionObject(this); }
	void DisableAttentionObject() { FDisableAttentionObject(this); }

#if 0
	bool IsDepleted() const;
	void SetRandomValueSeed(const uint64_t _arg0_);
	uint64_t GetRandomValueSeed() const;
	void InitArea();
#endif

	static inline auto FArkTyphonNest = PreyFunction<void(ArkTyphonNest* const _this)>(0x11D9490);
	static inline auto FBitNotArkTyphonNest = PreyFunction<void(ArkTyphonNest* const _this)>(0x11D9640);
	static inline auto FInit = PreyFunction<bool(ArkTyphonNest* const _this, IGameObject* _pGameObject)>(0x11DA3B0);
	static inline auto FPostInit = PreyFunction<void(ArkTyphonNest* const _this, IGameObject* _pGameObject)>(0x11DC1D0);
	static inline auto FRelease = PreyFunction<void(ArkTyphonNest* const _this)>(0x11DC700);
	static inline auto FFullSerialize = PreyFunction<void(ArkTyphonNest* const _this, TSerialize _ser)>(0x11D9890);
	static inline auto FPostSerialize = PreyFunction<void(ArkTyphonNest* const _this)>(0x11DC2C0);
	static inline auto FHandleEvent = PreyFunction<void(ArkTyphonNest* const _this, const SGameObjectEvent& _event)>(0x11DA2F0);
	static inline auto FProcessEvent = PreyFunction<void(ArkTyphonNest* const _this, SEntityEvent& _event)>(0x11DC2E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkTyphonNest* const _this, ICrySizer* _s)>(0x11DA280);
	static inline auto FForceTrigger = PreyFunction<void(ArkTyphonNest* const _this, unsigned _forcedTarget)>(0x11D9840);
	static inline auto FGetAttachmentLoc = PreyFunction<QuatT*(ArkTyphonNest* const _this, QuatT* _return_value_, const char* _attachmentName)>(0x11D9BC0);
	static inline auto FOnReset = PreyFunction<void(ArkTyphonNest* const _this, bool _bEnteringGameMode)>(0x11DBFE0);
	static inline auto FLoadProperties = PreyFunction<void(ArkTyphonNest* const _this)>(0x11DADE0);
	static inline auto FLoadGravityProperties = PreyFunction<void(ArkTyphonNest* const _this)>(0x11DA8D0);
	static inline auto FInitCachedPositionData = PreyFunction<void(ArkTyphonNest* const _this)>(0x11DA4B0);
	static inline auto FUpdateFromCystoidManager = PreyFunction<void(ArkTyphonNest* const _this, const float _frameTime, const int _zeroGUpdateSlice, bool& _bDidZeroGTest)>(0x11DCD20);
	static inline auto FSetState = PreyFunction<bool(ArkTyphonNest* const _this, EArkTyphonNestState _state, bool _bForce)>(0x11DC840);
	static inline auto FIsActive = PreyFunction<bool(const ArkTyphonNest* const _this)>(0x13B0900);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkTyphonNest* const _this, const ArkSignalSystem::Package& _package)>(0x11DBC00);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkTyphonNest* const _this, bool _bRegister)>(0x11DC5D0);
	static inline auto FCanActivate = PreyFunction<bool(const ArkTyphonNest* const _this)>(0x11D97C0);
	static inline auto FSetMaterial = PreyFunction<void(const ArkTyphonNest* const _this, IMaterial* const _material)>(0x11DC7D0);
	static inline auto FPlayAnimation = PreyFunction<void(ArkTyphonNest* const _this, int _animId, int _layer, bool _bLooping)>(0x11DC100);
	static inline auto FLoadAnimIDs = PreyFunction<void(ArkTyphonNest* const _this)>(0x11DA680);
	static inline auto FEnableAttentionObject = PreyFunction<void(ArkTyphonNest* const _this)>(0x11D9810);
	static inline auto FDisableAttentionObject = PreyFunction<void(ArkTyphonNest* const _this)>(0x11D97D0);
};
#endif // MOONCRASH
