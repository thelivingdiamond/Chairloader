// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/dialog/IArkConversationListener.h>
#include <Prey/GameDll/ark/dialog/arkflownodedialogtrigger.h>

class ArkConversation;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/pda/ArkLiveTranscribeComponent.h
class ArkLiveTranscribeComponent : public IArkConversationListener // Id=80172B1 Size=152
{
public:
	std::vector<unsigned __int64> m_queuedConversations;
	std::unordered_map<unsigned __int64,ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger> *> m_hookNodeMap;
	ArkConversation *m_pCurrentPlayingConversation;
	uint64_t m_currentConversationId;
	ArkSimpleTimer m_startNextTimer;
	ArkSimpleTimer m_ringTimer;
	ArkAudioTrigger m_startRingTrigger;
	ArkAudioTrigger m_answerCallTrigger;
	float m_timeSinceLastCall;
	bool m_bSilenced;
	float m_minTimeBetweenConversations;
	float m_maxTimeBetweenConversations;
	
	ArkLiveTranscribeComponent();
	virtual ~ArkLiveTranscribeComponent();
	void PlayConversation(ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger> &_transcribeNode, uint64_t _hookId, bool _bQueue, float _minTimeSinceLastCall) { FPlayConversation(this,_transcribeNode,_hookId,_bQueue,_minTimeSinceLastCall); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Reset() { FReset(this); }
	void LoadConfig(XmlNodeRef const &_config) { FLoadConfig(this,_config); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void SetConversationListener(ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger> &_node, uint64_t _hookId) { FSetConversationListener(this,_node,_hookId); }
	void ClearQueuedConversations() { FClearQueuedConversations(this); }
	virtual void OnConversationComplete(const bool _bComplete);
	void SetSilenced(bool _bSilenced) { FSetSilenced(this,_bSilenced); }
	void PlayIncomingCallSequence(bool _bResetTimer) { FPlayIncomingCallSequence(this,_bResetTimer); }
	void StopIncomingCallSequence() { FStopIncomingCallSequence(this); }
	void ResetNextCallTimer() { FResetNextCallTimer(this); }
	
#if 0
	bool IsPlaying() const;
	bool PlayConversationInternal(ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger> &arg0, uint64_t arg1);
#endif
	
	static inline auto FPlayConversation = PreyFunction<void(ArkLiveTranscribeComponent *const _this, ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger> &_transcribeNode, uint64_t _hookId, bool _bQueue, float _minTimeSinceLastCall)>(0x130D3D0);
	static inline auto FUpdate = PreyFunction<void(ArkLiveTranscribeComponent *const _this, float _frameTime)>(0x130DD90);
	static inline auto FReset = PreyFunction<void(ArkLiveTranscribeComponent *const _this)>(0x130D800);
	static inline auto FLoadConfig = PreyFunction<void(ArkLiveTranscribeComponent *const _this, XmlNodeRef const &_config)>(0x130D1A0);
	static inline auto FSerialize = PreyFunction<void(ArkLiveTranscribeComponent *const _this, TSerialize _ser)>(0x130D920);
	static inline auto FPostSerialize = PreyFunction<void(ArkLiveTranscribeComponent *const _this)>(0x130D780);
	static inline auto FSetConversationListener = PreyFunction<void(ArkLiveTranscribeComponent *const _this, ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger> &_node, uint64_t _hookId)>(0x130DBA0);
	static inline auto FClearQueuedConversations = PreyFunction<void(ArkLiveTranscribeComponent *const _this)>(0x130D000);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkLiveTranscribeComponent *const _this, const bool _bComplete)>(0x130D2E0);
	static inline auto FSetSilenced = PreyFunction<void(ArkLiveTranscribeComponent *const _this, bool _bSilenced)>(0x130DBF0);
	static inline auto FPlayIncomingCallSequence = PreyFunction<void(ArkLiveTranscribeComponent *const _this, bool _bResetTimer)>(0x130D570);
	static inline auto FStopIncomingCallSequence = PreyFunction<void(ArkLiveTranscribeComponent *const _this)>(0x130DC30);
	static inline auto FResetNextCallTimer = PreyFunction<void(ArkLiveTranscribeComponent *const _this)>(0x130D8C0);
};

