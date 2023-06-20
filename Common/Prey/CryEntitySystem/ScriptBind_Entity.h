// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryPhysics/physinterface.h>
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class CDLight;
struct GoalParams;
struct ICharacterInstance;
class ICrySizer;
struct IEntity;
struct IEntitySystem;
struct IFunctionHandler;
struct IPhysicalEntity;
struct IScriptSystem;
struct IScriptTable;
struct IStatObj;
struct ISystem;
struct ParticleParams;
struct SAudioRequestInfo;
struct SEntityPhysicalizeParams;
struct SFogVolumeProperties;
struct SVolumeObjectMovementProperties;
union ScriptHandle;

// CScriptBind_Entity
// Header:  CryEngine/cryentitysystem/ScriptBind_Entity.h
// Include: Prey/CryEntitySystem/ScriptBind_Entity.h
class CScriptBind_Entity : public CScriptableBase
{ // Size=888 (0x378)
public:
	// CScriptBind_Entity::SIntersectionResult
	// Header:  CryEngine/cryentitysystem/ScriptBind_Entity.h
	struct SIntersectionResult
	{ // Size=348 (0x15C)
		Vec3 position;
		Vec3 v0;
		Vec3 v1;
		Vec3 v2;
		Vec2 uv0;
		Vec2 uv1;
		Vec2 uv2;
		Vec3 baricentric;
		float distance;
		bool backface;
		char material[256];
	};

	IEntitySystem* m_pEntitySystem;
	ISystem* m_pISystem;
	pe_params_particle m_particleParams;
	pe_params_buoyancy m_buoyancyParams;
	pe_player_dimensions m_playerDimensions;
	pe_player_dynamics m_playerDynamics;
	pe_params_area m_areaGravityParams;
	SEntityPhysicalizeParams::AreaDefinition m_areaDefinition;
	std::vector<Vec3> m_areaPoints;
	pe_params_car m_carParams;
	SmartScriptTable m_pStats;
	bool m_bIsAudioEventListener;

