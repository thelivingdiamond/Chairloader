// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IEntity;

// ArkSpatiallySortedEntity
// Header:  Prey/GameDll/ark/spatial/ArkSpatiallySortedEntity.h
class ArkSpatiallySortedEntity
{ // Size=8 (0x8)
public:
	const IEntity* m_pEntity;

	ArkSpatiallySortedEntity();
	ArkSpatiallySortedEntity(const IEntity& _entity);
	const IEntity* GetEntity() const { return FGetEntity(this); }
	bool IsValid() const { return FIsValid(this); }
	Vec3 GetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }

	static inline auto FArkSpatiallySortedEntityOv1 = PreyFunction<void(ArkSpatiallySortedEntity* const _this)>(0x12A2F50);
	static inline auto FArkSpatiallySortedEntityOv0 = PreyFunction<void(ArkSpatiallySortedEntity* const _this, const IEntity& _entity)>(0x14124F0);
	static inline auto FGetEntity = PreyFunction<const IEntity* (const ArkSpatiallySortedEntity* const _this)>(0x1112EA0);
	static inline auto FIsValid = PreyFunction<bool(const ArkSpatiallySortedEntity* const _this)>(0x13CA050);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkSpatiallySortedEntity* const _this, Vec3* _return_value_)>(0x1412450);
};
#endif // !MOONCRASH
