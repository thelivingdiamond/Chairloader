// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryextension/impl/classweaver.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/TL__Typelist.h>

struct CryGUID;
struct IActor;
struct ICryFactory;

// CProceduralContextRagdoll
// Header:  Prey/GameDll/ProceduralContextRagdoll.h
class CProceduralContextRagdoll : public IProceduralContext
{ // Size=48 (0x30)
public:
	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;
	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;

	static inline auto s_factory = PreyGlobal<CFactory<CProceduralContextRagdoll>>(0x23F12B8);
	unsigned m_targetEntityId;
	float m_stiffness;
	float m_blendOutTime;
	float m_blendOutTimeCurrent;
	bool m_bInRagdoll;
	bool m_bInBlendOut;
	bool m_bEntityAlive;
	bool m_bDispatchedAspectProfile;
	bool m_bForceRagdollFinish;
	bool m_bFromProcClip;

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	virtual ~CProceduralContextRagdoll();
	void EnableRagdoll(const unsigned entityID, const bool bAlive, const float stiffness, const bool bFromProcClip) { FEnableRagdoll(this, entityID, bAlive, stiffness, bFromProcClip); }
	void DisableRagdoll(float blendOutTime) { FDisableRagdoll(this, blendOutTime); }
	void QueueRagdoll(bool bAlive) { FQueueRagdoll(this, bAlive); }
	void ForceRagdollFinish(IActor* piActor, bool bForceDead) { FForceRagdollFinish(this, piActor, bForceDead); }
	virtual void Update(float timePassedSeconds);

#if 0
	static const char* GetCName();
	static const CryGUID& GetCID();
	static std::shared_ptr<CProceduralContextRagdoll> CreateClassInstance();
	CProceduralContextRagdoll();
	static const char* GetContextName();
	unsigned GetEntityTarget() const;
	void SetEntityTarget(const unsigned _arg0_);
	void SetAspectProfileScope(bool _arg0_);
	bool GetAspectProfileScope() const;
	bool IsInRagdoll() const;
	void SetBlendOut(float _arg0_);
	void Reset();
#endif

	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CProceduralContextRagdoll* const _this)>(0x18F77A0);
	static inline auto FQueryInterface = PreyFunction<void* (const CProceduralContextRagdoll* const _this, const CryGUID& iid)>(0x18F70B0);
	static inline auto FQueryComposite = PreyFunction<void* (const CProceduralContextRagdoll* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FEnableRagdoll = PreyFunction<void(CProceduralContextRagdoll* const _this, const unsigned entityID, const bool bAlive, const float stiffness, const bool bFromProcClip)>(0x18F7E30);
	static inline auto FDisableRagdoll = PreyFunction<void(CProceduralContextRagdoll* const _this, float blendOutTime)>(0x18F7E00);
	static inline auto FQueueRagdoll = PreyFunction<void(CProceduralContextRagdoll* const _this, bool bAlive)>(0x18F80D0);
	static inline auto FForceRagdollFinish = PreyFunction<void(CProceduralContextRagdoll* const _this, IActor* piActor, bool bForceDead)>(0x18F7FC0);
	static inline auto FUpdate = PreyFunction<void(CProceduralContextRagdoll* const _this, float timePassedSeconds)>(0x18F77B0);
};
#endif // MOONCRASH
