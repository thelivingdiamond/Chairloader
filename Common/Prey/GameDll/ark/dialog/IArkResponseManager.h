// Header file automatically created from a PDB.

#pragma once

class IArkConversation;
class IArkDialogAudioManager;
class IArkSpeaker;
struct SConversationParams;

// Prey/GameDll/ark/dialog/IArkResponseManager.h
class IArkResponseManager // Id=80020C8 Size=8
{
public:
	virtual uint64_t ResolveAbstractVoiceIdByPlayerSex(uint64_t arg0) const = 0;
	virtual IArkConversation *StartConversation(IArkSpeaker *arg0, uint64_t arg1, SConversationParams &arg2) = 0;
	virtual void EndConversation(IArkConversation *arg0, bool arg1) = 0;
	virtual void SetRuleDebug(uint64_t arg0, bool arg1) = 0;
	virtual bool GetRuleDebug(uint64_t arg0) const = 0;
	virtual void SaveDebugRules() const = 0;
	virtual void ClearDebugRules() = 0;
	virtual uint64_t GetNextConversationId() = 0;
	virtual IArkDialogAudioManager &GetAudioManager() = 0;
};

