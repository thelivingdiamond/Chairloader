// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class IArkConversation;
class IArkDialogAudioManager;
class IArkSpeaker;
struct SConversationParams;

// IArkResponseManager
// Header:  Prey/GameDll/ark/dialog/IArkResponseManager.h
class IArkResponseManager
{ // Size=8 (0x8)
public:
	virtual uint64_t ResolveAbstractVoiceIdByPlayerSex(uint64_t _voiceId) const = 0;
	virtual IArkConversation* StartConversation(IArkSpeaker* _pSpeaker, uint64_t _conversationId, SConversationParams& _params) = 0;
	virtual void EndConversation(IArkConversation* _pConversation, bool _bComplete) = 0;
	virtual void SetRuleDebug(uint64_t _ruleId, bool _bEnable) = 0;
	virtual bool GetRuleDebug(uint64_t _ruleId) const = 0;
	virtual void SaveDebugRules() const = 0;
	virtual void ClearDebugRules() = 0;
	virtual uint64_t GetNextConversationId() = 0;
	virtual IArkDialogAudioManager& GetAudioManager() = 0;
};
#endif // !MOONCRASH
