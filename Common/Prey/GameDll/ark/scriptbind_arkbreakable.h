// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

struct IEntity;
struct IFunctionHandler;

// Header: FromCpp
// Prey/GameDll/ark/scriptbind_arkbreakable.h
class CScriptBind_ArkBreakable : public CScriptableBase // Id=8016460 Size=96
{
public:
	CScriptBind_ArkBreakable();
	void AttachTo(IEntity const &_entity) { FAttachTo(this,_entity); }
	int LoadParameters(IFunctionHandler *_pH) { return FLoadParameters(this,_pH); }
	int SetHealth(IFunctionHandler *_pH, const float _value) { return FSetHealth(this,_pH,_value); }
	
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_ArkBreakable *const _this, IEntity const &_entity)>(0x15C36B0);
	static inline auto FLoadParameters = PreyFunction<int(CScriptBind_ArkBreakable *const _this, IFunctionHandler *_pH)>(0x15C3A00);
	static inline auto FSetHealth = PreyFunction<int(CScriptBind_ArkBreakable *const _this, IFunctionHandler *_pH, const float _value)>(0x15C3A30);
};

