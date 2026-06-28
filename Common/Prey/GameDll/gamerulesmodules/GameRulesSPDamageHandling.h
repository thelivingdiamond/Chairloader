// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/GameRules.h>
#include <Prey/GameDll/gamerulesmodules/GameRulesCommonDamageHandling.h>
#include <_unknown/CInvulnerableFilter.h>
#include <_unknown/CryFixedArray.h>
#include <_unknown/IGameRulesDamageHandlingModule.h>

class CCryActor;
struct ExplosionInfo;
struct HitInfo;
struct IActor;
struct IEntity;
struct IEntityClass;
struct IScriptTable;
class SmartScriptTable;
class XmlNodeRef;

// CMercyTimeFilter
// Header:  Prey/GameDll/gamerulesmodules/GameRulesSPDamageHandling.h
class CMercyTimeFilter
{ // Size=64 (0x40)
public:
	enum class #unnamed_enum_MaxDifficultyLevels
	{
		MaxDifficultyLevels = 5,
	};

	// CMercyTimeFilter::ClassFilter
	// Header:  Prey/GameDll/gamerulesmodules/GameRulesSPDamageHandling.h
	struct ClassFilter
	{ // Size=4 (0x4)
		enum #unnamed_enum_eType_None
		{
			eType_None = 0,
			eType_Self = 1,
		};

		uint16_t classId;
		uint16_t type;

	#if 0
		bool operator==(const uint16_t& _arg0_) const;
		bool operator<(const uint16_t& _arg0_) const;
	#endif
	};

	// CMercyTimeFilter::CompareClassFilter
	// Header:  Prey/GameDll/gamerulesmodules/GameRulesSPDamageHandling.h
	struct CompareClassFilter
	{ // Size=1 (0x1)
	#if 0
		bool operator()(const CMercyTimeFilter::ClassFilter& _arg0_, const CMercyTimeFilter::ClassFilter& _arg1_) const;
	#endif
	};

	using FilteredProjectiles = std::vector<CMercyTimeFilter::ClassFilter>;

	std::vector<CMercyTimeFilter::ClassFilter> m_filteredProjectiles;
	CryFixedArray<unsigned int,5> m_difficultyTolerance;
	unsigned m_lastMercyTimeFilterCount;

	void Init(const XmlNodeRef& xml) { FInit(this, xml); }

#if 0
	CMercyTimeFilter();
	bool Filtered(const uint16_t _arg0_, const unsigned _arg1_, const unsigned _arg2_) const;
	void OnLocalPlayerEnteredMercyTime();
#endif

	static inline auto FInit = PreyFunction<void(CMercyTimeFilter* const _this, const XmlNodeRef& xml)>(0x185D290);
};

// CGameRulesSPDamageHandling
// Header:  Prey/GameDll/gamerulesmodules/GameRulesSPDamageHandling.h
class CGameRulesSPDamageHandling : public CGameRulesCommonDamageHandling
{ // Size=200 (0xC8)
public:
	// CGameRulesSPDamageHandling::SReactionInfoOnHit
	// Header:  Prey/GameDll/gamerulesmodules/GameRulesSPDamageHandling.h
	struct SReactionInfoOnHit
	{ // Size=16 (0x10)
		bool bMakeVictimFall;
		bool bMakeOffenderFall;
		bool bTriggerHitReaction;
		IActor* pOffenderActor;

	#if 0
		SReactionInfoOnHit();
	#endif
	};

	// CGameRulesSPDamageHandling::EntityCollisionRecord
	// Header:  Prey/GameDll/gamerulesmodules/GameRulesSPDamageHandling.h
	struct EntityCollisionRecord
	{ // Size=8 (0x8)
		unsigned entityID;
		float time;

	#if 0
		EntityCollisionRecord();
		EntityCollisionRecord(unsigned _arg0_, float _arg1_);
	#endif
	};

	using TEntityClassesTrackedForAI = std::vector<const IEntityClass*>;
	using EntityCollisionRecords = std::unordered_map<unsigned int,CGameRulesSPDamageHandling::EntityCollisionRecord,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,CGameRulesSPDamageHandling::EntityCollisionRecord> > >;

	std::vector<const IEntityClass*> m_entityClassesWithTrackedMovement;
	std::unordered_map<unsigned int,CGameRulesSPDamageHandling::EntityCollisionRecord,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,CGameRulesSPDamageHandling::EntityCollisionRecord> > > m_entityCollisionRecords;
	CMercyTimeFilter m_mercyTimeFilter;
	CInvulnerableFilter m_invulnerableFilter;
	float m_entityLastDamageUpdateTimer;

