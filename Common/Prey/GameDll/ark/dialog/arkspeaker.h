// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
//#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/ui/IUIElementEventListener.h>
#include <Prey/GameDll/ark/dialog/ArkConversation.h>

struct IEntity;
struct IUIElement;
struct SDialogParams;

// Header: Exact
// Prey/GameDll/ark/dialog/arkspeaker.h
template <typename T>
class ArkSpeaker : public ArkSpeakerBase, public IUIElementEventListener // Id=80152C5 Size=512
{
public:
	T m_dialogPlayer;
	bool m_bResumePlayback;
	
	virtual ~ArkSpeaker();
	virtual void OnSetVisible(IUIElement *const _pSender, const bool _bVisible);
	void Pause(const bool arg0);
	virtual void Stop(const bool _bLoading, const bool _bConversationComplete);
	virtual void Update(const float _frameTime);
	virtual void SetEntity(IEntity *const _pEntity);
	virtual bool PlayDialog(SDialogParams &_params);
	virtual void OnConversationComplete(const bool _bComplete);
	virtual void SetVoice(const uint64_t _voiceId);
	virtual void PostSerialize();
	virtual void OnDialogAnimationEvent();
	virtual void SetMute(const bool _bMute);
	T &GetDialogPlayer();
	T const &GetDialogPlayer() const;
	virtual bool IsSpeaking() const;
	bool IsActive() const;
	virtual EArkDialogPlayerType GetPlayerType() const;
	virtual void SetVoiceEffect(unsigned _environmentId);
	virtual EArkConversationDominance GetDefaultDominance() const;
	virtual void SetDuckAudio(const bool _bEnable);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayerNPC.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayerPA.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayerPlayer.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayerTranscribe.h>
#include <Prey/GameDll/ark/dialog/ArkSpeakerBase.h>
#include <Prey/GameDll/ark/turret/ArkDialogTurret.h>
#include <_unknown/ArkDialogPlayerNull.h>

enum class EArkConversationDominance;
enum class EArkDialogPlayerType;
struct IEntity;
struct IUIElement;
struct SDialogParams;

// ArkSpeaker<ArkDialogPlayer>
// Header:  Prey/GameDll/ark/dialog/arkspeaker.h
class ArkSpeaker<ArkDialogPlayer> : public ArkSpeakerBase, public IUIElementEventListener
{ // Size=512 (0x200)
public:
	ArkDialogPlayer m_dialogPlayer;
	bool m_bResumePlayback;

	virtual ~ArkSpeaker<ArkDialogPlayer>();
	virtual void OnSetVisible(IUIElement* const _pSender, const bool _bVisible);
	virtual void Stop(const bool _bLoading, const bool _bConversationComplete);
	virtual void Update(const float _frameTime);
	virtual void SetEntity(IEntity* const _pEntity);
	virtual bool PlayDialog(SDialogParams& _params);
	virtual void OnConversationComplete(const bool _bComplete);
	virtual void SetVoice(const uint64_t _voiceId);
	virtual void PostSerialize();
	virtual void OnDialogAnimationEvent();
	virtual void SetMute(const bool _bMute);
	virtual bool IsSpeaking() const;
	virtual EArkDialogPlayerType GetPlayerType() const;
	virtual void SetVoiceEffect(unsigned _environmentId);
	virtual EArkConversationDominance GetDefaultDominance() const;
	virtual void SetDuckAudio(const bool _bEnable);

#if 0
	ArkSpeaker<ArkDialogPlayer>();
	void Pause(const bool _arg0_);
	ArkDialogPlayer& GetDialogPlayer();
	const ArkDialogPlayer& GetDialogPlayer() const;
	bool IsActive() const;
#endif

