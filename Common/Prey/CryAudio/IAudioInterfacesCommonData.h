// Header file automatically created from a PDB.

#pragma once
#include <Chairloader/pch.h>
#include <Prey/CryAudio/IAudioInterfacesCommonData.h>

enum EAudioRequestType
{
    eART_NONE=0,
    eART_AUDIO_MANAGER_REQUEST=1,
    eART_AUDIO_CALLBACK_MANAGER_REQUEST=2,
    eART_AUDIO_OBJECT_REQUEST=3,
    eART_AUDIO_LISTENER_REQUEST=4,
    eART_AUDIO_ALL_REQUESTS=4294967295
};

// Header: Exact
// CryEngine/crycommon/iaudiointerfacescommondata.h
struct SAudioCallBackInfos // Id=80021AF Size=32
{
	void *const pObjectToNotify;
	void *const pUserData;
	void *const pUserDataOwner;
	const unsigned nRequestFlags;
	
	static SAudioCallBackInfos const &GetEmptyObject() { return FGetEmptyObject(); }
	
#if 0
	void __dflt_ctor_closure();
#endif
	
	static inline auto FGetEmptyObject = PreyFunction<SAudioCallBackInfos const &()>(0x1A0A00);
};

// Header: Exact
// CryEngine/crycommon/iaudiointerfacescommondata.h
class CAudioObjectTransformation // Id=8002D90 Size=36
{
public:
	Vec3 m_position;
	Vec3 m_forward;
	Vec3 m_up;
	
	CAudioObjectTransformation(Matrix34 const &transformation);
	
#if 0
	Vec3 const &GetPosition() const;
	Vec3 const &GetForward() const;
	Vec3 const &GetUp() const;
	bool IsEquivalent(Matrix34 const &arg0, const float arg1) const;
#endif
};

