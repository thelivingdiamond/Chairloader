// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLiftVolumeEntity.h>

class ArkPsiLift;
class ArkPsiPowerLiftUniqueProperties;
struct IEntity;

// ArkPlayerLiftEntity
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerLiftEntity.h
class ArkPlayerLiftEntity
{ // Size=16 (0x10)
public:
	ArkSimpleTimer m_destroyGooTimer;
	float m_inwardLiftForce;
	float m_upwardLiftForce;

	ArkPlayerLiftEntity();
	ArkPlayerLiftEntity(const float _inwardLiftForce, const float _upwardLiftForce);
	void EnterLiftVolume(const IEntity& _entity) const { FEnterLiftVolume(this, _entity); }
	void ExitLiftVolume(const IEntity& _entity) const { FExitLiftVolume(this, _entity); }
	void Update(const IEntity& _entity, const ArkPsiLift& _lift, const float _frameTime) const { FUpdate(this, _entity, _lift, _frameTime); }
	void PostSerialize(const IEntity& _entity) const { FPostSerialize(this, _entity); }

	static inline auto FArkPlayerLiftEntityOv1 = PreyFunction<void(ArkPlayerLiftEntity* const _this)>(0x130E8D0);
	static inline auto FArkPlayerLiftEntityOv0 = PreyFunction<void(ArkPlayerLiftEntity* const _this, const float _inwardLiftForce, const float _upwardLiftForce)>(0x130E890);
	static inline auto FEnterLiftVolume = PreyFunction<void(const ArkPlayerLiftEntity* const _this, const IEntity& _entity)>(0x130E920);
	static inline auto FExitLiftVolume = PreyFunction<void(const ArkPlayerLiftEntity* const _this, const IEntity& _entity)>(0x130E9F0);
	static inline auto FUpdate = PreyFunction<void(const ArkPlayerLiftEntity* const _this, const IEntity& _entity, const ArkPsiLift& _lift, const float _frameTime)>(0x130EC30);
	static inline auto FPostSerialize = PreyFunction<void(const ArkPlayerLiftEntity* const _this, const IEntity& _entity)>(0x130EAB0);
};

// ArkPlayerLiftEntitySpawner
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerLiftEntity.h
class ArkPlayerLiftEntitySpawner
{ // Size=8 (0x8)
public:
	const ArkPsiPowerLiftUniqueProperties& m_properties;

	ArkPlayerLiftEntitySpawner();
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity> Spawn(const unsigned _entityId) const { alignas(ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>) std::byte _return_buf_[sizeof(ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>)]; return *FSpawn(this, reinterpret_cast<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>*>(_return_buf_), _entityId); }

	static inline auto FArkPlayerLiftEntitySpawner = PreyFunction<void(ArkPlayerLiftEntitySpawner* const _this)>(0x130E8F0);
	static inline auto FSpawn = PreyFunction<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>*(const ArkPlayerLiftEntitySpawner* const _this, ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>* _return_value_, const unsigned _entityId)>(0x130EAE0);
};

