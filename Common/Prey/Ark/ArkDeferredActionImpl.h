// Size=1 policy classes used as the base of ArkDeferredAction<...>::ImplType. No method has an address.
#pragma once
#include <Prey/CryPhysics/RayCastQueue.h>

struct IntersectionTestRequest;
struct IntersectionTestResult;

template<typename RayCaster>
class ArkDeferredActionImpl_RayCast
{
public:
	using RayCasterType = RayCaster;
	using QueueType = RayCaster;
	using RequestType = RayCastRequest;
	using ResultType = RayCastResult;

	static constexpr const RayCastRequest::Priority k_defaultPriority = RayCastRequest::MediumPriority; // = 1

#if 0
	static void ClearResult(RayCastResult&);
	ArkDeferredActionImpl_RayCast();
	~ArkDeferredActionImpl_RayCast();
#endif
};

template<typename IntersectionTester>
class ArkDeferredActionImpl_IntersectionTest
{
public:
	using IntersectionTesterType = IntersectionTester;
	using QueueType = IntersectionTester;
	using RequestType = IntersectionTestRequest;
	using ResultType = IntersectionTestResult;

#if 0
	// Needs a complete IntersectionTestRequest (Prey/Ark/IntersectionTestRequest.h does not compile yet).
	static constexpr const IntersectionTestRequest::Priority k_defaultPriority = IntersectionTestRequest::Priority::MediumPriority; // = 1

	static void ClearResult(IntersectionTestResult&);
	ArkDeferredActionImpl_IntersectionTest();
	~ArkDeferredActionImpl_IntersectionTest();
#endif
};
