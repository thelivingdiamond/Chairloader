// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryEntitySystem/IEntityRenderState.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalHazard.h>
#include <Prey/GameDll/ark/iface/IArkGroundColliderListener.h>
#include <Prey/GameDll/ark/iface/IArkPsiPowerTargetingListener.h>

namespace ArkSignalSystem
{
class Data;
class Package;
} // namespace ArkSignalSystem
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IRenderNode;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: Exact
// Prey/GameDll/ark/environment/ArkSurfaceHazard.h
class ArkSurfaceHazard : public ArkEnvironmentalHazard, public IArkPsiPowerTargetingListener, public IArkGroundColliderListener // Id=801BE76 Size=768
{
public:
	enum class ForceType
	{
		none = 0,
		init = 1,
		serialize = 2,
	};

	EArkSurfaceHazardState m_state;
	ArkSimpleTimer m_hazardStateTimer;
	ArkSimpleTimer m_depletedDelay;
	ArkSimpleTimer m_triggerDelay;
	ArkSimpleTimer m_neighborActivationCooldown;
	ArkAutoResetTimer m_hazardIntervalTimer;
	std::vector<unsigned int> m_neighbors;
	IRenderNode *m_pDecal;
	ArkEntityEffect m_hazardVfx;
	ArkFireAndForgetEffect m_explosionVfx;
	ArkFireAndForgetEffect m_deactivateVfx;
	bool m_bTriggerExplosionVfx;
	bool m_bPlayerTouchedSinceLastPulse;
	float m_hazardRadius;
	float m_hazardLength;
	float m_hazardWidth;
	bool m_bEffectOnCollision;
	bool m_bEffectOnProximity;
	bool m_bDepletesAfterDuration;
	bool m_bRefreshDurationOnActivation;
	bool m_bPlaceHazardVFX;
	uint64_t m_explosionHazard;
	ArkAudioTrigger m_triggerActivate;
	ArkAudioTrigger m_triggerDeactivate;
	ArkSignalSystem::Data::SignalGroupData const *m_pActivatingSignalGroup;
	ArkSignalSystem::Data::SignalGroupData const *m_pDeactivatingSignalGroup;
	bool m_bStartsEnabled;
	SDecalProperties m_decalProperties;
	SDecalProperties m_depletedDecalProperties;
	
	ArkSurfaceHazard();
	virtual ~ArkSurfaceHazard();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &ctx, int updateSlot);
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	void ActivateHazard(bool _bFromNeighbor) { FActivateHazard(this,_bFromNeighbor); }
	void DeactivateHazard(bool _bNeighbors) { FDeactivateHazard(this,_bNeighbors); }
	virtual void RegisterForSignals(bool _bRegister);
	bool IsWithinProximity(IEntity const *_pEntity, Vec3 _center) const { return FIsWithinProximity(this,_pEntity,_center); }
	virtual void LoadProperties();
	virtual void OnGroundEntityChanged(IEntity const *_pOwner, IEntity const *_pOldEntity, IEntity const *_pNewEntity);
	bool SetState(EArkSurfaceHazardState _state, ArkSurfaceHazard::ForceType _forceType) { return FSetState(this,_state,_forceType); }
	virtual void OnReset(bool _bEnteringGameMode);
	void HitTargetWithHazard(IEntity *_pTarget) const { FHitTargetWithHazard(this,_pTarget); }
	bool CanActivateHazard(ArkSignalSystem::Package const &_package, bool _bFromNeighbor) const { return FCanActivateHazard(this,_package,_bFromNeighbor); }
	bool CanDeactivateHazard(ArkSignalSystem::Package const &_package) const { return FCanDeactivateHazard(this,_package); }
	void ActivateNeighbors() const { FActivateNeighbors(this); }
	void DeactivateNeighbors() const { FDeactivateNeighbors(this); }
	virtual void AddTarget(unsigned _target);
	virtual void RemoveTarget(unsigned _target);
	void SetupDecal(SDecalProperties &_properties) { FSetupDecal(this,_properties); }
	void InitialExplosion() { FInitialExplosion(this); }
	virtual AABB GetLocalAreaBounds() const;
	virtual bool ShouldUpdateWithTargets() const;
	virtual void OnPsiTargetingStart(const unsigned _targetEntity);
	virtual void OnPsiTargetingStop(const unsigned _targetEntity);
	
#if 0
	void PulseSurfaceHazard();
	void StartNeighborCooldown();
	void InitArea();
	void RemoveDecal();
