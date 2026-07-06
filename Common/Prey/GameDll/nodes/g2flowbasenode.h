// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/GameDll/ark/flowgraph/arkflownodegravshaft.h>
#include <Prey/GameDll/ark/flowgraph/arkflownodehelpers.h>
#include <Prey/GameDll/nodes/flowpostfxnodes.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ArkFlowEnablePlayerSimulationReset;
class ArkFlowForceSatellite;
class ArkFlowGetRandomValue;
class ArkFlowGetShuffledListValue;
class ArkFlowHideRobotLight;
class ArkFlowInhibitJump;
class ArkFlowLockRandomSeed;
class ArkFlowNeuromod;
class ArkFlowNightmareManagerEnable;
class ArkFlowNodeAbsoluteTimeEvent;
class ArkFlowNodeAttentionLevelChanged;
class ArkFlowNodeAudioLogEvent;
class ArkFlowNodeCarry;
class ArkFlowNodeClearAttention;
class ArkFlowNodeClearDispositionEntityEntity;
class ArkFlowNodeClearDispositionEntityFaction;
class ArkFlowNodeClearDispositionEntityToFactionEntities;
class ArkFlowNodeClearDispositionFactionEntitiesToEntity;
class ArkFlowNodeClearDispositionFactionEntitiesToFaction;
class ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities;
class ArkFlowNodeClearDispositionFactionFaction;
class ArkFlowNodeClearDispositionFactionToFactionEntities;
class ArkFlowNodeClearRelationshipFactionEntity;
class ArkFlowNodeCreatePhantom;
class ArkFlowNodeDispositionSwitch;
class ArkFlowNodeDissipateNightmare;
class ArkFlowNodeDoomClock;
class ArkFlowNodeDoomClockProfile;
class ArkFlowNodeEffectiveDisposition_EntityToEntity;
class ArkFlowNodeEffectiveDisposition_EntityToFaction;
class ArkFlowNodeEffectiveDisposition_FactionToEntity;
class ArkFlowNodeEnableDoomClock;
class ArkFlowNodeEnablePatrolPath;
class ArkFlowNodeEndHostilityEntityEntity;
class ArkFlowNodeEndHostilityEntityFaction;
class ArkFlowNodeEndHostilityFactionEntity;
class ArkFlowNodeEndHostilityFactionFaction;
class ArkFlowNodeFlashlight;
class ArkFlowNodeGenderSelectMenu;
class ArkFlowNodeGetAttention;
class ArkFlowNodeGetDispositionEntityEntity;
class ArkFlowNodeGetDispositionEntityFaction;
class ArkFlowNodeGetDispositionFactionEntity;
class ArkFlowNodeGetDispositionFactionFaction;
class ArkFlowNodeGetDoomClockLevel;
class ArkFlowNodeGetFaction;
class ArkFlowNodeGetGameTime;
class ArkFlowNodeGetPlayerCombatState;
class ArkFlowNodeIsEntityFriendlyToEntity;
class ArkFlowNodeIsEntityFriendlyToFaction;
class ArkFlowNodeIsEntityHostileToEntity;
class ArkFlowNodeIsEntityHostileToFaction;
class ArkFlowNodeIsEntityNeutralToEntity;
class ArkFlowNodeIsEntityNeutralToFaction;
class ArkFlowNodeIsFactionFriendlyToEntity;
class ArkFlowNodeIsFactionFriendlyToFaction;
class ArkFlowNodeIsFactionHostileToEntity;
class ArkFlowNodeIsFactionHostileToFaction;
class ArkFlowNodeIsFactionNeutralToEntity;
class ArkFlowNodeIsFactionNeutralToFaction;
class ArkFlowNodeMakeAiNoise;
class ArkFlowNodeNPCCallMimicsTest;
class ArkFlowNodeNpcAiDumb;
class ArkFlowNodeNpcCreatePhantomInstant;
class ArkFlowNodeNpcEnableAI;
class ArkFlowNodeNpcEnableDistraction;
class ArkFlowNodeNpcEnableWander;
class ArkFlowNodeNpcEncounterEnableWander;
class ArkFlowNodeNpcEncounterIgnoreDistract;
class ArkFlowNodeNpcEncounterPatrolRequest;
class ArkFlowNodeNpcEncounterSetWanderContainer;
class ArkFlowNodeNpcGodMode;
class ArkFlowNodeNpcGodModeAll;
class ArkFlowNodeNpcHasAllTags;
class ArkFlowNodeNpcHasAnyTags;
class ArkFlowNodeNpcIgnoreDistract;
class ArkFlowNodeNpcLockBurrow;
class ArkFlowNodeNpcLockMimicry;
class ArkFlowNodeNpcLockStance;
class ArkFlowNodeNpcLockUnburrow;
class ArkFlowNodeNpcLookAtEntityCustom;
class ArkFlowNodeNpcMakeConscious;
class ArkFlowNodeNpcNightmareForceMode;
class ArkFlowNodeNpcPatrolRequest;
class ArkFlowNodeNpcPatrolRequestClosest;
class ArkFlowNodeNpcPoltergeistThrow;
class ArkFlowNodeNpcSetWanderContainer;
class ArkFlowNodeNpcStopLurking;
class ArkFlowNodeNpcStopLurkingForEncounter;
class ArkFlowNodeNpcStopMimicking;
class ArkFlowNodeNpcStopMimickingForEncounter;
class ArkFlowNodeNpcTrackView_GetStartPos;
class ArkFlowNodeNpcTrackView_SetDynamicNode;
class ArkFlowNodeNpcUnlockBurrow;
class ArkFlowNodeNpcUnlockMimicry;
class ArkFlowNodeNpcUnlockUnburrow;
class ArkFlowNodePlayerAlien;
class ArkFlowNodePlayerCombatStateChanged;
class ArkFlowNodeRelativeTimeEvent;
class ArkFlowNodeRemoveLocationAlternateName;
class ArkFlowNodeResetPDAData;
class ArkFlowNodeScanAlienEvent;
class ArkFlowNodeSetCharacterAlternateName;
class ArkFlowNodeSetDispositionEntityEntity;
class ArkFlowNodeSetDispositionEntityFaction;
class ArkFlowNodeSetDispositionEntityToFactionEntities;
class ArkFlowNodeSetDispositionFactionEntitiesToEntity;
class ArkFlowNodeSetDispositionFactionEntitiesToFaction;
class ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities;
class ArkFlowNodeSetDispositionFactionEntity;
class ArkFlowNodeSetDispositionFactionFaction;
class ArkFlowNodeSetDispositionFactionToFactionEntities;
class ArkFlowNodeSetFaction;
class ArkFlowNodeSetGameTime;
class ArkFlowNodeSetLocationAlternateName;
class ArkFlowNodeSetPortalOcclusion;
class ArkFlowNodeStartLurking;
class ArkFlowNodeStartMimicking;
class ArkFlowNodeUnhideAbility;
class ArkFlowNode_EnableEnemyHealthMeter;
class ArkFlowNode_FabricationPlanAcquired;
class ArkFlowNode_GetCharacterSpecialObjective;
class ArkFlowNode_GetPlayableCharacter;
class ArkFlowNode_ItemFabricated;
class ArkFlowNode_ItemRecycled;
class ArkFlowNode_KillLatentPowers;
class ArkFlowNode_LearnNameForResearchTopic;
class ArkFlowNode_PlayerCorpseCreated;
class ArkFlowNode_PostEffect;
class ArkFlowNode_PostEffectParameter;
class ArkFlowNode_RestrictPlayerItems;
class ArkFlowNode_SetFabricationPlanError;
class ArkFlowNode_SetPlayableCharacter;
class ArkFlowNode_SetStationAccess;
class ArkFlowNode_SilenceTranscribe;
class ArkFlowNode_TestDifficultyOption;
class ArkFlowNode_UpdatePlayableCharacterStatus;
class ArkFlowPlayerMannequinTag;
class ArkFlowReadyRoom;
class ArkFlowReadyRoomListener;
class ArkFlowReadyRoomRequest;
class ArkFlowResetGameToken;
class ArkFlowSendSignalPackage;
class ArkFlowSendSignalPackageInArea;
class ArkFlowSendSignalPackageToNpcsInVolume;
class CAchievementNode;
class CArkFlowNodeAddEncounter;
class CArkFlowNodeAddEncounterProfile;
class CArkFlowNodeAddEncounterSpawnInfo;
class CArkFlowNodeAddToEncounter;
class CArkFlowNodeChangeHelmet;
class CArkFlowNodeCharacterLocatedEvent;
class CArkFlowNodeCheckDownloadHidden;
class CArkFlowNodeCheckUtilityButtonEnabled;
class CArkFlowNodeCheckUtilityButtonHidden;
class CArkFlowNodeCheckUtilityEnabled;
class CArkFlowNodeCheckUtilityHidden;
class CArkFlowNodeCompareUtility;
class CArkFlowNodeCompareUtilityButton;
class CArkFlowNodeConversationStatus;
class CArkFlowNodeDiscoverLocation;
class CArkFlowNodeDownloadAcquired;
class CArkFlowNodeEliminateCurrentPopulation;
class CArkFlowNodeEmailAcquired;
class CArkFlowNodeEnableScope;
class CArkFlowNodeEntityLink;
class CArkFlowNodeFocusModeEnabled;
class CArkFlowNodeGetEquippedItem;
class CArkFlowNodeGetTaskState;
class CArkFlowNodeGiveAbility;
class CArkFlowNodeGiveNote;
class CArkFlowNodeHasAbility;
class CArkFlowNodeHasDiscoveredLocation;
class CArkFlowNodeHasNote;
class CArkFlowNodeHelmet;
class CArkFlowNodeHideEmail;
class CArkFlowNodeIncrementGameMetric;
class CArkFlowNodeKeyCardAcquired;
class CArkFlowNodeKeyCodeAcquired;
class CArkFlowNodeLearnResearch;
class CArkFlowNodeLocateCharacterObjectiveEvent;
class CArkFlowNodeNpcDeactivateCombatIntensity;
class CArkFlowNodeNpcDestroy;
class CArkFlowNodeNpcKill;
class CArkFlowNodeNpcKillByTag;
class CArkFlowNodePlayerCinematic;
class CArkFlowNodePlayerMimicState;
class CArkFlowNodePsiPowerActive;
class CArkFlowNodePsiPowerMenuActive;
class CArkFlowNodePsiPowerTargetingActive;
class CArkFlowNodePsiScanning;
class CArkFlowNodePurchaseRandomAbilities;
class CArkFlowNodeRefreshCurrentPopulation;
class CArkFlowNodeRemoteEvent;
class CArkFlowNodeRenderAlways;
class CArkFlowNodeSendEmail;
class CArkFlowNodeSetDownloadHidden;
class CArkFlowNodeSetEncounterProfile;
class CArkFlowNodeSetEquippedItem;
class CArkFlowNodeSetObjectiveDescription;
class CArkFlowNodeSetSpawnerActiveForEncounters;
class CArkFlowNodeSetTaskLocation;
class CArkFlowNodeSetTaskMarker;
class CArkFlowNodeSetTaskMarkerOverride;
class CArkFlowNodeSetUtilityButtonEnabled;
class CArkFlowNodeSetUtilityButtonHidden;
class CArkFlowNodeSetUtilityEnabled;
class CArkFlowNodeSetUtilityHidden;
class CArkFlowNodeSpawnAtTravelDest;
class CArkFlowNodeUnequipItem;
class CArkFlowNode_CheckArchetype;
class CArkFlowNode_ClearLevelMapFog;
class CArkFlowNode_ClosePDA;
class CArkFlowNode_CollectAudioLog;
class CArkFlowNode_CollectTutorialCard;
class CArkFlowNode_CompleteChecklistEntry;
class CArkFlowNode_CystoidManager;
class CArkFlowNode_EnableChecklistEntry;
class CArkFlowNode_EnableGameStateCondition;
class CArkFlowNode_EnableHUDArmor;
class CArkFlowNode_EnableHUDHealth;
class CArkFlowNode_EnablePDADateAndTime;
class CArkFlowNode_EnablePDAPage;
class CArkFlowNode_EndGame;
class CArkFlowNode_EntityControl;
class CArkFlowNode_EntityRender;
class CArkFlowNode_ExamineWorldUI;
class CArkFlowNode_ForceStopCameraShakes;
class CArkFlowNode_GameDisconnect;
class CArkFlowNode_HasEntitlement;
class CArkFlowNode_HideFailedAbilityInteractions;
class CArkFlowNode_InterferenceGameEffect;
class CArkFlowNode_IsArchetypeInWorld;
class CArkFlowNode_IsInChallengeMode;
class CArkFlowNode_KioskElevatorError;
class CArkFlowNode_MimicMorphEffect;
class CArkFlowNode_OnPlayerSpawned;
class CArkFlowNode_OpenPDAPage;
class CArkFlowNode_PopulateBonusContainer;
class CArkFlowNode_PopulateEndGameUI;
class CArkFlowNode_QueueTutorials;
class CArkFlowNode_SetConsumingOxygen;
class CArkFlowNode_SetPDAAccess;
class CArkFlowNode_SetPlayerStance;
class CArkFlowNode_SkipNextDeathDelay;
class CArkFlowNode_TestChecklistEntry;
class CArkFlowNode_TestFlashlight;
class CArkFlowNode_TriggerCameraShake;
class CArkFlowNode_UnlockTips;
class CArkFlowNode_UsePlayerTimer;
class CArkFlowNode_WhiplashPopup;
class CFlowControlPlayerHealthEffect;
class CFlowNode_AddEquipmentPack;
class CFlowNode_AddLoot;
class CFlowNode_ArkPlayerWeaponSensor;
class CFlowNode_GetNearestActor;
class CFlowNode_InventoryAddItem;
class CFlowNode_InventoryAddItemById;
class CFlowNode_InventoryGetItemQuantity;
class CFlowNode_InventoryRemoveAllItems;
class CFlowNode_InventoryRemoveItem;
class CFlowNode_OverrideFOV;
class CFlowNode_PlayerCinematicControl;
class CFlowNode_PlayerLookAt;
class CFlowNode_SetPostEffectParam;
class CFlowNode_SimulatePlayerInput;
class CFlowNode_SpawnItemArchetype;
class CFlowPlayerLinkNode;
class CFlowPlayerStagingNode;
class CTacticalScanCurrentControlNode;
class CTacticalScanNode;
class ICrySizer;
struct IFlowNode;

