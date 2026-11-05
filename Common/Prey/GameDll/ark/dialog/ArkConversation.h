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
	
#ifndef MOONCRASH
	static inline auto FCanJoin = PreyFunction<bool(ArkConversation const *const _this, const uint64_t _voiceId)>(0x1484880);
	static inline auto FAddSpeaker = PreyFunction<void(ArkConversation *const _this, IArkSpeaker *_pSpeaker)>(0x1484840);
	static inline auto FOnComplete = PreyFunction<void(ArkConversation *const _this, const bool _bComplete)>(0x14848B0);
	static inline auto FSerialize = PreyFunction<void(ArkConversation *const _this, TSerialize _ser)>(0x14849B0);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkConversation const *const _this, bool _bEnable)>(0x1484AF0);
	static inline auto FGetConversationId = PreyFunction<uint64_t(ArkConversation const *const _this)>(0x864AF0);
	static inline auto FAddListener = PreyFunction<void(ArkConversation *const _this, IArkConversationListener *const _pListener)>(0x14847F0);
	static inline auto FRemoveListener = PreyFunction<void(ArkConversation *const _this, IArkConversationListener *const _pListener)>(0x1484970);
#else
	static inline auto FArkConversationOv3 = PreyFunction<void(ArkConversation* const _this)>(0x159BFB0);
	static inline auto FArkConversationOv2 = PreyFunction<void(ArkConversation* const _this, const uint64_t _conversationId, const bool _bImportant, const SConversationParams& _params)>(0x159C000);
	static inline auto FCanJoin = PreyFunction<bool(const ArkConversation* const _this, const uint64_t _voiceId)>(0x159C0F0);
	static inline auto FAddSpeaker = PreyFunction<void(ArkConversation* const _this, IArkSpeaker* _pSpeaker)>(0x159C0B0);
	static inline auto FOnComplete = PreyFunction<void(ArkConversation* const _this, const bool _bComplete)>(0x159C120);
	static inline auto FSerialize = PreyFunction<void(ArkConversation* const _this, TSerialize _ser)>(0x159C220);
	static inline auto FSetDuckAudio = PreyFunction<void(const ArkConversation* const _this, bool _bEnable)>(0x159C360);
	static inline auto FGetConversationId = PreyFunction<uint64_t(const ArkConversation* const _this)>(0xEDF820);
	static inline auto FAddListener = PreyFunction<void(ArkConversation* const _this, IArkConversationListener* const _pListener)>(0x159C060);
	static inline auto FRemoveListener = PreyFunction<void(ArkConversation* const _this, IArkConversationListener* const _pListener)>(0x159C1E0);
#endif
};
