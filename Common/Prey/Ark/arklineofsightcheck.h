// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkDeferredActionImpl.h>
#include <Prey/Ark/arkdeferredaction.h>
#include <Prey/CryPhysics/RayCastQueue.h>

// Enumerators unknown; an opaque scoped enum is still a complete type.
enum class EArkLineOfSightCheckStatus;
enum class EArkLineOfSightCheckPolicy;

// RayCastQueue<N> (CryPhysics/RayCastQueue.h) is not defined in the tree yet; only named here.
template<int RayCasterID> class RayCastQueue;

// ArkLineOfSightCheck<TImpl,N>
// Header:  Prey/Ark/arklineofsightcheck.h
// Instantiations:
//   <ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>                                                      Size=392
//   <ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>       Size=376
//   <ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1> Size=376
//   <ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>   Size=728
//   <ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>   Size=728
// No addresses: they differ per instantiation.
template<typename TImpl, size_t N>
class ArkLineOfSightCheck : public TImpl
{
public:
#if 0
	// Dumped as a copy of RayCastRequest::Priority.
	using PriorityType = RayCastRequest::Priority;
#endif

	// ArkLineOfSightCheck<TImpl,N>::DeferredRayCastImpl
	// Header:  Prey/Ark/arklineofsightcheck.h
	class DeferredRayCastImpl : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=16 (0x10)
	public:
		ArkLineOfSightCheck* m_pLineOfSightCheck;
		uint64_t m_index;

	#if 0
		DeferredRayCastImpl();
		RayCastQueue<41>& GetQueue() const;
		bool GetRequest(RayCastRequest& _arg0_) const;
		void OnAborted();
		void OnResult(const RayCastResult& _arg0_);
	#endif
	};

	using RayCasterType = RayCastQueue<41>;
	using DeferredRayCast = ArkDeferredAction<DeferredRayCastImpl>;
	using DeferredRayCastArray = std::array<ArkDeferredAction<DeferredRayCastImpl>, N>;

	EArkLineOfSightCheckStatus m_status;
	EArkLineOfSightCheckPolicy m_policy;
	std::array<ArkDeferredAction<DeferredRayCastImpl>, N> m_rayCasts;

	ArkLineOfSightCheck();
	// The game inlines the copy/move members (memberwise); a declared-only move constructor would delete the copy
	// constructor and make std::vector<ArkSignalSystem::Manager::AreaTarget> non-copyable.
	ArkLineOfSightCheck(const ArkLineOfSightCheck&) = default;
	ArkLineOfSightCheck(ArkLineOfSightCheck&&) = default;
	ArkLineOfSightCheck& operator=(const ArkLineOfSightCheck&) = default;
	ArkLineOfSightCheck& operator=(ArkLineOfSightCheck&&) = default;
	void Begin(RayCastRequest::Priority _priority, EArkLineOfSightCheckPolicy _policy);
	void CancelPendingRayCasts();

#if 0
	ArkLineOfSightCheck(const ArkLineOfSightCheck& _arg0_);
	~ArkLineOfSightCheck();
	ArkLineOfSightCheck& operator=(ArkLineOfSightCheck&& _arg0_);
	ArkLineOfSightCheck& operator=(const ArkLineOfSightCheck& _arg0_);
	void Cancel();
	void Reset();
	EArkLineOfSightCheckStatus GetStatus() const;
	bool IsPending() const;
	bool HasCompleted() const;
	bool HasSucceeded() const;
	bool HasFailed() const;
	void InitializeRayCasts();
	void Expire();
	RayCastQueue<41>& GetRayCaster() const;
	bool GetRayCastRequest(uint64_t _arg0_, RayCastRequest& _arg1_) const;
	void OnSucceedIfAnyLineClearAborted();
	void OnFailIfAnyLineObstructedAborted();
	void OnSucceedIfAnyLineClearResult(uint64_t _arg0_, const RayCastResult& _arg1_);
	void OnFailIfAnyLineObstructedResult(uint64_t _arg0_, const RayCastResult& _arg1_);
#endif
};
