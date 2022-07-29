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

