// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/dialog/IArkConversation.h>
#include <Prey/GameDll/ark/dialog/IArkSpeaker.h>
#include <Prey/GameDll/ark/dialog/SArkRuleQuery.h>

class ArkCharacter;
class ArkResponse;
class ArkResponseQuery;
class ArkResponseRule;
class IArkActiveUserManagerListener;
class IArkConversationListener;
struct IEntity;
struct SConversationParams;
struct SDialogParams;
class ArkSpeakerBase;
class ArkConversation;

// Header: Exact
// Prey/GameDll/ark/dialog/arkconversation.h
class ArkSpeakerBase : public IArkSpeaker // Id=801397D Size=240
{
public:
	std::vector<ArkSpeakerBase*> m_listeners;
	std::vector<ArkResponseFact> m_memory;
	std::unordered_map<unsigned __int64, float> m_usedResponses;
	std::vector<unsigned __int64> m_voices;

	using TMemoryTimeout = std::pair<unsigned __int64, float>;
	using TMemoryTimeouts = std::list<std::pair<unsigned __int64, float>, std::allocator<std::pair<unsigned __int64, float> > >;

	std::list<std::pair<unsigned __int64, float>, std::allocator<std::pair<unsigned __int64, float> > > m_timeouts;
	uint64_t m_voiceId;
	ArkCharacter const* m_pCharacter;
	ArkConversation* m_pCurrentConversation;
	ArkResponse const* m_pCurrentResponse;
	IEntity* m_pEntity;
	uint64_t m_conversationId;
	uint64_t m_playbackVoice;
	string m_playbackName;
	string m_playbackPortrait;
	bool m_bAudioDucked;

	ArkSpeakerBase();
	virtual ~ArkSpeakerBase();
	virtual void Update(float _frameTime);
	bool Speak(const char* _concept, ArkResponseQuery& _query, ArkConversation* const _pConversation) { return FSpeakOv2(this, _concept, _query, _pConversation); }
	bool Speak(const char* _conceptStr, uint64_t _conceptId, ArkResponseQuery& _query, ArkConversation* _pConversation) { return FSpeakOv0(this, _conceptStr, _conceptId, _query, _pConversation); }
	bool CanSpeak(const char* _concept, ArkResponseQuery& _query) const { return FCanSpeak(this, _concept, _query); }
	virtual void Stop(bool _bLoading, bool _bConversationComplete);
	void OnDialogComplete(uint64_t _dialogId, bool _bAudioFinished) { FOnDialogComplete(this, _dialogId, _bAudioFinished); }
	ArkConversation* TriggerRule(const uint64_t _ruleId, const bool _bIgnoreVoiceRequirement, const char* const _concept, ArkResponseQuery* const _pQuery, const int _paChannel, const bool _bIsLiveAudio, const int _priority) { return FTriggerRule(this, _ruleId, _bIgnoreVoiceRequirement, _concept, _pQuery, _paChannel, _bIsLiveAudio, _priority); }
	bool PlayResponse(ArkResponseRule& _rule, ArkConversation* const _pConversation, const float _currentTime, const bool _bUseRuleVoice, const int _paChannel) { return FPlayResponse(this, _rule, _pConversation, _currentTime, _bUseRuleVoice, _paChannel); }
	void AddListener(ArkSpeakerBase* _pListener) { FAddListener(this, _pListener); }
	void RemoveListener(ArkSpeakerBase* _pListener) { FRemoveListener(this, _pListener); }
	void SetCharacter(ArkCharacter const* const _pCharacter, uint64_t _voiceOverride) { FSetCharacter(this, _pCharacter, _voiceOverride); }
	virtual const char* GetName() const;
	SArkRuleQuery BuildRuleQuery(const char* _concept, const uint64_t _conceptId, ArkResponseQuery& _query, ArkConversation const* _pConversation) const { return FBuildRuleQuery(this, _concept, _conceptId, _query, _pConversation); }
	void ApplyEmotion(uint64_t _dialogId) { FApplyEmotion(this, _dialogId); }
	void ApplyResponseTargetTracking() { FApplyResponseTargetTracking(this); }
	void Reset() { FReset(this); }
	void OnConversationJoined(ArkConversation* _pConversation) { FOnConversationJoined(this, _pConversation); }
	virtual void OnConversationComplete(const bool _bComplete);
	virtual bool PlayDialog(SDialogParams& _params);
	virtual void SetEntity(IEntity* const _pEntity);
	virtual IArkConversation const* GetConversation() const;
	virtual bool IsSpeaking() const;
	virtual EArkConversationDominance GetDefaultDominance() const = 0;
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void PostSerialize();
	float GetAudioLevel() const { return FGetAudioLevel(this); }
	virtual void SetDuckAudio(const bool _bEnable);
	virtual EArkDialogPlayerType GetPlayerType() const = 0;
	virtual void OnDialogAnimationEvent() = 0;
	virtual void SetMute(const bool arg0) = 0;
	virtual void SetVoiceEffect(unsigned arg0) = 0;
	virtual void SetVoice(const uint64_t _voiceId);
	static uint64_t ResolveAbstractVoice(const uint64_t _voiceId) { return FResolveAbstractVoice(_voiceId); }

#if 0
	bool Speak(uint64_t arg0, ArkResponseQuery& arg1, ArkConversation* const arg2);
	const char* GetPortrait() const;
	uint64_t GetVoice() const;
	ArkCharacter const* GetCharacter() const;
	IEntity* GetEntity() const;
	ArkConversation* GetConversation();
	const char* GetPlaybackName() const;
	uint64_t GetPlaybackVoice() const;
	bool IsAudioDucked() const;
	void UpdateMemory();
#endif

