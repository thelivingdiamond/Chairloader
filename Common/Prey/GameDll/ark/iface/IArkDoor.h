// Header file automatically created from a PDB.

#pragma once

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

