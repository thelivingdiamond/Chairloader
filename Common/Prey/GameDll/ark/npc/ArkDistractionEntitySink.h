// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>

struct IEntity;
struct IEntityArchetype;
struct IEntityClass;
struct SEntityEvent;
struct SEntitySpawnParams;
class XmlNodeRef;

// ArkDistractionEntitySink
// Header:  Prey/GameDll/ark/npc/ArkDistractionEntitySink.h
class ArkDistractionEntitySink : public IEntitySystemSink
{ // Size=208 (0xD0)
public:
	enum class EDistractionLifetime
	{
		dead = 0,
		alive = 1,
		deadOrAlive = 2,
	};

	// ArkDistractionEntitySink::DistractionInfo
	// Header:  Prey/GameDll/ark/npc/ArkDistractionEntitySink.h
	struct DistractionInfo
	{ // Size=16 (0x10)
		uint64_t m_distractionId;
		ArkDistractionEntitySink::EDistractionLifetime m_lifetime;

	#if 0
		DistractionInfo(const uint64_t _arg0_, const ArkDistractionEntitySink::EDistractionLifetime _arg1_);
	#endif
	};

	// ArkDistractionEntitySink::EntityClassDistractionInfo
	// Header:  Prey/GameDll/ark/npc/ArkDistractionEntitySink.h
	struct EntityClassDistractionInfo
	{ // Size=24 (0x18)
		uint64_t m_distractionId;
		ArkDistractionEntitySink::EDistractionLifetime m_lifetime;
		float m_minimumMass;
		float m_maximumMass;

	#if 0
		EntityClassDistractionInfo(const uint64_t _arg0_, const ArkDistractionEntitySink::EDistractionLifetime _arg1_, const float _arg2_, const float _arg3_);
	#endif
	};

	using DistractionInfoVector = std::vector<ArkDistractionEntitySink::DistractionInfo>;
	using EntityClassDistractionInfoVector = std::vector<ArkDistractionEntitySink::EntityClassDistractionInfo>;
	using EntityClassToDistractionInfoMap = std::unordered_map<const IEntityClass*, std::vector<ArkDistractionEntitySink::EntityClassDistractionInfo>>;
	using CrcToDistractionInfoMap = std::unordered_map<unsigned int, std::vector<ArkDistractionEntitySink::DistractionInfo>>;
	using MetaTagIdToDistractionInfoMap = std::unordered_map<uint64_t, std::vector<ArkDistractionEntitySink::DistractionInfo>>;

	std::unordered_map<const IEntityClass*, std::vector<ArkDistractionEntitySink::EntityClassDistractionInfo>> m_entityClassToDistractionsMap;
	std::unordered_map<unsigned int, std::vector<ArkDistractionEntitySink::DistractionInfo>> m_archetypeCrcToDistractionsMap;
	std::unordered_map<uint64_t, std::vector<ArkDistractionEntitySink::DistractionInfo>> m_metaTagCrcToDistractionsMap;
	uint64_t m_mimicryDistractionId;

	ArkDistractionEntitySink();
	virtual ~ArkDistractionEntitySink();
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	virtual bool OnBeforeSpawn(SEntitySpawnParams& params);
	virtual void OnSpawn(IEntity* _pEntity, SEntitySpawnParams& _params);
	virtual bool OnRemove(IEntity* _pEntity);
	virtual void OnReused(IEntity* _pEntity, SEntitySpawnParams& params);
	virtual void OnEvent(IEntity* _pEntity, SEntityEvent& _event);
	void OnEntityDied(IEntity* _pEntity) { FOnEntityDied(this, _pEntity); }
	void OnEntityStartMimicking(const IEntity* _pEntity, const IEntity* _pEntityBeingMimicked) { FOnEntityStartMimicking(this, _pEntity, _pEntityBeingMimicked); }
	void OnEntityStopMimicking(const IEntity* _pEntity) { FOnEntityStopMimicking(this, _pEntity); }
	void LoadAutoDistractionXml() { FLoadAutoDistractionXml(this); }
	void LoadEntityClassesXmlNode(const XmlNodeRef& _entityClassXmlNode) { FLoadEntityClassesXmlNode(this, _entityClassXmlNode); }
	void LoadArchetypesXmlNode(const XmlNodeRef& _archetypeClassXmlNode) { FLoadArchetypesXmlNode(this, _archetypeClassXmlNode); }
	void LoadMetaTagXmlNode(const XmlNodeRef& _metaTagXmlNode) { FLoadMetaTagXmlNode(this, _metaTagXmlNode); }
	void RegisterEntityForDistractions(const IEntity& _entity, ArkDistractionEntitySink::EDistractionLifetime _entityLifetimeState) const { FRegisterEntityForDistractions(this, _entity, _entityLifetimeState); }
	void AddEntityClassDistractions(const IEntity& _entity, const IEntityClass& _entityClass, ArkDistractionEntitySink::EDistractionLifetime _entityLifetimeState) const { FAddEntityClassDistractions(this, _entity, _entityClass, _entityLifetimeState); }
	void AddArchetypeDistractions(const IEntity& _entity, const IEntityArchetype& _entityArchetype, ArkDistractionEntitySink::EDistractionLifetime _entityLifetimeState) const { FAddArchetypeDistractions(this, _entity, _entityArchetype, _entityLifetimeState); }
	void AddMetaTagDistraction(const IEntity& _entity, const IEntity& _addUsingThisEntityTags, ArkDistractionEntitySink::EDistractionLifetime _entityLifetimeState) const { FAddMetaTagDistraction(this, _entity, _addUsingThisEntityTags, _entityLifetimeState); }
	void AddOrRemoveDistraction(const IEntity& _entity, const uint64_t& _distractionId, ArkDistractionEntitySink::EDistractionLifetime _entityLifetimeState, ArkDistractionEntitySink::EDistractionLifetime _distractionLifetime) const { FAddOrRemoveDistraction(this, _entity, _distractionId, _entityLifetimeState, _distractionLifetime); }

#if 0
	void RegisterSpawnedEntities() const;
	void AddMimicryDistraction(const IEntity& _arg0_, bool _arg1_) const;
	void AddDistraction(const IEntity& _arg0_, const uint64_t& _arg1_) const;
	void RemoveDistraction(const IEntity& _arg0_, const uint64_t& _arg1_) const;
#endif

