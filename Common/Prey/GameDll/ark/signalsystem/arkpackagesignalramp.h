// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CrySystem/TimeValue.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

namespace ArkSignalSystem
{

// Header: Override
// Prey/GameDll/ark/signalsystem/ArkPackageSignalRamp.h
struct PackageSignalRamp // Id=8013724 Size=48
{
	const float m_ramp;
	const int m_maxRepeatCount;
	const float m_increaseTime;
	const float m_decreaseTime;
	const int m_decreaseCount;
	int m_repeatCount;
	float m_leftoverInterval;
	CTimeValue m_lastReceiveTime;
	CTimeValue m_lastIncrementTime;
	
#if 0
	void Reset();
	float CalculateRamp(ArkSignalSystem::Package const &arg0);
#endif
};

} // namespace ArkSignalSystem

namespace ArkSignalSystem
{

// Header: Override
// Prey/GameDll/ark/signalsystem/ArkPackageSignalRamp.h
class PackageSignalRampContainer // Id=8013723 Size=64
{
public:
	std::unordered_map<unsigned __int64,ArkSignalSystem::PackageSignalRamp> m_packageSignalRamps;
	
	void AddRamp(uint64_t _id, ArkSignalSystem::PackageSignalRamp _ramp) { FAddRamp(this,_id,_ramp); }
	void Reset() { FReset(this); }
	bool CalculateRamp(ArkSignalSystem::Package const &_package, float &_outScale) { return FCalculateRamp(this,_package,_outScale); }
	
	static inline auto FAddRamp = PreyFunction<void(ArkSignalSystem::PackageSignalRampContainer *const _this, uint64_t _id, ArkSignalSystem::PackageSignalRamp _ramp)>(0x1336180);
	static inline auto FReset = PreyFunction<void(ArkSignalSystem::PackageSignalRampContainer *const _this)>(0x13364E0);
	static inline auto FCalculateRamp = PreyFunction<bool(ArkSignalSystem::PackageSignalRampContainer *const _this, ArkSignalSystem::Package const &_package, float &_outScale)>(0x1336280);
};

} // namespace ArkSignalSystem
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/TimeValue.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

namespace ArkSignalSystem
{

// ArkSignalSystem::PackageSignalRamp
// Header:  Prey/GameDll/ark/signalsystem/ArkPackageSignalRamp.h
struct PackageSignalRamp
{ // Size=48 (0x30)
	const float m_ramp;
	const int m_maxRepeatCount;
	const float m_increaseTime;
	const float m_decreaseTime;
	const int m_decreaseCount;
	int m_repeatCount;
	float m_leftoverInterval;
	CTimeValue m_lastReceiveTime;
	CTimeValue m_lastIncrementTime;

#if 0
	PackageSignalRamp(float _arg0_, int _arg1_, float _arg2_, float _arg3_, int _arg4_);
	void Reset();
	float CalculateRamp(const ArkSignalSystem::Package& _arg0_);
#endif
};

// ArkSignalSystem::PackageSignalRampContainer
// Header:  Prey/GameDll/ark/signalsystem/ArkPackageSignalRamp.h
class PackageSignalRampContainer
{ // Size=64 (0x40)
public:
	std::unordered_map<uint64_t, ArkSignalSystem::PackageSignalRamp> m_packageSignalRamps;

	void AddRamp(uint64_t _id, ArkSignalSystem::PackageSignalRamp _ramp) { FAddRamp(this, _id, _ramp); }
	void Reset() { FReset(this); }
	bool CalculateRamp(const ArkSignalSystem::Package& _package, float& _outScale) { return FCalculateRamp(this, _package, _outScale); }

	static inline auto FAddRamp = PreyFunction<void(ArkSignalSystem::PackageSignalRampContainer* const _this, uint64_t _id, ArkSignalSystem::PackageSignalRamp _ramp)>(0x1411D10);
	static inline auto FReset = PreyFunction<void(ArkSignalSystem::PackageSignalRampContainer* const _this)>(0x1412070);
	static inline auto FCalculateRamp = PreyFunction<bool(ArkSignalSystem::PackageSignalRampContainer* const _this, const ArkSignalSystem::Package& _package, float& _outScale)>(0x1411E10);
};


} // namespace ArkSignalSystem
#endif // !MOONCRASH
