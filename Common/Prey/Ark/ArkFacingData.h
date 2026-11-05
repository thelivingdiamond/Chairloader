// Header file automatically created from a PDB.

#pragma once

// Header: Exact
// Prey/Ark/ArkFacingData.h
struct ArkFacingData // Id=800222A Size=44
{
	enum class Type
	{
		Position = 0,
		Direction = 1,
		Entity = 2,
	};

	ArkFacingData::Type type;
	Vec3 target;
	unsigned targetEntityId;
	bool bHasAlignConstraint;
	ArkFacingData::Type alignType;
	Vec3 alignTarget;
	unsigned alignEntityId;
	
#ifndef MOONCRASH
	Vec3 GetDirection(Vec3 const &_curPos) { return FGetDirection(this,_curPos); }
#else
	Vec3 GetDirection(const Vec3& _curPos) { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetDirection(this, reinterpret_cast<Vec3*>(_return_buf_), _curPos); }
#endif
	
#ifndef MOONCRASH
	static inline auto FGetDirection = PreyFunction<Vec3(ArkFacingData *const _this, Vec3 const &_curPos)>(0x5F27C0);
#else
	static inline auto FGetDirection = PreyFunction<Vec3*(ArkFacingData* const _this, Vec3* _return_value_, const Vec3& _curPos)>(0x60D190);
#endif
};
