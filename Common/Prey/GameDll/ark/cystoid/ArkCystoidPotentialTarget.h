// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Prey/GameDll/ark/cystoid/ArkCystoidPotentialTarget.h
class ArkCystoidPotentialTarget // Id=801541F Size=8
{
public:
	unsigned m_target;
	bool m_bProcessed;
	
#if 0
	void Serialize(TSerialize arg0);
	bool operator==(const unsigned arg0) const;
	void SetProcessed();
	unsigned GetTarget() const;
	bool IsProcessed() const;
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkCystoidPotentialTarget
// Header:  Prey/GameDll/ark/cystoid/ArkCystoidPotentialTarget.h
class ArkCystoidPotentialTarget
{ // Size=8 (0x8)
public:
	unsigned m_target;
	bool m_bProcessed;

#if 0
	ArkCystoidPotentialTarget();
	ArkCystoidPotentialTarget(const unsigned _arg0_);
	ArkCystoidPotentialTarget(const unsigned _arg0_, const bool _arg1_);
	void Serialize(TSerialize _arg0_);
	bool operator==(const unsigned _arg0_) const;
	void SetProcessed();
	unsigned GetTarget() const;
	bool IsProcessed() const;
#endif
};
#endif // !MOONCRASH
