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