// CG2AutoRegFlowNodeBase
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNodeBase : public IFlowNodeFactory
{ // Size=24 (0x18)
public:
	const char* m_sClassName;
	CG2AutoRegFlowNodeBase* m_pNext;
	static inline auto m_pFirst = PreyGlobal<CG2AutoRegFlowNodeBase*>(0x2D83120);
	static inline auto m_pLast = PreyGlobal<CG2AutoRegFlowNodeBase*>(0x2D83128);

	virtual ~CG2AutoRegFlowNodeBase();
	virtual void AddRef();
	virtual void Release();
	virtual void Reset();
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CG2AutoRegFlowNodeBase(const char* _arg0_);
#endif

	static inline auto FBitNotCG2AutoRegFlowNodeBase = PreyFunction<void(CG2AutoRegFlowNodeBase* const _this)>(0x10D5030);
	static inline auto FAddRef = PreyFunction<void(CG2AutoRegFlowNodeBase* const _this)>(0x1333E90);
	static inline auto FRelease = PreyFunction<void(CG2AutoRegFlowNodeBase* const _this)>(0x1333E90);
	static inline auto FReset = PreyFunction<void(CG2AutoRegFlowNodeBase* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CG2AutoRegFlowNodeBase* const _this, ICrySizer* s)>(0x10D4FC0);
};

// CG2AutoRegFlowNode<ArkFlowEnablePlayerSimulationReset>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowEnablePlayerSimulationReset> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowEnablePlayerSimulationReset>(const char* _arg0_);
	ArkFlowEnablePlayerSimulationReset* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowEnablePlayerSimulationReset>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1468A60);
};

// CG2AutoRegFlowNode<ArkFlowForceSatellite>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowForceSatellite> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowForceSatellite>(const char* _arg0_);
	ArkFlowForceSatellite* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowForceSatellite>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x14689D0);
};

// CG2AutoRegFlowNode<ArkFlowGetRandomValue>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowGetRandomValue> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowGetRandomValue>(const char* _arg0_);
	ArkFlowGetRandomValue* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowGetRandomValue>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11E1FE0);
};

// CG2AutoRegFlowNode<ArkFlowGetShuffledListValue>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowGetShuffledListValue> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowGetShuffledListValue>(const char* _arg0_);
	ArkFlowGetShuffledListValue* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowGetShuffledListValue>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11E2A30);
};

// CG2AutoRegFlowNode<ArkFlowHideRobotLight>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowHideRobotLight> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowHideRobotLight>(const char* _arg0_);
	ArkFlowHideRobotLight* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowHideRobotLight>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x123D810);
};

// CG2AutoRegFlowNode<ArkFlowInhibitJump>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowInhibitJump> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowInhibitJump>(const char* _arg0_);
	ArkFlowInhibitJump* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowInhibitJump>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x123DBF0);
};

// CG2AutoRegFlowNode<ArkFlowLockRandomSeed>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowLockRandomSeed> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowLockRandomSeed>(const char* _arg0_);
	ArkFlowLockRandomSeed* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowLockRandomSeed>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11E2400);
};

// CG2AutoRegFlowNode<ArkFlowNeuromod>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNeuromod> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNeuromod>(const char* _arg0_);
	ArkFlowNeuromod* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNeuromod>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C0D50);
};

// CG2AutoRegFlowNode<ArkFlowNightmareManagerEnable>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNightmareManagerEnable> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNightmareManagerEnable>(const char* _arg0_);
	ArkFlowNightmareManagerEnable* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNightmareManagerEnable>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11DE1B0);
};

// CG2AutoRegFlowNode<ArkFlowNodeAbsoluteTimeEvent>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeAbsoluteTimeEvent> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeAbsoluteTimeEvent>(const char* _arg0_);
	ArkFlowNodeAbsoluteTimeEvent* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeAbsoluteTimeEvent>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x14C67C0);
};

// CG2AutoRegFlowNode<ArkFlowNodeAttentionLevelChanged>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeAttentionLevelChanged> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeAttentionLevelChanged>(const char* _arg0_);
	ArkFlowNodeAttentionLevelChanged* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeAttentionLevelChanged>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x150FC40);
};

// CG2AutoRegFlowNode<ArkFlowNodeAudioLogEvent>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeAudioLogEvent> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeAudioLogEvent>(const char* _arg0_);
	ArkFlowNodeAudioLogEvent* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeAudioLogEvent>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1312E20);
};

// CG2AutoRegFlowNode<ArkFlowNodeCarry>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeCarry> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeCarry>(const char* _arg0_);
	ArkFlowNodeCarry* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeCarry>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C3C30);
};

// CG2AutoRegFlowNode<ArkFlowNodeClearAttention>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeClearAttention> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeClearAttention>(const char* _arg0_);
	ArkFlowNodeClearAttention* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeClearAttention>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1528FF0);
};

// CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityEntity>(const char* _arg0_);
	ArkFlowNodeClearDispositionEntityEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B83A0);
};

// CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityFaction>(const char* _arg0_);
	ArkFlowNodeClearDispositionEntityFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BA080);
};

// CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityToFactionEntities>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityToFactionEntities> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityToFactionEntities>(const char* _arg0_);
	ArkFlowNodeClearDispositionEntityToFactionEntities* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionEntityToFactionEntities>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B6BA0);
};

// CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToEntity>(const char* _arg0_);
	ArkFlowNodeClearDispositionFactionEntitiesToEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B8C40);
};

// CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToFaction>(const char* _arg0_);
	ArkFlowNodeClearDispositionFactionEntitiesToFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B58D0);
};

// CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities>(const char* _arg0_);
	ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B5090);
};

// CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionFaction>(const char* _arg0_);
	ArkFlowNodeClearDispositionFactionFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BB810);
};

// CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionToFactionEntities>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionToFactionEntities> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionToFactionEntities>(const char* _arg0_);
	ArkFlowNodeClearDispositionFactionToFactionEntities* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeClearDispositionFactionToFactionEntities>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B9480);
};

// CG2AutoRegFlowNode<ArkFlowNodeClearRelationshipFactionEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeClearRelationshipFactionEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeClearRelationshipFactionEntity>(const char* _arg0_);
	ArkFlowNodeClearRelationshipFactionEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeClearRelationshipFactionEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BAC90);
};

