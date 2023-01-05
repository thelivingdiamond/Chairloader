// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryScriptSystem/IScriptSystem.h>

class ArkNpc;
class ArkNpcPlayer;
struct HitInfo;
struct IFunctionHandler;
struct IGameFramework;
struct ISystem;
class SmartScriptTable;

// Header: FromCpp
// Prey/GameDll/ark/scriptbind_arknpc.h
class CScriptBind_ArkNpc : public CScriptableBase // Id=8016462 Size=112
{
public:
	ISystem *m_pSystem;
	IGameFramework *m_pGameFW;
	
	CScriptBind_ArkNpc(ISystem *pSystem);
	virtual ~CScriptBind_ArkNpc();
	void AttachTo(ArkNpc *const _pArkNpc) { FAttachTo(this,_pArkNpc); }
	int IsAlive(IFunctionHandler *_pH) { return FIsAlive(this,_pH); }
	int IsDead(IFunctionHandler *_pH) { return FIsDead(this,_pH); }
	int IsCorrupted(IFunctionHandler *_pH) { return FIsCorrupted(this,_pH); }
	int IsHacked(IFunctionHandler *_pH) { return FIsHacked(this,_pH); }
	int IsBroken(IFunctionHandler *_pH) { return FIsBroken(this,_pH); }
	int IsDestroyed(IFunctionHandler *_pH) { return FIsDestroyed(this,_pH); }
	int IsStunned(IFunctionHandler *_pH) { return FIsStunned(this,_pH); }
	int IsAsleep(IFunctionHandler *_pH) { return FIsAsleep(this,_pH); }
	int IsGlooed(IFunctionHandler *_pH) { return FIsGlooed(this,_pH); }
	int IsRaisedCorpse(IFunctionHandler *_pH) { return FIsRaisedCorpse(this,_pH); }
	int OnHit(IFunctionHandler *_pH) { return FOnHit(this,_pH); }
	int Kill(IFunctionHandler *_pH) { return FKill(this,_pH); }
	int Corrupt(IFunctionHandler *_pH) { return FCorrupt(this,_pH); }
	int Hack(IFunctionHandler *_pH) { return FHack(this,_pH); }
	int HasArkMetaTag(IFunctionHandler *_pH) { return FHasArkMetaTag(this,_pH); }
	int LightOnFire(IFunctionHandler *_pH) { return FLightOnFire(this,_pH); }
	int OnLured(IFunctionHandler *_pH) { return FOnLured(this,_pH); }
	int HasUseDialog(IFunctionHandler *_pH) { return FHasUseDialog(this,_pH); }
	int OnGlooSignal(IFunctionHandler *_pH) { return FOnGlooSignal(this,_pH); }
	int OnRecycle(IFunctionHandler *_pH) { return FOnRecycle(this,_pH); }
	int IsEtherform(IFunctionHandler *_pH) { return FIsEtherform(this,_pH); }
	int RestrictToEtherForm(IFunctionHandler *_pH) { return FRestrictToEtherForm(this,_pH); }
	int ClearRestrictToEtherForm(IFunctionHandler *_pH) { return FClearRestrictToEtherForm(this,_pH); }
	int AttachGameEffect(IFunctionHandler *_pH) { return FAttachGameEffect(this,_pH); }
	int HasGameEffect(IFunctionHandler *_pH) { return FHasGameEffect(this,_pH); }
	int DetachGameEffect(IFunctionHandler *_pH) { return FDetachGameEffect(this,_pH); }
	int StartCharacterEffect(IFunctionHandler *_pH) { return FStartCharacterEffect(this,_pH); }
	int StopCharacterEffect(IFunctionHandler *_pH) { return FStopCharacterEffect(this,_pH); }
	int GetAttentionLevelOnPlayer(IFunctionHandler *_pH) { return FGetAttentionLevelOnPlayer(this,_pH); }
	int WakeFromDormant(IFunctionHandler *_pH) { return FWakeFromDormant(this,_pH); }
	int GoToSleep(IFunctionHandler *_pH) { return FGoToSleep(this,_pH); }
	static bool GetHitInfoFromScript(SmartScriptTable const &_scriptTable, HitInfo &_info) { return FGetHitInfoFromScript(_scriptTable,_info); }
	void RegisterGlobals() const { FRegisterGlobals(this); }
	
#if 0
	static unsigned GetEntityIdArg(IFunctionHandler *arg0);
	static ArkNpc *GetArkNpcArg(IFunctionHandler *arg0);
	static ArkNpcPlayer *GetArkNpcPlayerArg(IFunctionHandler *arg0);
#endif
	
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_ArkNpc *const _this, ArkNpc *const _pArkNpc)>(0x15C4A60);
	static inline auto FIsAlive = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C5B50);
	static inline auto FIsDead = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C5E50);
	static inline auto FIsCorrupted = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C5D90);
	static inline auto FIsHacked = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C6130);
	static inline auto FIsBroken = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C5CD0);
	static inline auto FIsDestroyed = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C5F10);
	static inline auto FIsStunned = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C6290);
	static inline auto FIsAsleep = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C5C10);
	static inline auto FIsGlooed = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C6070);
	static inline auto FIsRaisedCorpse = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C61F0);
	static inline auto FOnHit = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C66C0);
	static inline auto FKill = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C6350);
	static inline auto FCorrupt = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C4C90);
	static inline auto FHack = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C5710);
	static inline auto FHasArkMetaTag = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C57C0);
	static inline auto FLightOnFire = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C6560);
	static inline auto FOnLured = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C68B0);
	static inline auto FHasUseDialog = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C5A90);
	static inline auto FOnGlooSignal = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C6610);
	static inline auto FOnRecycle = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C6A00);
	static inline auto FIsEtherform = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C5FD0);
	static inline auto FRestrictToEtherForm = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C7170);
	static inline auto FClearRestrictToEtherForm = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C4BC0);
	static inline auto FAttachGameEffect = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C48E0);
	static inline auto FHasGameEffect = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C5910);
	static inline auto FDetachGameEffect = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C4D40);
	static inline auto FStartCharacterEffect = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C7240);
	static inline auto FStopCharacterEffect = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C7370);
	static inline auto FGetAttentionLevelOnPlayer = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C4EC0);
	static inline auto FWakeFromDormant = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C74A0);
	static inline auto FGoToSleep = PreyFunction<int(CScriptBind_ArkNpc *const _this, IFunctionHandler *_pH)>(0x15C5650);
	static inline auto FGetHitInfoFromScript = PreyFunction<bool(SmartScriptTable const &_scriptTable, HitInfo &_info)>(0x15C4FA0);
	static inline auto FRegisterGlobals = PreyFunction<void(CScriptBind_ArkNpc const *const _this)>(0x15C6B50);
};

