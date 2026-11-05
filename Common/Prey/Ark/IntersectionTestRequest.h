// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryPhysics/physinterface.h>
#include <Prey/CryCore/Assert/CompileTimeUtils.h>

struct IPhysicalEntity;
namespace primitives
{
struct primitive;
} // namespace primitives

// IntersectionTestRequest
// Header:  _unknown/IntersectionTestRequest.h
// Include: Prey/CryPhysics/IntersectionTestQueue.h
struct IntersectionTestRequest
{ // Size=624 (0x270)
	enum
	{
		MaxSkipListCount = 64,
	};

	enum class Priority
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
	};

	enum
	{
		_MaxCapsuleSphereSize = 32,
		_MaxCapsuleSphereCylinderSize = 32,
		MaxPrimitiveSize = 64,
		_MaxCapsuleSphereAlignment = 4,
		_MaxCapsuleSphereCylinderAlignment = 4,
		MaxPrimitiveAlignment = 4,
	};

	int primitiveType;
	Vec3 sweepDir;
	int objTypes;
	int flagsAll;
	int flagsAny;
	IPhysicalEntity* skipList[64];
	uint8_t skipListCount;
	SCollisionClass collClass;
	aligned_buffer<4,64> primitiveBuf;

#if 0
	IntersectionTestRequest();
	IntersectionTestRequest(int _arg0_, const primitives::primitive& _arg1_, const Vec3& _arg2_, int _arg3_, int _arg4_, int _arg5_, IPhysicalEntity* * _arg6_, uint8_t _arg7_, const SCollisionClass& _arg8_);
	~IntersectionTestRequest();
#endif
};

