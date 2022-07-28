#pragma once

class CKeyboard;
class CBaseInput;
struct ArkPlayerWeaponComponent;

class PreyFunctionBaseOld {
public:
	template<typename t> t getFunctionAddr(uintptr_t moduleBase, uint64_t offset);
};
class PreyFunctions : PreyFunctionBaseOld{
public:
	PreyFunctions(uintptr_t moduleBase);
	class ArkPlayerPrivate : PreyFunctionBaseOld {
	public:
		ArkPlayerPrivate(uintptr_t moduleBase);
		typedef void(__thiscall* _ShowThirdPerson)(ArkPlayer*, bool); _ShowThirdPerson showThirdPerson; //1557e20
		typedef Vec3_tpl<float>* (__thiscall* _GetPlayerWorldEyePos)(ArkPlayer*, Vec3_tpl<float>*); _GetPlayerWorldEyePos getPlayerWorldEyePos;
		typedef void(__thiscall* _Ragdollize)(ArkPlayer*, float); _Ragdollize ragdollize;//
		typedef void(__thiscall* _onFlyModePressed)(ArkPlayer*); _onFlyModePressed onFlyModePressed;//15710e0
		typedef ArkPlayer* (_fastcall* _GetPlayerInstance)(); _GetPlayerInstance getInstance;
		typedef CGodMode* (_fastcall* _GetGodModeInstance)(); _GetGodModeInstance getGodModeInstance;

	};

	class CArkWeaponPrivate :PreyFunctionBaseOld {
	public:
		CArkWeaponPrivate(uintptr_t moduleBase);
		typedef CArkWeapon* (__thiscall* _GetEquippedWeapon)(ArkPlayerWeaponComponent*); _GetEquippedWeapon getEquippedWeapon;
		typedef void(__thiscall* _FireWeapon)(CArkWeapon*); _FireWeapon fireWeapon;
		typedef void(__thiscall* _SetWeaponAmmoCount)(CArkWeapon*, uint32_t count); _SetWeaponAmmoCount setWeaponAmmoCount;
		typedef uint32_t(__thiscall* _GetClipSize)(CArkWeapon*); _GetClipSize getClipSize;
	};

	class CEntitySystemPrivate :PreyFunctionBaseOld {
	public:
		CEntitySystemPrivate(uintptr_t moduleBase);
		typedef std::vector<CryStringT<char>>(__thiscall* _GetArchetypeNames)(CEntitySystem*, CryStringT<char>); _GetArchetypeNames getArchetypeNames;
		typedef CEntityArchetype* (__thiscall* _FindEntityArchetype)(CEntitySystem*, char*); _FindEntityArchetype findEntityArchetype;
		typedef CEntity* (__cdecl* _CreateNpc)(CEntityArchetype*, Vec3_tpl<float>, Quat_tpl<float>, uint32_t, boost::variant<ArkNpcSpawnedState_Alert, ArkNpcSpawnedState_Broken, ArkNpcSpawnedState_Dead, ArkNpcSpawnedState_Dormant>*); _CreateNpc createNpc;
		//typedef CEntity* (__fastcall *_CreateNpc)(CEntityArchetype*, Vec3_tpl<float>, Quat_tpl<float>, uint64_t, uint32_t*); _CreateNpc createNpc;
		typedef CEntityArchetype* (__thiscall* _GetArchetype)(CEntitySystem*, uint64_t); _GetArchetype getArchetype;// 0922de0
		typedef void(__thiscall* _Update)(CEntitySystem*); _Update update;//0927920
		typedef uint32_t(__thiscall* _GenerateEntityId)(CEntitySystem*, bool bStaticID); _GenerateEntityId generateEntityId;
	};

	class ArkNpcSpawnManagerPrivate : PreyFunctionBaseOld {
	public:
		ArkNpcSpawnManagerPrivate(uintptr_t moduleBase);
		typedef void(__thiscall* _ArkNpcSpawnManagerUpdate)(ArkNpcSpawnManager*, float); _ArkNpcSpawnManagerUpdate ArkNpcSpawnManagerUpdate;//151db30
		typedef uint64_t(__thiscall* _RequestNpcSpawn)(ArkNpcSpawnManager*, ArkNpcSpawnRequester*, CArkNpcSpawner*); _RequestNpcSpawn requestNpcSpawn; //151dac0
		typedef uintptr_t(__fastcall* _InternalCreateNpc)(IEntityArchetype* param_1, Vec3_tpl<float>* param_2, Quat_tpl<float>* param_3); _InternalCreateNpc internalCreateNpc;//151d450
		// typedef IEntity* (__fastcall* _CreateNpc)(IEntityArchetype* param_1, Vec3_tpl<float>* param_2, Quat_tpl<float>* param_3, boost::variant<ArkNpcSpawnedState_Alert, ArkNpcSpawnedState_Broken, ArkNpcSpawnedState_Dead, ArkNpcSpawnedState_Dormant >); _CreateNpc createNpc; // 151d6d0
		// typedef IEntity* (__fastcall* _CreateNpc)(IEntityArchetype* param_1, Vec3_tpl<float>* param_2, Quat_tpl<float>* param_3, unsigned int fromStartGameEntityId, const boost::variant<ArkNpcSpawnedState_Alert, ArkNpcSpawnedState_Broken, ArkNpcSpawnedState_Dead, ArkNpcSpawnedState_Dormant>* spawnedState); _CreateNpc createNpc; // 151d6d0
	};
	
	class CEntityPrivate : PreyFunctionBaseOld {
	public:
		CEntityPrivate(uintptr_t moduleBase);
		typedef bool(__thiscall* _InitCEntity)(CEntity*, SEntitySpawnParams*);//0905cb0
		typedef bool(__thiscall* _HasAi)(CEntity*); _HasAi hasAi;
		typedef CArkNpcSpawner* (__fastcall* _GetArkNpcSpawner)(CEntity*); _GetArkNpcSpawner getArkNpcSpawner;//151c740
		typedef void* (__thiscall* _CEntity)(CEntity*, SEntitySpawnParams* param_1); _CEntity CEntityConstructor;//09022a0
		typedef IScriptTable(__thiscall* _GetScriptTable)(IEntity*); _GetScriptTable getScriptTable; //03ec540
		typedef ArkNpc* (__fastcall* _SafeGetArkNpcFromEntityPtr)(IEntity* param_1); _SafeGetArkNpcFromEntityPtr safeGetArkNpcFromEntityPtr;//12af240
		typedef ArkNpc* (__fastcall* _SafeGetArkNpcFromEntityId)(uint32_t); _SafeGetArkNpcFromEntityId safeGetArkNpcFromEntityId;//12af1f0
		typedef ArkSafeScriptTable (__thiscall* _getSafePropertiesTable)(IEntity* param_1); _getSafePropertiesTable getSafePropertiesTable;//1480480
		typedef bool(__thiscall* _ReloadEntity)(CEntity*, SEntityLoadParams*); _ReloadEntity reloadEntity; //0908650
	};

	class ArkNightmareSpawnManagerPrivate : PreyFunctionBaseOld {
	public:
		ArkNightmareSpawnManagerPrivate(uintptr_t moduleBase);
		typedef void(__thiscall* _SpawnNewNightmare)(ArkNightmareSpawnManager*); _SpawnNewNightmare spawnNewNightmare;//11f58d0
		typedef void(__thiscall* _enableNightmareSpawner)(ArkNightmareSpawnManager*); _enableNightmareSpawner enableNightmareSpawner;
	};

	class CArkNpcSpawnerPrivate : PreyFunctionBaseOld{
	public:
		CArkNpcSpawnerPrivate(uintptr_t moduleBase);
		typedef void* (__fastcall* _CreateNpcSpawner)(uint64_t, void*); _CreateNpcSpawner createNpcSpawner;//1703f00
		typedef void* (__thiscall* _CArkNpcSpawner)(CArkNpcSpawner*); _CArkNpcSpawner cArkNpcSpawnerConstructor; //151bed0
		typedef void(__thiscall* _RequestSpawn)(CArkNpcSpawner*); _RequestSpawn requestSpawn;//151cd80
	};
	// typedef CryStringT<char>(__thiscall* _GetEntityClassName)(ArkPlayer*); _GetEntityClassName getEntityClassName;//1557e20
	// typedef Quat_tpl<float>* (__thiscall* _GetViewRotation)(ArkPlayer*, Quat_tpl<float>*); _GetViewRotation getViewRotation;

	class CXConsolePrivate : PreyFunctionBaseOld {
	public:
		CXConsolePrivate(uintptr_t moduleBase);
		typedef void(__thiscall* _ShowConsole)(CXConsole*, bool, int32_t); _ShowConsole showConsole;
		typedef void(__thiscall* _DisplayHelp)(CXConsole*, char*, char*); _DisplayHelp displayHelp;//0df0fa0
		typedef void(__thiscall* _EnableActivationKey)(CXConsole*, bool); _EnableActivationKey enableActivationKey;//0df23b0
		typedef void(__thiscall* _Init)(CXConsole*, CSystem*); _Init initCXConsole;//0df5270
		typedef void(__thiscall* _ExecuteString)(CXConsole*, char* command, bool silentMode, bool bDeferExecution); _ExecuteString executeString; //0df3640
		typedef CVar* (__thiscall* _GetCvar)(CXConsole*, char*); _GetCvar getCvar;
		typedef void(__thiscall* _AddLine)(CXConsole*, char*); _AddLine addLine;//0defa00
	};

