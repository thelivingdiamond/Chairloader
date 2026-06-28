// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/dialog/IArkSpeaker.h>
#include <Prey/GameDll/ark/dialog/arkresponsetypes.h>

class ArkCharacter;
class ArkConversation;
class ArkResponse;
class ArkResponseQuery;
class ArkResponseRule;
enum class EArkConversationDominance;
enum class EArkDialogPlayerType;
class IArkConversation;
struct IEntity;
struct SArkRuleQuery;
struct SDialogParams;

// ArkSpeakerBase
// Header:  Prey/GameDll/ark/dialog/ArkSpeakerBase.h
class ArkSpeakerBase : public IArkSpeaker
{ // Size=240 (0xF0)
public:
	using TMemoryTimeout = std::pair<uint64_t, float>;
	using TMemoryTimeouts = std::list<std::pair<unsigned __int64,float>,std::allocator<std::pair<unsigned __int64,float> > >;

	std::vector<ArkSpeakerBase*> m_listeners;
	std::vector<ArkResponseFact> m_memory;
	std::unordered_map<uint64_t, float> m_usedResponses;
	std::vector<uint64_t> m_voices;
	std::list<std::pair<unsigned __int64,float>,std::allocator<std::pair<unsigned __int64,float> > > m_timeouts;
	uint64_t m_voiceId;
	const ArkCharacter* m_pCharacter;
	ArkConversation* m_pCurrentConversation;
	const ArkResponse* m_pCurrentResponse;
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
	bool PlayResponse(const ArkResponseRule& _rule, ArkConversation* const _pConversation, const float _currentTime, const bool _bUseRuleVoice, const int _paChannel) { return FPlayResponse(this, _rule, _pConversation, _currentTime, _bUseRuleVoice, _paChannel); }
	const ArkResponse* FindResponseFromRule(const ArkResponseRule& _rule, const float _currentTime) { return FFindResponseFromRule(this, _rule, _currentTime); }
	void AddListener(ArkSpeakerBase* _pListener) { FAddListener(this, _pListener); }
	void RemoveListener(ArkSpeakerBase* _pListener) { FRemoveListener(this, _pListener); }
	void SetCharacter(const ArkCharacter* const _pCharacter, uint64_t _voiceOverride) { FSetCharacter(this, _pCharacter, _voiceOverride); }
	virtual const char* GetName() const;
	SArkRuleQuery BuildRuleQuery(const char* _concept, const uint64_t _conceptId, ArkResponseQuery& _query, const ArkConversation* _pConversation) const { alignas(SArkRuleQuery) std::byte _return_buf_[sizeof(SArkRuleQuery)]; return *FBuildRuleQuery(this, reinterpret_cast<SArkRuleQuery*>(_return_buf_), _concept, _conceptId, _query, _pConversation); }
	void ApplyEmotion(uint64_t _dialogId) { FApplyEmotion(this, _dialogId); }
	void ApplyResponseTargetTracking() { FApplyResponseTargetTracking(this); }
	void Reset() { FReset(this); }
	void OnConversationJoined(ArkConversation* _pConversation) { FOnConversationJoined(this, _pConversation); }
	virtual void OnConversationComplete(const bool _bComplete);
	virtual bool PlayDialog(SDialogParams& _params);
	virtual void SetEntity(IEntity* const _pEntity);
	virtual const IArkConversation* GetConversation() const;
	virtual bool IsSpeaking() const;
	virtual EArkConversationDominance GetDefaultDominance() const = 0;
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void PostSerialize();
	float GetAudioLevel() const { return FGetAudioLevel(this); }
	virtual void SetDuckAudio(const bool _bEnable);
	virtual EArkDialogPlayerType GetPlayerType() const = 0;
	virtual void OnDialogAnimationEvent() = 0;
	virtual void SetMute(const bool _bMute) = 0;
	virtual void SetVoiceEffect(unsigned _environmentId) = 0;
	virtual void SetVoice(const uint64_t _voiceId);
	static uint64_t ResolveAbstractVoice(const uint64_t _voiceId) { return FResolveAbstractVoice(_voiceId); }

#if 0
	bool Speak(uint64_t _arg0_, ArkResponseQuery& _arg1_, ArkConversation* const _arg2_);
	const char* GetPortrait() const;
	uint64_t GetVoice() const;
	const ArkCharacter* GetCharacter() const;
	IEntity* GetEntity() const;
	ArkConversation* GetConversation();
	const char* GetPlaybackName() const;
	uint64_t GetPlaybackVoice() const;
	bool IsAudioDucked() const;
	void UpdateMemory();
#endif

