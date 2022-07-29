// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>

struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicSpawner.h
class ArkPlayerMimicSpawner // Id=801B6B8 Size=1
{
public:
	static OOB ComputeInitialWorldBounds(IEntity const &_targetEntity) { return FComputeInitialWorldBounds(_targetEntity); }
	static const char *GetSurrogateArchetype(IEntity const &_entity) { return FGetSurrogateArchetype(_entity); }
	static std::unique_ptr<IArkPlayerMimic> Spawn(IEntity const &_targetEntity, QuatT const &_worldTransform) { return FSpawnOv1(_targetEntity,_worldTransform); }
	static std::unique_ptr<IArkPlayerMimic> Spawn(const char *_pClassName, const unsigned _entityId) { return FSpawnOv0(_pClassName,_entityId); }
	static void Serialize(TSerialize _ser, std::unique_ptr<IArkPlayerMimic> &_pMimic) { FSerialize(_ser,_pMimic); }
	
	static inline auto FComputeInitialWorldBounds = PreyFunction<OOB(IEntity const &_targetEntity)>(0x1320280);
	static inline auto FGetSurrogateArchetype = PreyFunction<const char *(IEntity const &_entity)>(0x1320830);
	static inline auto FSpawnOv1 = PreyFunction<std::unique_ptr<IArkPlayerMimic>(IEntity const &_targetEntity, QuatT const &_worldTransform)>(0x1321A70);
	static inline auto FSpawnOv0 = PreyFunction<std::unique_ptr<IArkPlayerMimic>(const char *_pClassName, const unsigned _entityId)>(0x1321700);
	static inline auto FSerialize = PreyFunction<void(TSerialize _ser, std::unique_ptr<IArkPlayerMimic> &_pMimic)>(0x13211C0);
};