// CG2AutoRegFlowNode<ArkFlowNodeCreatePhantom>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeCreatePhantom> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeCreatePhantom>(const char* _arg0_);
	ArkFlowNodeCreatePhantom* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeCreatePhantom>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x123F760);
};

// CG2AutoRegFlowNode<ArkFlowNodeDispositionSwitch>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeDispositionSwitch> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeDispositionSwitch>(const char* _arg0_);
	ArkFlowNodeDispositionSwitch* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeDispositionSwitch>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B5C40);
};

// CG2AutoRegFlowNode<ArkFlowNodeDissipateNightmare>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeDissipateNightmare> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeDissipateNightmare>(const char* _arg0_);
	ArkFlowNodeDissipateNightmare* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeDissipateNightmare>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11DE830);
};

// CG2AutoRegFlowNode<ArkFlowNodeDoomClock>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeDoomClock> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeDoomClock>(const char* _arg0_);
	ArkFlowNodeDoomClock* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeDoomClock>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x131E3E0);
};

// CG2AutoRegFlowNode<ArkFlowNodeDoomClockProfile>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeDoomClockProfile> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeDoomClockProfile>(const char* _arg0_);
	ArkFlowNodeDoomClockProfile* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeDoomClockProfile>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x131E590);
};

// CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_EntityToEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_EntityToEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_EntityToEntity>(const char* _arg0_);
	ArkFlowNodeEffectiveDisposition_EntityToEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_EntityToEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B7720);
};

// CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_EntityToFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_EntityToFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_EntityToFaction>(const char* _arg0_);
	ArkFlowNodeEffectiveDisposition_EntityToFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_EntityToFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B5FA0);
};

// CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_FactionToEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_FactionToEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_FactionToEntity>(const char* _arg0_);
	ArkFlowNodeEffectiveDisposition_FactionToEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeEffectiveDisposition_FactionToEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B6300);
};

// CG2AutoRegFlowNode<ArkFlowNodeEnableDoomClock>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeEnableDoomClock> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeEnableDoomClock>(const char* _arg0_);
	ArkFlowNodeEnableDoomClock* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeEnableDoomClock>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x131E470);
};

// CG2AutoRegFlowNode<ArkFlowNodeEnablePatrolPath>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeEnablePatrolPath> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeEnablePatrolPath>(const char* _arg0_);
	ArkFlowNodeEnablePatrolPath* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeEnablePatrolPath>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D7F30);
};

// CG2AutoRegFlowNode<ArkFlowNodeEndHostilityEntityEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeEndHostilityEntityEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeEndHostilityEntityEntity>(const char* _arg0_);
	ArkFlowNodeEndHostilityEntityEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeEndHostilityEntityEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B44D0);
};

// CG2AutoRegFlowNode<ArkFlowNodeEndHostilityEntityFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeEndHostilityEntityFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeEndHostilityEntityFaction>(const char* _arg0_);
	ArkFlowNodeEndHostilityEntityFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeEndHostilityEntityFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B45F0);
};

// CG2AutoRegFlowNode<ArkFlowNodeEndHostilityFactionEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeEndHostilityFactionEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeEndHostilityFactionEntity>(const char* _arg0_);
	ArkFlowNodeEndHostilityFactionEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeEndHostilityFactionEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B4560);
};

// CG2AutoRegFlowNode<ArkFlowNodeEndHostilityFactionFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeEndHostilityFactionFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeEndHostilityFactionFaction>(const char* _arg0_);
	ArkFlowNodeEndHostilityFactionFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeEndHostilityFactionFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B4680);
};

// CG2AutoRegFlowNode<ArkFlowNodeFlashlight>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeFlashlight> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeFlashlight>(const char* _arg0_);
	ArkFlowNodeFlashlight* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeFlashlight>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1681FE0);
};

// CG2AutoRegFlowNode<ArkFlowNodeGenderSelectMenu>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeGenderSelectMenu> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeGenderSelectMenu>(const char* _arg0_);
	ArkFlowNodeGenderSelectMenu* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeGenderSelectMenu>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x14235A0);
};

// CG2AutoRegFlowNode<ArkFlowNodeGetAttention>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeGetAttention> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeGetAttention>(const char* _arg0_);
	ArkFlowNodeGetAttention* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeGetAttention>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15139C0);
};

// CG2AutoRegFlowNode<ArkFlowNodeGetDispositionEntityEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeGetDispositionEntityEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeGetDispositionEntityEntity>(const char* _arg0_);
	ArkFlowNodeGetDispositionEntityEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeGetDispositionEntityEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B8310);
};

// CG2AutoRegFlowNode<ArkFlowNodeGetDispositionEntityFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeGetDispositionEntityFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeGetDispositionEntityFaction>(const char* _arg0_);
	ArkFlowNodeGetDispositionEntityFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeGetDispositionEntityFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B9FF0);
};

// CG2AutoRegFlowNode<ArkFlowNodeGetDispositionFactionEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeGetDispositionFactionEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeGetDispositionFactionEntity>(const char* _arg0_);
	ArkFlowNodeGetDispositionFactionEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeGetDispositionFactionEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BAC00);
};

// CG2AutoRegFlowNode<ArkFlowNodeGetDispositionFactionFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeGetDispositionFactionFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeGetDispositionFactionFaction>(const char* _arg0_);
	ArkFlowNodeGetDispositionFactionFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeGetDispositionFactionFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BB780);
};

// CG2AutoRegFlowNode<ArkFlowNodeGetDoomClockLevel>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeGetDoomClockLevel> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeGetDoomClockLevel>(const char* _arg0_);
	ArkFlowNodeGetDoomClockLevel* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeGetDoomClockLevel>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x131E500);
};

// CG2AutoRegFlowNode<ArkFlowNodeGetFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeGetFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeGetFaction>(const char* _arg0_);
	ArkFlowNodeGetFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeGetFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B7380);
};

// CG2AutoRegFlowNode<ArkFlowNodeGetGameTime>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeGetGameTime> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeGetGameTime>(const char* _arg0_);
	ArkFlowNodeGetGameTime* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeGetGameTime>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x14C5300);
};

// CG2AutoRegFlowNode<ArkFlowNodeGetPlayerCombatState>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeGetPlayerCombatState> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeGetPlayerCombatState>(const char* _arg0_);
	ArkFlowNodeGetPlayerCombatState* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeGetPlayerCombatState>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x131AE20);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsEntityFriendlyToEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsEntityFriendlyToEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsEntityFriendlyToEntity>(const char* _arg0_);
	ArkFlowNodeIsEntityFriendlyToEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsEntityFriendlyToEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BC9F0);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsEntityFriendlyToFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsEntityFriendlyToFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsEntityFriendlyToFaction>(const char* _arg0_);
	ArkFlowNodeIsEntityFriendlyToFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsEntityFriendlyToFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BBF70);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsEntityHostileToEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsEntityHostileToEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsEntityHostileToEntity>(const char* _arg0_);
	ArkFlowNodeIsEntityHostileToEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsEntityHostileToEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BD130);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsEntityHostileToFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsEntityHostileToFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsEntityHostileToFaction>(const char* _arg0_);
	ArkFlowNodeIsEntityHostileToFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsEntityHostileToFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BC650);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsEntityNeutralToEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsEntityNeutralToEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsEntityNeutralToEntity>(const char* _arg0_);
	ArkFlowNodeIsEntityNeutralToEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsEntityNeutralToEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BCD90);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsEntityNeutralToFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsEntityNeutralToFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsEntityNeutralToFaction>(const char* _arg0_);
	ArkFlowNodeIsEntityNeutralToFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsEntityNeutralToFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BC2E0);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsFactionFriendlyToEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsFactionFriendlyToEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsFactionFriendlyToEntity>(const char* _arg0_);
	ArkFlowNodeIsFactionFriendlyToEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsFactionFriendlyToEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BDE20);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsFactionFriendlyToFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsFactionFriendlyToFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsFactionFriendlyToFaction>(const char* _arg0_);
	ArkFlowNodeIsFactionFriendlyToFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsFactionFriendlyToFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BD460);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsFactionHostileToEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsFactionHostileToEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsFactionHostileToEntity>(const char* _arg0_);
	ArkFlowNodeIsFactionHostileToEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsFactionHostileToEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BBC00);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsFactionHostileToFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsFactionHostileToFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsFactionHostileToFaction>(const char* _arg0_);
	ArkFlowNodeIsFactionHostileToFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsFactionHostileToFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BDAC0);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsFactionNeutralToEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsFactionNeutralToEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsFactionNeutralToEntity>(const char* _arg0_);
	ArkFlowNodeIsFactionNeutralToEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsFactionNeutralToEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BB8A0);
};

// CG2AutoRegFlowNode<ArkFlowNodeIsFactionNeutralToFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeIsFactionNeutralToFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeIsFactionNeutralToFaction>(const char* _arg0_);
	ArkFlowNodeIsFactionNeutralToFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeIsFactionNeutralToFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BD790);
};

