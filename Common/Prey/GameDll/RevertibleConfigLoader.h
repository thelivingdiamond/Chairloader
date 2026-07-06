// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/utility/SingleAllocTextBlock.h>

// CRevertibleConfigLoader
// Header:  Prey/GameDll/RevertibleConfigLoader.h
class CRevertibleConfigLoader : public ILoadConfigurationEntrySink
{ // Size=88 (0x58)
public:
	// CRevertibleConfigLoader::SSavedCVar
	// Header:  Prey/GameDll/RevertibleConfigLoader.h
	struct SSavedCVar
	{ // Size=16 (0x10)
		const char* m_name;
		const char* m_value;
	};

	std::vector<CRevertibleConfigLoader::SSavedCVar> m_savedCVars;
	CSingleAllocTextBlock m_cvarsTextBlock;
	bool m_allowCheatCVars;

	CRevertibleConfigLoader(int maxCvars, int maxTextBufferSize);
	virtual ~CRevertibleConfigLoader();
	virtual void OnLoadConfigurationEntry(const char* szKey, const char* szValue, const char* szGroup);
	void LoadConfiguration(const char* szConfig) { FLoadConfiguration(this, szConfig); }
	void ApplyAndStoreCVar(const char* szKey, const char* szValue) { FApplyAndStoreCVar(this, szKey, szValue); }
	void RevertCVarChanges() { FRevertCVarChanges(this); }

#if 0
	void SetAllowCheatCVars(bool _arg0_);
#endif

	static inline auto FCRevertibleConfigLoaderOv1 = PreyFunction<void(CRevertibleConfigLoader* const _this, int maxCvars, int maxTextBufferSize)>(0x18FCAA0);
	static inline auto FBitNotCRevertibleConfigLoader = PreyFunction<void(CRevertibleConfigLoader* const _this)>(0x17EBFD0);
	static inline auto FOnLoadConfigurationEntry = PreyFunction<void(CRevertibleConfigLoader* const _this, const char* szKey, const char* szValue, const char* szGroup)>(0x18FCDF0);
	static inline auto FLoadConfiguration = PreyFunction<void(CRevertibleConfigLoader* const _this, const char* szConfig)>(0x18FCD90);
	static inline auto FApplyAndStoreCVar = PreyFunction<void(CRevertibleConfigLoader* const _this, const char* szKey, const char* szValue)>(0x18FCB50);
	static inline auto FRevertCVarChanges = PreyFunction<void(CRevertibleConfigLoader* const _this)>(0x18FCE00);
};
#endif // MOONCRASH
