#pragma once
#include <Prey/CryPhysics/physinterface.h>

class RayCastResult
{
	ray_hit hits[4];
	int hitCount;
};
class RayCastRequest
{
	Vec3_tpl<float> pos;
	Vec3_tpl<float> dir;
	int objTypes;
	int flags;
	unsigned __int8 skipListCount;
	IPhysicalEntity* skipList[64];
	unsigned __int8 maxHitCount;
	SCollisionClass collclass;
};
class ArkLatentRaycast
{
	enum RaycastStatus : __int32
	{
		ePending = 0x0,
		eSuccessful = 0x1,
		eFailure = 0x2,
		eNotStarted = 0x3,
	};
	unsigned int m_rayID;
	ArkLatentRaycast::RaycastStatus m_status;
	Functor1wRet<RayCastResult const&, bool> m_resultCallback;
	Functor1wRet<RayCastRequest&, bool> m_submitCallback;
};