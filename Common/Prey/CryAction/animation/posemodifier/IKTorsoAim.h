// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryExtension/ClassWeaver.h>
#include <Prey/CryAnimation/IAnimationPoseModifier.h>
#include <Prey/CryExtension/TypeList.h>

struct CryGUID;
struct ICryFactory;
class ICrySizer;
struct SAnimationPoseModifierParams;

// CIKTorsoAim
// Header:  CryEngine/cryaction/animation/posemodifier/IKTorsoAim.h
class CIKTorsoAim : public IAnimationPoseModifier
{ // Size=264 (0x108)
public:
	// CIKTorsoAim::SParams
	// Header:  CryEngine/cryaction/animation/posemodifier/IKTorsoAim.h
	struct SParams
	{ // Size=96 (0x60)
		QuatT viewOffset;
		Vec3 targetDirection;
		Vec3 absoluteTargetPosition;
		float baseAnimTrackFactor;
		float weights[5];
		float blend;
		float blendPosition;
		int numParents;
		int effectorJoint;
		int aimJoint;

	#if 0
		SParams();
	#endif
	};

	// CIKTorsoAim::STorsoAim_CVars
	// Header:  CryEngine/cryaction/animation/posemodifier/IKTorsoAim.h
	struct STorsoAim_CVars
	{ // Size=28 (0x1C)
		int STAP_DEBUG;
		int STAP_DISABLE;
		int STAP_TRANSLATION_FUDGE;
		int STAP_TRANSLATION_FEATHER;
		int STAP_LOCK_EFFECTOR;
		float STAP_OVERRIDE_TRACK_FACTOR;
		bool m_initialized;

		~STorsoAim_CVars();

	#if 0
		STorsoAim_CVars();
		void InitCvars();
		void ReleaseCVars();
	#endif

#ifndef MOONCRASH
		static inline auto FBitNotSTorsoAim_CVars = PreyFunction<void(CIKTorsoAim::STorsoAim_CVars* const _this)>(0xA13080);
#else
		static inline auto FBitNotSTorsoAim_CVars = PreyFunction<void(CIKTorsoAim::STorsoAim_CVars* const _this)>(0x1333E90);
#endif
	};

	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IAnimationPoseModifier,TL::NullType> >;
	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IAnimationPoseModifier,TL::NullType> >;

#ifndef MOONCRASH
	static inline auto s_factory = PreyGlobal<CFactory<CIKTorsoAim>>(0x224A320);
#else
	static inline auto s_factory = PreyGlobal<CFactory<CIKTorsoAim>>(0x23B7360);
#endif
	CIKTorsoAim::SParams m_params;
	CIKTorsoAim::SParams m_setParams;
	bool m_active;
	bool m_blending;
	float m_blendRate;
	Vec3 m_aimToEffector;
	Quat m_effectorDirQuat;
	QuatT m_lastProcessedEffector;
#ifndef MOONCRASH
	static inline auto s_CVars = PreyGlobal<CIKTorsoAim::STorsoAim_CVars>(0x249EF18);
#else
	static inline auto s_CVars = PreyGlobal<CIKTorsoAim::STorsoAim_CVars>(0x260E538);
#endif

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	virtual ~CIKTorsoAim();
	static void InitCVars() { FInitCVars(); }
	virtual void SetBlendWeight(float blend);
	virtual void SetBlendWeightPosition(float blendPos);
	virtual void SetTargetDirection(const Vec3& direction);
	virtual void SetViewOffset(const QuatT& offset);
	virtual void SetAbsoluteTargetPosition(const Vec3& targetPosition);
	virtual void SetFeatherWeights(unsigned weights, const float* customBlends);
	virtual void SetJoints(unsigned jntEffector, unsigned jntAdjustment);
	virtual void SetBaseAnimTrackFactor(float factor);
	virtual bool Prepare(const SAnimationPoseModifierParams& params);
	virtual bool Execute(const SAnimationPoseModifierParams& params);
	virtual void Synchronize();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;

#if 0
	static const char* GetCName();
	static const CryGUID& GetCID();
	static std::shared_ptr<CIKTorsoAim> CreateClassInstance();
	CIKTorsoAim();
	void Enable(bool _arg0_);
	const QuatT& GetLastProcessedEffector() const;
	void Init();
#endif

#ifndef MOONCRASH
	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CIKTorsoAim* const _this)>(0x594F20);
	static inline auto FQueryInterface = PreyFunction<void* (const CIKTorsoAim* const _this, const CryGUID& iid)>(0x86D150);
	static inline auto FQueryComposite = PreyFunction<void* (const CIKTorsoAim* const _this, const char* name)>(0x158AEF0);
	static inline auto FInitCVars = PreyFunction<void()>(0x597B30);
	static inline auto FSetBlendWeight = PreyFunction<void(CIKTorsoAim* const _this, float blend)>(0x870520);
	static inline auto FSetBlendWeightPosition = PreyFunction<void(CIKTorsoAim* const _this, float blendPos)>(0x18E6F00);
	static inline auto FSetTargetDirection = PreyFunction<void(CIKTorsoAim* const _this, const Vec3& direction)>(0x594F30);
	static inline auto FSetViewOffset = PreyFunction<void(CIKTorsoAim* const _this, const QuatT& offset)>(0x594F50);
	static inline auto FSetAbsoluteTargetPosition = PreyFunction<void(CIKTorsoAim* const _this, const Vec3& targetPosition)>(0x594F80);
	static inline auto FSetFeatherWeights = PreyFunction<void(CIKTorsoAim* const _this, unsigned weights, const float* customBlends)>(0x594FA0);
	static inline auto FSetJoints = PreyFunction<void(CIKTorsoAim* const _this, unsigned jntEffector, unsigned jntAdjustment)>(0x594FE0);
	static inline auto FSetBaseAnimTrackFactor = PreyFunction<void(CIKTorsoAim* const _this, float factor)>(0x8705E0);
	static inline auto FPrepare = PreyFunction<bool(CIKTorsoAim* const _this, const SAnimationPoseModifierParams& params)>(0x594FF0);
	static inline auto FExecute = PreyFunction<bool(CIKTorsoAim* const _this, const SAnimationPoseModifierParams& params)>(0x5951E0);
	static inline auto FSynchronize = PreyFunction<void(CIKTorsoAim* const _this)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CIKTorsoAim* const _this, ICrySizer* pSizer)>(0x31A090);
