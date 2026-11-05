// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryExtension/ClassWeaver.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/GameDll/ProceduralContextHelpers.h>
#include <Prey/CryExtension/TypeList.h>

struct CryGUID;
struct IAnimatedCharacter;
struct ICryFactory;

// CProceduralContextColliderMode
// Header:  Prey/GameDll/ProceduralContextColliderMode.h
class CProceduralContextColliderMode : public IProceduralContext
{ // Size=56 (0x38)
public:
	// CProceduralContextColliderMode::SColliderModeRequest
	// Header:  Prey/GameDll/ProceduralContextColliderMode.h
	struct SColliderModeRequest
	{ // Size=8 (0x8)
		unsigned id;
		EColliderMode mode;
	};

	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;
	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;
	using TColliderModeRequestList = ProceduralContextHelpers::CRequestList<CProceduralContextColliderMode::SColliderModeRequest>;

#ifndef MOONCRASH
	static inline auto s_factory = PreyGlobal<CFactory<CProceduralContextColliderMode>>(0x22826F0);
#else
	static inline auto s_factory = PreyGlobal<CFactory<CProceduralContextColliderMode>>(0x23F11F0);
#endif
	ProceduralContextHelpers::CRequestList<CProceduralContextColliderMode::SColliderModeRequest> m_requestList;

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	virtual ~CProceduralContextColliderMode();
	virtual void Update(float timePassedSeconds);
	unsigned RequestColliderMode(const EColliderMode colliderMode) { return FRequestColliderMode(this, colliderMode); }
	void CancelRequest(const unsigned cancelRequestId) { FCancelRequest(this, cancelRequestId); }

#if 0
	static const char* GetCName();
	static const CryGUID& GetCID();
	static std::shared_ptr<CProceduralContextColliderMode> CreateClassInstance();
	CProceduralContextColliderMode();
	static const char* GetContextName();
	IAnimatedCharacter* GetAnimatedCharacter() const;
#endif

#ifndef MOONCRASH
	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CProceduralContextColliderMode* const _this)>(0x17CEBA0);
	static inline auto FQueryInterface = PreyFunction<void* (const CProceduralContextColliderMode* const _this, const CryGUID& iid)>(0x3A9BC0);
	static inline auto FQueryComposite = PreyFunction<void* (const CProceduralContextColliderMode* const _this, const char* name)>(0x158AEF0);
	static inline auto FUpdate = PreyFunction<void(CProceduralContextColliderMode* const _this, float timePassedSeconds)>(0x17CEBB0);
	static inline auto FRequestColliderMode = PreyFunction<unsigned(CProceduralContextColliderMode* const _this, const EColliderMode colliderMode)>(0x17CF170);
	static inline auto FCancelRequest = PreyFunction<void(CProceduralContextColliderMode* const _this, const unsigned cancelRequestId)>(0x17CF120);
#else
	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CProceduralContextColliderMode* const _this)>(0x18F5900);
	static inline auto FQueryInterface = PreyFunction<void* (const CProceduralContextColliderMode* const _this, const CryGUID& iid)>(0x18F70B0);
	static inline auto FQueryComposite = PreyFunction<void* (const CProceduralContextColliderMode* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FUpdate = PreyFunction<void(CProceduralContextColliderMode* const _this, float timePassedSeconds)>(0x18F5910);
	static inline auto FRequestColliderMode = PreyFunction<unsigned(CProceduralContextColliderMode* const _this, const EColliderMode colliderMode)>(0x18F5EA0);
	static inline auto FCancelRequest = PreyFunction<void(CProceduralContextColliderMode* const _this, const unsigned cancelRequestId)>(0x18F5E50);
#endif
};

