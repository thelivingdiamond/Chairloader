// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/worldui/ArkInteractiveScreen.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
struct IEntity;
struct IGameObject;
struct IUIElement;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/worldui/ArkKioskBase.h
class ArkKioskBase : public ArkInteractiveScreen, public ArkUIMenuBase<ArkKioskBase> // Id=801B8A0 Size=488
{
public:
	bool m_bUINeedsRefresh;
	
	ArkKioskBase();
	virtual ~ArkKioskBase();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual void OnWorldUIInstanceGranted(IUIElement *_pUIInstance);
	virtual void OnWorldUIInstanceRevoked(IUIElement *_pUIInstance);
	virtual void OnButtonPress(IUIElement *const arg0, SUIEventDesc const &arg1, SUIArguments const &arg2) = 0;
	void OnSoundEvent(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSoundEvent(this,_pSender,_event,_args); }
	virtual void OnReset(bool _bEnteringGameMode);
	void MarkUINeedsRefresh() { FMarkUINeedsRefresh(this); }
	virtual void RefreshUI(bool arg0) = 0;
	virtual void HandleInteraction(IUIElement *arg0) = 0;
	
#if 0
	void RegisterOnWorldUI();
	void UnregisterOnWorldUI();
#endif
	
	static inline auto FBitNotArkKioskBase = PreyFunction<void(ArkKioskBase *const _this)>(0x139F850);
	static inline auto FPostInit = PreyFunction<void(ArkKioskBase *const _this, IGameObject *_pGameObject)>(0x139FF60);
	static inline auto FPostSerialize = PreyFunction<void(ArkKioskBase *const _this)>(0x139FFA0);
	static inline auto FUpdate = PreyFunction<void(ArkKioskBase *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x139FFF0);
	static inline auto FOnInteraction = PreyFunction<bool(ArkKioskBase *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x139FB60);
	static inline auto FTestInteraction = PreyFunction<bool(ArkKioskBase const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x1396B70);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkKioskBase *const _this, IUIElement *_pUIInstance)>(0x139FDC0);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkKioskBase *const _this, IUIElement *_pUIInstance)>(0x139FEA0);
	static inline auto FOnSoundEvent = PreyFunction<void(ArkKioskBase *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x139D6D0);
	static inline auto FOnReset = PreyFunction<void(ArkKioskBase *const _this, bool _bEnteringGameMode)>(0x139FD70);
	static inline auto FMarkUINeedsRefresh = PreyFunction<void(ArkKioskBase *const _this)>(0x139FB20);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/worldui/ArkInteractiveScreen.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
enum class EArkInteractionMode;
enum class EArkInteractionType;
struct IEntity;
struct IGameObject;
struct IUIElement;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// ArkKioskBase
// Header:  Prey/GameDll/ark/worldui/ArkKioskBase.h
class ArkKioskBase : public ArkInteractiveScreen, public ArkUIMenuBase<ArkKioskBase>
{ // Size=512 (0x200)
public:
	bool m_bUINeedsRefresh;

	ArkKioskBase();
	virtual ~ArkKioskBase();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	virtual void OnWorldUIInstanceGranted(IUIElement* _pUIInstance);
	virtual void OnWorldUIInstanceRevoked(IUIElement* _pUIInstance);
	virtual void OnButtonPress(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) = 0;
	void OnSoundEvent(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnSoundEvent(this, _pSender, _event, _args); }
	virtual void OnReset(bool _bEnteringGameMode);
	void MarkUINeedsRefresh() { FMarkUINeedsRefresh(this); }
	virtual void RefreshUI(bool _bReinit) = 0;
	virtual void HandleInteraction(IUIElement* _pUIInstance) = 0;

	static inline auto FArkKioskBaseOv1 = PreyFunction<void(ArkKioskBase* const _this)>(0x14A9F50);
	static inline auto FBitNotArkKioskBase = PreyFunction<void(ArkKioskBase* const _this)>(0x14AA0C0);
	static inline auto FPostInit = PreyFunction<void(ArkKioskBase* const _this, IGameObject* _pGameObject)>(0x14AA500);
	static inline auto FPostSerialize = PreyFunction<void(ArkKioskBase* const _this)>(0x14AA540);
	static inline auto FUpdate = PreyFunction<void(ArkKioskBase* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x14AA590);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x14AA3D0);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x14B5F80);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkKioskBase* const _this, IUIElement* _pUIInstance)>(0x14AA4A0);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkKioskBase* const _this, IUIElement* _pUIInstance)>(0x14A0440);
	static inline auto FOnSoundEvent = PreyFunction<void(ArkKioskBase* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14A0180);
	static inline auto FOnReset = PreyFunction<void(ArkKioskBase* const _this, bool _bEnteringGameMode)>(0x14AA450);
	static inline auto FMarkUINeedsRefresh = PreyFunction<void(ArkKioskBase* const _this)>(0x14AA390);
};
#endif // !MOONCRASH
