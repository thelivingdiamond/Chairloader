// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>
struct IRenderNode;
class SMFXAudioListNode;
class SMFXDecalListNode;
class SMFXFlowGraphListNode;
class SMFXForceFeedbackListNode;
class SMFXParticleListNode;

struct SMFXAudioEffectRtpc // Id=8001FBD Size=16
{
    const char *rtpcName;
    float rtpcValue;
};


// Header: Exact
// CryEngine/crycommon/imaterialeffects.h
struct SMFXResourceList // Id=8001FAF Size=56
{
	SMFXParticleListNode *m_particleList;
	SMFXAudioListNode *m_audioList;
	SMFXDecalListNode *m_decalList;
	SMFXFlowGraphListNode *m_flowGraphList;
	SMFXForceFeedbackListNode *m_forceFeedbackList;
	int m_refs;
	
	virtual void Destroy();
	virtual ~SMFXResourceList();
	
#if 0
	void AddRef();
	void Release();
	static _smart_ptr<SMFXResourceList> Create();
	static void FreePool();
#endif
	
	static inline auto FDestroy = PreyFunction<void(SMFXResourceList *const _this)>(0x50EEC0);
	static inline auto FBitNotSMFXResourceList = PreyFunction<void(SMFXResourceList *const _this)>(0x50E7D0);
};

// Header: Exact
// CryEngine/crycommon/imaterialeffects.h
struct SMFXRunTimeEffectParams // Id=8001FBC Size=208
{
	static constexpr const int MAX_AUDIO_RTPCS = 4;
	uint16_t playSoundFP;
	uint16_t playflags;
	float fLastTime;
	float fDecalPlacementTestMaxSize;
	unsigned src;
	unsigned trg;
	int srcSurfaceId;
	int trgSurfaceId;
	IRenderNode *srcRenderNode;
	IRenderNode *trgRenderNode;
	int partID;
	Vec3 pos;
	Vec3 decalPos;
	Vec3 dir[2];
	Vec3 normal;
	float angle;
	float scale;
	unsigned audioProxyEntityId;
	Vec3 audioProxyOffset;
	SMFXAudioEffectRtpc audioRtpcs[4];
	unsigned numAudioRtpcs;
	
	SMFXRunTimeEffectParams();
	
#if 0
	bool AddAudioRtpc(const char *arg0, float arg1);
	void ResetAudioRtpcs();
#endif
};

