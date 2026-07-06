// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class CCryActor;
class CScriptVector;
struct IActor;
struct IEntityClass;
struct IFunctionHandler;
struct IGameFramework;
struct IInventory;
struct ISystem;
union ScriptHandle;
class SmartScriptTable;

// CScriptBind_Actor
// Header:  Prey/GameDll/ScriptBind_Actor.h
class CScriptBind_Actor : public CScriptableBase
{ // Size=112 (0x70)
public:
	ISystem* m_pSystem;
	IGameFramework* m_pGameFW;

	CScriptBind_Actor(ISystem* pSystem);
	virtual ~CScriptBind_Actor();
	void AttachTo(IActor* pActor) { FAttachTo(this, pActor); }
	int DumpActorInfo(IFunctionHandler* pH) { return FDumpActorInfo(this, pH); }
	int Revive(IFunctionHandler* pH) { return FRevive(this, pH); }
	int Kill(IFunctionHandler* pH) { return FKill(this, pH); }
	int ShutDown(IFunctionHandler* pH) { return FShutDown(this, pH); }
	int SetParams(IFunctionHandler* pH) { return FSetParams(this, pH); }
	int GetHeadDir(IFunctionHandler* pH) { return FGetHeadDir(this, pH); }
	int GetAimDir(IFunctionHandler* pH) { return FGetAimDir(this, pH); }
	int PostPhysicalize(IFunctionHandler* pH) { return FPostPhysicalize(this, pH); }
	int GetChannel(IFunctionHandler* pH) { return FGetChannel(this, pH); }
	int IsPlayer(IFunctionHandler* pH) { return FIsPlayer(this, pH); }
	int IsLocalClient(IFunctionHandler* pH) { return FIsLocalClient(this, pH); }
	int GetLinkedVehicleId(IFunctionHandler* pH) { return FGetLinkedVehicleId(this, pH); }
	int LinkToEntity(IFunctionHandler* pH) { return FLinkToEntity(this, pH); }
	int SetAngles(IFunctionHandler* pH, Ang3 vAngles) { return FSetAngles(this, pH, vAngles); }
	int PlayerSetViewAngles(IFunctionHandler* pH, Ang3 vAngles) { return FPlayerSetViewAngles(this, pH, vAngles); }
	int GetAngles(IFunctionHandler* pH) { return FGetAngles(this, pH); }
	int SetMovementTarget(IFunctionHandler* pH, Vec3 pos, Vec3 target, Vec3 up, float speed) { return FSetMovementTarget(this, pH, pos, target, up, speed); }
	int CameraShake(IFunctionHandler* pH, float amount, float duration, float frequency, Vec3 pos) { return FCameraShake(this, pH, amount, duration, frequency, pos); }
	int SetViewShake(IFunctionHandler* pH, Ang3 shakeAngle, Vec3 shakeShift, float duration, float frequency, float randomness) { return FSetViewShake(this, pH, shakeAngle, shakeShift, duration, frequency, randomness); }
	int SetExtensionParams(IFunctionHandler* pH, const char* extension, SmartScriptTable params) { return FSetExtensionParams(this, pH, extension, params); }
	int ClRefillAmmoResult(IFunctionHandler* pH, bool ammoRefilled) { return FClRefillAmmoResult(this, pH, ammoRefilled); }
	int SvGiveAmmoClips(IFunctionHandler* pH, int numClips) { return FSvGiveAmmoClips(this, pH, numClips); }
	int IsImmuneToForbiddenArea(IFunctionHandler* pH) { return FIsImmuneToForbiddenArea(this, pH); }
	int SetHealth(IFunctionHandler* pH, float health) { return FSetHealth(this, pH, health); }
	int SetMaxHealth(IFunctionHandler* pH, float health) { return FSetMaxHealth(this, pH, health); }
	int GetHealth(IFunctionHandler* pH) { return FGetHealth(this, pH); }
	int GetMaxHealth(IFunctionHandler* pH) { return FGetMaxHealth(this, pH); }
	int DamageInfo(IFunctionHandler* pH, ScriptHandle shooter, ScriptHandle target, ScriptHandle weapon, ScriptHandle projectile, float damage, int damageType, Vec3 hitDirection) { return FDamageInfo(this, pH, shooter, target, weapon, projectile, damage, damageType, hitDirection); }
	int GetLowHealthThreshold(IFunctionHandler* pH) { return FGetLowHealthThreshold(this, pH); }
	int SetPhysicalizationProfile(IFunctionHandler* pH, const char* profile) { return FSetPhysicalizationProfile(this, pH, profile); }
	int GetPhysicalizationProfile(IFunctionHandler* pH) { return FGetPhysicalizationProfile(this, pH); }
	int QueueAnimationState(IFunctionHandler* pH, const char* animationState) { return FQueueAnimationState(this, pH, animationState); }
	int CreateCodeEvent(IFunctionHandler* pH, SmartScriptTable params) { return FCreateCodeEvent(this, pH, params); }
	int PauseAnimationGraph(IFunctionHandler* pH) { return FPauseAnimationGraph(this, pH); }
	int ResumeAnimationGraph(IFunctionHandler* pH) { return FResumeAnimationGraph(this, pH); }
	int HurryAnimationGraph(IFunctionHandler* pH) { return FHurryAnimationGraph(this, pH); }
	int SetTurnAnimationParams(IFunctionHandler* pH, const float turnThresholdAngle, const float turnThresholdTime) { return FSetTurnAnimationParams(this, pH, turnThresholdAngle, turnThresholdTime); }
	int SetSpectatorMode(IFunctionHandler* pH, int mode, ScriptHandle targetId) { return FSetSpectatorMode(this, pH, mode, targetId); }
	int GetSpectatorMode(IFunctionHandler* pH) { return FGetSpectatorMode(this, pH); }
	int GetSpectatorState(IFunctionHandler* pH) { return FGetSpectatorState(this, pH); }
	int GetSpectatorTarget(IFunctionHandler* pH) { return FGetSpectatorTarget(this, pH); }
	int Fall(IFunctionHandler* pH, Vec3 hitPos) { return FFall(this, pH, hitPos); }
	int StandUp(IFunctionHandler* pH) { return FStandUp(this, pH); }
	int GetExtraHitLocationInfo(IFunctionHandler* pH, int slot, int partId) { return FGetExtraHitLocationInfo(this, pH, slot, partId); }
	int SetForcedLookDir(IFunctionHandler* pH, CScriptVector dir) { return FSetForcedLookDir(this, pH, dir); }
	int ClearForcedLookDir(IFunctionHandler* pH) { return FClearForcedLookDir(this, pH); }
	int SetForcedLookObjectId(IFunctionHandler* pH, ScriptHandle objectId) { return FSetForcedLookObjectId(this, pH, objectId); }
	int ClearForcedLookObjectId(IFunctionHandler* pH) { return FClearForcedLookObjectId(this, pH); }
	int CanSpectacularKillOn(IFunctionHandler* pH, ScriptHandle targetId) { return FCanSpectacularKillOn(this, pH, targetId); }
	int StartSpectacularKill(IFunctionHandler* pH, ScriptHandle targetId) { return FStartSpectacularKill(this, pH, targetId); }
	int CheckBodyDamagePartFlags(IFunctionHandler* pH, int partID, int materialID, unsigned bodyPartFlagsMask) { return FCheckBodyDamagePartFlags(this, pH, partID, materialID, bodyPartFlagsMask); }
	int GetBodyDamageProfileID(IFunctionHandler* pH, const char* bodyDamageFileName, const char* bodyDamagePartsFileName) { return FGetBodyDamageProfileID(this, pH, bodyDamageFileName, bodyDamagePartsFileName); }
	int OverrideBodyDamageProfileID(IFunctionHandler* pH, const int bodyDamageProfileID) { return FOverrideBodyDamageProfileID(this, pH, bodyDamageProfileID); }
	int IsGod(IFunctionHandler* pH) { return FIsGod(this, pH); }
	int HolsterItem(IFunctionHandler* pH, bool holster) { return FHolsterItem(this, pH, holster); }
	int DropItem(IFunctionHandler* pH, ScriptHandle itemId) { return FDropItem(this, pH, itemId); }
	int PickUpItem(IFunctionHandler* pH, ScriptHandle itemId) { return FPickUpItem(this, pH, itemId); }
	int IsCurrentItemHeavy(IFunctionHandler* pH) { return FIsCurrentItemHeavy(this, pH); }
	int PickUpPickableAmmo(IFunctionHandler* pH, const char* ammoName, int count) { return FPickUpPickableAmmo(this, pH, ammoName, count); }
	int SelectItemByName(IFunctionHandler* pH, const char* name) { return FSelectItemByName(this, pH, name); }
	int SelectItem(IFunctionHandler* pH, ScriptHandle itemId, bool forceSelect) { return FSelectItem(this, pH, itemId, forceSelect); }
	int SelectLastItem(IFunctionHandler* pH) { return FSelectLastItem(this, pH); }
	int SelectNextItem(IFunctionHandler* pH, int direction, bool keepHistory, const char* category) { return FSelectNextItem(this, pH, direction, keepHistory, category); }
	int SimpleFindItemIdInCategory(IFunctionHandler* pH, const char* category) { return FSimpleFindItemIdInCategory(this, pH, category); }
	int DisableHitReaction(IFunctionHandler* pH) { return FDisableHitReaction(this, pH); }
	int EnableHitReaction(IFunctionHandler* pH) { return FEnableHitReaction(this, pH); }
	int CreateIKLimb(IFunctionHandler* pH, int slot, const char* limbName, const char* rootBone, const char* midBone, const char* endBone, int flags) { return FCreateIKLimb(this, pH, slot, limbName, rootBone, midBone, endBone, flags); }
	int PlayAction(IFunctionHandler* pH, const char* action) { return FPlayAction(this, pH, action); }
	int RefreshPickAndThrowObjectPhysics(IFunctionHandler* pH) { return FRefreshPickAndThrowObjectPhysics(this, pH); }
	int ModifySpeed(IFunctionHandler* pH, float fFactor) { return FModifySpeed(this, pH, fFactor); }
	int AcquireOrReleaseLipSyncExtension(IFunctionHandler* pH) { return FAcquireOrReleaseLipSyncExtension(this, pH); }
	CCryActor* GetCActor(IFunctionHandler* _pH) { return FGetCActor(this, _pH); }

#if 0
	IActor* GetActor(IFunctionHandler* _arg0_);
	bool IsGrenadeClass(const IEntityClass* _arg0_) const;
	bool RefillOrGiveGrenades(CCryActor& _arg0_, IInventory& _arg1_, IEntityClass* _arg2_, int _arg3_);
#endif

