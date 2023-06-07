// Header file automatically created from a PDB.
#pragma once

class CScriptSurfaceTypesLoader;
class ICrySizer;
struct IScriptSystem;
struct ISystem;

// CScriptBindings
// Header:  CryEngine/cryscriptsystem/scriptbindings/scriptbinding.h
// Include: Prey/CryScriptSystem/ScriptBindings/ScriptBinding.h
class CScriptBindings
{ // Size=40 (0x28)
public:
	std::vector<std::unique_ptr<CScriptableBase>> m_binds;
	CScriptSurfaceTypesLoader* m_pScriptSurfaceTypes;

	CScriptBindings();
	virtual ~CScriptBindings();
	void Init(ISystem* pSystem, IScriptSystem* pSS) { FInit(this, pSystem, pSS); }
	void Done() { FDone(this); }
	void LoadScriptedSurfaceTypes(const char* sFolder, bool bReload) { FLoadScriptedSurfaceTypes(this, sFolder, bReload); }
	virtual void GetMemoryStatistics(ICrySizer* pSizer) const;

	static inline auto FCScriptBindingsOv1 = PreyFunction<void(CScriptBindings* const _this)>(0xD2B040);
	static inline auto FBitNotCScriptBindings = PreyFunction<void(CScriptBindings* const _this)>(0xD2B060);
	static inline auto FInit = PreyFunction<void(CScriptBindings* const _this, ISystem* pSystem, IScriptSystem* pSS)>(0xD2B240);
	static inline auto FDone = PreyFunction<void(CScriptBindings* const _this)>(0xD2B1B0);
	static inline auto FLoadScriptedSurfaceTypes = PreyFunction<void(CScriptBindings* const _this, const char* sFolder, bool bReload)>(0xD2B430);
	static inline auto FGetMemoryStatistics = PreyFunction<void(const CScriptBindings* const _this, ICrySizer* pSizer)>(0xA13080);
};

