// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryScriptSystem/IScriptSystem.h>
#include <Prey/GameDll/ark/ScriptHandle.h>

struct IFunctionHandler;
struct IRenderer;
struct ISystem;

// Header: FromCpp
// Prey/GameDll/ark/scriptbind_ark.h
class CScriptBind_Ark : public CScriptableBase // Id=8016630 Size=112
{
public:
	ISystem *m_pSystem;
	IRenderer *m_pRenderer;
	
	CScriptBind_Ark(ISystem *pSystem);
	int DrawNote(IFunctionHandler *pH) { return FDrawNote(this,pH); }
	int SpawnAttachedParticleEffect(IFunctionHandler *pH, const char *effectName, ScriptHandle parentId) { return FSpawnAttachedParticleEffect(this,pH,effectName,parentId); }
	int TriggerPostEffect(IFunctionHandler *_pH, const char *_effectId) { return FTriggerPostEffect(this,_pH,_effectId); }
	int ModifyGameMetric(IFunctionHandler *_pH, const char *_id, float _delta) { return FModifyGameMetric(this,_pH,_id,_delta); }
	int SetWorldUIEntity(IFunctionHandler *_pH, ScriptHandle _entityId, unsigned _instanceId, const char *_materialName, const char *_uiElementName, int _subMatIndex) { return FSetWorldUIEntity(this,_pH,_entityId,_instanceId,_materialName,_uiElementName,_subMatIndex); }
	int SetWorldUIDistances(IFunctionHandler *_pH, unsigned _instanceId, const char *_uiElementName, float _fInteractDistance, float _fActiveDistance, float _fInteractAngle) { return FSetWorldUIDistances(this,_pH,_instanceId,_uiElementName,_fInteractDistance,_fActiveDistance,_fInteractAngle); }
	int SetWorldUIActive(IFunctionHandler *_pH, unsigned _instanceId, const char *_uiElementName, bool _bActive) { return FSetWorldUIActive(this,_pH,_instanceId,_uiElementName,_bActive); }
	int OpenExternalInventory(IFunctionHandler *_pH, ScriptHandle _ownerEntityId) { return FOpenExternalInventory(this,_pH,_ownerEntityId); }
	int SpawnLootFromTable(IFunctionHandler *_pH, const char *_tableName, ScriptHandle _ownerId) { return FSpawnLootFromTable(this,_pH,_tableName,_ownerId); }
	int RegisterForSignal(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_signalId) { return FRegisterForSignal(this,_pH,_entityId,_signalId); }
	int RegisterForAllSignals(IFunctionHandler *_pH, ScriptHandle _entityId) { return FRegisterForAllSignals(this,_pH,_entityId); }
	int SendSignalPackage(IFunctionHandler *_pH, ScriptHandle _targetEntityId, ScriptHandle _senderEntityId, ScriptHandle _instigatorEntityId, const char *_packageId) { return FSendSignalPackage(this,_pH,_targetEntityId,_senderEntityId,_instigatorEntityId,_packageId); }
	int SendSignalPackageInAOE(IFunctionHandler *_pH, ScriptHandle _senderEntityId, ScriptHandle _instigatorEntityId, const char *_packageId, Vec3 _location, float _minRadius, float _maxRadius, const bool _bShouldCheckLOS, const float _impulse) { return FSendSignalPackageInAOE(this,_pH,_senderEntityId,_instigatorEntityId,_packageId,_location,_minRadius,_maxRadius,_bShouldCheckLOS,_impulse); }
	int AttachInboundSignalModifier(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_modifierId) { return FAttachInboundSignalModifier(this,_pH,_entityId,_modifierId); }
	int AttachOutboundSignalModifier(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_modifierId) { return FAttachOutboundSignalModifier(this,_pH,_entityId,_modifierId); }
	int RemoveInboundSignalModifier(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_modifierId) { return FRemoveInboundSignalModifier(this,_pH,_entityId,_modifierId); }
	int RemoveOutboundSignalModifier(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_modifierId) { return FRemoveOutboundSignalModifier(this,_pH,_entityId,_modifierId); }
	int EnableCollision(IFunctionHandler *_pH, ScriptHandle _entityId) { return FEnableCollision(this,_pH,_entityId); }
	int DisableCollision(IFunctionHandler *_pH, ScriptHandle _entityId) { return FDisableCollision(this,_pH,_entityId); }
	int LockDoor(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bLock) { return FLockDoor(this,_pH,_entityId,_bLock); }
	int OpenDoor(IFunctionHandler *_pH, ScriptHandle _entityId) { return FOpenDoor(this,_pH,_entityId); }
	int CloseDoor(IFunctionHandler *_pH, ScriptHandle _entityId) { return FCloseDoor(this,_pH,_entityId); }
	int PowerDoor(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bOn) { return FPowerDoor(this,_pH,_entityId,_bOn); }
	int AttemptHack(IFunctionHandler *_pH, ScriptHandle _entityId) { return FAttemptHack(this,_pH,_entityId); }
	int SetFabricatorPowered(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered) { return FSetFabricatorPowered(this,_pH,_entityId,_bPowered); }
	int SetRecyclerPowered(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered) { return FSetRecyclerPowered(this,_pH,_entityId,_bPowered); }
	int SetOperatorDispenserPowered(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered) { return FSetOperatorDispenserPowered(this,_pH,_entityId,_bPowered); }
	int SetOperatorDispenserLocked(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bLocked) { return FSetOperatorDispenserLocked(this,_pH,_entityId,_bLocked); }
	int ForceOperatorDispenserSpawn(IFunctionHandler *_pH, ScriptHandle _entityId) { return FForceOperatorDispenserSpawn(this,_pH,_entityId); }
	int OperatorDispenserOverrideValues(IFunctionHandler *_pH, ScriptHandle _entityId, string _archetypeName, int _maxConcurrent, int _maxLifetime, float _autospawnDuration) { return FOperatorDispenserOverrideValues(this,_pH,_entityId,_archetypeName,_maxConcurrent,_maxLifetime,_autospawnDuration); }
	int OperatorDispenserClearOverrides(IFunctionHandler *_pH, ScriptHandle _dispenserId) { return FOperatorDispenserClearOverrides(this,_pH,_dispenserId); }
	int OperatorDispenserAssignOperator(IFunctionHandler *_pH, ScriptHandle _dispenserId, ScriptHandle _operatorId) { return FOperatorDispenserAssignOperator(this,_pH,_dispenserId,_operatorId); }
	int SetElectricalBoxPowered(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered, ScriptHandle _activatorId) { return FSetElectricalBoxPowered(this,_pH,_entityId,_bPowered,_activatorId); }
	int SetLeakableValveState(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bOpen) { return FSetLeakableValveState(this,_pH,_entityId,_bOpen); }
	int ExplodeTank(IFunctionHandler *_pH, ScriptHandle _entityId) { return FExplodeTank(this,_pH,_entityId); }
	int SetEnvironmentalHazardActivator(IFunctionHandler *_pH, ScriptHandle _entityId, ScriptHandle _activatorId) { return FSetEnvironmentalHazardActivator(this,_pH,_entityId,_activatorId); }
	int ActivateSurfaceHazard(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bActivate, bool _bNeighbors) { return FActivateSurfaceHazard(this,_pH,_entityId,_bActivate,_bNeighbors); }
	int LinkKeyUIToDoor(IFunctionHandler *_pH, ScriptHandle _keyId, ScriptHandle _doorId) { return FLinkKeyUIToDoor(this,_pH,_keyId,_doorId); }
	int SetKeyUIPowered(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered) { return FSetKeyUIPowered(this,_pH,_entityId,_bPowered); }
	int SetKeyUILocked(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bLocked) { return FSetKeyUILocked(this,_pH,_entityId,_bLocked); }
	int SetLevelTransitionDoorInaccessible(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bInaccessible) { return FSetLevelTransitionDoorInaccessible(this,_pH,_entityId,_bInaccessible); }
	int SetLevelTransitionDoorInaccessibleText(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_text) { return FSetLevelTransitionDoorInaccessibleText(this,_pH,_entityId,_text); }
	int SetStationUIPowered(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered) { return FSetStationUIPowered(this,_pH,_entityId,_bPowered); }
	int SetStationUILocked(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bLocked) { return FSetStationUILocked(this,_pH,_entityId,_bLocked); }
	int ClearWorkstationKeypad(IFunctionHandler *_pH, ScriptHandle _entityId) { return FClearWorkstationKeypad(this,_pH,_entityId); }
	int RefreshSecurityStationRoster(IFunctionHandler *_pH, ScriptHandle _entityId) { return FRefreshSecurityStationRoster(this,_pH,_entityId); }
	int EnableTrackingCamera(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bEnable) { return FEnableTrackingCamera(this,_pH,_entityId,_bEnable); }
	int ActivateInteractiveObject(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bActivate) { return FActivateInteractiveObject(this,_pH,_entityId,_bActivate); }
	int DisableInteractiveObject(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bDisable) { return FDisableInteractiveObject(this,_pH,_entityId,_bDisable); }
	int LinkInteractiveObjectToDoor(IFunctionHandler *_pH, ScriptHandle _entityId, ScriptHandle _doorId) { return FLinkInteractiveObjectToDoor(this,_pH,_entityId,_doorId); }
	int ProfileZoneEnter(IFunctionHandler *_pH, const char *_label) { return FProfileZoneEnter(this,_pH,_label); }
	int ProfileZoneExit(IFunctionHandler *_pH) { return FProfileZoneExit(this,_pH); }
	int RegisterPASpeaker(IFunctionHandler *_pH, ScriptHandle _entityId, int _channelId, float _scale) { return FRegisterPASpeaker(this,_pH,_entityId,_channelId,_scale); }
	int UnregisterPASpeaker(IFunctionHandler *_pH, ScriptHandle _entityId, int _channelId) { return FUnregisterPASpeaker(this,_pH,_entityId,_channelId); }
	int ForceCystoidToFollow(IFunctionHandler *_pH, ScriptHandle _cystoidId, ScriptHandle _targetId) { return FForceCystoidToFollow(this,_pH,_cystoidId,_targetId); }
	int TriggerCystoidNest(IFunctionHandler *_pH, ScriptHandle _nestId, ScriptHandle _targetId) { return FTriggerCystoidNest(this,_pH,_nestId,_targetId); }
	int EnableTentacleSpawner(IFunctionHandler *_pH, ScriptHandle _spawnerId, bool _bEnable) { return FEnableTentacleSpawner(this,_pH,_spawnerId,_bEnable); }
	int MorphIn(IFunctionHandler *_pH, ScriptHandle _entityId, float _timeToMorph) { return FMorphIn(this,_pH,_entityId,_timeToMorph); }
	int DisplayTutorial(IFunctionHandler *_pH, const char *_pTutorialId) { return FDisplayTutorial(this,_pH,_pTutorialId); }
	int GetKeyCardLabel(IFunctionHandler *_pH, const char *_keycardID) { return FGetKeyCardLabel(this,_pH,_keycardID); }
	int GetNoteSubject(IFunctionHandler *const _pH, const char *_noteID) { return FGetNoteSubject(this,_pH,_noteID); }
	int IsNotePlotCritical(IFunctionHandler *const _pH, const char *_noteId) { return FIsNotePlotCritical(this,_pH,_noteId); }
	int IsAudioLogCollectionPlotCritical(IFunctionHandler *_pH, const char *_audioLogCollectionId) { return FIsAudioLogCollectionPlotCritical(this,_pH,_audioLogCollectionId); }
	int ApplyPharma(IFunctionHandler *_pH, ScriptHandle _entityId) { return FApplyPharma(this,_pH,_entityId); }
	int SetShouldGlint(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bEnabled) { return FSetShouldGlint(this,_pH,_entityId,_bEnabled); }
	int SetGlintConfig(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_szConfigId) { return FSetGlintConfig(this,_pH,_entityId,_szConfigId); }
	int SetArkRotatorActive(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bEnabled) { return FSetArkRotatorActive(this,_pH,_entityId,_bEnabled); }
	int HandleGooOverlappingEntity(IFunctionHandler *_pH, ScriptHandle _entityId, const bool _bDeleteGoo) { return FHandleGooOverlappingEntity(this,_pH,_entityId,_bDeleteGoo); }
	int AddInstigationEvent(IFunctionHandler *_pH, ScriptHandle _instigatedId, ScriptHandle _instigatorId, float _decayTime) { return FAddInstigationEvent(this,_pH,_instigatedId,_instigatorId,_decayTime); }
	int SetCollisionClassIgnore(IFunctionHandler *_pH, ScriptHandle _entityId, unsigned _flags) { return FSetCollisionClassIgnore(this,_pH,_entityId,_flags); }
	virtual ~CScriptBind_Ark();
	
