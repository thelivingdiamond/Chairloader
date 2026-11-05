// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryExtension/ClassWeaver.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/GameDll/ProceduralContextHelpers.h>
#include <Prey/CryExtension/TypeList.h>

struct CryGUID;
struct IAnimatedCharacter;
struct ICryFactory;

// CProceduralContextMovementControlMethod
// Header:  Prey/GameDll/ProceduralContextMovementControlMethod.h
class CProceduralContextMovementControlMethod : public IProceduralContext
{ // Size=56 (0x38)
public:
	// CProceduralContextMovementControlMethod::SMCMRequest
	// Header:  Prey/GameDll/ProceduralContextMovementControlMethod.h
	struct SMCMRequest
	{ // Size=12 (0xC)
		unsigned id;
		EMovementControlMethod horizontal;
		EMovementControlMethod vertical;
	};

	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;
	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IProceduralContext,TL::NullType> >;
	using TMCMRequestList = ProceduralContextHelpers::CRequestList<CProceduralContextMovementControlMethod::SMCMRequest>;

#ifndef MOONCRASH
	static inline auto s_factory = PreyGlobal<CFactory<CProceduralContextMovementControlMethod>>(0x2282790);
#else
	static inline auto s_factory = PreyGlobal<CFactory<CProceduralContextMovementControlMethod>>(0x23F1290);
#endif
	ProceduralContextHelpers::CRequestList<CProceduralContextMovementControlMethod::SMCMRequest> m_requestList;

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	virtual ~CProceduralContextMovementControlMethod();
	virtual void Update(float timePassedSeconds);
	unsigned RequestMovementControlMethod(const EMovementControlMethod horizontal, const EMovementControlMethod vertical) { return FRequestMovementControlMethod(this, horizontal, vertical); }
	void CancelRequest(const unsigned cancelRequestId) { FCancelRequest(this, cancelRequestId); }

#if 0
	static const char* GetCName();
	static const CryGUID& GetCID();
	static std::shared_ptr<CProceduralContextMovementControlMethod> CreateClassInstance();
	CProceduralContextMovementControlMethod();
	static const char* GetContextName();
	IAnimatedCharacter* GetAnimatedCharacter() const;
#endif

#ifndef MOONCRASH
	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CProceduralContextMovementControlMethod* const _this)>(0x17D0350);
	static inline auto FQueryInterface = PreyFunction<void* (const CProceduralContextMovementControlMethod* const _this, const CryGUID& iid)>(0x3A9BC0);
	static inline auto FQueryComposite = PreyFunction<void* (const CProceduralContextMovementControlMethod* const _this, const char* name)>(0x158AEF0);
	static inline auto FUpdate = PreyFunction<void(CProceduralContextMovementControlMethod* const _this, float timePassedSeconds)>(0x17D0360);
	static inline auto FRequestMovementControlMethod = PreyFunction<unsigned(CProceduralContextMovementControlMethod* const _this, const EMovementControlMethod horizontal, const EMovementControlMethod vertical)>(0x17D0990);
	static inline auto FCancelRequest = PreyFunction<void(CProceduralContextMovementControlMethod* const _this, const unsigned cancelRequestId)>(0x17D0940);
#else
	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CProceduralContextMovementControlMethod* const _this)>(0x18F70A0);
	static inline auto FQueryInterface = PreyFunction<void* (const CProceduralContextMovementControlMethod* const _this, const CryGUID& iid)>(0x18F70B0);
	static inline auto FQueryComposite = PreyFunction<void* (const CProceduralContextMovementControlMethod* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FUpdate = PreyFunction<void(CProceduralContextMovementControlMethod* const _this, float timePassedSeconds)>(0x18F7110);
	static inline auto FRequestMovementControlMethod = PreyFunction<unsigned(CProceduralContextMovementControlMethod* const _this, const EMovementControlMethod horizontal, const EMovementControlMethod vertical)>(0x18F7730);
	static inline auto FCancelRequest = PreyFunction<void(CProceduralContextMovementControlMethod* const _this, const unsigned cancelRequestId)>(0x18F76E0);
#endif
};