	static inline auto FBitNotArkSpeakerBase = PreyFunction<void(ArkSpeakerBase* const _this)>(0x14993A0);
	static inline auto FUpdate = PreyFunction<void(ArkSpeakerBase* const _this, float _frameTime)>(0x149B870);
	static inline auto FSpeakOv2 = PreyFunction<bool(ArkSpeakerBase* const _this, const char* _concept, ArkResponseQuery& _query, ArkConversation* const _pConversation)>(0x149B540);
	static inline auto FSpeakOv0 = PreyFunction<bool(ArkSpeakerBase* const _this, const char* _conceptStr, uint64_t _conceptId, ArkResponseQuery& _query, ArkConversation* _pConversation)>(0x149B5A0);
	static inline auto FCanSpeak = PreyFunction<bool(ArkSpeakerBase const* const _this, const char* _concept, ArkResponseQuery& _query)>(0x1499E40);
	static inline auto FStop = PreyFunction<void(ArkSpeakerBase* const _this, bool _bLoading, bool _bConversationComplete)>(0x149B6A0);
	static inline auto FOnDialogComplete = PreyFunction<void(ArkSpeakerBase* const _this, uint64_t _dialogId, bool _bAudioFinished)>(0x149A0A0);
	static inline auto FTriggerRule = PreyFunction<ArkConversation* (ArkSpeakerBase* const _this, const uint64_t _ruleId, const bool _bIgnoreVoiceRequirement, const char* const _concept, ArkResponseQuery* const _pQuery, const int _paChannel, const bool _bIsLiveAudio, const int _priority)>(0x149B6D0);
	static inline auto FPlayResponse = PreyFunction<bool(ArkSpeakerBase* const _this, ArkResponseRule& _rule, ArkConversation* const _pConversation, const float _currentTime, const bool _bUseRuleVoice, const int _paChannel)>(0x149A2D0);
	static inline auto FAddListener = PreyFunction<void(ArkSpeakerBase* const _this, ArkSpeakerBase* _pListener)>(0x1499810);
	static inline auto FRemoveListener = PreyFunction<void(ArkSpeakerBase* const _this, ArkSpeakerBase* _pListener)>(0x1484970);
	static inline auto FSetCharacter = PreyFunction<void(ArkSpeakerBase* const _this, ArkCharacter const* const _pCharacter, uint64_t _voiceOverride)>(0x149B480);
	static inline auto FGetName = PreyFunction<const char* (ArkSpeakerBase const* const _this)>(0x1499F40);
	static inline auto FBuildRuleQuery = PreyFunction<SArkRuleQuery(ArkSpeakerBase const* const _this, const char* _concept, const uint64_t _conceptId, ArkResponseQuery& _query, ArkConversation const* _pConversation)>(0x1499A70);
	static inline auto FApplyEmotion = PreyFunction<void(ArkSpeakerBase* const _this, uint64_t _dialogId)>(0x1499860);
	static inline auto FApplyResponseTargetTracking = PreyFunction<void(ArkSpeakerBase* const _this)>(0x1499940);
	static inline auto FReset = PreyFunction<void(ArkSpeakerBase* const _this)>(0x149AB10);
	static inline auto FOnConversationJoined = PreyFunction<void(ArkSpeakerBase* const _this, ArkConversation* _pConversation)>(0x1499FD0);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkSpeakerBase* const _this, const bool _bComplete)>(0x1499F80);
	static inline auto FPlayDialog = PreyFunction<bool(ArkSpeakerBase* const _this, SDialogParams& _params)>(0xDD23F0);
	static inline auto FSetEntity = PreyFunction<void(ArkSpeakerBase* const _this, IEntity* const _pEntity)>(0x11AA120);
	static inline auto FGetConversationOv1 = PreyFunction<IArkConversation const* (ArkSpeakerBase const* const _this)>(0x11A67A0);
	static inline auto FIsSpeaking = PreyFunction<bool(ArkSpeakerBase const* const _this)>(0xDD23F0);
	static inline auto FSerialize = PreyFunction<void(ArkSpeakerBase* const _this, TSerialize _ser)>(0x149ABD0);
	static inline auto FPostSerialize = PreyFunction<void(ArkSpeakerBase* const _this)>(0x149AA40);
	static inline auto FGetAudioLevel = PreyFunction<float(ArkSpeakerBase const* const _this)>(0x1499F10);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkSpeakerBase* const _this, const bool _bEnable)>(0x149B4B0);
	static inline auto FSetVoice = PreyFunction<void(ArkSpeakerBase* const _this, const uint64_t _voiceId)>(0x149B4C0);
	static inline auto FResolveAbstractVoice = PreyFunction<uint64_t(const uint64_t _voiceId)>(0x149ABB0);
};

