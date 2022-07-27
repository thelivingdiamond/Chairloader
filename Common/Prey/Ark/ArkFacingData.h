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
	
	Vec3 GetDirection(Vec3 const &_curPos) { return FGetDirection(this,_curPos); }
	
	static inline auto FGetDirection = PreyFunction<Vec3(ArkFacingData *const _this, Vec3 const &_curPos)>(0x5F27C0);
};