	static inline auto FDrawNote = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *pH)>(0x15BFE00);
	static inline auto FSpawnAttachedParticleEffect = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *pH, const char *effectName, ScriptHandle parentId)>(0x15C3000);
	static inline auto FTriggerPostEffect = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, const char *_effectId)>(0x15C3470);
	static inline auto FModifyGameMetric = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, const char *_id, float _delta)>(0x15C14F0);
	static inline auto FSetWorldUIEntity = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, unsigned _instanceId, const char *_materialName, const char *_uiElementName, int _subMatIndex)>(0x15C2D00);
	static inline auto FSetWorldUIDistances = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, unsigned _instanceId, const char *_uiElementName, float _fInteractDistance, float _fActiveDistance, float _fInteractAngle)>(0x15C2C90);
	static inline auto FSetWorldUIActive = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, unsigned _instanceId, const char *_uiElementName, bool _bActive)>(0x15C2C30);
	static inline auto FOpenExternalInventory = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _ownerEntityId)>(0x15C1640);
	static inline auto FSpawnLootFromTable = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, const char *_tableName, ScriptHandle _ownerId)>(0x15C3140);
	static inline auto FRegisterForSignal = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_signalId)>(0x15C1900);
	static inline auto FRegisterForAllSignals = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15C18C0);
	static inline auto FSendSignalPackage = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _targetEntityId, ScriptHandle _senderEntityId, ScriptHandle _instigatorEntityId, const char *_packageId)>(0x15C1BC0);
	static inline auto FSendSignalPackageInAOE = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _senderEntityId, ScriptHandle _instigatorEntityId, const char *_packageId, Vec3 _location, float _minRadius, float _maxRadius, const bool _bShouldCheckLOS, const float _impulse)>(0x15C1D50);
	static inline auto FAttachInboundSignalModifier = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_modifierId)>(0x15BF3F0);
	static inline auto FAttachOutboundSignalModifier = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_modifierId)>(0x15BF490);
	static inline auto FRemoveInboundSignalModifier = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_modifierId)>(0x15C1A80);
	static inline auto FRemoveOutboundSignalModifier = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_modifierId)>(0x15C1B20);
	static inline auto FEnableCollision = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15C05B0);
	static inline auto FDisableCollision = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15BF680);
	static inline auto FLockDoor = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bLock)>(0x15C14B0);
	static inline auto FOpenDoor = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15C1610);
	static inline auto FCloseDoor = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15BF650);
	static inline auto FPowerDoor = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bOn)>(0x15C1820);
	static inline auto FAttemptHack = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15BF530);
	static inline auto FSetFabricatorPowered = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered)>(0x15C2670);
	static inline auto FSetRecyclerPowered = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered)>(0x15C2AD0);
	static inline auto FSetOperatorDispenserPowered = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered)>(0x15C2A60);
	static inline auto FSetOperatorDispenserLocked = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bLocked)>(0x15C29F0);
	static inline auto FForceOperatorDispenserSpawn = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15C08F0);
	static inline auto FOperatorDispenserOverrideValues = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, string _archetypeName, int _maxConcurrent, int _maxLifetime, float _autospawnDuration)>(0x15C1780);
	static inline auto FOperatorDispenserClearOverrides = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _dispenserId)>(0x15C1720);
	static inline auto FOperatorDispenserAssignOperator = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _dispenserId, ScriptHandle _operatorId)>(0x15C16B0);
	static inline auto FSetElectricalBoxPowered = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered, ScriptHandle _activatorId)>(0x15C2570);
	static inline auto FSetLeakableValveState = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bOpen)>(0x15C2860);
	static inline auto FExplodeTank = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15C07A0);
	static inline auto FSetEnvironmentalHazardActivator = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, ScriptHandle _activatorId)>(0x15C25E0);
	static inline auto FActivateSurfaceHazard = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bActivate, bool _bNeighbors)>(0x15BF2C0);
	static inline auto FLinkKeyUIToDoor = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _keyId, ScriptHandle _doorId)>(0x15C1470);
	static inline auto FSetKeyUIPowered = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered)>(0x15C2810);
	static inline auto FSetKeyUILocked = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bLocked)>(0x15C27C0);
	static inline auto FSetLevelTransitionDoorInaccessible = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bInaccessible)>(0x15C28D0);
	static inline auto FSetLevelTransitionDoorInaccessibleText = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_text)>(0x15C2910);
	static inline auto FSetStationUIPowered = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered)>(0x15C2BE0);
	static inline auto FSetStationUILocked = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bLocked)>(0x15C2BA0);
	static inline auto FClearWorkstationKeypad = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15BF5F0);
	static inline auto FRefreshSecurityStationRoster = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15C1860);
	static inline auto FEnableTrackingCamera = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bEnable)>(0x15C06B0);
	static inline auto FActivateInteractiveObject = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bActivate)>(0x15BF270);
	static inline auto FDisableInteractiveObject = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bDisable)>(0x15BF690);
	static inline auto FLinkInteractiveObjectToDoor = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, ScriptHandle _doorId)>(0x15C1430);
	static inline auto FProfileZoneEnter = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, const char *_label)>(0x75CBB0);
	static inline auto FProfileZoneExit = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH)>(0x75CBB0);
	static inline auto FRegisterPASpeaker = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, int _channelId, float _scale)>(0x15C1A20);
	static inline auto FUnregisterPASpeaker = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, int _channelId)>(0x15C34F0);
	static inline auto FForceCystoidToFollow = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _cystoidId, ScriptHandle _targetId)>(0x15C0800);
	static inline auto FTriggerCystoidNest = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _nestId, ScriptHandle _targetId)>(0x15C3380);
	static inline auto FEnableTentacleSpawner = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _spawnerId, bool _bEnable)>(0x15C05C0);
	static inline auto FMorphIn = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, float _timeToMorph)>(0x15C15A0);
	static inline auto FDisplayTutorial = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, const char *_pTutorialId)>(0x15BFD60);
	static inline auto FGetKeyCardLabel = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, const char *_keycardID)>(0x15C0AD0);
	static inline auto FGetNoteSubject = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *const _pH, const char *_noteID)>(0x15C0E70);
	static inline auto FIsNotePlotCritical = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *const _pH, const char *_noteId)>(0x15C1350);
	static inline auto FIsAudioLogCollectionPlotCritical = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, const char *_audioLogCollectionId)>(0x15C1190);
	static inline auto FApplyPharma = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15BF380);
	static inline auto FSetShouldGlint = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bEnabled)>(0x15C2B40);
	static inline auto FSetGlintConfig = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_szConfigId)>(0x15C26E0);
	static inline auto FSetArkRotatorActive = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bEnabled)>(0x15C23E0);
	static inline auto FHandleGooOverlappingEntity = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const bool _bDeleteGoo)>(0x15C10D0);
	static inline auto FAddInstigationEvent = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _instigatedId, ScriptHandle _instigatorId, float _decayTime)>(0x15BF340);
	static inline auto FSetCollisionClassIgnore = PreyFunction<int(CScriptBind_Ark *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, unsigned _flags)>(0x15C24D0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

struct IFunctionHandler;
struct IRenderer;
struct ISystem;
union ScriptHandle;

// CScriptBind_Ark
// Header:  Prey/GameDll/ark/ScriptBind_Ark.h
class CScriptBind_Ark : public CScriptableBase
{ // Size=112 (0x70)
public:
	ISystem* m_pSystem;
	IRenderer* m_pRenderer;

	CScriptBind_Ark(ISystem* pSystem);
	int DrawNote(IFunctionHandler* pH) { return FDrawNote(this, pH); }
	int SpawnAttachedParticleEffect(IFunctionHandler* pH, const char* effectName, const ScriptHandle parentId) { return FSpawnAttachedParticleEffect(this, pH, effectName, parentId); }
	int TriggerPostEffect(IFunctionHandler* _pH, const char* _effectId) { return FTriggerPostEffect(this, _pH, _effectId); }
	int ModifyGameMetric(IFunctionHandler* _pH, const char* _id, float _delta) { return FModifyGameMetric(this, _pH, _id, _delta); }
	int IncreaseDoomClockDuration(IFunctionHandler* _pH, float _val) { return FIncreaseDoomClockDuration(this, _pH, _val); }
	int GetDoomClockAccumulation(IFunctionHandler* _pH) { return FGetDoomClockAccumulation(this, _pH); }
	int SetWorldUIEntity(IFunctionHandler* _pH, ScriptHandle _entityId, unsigned _instanceId, const char* _materialName, const char* _uiElementName, int _subMatIndex) { return FSetWorldUIEntity(this, _pH, _entityId, _instanceId, _materialName, _uiElementName, _subMatIndex); }
	int SetWorldUIDistances(IFunctionHandler* _pH, unsigned _instanceId, const char* _uiElementName, float _fInteractDistance, float _fActiveDistance, float _fInteractAngle) { return FSetWorldUIDistances(this, _pH, _instanceId, _uiElementName, _fInteractDistance, _fActiveDistance, _fInteractAngle); }
	int SetWorldUIActive(IFunctionHandler* _pH, unsigned _instanceId, const char* _uiElementName, bool _bActive) { return FSetWorldUIActive(this, _pH, _instanceId, _uiElementName, _bActive); }
	int OpenExternalInventory(IFunctionHandler* _pH, ScriptHandle _ownerEntityId) { return FOpenExternalInventory(this, _pH, _ownerEntityId); }
	int SpawnLootFromTable(IFunctionHandler* _pH, const char* _tableName, ScriptHandle _ownerId) { return FSpawnLootFromTable(this, _pH, _tableName, _ownerId); }
	int SpawnRandomItem(IFunctionHandler* _pH, const char* _lootTable, Vec3 _location, ScriptHandle _seedId) { return FSpawnRandomItem(this, _pH, _lootTable, _location, _seedId); }
	int GenerateRandomValue(IFunctionHandler* _pH, int _seedId, int _max) { return FGenerateRandomValue(this, _pH, _seedId, _max); }
	int GenerateRandomValueInRange(IFunctionHandler* _pH, int _seedId, int _min, int _max) { return FGenerateRandomValueInRange(this, _pH, _seedId, _min, _max); }
	int RegisterForSignal(IFunctionHandler* _pH, ScriptHandle _entityId, const char* _signalId) { return FRegisterForSignal(this, _pH, _entityId, _signalId); }
	int RegisterForAllSignals(IFunctionHandler* _pH, ScriptHandle _entityId) { return FRegisterForAllSignals(this, _pH, _entityId); }
	int SendSignalPackage(IFunctionHandler* _pH, ScriptHandle _targetEntityId, ScriptHandle _senderEntityId, ScriptHandle _instigatorEntityId, const char* _packageId) { return FSendSignalPackage(this, _pH, _targetEntityId, _senderEntityId, _instigatorEntityId, _packageId); }
	int SendSignalPackageInAOE(IFunctionHandler* _pH, ScriptHandle _senderEntityId, ScriptHandle _instigatorEntityId, const char* _packageId, Vec3 _location, float _minRadius, float _maxRadius, const bool _bShouldCheckLOS, const float _impulse) { return FSendSignalPackageInAOE(this, _pH, _senderEntityId, _instigatorEntityId, _packageId, _location, _minRadius, _maxRadius, _bShouldCheckLOS, _impulse); }
	int AttachInboundSignalModifier(IFunctionHandler* _pH, ScriptHandle _entityId, const char* _modifierId) { return FAttachInboundSignalModifier(this, _pH, _entityId, _modifierId); }
	int AttachOutboundSignalModifier(IFunctionHandler* _pH, ScriptHandle _entityId, const char* _modifierId) { return FAttachOutboundSignalModifier(this, _pH, _entityId, _modifierId); }
	int RemoveInboundSignalModifier(IFunctionHandler* _pH, ScriptHandle _entityId, const char* _modifierId) { return FRemoveInboundSignalModifier(this, _pH, _entityId, _modifierId); }
	int RemoveOutboundSignalModifier(IFunctionHandler* _pH, ScriptHandle _entityId, const char* _modifierId) { return FRemoveOutboundSignalModifier(this, _pH, _entityId, _modifierId); }
	int EnableCollision(IFunctionHandler* _pH, ScriptHandle _entityId) { return FEnableCollision(this, _pH, _entityId); }
	int DisableCollision(IFunctionHandler* _pH, ScriptHandle _entityId) { return FDisableCollision(this, _pH, _entityId); }
	int LockDoor(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bLock) { return FLockDoor(this, _pH, _entityId, _bLock); }
	int OpenDoor(IFunctionHandler* _pH, ScriptHandle _entityId) { return FOpenDoor(this, _pH, _entityId); }
	int CloseDoor(IFunctionHandler* _pH, ScriptHandle _entityId) { return FCloseDoor(this, _pH, _entityId); }
	int PowerDoor(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bOn) { return FPowerDoor(this, _pH, _entityId, _bOn); }
	int AttemptHack(IFunctionHandler* _pH, ScriptHandle _entityId) { return FAttemptHack(this, _pH, _entityId); }
	int SetFabricatorPowered(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered) { return FSetFabricatorPowered(this, _pH, _entityId, _bPowered); }
	int SetRecyclerPowered(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered) { return FSetRecyclerPowered(this, _pH, _entityId, _bPowered); }
	int SetOperatorDispenserPowered(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered) { return FSetOperatorDispenserPowered(this, _pH, _entityId, _bPowered); }
	int SetOperatorDispenserLocked(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bLocked) { return FSetOperatorDispenserLocked(this, _pH, _entityId, _bLocked); }
	int ForceOperatorDispenserSpawn(IFunctionHandler* _pH, ScriptHandle _entityId) { return FForceOperatorDispenserSpawn(this, _pH, _entityId); }
	int OperatorDispenserOverrideValues(IFunctionHandler* _pH, ScriptHandle _entityId, string _archetypeName, int _maxConcurrent, int _maxLifetime, float _autospawnDuration) { return FOperatorDispenserOverrideValues(this, _pH, _entityId, _archetypeName, _maxConcurrent, _maxLifetime, _autospawnDuration); }
	int OperatorDispenserClearOverrides(IFunctionHandler* _pH, ScriptHandle _dispenserId) { return FOperatorDispenserClearOverrides(this, _pH, _dispenserId); }
	int OperatorDispenserAssignOperator(IFunctionHandler* _pH, ScriptHandle _dispenserId, ScriptHandle _operatorId) { return FOperatorDispenserAssignOperator(this, _pH, _dispenserId, _operatorId); }
	int SetElectricalBoxPowered(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered, ScriptHandle _activatorId) { return FSetElectricalBoxPowered(this, _pH, _entityId, _bPowered, _activatorId); }
	int SetTyphonGatePowered(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered) { return FSetTyphonGatePowered(this, _pH, _entityId, _bPowered); }
	int SetTyphonGateSuppressed(IFunctionHandler* _pH, ScriptHandle _entityId) { return FSetTyphonGateSuppressed(this, _pH, _entityId); }
	int MarkTyphonGateTargets(IFunctionHandler* _pH, ScriptHandle _entityId) { return FMarkTyphonGateTargets(this, _pH, _entityId); }
	int SetLeakableValveState(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bOpen) { return FSetLeakableValveState(this, _pH, _entityId, _bOpen); }
	int ExplodeTank(IFunctionHandler* _pH, ScriptHandle _entityId) { return FExplodeTank(this, _pH, _entityId); }
	int SetEnvironmentalHazardActivator(IFunctionHandler* _pH, ScriptHandle _entityId, ScriptHandle _activatorId) { return FSetEnvironmentalHazardActivator(this, _pH, _entityId, _activatorId); }
	int ActivateSurfaceHazard(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bActivate, bool _bNeighbors) { return FActivateSurfaceHazard(this, _pH, _entityId, _bActivate, _bNeighbors); }
	int EnableSurfaceHazard(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bEnable) { return FEnableSurfaceHazard(this, _pH, _entityId, _bEnable); }
	int LinkKeyUIToDoor(IFunctionHandler* _pH, ScriptHandle _keyId, ScriptHandle _doorId) { return FLinkKeyUIToDoor(this, _pH, _keyId, _doorId); }
	int SetKeyUIPowered(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered) { return FSetKeyUIPowered(this, _pH, _entityId, _bPowered); }
	int SetKeyUILocked(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bLocked) { return FSetKeyUILocked(this, _pH, _entityId, _bLocked); }
	int SetLevelTransitionDoorInaccessible(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bInaccessible) { return FSetLevelTransitionDoorInaccessible(this, _pH, _entityId, _bInaccessible); }
	int SetLevelTransitionDoorInaccessibleText(IFunctionHandler* _pH, ScriptHandle _entityId, const char* _text) { return FSetLevelTransitionDoorInaccessibleText(this, _pH, _entityId, _text); }
	int EnableLevelTransitionDoorLevelLoad(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bEnabled) { return FEnableLevelTransitionDoorLevelLoad(this, _pH, _entityId, _bEnabled); }
	int RegisterArkDoorController(IFunctionHandler* _pH, ScriptHandle _doorId, ScriptHandle _controllerId) { return FRegisterArkDoorController(this, _pH, _doorId, _controllerId); }
	int UnregisterArkDoorController(IFunctionHandler* _pH, ScriptHandle _doorId, ScriptHandle _controllerId) { return FUnregisterArkDoorController(this, _pH, _doorId, _controllerId); }
	int SetStationUIPowered(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered) { return FSetStationUIPowered(this, _pH, _entityId, _bPowered); }
	int SetStationUILocked(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bLocked) { return FSetStationUILocked(this, _pH, _entityId, _bLocked); }
	int ClearWorkstationKeypad(IFunctionHandler* _pH, ScriptHandle _entityId) { return FClearWorkstationKeypad(this, _pH, _entityId); }
	int RefreshSecurityStationRoster(IFunctionHandler* _pH, ScriptHandle _entityId) { return FRefreshSecurityStationRoster(this, _pH, _entityId); }
	int OverrideSecurityStationLocation(IFunctionHandler* _pH, ScriptHandle _entityId, const char* _locationIdString) { return FOverrideSecurityStationLocation(this, _pH, _entityId, _locationIdString); }
	int EnableTrackingCamera(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bEnable) { return FEnableTrackingCamera(this, _pH, _entityId, _bEnable); }
	int ActivateInteractiveObject(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bActivate, bool _bForce) { return FActivateInteractiveObject(this, _pH, _entityId, _bActivate, _bForce); }
	int DisableInteractiveObject(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bDisable) { return FDisableInteractiveObject(this, _pH, _entityId, _bDisable); }
	int LinkInteractiveObjectToDoor(IFunctionHandler* _pH, ScriptHandle _entityId, ScriptHandle _doorId) { return FLinkInteractiveObjectToDoor(this, _pH, _entityId, _doorId); }
	int ProfileZoneEnter(IFunctionHandler* _pH, const char* _label) { return FProfileZoneEnter(this, _pH, _label); }
	int ProfileZoneExit(IFunctionHandler* _pH) { return FProfileZoneExit(this, _pH); }
	int RegisterPASpeaker(IFunctionHandler* _pH, ScriptHandle _entityId, int _channelId, float _scale) { return FRegisterPASpeaker(this, _pH, _entityId, _channelId, _scale); }
	int UnregisterPASpeaker(IFunctionHandler* _pH, ScriptHandle _entityId, int _channelId) { return FUnregisterPASpeaker(this, _pH, _entityId, _channelId); }
	int ForceCystoidToFollow(IFunctionHandler* _pH, ScriptHandle _cystoidId, ScriptHandle _targetId) { return FForceCystoidToFollow(this, _pH, _cystoidId, _targetId); }
	int TriggerTyphonNest(IFunctionHandler* _pH, ScriptHandle _nestId, ScriptHandle _targetId) { return FTriggerTyphonNest(this, _pH, _nestId, _targetId); }
	int EnableTentacleSpawner(IFunctionHandler* _pH, ScriptHandle _spawnerId, bool _bEnable) { return FEnableTentacleSpawner(this, _pH, _spawnerId, _bEnable); }
	int MorphIn(IFunctionHandler* _pH, ScriptHandle _entityId, float _timeToMorph) { return FMorphIn(this, _pH, _entityId, _timeToMorph); }
	int DisplayTutorial(IFunctionHandler* _pH, const char* _pTutorialId) { return FDisplayTutorial(this, _pH, _pTutorialId); }
	int GetKeyCardLabel(IFunctionHandler* _pH, const char* _keycardID) { return FGetKeyCardLabel(this, _pH, _keycardID); }
	int GetNoteSubject(IFunctionHandler* const _pH, const char* _noteID) { return FGetNoteSubject(this, _pH, _noteID); }
	int IsNotePlotCritical(IFunctionHandler* const _pH, const char* _noteId) { return FIsNotePlotCritical(this, _pH, _noteId); }
	int IsAudioLogCollectionPlotCritical(IFunctionHandler* _pH, const char* _audioLogCollectionId) { return FIsAudioLogCollectionPlotCritical(this, _pH, _audioLogCollectionId); }
	int ApplyPharma(IFunctionHandler* _pH, ScriptHandle _entityId) { return FApplyPharma(this, _pH, _entityId); }
	int SetShouldGlint(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bEnabled) { return FSetShouldGlint(this, _pH, _entityId, _bEnabled); }
	int SetGlintConfig(IFunctionHandler* _pH, ScriptHandle _entityId, const char* _szConfigId) { return FSetGlintConfig(this, _pH, _entityId, _szConfigId); }
	int SetArkRotatorActive(IFunctionHandler* _pH, ScriptHandle _entityId, bool _bEnabled) { return FSetArkRotatorActive(this, _pH, _entityId, _bEnabled); }
	int HandleGooOverlappingEntity(IFunctionHandler* _pH, ScriptHandle _entityId, const bool _bDeleteGoo) { return FHandleGooOverlappingEntity(this, _pH, _entityId, _bDeleteGoo); }
	int AddInstigationEvent(IFunctionHandler* _pH, ScriptHandle _instigatedId, ScriptHandle _instigatorId, float _decayTime) { return FAddInstigationEvent(this, _pH, _instigatedId, _instigatorId, _decayTime); }
	int ActivatePsiPower(IFunctionHandler* const _pH, const char* _powerName) { return FActivatePsiPower(this, _pH, _powerName); }
	int UnlockPsiPower(IFunctionHandler* const _pH, const char* _powerName) { return FUnlockPsiPower(this, _pH, _powerName); }
	int LockPsiPower(IFunctionHandler* const _pH, const char* _powerName) { return FLockPsiPower(this, _pH, _powerName); }
	int IsPsiPowerActive(IFunctionHandler* const _pH, const char* _powerName) { return FIsPsiPowerActive(this, _pH, _powerName); }
	int ApplyRandomName(IFunctionHandler* _pH, ScriptHandle _target, string _randomNamePool, string _restrictedCharacter) { return FApplyRandomName(this, _pH, _target, _randomNamePool, _restrictedCharacter); }
	int SetCollisionClassIgnore(IFunctionHandler* _pH, ScriptHandle _entityId, unsigned _flags) { return FSetCollisionClassIgnore(this, _pH, _entityId, _flags); }

	static inline auto FCScriptBind_ArkOv2 = PreyFunction<void(CScriptBind_Ark* const _this, ISystem* pSystem)>(0x16E31C0);
	static inline auto FDrawNote = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* pH)>(0x16E63D0);
	static inline auto FSpawnAttachedParticleEffect = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* pH, const char* effectName, const ScriptHandle parentId)>(0x16E9B30);
	static inline auto FTriggerPostEffect = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, const char* _effectId)>(0x16E9E90);
	static inline auto FModifyGameMetric = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, const char* _id, float _delta)>(0x16E7F50);
	static inline auto FIncreaseDoomClockDuration = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, float _val)>(0x16E79C0);
	static inline auto FGetDoomClockAccumulation = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH)>(0x16E71B0);
	static inline auto FSetWorldUIEntity = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, unsigned _instanceId, const char* _materialName, const char* _uiElementName, int _subMatIndex)>(0x16E9830);
	static inline auto FSetWorldUIDistances = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, unsigned _instanceId, const char* _uiElementName, float _fInteractDistance, float _fActiveDistance, float _fInteractAngle)>(0x16E97C0);
	static inline auto FSetWorldUIActive = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, unsigned _instanceId, const char* _uiElementName, bool _bActive)>(0x16E9760);
	static inline auto FOpenExternalInventory = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _ownerEntityId)>(0x16E8060);
	static inline auto FSpawnLootFromTable = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, const char* _tableName, ScriptHandle _ownerId)>(0x16E9C70);
	static inline auto FSpawnRandomItem = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, const char* _lootTable, Vec3 _location, ScriptHandle _seedId)>(0x16E9D70);
	static inline auto FGenerateRandomValue = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, int _seedId, int _max)>(0x16E7050);
	static inline auto FGenerateRandomValueInRange = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, int _seedId, int _min, int _max)>(0x16E7100);
	static inline auto FRegisterForSignal = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, const char* _signalId)>(0x16E83A0);
	static inline auto FRegisterForAllSignals = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E8360);
	static inline auto FSendSignalPackage = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _targetEntityId, ScriptHandle _senderEntityId, ScriptHandle _instigatorEntityId, const char* _packageId)>(0x16E8690);
	static inline auto FSendSignalPackageInAOE = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _senderEntityId, ScriptHandle _instigatorEntityId, const char* _packageId, Vec3 _location, float _minRadius, float _maxRadius, const bool _bShouldCheckLOS, const float _impulse)>(0x16E8830);
	static inline auto FAttachInboundSignalModifier = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, const char* _modifierId)>(0x16E5850);
	static inline auto FAttachOutboundSignalModifier = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, const char* _modifierId)>(0x16E5900);
	static inline auto FRemoveInboundSignalModifier = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, const char* _modifierId)>(0x16E8530);
	static inline auto FRemoveOutboundSignalModifier = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, const char* _modifierId)>(0x16E85E0);
	static inline auto FEnableCollision = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E6B80);
	static inline auto FDisableCollision = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E5B00);
	static inline auto FLockDoor = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bLock)>(0x16E7E80);
	static inline auto FOpenDoor = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E8030);
	static inline auto FCloseDoor = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E5AD0);
	static inline auto FPowerDoor = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bOn)>(0x16E82A0);
	static inline auto FAttemptHack = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E59B0);
	static inline auto FSetFabricatorPowered = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered)>(0x16E9170);
	static inline auto FSetRecyclerPowered = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered)>(0x16E9590);
	static inline auto FSetOperatorDispenserPowered = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered)>(0x16E9520);
	static inline auto FSetOperatorDispenserLocked = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bLocked)>(0x16E94B0);
	static inline auto FForceOperatorDispenserSpawn = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E6FF0);
	static inline auto FOperatorDispenserOverrideValues = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, string _archetypeName, int _maxConcurrent, int _maxLifetime, float _autospawnDuration)>(0x16E81A0);
	static inline auto FOperatorDispenserClearOverrides = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _dispenserId)>(0x16E8140);
	static inline auto FOperatorDispenserAssignOperator = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _dispenserId, ScriptHandle _operatorId)>(0x16E80D0);
	static inline auto FSetElectricalBoxPowered = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered, ScriptHandle _activatorId)>(0x16E9070);
	static inline auto FSetTyphonGatePowered = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered)>(0x16E96F0);
	static inline auto FSetTyphonGateSuppressed = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E9730);
	static inline auto FMarkTyphonGateTargets = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E7F20);
	static inline auto FSetLeakableValveState = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bOpen)>(0x16E9320);
	static inline auto FExplodeTank = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E6EA0);
	static inline auto FSetEnvironmentalHazardActivator = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, ScriptHandle _activatorId)>(0x16E90E0);
	static inline auto FActivateSurfaceHazard = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bActivate, bool _bNeighbors)>(0x16E5500);
	static inline auto FEnableSurfaceHazard = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bEnable)>(0x16E6BD0);
	static inline auto FLinkKeyUIToDoor = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _keyId, ScriptHandle _doorId)>(0x16E7E40);
	static inline auto FSetKeyUIPowered = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered)>(0x16E92D0);
	static inline auto FSetKeyUILocked = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bLocked)>(0x16E9280);
	static inline auto FSetLevelTransitionDoorInaccessible = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bInaccessible)>(0x16E9390);
	static inline auto FSetLevelTransitionDoorInaccessibleText = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, const char* _text)>(0x16E93D0);
	static inline auto FEnableLevelTransitionDoorLevelLoad = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bEnabled)>(0x16E6B90);
	static inline auto FRegisterArkDoorController = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _doorId, ScriptHandle _controllerId)>(0x16E8320);
	static inline auto FUnregisterArkDoorController = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _doorId, ScriptHandle _controllerId)>(0x16EA140);
	static inline auto FSetStationUIPowered = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bPowered)>(0x16E96A0);
	static inline auto FSetStationUILocked = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bLocked)>(0x16E9660);
	static inline auto FClearWorkstationKeypad = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E5A70);
	static inline auto FRefreshSecurityStationRoster = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E82E0);
	static inline auto FOverrideSecurityStationLocation = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, const char* _locationIdString)>(0x16E8240);
	static inline auto FEnableTrackingCamera = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bEnable)>(0x16E6DB0);
	static inline auto FActivateInteractiveObject = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bActivate, bool _bForce)>(0x16E5440);
	static inline auto FDisableInteractiveObject = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bDisable)>(0x16E5B10);
	static inline auto FLinkInteractiveObjectToDoor = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, ScriptHandle _doorId)>(0x16E7E00);
	static inline auto FProfileZoneEnter = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, const char* _label)>(0x77DB10);
	static inline auto FProfileZoneExit = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH)>(0x77DB10);
	static inline auto FRegisterPASpeaker = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, int _channelId, float _scale)>(0x16E84D0);
	static inline auto FUnregisterPASpeaker = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, int _channelId)>(0x16EA180);
	static inline auto FForceCystoidToFollow = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _cystoidId, ScriptHandle _targetId)>(0x16E6F00);
	static inline auto FTriggerTyphonNest = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _nestId, ScriptHandle _targetId)>(0x16E9F20);
	static inline auto FEnableTentacleSpawner = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _spawnerId, bool _bEnable)>(0x16E6C40);
	static inline auto FMorphIn = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, float _timeToMorph)>(0x16E7FC0);
	static inline auto FDisplayTutorial = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, const char* _pTutorialId)>(0x16E6320);
	static inline auto FGetKeyCardLabel = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, const char* _keycardID)>(0x16E72F0);
	static inline auto FGetNoteSubject = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* const _pH, const char* _noteID)>(0x16E76A0);
	static inline auto FIsNotePlotCritical = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* const _pH, const char* _noteId)>(0x16E7C50);
	static inline auto FIsAudioLogCollectionPlotCritical = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, const char* _audioLogCollectionId)>(0x16E7A80);
	static inline auto FApplyPharma = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId)>(0x16E55C0);
	static inline auto FSetShouldGlint = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bEnabled)>(0x16E9600);
	static inline auto FSetGlintConfig = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, const char* _szConfigId)>(0x16E91E0);
	static inline auto FSetArkRotatorActive = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, bool _bEnabled)>(0x16E8EE0);
	static inline auto FHandleGooOverlappingEntity = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, const bool _bDeleteGoo)>(0x16E7900);
	static inline auto FAddInstigationEvent = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _instigatedId, ScriptHandle _instigatorId, float _decayTime)>(0x16E5580);
	static inline auto FActivatePsiPower = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* const _pH, const char* _powerName)>(0x16E5490);
	static inline auto FUnlockPsiPower = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* const _pH, const char* _powerName)>(0x16EA0E0);
	static inline auto FLockPsiPower = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* const _pH, const char* _powerName)>(0x16E7EC0);
	static inline auto FIsPsiPowerActive = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* const _pH, const char* _powerName)>(0x16E7D40);
	static inline auto FApplyRandomName = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _target, string _randomNamePool, string _restrictedCharacter)>(0x16E5630);
	static inline auto FSetCollisionClassIgnore = PreyFunction<int(CScriptBind_Ark* const _this, IFunctionHandler* _pH, ScriptHandle _entityId, unsigned _flags)>(0x16E8FD0);
};
#endif // !MOONCRASH
