// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/spatial/ArkSpatiallySortedEntity.h
class ArkSpatiallySortedEntity // Id=8016199 Size=8
{
public:
	IEntity const *m_pEntity;
	
	ArkSpatiallySortedEntity();
	ArkSpatiallySortedEntity(IEntity const &_entity);
	IEntity const *GetEntity() const { return FGetEntity(this); }
	bool IsValid() const { return FIsValid(this); }
	Vec3 GetPosition() const { return FGetPosition(this); }
	
	static inline auto FGetEntity = PreyFunction<IEntity const *(ArkSpatiallySortedEntity const *const _this)>(0x12E5E70);
	static inline auto FIsValid = PreyFunction<bool(ArkSpatiallySortedEntity const *const _this)>(0x12F72B0);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkSpatiallySortedEntity const *const _this)>(0x13368C0);
};