// CG2AutoRegFlowNode<ArkFlowNodeMakeAiNoise>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeMakeAiNoise> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeMakeAiNoise>(const char* _arg0_);
	ArkFlowNodeMakeAiNoise* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeMakeAiNoise>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1514FA0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNPCCallMimicsTest>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNPCCallMimicsTest> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNPCCallMimicsTest>(const char* _arg0_);
	ArkFlowNodeNPCCallMimicsTest* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNPCCallMimicsTest>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15CA3F0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcAiDumb>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcAiDumb> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcAiDumb>(const char* _arg0_);
	ArkFlowNodeNpcAiDumb* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcAiDumb>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E5080);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcCreatePhantomInstant>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcCreatePhantomInstant> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcCreatePhantomInstant>(const char* _arg0_);
	ArkFlowNodeNpcCreatePhantomInstant* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcCreatePhantomInstant>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11DE8C0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcEnableAI>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcEnableAI> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcEnableAI>(const char* _arg0_);
	ArkFlowNodeNpcEnableAI* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcEnableAI>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E6EE0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcEnableDistraction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcEnableDistraction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcEnableDistraction>(const char* _arg0_);
	ArkFlowNodeNpcEnableDistraction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcEnableDistraction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15168E0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcEnableWander>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcEnableWander> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcEnableWander>(const char* _arg0_);
	ArkFlowNodeNpcEnableWander* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcEnableWander>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1517830);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterEnableWander>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterEnableWander> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterEnableWander>(const char* _arg0_);
	ArkFlowNodeNpcEncounterEnableWander* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterEnableWander>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15177A0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterIgnoreDistract>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterIgnoreDistract> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterIgnoreDistract>(const char* _arg0_);
	ArkFlowNodeNpcEncounterIgnoreDistract* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterIgnoreDistract>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x151A440);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterPatrolRequest>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterPatrolRequest> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterPatrolRequest>(const char* _arg0_);
	ArkFlowNodeNpcEncounterPatrolRequest* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterPatrolRequest>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15EA910);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterSetWanderContainer>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterSetWanderContainer> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterSetWanderContainer>(const char* _arg0_);
	ArkFlowNodeNpcEncounterSetWanderContainer* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcEncounterSetWanderContainer>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x13330E0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcGodMode>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcGodMode> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcGodMode>(const char* _arg0_);
	ArkFlowNodeNpcGodMode* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcGodMode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E6710);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcGodModeAll>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcGodModeAll> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcGodModeAll>(const char* _arg0_);
	ArkFlowNodeNpcGodModeAll* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcGodModeAll>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E67A0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcHasAllTags>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcHasAllTags> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcHasAllTags>(const char* _arg0_);
	ArkFlowNodeNpcHasAllTags* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcHasAllTags>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1518EB0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcHasAnyTags>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcHasAnyTags> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcHasAnyTags>(const char* _arg0_);
	ArkFlowNodeNpcHasAnyTags* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcHasAnyTags>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1519610);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcIgnoreDistract>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcIgnoreDistract> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcIgnoreDistract>(const char* _arg0_);
	ArkFlowNodeNpcIgnoreDistract* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcIgnoreDistract>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x151A4D0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcLockBurrow>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcLockBurrow> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcLockBurrow>(const char* _arg0_);
	ArkFlowNodeNpcLockBurrow* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcLockBurrow>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11DF6D0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcLockMimicry>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcLockMimicry> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcLockMimicry>(const char* _arg0_);
	ArkFlowNodeNpcLockMimicry* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcLockMimicry>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1246750);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcLockStance>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcLockStance> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcLockStance>(const char* _arg0_);
	ArkFlowNodeNpcLockStance* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcLockStance>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x151B8E0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcLockUnburrow>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcLockUnburrow> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcLockUnburrow>(const char* _arg0_);
	ArkFlowNodeNpcLockUnburrow* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcLockUnburrow>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11DFA70);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcLookAtEntityCustom>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcLookAtEntityCustom> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcLookAtEntityCustom>(const char* _arg0_);
	ArkFlowNodeNpcLookAtEntityCustom* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcLookAtEntityCustom>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x151DAB0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcMakeConscious>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcMakeConscious> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcMakeConscious>(const char* _arg0_);
	ArkFlowNodeNpcMakeConscious* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcMakeConscious>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11B7C10);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcNightmareForceMode>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcNightmareForceMode> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcNightmareForceMode>(const char* _arg0_);
	ArkFlowNodeNpcNightmareForceMode* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcNightmareForceMode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x151E820);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcPatrolRequest>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcPatrolRequest> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcPatrolRequest>(const char* _arg0_);
	ArkFlowNodeNpcPatrolRequest* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcPatrolRequest>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15EA9A0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcPatrolRequestClosest>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcPatrolRequestClosest> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcPatrolRequestClosest>(const char* _arg0_);
	ArkFlowNodeNpcPatrolRequestClosest* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcPatrolRequestClosest>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x151EEC0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcPoltergeistThrow>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcPoltergeistThrow> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcPoltergeistThrow>(const char* _arg0_);
	ArkFlowNodeNpcPoltergeistThrow* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcPoltergeistThrow>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1247080);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcSetWanderContainer>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcSetWanderContainer> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcSetWanderContainer>(const char* _arg0_);
	ArkFlowNodeNpcSetWanderContainer* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcSetWanderContainer>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1333050);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcStopLurking>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcStopLurking> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcStopLurking>(const char* _arg0_);
	ArkFlowNodeNpcStopLurking* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcStopLurking>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1248140);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcStopLurkingForEncounter>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcStopLurkingForEncounter> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcStopLurkingForEncounter>(const char* _arg0_);
	ArkFlowNodeNpcStopLurkingForEncounter* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcStopLurkingForEncounter>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1248440);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcStopMimicking>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcStopMimicking> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcStopMimicking>(const char* _arg0_);
	ArkFlowNodeNpcStopMimicking* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcStopMimicking>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1248C90);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcStopMimickingForEncounter>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcStopMimickingForEncounter> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcStopMimickingForEncounter>(const char* _arg0_);
	ArkFlowNodeNpcStopMimickingForEncounter* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcStopMimickingForEncounter>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x12490A0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcTrackView_GetStartPos>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcTrackView_GetStartPos> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcTrackView_GetStartPos>(const char* _arg0_);
	ArkFlowNodeNpcTrackView_GetStartPos* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcTrackView_GetStartPos>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x154B4F0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcTrackView_SetDynamicNode>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcTrackView_SetDynamicNode> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcTrackView_SetDynamicNode>(const char* _arg0_);
	ArkFlowNodeNpcTrackView_SetDynamicNode* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcTrackView_SetDynamicNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x154C0E0);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockBurrow>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockBurrow> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockBurrow>(const char* _arg0_);
	ArkFlowNodeNpcUnlockBurrow* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockBurrow>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11DFE10);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockMimicry>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockMimicry> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockMimicry>(const char* _arg0_);
	ArkFlowNodeNpcUnlockMimicry* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockMimicry>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1249990);
};

// CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockUnburrow>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockUnburrow> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockUnburrow>(const char* _arg0_);
	ArkFlowNodeNpcUnlockUnburrow* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeNpcUnlockUnburrow>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11E02E0);
};

// CG2AutoRegFlowNode<ArkFlowNodePlayerAlien>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodePlayerAlien> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodePlayerAlien>(const char* _arg0_);
	ArkFlowNodePlayerAlien* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodePlayerAlien>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BF670);
};

// CG2AutoRegFlowNode<ArkFlowNodePlayerCombatStateChanged>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodePlayerCombatStateChanged> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodePlayerCombatStateChanged>(const char* _arg0_);
	ArkFlowNodePlayerCombatStateChanged* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodePlayerCombatStateChanged>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x131B490);
};

// CG2AutoRegFlowNode<ArkFlowNodeRelativeTimeEvent>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeRelativeTimeEvent> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeRelativeTimeEvent>(const char* _arg0_);
	ArkFlowNodeRelativeTimeEvent* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeRelativeTimeEvent>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x14C4E90);
};

// CG2AutoRegFlowNode<ArkFlowNodeRemoveLocationAlternateName>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeRemoveLocationAlternateName> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeRemoveLocationAlternateName>(const char* _arg0_);
	ArkFlowNodeRemoveLocationAlternateName* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeRemoveLocationAlternateName>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E2870);
};

// CG2AutoRegFlowNode<ArkFlowNodeResetPDAData>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeResetPDAData> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeResetPDAData>(const char* _arg0_);
	ArkFlowNodeResetPDAData* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeResetPDAData>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15255C0);
};

// CG2AutoRegFlowNode<ArkFlowNodeScanAlienEvent>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeScanAlienEvent> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeScanAlienEvent>(const char* _arg0_);
	ArkFlowNodeScanAlienEvent* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeScanAlienEvent>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C0DA0);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetCharacterAlternateName>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetCharacterAlternateName> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetCharacterAlternateName>(const char* _arg0_);
	ArkFlowNodeSetCharacterAlternateName* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetCharacterAlternateName>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x13142E0);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityEntity>(const char* _arg0_);
	ArkFlowNodeSetDispositionEntityEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B8280);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityFaction>(const char* _arg0_);
	ArkFlowNodeSetDispositionEntityFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B9F60);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityToFactionEntities>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityToFactionEntities> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityToFactionEntities>(const char* _arg0_);
	ArkFlowNodeSetDispositionEntityToFactionEntities* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionEntityToFactionEntities>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B6B10);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToEntity>(const char* _arg0_);
	ArkFlowNodeSetDispositionFactionEntitiesToEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B8BB0);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToFaction>(const char* _arg0_);
	ArkFlowNodeSetDispositionFactionEntitiesToFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B5840);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities>(const char* _arg0_);
	ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B5000);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntity>(const char* _arg0_);
	ArkFlowNodeSetDispositionFactionEntity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BAB70);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionFaction>(const char* _arg0_);
	ArkFlowNodeSetDispositionFactionFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BB6F0);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionToFactionEntities>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionToFactionEntities> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionToFactionEntities>(const char* _arg0_);
	ArkFlowNodeSetDispositionFactionToFactionEntities* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetDispositionFactionToFactionEntities>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B93F0);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetFaction>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetFaction> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetFaction>(const char* _arg0_);
	ArkFlowNodeSetFaction* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetFaction>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15B72F0);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetGameTime>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetGameTime> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetGameTime>(const char* _arg0_);
	ArkFlowNodeSetGameTime* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetGameTime>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x14C5C80);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetLocationAlternateName>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetLocationAlternateName> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetLocationAlternateName>(const char* _arg0_);
	ArkFlowNodeSetLocationAlternateName* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetLocationAlternateName>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E4140);
};

// CG2AutoRegFlowNode<ArkFlowNodeSetPortalOcclusion>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeSetPortalOcclusion> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeSetPortalOcclusion>(const char* _arg0_);
	ArkFlowNodeSetPortalOcclusion* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeSetPortalOcclusion>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1510980);
};

// CG2AutoRegFlowNode<ArkFlowNodeStartLurking>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeStartLurking> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeStartLurking>(const char* _arg0_);
	ArkFlowNodeStartLurking* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeStartLurking>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x124CEF0);
};

// CG2AutoRegFlowNode<ArkFlowNodeStartMimicking>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeStartMimicking> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeStartMimicking>(const char* _arg0_);
	ArkFlowNodeStartMimicking* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeStartMimicking>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1247940);
};

// CG2AutoRegFlowNode<ArkFlowNodeUnhideAbility>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNodeUnhideAbility> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNodeUnhideAbility>(const char* _arg0_);
	ArkFlowNodeUnhideAbility* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNodeUnhideAbility>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15BFC20);
};

// CG2AutoRegFlowNode<ArkFlowNode_EnableEnemyHealthMeter>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_EnableEnemyHealthMeter> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_EnableEnemyHealthMeter>(const char* _arg0_);
	ArkFlowNode_EnableEnemyHealthMeter* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_EnableEnemyHealthMeter>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1522CE0);
};

