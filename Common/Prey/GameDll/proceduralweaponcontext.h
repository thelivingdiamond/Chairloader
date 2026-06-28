// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryextension/impl/classweaver.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/GameDll/ProceduralWeaponAnimation.h>
#include <_unknown/TL__Typelist.h>

struct CryGUID;
struct ICryFactory;
struct IDefaultSkeleton;
class IScope;

// CProceduralWeaponAnimationContext
// Header:  Prey/GameDll/proceduralweaponcontext.h
class CProceduralWeaponAnimationContext : public IProceduralContext
{ // Size=888 (0x378)
public:
	// CProceduralWeaponAnimationContext::SParams
	// Header:  Prey/GameDll/proceduralweaponcontext.h
	struct SParams
	{ // Size=12 (0xC)
		int m_weaponTargetIdx;
		int m_leftHandTargetIdx;
		int m_rightBlendIkIdx;

	#if 0
		SParams();
		SParams(IDefaultSkeleton& _arg0_);
	#endif
	};

	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;
	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;

	static inline auto s_factory = PreyGlobal<CFactory<CProceduralWeaponAnimationContext>>(0x23F1358);
	CProceduralWeaponAnimationContext::SParams m_params;
	std::shared_ptr<IAnimationOperatorQueue> m_pPoseModifier;
	IScope* m_pScope;
	CProceduralWeaponAnimation m_weaponSway;
	Vec3 m_aimDirection;
	int m_instanceCount;

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	virtual ~CProceduralWeaponAnimationContext();
	virtual void Update(float timePassed);
	void SetAimDirection(Vec3 direction) { FSetAimDirection(this, direction); }
	void Initialize(IScope* pScope) { FInitialize(this, pScope); }
	void Finalize() { FFinalize(this); }

#if 0
	static const char* GetCName();
	static const CryGUID& GetCID();
	static std::shared_ptr<CProceduralWeaponAnimationContext> CreateClassInstance();
	CProceduralWeaponAnimationContext();
	static const char* GetContextName();
	CProceduralWeaponAnimation& GetWeaponSway();
#endif

	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CProceduralWeaponAnimationContext* const _this)>(0x18FBAC0);
	static inline auto FQueryInterface = PreyFunction<void* (const CProceduralWeaponAnimationContext* const _this, const CryGUID& iid)>(0x18F70B0);
	static inline auto FQueryComposite = PreyFunction<void* (const CProceduralWeaponAnimationContext* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FBitNotCProceduralWeaponAnimationContext = PreyFunction<void(CProceduralWeaponAnimationContext* const _this)>(0x18FC800);
	static inline auto FUpdate = PreyFunction<void(CProceduralWeaponAnimationContext* const _this, float timePassed)>(0x18FBAD0);
	static inline auto FSetAimDirection = PreyFunction<void(CProceduralWeaponAnimationContext* const _this, Vec3 direction)>(0x18FC990);
	static inline auto FInitialize = PreyFunction<void(CProceduralWeaponAnimationContext* const _this, IScope* pScope)>(0x18FC8E0);
	static inline auto FFinalize = PreyFunction<void(CProceduralWeaponAnimationContext* const _this)>(0x18FC8D0);
};
#endif // MOONCRASH
