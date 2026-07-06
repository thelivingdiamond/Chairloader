// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryextension/impl/classweaver.h>
#include <_unknown/ITransformationPinning.h>
#include <_unknown/TL__Typelist.h>

struct CryGUID;
struct ICharacterInstance;
struct ICryFactory;
class ICrySizer;
struct SAnimationPoseModifierParams;

// CTransformationPinning
// Header:  Prey/GameDll/TransformationPinning.h
class CTransformationPinning : public ITransformationPinning
{ // Size=48 (0x30)
public:
	// CTransformationPinning::TransformationPinJoint
	// Header:  Prey/GameDll/TransformationPinning.h
	struct TransformationPinJoint
	{ // Size=1 (0x1)
		enum class Type
		{
			Copy = 67,
			Feather = 70,
			Inherit = 73,
		};

	};

	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IAnimationPoseModifier,TL::Typelist<ITransformationPinning,TL::NullType> > >;
	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IAnimationPoseModifier,TL::Typelist<ITransformationPinning,TL::NullType> > >;

	static inline auto s_factory = PreyGlobal<CFactory<CTransformationPinning>>(0x23F1388);
	float m_factor;
	unsigned m_jointID;
	char* m_jointTypes;
	unsigned m_numJoints;
	ICharacterInstance* m_source;
	bool m_jointsInitialised;

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	virtual ~CTransformationPinning();
	virtual void SetBlendWeight(float factor);
	virtual void SetJoint(unsigned jntID);
	virtual void SetSource(ICharacterInstance* source);
	virtual bool Prepare(const SAnimationPoseModifierParams& params);
	virtual bool Execute(const SAnimationPoseModifierParams& params);
	virtual void Synchronize();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;

#if 0
	static const char* GetCName();
	static const CryGUID& GetCID();
	static std::shared_ptr<CTransformationPinning> CreateClassInstance();
	CTransformationPinning();
	void Init(const SAnimationPoseModifierParams& _arg0_);
#endif

	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CTransformationPinning* const _this)>(0x191FC00);
	static inline auto FQueryInterface = PreyFunction<void* (const CTransformationPinning* const _this, const CryGUID& iid)>(0x191FC10);
	static inline auto FQueryComposite = PreyFunction<void* (const CTransformationPinning* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FSetBlendWeight = PreyFunction<void(CTransformationPinning* const _this, float factor)>(0x1396E40);
	static inline auto FSetJoint = PreyFunction<void(CTransformationPinning* const _this, unsigned jntID)>(0x191FC90);
	static inline auto FSetSource = PreyFunction<void(CTransformationPinning* const _this, ICharacterInstance* source)>(0x191FCA0);
	static inline auto FPrepare = PreyFunction<bool(CTransformationPinning* const _this, const SAnimationPoseModifierParams& params)>(0x1A302A0);
	static inline auto FExecute = PreyFunction<bool(CTransformationPinning* const _this, const SAnimationPoseModifierParams& params)>(0x191FCB0);
	static inline auto FSynchronize = PreyFunction<void(CTransformationPinning* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CTransformationPinning* const _this, ICrySizer* pSizer)>(0x4BAFC0);
};
#endif // MOONCRASH
