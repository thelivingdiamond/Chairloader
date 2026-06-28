// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

struct SHUDEvent;

// Header: Override
// Prey/GameDll/ark/ui/IHUDEventListener.h
struct IHUDEventListener // Id=8016E2A Size=8
{
	virtual ~IHUDEventListener();
	virtual void OnHUDEvent(SHUDEvent const &arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct SHUDEvent;

// IHUDEventListener
// Header:  Prey/GameDll/ark/ui/IHUDEventListener.h
struct IHUDEventListener
{ // Size=8 (0x8)
	virtual ~IHUDEventListener();
	virtual void OnHUDEvent(const SHUDEvent& _event) = 0;
};
#endif // !MOONCRASH
