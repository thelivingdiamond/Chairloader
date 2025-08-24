// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDisruptable.h>
#include <Prey/GameDll/ark/ArkDisruptableSignalReceiver.h>
#include <Prey/GameDll/ark/arkgameobjectextension.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkDisruptableListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <Prey/GameDll/ark/worldui/ArkWorldUIOwner.h>
#include <Prey/GameDll/ark/worldui/ArkInteractiveScreen.h>

struct ArkInteractionInfo;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IUIElement;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: Exact
// Prey/GameDll/ark/worldui/ArkInteractiveScreen.h
class ArkInteractiveScreen : public CGameObjectExtensionHelper<ArkInteractiveScreen,IGameObjectExtension>, public IArkPlayerInteractionListener, public IArkDisruptableListener // Id=80163C2 Size=456
{
public:
	QuatT m_sparkLoc;
	bool m_bHidInteractionPrompt;
	bool m_bCollisionInteraction;
	bool m_bPowered;
	bool m_bLookingAt;
	ArkAutoResetTimer m_clockTimer;
	ArkWorldUIOwner m_worldUIOwner;
	ArkDisruptable m_disruptable;
	ArkDisruptableSignalReceiver m_disruptableSignalReceiver;
	string m_model;
	bool m_bStartsPowered;
	
	ArkInteractiveScreen();
	virtual ~ArkInteractiveScreen();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual void PostReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual void OnWorldUISetup();
	virtual void OnWorldUIDestroyed();
	virtual void SetupStaticMaterial();
	virtual void OnWorldUIInstanceGranted(IUIElement *_pUIInstance);
	virtual void OnWorldUIInstanceRevoked(IUIElement *_pUIInstance);
	virtual bool IsPowered() const;
	virtual bool OnWorldUIBack();
	virtual void OnForceInteraction();
	virtual void EnableCollisions();
	virtual EArkInteractiveScreenType GetInteractiveScreenType() const;
	virtual bool GrantInstances() const;
	bool OnWorldUIRequestUpdateClock(const float _frameTime) { return FOnWorldUIRequestUpdateClock(this,_frameTime); }
	virtual bool PopulateRemoteManipulationInteraction(IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo) const;
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnStopLookingAt(unsigned _targetId);
	virtual void SetPowered(bool _bPowered, bool _bForce);
	virtual bool HasClock() const;
	virtual void LoadProperties();
	virtual void OnReset(bool _bEnteringGameMode);
	void UnregisterOnWorldUI() { FUnregisterOnWorldUI(this); }
	virtual bool IsEnabled() const;
	virtual void OnEnabledChanged(bool _bForce);
	virtual bool IsProcessing() const;
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual void OnInterferenceChanged(bool _bInterfered);
	virtual QuatT GetSparkLoc() const;
	void UpdateLinkedLights() const { FUpdateLinkedLights(this); }
	
#if 0
	ArkWorldUIOwner &GetWorldUIOwner();
	ArkDisruptable &GetDisruptable();
	void RegisterOnWorldUI();
	void DisableInteractionPrompt(bool arg0, unsigned arg1);
#endif
	
