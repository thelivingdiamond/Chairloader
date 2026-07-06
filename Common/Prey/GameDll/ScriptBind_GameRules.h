// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class CGameRules;
struct HitInfo;
class ICrySizer;
struct IFunctionHandler;
struct IGameFramework;
struct ISystem;
union ScriptHandle;

// CScriptBind_GameRules
// Header:  Prey/GameDll/ScriptBind_GameRules.h
class CScriptBind_GameRules : public CScriptableBase
{ // Size=152 (0x98)
public:
	SmartScriptTable m_players;
	SmartScriptTable m_teamplayers;
	SmartScriptTable m_spawnlocations;
	SmartScriptTable m_spectatorlocations;
	SmartScriptTable m_spawngroups;
	ISystem* m_pSystem;
	IGameFramework* m_pGameFW;

	CScriptBind_GameRules(ISystem* pSystem, IGameFramework* pGameFramework);
	virtual ~CScriptBind_GameRules();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	void AttachTo(CGameRules* pGameRules) { FAttachTo(this, pGameRules); }
	int IsServer(IFunctionHandler* pH) { return FIsServer(this, pH); }
	int IsClient(IFunctionHandler* pH) { return FIsClient(this, pH); }
	int IsMultiplayer(IFunctionHandler* pH) { return FIsMultiplayer(this, pH); }
	int CanCheat(IFunctionHandler* pH) { return FCanCheat(this, pH); }
	int SpawnPlayer(IFunctionHandler* pH, int channelId, const char* name, const char* className, Vec3 pos, Vec3 angles) { return FSpawnPlayer(this, pH, channelId, name, className, pos, angles); }
	int IsPlayer(IFunctionHandler* pH, ScriptHandle playerId) { return FIsPlayer(this, pH, playerId); }
	int AddSpawnLocation(IFunctionHandler* pH, ScriptHandle entityId, bool isInitialSpawn, bool doVisTest, const char* pGroupName) { return FAddSpawnLocation(this, pH, entityId, isInitialSpawn, doVisTest, pGroupName); }
	int RemoveSpawnLocation(IFunctionHandler* pH, ScriptHandle id, bool isInitialSpawn) { return FRemoveSpawnLocation(this, pH, id, isInitialSpawn); }
	int EnableSpawnLocation(IFunctionHandler* pH, ScriptHandle id, bool isInitialSpawn, const char* pGroupName) { return FEnableSpawnLocation(this, pH, id, isInitialSpawn, pGroupName); }
	int DisableSpawnLocation(IFunctionHandler* pH, ScriptHandle id, bool isInitialSpawn) { return FDisableSpawnLocation(this, pH, id, isInitialSpawn); }
	int GetFirstSpawnLocation(IFunctionHandler* pH, int teamId) { return FGetFirstSpawnLocation(this, pH, teamId); }
	int AddSpawnGroup(IFunctionHandler* pH, ScriptHandle groupId) { return FAddSpawnGroup(this, pH, groupId); }
	int AddSpawnLocationToSpawnGroup(IFunctionHandler* pH, ScriptHandle groupId, ScriptHandle location) { return FAddSpawnLocationToSpawnGroup(this, pH, groupId, location); }
	int RemoveSpawnLocationFromSpawnGroup(IFunctionHandler* pH, ScriptHandle groupId, ScriptHandle location) { return FRemoveSpawnLocationFromSpawnGroup(this, pH, groupId, location); }
	int RemoveSpawnGroup(IFunctionHandler* pH, ScriptHandle groupId) { return FRemoveSpawnGroup(this, pH, groupId); }
	int GetSpawnGroups(IFunctionHandler* pH) { return FGetSpawnGroups(this, pH); }
	int IsSpawnGroup(IFunctionHandler* pH, ScriptHandle entityId) { return FIsSpawnGroup(this, pH, entityId); }
	int SetPlayerSpawnGroup(IFunctionHandler* pH, ScriptHandle playerId, ScriptHandle groupId) { return FSetPlayerSpawnGroup(this, pH, playerId, groupId); }
	int AddSpectatorLocation(IFunctionHandler* pH, ScriptHandle location) { return FAddSpectatorLocation(this, pH, location); }
	int RemoveSpectatorLocation(IFunctionHandler* pH, ScriptHandle id) { return FRemoveSpectatorLocation(this, pH, id); }
	int ServerExplosion(IFunctionHandler* pH, ScriptHandle shooterId, ScriptHandle weaponId, float dmg, Vec3 pos, Vec3 dir, float radius, float angle, float pressure, float holesize) { return FServerExplosion(this, pH, shooterId, weaponId, dmg, pos, dir, radius, angle, pressure, holesize); }
	int ServerHit(IFunctionHandler* pH, ScriptHandle targetId, ScriptHandle shooterId, ScriptHandle weaponId, float dmg, float radius, int materialId, int partId, int typeId) { return FServerHit(this, pH, targetId, shooterId, weaponId, dmg, radius, materialId, partId, typeId); }
	int ClientSelfHarm(IFunctionHandler* pH, float dmg, int materialId, int partId, int typeId, Vec3 dir) { return FClientSelfHarm(this, pH, dmg, materialId, partId, typeId, dir); }
	int ClientSelfHarmByEntity(IFunctionHandler* pH, ScriptHandle sourceEntity, float dmg, int materialId, int partId, int typeId, Vec3 dir) { return FClientSelfHarmByEntity(this, pH, sourceEntity, dmg, materialId, partId, typeId, dir); }
	int ServerHarmVehicle(IFunctionHandler* pH, ScriptHandle vehicle, float dmg, int materialId, int typeId, Vec3 dir) { return FServerHarmVehicle(this, pH, vehicle, dmg, materialId, typeId, dir); }
	int GetTeamName(IFunctionHandler* pH, int teamId) { return FGetTeamName(this, pH, teamId); }
	int GetTeamId(IFunctionHandler* pH, const char* teamName) { return FGetTeamId(this, pH, teamName); }
	int SetTeam(IFunctionHandler* pH, int teamId, ScriptHandle playerId) { return FSetTeam(this, pH, teamId, playerId); }
	int ClientSetTeam(IFunctionHandler* pH, int teamId, ScriptHandle playerId) { return FClientSetTeam(this, pH, teamId, playerId); }
	int GetTeam(IFunctionHandler* pH, ScriptHandle playerId) { return FGetTeam(this, pH, playerId); }
	int ForbiddenAreaWarning(IFunctionHandler* pH, bool active, int timer, ScriptHandle targetId) { return FForbiddenAreaWarning(this, pH, active, timer, targetId); }
	int Announce(IFunctionHandler* pH, ScriptHandle playerId, const char* announcement, int context) { return FAnnounce(this, pH, playerId, announcement, context); }
	int GetServerTime(IFunctionHandler* pH) { return FGetServerTime(this, pH); }
	int EndGame(IFunctionHandler* pH) { return FEndGame(this, pH); }
	int NextLevel(IFunctionHandler* pH) { return FNextLevel(this, pH); }
	int GetHitMaterialId(IFunctionHandler* pH, const char* materialName) { return FGetHitMaterialId(this, pH, materialName); }
	int GetHitTypeId(IFunctionHandler* pH, const char* type) { return FGetHitTypeId(this, pH, type); }
	int GetHitType(IFunctionHandler* pH, int id) { return FGetHitType(this, pH, id); }
	int IsHitTypeIdMelee(IFunctionHandler* pH, int hitTypeId) { return FIsHitTypeIdMelee(this, pH, hitTypeId); }
	int IsDemoMode(IFunctionHandler* pH) { return FIsDemoMode(this, pH); }
	int DebugCollisionDamage(IFunctionHandler* pH) { return FDebugCollisionDamage(this, pH); }
	int SendDamageIndicator(IFunctionHandler* pH, ScriptHandle targetId, ScriptHandle shooterId, ScriptHandle weaponId, Vec3 dir, float damage, int projectileClassId, int hitTypeId) { return FSendDamageIndicator(this, pH, targetId, shooterId, weaponId, dir, damage, projectileClassId, hitTypeId); }
	int EnteredGame(IFunctionHandler* pH) { return FEnteredGame(this, pH); }
	int Watch(IFunctionHandler* pH, const char* text) { return FWatch(this, pH, text); }
	int DemiGodDeath(IFunctionHandler* pH) { return FDemiGodDeath(this, pH); }
	int GetPrimaryTeam(IFunctionHandler* pH) { return FGetPrimaryTeam(this, pH); }
	int AddForbiddenArea(IFunctionHandler* pH, ScriptHandle entityId) { return FAddForbiddenArea(this, pH, entityId); }
	int RemoveForbiddenArea(IFunctionHandler* pH, ScriptHandle entityId) { return FRemoveForbiddenArea(this, pH, entityId); }
	int MakeMovementVisibleToAI(IFunctionHandler* pH, const char* entityClass) { return FMakeMovementVisibleToAI(this, pH, entityClass); }
	int SendGameRulesObjectiveEntitySignal(IFunctionHandler* pH, ScriptHandle entityId, int signal) { return FSendGameRulesObjectiveEntitySignal(this, pH, entityId, signal); }
	int ReRecordEntity(IFunctionHandler* pH, ScriptHandle entityId) { return FReRecordEntity(this, pH, entityId); }
	int ShouldGiveLocalPlayerHitFeedback2DSound(IFunctionHandler* pH, float damage) { return FShouldGiveLocalPlayerHitFeedback2DSound(this, pH, damage); }
	int CanUsePowerStruggleNode(IFunctionHandler* pH, ScriptHandle userId, ScriptHandle entityId) { return FCanUsePowerStruggleNode(this, pH, userId, entityId); }
	void RegisterGlobals() { FRegisterGlobals(this); }
	void RegisterMethods() { FRegisterMethods(this); }

#if 0
	CGameRules* GetGameRules(IFunctionHandler* _arg0_);
	void GetOptionalHitInfoParams(IFunctionHandler* _arg0_, HitInfo& _arg1_);
#endif

