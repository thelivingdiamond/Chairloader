// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkDeferredActionImpl.h>
#include <Prey/CryPhysics/RayCastQueue.h>

// Enumerators unknown; an opaque scoped enum is still a complete type.
enum class EArkDeferredActionStatus;

// ArkDeferredAction<TImpl>
// Header:  Prey/Ark/arkdeferredaction.h
// TImpl (exposed as ImplType) is a ArkDeferredActionImpl_RayCast<> / ArkDeferredActionImpl_IntersectionTest<>
// policy subclass that carries the per-action payload. Instantiations:
//   ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl              Size=352
//   ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<...>,1|2>::DeferredRayCastImpl (x4) Size=352
//   ArkMoonRockManager::DeferredRayCastImpl (Mooncrash only)                                                  Size=384
//   ArkNpcThrowPropManager::DeferredRayCastImpl                                                               Size=344
//   NavigationSystem::DeferredHeightCastImpl                                                                  Size=96
// No addresses: they differ per instantiation.
template<typename TImpl>
class ArkDeferredAction : public TImpl
{
public:
#if 0
	// Dumped as a copy of RequestType::Priority (RayCastRequest::Priority / IntersectionTestRequest::Priority).
	using PriorityType = typename TImpl::RequestType::Priority;
#endif
	using ImplType = TImpl;
	using QueueType = typename TImpl::QueueType;
	using RequestType = typename TImpl::RequestType;
	using ResultType = typename TImpl::ResultType;

	static constexpr const unsigned k_invalidActionId = 4294967295;
	EArkDeferredActionStatus m_status;
	unsigned m_queuedActionId;
	ResultType m_result;

	void Cancel();
	void MoveCallbacks();
	bool OnSubmit(const unsigned& _queuedActionId, RequestType& _request);
	void OnResult(const unsigned& _queuedActionId, const ResultType& _result);

#if 0
	// Kept under #if 0 so that instantiating with an incomplete RequestType (IntersectionTestRequest) works.
	void Begin(typename RequestType::Priority _priority);
	ArkDeferredAction();
	ArkDeferredAction(ArkDeferredAction&& _arg0_);
	ArkDeferredAction(const ArkDeferredAction& _arg0_);
	~ArkDeferredAction();
	ArkDeferredAction& operator=(ArkDeferredAction&& _arg0_);
	ArkDeferredAction& operator=(const ArkDeferredAction& _arg0_);
	void Reset();
	EArkDeferredActionStatus GetStatus() const;
	bool IsPending() const;
	bool IsAborted() const;
	bool IsCompleted() const;
	const ResultType& GetResult() const;
	void Expire();
#endif
};
