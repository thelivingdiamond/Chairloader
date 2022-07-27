// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IArkFactionManager.h>

class IArkFactionListener;
struct IConsoleCmdArgs;

// Header: Exact
// Prey/GameDll/ark/ArkFactionManager.h
class ArkFactionManager : public IArkFactionManager // Id=800B7CF Size=472
{
public:
	using FactionToEntityPair = std::pair<unsigned int,unsigned int>;
	using EntityToFactionPair = std::pair<unsigned int,unsigned int>;
	using EntityToEntityPair = std::pair<unsigned int,unsigned int>;
	
	unsigned m_numberOfFactions;
	std::unordered_map<unsigned int,unsigned int> m_entityFactionMap;
	std::vector<std::vector<unsigned int>> m_factionFollowers;
	std::vector<enum EArkDisposition> m_factionDispositions;
	std::unordered_map<std::pair<unsigned int,unsigned int>,enum EArkDisposition,ArkPairHash<std::hash>,std::equal_to<std::pair<unsigned int,unsigned int> >,std::allocator<std::pair<std::pair<unsigned int,unsigned int> const ,enum EArkDisposition> > > m_factionToEntityDisposition;
	std::unordered_map<std::pair<unsigned int,unsigned int>,enum EArkDisposition,ArkPairHash<std::hash>,std::equal_to<std::pair<unsigned int,unsigned int> >,std::allocator<std::pair<std::pair<unsigned int,unsigned int> const ,enum EArkDisposition> > > m_entityToFactionDisposition;
	std::unordered_map<std::pair<unsigned int,unsigned int>,enum EArkDisposition,ArkPairHash<std::hash>,std::equal_to<std::pair<unsigned int,unsigned int> >,std::allocator<std::pair<std::pair<unsigned int,unsigned int> const ,enum EArkDisposition> > > m_entityToEntityDisposition;
	std::set<IArkFactionListener *,std::less<IArkFactionListener *>> m_factionListeners;
	std::unordered_map<string,unsigned int,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,unsigned int>>> m_nameToIndexMap;
	std::unordered_map<unsigned __int64,unsigned int> m_idToIndexMap;
	bool m_bDisableListeners;
	