	static inline auto FCScriptBind_GameRulesOv1 = PreyFunction<void(CScriptBind_GameRules* const _this, ISystem* pSystem, IGameFramework* pGameFramework)>(0x190ED50);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CScriptBind_GameRules* const _this, ICrySizer* pSizer)>(0xCF0B20);
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_GameRules* const _this, CGameRules* pGameRules)>(0x190F150);
	static inline auto FIsServer = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x1910710);
	static inline auto FIsClient = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x19103F0);
	static inline auto FIsMultiplayer = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x1910600);
	static inline auto FCanCheat = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x190F240);
	static inline auto FSpawnPlayer = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, int channelId, const char* name, const char* className, Vec3 pos, Vec3 angles)>(0x1913740);
	static inline auto FIsPlayer = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle playerId)>(0x1910650);
	static inline auto FAddSpawnLocation = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle entityId, bool isInitialSpawn, bool doVisTest, const char* pGroupName)>(0x190F070);
	static inline auto FRemoveSpawnLocation = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle id, bool isInitialSpawn)>(0x1912860);
	static inline auto FEnableSpawnLocation = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle id, bool isInitialSpawn, const char* pGroupName)>(0x190F9C0);
	static inline auto FDisableSpawnLocation = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle id, bool isInitialSpawn)>(0x190F5E0);
	static inline auto FGetFirstSpawnLocation = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, int teamId)>(0x190FB20);
	static inline auto FAddSpawnGroup = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle groupId)>(0x190F020);
	static inline auto FAddSpawnLocationToSpawnGroup = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle groupId, ScriptHandle location)>(0x190F0F0);
	static inline auto FRemoveSpawnLocationFromSpawnGroup = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle groupId, ScriptHandle location)>(0x19128C0);
	static inline auto FRemoveSpawnGroup = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle groupId)>(0x1912810);
	static inline auto FGetSpawnGroups = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x190FED0);
	static inline auto FIsSpawnGroup = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x1910760);
	static inline auto FSetPlayerSpawnGroup = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle playerId, ScriptHandle groupId)>(0x19135D0);
	static inline auto FAddSpectatorLocation = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle location)>(0x77DB10);
	static inline auto FRemoveSpectatorLocation = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle id)>(0x77DB10);
	static inline auto FServerExplosion = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle shooterId, ScriptHandle weaponId, float dmg, Vec3 pos, Vec3 dir, float radius, float angle, float pressure, float holesize)>(0x1912CE0);
	static inline auto FServerHit = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle targetId, ScriptHandle shooterId, ScriptHandle weaponId, float dmg, float radius, int materialId, int partId, int typeId)>(0x1913440);
	static inline auto FClientSelfHarm = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, float dmg, int materialId, int partId, int typeId, Vec3 dir)>(0x190F310);
	static inline auto FClientSelfHarmByEntity = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle sourceEntity, float dmg, int materialId, int partId, int typeId, Vec3 dir)>(0x190F420);
	static inline auto FServerHarmVehicle = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle vehicle, float dmg, int materialId, int typeId, Vec3 dir)>(0x77DB10);
	static inline auto FGetTeamName = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, int teamId)>(0x1910320);
	static inline auto FGetTeamId = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, const char* teamName)>(0x1910250);
	static inline auto FSetTeam = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, int teamId, ScriptHandle playerId)>(0x1913630);
	static inline auto FClientSetTeam = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, int teamId, ScriptHandle playerId)>(0x190F520);
	static inline auto FGetTeam = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle playerId)>(0x1910180);
	static inline auto FForbiddenAreaWarning = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, bool active, int timer, ScriptHandle targetId)>(0x190FAB0);
	static inline auto FAnnounce = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle playerId, const char* announcement, int context)>(0x77DB10);
	static inline auto FGetServerTime = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x190FE10);
	static inline auto FEndGame = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x190FA30);
	static inline auto FNextLevel = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x19108B0);
	static inline auto FGetHitMaterialId = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, const char* materialName)>(0x190FBF0);
	static inline auto FGetHitTypeId = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, const char* type)>(0x190FD50);
	static inline auto FGetHitType = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, int id)>(0x190FCA0);
	static inline auto FIsHitTypeIdMelee = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, int hitTypeId)>(0x1910540);
	static inline auto FIsDemoMode = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x1910490);
	static inline auto FDebugCollisionDamage = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x190F580);
	static inline auto FSendDamageIndicator = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle targetId, ScriptHandle shooterId, ScriptHandle weaponId, Vec3 dir, float damage, int projectileClassId, int hitTypeId)>(0x1912920);
	static inline auto FEnteredGame = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x190FA70);
	static inline auto FWatch = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, const char* text)>(0x77DB10);
	static inline auto FDemiGodDeath = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x190F5A0);
	static inline auto FGetPrimaryTeam = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH)>(0x782880);
	static inline auto FAddForbiddenArea = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x190EFD0);
	static inline auto FRemoveForbiddenArea = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x19127C0);
	static inline auto FMakeMovementVisibleToAI = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, const char* entityClass)>(0x1910820);
	static inline auto FSendGameRulesObjectiveEntitySignal = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle entityId, int signal)>(0x77DB10);
	static inline auto FReRecordEntity = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x77DB10);
	static inline auto FShouldGiveLocalPlayerHitFeedback2DSound = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, float damage)>(0x1913690);
	static inline auto FCanUsePowerStruggleNode = PreyFunction<int(CScriptBind_GameRules* const _this, IFunctionHandler* pH, ScriptHandle userId, ScriptHandle entityId)>(0x782880);
	static inline auto FRegisterGlobals = PreyFunction<void(CScriptBind_GameRules* const _this)>(0x19108F0);
	static inline auto FRegisterMethods = PreyFunction<void(CScriptBind_GameRules* const _this)>(0x1911280);
};
#endif // MOONCRASH