// CG2AutoRegFlowNode<ArkFlowNode_FabricationPlanAcquired>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_FabricationPlanAcquired> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_FabricationPlanAcquired>(const char* _arg0_);
	ArkFlowNode_FabricationPlanAcquired* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_FabricationPlanAcquired>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1314A10);
};

// CG2AutoRegFlowNode<ArkFlowNode_GetCharacterSpecialObjective>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_GetCharacterSpecialObjective> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_GetCharacterSpecialObjective>(const char* _arg0_);
	ArkFlowNode_GetCharacterSpecialObjective* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_GetCharacterSpecialObjective>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1523870);
};

// CG2AutoRegFlowNode<ArkFlowNode_GetPlayableCharacter>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_GetPlayableCharacter> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_GetPlayableCharacter>(const char* _arg0_);
	ArkFlowNode_GetPlayableCharacter* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_GetPlayableCharacter>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1523750);
};

// CG2AutoRegFlowNode<ArkFlowNode_ItemFabricated>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_ItemFabricated> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_ItemFabricated>(const char* _arg0_);
	ArkFlowNode_ItemFabricated* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_ItemFabricated>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1314B00);
};

// CG2AutoRegFlowNode<ArkFlowNode_ItemRecycled>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_ItemRecycled> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_ItemRecycled>(const char* _arg0_);
	ArkFlowNode_ItemRecycled* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_ItemRecycled>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1523950);
};

// CG2AutoRegFlowNode<ArkFlowNode_KillLatentPowers>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_KillLatentPowers> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_KillLatentPowers>(const char* _arg0_);
	ArkFlowNode_KillLatentPowers* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_KillLatentPowers>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15228E0);
};

// CG2AutoRegFlowNode<ArkFlowNode_LearnNameForResearchTopic>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_LearnNameForResearchTopic> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_LearnNameForResearchTopic>(const char* _arg0_);
	ArkFlowNode_LearnNameForResearchTopic* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_LearnNameForResearchTopic>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1522C50);
};

// CG2AutoRegFlowNode<ArkFlowNode_PlayerCorpseCreated>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_PlayerCorpseCreated> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_PlayerCorpseCreated>(const char* _arg0_);
	ArkFlowNode_PlayerCorpseCreated* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_PlayerCorpseCreated>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1523900);
};

// CG2AutoRegFlowNode<ArkFlowNode_PostEffect>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_PostEffect> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_PostEffect>(const char* _arg0_);
	ArkFlowNode_PostEffect* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_PostEffect>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1527980);
};

// CG2AutoRegFlowNode<ArkFlowNode_PostEffectParameter>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_PostEffectParameter> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_PostEffectParameter>(const char* _arg0_);
	ArkFlowNode_PostEffectParameter* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_PostEffectParameter>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1527A10);
};

// CG2AutoRegFlowNode<ArkFlowNode_RestrictPlayerItems>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_RestrictPlayerItems> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_RestrictPlayerItems>(const char* _arg0_);
	ArkFlowNode_RestrictPlayerItems* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_RestrictPlayerItems>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1522850);
};

// CG2AutoRegFlowNode<ArkFlowNode_SetFabricationPlanError>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_SetFabricationPlanError> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_SetFabricationPlanError>(const char* _arg0_);
	ArkFlowNode_SetFabricationPlanError* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_SetFabricationPlanError>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1314A60);
};

// CG2AutoRegFlowNode<ArkFlowNode_SetPlayableCharacter>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_SetPlayableCharacter> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_SetPlayableCharacter>(const char* _arg0_);
	ArkFlowNode_SetPlayableCharacter* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_SetPlayableCharacter>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1522D70);
};

// CG2AutoRegFlowNode<ArkFlowNode_SetStationAccess>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_SetStationAccess> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_SetStationAccess>(const char* _arg0_);
	ArkFlowNode_SetStationAccess* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_SetStationAccess>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1525EB0);
};

// CG2AutoRegFlowNode<ArkFlowNode_SilenceTranscribe>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_SilenceTranscribe> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_SilenceTranscribe>(const char* _arg0_);
	ArkFlowNode_SilenceTranscribe* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_SilenceTranscribe>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x124E220);
};

// CG2AutoRegFlowNode<ArkFlowNode_TestDifficultyOption>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_TestDifficultyOption> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_TestDifficultyOption>(const char* _arg0_);
	ArkFlowNode_TestDifficultyOption* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_TestDifficultyOption>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x12400F0);
};

// CG2AutoRegFlowNode<ArkFlowNode_UpdatePlayableCharacterStatus>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowNode_UpdatePlayableCharacterStatus> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowNode_UpdatePlayableCharacterStatus>(const char* _arg0_);
	ArkFlowNode_UpdatePlayableCharacterStatus* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowNode_UpdatePlayableCharacterStatus>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15237E0);
};

// CG2AutoRegFlowNode<ArkFlowPlayerMannequinTag>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowPlayerMannequinTag> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowPlayerMannequinTag>(const char* _arg0_);
	ArkFlowPlayerMannequinTag* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowPlayerMannequinTag>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x124E710);
};

// CG2AutoRegFlowNode<ArkFlowReadyRoom>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowReadyRoom> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowReadyRoom>(const char* _arg0_);
	ArkFlowReadyRoom* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowReadyRoom>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x14688A0);
};

// CG2AutoRegFlowNode<ArkFlowReadyRoomListener>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowReadyRoomListener> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowReadyRoomListener>(const char* _arg0_);
	ArkFlowReadyRoomListener* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowReadyRoomListener>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1468930);
};

// CG2AutoRegFlowNode<ArkFlowReadyRoomRequest>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowReadyRoomRequest> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowReadyRoomRequest>(const char* _arg0_);
	ArkFlowReadyRoomRequest* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowReadyRoomRequest>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1468980);
};

// CG2AutoRegFlowNode<ArkFlowResetGameToken>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowResetGameToken> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowResetGameToken>(const char* _arg0_);
	ArkFlowResetGameToken* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowResetGameToken>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x124F480);
};

// CG2AutoRegFlowNode<ArkFlowSendSignalPackage>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowSendSignalPackage> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowSendSignalPackage>(const char* _arg0_);
	ArkFlowSendSignalPackage* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowSendSignalPackage>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15F83B0);
};

// CG2AutoRegFlowNode<ArkFlowSendSignalPackageInArea>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowSendSignalPackageInArea> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowSendSignalPackageInArea>(const char* _arg0_);
	ArkFlowSendSignalPackageInArea* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowSendSignalPackageInArea>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15F8440);
};

// CG2AutoRegFlowNode<ArkFlowSendSignalPackageToNpcsInVolume>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<ArkFlowSendSignalPackageToNpcsInVolume> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<ArkFlowSendSignalPackageToNpcsInVolume>(const char* _arg0_);
	ArkFlowSendSignalPackageToNpcsInVolume* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<ArkFlowSendSignalPackageToNpcsInVolume>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15F84D0);
};

// CG2AutoRegFlowNode<CAchievementNode>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CAchievementNode> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CAchievementNode>(const char* _arg0_);
	CAchievementNode* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CAchievementNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x189C400);
};

// CG2AutoRegFlowNode<CArkFlowNodeAddEncounter>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeAddEncounter> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeAddEncounter>(const char* _arg0_);
	CArkFlowNodeAddEncounter* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeAddEncounter>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1321310);
};

// CG2AutoRegFlowNode<CArkFlowNodeAddEncounterProfile>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeAddEncounterProfile> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeAddEncounterProfile>(const char* _arg0_);
	CArkFlowNodeAddEncounterProfile* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeAddEncounterProfile>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1321430);
};

// CG2AutoRegFlowNode<CArkFlowNodeAddEncounterSpawnInfo>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeAddEncounterSpawnInfo> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeAddEncounterSpawnInfo>(const char* _arg0_);
	CArkFlowNodeAddEncounterSpawnInfo* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeAddEncounterSpawnInfo>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x13213A0);
};

// CG2AutoRegFlowNode<CArkFlowNodeAddToEncounter>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeAddToEncounter> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeAddToEncounter>(const char* _arg0_);
	CArkFlowNodeAddToEncounter* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeAddToEncounter>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x13214C0);
};

// CG2AutoRegFlowNode<CArkFlowNodeChangeHelmet>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeChangeHelmet> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeChangeHelmet>(const char* _arg0_);
	CArkFlowNodeChangeHelmet* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeChangeHelmet>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1319560);
};

// CG2AutoRegFlowNode<CArkFlowNodeCharacterLocatedEvent>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeCharacterLocatedEvent> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeCharacterLocatedEvent>(const char* _arg0_);
	CArkFlowNodeCharacterLocatedEvent* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeCharacterLocatedEvent>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C43D0);
};

// CG2AutoRegFlowNode<CArkFlowNodeCheckDownloadHidden>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeCheckDownloadHidden> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeCheckDownloadHidden>(const char* _arg0_);
	CArkFlowNodeCheckDownloadHidden* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeCheckDownloadHidden>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D3D70);
};

// CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityButtonEnabled>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityButtonEnabled> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityButtonEnabled>(const char* _arg0_);
	CArkFlowNodeCheckUtilityButtonEnabled* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityButtonEnabled>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D41F0);
};

// CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityButtonHidden>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityButtonHidden> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityButtonHidden>(const char* _arg0_);
	CArkFlowNodeCheckUtilityButtonHidden* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityButtonHidden>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D4310);
};

// CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityEnabled>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityEnabled> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityEnabled>(const char* _arg0_);
	CArkFlowNodeCheckUtilityEnabled* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityEnabled>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D3F20);
};

// CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityHidden>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityHidden> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityHidden>(const char* _arg0_);
	CArkFlowNodeCheckUtilityHidden* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeCheckUtilityHidden>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D4040);
};

// CG2AutoRegFlowNode<CArkFlowNodeCompareUtility>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeCompareUtility> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeCompareUtility>(const char* _arg0_);
	CArkFlowNodeCompareUtility* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeCompareUtility>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D3E00);
};

// CG2AutoRegFlowNode<CArkFlowNodeCompareUtilityButton>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeCompareUtilityButton> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeCompareUtilityButton>(const char* _arg0_);
	CArkFlowNodeCompareUtilityButton* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeCompareUtilityButton>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D40D0);
};

