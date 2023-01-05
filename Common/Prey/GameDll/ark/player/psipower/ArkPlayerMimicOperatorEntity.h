// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>

struct IEntity;
struct IEntityArchetype;
struct IEntityClass;

// ArkPlayerMimicOperatorEntity
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicOperatorEntity.h
class ArkPlayerMimicOperatorEntity
{ // Size=4 (0x4)
public:
	unsigned m_entityId;

	ArkPlayerMimicOperatorEntity(const IEntityArchetype& _archetype, const QuatT& _worldTransform);
	ArkPlayerMimicOperatorEntity(const unsigned _entityId);
	~ArkPlayerMimicOperatorEntity();
	void Show(const Vec3& _velocity) { FShow(this, _velocity); }
	bool IsVisible() const { return FIsVisible(this); }
	Vec3 GetSize() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetSize(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	int GetHealth() const { return FGetHealth(this); }
	const IEntityClass* GetClass() const { return FGetClass(this); }
	void PostSerialize() const { FPostSerialize(this); }
	static OBB ComputeInitialWorldBounds(const IEntity& _targetEntity) { return FComputeInitialWorldBounds(_targetEntity); }

#if 0
	unsigned GetEntityId() const;
	void Serialize(TSerialize _arg0_);
#endif

	static inline auto FArkPlayerMimicOperatorEntityOv1 = PreyFunction<void(ArkPlayerMimicOperatorEntity* const _this, const IEntityArchetype& _archetype, const QuatT& _worldTransform)>(0x131F4C0);
	static inline auto FArkPlayerMimicOperatorEntityOv0 = PreyFunction<void(ArkPlayerMimicOperatorEntity* const _this, const unsigned _entityId)>(0x1455D10);
	static inline auto FBitNotArkPlayerMimicOperatorEntity = PreyFunction<void(ArkPlayerMimicOperatorEntity* const _this)>(0x131F580);
	static inline auto FShow = PreyFunction<void(ArkPlayerMimicOperatorEntity* const _this, const Vec3& _velocity)>(0x131FB00);
	static inline auto FIsVisible = PreyFunction<bool(const ArkPlayerMimicOperatorEntity* const _this)>(0x131FA90);
	static inline auto FGetSize = PreyFunction<Vec3*(const ArkPlayerMimicOperatorEntity* const _this, Vec3* _return_value_)>(0x131FA70);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkPlayerMimicOperatorEntity* const _this, Vec3* _return_value_)>(0x131FA00);
	static inline auto FGetHealth = PreyFunction<int(const ArkPlayerMimicOperatorEntity* const _this)>(0x131F8D0);
	static inline auto FGetClass = PreyFunction<const IEntityClass* (const ArkPlayerMimicOperatorEntity* const _this)>(0x131F8A0);
	static inline auto FPostSerialize = PreyFunction<void(const ArkPlayerMimicOperatorEntity* const _this)>(0x131FAD0);
	static inline auto FComputeInitialWorldBounds = PreyFunction<OBB(const IEntity& _targetEntity)>(0x131F5A0);
};