	ArkFactionManager();
	~ArkFactionManager() { FBitNotArkFactionManager(this); }
	virtual unsigned GetFactionIndex(const char *const _pFactionName) const;
	virtual unsigned GetFactionIndex(const uint64_t &_factionGuid) const;
	virtual string const &GetFactionName(unsigned _factionIndex) const;
	virtual string const &GetFactionName(uint64_t _factionId) const;
	virtual uint64_t GetFactionId(const char *const _pFactionName) const;
	virtual uint64_t GetFactionId(unsigned _factionIndex) const;
	bool IsValidFaction(unsigned _factionIndex) const { return FIsValidFaction(this,_factionIndex); }
	void SetEntityFaction(unsigned _entityId, unsigned _factionIndex) { FSetEntityFaction(this,_entityId,_factionIndex); }
	virtual unsigned GetEntityFaction(unsigned _entityId) const;
	uint64_t GetEntityFactionId(unsigned _entityId) const { return FGetEntityFactionId(this,_entityId); }
	void OnEntityRelease(unsigned _entityId) { FOnEntityRelease(this,_entityId); }
	void RegisterFactionListener(IArkFactionListener *_pFactionListener) { FRegisterFactionListener(this,_pFactionListener); }
	void UnregisterFactionListener(IArkFactionListener *_pFactionListener) { FUnregisterFactionListener(this,_pFactionListener); }
	bool HasFactionListener(IArkFactionListener *_pFactionListener) { return FHasFactionListener(this,_pFactionListener); }
	void SetEntityDispositionToFaction(unsigned _fromEntityId, unsigned _toFactionIndex, EArkDisposition _disposition, bool _bReciprocate) { FSetEntityDispositionToFaction(this,_fromEntityId,_toFactionIndex,_disposition,_bReciprocate); }
	virtual void SetEntityDispositionToEntity(unsigned arg0, unsigned arg1, EArkDisposition arg2, bool arg3);
	void SetEntityDispositionToFactionEntities(unsigned _fromEntityId, unsigned _toFactionIndex, EArkDisposition _disposition, bool _bReciprocate) { FSetEntityDispositionToFactionEntities(this,_fromEntityId,_toFactionIndex,_disposition,_bReciprocate); }
	virtual void SetFactionDispositionToFaction(unsigned arg0, unsigned arg1, EArkDisposition arg2, bool arg3);
	virtual void SetFactionDispositionToEntity(unsigned arg0, unsigned arg1, EArkDisposition arg2, bool arg3);
	EArkDisposition GetAssignedFactionDispositionToFaction(unsigned _fromFactionIndex, unsigned _toFactionIndex) const { return FGetAssignedFactionDispositionToFaction(this,_fromFactionIndex,_toFactionIndex); }
	EArkDisposition GetAssignedFactionDispositionToEntity(unsigned _fromFactionIndex, unsigned _toEntityId) const { return FGetAssignedFactionDispositionToEntity(this,_fromFactionIndex,_toEntityId); }
	EArkDisposition GetAssignedEntityDispositionToEntity(unsigned _fromEntityId, unsigned _toEntityId) const { return FGetAssignedEntityDispositionToEntity(this,_fromEntityId,_toEntityId); }
	EArkDisposition GetAssignedEntityDispositionToFaction(unsigned _fromEntityId, unsigned _toFactionIndex) const { return FGetAssignedEntityDispositionToFaction(this,_fromEntityId,_toFactionIndex); }
	EArkDisposition GetEffectiveFactionDispositionToFaction(unsigned _fromFactionIndex, unsigned _toFactionIndex) const { return FGetEffectiveFactionDispositionToFaction(this,_fromFactionIndex,_toFactionIndex); }
	virtual EArkDisposition GetEffectiveFactionDispositionToEntity(unsigned _fromFactionIndex, unsigned _toEntityId) const;
	virtual EArkDisposition GetEffectiveEntityDispositionToEntity(unsigned _fromEntityId, unsigned _toEntityId) const;
	EArkDisposition GetEffectiveEntityDispositionToFaction(unsigned _fromEntityId, unsigned _toFactionIndex) const { return FGetEffectiveEntityDispositionToFaction(this,_fromEntityId,_toFactionIndex); }
	void RemoveEntityDispositionToFaction(unsigned _fromEntityId, unsigned _toFactionIndex, bool _bReciprocate, bool _bHostileOnly) { FRemoveEntityDispositionToFaction(this,_fromEntityId,_toFactionIndex,_bReciprocate,_bHostileOnly); }
	void RemoveEntityDispositionToEntity(unsigned _fromEntityId, unsigned _toEntityId, bool _bReciprocate, bool _bHostileOnly) { FRemoveEntityDispositionToEntity(this,_fromEntityId,_toEntityId,_bReciprocate,_bHostileOnly); }
	void RemoveEntityDispositionToFactionEntities(unsigned _fromEntityId, unsigned _toFactionIndex, bool _bReciprocate, bool _bHostileOnly) { FRemoveEntityDispositionToFactionEntities(this,_fromEntityId,_toFactionIndex,_bReciprocate,_bHostileOnly); }
	void RemoveFactionDispositionToEntity(unsigned _factionIndex, unsigned _entityId, bool _bReciprocate, bool _bHostileOnly) { FRemoveFactionDispositionToEntity(this,_factionIndex,_entityId,_bReciprocate,_bHostileOnly); }
	void RemoveFactionDispositionToFactionEntities(unsigned _fromFactionIndex, unsigned _toFactionIndex, bool _bReciprocate, bool _bHostileOnly) { FRemoveFactionDispositionToFactionEntities(this,_fromFactionIndex,_toFactionIndex,_bReciprocate,_bHostileOnly); }
	void RemoveFactionEntitiesDispositionToFactionEntities(unsigned _fromFactionIndex, unsigned _toFactionIndex, bool _bReciprocate, bool _bHostileOnly) { FRemoveFactionEntitiesDispositionToFactionEntities(this,_fromFactionIndex,_toFactionIndex,_bReciprocate,_bHostileOnly); }
	void RemoveFactionEntitiesDispositionToEntity(unsigned _fromFactionIndex, unsigned _toEntityId, bool _bReciprocate, bool _bHostileOnly) { FRemoveFactionEntitiesDispositionToEntity(this,_fromFactionIndex,_toEntityId,_bReciprocate,_bHostileOnly); }
	void RemoveFactionEntitiesDispositionToFaction(unsigned _fromFactionIndex, unsigned _toFactionIndex, bool _bReciprocate, bool _bHostileOnly) { FRemoveFactionEntitiesDispositionToFaction(this,_fromFactionIndex,_toFactionIndex,_bReciprocate,_bHostileOnly); }
	void EndFactionHostilityWithFaction(unsigned _fromFactionIndex, unsigned _toFactionIndex, bool _bMakeFriendly) { FEndFactionHostilityWithFaction(this,_fromFactionIndex,_toFactionIndex,_bMakeFriendly); }
	void EndFactionHostilityWithEntity(unsigned _fromFactionIndex, unsigned _toEntityId, bool _bMakeFriendly) { FEndFactionHostilityWithEntity(this,_fromFactionIndex,_toEntityId,_bMakeFriendly); }
	void EndEntityHostilityWithFaction(unsigned _fromEntityId, unsigned _toFactionIndex, bool _bMakeFriendly) { FEndEntityHostilityWithFaction(this,_fromEntityId,_toFactionIndex,_bMakeFriendly); }
	void EndEntityHostilityWithEntity(unsigned _fromEntityId, unsigned _toEntityId, bool _bMakeFriendly) { FEndEntityHostilityWithEntity(this,_fromEntityId,_toEntityId,_bMakeFriendly); }
	virtual std::unordered_map<unsigned __int64,unsigned int> const &GetGuidMap() const;
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	virtual void ReloadFactions();
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	void ClearAll() { FClearAll(this); }
	void LoadFile() { FLoadFile(this); }
	void RemoveFollowerFromFaction(unsigned _faction, unsigned _entityId) { FRemoveFollowerFromFaction(this,_faction,_entityId); }
	void ClearAssignedDispositionsForEntity(unsigned _entityId) { FClearAssignedDispositionsForEntity(this,_entityId); }
	static void StopFighting(unsigned _fromEntityId, unsigned _toEntityId) { FStopFighting(_fromEntityId,_toEntityId); }
	
#if 0
	unsigned GetNumFactions() const;
	void SetFactionDispositionToFactionEntities(unsigned arg0, unsigned arg1, EArkDisposition arg2, bool arg3);
	void SetFactionEntitiesDispositionToFactionEntities(unsigned arg0, unsigned arg1, EArkDisposition arg2, bool arg3);
	void SetFactionEntitiesDispositionToFaction(unsigned arg0, unsigned arg1, EArkDisposition arg2, bool arg3);
	void SetFactionEntitiesDispositionToEntity(unsigned arg0, unsigned arg1, EArkDisposition arg2, bool arg3);
	void DumpAllFactions(const char *const arg0) const;
	void AddFollowerToFaction(unsigned arg0, unsigned arg1);
	unsigned GetFactionOffset(const unsigned arg0) const;
	void NotifyAssignedFactionToFactionDispositionChange(unsigned arg0, unsigned arg1, EArkDisposition arg2, EArkDisposition arg3);
	void NotifyAssignedFactionToEntityDispositionChange(unsigned arg0, unsigned arg1, EArkDisposition arg2, EArkDisposition arg3);
	void NotifyAssignedEntityToFactionDispositionChange(unsigned arg0, unsigned arg1, EArkDisposition arg2, EArkDisposition arg3);
	void NotifyAssignedEntityToEntityDispositionChange(unsigned arg0, unsigned arg1, EArkDisposition arg2, EArkDisposition arg3);
	void NotifyEffectiveEntityToEntityDispositionChange(unsigned arg0, unsigned arg1, EArkDisposition arg2, EArkDisposition arg3);
	void LiveFix_PlayerFactions();
	static void OnConsoleDumpFaction(IConsoleCmdArgs *arg0);
	static void OnConsoleSetPlayerFaction(IConsoleCmdArgs *arg0);
#endif
	
