// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class CLightningArc;
struct IFunctionHandler;
struct ISystem;

// CScriptBind_LightningArc
// Header:  Prey/GameDll/ScriptBind_LightningArc.h
class CScriptBind_LightningArc : public CScriptableBase
{ // Size=104 (0x68)
public:
	ISystem* m_pSystem;

	CScriptBind_LightningArc(ISystem* pSystem);
	virtual ~CScriptBind_LightningArc();
	void AttachTo(CLightningArc* pLightningArc) { FAttachTo(this, pLightningArc); }
	int ReadLuaParameters(IFunctionHandler* _pH) { return FReadLuaParameters(this, _pH); }
	int TriggerSpark(IFunctionHandler* _pH) { return FTriggerSpark(this, _pH); }
	int Enable(IFunctionHandler* _pH, bool _bEnable) { return FEnable(this, _pH, _bEnable); }
	CLightningArc* GetLightningArcFromScript(IFunctionHandler* pH) { return FGetLightningArcFromScript(this, pH); }

#if 0
	void RegisterMethods();
#endif

	static inline auto FCScriptBind_LightningArcOv1 = PreyFunction<void(CScriptBind_LightningArc* const _this, ISystem* pSystem)>(0x1916520);
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_LightningArc* const _this, CLightningArc* pLightningArc)>(0x1916750);
	static inline auto FReadLuaParameters = PreyFunction<int(CScriptBind_LightningArc* const _this, IFunctionHandler* _pH)>(0x1916A00);
	static inline auto FTriggerSpark = PreyFunction<int(CScriptBind_LightningArc* const _this, IFunctionHandler* _pH)>(0x1916A30);
	static inline auto FEnable = PreyFunction<int(CScriptBind_LightningArc* const _this, IFunctionHandler* _pH, bool _bEnable)>(0x1916900);
	static inline auto FGetLightningArcFromScript = PreyFunction<CLightningArc* (CScriptBind_LightningArc* const _this, IFunctionHandler* pH)>(0x1916940);
};
#endif // MOONCRASH
