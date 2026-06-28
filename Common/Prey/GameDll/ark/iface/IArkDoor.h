// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkDoor.h
class IArkDoor // Id=8002088 Size=8
{
public:
	virtual bool IsOpen() const = 0;
	virtual bool IsOpening() const = 0;
	virtual void Open() = 0;
	virtual void OpenResetTimer() = 0;
	virtual bool WaitToUse(unsigned arg0) const = 0;
	virtual void SetUsing(unsigned arg0, bool arg1) = 0;
	virtual bool IsDoorGlooed() const = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkDoor
// Header:  Prey/GameDll/ark/iface/IArkDoor.h
class IArkDoor
{ // Size=8 (0x8)
public:
	virtual bool IsOpen() const = 0;
	virtual bool IsOpening() const = 0;
	virtual void Open() = 0;
	virtual void OpenResetTimer() = 0;
	virtual bool WaitToUse(unsigned _id) const = 0;
	virtual void SetUsing(unsigned _id, bool _bUsing) = 0;
	virtual bool IsDoorGlooed() const = 0;
};
#endif // !MOONCRASH