	class ArkHealthExtensionPrivate : PreyFunctionBaseOld{
	public:
		typedef void(__thiscall* _FullSerialize)(ArkHealthExtension*, CSerializeWrapper<ISerialize>); _FullSerialize fullSerialize;
		typedef ArkHealthExtension* (__fastcall* _GetExtensionFromGameObject)(IGameObjectExtension* param_1); _GetExtensionFromGameObject getExtensionFromGameObject;
		typedef ArkHealthExtension* (__fastcall* _GetExtensionFromEntityID)(uint32_t param_1); _GetExtensionFromEntityID getExtensionFromEntityID;
		typedef ArkHealthExtension* (__fastcall* _GetExtensionFromEntityPtr)(IEntity* param_1); _GetExtensionFromEntityPtr getExtensionFromEntityPtr;
	};
	class ArkFactionManagerPrivate : PreyFunctionBaseOld {
	public:
		ArkFactionManagerPrivate(uintptr_t moduleBase);
		typedef void(__thiscall* _SetEntityFaction)(ArkFactionManager*,uint32_t entityId, uint32_t factionId); _SetEntityFaction setEntityFaction;//14336a0
	};
	class ArkNpcPrivate : PreyFunctionBaseOld {
	public:
		ArkNpcPrivate(uintptr_t moduleBase);
		/*14f36c0);*/typedef void(__thiscall*  _ActivateWander)(ArkNpc* _this); _ActivateWander ActivateWander;
		/*14f37a0);*/typedef void(__thiscall* _AddCollisionObserver)(ArkNpc* _this, ArkNpcCollisionObserver* param_1); _AddCollisionObserver AddCollisionObserver;
		/*14f3810);*/typedef void(__thiscall* _AddFacingDesire)(ArkNpc* _this, ArkNpcFacingDesire* param_1); _AddFacingDesire AddFacingDesire;
		/*14f3950);*/typedef void(__thiscall* _AddInboundModifier)(ArkNpc* _this, uint64_t param_1, bool param_2); _AddInboundModifier AddInboundModifier;
		/*14f39c0);*/typedef void(__thiscall* _AddLookDesire)(ArkNpc* _this, ArkNpcLookDesire* param_1); _AddLookDesire  AddLookDesire;
		/*14f3b00);*/typedef void(__thiscall* _AddMovementDesire)(ArkNpc* _this, ArkNpcMovementDesire* param_1); _AddMovementDesire  AddMovementDesire;
		/*14f3c40);*/typedef void(__thiscall* _AddNoiseStateDesire)(ArkNpc* _this, ArkNpcNoiseStateDesire* param_1); _AddNoiseStateDesire  AddNoiseStateDesire;
		/*14f3d80);*/typedef void(__thiscall* _AddSpeedDesire)(ArkNpc* _this, ArkNpcSpeedDesire* param_1); _AddSpeedDesire	  AddSpeedDesire;
		/*14f3ec0);*/typedef void(__thiscall* _AttachPistol)(ArkNpc* _this); _AttachPistol  AttachPistol;
		/*14f3fe0);*/typedef void(__thiscall* _BecomeActive)(ArkNpc* _this); _BecomeActive  BecomeActive;
		/*14f4070);*/typedef void(__thiscall* _BecomeBroken)(ArkNpc* _this); _BecomeBroken  BecomeBroken;
		/*14f4080);*/typedef void(__thiscall* _BecomeInactive)(ArkNpc* _this); _BecomeInactive	  BecomeInactive;
		/*14f40c0);*/typedef bool(__thiscall* _BeginAnimatedDistraction)(ArkNpc* _this, ArkNpcAnimAction* param_1, ArkNpcBodyStateObserver_Animated* param_2); _BeginAnimatedDistraction	  BeginAnimatedDistraction;
		/*14f40d0);*/typedef bool(__thiscall* _BeginAnimatedStunned)(ArkNpc* _this); _BeginAnimatedStunned  BeginAnimatedStunned;
		/*14f40e0);*/typedef void(__thiscall* _BeginDamagedAudio)(ArkNpc* _this); _BeginDamagedAudio  BeginDamagedAudio;
		/*14f40f0);*/typedef void(__thiscall* _BeginDisabledAudio)(ArkNpc* _this); _BeginDisabledAudio	  BeginDisabledAudio;
		/*14f4100);*/typedef bool(__thiscall* _BeginLurking)(ArkNpc* _this, ArkNpcBodyStateObserver_Animated* param_1); _BeginLurking	  BeginLurking;
		/*14f4150);*/typedef bool(__thiscall* _BeginSearchExamine)(ArkNpc* _this, float param_1); _BeginSearchExamine  BeginSearchExamine;
		/*14f42a0);*/typedef void(__thiscall* _BeginUndamagedAudio)(ArkNpc* _this); _BeginUndamagedAudio	  BeginUndamagedAudio;
		/*14f42b0);*/typedef void(__thiscall* _BreakGlooEntity)(ArkNpc* _this); _BreakGlooEntity	  BreakGlooEntity;
		/*14f4330);*/typedef void(__thiscall* _BreakNearbyGloo)(ArkNpc* _this); _BreakNearbyGloo	  BreakNearbyGloo;
		/*14f4750);*/typedef bool(__thiscall* _CalcHasSpaceToMimicSideStep)(ArkNpc* _this, Vec2_tpl<float> param_1, float param_2, float param_3, float param_4); _CalcHasSpaceToMimicSideStep  CalcHasSpaceToMimicSideStep;
		/*14f4940);*/typedef void(__thiscall* _CallForHelp)(ArkNpc* _this, uint32_t param_1, Vec3_tpl<float>* param_2, uint64_t param_3, uint64_t param_4); _CallForHelp	  CallForHelp;
		/*14f4a00);*/typedef bool(__thiscall* _CanAttachGloo)(ArkNpc* _this); _CanAttachGloo  CanAttachGloo;
		/*14f4a40);*/typedef bool(__thiscall* _CanBeDistracted)(ArkNpc* _this); _CanBeDistracted	  CanBeDistracted;
		/*14f4ac0);*/typedef bool(__thiscall* _CanBeHypnotized)(ArkNpc* _this); _CanBeHypnotized	  CanBeHypnotized;
		/*14f4b10);*/typedef bool(__thiscall* _CanDeathReact)(ArkNpc* _this); _CanDeathReact  CanDeathReact;
		/*14f4b20);*/typedef bool(__thiscall* _CanHitReact)(ArkNpc* _this, HitInfo* param_1, bool param_2); _CanHitReact	  CanHitReact;
		/*14f4c30);*/typedef bool(__thiscall* _CanInstigate)(ArkNpc* _this); _CanInstigate  CanInstigate;
		/*14f4c70);*/typedef bool(__thiscall* _CanJump)(ArkNpc* _this); _CanJump	  CanJump;
		/*14f4d50);*/typedef bool(__thiscall* _CanMimicSideStepLeft)(ArkNpc* _this); _CanMimicSideStepLeft  CanMimicSideStepLeft;
		/*14f4d60);*/typedef bool(__thiscall* _CanMimicSideStepRight)(ArkNpc* _this); _CanMimicSideStepRight  CanMimicSideStepRight;
		/*14f4d70);*/typedef bool(__thiscall* _CanPerformAbilityContext)(ArkNpc* _this, uint64_t param_1); _CanPerformAbilityContext	  CanPerformAbilityContext;
		/*14f4e00);*/typedef bool(__thiscall* _CanPerformAnimatedAbility)(ArkNpc* _this); _CanPerformAnimatedAbility  CanPerformAnimatedAbility;
		/*14f4e10);*/typedef bool(__thiscall* _CanPerformFatality)(ArkNpc* _this); _CanPerformFatality	  CanPerformFatality;
		/*14f4e20);*/typedef bool(__thiscall* _CanPerformHitReactShift)(ArkNpc* _this); _CanPerformHitReactShift	  CanPerformHitReactShift;
		/*14f4e30);*/typedef bool(__thiscall* _CanPerformUnanimatedAbility)(ArkNpc* _this); _CanPerformUnanimatedAbility	  CanPerformUnanimatedAbility;
		/*14f4e40);*/typedef bool(__thiscall* _CanRaiseAnotherPhantom)(ArkNpc* _this); _CanRaiseAnotherPhantom	  CanRaiseAnotherPhantom;
		/*14f4f40);*/typedef bool(__thiscall* _CanSee)(ArkNpc* _this, IEntity* param_1); _CanSee  CanSee;
		/*14f4fe0);*/typedef bool(__thiscall* _CanSpeak)(ArkNpc* _this); _CanSpeak  CanSpeak;
		/*14f5020);*/typedef void(__thiscall* _CancelMovement)(ArkNpc* _this); _CancelMovement	  CancelMovement;
		/*14f5030);*/typedef void(__thiscall* _ChangeAiTree)(ArkNpc* _this, char* param_1); _ChangeAiTree	  ChangeAiTree;
		/*14f5080);*/typedef void(__thiscall* _ClearAllAttention)(ArkNpc* _this); _ClearAllAttention  ClearAllAttention;
		/*14f5110);*/typedef void(__thiscall* _ClearAttentionOnPlayer)(ArkNpc* _this); _ClearAttentionOnPlayer	  ClearAttentionOnPlayer;
		/*14f51c0);*/typedef void(__thiscall* _ClearConversationFacingTarget)(ArkNpc* _this); _ClearConversationFacingTarget  ClearConversationFacingTarget;
		/*14f5210);*/typedef void(__thiscall* _ClearConversationLookTarget)(ArkNpc* _this); _ClearConversationLookTarget	  ClearConversationLookTarget;
		/*14f5230);*/typedef void(__thiscall* _ClearFear)(ArkNpc* _this); _ClearFear  ClearFear;
		/*14f52a0);*/typedef void(__thiscall* _ClearPrecache)(void); _ClearPrecache  ClearPrecache;
		/*14f52c0);*/typedef bool(__thiscall* _Corrupt)(ArkNpc* _this, bool param_1, uint32_t param_2); _Corrupt	  Corrupt;
		/*14f5380);*/typedef void(__thiscall* _CorruptNpc)(ArkNpc* _this, ArkNpc* param_1, bool param_2); _CorruptNpc  CorruptNpc;
		/*14f53f0);*/typedef void(__thiscall* _CorruptedMovementGlitch)(ArkNpc* _this); _CorruptedMovementGlitch	  CorruptedMovementGlitch;
		/*14f5430);*/typedef void(__thiscall* _CreateAiTree)(ArkNpc* _this, char* param_1); _CreateAiTree	  CreateAiTree;
		/*14f5670);*/typedef void(__thiscall* _DeactivateWander)(ArkNpc* _this); _DeactivateWander  DeactivateWander;
		/*14f5750);*/typedef void(__thiscall* _DestroyAiTree)(ArkNpc* _this); _DestroyAiTree  DestroyAiTree;
		/*14f58c0);*/typedef bool(__thiscall* _Dissipate)(ArkNpc* _this, ArkNpcBodyStateObserver_Dissipate* param_1); _Dissipate  Dissipate;
		/*14f58d0);*/typedef void(__thiscall* _DoCorruptExplode)(ArkNpc* _this, uint64_t param_1, Vec3_tpl<float>* param_2, float param_3, float param_4, float param_5, uint64_t param_6); _DoCorruptExplode	  DoCorruptExplode;
		/*14f5a10);*/typedef bool(__thiscall* _EndAnimatedDistraction)(ArkNpc* _this); _EndAnimatedDistraction	  EndAnimatedDistraction;
		/*14f5a20);*/typedef void(__thiscall* _EndAnimatedStunned)(ArkNpc* _this); _EndAnimatedStunned	  EndAnimatedStunned;
		/*14f5a30);*/typedef bool(__thiscall* _EndDormant)(ArkNpc* _this); _EndDormant	  EndDormant;
		/*14f5a70);*/typedef bool(__thiscall* _EndLurking)(ArkNpc* _this); _EndLurking	  EndLurking;
		/*14f5ab0);*/typedef bool(__thiscall* _EndMimicry)(ArkNpc* _this); _EndMimicry	  EndMimicry;
		/*14f5ac0);*/typedef void(__thiscall* _EndPsiSuppressed)(ArkNpc* _this); _EndPsiSuppressed  EndPsiSuppressed;
		/*14f5b10);*/typedef void(__thiscall* _EndSearchExamine)(ArkNpc* _this); _EndSearchExamine  EndSearchExamine;
		/*14f5b20);*/typedef void(__thiscall* _FearAOEOnPlayerKill)(ArkNpc* _this, HitInfo* param_1); _FearAOEOnPlayerKill  FearAOEOnPlayerKill;
		/*14f5d80);*/typedef uint32_t(__thiscall* _FindDeathInstigator)(HitInfo* param_1); _FindDeathInstigator		  FindDeathInstigator;
		/*14f5df0);*/typedef bool(__thiscall* _FindNearestReachablePoint)(ArkNpc* _this, Vec3_tpl<float>* param_1, float param_2, float param_3, float param_4, Vec3_tpl<float>* param_5); _FindNearestReachablePoint	  FindNearestReachablePoint;
		/*14f5ea0);*/typedef bool(__thiscall* _FindNearestValidPoint)(ArkNpc* _this, Vec3_tpl<float>* param_1, float param_2, float param_3, float param_4, Vec3_tpl<float>* param_5); _FindNearestValidPoint	  FindNearestValidPoint;
		/*14f5f50);*/typedef void(__thiscall* _FinishRaiseFromCorpse)(ArkNpc* _this); _FinishRaiseFromCorpse  FinishRaiseFromCorpse;
		/*14f5f80);*/typedef void(__thiscall* _FlowGraphDisableAi)(ArkNpc* _this, bool param_1); _FlowGraphDisableAi  FlowGraphDisableAi;
		/*14f6000);*/typedef void(__thiscall* _FlowGraphIgnoreDistractions)(ArkNpc* _this, bool param_1, bool param_2); _FlowGraphIgnoreDistractions	  FlowGraphIgnoreDistractions;
		/*14f60f0);*/typedef void(__thiscall* _FlowGraphSetDumbed)(ArkNpc* _this, bool param_1); _FlowGraphSetDumbed  FlowGraphSetDumbed;
		/*14f6160);*/typedef void(__thiscall* _FlowgraphDisableCombatIntensity)(ArkNpc* _this); _FlowgraphDisableCombatIntensity	  FlowgraphDisableCombatIntensity;
		/*14f61c0);*/typedef void(__thiscall* _FlowgraphEnableCombatIntensity)(ArkNpc* _this); _FlowgraphEnableCombatIntensity	  FlowgraphEnableCombatIntensity;
		/*14f61e0);*/typedef void(__thiscall* _FollowLeaderEntity)(ArkNpc* _this, uint32_t param_1); _FollowLeaderEntity  FollowLeaderEntity;
		/*14f62b0);*/typedef void(__thiscall* _ForceDesperationMimicryInPlace)(ArkNpc* _this); _ForceDesperationMimicryInPlace	  ForceDesperationMimicryInPlace;
		/*14f64e0);*/typedef void(__thiscall* _ForceDownToSearchAttentionLevel)(ArkNpc* _this, uint32_t param_1); _ForceDownToSearchAttentionLevel  ForceDownToSearchAttentionLevel;
		/*14f6690);*/typedef void(__thiscall* _ForceMovementReplan)(ArkNpc* _this); _ForceMovementReplan	  ForceMovementReplan;
		/*14f66a0);*/typedef void(__thiscall* _ForceReevaluateMovementAnimAction)(ArkNpc* _this); _ForceReevaluateMovementAnimAction  ForceReevaluateMovementAnimAction;
		/*14f66d0);*/typedef void(__thiscall* _ForceStopCharacterEffect)(ArkNpc* _this, ArkCharacterEffectType param_1); _ForceStopCharacterEffect  ForceStopCharacterEffect;
		/*14f66e0);*/typedef void(__thiscall* _ForceStopDistraction)(ArkNpc* _this); _ForceStopDistraction  ForceStopDistraction;
		/*14f67b0);*/typedef void(__thiscall* _FullSerialize)(ArkNpc* _this, CSerializeWrapper<ISerialize> param_1); _FullSerialize  FullSerialize;
		/*14f71f0);*/typedef uint32_t(__thiscall* _GetActiveEthericDoppelgangerId)(ArkNpc* _this); _GetActiveEthericDoppelgangerId		  GetActiveEthericDoppelgangerId;
		/*14f7200);*/typedef int32_t(__thiscall* _GetAmmoCount)(ArkNpc* _this); _GetAmmoCount	  GetAmmoCount;
		/*14f7210);*/typedef uint32_t(__thiscall* _GetAttachedPistolId)(ArkNpc* _this); _GetAttachedPistolId		  GetAttachedPistolId;
		/*14f7220);*/typedef uint64_t(__thiscall* _GetAttachment)(uint64_t* param_1, uint64_t param_2, uint32_t param_3); _GetAttachment	  getAttachment;
		/*14f7270);*/typedef EArkAttentionLevel(__thiscall* _GetAttentionOnPlayer)(ArkNpc* _this); _GetAttentionOnPlayer				  GetAttentionOnPlayer;
		/*14f72d0);*/typedef Vec3_tpl<float>* (__thiscall* _GetCachedThrowAtLocation)(ArkNpc* _this); _GetCachedThrowAtLocation			  GetCachedThrowAtLocation;
		/*14f72e0);*/typedef EReactionThrowAtType(__thiscall* _GetCachedThrowAtType)(ArkNpc* _this); _GetCachedThrowAtType				  GetCachedThrowAtType;
		/*14f72f0);*/typedef ArkCharacterEffectsManager* (__thiscall* _GetCharacterEffectsManager)(ArkNpc* _this); _GetCharacterEffectsManager	GetCharacterEffectsManager;
		/*14f7300);*/typedef float(__thiscall* _GetComplexHearingGain)(ArkNpc* _this); _GetComplexHearingGain	  GetComplexHearingGain;
		/*14f7310);*/typedef float(__thiscall* _GetComplexVisionGain)(ArkNpc* _this); _GetComplexVisionGain  GetComplexVisionGain;
		/*14f7320);*/typedef uint64_t(__thiscall* _GetCurrentAbilityContextId)(ArkNpc* _this); _GetCurrentAbilityContextId		  GetCurrentAbilityContextId;
		/*14f7340);*/typedef EArkCombatRole(__thiscall* _GetCurrentCombatRole)(ArkNpc* _this); _GetCurrentCombatRole			  GetCurrentCombatRole;
		/*14f7350);*/typedef uint32_t(__thiscall* _GetDefaultFaction)(ArkNpc* _this); _GetDefaultFaction	  GetDefaultFaction;
		/*14f73f0);*/typedef EArkNpcSpeedType(__thiscall* _GetDesiredSpeed)(ArkNpc* _this); _GetDesiredSpeed				  GetDesiredSpeed;
		/*14f7400);*/typedef CTimeValue(__thiscall* _GetDodgeTimeStamp)(ArkNpc* _this); _GetDodgeTimeStamp		  GetDodgeTimeStamp;
		/*14f7410);*/typedef float(__thiscall* _GetEnergizedAmount)(ArkNpc* _this); _GetEnergizedAmount	  GetEnergizedAmount;
		/*14f7480);*/typedef bool(__thiscall* _GetEntityPoolSignature)(ArkNpc* _this, CSerializeWrapper<ISerialize> param_1); _GetEntityPoolSignature  GetEntityPoolSignature;
		/*14f74b0);*/typedef uint32_t(__thiscall* _GetEthericDoppelgangerOwnerId)(ArkNpc* _this); _GetEthericDoppelgangerOwnerId	  GetEthericDoppelgangerOwnerId;
		/*14f74c0);*/typedef ArkGlooEffectAccumulated* (__thiscall* _GetGlooEffect)(ArkNpc* _this); _GetGlooEffect								  GetGlooEffect;
		/*14f7530);*/typedef Vec3_tpl<float>* (__thiscall* _GetHeadDirection)(ArkNpc* _this, Vec3_tpl<float>* __return_storage_ptr__); _GetHeadDirection				  GetHeadDirection;
		/*14f7550);*/typedef Vec3_tpl<float>* (__thiscall* _GetHeadPosition)(ArkNpc* _this, Vec3_tpl<float>* __return_storage_ptr__); _GetHeadPosition			  GetHeadPosition;
		/*14f7570);*/typedef CTimeValue(__thiscall* _GetHitReactKnockDownTimeStamp)(ArkNpc* _this); _GetHitReactKnockDownTimeStamp		  GetHitReactKnockDownTimeStamp;
		/*14f7580);*/typedef CTimeValue(__thiscall* _GetHitReactStaggerTimeStamp)(ArkNpc* _this); _GetHitReactStaggerTimeStamp		  GetHitReactStaggerTimeStamp;
		/*14f7590);*/typedef bool(__thiscall* _GetIsHitReactingPrereqFlag)(ArkNpc* _this); _GetIsHitReactingPrereqFlag	  GetIsHitReactingPrereqFlag;
		/*14f75a0);*/typedef bool(__thiscall* _GetIsRegainingLosPrereqFlag)(ArkNpc* _this); _GetIsRegainingLosPrereqFlag	  GetIsRegainingLosPrereqFlag;
		/*14f75b0);*/typedef bool(__thiscall* _GetIsShuttingDown_Hack)(ArkNpc* _this); _GetIsShuttingDown_Hack	  GetIsShuttingDown_Hack;
		/*14f75c0);*/typedef bool(__thiscall* _GetIsTakingDamagePrereqFlag)(ArkNpc* _this); _GetIsTakingDamagePrereqFlag	  GetIsTakingDamagePrereqFlag;
		/*14f75d0);*/typedef uint64_t(__thiscall* _GetLastPerformedContextId)(ArkNpc* _this); _GetLastPerformedContextId	  GetLastPerformedContextId;
		/*14f75e0);*/typedef uint32_t(__thiscall* _GetLeaderId)(ArkNpc* _this); _GetLeaderId		  GetLeaderId;
		/*14f75f0);*/typedef float(__thiscall* _GetMaterialAnimationDuration)(ArkNpc* _this, ArkMaterialAnimationType param_1); _GetMaterialAnimationDuration	  GetMaterialAnimationDuration;
		/*14f7600);*/typedef ArkMaterialAnimationManager* (__thiscall* _GetMaterialAnimationManager)(ArkNpc* _this); _GetMaterialAnimationManager				GetMaterialAnimationManager;
		/*14f7610);*/typedef uint32_t(__thiscall* _GetMimicingEntityId)(ArkNpc* _this); _GetMimicingEntityId		  GetMimicingEntityId;
		/*14f7620);*/typedef EArkNpcMimicryReason(__thiscall* _GetMimicryReason)(ArkNpc* _this); _GetMimicryReason				  GetMimicryReason;
		/*14f7630);*/typedef MovementRequestID(__thiscall* _GetMovementRequestId)(ArkNpc* _this); _GetMovementRequestId					  GetMovementRequestId;
		/*14f7650);*/typedef int32_t(__thiscall* _GetNpcManagerCombatPoints)(ArkNpc* _this); _GetNpcManagerCombatPoints	  GetNpcManagerCombatPoints;
		/*14f7660);*/typedef int32_t(__thiscall* _GetNumControlledTurrets)(ArkNpc* _this); _GetNumControlledTurrets		  GetNumControlledTurrets;
		/*14f76e0);*/typedef int32_t(__thiscall* _GetNumCorruptedNpcs)(ArkNpc* _this); _GetNumCorruptedNpcs		  GetNumCorruptedNpcs;
		/*14f7700);*/typedef uint64_t* (__thiscall* _GetPhysicalEntitiesInBox)(uint64_t* param_1, uint32_t* param_2, uint32_t param_3); _GetPhysicalEntitiesInBox		  GetPhysicalEntitiesInBox;
		/*14f77b0);*/typedef ArkNpcProperties* (__thiscall* _GetProperties)(ArkNpc* _this); _GetProperties						  GetProperties;
		/*14f77c0);*/typedef void* (__thiscall* _GetRMIBase)(ArkNpc* _this); _GetRMIBase	  GetRMIBase;
		/*14f77d0);*/typedef char(__thiscall* _GetSearchReasonFromChangeReason)(int32_t param_1); _GetSearchReasonFromChangeReason  GetSearchReasonFromChangeReason;
		/*14f77e0);*/typedef uint32_t(__thiscall* _GetTopAttentionTargetEntityId)(ArkNpc* _this); _GetTopAttentionTargetEntityId	  GetTopAttentionTargetEntityId;
		/*14f77f0);*/typedef bool(__thiscall* _GiveUpSearch)(ArkNpc* _this); _GiveUpSearch  GiveUpSearch;
		/*14f7800);*/typedef void(__thiscall* _Hack)(ArkNpc* _this); _Hack  Hack;
		/*14f7870);*/typedef void(__thiscall* _HandleEvent)(ArkNpc* _this, SGameObjectEvent* param_1); _HandleEvent	  HandleEvent;
		/*14f79f0);*/typedef bool(__thiscall* _HasActiveEthericDoppelganger)(ArkNpc* _this); _HasActiveEthericDoppelganger  HasActiveEthericDoppelganger;
		/*14f7a30);*/typedef bool(__thiscall* _HasFacingDesire)(ArkNpc* _this, ArkNpcFacingDesire* param_1); _HasFacingDesire  HasFacingDesire;
		/*14f7a40);*/typedef bool(__thiscall* _HasHead)(ArkNpc* _this); _HasHead	  HasHead;
		/*14f7aa0);*/typedef bool(__thiscall* _HasLookDesire)(ArkNpc* _this, ArkNpcLookDesire* param_1); _HasLookDesire  HasLookDesire;
		/*14f7ab0);*/typedef bool(__thiscall* _HasMaxAmmo)(ArkNpc* _this); _HasMaxAmmo	  HasMaxAmmo;
		/*14f7ac0);*/typedef bool(__thiscall* _HasMovementDesire)(ArkNpc* _this, ArkNpcMovementDesire* param_1); _HasMovementDesire  HasMovementDesire;
		/*14f7ad0);*/typedef bool(__thiscall* _HasMovementRequest)(ArkNpc* _this); _HasMovementRequest	  HasMovementRequest;
		/*14f7ae0);*/typedef bool(__thiscall* _HasPerformedNotice)(ArkNpc* _this); _HasPerformedNotice	  HasPerformedNotice;
		/*14f7af0);*/typedef bool(__thiscall* _HasSpeedDesire)(ArkNpc* _this, ArkNpcSpeedDesire* param_1); _HasSpeedDesire	  HasSpeedDesire;
		/*14f7b00);*/typedef undefined(__thiscall* _HideAttachment)(uint64_t* param_1, uint64_t param_2, uint32_t param_3); _HideAttachment		  HideAttachment;
		/*14f7bb0);*/typedef bool(__thiscall* _HideDisplayName)(ArkNpc* _this, IEntity* param_1); _HideDisplayName  HideDisplayName;
		/*14f7bf0);*/typedef bool(__thiscall* _Hypnotize)(ArkNpc* _this, uint32_t param_1); _Hypnotize	  Hypnotize;
		/*14f7c40);*/typedef bool(__thiscall* _HypnotizeInterrupted)(ArkNpc* _this); _HypnotizeInterrupted  HypnotizeInterrupted;
		/*14f7c50);*/typedef bool(__thiscall* _InTrackviewSequence)(ArkNpc* _this); _InTrackviewSequence	  InTrackviewSequence;
		/*14f7c60);*/typedef undefined(__thiscall* _IncreaseAttentionLevelTowards)(uint32_t param_1, uint32_t param_2, EArkAttentionChangeReason param_3, EArkAttentionLevel param_4); _IncreaseAttentionLevelTowards		  IncreaseAttentionLevelTowards;
		/*14f7e30);*/typedef void(__thiscall* _IncreaseGloo)(ArkNpc* _this, float param_1); _IncreaseGloo	  IncreaseGloo;
		/*14f7f20);*/typedef bool(__thiscall* _Init)(ArkNpc* _this, IGameObject* param_1); _Init	  Init;
		/*14f7fc0);*/typedef void(__thiscall* _InitLiftVolumeManager)(ArkNpc* _this); _InitLiftVolumeManager  InitLiftVolumeManager;
		/*14f8050);*/typedef void(__thiscall* _InitMimicableClasses)(void); _InitMimicableClasses	  InitMimicableClasses;
		/*14f8290);*/typedef void(__thiscall* _InitializeNpc)(ArkNpc* _this); _InitializeNpc  InitializeNpc;
		/*14f8340);*/typedef void(__thiscall* _InitializeTrackviewTempNpc)(ArkNpc* _this); _InitializeTrackviewTempNpc	  InitializeTrackviewTempNpc;
		/*14f8360);*/typedef bool(__thiscall* _InterruptAbility)(ArkNpc* _this); _InterruptAbility  InterruptAbility;
		/*14f83b0);*/typedef bool(__thiscall* _InterruptHitReactShift)(ArkNpc* _this); _InterruptHitReactShift	  InterruptHitReactShift;
		/*14f83c0);*/typedef void(__thiscall* _InterruptRaiseFromCorpse)(ArkNpc* _this); _InterruptRaiseFromCorpse  InterruptRaiseFromCorpse;
		/*14f83d0);*/typedef bool(__thiscall* _InterruptUnanimatedAbility)(ArkNpc* _this); _InterruptUnanimatedAbility	  InterruptUnanimatedAbility;
		/*14f83e0);*/typedef bool(__thiscall* _IsAlert)(ArkNpc* _this); _IsAlert	  IsAlert;
		/*14f83f0);*/typedef bool(__thiscall* _IsAsleep)(ArkNpc* _this); _IsAsleep  IsAsleep;
		/*14f8400);*/typedef bool(__thiscall* _IsAttentionProxyFollowing)(ArkNpc* _this, uint32_t param_1); _IsAttentionProxyFollowing	  IsAttentionProxyFollowing;
		/*14f8470);*/typedef bool(__thiscall* _IsBreakable)(ArkNpc* _this); _IsBreakable	  IsBreakable;
		/*14f8490);*/typedef bool(__thiscall* _IsBroken)(ArkNpc* _this); _IsBroken  IsBroken;
		/*14f84a0);*/typedef bool(__thiscall* _IsCharacterEffectEnabled)(ArkNpc* _this, ArkCharacterEffectType param_1); _IsCharacterEffectEnabled  IsCharacterEffectEnabled;
		/*14f84b0);*/typedef bool(__thiscall* _IsCorrupted)(ArkNpc* _this); _IsCorrupted	  IsCorrupted;
		/*14f84d0);*/typedef bool(__thiscall* _IsCowering)(ArkNpc* _this); _IsCowering	  IsCowering;
		/*14f84e0);*/typedef bool(__thiscall* _IsDead)(ArkNpc* _this); _IsDead	  IsDead;
		/*14f8510);*/typedef bool(__thiscall* _IsDestroyed)(ArkNpc* _this); _IsDestroyed	  IsDestroyed;
		/*14f8520);*/typedef bool(__thiscall* _IsDissipating)(ArkNpc* _this); _IsDissipating  IsDissipating;
		/*14f8530);*/typedef bool(__thiscall* _IsDormant)(ArkNpc* _this); _IsDormant  IsDormant;
		/*14f8540);*/typedef bool(__thiscall* _IsEntityMimicable)(IEntity* param_1); _IsEntityMimicable  IsEntityMimicable;
		/*14f86c0);*/typedef bool(__thiscall* _IsEthericDoppelganger)(ArkNpc* _this); _IsEthericDoppelganger  IsEthericDoppelganger;
		/*14f86d0);*/typedef bool(__thiscall* _IsFalling)(ArkNpc* _this); _IsFalling  IsFalling;
		/*14f86e0);*/typedef bool(__thiscall* _IsFeared)(ArkNpc* _this); _IsFeared  IsFeared;
		/*14f8750);*/typedef bool(__thiscall* _IsFollowingPlayer)(ArkNpc* _this); _IsFollowingPlayer  IsFollowingPlayer;
		/*14f8760);*/typedef bool(__thiscall* _IsGlooSlow)(ArkNpc* _this); _IsGlooSlow	  IsGlooSlow;
		/*14f8780);*/typedef bool(__thiscall* _IsGoingToFreezeInGloo)(ArkNpc* _this); _IsGoingToFreezeInGloo  IsGoingToFreezeInGloo;
		/*14f8810);*/typedef bool(__thiscall* _IsHacked)(ArkNpc* _this); _IsHacked  IsHacked;
		/*14f8830);*/typedef bool(__thiscall* _IsIgnoringRangedAbilities)(ArkNpc* _this); _IsIgnoringRangedAbilities  IsIgnoringRangedAbilities;
		/*14f8840);*/typedef bool(__thiscall* _IsInRaiseFromCorpseAnim)(ArkNpc* _this); _IsInRaiseFromCorpseAnim	  IsInRaiseFromCorpseAnim;
		/*14f8850);*/typedef bool(__thiscall* _IsJumping)(ArkNpc* _this); _IsJumping  IsJumping;
		/*14f8860);*/typedef bool(__thiscall* _IsLureFlareValid)(ArkNpc* _this, uint32_t param_1); _IsLureFlareValid	  IsLureFlareValid;
		/*14f8a70);*/typedef bool(__thiscall* _IsLurking)(ArkNpc* _this); _IsLurking  IsLurking;
		/*14f8a80);*/typedef bool(__thiscall* _IsMimic)(ArkNpc* _this); _IsMimic	  IsMimic;
		/*14f8b90);*/typedef bool(__thiscall* _IsMimicking)(ArkNpc* _this); _IsMimicking	  IsMimicking;
		/*14f8ba0);*/typedef bool(__thiscall* _IsMindControlled)(ArkNpc* _this); _IsMindControlled  IsMindControlled;
		/*14f8c10);*/typedef bool(__thiscall* _IsMovementAnimated)(ArkNpc* _this); _IsMovementAnimated	  IsMovementAnimated;
		/*14f8c20);*/typedef bool(__thiscall* _IsMovementDesireExecuting)(ArkNpc* _this, ArkNpcMovementDesire* param_1); _IsMovementDesireExecuting  IsMovementDesireExecuting;
		/*14f8ce0);*/typedef bool(__thiscall* _IsMovementInterruptible)(ArkNpc* _this); _IsMovementInterruptible	  IsMovementInterruptible;
		/*14f8d20);*/typedef bool(__thiscall* _IsNpcHealthUIDisabled)(ArkNpc* _this); _IsNpcHealthUIDisabled  IsNpcHealthUIDisabled;
		/*14f8d30);*/typedef bool(__thiscall* _IsPerformingAbility)(ArkNpc* _this); _IsPerformingAbility	  IsPerformingAbility;
		/*14f8d50);*/typedef bool(__thiscall* _IsPlayerControlled)(ArkNpc* _this); _IsPlayerControlled	  IsPlayerControlled;
		/*14f8d70);*/typedef bool(__thiscall* _IsPsiLifted)(ArkNpc* _this); _IsPsiLifted	  IsPsiLifted;
		/*14f8d80);*/typedef bool(__thiscall* _IsPsiSuppressed)(ArkNpc* _this); _IsPsiSuppressed	  IsPsiSuppressed;
		/*14f8d90);*/typedef bool(__thiscall* _IsRagdolled)(ArkNpc* _this); _IsRagdolled	  IsRagdolled;
		/*14f8da0);*/typedef bool(__thiscall* _IsResisting)(ArkNpc* _this); _IsResisting	  IsResisting;
		/*14f8db0);*/typedef bool(__thiscall* _IsScrunched)(ArkNpc* _this); _IsScrunched	  IsScrunched;
		/*14f8dc0);*/typedef bool(__thiscall* _IsShifting)(ArkNpc* _this); _IsShifting	  IsShifting;
		/*14f8dd0);*/typedef bool(__thiscall* _IsStandingUp)(ArkNpc* _this); _IsStandingUp  IsStandingUp;
		/*14f8de0);*/typedef bool(__thiscall* _IsStunned)(ArkNpc* _this); _IsStunned  IsStunned;
		/*14f8e00);*/typedef bool(__thiscall* _IsVisible)(ArkNpc* _this); _IsVisible  IsVisible;
		/*14f8e80);*/typedef bool(__thiscall* _IsVulnerable)(ArkNpc* _this); _IsVulnerable  IsVulnerable;
		/*14f8ee0);*/typedef bool(__thiscall* _IsWithinCameraViewCone)(ArkNpc* _this, float param_1); _IsWithinCameraViewCone  IsWithinCameraViewCone;
		/*14f9030);*/typedef bool(__thiscall* _IsXRayTrackingTarget)(ArkNpc* _this, uint32_t param_1); _IsXRayTrackingTarget	  IsXRayTrackingTarget;
		/*14f9060);*/typedef void(__thiscall* _LightOnFire)(ArkNpc* _this); _LightOnFire	  LightOnFire;
		/*14f90d0);*/typedef void(__thiscall* _LoadScriptVariables)(ArkNpc* _this); _LoadScriptVariables	  LoadScriptVariables;
		/*14f9670);*/typedef void(__thiscall* _LockKnownAttentionOnTarget)(ArkNpc* _this, uint32_t param_1); _LockKnownAttentionOnTarget  LockKnownAttentionOnTarget;
		/*14f96e0);*/typedef bool(__thiscall* _LockMimicry)(ArkNpc* param_1, bool param_2); _LockMimicry	  LockMimicry;
		/*14f96f0);*/typedef void(__thiscall* _MakeConscious)(ArkNpc* _this); _MakeConscious  MakeConscious;
		/*14f9700);*/typedef void(__thiscall* _MakePoltergeistAppear)(ArkNpc* _this); _MakePoltergeistAppear  MakePoltergeistAppear;
		/*14f9770);*/typedef void(__thiscall* _MakePoltergeistDisapear)(ArkNpc* _this); _MakePoltergeistDisapear	  MakePoltergeistDisapear;
		/*14f97e0);*/typedef bool(__thiscall* _MimicAndReplaceEntity)(ArkNpc* _this, IEntity* param_1, EArkNpcMimicryReason param_2); _MimicAndReplaceEntity  MimicAndReplaceEntity;
		/*14f97f0);*/typedef bool(__thiscall* _MimicCollisionRebound)(ArkNpc* _this, EventPhysCollision* param_1); _MimicCollisionRebound	  MimicCollisionRebound;
		/*14f9b90);*/typedef bool(__thiscall* _MimicEntity)(ArkNpc* _this, IEntity* param_1, EArkNpcMimicryReason param_2, bool param_3); _MimicEntity  MimicEntity;
		/*14f9bc0);*/typedef bool(__thiscall* _NoticeTargetPosition)(ArkNpc* _this, Vec3_tpl<float>* param_1, EArkAiTreeSearchReason param_2); _NoticeTargetPosition	  NoticeTargetPosition;
		/*14f9c50);*/typedef void(__thiscall* _NotifyCorruptedOwnerOfUncorruption)(ArkNpc* _this); _NotifyCorruptedOwnerOfUncorruption	  NotifyCorruptedOwnerOfUncorruption;
		/*14f9d60);*/typedef void(__thiscall* _OnAnimatedMovement_Start)(ArkNpc* _this); _OnAnimatedMovement_Start  OnAnimatedMovement_Start;
		/*14f9d70);*/typedef void(__thiscall* _OnAnimatedMovement_Stop)(ArkNpc* _this); _OnAnimatedMovement_Stop	  OnAnimatedMovement_Stop;
		/*14f9d80);*/typedef void(__thiscall* _OnAttack)(ArkNpc* _this, uint32_t param_1); _OnAttack	  OnAttack;
		/*14f9e20);*/typedef void(__thiscall* _OnAttentionLevelChanged)(ArkNpc* _this, uint32_t param_1, EArkAttentionLevel param_2, EArkAttentionLevel param_3, EArkAttentionChangeReason param_4, bool param_5, bool param_6, uint32_t param_7); _OnAttentionLevelChanged	  OnAttentionLevelChanged;
		/*14fa5e0);*/typedef void(__thiscall* _OnAttentionProxyUpdated)(ArkNpc* _this, uint32_t param_1); _OnAttentionProxyUpdated  OnAttentionProxyUpdated;
		/*14fa6a0);*/typedef void(__thiscall* _OnBeginDormant)(ArkNpc* _this, ArkNpcAnimAction* param_1); _OnBeginDormant  OnBeginDormant;
		/*14fa770);*/typedef void(__thiscall* _OnCallMimicsReceived)(ArkNpc* _this, uint32_t param_1); _OnCallMimicsReceived	  OnCallMimicsReceived;
		/*14fa830);*/typedef void(__thiscall* _OnCallNpcsCallerDead)(ArkNpc* _this, uint32_t param_1); _OnCallNpcsCallerDead	  OnCallNpcsCallerDead;
		/*14fa920);*/typedef void(__thiscall* _OnCallNpcsEnded)(ArkNpc* _this); _OnCallNpcsEnded	  OnCallNpcsEnded;
		/*14fa9f0);*/typedef void(__thiscall* _OnCallNpcsReceived)(ArkNpc* _this, uint32_t param_1); _OnCallNpcsReceived  OnCallNpcsReceived;
		/*14faab0);*/typedef void(__thiscall* _OnCancelGuard)(ArkNpc* _this); _OnCancelGuard  OnCancelGuard;
		/*14fab90);*/typedef void(__thiscall* _OnChargeTarget)(ArkNpc* _this, uint32_t param_1); _OnChargeTarget  OnChargeTarget;
		/*14fac50);*/typedef void(__thiscall* _OnCollisionSignal)(ArkNpc* _this, uint32_t param_1); _OnCollisionSignal	  OnCollisionSignal;
		/*14fac70);*/typedef void(__thiscall* _OnCombatBegin)(ArkNpc* _this); _OnCombatBegin  OnCombatBegin;
		/*14faca0);*/typedef void(__thiscall* _OnCombatEnd)(ArkNpc* _this); _OnCombatEnd	  OnCombatEnd;
		/*14fad10);*/typedef void(__thiscall* _OnCorruptNpcRequest)(ArkNpc* _this, uint32_t param_1, bool param_2); _OnCorruptNpcRequest	  OnCorruptNpcRequest;
		/*14fadf0);*/typedef void(__thiscall* _OnCreatePhantomCancel)(ArkNpc* _this); _OnCreatePhantomCancel  OnCreatePhantomCancel;
		/*14faec0);*/typedef void(__thiscall* _OnCreatePhantomFail)(ArkNpc* _this); _OnCreatePhantomFail	  OnCreatePhantomFail;
		/*14faf10);*/typedef void(__thiscall* _OnCreatePhantomRequest)(uint32_t, uint32_t, bool, ArkDelegate<void __cdecl(uint32_t, uint32_t, bool)> param_4, IEntityArchetype* param_5, bool param_6, bool param_7); _OnCreatePhantomRequest  OnCreatePhantomRequest;
		/*14fb030);*/typedef void(__thiscall* _OnCreatePhantomSuccess)(ArkNpc* _this, uint32_t param_1); _OnCreatePhantomSuccess  OnCreatePhantomSuccess;
		/*14fb0a0);*/typedef void(__thiscall* _OnDealtDamage)(ArkNpc* _this, uint32_t param_1); _OnDealtDamage	  OnDealtDamage;
		/*14fb160);*/typedef void(__thiscall* _OnDesiredRoleChanged)(ArkNpc* _this, EArkCombatRole param_1); _OnDesiredRoleChanged  OnDesiredRoleChanged;
		/*14fb220);*/typedef void(__thiscall* _OnEndDormant)(ArkNpc* _this); _OnEndDormant  OnEndDormant;
		/*14fb2f0);*/typedef void(__thiscall* _OnEnergizedExplosion)(ArkNpc* _this); _OnEnergizedExplosion  OnEnergizedExplosion;
		/*14fb360);*/typedef void(__thiscall* _OnEnteredTrackviewBodyState)(ArkNpc* _this); _OnEnteredTrackviewBodyState	  OnEnteredTrackviewBodyState;
		/*14fb430);*/typedef void(__thiscall* _OnEntityEvent)(ArkNpc* _this, IEntity* param_1, SEntityEvent* param_2); _OnEntityEvent	  OnEntityEvent;
		/*14fb620);*/typedef void(__thiscall* _OnFearStopped)(ArkNpc* _this); _OnFearStopped  OnFearStopped;
		/*14fb730);*/typedef void(__thiscall* _OnFearedRefreshed)(ArkNpc* _this, uint32_t param_1); _OnFearedRefreshed	  OnFearedRefreshed;
		/*14fb800);*/typedef void(__thiscall* _OnFearedStarted)(ArkNpc* _this, uint32_t param_1); _OnFearedStarted  OnFearedStarted;
		/*14fb970);*/typedef void(__thiscall* _OnGlooBroken)(ArkNpc* _this); _OnGlooBroken  OnGlooBroken;
		/*14fb9d0);*/typedef void(__thiscall* _OnGlooFrozen)(ArkNpc* _this); _OnGlooFrozen  OnGlooFrozen;
		/*14fbaf0);*/typedef bool(__thiscall* _OnGravShaftEnter)(ArkNpc* _this); _OnGravShaftEnter  OnGravShaftEnter;
		/*14fbb40);*/typedef void(__thiscall* _OnGravShaftExit)(ArkNpc* _this, bool param_1); _OnGravShaftExit  OnGravShaftExit;
		/*14fbc30);*/typedef void(__thiscall* _OnGuardInPosition)(ArkNpc* _this); _OnGuardInPosition  OnGuardInPosition;
		/*14fbc60);*/typedef void(__thiscall* _OnHealthChanged)(ArkNpc* _this, float param_1, bool param_2); _OnHealthChanged  OnHealthChanged;
		/*14fbcc0);*/typedef void(__thiscall* _OnHit)(ArkNpc* _this, HitInfo* param_1, Package* param_2); _OnHit  OnHit;
		/*14fc120);*/typedef void(__thiscall* _OnHitFloor)(ArkNpc* _this, float param_1); _OnHitFloor  OnHitFloor;
		/*14fc3c0);*/typedef bool(__thiscall* _OnInteraction)(ArkNpc* _this, EArkInteractionType param_1, EArkInteractionMode param_2, IEntity* param_3); _OnInteraction  OnInteraction;
		/*14fc430);*/typedef void(__thiscall* _OnJumpAnimActionSequence_Start)(ArkNpc* _this); _OnJumpAnimActionSequence_Start	  OnJumpAnimActionSequence_Start;
		/*14fc4a0);*/typedef void(__thiscall* _OnJumpAnimActionSequence_Stop)(ArkNpc* _this); _OnJumpAnimActionSequence_Stop  OnJumpAnimActionSequence_Stop;
		/*14fc510);*/typedef void(__thiscall* _OnJumpAnimAction_Fall)(ArkNpc* _this); _OnJumpAnimAction_Fall  OnJumpAnimAction_Fall;
		/*14fc520);*/typedef void(__thiscall* _OnKill)(ArkNpc* _this, bool param_1); _OnKill  OnKill;
		/*14fc8f0);*/typedef bool(__thiscall* _OnKillHitReaction)(ArkNpc* _this, ArkNpcAnimAction* param_1); _OnKillHitReaction  OnKillHitReaction;
		/*14fc930);*/typedef bool(__thiscall* _OnKnockdownHitReaction)(ArkNpc* _this, ArkNpcAnimAction* param_1); _OnKnockdownHitReaction  OnKnockdownHitReaction;
		/*14fc9a0);*/typedef void(__thiscall* _OnLeaderDamaged)(ArkNpc* _this, uint32_t param_1); _OnLeaderDamaged  OnLeaderDamaged;
		/*14fc9c0);*/typedef void(__thiscall* _OnLostAttentionTarget)(ArkNpc* _this, uint32_t param_1, bool param_2); _OnLostAttentionTarget  OnLostAttentionTarget;
		/*14fcbd0);*/typedef void(__thiscall* _OnMantleAnimAction_Start)(ArkNpc* _this); _OnMantleAnimAction_Start  OnMantleAnimAction_Start;
		/*14fcbe0);*/typedef void(__thiscall* _OnMantleAnimAction_Stop)(ArkNpc* _this); _OnMantleAnimAction_Stop	  OnMantleAnimAction_Stop;
		/*14fcbf0);*/typedef void(__thiscall* _OnNewAttentionTarget)(ArkNpc* _this, uint32_t param_1, bool param_2); _OnNewAttentionTarget  OnNewAttentionTarget;
		/*14fcd70);*/typedef void(__thiscall* _OnPatrolCancel)(ArkNpc* _this); _OnPatrolCancel	  OnPatrolCancel;
		/*14fce60);*/typedef void(__thiscall* _OnPatrolEnd)(ArkNpc* _this); _OnPatrolEnd	  OnPatrolEnd;
		/*14fcea0);*/typedef bool(__thiscall* _OnPatrolRequest)(ArkNpc* _this, uint32_t param_1, int32_t param_2, int32_t param_3, bool param_4); _OnPatrolRequest  OnPatrolRequest;
		/*14fcf50);*/typedef void(__thiscall* _OnPatrolRequestClosest)(ArkNpc* _this, int32_t param_1, bool param_2); _OnPatrolRequestClosest  OnPatrolRequestClosest;
		/*14fcfe0);*/typedef void(__thiscall* _OnPatrolRequestUpdate)(ArkNpc* _this, uint32_t param_1, int32_t param_2, int32_t param_3, bool param_4); _OnPatrolRequestUpdate	  OnPatrolRequestUpdate;
		/*14fd060);*/typedef void(__thiscall* _OnPsiLiftedBegin)(ArkNpc* _this); _OnPsiLiftedBegin  OnPsiLiftedBegin;
		/*14fd070);*/typedef void(__thiscall* _OnPsiLiftedEnd)(ArkNpc* _this); _OnPsiLiftedEnd	  OnPsiLiftedEnd;
		/*14fd080);*/typedef void(__thiscall* _OnPsiTargetingStart)(ArkNpc* _this, uint32_t param_1); _OnPsiTargetingStart  OnPsiTargetingStart;
		/*14fd100);*/typedef void(__thiscall* _OnPsiTargetingStop)(ArkNpc* _this, uint32_t param_1); _OnPsiTargetingStop  OnPsiTargetingStop;
		/*14fd180);*/typedef void(__thiscall* _OnReactionComplete)(ArkNpc* _this); _OnReactionComplete	  OnReactionComplete;
		/*14fd190);*/typedef void(__thiscall* _OnRecycled)(ArkNpc* _this, uint32_t param_1); _OnRecycled  OnRecycled;
		/*14fd250);*/typedef void(__thiscall* _OnRequestGuard)(ArkNpc*, Vec3_tpl<float>* param_1, Ang3_tpl<float>* param_2, ArkDelegate<void __cdecl(void)> param_3); _OnRequestGuard  OnRequestGuard;
		/*14fd340);*/typedef void(__thiscall* _MakeUnconscious)(ArkNpc* _this); _MakeUnconscious	  MakeUnconscious;
		/*14fd350);*/typedef void(__thiscall* _OnScriptWakeFromDormant)(ArkNpc* _this); _OnScriptWakeFromDormant	  OnScriptWakeFromDormant;
		/*14fd380);*/typedef void(__thiscall* _OnSearchExamineFinished)(ArkNpc* _this); _OnSearchExamineFinished	  OnSearchExamineFinished;
		/*14fd450);*/typedef bool(__thiscall* _OnSmallHitReaction)(ArkNpc* _this, bool param_1, ArkNpcAnimAction* param_2); _OnSmallHitReaction	  OnSmallHitReaction;
		/*14fd500);*/typedef bool(__thiscall* _OnStaggerHitReaction)(ArkNpc* _this, ArkNpcAnimAction* param_1); _OnStaggerHitReaction	  OnStaggerHitReaction;
		/*14fd570);*/typedef void(__thiscall* _OnStartConversation)(ArkNpc* _this); _OnStartConversation	  OnStartConversation;
		/*14fd760);*/typedef void(__thiscall* _OnStartFlareHypnotize)(ArkNpc* _this, uint32_t param_1); _OnStartFlareHypnotize	  OnStartFlareHypnotize;
		/*14fd910);*/typedef void(__thiscall* _OnStartLookingAt)(ArkNpc* _this, uint32_t param_1); _OnStartLookingAt	  OnStartLookingAt;
		/*14fd970);*/typedef void(__thiscall* _OnStartScriptMove)(ArkNpc* _this); _OnStartScriptMove  OnStartScriptMove;
		/*14fda40);*/typedef void(__thiscall* _OnStartedMimicking)(ArkNpc* _this, IEntity* param_1, EArkNpcMimicryReason param_2); _OnStartedMimicking	  OnStartedMimicking;
		/*14fdd40);*/typedef void(__thiscall* _OnStartedMusicInactiveBehavior)(ArkNpc* _this); _OnStartedMusicInactiveBehavior	  OnStartedMusicInactiveBehavior;
		/*14fde10);*/typedef void(__thiscall* _OnStopConversation)(ArkNpc* _this); _OnStopConversation	  OnStopConversation;
		/*14fde80);*/typedef void(__thiscall* _OnStopFlareHypnotize)(ArkNpc* _this); _OnStopFlareHypnotize  OnStopFlareHypnotize;
		/*14fdf60);*/typedef void(__thiscall* _OnStopScriptMove)(ArkNpc* _this); _OnStopScriptMove  OnStopScriptMove;
		/*14fe030);*/typedef void(__thiscall* _OnStoppedMimicking)(ArkNpc* _this); _OnStoppedMimicking	  OnStoppedMimicking;
		/*14fe2b0);*/typedef void(__thiscall* _OnStoppedMusicInactiveBehavior)(ArkNpc* _this); _OnStoppedMusicInactiveBehavior	  OnStoppedMusicInactiveBehavior;
		/*14fe380);*/typedef void(__thiscall* _OnSurprised)(ArkNpc* _this, uint32_t param_1); _OnSurprised  OnSurprised;
		/*14fe390);*/typedef void(__thiscall* _OnTargetDead)(ArkNpc* _this, uint32_t param_1); _OnTargetDead	  OnTargetDead;
		/*14fe4a0);*/typedef void(__thiscall* _OnTargetStartedMimicry)(ArkNpc* _this, uint32_t param_1, bool param_2); _OnTargetStartedMimicry	  OnTargetStartedMimicry;
		/*14fe5b0);*/typedef void(__thiscall* _OnTargetStoppedMimicry)(ArkNpc* _this, uint32_t param_1); _OnTargetStoppedMimicry  OnTargetStoppedMimicry;
		/*14fe670);*/typedef void(__thiscall* _OnTrackviewStateExit)(ArkNpc* _this); _OnTrackviewStateExit  OnTrackviewStateExit;
		/*14fe700);*/typedef void(__thiscall* _OnUnCorrupted)(ArkNpc* _this); _OnUnCorrupted  OnUnCorrupted;
		/*14fe730);*/typedef void(__thiscall* _OnUsePower)(ArkNpc* _this); _OnUsePower	  OnUsePower;
		/*14fe750);*/typedef void(__thiscall* _OnWanderBecomeActive)(ArkNpc* _this); _OnWanderBecomeActive  OnWanderBecomeActive;
		/*14fe760);*/typedef void(__thiscall* _OnWanderBecomeInactive)(ArkNpc* _this); _OnWanderBecomeInactive	  OnWanderBecomeInactive;
		/*14fe770);*/typedef void(__thiscall* _OnWanderWaiting)(ArkNpc* _this); _OnWanderWaiting	  OnWanderWaiting;
		/*14fe840);*/typedef bool(__thiscall* _OnWrenchAttack)(ArkNpc* _this, float param_1); _OnWrenchAttack  OnWrenchAttack;
		/*14fe850);*/typedef void(__thiscall* _OnZeroDamageHit)(ArkNpc* _this, HitInfo* param_1); _OnZeroDamageHit  OnZeroDamageHit;
		/*14fe900);*/typedef bool(__thiscall* _OutOfAmmo)(ArkNpc* _this); _OutOfAmmo  OutOfAmmo;
		/*14fe910);*/typedef void(__thiscall* _OverrideCharacterId)(ArkNpc* _this, uint64_t param_1); _OverrideCharacterId  OverrideCharacterId;
		/*14feaa0);*/typedef bool(__thiscall* _OverrideHitReactAnimation)(ArkNpc* _this, HitInfo* param_1); _OverrideHitReactAnimation	  OverrideHitReactAnimation;
		/*14feb00);*/typedef bool(__thiscall* _PerformAnimatedAbility)(ArkNpc* _this, ArkNpcAnimAction* param_1, ArkNpcBodyStateObserver_Animated* param_2); _PerformAnimatedAbility  PerformAnimatedAbility;
		/*14Feb10);*/typedef bool(__thiscall* _PerformCombatReaction)(ArkNpc* _this); _PerformCombatReaction  PerformCombatReaction;
		/*14feb80);*/typedef bool(__thiscall* _PerformFatality)(ArkNpc* _this, ArkNpcAnimAction* param_1); _PerformFatality	  PerformFatality;
		/*14feb90);*/typedef bool(__thiscall* _PerformHitReactShift)(ArkNpc* _this, ArkNpcBodyStateObserver_Busy* param_1); _PerformHitReactShift	  PerformHitReactShift;
		/*14feba0);*/typedef void(__thiscall* _PerformMimicGlitch)(ArkNpc* _this); _PerformMimicGlitch	  PerformMimicGlitch;
		/*14fec20);*/typedef bool(__thiscall* _PerformMimicReorientation)(ArkNpc* _this, Vec2_tpl<float>* param_1); _PerformMimicReorientation	  PerformMimicReorientation;
		/*14fed40);*/typedef void(__thiscall* _PerformMindControlled)(ArkNpc* _this); _PerformMindControlled  PerformMindControlled;
		/*14fedf0);*/typedef void(__thiscall* _PerformPassiveGlooBreak)(ArkNpc* _this); _PerformPassiveGlooBreak	  PerformPassiveGlooBreak;
		/*14fee20);*/typedef bool(__thiscall* _PerformPatrolIdle)(ArkNpc* _this, ArkNpcBodyStateObserver_Animated* param_1); _PerformPatrolIdle  PerformPatrolIdle;
		/*14fee30);*/typedef bool(__thiscall* _PerformPostSerializeGloodPose)(ArkNpc* _this, int32_t param_1); _PerformPostSerializeGloodPose	  PerformPostSerializeGloodPose;
		/*14fee40);*/typedef bool(__thiscall* _PerformReorientation)(ArkNpc* _this, Vec2_tpl<float>* param_1); _PerformReorientation	  PerformReorientation;
		/*14ff280);*/typedef void(__thiscall* _PerformScan)(ArkNpc* _this); _PerformScan	  PerformScan;
		/*14ff290);*/typedef void(__thiscall* _PerformStopMindControlled)(ArkNpc* _this); _PerformStopMindControlled  PerformStopMindControlled;
		/*14ff2a0);*/typedef bool(__thiscall* _PerformUnanimatedAbility)(ArkNpc* _this, ArkNpcBodyStateObserver_Busy* param_1); _PerformUnanimatedAbility	  PerformUnanimatedAbility;
		/*14ff2b0);*/typedef bool(__thiscall* _PerformWanderIdle)(ArkNpc* _this); _PerformWanderIdle  PerformWanderIdle;
		/*14ff2c0);*/typedef void(__thiscall* _PlayMimicHitEffect)(ArkNpc* _this); _PlayMimicHitEffect	  PlayMimicHitEffect;
		/*14ff460);*/typedef void(__thiscall* _PlayMimicryMorphInEffect)(ArkNpc* _this); _PlayMimicryMorphInEffect  PlayMimicryMorphInEffect;
		/*14ff470);*/typedef void(__thiscall* _PlayMimicryMorphOutEffect)(ArkNpc* _this); _PlayMimicryMorphOutEffect  PlayMimicryMorphOutEffect;
		/*14ff4f0);*/typedef void(__thiscall* _PopAIAlwaysUpdate)(ArkNpc* _this); _PopAIAlwaysUpdate  PopAIAlwaysUpdate;
		/*14ff560);*/typedef void(__thiscall* _PopAttentionDrainLockOnTarget)(ArkNpc* _this, uint32_t param_1); _PopAttentionDrainLockOnTarget	  PopAttentionDrainLockOnTarget;
		/*14ff5d0);*/typedef void(__thiscall* _PopDisableAiTree)(ArkNpc* _this); _PopDisableAiTree  PopDisableAiTree;
		/*14ff660);*/typedef void(__thiscall* _PopDisableAllAmbientSounds)(ArkNpc* _this); _PopDisableAllAmbientSounds	  PopDisableAllAmbientSounds;
		/*14ff6e0);*/typedef void(__thiscall* _PopDisableAttentionAndSenses)(ArkNpc* _this); _PopDisableAttentionAndSenses  PopDisableAttentionAndSenses;
		/*14ff7b0);*/typedef void(__thiscall* _PopDisableAttentionObjectAndPerceivables)(ArkNpc* _this); _PopDisableAttentionObjectAndPerceivables  PopDisableAttentionObjectAndPerceivables;
		/*14ff860);*/typedef void(__thiscall* _PopDisableAudible)(ArkNpc* _this); _PopDisableAudible  PopDisableAudible;
		/*14ff8a0);*/typedef void(__thiscall* _PopDisableBreakable)(ArkNpc* _this); _PopDisableBreakable	  PopDisableBreakable;
		/*14ff8b0);*/typedef void(__thiscall* _PopDisableHearing)(ArkNpc* _this); _PopDisableHearing  PopDisableHearing;
		/*14ff8f0);*/typedef void(__thiscall* _PopDisableHitReactions)(ArkNpc* _this); _PopDisableHitReactions	  PopDisableHitReactions;
		/*14ff900);*/typedef void(__thiscall* _PopDisableLifetimeEffect)(ArkNpc* _this); _PopDisableLifetimeEffect  PopDisableLifetimeEffect;
		/*14ff940);*/typedef void(__thiscall* _PopDisableNpcHealthUI)(ArkNpc* _this); _PopDisableNpcHealthUI  PopDisableNpcHealthUI;
		/*14ff950);*/typedef void(__thiscall* _PopDisableOperatorLevitatorsEffect)(ArkNpc* _this); _PopDisableOperatorLevitatorsEffect	  PopDisableOperatorLevitatorsEffect;
		/*14ff990);*/typedef void(__thiscall* _PopDisableSenses)(ArkNpc* _this); _PopDisableSenses  PopDisableSenses;
		/*14ffa40);*/typedef void(__thiscall* _PopDisableVisible)(ArkNpc* _this); _PopDisableVisible  PopDisableVisible;
		/*14ffa80);*/typedef void(__thiscall* _PopDisableVision)(ArkNpc* _this); _PopDisableVision  PopDisableVision;
		/*14ffac0);*/typedef void(__thiscall* _PopDumbed)(ArkNpc* _this); _PopDumbed  PopDumbed;
		/*14ffad0);*/typedef void(__thiscall* _PopEnableAbilities)(ArkNpc* _this); _PopEnableAbilities	  PopEnableAbilities;
		/*14ffae0);*/typedef void(__thiscall* _PopEnableAiTree)(ArkNpc* _this); _PopEnableAiTree	  PopEnableAiTree;
		/*14ffb70);*/typedef void(__thiscall* _PopEnableAttentionObject)(ArkNpc* _this); _PopEnableAttentionObject  PopEnableAttentionObject;
		/*14ffbb0);*/typedef void(__thiscall* _PopEnableAttentiveSubject)(ArkNpc* _this); _PopEnableAttentiveSubject  PopEnableAttentiveSubject;
		/*14ffbf0);*/typedef void(__thiscall* _PopEnableAudible)(ArkNpc* _this); _PopEnableAudible  PopEnableAudible;
		/*14ffc30);*/typedef void(__thiscall* _PopEnableGlassBreaking)(ArkNpc* _this); _PopEnableGlassBreaking	  PopEnableGlassBreaking;
		/*14ffc70);*/typedef void(__thiscall* _PopEnableHearing)(ArkNpc* _this); _PopEnableHearing  PopEnableHearing;
		/*14ffcb0);*/typedef void(__thiscall* _PopEnableLifetimeEffect)(ArkNpc* _this); _PopEnableLifetimeEffect	  PopEnableLifetimeEffect;
		/*14ffd10);*/typedef void(__thiscall* _PopEnableOperatorLevitatorsEffect)(ArkNpc* _this); _PopEnableOperatorLevitatorsEffect  PopEnableOperatorLevitatorsEffect;
		/*14ffd70);*/typedef void(__thiscall* _PopEnableRoomPerceiver)(ArkNpc* _this); _PopEnableRoomPerceiver	  PopEnableRoomPerceiver;
		/*14ffdb0);*/typedef void(__thiscall* _PopEnableVisible)(ArkNpc* _this); _PopEnableVisible  PopEnableVisible;
		/*14ffdf0);*/typedef void(__thiscall* _PopEnableVision)(ArkNpc* _this); _PopEnableVision	  PopEnableVision;
		/*14ffe50);*/typedef void(__thiscall* _PopEnabledAmbientSound)(ArkNpc* _this, EArkNpcAmbientSoundId param_1); _PopEnabledAmbientSound  PopEnabledAmbientSound;
		/*14ffee0);*/typedef void(__thiscall* _PopFear)(ArkNpc* _this, bool param_1); _PopFear  PopFear;
		/*14fff60);*/typedef void(__thiscall* _PopForceRigidOnGloo)(ArkNpc* _this); _PopForceRigidOnGloo	  PopForceRigidOnGloo;
		/*14fff70);*/typedef bool(__thiscall* _PopIndefiniteRagdoll)(ArkNpc* _this); _PopIndefiniteRagdoll  PopIndefiniteRagdoll;
		/*14fff80);*/typedef bool(__thiscall* _PopulateInteractionInfo)(ArkNpc* _this, IEntity* param_1, std::array<ArkInteractionInfo, 4>* param_2); _PopulateInteractionInfo  PopulateInteractionInfo;
		/*14ffff0);*/typedef bool(__thiscall* _PopulateRemoteManipulationInteraction)(ArkNpc* _this, IEntity* param_1, ArkInteractionInfo* param_2); _PopulateRemoteManipulationInteraction  PopulateRemoteManipulationInteraction;
		/*1500090);*/typedef void(__thiscall* _PostInit)(ArkNpc* _this, IGameObject* param_1); _PostInit	  PostInit;
		/*1500300);*/typedef void(__thiscall* _PostSerialize)(ArkNpc* _this); _PostSerialize  PostSerialize;
		/*1500700);*/typedef void(__thiscall* _Precache)(void); _Precache	  Precache;
		/*1500a60);*/typedef void(__thiscall* _ProcessDoneEvent)(ArkNpc* _this, SEntityEvent* param_1); _ProcessDoneEvent	  ProcessDoneEvent;
		/*1500cf0);*/typedef void(__thiscall* _ProcessEvent)(ArkNpc* _this, SEntityEvent* param_1); _ProcessEvent	  ProcessEvent;
		/*1501430);*/typedef void(__thiscall* _ProcessStartGameEvent)(ArkNpc* _this, SEntityEvent* param_1); _ProcessStartGameEvent  ProcessStartGameEvent;
		/*1501750);*/typedef void(__thiscall* _PushAIAlwaysUpdate)(ArkNpc* _this); _PushAIAlwaysUpdate	  PushAIAlwaysUpdate;
		/*15017b0);*/typedef void(__thiscall* _PushAIAlwaysUpdateForPatrol)(ArkNpc* _this); _PushAIAlwaysUpdateForPatrol	  PushAIAlwaysUpdateForPatrol;
		/*1501830);*/typedef void(__thiscall* _PushAttentionDrainLockOnTarget)(ArkNpc* _this, uint32_t param_1); _PushAttentionDrainLockOnTarget  PushAttentionDrainLockOnTarget;
		/*1501890);*/typedef void(__thiscall* _PushDisableAiTree)(ArkNpc* _this); _PushDisableAiTree  PushDisableAiTree;
		/*1501920);*/typedef void(__thiscall* _PushDisableAllAmbientSounds)(ArkNpc* _this); _PushDisableAllAmbientSounds	  PushDisableAllAmbientSounds;
		/*15019c0);*/typedef void(__thiscall* _PushDisableAttentionAndSenses)(ArkNpc* _this); _PushDisableAttentionAndSenses  PushDisableAttentionAndSenses;
		/*1501a60);*/typedef void(__thiscall* _PushDisableAttentionObjectAndPerceivables)(ArkNpc* _this); _PushDisableAttentionObjectAndPerceivables  PushDisableAttentionObjectAndPerceivables;
		/*1501ae0);*/typedef void(__thiscall* _PushDisableAudible)(ArkNpc* _this); _PushDisableAudible	  PushDisableAudible;
		/*1501b20);*/typedef void(__thiscall* _PushDisableBreakable)(ArkNpc* _this); _PushDisableBreakable  PushDisableBreakable;
		/*1501b30);*/typedef void(__thiscall* _PushDisableDeathReactions)(ArkNpc* _this); _PushDisableDeathReactions  PushDisableDeathReactions;
		/*1501b40);*/typedef void(__thiscall* _PushDisableHearing)(ArkNpc* _this); _PushDisableHearing	  PushDisableHearing;
		/*1501b80);*/typedef void(__thiscall* _PushDisableHitReactions)(ArkNpc* _this); _PushDisableHitReactions	  PushDisableHitReactions;
		/*1501b90);*/typedef void(__thiscall* _PushDisableLifetimeEffect)(ArkNpc* _this); _PushDisableLifetimeEffect  PushDisableLifetimeEffect;
		/*1501be0);*/typedef void(__thiscall* _PushDisableNpcHealthUI)(ArkNpc* _this); _PushDisableNpcHealthUI	  PushDisableNpcHealthUI;
		/*1501bf0);*/typedef void(__thiscall* _PushDisableOperatorLevitatorsEffect)(ArkNpc* _this); _PushDisableOperatorLevitatorsEffect	  PushDisableOperatorLevitatorsEffect;
		/*1501c40);*/typedef void(__thiscall* _PushDisableSenses)(ArkNpc* _this); _PushDisableSenses  PushDisableSenses;
		/*1501cc0);*/typedef void(__thiscall* _PushDisableVisible)(ArkNpc* _this); _PushDisableVisible	  PushDisableVisible;
		/*1501d00);*/typedef void(__thiscall* _PushDisableVision)(ArkNpc* _this); _PushDisableVision  PushDisableVision;
		/*1501d40);*/typedef void(__thiscall* _PushDumbed)(ArkNpc* _this); _PushDumbed	  PushDumbed;
		/*1501d60);*/typedef void(__thiscall* _PushEnableAbilities)(ArkNpc* _this); _PushEnableAbilities	  PushEnableAbilities;
		/*1501d70);*/typedef void(__thiscall* _PushEnableAiTree)(ArkNpc* _this); _PushEnableAiTree  PushEnableAiTree;
		/*14ffb70);*/typedef void(__thiscall* _PushEnableAttentionObject)(ArkNpc* _this); _PushEnableAttentionObject  PushEnableAttentionObject;
		/*14ffbb0);*/typedef void(__thiscall* _PushEnableAttentiveSubject)(ArkNpc* _this); _PushEnableAttentiveSubject	  PushEnableAttentiveSubject;
		/*14ffbf0);*/typedef void(__thiscall* _PushEnableAudible)(ArkNpc* _this); _PushEnableAudible  PushEnableAudible;
		/*1501ec0);*/typedef void(__thiscall* _PushEnableGlassBreaking)(ArkNpc* _this); _PushEnableGlassBreaking	  PushEnableGlassBreaking;
		/*1501f10);*/typedef void(__thiscall* _PushEnableHearing)(ArkNpc* _this); _PushEnableHearing  PushEnableHearing;
		/*1501f50);*/typedef void(__thiscall* _PushEnableLifetimeEffect)(ArkNpc* _this); _PushEnableLifetimeEffect  PushEnableLifetimeEffect;
		/*1501fb0);*/typedef void(__thiscall* _PushEnableOperatorLevitatorsEffect)(ArkNpc* _this); _PushEnableOperatorLevitatorsEffect	  PushEnableOperatorLevitatorsEffect;
		/*1502010);*/typedef void(__thiscall* _PushEnableRoomPerceiver)(ArkNpc* _this); _PushEnableRoomPerceiver	  PushEnableRoomPerceiver;
		/*1502050);*/typedef void(__thiscall* _PushEnableVisible)(ArkNpc* _this); _PushEnableVisible  PushEnableVisible;
		/*1502090);*/typedef void(__thiscall* _PushEnableVision)(ArkNpc* _this); _PushEnableVision  PushEnableVision;
		/*15020d0);*/typedef void(__thiscall* _PushEnabledAmbientSound)(ArkNpc* _this, EArkNpcAmbientSoundId param_1); _PushEnabledAmbientSound	  PushEnabledAmbientSound;
		/*1502140);*/typedef void(__thiscall* _PushFear)(ArkNpc* _this, uint32_t param_1, bool param_2, bool param_3, bool param_4); _PushFear  PushFear;
		/*1502200);*/typedef void(__thiscall* _PushForceRigidOnGloo)(ArkNpc* _this); _PushForceRigidOnGloo  PushForceRigidOnGloo;
		/*1502210);*/typedef bool(__thiscall* _PushIndefiniteRagdoll)(ArkNpc* _this); _PushIndefiniteRagdoll  PushIndefiniteRagdoll;
		/*15022e0);*/typedef void(__thiscall* _QueueStimulus_CallForHelp)(ArkNpc* _this, IEntity* param_1, IEntity* param_2); _QueueStimulus_CallForHelp  QueueStimulus_CallForHelp;
		/*15023c0);*/typedef void(__thiscall* _QueueStimulus_Diagnose)(ArkNpc* _this); _QueueStimulus_Diagnose	  QueueStimulus_Diagnose;
		/*1502490);*/typedef void(__thiscall* _QueueStimulus_Escape)(ArkNpc* _this); _QueueStimulus_Escape  QueueStimulus_Escape;
		/*1502560);*/typedef void(__thiscall* _QueueStimulus_FrightfulNoise)(ArkNpc* _this, IEntity* param_1, Vec3_tpl<float>* param_2, float param_3); _QueueStimulus_FrightfulNoise	  QueueStimulus_FrightfulNoise;
		/*1502640);*/typedef void(__thiscall* _QueueStimulus_MovementEvent)(ArkNpc* _this, ArkAiTreeInstanceNode* param_1, EArkNpcMovementDesireCallbackEvent param_2); _QueueStimulus_MovementEvent	  QueueStimulus_MovementEvent;
		/*1502720);*/typedef bool(__thiscall* _Ragdoll)(ArkNpc* _this, ArkInterval<float>* param_1); _Ragdoll  Ragdoll;
		/*15027f0);*/typedef void(__thiscall* _RefreshCombatIntensity)(ArkNpc* _this, bool param_1); _RefreshCombatIntensity  RefreshCombatIntensity;
		/*1502880);*/typedef bool(__thiscall* _RefreshNotice)(ArkNpc* _this, Vec3_tpl<float>* param_1, ArkInterval<float>* param_2, ArkInterval<float>* param_3); _RefreshNotice  RefreshNotice;
		/*1502890);*/typedef void(__thiscall* _RegisterOnFleeNodeCallsbacks)(ArkNpc* _this, ArkDelegate<void __cdecl(void)> param_1, ArkDelegate<void __cdecl(void)> param_2); _RegisterOnFleeNodeCallsbacks	  RegisterOnFleeNodeCallsbacks;
		/*15028c0);*/typedef void(__thiscall* _Release)(ArkNpc* _this); _Release	  Release;
		/*1502970);*/typedef void(__thiscall* _ReloadAmmo)(ArkNpc* _this); _ReloadAmmo	  ReloadAmmo;
		/*1502980);*/typedef void(__thiscall* _RemoveAmmoAmount)(ArkNpc* _this, uint32_t param_1); _RemoveAmmoAmount	  RemoveAmmoAmount;
		/*1502990);*/typedef void(__thiscall* _RemoveCollisionObserver)(ArkNpc* _this, ArkNpcCollisionObserver* param_1); _RemoveCollisionObserver  RemoveCollisionObserver;
		/*15029d0);*/typedef void(__thiscall* _RemoveFacingDesire)(ArkNpc* _this, ArkNpcFacingDesire* param_1); _RemoveFacingDesire	  RemoveFacingDesire;
		/*1502a60);*/typedef void(__thiscall* _RemoveHead)(ArkNpc* _this); _RemoveHead	  RemoveHead;
		/*1502b40);*/typedef void(__thiscall* _RemoveInboundModifier)(ArkNpc* _this, uint64_t param_1); _RemoveInboundModifier	  RemoveInboundModifier;
		/*1502b80);*/typedef void(__thiscall* _RemoveLookDesire)(ArkNpc* _this, ArkNpcLookDesire* param_1); _RemoveLookDesire	  RemoveLookDesire;
		/*1502c10);*/typedef void(__thiscall* _RemoveMovementDesire)(ArkNpc* _this, ArkNpcMovementDesire* param_1); _RemoveMovementDesire	  RemoveMovementDesire;
		/*1502ca0);*/typedef void(__thiscall* _RemoveNoiseStateDesire)(ArkNpc* _this, ArkNpcNoiseStateDesire* param_1); _RemoveNoiseStateDesire	  RemoveNoiseStateDesire;
		/*1502d30);*/typedef void(__thiscall* _RemoveSpeedDesire)(ArkNpc* _this, ArkNpcSpeedDesire* param_1); _RemoveSpeedDesire  RemoveSpeedDesire;
		/*1502dc0);*/typedef void(__thiscall* _RequestDistraction)(ArkNpc* _this, uint32_t param_1, uint64_t param_2); _RequestDistraction	  RequestDistraction;
		/*1502ea0);*/typedef void(__thiscall* _RequestLurk)(ArkNpc* _this, uint32_t param_1, uint32_t param_2, bool param_3, bool param_4); _RequestLurk	  RequestLurk;
		/*1502f80);*/typedef void(__thiscall* _RequestStopLurk)(ArkNpc* _this); _RequestStopLurk	  RequestStopLurk;
		/*1503050);*/typedef void(__thiscall* _ResetAIAlwaysUpdate)(ArkNpc* _this); _ResetAIAlwaysUpdate	  ResetAIAlwaysUpdate;
		/*15030b0);*/typedef void(__thiscall* _ResetPlayerBumpTimer)(ArkNpc* _this); _ResetPlayerBumpTimer  ResetPlayerBumpTimer;
		/*15030c0);*/typedef bool(__thiscall* _Resist)(ArkNpc* _this, Vec3_tpl<float>* param_1, float param_2); _Resist	  Resist;
		/*1503140);*/typedef void(__thiscall* _ScaleLookDesireSpeed)(ArkNpc* _this, float param_1); _ScaleLookDesireSpeed	  ScaleLookDesireSpeed;
		/*1503150);*/typedef void(__thiscall* _Serialize)(ArkNpc* _this, CSerializeWrapper<ISerialize> param_1); _Serialize  Serialize;
		/*15034d0);*/typedef void(__thiscall* _SetAnimTag)(ArkNpc* _this, char* param_1, bool param_2); _SetAnimTag	  SetAnimTag;
		/*1503620);*/typedef void(__thiscall* _SetBreakGlooEntity)(ArkNpc* _this, uint32_t param_1); _SetBreakGlooEntity  SetBreakGlooEntity;
		/*1503630);*/typedef void(__thiscall* _SetCachedThrowAtLocation)(ArkNpc* _this, Vec3_tpl<float>* param_1, EReactionThrowAtType param_2); _SetCachedThrowAtLocation  SetCachedThrowAtLocation;
		/*1503650);*/typedef void(__thiscall* _SetComplexHearingGain)(ArkNpc* _this, float param_1); _SetComplexHearingGain  SetComplexHearingGain;
		/*1503660);*/typedef void(__thiscall* _SetComplexVisionGain)(ArkNpc* _this, float param_1); _SetComplexVisionGain	  SetComplexVisionGain;
		/*1503670);*/typedef void(__thiscall* _SetConversationFacingTarget)(ArkNpc* _this, uint32_t param_1); _SetConversationFacingTarget  SetConversationFacingTarget;
		/*1503780);*/typedef void(__thiscall* _SetConversationLookTarget)(ArkNpc* _this, uint32_t param_1, bool param_2); _SetConversationLookTarget  SetConversationLookTarget;
		/*1503900);*/typedef void(__thiscall* _SetCurrentCombatRole)(ArkNpc* _this, EArkCombatRole param_1); _SetCurrentCombatRole  SetCurrentCombatRole;
		/*15039e0);*/typedef void(__thiscall* _SetEthericDoppelgangerId)(ArkNpc* _this, uint32_t param_1); _SetEthericDoppelgangerId	  SetEthericDoppelgangerId;
		/*15039f0);*/typedef void(__thiscall* _SetEthericDoppengangerOwnerId)(ArkNpc* _this, uint32_t param_1); _SetEthericDoppengangerOwnerId	  SetEthericDoppengangerOwnerId;
		/*1503a00);*/typedef void(__thiscall* _SetFearFromHostileDamage)(ArkNpc* _this, bool param_1); _SetFearFromHostileDamage	  SetFearFromHostileDamage;
		/*1503a70);*/typedef void(__thiscall* _SetHasPerformedNotice)(ArkNpc* _this, bool param_1); _SetHasPerformedNotice	  SetHasPerformedNotice;
		/*1503ab0);*/typedef void(__thiscall* _SetHypnotizeStartTimeStamp)(ArkNpc* _this); _SetHypnotizeStartTimeStamp	  SetHypnotizeStartTimeStamp;
		/*1503ae0);*/typedef void(__thiscall* _SetIsEthericDoppelganger)(ArkNpc* _this, bool param_1); _SetIsEthericDoppelganger	  SetIsEthericDoppelganger;
		/*1503af0);*/typedef void(__thiscall* _SetIsHitReactingPrereqFlag)(ArkNpc* _this, bool param_1); _SetIsHitReactingPrereqFlag  SetIsHitReactingPrereqFlag;
		/*1503b00);*/typedef void(__thiscall* _SetIsIgnoringRangedAbilities)(ArkNpc* _this, bool param_1); _SetIsIgnoringRangedAbilities	  SetIsIgnoringRangedAbilities;
		/*1503b10);*/typedef void(__thiscall* _SetIsPlayerControlled)(ArkNpc* _this); _SetIsPlayerControlled  SetIsPlayerControlled;
		/*1503b80);*/typedef void(__thiscall* _SetIsRegainingLoSPrereqFlag)(ArkNpc* _this, bool param_1); _SetIsRegainingLoSPrereqFlag  SetIsRegainingLoSPrereqFlag;
		/*1503b90);*/typedef void(__thiscall* _SetPistolHidden)(ArkNpc* _this, bool param_1); _SetPistolHidden  SetPistolHidden;
		/*1503bd0);*/typedef void(__thiscall* _SetShouldSkipNextCombatReaction)(ArkNpc* _this, bool param_1); _SetShouldSkipNextCombatReaction  SetShouldSkipNextCombatReaction;
		/*1503be0);*/typedef void(__thiscall* _SetSpawnedState)(ArkNpc* _this, boost::variant<ArkNpcSpawnedState_Alert, ArkNpcSpawnedState_Broken, ArkNpcSpawnedState_Dead, ArkNpcSpawnedState_Dormant>* param_1); _SetSpawnedState	  SetSpawnedState;
		/*1503c90);*/typedef void(__thiscall* _SetStance)(ArkNpc* _this, EStance param_1); _SetStance	  SetStance;
		/*1503cd0);*/typedef void(__thiscall* _SetTimeUntilDeath)(ArkNpc* _this, float param_1); _SetTimeUntilDeath  SetTimeUntilDeath;
		/*1503ce0);*/typedef void(__thiscall* _SetTransitionStateTag)(ArkNpc* _this, char* param_1); _SetTransitionStateTag  SetTransitionStateTag;
		/*1503d10);*/typedef void(__thiscall* _SetWanderAreaContainerEntity)(ArkNpc* _this, uint32_t param_1); _SetWanderAreaContainerEntity	  SetWanderAreaContainerEntity;
		/*1503e10);*/typedef void(__thiscall* _SetWanderFollowEntityId)(ArkNpc* _this, uint32_t param_1); _SetWanderFollowEntityId  SetWanderFollowEntityId;
		/*1503ed0);*/typedef void(__thiscall* _ShiftBegin)(ArkNpc* _this, ShiftType param_1); _ShiftBegin  ShiftBegin;
		/*1503f90);*/typedef void(__thiscall* _ShiftEnd)(ArkNpc* _this, ShiftType param_1); _ShiftEnd	  ShiftEnd;
		/*1504010);*/typedef void(__thiscall* _ShiftTelegraph)(ArkNpc* _this, ShiftType param_1); _ShiftTelegraph  ShiftTelegraph;
		/*15040b0);*/typedef bool(__thiscall* _ShouldBecomeRigidOnGloo)(ArkNpc* _this); _ShouldBecomeRigidOnGloo	  ShouldBecomeRigidOnGloo;
		/*15040c0);*/typedef bool(__thiscall* _ShouldMimicRebound)(ArkNpc* _this, IEntity* param_1, Vec3_tpl<float>* param_2); _ShouldMimicRebound	  ShouldMimicRebound;
		/*15041e0);*/typedef void(__thiscall* _SpawnLootOnDeath)(ArkNpc* _this); _SpawnLootOnDeath  SpawnLootOnDeath;
		/*15046f0);*/typedef void(__thiscall* _StartAmbientSound)(ArkNpc* _this, EArkNpcAmbientSoundId param_1); _StartAmbientSound  StartAmbientSound;
		/*15047b0);*/typedef void(__thiscall* _StartAttackGlow)(ArkNpc* _this); _StartAttackGlow	  StartAttackGlow;
		/*15047c0);*/typedef void(__thiscall* _StartAttackJitter)(ArkNpc* _this); _StartAttackJitter  StartAttackJitter;
		/*15047d0);*/typedef void(__thiscall* _StartCharacterEffect)(ArkNpc* _this, ArkCharacterEffectType param_1); _StartCharacterEffect  StartCharacterEffect;
		/*15047e0);*/typedef bool(__thiscall* _StartCowering)(ArkNpc* _this); _StartCowering  StartCowering;
		/*1504820);*/typedef void(__thiscall* _StartEnergizedDeath)(ArkNpc* _this); _StartEnergizedDeath	  StartEnergizedDeath;
		/*1504990);*/typedef void(__thiscall* _StartGlooEffects)(ArkNpc* _this, bool param_1); _StartGlooEffects	  StartGlooEffects;
		/*1504a60);*/typedef void(__thiscall* _StartInstantDeath)(ArkNpc* _this); _StartInstantDeath  StartInstantDeath;
		/*1504aa0);*/typedef void(__thiscall* _StartMaterialAnimation)(ArkNpc* _this, ArkMaterialAnimationType param_1, float param_2); _StartMaterialAnimation	  StartMaterialAnimation;
		/*1504ab0);*/typedef void(__thiscall* _StartOnFireEffect)(ArkNpc* _this); _StartOnFireEffect  StartOnFireEffect;
		/*1504ac0);*/typedef void(__thiscall* _StartOperatorArmIdle)(ArkNpc* _this); _StartOperatorArmIdle  StartOperatorArmIdle;
		/*1504b30);*/typedef void(__thiscall* _StartPsiSuppressed)(ArkNpc* _this); _StartPsiSuppressed	  StartPsiSuppressed;
		/*1504bd0);*/typedef void(__thiscall* _StartRaiseFromCorpse)(ArkNpc* _this, bool param_1); _StartRaiseFromCorpse	  StartRaiseFromCorpse;
		/*1504c30);*/typedef void(__thiscall* _StartRaisePhantomCast)(ArkNpc* _this); _StartRaisePhantomCast  StartRaisePhantomCast;
		/*1504c40);*/typedef void(__thiscall* _StartStun)(ArkNpc* _this, uint32_t param_1, float param_2); _StartStun	  StartStun;
		/*1504d30);*/typedef void(__thiscall* _StartXRayVisionOn)(ArkNpc* _this, uint32_t param_1, float param_2); _StartXRayVisionOn	  StartXRayVisionOn;
		/*1504df0);*/typedef void(__thiscall* _StopCharacterEffect)(ArkNpc* _this, ArkCharacterEffectType param_1); _StopCharacterEffect	  StopCharacterEffect;
		/*1504e00);*/typedef bool(__thiscall* _StopCowering)(ArkNpc* _this); _StopCowering  StopCowering;
		/*1504e10);*/typedef void(__thiscall* _StopGlooEffects)(ArkNpc* _this); _StopGlooEffects	  StopGlooEffects;
		/*1504f30);*/typedef void(__thiscall* _StopMimicGlitch)(ArkNpc* _this); _StopMimicGlitch	  StopMimicGlitch;
		/*1504f40);*/typedef void(__thiscall* _StopOnFireEffect)(ArkNpc* _this); _StopOnFireEffect  StopOnFireEffect;
		/*1504f50);*/typedef void(__thiscall* _StopOperatorArmIdle)(ArkNpc* _this); _StopOperatorArmIdle	  StopOperatorArmIdle;
		/*1504fa0);*/typedef void(__thiscall* _StopStun)(ArkNpc* _this); _StopStun  StopStun;
		/*1504ff0);*/typedef void(__thiscall* _StopXRayVisionOn)(ArkNpc* _this, uint32_t param_1); _StopXRayVisionOn	  StopXRayVisionOn;
		/*15050a0);*/typedef bool(__thiscall* _SupportsLookAt)(ArkNpc* _this); _SupportsLookAt	  SupportsLookAt;
		/*15050b0);*/typedef bool(__thiscall* _TestInteraction)(ArkNpc* _this, IEntity* param_1, ArkInteractionInfo* param_2, EArkInteractionMode param_3, ArkInteractionTestResult* param_4); _TestInteraction	  TestInteraction;
		/*1505210);*/typedef bool(__thiscall* _TryDodge)(ArkNpc* _this, float param_1); _TryDodge	  TryDodge;
		/*1505490);*/typedef bool(__thiscall* _TryEvaluateAbilityContext)(ArkNpc* _this, uint64_t param_1, IEntity* param_2); _TryEvaluateAbilityContext  TryEvaluateAbilityContext;
		/*1505510);*/typedef bool(__thiscall* _TryEvaluateAndPerformAbilityContext)(ArkNpc* _this, uint64_t param_1, IEntity* param_2); _TryEvaluateAndPerformAbilityContext	  TryEvaluateAndPerformAbilityContext;
		/*15055b0);*/typedef bool(__thiscall* _TryPerformAbilityContext1)(ArkNpc* _this, uint64_t param_1, IEntity* param_2, IEntity* param_3); _TryPerformAbilityContext1	  TryPerformAbilityContext1;
		/*15056b0);*/typedef bool(__thiscall* _TryPerformAbilityContext2)(ArkNpc* _this, uint64_t param_1); _TryPerformAbilityContext2	  TryPerformAbilityContext2;
		// /*1505);6ctypedef 0*/thunk bool  TryPerformAbilityContext)(ArkNpc* _this, uint64_t param_1, IEntity* param_2, IEntity* param_3);															 											T_ryPerformAbilityContext	TryPerformAbilityContext;																																										   
		/*15056d0);*/typedef bool(__thiscall* _TryPerformAbilityContext3)(ArkNpc* _this, uint64_t param_1, IEntity* param_2); _TryPerformAbilityContext3  TryPerformAbilityContext3;
		/*15056e0);*/typedef bool(__thiscall* _TryPerformAnyAbility)(ArkNpc* _this, uint32_t param_1); _TryPerformAnyAbility	  TryPerformAnyAbility;
		/*1505780);*/typedef void(__thiscall* _UnCorrupt)(ArkNpc* _this, bool param_1); _UnCorrupt	  UnCorrupt;
		/*15057d0);*/typedef bool(__thiscall* _UnlockMimicry)(ArkNpc* _this); _UnlockMimicry  UnlockMimicry;
		// /*.82E);+0typedef 6*/bool  Update)(ArkNpc* _this, float param_1);																														 												U_pdate	Update;
		/*1505d70);*/typedef void(__thiscall* _Update)(ArkNpc* _this, SEntityUpdateContext* param_1, int32_t param_2); _Update	  Update;
		/*15068b0);*/typedef void(__thiscall* _UpdateFactions)(ArkNpc* _this, uint32_t param_1, float param_2); _UpdateFactions	  UpdateFactions;
		/*1506f50);*/typedef bool(__thiscall* _UpdateMaterialAnimation)(ArkNpc* _this, ArkMaterialAnimationType param_1, float param_2, float param_3); _UpdateMaterialAnimation	  UpdateMaterialAnimation;
		/*1506f60);*/typedef bool(__thiscall* _WaitForAnimatedStunned)(ArkNpc* _this); _WaitForAnimatedStunned	  WaitForAnimatedStunned;
	};
	class CArkNpcSpawnCystoidPrivate : PreyFunctionBaseOld{
	public:
		CArkNpcSpawnCystoidPrivate(uintptr_t moduleBase);
		typedef IEntityArchetype* (__thiscall* _GetEntityArchetype)(CArkNpcSpawnCystoid*); _GetEntityArchetype getEntityArchetype;
	};
	class ArkSafeScriptTablePrivate : PreyFunctionBaseOld {
	public:
		ArkSafeScriptTablePrivate(uintptr_t moduleBase);
		typedef void* (__thiscall* _GetArkSafeScriptTableFromEntity)(ArkSafeScriptTable*, IEntity*);
		typedef void* (__thiscall* _GetArkSafeScriptTableFromScriptTable)(ArkSafeScriptTable*, IScriptTable*);
		typedef bool(__thiscall* _GetCryStringTValue)(ArkSafeScriptTable*, char* param_1, CryStringT<char>* param_2);
		_GetCryStringTValue getCryStringTValue;// = (_GetCryStringTValue)(moduleBase + 0x1160740);
		_GetArkSafeScriptTableFromEntity getArkSafeScriptFromEntity;
		_GetArkSafeScriptTableFromScriptTable getArkSafeScriptFromScriptTable;// = (_GetArkSafeScriptTableFromScriptTable)(moduleBase + 0x1480240);
	};
	class ArkLocationManagerPrivate : PreyFunctionBaseOld {
	public:
		ArkLocationManagerPrivate(uintptr_t moduleBase);
		typedef LocationInfo* (__thiscall* _GetAlternateNameInfo)(ArkLocationManager* _this, uint64_t param_1);					_GetAlternateNameInfo				GetAlternateNameInfo;
		typedef uint64_t(__thiscall* _GetCurrentLocation)(ArkLocationManager* _this);											_GetCurrentLocation					GetCurrentLocation;
		typedef char* (__thiscall* _GetCurrentLocationLabel)(ArkLocationManager* _this);										_GetCurrentLocationLabel			GetCurrentLocationLabel;
		typedef char* (__thiscall* _GetCurrentLocationScreenshotPath)(ArkLocationManager* _this);								_GetCurrentLocationScreenshotPath	GetCurrentLocationScreenshotPath;
		typedef char* (__thiscall* _GetLocationLabel)(ArkLocationManager* _this, uint64_t param_1);								_GetLocationLabel					GetLocationLabel;
		typedef bool(__thiscall* _HasLoaded)(ArkLocationManager* _this, uint64_t param_1);										_HasLoaded							HasLoaded;
		typedef void(__thiscall* _RemoveAlternateName)(ArkLocationManager* _this, uint64_t param_1);							_RemoveAlternateName				RemoveAlternateName;
		typedef void(__thiscall* _Reset)(ArkLocationManager* _this);															_Reset								Reset;
		typedef void(__thiscall* _Serialize)(ArkLocationManager* _this, CSerializeWrapper<ISerialize> param_1);					_Serialize							Serialize;
		typedef void(__thiscall* _SetAlternateName)(ArkLocationManager* _this, uint64_t param_1, char* param_2, char* param_3);	_SetAlternateName					SetAlternateName;
		typedef void(__thiscall* _SetLoaded)(ArkLocationManager* _this, uint64_t param_1, bool param_2);						_SetLoaded							SetLoaded;
	};
	class ArkAbilitiesPrivate : PreyFunctionBaseOld {
	public:
		ArkAbilitiesPrivate(uintptr_t moduleBase);;
		// typedef ArkAbilities*
	};
	class ArkAbilityComponentPrivate : PreyFunctionBaseOld {
	public:
		ArkAbilityComponentPrivate(uintptr_t moduleBase);;
		typedef undefined(__thiscall* _ArkAbilityComponentConst)(ArkAbilityComponent* _this);;																			_ArkAbilityComponentConst			ArkAbilityComponentConst1	  ;
		typedef void(__thiscall* _ArkAbilityComponentConst2)(ArkAbilityComponent* _this);;																				_ArkAbilityComponentConst2		  	ArkAbilityComponentConst2	  ;
		typedef ArkAbilityUpgradeState(__thiscall* _GetAbilityState)(ArkAbilityComponent* _this, uint64_t param_1);;													_GetAbilityState					GetAbilityState		  ;
		typedef std::vector<ArkAbilityData*>(__thiscall* _GetAcquiredAbilities)(ArkAbilityComponent* _this);;														_GetAcquiredAbilities			  	GetAcquiredAbilities		  ;
		typedef uint64_t(__thiscall* _GetCurrencyArchetypeId)(void);;																									_GetCurrencyArchetypeId			  	GetCurrencyArchetypeId		  ;
		typedef int(__thiscall* _GetNumNeuromodsUsed)(ArkAbilityComponent* _this);;																						_GetNumNeuromodsUsed				GetNumNeuromodsUsed	  ;
		typedef float(__thiscall* _GetPlayerResearchFraction)(ArkAbilityComponent* _this, uint64_t param_1);;															_GetPlayerResearchFraction		  	GetPlayerResearchFraction	  ;
		typedef int(__thiscall* _GetResearchTopicScanCount)(ArkAbilityComponent* _this, uint64_t param_1);;																_GetResearchTopicScanCount		  	GetResearchTopicScanCount	  ;
		typedef ArkTyphonStatus(__thiscall* _GetTyphonStatus)(ArkAbilityComponent* _this);;																				_GetTyphonStatus					GetTyphonStatus		  ;
		typedef void(__thiscall* _GrantAbility)(ArkAbilityComponent* _this, uint64_t param_1);;																			_GrantAbility					  	GrantAbility				  ;
		typedef bool(__thiscall* _HasAbility)(ArkAbilityComponent* _this, uint64_t param_1);;																			_HasAbility						  	HasAbility					  ;
		typedef int(__thiscall* _IncrementResearchTopicScanCount)(ArkAbilityComponent* _this, uint64_t param_1, int param_2, uint64_t* param_3, uint32_t param_4);;		_IncrementResearchTopicScanCount	IncrementResearchTopicScanCount;
		typedef void(__thiscall* _InitAbilityResearchTopicData)(ArkAbilityComponent* _this);;																			_InitAbilityResearchTopicData	  	InitAbilityResearchTopicData ;
		typedef bool(__thiscall* _IsAbilityNameRevealedByAbilityData)(ArkAbilityComponent* _this, ArkAbilityData* param_1);;											_IsAbilityNameRevealedByAbilityData	IsAbilityNameRevealedByAbilityData;
		typedef bool(__thiscall* _IsAbilityNameRevealedByID)(ArkAbilityComponent* _this, uint64_t param_1);;															_IsAbilityNameRevealedByID			IsAbilityNameRevealedByID;
		typedef bool(__thiscall* _IsAbilityNew)(ArkAbilityComponent* _this, uint64_t param_1);;																			_IsAbilityNew					  	IsAbilityNew				  ;
		typedef bool(__thiscall* _IsAbilityResearched)(ArkAbilityComponent* _this, uint64_t param_1);;																	_IsAbilityResearched				IsAbilityResearched	  ;
		typedef bool(__thiscall* _IsAbilityVisible)(ArkAbilityComponent* _this, uint64_t param_1);;																		_IsAbilityVisible				  	IsAbilityVisible			  ;
		typedef void(__thiscall* _LoadConfig)(ArkAbilityComponent* _this, XmlNodeRef param_1);;																			_LoadConfig						  	LoadConfig					  ;
		typedef bool(__thiscall* _MarkAbilitySeen)(ArkAbilityComponent* _this, uint64_t param_1);;																		_MarkAbilitySeen					MarkAbilitySeen		  ;
		typedef void(__thiscall* _OnGrantAbilityCheat)(ArkAbilityComponent* _this, uint64_t param_1, bool param_2);;													_OnGrantAbilityCheat				OnGrantAbilityCheat	  ;
		typedef void(__thiscall* _OnPDAOpenComplete)(ArkAbilityComponent* _this);;																						_OnPDAOpenComplete				  	OnPDAOpenComplete			  ;
		typedef void(__thiscall* _PostSerialize)(ArkAbilityComponent* _this);;																							_PostSerialize					  	PostSerialize				  ;
		typedef bool(__thiscall* _PurchaseAbility)(ArkAbilityComponent* _this, uint64_t param_1);;																		_PurchaseAbility					PurchaseAbility		  ;
		typedef void(__thiscall* _Reset)(ArkAbilityComponent* _this);;																									_Reset							  	Reset						  ;
		typedef void(__thiscall* _Serialize)(ArkAbilityComponent* _this, CSerializeWrapper<ISerialize> param_1);;														_Serialize						  	Serialize					  ;
		typedef void(__thiscall* _ShowLastResearchedAbility)(ArkAbilityComponent* _this);;																				_ShowLastResearchedAbility		  	ShowLastResearchedAbility	  ;
		typedef void(__thiscall* _UpdatePlayerMetrics)(ArkAbilityComponent* _this);;																					_UpdatePlayerMetrics				UpdatePlayerMetrics	  ;
	};