	static inline auto FBitNotArkSpeakerLessArkDialogPlayerGreater = PreyFunction<void(ArkSpeaker<ArkDialogPlayer>* const _this)>(0x11D1A70);
	static inline auto FOnSetVisible = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* const _pSender, const bool _bVisible)>(0x11D4B60);
	static inline auto FStop = PreyFunction<void(ArkSpeaker<ArkDialogPlayer>* const _this, const bool _bLoading, const bool _bConversationComplete)>(0x1681C00);
	static inline auto FUpdate = PreyFunction<void(ArkSpeaker<ArkDialogPlayer>* const _this, const float _frameTime)>(0x15A4260);
	static inline auto FSetEntity = PreyFunction<void(ArkSpeaker<ArkDialogPlayer>* const _this, IEntity* const _pEntity)>(0x11D5950);
	static inline auto FPlayDialog = PreyFunction<bool(ArkSpeaker<ArkDialogPlayer>* const _this, SDialogParams& _params)>(0x1680B30);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkSpeaker<ArkDialogPlayer>* const _this, const bool _bComplete)>(0x11C8900);
	static inline auto FSetVoice = PreyFunction<void(ArkSpeaker<ArkDialogPlayer>* const _this, const uint64_t _voiceId)>(0x11D6200);
	static inline auto FPostSerialize = PreyFunction<void(ArkSpeaker<ArkDialogPlayer>* const _this)>(0x11C8980);
	static inline auto FOnDialogAnimationEvent = PreyFunction<void(ArkSpeaker<ArkDialogPlayer>* const _this)>(0x1333E90);
	static inline auto FSetMute = PreyFunction<void(ArkSpeaker<ArkDialogPlayer>* const _this, const bool _bMute)>(0x14E1FD0);
	static inline auto FIsSpeaking = PreyFunction<bool(const ArkSpeaker<ArkDialogPlayer>* const _this)>(0x16805A0);
	static inline auto FSetVoiceEffect = PreyFunction<void(ArkSpeaker<ArkDialogPlayer>* const _this, unsigned _environmentId)>(0x14E1FE0);
	static inline auto FGetDefaultDominance = PreyFunction<EArkConversationDominance(const ArkSpeaker<ArkDialogPlayer>* const _this)>(0x15A3700);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkSpeaker<ArkDialogPlayer>* const _this, const bool _bEnable)>(0x141FF30);
};

// ArkSpeaker<ArkDialogPlayerNPC>
// Header:  Prey/GameDll/ark/dialog/arkspeaker.h
class ArkSpeaker<ArkDialogPlayerNPC> : public ArkSpeakerBase, public IUIElementEventListener
{ // Size=536 (0x218)
public:
	ArkDialogPlayerNPC m_dialogPlayer;
	bool m_bResumePlayback;

	virtual ~ArkSpeaker<ArkDialogPlayerNPC>();
	virtual void OnSetVisible(IUIElement* const _pSender, const bool _bVisible);
	virtual void Stop(const bool _bLoading, const bool _bConversationComplete);
	virtual void Update(const float _frameTime);
	virtual void SetEntity(IEntity* const _pEntity);
	virtual bool PlayDialog(SDialogParams& _params);
	virtual void OnConversationComplete(const bool _bComplete);
	virtual void SetVoice(const uint64_t _voiceId);
	virtual void PostSerialize();
	virtual void OnDialogAnimationEvent();
	virtual void SetMute(const bool _bMute);
	virtual bool IsSpeaking() const;
	virtual EArkDialogPlayerType GetPlayerType() const;
	virtual void SetVoiceEffect(unsigned _environmentId);
	virtual EArkConversationDominance GetDefaultDominance() const;
	virtual void SetDuckAudio(const bool _bEnable);

#if 0
	ArkSpeaker<ArkDialogPlayerNPC>();
	void Pause(const bool _arg0_);
	ArkDialogPlayerNPC& GetDialogPlayer();
	const ArkDialogPlayerNPC& GetDialogPlayer() const;
	bool IsActive() const;
#endif

