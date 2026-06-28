// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkSimpleHearingInput.h
struct ArkSimpleHearingInput // Id=801A8E8 Size=16
{
	unsigned m_noiseMakerEntityId;
	uint64_t m_noiseTypeId;
	
	ArkSimpleHearingInput();
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkSimpleHearingInput
// Header:  Prey/GameDll/ark/attention/ArkSimpleHearingInput.h
struct ArkSimpleHearingInput
{ // Size=16 (0x10)
	unsigned m_noiseMakerEntityId;
	uint64_t m_noiseTypeId;

	ArkSimpleHearingInput();

#if 0
	ArkSimpleHearingInput(unsigned _arg0_, uint64_t _arg1_);
#endif

	static inline auto FArkSimpleHearingInputOv1 = PreyFunction<void(ArkSimpleHearingInput* const _this)>(0x12FD660);
};
#endif // !MOONCRASH
