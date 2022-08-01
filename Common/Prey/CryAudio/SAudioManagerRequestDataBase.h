// Header file automatically created from a PDB.

#pragma once
#include <ChairLoader/pch.h>
#include <Prey/CryAudio/IAudioInterfacesCommonData.h>
#include <Prey/CryAudio/IAudioSystem.h>
#include <Prey/CryAudio/SAudioRequestDataBase.h>
enum EAudioManagerRequestType
{
    eAMRT_NONE=0,
    eAMRT_SET_AUDIO_IMPL=1,
    eAMRT_RELEASE_AUDIO_IMPL=2,
    eAMRT_REFRESH_AUDIO_SYSTEM=4,
    eAMRT_RESERVE_AUDIO_OBJECT_ID=8,
    eAMRT_LOSE_FOCUS=16,
    eAMRT_GET_FOCUS=32,
    eAMRT_MUTE_ALL=64,
    eAMRT_UNMUTE_ALL=128,
    eAMRT_STOP_ALL_SOUNDS=256,
    eAMRT_PARSE_CONTROLS_DATA=512,
    eAMRT_PARSE_PRELOADS_DATA=1024,
    eAMRT_CLEAR_CONTROLS_DATA=2048,
    eAMRT_CLEAR_PRELOADS_DATA=4096,
    eAMRT_PRELOAD_SINGLE_REQUEST=8192,
    eAMRT_UNLOAD_SINGLE_REQUEST=16384,
    eAMRT_UNLOAD_AFCM_DATA_BY_SCOPE=32768,
    eAMRT_DRAW_DEBUG_INFO=65536,
    eAMRT_ADD_REQUEST_LISTENER=131072,
    eAMRT_REMOVE_REQUEST_LISTENER=262144,
    eAMRT_CHANGE_LANGUAGE=524288,
    eAMRT_RETRIGGER_AUDIO_CONTROLS=1048576,
    eAMRT_AUDIO_PROPAGATION_CONTROL=2097152,
    eAMRT_AUDIO_PROPAGATION_VOLUMEEDIT=4194304,
    eAMRT_AUDIO_PROPAGATION_PORTALEDIT=8388608,
    eAMRT_PAUSE=16777216,
    eAMRT_RESUME=33554432
};
// Header: MadeUp
// _unknown/SAudioManagerRequestDataBase.h
struct SAudioManagerRequestDataBase : public SAudioRequestDataBase // Id=8002D38 Size=24
{
	EAudioManagerRequestType eType;
	
	virtual ~SAudioManagerRequestDataBase();
	
#if 0
	void __dflt_ctor_closure();
#endif
};

