// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryRenderer/IShader.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/ArkDisruptable.h>
#include <Prey/GameDll/ark/ArkEmissiveComponent.h>
#include <Prey/GameDll/ark/arkgameobjectextension.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkDisruptableListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

struct ArkInteractionInfo;
class ArkLightDisruptionProfile;
struct ArkLightManagerLightData;
class ArkSafeScriptTable;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct IArkLightListener;
class ICrySizer;
struct IEntity;
struct IEntityRenderProxy;
struct IGameObject;
struct IMaterial;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SGameObjectEvent;

class CArkLight;

// Header: FromCpp
// Prey/GameDll/ark/arklight.h
class ArkLightSignalReceiver : public ArkSignalSystem::Receiver // Id=80141F8 Size=32
{
public:
	CArkLight* m_pLight;
	uint64_t m_signalGroupId;

	virtual ~ArkLightSignalReceiver();
	virtual void OnReceiveSignal(ArkSignalSystem::Package const& _package);
	void RegisterForSignals(bool _bRegister) { FRegisterForSignals(this, _bRegister); }
	void SetSignalGroupId(const uint64_t _id) { FSetSignalGroupId(this, _id); }

	static inline auto FOnReceiveSignal = PreyFunction<void(ArkLightSignalReceiver* const _this, ArkSignalSystem::Package const& _package)>(0x1445C40);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkLightSignalReceiver* const _this, bool _bRegister)>(0x1446A20);
	static inline auto FSetSignalGroupId = PreyFunction<void(ArkLightSignalReceiver* const _this, const uint64_t _id)>(0x1447A90);
};

// Header: FromCpp
// Prey/GameDll/ark/arklight.h
class CArkLight : public CArkGameObjectExtension<CArkLight>, public IArkDisruptableListener, public IArkPlayerInteractionListener // Id=80141D9 Size=3136
{
public:
	struct LightData // Id=80141DE Size=712
	{
		bool m_bEnabled;
		bool m_bIgnoreGeomCaster;
		bool m_bProjectEmissive;
		bool m_bShadowCaster;
		uint8_t m_nLightStyleProperty;
		uint8_t m_nLightStyle;
		uint8_t m_nLightStylePhase;
		uint8_t m_nLightStyleAnimSpeed;
		float m_fDiffuseMultiplier;
		Vec3 m_cDiffuseColor;
		Vec3 m_cAnimColor;
		const char *m_szProjectorTexture;
		Matrix34 m_localTM;
		CDLight m_engineLight;
	};

	enum class EConstants
	{
		k_MaxLights = 2,
	};

	enum class EMovementResponse : uint8_t
	{
		disableLights = 0,
		disableShadows = 1,
		nothing = 2,
	};

	enum class EUpdateSlots
	{
		k_DisruptionUpdateSlot = 0,
		k_LightAnimUpdateSlot = 1,
		k_LightVisualUpdateSlot = 2,
	};

	enum class ESlots
	{
		k_ModelSlot = 0,
		k_Light1Slot = 1,
		k_Light2Slot = 2,
		k_EmpLightSlot = 3,
		k_DisruptionVfxSlot = 4,
		k_InterferenceVfxSlot = 5,
		k_BreakVfxSlot = 6,
		k_EnabledVfxSlot = 7,
	};

	ArkLightSignalReceiver m_signalReceiver;
	float m_fBrightness;
	float m_fTimeBrightness;
	float m_fVisualEmpInfluence;
	float m_fVisualEmpBrightness;
	ArkEmissiveComponent m_emissiveComponent;
	bool m_bWasMoved;
	bool m_bLightsDisabledFromMovement;
	bool m_bNeedUpdateVisuals;
	bool m_bNeedDisableShadows;
	bool m_bRecursing;
	ArkDisruptable m_disruptable;
	float m_empBrightness;
	float m_empTargetBrightness;
	float m_empInfluence;
	float m_empTargetInfluence;
	float m_empRandomBurstTimer;
	bool m_bLinkedToWorldUI;
	std::vector<IArkLightListener *> m_listeners;
	float m_health;
	float m_maxHealth;
	CArkLight::LightData m_lights[2];
	
