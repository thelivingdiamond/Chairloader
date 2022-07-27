// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLiftVolumeEntity.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerLiftEntity.h>

class ArkPsiLift;
class ArkPsiPowerLiftUniqueProperties;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerLiftEntity.h
class ArkPlayerLiftEntity // Id=80141B4 Size=16
{
public:
	ArkSimpleTimer m_destroyGooTimer;
	float m_inwardLiftForce;
	float m_upwardLiftForce;
	
	ArkPlayerLiftEntity();
	ArkPlayerLiftEntity(const float _inwardLiftForce, const float _upwardLiftForce);
	void EnterLiftVolume(IEntity const &_entity) const { FEnterLiftVolume(this,_entity); }
	void ExitLiftVolume(IEntity const &_entity) const { FExitLiftVolume(this,_entity); }
	void Update(IEntity const &_entity, ArkPsiLift const &_lift, const float _frameTime) const { FUpdate(this,_entity,_lift,_frameTime); }
	void PostSerialize(IEntity const &_entity) const { FPostSerialize(this,_entity); }
	
	static inline auto FEnterLiftVolume = PreyFunction<void(ArkPlayerLiftEntity const *const _this, IEntity const &_entity)>(0x130E920);
	static inline auto FExitLiftVolume = PreyFunction<void(ArkPlayerLiftEntity const *const _this, IEntity const &_entity)>(0x130E9F0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerLiftEntity const *const _this, IEntity const &_entity, ArkPsiLift const &_lift, const float _frameTime)>(0x130EC30);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerLiftEntity const *const _this, IEntity const &_entity)>(0x130EAB0);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkplayerliftentity.h
class ArkPlayerLiftEntitySpawner // Id=801B7AA Size=8
{
public:
	ArkPsiPowerLiftUniqueProperties const &m_properties;
	
	ArkPlayerLiftEntitySpawner();
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity> Spawn(const unsigned _entityId) const { return FSpawn(this,_entityId); }
	
	static inline auto FSpawn = PreyFunction<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>(ArkPlayerLiftEntitySpawner const *const _this, const unsigned _entityId)>(0x130EAE0);
};

