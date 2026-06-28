// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/perception/ArkGameNoiseInfo.h>

// Header: FromCpp
// Prey/GameDll/ark/perception/ArkSimpleAuralPerceptionInfo.h
struct ArkSimpleAuralPerceptionInfo // Id=801430F Size=32
{
	unsigned m_noiseMakerEntityId;
	ArkGameNoiseInfo m_noiseInfo;
	
	ArkSimpleAuralPerceptionInfo(unsigned _noiseMakerEntityId, ArkGameNoiseInfo const &_noiseInfo);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/perception/ArkGameNoiseInfo.h>

// ArkSimpleAuralPerceptionInfo
// Header:  Prey/GameDll/ark/perception/ArkSimpleAuralPerceptionInfo.h
struct ArkSimpleAuralPerceptionInfo
{ // Size=32 (0x20)
	unsigned m_noiseMakerEntityId;
	ArkGameNoiseInfo m_noiseInfo;

	ArkSimpleAuralPerceptionInfo(unsigned _noiseMakerEntityId, const ArkGameNoiseInfo& _noiseInfo);

	static inline auto FArkSimpleAuralPerceptionInfoOv2 = PreyFunction<void(ArkSimpleAuralPerceptionInfo* const _this, unsigned _noiseMakerEntityId, const ArkGameNoiseInfo& _noiseInfo)>(0x135AC70);
};
#endif // !MOONCRASH