	static inline auto FArkSpeakerBaseOv1 = PreyFunction<void(ArkSpeakerBase* const _this)>(0x15B0D50);
	static inline auto FBitNotArkSpeakerBase = PreyFunction<void(ArkSpeakerBase* const _this)>(0x15B0E70);
	static inline auto FUpdate = PreyFunction<void(ArkSpeakerBase* const _this, float _frameTime)>(0x15B3410);
	static inline auto FSpeakOv2 = PreyFunction<bool(ArkSpeakerBase* const _this, const char* _concept, ArkResponseQuery& _query, ArkConversation* const _pConversation)>(0x15B30B0);
	static inline auto FSpeakOv0 = PreyFunction<bool(ArkSpeakerBase* const _this, const char* _conceptStr, uint64_t _conceptId, ArkResponseQuery& _query, ArkConversation* _pConversation)>(0x15B3110);
	static inline auto FCanSpeak = PreyFunction<bool(const ArkSpeakerBase* const _this, const char* _concept, ArkResponseQuery& _query)>(0x15B1960);
	static inline auto FStop = PreyFunction<void(ArkSpeakerBase* const _this, bool _bLoading, bool _bConversationComplete)>(0x15B3240);
	static inline auto FOnDialogComplete = PreyFunction<void(ArkSpeakerBase* const _this, uint64_t _dialogId, bool _bAudioFinished)>(0x15B1E10);
	static inline auto FTriggerRule = PreyFunction<ArkConversation* (ArkSpeakerBase* const _this, const uint64_t _ruleId, const bool _bIgnoreVoiceRequirement, const char* const _concept, ArkResponseQuery* const _pQuery, const int _paChannel, const bool _bIsLiveAudio, const int _priority)>(0x15B3270);
	static inline auto FPlayResponse = PreyFunction<bool(ArkSpeakerBase* const _this, const ArkResponseRule& _rule, ArkConversation* const _pConversation, const float _currentTime, const bool _bUseRuleVoice, const int _paChannel)>(0x15B2040);
	static inline auto FFindResponseFromRule = PreyFunction<const ArkResponse* (ArkSpeakerBase* const _this, const ArkResponseRule& _rule, const float _currentTime)>(0x15B1A30);
	static inline auto FAddListener = PreyFunction<void(ArkSpeakerBase* const _this, ArkSpeakerBase* _pListener)>(0x15B12E0);
	static inline auto FRemoveListener = PreyFunction<void(ArkSpeakerBase* const _this, ArkSpeakerBase* _pListener)>(0x159C1E0);
	static inline auto FSetCharacter = PreyFunction<void(ArkSpeakerBase* const _this, const ArkCharacter* const _pCharacter, uint64_t _voiceOverride)>(0x15B2FF0);
	static inline auto FGetName = PreyFunction<const char* (const ArkSpeakerBase* const _this)>(0x15B1CB0);
	static inline auto FBuildRuleQuery = PreyFunction<SArkRuleQuery*(const ArkSpeakerBase* const _this, SArkRuleQuery* _return_value_, const char* _concept, const uint64_t _conceptId, ArkResponseQuery& _query, const ArkConversation* _pConversation)>(0x15B1540);
	static inline auto FApplyEmotion = PreyFunction<void(ArkSpeakerBase* const _this, uint64_t _dialogId)>(0x15B1330);
	static inline auto FApplyResponseTargetTracking = PreyFunction<void(ArkSpeakerBase* const _this)>(0x15B1410);
	static inline auto FReset = PreyFunction<void(ArkSpeakerBase* const _this)>(0x15B2680);
	static inline auto FOnConversationJoined = PreyFunction<void(ArkSpeakerBase* const _this, ArkConversation* _pConversation)>(0x15B1D40);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkSpeakerBase* const _this, const bool _bComplete)>(0x15B1CF0);
	static inline auto FPlayDialog = PreyFunction<bool(ArkSpeakerBase* const _this, SDialogParams& _params)>(0x13B0900);
	static inline auto FSetEntity = PreyFunction<void(ArkSpeakerBase* const _this, IEntity* const _pEntity)>(0x11C89D0);
	static inline auto FGetConversationOv1 = PreyFunction<const IArkConversation* (const ArkSpeakerBase* const _this)>(0x11C8520);
	static inline auto FIsSpeaking = PreyFunction<bool(const ArkSpeakerBase* const _this)>(0x13B0900);
	static inline auto FSerialize = PreyFunction<void(ArkSpeakerBase* const _this, TSerialize _ser)>(0x15B2740);
	static inline auto FPostSerialize = PreyFunction<void(ArkSpeakerBase* const _this)>(0x15B25B0);
	static inline auto FGetAudioLevel = PreyFunction<float(const ArkSpeakerBase* const _this)>(0x15B1C80);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkSpeakerBase* const _this, const bool _bEnable)>(0x15B3020);
	static inline auto FSetVoice = PreyFunction<void(ArkSpeakerBase* const _this, const uint64_t _voiceId)>(0x15B3030);
	static inline auto FResolveAbstractVoice = PreyFunction<uint64_t(const uint64_t _voiceId)>(0x15B2720);
};
#endif // MOONCRASH
