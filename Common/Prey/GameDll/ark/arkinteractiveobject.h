// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/perception/ArkAuralPerceivable.h>

class ArkInteractiveMachine;
class ArkInteractiveObject;

// Header: FromCpp
// Prey/GameDll/ark/arkinteractiveobject.h
class ArkInteractiveMachinePerceivable : public ArkAuralPerceivable // Id=8019072 Size=16
{
public:
	ArkInteractiveMachine const &m_machine;

    ArkInteractiveMachinePerceivable();
	virtual unsigned DoGetEntityId() const;
	virtual bool DoGetAuralPerceivableIsInVacuum() const;
	virtual bool DoGetAuralPerceivableIsComplexAttentionObject() const;
	
	static inline auto FDoGetEntityId = PreyFunction<unsigned(ArkInteractiveMachinePerceivable const *const _this)>(0x1184710);
	static inline auto FDoGetAuralPerceivableIsInVacuum = PreyFunction<bool(ArkInteractiveMachinePerceivable const *const _this)>(0xDD23F0);
	static inline auto FDoGetAuralPerceivableIsComplexAttentionObject = PreyFunction<bool(ArkInteractiveMachinePerceivable const *const _this)>(0xDD23F0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkinteractiveobject.h
class ArkInteractiveObjectPerceivable : public ArkAuralPerceivable // Id=8019362 Size=16
{
public:
	ArkInteractiveObject const &m_interactiveObject;

    ArkInteractiveObjectPerceivable();
	virtual unsigned DoGetEntityId() const;
	virtual bool DoGetAuralPerceivableIsInVacuum() const;
	virtual bool DoGetAuralPerceivableIsComplexAttentionObject() const;
	
	static inline auto FDoGetEntityId = PreyFunction<unsigned(ArkInteractiveObjectPerceivable const *const _this)>(0x1184710);
	static inline auto FDoGetAuralPerceivableIsInVacuum = PreyFunction<bool(ArkInteractiveObjectPerceivable const *const _this)>(0xDD23F0);
	static inline auto FDoGetAuralPerceivableIsComplexAttentionObject = PreyFunction<bool(ArkInteractiveObjectPerceivable const *const _this)>(0xDD23F0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDisruptable.h>
#include <Prey/GameDll/ark/ArkDisruptableSignalReceiver.h>
#include <Prey/GameDll/ark/ArkEmissiveComponent.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/iface/IArkDisruptableListener.h>
#include <Prey/GameDll/ark/perception/ArkGameNoise.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <_unknown/ArkInteractiveObjectPerceivable.h>

struct ArkInteractionTestResult;
enum class EArkInteractionMode;
enum class EArkInteractionType;
enum EEntityAspects;
class ICrySizer;
struct IEntity;
struct IEntityRenderProxy;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// ArkInteractiveObject
// Header:  Prey/GameDll/ark/ArkInteractiveObject.h
class ArkInteractiveObject
	: public CGameObjectExtensionHelper<ArkInteractiveObject, IGameObjectExtension>
	, public IArkDisruptableListener
	, public IArkPlayerInteractionListener
{ // Size=848 (0x350)
public:
	bool m_bActive;
	bool m_bDisabled;
	bool m_bPlayingAudio;
	bool m_bAnimating;
	int m_activatedAnimId;
	int m_deactivatedAnimId;
	ArkSimpleTimer m_autoTimeOut;
	ArkDisruptable m_disruptable;
	ArkDisruptableSignalReceiver m_signalReceiver;
	ArkEntityEffect m_vfx;
	ArkEntityEffect m_inactiveVfx;
	QuatT m_vfxLoc;
	unsigned m_linkedEntity;
	ArkEmissiveComponent m_emissiveComponent;
	ArkInteractiveObjectPerceivable m_perceivable;
	string m_model;
	string m_disabledMaterial;
	string m_enabledMaterial;
	string m_skinAttachmentName;
	float m_enabledGlowAmount;
	float m_disabledGlowAmount;
	Vec3 m_enabledGlowColor;
	Vec3 m_disabledGlowColor;
	Vec3 m_vfxOffset;
	Ang3 m_vfxDir;
	string m_vfxBoneName;
	string m_useMessage;
	string m_activeUseMessage;
	ArkGameNoise::Params m_gameNoiseParams;
	ArkAudioTrigger m_triggerStart;
	ArkAudioTrigger m_triggerStop;
	int m_tokenIsPsiAddedToWater;
	uint64_t m_signalPackagePsiRewardOnUse;
	uint64_t m_signalPackageHealthOnUse;
	uint64_t m_glintConfig;
	uint64_t m_requiredAbility;
	bool m_bIsWaterSource;
	bool m_bDisableOnUse;
	bool m_bStartsActive;
	bool m_bStartsDisabled;
	bool m_bPreviewVFX;
	bool m_bUseGlow;
	bool m_bCanBeCarried;
	bool m_bAllowRemoteManipulation;

	ArkInteractiveObject();
	virtual ~ArkInteractiveObject();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	void SetActive(bool _bActive, bool _bForce, bool _bIsPlayerInteraction) { FSetActive(this, _bActive, _bForce, _bIsPlayerInteraction); }
	void SetDisabled(bool _bDisabled, bool _bForced) { FSetDisabled(this, _bDisabled, _bForced); }
	void LinkToEntity(const unsigned _linkedEntityId) { FLinkToEntity(this, _linkedEntityId); }
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, const EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo) const;
	void LoadProperties() { FLoadProperties(this); }
	void LoadCharacterData() { FLoadCharacterData(this); }
	void SetActive_Internal(bool _bActive, bool _bForce) { FSetActive_Internal(this, _bActive, _bForce); }
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual QuatT GetSparkLoc() const;

#if 0
	void OnReset(bool _arg0_);
	void TriggerGameNoise();
	IEntityRenderProxy* GetRenderProxy() const;
#endif

	static inline auto FArkInteractiveObjectOv1 = PreyFunction<void(ArkInteractiveObject* const _this)>(0x11FF5B0);
	static inline auto FBitNotArkInteractiveObject = PreyFunction<void(ArkInteractiveObject* const _this)>(0x11FF800);
	static inline auto FInit = PreyFunction<bool(ArkInteractiveObject* const _this, IGameObject* _pGameObject)>(0x11FFF80);
	static inline auto FInitClient = PreyFunction<void(ArkInteractiveObject* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(ArkInteractiveObject* const _this, IGameObject* _pGameObject)>(0x1201830);
	static inline auto FPostInitClient = PreyFunction<void(ArkInteractiveObject* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(ArkInteractiveObject* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkInteractiveObject* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkInteractiveObject* const _this, TSerialize signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(ArkInteractiveObject* const _this)>(0x1201BE0);
	static inline auto FFullSerialize = PreyFunction<void(ArkInteractiveObject* const _this, TSerialize _ser)>(0x11FFA50);
	static inline auto FNetSerialize = PreyFunction<bool(ArkInteractiveObject* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkInteractiveObject* const _this)>(0x1201A00);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkInteractiveObject* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(ArkInteractiveObject* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(ArkInteractiveObject* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x12027E0);
	static inline auto FPostUpdate = PreyFunction<void(ArkInteractiveObject* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkInteractiveObject* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(ArkInteractiveObject* const _this, const SGameObjectEvent& _event)>(0x11FFDA0);
	static inline auto FProcessEvent = PreyFunction<void(ArkInteractiveObject* const _this, SEntityEvent& _event)>(0x1201A50);
	static inline auto FSetChannelId = PreyFunction<void(ArkInteractiveObject* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(ArkInteractiveObject* const _this, bool auth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkInteractiveObject* const _this, ICrySizer* s)>(0x1333E90);
	static inline auto FSetActive = PreyFunction<void(ArkInteractiveObject* const _this, bool _bActive, bool _bForce, bool _bIsPlayerInteraction)>(0x1201CA0);
	static inline auto FSetDisabled = PreyFunction<void(ArkInteractiveObject* const _this, bool _bDisabled, bool _bForced)>(0x12024A0);
	static inline auto FLinkToEntity = PreyFunction<void(ArkInteractiveObject* const _this, const unsigned _linkedEntityId)>(0x11FFFC0);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x1201560);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, const EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x1202750);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x12016F0);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo)>(0x12017D0);
	static inline auto FLoadProperties = PreyFunction<void(ArkInteractiveObject* const _this)>(0x1200270);
	static inline auto FLoadCharacterData = PreyFunction<void(ArkInteractiveObject* const _this)>(0x11FFFD0);
	static inline auto FSetActive_Internal = PreyFunction<void(ArkInteractiveObject* const _this, bool _bActive, bool _bForce)>(0x1201FF0);
	static inline auto FOnDisruptedChanged = PreyFunction<void(IArkDisruptableListener* const _this, bool _bDisrupted, bool _bWasForced)>(0x1201540);
	static inline auto FGetSparkLoc = PreyFunction<QuatT*(const IArkDisruptableListener* const _this, QuatT* _return_value_)>(0x11FFBE0);
};
#endif // !MOONCRASH
