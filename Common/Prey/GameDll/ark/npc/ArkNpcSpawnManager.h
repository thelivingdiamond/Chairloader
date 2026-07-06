// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include "ArkNpcSpawnedState.h"

class ArkNpcSpawnRequester;
class CArkNpcSpawner;
struct IEntity;
struct IEntityArchetype;

// Header: FromCpp
// Prey/GameDll/ark/npc/ArkNpcSpawnManager.h
class ArkNpcSpawnManager // Id=8015CD6 Size=24
{
public:
	struct SpawnRequest // Id=8015CDB Size=32
	{
		uint64_t m_id;
		ArkNpcSpawnRequester *m_pRequester;
		CArkNpcSpawner *m_pSpawner;
		void *m_pData;
		
#if 0
		bool operator<(uint64_t arg0) const;
#endif
	};

	using SpawnRequestVector = std::vector<ArkNpcSpawnManager::SpawnRequest>;
	
	std::vector<ArkNpcSpawnManager::SpawnRequest> m_spawnRequests;
	
	static IEntity *CreateNpc(IEntityArchetype &_entityArchetype, Vec3 const &_position, Quat const &_rotation, unsigned _fromStartGameEntityId, boost::variant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant> const &_spawnedState) { return FCreateNpc(_entityArchetype,_position,_rotation,_fromStartGameEntityId,_spawnedState); }
	static IEntity *CreateNpcCorpse(IEntityArchetype &_entityArchetype, Vec3 const &_position, Quat const &_rotation, unsigned _fromStartGameEntityId) { return FCreateNpcCorpseOv1(_entityArchetype,_position,_rotation,_fromStartGameEntityId); }
	static IEntity *CreateNpcCorpse(IEntityArchetype &_entityArchetype, Vec3 const &_position, Quat const &_rotation, const char *_pPoseAnimationName, bool _bRigorMortis, unsigned _fromStartGameEntityId) { return FCreateNpcCorpseOv0(_entityArchetype,_position,_rotation,_pPoseAnimationName,_bRigorMortis,_fromStartGameEntityId); }
	ArkNpcSpawnManager();
	uint64_t RequestNpcSpawn(ArkNpcSpawnRequester &_requester, CArkNpcSpawner &_spawner) { return FRequestNpcSpawnOv1(this,_requester,_spawner); }
	void Update(float _elapsedTime) { FUpdate(this,_elapsedTime); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	
#if 0
	uint64_t RequestNpcSpawn(ArkNpcSpawnRequester &arg0, CArkNpcSpawner &arg1, void *arg2);
	uint64_t RequestNpcSpawn(CArkNpcSpawner &arg0);
	void CancelNpcSpawnRequest(uint64_t arg0);
	bool HasNpcSpawnRequest(uint64_t arg0) const;
#endif
	
	static inline auto FCreateNpc = PreyFunction<IEntity *(IEntityArchetype &_entityArchetype, Vec3 const &_position, Quat const &_rotation, unsigned _fromStartGameEntityId, boost::variant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant> const &_spawnedState)>(0x151D6D0);
	static inline auto FCreateNpcCorpseOv1 = PreyFunction<IEntity *(IEntityArchetype &_entityArchetype, Vec3 const &_position, Quat const &_rotation, unsigned _fromStartGameEntityId)>(0x151D770);
	static inline auto FCreateNpcCorpseOv0 = PreyFunction<IEntity *(IEntityArchetype &_entityArchetype, Vec3 const &_position, Quat const &_rotation, const char *_pPoseAnimationName, bool _bRigorMortis, unsigned _fromStartGameEntityId)>(0x151D8A0);
	static inline auto FRequestNpcSpawnOv1 = PreyFunction<uint64_t(ArkNpcSpawnManager *const _this, ArkNpcSpawnRequester &_requester, CArkNpcSpawner &_spawner)>(0x151DAC0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcSpawnManager *const _this, float _elapsedTime)>(0x151DB30);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkNpcSpawnManager *const _this)>(0x151DAA0);
	static inline auto FReset = PreyFunction<void(ArkNpcSpawnManager *const _this, bool _bEnteringGameMode)>(0x151DB10);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkNpcSpawnRequester;
struct IEntity;
struct IEntityArchetype;

// ArkNpcSpawnManager
// Header:  Prey/GameDll/ark/npc/ArkNpcSpawnManager.h
class ArkNpcSpawnManager
{ // Size=24 (0x18)
public:
	// ArkNpcSpawnManager::SpawnRequest
	// Header:  Prey/GameDll/ark/npc/ArkNpcSpawnManager.h
	struct SpawnRequest
	{ // Size=40 (0x28)
		uint64_t m_id;
		ArkNpcSpawnRequester* m_pRequester;
		unsigned m_spawnerEntityId;
		string m_encounterProfileName;
		string m_encounterName;

