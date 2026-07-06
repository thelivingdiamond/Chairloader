// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>

class ArkDialogAudioTrigger;
class ArkSpeakerBase;
struct IEntity;

// ArkDialogPlayerPlayer
// Header:  Prey/GameDll/ark/dialog/ArkDialogPlayerPlayer.h
class ArkDialogPlayerPlayer : public ArkDialogPlayer
{ // Size=264 (0x108)
public:
	EArkConversationDominance m_dominance;
	bool m_bUpdateProxyPos;

	ArkDialogPlayerPlayer(ArkSpeakerBase* const _pSpeaker);
	void SetEntity(IEntity* const _pEntity) { FSetEntity(this, _pEntity); }
	void Update(float _deltaTime) { FUpdate(this, _deltaTime); }
	void OnConversationComplete(bool _bHasResponse) { FOnConversationComplete(this, _bHasResponse); }
	void PostSerialize() { FPostSerialize(this); }
	virtual bool PlayTriggerInternal(ArkDialogAudioTrigger& _trigger);

#if 0
	EArkConversationDominance GetDefaultDominance() const;
	void SetDefaultDominance(EArkConversationDominance _arg0_);
#endif

	static inline auto FArkDialogPlayerPlayerOv2 = PreyFunction<void(ArkDialogPlayerPlayer* const _this, ArkSpeakerBase* const _pSpeaker)>(0x11C7FF0);
	static inline auto FSetEntity = PreyFunction<void(ArkDialogPlayerPlayer* const _this, IEntity* const _pEntity)>(0x11C80C0);
	static inline auto FUpdate = PreyFunction<void(ArkDialogPlayerPlayer* const _this, float _deltaTime)>(0x11C81E0);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkDialogPlayerPlayer* const _this, bool _bHasResponse)>(0x11C8070);
	static inline auto FPostSerialize = PreyFunction<void(ArkDialogPlayerPlayer* const _this)>(0x11C8070);
	static inline auto FPlayTriggerInternal = PreyFunction<bool(ArkDialogPlayerPlayer* const _this, ArkDialogAudioTrigger& _trigger)>(0x11C8080);
};
#endif // MOONCRASH
