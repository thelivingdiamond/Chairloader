// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Prey/GameDll/ark/dialog/IArkConversationListener.h
class IArkConversationListener // Id=80019DC Size=8
{
public:
	virtual void OnConversationComplete(const bool arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkConversationListener
// Header:  Prey/GameDll/ark/dialog/IArkConversationListener.h
class IArkConversationListener
{ // Size=8 (0x8)
public:
	virtual void OnConversationComplete(const bool _bComplete) = 0;
};
#endif // !MOONCRASH