	struct EmpLightData // Id=8014215 Size=640
	{
		bool m_bEnabled;
		float m_fMaxRadius;
		Vec3 m_offset;
		CDLight m_engineLight;
	};

	CArkLight::EmpLightData m_empLight;
	bool m_bHasModel;
	bool m_bHasLights;
	bool m_bHasLightAnimation;
	bool m_bHasTimeControls;
	bool m_bForceDisableAffectsThisAreaOnly;
	bool m_bIsCarryable;
	Vec3 m_vOrigPosition;
	CArkLight::EMovementResponse m_movementResponse;
	ArkLightDisruptionProfile const *m_pLightDisruptionProfile;
	float m_empBrightnessChangeSpeed;
	float m_empInfluenceChangeSpeed;
	EArkLightInterferenceState m_interferenceState;
	ArkRandomizedAutoResetTimer m_interferenceRampIn;
	ArkRandomizedAutoResetTimer m_interferenceBright;
	ArkRandomizedAutoResetTimer m_interferenceRampOut;
	ArkRandomizedAutoResetTimer m_interferenceDarkness;
	ArkAudioTrigger m_empDisruptionStartTrigger;
	ArkAudioTrigger m_empDisruptionStopTrigger;
	Vec3 m_empEffectPositionOffset;
	Vec3 m_empEffectRotationOffset;
	ArkAudioTrigger m_breakableDestroySound;
	ArkEntityEffect m_disruptionEffect;
	ArkFireAndForgetEffect m_intereferenceEffect;
	ArkEntityEffect m_breakEffect;
	ArkEntityEffect m_enabledEffect;
	ArkFireAndForgetEffect m_movementResponseEffect;
	