	static inline auto FBitNotArkSpeakerLessArkDialogPlayerNPCGreater = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNPC>* const _this)>(0x14E1630);
	static inline auto FOnSetVisible = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* const _pSender, const bool _bVisible)>(0x14E1EB0);
	static inline auto FStop = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNPC>* const _this, const bool _bLoading, const bool _bConversationComplete)>(0x14E1FF0);
	static inline auto FUpdate = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNPC>* const _this, const float _frameTime)>(0x14E2040);
	static inline auto FSetEntity = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNPC>* const _this, IEntity* const _pEntity)>(0x14E1FB0);
	static inline auto FPlayDialog = PreyFunction<bool(ArkSpeaker<ArkDialogPlayerNPC>* const _this, SDialogParams& _params)>(0x14E1F10);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNPC>* const _this, const bool _bComplete)>(0x14E1E60);
	static inline auto FSetVoice = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNPC>* const _this, const uint64_t _voiceId)>(0x1681B80);
	static inline auto FPostSerialize = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNPC>* const _this)>(0x11C8980);
	static inline auto FOnDialogAnimationEvent = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNPC>* const _this)>(0x14E1EA0);
	static inline auto FSetMute = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNPC>* const _this, const bool _bMute)>(0x14E1FD0);
	static inline auto FIsSpeaking = PreyFunction<bool(const ArkSpeaker<ArkDialogPlayerNPC>* const _this)>(0x16805A0);
	static inline auto FSetVoiceEffect = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNPC>* const _this, unsigned _environmentId)>(0x14E1FE0);
	static inline auto FGetDefaultDominance = PreyFunction<EArkConversationDominance(const ArkSpeaker<ArkDialogPlayerNPC>* const _this)>(0x15A3700);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNPC>* const _this, const bool _bEnable)>(0x141FF30);
};

// ArkSpeaker<ArkDialogPlayerNull>
// Header:  Prey/GameDll/ark/dialog/arkspeaker.h
class ArkSpeaker<ArkDialogPlayerNull> : public ArkSpeakerBase, public IUIElementEventListener
{ // Size=264 (0x108)
public:
	ArkDialogPlayerNull m_dialogPlayer;
	bool m_bResumePlayback;

	virtual ~ArkSpeaker<ArkDialogPlayerNull>();
	virtual void OnSetVisible(IUIElement* const _pSender, const bool _bVisible);
	virtual void Stop(const bool _bLoading, const bool _bConversationComplete);
	virtual void Update(const float _frameTime);
	virtual void SetEntity(IEntity* const _pEntity);
	virtual bool PlayDialog(SDialogParams& _params);
	virtual void OnConversationComplete(const bool _bComplete);
	virtual void SetVoice(const uint64_t _voiceId);
	virtual void PostSerialize();
	virtual void OnDialogAnimationEvent();
	virtual void SetMute(const bool _bMute);
	virtual bool IsSpeaking() const;
	virtual EArkDialogPlayerType GetPlayerType() const;
	virtual void SetVoiceEffect(unsigned _environmentId);
	virtual EArkConversationDominance GetDefaultDominance() const;
	virtual void SetDuckAudio(const bool _bEnable);

#if 0
	ArkSpeaker<ArkDialogPlayerNull>();
	void Pause(const bool _arg0_);
	ArkDialogPlayerNull& GetDialogPlayer();
	const ArkDialogPlayerNull& GetDialogPlayer() const;
	bool IsActive() const;
#endif

	static inline auto FBitNotArkSpeakerLessArkDialogPlayerNullGreater = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNull>* const _this)>(0x11C8350);
	static inline auto FOnSetVisible = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* const _pSender, const bool _bVisible)>(0x11C8910);
	static inline auto FStop = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNull>* const _this, const bool _bLoading, const bool _bConversationComplete)>(0x11C8B30);
	static inline auto FUpdate = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNull>* const _this, const float _frameTime)>(0x11C8B40);
	static inline auto FSetEntity = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNull>* const _this, IEntity* const _pEntity)>(0x11C89D0);
	static inline auto FPlayDialog = PreyFunction<bool(ArkSpeaker<ArkDialogPlayerNull>* const _this, SDialogParams& _params)>(0x11C8940);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNull>* const _this, const bool _bComplete)>(0x11C8900);
	static inline auto FSetVoice = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNull>* const _this, const uint64_t _voiceId)>(0x11C89E0);
	static inline auto FPostSerialize = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNull>* const _this)>(0x11C8980);
	static inline auto FOnDialogAnimationEvent = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNull>* const _this)>(0x1333E90);
	static inline auto FSetMute = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNull>* const _this, const bool _bMute)>(0x1333E90);
	static inline auto FIsSpeaking = PreyFunction<bool(const ArkSpeaker<ArkDialogPlayerNull>* const _this)>(0x13B0900);
	static inline auto FGetPlayerType = PreyFunction<EArkDialogPlayerType(const ArkSpeaker<ArkDialogPlayerNull>* const _this)>(0x11C8530);
	static inline auto FSetVoiceEffect = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNull>* const _this, unsigned _environmentId)>(0x1333E90);
	static inline auto FGetDefaultDominance = PreyFunction<EArkConversationDominance(const ArkSpeaker<ArkDialogPlayerNull>* const _this)>(0x1CBB0B0);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkSpeaker<ArkDialogPlayerNull>* const _this, const bool _bEnable)>(0x11C89C0);
};