	static inline auto FCScriptBind_ActorOv1 = PreyFunction<void(CScriptBind_Actor* const _this, ISystem* pSystem)>(0x1901820);
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_Actor* const _this, IActor* pActor)>(0x1903780);
	static inline auto FDumpActorInfo = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1904660);
	static inline auto FRevive = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1906CB0);
	static inline auto FKill = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x19062E0);
	static inline auto FShutDown = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1907A70);
	static inline auto FSetParams = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1907590);
	static inline auto FGetHeadDir = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1905640);
	static inline auto FGetAimDir = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1904810);
	static inline auto FPostPhysicalize = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1906B10);
	static inline auto FGetChannel = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1904C60);
	static inline auto FIsPlayer = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x19061E0);
	static inline auto FIsLocalClient = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x19060E0);
	static inline auto FGetLinkedVehicleId = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x77DB10);
	static inline auto FLinkToEntity = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1906360);
	static inline auto FSetAngles = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, Ang3 vAngles)>(0x19070D0);
	static inline auto FPlayerSetViewAngles = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, Ang3 vAngles)>(0x1906930);
	static inline auto FGetAngles = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1904930);
	static inline auto FSetMovementTarget = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, Vec3 pos, Vec3 target, Vec3 up, float speed)>(0x19074E0);
	static inline auto FCameraShake = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, float amount, float duration, float frequency, Vec3 pos)>(0x19038E0);
	static inline auto FSetViewShake = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, Ang3 shakeAngle, Vec3 shakeShift, float duration, float frequency, float randomness)>(0x1907930);
	static inline auto FSetExtensionParams = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, const char* extension, SmartScriptTable params)>(0x1907160);
	static inline auto FClRefillAmmoResult = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, bool ammoRefilled)>(0x1903B60);
	static inline auto FSvGiveAmmoClips = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, int numClips)>(0x782880);
	static inline auto FIsImmuneToForbiddenArea = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1905FE0);
	static inline auto FSetHealth = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, float health)>(0x1907370);
	static inline auto FSetMaxHealth = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, float health)>(0x1907460);
	static inline auto FGetHealth = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1905770);
	static inline auto FGetMaxHealth = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1905880);
	static inline auto FDamageInfo = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, ScriptHandle shooter, ScriptHandle target, ScriptHandle weapon, ScriptHandle projectile, float damage, int damageType, Vec3 hitDirection)>(0x1904060);
	static inline auto FGetLowHealthThreshold = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1905860);
	static inline auto FSetPhysicalizationProfile = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, const char* profile)>(0x1907660);
	static inline auto FGetPhysicalizationProfile = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1905970);
	static inline auto FQueueAnimationState = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, const char* animationState)>(0x1906B90);
	static inline auto FCreateCodeEvent = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, SmartScriptTable params)>(0x1903E40);
	static inline auto FPauseAnimationGraph = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1906590);
	static inline auto FResumeAnimationGraph = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1906C20);
	static inline auto FHurryAnimationGraph = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1905E60);
	static inline auto FSetTurnAnimationParams = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, const float turnThresholdAngle, const float turnThresholdTime)>(0x19078B0);
	static inline auto FSetSpectatorMode = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, int mode, ScriptHandle targetId)>(0x1907790);
	static inline auto FGetSpectatorMode = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1905AB0);
	static inline auto FGetSpectatorState = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1905BB0);
	static inline auto FGetSpectatorTarget = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1905CC0);
	static inline auto FFall = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, Vec3 hitPos)>(0x1904760);
	static inline auto FStandUp = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1907BE0);
	static inline auto FGetExtraHitLocationInfo = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, int slot, int partId)>(0x1904D60);
	static inline auto FSetForcedLookDir = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, CScriptVector dir)>(0x1907230);
	static inline auto FClearForcedLookDir = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1903D40);
	static inline auto FSetForcedLookObjectId = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, ScriptHandle objectId)>(0x19072E0);
	static inline auto FClearForcedLookObjectId = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1903DC0);
	static inline auto FCanSpectacularKillOn = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, ScriptHandle targetId)>(0x78FD70);
	static inline auto FStartSpectacularKill = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, ScriptHandle targetId)>(0x78FD70);
	static inline auto FCheckBodyDamagePartFlags = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, int partID, int materialID, unsigned bodyPartFlagsMask)>(0x1903A60);
	static inline auto FGetBodyDamageProfileID = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, const char* bodyDamageFileName, const char* bodyDamagePartsFileName)>(0x1904A30);
	static inline auto FOverrideBodyDamageProfileID = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, const int bodyDamageProfileID)>(0x1906500);
	static inline auto FIsGod = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x78FD70);
	static inline auto FHolsterItem = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, bool holster)>(0x1905DD0);
	static inline auto FDropItem = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, ScriptHandle itemId)>(0x1904480);
	static inline auto FPickUpItem = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, ScriptHandle itemId)>(0x1906620);
	static inline auto FIsCurrentItemHeavy = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1905EE0);
	static inline auto FPickUpPickableAmmo = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, const char* ammoName, int count)>(0x19067A0);
	static inline auto FSelectItemByName = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, const char* name)>(0x1906DF0);
	static inline auto FSelectItem = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, ScriptHandle itemId, bool forceSelect)>(0x1906D40);
	static inline auto FSelectLastItem = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1906F10);
	static inline auto FSelectNextItem = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, int direction, bool keepHistory, const char* category)>(0x1906FA0);
	static inline auto FSimpleFindItemIdInCategory = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, const char* category)>(0x1907AF0);
	static inline auto FDisableHitReaction = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1904150);
	static inline auto FEnableHitReaction = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x19046E0);
	static inline auto FCreateIKLimb = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, int slot, const char* limbName, const char* rootBone, const char* midBone, const char* endBone, int flags)>(0x1903EF0);
	static inline auto FPlayAction = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, const char* action)>(0x19068A0);
	static inline auto FRefreshPickAndThrowObjectPhysics = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x77DB10);
	static inline auto FModifySpeed = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH, float fFactor)>(0x1906470);
	static inline auto FAcquireOrReleaseLipSyncExtension = PreyFunction<int(CScriptBind_Actor* const _this, IFunctionHandler* pH)>(0x1903700);
	static inline auto FGetCActor = PreyFunction<CCryActor* (CScriptBind_Actor* const _this, IFunctionHandler* _pH)>(0x1904B60);
};
#endif // MOONCRASH
