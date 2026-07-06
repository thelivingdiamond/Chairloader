// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/perception/ArkComplexVisualPerceptionInfo.h
struct ArkComplexVisualPerceptionInfo // Id=8014314 Size=8
{
	unsigned m_perceivableEntityId;
	float m_magnitude;
	
	ArkComplexVisualPerceptionInfo(unsigned _perceivableEntityId, float _magnitude);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkComplexVisualPerceptionInfo
// Header:  Prey/GameDll/ark/perception/ArkComplexVisualPerceptionInfo.h
struct ArkComplexVisualPerceptionInfo
{ // Size=8 (0x8)
	unsigned m_perceivableEntityId;
	float m_magnitude;

	ArkComplexVisualPerceptionInfo(unsigned _perceivableEntityId, float _magnitude);

	static inline auto FArkComplexVisualPerceptionInfo = PreyFunction<void(ArkComplexVisualPerceptionInfo* const _this, unsigned _perceivableEntityId, float _magnitude)>(0x1648700);
};
#endif // !MOONCRASH
