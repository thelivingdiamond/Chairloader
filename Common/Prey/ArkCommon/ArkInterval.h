// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

template <typename T>
struct ArkInterval // Id=801346D Size=8
{
	T minimum;
	T maximum;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once

// ArkInterval<float>
// Header:  Prey/ArkCommon/ArkInterval.h
struct ArkInterval<float>
{ // Size=8 (0x8)
	float minimum;
	float maximum;

#if 0
	ArkInterval<float>();
	ArkInterval<float>(float _arg0_, float _arg1_);
#endif
};
#endif // !MOONCRASH
