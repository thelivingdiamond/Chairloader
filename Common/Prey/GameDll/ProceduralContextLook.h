// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryextension/impl/classweaver.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/TL__Typelist.h>

struct CryGUID;
class IActionController;
struct IAnimationPoseBlenderDir;
struct ICryFactory;
struct IEntity;

// CProceduralContextLook
// Header:  Prey/GameDll/ProceduralContextLook.h
class CProceduralContextLook : public IProceduralContext
{ // Size=56 (0x38)
public:
	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;
	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;

	static inline auto s_factory = PreyGlobal<CFactory<CProceduralContextLook>>(0x23F1218);
	CProceduralContextLook* m_pParentContext;
	IAnimationPoseBlenderDir* m_pPoseBlenderLook;
	bool m_gameRequestsLooking;
	bool m_procClipRequestsLooking;
	Vec3 m_gameLookTarget;

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	virtual ~CProceduralContextLook();
	virtual void Initialise(IEntity& entity, IActionController& actionController);
	virtual void Update(float timePassedSeconds);
	void UpdateGameLookingRequest(const bool lookRequest) { FUpdateGameLookingRequest(this, lookRequest); }
	void UpdateProcClipLookingRequest(const bool lookRequest) { FUpdateProcClipLookingRequest(this, lookRequest); }
	void UpdateGameLookTarget(const Vec3& lookTarget) { FUpdateGameLookTarget(this, lookTarget); }
	void SetBlendInTime(const float blendInTime) { FSetBlendInTime(this, blendInTime); }
	void SetBlendOutTime(const float blendOutTime) { FSetBlendOutTime(this, blendOutTime); }
	virtual void InitialisePoseBlenderLook();
	void InitialisePoseBlenderLookParams() { FInitialisePoseBlenderLookParams(this); }
	virtual const char* GetParamSectionName();

#if 0
	static const char* GetCName();
	static const CryGUID& GetCID();
	static std::shared_ptr<CProceduralContextLook> CreateClassInstance();
	CProceduralContextLook();
	static const char* GetContextName();
	void SetFovRadians(const float _arg0_);
	void SetParentContext(CProceduralContextLook* _arg0_);
	void InitialiseGameLookTarget();
#endif

	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CProceduralContextLook* const _this)>(0x18F5EE0);
	static inline auto FQueryInterface = PreyFunction<void* (const CProceduralContextLook* const _this, const CryGUID& iid)>(0x18F70B0);
	static inline auto FQueryComposite = PreyFunction<void* (const CProceduralContextLook* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FInitialise = PreyFunction<void(CProceduralContextLook* const _this, IEntity& entity, IActionController& actionController)>(0x18F5EF0);
	static inline auto FUpdate = PreyFunction<void(CProceduralContextLook* const _this, float timePassedSeconds)>(0x18F5FC0);
	static inline auto FUpdateGameLookingRequest = PreyFunction<void(CProceduralContextLook* const _this, const bool lookRequest)>(0x874EB0);
	static inline auto FUpdateProcClipLookingRequest = PreyFunction<void(CProceduralContextLook* const _this, const bool lookRequest)>(0x18F7080);
	static inline auto FUpdateGameLookTarget = PreyFunction<void(CProceduralContextLook* const _this, const Vec3& lookTarget)>(0x18F7070);
	static inline auto FSetBlendInTime = PreyFunction<void(CProceduralContextLook* const _this, const float blendInTime)>(0x18F7030);
	static inline auto FSetBlendOutTime = PreyFunction<void(CProceduralContextLook* const _this, const float blendOutTime)>(0x18F7050);
	static inline auto FInitialisePoseBlenderLook = PreyFunction<void(CProceduralContextLook* const _this)>(0x18F6030);
	static inline auto FInitialisePoseBlenderLookParams = PreyFunction<void(CProceduralContextLook* const _this)>(0x18F6990);
	static inline auto FGetParamSectionName = PreyFunction<const char* (CProceduralContextLook* const _this)>(0x18F3E40);
};

// CProceduralContextLookEyes
// Header:  Prey/GameDll/ProceduralContextLook.h
class CProceduralContextLookEyes : public CProceduralContextLook
{ // Size=56 (0x38)
public:
	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;
	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;

	static inline auto s_factory = PreyGlobal<CFactory<CProceduralContextLookEyes>>(0x23F1268);

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	virtual ~CProceduralContextLookEyes();
	virtual void InitialisePoseBlenderLook();
	virtual const char* GetParamSectionName();

#if 0
	static const char* GetCName();
	static const CryGUID& GetCID();
	static std::shared_ptr<CProceduralContextLookEyes> CreateClassInstance();
	CProceduralContextLookEyes();
	static const char* GetContextName();
#endif

	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CProceduralContextLookEyes* const _this)>(0x18F6470);
	static inline auto FQueryInterface = PreyFunction<void* (const CProceduralContextLookEyes* const _this, const CryGUID& iid)>(0x18F70B0);
	static inline auto FQueryComposite = PreyFunction<void* (const CProceduralContextLookEyes* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FInitialisePoseBlenderLook = PreyFunction<void(CProceduralContextLookEyes* const _this)>(0x18F6480);
	static inline auto FGetParamSectionName = PreyFunction<const char* (CProceduralContextLookEyes* const _this)>(0x18F64D0);
};

// CProceduralContextLookHead
// Header:  Prey/GameDll/ProceduralContextLook.h
class CProceduralContextLookHead : public CProceduralContextLook
{ // Size=56 (0x38)
public:
	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;
	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;

	static inline auto s_factory = PreyGlobal<CFactory<CProceduralContextLookHead>>(0x23F1240);

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	virtual ~CProceduralContextLookHead();
	virtual void InitialisePoseBlenderLook();
	virtual const char* GetParamSectionName();

#if 0
	static const char* GetCName();
	static const CryGUID& GetCID();
	static std::shared_ptr<CProceduralContextLookHead> CreateClassInstance();
	CProceduralContextLookHead();
	static const char* GetContextName();
#endif

	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CProceduralContextLookHead* const _this)>(0x18F6240);
	static inline auto FQueryInterface = PreyFunction<void* (const CProceduralContextLookHead* const _this, const CryGUID& iid)>(0x18F70B0);
	static inline auto FQueryComposite = PreyFunction<void* (const CProceduralContextLookHead* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FInitialisePoseBlenderLook = PreyFunction<void(CProceduralContextLookHead* const _this)>(0x18F6250);
	static inline auto FGetParamSectionName = PreyFunction<const char* (CProceduralContextLookHead* const _this)>(0x18F62A0);
};
#endif // MOONCRASH
