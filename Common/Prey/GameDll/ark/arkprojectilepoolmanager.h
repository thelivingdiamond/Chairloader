// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/VectorMap.h>

class CArkProjectile;
class CArkProjectileGoo;
class CArkProjectileGrenade;
struct IEntityArchetype;
struct SEntitySpawnParams;

// Header: FromCpp
// Prey/GameDll/ark/arkprojectilepoolmanager.h
class CArkProjectilePoolManager // Id=8015F09 Size=24
{
public:
	struct SProjectilePoolDesc // Id=8016044 Size=72
	{
		std::deque<unsigned int,std::allocator<unsigned int> > m_freeProjectiles;
		std::vector<unsigned int> m_usedProjectiles;
		int m_maxSize;
		bool m_bDeleteOnLevelTransition;
		bool m_bIsGrenade;
	};

	using TProjectilePoolMap = VectorMap<unsigned __int64,CArkProjectilePoolManager::SProjectilePoolDesc,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64,CArkProjectilePoolManager::SProjectilePoolDesc> > >;
	
	VectorMap<unsigned __int64,CArkProjectilePoolManager::SProjectilePoolDesc,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64,CArkProjectilePoolManager::SProjectilePoolDesc> > > m_archetypePools;
	
	CArkProjectilePoolManager();
	~CArkProjectilePoolManager();
	void Shutdown() { FShutdown(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void Reset() { FReset(this); }
	void LoadPoolDefinitions() { FLoadPoolDefinitions(this); }
	void CreatePool(IEntityArchetype *const _pArchetype, const int _maxPoolSize, const bool _bDeleteOnLevelTransition, const bool _bIsGrenade) { FCreatePool(this,_pArchetype,_maxPoolSize,_bDeleteOnLevelTransition,_bIsGrenade); }
	void SpawnAndReleaseAllPooledProjectiles(IEntityArchetype *const _pArchetype, const int _maxPoolSize) { FSpawnAndReleaseAllPooledProjectiles(this,_pArchetype,_maxPoolSize); }
	void ReturnAllToPool() { FReturnAllToPool(this); }
	void ReturnToPool(CArkProjectile *const _pProjectile) { FReturnToPool(this,_pProjectile); }
	void RemoveFromPool(CArkProjectile *const _pProjectile) { FRemoveFromPool(this,_pProjectile); }
	bool IsPooled(IEntityArchetype *const _pArchetype) { return FIsPooled(this,_pArchetype); }
	CArkProjectile *SpawnProjectile(SEntitySpawnParams &_spawnParams, const bool _bIsPooled) { return FSpawnProjectile(this,_spawnParams,_bIsPooled); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	uint64_t GetProjectilePackageId(IEntityArchetype *const _pArchetype) { return FGetProjectilePackageId(this,_pArchetype); }
	void DestroyAllProjectilesForLevelTransition() { FDestroyAllProjectilesForLevelTransition(this); }
	bool IsAnotherGrenadeDetonating(CArkProjectileGrenade *const _pGrenade) { return FIsAnotherGrenadeDetonating(this,_pGrenade); }
	bool IsAnotherGooDestroying(CArkProjectileGoo *const _pGoo) { return FIsAnotherGooDestroying(this,_pGoo); }
	CArkProjectile *GetArkProjectileFromEntityId(const unsigned _entityId, const char *const _pArchetype) { return FGetArkProjectileFromEntityId(this,_entityId,_pArchetype); }
	void DestroyAllProjectiles() { FDestroyAllProjectiles(this); }
	void FreePool(IEntityArchetype *const _pArchetype) { FFreePool(this,_pArchetype); }
	CArkProjectile *DoSpawnProjectile(SEntitySpawnParams &_spawnParams) { return FDoSpawnProjectile(this,_spawnParams); }
	CArkProjectile *UseFromPool(SEntitySpawnParams &_spawnParams) { return FUseFromPool(this,_spawnParams); }
	
#if 0
	void FreePools();
#endif
	
	static inline auto FBitNotCArkProjectilePoolManager = PreyFunction<void(CArkProjectilePoolManager *const _this)>(0x124D4E0);
	static inline auto FShutdown = PreyFunction<void(CArkProjectilePoolManager *const _this)>(0x124F5A0);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(CArkProjectilePoolManager *const _this)>(0x124E6F0);
	static inline auto FSerialize = PreyFunction<void(CArkProjectilePoolManager *const _this, TSerialize _ser)>(0x124EEB0);
	static inline auto FPostSerialize = PreyFunction<void(CArkProjectilePoolManager *const _this)>(0x124E770);
	static inline auto FReset = PreyFunction<void(CArkProjectilePoolManager *const _this)>(0x124EA90);
	static inline auto FLoadPoolDefinitions = PreyFunction<void(CArkProjectilePoolManager *const _this)>(0x124E440);
	static inline auto FCreatePool = PreyFunction<void(CArkProjectilePoolManager *const _this, IEntityArchetype *const _pArchetype, const int _maxPoolSize, const bool _bDeleteOnLevelTransition, const bool _bIsGrenade)>(0x124D5E0);
	static inline auto FSpawnAndReleaseAllPooledProjectiles = PreyFunction<void(CArkProjectilePoolManager *const _this, IEntityArchetype *const _pArchetype, const int _maxPoolSize)>(0x124F620);
	static inline auto FReturnAllToPool = PreyFunction<void(CArkProjectilePoolManager *const _this)>(0x124EAA0);
	static inline auto FReturnToPool = PreyFunction<void(CArkProjectilePoolManager *const _this, CArkProjectile *const _pProjectile)>(0x124EC80);
	static inline auto FRemoveFromPool = PreyFunction<void(CArkProjectilePoolManager *const _this, CArkProjectile *const _pProjectile)>(0x124E880);
	static inline auto FIsPooled = PreyFunction<bool(CArkProjectilePoolManager *const _this, IEntityArchetype *const _pArchetype)>(0x124E380);
	static inline auto FSpawnProjectile = PreyFunction<CArkProjectile *(CArkProjectilePoolManager *const _this, SEntitySpawnParams &_spawnParams, const bool _bIsPooled)>(0x124F9D0);
	static inline auto FUpdate = PreyFunction<void(CArkProjectilePoolManager *const _this, const float _frameTime)>(0xA13080);
	static inline auto FGetProjectilePackageId = PreyFunction<uint64_t(CArkProjectilePoolManager *const _this, IEntityArchetype *const _pArchetype)>(0x124DFA0);
	static inline auto FDestroyAllProjectilesForLevelTransition = PreyFunction<void(CArkProjectilePoolManager *const _this)>(0x124DAC0);
	static inline auto FIsAnotherGrenadeDetonating = PreyFunction<bool(CArkProjectilePoolManager *const _this, CArkProjectileGrenade *const _pGrenade)>(0x124E1E0);
	static inline auto FIsAnotherGooDestroying = PreyFunction<bool(CArkProjectilePoolManager *const _this, CArkProjectileGoo *const _pGoo)>(0x124E0D0);
	static inline auto FGetArkProjectileFromEntityId = PreyFunction<CArkProjectile *(CArkProjectilePoolManager *const _this, const unsigned _entityId, const char *const _pArchetype)>(0x124DF00);
	static inline auto FDestroyAllProjectiles = PreyFunction<void(CArkProjectilePoolManager *const _this)>(0x124D7E0);
	static inline auto FFreePool = PreyFunction<void(CArkProjectilePoolManager *const _this, IEntityArchetype *const _pArchetype)>(0x124DD80);
	static inline auto FDoSpawnProjectile = PreyFunction<CArkProjectile *(CArkProjectilePoolManager *const _this, SEntitySpawnParams &_spawnParams)>(0x124DCE0);
	static inline auto FUseFromPool = PreyFunction<CArkProjectile *(CArkProjectilePoolManager *const _this, SEntitySpawnParams &_spawnParams)>(0x124F9E0);
};

