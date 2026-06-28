// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkSimpleVisionInput.h
struct ArkSimpleVisionInput // Id=80195E4 Size=8
{
	unsigned m_entityId;
	bool m_bSighted;
	
	ArkSimpleVisionInput();
	ArkSimpleVisionInput(ArkSimpleVisionInput const &_other);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkSimpleVisionInput
// Header:  Prey/GameDll/ark/attention/ArkSimpleVisionInput.h
struct ArkSimpleVisionInput
{ // Size=8 (0x8)
	unsigned m_entityId;
	bool m_bSighted;

	ArkSimpleVisionInput();
	ArkSimpleVisionInput(const ArkSimpleVisionInput& _other);

#if 0
	ArkSimpleVisionInput(unsigned _arg0_, bool _arg1_);
#endif

	static inline auto FArkSimpleVisionInputOv2 = PreyFunction<void(ArkSimpleVisionInput* const _this)>(0x1508450);
	static inline auto FArkSimpleVisionInputOv0 = PreyFunction<void(ArkSimpleVisionInput* const _this, const ArkSimpleVisionInput& _other)>(0x1508440);
};
#endif // !MOONCRASH
