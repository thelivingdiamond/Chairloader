// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

class CArkGravShaftEntity;

// Header: Override
// Prey/GameDll/ark/iface/IArkGravShaftListener.h
class IArkGravShaftListener // Id=801550A Size=8
{
public:
	virtual void OnEnter(CArkGravShaftEntity const &arg0, const unsigned arg1);
	virtual void OnExit(CArkGravShaftEntity const &arg0, const unsigned arg1);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CArkGravShaftEntity;

// IArkGravShaftListener
// Header:  Prey/GameDll/ark/iface/IArkGravShaftListener.h
class IArkGravShaftListener
{ // Size=8 (0x8)
public:
	virtual void OnEnter(const CArkGravShaftEntity& _arg0_, const unsigned _arg1_);
	virtual void OnExit(const CArkGravShaftEntity& _arg0_, const unsigned _arg1_);
};
#endif // !MOONCRASH