	CScriptBind_Entity(IScriptSystem* pSS, ISystem* pSystem, IEntitySystem* pEntitySystem);
	virtual ~CScriptBind_Entity();
	void DelegateCalls(IScriptTable* pInstanceTable) { FDelegateCalls(this, pInstanceTable); }
	void GoalParamsHelper(IFunctionHandler* pH, unsigned index, GoalParams& node) { FGoalParamsHelper(this, pH, index, node); }
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	int DeleteThis(IFunctionHandler* pH) { return FDeleteThis(this, pH); }
	int CreateRenderProxy(IFunctionHandler* pH) { return FCreateRenderProxy(this, pH); }
	int CheckShaderParamCallbacks(IFunctionHandler* pH) { return FCheckShaderParamCallbacks(this, pH); }
	int LoadObject(IFunctionHandler* pH, int nSlot, const char* sFilename) { return FLoadObject(this, pH, nSlot, sFilename); }
	int LoadObjectWithFlags(IFunctionHandler* pH, int nSlot, const char* sFilename, const int loadFlags) { return FLoadObjectWithFlags(this, pH, nSlot, sFilename, loadFlags); }
	int LoadObjectLattice(IFunctionHandler* pH, int nSlot) { return FLoadObjectLattice(this, pH, nSlot); }
	int LoadSubObject(IFunctionHandler* pH, int nSlot, const char* sFilename, const char* sGeomName) { return FLoadSubObject(this, pH, nSlot, sFilename, sGeomName); }
	int LoadCharacter(IFunctionHandler* pH, int nSlot, const char* sFilename) { return FLoadCharacter(this, pH, nSlot, sFilename); }
	int LoadGeomCache(IFunctionHandler* pH, int nSlot, const char* sFilename) { return FLoadGeomCache(this, pH, nSlot, sFilename); }
	int LoadLight(IFunctionHandler* pH, int nSlot, SmartScriptTable table) { return FLoadLight(this, pH, nSlot, table); }
	int SetLightColorParams(IFunctionHandler* pH, int nSlot, Vec3 color, float specular_multiplier) { return FSetLightColorParams(this, pH, nSlot, color, specular_multiplier); }
	int UpdateLightClipBounds(IFunctionHandler* pH, int nSlot) { return FUpdateLightClipBounds(this, pH, nSlot); }
	int SetSelfAsLightCasterException(IFunctionHandler* pH, int nLightSlot) { return FSetSelfAsLightCasterException(this, pH, nLightSlot); }
	int LoadCloud(IFunctionHandler* pH, int nSlot, const char* sFilename) { return FLoadCloud(this, pH, nSlot, sFilename); }
	int SetCloudMovementProperties(IFunctionHandler* pH, int nSlot, SmartScriptTable table) { return FSetCloudMovementProperties(this, pH, nSlot, table); }
	int LoadFogVolume(IFunctionHandler* pH, int nSlot, SmartScriptTable table) { return FLoadFogVolume(this, pH, nSlot, table); }
	int FadeGlobalDensity(IFunctionHandler* pH, int nSlot, float fadeTime, float newGlobalDensity) { return FFadeGlobalDensity(this, pH, nSlot, fadeTime, newGlobalDensity); }
	int LoadVolumeObject(IFunctionHandler* pH, int nSlot, const char* sFilename) { return FLoadVolumeObject(this, pH, nSlot, sFilename); }
	int SetVolumeObjectMovementProperties(IFunctionHandler* pH, int nSlot, SmartScriptTable table) { return FSetVolumeObjectMovementProperties(this, pH, nSlot, table); }
	int LoadParticleEffect(IFunctionHandler* pH, int nSlot, const char* sEffectName, SmartScriptTable table) { return FLoadParticleEffect(this, pH, nSlot, sEffectName, table); }
	int PreLoadParticleEffect(IFunctionHandler* pH, const char* sEffectName) { return FPreLoadParticleEffect(this, pH, sEffectName); }
	int IsSlotParticleEmitter(IFunctionHandler* pH, int slot) { return FIsSlotParticleEmitter(this, pH, slot); }
	int IsSlotLight(IFunctionHandler* pH, int slot) { return FIsSlotLight(this, pH, slot); }
	int IsSlotGeometry(IFunctionHandler* pH, int slot) { return FIsSlotGeometry(this, pH, slot); }
	int IsSlotCharacter(IFunctionHandler* pH, int slot) { return FIsSlotCharacter(this, pH, slot); }
	int GetSlotCount(IFunctionHandler* pH) { return FGetSlotCount(this, pH); }
	int GetSlotPos(IFunctionHandler* pH, int nSlot) { return FGetSlotPos(this, pH, nSlot); }
	int SetSlotPos(IFunctionHandler* pH, int nSlot, Vec3 vPos) { return FSetSlotPos(this, pH, nSlot, vPos); }
	int SetSlotPosAndDir(IFunctionHandler* pH, int nSlot, Vec3 pos, Vec3 dir) { return FSetSlotPosAndDir(this, pH, nSlot, pos, dir); }
	int GetSlotAngles(IFunctionHandler* pH, int nSlot) { return FGetSlotAngles(this, pH, nSlot); }
	int SetSlotAngles(IFunctionHandler* pH, int nSlot, Ang3 vAngles) { return FSetSlotAngles(this, pH, nSlot, vAngles); }
	int SetSlotAnglesDeg(IFunctionHandler* pH, int nSlot, Vec3 vAnglesDeg) { return FSetSlotAnglesDeg(this, pH, nSlot, vAnglesDeg); }
	int GetSlotScale(IFunctionHandler* pH, int nSlot) { return FGetSlotScale(this, pH, nSlot); }
	int SetSlotScale(IFunctionHandler* pH, int nSlot, float fScale) { return FSetSlotScale(this, pH, nSlot, fScale); }
	int IsSlotValid(IFunctionHandler* pH, int nSlot) { return FIsSlotValid(this, pH, nSlot); }
	int CopySlotTM(IFunctionHandler* pH, int destSlot, int srcSlot, bool includeTranslation) { return FCopySlotTM(this, pH, destSlot, srcSlot, includeTranslation); }
	int MultiplyWithSlotTM(IFunctionHandler* pH, int slot, Vec3 pos) { return FMultiplyWithSlotTM(this, pH, slot, pos); }
	int SetSlotWorldTM(IFunctionHandler* pH, int nSlot, Vec3 pos, Vec3 dir) { return FSetSlotWorldTM(this, pH, nSlot, pos, dir); }
	int GetSlotWorldPos(IFunctionHandler* pH, int nSlot) { return FGetSlotWorldPos(this, pH, nSlot); }
	int GetSlotWorldDir(IFunctionHandler* pH, int nSlot) { return FGetSlotWorldDir(this, pH, nSlot); }
	int SetSlotHud3D(IFunctionHandler* pH, int nSlot) { return FSetSlotHud3D(this, pH, nSlot); }
	int SetPos(IFunctionHandler* pH, Vec3 vPos) { return FSetPos(this, pH, vPos); }
	int GetPos(IFunctionHandler* pH) { return FGetPos(this, pH); }
	int SetAngles(IFunctionHandler* pH, Ang3 vAngles) { return FSetAngles(this, pH, vAngles); }
	int GetAngles(IFunctionHandler* pH) { return FGetAngles(this, pH); }
	int SetScale(IFunctionHandler* pH, float fScale) { return FSetScale(this, pH, fScale); }
	int GetScale(IFunctionHandler* pH) { return FGetScale(this, pH); }
	int GetCenterOfMassPos(IFunctionHandler* pH) { return FGetCenterOfMassPos(this, pH); }
	int GetWorldBoundsCenter(IFunctionHandler* pH) { return FGetWorldBoundsCenter(this, pH); }
	int SetLocalPos(IFunctionHandler* pH, Vec3 vPos) { return FSetLocalPos(this, pH, vPos); }
	int GetLocalPos(IFunctionHandler* pH) { return FGetLocalPos(this, pH); }
	int SetLocalAngles(IFunctionHandler* pH, Ang3 vAngles) { return FSetLocalAngles(this, pH, vAngles); }
	int GetLocalAngles(IFunctionHandler* pH) { return FGetLocalAngles(this, pH); }
	int SetLocalScale(IFunctionHandler* pH, float fScale) { return FSetLocalScale(this, pH, fScale); }
	int GetLocalScale(IFunctionHandler* pH) { return FGetLocalScale(this, pH); }
	int SetWorldPos(IFunctionHandler* pH, Vec3 vPos) { return FSetWorldPos(this, pH, vPos); }
	int GetWorldPos(IFunctionHandler* pH) { return FGetWorldPos(this, pH); }
	int GetWorldDir(IFunctionHandler* pH) { return FGetWorldDir(this, pH); }
	int SetWorldAngles(IFunctionHandler* pH, Ang3 vAngles) { return FSetWorldAngles(this, pH, vAngles); }
	int GetWorldAngles(IFunctionHandler* pH) { return FGetWorldAngles(this, pH); }
	int SetWorldScale(IFunctionHandler* pH, float fScale) { return FSetWorldScale(this, pH, fScale); }
	int GetWorldScale(IFunctionHandler* pH) { return FGetWorldScale(this, pH); }
	int GetBoneLocal(IFunctionHandler* pH, const char* boneName, Vec3 trgDir) { return FGetBoneLocal(this, pH, boneName, trgDir); }
	int CalcWorldAnglesFromRelativeDir(IFunctionHandler* pH, Vec3 dir) { return FCalcWorldAnglesFromRelativeDir(this, pH, dir); }
	int IsEntityInside(IFunctionHandler* pH, ScriptHandle entityId) { return FIsEntityInside(this, pH, entityId); }
	int GetDistance(IFunctionHandler* pH) { return FGetDistance(this, pH); }
	int DrawSlot(IFunctionHandler* pH, int nSlot, int nEnable) { return FDrawSlot(this, pH, nSlot, nEnable); }
	int IgnorePhysicsUpdatesOnSlot(IFunctionHandler* pH, int nSlot) { return FIgnorePhysicsUpdatesOnSlot(this, pH, nSlot); }
	int FreeSlot(IFunctionHandler* pH, int nSlot) { return FFreeSlot(this, pH, nSlot); }
	int FreeAllSlots(IFunctionHandler* pH) { return FFreeAllSlots(this, pH); }
	int GetCharacter(IFunctionHandler* pH, int nSlot) { return FGetCharacter(this, pH, nSlot); }
	int DestroyPhysics(IFunctionHandler* pH) { return FDestroyPhysics(this, pH); }
	int EnablePhysics(IFunctionHandler* pH, bool bEnable) { return FEnablePhysics(this, pH, bEnable); }
	int ResetPhysics(IFunctionHandler* pH) { return FResetPhysics(this, pH); }
	int AwakePhysics(IFunctionHandler* pH, int nAwake) { return FAwakePhysics(this, pH, nAwake); }
	int AwakeCharacterPhysics(IFunctionHandler* pH, int nSlot, const char* sRootBoneName, int nAwake) { return FAwakeCharacterPhysics(this, pH, nSlot, sRootBoneName, nAwake); }
	int Physicalize(IFunctionHandler* pH, int nSlot, int nPhysicsType, SmartScriptTable physicsParams) { return FPhysicalize(this, pH, nSlot, nPhysicsType, physicsParams); }
	int SetAreaAffectsParticleEmitterPosition(IFunctionHandler* pH, int bAreaAffectsParticleEmitterPosition) { return FSetAreaAffectsParticleEmitterPosition(this, pH, bAreaAffectsParticleEmitterPosition); }
	int SetPhysicParams(IFunctionHandler* pH) { return FSetPhysicParams(this, pH); }
	int SetCharacterPhysicParams(IFunctionHandler* pH) { return FSetCharacterPhysicParams(this, pH); }
	int ActivatePlayerPhysics(IFunctionHandler* pH, bool bEnable) { return FActivatePlayerPhysics(this, pH, bEnable); }
	int ReattachSoftEntityVtx(IFunctionHandler* pH, ScriptHandle entityId, int partId) { return FReattachSoftEntityVtx(this, pH, entityId, partId); }
	int PhysicalizeSlot(IFunctionHandler* pH, int slot, SmartScriptTable physicsParams) { return FPhysicalizeSlot(this, pH, slot, physicsParams); }
	int UpdateSlotPhysics(IFunctionHandler* pH, int slot) { return FUpdateSlotPhysics(this, pH, slot); }
	int SetColliderMode(IFunctionHandler* pH, int mode) { return FSetColliderMode(this, pH, mode); }
	int SelectPipe(IFunctionHandler* pH) { return FSelectPipe(this, pH); }
	int IsUsingPipe(IFunctionHandler* pH) { return FIsUsingPipe(this, pH); }
	int Activate(IFunctionHandler* pH, int bActive) { return FActivate(this, pH, bActive); }
	int IsActive(IFunctionHandler* pH) { return FIsActive(this, pH); }
	int IsFromPool(IFunctionHandler* pH) { return FIsFromPool(this, pH); }
	int SetUpdatePolicy(IFunctionHandler* pH, int nUpdatePolicy) { return FSetUpdatePolicy(this, pH, nUpdatePolicy); }
	int SetLocalBBox(IFunctionHandler* pH, Vec3 vMin, Vec3 vMax) { return FSetLocalBBox(this, pH, vMin, vMax); }
	int GetLocalBBox(IFunctionHandler* pH) { return FGetLocalBBox(this, pH); }
	int GetWorldBBox(IFunctionHandler* pH) { return FGetWorldBBox(this, pH); }
	int GetProjectedWorldBBox(IFunctionHandler* pH) { return FGetProjectedWorldBBox(this, pH); }
	int SetTriggerBBox(IFunctionHandler* pH, Vec3 vMin, Vec3 vMax) { return FSetTriggerBBox(this, pH, vMin, vMax); }
	int GetTriggerBBox(IFunctionHandler* pH) { return FGetTriggerBBox(this, pH); }
	int InvalidateTrigger(IFunctionHandler* pH) { return FInvalidateTrigger(this, pH); }
	int ForwardTriggerEventsTo(IFunctionHandler* pH, ScriptHandle entityId) { return FForwardTriggerEventsTo(this, pH, entityId); }
	int SetUpdateRadius(IFunctionHandler* pH) { return FSetUpdateRadius(this, pH); }
	int GetUpdateRadius(IFunctionHandler* pH) { return FGetUpdateRadius(this, pH); }
	int TriggerEvent(IFunctionHandler* pH) { return FTriggerEvent(this, pH); }
	int GetHelperPos(IFunctionHandler* pH) { return FGetHelperPos(this, pH); }
	int GetHelperDir(IFunctionHandler* pH) { return FGetHelperDir(this, pH); }
	int GetHelperAngles(IFunctionHandler* pH) { return FGetHelperAngles(this, pH); }
	int GetSlotHelperPos(IFunctionHandler* pH, int slot, const char* helperName, bool objectSpace) { return FGetSlotHelperPos(this, pH, slot, helperName, objectSpace); }
	int GetBonePos(IFunctionHandler* pH) { return FGetBonePos(this, pH); }
	int GetBoneDir(IFunctionHandler* pH) { return FGetBoneDir(this, pH); }
	int GetBoneUp(IFunctionHandler* pH) { return FGetBoneUp(this, pH); }
	int GetBoneGlobal(IFunctionHandler* pH, const Vec3& _trgDir) { return FGetBoneGlobal(this, pH, _trgDir); }
	int GetBoneVelocity(IFunctionHandler* pH, int characterSlot, const char* boneName) { return FGetBoneVelocity(this, pH, characterSlot, boneName); }
	int GetBoneAngularVelocity(IFunctionHandler* pH, int characterSlot, const char* boneName) { return FGetBoneAngularVelocity(this, pH, characterSlot, boneName); }
	int GetBoneNameFromTable(IFunctionHandler* pH) { return FGetBoneNameFromTable(this, pH); }
	int SetName(IFunctionHandler* pH) { return FSetName(this, pH); }
	int GetName(IFunctionHandler* pH) { return FGetName(this, pH); }
	int GetRawId(IFunctionHandler* pH) { return FGetRawId(this, pH); }
	int SetAIName(IFunctionHandler* pH) { return FSetAIName(this, pH); }
	int GetAIName(IFunctionHandler* pH) { return FGetAIName(this, pH); }
	int SetFlags(IFunctionHandler* pH, int flags, int mode) { return FSetFlags(this, pH, flags, mode); }
	int GetFlags(IFunctionHandler* pH) { return FGetFlags(this, pH); }
	int HasFlags(IFunctionHandler* pH, int flags) { return FHasFlags(this, pH, flags); }
	int SetFlagsExtended(IFunctionHandler* pH, int flags, int mode) { return FSetFlagsExtended(this, pH, flags, mode); }
	int GetFlagsExtended(IFunctionHandler* pH) { return FGetFlagsExtended(this, pH); }
	int HasFlagsExtended(IFunctionHandler* pH, int flags) { return FHasFlagsExtended(this, pH, flags); }
	int GetArchetype(IFunctionHandler* pH) { return FGetArchetype(this, pH); }
	int IntersectRay(IFunctionHandler* pH, int slot, Vec3 rayOrigin, Vec3 rayDir, float maxDistance) { return FIntersectRay(this, pH, slot, rayOrigin, rayDir, maxDistance); }
	int AttachChild(IFunctionHandler* pH, ScriptHandle childEntityId, int flags) { return FAttachChild(this, pH, childEntityId, flags); }
	int DetachThis(IFunctionHandler* pH) { return FDetachThis(this, pH); }
	int DetachAll(IFunctionHandler* pH) { return FDetachAll(this, pH); }
	int GetParent(IFunctionHandler* pH) { return FGetParent(this, pH); }
	int GetChildCount(IFunctionHandler* pH) { return FGetChildCount(this, pH); }
	int GetChild(IFunctionHandler* pH, int nIndex) { return FGetChild(this, pH, nIndex); }
	int EnableInheritXForm(IFunctionHandler* pH, bool bEnable) { return FEnableInheritXForm(this, pH, bEnable); }
	int NetPresent(IFunctionHandler* pH) { return FNetPresent(this, pH); }
	int RenderShadow(IFunctionHandler* pH) { return FRenderShadow(this, pH); }
	int SetRegisterInSectors(IFunctionHandler* pH) { return FSetRegisterInSectors(this, pH); }
	int IsColliding(IFunctionHandler* pH) { return FIsColliding(this, pH); }
	int GetDirectionVector(IFunctionHandler* pH) { return FGetDirectionVector(this, pH); }
	int SetDirectionVector(IFunctionHandler* pH, Vec3 dir) { return FSetDirectionVector(this, pH, dir); }
	int IsAnimationRunning(IFunctionHandler* pH, int characterSlot, int layer) { return FIsAnimationRunning(this, pH, characterSlot, layer); }
	int AddImpulse(IFunctionHandler* pH) { return FAddImpulse(this, pH); }
	int AddConstraint(IFunctionHandler* pH) { return FAddConstraint(this, pH); }
	int SetPublicParam(IFunctionHandler* pH) { return FSetPublicParam(this, pH); }
	int GetAllAuxAudioProxiesID(IFunctionHandler* pH) { return FGetAllAuxAudioProxiesID(this, pH); }
	int GetDefaultAuxAudioProxyID(IFunctionHandler* pH) { return FGetDefaultAuxAudioProxyID(this, pH); }
	int CreateAuxAudioProxy(IFunctionHandler* pH) { return FCreateAuxAudioProxy(this, pH); }
	int RemoveAuxAudioProxy(IFunctionHandler* pH, const ScriptHandle hAudioProxyLocalID) { return FRemoveAuxAudioProxy(this, pH, hAudioProxyLocalID); }
	int ExecuteAudioTrigger(IFunctionHandler* pH, const ScriptHandle hTriggerID, const ScriptHandle hAudioProxyLocalID) { return FExecuteAudioTrigger(this, pH, hTriggerID, hAudioProxyLocalID); }
	int StopAudioTrigger(IFunctionHandler* pH, const ScriptHandle hTriggerID, const ScriptHandle hAudioProxyLocalID) { return FStopAudioTrigger(this, pH, hTriggerID, hAudioProxyLocalID); }
	int SetAudioSwitchState(IFunctionHandler* pH, const ScriptHandle hSwitchID, const ScriptHandle hSwitchStateID, const ScriptHandle hAudioProxyLocalID) { return FSetAudioSwitchState(this, pH, hSwitchID, hSwitchStateID, hAudioProxyLocalID); }
	int SetFadeDistance(IFunctionHandler* pH, const float fFadeDistance) { return FSetFadeDistance(this, pH, fFadeDistance); }
	int SetAudioProxyOffset(IFunctionHandler* pH, const Vec3 vOffset, const ScriptHandle hAudioProxyLocalID) { return FSetAudioProxyOffset(this, pH, vOffset, hAudioProxyLocalID); }
	int SetAudioProxyAttenuationScale(IFunctionHandler* pH, const float _fScale, const ScriptHandle _hAudioProxyLocalID) { return FSetAudioProxyAttenuationScale(this, pH, _fScale, _hAudioProxyLocalID); }
	int SetEnvironmentFadeDistance(IFunctionHandler* pH, const float fEnvironmentFadeDistance) { return FSetEnvironmentFadeDistance(this, pH, fEnvironmentFadeDistance); }
	int SetAudioEnvironmentID(IFunctionHandler* pH, const ScriptHandle hAudioEnvironmentID) { return FSetAudioEnvironmentID(this, pH, hAudioEnvironmentID); }
	int SetCurrentAudioEnvironments(IFunctionHandler* pH) { return FSetCurrentAudioEnvironments(this, pH); }
	int SetAudioRtpcValue(IFunctionHandler* pH, const ScriptHandle hRtpcID, const float fValue, const ScriptHandle hAudioProxyLocalID) { return FSetAudioRtpcValue(this, pH, hRtpcID, fValue, hAudioProxyLocalID); }
	int SetGeomCachePlaybackTime(IFunctionHandler* pH, float time) { return FSetGeomCachePlaybackTime(this, pH, time); }
	int SetGeomCacheParams(IFunctionHandler* pH, bool looping, const char* standIn, const char* standInMaterial, const char* firstFrameStandIn, const char* firstFrameStandInMaterial, const char* lastFrameStandIn, const char* lastFrameStandInMaterial, float standInDistance, float streamInDistance) { return FSetGeomCacheParams(this, pH, looping, standIn, standInMaterial, firstFrameStandIn, firstFrameStandInMaterial, lastFrameStandIn, lastFrameStandInMaterial, standInDistance, streamInDistance); }
	int SetGeomCacheStreaming(IFunctionHandler* pH, bool active, float time) { return FSetGeomCacheStreaming(this, pH, active, time); }
	int IsGeomCacheStreaming(IFunctionHandler* pH) { return FIsGeomCacheStreaming(this, pH); }
	int GetGeomCachePrecachedTime(IFunctionHandler* pH) { return FGetGeomCachePrecachedTime(this, pH); }
	int SetGeomCacheDrawing(IFunctionHandler* pH, bool active) { return FSetGeomCacheDrawing(this, pH, active); }
	int SetGeomCacheSortOffset(IFunctionHandler* pH, float _sortOffset) { return FSetGeomCacheSortOffset(this, pH, _sortOffset); }
	int StartAnimation(IFunctionHandler* pH) { return FStartAnimation(this, pH); }
	int StopAnimation(IFunctionHandler* pH, int characterSlot, int layer) { return FStopAnimation(this, pH, characterSlot, layer); }
	int ResetAnimation(IFunctionHandler* pH, int characterSlot, int layer) { return FResetAnimation(this, pH, characterSlot, layer); }
	int RedirectAnimationToLayer0(IFunctionHandler* pH, int characterSlot, bool redirect) { return FRedirectAnimationToLayer0(this, pH, characterSlot, redirect); }
	int SetAnimationBlendOut(IFunctionHandler* pH, int characterSlot, int layer, float blendOut) { return FSetAnimationBlendOut(this, pH, characterSlot, layer, blendOut); }
	int EnableBoneAnimation(IFunctionHandler* pH, int characterSlot, int layer, const char* boneName, bool status) { return FEnableBoneAnimation(this, pH, characterSlot, layer, boneName, status); }
	int EnableBoneAnimationAll(IFunctionHandler* pH, int characterSlot, int layer, bool status) { return FEnableBoneAnimationAll(this, pH, characterSlot, layer, status); }
	int EnableProceduralFacialAnimation(IFunctionHandler* pH, bool enable) { return FEnableProceduralFacialAnimation(this, pH, enable); }
	int PlayFacialAnimation(IFunctionHandler* pH, char* name, bool looping) { return FPlayFacialAnimation(this, pH, name, looping); }
	int SetAnimationEvent(IFunctionHandler* pH, int nSlot, const char* sAnimation) { return FSetAnimationEvent(this, pH, nSlot, sAnimation); }
	int SetAnimationKeyEvent(IFunctionHandler* pH) { return FSetAnimationKeyEvent(this, pH); }
	int DisableAnimationEvent(IFunctionHandler* pH, int nSlot, const char* sAnimation) { return FDisableAnimationEvent(this, pH, nSlot, sAnimation); }
	int SetAnimationSpeed(IFunctionHandler* pH, int characterSlot, int layer, float speed) { return FSetAnimationSpeed(this, pH, characterSlot, layer, speed); }
	int SetAnimationTime(IFunctionHandler* pH, int nSlot, int nLayer, float fNormalizedTime) { return FSetAnimationTime(this, pH, nSlot, nLayer, fNormalizedTime); }
	int GetAnimationTime(IFunctionHandler* pH, int nSlot, int nLayer) { return FGetAnimationTime(this, pH, nSlot, nLayer); }
	int GetNumQueuedAnimations(IFunctionHandler* pH, int nSlot, int nLayer) { return FGetNumQueuedAnimations(this, pH, nSlot, nLayer); }
	int GetCurAnimation(IFunctionHandler* pH) { return FGetCurAnimation(this, pH); }
	int GetAnimationLength(IFunctionHandler* pH, int characterSlot, const char* animation) { return FGetAnimationLength(this, pH, characterSlot, animation); }
	int SetAnimationFlip(IFunctionHandler* pH, int characterSlot, Vec3 flip) { return FSetAnimationFlip(this, pH, characterSlot, flip); }
	int SetTimer(IFunctionHandler* pH) { return FSetTimer(this, pH); }
	int KillTimer(IFunctionHandler* pH) { return FKillTimer(this, pH); }
	int SetScriptUpdateRate(IFunctionHandler* pH, int nMillis) { return FSetScriptUpdateRate(this, pH, nMillis); }
	int GotoState(IFunctionHandler* pH, const char* sStateName) { return FGotoState(this, pH, sStateName); }
	int IsInState(IFunctionHandler* pH, const char* sStateName) { return FIsInState(this, pH, sStateName); }
	int GetState(IFunctionHandler* pH) { return FGetState(this, pH); }
	int IsHidden(IFunctionHandler* pH) { return FIsHidden(this, pH); }
	int GetTouchedSurfaceID(IFunctionHandler* pH) { return FGetTouchedSurfaceID(this, pH); }
	int GetTouchedPoint(IFunctionHandler* pH) { return FGetTouchedPoint(this, pH); }
	int CreateBoneAttachment(IFunctionHandler* pH, int characterSlot, const char* boneName, const char* attachmentName) { return FCreateBoneAttachment(this, pH, characterSlot, boneName, attachmentName); }
	int CreateSkinAttachment(IFunctionHandler* pH, int characterSlot, const char* attachmentName) { return FCreateSkinAttachment(this, pH, characterSlot, attachmentName); }
	int DestroyAttachment(IFunctionHandler* pH, int characterSlot, const char* attachmentName) { return FDestroyAttachment(this, pH, characterSlot, attachmentName); }
	int GetAttachmentBone(IFunctionHandler* pH, int characterSlot, const char* attachmentName) { return FGetAttachmentBone(this, pH, characterSlot, attachmentName); }
	int GetAttachmentCGF(IFunctionHandler* pH, int characterSlot, const char* attachmentName) { return FGetAttachmentCGF(this, pH, characterSlot, attachmentName); }
	int ResetAttachment(IFunctionHandler* pH, int characterSlot, const char* attachmentName) { return FResetAttachment(this, pH, characterSlot, attachmentName); }
	int SetAttachmentEffect(IFunctionHandler* pH, int characterSlot, const char* attachmentName, const char* effectName, Vec3 offset, Vec3 dir, float scale, int flags) { return FSetAttachmentEffect(this, pH, characterSlot, attachmentName, effectName, offset, dir, scale, flags); }
	int SetAttachmentObject(IFunctionHandler* pH, int characterSlot, const char* attachmentName, ScriptHandle entityId, int slot, int flags) { return FSetAttachmentObject(this, pH, characterSlot, attachmentName, entityId, slot, flags); }
	int SetAttachmentCGF(IFunctionHandler* pH, int characterSlot, const char* attachmentName, const char* filePath) { return FSetAttachmentCGF(this, pH, characterSlot, attachmentName, filePath); }
	int SetAttachmentLight(IFunctionHandler* pH, int characterSlot, const char* attachmentName, SmartScriptTable lightTable, int flags) { return FSetAttachmentLight(this, pH, characterSlot, attachmentName, lightTable, flags); }
	int SetAttachmentPos(IFunctionHandler* pH, int characterSlot, const char* attachmentName, Vec3 pos) { return FSetAttachmentPos(this, pH, characterSlot, attachmentName, pos); }
	int SetAttachmentAngles(IFunctionHandler* pH, int characterSlot, const char* attachmentName, Vec3 angles) { return FSetAttachmentAngles(this, pH, characterSlot, attachmentName, angles); }
	int SetAttachmentDir(IFunctionHandler* pH, int characterSlot, const char* attachmentName, Vec3 dir, bool worldSpace) { return FSetAttachmentDir(this, pH, characterSlot, attachmentName, dir, worldSpace); }
	int HideAttachment(IFunctionHandler* pH, int characterSlot, const char* attachmentName, bool hide, bool hideShadow) { return FHideAttachment(this, pH, characterSlot, attachmentName, hide, hideShadow); }
	int HideAllAttachments(IFunctionHandler* pH, int characterSlot, bool hide, bool hideShadow) { return FHideAllAttachments(this, pH, characterSlot, hide, hideShadow); }
	int HideAttachmentMaster(IFunctionHandler* pH, int characterSlot, bool hide) { return FHideAttachmentMaster(this, pH, characterSlot, hide); }
	int PhysicalizeAttachment(IFunctionHandler* pH, int characterSlot, const char* attachmentName, bool physicalize) { return FPhysicalizeAttachment(this, pH, characterSlot, attachmentName, physicalize); }
	int Damage(IFunctionHandler* pH) { return FDamage(this, pH); }
	int GetExplosionObstruction(IFunctionHandler* pH) { return FGetExplosionObstruction(this, pH); }
	int GetExplosionImpulse(IFunctionHandler* pH) { return FGetExplosionImpulse(this, pH); }
	int SetMaterial(IFunctionHandler* pH) { return FSetMaterial(this, pH); }
	int GetMaterial(IFunctionHandler* pH) { return FGetMaterial(this, pH); }
	int GetEntityMaterial(IFunctionHandler* pH) { return FGetEntityMaterial(this, pH); }
	int ChangeAttachmentMaterial(IFunctionHandler* pH, const char* attachmentName, const char* materialName) { return FChangeAttachmentMaterial(this, pH, attachmentName, materialName); }
	int CloneAttachmentMaterial(IFunctionHandler* _pH, int _characterSlot, const char* _attachmentName) { return FCloneAttachmentMaterial(this, _pH, _characterSlot, _attachmentName); }
	int SetAttachmentMaterialFloat(IFunctionHandler* pH, int _characterSlot, const char* _attachmentName, int _nSubMtlId, int _nParam, float _fValue) { return FSetAttachmentMaterialFloat(this, pH, _characterSlot, _attachmentName, _nSubMtlId, _nParam, _fValue); }
	int SetAttachmentMaterialVec3(IFunctionHandler* pH, int _characterSlot, const char* _attachmentName, int _nSubMtlId, int _nParam, Vec3 _vValue) { return FSetAttachmentMaterialVec3(this, pH, _characterSlot, _attachmentName, _nSubMtlId, _nParam, _vValue); }
	int GetAttachmentMaterialVec3(IFunctionHandler* pH, int _characterSlot, const char* _attachmentName, int _nSubMtlId, int _nParam) { return FGetAttachmentMaterialVec3(this, pH, _characterSlot, _attachmentName, _nSubMtlId, _nParam); }
	int ReplaceMaterial(IFunctionHandler* pH, int slot, const char* name, const char* replacement) { return FReplaceMaterial(this, pH, slot, name, replacement); }
	int ResetMaterial(IFunctionHandler* pH, int slot) { return FResetMaterial(this, pH, slot); }
	int EnableMaterialLayer(IFunctionHandler* pH, bool enable, int layer) { return FEnableMaterialLayer(this, pH, enable, layer); }
	int CloneMaterial(IFunctionHandler* pH, int slot) { return FCloneMaterial(this, pH, slot); }
	int SetMaterialFloat(IFunctionHandler* pH, int slot, int nSubMtlId, int _nParam, float fValue) { return FSetMaterialFloat(this, pH, slot, nSubMtlId, _nParam, fValue); }
	int GetMaterialFloat(IFunctionHandler* pH, int slot, int nSubMtlId, int _nParam) { return FGetMaterialFloat(this, pH, slot, nSubMtlId, _nParam); }
	int SetMaterialVec3(IFunctionHandler* pH, int slot, int nSubMtlId, int _nParam, Vec3 vValue) { return FSetMaterialVec3(this, pH, slot, nSubMtlId, _nParam, vValue); }
	int GetMaterialVec3(IFunctionHandler* pH, int slot, int nSubMtlId, int _nParam) { return FGetMaterialVec3(this, pH, slot, nSubMtlId, _nParam); }
	int MaterialFlashInvoke(IFunctionHandler* pH) { return FMaterialFlashInvoke(this, pH); }
	int ToLocal(IFunctionHandler* pH, int slotId, Vec3 point) { return FToLocal(this, pH, slotId, point); }
	int ToGlobal(IFunctionHandler* pH, int slotId, Vec3 point) { return FToGlobal(this, pH, slotId, point); }
	int VectorToLocal(IFunctionHandler* pH, int slotId, Vec3 dir) { return FVectorToLocal(this, pH, slotId, dir); }
	int VectorToGlobal(IFunctionHandler* pH, int slotId, Vec3 dir) { return FVectorToGlobal(this, pH, slotId, dir); }
	int CheckCollisions(IFunctionHandler* pH) { return FCheckCollisions(this, pH); }
	int AwakeEnvironment(IFunctionHandler* pH) { return FAwakeEnvironment(this, pH); }
	int GetTimeSinceLastSeen(IFunctionHandler* pH) { return FGetTimeSinceLastSeen(this, pH); }
	int GetViewDistRatio(IFunctionHandler* pH) { return FGetViewDistRatio(this, pH); }
	int SetViewDistRatio(IFunctionHandler* pH) { return FSetViewDistRatio(this, pH); }
	int SetViewDistUnlimited(IFunctionHandler* pH) { return FSetViewDistUnlimited(this, pH); }
	int SetLodRatio(IFunctionHandler* pH) { return FSetLodRatio(this, pH); }
	int GetLodRatio(IFunctionHandler* pH) { return FGetLodRatio(this, pH); }
	int SetStateClientside(IFunctionHandler* pH) { return FSetStateClientside(this, pH); }
	int InsertSubpipe(IFunctionHandler* pH) { return FInsertSubpipe(this, pH); }
	int CancelSubpipe(IFunctionHandler* pH) { return FCancelSubpipe(this, pH); }
	int PassParamsToPipe(IFunctionHandler* pH) { return FPassParamsToPipe(this, pH); }
	int SetDefaultIdleAnimations(IFunctionHandler* pH) { return FSetDefaultIdleAnimations(this, pH); }
	int GetVelocity(IFunctionHandler* pH) { return FGetVelocity(this, pH); }
	int GetVelocityEx(IFunctionHandler* pH) { return FGetVelocityEx(this, pH); }
	int SetVelocity(IFunctionHandler* pH, Vec3 velocity) { return FSetVelocity(this, pH, velocity); }
	int SetVelocityEx(IFunctionHandler* pH, Vec3 velocity, Vec3 angularVelocity) { return FSetVelocityEx(this, pH, velocity, angularVelocity); }
	int GetSpeed(IFunctionHandler* pH) { return FGetSpeed(this, pH); }
	int GetMass(IFunctionHandler* pH) { return FGetMass(this, pH); }
	int GetVolume(IFunctionHandler* pH, int slot) { return FGetVolume(this, pH, slot); }
	int GetGravity(IFunctionHandler* pH) { return FGetGravity(this, pH); }
	int GetSubmergedVolume(IFunctionHandler* pH, int slot, Vec3 planeNormal, Vec3 planeOrigin) { return FGetSubmergedVolume(this, pH, slot, planeNormal, planeOrigin); }
	int CreateLink(IFunctionHandler* pH, const char* name) { return FCreateLink(this, pH, name); }
	int GetLinkName(IFunctionHandler* pH, ScriptHandle targetId) { return FGetLinkName(this, pH, targetId); }
	int SetLinkTarget(IFunctionHandler* pH, const char* name, ScriptHandle targetId) { return FSetLinkTarget(this, pH, name, targetId); }
	int GetLinkTarget(IFunctionHandler* pH, const char* name) { return FGetLinkTarget(this, pH, name); }
	int RemoveLink(IFunctionHandler* pH, const char* name) { return FRemoveLink(this, pH, name); }
	int RemoveAllLinks(IFunctionHandler* pH) { return FRemoveAllLinks(this, pH); }
	int GetLink(IFunctionHandler* pH, int ith) { return FGetLink(this, pH, ith); }
	int CountLinks(IFunctionHandler* pH) { return FCountLinks(this, pH); }
	int RemoveDecals(IFunctionHandler* pH) { return FRemoveDecals(this, pH); }
	int EnableDecals(IFunctionHandler* pH, int slot, bool enable) { return FEnableDecals(this, pH, slot, enable); }
	int ForceCharacterUpdate(IFunctionHandler* pH, int characterSlot, bool updateAlways) { return FForceCharacterUpdate(this, pH, characterSlot, updateAlways); }
	int CharacterUpdateAlways(IFunctionHandler* pH, int characterSlot, bool updateAlways) { return FCharacterUpdateAlways(this, pH, characterSlot, updateAlways); }
	int CharacterUpdateOnRender(IFunctionHandler* pH, int characterSlot, bool bUpdateOnRender) { return FCharacterUpdateOnRender(this, pH, characterSlot, bUpdateOnRender); }
	int SetAnimateOffScreenShadow(IFunctionHandler* pH, bool bAnimateOffScreenShadow) { return FSetAnimateOffScreenShadow(this, pH, bAnimateOffScreenShadow); }
	int RagDollize(IFunctionHandler* pH, int slot) { return FRagDollize(this, pH, slot); }
	int Hide(IFunctionHandler* pH) { return FHide(this, pH); }
	int NoExplosionCollision(IFunctionHandler* pH) { return FNoExplosionCollision(this, pH); }
	int NoBulletForce(IFunctionHandler* pH, bool state) { return FNoBulletForce(this, pH, state); }
	int UpdateAreas(IFunctionHandler* pH) { return FUpdateAreas(this, pH); }
	int IsPointInsideArea(IFunctionHandler* pH, int areaId, Vec3 point) { return FIsPointInsideArea(this, pH, areaId, point); }
	int IsEntityInsideArea(IFunctionHandler* pH, int areaId, ScriptHandle entityId) { return FIsEntityInsideArea(this, pH, areaId, entityId); }
	int GetPhysicalStats(IFunctionHandler* pH) { return FGetPhysicalStats(this, pH); }
	int SetParentSlot(IFunctionHandler* pH, int child, int parent) { return FSetParentSlot(this, pH, child, parent); }
	int GetParentSlot(IFunctionHandler* pH, int child) { return FGetParentSlot(this, pH, child); }
	int BreakToPieces(IFunctionHandler* pH, int nSlot, int nPiecesSlot, float fExplodeImp, Vec3 vHitPt, Vec3 vHitImp, float fLifeTime, bool bMaterialEffects) { return FBreakToPieces(this, pH, nSlot, nPiecesSlot, fExplodeImp, vHitPt, vHitImp, fLifeTime, bMaterialEffects); }
	int AttachSurfaceEffect(IFunctionHandler* pH, int nSlot, const char* effect, bool countPerUnit, const char* form, const char* typ, float countScale, float sizeScale) { return FAttachSurfaceEffect(this, pH, nSlot, effect, countPerUnit, form, typ, countScale, sizeScale); }
	int ProcessBroadcastEvent(IFunctionHandler* pH) { return FProcessBroadcastEvent(this, pH); }
	int ActivateOutput(IFunctionHandler* pH) { return FActivateOutput(this, pH); }
	int CreateCameraProxy(IFunctionHandler* pH) { return FCreateCameraProxy(this, pH); }
	int UnSeenFrames(IFunctionHandler* pH) { return FUnSeenFrames(this, pH); }
	int DeleteParticleEmitter(IFunctionHandler* pH, int slot) { return FDeleteParticleEmitter(this, pH, slot); }
	int RegisterForAreaEvents(IFunctionHandler* pH, int enable) { return FRegisterForAreaEvents(this, pH, enable); }
	int RenderAlways(IFunctionHandler* pH, int enable) { return FRenderAlways(this, pH, enable); }
	int GetTimeOfDayHour(IFunctionHandler* pH) { return FGetTimeOfDayHour(this, pH); }
	int GetAttachmentPos(IFunctionHandler* pH, const char* _attachmentName) { return FGetAttachmentPos(this, pH, _attachmentName); }
	int SetDisplayName(IFunctionHandler* const _pH, const char* _pName) { return FSetDisplayName(this, _pH, _pName); }
	int GetDisplayName(IFunctionHandler* const _pH) { return FGetDisplayName(this, _pH); }
	int SetAsSceneWindow(IFunctionHandler* pH, bool _bIsSceneWindow) { return FSetAsSceneWindow(this, pH, _bIsSceneWindow); }
	int SetEntireMaterialFloat(IFunctionHandler* const pH, const int _slot, const char* const _paramName, float _value) { return FSetEntireMaterialFloat(this, pH, _slot, _paramName, _value); }
	int RenderBeginMorphingSwipe(IFunctionHandler* pH, int nSlot, int nEnable, float time) { return FRenderBeginMorphingSwipe(this, pH, nSlot, nEnable, time); }
	IEntity* GetEntity(IFunctionHandler* pH) { return FGetEntity(this, pH); }
	int SetEntityPhysicParams(IFunctionHandler* pH, IPhysicalEntity* pe, int nType, IScriptTable* pTable, ICharacterInstance* pIChar) { return FSetEntityPhysicParams(this, pH, pe, nType, pTable, pIChar); }
	bool ParseLightParams(IScriptTable* pLightTable, IEntity* pEntity, CDLight& light) { return FParseLightParams(this, pLightTable, pEntity, light); }
	bool ParseFogVolumesParams(IScriptTable* pTable, IEntity* pEntity, SFogVolumeProperties& properties) { return FParseFogVolumesParams(this, pTable, pEntity, properties); }
	bool ParseVolumeObjectMovementProperties(IScriptTable* pTable, IEntity* pEntity, SVolumeObjectMovementProperties& properties) { return FParseVolumeObjectMovementProperties(this, pTable, pEntity, properties); }
	bool ParsePhysicsParams(IScriptTable* pTable, SEntityPhysicalizeParams& params) { return FParsePhysicsParams(this, pTable, params); }
	static int cmpIntersectionResult(const void* v1, const void* v2) { return FcmpIntersectionResult(v1, v2); }
	static void OnAudioTriggerFinishedEvent(const SAudioRequestInfo* const pAudioRequestInfo) { FOnAudioTriggerFinishedEvent(pAudioRequestInfo); }
	int IStatObjRayIntersect(IStatObj* pStatObj, const Vec3& rayOrigin, const Vec3& rayDir, float maxDistance, CScriptBind_Entity::SIntersectionResult* pOutResult, unsigned maxResults) { return FIStatObjRayIntersect(this, pStatObj, rayOrigin, rayDir, maxDistance, pOutResult, maxResults); }

#if 0
	int GetEntitiesInContact(IFunctionHandler* _arg0_);
	int GetAttachmentMaterialFloat(IFunctionHandler* _arg0_, int _arg1_, const char* _arg2_, int _arg3_, int _arg4_);
	Vec3 GetGlobalGravity() const;
	unsigned GetEntityID(IScriptTable* _arg0_);
	bool ReadParticleTable(IScriptTable* _arg0_, ParticleParams& _arg1_);
#endif

