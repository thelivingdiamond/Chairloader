// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <CryEngine/cryaisystem/navigation/navigationsystem/NavigationSystem.h>
#include <Prey/Ark/arklineofsightcheck.h>
#include <Prey/CryPhysics/IntersectionTestQueue.h>
#include <Prey/CryPhysics/RayCastQueue.h>
#include <Prey/GameDll/ark/ArkMoonRockManager.h>
#include <Prey/GameDll/ark/npc/ArkNpcThrowPropManager.h>
#include <_unknown/ArkDeferredActionImpl_IntersectionTest.h>
#include <_unknown/ArkDeferredActionImpl_RayCast.h>
#include <_unknown/IntersectionTestQueue.h>
#include <_unknown/IntersectionTestRequest.h>
#include <_unknown/RayCastQueue.h>
#include <_unknown/RayCastRequest.h>

struct IntersectionTestRequest;
struct RayCastRequest;

// ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>
// Header:  Prey/Ark/arkdeferredaction.h
class ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl> : public ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl
{ // Size=352 (0x160)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>::ImplType
	// Header:  Prey/Ark/arkdeferredaction.h
	class ImplType : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=16 (0x10)
	public:
		ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>* m_pLineOfSightCheck;
		uint64_t m_index;

	#if 0
		void DeferredRayCastImpl();
		RayCastQueue<41>& GetQueue() const;
		bool GetRequest(RayCastRequest& _arg0_) const;
		void OnAborted();
		void OnResult(const RayCastResult& _arg0_);
	#endif
	};

	using QueueType = RayCastQueue<41>;
	using RequestType = RayCastRequest;
	using ResultType = RayCastResult;

	static constexpr const unsigned k_invalidActionId = 4294967295;
	EArkDeferredActionStatus m_status;
	unsigned m_queuedActionId;
	RayCastResult m_result;

	void Cancel() { FCancel(this); }
	void MoveCallbacks() { FMoveCallbacks(this); }
	bool OnSubmit(const unsigned& _queuedActionId, RayCastRequest& _request) { return FOnSubmit(this, _queuedActionId, _request); }
	void OnResult(const unsigned& _queuedActionId, const RayCastResult& _result) { FOnResult(this, _queuedActionId, _result); }

