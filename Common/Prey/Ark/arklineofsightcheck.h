// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/Ark/arkdeferredaction.h>
#include <Prey/GameDll/ark/signalsystem/arksignalmanager.h>
#include <_unknown/ArkDeferredActionImpl_RayCast.h>
#include <_unknown/ArkVisualPerceptionManager__LineOfSightCheckImpl.h>
#include <_unknown/RayCastQueue.h>
#include <_unknown/RayCastRequest.h>

struct RayCastRequest;
struct RayCastResult;

// ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>
// Header:  Prey/Ark/arklineofsightcheck.h
class ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1> : public ArkSignalSystem::Manager::AreaTargetLOSCheckImpl
{ // Size=392 (0x188)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl
	// Header:  Prey/Ark/arklineofsightcheck.h
	class DeferredRayCastImpl : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=16 (0x10)
	public:
		ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>* m_pLineOfSightCheck;
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
	using DeferredRayCast = ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>::DeferredRayCastImpl>;
	using DeferredRayCastArray = std::array<ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl, 1>::DeferredRayCastImpl>, 1>;

	EArkLineOfSightCheckStatus m_status;
	EArkLineOfSightCheckPolicy m_policy;
	std::array<ArkDeferredAction<ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl, 1>::DeferredRayCastImpl>, 1> m_rayCasts;

	ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>();
	void Begin(RayCastRequest::Priority _priority, EArkLineOfSightCheckPolicy _policy) { FBegin(this, _priority, _policy); }
	void CancelPendingRayCasts() { FCancelPendingRayCasts(this); }

#if 0
	ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>(ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>&& _arg0_);
	ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>(const ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>& _arg0_);
	~ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>();
	ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>& operator=(ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>&& _arg0_);
	ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>& operator=(const ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>& _arg0_);
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

	static inline auto FArkLineOfSightCheckLessArkSignalSystem::Manager::AreaTargetLOSCheckImplComma1GreaterOv2 = PreyFunction<void(ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>* const _this)>(0x16FFFC0);
	static inline auto FBegin = PreyFunction<void(ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>* const _this, RayCastRequest::Priority _priority, EArkLineOfSightCheckPolicy _policy)>(0x17015E0);
	static inline auto FCancelPendingRayCasts = PreyFunction<void(ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>* const _this)>(0x1701AB0);
};

// ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>
// Header:  Prey/Ark/arklineofsightcheck.h
class ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1> : public ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>
{ // Size=376 (0x178)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl
	// Header:  Prey/Ark/arklineofsightcheck.h
	class DeferredRayCastImpl : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=16 (0x10)
	public:
		ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>* m_pLineOfSightCheck;
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
	using DeferredRayCast = ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>::DeferredRayCastImpl>;
	using DeferredRayCastArray = std::array<ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>, 1>::DeferredRayCastImpl>, 1>;

	EArkLineOfSightCheckStatus m_status;
	EArkLineOfSightCheckPolicy m_policy;
	std::array<ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>, 1>::DeferredRayCastImpl>, 1> m_rayCasts;

	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>&& _other);
	void CancelPendingRayCasts() { FCancelPendingRayCasts(this); }

#if 0
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>();
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>(const ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>& _arg0_);
	~ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>();
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>& operator=(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>&& _arg0_);
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>& operator=(const ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>& _arg0_);
	void Begin(RayCastRequest::Priority _arg0_, EArkLineOfSightCheckPolicy _arg1_);
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

	static inline auto FArkLineOfSightCheckLessArkVisualPerceptionManager::LineOfSightCheckImplLessArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImplGreaterComma1GreaterOv1 = PreyFunction<void(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>* const _this, ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>&& _other)>(0x164DBF0);
	static inline auto FCancelPendingRayCasts = PreyFunction<void(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl>,1>* const _this)>(0x1652AD0);
};

// ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>
// Header:  Prey/Ark/arklineofsightcheck.h
class ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2> : public ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>
{ // Size=728 (0x2D8)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl
	// Header:  Prey/Ark/arklineofsightcheck.h
	class DeferredRayCastImpl : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=16 (0x10)
	public:
		ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>* m_pLineOfSightCheck;
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
	using DeferredRayCast = ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>::DeferredRayCastImpl>;
	using DeferredRayCastArray = std::array<ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>, 2>::DeferredRayCastImpl>, 2>;

	EArkLineOfSightCheckStatus m_status;
	EArkLineOfSightCheckPolicy m_policy;
	std::array<ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>, 2>::DeferredRayCastImpl>, 2> m_rayCasts;

	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>&& _other);
	void CancelPendingRayCasts() { FCancelPendingRayCasts(this); }

