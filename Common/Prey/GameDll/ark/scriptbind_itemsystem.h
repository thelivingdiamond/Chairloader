// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/scriptbind_itemsystem.h>
#include <Prey/CryScriptSystem/IScriptSystem.h>

class ArkItemSystem;
class ICrySizer;
struct IFunctionHandler;
struct ISystem;

// Header: FromCpp
// Prey/GameDll/ark/scriptbind_itemsystem.h
#ifdef MOONCRASH
#include <Prey/CryScriptSystem/ScriptHelpers.h>
#endif
class CScriptBind_ItemSystem : public CScriptableBase // Id=8016545 Size=96
{
public:
	CScriptBind_ItemSystem(ISystem *_pSystem);
	virtual ~CScriptBind_ItemSystem();
	virtual void GetMemoryUsage(ICrySizer *pSizer) const;
	int GiveItem(IFunctionHandler *_pH, const char *_archetypeName) { return FGiveItem(this,_pH,_archetypeName); }
	int GiveItemPack(IFunctionHandler *_pH, const char *_packName) { return FGiveItemPack(this,_pH,_packName); }
	int GetArchetypeName(IFunctionHandler *_pH, const char *_className, const char *_friendlyName) { return FGetArchetypeName(this,_pH,_className,_friendlyName); }
	
#if 0
	void RegisterMethods();
	ArkItemSystem &GetArkItemSystem() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FGetMemoryUsage = PreyFunction<void(CScriptBind_ItemSystem const *const _this, ICrySizer *pSizer)>(0xA39190);
	static inline auto FGiveItem = PreyFunction<int(CScriptBind_ItemSystem *const _this, IFunctionHandler *_pH, const char *_archetypeName)>(0x15C83D0);
	static inline auto FGiveItemPack = PreyFunction<int(CScriptBind_ItemSystem *const _this, IFunctionHandler *_pH, const char *_packName)>(0x15C8700);
	static inline auto FGetArchetypeName = PreyFunction<int(CScriptBind_ItemSystem *const _this, IFunctionHandler *_pH, const char *_className, const char *_friendlyName)>(0x15C8310);
#else
	static inline auto FCScriptBind_ItemSystemOv1 = PreyFunction<void(CScriptBind_ItemSystem* const _this, ISystem* _pSystem)>(0x16EECC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CScriptBind_ItemSystem* const _this, ICrySizer* pSizer)>(0xA55F00);
	static inline auto FGiveItem = PreyFunction<int(CScriptBind_ItemSystem* const _this, IFunctionHandler* _pH, const char* _archetypeName)>(0x16EF130);
	static inline auto FGiveItemPack = PreyFunction<int(CScriptBind_ItemSystem* const _this, IFunctionHandler* _pH, const char* _packName)>(0x16EF4E0);
	static inline auto FGetArchetypeName = PreyFunction<int(CScriptBind_ItemSystem* const _this, IFunctionHandler* _pH, const char* _className, const char* _friendlyName)>(0x16EF070);
#endif
};
