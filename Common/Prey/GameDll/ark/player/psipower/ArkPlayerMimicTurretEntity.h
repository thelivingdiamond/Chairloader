// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>

struct IEntity;
struct IEntityClass;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretEntity.h
class ArkPlayerMimicTurretEntity // Id=801B843 Size=4
{
public:
	unsigned m_entityId;
	
	ArkPlayerMimicTurretEntity(IEntity const &_targetEntity, QuatT const &_worldTransform);
	ArkPlayerMimicTurretEntity(const unsigned _entityId);
	~ArkPlayerMimicTurretEntity() { FBitNotArkPlayerMimicTurretEntity(this); }
	void Show(Vec3 const &_velocity) { FShow(this,_velocity); }
	bool IsVisible() const { return FIsVisible(this); }
	Vec3 GetSize() const { return FGetSize(this); }
	Vec3 GetPosition() const { return FGetPosition(this); }
	int GetHealth() const { return FGetHealth(this); }
	IEntityClass const *GetClass() const { return FGetClass(this); }
	static OOB ComputeInitialWorldBounds(IEntity const &_targetEntity) { return FComputeInitialWorldBounds(_targetEntity); }
	
#if 0
	unsigned GetEntityId() const;
	void Serialize(TSerialize arg0);
	void PostSerialize() const;
#endif
	
	static inline auto FBitNotArkPlayerMimicTurretEntity = PreyFunction<void(ArkPlayerMimicTurretEntity *const _this)>(0x131F580);
	static inline auto FShow = PreyFunction<void(ArkPlayerMimicTurretEntity *const _this, Vec3 const &_velocity)>(0x1324160);
	static inline auto FIsVisible = PreyFunction<bool(ArkPlayerMimicTurretEntity const *const _this)>(0x131FA90);
	static inline auto FGetSize = PreyFunction<Vec3(ArkPlayerMimicTurretEntity const *const _this)>(0x1324140);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkPlayerMimicTurretEntity const *const _this)>(0x1324100);
	static inline auto FGetHealth = PreyFunction<int(ArkPlayerMimicTurretEntity const *const _this)>(0x1324080);
	static inline auto FGetClass = PreyFunction<IEntityClass const *(ArkPlayerMimicTurretEntity const *const _this)>(0x131F8A0);
	static inline auto FComputeInitialWorldBounds = PreyFunction<OOB(IEntity const &_targetEntity)>(0x1323CC0);
};

