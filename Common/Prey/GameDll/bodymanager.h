// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/Containers/VectorMap.h>
#include <Prey/GameDll/SBodyDamageDef.h>
#include <Prey/GameDll/SBodyDestructibilityDef.h>

class CBodyDamageProfile;
class CBodyDestructibilityProfile;
class CBodyDestrutibilityInstance;
class CCryActor;
struct HitInfo;
class ICrySizer;
struct IEntity;
struct SBodyCharacterInfo;
struct SBodyDamageImpulseFilter;
class SmartScriptTable;

// CBodyDamageManager
// Header:  Prey/GameDll/bodymanager.h
class CBodyDamageManager
{ // Size=136 (0x88)
public:
	using TBodyDamageDefinitions = std::vector<SBodyDamageDef>;
	using TBodyDamageProfiles = std::vector<_smart_ptr<CBodyDamageProfile>>;
	using TBodyDestructibilityDefinitions = std::vector<SBodyDestructibilityDef>;
	using TBodyDestructibilityProfiles = std::vector<_smart_ptr<CBodyDestructibilityProfile>>;
	using TBodyDamageProfileIdEntityBindings = VectorMap<unsigned int,unsigned int,std::less<unsigned int>,std::allocator<std::pair<unsigned int,unsigned int> > >;

	std::vector<SBodyDamageDef> m_bodyDamageDefinitions;
	std::vector<_smart_ptr<CBodyDamageProfile>> m_bodyDamageProfiles;
	unsigned m_bodyDamageIdGen;
	std::vector<SBodyDestructibilityDef> m_bodyDestructibilityDefinitions;
	std::vector<_smart_ptr<CBodyDestructibilityProfile>> m_bodyDestructibilityProfiles;
	unsigned m_bodyDestructibilityIdGen;
	VectorMap<unsigned int,unsigned int,std::less<unsigned int>,std::allocator<std::pair<unsigned int,unsigned int> > > m_bodyDamageProfileIdEntityBindings;

