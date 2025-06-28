// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDisruptable.h>
#include <Prey/GameDll/ark/ArkRepairable.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/iface/IArkDisruptableListener.h>
#include <Prey/GameDll/ark/iface/IArkRepairableListener.h>

namespace ArkSignalSystem
{
class Data;
class Package;
} // namespace ArkSignalSystem
class ICrySizer;
struct IEntity;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkElectricalBox.h
class ArkElectricalBox : public ArkEnvironmentalObject, public IArkRepairableListener, public IArkDisruptableListener, public IEntityEventListener // Id=801A9CE Size=1032
{
public:
	unsigned m_instigatorId;
	ArkRandomizedAutoResetTimer m_sparkTimer;
	std::vector<unsigned int> m_arcs;
	std::vector<Vec3> m_arcPositions;
	bool m_bPowered;
	bool m_bZapOccurred;
	bool m_bUpdating;
	std::vector<unsigned int> m_targets;
	bool m_bTargetsChanged;
	unsigned m_decalId;
	float m_gooAccumulation;
	ArkRepairable m_repairable;
	ArkDisruptable m_disruptable;
	ArkFireAndForgetEffect m_flashVfx;
	ArkEntityEffect m_idleVfx;
	ArkEntityEffect m_warningVfx;
	bool m_bIsPlayerTarget;
	bool m_bStartsPowered;
	ArkSignalSystem::Data::SignalGroupData const *m_pDamageSignalGroup;
	float m_sparkVFXScale;
	float m_hazardRadius;
	float m_maxGooAccumulation;
	float m_gooDrainRate;
	float m_gooSparkWarningTime;
	float m_gooBreakWarningTime;
	float m_gooDecalSize;
	float m_instigationDecayTime;
	float m_playerZeroGImpulseScale;
	Vec3 m_gooDecalPos;
	uint64_t m_hazardSignalPackage;
	uint64_t m_gooSignal;
	ArkAudioTrigger m_triggerZap;
	ArkAudioTrigger m_triggerPowerOff;
	ArkAudioTrigger m_triggerIntactLoop;
	ArkAudioTrigger m_triggerHazardLoop;
	ArkAudioTrigger m_triggerWarningLoop;
	ArkAudioTrigger m_triggerWarningStop;
	unsigned m_numArcs;
	string m_lightningMaterial;
	string m_gooDecalMaterial;
	uint64_t m_lightningArcArchetype;
	std::vector<string> m_hazardBlackList;
	
	ArkElectricalBox();
	virtual ~ArkElectricalBox();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &ctx, int updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	void OnLightningCallback(IEntity *_pArc, IEntity *_pTarget, float _strikeTime) { FOnLightningCallback(this,_pArc,_pTarget,_strikeTime); }
	void SetPowered(bool _bPowered, unsigned _activator) { FSetPowered(this,_bPowered,_activator); }
	void InitArea() { FInitArea(this); }
	virtual void AddTarget(unsigned _entityId);
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual void RegisterForSignals(bool _bRegister);
	void UpdateHazardTargets() { FUpdateHazardTargets(this); }
	void RecheckFortifyTargets() { FRecheckFortifyTargets(this); }
	void UpdateArcs() { FUpdateArcs(this); }
	void CreateArcs() { FCreateArcs(this); }
	void ExplodeNearbyGoo() { FExplodeNearbyGoo(this); }
	void ClearGooAccumulation() { FClearGooAccumulation(this); }
	void UpdateGooAccumulation(float _delta) { FUpdateGooAccumulation(this,_delta); }
	void StartWarning() { FStartWarning(this); }
	void StopWarning(bool _bImmediate) { FStopWarning(this,_bImmediate); }
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);
	virtual void OnFortified();
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual QuatT GetSparkLoc() const;
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	void ClearArcs() { FClearArcs(this); }
	
#if 0
	float GetHazardRadius() const;
	void Spark();
	void UpdateAudio();
	void UpdateHazardFeedback();
	bool IsWarning() const;
	bool ShouldGooBeBroken() const;
#endif
	
	static inline auto FBitNotArkElectricalBox = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B2EE0);
	static inline auto FInit = PreyFunction<bool(ArkElectricalBox *const _this, IGameObject *_pGameObject)>(0x13B40B0);
	static inline auto FPostInit = PreyFunction<void(ArkElectricalBox *const _this, IGameObject *_pGameObject)>(0x13B6490);
	static inline auto FFullSerialize = PreyFunction<void(ArkElectricalBox *const _this, TSerialize _ser)>(0x13B3C70);
	static inline auto FPostSerialize = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B64E0);
	static inline auto FUpdate = PreyFunction<void(ArkElectricalBox *const _this, SEntityUpdateContext &ctx, int updateSlot)>(0x13B6BA0);
	static inline auto FProcessEvent = PreyFunction<void(ArkElectricalBox *const _this, SEntityEvent &_event)>(0x13B6550);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkElectricalBox const *const _this, ICrySizer *_s)>(0x13B3F10);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkElectricalBox *const _this, ArkSignalSystem::Package const &_package)>(0x13B5F70);
	static inline auto FOnLightningCallback = PreyFunction<void(ArkElectricalBox *const _this, IEntity *_pArc, IEntity *_pTarget, float _strikeTime)>(0x13B5A90);
	static inline auto FSetPowered = PreyFunction<void(ArkElectricalBox *const _this, bool _bPowered, unsigned _activator)>(0x13B6940);
	static inline auto FInitArea = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B41C0);
	static inline auto FAddTarget = PreyFunction<void(ArkElectricalBox *const _this, unsigned _entityId)>(0x13B3420);
	static inline auto FOnReset = PreyFunction<void(ArkElectricalBox *const _this, bool _bEnteringGameMode)>(0x13B6290);
	static inline auto FLoadProperties = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B4580);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkElectricalBox *const _this, bool _bRegister)>(0x13B6830);
	static inline auto FUpdateHazardTargets = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B6EE0);
	static inline auto FRecheckFortifyTargets = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B6650);
	static inline auto FUpdateArcs = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B6CF0);
	static inline auto FCreateArcs = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B36D0);
	static inline auto FExplodeNearbyGoo = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B3AA0);
	static inline auto FClearGooAccumulation = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B3640);
	static inline auto FUpdateGooAccumulation = PreyFunction<void(ArkElectricalBox *const _this, float _delta)>(0x13B6DB0);
	static inline auto FStartWarning = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B6A30);
	static inline auto FStopWarning = PreyFunction<void(ArkElectricalBox *const _this, bool _bImmediate)>(0x13B6AA0);
	static inline auto FOnBrokenChanged = PreyFunction<void(ArkElectricalBox *const _this, bool _bBroken, bool _bWasForced)>(0x13B56A0);
	static inline auto FOnFortified = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B5A00);
	static inline auto FOnDisruptedChanged = PreyFunction<void(ArkElectricalBox *const _this, bool _bDisrupted, bool _bWasForced)>(0x13B58A0);
	static inline auto FGetSparkLoc = PreyFunction<QuatT(ArkElectricalBox const *const _this)>(0x13B3FD0);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkElectricalBox *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x13B5950);
	static inline auto FClearArcs = PreyFunction<void(ArkElectricalBox *const _this)>(0x13B3570);
};

