// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryScriptSystem/IScriptSystem.h>

struct IEntity;
struct IFunctionHandler;

// Header: FromCpp
// Prey/GameDll/ark/scriptbind_arkbreakable.h
#ifdef MOONCRASH
#include <Prey/CryScriptSystem/ScriptHelpers.h>
#endif
class CScriptBind_ArkBreakable : public CScriptableBase // Id=8016460 Size=96
{
public:
	CScriptBind_ArkBreakable();
	void AttachTo(IEntity const &_entity) { FAttachTo(this,_entity); }
	int LoadParameters(IFunctionHandler *_pH) { return FLoadParameters(this,_pH); }
	int SetHealth(IFunctionHandler *_pH, const float _value) { return FSetHealth(this,_pH,_value); }
	virtual ~CScriptBind_ArkBreakable();
	
#ifndef MOONCRASH
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_ArkBreakable *const _this, IEntity const &_entity)>(0x15C36B0);
	static inline auto FLoadParameters = PreyFunction<int(CScriptBind_ArkBreakable *const _this, IFunctionHandler *_pH)>(0x15C3A00);
	static inline auto FSetHealth = PreyFunction<int(CScriptBind_ArkBreakable *const _this, IFunctionHandler *_pH, const float _value)>(0x15C3A30);
#else
	static inline auto FCScriptBind_ArkBreakableOv2 = PreyFunction<void(CScriptBind_ArkBreakable* const _this)>(0x16EA1E0);
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_ArkBreakable* const _this, const IEntity& _entity)>(0x16EA340);
	static inline auto FLoadParameters = PreyFunction<int(CScriptBind_ArkBreakable* const _this, IFunctionHandler* _pH)>(0x16EA5C0);
	static inline auto FSetHealth = PreyFunction<int(CScriptBind_ArkBreakable* const _this, IFunctionHandler* _pH, const float _value)>(0x16EA5F0);
#endif
};