	CArkLight();
	virtual ~CArkLight();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Release();
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	void SetPowered(bool _bPowered) { FSetPowered(this,_bPowered); }
	void RegisterListener(IArkLightListener &_listener) { FRegisterListener(this,_listener); }
	void UnregisterListener(IArkLightListener &_listener) { FUnregisterListener(this,_listener); }
	void SetDiffuseColor(Vec3 const &_color, int _lightIndex, bool _bForce) { FSetDiffuseColorOv1(this,_color,_lightIndex,_bForce); }
	void SetDiffuseColor(const int _lightIndex, Vec3 _color) { FSetDiffuseColorOv0(this,_lightIndex,_color); }
	void SetBrightness(float _fBrightness, bool _bForce) { FSetBrightness(this,_fBrightness,_bForce); }
	void SetTimeBrightness(float _fTimeBrightness, bool _bForce) { FSetTimeBrightness(this,_fTimeBrightness,_bForce); }
	void SetVisualEmpInfluence(float _fEmpInfluence, bool _bForce) { FSetVisualEmpInfluence(this,_fEmpInfluence,_bForce); }
	void SetVisualEmpBrightness(float _fEmpBrightness, bool _bForce) { FSetVisualEmpBrightness(this,_fEmpBrightness,_bForce); }
	void ForceDisableAffectsThisAreaOnly() { FForceDisableAffectsThisAreaOnly(this); }
	void ApplySerializedData(ArkLightManagerLightData const &_data) { FApplySerializedData(this,_data); }
	void ProcessScriptEvent(const char *_szEventName) { FProcessScriptEvent(this,_szEventName); }
	void ParseLightStyleData(const int _index, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps) { FParseLightStyleData(this,_index,_props,_instProps); }
	void ParseLightShapeParams(CArkLight::LightData &_lightData, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps) { FParseLightShapeParams(this,_lightData,_props,_instProps); }
	void ParseLightParams(CArkLight::LightData &_lightData, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps) { FParseLightParams(this,_lightData,_props,_instProps); }
	void LoadCachedProperties_Audio(ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps) { FLoadCachedProperties_Audio(this,_props,_instProps); }
	void LoadCachedProperties_Particles(ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps) { FLoadCachedProperties_Particles(this,_props,_instProps); }
	void LoadCachedProperties_Disruption(ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps) { FLoadCachedProperties_Disruption(this,_props,_instProps); }
	void LoadCachedProperties_Lights(ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps) { FLoadCachedProperties_Lights(this,_props,_instProps); }
	void LoadCachedProperties_Breakable(ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps) { FLoadCachedProperties_Breakable(this,_props,_instProps); }
	void LoadCachedProperties_Time(ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps) { FLoadCachedProperties_Time(this,_props,_instProps); }
	void LoadCachedProperties() { FLoadCachedProperties(this); }
	void Shutdown() { FShutdown(this); }
	void Startup() { FStartup(this); }
	void CacheLightSlots() { FCacheLightSlots(this); }
	void SetupLightSlots() { FSetupLightSlots(this); }
	void SetupModel(const bool _bPhysicalize) { FSetupModel(this,_bPhysicalize); }
	void OnMaterialChanged(IMaterial *_pNewMaterial) { FOnMaterialChanged(this,_pNewMaterial); }
	void QueueUpdateVisuals() { FQueueUpdateVisuals(this); }
	void OnDisruptStart() { FOnDisruptStart(this); }
	void InterferenceMaxBrightnessEffects() { FInterferenceMaxBrightnessEffects(this); }
	void UpdateDisruption(float _dt) { FUpdateDisruption(this,_dt); }
	void UpdateVisuals() { FUpdateVisuals(this); }
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual void OnInterferenceChanged(bool _bInterfered);
	virtual QuatT GetSparkLoc() const;
	virtual bool AffectedByDisruption() const;
	virtual void OnDisruptAccumulationValueChanged(const float _value) const;
	virtual void OnInterferenceAccumulationValueChanged(const float _value) const;
	virtual void OnSparkTimerChanged(const float _value) const;
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo) const;
	void SetEmpBrightness(const float _value) { FSetEmpBrightness(this,_value); }
	void SetEmpTargetBrightness(const float _value) { FSetEmpTargetBrightness(this,_value); }
	void SetEmpInfluence(const float _value) { FSetEmpInfluence(this,_value); }
	void SetEmpTargetInfluence(const float _value) { FSetEmpTargetInfluence(this,_value); }
	void SetHealth_Internal(const float _value) { FSetHealth_Internal(this,_value); }
	void SetLightStyle(const int _lightIndex, const uint8_t _style) { FSetLightStyle(this,_lightIndex,_style); }
	void SetInterferenceState(EArkLightInterferenceState _interferenceState) { FSetInterferenceState(this,_interferenceState); }
	void SetMoved(CArkLight::EMovementResponse _response, bool _bFromLink) { FSetMoved(this,_response,_bFromLink); }
	void PopulateInteractionForCarry(ArkInteractionInfo &_interactionInfo) const { FPopulateInteractionForCarry(this,_interactionInfo); }
	
#if 0
	void SetLinkedToWorldUI(bool arg0);
	void ForceDisableLinkedLights();
	void SetHealth(float arg0);
	float GetHealth() const;
	bool IsBroken() const;
	ArkDisruptable &GetArkDisruptable();
	void SetupPhysics(const char *arg0);
	void SetupLights();
	float GetActualBrightness() const;
	void OnDisruptStop();
	void StartDisruptionEffects(bool arg0);
	void Burst(float arg0);
	void UpdateLightAnimation();
	bool IsDisruptedOrRecovering() const;
	IEntityRenderProxy *GetRenderProxy() const;
	void SetWasMoved(const bool arg0);
	void SetLightsDisabledFromMovement(const bool arg0);
	void SetNeedsDisableShadows(const bool arg0);
