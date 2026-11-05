// Header file automatically created from a PDB.

#pragma once
//#include <CryEngine/crycommon/cryextension/impl/classweaver.h>
#include <Prey/CrySystem/IEngineModule.h>
//#include <_unknown/TL__Typelist_ICryUnknown,TL__Typelist_IEngineModule,TL__NullType_ _.h>

struct CryGUID;
struct ICryFactory;
struct SSystemGlobalEnvironment;
struct SSystemInitParams;

// Header: FromCpp
// CryEngine/cryinput/cryinput.h
class CEngineModule_CryInput : public IEngineModule // Id=800D0CF Size=8
{
public:
//	using _UserDefinedPartialInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IEngineModule,TL::NullType> >;
//	using FullInterfaceList = TL::Typelist<ICryUnknown,TL::Typelist<IEngineModule,TL::NullType> >;
	
//	static inline auto s_factory = PreyGlobal<CSingletonFactory<CEngineModule_CryInput>>(0x224C030);
	
	virtual ICryFactory *GetFactory() const;
	virtual void *QueryInterface(CryGUID const &iid) const;
	virtual void *QueryComposite(const char *name) const;
	virtual ~CEngineModule_CryInput();
	virtual const char *GetName();
	virtual const char *GetCategory();
	virtual bool Initialize(SSystemGlobalEnvironment &env, SSystemInitParams const &initParams);
	
#if 0
	static const char *GetCName();
	static CryGUID const &GetCID();
	static std::shared_ptr<CEngineModule_CryInput> CreateClassInstance();
#endif

#ifndef MOONCRASH
	static inline auto FGetFactory = PreyFunction<ICryFactory *(CEngineModule_CryInput const *const _this)>(0x9DA760);
	static inline auto FQueryInterface = PreyFunction<void *(CEngineModule_CryInput const *const _this, CryGUID const &iid)>(0x182A3A0);
	static inline auto FQueryComposite = PreyFunction<void *(CEngineModule_CryInput const *const _this, const char *name)>(0x158AEF0);
	static inline auto FGetName = PreyFunction<const char *(CEngineModule_CryInput *const _this)>(0x9DA770);
	static inline auto FGetCategory = PreyFunction<const char *(CEngineModule_CryInput *const _this)>(0xD0C1F0);
	static inline auto FInitialize = PreyFunction<bool(CEngineModule_CryInput *const _this, SSystemGlobalEnvironment &env, SSystemInitParams const &initParams)>(0x9DA780);
#else
	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CEngineModule_CryInput* const _this)>(0x9F7B20);
	static inline auto FQueryInterface = PreyFunction<void* (const CEngineModule_CryInput* const _this, const CryGUID& iid)>(0x1949360);
	static inline auto FQueryComposite = PreyFunction<void* (const CEngineModule_CryInput* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FGetName = PreyFunction<const char* (CEngineModule_CryInput* const _this)>(0x9F7B30);
	static inline auto FGetCategory = PreyFunction<const char* (CEngineModule_CryInput* const _this)>(0xD29A50);
	static inline auto FInitialize = PreyFunction<bool(CEngineModule_CryInput* const _this, SSystemGlobalEnvironment& env, const SSystemInitParams& initParams)>(0x9F7B40);
#endif
};