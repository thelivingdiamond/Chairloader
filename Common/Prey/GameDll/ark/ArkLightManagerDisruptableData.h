// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: Override
// Prey/GameDll/ark/ArkLightManagerDisruptableData.h
struct ArkLightManagerDisruptableData // Id=80141E1 Size=16
{
	float m_disruptAccumulation;
	float m_interferenceAccumulation;
	float m_sparkTimerTimeRemaining;
	bool m_bDisrupted;
	bool m_bInterfered;
	
#if 0
	void Serialize(TSerialize arg0);
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkLightManagerDisruptableData
// Header:  Prey/GameDll/ark/ArkLightManagerDisruptableData.h
struct ArkLightManagerDisruptableData
{ // Size=16 (0x10)
	float m_disruptAccumulation;
	float m_interferenceAccumulation;
	float m_sparkTimerTimeRemaining;
	bool m_bDisrupted;
	bool m_bInterfered;

#if 0
	ArkLightManagerDisruptableData();
	void Serialize(TSerialize _arg0_);
#endif
};
#endif // !MOONCRASH
