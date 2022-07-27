// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/worldui/ArkInteractiveScreen.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
struct IEntity;
struct IGameObject;
struct IUIElement;
struct SEntityEvent;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/worldui/ArkKeyWorldUI.h
class ArkKeyWorldUI : public ArkInteractiveScreen, public ArkUIMenuBase<ArkKeyWorldUI> // Id=801BC6C Size=536
{
public:
	bool m_bLocked;
	unsigned m_door;
	string m_interactMessage;
	string m_powerOffDisplayName;
	_smart_ptr<IMaterial> m_pLockedMaterial;
	_smart_ptr<IMaterial> m_pUnlockedMaterial;
	_smart_ptr<IMaterial> m_pPowerOffMaterial;
	bool m_bStartsLocked;
	
	ArkKeyWorldUI();
	virtual ~ArkKeyWorldUI();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual void SetupStaticMaterial();
	virtual void OnWorldUIInstanceGranted(IUIElement *_pUIInstance);
	virtual void OnWorldUIInstanceRevoked(IUIElement *_pUIInstance);
	void LinkToDoor(unsigned _doorId) { FLinkToDoor(this,_doorId); }
	virtual bool SetLocked(bool _bLocked, bool _bForce);
	virtual void OnButtonPress(IUIElement *const arg0, SUIEventDesc const &arg1, SUIArguments const &arg2) = 0;
	void OnSoundEvent(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSoundEvent(this,_pSender,_event,_args); }
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual void LoadInstanceProperties();
	bool CopyInstancePropertiesFromDoor() { return FCopyInstancePropertiesFromDoor(this); }
	virtual bool UseLockedMaterial() const;
	virtual void OnEnabledChanged(bool _bForce);
	virtual const char *GetInteractFunctionName() const = 0;
	
	static inline auto FBitNotArkKeyWorldUI = PreyFunction<void(ArkKeyWorldUI *const _this)>(0x139C850);
	static inline auto FPostInit = PreyFunction<void(ArkKeyWorldUI *const _this, IGameObject *_pGameObject)>(0x139D970);
	static inline auto FFullSerialize = PreyFunction<void(ArkKeyWorldUI *const _this, TSerialize _ser)>(0x139CD70);
	static inline auto FProcessEvent = PreyFunction<void(ArkKeyWorldUI *const _this, SEntityEvent &_event)>(0x139DD30);
	static inline auto FOnInteraction = PreyFunction<bool(ArkKeyWorldUI *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x139D4E0);
	static inline auto FTestInteraction = PreyFunction<bool(ArkKeyWorldUI const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x139DEC0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkKeyWorldUI const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x139D8E0);
	static inline auto FSetupStaticMaterial = PreyFunction<void(ArkKeyWorldUI *const _this)>(0x139DE40);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkKeyWorldUI *const _this, IUIElement *_pUIInstance)>(0x139D830);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkKeyWorldUI *const _this, IUIElement *_pUIInstance)>(0x139D8A0);
	static inline auto FLinkToDoor = PreyFunction<void(ArkKeyWorldUI *const _this, unsigned _doorId)>(0x139CDE0);
	static inline auto FSetLocked = PreyFunction<bool(ArkKeyWorldUI *const _this, bool _bLocked, bool _bForce)>(0x139DD80);
	static inline auto FOnSoundEvent = PreyFunction<void(ArkKeyWorldUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x139D6D0);
	static inline auto FOnReset = PreyFunction<void(ArkKeyWorldUI *const _this, bool _bEnteringGameMode)>(0x139D690);
	static inline auto FLoadProperties = PreyFunction<void(ArkKeyWorldUI *const _this)>(0x139CFB0);
	static inline auto FLoadInstanceProperties = PreyFunction<void(ArkKeyWorldUI *const _this)>(0x139CE30);
	static inline auto FCopyInstancePropertiesFromDoor = PreyFunction<bool(ArkKeyWorldUI *const _this)>(0x139CBC0);
	static inline auto FUseLockedMaterial = PreyFunction<bool(ArkKeyWorldUI const *const _this)>(0x139C710);
	static inline auto FOnEnabledChanged = PreyFunction<void(ArkKeyWorldUI *const _this, bool _bForce)>(0x139D470);
};