	static inline auto FBitNotArkFactionManager = PreyFunction<void(ArkFactionManager *const _this)>(0x142FE10);
	static inline auto FGetFactionIndexOv1 = PreyFunction<unsigned(ArkFactionManager const *const _this, const char *const _pFactionName)>(0x1431730);
	static inline auto FGetFactionIndexOv0 = PreyFunction<unsigned(ArkFactionManager const *const _this, const uint64_t &_factionGuid)>(0x1431650);
	static inline auto FGetFactionNameOv1 = PreyFunction<string const &(ArkFactionManager const *const _this, unsigned _factionIndex)>(0x14318F0);
	static inline auto FGetFactionNameOv0 = PreyFunction<string const &(ArkFactionManager const *const _this, uint64_t _factionId)>(0x1431A30);
	static inline auto FGetFactionIdOv1 = PreyFunction<uint64_t(ArkFactionManager const *const _this, const char *const _pFactionName)>(0x1431620);
	static inline auto FGetFactionIdOv0 = PreyFunction<uint64_t(ArkFactionManager const *const _this, unsigned _factionIndex)>(0x14315C0);
	static inline auto FIsValidFaction = PreyFunction<bool(ArkFactionManager const *const _this, unsigned _factionIndex)>(0x1431AC0);
	static inline auto FSetEntityFaction = PreyFunction<void(ArkFactionManager *const _this, unsigned _entityId, unsigned _factionIndex)>(0x14336A0);
	static inline auto FGetEntityFaction = PreyFunction<unsigned(ArkFactionManager const *const _this, unsigned _entityId)>(0x14314D0);
	static inline auto FGetEntityFactionId = PreyFunction<uint64_t(ArkFactionManager const *const _this, unsigned _entityId)>(0x1431590);
	static inline auto FOnEntityRelease = PreyFunction<void(ArkFactionManager *const _this, unsigned _entityId)>(0x1431F60);
	static inline auto FRegisterFactionListener = PreyFunction<void(ArkFactionManager *const _this, IArkFactionListener *_pFactionListener)>(0x1431FB0);
	static inline auto FUnregisterFactionListener = PreyFunction<void(ArkFactionManager *const _this, IArkFactionListener *_pFactionListener)>(0x14342D0);
	static inline auto FHasFactionListener = PreyFunction<bool(ArkFactionManager *const _this, IArkFactionListener *_pFactionListener)>(0x1431A70);
	static inline auto FSetEntityDispositionToFaction = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromEntityId, unsigned _toFactionIndex, EArkDisposition _disposition, bool _bReciprocate)>(0x1433340);
	static inline auto FSetEntityDispositionToFactionEntities = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromEntityId, unsigned _toFactionIndex, EArkDisposition _disposition, bool _bReciprocate)>(0x14335D0);
	static inline auto FGetAssignedFactionDispositionToFaction = PreyFunction<EArkDisposition(ArkFactionManager const *const _this, unsigned _fromFactionIndex, unsigned _toFactionIndex)>(0x1431480);
	static inline auto FGetAssignedFactionDispositionToEntity = PreyFunction<EArkDisposition(ArkFactionManager const *const _this, unsigned _fromFactionIndex, unsigned _toEntityId)>(0x1431220);
	static inline auto FGetAssignedEntityDispositionToEntity = PreyFunction<EArkDisposition(ArkFactionManager const *const _this, unsigned _fromEntityId, unsigned _toEntityId)>(0x1431170);
	static inline auto FGetAssignedEntityDispositionToFaction = PreyFunction<EArkDisposition(ArkFactionManager const *const _this, unsigned _fromEntityId, unsigned _toFactionIndex)>(0x14311B0);
	static inline auto FGetEffectiveFactionDispositionToFaction = PreyFunction<EArkDisposition(ArkFactionManager const *const _this, unsigned _fromFactionIndex, unsigned _toFactionIndex)>(0x1431480);
	static inline auto FGetEffectiveFactionDispositionToEntity = PreyFunction<EArkDisposition(ArkFactionManager const *const _this, unsigned _fromFactionIndex, unsigned _toEntityId)>(0x14313B0);
	static inline auto FGetEffectiveEntityDispositionToEntity = PreyFunction<EArkDisposition(ArkFactionManager const *const _this, unsigned _fromEntityId, unsigned _toEntityId)>(0x1431290);
	static inline auto FGetEffectiveEntityDispositionToFaction = PreyFunction<EArkDisposition(ArkFactionManager const *const _this, unsigned _fromEntityId, unsigned _toFactionIndex)>(0x1431320);
	static inline auto FRemoveEntityDispositionToFaction = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromEntityId, unsigned _toFactionIndex, bool _bReciprocate, bool _bHostileOnly)>(0x14320A0);
	static inline auto FRemoveEntityDispositionToEntity = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromEntityId, unsigned _toEntityId, bool _bReciprocate, bool _bHostileOnly)>(0x1432000);
	static inline auto FRemoveEntityDispositionToFactionEntities = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromEntityId, unsigned _toFactionIndex, bool _bReciprocate, bool _bHostileOnly)>(0x1432180);
	static inline auto FRemoveFactionDispositionToEntity = PreyFunction<void(ArkFactionManager *const _this, unsigned _factionIndex, unsigned _entityId, bool _bReciprocate, bool _bHostileOnly)>(0x1432250);
	static inline auto FRemoveFactionDispositionToFactionEntities = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromFactionIndex, unsigned _toFactionIndex, bool _bReciprocate, bool _bHostileOnly)>(0x14322F0);
	static inline auto FRemoveFactionEntitiesDispositionToFactionEntities = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromFactionIndex, unsigned _toFactionIndex, bool _bReciprocate, bool _bHostileOnly)>(0x1432550);
	static inline auto FRemoveFactionEntitiesDispositionToEntity = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromFactionIndex, unsigned _toEntityId, bool _bReciprocate, bool _bHostileOnly)>(0x14323D0);
	static inline auto FRemoveFactionEntitiesDispositionToFaction = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromFactionIndex, unsigned _toFactionIndex, bool _bReciprocate, bool _bHostileOnly)>(0x14324A0);
	static inline auto FEndFactionHostilityWithFaction = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromFactionIndex, unsigned _toFactionIndex, bool _bMakeFriendly)>(0x1430EE0);
	static inline auto FEndFactionHostilityWithEntity = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromFactionIndex, unsigned _toEntityId, bool _bMakeFriendly)>(0x1430D60);
	static inline auto FEndEntityHostilityWithFaction = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromEntityId, unsigned _toFactionIndex, bool _bMakeFriendly)>(0x1430BE0);
	static inline auto FEndEntityHostilityWithEntity = PreyFunction<void(ArkFactionManager *const _this, unsigned _fromEntityId, unsigned _toEntityId, bool _bMakeFriendly)>(0x1430BA0);
	static inline auto FGetGuidMap = PreyFunction<std::unordered_map<unsigned __int64,unsigned int> const &(ArkFactionManager const *const _this)>(0x1431A60);
	static inline auto FSerialize = PreyFunction<void(ArkFactionManager *const _this, TSerialize _ser)>(0x14327C0);
	static inline auto FReloadFactions = PreyFunction<void(ArkFactionManager *const _this)>(0x1431FE0);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkFactionManager *const _this)>(0x1043A70);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkFactionManager *const _this)>(0x1431FA0);
	static inline auto FReset = PreyFunction<void(ArkFactionManager *const _this, bool _bEnteringGameMode)>(0x1043A70);
	static inline auto FClearAll = PreyFunction<void(ArkFactionManager *const _this)>(0x14305C0);
	static inline auto FLoadFile = PreyFunction<void(ArkFactionManager *const _this)>(0x1431AF0);
	static inline auto FRemoveFollowerFromFaction = PreyFunction<void(ArkFactionManager *const _this, unsigned _faction, unsigned _entityId)>(0x14326D0);
	static inline auto FClearAssignedDispositionsForEntity = PreyFunction<void(ArkFactionManager *const _this, unsigned _entityId)>(0x1430790);
	static inline auto FStopFighting = PreyFunction<void(unsigned _fromEntityId, unsigned _toEntityId)>(0x1434210);
};