// ArkSpeaker<ArkDialogPlayerPA>
// Header:  Prey/GameDll/ark/dialog/arkspeaker.h
class ArkSpeaker<ArkDialogPlayerPA> : public ArkSpeakerBase, public IUIElementEventListener
{ // Size=560 (0x230)
public:
	ArkDialogPlayerPA m_dialogPlayer;
	bool m_bResumePlayback;

	virtual ~ArkSpeaker<ArkDialogPlayerPA>();
	virtual void OnSetVisible(IUIElement* const _pSender, const bool _bVisible);
	virtual void Stop(const bool _bLoading, const bool _bConversationComplete);
	virtual void Update(const float _frameTime);
	virtual void SetEntity(IEntity* const _pEntity);
	virtual bool PlayDialog(SDialogParams& _params);
	virtual void OnConversationComplete(const bool _bComplete);
	virtual void SetVoice(const uint64_t _voiceId);
	virtual void PostSerialize();
	virtual void OnDialogAnimationEvent();
	virtual void SetMute(const bool _bMute);
	virtual bool IsSpeaking() const;
	virtual EArkDialogPlayerType GetPlayerType() const;
	virtual void SetVoiceEffect(unsigned _environmentId);
	virtual EArkConversationDominance GetDefaultDominance() const;
	virtual void SetDuckAudio(const bool _bEnable);

#if 0
	ArkSpeaker<ArkDialogPlayerPA>();
	void Pause(const bool _arg0_);
	ArkDialogPlayerPA& GetDialogPlayer();
	const ArkDialogPlayerPA& GetDialogPlayer() const;
	bool IsActive() const;
#endif

	static inline auto FBitNotArkSpeakerLessArkDialogPlayerPAGreater = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPA>* const _this)>(0x15A3220);
	static inline auto FOnSetVisible = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* const _pSender, const bool _bVisible)>(0x15A37F0);
	static inline auto FStop = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPA>* const _this, const bool _bLoading, const bool _bConversationComplete)>(0x15A3F90);
	static inline auto FUpdate = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPA>* const _this, const float _frameTime)>(0x15A4260);
	static inline auto FSetEntity = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPA>* const _this, IEntity* const _pEntity)>(0x11D5950);
	static inline auto FPlayDialog = PreyFunction<bool(ArkSpeaker<ArkDialogPlayerPA>* const _this, SDialogParams& _params)>(0x15A3900);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPA>* const _this, const bool _bComplete)>(0x11C8900);
	static inline auto FSetVoice = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPA>* const _this, const uint64_t _voiceId)>(0x11D6200);
	static inline auto FPostSerialize = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPA>* const _this)>(0x11C8980);
	static inline auto FOnDialogAnimationEvent = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPA>* const _this)>(0x1333E90);
	static inline auto FSetMute = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPA>* const _this, const bool _bMute)>(0x14E1FD0);
	static inline auto FIsSpeaking = PreyFunction<bool(const ArkSpeaker<ArkDialogPlayerPA>* const _this)>(0x16805A0);
	static inline auto FGetPlayerType = PreyFunction<EArkDialogPlayerType(const ArkSpeaker<ArkDialogPlayerPA>* const _this)>(0x141EC80);
	static inline auto FSetVoiceEffect = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPA>* const _this, unsigned _environmentId)>(0x14E1FE0);
	static inline auto FGetDefaultDominance = PreyFunction<EArkConversationDominance(const ArkSpeaker<ArkDialogPlayerPA>* const _this)>(0x15A3700);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPA>* const _this, const bool _bEnable)>(0x15A3DD0);
};