#if 0
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>();
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>(const ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>& _arg0_);
	~ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>();
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>& operator=(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>&& _arg0_);
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>& operator=(const ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>& _arg0_);
	void Begin(RayCastRequest::Priority _arg0_, EArkLineOfSightCheckPolicy _arg1_);
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

	static inline auto FArkLineOfSightCheckLessArkVisualPerceptionManager::LineOfSightCheckImplLessArkVisualPerceptionManager::ComplexAllLineOfSightCheckImplGreaterComma2GreaterOv1 = PreyFunction<void(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>* const _this, ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>&& _other)>(0x164DE90);
	static inline auto FCancelPendingRayCasts = PreyFunction<void(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl>,2>* const _this)>(0x1652A60);
};

// ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>
// Header:  Prey/Ark/arklineofsightcheck.h
class ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2> : public ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>
{ // Size=728 (0x2D8)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl
	// Header:  Prey/Ark/arklineofsightcheck.h
	class DeferredRayCastImpl : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=16 (0x10)
	public:
		ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>* m_pLineOfSightCheck;
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
	using DeferredRayCast = ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>::DeferredRayCastImpl>;
	using DeferredRayCastArray = std::array<ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>, 2>::DeferredRayCastImpl>, 2>;

	EArkLineOfSightCheckStatus m_status;
	EArkLineOfSightCheckPolicy m_policy;
	std::array<ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>, 2>::DeferredRayCastImpl>, 2> m_rayCasts;

	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>&& _other);
	void CancelPendingRayCasts() { FCancelPendingRayCasts(this); }

#if 0
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>();
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>(const ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>& _arg0_);
	~ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>();
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>& operator=(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>&& _arg0_);
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>& operator=(const ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>& _arg0_);
	void Begin(RayCastRequest::Priority _arg0_, EArkLineOfSightCheckPolicy _arg1_);
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

	static inline auto FArkLineOfSightCheckLessArkVisualPerceptionManager::LineOfSightCheckImplLessArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImplGreaterComma2GreaterOv1 = PreyFunction<void(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>* const _this, ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>&& _other)>(0x164E150);
	static inline auto FCancelPendingRayCasts = PreyFunction<void(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl>,2>* const _this)>(0x1652A60);
};

// ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>
// Header:  Prey/Ark/arklineofsightcheck.h
class ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1> : public ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>
{ // Size=376 (0x178)
public:
	enum class PriorityType
	{
		LowPriority = 0,
		MediumPriority = 1,
		HighPriority = 2,
		HighestPriority = 3,
		TotalNumberOfPriorities = 4,
	};

	// ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl
	// Header:  Prey/Ark/arklineofsightcheck.h
	class DeferredRayCastImpl : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=16 (0x10)
	public:
		ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>* m_pLineOfSightCheck;
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
	using DeferredRayCast = ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>::DeferredRayCastImpl>;
	using DeferredRayCastArray = std::array<ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>, 1>::DeferredRayCastImpl>, 1>;

	EArkLineOfSightCheckStatus m_status;
	EArkLineOfSightCheckPolicy m_policy;
	std::array<ArkDeferredAction<ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>, 1>::DeferredRayCastImpl>, 1> m_rayCasts;

	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>&& _other);
	void Begin(RayCastRequest::Priority _priority, EArkLineOfSightCheckPolicy _policy) { FBegin(this, _priority, _policy); }
	void CancelPendingRayCasts() { FCancelPendingRayCasts(this); }

#if 0
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>();
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>(const ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>& _arg0_);
	~ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>();
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>& operator=(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>&& _arg0_);
	ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>& operator=(const ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>& _arg0_);
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

	static inline auto FArkLineOfSightCheckLessArkVisualPerceptionManager::LineOfSightCheckImplLessArkVisualPerceptionManager::SimpleLineOfSightCheckImplGreaterComma1GreaterOv1 = PreyFunction<void(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>* const _this, ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>&& _other)>(0x164E410);
	static inline auto FBegin = PreyFunction<void(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>* const _this, RayCastRequest::Priority _priority, EArkLineOfSightCheckPolicy _policy)>(0x1652160);
	static inline auto FCancelPendingRayCasts = PreyFunction<void(ArkLineOfSightCheck<ArkVisualPerceptionManager::LineOfSightCheckImpl<ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl>,1>* const _this)>(0x1652AD0);
};
#endif // MOONCRASH
