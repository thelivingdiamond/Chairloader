// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/perception/ArkGameNoiseInfo.h>

// Header: FromCpp
// Prey/GameDll/ark/perception/ArkComplexAuralPerceptionInfo.h
struct ArkComplexAuralPerceptionInfo // Id=8014311 Size=48
{
	unsigned m_noiseMakerEntityId;
	ArkGameNoiseInfo m_noiseInfo;
	float m_magnitude;
	Vec3 m_noisePosition;
	
	ArkComplexAuralPerceptionInfo(unsigned _noiseMakerEntityId, ArkGameNoiseInfo const &_noiseInfo, float _magnitude, Vec3 const &_noisePosition);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/perception/ArkGameNoiseInfo.h>

// ArkComplexAuralPerceptionInfo
// Header:  Prey/GameDll/ark/perception/ArkComplexAuralPerceptionInfo.h
struct ArkComplexAuralPerceptionInfo
{ // Size=48 (0x30)
	unsigned m_noiseMakerEntityId;
	unsigned m_noiseEmitterEntityId;
	ArkGameNoiseInfo m_noiseInfo;
	float m_magnitude;
	Vec3 m_noisePosition;

	ArkComplexAuralPerceptionInfo(unsigned _noiseMakerEntityId, unsigned _noiseEmitterEntityId, const ArkGameNoiseInfo& _noiseInfo, float _magnitude, const Vec3& _noisePosition);

	static inline auto FArkComplexAuralPerceptionInfoOv2 = PreyFunction<void(ArkComplexAuralPerceptionInfo* const _this, unsigned _noiseMakerEntityId, unsigned _noiseEmitterEntityId, const ArkGameNoiseInfo& _noiseInfo, float _magnitude, const Vec3& _noisePosition)>(0x1571020);
};
#endif // !MOONCRASH