	static inline auto FBitNotArkInteractiveScreen = PreyFunction<void(ArkInteractiveScreen *const _this)>(0x1397A50);
	static inline auto FInit = PreyFunction<bool(ArkInteractiveScreen *const _this, IGameObject *_pGameObject)>(0x1397EC0);
	static inline auto FInitClient = PreyFunction<void(ArkInteractiveScreen *const _this, int channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(ArkInteractiveScreen *const _this, IGameObject *_pGameObject)>(0x13989F0);
	static inline auto FPostInitClient = PreyFunction<void(ArkInteractiveScreen *const _this, int channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkInteractiveScreen *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkInteractiveScreen *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkInteractiveScreen *const _this, TSerialize signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(ArkInteractiveScreen *const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(ArkInteractiveScreen *const _this, TSerialize _ser)>(0x1397CA0);
	static inline auto FNetSerialize = PreyFunction<bool(ArkInteractiveScreen *const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkInteractiveScreen *const _this)>(0x1399120);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkInteractiveScreen *const _this, TSerialize ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkInteractiveScreen *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkInteractiveScreen *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x13992C0);
	static inline auto FPostUpdate = PreyFunction<void(ArkInteractiveScreen *const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkInteractiveScreen *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkInteractiveScreen *const _this, SGameObjectEvent const &_event)>(0x1397E70);
	static inline auto FProcessEvent = PreyFunction<void(ArkInteractiveScreen *const _this, SEntityEvent &_event)>(0x1399180);
	static inline auto FSetChannelId = PreyFunction<void(ArkInteractiveScreen *const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkInteractiveScreen *const _this, bool auth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkInteractiveScreen const *const _this, ICrySizer *s)>(0xA13080);
	static inline auto FOnWorldUISetup = PreyFunction<void(ArkInteractiveScreen *const _this)>(0xA13080);
	static inline auto FOnWorldUIDestroyed = PreyFunction<void(ArkInteractiveScreen *const _this)>(0x1398650);
	static inline auto FSetupStaticMaterial = PreyFunction<void(ArkInteractiveScreen *const _this)>(0xA13080);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkInteractiveScreen *const _this, IUIElement *_pUIInstance)>(0x1398680);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkInteractiveScreen *const _this, IUIElement *_pUIInstance)>(0x13986D0);
	static inline auto FIsPowered = PreyFunction<bool(ArkInteractiveScreen const *const _this)>(0x1163850);
	static inline auto FOnWorldUIBack = PreyFunction<bool(ArkInteractiveScreen *const _this)>(0xDD23F0);
	static inline auto FOnForceInteraction = PreyFunction<void(ArkInteractiveScreen *const _this)>(0x13984A0);
	static inline auto FEnableCollisions = PreyFunction<void(ArkInteractiveScreen *const _this)>(0x1397C50);
	static inline auto FGetInteractiveScreenType = PreyFunction<EArkInteractiveScreenType(ArkInteractiveScreen const *const _this)>(0xC36440);
	static inline auto FGrantInstances = PreyFunction<bool(ArkInteractiveScreen const *const _this)>(0x1B933B0);
	static inline auto FOnWorldUIRequestUpdateClock = PreyFunction<bool(ArkInteractiveScreen *const _this, const float _frameTime)>(0x1398720);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(ArkInteractiveScreen const *const _this, IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo)>(0x1398970);
	static inline auto FOnInteraction = PreyFunction<bool(ArkInteractiveScreen *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x13984F0);
	static inline auto FOnStartLookingAt = PreyFunction<void(ArkInteractiveScreen *const _this, unsigned _targetId)>(0x13985F0);
	static inline auto FOnStopLookingAt = PreyFunction<void(ArkInteractiveScreen *const _this, unsigned _targetId)>(0x1398600);
	static inline auto FSetPowered = PreyFunction<void(ArkInteractiveScreen *const _this, bool _bPowered, bool _bForce)>(0x1399220);
	static inline auto FHasClock = PreyFunction<bool(ArkInteractiveScreen const *const _this)>(0xDD23F0);
	static inline auto FLoadProperties = PreyFunction<void(ArkInteractiveScreen *const _this)>(0x1397F20);
	static inline auto FOnReset = PreyFunction<void(ArkInteractiveScreen *const _this, bool _bEnteringGameMode)>(0x1398560);
	static inline auto FUnregisterOnWorldUI = PreyFunction<void(ArkInteractiveScreen *const _this)>(0x1398650);
	static inline auto FIsEnabled = PreyFunction<bool(ArkInteractiveScreen const *const _this)>(0x1397F00);
	static inline auto FOnEnabledChanged = PreyFunction<void(ArkInteractiveScreen *const _this, bool _bForce)>(0x1398230);
	static inline auto FIsProcessing = PreyFunction<bool(ArkInteractiveScreen const *const _this)>(0xDD23F0);
	static inline auto FOnDisruptedChanged = PreyFunction<void(ArkInteractiveScreen *const _this, bool _bDisrupted, bool _bWasForced)>(0x1398210);
	static inline auto FOnInterferenceChanged = PreyFunction<void(ArkInteractiveScreen *const _this, bool _bInterfered)>(0x1398540);
	static inline auto FGetSparkLoc = PreyFunction<QuatT(ArkInteractiveScreen const *const _this)>(0x1397E40);
	static inline auto FUpdateLinkedLights = PreyFunction<void(ArkInteractiveScreen const *const _this)>(0x13992E0);
};

// Header: FromCpp
// Prey/GameDll/ark/worldui/arkinteractivescreen.h
class ArkWorldUI : public CArkGameObjectExtension<ArkWorldUI> // Id=801BCF1 Size=64
{
public:
	virtual bool Init(IGameObject *_pGameObject);
	virtual void Release();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	void EnableCollisions() { FEnableCollisions(this); }
	virtual ~ArkWorldUI();
	
	static inline auto FInit = PreyFunction<bool(ArkWorldUI *const _this, IGameObject *_pGameObject)>(0x13CACC0);
	static inline auto FRelease = PreyFunction<void(ArkWorldUI *const _this)>(0xA97D40);
	static inline auto FHandleEvent = PreyFunction<void(ArkWorldUI *const _this, SGameObjectEvent const &_event)>(0x13ACD10);
	static inline auto FEnableCollisions = PreyFunction<void(ArkWorldUI *const _this)>(0x1397C50);
};