// CG2AutoRegFlowNode<CArkFlowNodeConversationStatus>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeConversationStatus> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeConversationStatus>(const char* _arg0_);
	CArkFlowNodeConversationStatus* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeConversationStatus>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C8990);
};

// CG2AutoRegFlowNode<CArkFlowNodeDiscoverLocation>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeDiscoverLocation> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeDiscoverLocation>(const char* _arg0_);
	CArkFlowNodeDiscoverLocation* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeDiscoverLocation>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E4020);
};

// CG2AutoRegFlowNode<CArkFlowNodeDownloadAcquired>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeDownloadAcquired> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeDownloadAcquired>(const char* _arg0_);
	CArkFlowNodeDownloadAcquired* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeDownloadAcquired>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D43A0);
};

// CG2AutoRegFlowNode<CArkFlowNodeEliminateCurrentPopulation>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeEliminateCurrentPopulation> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeEliminateCurrentPopulation>(const char* _arg0_);
	CArkFlowNodeEliminateCurrentPopulation* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeEliminateCurrentPopulation>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1321550);
};

// CG2AutoRegFlowNode<CArkFlowNodeEmailAcquired>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeEmailAcquired> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeEmailAcquired>(const char* _arg0_);
	CArkFlowNodeEmailAcquired* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeEmailAcquired>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D3C90);
};

// CG2AutoRegFlowNode<CArkFlowNodeEnableScope>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeEnableScope> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeEnableScope>(const char* _arg0_);
	CArkFlowNodeEnableScope* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeEnableScope>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15EF3B0);
};

// CG2AutoRegFlowNode<CArkFlowNodeEntityLink>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeEntityLink> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeEntityLink>(const char* _arg0_);
	CArkFlowNodeEntityLink* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeEntityLink>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1314980);
};

// CG2AutoRegFlowNode<CArkFlowNodeFocusModeEnabled>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeFocusModeEnabled> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeFocusModeEnabled>(const char* _arg0_);
	CArkFlowNodeFocusModeEnabled* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeFocusModeEnabled>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1241F10);
};

// CG2AutoRegFlowNode<CArkFlowNodeGetEquippedItem>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeGetEquippedItem> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeGetEquippedItem>(const char* _arg0_);
	CArkFlowNodeGetEquippedItem* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeGetEquippedItem>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15CAEE0);
};

// CG2AutoRegFlowNode<CArkFlowNodeGetTaskState>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeGetTaskState> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeGetTaskState>(const char* _arg0_);
	CArkFlowNodeGetTaskState* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeGetTaskState>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15DA300);
};

// CG2AutoRegFlowNode<CArkFlowNodeGiveAbility>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeGiveAbility> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeGiveAbility>(const char* _arg0_);
	CArkFlowNodeGiveAbility* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeGiveAbility>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C0B80);
};

// CG2AutoRegFlowNode<CArkFlowNodeGiveNote>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeGiveNote> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeGiveNote>(const char* _arg0_);
	CArkFlowNodeGiveNote* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeGiveNote>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E5110);
};

// CG2AutoRegFlowNode<CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate> >(const char* _arg0_);
	CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15DAAD0);
};

// CG2AutoRegFlowNode<CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate> >(const char* _arg0_);
	CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15DA390);
};

// CG2AutoRegFlowNode<CArkFlowNodeHasAbility>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeHasAbility> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeHasAbility>(const char* _arg0_);
	CArkFlowNodeHasAbility* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeHasAbility>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C0C10);
};

// CG2AutoRegFlowNode<CArkFlowNodeHasDiscoveredLocation>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeHasDiscoveredLocation> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeHasDiscoveredLocation>(const char* _arg0_);
	CArkFlowNodeHasDiscoveredLocation* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeHasDiscoveredLocation>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E40B0);
};

// CG2AutoRegFlowNode<CArkFlowNodeHasNote>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeHasNote> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeHasNote>(const char* _arg0_);
	CArkFlowNodeHasNote* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeHasNote>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E51A0);
};

// CG2AutoRegFlowNode<CArkFlowNodeHelmet>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeHelmet> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeHelmet>(const char* _arg0_);
	CArkFlowNodeHelmet* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeHelmet>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1318DE0);
};

// CG2AutoRegFlowNode<CArkFlowNodeHideEmail>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeHideEmail> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeHideEmail>(const char* _arg0_);
	CArkFlowNodeHideEmail* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeHideEmail>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D3750);
};

// CG2AutoRegFlowNode<CArkFlowNodeIncrementGameMetric>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeIncrementGameMetric> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeIncrementGameMetric>(const char* _arg0_);
	CArkFlowNodeIncrementGameMetric* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeIncrementGameMetric>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1317D90);
};

// CG2AutoRegFlowNode<CArkFlowNodeKeyCardAcquired>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeKeyCardAcquired> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeKeyCardAcquired>(const char* _arg0_);
	CArkFlowNodeKeyCardAcquired* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeKeyCardAcquired>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E1580);
};

// CG2AutoRegFlowNode<CArkFlowNodeKeyCodeAcquired>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeKeyCodeAcquired> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeKeyCodeAcquired>(const char* _arg0_);
	CArkFlowNodeKeyCodeAcquired* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeKeyCodeAcquired>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15ED8D0);
};

// CG2AutoRegFlowNode<CArkFlowNodeLearnResearch>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeLearnResearch> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeLearnResearch>(const char* _arg0_);
	CArkFlowNodeLearnResearch* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeLearnResearch>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C0980);
};

// CG2AutoRegFlowNode<CArkFlowNodeLocateCharacterObjectiveEvent>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeLocateCharacterObjectiveEvent> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeLocateCharacterObjectiveEvent>(const char* _arg0_);
	CArkFlowNodeLocateCharacterObjectiveEvent* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeLocateCharacterObjectiveEvent>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15CCCC0);
};

// CG2AutoRegFlowNode<CArkFlowNodeNpcDeactivateCombatIntensity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeNpcDeactivateCombatIntensity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeNpcDeactivateCombatIntensity>(const char* _arg0_);
	CArkFlowNodeNpcDeactivateCombatIntensity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeNpcDeactivateCombatIntensity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1515470);
};

// CG2AutoRegFlowNode<CArkFlowNodeNpcDestroy>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeNpcDestroy> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeNpcDestroy>(const char* _arg0_);
	CArkFlowNodeNpcDestroy* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeNpcDestroy>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1515CA0);
};

// CG2AutoRegFlowNode<CArkFlowNodeNpcKill>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeNpcKill> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeNpcKill>(const char* _arg0_);
	CArkFlowNodeNpcKill* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeNpcKill>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x151B0D0);
};

// CG2AutoRegFlowNode<CArkFlowNodeNpcKillByTag>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeNpcKillByTag> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeNpcKillByTag>(const char* _arg0_);
	CArkFlowNodeNpcKillByTag* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeNpcKillByTag>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x12466C0);
};

// CG2AutoRegFlowNode<CArkFlowNodePlayerCinematic>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodePlayerCinematic> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodePlayerCinematic>(const char* _arg0_);
	CArkFlowNodePlayerCinematic* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodePlayerCinematic>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x124A860);
};

// CG2AutoRegFlowNode<CArkFlowNodePlayerMimicState>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodePlayerMimicState> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodePlayerMimicState>(const char* _arg0_);
	CArkFlowNodePlayerMimicState* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodePlayerMimicState>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15EF290);
};

// CG2AutoRegFlowNode<CArkFlowNodePsiPowerActive>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodePsiPowerActive> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodePsiPowerActive>(const char* _arg0_);
	CArkFlowNodePsiPowerActive* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodePsiPowerActive>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C0CB0);
};

// CG2AutoRegFlowNode<CArkFlowNodePsiPowerMenuActive>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodePsiPowerMenuActive> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodePsiPowerMenuActive>(const char* _arg0_);
	CArkFlowNodePsiPowerMenuActive* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodePsiPowerMenuActive>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C0D00);
};

// CG2AutoRegFlowNode<CArkFlowNodePsiPowerTargetingActive>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodePsiPowerTargetingActive> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodePsiPowerTargetingActive>(const char* _arg0_);
	CArkFlowNodePsiPowerTargetingActive* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodePsiPowerTargetingActive>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C0C60);
};

// CG2AutoRegFlowNode<CArkFlowNodePsiScanning>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodePsiScanning> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodePsiScanning>(const char* _arg0_);
	CArkFlowNodePsiScanning* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodePsiScanning>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15EF320);
};

// CG2AutoRegFlowNode<CArkFlowNodePurchaseRandomAbilities>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodePurchaseRandomAbilities> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodePurchaseRandomAbilities>(const char* _arg0_);
	CArkFlowNodePurchaseRandomAbilities* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodePurchaseRandomAbilities>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C0060);
};

// CG2AutoRegFlowNode<CArkFlowNodeRefreshCurrentPopulation>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeRefreshCurrentPopulation> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeRefreshCurrentPopulation>(const char* _arg0_);
	CArkFlowNodeRefreshCurrentPopulation* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeRefreshCurrentPopulation>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x13215E0);
};

// CG2AutoRegFlowNode<CArkFlowNodeRemoteEvent>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeRemoteEvent> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeRemoteEvent>(const char* _arg0_);
	CArkFlowNodeRemoteEvent* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeRemoteEvent>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15F4D60);
};

// CG2AutoRegFlowNode<CArkFlowNodeRenderAlways>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeRenderAlways> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeRenderAlways>(const char* _arg0_);
	CArkFlowNodeRenderAlways* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeRenderAlways>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x124CE60);
};

