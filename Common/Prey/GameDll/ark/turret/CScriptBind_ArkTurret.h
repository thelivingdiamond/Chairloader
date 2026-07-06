// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryScriptSystem/IScriptSystem.h>

class ArkTurret;
struct IFunctionHandler;
struct IGameFramework;
struct ISystem;

// Header: FromCpp
// Prey/GameDll/ark/turret/CScriptBind_ArkTurret.h
class CScriptBind_ArkTurret : public CScriptableBase // Id=8016543 Size=112
{
public:
	ISystem *m_pSystem;
	IGameFramework *m_pGameFW;
	
	CScriptBind_ArkTurret(ISystem *const _pSystem);
	virtual ~CScriptBind_ArkTurret();
	void AttachTo(ArkTurret *const _pArkTurret) { FAttachTo(this,_pArkTurret); }
	int StartBeingCarried(IFunctionHandler *_pH) { return FStartBeingCarried(this,_pH); }
	int StopBeingCarried(IFunctionHandler *_pH) { return FStopBeingCarried(this,_pH); }
	int SpawnedByFabricator(IFunctionHandler *_pH) { return FSpawnedByFabricator(this,_pH); }
	int StopShooting(IFunctionHandler *_pH) { return FStopShooting(this,_pH); }
	int IsBroken(IFunctionHandler *_pH) { return FIsBroken(this,_pH); }
	int IsHacked(IFunctionHandler *_pH) { return FIsHacked(this,_pH); }
	ArkTurret *GetArkTurret(IFunctionHandler *const _pH) { return FGetArkTurret(this,_pH); }
	
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_ArkTurret *const _this, ArkTurret *const _pArkTurret)>(0x15ED600);
	static inline auto FStartBeingCarried = PreyFunction<int(CScriptBind_ArkTurret *const _this, IFunctionHandler *_pH)>(0x15EDA20);
	static inline auto FStopBeingCarried = PreyFunction<int(CScriptBind_ArkTurret *const _this, IFunctionHandler *_pH)>(0x15EDAC0);
	static inline auto FSpawnedByFabricator = PreyFunction<int(CScriptBind_ArkTurret *const _this, IFunctionHandler *_pH)>(0x15ED980);
	static inline auto FStopShooting = PreyFunction<int(CScriptBind_ArkTurret *const _this, IFunctionHandler *_pH)>(0x15EDB60);
	static inline auto FIsBroken = PreyFunction<int(CScriptBind_ArkTurret *const _this, IFunctionHandler *_pH)>(0x15ED840);
	static inline auto FIsHacked = PreyFunction<int(CScriptBind_ArkTurret *const _this, IFunctionHandler *_pH)>(0x15ED8E0);
	static inline auto FGetArkTurret = PreyFunction<ArkTurret *(CScriptBind_ArkTurret *const _this, IFunctionHandler *const _pH)>(0x15ED760);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class ArkTurret;
struct IFunctionHandler;
struct IGameFramework;
struct ISystem;

// CScriptBind_ArkTurret
// Header:  Prey/GameDll/ark/turret/CScriptBind_ArkTurret.h
class CScriptBind_ArkTurret : public CScriptableBase
{ // Size=112 (0x70)
public:
	ISystem* m_pSystem;
	IGameFramework* m_pGameFW;

	CScriptBind_ArkTurret(ISystem* const _pSystem);
	virtual ~CScriptBind_ArkTurret();
	void AttachTo(ArkTurret* const _pArkTurret) { FAttachTo(this, _pArkTurret); }
	int StartBeingCarried(IFunctionHandler* _pH) { return FStartBeingCarried(this, _pH); }
	int StopBeingCarried(IFunctionHandler* _pH) { return FStopBeingCarried(this, _pH); }
	int SpawnedByFabricator(IFunctionHandler* _pH) { return FSpawnedByFabricator(this, _pH); }
	int StopShooting(IFunctionHandler* _pH) { return FStopShooting(this, _pH); }
	int IsBroken(IFunctionHandler* _pH) { return FIsBroken(this, _pH); }
	int IsHacked(IFunctionHandler* _pH) { return FIsHacked(this, _pH); }

#if 0
	ArkTurret* GetArkTurret(IFunctionHandler* const _arg0_);
#endif

	static inline auto FCScriptBind_ArkTurretOv1 = PreyFunction<void(CScriptBind_ArkTurret* const _this, ISystem* const _pSystem)>(0x170D870);
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_ArkTurret* const _this, ArkTurret* const _pArkTurret)>(0x170DBA0);
	static inline auto FStartBeingCarried = PreyFunction<int(CScriptBind_ArkTurret* const _this, IFunctionHandler* _pH)>(0x170DF40);
	static inline auto FStopBeingCarried = PreyFunction<int(CScriptBind_ArkTurret* const _this, IFunctionHandler* _pH)>(0x170E000);
	static inline auto FSpawnedByFabricator = PreyFunction<int(CScriptBind_ArkTurret* const _this, IFunctionHandler* _pH)>(0x170DE80);
	static inline auto FStopShooting = PreyFunction<int(CScriptBind_ArkTurret* const _this, IFunctionHandler* _pH)>(0x170E0C0);
	static inline auto FIsBroken = PreyFunction<int(CScriptBind_ArkTurret* const _this, IFunctionHandler* _pH)>(0x170DD00);
	static inline auto FIsHacked = PreyFunction<int(CScriptBind_ArkTurret* const _this, IFunctionHandler* _pH)>(0x170DDC0);
};
#endif // !MOONCRASH
