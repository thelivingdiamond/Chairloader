// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>

struct IEntity;
struct IEntityClass;

// ArkPlayerMimicTurretEntity
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretEntity.h
class ArkPlayerMimicTurretEntity
{ // Size=4 (0x4)
public:
	unsigned m_entityId;

	ArkPlayerMimicTurretEntity(const IEntity& _targetEntity, const QuatT& _worldTransform);
	ArkPlayerMimicTurretEntity(const unsigned _entityId);
	~ArkPlayerMimicTurretEntity();
	void Show(const Vec3& _velocity) { FShow(this, _velocity); }
	bool IsVisible() const { return FIsVisible(this); }
	Vec3 GetSize() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetSize(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	int GetHealth() const { return FGetHealth(this); }
	const IEntityClass* GetClass() const { return FGetClass(this); }
	static OBB ComputeInitialWorldBounds(const IEntity& _targetEntity) { return FComputeInitialWorldBounds(_targetEntity); }

#if 0
	unsigned GetEntityId() const;
	void Serialize(TSerialize _arg0_);
	void PostSerialize() const;
#endif

	static inline auto FArkPlayerMimicTurretEntityOv1 = PreyFunction<void(ArkPlayerMimicTurretEntity* const _this, const IEntity& _targetEntity, const QuatT& _worldTransform)>(0x1323C00);
	static inline auto FArkPlayerMimicTurretEntityOv0 = PreyFunction<void(ArkPlayerMimicTurretEntity* const _this, const unsigned _entityId)>(0x1323C80);
	static inline auto FBitNotArkPlayerMimicTurretEntity = PreyFunction<void(ArkPlayerMimicTurretEntity* const _this)>(0x131F580);
	static inline auto FShow = PreyFunction<void(ArkPlayerMimicTurretEntity* const _this, const Vec3& _velocity)>(0x1324160);
	static inline auto FIsVisible = PreyFunction<bool(const ArkPlayerMimicTurretEntity* const _this)>(0x131FA90);
	static inline auto FGetSize = PreyFunction<Vec3*(const ArkPlayerMimicTurretEntity* const _this, Vec3* _return_value_)>(0x1324140);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkPlayerMimicTurretEntity* const _this, Vec3* _return_value_)>(0x1324100);
	static inline auto FGetHealth = PreyFunction<int(const ArkPlayerMimicTurretEntity* const _this)>(0x1324080);
	static inline auto FGetClass = PreyFunction<const IEntityClass* (const ArkPlayerMimicTurretEntity* const _this)>(0x131F8A0);
	static inline auto FComputeInitialWorldBounds = PreyFunction<OBB(const IEntity& _targetEntity)>(0x1323CC0);
};