// Header: Exact
// Prey/GameDll/ark/dialog/ArkConversation.h
class ArkConversation : public IArkConversation // Id=8013979 Size=96
{
public:
	std::vector<IArkConversationListener *> m_listeners;
	std::vector<ArkSpeakerBase *> m_speakers;
	uint64_t m_conversationId;
	uint64_t m_hookId;
	int8_t m_nPAChannel;
	EArkConversationDominance m_dominance;
	EArkConversationPriority m_priority;
	EArkConversationType m_type;
	bool m_bIgnoreVoiceRequirement;
	bool m_bLiveAudio;
	bool m_bImportant;
	
	ArkConversation();
	ArkConversation(const uint64_t _conversationId, const bool _bImportant, SConversationParams const &_params);
	bool CanJoin(const uint64_t _voiceId) const { return FCanJoin(this,_voiceId); }
	virtual void AddSpeaker(IArkSpeaker *_pSpeaker);
	void OnComplete(const bool _bComplete) { FOnComplete(this,_bComplete); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SetDuckAudio(bool _bEnable) const { FSetDuckAudio(this,_bEnable); }
	virtual uint64_t GetConversationId() const;
	virtual void AddListener(IArkConversationListener *const _pListener);
	virtual void RemoveListener(IArkConversationListener *const _pListener);
	
#if 0
	std::vector<ArkSpeakerBase *> const &GetSpeakers() const;
	void SetIgnoreVoiceRequirement(const bool arg0);
	bool CanIgnoreVoiceRequirement() const;
	void SetPAChannel(const int8_t arg0);
	int GetPAChannel() const;
	uint64_t GetHookId() const;
	bool IsLiveAudio() const;
	void SetIsLiveAudio(const bool arg0);
	EArkConversationType GetType() const;
	EArkConversationPriority GetPriority() const;
	void SetPriority(EArkConversationPriority arg0);
	bool IsImportant() const;
	EArkConversationDominance GetDominance() const;
	bool CanSerialize() const;
#endif
	
	static inline auto FCanJoin = PreyFunction<bool(ArkConversation const *const _this, const uint64_t _voiceId)>(0x1484880);
	static inline auto FAddSpeaker = PreyFunction<void(ArkConversation *const _this, IArkSpeaker *_pSpeaker)>(0x1484840);
	static inline auto FOnComplete = PreyFunction<void(ArkConversation *const _this, const bool _bComplete)>(0x14848B0);
	static inline auto FSerialize = PreyFunction<void(ArkConversation *const _this, TSerialize _ser)>(0x14849B0);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkConversation const *const _this, bool _bEnable)>(0x1484AF0);
	static inline auto FGetConversationId = PreyFunction<uint64_t(ArkConversation const *const _this)>(0x864AF0);
	static inline auto FAddListener = PreyFunction<void(ArkConversation *const _this, IArkConversationListener *const _pListener)>(0x14847F0);
	static inline auto FRemoveListener = PreyFunction<void(ArkConversation *const _this, IArkConversationListener *const _pListener)>(0x1484970);
};

