// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/GameRules.h>

struct ExplosionInfo;
struct HitInfo;
struct IEntity;
struct IEntityClass;
class XmlNodeRef;

// IGameRulesDamageHandlingModule
// Header:  _unknown/IGameRulesDamageHandlingModule.h
class IGameRulesDamageHandlingModule
{ // Size=8 (0x8)
public:
	enum EGameEvents
	{
		eGameEvent_LocalPlayerEnteredMercyTime = 0,
		eGameEvent_TrainRideStarts = 1,
		eGameEvent_TrainRideEnds = 2,
	};

	enum class ePID_flags
	{
		PID_None = 0,
		PID_Headshot = 2,
	};

	virtual ~IGameRulesDamageHandlingModule();
	virtual void Init(XmlNodeRef xml) = 0;
	virtual void PostInit() = 0;
	virtual void Update(float frameTime) = 0;
	virtual bool SvOnHit(const HitInfo& hitInfo) = 0;
	virtual bool SvOnHitScaled(const HitInfo& hitInfo) = 0;
	virtual void SvOnExplosion(const ExplosionInfo& explosionInfo, const std::map<IEntity*, float>& affectedEntities) = 0;
	virtual void SvOnCollision(const IEntity* pEntity, const CGameRules::SCollisionHitInfo& colHitInfo) = 0;
	virtual void ClProcessHit(Vec3 dir, unsigned shooterId, unsigned weaponId, float damage, uint16_t projectileClassId, uint8_t hitTypeId) = 0;
	virtual bool AllowHitIndicatorForType(int hitTypeId) = 0;
	virtual void MakeMovementVisibleToAIForEntityClass(const IEntityClass* pEntityClass) = 0;
	virtual void OnGameEvent(const IGameRulesDamageHandlingModule::EGameEvents& gameEvent) = 0;
};

