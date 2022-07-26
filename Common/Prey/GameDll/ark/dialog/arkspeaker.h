// Header file automatically created from a PDB.

#pragma once
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayerNPC.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayerPA.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayerTranscribe.h>
#include <Prey/GameDll/ark/dialog/arkconversation.h>
#include <Prey/GameDll/ark/turret/ArkDialogTurret.h>

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
	
#if 0
	virtual void ~ArkSpeaker();
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
#endif
};

