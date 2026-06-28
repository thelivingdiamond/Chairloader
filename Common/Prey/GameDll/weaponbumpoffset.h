// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// CBumpOffset
// Header:  Prey/GameDll/weaponbumpoffset.h
class CBumpOffset
{ // Size=44 (0x2C)
public:
	QuatT m_direction;
	float m_attackTime;
	float m_releaseTime;
	float m_rebounceIntensity;
	float m_time;

	CBumpOffset();
	QuatT Compute(float frameTime) { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FCompute(this, reinterpret_cast<QuatT*>(_return_buf_), frameTime); }
	void AddBump(QuatT direction, float attackTime, float releaseTime, float reboundIntensity) { FAddBump(this, direction, attackTime, releaseTime, reboundIntensity); }
	QuatT ComputeBump(float frameTime) { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FComputeBump(this, reinterpret_cast<QuatT*>(_return_buf_), frameTime); }

	static inline auto FCBumpOffsetOv2 = PreyFunction<void(CBumpOffset* const _this)>(0x1928CD0);
	static inline auto FCompute = PreyFunction<QuatT*(CBumpOffset* const _this, QuatT* _return_value_, float frameTime)>(0x1928D50);
	static inline auto FAddBump = PreyFunction<void(CBumpOffset* const _this, QuatT direction, float attackTime, float releaseTime, float reboundIntensity)>(0x1928D00);
	static inline auto FComputeBump = PreyFunction<QuatT*(CBumpOffset* const _this, QuatT* _return_value_, float frameTime)>(0x1928DE0);
};
#endif // !MOONCRASH
