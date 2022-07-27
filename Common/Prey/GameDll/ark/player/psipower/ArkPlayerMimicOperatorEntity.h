// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>

struct IEntity;
struct IEntityArchetype;
struct IEntityClass;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicOperatorEntity.h
class ArkPlayerMimicOperatorEntity // Id=801B842 Size=4
{
public:
	unsigned m_entityId;
	
	ArkPlayerMimicOperatorEntity(IEntityArchetype const &_archetype, QuatT const &_worldTransform);
	ArkPlayerMimicOperatorEntity(const unsigned _entityId);
	~ArkPlayerMimicOperatorEntity() { FBitNotArkPlayerMimicOperatorEntity(this); }
	void Show(Vec3 const &_velocity) { FShow(this,_velocity); }
	bool IsVisible() const { return FIsVisible(this); }
	Vec3 GetSize() const { return FGetSize(this); }
	Vec3 GetPosition() const { return FGetPosition(this); }
	int GetHealth() const { return FGetHealth(this); }
	IEntityClass const *GetClass() const { return FGetClass(this); }
	void PostSerialize() const { FPostSerialize(this); }
	static OOB ComputeInitialWorldBounds(IEntity const &_targetEntity) { return FComputeInitialWorldBounds(_targetEntity); }
	
#if 0
	unsigned GetEntityId() const;
	void Serialize(TSerialize arg0);
#endif
	
	static inline auto FBitNotArkPlayerMimicOperatorEntity = PreyFunction<void(ArkPlayerMimicOperatorEntity *const _this)>(0x131F580);
	static inline auto FShow = PreyFunction<void(ArkPlayerMimicOperatorEntity *const _this, Vec3 const &_velocity)>(0x131FB00);
	static inline auto FIsVisible = PreyFunction<bool(ArkPlayerMimicOperatorEntity const *const _this)>(0x131FA90);
	static inline auto FGetSize = PreyFunction<Vec3(ArkPlayerMimicOperatorEntity const *const _this)>(0x131FA70);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkPlayerMimicOperatorEntity const *const _this)>(0x131FA00);
	static inline auto FGetHealth = PreyFunction<int(ArkPlayerMimicOperatorEntity const *const _this)>(0x131F8D0);
	static inline auto FGetClass = PreyFunction<IEntityClass const *(ArkPlayerMimicOperatorEntity const *const _this)>(0x131F8A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerMimicOperatorEntity const *const _this)>(0x131FAD0);
	static inline auto FComputeInitialWorldBounds = PreyFunction<OOB(IEntity const &_targetEntity)>(0x131F5A0);
};