// ArkSpeaker<ArkDialogPlayerPlayer>
// Header:  Prey/GameDll/ark/dialog/arkspeaker.h
class ArkSpeaker<ArkDialogPlayerPlayer> : public ArkSpeakerBase, public IUIElementEventListener
{ // Size=520 (0x208)
public:
	ArkDialogPlayerPlayer m_dialogPlayer;
	bool m_bResumePlayback;

	virtual ~ArkSpeaker<ArkDialogPlayerPlayer>();
	virtual void OnSetVisible(IUIElement* const _pSender, const bool _bVisible);
	virtual void Stop(const bool _bLoading, const bool _bConversationComplete);
	virtual void Update(const float _frameTime);
	virtual void SetEntity(IEntity* const _pEntity);
	virtual bool PlayDialog(SDialogParams& _params);
	virtual void OnConversationComplete(const bool _bComplete);
	virtual void SetVoice(const uint64_t _voiceId);
	virtual void PostSerialize();
	virtual void OnDialogAnimationEvent();
	virtual void SetMute(const bool _bMute);
	virtual bool IsSpeaking() const;
	virtual EArkDialogPlayerType GetPlayerType() const;
	virtual void SetVoiceEffect(unsigned _environmentId);
	virtual EArkConversationDominance GetDefaultDominance() const;
	virtual void SetDuckAudio(const bool _bEnable);

#if 0
	ArkSpeaker<ArkDialogPlayerPlayer>();
	void Pause(const bool _arg0_);
	ArkDialogPlayerPlayer& GetDialogPlayer();
	const ArkDialogPlayerPlayer& GetDialogPlayer() const;
	bool IsActive() const;
#endif

	static inline auto FOnSetVisible = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* const _pSender, const bool _bVisible)>(0x1680A70);
	static inline auto FStop = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPlayer>* const _this, const bool _bLoading, const bool _bConversationComplete)>(0x1681C00);
	static inline auto FUpdate = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPlayer>* const _this, const float _frameTime)>(0x1681D00);
	static inline auto FSetEntity = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPlayer>* const _this, IEntity* const _pEntity)>(0x1681AF0);
	static inline auto FPlayDialog = PreyFunction<bool(ArkSpeaker<ArkDialogPlayerPlayer>* const _this, SDialogParams& _params)>(0x1680B30);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPlayer>* const _this, const bool _bComplete)>(0x16808B0);
	static inline auto FSetVoice = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPlayer>* const _this, const uint64_t _voiceId)>(0x1681B80);
	static inline auto FPostSerialize = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPlayer>* const _this)>(0x1680B80);
	static inline auto FOnDialogAnimationEvent = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPlayer>* const _this)>(0x1333E90);
	static inline auto FSetMute = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPlayer>* const _this, const bool _bMute)>(0x14E1FD0);
	static inline auto FIsSpeaking = PreyFunction<bool(const ArkSpeaker<ArkDialogPlayerPlayer>* const _this)>(0x16805A0);
	static inline auto FGetPlayerType = PreyFunction<EArkDialogPlayerType(const ArkSpeaker<ArkDialogPlayerPlayer>* const _this)>(0x141EC80);
	static inline auto FSetVoiceEffect = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPlayer>* const _this, unsigned _environmentId)>(0x14E1FE0);
	static inline auto FGetDefaultDominance = PreyFunction<EArkConversationDominance(const ArkSpeaker<ArkDialogPlayerPlayer>* const _this)>(0x1680490);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkSpeaker<ArkDialogPlayerPlayer>* const _this, const bool _bEnable)>(0x141FF30);
};

