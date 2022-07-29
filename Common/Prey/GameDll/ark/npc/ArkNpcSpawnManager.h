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

