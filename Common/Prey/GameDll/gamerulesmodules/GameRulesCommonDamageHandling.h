// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>
#include <Prey/GameDll/GameRules.h>
#include <_unknown/IGameRulesDamageHandlingModule.h>

class CGameRules;
struct ExplosionInfo;
struct HitInfo;
struct IActor;
struct IEntity;
struct IEntityClass;
class XmlNodeRef;

// CGameRulesCommonDamageHandling
// Header:  Prey/GameDll/gamerulesmodules/GameRulesCommonDamageHandling.h
class CGameRulesCommonDamageHandling : public IGameRulesDamageHandlingModule
{ // Size=32 (0x20)
public:
	// CGameRulesCommonDamageHandling::SCollisionEntityInfo
	// Header:  Prey/GameDll/gamerulesmodules/GameRulesCommonDamageHandling.h
	struct SCollisionEntityInfo
	{ // Size=24 (0x18)
		unsigned entityId;
		const IEntity* pEntity;
		const IActor* pEntityActor;

	#if 0
		SCollisionEntityInfo(const IEntity* _arg0_);
	#endif
	};

	SmartScriptTable m_scriptHitInfo;
	CGameRules* m_pGameRules;
	IEntityClass* m_pEnvironmentalWeaponClass;

	CGameRulesCommonDamageHandling();
	virtual ~CGameRulesCommonDamageHandling();
	virtual void Init(XmlNodeRef xml);
	virtual void PostInit();
	virtual void Update(float frameTime);
	virtual bool SvOnHit(const HitInfo& hitInfo);
	virtual bool SvOnHitScaled(const HitInfo& hitInfo);
	virtual void SvOnExplosion(const ExplosionInfo& explosionInfo, const std::map<IEntity*, float>& affectedEntities);
	virtual void SvOnCollision(const IEntity* pEntity, const CGameRules::SCollisionHitInfo& colHitInfo);
	virtual void ClProcessHit(Vec3 dir, unsigned shooterId, unsigned weaponId, float damage, uint16_t projectileClassId, uint8_t hitTypeId);
	virtual bool AllowHitIndicatorForType(int hitTypeId);
	virtual void MakeMovementVisibleToAIForEntityClass(const IEntityClass* pEntityClass);
	virtual void OnGameEvent(const IGameRulesDamageHandlingModule::EGameEvents& gameEvent);
	float GetCollisionEnergy(const IEntity* pVictim, const CGameRules::SCollisionHitInfo& colHitInfo) const { return FGetCollisionEnergy(this, pVictim, colHitInfo); }
	float GetCollisionDamageMult(const IEntity* pEntity, const IEntity* pCollider, const CGameRules::SCollisionHitInfo& colHitInfo) const { return FGetCollisionDamageMult(this, pEntity, pCollider, colHitInfo); }
	float GetAIPlayerSelfCollisionMultiplier(const CGameRulesCommonDamageHandling::SCollisionEntityInfo& colliderInfo) const { return FGetAIPlayerSelfCollisionMultiplier(this, colliderInfo); }
	void LogHit(const HitInfo& hit, bool extended, bool dead) { FLogHit(this, hit, extended, dead); }

#if 0
	float GetPlayerAgainstColliderEnergyScale(const IEntity& _arg0_) const;
	float GetPlayerSelfCollisionMultiplier(const CGameRulesCommonDamageHandling::SCollisionEntityInfo& _arg0_) const;
	bool DebugCollisions() const;
#endif

	static inline auto FCGameRulesCommonDamageHandlingOv1 = PreyFunction<void(CGameRulesCommonDamageHandling* const _this)>(0x18561B0);
	static inline auto FBitNotCGameRulesCommonDamageHandling = PreyFunction<void(CGameRulesCommonDamageHandling* const _this)>(0x1856210);
	static inline auto FInit = PreyFunction<void(CGameRulesCommonDamageHandling* const _this, XmlNodeRef xml)>(0x1856920);
	static inline auto FPostInit = PreyFunction<void(CGameRulesCommonDamageHandling* const _this)>(0x1856F60);
	static inline auto FUpdate = PreyFunction<void(CGameRulesCommonDamageHandling* const _this, float frameTime)>(0x1333E90);
	static inline auto FSvOnHit = PreyFunction<bool(CGameRulesCommonDamageHandling* const _this, const HitInfo& hitInfo)>(0x1A302A0);
	static inline auto FSvOnHitScaled = PreyFunction<bool(CGameRulesCommonDamageHandling* const _this, const HitInfo& hitInfo)>(0x1A302A0);
	static inline auto FSvOnExplosion = PreyFunction<void(CGameRulesCommonDamageHandling* const _this, const ExplosionInfo& explosionInfo, const std::map<IEntity*, float>& affectedEntities)>(0x1333E90);
	static inline auto FSvOnCollision = PreyFunction<void(CGameRulesCommonDamageHandling* const _this, const IEntity* pEntity, const CGameRules::SCollisionHitInfo& colHitInfo)>(0x1333E90);
	static inline auto FClProcessHit = PreyFunction<void(CGameRulesCommonDamageHandling* const _this, Vec3 dir, unsigned shooterId, unsigned weaponId, float damage, uint16_t projectileClassId, uint8_t hitTypeId)>(0x1333E90);
	static inline auto FAllowHitIndicatorForType = PreyFunction<bool(CGameRulesCommonDamageHandling* const _this, int hitTypeId)>(0x18562E0);
	static inline auto FMakeMovementVisibleToAIForEntityClass = PreyFunction<void(CGameRulesCommonDamageHandling* const _this, const IEntityClass* pEntityClass)>(0x1333E90);
	static inline auto FOnGameEvent = PreyFunction<void(CGameRulesCommonDamageHandling* const _this, const IGameRulesDamageHandlingModule::EGameEvents& gameEvent)>(0x1333E90);
	static inline auto FGetCollisionEnergy = PreyFunction<float(const CGameRulesCommonDamageHandling* const _this, const IEntity* pVictim, const CGameRules::SCollisionHitInfo& colHitInfo)>(0x1856620);
	static inline auto FGetCollisionDamageMult = PreyFunction<float(const CGameRulesCommonDamageHandling* const _this, const IEntity* pEntity, const IEntity* pCollider, const CGameRules::SCollisionHitInfo& colHitInfo)>(0x18564C0);
	static inline auto FGetAIPlayerSelfCollisionMultiplier = PreyFunction<float(const CGameRulesCommonDamageHandling* const _this, const CGameRulesCommonDamageHandling::SCollisionEntityInfo& colliderInfo)>(0x18562F0);
	static inline auto FLogHit = PreyFunction<void(CGameRulesCommonDamageHandling* const _this, const HitInfo& hit, bool extended, bool dead)>(0x1856CF0);
};
#endif // MOONCRASH
