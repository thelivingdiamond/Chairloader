// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/dialog/IArkDialogAudioTriggerOwner.h>
#include <Prey/GameDll/ark/dialog/SSubtitleAudioData.h>
#include <Prey/Ark/ArkDialogAudioTrigger.h>

class ArkDialogAudioTrigger;
class ArkSpeakerBase;
class IArkDialogPlayerExtension;
struct IEntity;
struct SDialogParams;

// Header: FromCpp
// Prey/GameDll/ark/dialog/ArkDialogPlayer.h
class ArkDialogPlayer : public IArkDialogAudioTriggerOwner // Id=80152C7 Size=256
{
public:
	enum class ELoadResult
	{
		failed = 0,
		loading = 1,
		loaded = 2,
	};

	std::array<ArkDialogAudioTrigger,2> m_triggers;
	std::array<int,2> m_nPAPlaybackChannels;
	ArkSpeakerBase *m_pSpeaker;
	IArkDialogPlayerExtension *m_pExtension;
	unsigned m_nAudioProxy;
	unsigned m_nVoiceEffect;
	bool m_bMute;
	bool m_bPaused;
	
	ArkDialogPlayer(ArkSpeakerBase *_pSpeaker);
	virtual ~ArkDialogPlayer();
	bool Play(SDialogParams const &_params) { return FPlay(this,_params); }
	void Stop(bool _bInvalidate) { FStop(this,_bInvalidate); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void SetVoiceEffect(unsigned _environmentId) { FSetVoiceEffect(this,_environmentId); }
	void OnGamePause(bool _bPause) { FOnGamePause(this,_bPause); }
	bool IsPlaying() const { return FIsPlaying(this); }
	bool AreAllTriggersFree() const { return FAreAllTriggersFree(this); }
	void SetDuckAudio(bool _bEnable) { FSetDuckAudio(this,_bEnable); }
	virtual EArkDialogPlayerType GetType() const;
	boost::optional<float> GetNormalizedPlaytime(uint64_t _dialogId) const { return FGetNormalizedPlaytime(this,_dialogId); }
	virtual std::vector<SSubtitleAudioData> GetSubtitleAudioData() const;
	ArkDialogPlayer::ELoadResult Load(SDialogParams const &_params) { return FLoad(this,_params); }
	virtual void OnDialogComplete(ArkDialogAudioTrigger const *_pTrigger, const bool _bAudioFinished);
	virtual bool PlayTriggerInternal(ArkDialogAudioTrigger &_trigger);
	IEntity *GetEntity() const { return FGetEntity(this); }
	void UpdateAudioLevels(IEntity &_entity) { FUpdateAudioLevels(this,_entity); }
	void AddSubtitle(ArkDialogAudioTrigger const &_trigger) const { FAddSubtitle(this,_trigger); }
	void RemoveSubtitle(ArkDialogAudioTrigger const &_trigger) const { FRemoveSubtitle(this,_trigger); }
	virtual void OnTriggerLoaded(ArkDialogAudioTrigger const *_pTrigger, bool _bSuccess);
	virtual void OnTriggerCutoff(ArkDialogAudioTrigger const *_pTrigger);
	virtual void OnTriggerFinished(ArkDialogAudioTrigger const *_pTrigger);
	
#if 0
	EArkConversationDominance GetDefaultDominance() const;
	void SetExtension(IArkDialogPlayerExtension *const arg0);
	void PostSerialize();
	void OnConversationComplete(bool arg0);
	void OnDialogAnimationEvent();
	void SetEntity(IEntity *const arg0);
	void SetMute(bool arg0);
	bool IsMute() const;
	ArkDialogAudioTrigger *GetAvailableTrigger();
	static bool IsValidPlaybackChannel(int arg0);
	unsigned GetTriggerIndex(ArkDialogAudioTrigger const &arg0) const;
	bool IsAudioLogConversation() const;
#endif
	
	static inline auto FBitNotArkDialogPlayer = PreyFunction<void(ArkDialogPlayer *const _this)>(0x1484E80);
	static inline auto FPlay = PreyFunction<bool(ArkDialogPlayer *const _this, SDialogParams const &_params)>(0x1485600);
	static inline auto FStop = PreyFunction<void(ArkDialogPlayer *const _this, bool _bInvalidate)>(0x1485A40);
	static inline auto FUpdate = PreyFunction<void(ArkDialogPlayer *const _this, const float _frameTime)>(0x1485B90);
	static inline auto FSetVoiceEffect = PreyFunction<void(ArkDialogPlayer *const _this, unsigned _environmentId)>(0x16D5310);
	static inline auto FOnGamePause = PreyFunction<void(ArkDialogPlayer *const _this, bool _bPause)>(0x1485500);
	static inline auto FIsPlaying = PreyFunction<bool(ArkDialogPlayer const *const _this)>(0x1485330);
	static inline auto FAreAllTriggersFree = PreyFunction<bool(ArkDialogPlayer const *const _this)>(0x1485070);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkDialogPlayer *const _this, bool _bEnable)>(0x14859B0);
	static inline auto FGetType = PreyFunction<EArkDialogPlayerType(ArkDialogPlayer const *const _this)>(0x1B1DEA0);
	static inline auto FGetNormalizedPlaytime = PreyFunction<boost::optional<float>(ArkDialogPlayer const *const _this, uint64_t _dialogId)>(0x14850B0);
	static inline auto FGetSubtitleAudioData = PreyFunction<std::vector<SSubtitleAudioData>(ArkDialogPlayer const *const _this)>(0x1485100);
	static inline auto FLoad = PreyFunction<ArkDialogPlayer::ELoadResult(ArkDialogPlayer *const _this, SDialogParams const &_params)>(0x1485360);
	static inline auto FOnDialogComplete = PreyFunction<void(ArkDialogPlayer *const _this, ArkDialogAudioTrigger const *_pTrigger, const bool _bAudioFinished)>(0x1485450);
	static inline auto FPlayTriggerInternal = PreyFunction<bool(ArkDialogPlayer *const _this, ArkDialogAudioTrigger &_trigger)>(0x1485750);
	static inline auto FGetEntity = PreyFunction<IEntity *(ArkDialogPlayer const *const _this)>(0x14850A0);
	static inline auto FUpdateAudioLevels = PreyFunction<void(ArkDialogPlayer *const _this, IEntity &_entity)>(0x1485C70);
	static inline auto FAddSubtitle = PreyFunction<void(ArkDialogPlayer const *const _this, ArkDialogAudioTrigger const &_trigger)>(0x1484F80);
	static inline auto FRemoveSubtitle = PreyFunction<void(ArkDialogPlayer const *const _this, ArkDialogAudioTrigger const &_trigger)>(0x1485970);
	static inline auto FOnTriggerLoaded = PreyFunction<void(ArkDialogPlayer *const _this, ArkDialogAudioTrigger const *_pTrigger, bool _bSuccess)>(0x14855C0);
	static inline auto FOnTriggerCutoff = PreyFunction<void(ArkDialogPlayer *const _this, ArkDialogAudioTrigger const *_pTrigger)>(0x14855B0);
	static inline auto FOnTriggerFinished = PreyFunction<void(ArkDialogPlayer *const _this, ArkDialogAudioTrigger const *_pTrigger)>(0x14855B0);
};