// CG2AutoRegFlowNode<CArkFlowNodeSendEmail>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSendEmail> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSendEmail>(const char* _arg0_);
	CArkFlowNodeSendEmail* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSendEmail>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D35E0);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetDownloadHidden>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetDownloadHidden> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetDownloadHidden>(const char* _arg0_);
	CArkFlowNodeSetDownloadHidden* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetDownloadHidden>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D3CE0);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetEncounterProfile>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetEncounterProfile> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetEncounterProfile>(const char* _arg0_);
	CArkFlowNodeSetEncounterProfile* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetEncounterProfile>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1321670);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetEquippedItem>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetEquippedItem> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetEquippedItem>(const char* _arg0_);
	CArkFlowNodeSetEquippedItem* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetEquippedItem>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15CAF70);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetObjectiveDescription>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetObjectiveDescription> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetObjectiveDescription>(const char* _arg0_);
	CArkFlowNodeSetObjectiveDescription* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetObjectiveDescription>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15F2150);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetSpawnerActiveForEncounters>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetSpawnerActiveForEncounters> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetSpawnerActiveForEncounters>(const char* _arg0_);
	CArkFlowNodeSetSpawnerActiveForEncounters* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetSpawnerActiveForEncounters>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1321700);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetTaskLocation>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetTaskLocation> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetTaskLocation>(const char* _arg0_);
	CArkFlowNodeSetTaskLocation* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetTaskLocation>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15F38D0);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetTaskMarker>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetTaskMarker> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetTaskMarker>(const char* _arg0_);
	CArkFlowNodeSetTaskMarker* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetTaskMarker>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15F3840);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetTaskMarkerOverride>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetTaskMarkerOverride> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetTaskMarkerOverride>(const char* _arg0_);
	CArkFlowNodeSetTaskMarkerOverride* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetTaskMarkerOverride>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15F3960);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetUtilityButtonEnabled>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetUtilityButtonEnabled> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetUtilityButtonEnabled>(const char* _arg0_);
	CArkFlowNodeSetUtilityButtonEnabled* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetUtilityButtonEnabled>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D4160);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetUtilityButtonHidden>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetUtilityButtonHidden> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetUtilityButtonHidden>(const char* _arg0_);
	CArkFlowNodeSetUtilityButtonHidden* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetUtilityButtonHidden>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D4280);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetUtilityEnabled>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetUtilityEnabled> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetUtilityEnabled>(const char* _arg0_);
	CArkFlowNodeSetUtilityEnabled* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetUtilityEnabled>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D3E90);
};

// CG2AutoRegFlowNode<CArkFlowNodeSetUtilityHidden>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSetUtilityHidden> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSetUtilityHidden>(const char* _arg0_);
	CArkFlowNodeSetUtilityHidden* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSetUtilityHidden>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D3FB0);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15CCD10);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15CD1A0);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C45B0);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C4E20);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C4CC0);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C4910);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15CCF40);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C4420);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C4FF0);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C4770);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C4D70);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15C4B00);
};

// CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue> >(const char* _arg0_);
	CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15CCDC0);
};

// CG2AutoRegFlowNode<CArkFlowNodeSpawnAtTravelDest>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeSpawnAtTravelDest> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeSpawnAtTravelDest>(const char* _arg0_);
	CArkFlowNodeSpawnAtTravelDest* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeSpawnAtTravelDest>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15F3F80);
};

// CG2AutoRegFlowNode<CArkFlowNodeUnequipItem>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNodeUnequipItem> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNodeUnequipItem>(const char* _arg0_);
	CArkFlowNodeUnequipItem* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNodeUnequipItem>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15CB000);
};

// CG2AutoRegFlowNode<CArkFlowNode_CheckArchetype>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_CheckArchetype> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_CheckArchetype>(const char* _arg0_);
	CArkFlowNode_CheckArchetype* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_CheckArchetype>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x150F5E0);
};

// CG2AutoRegFlowNode<CArkFlowNode_ClearLevelMapFog>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_ClearLevelMapFog> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_ClearLevelMapFog>(const char* _arg0_);
	CArkFlowNode_ClearLevelMapFog* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_ClearLevelMapFog>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1525FD0);
};

// CG2AutoRegFlowNode<CArkFlowNode_ClosePDA>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_ClosePDA> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_ClosePDA>(const char* _arg0_);
	CArkFlowNode_ClosePDA* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_ClosePDA>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15258C0);
};

// CG2AutoRegFlowNode<CArkFlowNode_CollectAudioLog>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_CollectAudioLog> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_CollectAudioLog>(const char* _arg0_);
	CArkFlowNode_CollectAudioLog* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_CollectAudioLog>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1312D90);
};

// CG2AutoRegFlowNode<CArkFlowNode_CollectTutorialCard>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_CollectTutorialCard> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_CollectTutorialCard>(const char* _arg0_);
	CArkFlowNode_CollectTutorialCard* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_CollectTutorialCard>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x152A7C0);
};

// CG2AutoRegFlowNode<CArkFlowNode_CompleteChecklistEntry>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_CompleteChecklistEntry> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_CompleteChecklistEntry>(const char* _arg0_);
	CArkFlowNode_CompleteChecklistEntry* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_CompleteChecklistEntry>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11E15F0);
};

// CG2AutoRegFlowNode<CArkFlowNode_CystoidManager>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_CystoidManager> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_CystoidManager>(const char* _arg0_);
	CArkFlowNode_CystoidManager* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_CystoidManager>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x123FD00);
};

// CG2AutoRegFlowNode<CArkFlowNode_EnableChecklistEntry>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_EnableChecklistEntry> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_EnableChecklistEntry>(const char* _arg0_);
	CArkFlowNode_EnableChecklistEntry* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_EnableChecklistEntry>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11E1560);
};

// CG2AutoRegFlowNode<CArkFlowNode_EnableGameStateCondition>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_EnableGameStateCondition> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_EnableGameStateCondition>(const char* _arg0_);
	CArkFlowNode_EnableGameStateCondition* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_EnableGameStateCondition>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x152A8E0);
};

// CG2AutoRegFlowNode<CArkFlowNode_EnableHUDArmor>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_EnableHUDArmor> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_EnableHUDArmor>(const char* _arg0_);
	CArkFlowNode_EnableHUDArmor* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_EnableHUDArmor>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1513AE0);
};

// CG2AutoRegFlowNode<CArkFlowNode_EnableHUDHealth>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_EnableHUDHealth> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_EnableHUDHealth>(const char* _arg0_);
	CArkFlowNode_EnableHUDHealth* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_EnableHUDHealth>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1513A50);
};

// CG2AutoRegFlowNode<CArkFlowNode_EnablePDADateAndTime>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_EnablePDADateAndTime> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_EnablePDADateAndTime>(const char* _arg0_);
	CArkFlowNode_EnablePDADateAndTime* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_EnablePDADateAndTime>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1526060);
};

// CG2AutoRegFlowNode<CArkFlowNode_EnablePDAPage>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_EnablePDAPage> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_EnablePDAPage>(const char* _arg0_);
	CArkFlowNode_EnablePDAPage* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_EnablePDAPage>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15260F0);
};

// CG2AutoRegFlowNode<CArkFlowNode_EndGame>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_EndGame> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_EndGame>(const char* _arg0_);
	CArkFlowNode_EndGame* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_EndGame>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1242390);
};

// CG2AutoRegFlowNode<CArkFlowNode_EntityControl>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_EntityControl> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_EntityControl>(const char* _arg0_);
	CArkFlowNode_EntityControl* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_EntityControl>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D8050);
};

// CG2AutoRegFlowNode<CArkFlowNode_EntityRender>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_EntityRender> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_EntityRender>(const char* _arg0_);
	CArkFlowNode_EntityRender* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_EntityRender>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D80E0);
};

// CG2AutoRegFlowNode<CArkFlowNode_ExamineWorldUI>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_ExamineWorldUI> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_ExamineWorldUI>(const char* _arg0_);
	CArkFlowNode_ExamineWorldUI* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_ExamineWorldUI>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x152EE20);
};

// CG2AutoRegFlowNode<CArkFlowNode_ForceStopCameraShakes>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_ForceStopCameraShakes> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_ForceStopCameraShakes>(const char* _arg0_);
	CArkFlowNode_ForceStopCameraShakes* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_ForceStopCameraShakes>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x123E0F0);
};

// CG2AutoRegFlowNode<CArkFlowNode_GameDisconnect>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_GameDisconnect> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_GameDisconnect>(const char* _arg0_);
	CArkFlowNode_GameDisconnect* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_GameDisconnect>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1242A90);
};

// CG2AutoRegFlowNode<CArkFlowNode_HasEntitlement>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_HasEntitlement> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_HasEntitlement>(const char* _arg0_);
	CArkFlowNode_HasEntitlement* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_HasEntitlement>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x12414A0);
};

// CG2AutoRegFlowNode<CArkFlowNode_HideFailedAbilityInteractions>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_HideFailedAbilityInteractions> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_HideFailedAbilityInteractions>(const char* _arg0_);
	CArkFlowNode_HideFailedAbilityInteractions* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_HideFailedAbilityInteractions>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15227C0);
};

// CG2AutoRegFlowNode<CArkFlowNode_InterferenceGameEffect>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_InterferenceGameEffect> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_InterferenceGameEffect>(const char* _arg0_);
	CArkFlowNode_InterferenceGameEffect* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_InterferenceGameEffect>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x12406D0);
};

// CG2AutoRegFlowNode<CArkFlowNode_IsArchetypeInWorld>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_IsArchetypeInWorld> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_IsArchetypeInWorld>(const char* _arg0_);
	CArkFlowNode_IsArchetypeInWorld* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_IsArchetypeInWorld>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1514210);
};

// CG2AutoRegFlowNode<CArkFlowNode_IsInChallengeMode>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_IsInChallengeMode> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_IsInChallengeMode>(const char* _arg0_);
	CArkFlowNode_IsInChallengeMode* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_IsInChallengeMode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11DE240);
};

// CG2AutoRegFlowNode<CArkFlowNode_KioskElevatorError>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_KioskElevatorError> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_KioskElevatorError>(const char* _arg0_);
	CArkFlowNode_KioskElevatorError* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_KioskElevatorError>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x152EEB0);
};

// CG2AutoRegFlowNode<CArkFlowNode_MimicMorphEffect>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_MimicMorphEffect> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_MimicMorphEffect>(const char* _arg0_);
	CArkFlowNode_MimicMorphEffect* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_MimicMorphEffect>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15E4310);
};

// CG2AutoRegFlowNode<CArkFlowNode_OnPlayerSpawned>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_OnPlayerSpawned> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_OnPlayerSpawned>(const char* _arg0_);
	CArkFlowNode_OnPlayerSpawned* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_OnPlayerSpawned>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1522310);
};

// CG2AutoRegFlowNode<CArkFlowNode_OpenPDAPage>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_OpenPDAPage> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_OpenPDAPage>(const char* _arg0_);
	CArkFlowNode_OpenPDAPage* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_OpenPDAPage>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1526180);
};

// CG2AutoRegFlowNode<CArkFlowNode_PopulateBonusContainer>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_PopulateBonusContainer> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_PopulateBonusContainer>(const char* _arg0_);
	CArkFlowNode_PopulateBonusContainer* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_PopulateBonusContainer>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1241410);
};

