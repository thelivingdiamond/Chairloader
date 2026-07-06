// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

struct SDialogParams;

// Prey/GameDll/ark/dialog/IArkPADialogManager.h
class IArkPADialogManager // Id=80020BE Size=8
{
public:
	virtual void PlayDialog(uint8_t arg0, SDialogParams &arg1) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct SDialogParams;

// IArkPADialogManager
// Header:  Prey/GameDll/ark/dialog/IArkPADialogManager.h
class IArkPADialogManager
{ // Size=8 (0x8)
public:
	virtual void PlayDialog(uint8_t _channelId, SDialogParams& _params) = 0;

#if 0
	IArkPADialogManager();
	~IArkPADialogManager();
#endif
};
#endif // !MOONCRASH