	#if 0
		SpawnRequest();
		SpawnRequest(uint64_t _arg0_, ArkNpcSpawnRequester* _arg1_, unsigned _arg2_, const string& _arg3_, const string& _arg4_);
		bool operator<(uint64_t _arg0_) const;
	#endif
	};

	using SpawnRequestVector = std::vector<ArkNpcSpawnManager::SpawnRequest>;

	std::vector<ArkNpcSpawnManager::SpawnRequest> m_spawnRequests;

	static IEntity* CreateNpc(IEntityArchetype& _entityArchetype, const Vec3& _position, const Quat& _rotation, uint64_t _randomValueSeed, const boost::variant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant>& _spawnedState, unsigned _fromStartGameEntityId) { return FCreateNpc(_entityArchetype, _position, _rotation, _randomValueSeed, _spawnedState, _fromStartGameEntityId); }
	static IEntity* CreateNpcCorpse(IEntityArchetype& _entityArchetype, const Vec3& _position, const Quat& _rotation, uint64_t _randomValueSeed, unsigned _fromStartGameEntityId) { return FCreateNpcCorpseOv1(_entityArchetype, _position, _rotation, _randomValueSeed, _fromStartGameEntityId); }
	static IEntity* CreateNpcCorpse(IEntityArchetype& _entityArchetype, const Vec3& _position, const Quat& _rotation, const char* _pPoseAnimationName, bool _bRigorMortis, uint64_t _randomValueSeed, unsigned _fromStartGameEntityId) { return FCreateNpcCorpseOv0(_entityArchetype, _position, _rotation, _pPoseAnimationName, _bRigorMortis, _randomValueSeed, _fromStartGameEntityId); }
	ArkNpcSpawnManager();
	uint64_t RequestNpcSpawnFromFlowgraph(ArkNpcSpawnRequester& _requester, unsigned _spawnerEntityId) { return FRequestNpcSpawnFromFlowgraph(this, _requester, _spawnerEntityId); }
	void RequestNpcSpawn(unsigned _spawnerEntityId, const string& _profileEncounterName, const string& _encounterName) { FRequestNpcSpawn(this, _spawnerEntityId, _profileEncounterName, _encounterName); }
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Serialize(TSerialize _serializer) { FSerialize(this, _serializer); }

#if 0
	ArkNpcSpawnManager(const ArkNpcSpawnManager& _arg0_);
	void CancelNpcSpawnRequest(uint64_t _arg0_);
	bool HasNpcSpawnRequest(uint64_t _arg0_) const;
	ArkNpcSpawnManager& operator=(const ArkNpcSpawnManager& _arg0_);
#endif

	static inline auto FCreateNpc = PreyFunction<IEntity* (IEntityArchetype& _entityArchetype, const Vec3& _position, const Quat& _rotation, uint64_t _randomValueSeed, const boost::variant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant>& _spawnedState, unsigned _fromStartGameEntityId)>(0x163CA60);
	static inline auto FCreateNpcCorpseOv1 = PreyFunction<IEntity* (IEntityArchetype& _entityArchetype, const Vec3& _position, const Quat& _rotation, uint64_t _randomValueSeed, unsigned _fromStartGameEntityId)>(0x163CD40);
	static inline auto FCreateNpcCorpseOv0 = PreyFunction<IEntity* (IEntityArchetype& _entityArchetype, const Vec3& _position, const Quat& _rotation, const char* _pPoseAnimationName, bool _bRigorMortis, uint64_t _randomValueSeed, unsigned _fromStartGameEntityId)>(0x163CAE0);
	static inline auto FArkNpcSpawnManagerOv1 = PreyFunction<void(ArkNpcSpawnManager* const _this)>(0x1F4DF0);
	static inline auto FRequestNpcSpawnFromFlowgraph = PreyFunction<uint64_t(ArkNpcSpawnManager* const _this, ArkNpcSpawnRequester& _requester, unsigned _spawnerEntityId)>(0x163D000);
	static inline auto FRequestNpcSpawn = PreyFunction<void(ArkNpcSpawnManager* const _this, unsigned _spawnerEntityId, const string& _profileEncounterName, const string& _encounterName)>(0x163CF10);
	static inline auto FUpdate = PreyFunction<void(ArkNpcSpawnManager* const _this, float _elapsedTime)>(0x163D330);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkNpcSpawnManager* const _this)>(0x163CEE0);
	static inline auto FReset = PreyFunction<void(ArkNpcSpawnManager* const _this, bool _bEnteringGameMode)>(0x163D050);
	static inline auto FSerialize = PreyFunction<void(ArkNpcSpawnManager* const _this, TSerialize _serializer)>(0x163D090);
};
#endif // !MOONCRASH
