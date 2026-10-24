// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryExtension/ClassWeaver.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/GameDll/ProceduralContextHelpers.h>
#include <Prey/CryExtension/TypeList.h>

struct CryGUID;
class IActionController;
struct IAnimationPoseBlenderDir;
struct ICryFactory;
struct IEntity;

// CProceduralContextAim
// Header:  Prey/GameDll/ProceduralContextAim.h
class CProceduralContextAim : public IProceduralContext
{ // Size=96 (0x60)
public:
	// CProceduralContextAim::SPolarCoordinatesSmoothingParametersRequest
	// Header:  Prey/GameDll/ProceduralContextAim.h
	struct SPolarCoordinatesSmoothingParametersRequest
	{ // Size=16 (0x10)
		unsigned id;
		Vec2 maxSmoothRateRadiansPerSecond;
		float smoothTimeSeconds;
	};

	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;
	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;
	using TPolarCoordinatesSmoothingParametersRequestList = ProceduralContextHelpers::CRequestList<CProceduralContextAim::SPolarCoordinatesSmoothingParametersRequest>;

#ifndef MOONCRASH
	static inline auto s_factory = PreyGlobal<CFactory<CProceduralContextAim>>(0x22826C8);
#else
	static inline auto s_factory = PreyGlobal<CFactory<CProceduralContextAim>>(0x23F11C8);
#endif
	IAnimationPoseBlenderDir* m_pPoseBlenderAim;
	bool m_gameRequestsAiming;
	bool m_procClipRequestsAiming;
	Vec3 m_gameAimTarget;
	Vec2 m_defaultPolarCoordinatesMaxSmoothRateRadiansPerSecond;
	float m_defaultPolarCoordinatesSmoothTimeSeconds;
	ProceduralContextHelpers::CRequestList<CProceduralContextAim::SPolarCoordinatesSmoothingParametersRequest> m_polarCoordinatesSmoothingParametersRequestList;

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	virtual ~CProceduralContextAim();
	virtual void Initialise(IEntity& entity, IActionController& actionController);
	virtual void Update(float timePassedSeconds);
	void UpdateGameAimingRequest(const bool aimRequest) { FUpdateGameAimingRequest(this, aimRequest); }
	void UpdateProcClipAimingRequest(const bool aimRequest) { FUpdateProcClipAimingRequest(this, aimRequest); }
	void UpdateGameAimTarget(const Vec3& aimTarget) { FUpdateGameAimTarget(this, aimTarget); }
	void SetBlendInTime(const float blendInTime) { FSetBlendInTime(this, blendInTime); }
	void SetBlendOutTime(const float blendOutTime) { FSetBlendOutTime(this, blendOutTime); }
	unsigned RequestPolarCoordinatesSmoothingParameters(const Vec2& maxSmoothRateRadiansPerSecond, const float smoothTimeSeconds) { return FRequestPolarCoordinatesSmoothingParameters(this, maxSmoothRateRadiansPerSecond, smoothTimeSeconds); }
	void CancelPolarCoordinatesSmoothingParameters(const unsigned requestId) { FCancelPolarCoordinatesSmoothingParameters(this, requestId); }
	void InitialisePoseBlenderAim() { FInitialisePoseBlenderAim(this); }

#if 0
	static const char* GetCName();
	static const CryGUID& GetCID();
	static std::shared_ptr<CProceduralContextAim> CreateClassInstance();
	CProceduralContextAim();
	static const char* GetContextName();
	void InitialiseGameAimTarget();
	void UpdatePolarCoordinatesSmoothingParameters();
#endif

#ifndef MOONCRASH
	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CProceduralContextAim* const _this)>(0x17CDF10);
	static inline auto FQueryInterface = PreyFunction<void* (const CProceduralContextAim* const _this, const CryGUID& iid)>(0x3A9BC0);
	static inline auto FQueryComposite = PreyFunction<void* (const CProceduralContextAim* const _this, const char* name)>(0x158AEF0);
	static inline auto FInitialise = PreyFunction<void(CProceduralContextAim* const _this, IEntity& entity, IActionController& actionController)>(0x17CDF20);
	static inline auto FUpdate = PreyFunction<void(CProceduralContextAim* const _this, float timePassedSeconds)>(0x17CDFE0);
	static inline auto FUpdateGameAimingRequest = PreyFunction<void(CProceduralContextAim* const _this, const bool aimRequest)>(0x359F20);
	static inline auto FUpdateProcClipAimingRequest = PreyFunction<void(CProceduralContextAim* const _this, const bool aimRequest)>(0x710650);
	static inline auto FUpdateGameAimTarget = PreyFunction<void(CProceduralContextAim* const _this, const Vec3& aimTarget)>(0x17CEB90);
	static inline auto FSetBlendInTime = PreyFunction<void(CProceduralContextAim* const _this, const float blendInTime)>(0x17CEB50);
	static inline auto FSetBlendOutTime = PreyFunction<void(CProceduralContextAim* const _this, const float blendOutTime)>(0x17CEB70);
	static inline auto FRequestPolarCoordinatesSmoothingParameters = PreyFunction<unsigned(CProceduralContextAim* const _this, const Vec2& maxSmoothRateRadiansPerSecond, const float smoothTimeSeconds)>(0x17CEB00);
	static inline auto FCancelPolarCoordinatesSmoothingParameters = PreyFunction<void(CProceduralContextAim* const _this, const unsigned requestId)>(0x17CE400);
	static inline auto FInitialisePoseBlenderAim = PreyFunction<void(CProceduralContextAim* const _this)>(0x17CE460);
#else
	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CProceduralContextAim* const _this)>(0x18F4A70);
	static inline auto FQueryInterface = PreyFunction<void* (const CProceduralContextAim* const _this, const CryGUID& iid)>(0x18F70B0);
	static inline auto FQueryComposite = PreyFunction<void* (const CProceduralContextAim* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FInitialise = PreyFunction<void(CProceduralContextAim* const _this, IEntity& entity, IActionController& actionController)>(0x18F4A80);
	static inline auto FUpdate = PreyFunction<void(CProceduralContextAim* const _this, float timePassedSeconds)>(0x18F4B40);
	static inline auto FUpdateGameAimingRequest = PreyFunction<void(CProceduralContextAim* const _this, const bool aimRequest)>(0x374600);
	static inline auto FUpdateProcClipAimingRequest = PreyFunction<void(CProceduralContextAim* const _this, const bool aimRequest)>(0x18F58C0);
	static inline auto FUpdateGameAimTarget = PreyFunction<void(CProceduralContextAim* const _this, const Vec3& aimTarget)>(0x10ED6A0);
	static inline auto FSetBlendInTime = PreyFunction<void(CProceduralContextAim* const _this, const float blendInTime)>(0x18F5880);
	static inline auto FSetBlendOutTime = PreyFunction<void(CProceduralContextAim* const _this, const float blendOutTime)>(0x18F58A0);
	static inline auto FRequestPolarCoordinatesSmoothingParameters = PreyFunction<unsigned(CProceduralContextAim* const _this, const Vec2& maxSmoothRateRadiansPerSecond, const float smoothTimeSeconds)>(0x18F5830);
	static inline auto FCancelPolarCoordinatesSmoothingParameters = PreyFunction<void(CProceduralContextAim* const _this, const unsigned requestId)>(0x18F5130);
	static inline auto FInitialisePoseBlenderAim = PreyFunction<void(CProceduralContextAim* const _this)>(0x18F5190);
#endif
};

