// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

class ArkDialogAudioTrigger;

// Prey/GameDll/ark/dialog/IArkDialogAudioTriggerOwner.h
class IArkDialogAudioTriggerOwner // Id=80020DD Size=8
{
public:
	virtual void OnTriggerLoaded(ArkDialogAudioTrigger const *arg0, bool arg1) = 0;
	virtual void OnTriggerCutoff(ArkDialogAudioTrigger const *arg0) = 0;
	virtual void OnTriggerFinished(ArkDialogAudioTrigger const *arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkDialogAudioTrigger;

// IArkDialogAudioTriggerOwner
// Header:  Prey/GameDll/ark/dialog/IArkDialogAudioTriggerOwner.h
class IArkDialogAudioTriggerOwner
{ // Size=8 (0x8)
public:
	virtual void OnTriggerLoaded(const ArkDialogAudioTrigger* _pTrigger, bool _bSuccess) = 0;
	virtual void OnTriggerCutoff(const ArkDialogAudioTrigger* _pTrigger) = 0;
	virtual void OnTriggerFinished(const ArkDialogAudioTrigger* _pTrigger) = 0;
};
#endif // !MOONCRASH
