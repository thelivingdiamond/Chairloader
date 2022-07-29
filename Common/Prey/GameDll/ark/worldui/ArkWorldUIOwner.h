// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDisruptableSignalReceiver.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <Prey/GameDll/ark/ui/IUIElementEventListener.h>

class ArkInteractiveScreen;
struct EventPhysCollision;
struct IEntity;
struct IUIElement;
struct SEntityEvent;

// Header: FromCpp
// Prey/GameDll/ark/worldui/ArkWorldUIOwner.h
class ArkWorldUIOwner : public IEntityEventListener, public IUIElementEventListener, public IArkPlayerInteractionListener // Id=80163C1 Size=144
{
public:
	unsigned m_worldUI;
	ArkInteractiveScreen &m_interactiveScreen;
	ArkDisruptableSignalReceiver m_signalReceiver;
	std::vector<ArkMaterialParamOverride> m_originalInterferenceValues;
	string m_screenBoneName;
	int m_subMatIndex;
	float m_interactDistance;
	float m_activeDistance;
	float m_interactAngle;
	string m_screenModel;
	string m_uiElementName;
	IUIElement *m_pUIInstance;
	bool m_bPoolInstance;
	bool m_bCollisionInteraction;
	
	ArkWorldUIOwner(ArkInteractiveScreen &_screen);
	virtual ~ArkWorldUIOwner();
	bool OnWorldUIBack() { return FOnWorldUIBack(this); }
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	void OnWorldUIInstanceGranted(IUIElement *_pUIInstance) { FOnWorldUIInstanceGranted(this,_pUIInstance); }
	void OnWorldUIInstanceRevoked(IUIElement *_pUIInstance) { FOnWorldUIInstanceRevoked(this,_pUIInstance); }
	unsigned GetOwnerId() const { return FGetOwnerId(this); }
	bool HasClock() const { return FHasClock(this); }
	bool RequestUpdateClock(const float _frameTime) { return FRequestUpdateClock(this,_frameTime); }
	bool IsPowered() const { return FIsPowered(this); }
	bool IsValid() const { return FIsValid(this); }
	void CreateAndSetupWorldUI() { FCreateAndSetupWorldUI(this); }
	void LoadWorldUIProperties() { FLoadWorldUIProperties(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnReset(bool _bEnteringGameMode) { FOnReset(this,_bEnteringGameMode); }
	void OnInterferenceChanged(bool _bInterfered) { FOnInterferenceChanged(this,_bInterfered); }
	virtual void OnInstanceDestroyed(IUIElement *pSender, IUIElement *pDeletedInstance);
	void OnCollisionEvent(EventPhysCollision const *_pCollisionEvent, IEntity *_pOtherEntity) { FOnCollisionEvent(this,_pCollisionEvent,_pOtherEntity); }
	QuatT GetScreenLoc() const { return FGetScreenLoc(this); }
	void SetupWorldUI(IEntity *const _pScreen) { FSetupWorldUI(this,_pScreen); }
	void CleanupWorldUIInstance() { FCleanupWorldUIInstance(this); }
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	void RegisterOnWorldUI() { FRegisterOnWorldUI(this); }
	void UnregisterOnWorldUI() { FUnregisterOnWorldUI(this); }
	
#if 0
	IUIElement *GetUIInstance() const;
	unsigned GetWorldUIEntity() const;
	float GetInteractAngle();
#endif
	
	static inline auto FBitNotArkWorldUIOwner = PreyFunction<void(ArkWorldUIOwner *const _this)>(0x13B0A90);
	static inline auto FOnWorldUIBack = PreyFunction<bool(ArkWorldUIOwner *const _this)>(0x13B1EE0);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkWorldUIOwner *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x13B1C80);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkWorldUIOwner *const _this, IUIElement *_pUIInstance)>(0x13B1F00);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkWorldUIOwner *const _this, IUIElement *_pUIInstance)>(0x13B2220);
	static inline auto FGetOwnerId = PreyFunction<unsigned(ArkWorldUIOwner const *const _this)>(0x13B1060);
	static inline auto FHasClock = PreyFunction<bool(ArkWorldUIOwner const *const _this)>(0x13B1720);
	static inline auto FRequestUpdateClock = PreyFunction<bool(ArkWorldUIOwner *const _this, const float _frameTime)>(0x13B2370);
	static inline auto FIsPowered = PreyFunction<bool(ArkWorldUIOwner const *const _this)>(0x13B1730);
	static inline auto FIsValid = PreyFunction<bool(ArkWorldUIOwner const *const _this)>(0x13B1740);
	static inline auto FCreateAndSetupWorldUI = PreyFunction<void(ArkWorldUIOwner *const _this)>(0x13B0DC0);
	static inline auto FLoadWorldUIProperties = PreyFunction<void(ArkWorldUIOwner *const _this)>(0x13B1750);
	static inline auto FSerialize = PreyFunction<void(ArkWorldUIOwner *const _this, TSerialize _ser)>(0x13B2380);
	static inline auto FPostSerialize = PreyFunction<void(ArkWorldUIOwner *const _this)>(0x13B22C0);
	static inline auto FOnReset = PreyFunction<void(ArkWorldUIOwner *const _this, bool _bEnteringGameMode)>(0x13B1E80);
	static inline auto FOnInterferenceChanged = PreyFunction<void(ArkWorldUIOwner *const _this, bool _bInterfered)>(0x13B1D40);
	static inline auto FOnInstanceDestroyed = PreyFunction<void(ArkWorldUIOwner *const _this, IUIElement *pSender, IUIElement *pDeletedInstance)>(0x13B1CB0);
	static inline auto FOnCollisionEvent = PreyFunction<void(ArkWorldUIOwner *const _this, EventPhysCollision const *_pCollisionEvent, IEntity *_pOtherEntity)>(0x13B1B40);
	static inline auto FGetScreenLoc = PreyFunction<QuatT(ArkWorldUIOwner const *const _this)>(0x13B1070);
	static inline auto FSetupWorldUI = PreyFunction<void(ArkWorldUIOwner *const _this, IEntity *const _pScreen)>(0x13B23E0);
	static inline auto FCleanupWorldUIInstance = PreyFunction<void(ArkWorldUIOwner *const _this)>(0x13B0CA0);
	static inline auto FOnInteraction = PreyFunction<bool(ArkWorldUIOwner *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x13B1CC0);
	static inline auto FRegisterOnWorldUI = PreyFunction<void(ArkWorldUIOwner *const _this)>(0x13B2300);
	static inline auto FUnregisterOnWorldUI = PreyFunction<void(ArkWorldUIOwner *const _this)>(0x13B2680);
};

