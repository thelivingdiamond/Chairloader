// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>

class ArkDialogAudioTrigger;
class ArkSpeakerBase;
struct IEntity;
struct IEntityAudioProxy;
struct ILipSyncProvider;
struct SDialogParams;

// Header: FromCpp
// Prey/GameDll/ark/dialog/ArkDialogPlayerNPC.h
class ArkDialogPlayerNPC : public ArkDialogPlayer // Id=8016466 Size=280
{
public:
	ILipSyncProvider *m_pLipSyncProvider;
	unsigned m_controlId;
	float m_fAnimStartTime;
	int m_audioProxyJointId;
	bool m_bUpdateLipSync;
	bool m_bUseResearchName;
	
	ArkDialogPlayerNPC(ArkSpeakerBase *_pSpeaker);
	bool Play(SDialogParams &_params) { return FPlay(this,_params); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void Stop(bool _bInvalidate) { FStop(this,_bInvalidate); }
	void SetEntity(IEntity *const _pEntity) { FSetEntity(this,_pEntity); }
	void OnDialogAnimationEvent() { FOnDialogAnimationEvent(this); }
	virtual EArkDialogPlayerType GetType() const;
	void OnConversationComplete(bool _bHasResponse) { FOnConversationComplete(this,_bHasResponse); }
	virtual bool PlayTriggerInternal(ArkDialogAudioTrigger &_trigger);
	virtual void OnDialogComplete(ArkDialogAudioTrigger const *_pTrigger, const bool _bAudioFinished);
	void EnableBlink(bool _bEnable) { FEnableBlink(this,_bEnable); }
	IEntityAudioProxy *GetEntityAudioProxy() const { return FGetEntityAudioProxy(this); }
	void StopLipSync() { FStopLipSync(this); }
	
#if 0
	void UpdateAudioProxyOffset();
#endif
	
	static inline auto FPlay = PreyFunction<bool(ArkDialogPlayerNPC *const _this, SDialogParams &_params)>(0x13F7B80);
	static inline auto FUpdate = PreyFunction<void(ArkDialogPlayerNPC *const _this, const float _frameTime)>(0x13F8370);
	static inline auto FStop = PreyFunction<void(ArkDialogPlayerNPC *const _this, bool _bInvalidate)>(0x13F82A0);
	static inline auto FSetEntity = PreyFunction<void(ArkDialogPlayerNPC *const _this, IEntity *const _pEntity)>(0x13F7E00);
	static inline auto FOnDialogAnimationEvent = PreyFunction<void(ArkDialogPlayerNPC *const _this)>(0x13F7AE0);
	static inline auto FGetType = PreyFunction<EArkDialogPlayerType(ArkDialogPlayerNPC const *const _this)>(0x1A42CE0);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkDialogPlayerNPC *const _this, bool _bHasResponse)>(0x13F7A60);
	static inline auto FPlayTriggerInternal = PreyFunction<bool(ArkDialogPlayerNPC *const _this, ArkDialogAudioTrigger &_trigger)>(0x13F7D20);
	static inline auto FOnDialogComplete = PreyFunction<void(ArkDialogPlayerNPC *const _this, ArkDialogAudioTrigger const *_pTrigger, const bool _bAudioFinished)>(0x13F7B20);
	static inline auto FEnableBlink = PreyFunction<void(ArkDialogPlayerNPC *const _this, bool _bEnable)>(0x13F78F0);
	static inline auto FGetEntityAudioProxy = PreyFunction<IEntityAudioProxy *(ArkDialogPlayerNPC const *const _this)>(0x13F7980);
	static inline auto FStopLipSync = PreyFunction<void(ArkDialogPlayerNPC *const _this)>(0x13F8310);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>

class ArkDialogAudioTrigger;
class ArkSpeakerBase;
enum class EArkDialogPlayerType;
struct IEntity;
struct IEntityAudioProxy;
struct ILipSyncProvider;
struct SDialogParams;

// ArkDialogPlayerNPC
// Header:  Prey/GameDll/ark/dialog/ArkDialogPlayerNPC.h
class ArkDialogPlayerNPC : public ArkDialogPlayer
{ // Size=280 (0x118)
public:
	ILipSyncProvider* m_pLipSyncProvider;
	unsigned m_controlId;
	float m_fAnimStartTime;
	int m_audioProxyJointId;
	bool m_bUpdateLipSync;
	bool m_bUseResearchName;

	ArkDialogPlayerNPC(ArkSpeakerBase* _pSpeaker);
	bool Play(SDialogParams& _params) { return FPlay(this, _params); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void Stop(bool _bInvalidate) { FStop(this, _bInvalidate); }
	void SetEntity(IEntity* const _pEntity) { FSetEntity(this, _pEntity); }
	void OnDialogAnimationEvent() { FOnDialogAnimationEvent(this); }
	virtual EArkDialogPlayerType GetType() const;
	void OnConversationComplete(bool _bHasResponse) { FOnConversationComplete(this, _bHasResponse); }
	virtual bool PlayTriggerInternal(ArkDialogAudioTrigger& _trigger);
	virtual void OnDialogComplete(const ArkDialogAudioTrigger* _pTrigger, const bool _bAudioFinished);
	void EnableBlink(bool _bEnable) { FEnableBlink(this, _bEnable); }
	IEntityAudioProxy* GetEntityAudioProxy() const { return FGetEntityAudioProxy(this); }
	void StopLipSync() { FStopLipSync(this); }

#if 0
	void UpdateAudioProxyOffset();
#endif

	static inline auto FArkDialogPlayerNPCOv2 = PreyFunction<void(ArkDialogPlayerNPC* const _this, ArkSpeakerBase* _pSpeaker)>(0x1509880);
	static inline auto FPlay = PreyFunction<bool(ArkDialogPlayerNPC* const _this, SDialogParams& _params)>(0x1509BA0);
	static inline auto FUpdate = PreyFunction<void(ArkDialogPlayerNPC* const _this, const float _frameTime)>(0x150A390);
	static inline auto FStop = PreyFunction<void(ArkDialogPlayerNPC* const _this, bool _bInvalidate)>(0x150A2C0);
	static inline auto FSetEntity = PreyFunction<void(ArkDialogPlayerNPC* const _this, IEntity* const _pEntity)>(0x1509E20);
	static inline auto FOnDialogAnimationEvent = PreyFunction<void(ArkDialogPlayerNPC* const _this)>(0x1509B00);
	static inline auto FGetType = PreyFunction<EArkDialogPlayerType(const ArkDialogPlayerNPC* const _this)>(0x4FD7F0);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkDialogPlayerNPC* const _this, bool _bHasResponse)>(0x1509A80);
	static inline auto FPlayTriggerInternal = PreyFunction<bool(ArkDialogPlayerNPC* const _this, ArkDialogAudioTrigger& _trigger)>(0x1509D40);
	static inline auto FOnDialogComplete = PreyFunction<void(ArkDialogPlayerNPC* const _this, const ArkDialogAudioTrigger* _pTrigger, const bool _bAudioFinished)>(0x1509B40);
	static inline auto FEnableBlink = PreyFunction<void(ArkDialogPlayerNPC* const _this, bool _bEnable)>(0x1509910);
	static inline auto FGetEntityAudioProxy = PreyFunction<IEntityAudioProxy* (const ArkDialogPlayerNPC* const _this)>(0x15099A0);
	static inline auto FStopLipSync = PreyFunction<void(ArkDialogPlayerNPC* const _this)>(0x150A330);
};
#endif // !MOONCRASH