#endif
	
	static inline auto FInit = PreyFunction<bool(CArkLight *const _this, IGameObject *_pGameObject)>(0x1444F20);
	static inline auto FPostInit = PreyFunction<void(CArkLight *const _this, IGameObject *_pGameObject)>(0x14461B0);
	static inline auto FRelease = PreyFunction<void(CArkLight *const _this)>(0xA97D40);
	static inline auto FPostSerialize = PreyFunction<void(CArkLight *const _this)>(0x14461C0);
	static inline auto FUpdate = PreyFunction<void(CArkLight *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x14495C0);
	static inline auto FHandleEvent = PreyFunction<void(CArkLight *const _this, SGameObjectEvent const &_event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(CArkLight *const _this, SEntityEvent &_event)>(0x14462F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkLight const *const _this, ICrySizer *_pS)>(0x1444CD0);
	static inline auto FSetPowered = PreyFunction<void(CArkLight *const _this, bool _bPowered)>(0x1447A30);
	static inline auto FRegisterListener = PreyFunction<void(CArkLight *const _this, IArkLightListener &_listener)>(0x1446B40);
	static inline auto FUnregisterListener = PreyFunction<void(CArkLight *const _this, IArkLightListener &_listener)>(0x1449570);
	static inline auto FSetDiffuseColorOv1 = PreyFunction<void(CArkLight *const _this, Vec3 const &_color, int _lightIndex, bool _bForce)>(0x1446DF0);
	static inline auto FSetDiffuseColorOv0 = PreyFunction<void(CArkLight *const _this, const int _lightIndex, Vec3 _color)>(0x1446D50);
	static inline auto FSetBrightness = PreyFunction<void(CArkLight *const _this, float _fBrightness, bool _bForce)>(0x1446B90);
	static inline auto FSetTimeBrightness = PreyFunction<void(CArkLight *const _this, float _fTimeBrightness, bool _bForce)>(0x1447C30);
	static inline auto FSetVisualEmpInfluence = PreyFunction<void(CArkLight *const _this, float _fEmpInfluence, bool _bForce)>(0x1447F90);
	static inline auto FSetVisualEmpBrightness = PreyFunction<void(CArkLight *const _this, float _fEmpBrightness, bool _bForce)>(0x1447DF0);
	static inline auto FForceDisableAffectsThisAreaOnly = PreyFunction<void(CArkLight *const _this)>(0x1444B40);
	static inline auto FApplySerializedData = PreyFunction<void(CArkLight *const _this, ArkLightManagerLightData const &_data)>(0x1444960);
	static inline auto FProcessScriptEvent = PreyFunction<void(CArkLight *const _this, const char *_szEventName)>(0x14464E0);
	static inline auto FParseLightStyleData = PreyFunction<void(CArkLight *const _this, const int _index, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps)>(0x118E9C0);
	static inline auto FParseLightShapeParams = PreyFunction<void(CArkLight *const _this, CArkLight::LightData &_lightData, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps)>(0x118E550);
	static inline auto FParseLightParams = PreyFunction<void(CArkLight *const _this, CArkLight::LightData &_lightData, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps)>(0x118D8E0);
	static inline auto FLoadCachedProperties_Audio = PreyFunction<void(CArkLight *const _this, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps)>(0x118A7B0);
	static inline auto FLoadCachedProperties_Particles = PreyFunction<void(CArkLight *const _this, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps)>(0x118C1E0);
	static inline auto FLoadCachedProperties_Disruption = PreyFunction<void(CArkLight *const _this, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps)>(0x118ADF0);
	static inline auto FLoadCachedProperties_Lights = PreyFunction<void(CArkLight *const _this, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps)>(0x118B380);
	static inline auto FLoadCachedProperties_Breakable = PreyFunction<void(CArkLight *const _this, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps)>(0x118AB30);
	static inline auto FLoadCachedProperties_Time = PreyFunction<void(CArkLight *const _this, ArkSafeScriptTable const &_props, ArkSafeScriptTable const &_instProps)>(0x118CCE0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkLight *const _this)>(0x118A0E0);
	static inline auto FShutdown = PreyFunction<void(CArkLight *const _this)>(0x1448F80);
	static inline auto FStartup = PreyFunction<void(CArkLight *const _this)>(0x1449340);
	static inline auto FCacheLightSlots = PreyFunction<void(CArkLight *const _this)>(0x1444A10);
	static inline auto FSetupLightSlots = PreyFunction<void(CArkLight *const _this)>(0x1448390);
	static inline auto FSetupModel = PreyFunction<void(CArkLight *const _this, const bool _bPhysicalize)>(0x14484E0);
	static inline auto FOnMaterialChanged = PreyFunction<void(CArkLight *const _this, IMaterial *_pNewMaterial)>(0x1445900);
	static inline auto FQueueUpdateVisuals = PreyFunction<void(CArkLight *const _this)>(0x14469F0);
	static inline auto FOnDisruptStart = PreyFunction<void(CArkLight *const _this)>(0x14454E0);
	static inline auto FInterferenceMaxBrightnessEffects = PreyFunction<void(CArkLight *const _this)>(0x1444FC0);
	static inline auto FUpdateDisruption = PreyFunction<void(CArkLight *const _this, float _dt)>(0x1449770);
	static inline auto FUpdateVisuals = PreyFunction<void(CArkLight *const _this)>(0x1449C20);
	static inline auto FOnDisruptedChanged = PreyFunction<void(CArkLight *const _this, bool _bDisrupted, bool _bWasForced)>(0x1445690);
	static inline auto FOnInterferenceChanged = PreyFunction<void(CArkLight *const _this, bool _bInterfered)>(0x14457D0);
	static inline auto FGetSparkLoc = PreyFunction<QuatT(CArkLight const *const _this)>(0x1444D00);
	static inline auto FAffectedByDisruption = PreyFunction<bool(CArkLight const *const _this)>(0x1444940);
	static inline auto FOnDisruptAccumulationValueChanged = PreyFunction<void(CArkLight const *const _this, const float _value)>(0x14454A0);
	static inline auto FOnInterferenceAccumulationValueChanged = PreyFunction<void(CArkLight const *const _this, const float _value)>(0x1445790);
	static inline auto FOnSparkTimerChanged = PreyFunction<void(CArkLight const *const _this, const float _value)>(0x1446040);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(CArkLight const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x1446190);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(CArkLight const *const _this, IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo)>(0x1446190);
	static inline auto FSetEmpBrightness = PreyFunction<void(CArkLight *const _this, const float _value)>(0x1446EB0);
	static inline auto FSetEmpTargetBrightness = PreyFunction<void(CArkLight *const _this, const float _value)>(0x1446F50);
	static inline auto FSetEmpInfluence = PreyFunction<void(CArkLight *const _this, const float _value)>(0x1446F00);
	static inline auto FSetEmpTargetInfluence = PreyFunction<void(CArkLight *const _this, const float _value)>(0x1446FA0);
	static inline auto FSetHealth_Internal = PreyFunction<void(CArkLight *const _this, const float _value)>(0x1446FF0);
	static inline auto FSetLightStyle = PreyFunction<void(CArkLight *const _this, const int _lightIndex, const uint8_t _style)>(0x1447320);
	static inline auto FSetInterferenceState = PreyFunction<void(CArkLight *const _this, EArkLightInterferenceState _interferenceState)>(0x1447040);
	static inline auto FSetMoved = PreyFunction<void(CArkLight *const _this, CArkLight::EMovementResponse _response, bool _bFromLink)>(0x1447380);
	static inline auto FPopulateInteractionForCarry = PreyFunction<void(CArkLight const *const _this, ArkInteractionInfo &_interactionInfo)>(0x1446080);
};