	class CKeyboardPrivate : PreyFunctionBaseOld {
	public:
		CKeyboardPrivate(uintptr_t moduleBase);
		using _Update = bool (*)(CKeyboard *_this, bool bFocus);
		_Update Update;
	};

	class CBaseInputPrivate : PreyFunctionBaseOld {
	public:
		CBaseInputPrivate(uintptr_t moduleBase);
		using _PostInputEvent = void (*)(CBaseInput *_this, const SInputEvent &event, bool bForce);
		_PostInputEvent PostInputEvent;
	};

	typedef unsigned long(__cdecl *_CryGetCurrentThreadID)(); _CryGetCurrentThreadID CryGretCurrentThreadId;//0099910
	typedef Vec2_tpl<float>(__thiscall* _BeginDraw)(CWindowsConsole*); _BeginDraw beginDraw;//0de9710
	// typedef void (__thiscall* _OnToggleDebugMenu)();
	ArkSafeScriptTablePrivate* ArkSafeScriptTablef;
	CArkNpcSpawnCystoidPrivate* CArkNpcSpawnCystoidF;
	ArkPlayerPrivate *ArkPlayerF;
	CArkWeaponPrivate *CArkWeaponF;
	CEntitySystemPrivate* CEntitySystemF;
	ArkNpcSpawnManagerPrivate* ArkNpcSpawnManagerF;
	CEntityPrivate *CEntity;
	ArkNightmareSpawnManagerPrivate *ArkNightmareSpawnManagerF;
	CArkNpcSpawnerPrivate *CArkNpcSpawnerF;
	CXConsolePrivate *CXConsoleF;
	ArkFactionManagerPrivate* ArkFactionManagerF;
	ArkNpcPrivate* ArkNpcF;
	ArkLocationManagerPrivate* ArkLocationManagerF;
	ArkAbilityComponentPrivate* ArkAbilityComponentF;
	CKeyboardPrivate* CKeyboardF;
	CBaseInputPrivate* CBaseInputF;
};

extern PreyFunctions *gPreyFuncs;

// class ArkPlayer {
// 	
// };


