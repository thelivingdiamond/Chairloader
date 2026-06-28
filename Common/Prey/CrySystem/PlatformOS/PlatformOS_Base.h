// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/Platform/IPlatformOS.h>

// CPlatformOS_Base
// Header:  CryEngine/crysystem/platformos/PlatformOS_Base.h
struct CPlatformOS_Base : public IPlatformOS
{ // Size=16 (0x10)
	// CPlatformOS_Base::CStableFPSWatcher
	// Header:  CryEngine/crysystem/platformos/PlatformOS_Base.h
	class CStableFPSWatcher
	{ // Size=16 (0x10)
	public:
		float m_resetTime;
		float m_minFPS;
		float m_minStableTime;
		float m_maxTime;
		
	#if 0
		CStableFPSWatcher(float _arg0_, float _arg1_, float _arg2_);
		void Reset();
		bool HasAchievedStableFPS();
	#endif
	};
	
	ELanguageID m_languageId;
	unsigned m_supportedLanguages;
	
	virtual bool UsePlatformSavingAPI() const;
	virtual ELanguageID GetLanguageIDFromName(const char* _arg0_) const;
	virtual ELanguageID GetSystemLanguageID() const;
	virtual unsigned GetNumSystemSupportedLanguages() const;
	virtual unsigned GetSystemSupportedLanguages() const;
	virtual bool SwapConfirmCancel() const;
	
#if 0
	CPlatformOS_Base();
#endif
	
	static inline auto FUsePlatformSavingAPI = PreyFunction<bool(const CPlatformOS_Base* const _this)>(0xE78440);
	static inline auto FGetSystemLanguageID = PreyFunction<ELanguageID(const CPlatformOS_Base* const _this)>(0xEEBB60);
	static inline auto FGetNumSystemSupportedLanguages = PreyFunction<unsigned(const CPlatformOS_Base* const _this)>(0xE76B90);
	static inline auto FGetSystemSupportedLanguages = PreyFunction<unsigned(const CPlatformOS_Base* const _this)>(0x1A4D090);
	static inline auto FSwapConfirmCancel = PreyFunction<bool(const CPlatformOS_Base* const _this)>(0xDD23F0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crysystem/platformos/PlatformOS_PC.h>
#include <Prey/CryCore/Platform/IPlatformOS.h>
#include <_unknown/CryMT__CLocklessPointerQueue.h>

// CMarkerServiceTask
// Header:  CryEngine/crysystem/platformos/PlatformOS_Base.h
class CMarkerServiceTask : public IPlatformOS::IServiceTask
{ // Size=16 (0x10)
public:
	bool& m_marker;

	virtual void OnEnqueued();
	virtual void Run();
	virtual void Finish();
	virtual bool IsPending() const;
	virtual bool IsOwnedByScheduler() const;

#if 0
	CMarkerServiceTask(bool& _arg0_);
#endif

	static inline auto FOnEnqueued = PreyFunction<void(CMarkerServiceTask* const _this)>(0xE93EE0);
	static inline auto FRun = PreyFunction<void(CMarkerServiceTask* const _this)>(0x1333E90);
	static inline auto FFinish = PreyFunction<void(CMarkerServiceTask* const _this)>(0xE92F50);
	static inline auto FIsPending = PreyFunction<bool(const CMarkerServiceTask* const _this)>(0xAA1530);
	static inline auto FIsOwnedByScheduler = PreyFunction<bool(const CMarkerServiceTask* const _this)>(0x13B0900);
};

// CPlatformOS_Base
// Header:  CryEngine/crysystem/platformos/PlatformOS_Base.h
struct CPlatformOS_Base : public IPlatformOS
{ // Size=80 (0x50)
	// CPlatformOS_Base::CStableFPSWatcher
	// Header:  CryEngine/crysystem/platformos/PlatformOS_Base.h
	class CStableFPSWatcher
	{ // Size=16 (0x10)
	public:
		float m_resetTime;
		float m_minFPS;
		float m_minStableTime;
		float m_maxTime;

	#if 0
		CStableFPSWatcher(float _arg0_, float _arg1_, float _arg2_);
		void Reset();
		bool HasAchievedStableFPS();
	#endif
	};

	ELanguageID m_languageId;
	unsigned m_supportedLanguages;
	CryMT::CLocklessPointerQueue<IPlatformOS::IServiceTask,std::allocator<IPlatformOS::IServiceTask> > m_mainThreadTasks;

	virtual void PostMainThreadTask(IPlatformOS::IServiceTask* const _task);
	virtual bool UsePlatformSavingAPI() const;
	virtual ELanguageID GetLanguageIDFromName(const char* languageName) const;
	virtual ELanguageID GetSystemLanguageID() const;
	virtual unsigned GetNumSystemSupportedLanguages() const;
	virtual unsigned GetSystemSupportedLanguages() const;
	virtual bool SwapConfirmCancel() const;

#if 0
	CPlatformOS_Base();
	void ProcessMainThreadTasks();
#endif

	static inline auto FPostMainThreadTask = PreyFunction<void(CPlatformOS_Base* const _this, IPlatformOS::IServiceTask* const _task)>(0xE93F20);
	static inline auto FUsePlatformSavingAPI = PreyFunction<bool(const CPlatformOS_Base* const _this)>(0xE94940);
	static inline auto FGetLanguageIDFromName = PreyFunction<ELanguageID(const CPlatformOS_Base* const _this, const char* languageName)>(0xE930C0);
	static inline auto FGetSystemLanguageID = PreyFunction<ELanguageID(const CPlatformOS_Base* const _this)>(0x899030);
	static inline auto FGetNumSystemSupportedLanguages = PreyFunction<unsigned(const CPlatformOS_Base* const _this)>(0xE93300);
	static inline auto FGetSystemSupportedLanguages = PreyFunction<unsigned(const CPlatformOS_Base* const _this)>(0x528760);
	static inline auto FSwapConfirmCancel = PreyFunction<bool(const CPlatformOS_Base* const _this)>(0x13B0900);
};
#endif // !MOONCRASH