#endif
	
	static inline auto FInit = PreyFunction<bool(ArkSurfaceHazard *const _this, IGameObject *_pGameObject)>(0x13FA6D0);
	static inline auto FPostInit = PreyFunction<void(ArkSurfaceHazard *const _this, IGameObject *_pGameObject)>(0x13FC0C0);
	static inline auto FFullSerialize = PreyFunction<void(ArkSurfaceHazard *const _this, TSerialize _ser)>(0x13F9C60);
	static inline auto FPostSerialize = PreyFunction<void(ArkSurfaceHazard *const _this)>(0x13FC120);
	static inline auto FUpdate = PreyFunction<void(ArkSurfaceHazard *const _this, SEntityUpdateContext &ctx, int updateSlot)>(0x13FCB70);
	static inline auto FHandleEvent = PreyFunction<void(ArkSurfaceHazard *const _this, SGameObjectEvent const &_event)>(0x13FA3C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkSurfaceHazard const *const _this, ICrySizer *_s)>(0x13FA350);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkSurfaceHazard *const _this, ArkSignalSystem::Package const &_package)>(0x13FBFE0);
	static inline auto FActivateHazard = PreyFunction<void(ArkSurfaceHazard *const _this, bool _bFromNeighbor)>(0x13F9290);
	static inline auto FDeactivateHazard = PreyFunction<void(ArkSurfaceHazard *const _this, bool _bNeighbors)>(0x13F9890);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkSurfaceHazard *const _this, bool _bRegister)>(0x13FC170);
	static inline auto FIsWithinProximity = PreyFunction<bool(ArkSurfaceHazard const *const _this, IEntity const *_pEntity, Vec3 _center)>(0x13FAE60);
	static inline auto FLoadProperties = PreyFunction<void(ArkSurfaceHazard *const _this)>(0x13FB060);
	static inline auto FOnGroundEntityChanged = PreyFunction<void(ArkSurfaceHazard *const _this, IEntity const *_pOwner, IEntity const *_pOldEntity, IEntity const *_pNewEntity)>(0x13FBFB0);
	static inline auto FSetState = PreyFunction<bool(ArkSurfaceHazard *const _this, EArkSurfaceHazardState _state, ArkSurfaceHazard::ForceType _forceType)>(0x13FC320);
	static inline auto FOnReset = PreyFunction<void(ArkSurfaceHazard *const _this, bool _bEnteringGameMode)>(0x13FC050);
	static inline auto FHitTargetWithHazard = PreyFunction<void(ArkSurfaceHazard const *const _this, IEntity *_pTarget)>(0x13FA4B0);
	static inline auto FCanActivateHazard = PreyFunction<bool(ArkSurfaceHazard const *const _this, ArkSignalSystem::Package const &_package, bool _bFromNeighbor)>(0x13F96B0);
	static inline auto FCanDeactivateHazard = PreyFunction<bool(ArkSurfaceHazard const *const _this, ArkSignalSystem::Package const &_package)>(0x13F97A0);
	static inline auto FActivateNeighbors = PreyFunction<void(ArkSurfaceHazard const *const _this)>(0x13F9330);
	static inline auto FDeactivateNeighbors = PreyFunction<void(ArkSurfaceHazard const *const _this)>(0x13F9980);
	static inline auto FAddTarget = PreyFunction<void(ArkSurfaceHazard *const _this, unsigned _target)>(0x13F9580);
	static inline auto FRemoveTarget = PreyFunction<void(ArkSurfaceHazard *const _this, unsigned _target)>(0x13FC280);
	static inline auto FSetupDecal = PreyFunction<void(ArkSurfaceHazard *const _this, SDecalProperties &_properties)>(0x13FC920);
	static inline auto FInitialExplosion = PreyFunction<void(ArkSurfaceHazard *const _this)>(0x13FA700);
	static inline auto FGetLocalAreaBounds = PreyFunction<AABB(ArkSurfaceHazard const *const _this)>(0x13F9E60);
	static inline auto FShouldUpdateWithTargets = PreyFunction<bool(ArkSurfaceHazard const *const _this)>(0x13FCB30);
	static inline auto FOnPsiTargetingStart = PreyFunction<void(ArkSurfaceHazard *const _this, const unsigned _targetEntity)>(0x13FBFC0);
	static inline auto FOnPsiTargetingStop = PreyFunction<void(ArkSurfaceHazard *const _this, const unsigned _targetEntity)>(0x13FBFD0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/Ark/arksignalsystemdata.h>
#include <Prey/CryEntitySystem/IEntityRenderState.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkAvoidanceField.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalHazard.h>
#include <Prey/GameDll/ark/iface/IArkGroundColliderListener.h>
#include <Prey/GameDll/ark/iface/IArkPsiPowerTargetingListener.h>

struct AABB;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IRenderNode;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// ArkSurfaceHazard
// Header:  Prey/GameDll/ark/environment/ArkSurfaceHazard.h
class ArkSurfaceHazard
	: public ArkEnvironmentalHazard
	, public IArkPsiPowerTargetingListener
	, public IArkGroundColliderListener
{ // Size=792 (0x318)
public:
	enum class ForceType
	{
		none = 0,
		init = 1,
		serialize = 2,
	};

	EArkSurfaceHazardState m_state;
	ArkSimpleTimer m_hazardStateTimer;
	ArkSimpleTimer m_depletedDelay;
	ArkSimpleTimer m_triggerDelay;
	ArkSimpleTimer m_neighborActivationCooldown;
	ArkAutoResetTimer m_hazardIntervalTimer;
	std::vector<unsigned int> m_neighbors;
	IRenderNode* m_pDecal;
	ArkEntityEffect m_hazardVfx;
	ArkFireAndForgetEffect m_explosionVfx;
	ArkFireAndForgetEffect m_deactivateVfx;
	ArkAvoidanceField m_avoidanceField;
	bool m_bTriggerExplosionVfx;
	bool m_bPlayerTouchedSinceLastPulse;
	bool m_bScriptEnabled;
	float m_hazardRadius;
	float m_hazardLength;
	float m_hazardWidth;
	bool m_bEffectOnCollision;
	bool m_bEffectOnProximity;
	bool m_bDepletesAfterDuration;
	bool m_bRefreshDurationOnActivation;
	bool m_bPlaceHazardVFX;
	uint64_t m_explosionHazard;
	ArkAudioTrigger m_triggerActivate;
	ArkAudioTrigger m_triggerDeactivate;
	const ArkSignalSystem::Data::SignalGroupData* m_pActivatingSignalGroup;
	const ArkSignalSystem::Data::SignalGroupData* m_pDeactivatingSignalGroup;
	bool m_bStartsEnabled;
	SDecalProperties m_decalProperties;
	SDecalProperties m_depletedDecalProperties;

	ArkSurfaceHazard();
	virtual ~ArkSurfaceHazard();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);
	void ActivateHazard(bool _bFromNeighbor) { FActivateHazard(this, _bFromNeighbor); }
	void DeactivateHazard(bool _bNeighbors) { FDeactivateHazard(this, _bNeighbors); }
	void EnableFromScript(bool _bEnable) { FEnableFromScript(this, _bEnable); }
	virtual void RegisterForSignals(bool _bRegister);
	bool IsWithinProximity(const IEntity* _pEntity, Vec3 _center) const { return FIsWithinProximity(this, _pEntity, _center); }
	virtual void LoadProperties();
	virtual void OnGroundEntityChanged(const IEntity* _pOwner, const IEntity* _pOldEntity, const IEntity* _pNewEntity);
	bool SetState(EArkSurfaceHazardState _state, ArkSurfaceHazard::ForceType _forceType) { return FSetState(this, _state, _forceType); }
	virtual void OnReset(bool _bEnteringGameMode);
	void HitTargetWithHazard(IEntity* _pTarget) const { FHitTargetWithHazard(this, _pTarget); }
	bool CanActivateHazard(const ArkSignalSystem::Package& _package, bool _bFromNeighbor) const { return FCanActivateHazard(this, _package, _bFromNeighbor); }
	bool CanDeactivateHazard(const ArkSignalSystem::Package& _package) const { return FCanDeactivateHazard(this, _package); }
	void ActivateNeighbors() const { FActivateNeighbors(this); }
	void DeactivateNeighbors() const { FDeactivateNeighbors(this); }
	virtual void AddTarget(unsigned _target);
	virtual void RemoveTarget(unsigned _target);
	void SetupDecal(SDecalProperties& _properties) { FSetupDecal(this, _properties); }
	void InitialExplosion() { FInitialExplosion(this); }
	virtual AABB GetLocalAreaBounds() const;
	virtual bool ShouldUpdateWithTargets() const;
	virtual void OnPsiTargetingStart(const unsigned _targetEntity);
	virtual void OnPsiTargetingStop(const unsigned _targetEntity);

#if 0
	EArkSurfaceHazardState GetState() const;
	void UpdateAvoidanceField();
	void PulseSurfaceHazard();
	void StartNeighborCooldown();
	void InitArea();
	void RemoveDecal();
#endif

	static inline auto FArkSurfaceHazardOv1 = PreyFunction<void(ArkSurfaceHazard* const _this)>(0x150ACF0);
	static inline auto FInit = PreyFunction<bool(ArkSurfaceHazard* const _this, IGameObject* _pGameObject)>(0x150C8A0);
	static inline auto FPostInit = PreyFunction<void(ArkSurfaceHazard* const _this, IGameObject* _pGameObject)>(0x150E2C0);
	static inline auto FFullSerialize = PreyFunction<void(ArkSurfaceHazard* const _this, TSerialize _ser)>(0x150BD40);
	static inline auto FPostSerialize = PreyFunction<void(ArkSurfaceHazard* const _this)>(0x150E320);
	static inline auto FUpdate = PreyFunction<void(ArkSurfaceHazard* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x150ED70);
	static inline auto FHandleEvent = PreyFunction<void(ArkSurfaceHazard* const _this, const SGameObjectEvent& _event)>(0x150C590);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkSurfaceHazard* const _this, ICrySizer* _s)>(0x150C520);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkSurfaceHazard* const _this, const ArkSignalSystem::Package& _package)>(0x150E1E0);
	static inline auto FActivateHazard = PreyFunction<void(ArkSurfaceHazard* const _this, bool _bFromNeighbor)>(0x150B3D0);
	static inline auto FDeactivateHazard = PreyFunction<void(ArkSurfaceHazard* const _this, bool _bNeighbors)>(0x150B980);
	static inline auto FEnableFromScript = PreyFunction<void(ArkSurfaceHazard* const _this, bool _bEnable)>(0x150BD10);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkSurfaceHazard* const _this, bool _bRegister)>(0x150E370);
	static inline auto FIsWithinProximity = PreyFunction<bool(const ArkSurfaceHazard* const _this, const IEntity* _pEntity, Vec3 _center)>(0x150D040);
	static inline auto FLoadProperties = PreyFunction<void(ArkSurfaceHazard* const _this)>(0x150D240);
	static inline auto FOnGroundEntityChanged = PreyFunction<void(IArkGroundColliderListener* const _this, const IEntity* _pOwner, const IEntity* _pOldEntity, const IEntity* _pNewEntity)>(0x150E1B0);
	static inline auto FSetState = PreyFunction<bool(ArkSurfaceHazard* const _this, EArkSurfaceHazardState _state, ArkSurfaceHazard::ForceType _forceType)>(0x150E520);
	static inline auto FOnReset = PreyFunction<void(ArkSurfaceHazard* const _this, bool _bEnteringGameMode)>(0x150E250);
	static inline auto FHitTargetWithHazard = PreyFunction<void(const ArkSurfaceHazard* const _this, IEntity* _pTarget)>(0x150C680);
	static inline auto FCanActivateHazard = PreyFunction<bool(const ArkSurfaceHazard* const _this, const ArkSignalSystem::Package& _package, bool _bFromNeighbor)>(0x150B7A0);
	static inline auto FCanDeactivateHazard = PreyFunction<bool(const ArkSurfaceHazard* const _this, const ArkSignalSystem::Package& _package)>(0x150B890);
	static inline auto FActivateNeighbors = PreyFunction<void(const ArkSurfaceHazard* const _this)>(0x150B470);
	static inline auto FDeactivateNeighbors = PreyFunction<void(const ArkSurfaceHazard* const _this)>(0x150BA70);
	static inline auto FAddTarget = PreyFunction<void(ArkSurfaceHazard* const _this, unsigned _target)>(0x150B670);
	static inline auto FRemoveTarget = PreyFunction<void(ArkSurfaceHazard* const _this, unsigned _target)>(0x150E480);
	static inline auto FSetupDecal = PreyFunction<void(ArkSurfaceHazard* const _this, SDecalProperties& _properties)>(0x150EB20);
	static inline auto FInitialExplosion = PreyFunction<void(ArkSurfaceHazard* const _this)>(0x150C8E0);
	static inline auto FGetLocalAreaBounds = PreyFunction<AABB*(const ArkSurfaceHazard* const _this, AABB* _return_value_)>(0x150C030);
	static inline auto FShouldUpdateWithTargets = PreyFunction<bool(const ArkSurfaceHazard* const _this)>(0x150ED30);
	static inline auto FOnPsiTargetingStart = PreyFunction<void(IArkPsiPowerTargetingListener* const _this, const unsigned _targetEntity)>(0x150E1C0);
	static inline auto FOnPsiTargetingStop = PreyFunction<void(IArkPsiPowerTargetingListener* const _this, const unsigned _targetEntity)>(0x150E1D0);
};
#endif // !MOONCRASH
