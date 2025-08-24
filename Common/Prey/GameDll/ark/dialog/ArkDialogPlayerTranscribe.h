// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>

class ArkDialogAudioTrigger;
class ArkSpeakerBase;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/dialog/ArkDialogPlayerTranscribe.h
class ArkDialogPlayerTranscribe : public ArkDialogPlayer // Id=801731E Size=272
{
public:
	ArkAudioTrigger m_inSoundTrigger;
	ArkAudioTrigger m_outSoundTrigger;
	bool m_bConversationPlaying;
	
	ArkDialogPlayerTranscribe(ArkSpeakerBase *const _pSpeaker);
	void SetEntity(IEntity *const _pEntity) { FSetEntity(this,_pEntity); }
	void Update(float _deltaTime) { FUpdate(this,_deltaTime); }
	void OnConversationComplete(bool _bHasResponse) { FOnConversationComplete(this,_bHasResponse); }
	void PostSerialize() { FPostSerialize(this); }
	virtual EArkDialogPlayerType GetType() const;
	EArkConversationDominance GetDefaultDominance() const { return FGetDefaultDominance(this); }
	void SetDuckAudio(bool _bEnable) { FSetDuckAudio(this,_bEnable); }
	virtual bool PlayTriggerInternal(ArkDialogAudioTrigger &_trigger);
	
#if 0
	bool IsConversationPlaying() const;
#endif
	
	static inline auto FSetEntity = PreyFunction<void(ArkDialogPlayerTranscribe *const _this, IEntity *const _pEntity)>(0x13F8A50);
	static inline auto FUpdate = PreyFunction<void(ArkDialogPlayerTranscribe *const _this, float _deltaTime)>(0x13F8BF0);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkDialogPlayerTranscribe *const _this, bool _bHasResponse)>(0x13F8590);
	static inline auto FPostSerialize = PreyFunction<void(ArkDialogPlayerTranscribe *const _this)>(0x13F8960);
	static inline auto FGetType = PreyFunction<EArkDialogPlayerType(ArkDialogPlayerTranscribe const *const _this)>(0x13F8580);
	static inline auto FGetDefaultDominance = PreyFunction<EArkConversationDominance(ArkDialogPlayerTranscribe const *const _this)>(0x1A42CE0);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkDialogPlayerTranscribe *const _this, bool _bEnable)>(0xA13080);
	static inline auto FPlayTriggerInternal = PreyFunction<bool(ArkDialogPlayerTranscribe *const _this, ArkDialogAudioTrigger &_trigger)>(0x13F86E0);
};

