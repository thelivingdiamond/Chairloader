// Header file automatically created from a PDB.

#pragma once

class IArkConversation;
struct SDialogParams;

// Prey/GameDll/ark/dialog/IArkSpeaker.h
class IArkSpeaker // Id=80019D9 Size=8
{
public:
	virtual bool PlayDialog(SDialogParams &arg0) = 0;
	virtual const char *GetName() const = 0;
	virtual IArkConversation const *GetConversation() const = 0;
	virtual void Stop(bool arg0, bool arg1) = 0;
};

