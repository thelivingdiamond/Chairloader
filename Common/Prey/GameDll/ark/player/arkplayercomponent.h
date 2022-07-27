// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/player/arkplayercomponent.h
class ClimbPosInfo // Id=80173E6 Size=16
{
public:
	Vec3 m_point;
	EStance m_stance;
	
	ClimbPosInfo(Vec3 _point, EStance _stance);
	Vec3 GetPoint() const { return FGetPoint(this); }
	EStance GetStance() const { return FGetStance(this); }
	
	static inline auto FGetPoint = PreyFunction<Vec3(ClimbPosInfo const *const _this)>(0x155AD70);
	static inline auto FGetStance = PreyFunction<EStance(ClimbPosInfo const *const _this)>(0x1A4D090);
};