#else
	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CIKTorsoAim* const _this)>(0x5AE450);
	static inline auto FQueryInterface = PreyFunction<void* (const CIKTorsoAim* const _this, const CryGUID& iid)>(0x5B1070);
	static inline auto FQueryComposite = PreyFunction<void* (const CIKTorsoAim* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FInitCVars = PreyFunction<void()>(0x5B0E50);
	static inline auto FSetBlendWeight = PreyFunction<void(CIKTorsoAim* const _this, float blend)>(0x5AE460);
	static inline auto FSetBlendWeightPosition = PreyFunction<void(CIKTorsoAim* const _this, float blendPos)>(0x1A0EBD0);
	static inline auto FSetTargetDirection = PreyFunction<void(CIKTorsoAim* const _this, const Vec3& direction)>(0x5AE470);
	static inline auto FSetViewOffset = PreyFunction<void(CIKTorsoAim* const _this, const QuatT& offset)>(0x5AE490);
	static inline auto FSetAbsoluteTargetPosition = PreyFunction<void(CIKTorsoAim* const _this, const Vec3& targetPosition)>(0x5AE4C0);
	static inline auto FSetFeatherWeights = PreyFunction<void(CIKTorsoAim* const _this, unsigned weights, const float* customBlends)>(0x5AE4E0);
	static inline auto FSetJoints = PreyFunction<void(CIKTorsoAim* const _this, unsigned jntEffector, unsigned jntAdjustment)>(0x5AE520);
	static inline auto FSetBaseAnimTrackFactor = PreyFunction<void(CIKTorsoAim* const _this, float factor)>(0x5AE530);
	static inline auto FPrepare = PreyFunction<bool(CIKTorsoAim* const _this, const SAnimationPoseModifierParams& params)>(0x5AE540);
	static inline auto FExecute = PreyFunction<bool(CIKTorsoAim* const _this, const SAnimationPoseModifierParams& params)>(0x5AE730);
	static inline auto FSynchronize = PreyFunction<void(CIKTorsoAim* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CIKTorsoAim* const _this, ICrySizer* pSizer)>(0x334850);
#endif
};

