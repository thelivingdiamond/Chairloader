// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>

class IArkPlayerMimic;
struct IEntity;

// ArkPlayerMimicSpawner
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicSpawner.h
class ArkPlayerMimicSpawner
{ // Size=1 (0x1)
public:
	static OBB ComputeInitialWorldBounds(const IEntity& _targetEntity) { return FComputeInitialWorldBounds(_targetEntity); }
	static const char* GetSurrogateArchetype(const IEntity& _entity) { return FGetSurrogateArchetype(_entity); }
	static std::unique_ptr<IArkPlayerMimic> Spawn(const IEntity& _targetEntity, const QuatT& _worldTransform) { return FSpawnOv1(_targetEntity, _worldTransform); }
	static std::unique_ptr<IArkPlayerMimic> Spawn(const char* _pClassName, const unsigned _entityId) { return FSpawnOv0(_pClassName, _entityId); }
	static void Serialize(TSerialize _ser, std::unique_ptr<IArkPlayerMimic>& _pMimic) { FSerialize(_ser, _pMimic); }

	static inline auto FComputeInitialWorldBounds = PreyFunction<OBB(const IEntity& _targetEntity)>(0x1320280);
	static inline auto FGetSurrogateArchetype = PreyFunction<const char* (const IEntity& _entity)>(0x1320830);
	static inline auto FSpawnOv1 = PreyFunction<std::unique_ptr<IArkPlayerMimic>(const IEntity& _targetEntity, const QuatT& _worldTransform)>(0x1321A70);
	static inline auto FSpawnOv0 = PreyFunction<std::unique_ptr<IArkPlayerMimic>(const char* _pClassName, const unsigned _entityId)>(0x1321700);
	static inline auto FSerialize = PreyFunction<void(TSerialize _ser, std::unique_ptr<IArkPlayerMimic>& _pMimic)>(0x13211C0);
};

