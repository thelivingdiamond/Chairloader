// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
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

// ArkMetaTagManager
// Header:  Prey/GameDll/ark/ArkMetaTagManager.h
class ArkMetaTagManager
	: public IArkMetaTagManager
	, public IEntityArchetypeListener
	, public IEntityEventListener
{ // Size=176 (0xB0)
public:
	// ArkMetaTagManager::ArchetypeTagInfo
	// Header:  Prey/GameDll/ark/ArkMetaTagManager.h
	struct ArchetypeTagInfo
	{ // Size=8 (0x8)
		int m_numTags;
		int m_tagOffset;

	#if 0
		ArchetypeTagInfo();
	#endif
	};

	std::unordered_map<unsigned int, std::vector<uint64_t>> m_entityMetaTags;
	std::unordered_map<const IEntityArchetype*, ArkMetaTagManager::ArchetypeTagInfo> m_archetypeToTagInfo;
	std::vector<uint64_t> m_tags;

	ArkMetaTagManager();
	virtual ~ArkMetaTagManager();
	virtual bool DoesEntityHaveTag(const IEntity& _entity, const uint64_t& _tag) const;
	std::vector<uint64_t> GetArchetypeTags(const IEntityArchetype& _entityArchetype) const { alignas(std::vector<uint64_t>) std::byte _return_buf_[sizeof(std::vector<uint64_t>)]; return *FGetArchetypeTags(this, reinterpret_cast<std::vector<uint64_t>*>(_return_buf_), _entityArchetype); }
	std::vector<uint64_t> GetEntityTags(const IEntity& _entity) const { alignas(std::vector<uint64_t>) std::byte _return_buf_[sizeof(std::vector<uint64_t>)]; return *FGetEntityTags(this, reinterpret_cast<std::vector<uint64_t>*>(_return_buf_), _entity); }
	void AddMetaTagToEntity(unsigned _entityId, const uint64_t& _tag) { FAddMetaTagToEntity(this, _entityId, _tag); }
	void RemoveMetaTagFromEntity(unsigned _entityId, const uint64_t& _tag) { FRemoveMetaTagFromEntity(this, _entityId, _tag); }
	void RemoveAllAssignedMetaTagsFromEntity(unsigned _entityId, bool _bSilent) { FRemoveAllAssignedMetaTagsFromEntity(this, _entityId, _bSilent); }
	bool DoesEntityHaveAnyTags(const IEntity& _entity, const std::vector<uint64_t>& _inputTags) const { return FDoesEntityHaveAnyTagsOv1(this, _entity, _inputTags); }
	bool DoesEntityHaveAnyTags(const IEntityArchetype& _entityArchetype, const std::vector<uint64_t>& _tags) const { return FDoesEntityHaveAnyTagsOv0(this, _entityArchetype, _tags); }
	bool DoesEntityHaveAllTags(const IEntity& _entity, const std::vector<uint64_t>& _inputTags) const { return FDoesEntityHaveAllTags(this, _entity, _inputTags); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	bool IsValidTag(const uint64_t& _tag) const { return FIsValidTag(this, _tag); }
	std::vector<uint64_t> GetBaseEntityTags(const IEntity& _entity) const { alignas(std::vector<uint64_t>) std::byte _return_buf_[sizeof(std::vector<uint64_t>)]; return *FGetBaseEntityTags(this, reinterpret_cast<std::vector<uint64_t>*>(_return_buf_), _entity); }
	void ClearTags(bool _bSilent) { FClearTags(this, _bSilent); }
	void LoadTags() { FLoadTags(this); }
	void LoadTagsForArchetype(IEntityArchetype* _pArchetype) { FLoadTagsForArchetype(this, _pArchetype); }
	std::vector<uint64_t> LoadTagsFromScriptTable(const ArkSafeScriptTable& _table) const { alignas(std::vector<uint64_t>) std::byte _return_buf_[sizeof(std::vector<uint64_t>)]; return *FLoadTagsFromScriptTable(this, reinterpret_cast<std::vector<uint64_t>*>(_return_buf_), _table); }
	virtual void OnArchetypeCreated(IEntityArchetype* _pArchetype);
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);

#if 0
	bool DoesEntityArchetypeHaveTag(const IEntityArchetype& _arg0_, const uint64_t& _arg1_) const;
	bool DoesEntityArchetypeHaveTag(const ArkMetaTagManager::ArchetypeTagInfo& _arg0_, const uint64_t _arg1_) const;
#endif

	static inline auto FArkMetaTagManagerOv1 = PreyFunction<void(ArkMetaTagManager* const _this)>(0x1568860);
	static inline auto FDoesEntityHaveTag = PreyFunction<bool(const ArkMetaTagManager* const _this, const IEntity& _entity, const uint64_t& _tag)>(0x15691D0);
	static inline auto FGetArchetypeTags = PreyFunction<std::vector<uint64_t>*(const ArkMetaTagManager* const _this, std::vector<uint64_t>* _return_value_, const IEntityArchetype& _entityArchetype)>(0x15694A0);
	static inline auto FGetEntityTags = PreyFunction<std::vector<uint64_t>*(const ArkMetaTagManager* const _this, std::vector<uint64_t>* _return_value_, const IEntity& _entity)>(0x1569880);
	static inline auto FAddMetaTagToEntity = PreyFunction<void(ArkMetaTagManager* const _this, unsigned _entityId, const uint64_t& _tag)>(0x1568A40);
	static inline auto FRemoveMetaTagFromEntity = PreyFunction<void(ArkMetaTagManager* const _this, unsigned _entityId, const uint64_t& _tag)>(0x156A530);
	static inline auto FRemoveAllAssignedMetaTagsFromEntity = PreyFunction<void(ArkMetaTagManager* const _this, unsigned _entityId, bool _bSilent)>(0x156A3E0);
	static inline auto FDoesEntityHaveAnyTagsOv1 = PreyFunction<bool(const ArkMetaTagManager* const _this, const IEntity& _entity, const std::vector<uint64_t>& _inputTags)>(0x1568E60);
	static inline auto FDoesEntityHaveAnyTagsOv0 = PreyFunction<bool(const ArkMetaTagManager* const _this, const IEntityArchetype& _entityArchetype, const std::vector<uint64_t>& _tags)>(0x1569060);
	static inline auto FDoesEntityHaveAllTags = PreyFunction<bool(const ArkMetaTagManager* const _this, const IEntity& _entity, const std::vector<uint64_t>& _inputTags)>(0x1568C20);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkMetaTagManager* const _this)>(0x156A2F0);
	static inline auto FReset = PreyFunction<void(ArkMetaTagManager* const _this, bool _bEnteringGameMode)>(0x156A6B0);
	static inline auto FSerialize = PreyFunction<void(ArkMetaTagManager* const _this, TSerialize _ser)>(0x156A6E0);
	static inline auto FPostSerialize = PreyFunction<void(ArkMetaTagManager* const _this)>(0x156A330);
	static inline auto FIsValidTag = PreyFunction<bool(const ArkMetaTagManager* const _this, const uint64_t& _tag)>(0x1569980);
	static inline auto FGetBaseEntityTags = PreyFunction<std::vector<uint64_t>*(const ArkMetaTagManager* const _this, std::vector<uint64_t>* _return_value_, const IEntity& _entity)>(0x1569600);
	static inline auto FClearTags = PreyFunction<void(ArkMetaTagManager* const _this, bool _bSilent)>(0x1568B60);
	static inline auto FLoadTags = PreyFunction<void(ArkMetaTagManager* const _this)>(0x1569AD0);
	static inline auto FLoadTagsForArchetype = PreyFunction<void(ArkMetaTagManager* const _this, IEntityArchetype* _pArchetype)>(0x1569E40);
	static inline auto FLoadTagsFromScriptTable = PreyFunction<std::vector<uint64_t>*(const ArkMetaTagManager* const _this, std::vector<uint64_t>* _return_value_, const ArkSafeScriptTable& _table)>(0x156A150);
	static inline auto FOnArchetypeCreated = PreyFunction<void(IEntityArchetypeListener* const _this, IEntityArchetype* _pArchetype)>(0x156A2B0);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x156A2C0);
};
#endif // !MOONCRASH
