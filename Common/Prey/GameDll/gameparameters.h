// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/SAimLookParameters.h>

class CItemResourceCache;
class CItemSharedParams;
class ICrySizer;
struct IGameSharedParameters;

// CGameSharedParametersStorage
// Header:  Prey/GameDll/gameparameters.h
class CGameSharedParametersStorage
{ // Size=56 (0x38)
public:
	using TSharedParamsMap = std::map<string, _smart_ptr<IGameSharedParameters>>;

	CItemResourceCache* m_pItemResourceCache;
	std::map<string, _smart_ptr<IGameSharedParameters>> m_itemParametersMap;
	std::map<string, _smart_ptr<IGameSharedParameters>> m_weaponParametersMap;
	std::set<SAimLookParameters> m_SAimLookParameters;

	CGameSharedParametersStorage();
	~CGameSharedParametersStorage();
	CItemSharedParams* GetItemSharedParameters(const char* className, bool create) { return FGetItemSharedParameters(this, className, create); }
	void ReleaseLevelResources() { FReleaseLevelResourcesOv1(this); }
	void ReleaseLevelResources(std::map<string, _smart_ptr<IGameSharedParameters>>& paramsMap) { FReleaseLevelResourcesOv0(this, paramsMap); }
	void GetMemoryStatistics(ICrySizer* s) { FGetMemoryStatistics(this, s); }

#if 0
	void ResetItemParameters();
	CItemResourceCache& GetItemResourceCache();
	int GetWeaponSharedParametersCount() const;
	const char* GetWeaponSharedParametersName(int _arg0_) const;
	void ResetWeaponParameters();
	void GetDetailedMemoryStatics(std::map<string, _smart_ptr<IGameSharedParameters>>* _arg0_, const char* _arg1_);
	void GetDetailedItemParamMemoryStatistics();
	void GetDetailedWeaponParamMemoryStatistics();
	void ClearItemParamSets();
	const SAimLookParameters& StoreSAimLookParameters(const SAimLookParameters& _arg0_);
#endif

	static inline auto FCGameSharedParametersStorageOv1 = PreyFunction<void(CGameSharedParametersStorage* const _this)>(0x18357D0);
	static inline auto FBitNotCGameSharedParametersStorage = PreyFunction<void(CGameSharedParametersStorage* const _this)>(0x1835980);
	static inline auto FGetItemSharedParameters = PreyFunction<CItemSharedParams* (CGameSharedParametersStorage* const _this, const char* className, bool create)>(0x1835B30);
	static inline auto FReleaseLevelResourcesOv1 = PreyFunction<void(CGameSharedParametersStorage* const _this)>(0x1835CF0);
	static inline auto FReleaseLevelResourcesOv0 = PreyFunction<void(CGameSharedParametersStorage* const _this, std::map<string, _smart_ptr<IGameSharedParameters>>& paramsMap)>(0x1835C70);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CGameSharedParametersStorage* const _this, ICrySizer* s)>(0x1835B40);
};
#endif // MOONCRASH