	static inline auto FCScriptBind_EntityOv1 = PreyFunction<void(CScriptBind_Entity* const _this, IScriptSystem* pSS, ISystem* pSystem, IEntitySystem* pEntitySystem)>(0x9341A0);
	static inline auto FDelegateCalls = PreyFunction<void(CScriptBind_Entity* const _this, IScriptTable* pInstanceTable)>(0x93FDA0);
	static inline auto FGoalParamsHelper = PreyFunction<void(CScriptBind_Entity* const _this, IFunctionHandler* pH, unsigned index, GoalParams& node)>(0x94A480);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CScriptBind_Entity* const _this, ICrySizer* pSizer)>(0x947370);
	static inline auto FDeleteThis = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93FE60);
	static inline auto FCreateRenderProxy = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93FC80);
	static inline auto FCheckShaderParamCallbacks = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x75CBB0);
	static inline auto FLoadObject = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* sFilename)>(0x94E5B0);
	static inline auto FLoadObjectWithFlags = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* sFilename, const int loadFlags)>(0x94E860);
	static inline auto FLoadObjectLattice = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x94E730);
	static inline auto FLoadSubObject = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* sFilename, const char* sGeomName)>(0x94F570);
	static inline auto FLoadCharacter = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* sFilename)>(0x94E0C0);
	static inline auto FLoadGeomCache = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* sFilename)>(0x94E370);
	static inline auto FLoadLight = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, SmartScriptTable table)>(0x94E460);
	static inline auto FSetLightColorParams = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, Vec3 color, float specular_multiplier)>(0x95E6B0);
	static inline auto FUpdateLightClipBounds = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x9626C0);
	static inline auto FSetSelfAsLightCasterException = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nLightSlot)>(0x95F820);
	static inline auto FLoadCloud = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* sFilename)>(0x94E1B0);
	static inline auto FSetCloudMovementProperties = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, SmartScriptTable table)>(0x959F30);
	static inline auto FLoadFogVolume = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, SmartScriptTable table)>(0x94E250);
	static inline auto FFadeGlobalDensity = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, float fadeTime, float newGlobalDensity)>(0x941DA0);
	static inline auto FLoadVolumeObject = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* sFilename)>(0x94F670);
	static inline auto FSetVolumeObjectMovementProperties = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, SmartScriptTable table)>(0x9612C0);
	static inline auto FLoadParticleEffect = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* sEffectName, SmartScriptTable table)>(0x94E9E0);
	static inline auto FPreLoadParticleEffect = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const char* sEffectName)>(0x956210);
	static inline auto FIsSlotParticleEmitter = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot)>(0x94DC90);
	static inline auto FIsSlotLight = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot)>(0x94DB70);
	static inline auto FIsSlotGeometry = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot)>(0x94DA50);
	static inline auto FIsSlotCharacter = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot)>(0x94D930);
	static inline auto FGetSlotCount = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x948890);
	static inline auto FGetSlotPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x948C80);
	static inline auto FSetSlotPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, Vec3 vPos)>(0x95FF10);
	static inline auto FSetSlotPosAndDir = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, Vec3 pos, Vec3 dir)>(0x960020);
	static inline auto FGetSlotAngles = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x9485A0);
	static inline auto FSetSlotAngles = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, Ang3 vAngles)>(0x95F930);
	static inline auto FSetSlotAnglesDeg = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, Vec3 vAnglesDeg)>(0x95FC10);
	static inline auto FGetSlotScale = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x948D30);
	static inline auto FSetSlotScale = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, float fScale)>(0x960250);
	static inline auto FIsSlotValid = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x94DDB0);
	static inline auto FCopySlotTM = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int destSlot, int srcSlot, bool includeTranslation)>(0x93F5D0);
	static inline auto FMultiplyWithSlotTM = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot, Vec3 pos)>(0x94FCF0);
	static inline auto FSetSlotWorldTM = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, Vec3 pos, Vec3 dir)>(0x9604D0);
	static inline auto FGetSlotWorldPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x948E10);
	static inline auto FGetSlotWorldDir = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x948E10);
	static inline auto FSetSlotHud3D = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x75CBB0);
	static inline auto FSetPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Vec3 vPos)>(0x9616E0);
	static inline auto FGetPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x947C30);
	static inline auto FSetAngles = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Ang3 vAngles)>(0x957CF0);
	static inline auto FGetAngles = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x942290);
	static inline auto FSetScale = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, float fScale)>(0x95F760);
	static inline auto FGetScale = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x946BB0);
	static inline auto FGetCenterOfMassPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x943D40);
	static inline auto FGetWorldBoundsCenter = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94A2E0);
	static inline auto FSetLocalPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Vec3 vPos)>(0x95EB10);
	static inline auto FGetLocalPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x946B40);
	static inline auto FSetLocalAngles = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Ang3 vAngles)>(0x95E8E0);
	static inline auto FGetLocalAngles = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9465F0);
	static inline auto FSetLocalScale = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, float fScale)>(0x9617E0);
	static inline auto FGetLocalScale = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x946BB0);
	static inline auto FSetWorldPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Vec3 vPos)>(0x9616E0);
	static inline auto FGetWorldPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x947C30);
	static inline auto FGetWorldDir = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94A410);
	static inline auto FSetWorldAngles = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Ang3 vAngles)>(0x9613D0);
	static inline auto FGetWorldAngles = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94A140);
	static inline auto FSetWorldScale = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, float fScale)>(0x9617E0);
	static inline auto FGetWorldScale = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x946BB0);
	static inline auto FGetBoneLocal = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const char* boneName, Vec3 trgDir)>(0x9431E0);
	static inline auto FCalcWorldAnglesFromRelativeDir = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Vec3 dir)>(0x93D540);
	static inline auto FIsEntityInside = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x94C8C0);
	static inline auto FGetDistance = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x944440);
	static inline auto FDrawSlot = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, int nEnable)>(0x941800);
	static inline auto FIgnorePhysicsUpdatesOnSlot = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x94B450);
	static inline auto FFreeSlot = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x942070);
	static inline auto FFreeAllSlots = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x941FA0);
	static inline auto FGetCharacter = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot)>(0x943E60);
	static inline auto FDestroyPhysics = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93FF60);
	static inline auto FEnablePhysics = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, bool bEnable)>(0x941A40);
	static inline auto FResetPhysics = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x957770);
	static inline auto FAwakePhysics = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nAwake)>(0x93D3D0);
	static inline auto FAwakeCharacterPhysics = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* sRootBoneName, int nAwake)>(0x93D0F0);
	static inline auto FPhysicalize = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, int nPhysicsType, SmartScriptTable physicsParams)>(0x955C10);
	static inline auto FSetAreaAffectsParticleEmitterPosition = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int bAreaAffectsParticleEmitterPosition)>(0x957FF0);
	static inline auto FSetPhysicParams = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x95F070);
	static inline auto FSetCharacterPhysicParams = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x959BF0);
	static inline auto FActivatePlayerPhysics = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, bool bEnable)>(0x93B840);
	static inline auto FReattachSoftEntityVtx = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, ScriptHandle entityId, int partId)>(0x956B90);
	static inline auto FPhysicalizeSlot = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot, SmartScriptTable physicsParams)>(0x955EC0);
	static inline auto FUpdateSlotPhysics = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot)>(0x9627B0);
	static inline auto FSetColliderMode = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int mode)>(0x959FC0);
	static inline auto FSelectPipe = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9577D0);
	static inline auto FIsUsingPipe = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94DE60);
	static inline auto FActivate = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int bActive)>(0x93B4C0);
	static inline auto FIsActive = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94C650);
	static inline auto FIsFromPool = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94D480);
	static inline auto FSetUpdatePolicy = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nUpdatePolicy)>(0x960EF0);
	static inline auto FSetLocalBBox = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Vec3 vMin, Vec3 vMax)>(0x95EA80);
	static inline auto FGetLocalBBox = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x946860);
	static inline auto FGetWorldBBox = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94A1E0);
	static inline auto FGetProjectedWorldBBox = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x947CA0);
	static inline auto FSetTriggerBBox = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Vec3 vMin, Vec3 vMax)>(0x960DB0);
	static inline auto FGetTriggerBBox = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9499E0);
	static inline auto FInvalidateTrigger = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94C500);
	static inline auto FForwardTriggerEventsTo = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x941F40);
	static inline auto FSetUpdateRadius = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x960F30);
	static inline auto FGetUpdateRadius = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x949B40);
	static inline auto FTriggerEvent = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9623C0);
	static inline auto FGetHelperPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9459D0);
	static inline auto FGetHelperDir = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x945610);
	static inline auto FGetHelperAngles = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x944ED0);
	static inline auto FGetSlotHelperPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot, const char* helperName, bool objectSpace)>(0x948930);
	static inline auto FGetBonePos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x943940);
	static inline auto FGetBoneDir = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x942E50);
	static inline auto FGetBoneUp = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x943BA0);
	static inline auto FGetBoneGlobal = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const Vec3& _trgDir)>(0x942E90);
	static inline auto FGetBoneVelocity = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* boneName)>(0x943BD0);
	static inline auto FGetBoneAngularVelocity = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* boneName)>(0x942CE0);
	static inline auto FGetBoneNameFromTable = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9437D0);
	static inline auto FSetName = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x95EF30);
	static inline auto FGetName = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9473F0);
	static inline auto FGetRawId = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9484B0);
	static inline auto FSetAIName = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x957BF0);
	static inline auto FGetAIName = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x942110);
	static inline auto FSetFlags = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int flags, int mode)>(0x95E280);
	static inline auto FGetFlags = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x944B30);
	static inline auto FHasFlags = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int flags)>(0x94AA20);
	static inline auto FSetFlagsExtended = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int flags, int mode)>(0x95E300);
	static inline auto FGetFlagsExtended = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x944BD0);
	static inline auto FHasFlagsExtended = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int flags)>(0x94AAD0);
	static inline auto FGetArchetype = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x942720);
	static inline auto FIntersectRay = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot, Vec3 rayOrigin, Vec3 rayDir, float maxDistance)>(0x94B830);
	static inline auto FAttachChild = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, ScriptHandle childEntityId, int flags)>(0x93CDF0);
	static inline auto FDetachThis = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9400E0);
	static inline auto FDetachAll = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x940020);
	static inline auto FGetParent = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9475D0);
	static inline auto FGetChildCount = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x943FB0);
	static inline auto FGetChild = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nIndex)>(0x943F10);
	static inline auto FEnableInheritXForm = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, bool bEnable)>(0x941960);
	static inline auto FNetPresent = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94FE50);
	static inline auto FRenderShadow = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9570B0);
	static inline auto FSetRegisterInSectors = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x95F690);
	static inline auto FIsColliding = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94C7E0);
	static inline auto FGetDirectionVector = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9441A0);
	static inline auto FSetDirectionVector = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Vec3 dir)>(0x95A230);
	static inline auto FIsAnimationRunning = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, int layer)>(0x94C6F0);
	static inline auto FAddImpulse = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93C670);
	static inline auto FAddConstraint = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93B950);
	static inline auto FSetPublicParam = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x95F220);
	static inline auto FGetAllAuxAudioProxiesID = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x942220);
	static inline auto FGetDefaultAuxAudioProxyID = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x944130);
	static inline auto FCreateAuxAudioProxy = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93F7E0);
	static inline auto FRemoveAuxAudioProxy = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const ScriptHandle hAudioProxyLocalID)>(0x956D40);
	static inline auto FExecuteAudioTrigger = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const ScriptHandle hTriggerID, const ScriptHandle hAudioProxyLocalID)>(0x941BD0);
	static inline auto FStopAudioTrigger = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const ScriptHandle hTriggerID, const ScriptHandle hAudioProxyLocalID)>(0x961FC0);
	static inline auto FSetAudioSwitchState = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const ScriptHandle hSwitchID, const ScriptHandle hSwitchStateID, const ScriptHandle hAudioProxyLocalID)>(0x959A60);
	static inline auto FSetFadeDistance = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const float fFadeDistance)>(0x95E130);
	static inline auto FSetAudioProxyOffset = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const Vec3 vOffset, const ScriptHandle hAudioProxyLocalID)>(0x959780);
	static inline auto FSetAudioProxyAttenuationScale = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const float _fScale, const ScriptHandle _hAudioProxyLocalID)>(0x959640);
	static inline auto FSetEnvironmentFadeDistance = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const float fEnvironmentFadeDistance)>(0x95E010);
	static inline auto FSetAudioEnvironmentID = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const ScriptHandle hAudioEnvironmentID)>(0x959290);
	static inline auto FSetCurrentAudioEnvironments = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x95A030);
	static inline auto FSetAudioRtpcValue = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const ScriptHandle hRtpcID, const float fValue, const ScriptHandle hAudioProxyLocalID)>(0x959900);
	static inline auto FSetGeomCachePlaybackTime = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, float time)>(0x95E500);
	static inline auto FSetGeomCacheParams = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, bool looping, const char* standIn, const char* standInMaterial, const char* firstFrameStandIn, const char* firstFrameStandInMaterial, const char* lastFrameStandIn, const char* lastFrameStandInMaterial, float standInDistance, float streamInDistance)>(0x95E3E0);
	static inline auto FSetGeomCacheStreaming = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, bool active, float time)>(0x95E5C0);
	static inline auto FIsGeomCacheStreaming = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94D520);
	static inline auto FGetGeomCachePrecachedTime = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x944C70);
	static inline auto FSetGeomCacheDrawing = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, bool active)>(0x95E380);
	static inline auto FSetGeomCacheSortOffset = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, float _sortOffset)>(0x95E560);
	static inline auto FStartAnimation = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x961840);
	static inline auto FStopAnimation = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, int layer)>(0x961F40);
	static inline auto FResetAnimation = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, int layer)>(0x957540);
	static inline auto FRedirectAnimationToLayer0 = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, bool redirect)>(0x9418C0);
	static inline auto FSetAnimationBlendOut = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, int layer, float blendOut)>(0x9418C0);
	static inline auto FEnableBoneAnimation = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, int layer, const char* boneName, bool status)>(0x9418C0);
	static inline auto FEnableBoneAnimationAll = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, int layer, bool status)>(0x9418C0);
	static inline auto FEnableProceduralFacialAnimation = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, bool enable)>(0x941B70);
	static inline auto FPlayFacialAnimation = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, char* name, bool looping)>(0x956180);
	static inline auto FSetAnimationEvent = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* sAnimation)>(0x158AEF0);
	static inline auto FSetAnimationKeyEvent = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x158AEF0);
	static inline auto FDisableAnimationEvent = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* sAnimation)>(0x158AEF0);
	static inline auto FSetAnimationSpeed = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, int layer, float speed)>(0x957EF0);
	static inline auto FSetAnimationTime = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, int nLayer, float fNormalizedTime)>(0x957F80);
	static inline auto FGetAnimationTime = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, int nLayer)>(0x942630);
	static inline auto FGetNumQueuedAnimations = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, int nLayer)>(0x9474D0);
	static inline auto FGetCurAnimation = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x944050);
	static inline auto FGetAnimationLength = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* animation)>(0x9424D0);
	static inline auto FSetAnimationFlip = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, Vec3 flip)>(0x9418C0);
	static inline auto FSetTimer = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x960CB0);
	static inline auto FKillTimer = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94E000);
	static inline auto FSetScriptUpdateRate = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nMillis)>(0x95F7C0);
	static inline auto FGotoState = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const char* sStateName)>(0x94A940);
	static inline auto FIsInState = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const char* sStateName)>(0x94D680);
	static inline auto FGetState = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x949060);
	static inline auto FIsHidden = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94D5E0);
	static inline auto FGetTouchedSurfaceID = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9498D0);
	static inline auto FGetTouchedPoint = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9495E0);
	static inline auto FCreateBoneAttachment = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* boneName, const char* attachmentName)>(0x93F990);
	static inline auto FCreateSkinAttachment = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName)>(0x93FD10);
	static inline auto FDestroyAttachment = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName)>(0x93FED0);
	static inline auto FGetAttachmentBone = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName)>(0x942810);
	static inline auto FGetAttachmentCGF = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName)>(0x942930);
	static inline auto FResetAttachment = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName)>(0x957550);
	static inline auto FSetAttachmentEffect = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName, const char* effectName, Vec3 offset, Vec3 dir, float scale, int flags)>(0x958B40);
	static inline auto FSetAttachmentObject = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName, ScriptHandle entityId, int slot, int flags)>(0x958FC0);
	static inline auto FSetAttachmentCGF = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName, const char* filePath)>(0x958380);
	static inline auto FSetAttachmentLight = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName, SmartScriptTable lightTable, int flags)>(0x958CB0);
	static inline auto FSetAttachmentPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName, Vec3 pos)>(0x9591C0);
	static inline auto FSetAttachmentAngles = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName, Vec3 angles)>(0x958150);
	static inline auto FSetAttachmentDir = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName, Vec3 dir, bool worldSpace)>(0x9584A0);
	static inline auto FHideAttachment = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName, bool hide, bool hideShadow)>(0x94AD90);
	static inline auto FHideAllAttachments = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, bool hide, bool hideShadow)>(0x94AC80);
	static inline auto FHideAttachmentMaster = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, bool hide)>(0x94AE40);
	static inline auto FPhysicalizeAttachment = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, const char* attachmentName, bool physicalize)>(0x955E20);
	static inline auto FDamage = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x75CBB0);
	static inline auto FGetExplosionObstruction = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x944A20);
	static inline auto FGetExplosionImpulse = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x944900);
	static inline auto FSetMaterial = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x95EC70);
	static inline auto FGetMaterial = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x946EA0);
	static inline auto FGetEntityMaterial = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9447D0);
	static inline auto FChangeAttachmentMaterial = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const char* attachmentName, const char* materialName)>(0x93DAD0);
	static inline auto FCloneAttachmentMaterial = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* _pH, int _characterSlot, const char* _attachmentName)>(0x93F430);
	static inline auto FSetAttachmentMaterialFloat = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int _characterSlot, const char* _attachmentName, int _nSubMtlId, int _nParam, float _fValue)>(0x958E20);
	static inline auto FSetAttachmentMaterialVec3 = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int _characterSlot, const char* _attachmentName, int _nSubMtlId, int _nParam, Vec3 _vValue)>(0x958ED0);
	static inline auto FGetAttachmentMaterialVec3 = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int _characterSlot, const char* _attachmentName, int _nSubMtlId, int _nParam)>(0x942AF0);
	static inline auto FReplaceMaterial = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot, const char* name, const char* replacement)>(0x957230);
	static inline auto FResetMaterial = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot)>(0x9575D0);
	static inline auto FEnableMaterialLayer = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, bool enable, int layer)>(0x9419A0);
	static inline auto FCloneMaterial = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot)>(0x93F4F0);
	static inline auto FSetMaterialFloat = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot, int nSubMtlId, int _nParam, float fValue)>(0x95EDA0);
	static inline auto FGetMaterialFloat = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot, int nSubMtlId, int _nParam)>(0x947100);
	static inline auto FSetMaterialVec3 = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot, int nSubMtlId, int _nParam, Vec3 vValue)>(0x95EE50);
	static inline auto FGetMaterialVec3 = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot, int nSubMtlId, int _nParam)>(0x947220);
	static inline auto FMaterialFlashInvoke = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94F740);
	static inline auto FToLocal = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slotId, Vec3 point)>(0x962270);
	static inline auto FToGlobal = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slotId, Vec3 point)>(0x962070);
	static inline auto FVectorToLocal = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slotId, Vec3 dir)>(0x962990);
	static inline auto FVectorToGlobal = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slotId, Vec3 dir)>(0x9627F0);
	static inline auto FCheckCollisions = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93DD70);
	static inline auto FAwakeEnvironment = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93D1A0);
	static inline auto FGetTimeSinceLastSeen = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x949500);
	static inline auto FGetViewDistRatio = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x949EE0);
	static inline auto FSetViewDistRatio = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x961150);
	static inline auto FSetViewDistUnlimited = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x961260);
	static inline auto FSetLodRatio = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x95EB60);
	static inline auto FGetLodRatio = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x946C50);
	static inline auto FSetStateClientside = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x960BE0);
	static inline auto FInsertSubpipe = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94B4B0);
	static inline auto FCancelSubpipe = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93D930);
	static inline auto FPassParamsToPipe = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x955B00);
	static inline auto FSetDefaultIdleAnimations = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x95A140);
	static inline auto FGetVelocity = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x949C30);
	static inline auto FGetVelocityEx = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x949D50);
	static inline auto FSetVelocity = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Vec3 velocity)>(0x961010);
	static inline auto FSetVelocityEx = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, Vec3 velocity, Vec3 angularVelocity)>(0x9610A0);
	static inline auto FGetSpeed = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x948EB0);
	static inline auto FGetMass = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x946D20);
	static inline auto FGetVolume = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot)>(0x949FB0);
	static inline auto FGetGravity = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x944D30);
	static inline auto FGetSubmergedVolume = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot, Vec3 planeNormal, Vec3 planeOrigin)>(0x949120);
	static inline auto FCreateLink = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const char* name)>(0x93FB90);
	static inline auto FGetLinkName = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, ScriptHandle targetId)>(0x9462B0);
	static inline auto FSetLinkTarget = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const char* name, ScriptHandle targetId)>(0x95E7E0);
	static inline auto FGetLinkTarget = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const char* name)>(0x946430);
	static inline auto FRemoveLink = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const char* name)>(0x956EC0);
	static inline auto FRemoveAllLinks = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x956D10);
	static inline auto FGetLink = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int ith)>(0x946160);
	static inline auto FCountLinks = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93F710);
	static inline auto FRemoveDecals = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x956E60);
	static inline auto FEnableDecals = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot, bool enable)>(0x941900);
	static inline auto FForceCharacterUpdate = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, bool updateAlways)>(0x941E80);
	static inline auto FCharacterUpdateAlways = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, bool updateAlways)>(0x93DC70);
	static inline auto FCharacterUpdateOnRender = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int characterSlot, bool bUpdateOnRender)>(0x93DCF0);
	static inline auto FSetAnimateOffScreenShadow = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, bool bAnimateOffScreenShadow)>(0x957E90);
	static inline auto FRagDollize = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot)>(0x956700);
	static inline auto FHide = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x94AB80);
	static inline auto FNoExplosionCollision = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x950010);
	static inline auto FNoBulletForce = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, bool state)>(0x94FF20);
	static inline auto FUpdateAreas = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x962630);
	static inline auto FIsPointInsideArea = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int areaId, Vec3 point)>(0x94D760);
	static inline auto FIsEntityInsideArea = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int areaId, ScriptHandle entityId)>(0x94CCE0);
	static inline auto FGetPhysicalStats = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x947830);
	static inline auto FSetParentSlot = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int child, int parent)>(0x95F020);
	static inline auto FGetParentSlot = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int child)>(0x9476B0);
	static inline auto FBreakToPieces = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, int nPiecesSlot, float fExplodeImp, Vec3 vHitPt, Vec3 vHitImp, float fLifeTime, bool bMaterialEffects)>(0x93D440);
	static inline auto FAttachSurfaceEffect = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, const char* effect, bool countPerUnit, const char* form, const char* typ, float countScale, float sizeScale)>(0x93CEA0);
	static inline auto FProcessBroadcastEvent = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x956610);
	static inline auto FActivateOutput = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93B500);
	static inline auto FCreateCameraProxy = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x93FAD0);
	static inline auto FUnSeenFrames = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x962540);
	static inline auto FDeleteParticleEmitter = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int slot)>(0x93FDC0);
	static inline auto FRegisterForAreaEvents = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int enable)>(0x956C20);
	static inline auto FRenderAlways = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int enable)>(0x956FC0);
	static inline auto FGetTimeOfDayHour = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x949470);
	static inline auto FGetAttachmentPos = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, const char* _attachmentName)>(0x942C50);
	static inline auto FSetDisplayName = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* const _pH, const char* _pName)>(0x95A5E0);
	static inline auto FGetDisplayName = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* const _pH)>(0x9443A0);
	static inline auto FSetAsSceneWindow = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, bool _bIsSceneWindow)>(0x9580E0);
	static inline auto FSetEntireMaterialFloat = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* const pH, const int _slot, const char* const _paramName, float _value)>(0x95A620);
	static inline auto FRenderBeginMorphingSwipe = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, int nSlot, int nEnable, float time)>(0x957040);
	static inline auto FGetEntity = PreyFunction<IEntity* (CScriptBind_Entity* const _this, IFunctionHandler* pH)>(0x9445F0);
	static inline auto FSetEntityPhysicParams = PreyFunction<int(CScriptBind_Entity* const _this, IFunctionHandler* pH, IPhysicalEntity* pe, int nType, IScriptTable* pTable, ICharacterInstance* pIChar)>(0x95A770);
	static inline auto FParseLightParams = PreyFunction<bool(CScriptBind_Entity* const _this, IScriptTable* pLightTable, IEntity* pEntity, CDLight& light)>(0x9517A0);
	static inline auto FParseFogVolumesParams = PreyFunction<bool(CScriptBind_Entity* const _this, IScriptTable* pTable, IEntity* pEntity, SFogVolumeProperties& properties)>(0x950B50);
	static inline auto FParseVolumeObjectMovementProperties = PreyFunction<bool(CScriptBind_Entity* const _this, IScriptTable* pTable, IEntity* pEntity, SVolumeObjectMovementProperties& properties)>(0x9558A0);
	static inline auto FParsePhysicsParams = PreyFunction<bool(CScriptBind_Entity* const _this, IScriptTable* pTable, SEntityPhysicalizeParams& params)>(0x953A50);
	static inline auto FcmpIntersectionResult = PreyFunction<int(const void* v1, const void* v2)>(0x158AEF0);
	static inline auto FOnAudioTriggerFinishedEvent = PreyFunction<void(const SAudioRequestInfo* const pAudioRequestInfo)>(0x950AE0);
	static inline auto FIStatObjRayIntersect = PreyFunction<int(CScriptBind_Entity* const _this, IStatObj* pStatObj, const Vec3& rayOrigin, const Vec3& rayDir, float maxDistance, CScriptBind_Entity::SIntersectionResult* pOutResult, unsigned maxResults)>(0x94AEA0);
};

