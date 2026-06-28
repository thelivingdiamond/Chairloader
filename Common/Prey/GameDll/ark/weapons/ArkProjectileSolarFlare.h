// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/weapons/ArkProjectile.h>

class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkProjectileSolarFlare
// Header:  Prey/GameDll/ark/weapons/ArkProjectileSolarFlare.h
class CArkProjectileSolarFlare : public CArkProjectile
{ // Size=1168 (0x490)
public:
	ArkSimpleTimer m_delayBeforeFlareExplosionTimer;
	ArkSimpleTimer m_flareDurationTimer;
	ArkSimpleTimer m_flareTravelBlindPulseTimer;
	bool m_bFlareMadeContact;
	bool m_bHasFlareExploded;
	bool m_bDrawDebugSpheres;
	float m_flareRadius;
	float m_flareExplosionMinimumSignalPercent;
	ArkEntityEffect m_flareTravelEffect;
	ArkEntityEffect m_flareExplosionTelegraphEffect;
	ArkEntityEffect m_flareExplosionEffect;
	uint64_t m_flareExplosionPackageId;
	uint64_t m_travelBlindnessPackageId;
	float m_travelBlindnessMinEffectiveDistance;
	float m_travelBlindnessMaxEffectiveDistance;
	float m_travelBlindnessMinEffectiveAngle;
	float m_travelBlindnessMaxEffectiveAngle;
	uint64_t m_hazardArchetypeId;
	unsigned m_hazardEntityId;

	CArkProjectileSolarFlare();
	virtual ~CArkProjectileSolarFlare();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ReInitFromPool();
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext& _ctx, int _slot);
	virtual void LoadCachedProperties();
	virtual void StartDestroy();
	virtual void AttachParticleEffectsForLiveProjectiles();
	void Explode() { FExplode(this); }
	void UpdateTravelBlindness(float _elapsedTime) { FUpdateTravelBlindness(this, _elapsedTime); }

#if 0
	void ResetFlareProperties();
#endif

	static inline auto FCArkProjectileSolarFlareOv1 = PreyFunction<void(CArkProjectileSolarFlare* const _this)>(0x148A670);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkProjectileSolarFlare* const _this, ICrySizer* _s)>(0x148AC80);
	static inline auto FInit = PreyFunction<bool(CArkProjectileSolarFlare* const _this, IGameObject* _pGameObject)>(0x148A5E0);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileSolarFlare* const _this, IGameObject* _pGameObject)>(0x148B6B0);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectileSolarFlare* const _this, const SGameObjectEvent& _event)>(0x148ACA0);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectileSolarFlare* const _this)>(0x148B6C0);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileSolarFlare* const _this, TSerialize _ser)>(0x148AB50);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileSolarFlare* const _this, SEntityUpdateContext& _ctx, int _slot)>(0x148B760);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileSolarFlare* const _this)>(0x148AD00);
	static inline auto FStartDestroy = PreyFunction<void(CArkProjectileSolarFlare* const _this)>(0x148B700);
	static inline auto FAttachParticleEffectsForLiveProjectiles = PreyFunction<void(CArkProjectileSolarFlare* const _this)>(0x148A7C0);
	static inline auto FExplode = PreyFunction<void(CArkProjectileSolarFlare* const _this)>(0x148A7E0);
	static inline auto FUpdateTravelBlindness = PreyFunction<void(CArkProjectileSolarFlare* const _this, float _elapsedTime)>(0x148B9D0);
};
#endif // MOONCRASH
