// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkComplexRoomInput.h
struct ArkComplexRoomInput // Id=801A8E7 Size=12
{
	unsigned m_entityId;
	float m_magnitude;
	bool m_bStart;
	bool m_bSameAreaContainer;
	
	ArkComplexRoomInput();
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkComplexRoomInput
// Header:  Prey/GameDll/ark/attention/ArkComplexRoomInput.h
struct ArkComplexRoomInput
{ // Size=12 (0xC)
	unsigned m_entityId;
	float m_magnitude;
	bool m_bStart;
	bool m_bSameAreaContainer;

	ArkComplexRoomInput();

#if 0
	ArkComplexRoomInput(unsigned _arg0_, float _arg1_, bool _arg2_, bool _arg3_);
#endif

	static inline auto FArkComplexRoomInputOv1 = PreyFunction<void(ArkComplexRoomInput* const _this)>(0x12FD1D0);
};
#endif // !MOONCRASH