// Header: Exact
// Prey/GameDll/ark/dialog/arkconversation.h
class ArkActiveUserManagerBase // Id=8013CC6 Size=40
{
public:
	enum class EArkReason
	{
		userSignOut = 0,
		controllerUserInvalid = 1,
		controllerDisconnect = 2,
	};

	std::vector<IArkActiveUserManagerListener *> m_listeners;
	bool m_bListening;
	bool m_bReengagementPhase;
	bool m_bDisconnectQueued;
	
	ArkActiveUserManagerBase();
	virtual void RegisterActiveUser(unsigned platformUserId);
	virtual void ClearActiveUser();
	virtual bool IsActiveUserLoggedIn() const;
	virtual void EnsureActiveUserValid(const uint64_t exclusiveDeviceId);
	void AddListener(IArkActiveUserManagerListener *_pListener) { FAddListener(this,_pListener); }
	void RemoveListener(IArkActiveUserManagerListener const *_pListener) { FRemoveListener(this,_pListener); }
	void SetListening(bool _bListening) { FSetListening(this,_bListening); }
	virtual void OnUserSignOutStarted(const unsigned _userId);
	virtual void OnUserSignOutCompleted(const unsigned _userId);
	virtual void OnActiveUserControllerRemoved(const unsigned _userId);
	virtual void OnActiveUserControllerInvalid(const unsigned _userId);
	
#if 0
	bool IsReengaging() const;
	void SetDisconnecting(bool arg0);
	void SetReengaging(bool arg0);
	std::vector<IArkActiveUserManagerListener *> const &GetListeners();
	bool IsListening() const;
	static void NotifyLauncherMenuActiveUserRemoved(ArkActiveUserManagerBase::EArkReason arg0);
	static bool PlayerExists();
	static void NotifyModalDialogDisconnect(bool arg0);
#endif
	
	static inline auto FRegisterActiveUser = PreyFunction<void(ArkActiveUserManagerBase *const _this, unsigned platformUserId)>(0xA13080);
	static inline auto FClearActiveUser = PreyFunction<void(ArkActiveUserManagerBase *const _this)>(0xA13080);
	static inline auto FIsActiveUserLoggedIn = PreyFunction<bool(ArkActiveUserManagerBase const *const _this)>(0x1B933B0);
	static inline auto FEnsureActiveUserValid = PreyFunction<void(ArkActiveUserManagerBase *const _this, const uint64_t exclusiveDeviceId)>(0xA13080);
	static inline auto FAddListener = PreyFunction<void(ArkActiveUserManagerBase *const _this, IArkActiveUserManagerListener *_pListener)>(0x12F7620);
	static inline auto FRemoveListener = PreyFunction<void(ArkActiveUserManagerBase *const _this, IArkActiveUserManagerListener const *_pListener)>(0x1484970);
	static inline auto FSetListening = PreyFunction<void(ArkActiveUserManagerBase *const _this, bool _bListening)>(0x12F7670);
	static inline auto FOnUserSignOutStarted = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0xA13080);
	static inline auto FOnUserSignOutCompleted = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0xA13080);
	static inline auto FOnActiveUserControllerRemoved = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0xA13080);
	static inline auto FOnActiveUserControllerInvalid = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0xA13080);
};

