// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Prey/GameDll/ark/dialog/IArkDialogPlayerExtension.h
class IArkDialogPlayerExtension // Id=80141D8 Size=8
{
public:
	virtual void OnDialogStart(uint64_t arg0) = 0;
	virtual void OnDialogEnd(uint64_t arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkDialogPlayerExtension
// Header:  Prey/GameDll/ark/dialog/IArkDialogPlayerExtension.h
class IArkDialogPlayerExtension
{ // Size=8 (0x8)
public:
	virtual void OnDialogStart(uint64_t _dialogId) = 0;
	virtual void OnDialogEnd(uint64_t _dialogId) = 0;
};
#endif // !MOONCRASH
