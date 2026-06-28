// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/ArkDisruptableSignalReceiver.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <_unknown/ArkMaterialParamOverride.h>

class ArkInteractiveScreen;
enum class EArkInteractionMode;
enum class EArkInteractionType;
enum class EArkWorldUIMaterialOverride;
struct EventPhysCollision;
struct IEntity;
struct IUIElement;
struct SEntityEvent;

// ArkWorldUIOwner
// Header:  Prey/GameDll/ark/worldui/ArkWorldUIOwner.h
class ArkWorldUIOwner
	: public IEntityEventListener
	, public IUIElementEventListener
	, public IArkPlayerInteractionListener
{ // Size=168 (0xA8)
public:
	unsigned m_worldUI;
	ArkInteractiveScreen& m_interactiveScreen;
	ArkDisruptableSignalReceiver m_signalReceiver;
	std::vector<ArkMaterialParamOverride> m_originalInterferenceValues;
	std::vector<enum::EArkWorldUIMaterialOverride> m_materialOverrideStack;
	string m_screenBoneName;
	int m_subMatIndex;
	float m_interactDistance;
	float m_activeDistance;
	float m_interactAngle;
	string m_screenModel;
	string m_uiElementName;
	IUIElement* m_pUIInstance;
	bool m_bPoolInstance;
	bool m_bCollisionInteraction;

	ArkWorldUIOwner(ArkInteractiveScreen& _screen);
	virtual ~ArkWorldUIOwner();
	bool OnWorldUIBack() { return FOnWorldUIBack(this); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	void OnWorldUIInstanceGranted(IUIElement* _pUIInstance) { FOnWorldUIInstanceGranted(this, _pUIInstance); }
	void OnWorldUIInstanceRevoked(IUIElement* _pUIInstance) { FOnWorldUIInstanceRevoked(this, _pUIInstance); }
	unsigned GetOwnerId() const { return FGetOwnerId(this); }
	bool HasClock() const { return FHasClock(this); }
	bool RequestUpdateClock(const float _frameTime) { return FRequestUpdateClock(this, _frameTime); }
	bool IsPowered() const { return FIsPowered(this); }
	bool IsValid() const { return FIsValid(this); }
	void CreateAndSetupWorldUI() { FCreateAndSetupWorldUI(this); }
	void LoadWorldUIProperties() { FLoadWorldUIProperties(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnReset(bool _bEnteringGameMode) { FOnReset(this, _bEnteringGameMode); }
	void OnInterferenceChanged(bool _bInterfered) { FOnInterferenceChanged(this, _bInterfered); }
	virtual void OnInstanceDestroyed(IUIElement* pSender, IUIElement* pDeletedInstance);
	void OnCollisionEvent(const EventPhysCollision* _pCollisionEvent, IEntity* _pOtherEntity) { FOnCollisionEvent(this, _pCollisionEvent, _pOtherEntity); }
	void OverrideMaterialParams(EArkWorldUIMaterialOverride _type) { FOverrideMaterialParams(this, _type); }
	void ClearMaterialOverrides(EArkWorldUIMaterialOverride _type) { FClearMaterialOverrides(this, _type); }
	QuatT GetScreenLoc() const { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FGetScreenLoc(this, reinterpret_cast<QuatT*>(_return_buf_)); }
	void SetupWorldUI(IEntity* const _pScreen) { FSetupWorldUI(this, _pScreen); }
	void CleanupWorldUIInstance() { FCleanupWorldUIInstance(this); }
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	void RegisterOnWorldUI() { FRegisterOnWorldUI(this); }
	void UnregisterOnWorldUI() { FUnregisterOnWorldUI(this); }
	void RefreshMaterialOverrides() { FRefreshMaterialOverrides(this); }

#if 0
	IUIElement* GetUIInstance() const;
	unsigned GetWorldUIEntity() const;
	float GetInteractAngle();
#endif

	static inline auto FArkWorldUIOwnerOv1 = PreyFunction<void(ArkWorldUIOwner* const _this, ArkInteractiveScreen& _screen)>(0x14BC730);
	static inline auto FBitNotArkWorldUIOwner = PreyFunction<void(ArkWorldUIOwner* const _this)>(0x14BC800);
	static inline auto FOnWorldUIBack = PreyFunction<bool(ArkWorldUIOwner* const _this)>(0x14BDE70);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkWorldUIOwner* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x14BDB60);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkWorldUIOwner* const _this, IUIElement* _pUIInstance)>(0x14BDE90);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkWorldUIOwner* const _this, IUIElement* _pUIInstance)>(0x14BE1C0);
	static inline auto FGetOwnerId = PreyFunction<unsigned(const ArkWorldUIOwner* const _this)>(0x152FC20);
	static inline auto FHasClock = PreyFunction<bool(const ArkWorldUIOwner* const _this)>(0x14BD600);
	static inline auto FRequestUpdateClock = PreyFunction<bool(ArkWorldUIOwner* const _this, const float _frameTime)>(0x14BE5D0);
	static inline auto FIsPowered = PreyFunction<bool(const ArkWorldUIOwner* const _this)>(0x14BD610);
	static inline auto FIsValid = PreyFunction<bool(const ArkWorldUIOwner* const _this)>(0x14BD620);
	static inline auto FCreateAndSetupWorldUI = PreyFunction<void(ArkWorldUIOwner* const _this)>(0x14BCCB0);
	static inline auto FLoadWorldUIProperties = PreyFunction<void(ArkWorldUIOwner* const _this)>(0x14BD630);
	static inline auto FSerialize = PreyFunction<void(ArkWorldUIOwner* const _this, TSerialize _ser)>(0x14BE5E0);
	static inline auto FPostSerialize = PreyFunction<void(ArkWorldUIOwner* const _this)>(0x14BE2F0);
	static inline auto FOnReset = PreyFunction<void(ArkWorldUIOwner* const _this, bool _bEnteringGameMode)>(0x14BDE10);
	static inline auto FOnInterferenceChanged = PreyFunction<void(ArkWorldUIOwner* const _this, bool _bInterfered)>(0x14BDC30);
	static inline auto FOnInstanceDestroyed = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* pSender, IUIElement* pDeletedInstance)>(0x14BDB90);
	static inline auto FOnCollisionEvent = PreyFunction<void(ArkWorldUIOwner* const _this, const EventPhysCollision* _pCollisionEvent, IEntity* _pOtherEntity)>(0x14BDA20);
	static inline auto FOverrideMaterialParams = PreyFunction<void(ArkWorldUIOwner* const _this, EArkWorldUIMaterialOverride _type)>(0x14BE260);
	static inline auto FClearMaterialOverrides = PreyFunction<void(ArkWorldUIOwner* const _this, EArkWorldUIMaterialOverride _type)>(0x14BCB50);
	static inline auto FGetScreenLoc = PreyFunction<QuatT*(const ArkWorldUIOwner* const _this, QuatT* _return_value_)>(0x14BCF50);
	static inline auto FSetupWorldUI = PreyFunction<void(ArkWorldUIOwner* const _this, IEntity* const _pScreen)>(0x14BE640);
	static inline auto FCleanupWorldUIInstance = PreyFunction<void(ArkWorldUIOwner* const _this)>(0x14BCA30);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x14BDBB0);
	static inline auto FRegisterOnWorldUI = PreyFunction<void(ArkWorldUIOwner* const _this)>(0x14BE560);
	static inline auto FUnregisterOnWorldUI = PreyFunction<void(ArkWorldUIOwner* const _this)>(0x14BE8E0);
	static inline auto FRefreshMaterialOverrides = PreyFunction<void(ArkWorldUIOwner* const _this)>(0x14BE330);
};
#endif // !MOONCRASH
