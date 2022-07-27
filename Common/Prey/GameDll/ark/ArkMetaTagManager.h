// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IArkMetaTagManager.h>
#include <Prey/GameDll/ark/iface/IEntityArchetypeListener.h>

class ArkSafeScriptTable;
struct IEntity;
struct IEntityArchetype;
struct SEntityEvent;

// Header: FromCpp
// Prey/GameDll/ark/ArkMetaTagManager.h
class ArkMetaTagManager : public IArkMetaTagManager, public IEntityArchetypeListener, public IEntityEventListener // Id=8015CF0 Size=176
{
public:
	struct ArchetypeTagInfo // Id=8015CF1 Size=8
	{
		int m_numTags;
		int m_tagOffset;
	};

	std::unordered_map<unsigned int,std::vector<unsigned __int64>> m_entityMetaTags;
	std::unordered_map<IEntityArchetype const *,ArkMetaTagManager::ArchetypeTagInfo> m_archetypeToTagInfo;
	std::vector<unsigned __int64> m_tags;
	
	ArkMetaTagManager();
	virtual ~ArkMetaTagManager();
	virtual bool DoesEntityHaveTag(IEntity const &_entity, const uint64_t &_tag) const;
	std::vector<unsigned __int64> GetArchetypeTags(IEntityArchetype const &_entityArchetype) const { return FGetArchetypeTags(this,_entityArchetype); }
	std::vector<unsigned __int64> GetEntityTags(IEntity const &_entity) const { return FGetEntityTags(this,_entity); }
	void AddMetaTagToEntity(unsigned _entityId, const uint64_t &_tag) { FAddMetaTagToEntity(this,_entityId,_tag); }
	void RemoveMetaTagFromEntity(unsigned _entityId, const uint64_t &_tag) { FRemoveMetaTagFromEntity(this,_entityId,_tag); }
	void RemoveAllAssignedMetaTagsFromEntity(unsigned _entityId, bool _bSilent) { FRemoveAllAssignedMetaTagsFromEntity(this,_entityId,_bSilent); }
	bool DoesEntityHaveAnyTags(IEntity const &_entity, std::vector<unsigned __int64> const &_inputTags) const { return FDoesEntityHaveAnyTagsOv1(this,_entity,_inputTags); }
	bool DoesEntityHaveAnyTags(IEntityArchetype const &_entityArchetype, std::vector<unsigned __int64> const &_tags) const { return FDoesEntityHaveAnyTagsOv0(this,_entityArchetype,_tags); }
	bool DoesEntityHaveAllTags(IEntity const &_entity, std::vector<unsigned __int64> const &_inputTags) const { return FDoesEntityHaveAllTags(this,_entity,_inputTags); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	bool IsValidTag(const uint64_t &_tag) const { return FIsValidTag(this,_tag); }
	std::vector<unsigned __int64> GetBaseEntityTags(IEntity const &_entity) const { return FGetBaseEntityTags(this,_entity); }
	void ClearTags(bool _bSilent) { FClearTags(this,_bSilent); }
	void LoadTags() { FLoadTags(this); }
	void LoadTagsForArchetype(IEntityArchetype *_pArchetype) { FLoadTagsForArchetype(this,_pArchetype); }
	std::vector<unsigned __int64> LoadTagsFromScriptTable(ArkSafeScriptTable const &_table) const { return FLoadTagsFromScriptTable(this,_table); }
	virtual void OnArchetypeCreated(IEntityArchetype *_pArchetype);
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	
#if 0
	bool DoesEntityArchetypeHaveTag(IEntityArchetype const &arg0, const uint64_t &arg1) const;
	bool DoesEntityArchetypeHaveTag(ArkMetaTagManager::ArchetypeTagInfo const &arg0, const uint64_t arg1) const;
#endif
	
	static inline auto FDoesEntityHaveTag = PreyFunction<bool(ArkMetaTagManager const *const _this, IEntity const &_entity, const uint64_t &_tag)>(0x1453220);
	static inline auto FGetArchetypeTags = PreyFunction<std::vector<unsigned __int64>(ArkMetaTagManager const *const _this, IEntityArchetype const &_entityArchetype)>(0x14534F0);
	static inline auto FGetEntityTags = PreyFunction<std::vector<unsigned __int64>(ArkMetaTagManager const *const _this, IEntity const &_entity)>(0x14538D0);
	static inline auto FAddMetaTagToEntity = PreyFunction<void(ArkMetaTagManager *const _this, unsigned _entityId, const uint64_t &_tag)>(0x1452A90);
	static inline auto FRemoveMetaTagFromEntity = PreyFunction<void(ArkMetaTagManager *const _this, unsigned _entityId, const uint64_t &_tag)>(0x1454580);
	static inline auto FRemoveAllAssignedMetaTagsFromEntity = PreyFunction<void(ArkMetaTagManager *const _this, unsigned _entityId, bool _bSilent)>(0x1454430);
	static inline auto FDoesEntityHaveAnyTagsOv1 = PreyFunction<bool(ArkMetaTagManager const *const _this, IEntity const &_entity, std::vector<unsigned __int64> const &_inputTags)>(0x1452EB0);
	static inline auto FDoesEntityHaveAnyTagsOv0 = PreyFunction<bool(ArkMetaTagManager const *const _this, IEntityArchetype const &_entityArchetype, std::vector<unsigned __int64> const &_tags)>(0x14530B0);
	static inline auto FDoesEntityHaveAllTags = PreyFunction<bool(ArkMetaTagManager const *const _this, IEntity const &_entity, std::vector<unsigned __int64> const &_inputTags)>(0x1452C70);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkMetaTagManager *const _this)>(0x1454340);
	static inline auto FReset = PreyFunction<void(ArkMetaTagManager *const _this, bool _bEnteringGameMode)>(0x1454700);
	static inline auto FSerialize = PreyFunction<void(ArkMetaTagManager *const _this, TSerialize _ser)>(0x1454730);
	static inline auto FPostSerialize = PreyFunction<void(ArkMetaTagManager *const _this)>(0x1454380);
	static inline auto FIsValidTag = PreyFunction<bool(ArkMetaTagManager const *const _this, const uint64_t &_tag)>(0x14539D0);
	static inline auto FGetBaseEntityTags = PreyFunction<std::vector<unsigned __int64>(ArkMetaTagManager const *const _this, IEntity const &_entity)>(0x1453650);
	static inline auto FClearTags = PreyFunction<void(ArkMetaTagManager *const _this, bool _bSilent)>(0x1452BB0);
	static inline auto FLoadTags = PreyFunction<void(ArkMetaTagManager *const _this)>(0x1453B20);
	static inline auto FLoadTagsForArchetype = PreyFunction<void(ArkMetaTagManager *const _this, IEntityArchetype *_pArchetype)>(0x1453E90);
	static inline auto FLoadTagsFromScriptTable = PreyFunction<std::vector<unsigned __int64>(ArkMetaTagManager const *const _this, ArkSafeScriptTable const &_table)>(0x14541A0);
	static inline auto FOnArchetypeCreated = PreyFunction<void(ArkMetaTagManager *const _this, IEntityArchetype *_pArchetype)>(0x1454300);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkMetaTagManager *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x1454310);
};

