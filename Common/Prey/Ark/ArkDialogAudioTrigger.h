// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/Ark/IArkDialogLoadListener.h>

class IArkDialogAudioTriggerOwner;
struct IEntity;
struct SDialogParams;

// Header: FromCpp
// Prey/Ark/ArkDialogAudioTrigger.h
class ArkDialogAudioTrigger : public ArkAudioTrigger, public IArkDialogLoadListener // Id=80020DA Size=104
{
public:
	enum class EState
	{
		CryModuleCRTFree = 0,
		loading = 1,
		ready = 2,
		playing = 3,
		finished = 4,
	};

	IArkDialogAudioTriggerOwner *m_pOwner;
	ArkDialogAudioTrigger::EState m_state;
	uint64_t m_dialogId;
	uint64_t m_voiceId;
	uint64_t m_conversationId;
	uint64_t m_playbackHandle;
	float m_fDelay;
	float m_fPlayTime;
	float m_fDuration;
	float m_fEndEarly;
	string m_speakerName;
	string m_speakerPortrait;
	int m_nPASpeakerChannel;
	bool m_bCutoffEvent;
	
	ArkDialogAudioTrigger();
	virtual ~ArkDialogAudioTrigger();
	void Init(IArkDialogAudioTriggerOwner *_pOwner) { FInit(this,_pOwner); }
	ArkDialogAudioTrigger::EState Load(SDialogParams const &_params) { return FLoad(this,_params); }
	bool Execute(IEntity *_pEntity, unsigned _nAudioProxy) { return FExecute(this,_pEntity,_nAudioProxy); }
	void Stop(IEntity *_pEntity, unsigned _nAudioProxy) { FStop(this,_pEntity,_nAudioProxy); }
	void Pause(IEntity *_pEntity, unsigned _nAudioProxy, bool _bPause) const { FPause(this,_pEntity,_nAudioProxy,_bPause); }
	void Update(const float _fFrameTime) { FUpdate(this,_fFrameTime); }
	void Invalidate() { FInvalidate(this); }
	virtual void OnLoad(unsigned _controlId, bool _bSuccess);
	void OnFinish() { FOnFinish(this); }
	void OnDuration(float _fDuration) { FOnDuration(this,_fDuration); }
	
#if 0
	unsigned GetId() const;
	bool IsReady() const;
	bool IsPlaying() const;
	bool IsFree() const;
	bool IsFinished() const;
	const char *GetSpeakerName() const;
	const char *GetSpeakerPortrait() const;
	void SetDelay(const float arg0);
	float GetDelay() const;
	int GetPASpeakerChannel() const;
	uint64_t GetDialogId() const;
	uint64_t GetVoiceId() const;
	uint64_t GetConversationId() const;
	bool WasCutoffEarly() const;
	float GetDuration() const;
	float GetPlayTime() const;
	uint64_t GetPlaybackHandle();
#endif
	
	static inline auto FBitNotArkDialogAudioTrigger = PreyFunction<void(ArkDialogAudioTrigger *const _this)>(0x105EF60);
	static inline auto FInit = PreyFunction<void(ArkDialogAudioTrigger *const _this, IArkDialogAudioTriggerOwner *_pOwner)>(0x105F290);
	static inline auto FLoad = PreyFunction<ArkDialogAudioTrigger::EState(ArkDialogAudioTrigger *const _this, SDialogParams const &_params)>(0x105F3F0);
	static inline auto FExecute = PreyFunction<bool(ArkDialogAudioTrigger *const _this, IEntity *_pEntity, unsigned _nAudioProxy)>(0x105F0A0);
	static inline auto FStop = PreyFunction<void(ArkDialogAudioTrigger *const _this, IEntity *_pEntity, unsigned _nAudioProxy)>(0x105F790);
	static inline auto FPause = PreyFunction<void(ArkDialogAudioTrigger const *const _this, IEntity *_pEntity, unsigned _nAudioProxy, bool _bPause)>(0x105F620);
	static inline auto FUpdate = PreyFunction<void(ArkDialogAudioTrigger *const _this, const float _fFrameTime)>(0x105F940);
	static inline auto FInvalidate = PreyFunction<void(ArkDialogAudioTrigger *const _this)>(0x105F2E0);
	static inline auto FOnLoad = PreyFunction<void(ArkDialogAudioTrigger *const _this, unsigned _controlId, bool _bSuccess)>(0x105F5D0);
	static inline auto FOnFinish = PreyFunction<void(ArkDialogAudioTrigger *const _this)>(0x105F5A0);
	static inline auto FOnDuration = PreyFunction<void(ArkDialogAudioTrigger *const _this, float _fDuration)>(0x105F590);
};

