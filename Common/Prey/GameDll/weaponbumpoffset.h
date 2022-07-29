// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/weaponbumpoffset.h
class CBumpOffset // Id=8016D2A Size=44
{
public:
	QuatT m_direction;
	float m_attackTime;
	float m_releaseTime;
	float m_rebounceIntensity;
	float m_time;
	
	CBumpOffset();
	QuatT Compute(float frameTime) { return FCompute(this,frameTime); }
	void AddBump(QuatT direction, float attackTime, float releaseTime, float reboundIntensity) { FAddBump(this,direction,attackTime,releaseTime,reboundIntensity); }
	QuatT ComputeBump(float frameTime) { return FComputeBump(this,frameTime); }
	
	static inline auto FCompute = PreyFunction<QuatT(CBumpOffset *const _this, float frameTime)>(0x1801250);
	static inline auto FAddBump = PreyFunction<void(CBumpOffset *const _this, QuatT direction, float attackTime, float releaseTime, float reboundIntensity)>(0x1801200);
	static inline auto FComputeBump = PreyFunction<QuatT(CBumpOffset *const _this, float frameTime)>(0x18012E0);
};