	// varargs: static void Warning(const char* szFormat, ...) { FWarning(szFormat, _arg1_); }
	CBodyDamageManager();
	void GetMemoryUsage(ICrySizer* pSizer) const { FGetMemoryUsage(this, pSizer); }
	void ReloadBodyDamage() { FReloadBodyDamageOv2(this); }
	void ReloadBodyDamage(const CCryActor& actor) { FReloadBodyDamageOv1(this, actor); }
	void ReloadBodyDamage(unsigned profileId, IEntity& entity) { FReloadBodyDamageOv0(this, profileId, entity); }
	void ReloadBodyDestruction() { FReloadBodyDestruction(this); }
	unsigned GetBodyDamage(IEntity& characterEntity, const char* damageTable) { return FGetBodyDamageOv2(this, characterEntity, damageTable); }
	unsigned GetBodyDamage(IEntity& characterEntity, SBodyDamageDef& bodyDamageDef) { return FGetBodyDamageOv1(this, characterEntity, bodyDamageDef); }
	unsigned GetBodyDamage(IEntity& characterEntity, const char* bodyDamageFileName, const char* bodyDamagePartsFileName) { return FGetBodyDamageOv0(this, characterEntity, bodyDamageFileName, bodyDamagePartsFileName); }
	bool CacheBodyDamage(SmartScriptTable pProperties, const char* damageTable) { return FCacheBodyDamageOv1(this, pProperties, damageTable); }
#ifndef MOONCRASH
	bool CacheBodyDamage(SBodyDamageDef& bodyDamageDef) { return FCacheBodyDamageOv0(this, bodyDamageDef); }
#endif
	bool PhysicalizePlayer(unsigned profileId, IEntity& characterEntity) const { return FPhysicalizePlayer(this, profileId, characterEntity); }
	float GetDamageMultiplier(unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo) const { return FGetDamageMultiplier(this, profileId, characterEntity, hitInfo); }
	float GetExplosionDamageMultiplier(unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo) const { return FGetExplosionDamageMultiplier(this, profileId, characterEntity, hitInfo); }
	unsigned GetPartFlags(unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo) const { return FGetPartFlags(this, profileId, characterEntity, hitInfo); }
	bool GetHitImpulseFilter(unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo, SBodyDamageImpulseFilter& impulseFilter) const { return FGetHitImpulseFilter(this, profileId, characterEntity, hitInfo, impulseFilter); }
	unsigned FindBodyDamageProfileIdBinding(unsigned entityId) const { return FFindBodyDamageProfileIdBinding(this, entityId); }
	bool CacheBodyDestruction(SmartScriptTable pProperties, const char* damageTable) { return FCacheBodyDestructionOv1(this, pProperties, damageTable); }
#ifndef MOONCRASH
	void CacheBodyDestruction(SBodyDestructibilityDef& bodyDestructionDef) { FCacheBodyDestructionOv0(this, bodyDestructionDef); }
#endif
	void FlushLevelResourcesCache() { FFlushLevelResourcesCache(this); }
	unsigned GetBodyDestructibility(IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const char* damageTable) { return FGetBodyDestructibility(this, characterEntity, instance, damageTable); }
	void ResetInstance(IEntity& characterEntity, CBodyDestrutibilityInstance& instance) { FResetInstance(this, characterEntity, instance); }
	void ProcessDestructiblesHit(IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float previousHealth, const float newHealth) { FProcessDestructiblesHit(this, characterEntity, instance, hitInfo, previousHealth, newHealth); }
	void ProcessDestructiblesOnExplosion(IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float previousHealth, const float newHealth) { FProcessDestructiblesOnExplosion(this, characterEntity, instance, hitInfo, previousHealth, newHealth); }
	static void GetBodyDamageDef(const char* pBodyDamageFile, const char* pBodyPartsFile, SBodyDamageDef& outDef) { FGetBodyDamageDefOv2(pBodyDamageFile, pBodyPartsFile, outDef); }
	static bool GetBodyDamageDef(IEntity& characterEntity, SBodyDamageDef& outDef, const char* damageTable) { return FGetBodyDamageDefOv1(characterEntity, outDef, damageTable); }
	static bool GetBodyDamageDef(SmartScriptTable pProperties, SBodyDamageDef& outDef, const char* damageTable) { return FGetBodyDamageDefOv0(pProperties, outDef, damageTable); }
#ifndef MOONCRASH
	static void GetBodyDestructibilityDef(const char* pBodyDestructibilityFile, SBodyDestructibilityDef& outDef) { FGetBodyDestructibilityDefOv2(pBodyDestructibilityFile, outDef); }
#endif
	static bool GetBodyDestructibilityDef(SmartScriptTable pProperties, SBodyDestructibilityDef& outDef, float& maxHealth, const char* damageTable) { return FGetBodyDestructibilityDefOv0(pProperties, outDef, maxHealth, damageTable); }
	unsigned LoadBodyDamageDefinition(SBodyDamageDef& bodyDamageDef) { return FLoadBodyDamageDefinition(this, bodyDamageDef); }
	unsigned LoadBodyDestructibilityDefinition(SBodyDestructibilityDef& bodyDestructibilityDef) { return FLoadBodyDestructibilityDefinition(this, bodyDestructibilityDef); }
	static bool GetCharacterInfo(IEntity& characterEntity, SBodyCharacterInfo& outCharacterInfo) { return FGetCharacterInfo(characterEntity, outCharacterInfo); }

#if 0
	bool IsValidBodyDamageProfileID(const unsigned _arg0_) const;
	void RegisterBodyDamageProfileIdBinding(unsigned _arg0_, unsigned _arg1_);
	void UnregisterBodyDamageProfileIdBinding(unsigned _arg0_);
	void ProcessDestructionEventByName(const char* _arg0_, const char* _arg1_, IEntity& _arg2_, CBodyDestrutibilityInstance& _arg3_, const HitInfo& _arg4_);
	void DebugBodyDestructionInstance(IEntity& _arg0_, CBodyDestrutibilityInstance& _arg1_);
	static bool GetBodyDestructibilityDef(IEntity& _arg0_, SBodyDestructibilityDef& _arg1_, float& _arg2_, const char* _arg3_);
	bool InitializeBodyDamageProfile(IEntity& _arg0_, const unsigned _arg1_);
#endif

#ifndef MOONCRASH
	// varargs: static inline auto FWarning = PreyFunction<void(const char* szFormat, ...)>(0x1697F10);
	static inline auto FCBodyDamageManagerOv2 = PreyFunction<void(CBodyDamageManager* const _this)>(0x1695FB0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CBodyDamageManager* const _this, ICrySizer* pSizer)>(0x16977A0);
	static inline auto FReloadBodyDamageOv2 = PreyFunction<void(CBodyDamageManager* const _this)>(0x1697E10);
	static inline auto FReloadBodyDamageOv1 = PreyFunction<void(CBodyDamageManager* const _this, const CCryActor& actor)>(0x1697D00);
	static inline auto FReloadBodyDamageOv0 = PreyFunction<void(CBodyDamageManager* const _this, unsigned profileId, IEntity& entity)>(0x1697D20);
	static inline auto FReloadBodyDestruction = PreyFunction<void(CBodyDamageManager* const _this)>(0x1697E70);
	static inline auto FGetBodyDamageOv2 = PreyFunction<unsigned(CBodyDamageManager* const _this, IEntity& characterEntity, const char* damageTable)>(0x1696910);
	static inline auto FGetBodyDamageOv1 = PreyFunction<unsigned(CBodyDamageManager* const _this, IEntity& characterEntity, SBodyDamageDef& bodyDamageDef)>(0x1696750);
	static inline auto FGetBodyDamageOv0 = PreyFunction<unsigned(CBodyDamageManager* const _this, IEntity& characterEntity, const char* bodyDamageFileName, const char* bodyDamagePartsFileName)>(0x1696870);
	static inline auto FCacheBodyDamageOv1 = PreyFunction<bool(CBodyDamageManager* const _this, SmartScriptTable pProperties, const char* damageTable)>(0x1696410);
	static inline auto FCacheBodyDamageOv0 = PreyFunction<bool(CBodyDamageManager* const _this, SBodyDamageDef& bodyDamageDef)>(0x16963C0);
	static inline auto FPhysicalizePlayer = PreyFunction<bool(const CBodyDamageManager* const _this, unsigned profileId, IEntity& characterEntity)>(0x1697C20);
	static inline auto FGetDamageMultiplier = PreyFunction<float(const CBodyDamageManager* const _this, unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo)>(0x16976D0);
	static inline auto FGetExplosionDamageMultiplier = PreyFunction<float(const CBodyDamageManager* const _this, unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo)>(0x1697710);
	static inline auto FGetPartFlags = PreyFunction<unsigned(const CBodyDamageManager* const _this, unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo)>(0x1697930);
	static inline auto FGetHitImpulseFilter = PreyFunction<bool(const CBodyDamageManager* const _this, unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo, SBodyDamageImpulseFilter& impulseFilter)>(0x1697750);
	static inline auto FFindBodyDamageProfileIdBinding = PreyFunction<unsigned(const CBodyDamageManager* const _this, unsigned entityId)>(0x16966A0);
	static inline auto FCacheBodyDestructionOv1 = PreyFunction<bool(CBodyDamageManager* const _this, SmartScriptTable pProperties, const char* damageTable)>(0x16965A0);
	static inline auto FCacheBodyDestructionOv0 = PreyFunction<void(CBodyDamageManager* const _this, SBodyDestructibilityDef& bodyDestructionDef)>(0x1696530);
	static inline auto FFlushLevelResourcesCache = PreyFunction<void(CBodyDamageManager* const _this)>(0x1696710);
	static inline auto FGetBodyDestructibility = PreyFunction<unsigned(CBodyDamageManager* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const char* damageTable)>(0x1696F00);
	static inline auto FResetInstance = PreyFunction<void(CBodyDamageManager* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance)>(0x1697EE0);
	static inline auto FProcessDestructiblesHit = PreyFunction<void(CBodyDamageManager* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float previousHealth, const float newHealth)>(0x1697CA0);
	static inline auto FProcessDestructiblesOnExplosion = PreyFunction<void(CBodyDamageManager* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float previousHealth, const float newHealth)>(0x1697CD0);
	static inline auto FGetBodyDamageDefOv2 = PreyFunction<void(const char* pBodyDamageFile, const char* pBodyPartsFile, SBodyDamageDef& outDef)>(0x1696C20);
	static inline auto FGetBodyDamageDefOv1 = PreyFunction<bool(IEntity& characterEntity, SBodyDamageDef& outDef, const char* damageTable)>(0x16969C0);
	static inline auto FGetBodyDamageDefOv0 = PreyFunction<bool(SmartScriptTable pProperties, SBodyDamageDef& outDef, const char* damageTable)>(0x1696A90);
	static inline auto FGetBodyDestructibilityDefOv2 = PreyFunction<void(const char* pBodyDestructibilityFile, SBodyDestructibilityDef& outDef)>(0x16973D0);
	static inline auto FGetBodyDestructibilityDefOv0 = PreyFunction<bool(SmartScriptTable pProperties, SBodyDestructibilityDef& outDef, float& maxHealth, const char* damageTable)>(0x16970E0);
	static inline auto FLoadBodyDamageDefinition = PreyFunction<unsigned(CBodyDamageManager* const _this, SBodyDamageDef& bodyDamageDef)>(0x1697970);
	static inline auto FLoadBodyDestructibilityDefinition = PreyFunction<unsigned(CBodyDamageManager* const _this, SBodyDestructibilityDef& bodyDestructibilityDef)>(0x1697A30);
	static inline auto FGetCharacterInfo = PreyFunction<bool(IEntity& characterEntity, SBodyCharacterInfo& outCharacterInfo)>(0x1697530);
#else
	// varargs: static inline auto FWarning = PreyFunction<void(const char* szFormat, ...)>(0xAA85D0);
	static inline auto FCBodyDamageManagerOv2 = PreyFunction<void(CBodyDamageManager* const _this)>(0x17B9600);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CBodyDamageManager* const _this, ICrySizer* pSizer)>(0x17BAB60);
	static inline auto FReloadBodyDamageOv2 = PreyFunction<void(CBodyDamageManager* const _this)>(0x17BB1D0);
	static inline auto FReloadBodyDamageOv1 = PreyFunction<void(CBodyDamageManager* const _this, const CCryActor& actor)>(0x17BB0C0);
	static inline auto FReloadBodyDamageOv0 = PreyFunction<void(CBodyDamageManager* const _this, unsigned profileId, IEntity& entity)>(0x17BB0E0);
	static inline auto FReloadBodyDestruction = PreyFunction<void(CBodyDamageManager* const _this)>(0x17BB230);
	static inline auto FGetBodyDamageOv2 = PreyFunction<unsigned(CBodyDamageManager* const _this, IEntity& characterEntity, const char* damageTable)>(0x17B9E30);
	static inline auto FGetBodyDamageOv1 = PreyFunction<unsigned(CBodyDamageManager* const _this, IEntity& characterEntity, SBodyDamageDef& bodyDamageDef)>(0x17B9C70);
	static inline auto FGetBodyDamageOv0 = PreyFunction<unsigned(CBodyDamageManager* const _this, IEntity& characterEntity, const char* bodyDamageFileName, const char* bodyDamagePartsFileName)>(0x17B9D90);
	static inline auto FCacheBodyDamageOv1 = PreyFunction<bool(CBodyDamageManager* const _this, SmartScriptTable pProperties, const char* damageTable)>(0x17B99A0);
	static inline auto FPhysicalizePlayer = PreyFunction<bool(const CBodyDamageManager* const _this, unsigned profileId, IEntity& characterEntity)>(0x17BAFE0);
	static inline auto FGetDamageMultiplier = PreyFunction<float(const CBodyDamageManager* const _this, unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo)>(0x17BAA90);
	static inline auto FGetExplosionDamageMultiplier = PreyFunction<float(const CBodyDamageManager* const _this, unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo)>(0x17BAAD0);
	static inline auto FGetPartFlags = PreyFunction<unsigned(const CBodyDamageManager* const _this, unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo)>(0x17BACF0);
	static inline auto FGetHitImpulseFilter = PreyFunction<bool(const CBodyDamageManager* const _this, unsigned profileId, IEntity& characterEntity, const HitInfo& hitInfo, SBodyDamageImpulseFilter& impulseFilter)>(0x17BAB10);
	static inline auto FFindBodyDamageProfileIdBinding = PreyFunction<unsigned(const CBodyDamageManager* const _this, unsigned entityId)>(0x17B9BC0);
	static inline auto FCacheBodyDestructionOv1 = PreyFunction<bool(CBodyDamageManager* const _this, SmartScriptTable pProperties, const char* damageTable)>(0x17B9AC0);
	static inline auto FFlushLevelResourcesCache = PreyFunction<void(CBodyDamageManager* const _this)>(0x17B9C30);
	static inline auto FGetBodyDestructibility = PreyFunction<unsigned(CBodyDamageManager* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const char* damageTable)>(0x17BA420);
	static inline auto FResetInstance = PreyFunction<void(CBodyDamageManager* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance)>(0x17BB2A0);
	static inline auto FProcessDestructiblesHit = PreyFunction<void(CBodyDamageManager* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float previousHealth, const float newHealth)>(0x17BB060);
	static inline auto FProcessDestructiblesOnExplosion = PreyFunction<void(CBodyDamageManager* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float previousHealth, const float newHealth)>(0x17BB090);
	static inline auto FGetBodyDamageDefOv2 = PreyFunction<void(const char* pBodyDamageFile, const char* pBodyPartsFile, SBodyDamageDef& outDef)>(0x17BA140);
	static inline auto FGetBodyDamageDefOv1 = PreyFunction<bool(IEntity& characterEntity, SBodyDamageDef& outDef, const char* damageTable)>(0x17B9EE0);
	static inline auto FGetBodyDamageDefOv0 = PreyFunction<bool(SmartScriptTable pProperties, SBodyDamageDef& outDef, const char* damageTable)>(0x17B9FB0);
	static inline auto FGetBodyDestructibilityDefOv0 = PreyFunction<bool(SmartScriptTable pProperties, SBodyDestructibilityDef& outDef, float& maxHealth, const char* damageTable)>(0x17BA600);
	static inline auto FLoadBodyDamageDefinition = PreyFunction<unsigned(CBodyDamageManager* const _this, SBodyDamageDef& bodyDamageDef)>(0x17BAD30);
	static inline auto FLoadBodyDestructibilityDefinition = PreyFunction<unsigned(CBodyDamageManager* const _this, SBodyDestructibilityDef& bodyDestructibilityDef)>(0x17BADF0);
	static inline auto FGetCharacterInfo = PreyFunction<bool(IEntity& characterEntity, SBodyCharacterInfo& outCharacterInfo)>(0x17BA8F0);
#endif
};

