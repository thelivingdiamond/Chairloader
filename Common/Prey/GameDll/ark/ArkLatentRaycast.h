// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/Navigation/MNM/MeshGrid.h>
#include <Prey/CryCore/functor.h>

struct RayCastResult;

// Header: FromCpp
// Prey/GameDll/ark/ArkLatentRaycast.h
class ArkLatentRaycast // Id=80173EB Size=72
{
public:
	using ResultCallback = Functor1wRet<RayCastResult const &,bool>;
	using SubmitCallback = Functor1wRet<RayCastRequest &,bool>;
	
	enum RaycastStatus
	{
		ePending = 0,
		eSuccessful = 1,
		eFailure = 2,
		eNotStarted = 3,
	};

	unsigned m_rayID;
	ArkLatentRaycast::RaycastStatus m_status;
	Functor1wRet<RayCastResult const &,bool> m_resultCallback;
	Functor1wRet<RayCastRequest &,bool> m_submitCallback;
	
	ArkLatentRaycast();
	~ArkLatentRaycast() { FBitNotArkLatentRaycast(this); }
	void Start(RayCastRequest const &_request, RayCastRequest::Priority _priority, Functor1wRet<RayCastResult const &,bool> const &_resultCallback, Functor1wRet<RayCastRequest &,bool> const &_submitCallback) { FStart(this,_request,_priority,_resultCallback,_submitCallback); }
	void Cancel() { FCancel(this); }
	bool RaycastSubmitCallback(const unsigned &rayID, RayCastRequest &_result) { return FRaycastSubmitCallback(this,rayID,_result); }
	void RaycastCompleteCallback(const unsigned &rayID, RayCastResult const &_result) { FRaycastCompleteCallback(this,rayID,_result); }
	
#if 0
	bool IsNotStarted() const;
	bool IsPending() const;
	bool IsSuccessful() const;
	bool IsFailure() const;
	void Reset();
#endif
	
	static inline auto FBitNotArkLatentRaycast = PreyFunction<void(ArkLatentRaycast *const _this)>(0x1443ED0);
	static inline auto FStart = PreyFunction<void(ArkLatentRaycast *const _this, RayCastRequest const &_request, RayCastRequest::Priority _priority, Functor1wRet<RayCastResult const &,bool> const &_resultCallback, Functor1wRet<RayCastRequest &,bool> const &_submitCallback)>(0x14440C0);
	static inline auto FCancel = PreyFunction<void(ArkLatentRaycast *const _this)>(0x1443EE0);
	static inline auto FRaycastSubmitCallback = PreyFunction<bool(ArkLatentRaycast *const _this, const unsigned &rayID, RayCastRequest &_result)>(0x14440A0);
	static inline auto FRaycastCompleteCallback = PreyFunction<void(ArkLatentRaycast *const _this, const unsigned &rayID, RayCastResult const &_result)>(0x1444070);
};

