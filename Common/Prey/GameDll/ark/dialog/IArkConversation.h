// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

class IArkConversationListener;
class IArkSpeaker;

// Prey/GameDll/ark/dialog/IArkConversation.h
class IArkConversation // Id=80019D8 Size=8
{
public:
	virtual void AddSpeaker(IArkSpeaker *arg0) = 0;
	virtual void AddListener(IArkConversationListener *const arg0) = 0;
	virtual void RemoveListener(IArkConversationListener *const arg0) = 0;
	virtual uint64_t GetConversationId() const = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class IArkConversationListener;
class IArkSpeaker;

// IArkConversation
// Header:  Prey/GameDll/ark/dialog/IArkConversation.h
class IArkConversation
{ // Size=8 (0x8)
public:
	virtual void AddSpeaker(IArkSpeaker* _pSpeaker) = 0;
	virtual void AddListener(IArkConversationListener* const _pListener) = 0;
	virtual void RemoveListener(IArkConversationListener* const _pListener) = 0;
	virtual uint64_t GetConversationId() const = 0;
};
#endif // !MOONCRASH
