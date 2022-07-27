// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLiftVolumeEntity.h>
#include <Prey/GameDll/ark/player/psipower/arkplayerliftentityzerog.h>

class ArkPsiLift;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerLiftEntityZeroG.h
class ArkPlayerLiftEntityZeroG // Id=8017575 Size=12
{
public:
	ArkSimpleTimer m_destroyGooTimer;
	float m_speed;
	
	ArkPlayerLiftEntityZeroG();
	void ExitLiftVolume(IEntity const &_entity) const { FExitLiftVolume(this,_entity); }
	void Update(IEntity const &_entity, ArkPsiLift const &_lift, const float _frameTime) const { FUpdate(this,_entity,_lift,_frameTime); }
	
#if 0
	void EnterLiftVolume(IEntity const &arg0) const;
	void PostSerialize(IEntity const &arg0) const;
#endif
	
	static inline auto FExitLiftVolume = PreyFunction<void(ArkPlayerLiftEntityZeroG const *const _this, IEntity const &_entity)>(0x130F090);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerLiftEntityZeroG const *const _this, IEntity const &_entity, ArkPsiLift const &_lift, const float _frameTime)>(0x130F1A0);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkplayerliftentityzerog.h
class ArkPlayerLiftEntityZeroGSpawner // Id=801B7AD Size=4
{
public:
	float m_speed;
	
	ArkPlayerLiftEntityZeroGSpawner();
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG> Spawn(const unsigned _entityId) const { return FSpawn(this,_entityId); }
	
	static inline auto FSpawn = PreyFunction<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>(ArkPlayerLiftEntityZeroGSpawner const *const _this, const unsigned _entityId)>(0x130F0E0);
};

