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
