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