	CGameRulesSPDamageHandling();
	virtual ~CGameRulesSPDamageHandling();
	virtual void Init(XmlNodeRef xml);
	virtual void Update(float frameTime);
	virtual bool SvOnHit(const HitInfo& hit);
	virtual bool SvOnHitScaled(const HitInfo& hitInfo);
	virtual void SvOnExplosion(const ExplosionInfo& explosionInfo, const std::map<IEntity*, float>& affectedEntities);
	virtual void SvOnCollision(const IEntity* pVictimEntity, const CGameRules::SCollisionHitInfo& collisionHitInfo);
	virtual void MakeMovementVisibleToAIForEntityClass(const IEntityClass* pEntityClass);
	virtual void OnGameEvent(const IGameRulesDamageHandlingModule::EGameEvents& gameEvent);
	bool IsDead(IActor* actor, IScriptTable* actorScript) { return FIsDead(this, actor, actorScript); }
	void ProcessDeath(IActor* victimActor, const SmartScriptTable& victimScript, const HitInfo& hitInfo) { FProcessDeath(this, victimActor, victimScript, hitInfo); }
	float CalcExplosionDamage(IEntity* entity, const ExplosionInfo& explosionInfo, float obstruction) { return FCalcExplosionDamage(this, entity, explosionInfo, obstruction); }
	void DelegateServerHit(IScriptTable* victimScript, const HitInfo& hit, IActor* pVictimActor, const CGameRulesSPDamageHandling::SReactionInfoOnHit* pReactionInfo) { FDelegateServerHit(this, victimScript, hit, pVictimActor, pReactionInfo); }

#if 0
	float AdjustPlayerCollisionDamage(const IEntity* _arg0_, const CGameRules::SCollisionHitInfo& _arg1_, float _arg2_);
	bool ShouldApplyMercyTime(CCryActor& _arg0_, const HitInfo& _arg1_) const;
#endif

	static inline auto FCGameRulesSPDamageHandlingOv1 = PreyFunction<void(CGameRulesSPDamageHandling* const _this)>(0x185C890);
	static inline auto FInit = PreyFunction<void(CGameRulesSPDamageHandling* const _this, XmlNodeRef xml)>(0x185D140);
	static inline auto FUpdate = PreyFunction<void(CGameRulesSPDamageHandling* const _this, float frameTime)>(0x185F5A0);
	static inline auto FSvOnHit = PreyFunction<bool(CGameRulesSPDamageHandling* const _this, const HitInfo& hit)>(0x185EA50);
	static inline auto FSvOnHitScaled = PreyFunction<bool(CGameRulesSPDamageHandling* const _this, const HitInfo& hitInfo)>(0x185EC10);
	static inline auto FSvOnExplosion = PreyFunction<void(CGameRulesSPDamageHandling* const _this, const ExplosionInfo& explosionInfo, const std::map<IEntity*, float>& affectedEntities)>(0x185E3C0);
	static inline auto FSvOnCollision = PreyFunction<void(CGameRulesSPDamageHandling* const _this, const IEntity* pVictimEntity, const CGameRules::SCollisionHitInfo& collisionHitInfo)>(0x185D8D0);
	static inline auto FMakeMovementVisibleToAIForEntityClass = PreyFunction<void(CGameRulesSPDamageHandling* const _this, const IEntityClass* pEntityClass)>(0x185D720);
	static inline auto FOnGameEvent = PreyFunction<void(CGameRulesSPDamageHandling* const _this, const IGameRulesDamageHandlingModule::EGameEvents& gameEvent)>(0x185D770);
	static inline auto FIsDead = PreyFunction<bool(CGameRulesSPDamageHandling* const _this, IActor* actor, IScriptTable* actorScript)>(0x185D530);
	static inline auto FProcessDeath = PreyFunction<void(CGameRulesSPDamageHandling* const _this, IActor* victimActor, const SmartScriptTable& victimScript, const HitInfo& hitInfo)>(0x185D7A0);
	static inline auto FCalcExplosionDamage = PreyFunction<float(CGameRulesSPDamageHandling* const _this, IEntity* entity, const ExplosionInfo& explosionInfo, float obstruction)>(0x185CA90);
	static inline auto FDelegateServerHit = PreyFunction<void(CGameRulesSPDamageHandling* const _this, IScriptTable* victimScript, const HitInfo& hit, IActor* pVictimActor, const CGameRulesSPDamageHandling::SReactionInfoOnHit* pReactionInfo)>(0x185CC90);
};
#endif // MOONCRASH
