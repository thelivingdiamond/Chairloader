// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryExtension/ClassWeaver.h>
#include <Prey/CryAnimation/IAnimationPoseModifier.h>
#include <Prey/CryExtension/TypeList.h>

struct CryGUID;
struct ICryFactory;
class ICrySizer;
struct IDefaultSkeleton;
struct SAnimationPoseModifierParams;

namespace AnimPoseModifier
{

// AnimPoseModifier::CLookAtSimple
// Header:  CryEngine/cryaction/animation/posemodifier/LookAtSimple.h
class CLookAtSimple : public IAnimationPoseModifier
{ // Size=72 (0x48)
public:
	// AnimPoseModifier::CLookAtSimple::State
	// Header:  CryEngine/cryaction/animation/posemodifier/LookAtSimple.h
	struct State
	{ // Size=32 (0x20)
		int jointId;
		Vec3 jointOffsetRelative;
		Vec3 targetGlobal;
		float weight;
	};

	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IAnimationPoseModifier,TL::NullType> >;
	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IAnimationPoseModifier,TL::NullType> >;

#ifndef MOONCRASH
	static inline auto s_factory = PreyGlobal<CFactory<AnimPoseModifier::CLookAtSimple>>(0x224A348);
#else
	static inline auto s_factory = PreyGlobal<CFactory<AnimPoseModifier::CLookAtSimple>>(0x23B7388);
#endif
	AnimPoseModifier::CLookAtSimple::State m_state;
	AnimPoseModifier::CLookAtSimple::State m_stateExecute;

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	virtual ~CLookAtSimple();
	virtual bool Prepare(const SAnimationPoseModifierParams& params);
	virtual bool Execute(const SAnimationPoseModifierParams& params);
	virtual void Synchronize();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;

#if 0
	static const char* GetCName();
	static const CryGUID& GetCID();
	static std::shared_ptr<AnimPoseModifier::CLookAtSimple> CreateClassInstance();
	CLookAtSimple();
	void SetJointId(unsigned _arg0_);
	void SetJointOffsetRelative(const Vec3& _arg0_);
	void SetTargetGlobal(const Vec3& _arg0_);
	void SetWeight(float _arg0_);
	bool ValidateJointId(IDefaultSkeleton& _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FGetFactory = PreyFunction<ICryFactory* (const AnimPoseModifier::CLookAtSimple* const _this)>(0x597CE0);
	static inline auto FQueryInterface = PreyFunction<void* (const AnimPoseModifier::CLookAtSimple* const _this, const CryGUID& iid)>(0x86D150);
	static inline auto FQueryComposite = PreyFunction<void* (const AnimPoseModifier::CLookAtSimple* const _this, const char* name)>(0x158AEF0);
	static inline auto FPrepare = PreyFunction<bool(AnimPoseModifier::CLookAtSimple* const _this, const SAnimationPoseModifierParams& params)>(0x597CF0);
	static inline auto FExecute = PreyFunction<bool(AnimPoseModifier::CLookAtSimple* const _this, const SAnimationPoseModifierParams& params)>(0x597D10);
	static inline auto FSynchronize = PreyFunction<void(AnimPoseModifier::CLookAtSimple* const _this)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(const AnimPoseModifier::CLookAtSimple* const _this, ICrySizer* pSizer)>(0x345AA0);
#else
	static inline auto FGetFactory = PreyFunction<ICryFactory* (const AnimPoseModifier::CLookAtSimple* const _this)>(0x5B1060);
	static inline auto FQueryInterface = PreyFunction<void* (const AnimPoseModifier::CLookAtSimple* const _this, const CryGUID& iid)>(0x5B1070);
	static inline auto FQueryComposite = PreyFunction<void* (const AnimPoseModifier::CLookAtSimple* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FPrepare = PreyFunction<bool(AnimPoseModifier::CLookAtSimple* const _this, const SAnimationPoseModifierParams& params)>(0x5B10D0);
	static inline auto FExecute = PreyFunction<bool(AnimPoseModifier::CLookAtSimple* const _this, const SAnimationPoseModifierParams& params)>(0x5B10F0);
	static inline auto FSynchronize = PreyFunction<void(AnimPoseModifier::CLookAtSimple* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const AnimPoseModifier::CLookAtSimple* const _this, ICrySizer* pSizer)>(0x35A360);
#endif
};


} // namespace AnimPoseModifier