// ArkSpeaker<ArkDialogPlayerTranscribe>
// Header:  Prey/GameDll/ark/dialog/arkspeaker.h
class ArkSpeaker<ArkDialogPlayerTranscribe> : public ArkSpeakerBase, public IUIElementEventListener
{ // Size=528 (0x210)
public:
	ArkDialogPlayerTranscribe m_dialogPlayer;
	bool m_bResumePlayback;

	virtual ~ArkSpeaker<ArkDialogPlayerTranscribe>();
	virtual void OnSetVisible(IUIElement* const _pSender, const bool _bVisible);
	virtual void Stop(const bool _bLoading, const bool _bConversationComplete);
	virtual void Update(const float _frameTime);
	virtual void SetEntity(IEntity* const _pEntity);
	virtual bool PlayDialog(SDialogParams& _params);
	virtual void OnConversationComplete(const bool _bComplete);
	virtual void SetVoice(const uint64_t _voiceId);
	virtual void PostSerialize();
	virtual void OnDialogAnimationEvent();
	virtual void SetMute(const bool _bMute);
	virtual bool IsSpeaking() const;
	virtual EArkDialogPlayerType GetPlayerType() const;
	virtual void SetVoiceEffect(unsigned _environmentId);
	virtual EArkConversationDominance GetDefaultDominance() const;
	virtual void SetDuckAudio(const bool _bEnable);

#if 0
	ArkSpeaker<ArkDialogPlayerTranscribe>();
	void Pause(const bool _arg0_);
	ArkDialogPlayerTranscribe& GetDialogPlayer();
	const ArkDialogPlayerTranscribe& GetDialogPlayer() const;
	bool IsActive() const;
#endif

	static inline auto FOnSetVisible = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* const _pSender, const bool _bVisible)>(0x1680AD0);
	static inline auto FStop = PreyFunction<void(ArkSpeaker<ArkDialogPlayerTranscribe>* const _this, const bool _bLoading, const bool _bConversationComplete)>(0x1681C00);
	static inline auto FUpdate = PreyFunction<void(ArkSpeaker<ArkDialogPlayerTranscribe>* const _this, const float _frameTime)>(0x1681D30);
	static inline auto FSetEntity = PreyFunction<void(ArkSpeaker<ArkDialogPlayerTranscribe>* const _this, IEntity* const _pEntity)>(0x1681B10);
	static inline auto FPlayDialog = PreyFunction<bool(ArkSpeaker<ArkDialogPlayerTranscribe>* const _this, SDialogParams& _params)>(0x1680B30);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkSpeaker<ArkDialogPlayerTranscribe>* const _this, const bool _bComplete)>(0x16808F0);
	static inline auto FSetVoice = PreyFunction<void(ArkSpeaker<ArkDialogPlayerTranscribe>* const _this, const uint64_t _voiceId)>(0x1681B80);
	static inline auto FPostSerialize = PreyFunction<void(ArkSpeaker<ArkDialogPlayerTranscribe>* const _this)>(0x1680BB0);
	static inline auto FOnDialogAnimationEvent = PreyFunction<void(ArkSpeaker<ArkDialogPlayerTranscribe>* const _this)>(0x1333E90);
	static inline auto FSetMute = PreyFunction<void(ArkSpeaker<ArkDialogPlayerTranscribe>* const _this, const bool _bMute)>(0x14E1FD0);
	static inline auto FIsSpeaking = PreyFunction<bool(const ArkSpeaker<ArkDialogPlayerTranscribe>* const _this)>(0x16805A0);
	static inline auto FGetPlayerType = PreyFunction<EArkDialogPlayerType(const ArkSpeaker<ArkDialogPlayerTranscribe>* const _this)>(0x141EC80);
	static inline auto FSetVoiceEffect = PreyFunction<void(ArkSpeaker<ArkDialogPlayerTranscribe>* const _this, unsigned _environmentId)>(0x14E1FE0);
	static inline auto FGetDefaultDominance = PreyFunction<EArkConversationDominance(const ArkSpeaker<ArkDialogPlayerTranscribe>* const _this)>(0x16804A0);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkSpeaker<ArkDialogPlayerTranscribe>* const _this, const bool _bEnable)>(0x141FF30);
};