	static inline auto FArkDistractionEntitySinkOv1 = PreyFunction<void(ArkDistractionEntitySink* const _this)>(0x16047E0);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkDistractionEntitySink* const _this)>(0x1605F30);
	static inline auto FReset = PreyFunction<void(ArkDistractionEntitySink* const _this, bool _bEnteringGameMode)>(0x1606070);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(ArkDistractionEntitySink* const _this, SEntitySpawnParams& params)>(0x1A302A0);
	static inline auto FOnSpawn = PreyFunction<void(ArkDistractionEntitySink* const _this, IEntity* _pEntity, SEntitySpawnParams& _params)>(0x1605F70);
	static inline auto FOnRemove = PreyFunction<bool(ArkDistractionEntitySink* const _this, IEntity* _pEntity)>(0x1605F40);
	static inline auto FOnReused = PreyFunction<void(ArkDistractionEntitySink* const _this, IEntity* _pEntity, SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FOnEvent = PreyFunction<void(ArkDistractionEntitySink* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x1605E90);
	static inline auto FOnEntityDied = PreyFunction<void(ArkDistractionEntitySink* const _this, IEntity* _pEntity)>(0x1605D10);
	static inline auto FOnEntityStartMimicking = PreyFunction<void(ArkDistractionEntitySink* const _this, const IEntity* _pEntity, const IEntity* _pEntityBeingMimicked)>(0x1605D20);
	static inline auto FOnEntityStopMimicking = PreyFunction<void(ArkDistractionEntitySink* const _this, const IEntity* _pEntity)>(0x1605E30);
	static inline auto FLoadAutoDistractionXml = PreyFunction<void(ArkDistractionEntitySink* const _this)>(0x1605460);
	static inline auto FLoadEntityClassesXmlNode = PreyFunction<void(ArkDistractionEntitySink* const _this, const XmlNodeRef& _entityClassXmlNode)>(0x16056A0);
	static inline auto FLoadArchetypesXmlNode = PreyFunction<void(ArkDistractionEntitySink* const _this, const XmlNodeRef& _archetypeClassXmlNode)>(0x1605130);
	static inline auto FLoadMetaTagXmlNode = PreyFunction<void(ArkDistractionEntitySink* const _this, const XmlNodeRef& _metaTagXmlNode)>(0x1605A20);
	static inline auto FRegisterEntityForDistractions = PreyFunction<void(const ArkDistractionEntitySink* const _this, const IEntity& _entity, ArkDistractionEntitySink::EDistractionLifetime _entityLifetimeState)>(0x1605F80);
	static inline auto FAddEntityClassDistractions = PreyFunction<void(const ArkDistractionEntitySink* const _this, const IEntity& _entity, const IEntityClass& _entityClass, ArkDistractionEntitySink::EDistractionLifetime _entityLifetimeState)>(0x1604C10);
	static inline auto FAddArchetypeDistractions = PreyFunction<void(const ArkDistractionEntitySink* const _this, const IEntity& _entity, const IEntityArchetype& _entityArchetype, ArkDistractionEntitySink::EDistractionLifetime _entityLifetimeState)>(0x1604AA0);
	static inline auto FAddMetaTagDistraction = PreyFunction<void(const ArkDistractionEntitySink* const _this, const IEntity& _entity, const IEntity& _addUsingThisEntityTags, ArkDistractionEntitySink::EDistractionLifetime _entityLifetimeState)>(0x1604E60);
	static inline auto FAddOrRemoveDistraction = PreyFunction<void(const ArkDistractionEntitySink* const _this, const IEntity& _entity, const uint64_t& _distractionId, ArkDistractionEntitySink::EDistractionLifetime _entityLifetimeState, ArkDistractionEntitySink::EDistractionLifetime _distractionLifetime)>(0x1605080);
};
#endif // MOONCRASH
