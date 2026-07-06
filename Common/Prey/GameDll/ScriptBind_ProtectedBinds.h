// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class ICrySizer;
struct IFunctionHandler;
struct IPlayerProfile;
struct ISystem;
class SmartScriptTable;

// CScriptBind_ProtectedBinds
// Header:  Prey/GameDll/ScriptBind_ProtectedBinds.h
class CScriptBind_ProtectedBinds : public CScriptableBase
{ // Size=112 (0x70)
public:
	ISystem* m_pSystem;
	bool m_active;

	CScriptBind_ProtectedBinds(ISystem* pSystem);
	virtual ~CScriptBind_ProtectedBinds();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	int GetPersistantStat(IFunctionHandler* pH, const char* name) { return FGetPersistantStat(this, pH, name); }
	int SetPersistantStat(IFunctionHandler* pH, const char* name, SmartScriptTable valueTab) { return FSetPersistantStat(this, pH, name, valueTab); }
	int SavePersistantStatsToBlaze(IFunctionHandler* pH) { return FSavePersistantStatsToBlaze(this, pH); }
	int GetProfileAttribute(IFunctionHandler* pH, const char* name) { return FGetProfileAttribute(this, pH, name); }
	int SetProfileAttribute(IFunctionHandler* pH, const char* name, SmartScriptTable valueTab) { return FSetProfileAttribute(this, pH, name, valueTab); }
	int ActivateDemoEventEntitlement(IFunctionHandler* pH) { return FActivateDemoEventEntitlement(this, pH); }
	void Enable() { FEnable(this); }
	void Disable() { FDisable(this); }
	void RegisterMethods() { FRegisterMethods(this); }

#if 0
	void RegisterGlobals();
	IPlayerProfile* GetCurrentUserProfile();
#endif

	static inline auto FCScriptBind_ProtectedBindsOv1 = PreyFunction<void(CScriptBind_ProtectedBinds* const _this, ISystem* pSystem)>(0x1916C10);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CScriptBind_ProtectedBinds* const _this, ICrySizer* pSizer)>(0x578280);
	static inline auto FGetPersistantStat = PreyFunction<int(CScriptBind_ProtectedBinds* const _this, IFunctionHandler* pH, const char* name)>(0x77DB10);
	static inline auto FSetPersistantStat = PreyFunction<int(CScriptBind_ProtectedBinds* const _this, IFunctionHandler* pH, const char* name, SmartScriptTable valueTab)>(0x1917510);
	static inline auto FSavePersistantStatsToBlaze = PreyFunction<int(CScriptBind_ProtectedBinds* const _this, IFunctionHandler* pH)>(0x1917500);
	static inline auto FGetProfileAttribute = PreyFunction<int(CScriptBind_ProtectedBinds* const _this, IFunctionHandler* pH, const char* name)>(0x1916F00);
	static inline auto FSetProfileAttribute = PreyFunction<int(CScriptBind_ProtectedBinds* const _this, IFunctionHandler* pH, const char* name, SmartScriptTable valueTab)>(0x1917550);
	static inline auto FActivateDemoEventEntitlement = PreyFunction<int(CScriptBind_ProtectedBinds* const _this, IFunctionHandler* pH)>(0x1916D00);
	static inline auto FEnable = PreyFunction<void(CScriptBind_ProtectedBinds* const _this)>(0x1916DF0);
	static inline auto FDisable = PreyFunction<void(CScriptBind_ProtectedBinds* const _this)>(0x1916D80);
	static inline auto FRegisterMethods = PreyFunction<void(CScriptBind_ProtectedBinds* const _this)>(0x1917250);
};
#endif // MOONCRASH