// ArkSpeaker<ArkDialogTurret>
// Header:  Prey/GameDll/ark/dialog/arkspeaker.h
class ArkSpeaker<ArkDialogTurret> : public ArkSpeakerBase, public IUIElementEventListener
{ // Size=512 (0x200)
public:
	ArkDialogTurret m_dialogPlayer;
	bool m_bResumePlayback;

	virtual ~ArkSpeaker<ArkDialogTurret>();
	virtual void OnSetVisible(IUIElement* const _pSender, const bool _bVisible);
	virtual void Stop(const bool _bLoading, const bool _bConversationComplete);
	virtual void Update(const float _frameTime);
	virtual void SetEntity(IEntity* const _pEntity);
	virtual bool PlayDialog(SDialogParams& _params);
	virtual void OnConversationComplete(const bool _bComplete);
	virtual void SetVoice(const uint64_t _voiceId);
	virtual void PostSerialize();
	virtual void OnDialogAnimationEvent();
	virtual void SetMute(const bool _bMute);
	virtual bool IsSpeaking() const;
	virtual EArkDialogPlayerType GetPlayerType() const;
	virtual void SetVoiceEffect(unsigned _environmentId);
	virtual EArkConversationDominance GetDefaultDominance() const;
	virtual void SetDuckAudio(const bool _bEnable);

#if 0
	ArkSpeaker<ArkDialogTurret>();
	void Pause(const bool _arg0_);
	ArkDialogTurret& GetDialogPlayer();
	const ArkDialogTurret& GetDialogPlayer() const;
	bool IsActive() const;
#endif

	static inline auto FBitNotArkSpeakerLessArkDialogTurretGreater = PreyFunction<void(ArkSpeaker<ArkDialogTurret>* const _this)>(0x141EB20);
	static inline auto FOnSetVisible = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* const _pSender, const bool _bVisible)>(0x11D4B60);
	static inline auto FStop = PreyFunction<void(ArkSpeaker<ArkDialogTurret>* const _this, const bool _bLoading, const bool _bConversationComplete)>(0x1681C00);
	static inline auto FUpdate = PreyFunction<void(ArkSpeaker<ArkDialogTurret>* const _this, const float _frameTime)>(0x15A4260);
	static inline auto FSetEntity = PreyFunction<void(ArkSpeaker<ArkDialogTurret>* const _this, IEntity* const _pEntity)>(0x11D5950);
	static inline auto FPlayDialog = PreyFunction<bool(ArkSpeaker<ArkDialogTurret>* const _this, SDialogParams& _params)>(0x1680B30);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkSpeaker<ArkDialogTurret>* const _this, const bool _bComplete)>(0x11C8900);
	static inline auto FSetVoice = PreyFunction<void(ArkSpeaker<ArkDialogTurret>* const _this, const uint64_t _voiceId)>(0x11D6200);
	static inline auto FPostSerialize = PreyFunction<void(ArkSpeaker<ArkDialogTurret>* const _this)>(0x11C8980);
	static inline auto FOnDialogAnimationEvent = PreyFunction<void(ArkSpeaker<ArkDialogTurret>* const _this)>(0x1333E90);
	static inline auto FSetMute = PreyFunction<void(ArkSpeaker<ArkDialogTurret>* const _this, const bool _bMute)>(0x14E1FD0);
	static inline auto FIsSpeaking = PreyFunction<bool(const ArkSpeaker<ArkDialogTurret>* const _this)>(0x16805A0);
	static inline auto FSetVoiceEffect = PreyFunction<void(ArkSpeaker<ArkDialogTurret>* const _this, unsigned _environmentId)>(0x14E1FE0);
	static inline auto FGetDefaultDominance = PreyFunction<EArkConversationDominance(const ArkSpeaker<ArkDialogTurret>* const _this)>(0x15A3700);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkSpeaker<ArkDialogTurret>* const _this, const bool _bEnable)>(0x141FF30);
};
#endif // !MOONCRASH
