// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/weapons/arkprojectile.h>

struct EventPhysCollision;
class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkprojectilehomingpsiblast.h
class CArkProjectileHomingPsiBlast : public CArkProjectile // Id=80199C6 Size=872
{
public:
	uint64_t m_cameraShakeId;
	float m_maxSpeed;
	float m_turnSpeed;
	float m_detonationRadius;
	float m_acceleration;
	float m_maxBlastRadius;
	float m_targetHeightPercentage;
	bool m_bUsePredictiveHoming;
	unsigned m_targetID;
	Vec3 m_destination;
	ArkEntityEffect m_homingProjectileEffect;
	bool m_bGaveUp;
	ArkSimpleTimer m_giveUpTimer;
	
	CArkProjectileHomingPsiBlast();
	virtual ~CArkProjectileHomingPsiBlast();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ReInitFromPool();
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void DoDamage(EventPhysCollision const &_collision, const unsigned &_targetId, const int _targetIndex);
	virtual void StartDestroy();
	virtual void LoadCachedProperties();
	virtual void AttachParticleEffectsForLiveProjectiles();
	void DoPsiBlast(Vec3 const &_explosionVel, Vec3 const &_explosionNormal, const int16_t _materialId, const int _partId) { FDoPsiBlast(this,_explosionVel,_explosionNormal,_materialId,_partId); }
	
#if 0
	void SetDestination(unsigned arg0);
	void SetDestination(Vec3 const &arg0);
#endif
	
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkProjectileHomingPsiBlast const *const _this, ICrySizer *_s)>(0x16552B0);
	static inline auto FInit = PreyFunction<bool(CArkProjectileHomingPsiBlast *const _this, IGameObject *_pGameObject)>(0x1655490);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileHomingPsiBlast *const _this, IGameObject *_pGameObject)>(0x1655D00);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectileHomingPsiBlast *const _this, SGameObjectEvent const &_event)>(0x16552D0);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectileHomingPsiBlast *const _this)>(0x1655D30);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileHomingPsiBlast *const _this, TSerialize _ser)>(0x16551E0);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileHomingPsiBlast *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x1655DC0);
	static inline auto FDoDamage = PreyFunction<void(CArkProjectileHomingPsiBlast *const _this, EventPhysCollision const &_collision, const unsigned &_targetId, const int _targetIndex)>(0x1654DA0);
	static inline auto FStartDestroy = PreyFunction<void(CArkProjectileHomingPsiBlast *const _this)>(0x1655D40);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileHomingPsiBlast *const _this)>(0x16554A0);
	static inline auto FAttachParticleEffectsForLiveProjectiles = PreyFunction<void(CArkProjectileHomingPsiBlast *const _this)>(0x1654D80);
	static inline auto FDoPsiBlast = PreyFunction<void(CArkProjectileHomingPsiBlast *const _this, Vec3 const &_explosionVel, Vec3 const &_explosionNormal, const int16_t _materialId, const int _partId)>(0x1654DE0);
};