// CG2AutoRegFlowNode<CArkFlowNode_PopulateEndGameUI>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_PopulateEndGameUI> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_PopulateEndGameUI>(const char* _arg0_);
	CArkFlowNode_PopulateEndGameUI* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_PopulateEndGameUI>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1242860);
};

// CG2AutoRegFlowNode<CArkFlowNode_QueueTutorials>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_QueueTutorials> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_QueueTutorials>(const char* _arg0_);
	CArkFlowNode_QueueTutorials* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_QueueTutorials>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x152A850);
};

// CG2AutoRegFlowNode<CArkFlowNode_SetConsumingOxygen>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_SetConsumingOxygen> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_SetConsumingOxygen>(const char* _arg0_);
	CArkFlowNode_SetConsumingOxygen* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_SetConsumingOxygen>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1525190);
};

// CG2AutoRegFlowNode<CArkFlowNode_SetPDAAccess>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_SetPDAAccess> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_SetPDAAccess>(const char* _arg0_);
	CArkFlowNode_SetPDAAccess* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_SetPDAAccess>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1525F40);
};

// CG2AutoRegFlowNode<CArkFlowNode_SetPlayerStance>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_SetPlayerStance> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_SetPlayerStance>(const char* _arg0_);
	CArkFlowNode_SetPlayerStance* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_SetPlayerStance>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1522280);
};

// CG2AutoRegFlowNode<CArkFlowNode_SkipNextDeathDelay>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_SkipNextDeathDelay> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_SkipNextDeathDelay>(const char* _arg0_);
	CArkFlowNode_SkipNextDeathDelay* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_SkipNextDeathDelay>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15221F0);
};

// CG2AutoRegFlowNode<CArkFlowNode_TestChecklistEntry>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_TestChecklistEntry> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_TestChecklistEntry>(const char* _arg0_);
	CArkFlowNode_TestChecklistEntry* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_TestChecklistEntry>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11E1680);
};

// CG2AutoRegFlowNode<CArkFlowNode_TestFlashlight>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_TestFlashlight> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_TestFlashlight>(const char* _arg0_);
	CArkFlowNode_TestFlashlight* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_TestFlashlight>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1521D50);
};

// CG2AutoRegFlowNode<CArkFlowNode_TriggerCameraShake>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_TriggerCameraShake> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_TriggerCameraShake>(const char* _arg0_);
	CArkFlowNode_TriggerCameraShake* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_TriggerCameraShake>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x123E060);
};

// CG2AutoRegFlowNode<CArkFlowNode_UnlockTips>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_UnlockTips> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_UnlockTips>(const char* _arg0_);
	CArkFlowNode_UnlockTips* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_UnlockTips>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x124D900);
};

// CG2AutoRegFlowNode<CArkFlowNode_UsePlayerTimer>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_UsePlayerTimer> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_UsePlayerTimer>(const char* _arg0_);
	CArkFlowNode_UsePlayerTimer* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_UsePlayerTimer>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D7FC0);
};

// CG2AutoRegFlowNode<CArkFlowNode_WhiplashPopup>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CArkFlowNode_WhiplashPopup> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CArkFlowNode_WhiplashPopup>(const char* _arg0_);
	CArkFlowNode_WhiplashPopup* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CArkFlowNode_WhiplashPopup>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15D44B0);
};

// CG2AutoRegFlowNode<CFlowControlPlayerHealthEffect>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowControlPlayerHealthEffect> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowControlPlayerHealthEffect>(const char* _arg0_);
	CFlowControlPlayerHealthEffect* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowControlPlayerHealthEffect>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A9BE0);
};

// CG2AutoRegFlowNode<CFlowFXNode<FXParamsBloodSplats> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowFXNode<FXParamsBloodSplats> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowFXNode<FXParamsBloodSplats> >(const char* _arg0_);
	CFlowFXNode<FXParamsBloodSplats>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowFXNode<FXParamsBloodSplats> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A9610);
};

// CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlittering> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlittering> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlittering> >(const char* _arg0_);
	CFlowFXNode<FXParamsGlittering>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlittering> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A99F0);
};

// CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlobal> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlobal> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlobal> >(const char* _arg0_);
	CFlowFXNode<FXParamsGlobal>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlobal> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A9040);
};

// CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlow> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlow> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlow> >(const char* _arg0_);
	CFlowFXNode<FXParamsGlow>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowFXNode<FXParamsGlow> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A9800);
};

// CG2AutoRegFlowNode<CFlowFXNode<FXParamsScreenFrost> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowFXNode<FXParamsScreenFrost> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowFXNode<FXParamsScreenFrost> >(const char* _arg0_);
	CFlowFXNode<FXParamsScreenFrost>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowFXNode<FXParamsScreenFrost> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A9230);
};

// CG2AutoRegFlowNode<CFlowFXNode<FXParamsWaterDroplets> >
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowFXNode<FXParamsWaterDroplets> > : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowFXNode<FXParamsWaterDroplets> >(const char* _arg0_);
	CFlowFXNode<FXParamsWaterDroplets>* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowFXNode<FXParamsWaterDroplets> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A9420);
};

// CG2AutoRegFlowNode<CFlowNode_AddEquipmentPack>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_AddEquipmentPack> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_AddEquipmentPack>(const char* _arg0_);
	CFlowNode_AddEquipmentPack* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_AddEquipmentPack>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15DDF80);
};

// CG2AutoRegFlowNode<CFlowNode_AddLoot>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_AddLoot> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_AddLoot>(const char* _arg0_);
	CFlowNode_AddLoot* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_AddLoot>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15DE010);
};

// CG2AutoRegFlowNode<CFlowNode_ArkPlayerWeaponSensor>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_ArkPlayerWeaponSensor> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_ArkPlayerWeaponSensor>(const char* _arg0_);
	CFlowNode_ArkPlayerWeaponSensor* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_ArkPlayerWeaponSensor>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15FAEB0);
};

// CG2AutoRegFlowNode<CFlowNode_GetNearestActor>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_GetNearestActor> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_GetNearestActor>(const char* _arg0_);
	CFlowNode_GetNearestActor* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_GetNearestActor>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x189D6F0);
};

// CG2AutoRegFlowNode<CFlowNode_InventoryAddItem>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_InventoryAddItem> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_InventoryAddItem>(const char* _arg0_);
	CFlowNode_InventoryAddItem* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_InventoryAddItem>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15DD500);
};

// CG2AutoRegFlowNode<CFlowNode_InventoryAddItemById>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_InventoryAddItemById> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_InventoryAddItemById>(const char* _arg0_);
	CFlowNode_InventoryAddItemById* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_InventoryAddItemById>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15DD5B0);
};

// CG2AutoRegFlowNode<CFlowNode_InventoryGetItemQuantity>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_InventoryGetItemQuantity> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_InventoryGetItemQuantity>(const char* _arg0_);
	CFlowNode_InventoryGetItemQuantity* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_InventoryGetItemQuantity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15DD800);
};

// CG2AutoRegFlowNode<CFlowNode_InventoryRemoveAllItems>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_InventoryRemoveAllItems> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_InventoryRemoveAllItems>(const char* _arg0_);
	CFlowNode_InventoryRemoveAllItems* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_InventoryRemoveAllItems>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15DD6F0);
};

// CG2AutoRegFlowNode<CFlowNode_InventoryRemoveItem>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_InventoryRemoveItem> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_InventoryRemoveItem>(const char* _arg0_);
	CFlowNode_InventoryRemoveItem* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_InventoryRemoveItem>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15DD660);
};

// CG2AutoRegFlowNode<CFlowNode_OverrideFOV>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_OverrideFOV> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_OverrideFOV>(const char* _arg0_);
	CFlowNode_OverrideFOV* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_OverrideFOV>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x189EE40);
};

// CG2AutoRegFlowNode<CFlowNode_PlayerCinematicControl>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_PlayerCinematicControl> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_PlayerCinematicControl>(const char* _arg0_);
	CFlowNode_PlayerCinematicControl* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_PlayerCinematicControl>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x189D660);
};

// CG2AutoRegFlowNode<CFlowNode_PlayerLookAt>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_PlayerLookAt> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_PlayerLookAt>(const char* _arg0_);
	CFlowNode_PlayerLookAt* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_PlayerLookAt>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x189D5D0);
};

// CG2AutoRegFlowNode<CFlowNode_SetPostEffectParam>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_SetPostEffectParam> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_SetPostEffectParam>(const char* _arg0_);
	CFlowNode_SetPostEffectParam* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_SetPostEffectParam>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18B0B60);
};

// CG2AutoRegFlowNode<CFlowNode_SimulatePlayerInput>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_SimulatePlayerInput> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_SimulatePlayerInput>(const char* _arg0_);
	CFlowNode_SimulatePlayerInput* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_SimulatePlayerInput>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18B8960);
};

// CG2AutoRegFlowNode<CFlowNode_SpawnItemArchetype>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowNode_SpawnItemArchetype> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowNode_SpawnItemArchetype>(const char* _arg0_);
	CFlowNode_SpawnItemArchetype* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowNode_SpawnItemArchetype>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15DE120);
};

// CG2AutoRegFlowNode<CFlowPlayerLinkNode>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowPlayerLinkNode> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowPlayerLinkNode>(const char* _arg0_);
	CFlowPlayerLinkNode* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowPlayerLinkNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A8690);
};

// CG2AutoRegFlowNode<CFlowPlayerStagingNode>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CFlowPlayerStagingNode> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CFlowPlayerStagingNode>(const char* _arg0_);
	CFlowPlayerStagingNode* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CFlowPlayerStagingNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A8600);
};

// CG2AutoRegFlowNode<CTacticalScanCurrentControlNode>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CTacticalScanCurrentControlNode> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CTacticalScanCurrentControlNode>(const char* _arg0_);
	CTacticalScanCurrentControlNode* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CTacticalScanCurrentControlNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18BACF0);
};

// CG2AutoRegFlowNode<CTacticalScanNode>
// Header:  Prey/GameDll/nodes/g2flowbasenode.h
class CG2AutoRegFlowNode<CTacticalScanNode> : public CG2AutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CG2AutoRegFlowNode<CTacticalScanNode>(const char* _arg0_);
	CTacticalScanNode* GetInstance();
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CG2AutoRegFlowNode<CTacticalScanNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18BABC0);
};
#endif // MOONCRASH
