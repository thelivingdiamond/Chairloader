// Header file automatically created from a PDB.

#pragma once
#include <ChairLoader/pch.h>
#include <Prey/CryAudio/IAudioSystem.h>
#include <Prey/CryAudio/IAudioInterfacesCommonData.h>

struct IAudioProxy;
struct ICVar;
struct SAudioImplMemoryInfo;
struct SAudioRequest;
struct SAudioRequestInfo;
struct SAudioSystemInfo;


enum EAudioPropagationCommand
{
    eAPCC_UNLOAD=0,
    eAPCC_ENABLE=1,
    eAPCC_DISABLE=2,
    eAPPC_ACQUIRE_WRITE_ACCESS=3,
    eAPPC_RELEASE_WRITE_ACCESS=4
};
enum EAudioControlType
{
    eACT_NONE=0,
    eACT_AUDIO_OBJECT=1,
    eACT_TRIGGER=2,
    eACT_RTPC=3,
    eACT_SWITCH=4,
    eACT_SWITCH_STATE=5,
    eACT_PRELOAD=6,
    eACT_ENVIRONMENT=7
};

// Header: MadeUp
// _unknown/IAudioSystem.h
struct IAudioSystem // Id=80021A9 Size=8
{
	virtual ~IAudioSystem();
	virtual bool Initialize() = 0;
	virtual void Release() = 0;
	virtual void PushRequest(SAudioRequest const &arg0) = 0;
	virtual void AddRequestListener(void (*arg0)(SAudioRequestInfo const *const ), void *const arg1, EAudioRequestType arg2, const unsigned arg3) = 0;
	virtual void RemoveRequestListener(void (*arg0)(SAudioRequestInfo const *const ), void *const arg1) = 0;
	virtual void InvokeAudioPropagationCommand(EAudioPropagationCommand arg0) = 0;
	virtual void ExternalUpdate() = 0;
	virtual bool GetAudioTriggerID(const char *const arg0, unsigned &arg1) const = 0;
	virtual bool GetAudioRtpcID(const char *const arg0, unsigned &arg1) const = 0;
	virtual bool GetAudioSwitchID(const char *const arg0, unsigned &arg1) const = 0;
	virtual bool GetAudioSwitchStateID(const unsigned arg0, const char *const arg1, unsigned &arg2) const = 0;
	virtual bool GetAudioPreloadRequestID(const char *const arg0, unsigned &arg1) const = 0;
	virtual bool GetAudioEnvironmentID(const char *const arg0, unsigned &arg1) const = 0;
	virtual bool ReserveAudioListenerID(unsigned &arg0) = 0;
	virtual bool ReleaseAudioListenerID(const unsigned arg0) = 0;
	virtual void OnCVarChanged(ICVar *const arg0) = 0;
	virtual void GetInfo(SAudioSystemInfo &arg0) = 0;
	virtual const char *GetConfigPath() const = 0;
	virtual IAudioProxy *GetFreeAudioProxy() = 0;
	virtual void FreeAudioProxy(IAudioProxy *const arg0) = 0;
	virtual const char *GetAudioControlName(EAudioControlType arg0, const unsigned arg1) = 0;
	virtual const char *GetAudioControlName(EAudioControlType arg0, const unsigned arg1, const unsigned arg2) = 0;
	virtual void GetMemoryInfo(SAudioImplMemoryInfo &arg0) = 0;
};