#if 0
	ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>();
	ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>(ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>(const ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>& _arg0_);
	~ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>();
	ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>& operator=(ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>& operator=(const ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>& _arg0_);
	void Begin(RayCastRequest::Priority _arg0_);
	void Reset();
	EArkDeferredActionStatus GetStatus() const;
	bool IsPending() const;
	bool IsAborted() const;
	bool IsCompleted() const;
	const RayCastResult& GetResult() const;
	void Expire();
#endif

	static inline auto FCancel = PreyFunction<void(ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>* const _this)>(0x1701950);
	static inline auto FMoveCallbacks = PreyFunction<void(ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>* const _this)>(0x1702540);
	static inline auto FOnSubmit = PreyFunction<bool(ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, RayCastRequest& _request)>(0x1702950);
	static inline auto FOnResult = PreyFunction<void(ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, const RayCastResult& _result)>(0x1702800);
};

// ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>
// Header:  Prey/Ark/arkdeferredaction.h
class ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl> : public ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl
{ // Size=352 (0x160)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>::ImplType
	// Header:  Prey/Ark/arkdeferredaction.h
	class ImplType : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=16 (0x10)
	public:
		ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>* m_pLineOfSightCheck;
		uint64_t m_index;

	#if 0
		void DeferredRayCastImpl();
		RayCastQueue<41>& GetQueue() const;
		bool GetRequest(RayCastRequest& _arg0_) const;
		void OnAborted();
		void OnResult(const RayCastResult& _arg0_);
	#endif
	};

	using QueueType = RayCastQueue<41>;
	using RequestType = RayCastRequest;
	using ResultType = RayCastResult;

	static constexpr const unsigned k_invalidActionId = 4294967295;
	EArkDeferredActionStatus m_status;
	unsigned m_queuedActionId;
	RayCastResult m_result;

	bool OnSubmit(const unsigned& _queuedActionId, RayCastRequest& _request) { return FOnSubmit(this, _queuedActionId, _request); }
	void OnResult(const unsigned& _queuedActionId, const RayCastResult& _result) { FOnResult(this, _queuedActionId, _result); }

#if 0
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>();
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>(const ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>& _arg0_);
	~ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>();
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>& operator=(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>& operator=(const ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>& _arg0_);
	void Begin(RayCastRequest::Priority _arg0_);
	void Cancel();
	void Reset();
	EArkDeferredActionStatus GetStatus() const;
	bool IsPending() const;
	bool IsAborted() const;
	bool IsCompleted() const;
	const RayCastResult& GetResult() const;
	void MoveCallbacks();
	void Expire();
#endif

	static inline auto FOnSubmit = PreyFunction<bool(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, RayCastRequest& _request)>(0x1655050);
	static inline auto FOnResult = PreyFunction<void(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, const RayCastResult& _result)>(0x1654F00);
};

// ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>
// Header:  Prey/Ark/arkdeferredaction.h
class ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl> : public ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl
{ // Size=352 (0x160)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>::ImplType
	// Header:  Prey/Ark/arkdeferredaction.h
	class ImplType : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=16 (0x10)
	public:
		ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>* m_pLineOfSightCheck;
		uint64_t m_index;

	#if 0
		void DeferredRayCastImpl();
		RayCastQueue<41>& GetQueue() const;
		bool GetRequest(RayCastRequest& _arg0_) const;
		void OnAborted();
		void OnResult(const RayCastResult& _arg0_);
	#endif
	};

	using QueueType = RayCastQueue<41>;
	using RequestType = RayCastRequest;
	using ResultType = RayCastResult;

	static constexpr const unsigned k_invalidActionId = 4294967295;
	EArkDeferredActionStatus m_status;
	unsigned m_queuedActionId;
	RayCastResult m_result;

	bool OnSubmit(const unsigned& _queuedActionId, RayCastRequest& _request) { return FOnSubmit(this, _queuedActionId, _request); }
	void OnResult(const unsigned& _queuedActionId, const RayCastResult& _result) { FOnResult(this, _queuedActionId, _result); }

#if 0
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>();
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>(const ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>& _arg0_);
	~ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>();
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>& operator=(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>& operator=(const ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>& _arg0_);
	void Begin(RayCastRequest::Priority _arg0_);
	void Cancel();
	void Reset();
	EArkDeferredActionStatus GetStatus() const;
	bool IsPending() const;
	bool IsAborted() const;
	bool IsCompleted() const;
	const RayCastResult& GetResult() const;
	void MoveCallbacks();
	void Expire();
#endif

	static inline auto FOnSubmit = PreyFunction<bool(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, RayCastRequest& _request)>(0x16552F0);
	static inline auto FOnResult = PreyFunction<void(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, const RayCastResult& _result)>(0x1654DB0);
};

// ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>
// Header:  Prey/Ark/arkdeferredaction.h
class ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl> : public ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl
{ // Size=352 (0x160)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>::ImplType
	// Header:  Prey/Ark/arkdeferredaction.h
	class ImplType : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=16 (0x10)
	public:
		ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>* m_pLineOfSightCheck;
		uint64_t m_index;

	#if 0
		void DeferredRayCastImpl();
		RayCastQueue<41>& GetQueue() const;
		bool GetRequest(RayCastRequest& _arg0_) const;
		void OnAborted();
		void OnResult(const RayCastResult& _arg0_);
	#endif
	};

	using QueueType = RayCastQueue<41>;
	using RequestType = RayCastRequest;
	using ResultType = RayCastResult;

	static constexpr const unsigned k_invalidActionId = 4294967295;
	EArkDeferredActionStatus m_status;
	unsigned m_queuedActionId;
	RayCastResult m_result;

	bool OnSubmit(const unsigned& _queuedActionId, RayCastRequest& _request) { return FOnSubmit(this, _queuedActionId, _request); }
	void OnResult(const unsigned& _queuedActionId, const RayCastResult& _result) { FOnResult(this, _queuedActionId, _result); }

#if 0
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>();
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>(const ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>& _arg0_);
	~ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>();
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>& operator=(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>& operator=(const ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>& _arg0_);
	void Begin(RayCastRequest::Priority _arg0_);
	void Cancel();
	void Reset();
	EArkDeferredActionStatus GetStatus() const;
	bool IsPending() const;
	bool IsAborted() const;
	bool IsCompleted() const;
	const RayCastResult& GetResult() const;
	void MoveCallbacks();
	void Expire();
#endif

	static inline auto FOnSubmit = PreyFunction<bool(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, RayCastRequest& _request)>(0x1655590);
	static inline auto FOnResult = PreyFunction<void(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, const RayCastResult& _result)>(0x1654DB0);
};

// ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>
// Header:  Prey/Ark/arkdeferredaction.h
class ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl> : public ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl
{ // Size=352 (0x160)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>::ImplType
	// Header:  Prey/Ark/arkdeferredaction.h
	class ImplType : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=16 (0x10)
	public:
		ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>* m_pLineOfSightCheck;
		uint64_t m_index;

	#if 0
		void DeferredRayCastImpl();
		RayCastQueue<41>& GetQueue() const;
		bool GetRequest(RayCastRequest& _arg0_) const;
		void OnAborted();
		void OnResult(const RayCastResult& _arg0_);
	#endif
	};

	using QueueType = RayCastQueue<41>;
	using RequestType = RayCastRequest;
	using ResultType = RayCastResult;

	static constexpr const unsigned k_invalidActionId = 4294967295;
	EArkDeferredActionStatus m_status;
	unsigned m_queuedActionId;
	RayCastResult m_result;

	bool OnSubmit(const unsigned& _queuedActionId, RayCastRequest& _request) { return FOnSubmit(this, _queuedActionId, _request); }
	void OnResult(const unsigned& _queuedActionId, const RayCastResult& _result) { FOnResult(this, _queuedActionId, _result); }

#if 0
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>();
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>(const ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>& _arg0_);
	~ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>();
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>& operator=(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>& operator=(const ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>& _arg0_);
	void Begin(RayCastRequest::Priority _arg0_);
	void Cancel();
	void Reset();
	EArkDeferredActionStatus GetStatus() const;
	bool IsPending() const;
	bool IsAborted() const;
	bool IsCompleted() const;
	const RayCastResult& GetResult() const;
	void MoveCallbacks();
	void Expire();
#endif

	static inline auto FOnSubmit = PreyFunction<bool(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, RayCastRequest& _request)>(0x1655820);
	static inline auto FOnResult = PreyFunction<void(ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, const RayCastResult& _result)>(0x1654F00);
};

// ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>
// Header:  Prey/Ark/arkdeferredaction.h
class ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl> : public ArkMoonRockManager::DeferredRayCastImpl
{ // Size=384 (0x180)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>::ImplType
	// Header:  Prey/Ark/arkdeferredaction.h
	class ImplType : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=48 (0x30)
	public:
		unsigned m_propId;
		bool m_bHasPriority;
		unsigned m_targetId;
		int m_requesters;
		bool m_bLastTestSucceeded;
		float m_lastTestTimer;
		Vec3 m_lastRockTestPos;
		Vec3 m_lastTargetTestPos;

	#if 0
		void DeferredRayCastImpl();
		void DeferredRayCastImpl(unsigned _arg0_, unsigned _arg1_);
		RayCastQueue<41>& GetQueue() const;
		bool GetRequest(RayCastRequest& _arg0_) const;
		void OnAborted();
		void OnResult(const RayCastResult& _arg0_);
	#endif
	};

	using QueueType = RayCastQueue<41>;
	using RequestType = RayCastRequest;
	using ResultType = RayCastResult;

	static constexpr const unsigned k_invalidActionId = 4294967295;
	EArkDeferredActionStatus m_status;
	unsigned m_queuedActionId;
	RayCastResult m_result;

	void Begin(RayCastRequest::Priority _priority) { FBegin(this, _priority); }
	void MoveCallbacks() { FMoveCallbacks(this); }
	bool OnSubmit(const unsigned& _queuedActionId, RayCastRequest& _request) { return FOnSubmit(this, _queuedActionId, _request); }
	void OnResult(const unsigned& _queuedActionId, const RayCastResult& _result) { FOnResult(this, _queuedActionId, _result); }

#if 0
	ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>();
	ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>(ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>(const ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>& _arg0_);
	~ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>();
	ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>& operator=(ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>& operator=(const ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>& _arg0_);
	void Cancel();
	void Reset();
	EArkDeferredActionStatus GetStatus() const;
	bool IsPending() const;
	bool IsAborted() const;
	bool IsCompleted() const;
	const RayCastResult& GetResult() const;
	void Expire();
#endif

	static inline auto FBegin = PreyFunction<void(ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>* const _this, RayCastRequest::Priority _priority)>(0x11BAE90);
	static inline auto FMoveCallbacks = PreyFunction<void(ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>* const _this)>(0x11BBF50);
	static inline auto FOnSubmit = PreyFunction<bool(ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, RayCastRequest& _request)>(0x11BC1D0);
	static inline auto FOnResult = PreyFunction<void(ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, const RayCastResult& _result)>(0x11BC120);
};

// ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>
// Header:  Prey/Ark/arkdeferredaction.h
class ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl> : public ArkNpcThrowPropManager::DeferredRayCastImpl
{ // Size=344 (0x158)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>::ImplType
	// Header:  Prey/Ark/arkdeferredaction.h
	class ImplType : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=8 (0x8)
	public:
		unsigned m_propId;
		bool m_bHasPriority;

	#if 0
		void DeferredRayCastImpl();
		void DeferredRayCastImpl(unsigned _arg0_);
		RayCastQueue<41>& GetQueue() const;
		bool GetRequest(RayCastRequest& _arg0_) const;
		void OnAborted();
		void OnResult(const RayCastResult& _arg0_);
	#endif
	};

	using QueueType = RayCastQueue<41>;
	using RequestType = RayCastRequest;
	using ResultType = RayCastResult;

	static constexpr const unsigned k_invalidActionId = 4294967295;
	EArkDeferredActionStatus m_status;
	unsigned m_queuedActionId;
	RayCastResult m_result;

	void Begin(RayCastRequest::Priority _priority) { FBegin(this, _priority); }
	void Cancel() { FCancel(this); }
	bool OnSubmit(const unsigned& _queuedActionId, RayCastRequest& _request) { return FOnSubmit(this, _queuedActionId, _request); }
	void OnResult(const unsigned& _queuedActionId, const RayCastResult& _result) { FOnResult(this, _queuedActionId, _result); }

#if 0
	ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>();
	ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>(ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>(const ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>& _arg0_);
	~ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>();
	ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>& operator=(ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>&& _arg0_);
	ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>& operator=(const ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>& _arg0_);
	void Reset();
	EArkDeferredActionStatus GetStatus() const;
	bool IsPending() const;
	bool IsAborted() const;
	bool IsCompleted() const;
	const RayCastResult& GetResult() const;
	void MoveCallbacks();
	void Expire();
#endif

	static inline auto FBegin = PreyFunction<void(ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>* const _this, RayCastRequest::Priority _priority)>(0x129A100);
	static inline auto FCancel = PreyFunction<void(ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>* const _this)>(0x129A3F0);
	static inline auto FOnSubmit = PreyFunction<bool(ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, RayCastRequest& _request)>(0x129B4C0);
	static inline auto FOnResult = PreyFunction<void(ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>* const _this, const unsigned& _queuedActionId, const RayCastResult& _result)>(0x129B410);
};

// ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>
// Header:  Prey/Ark/arkdeferredaction.h
class ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl> : public NavigationSystem::DeferredHeightCastImpl
{ // Size=96 (0x60)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
	};

	// ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>::ImplType
	// Header:  Prey/Ark/arkdeferredaction.h
	class ImplType : public ArkDeferredActionImpl_IntersectionTest<IntersectionTestQueue<128> >
	{ // Size=48 (0x30)
	public:
		NavigationSystem::DeferredHeightTestId id;
		Vec3 pos;
		float height;
		bool bLargeForm;

		bool IsMeshValid() const { return FIsMeshValid(this); }

	#if 0
		void DeferredHeightCastImpl();
		IntersectionTestQueue<128>& GetQueue() const;
		bool GetRequest(IntersectionTestRequest& _arg0_) const;
		void OnAborted();
		void OnResult(const IntersectionTestResult& _arg0_);
		bool IsWaitingForTileCommit() const;
	#endif

		static inline auto FIsMeshValid = PreyFunction<bool(const NavigationSystem::DeferredHeightCastImpl* const _this)>(0x698BC0);
	};

	using QueueType = IntersectionTestQueue<128>;
	using RequestType = IntersectionTestRequest;
	using ResultType = IntersectionTestResult;

	static constexpr const unsigned k_invalidActionId = 4294967295;
	EArkDeferredActionStatus m_status;
	unsigned m_queuedActionId;
	IntersectionTestResult m_result;

	void Begin(IntersectionTestRequest::Priority _priority) { FBegin(this, _priority); }
	bool OnSubmit(const unsigned& _queuedActionId, IntersectionTestRequest& _request) { return FOnSubmit(this, _queuedActionId, _request); }
	void OnResult(const unsigned& _queuedActionId, const IntersectionTestResult& _result) { FOnResult(this, _queuedActionId, _result); }

#if 0
	ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>();
	ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>(ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>&& _arg0_);
	ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>(const ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>& _arg0_);
	~ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>();
	ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>& operator=(ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>&& _arg0_);
	ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>& operator=(const ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>& _arg0_);
	void Cancel();
	void Reset();
	EArkDeferredActionStatus GetStatus() const;
	bool IsPending() const;
	bool IsAborted() const;
	bool IsCompleted() const;
	const IntersectionTestResult& GetResult() const;
	void MoveCallbacks();
	void Expire();
#endif

	static inline auto FBegin = PreyFunction<void(ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>* const _this, IntersectionTestRequest::Priority _priority)>(0x68B8E0);
	static inline auto FOnSubmit = PreyFunction<bool(ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>* const _this, const unsigned& _queuedActionId, IntersectionTestRequest& _request)>(0x699B00);
	static inline auto FOnResult = PreyFunction<void(ArkDeferredAction<NavigationSystem::DeferredHeightCastImpl>* const _this, const unsigned& _queuedActionId, const IntersectionTestResult& _result)>(0x699940);
};
#endif // MOONCRASH
