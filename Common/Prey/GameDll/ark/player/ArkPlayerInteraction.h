// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkEntityGrabber.h>
#include <Prey/GameDll/ark/ArkInteractionTestResult.h>
#include <Prey/GameDll/ark/player/ArkPlayerCarry.h>
#include <Prey/GameDll/ark/player/ArkPlayerTargetSelector.h>
#include <Prey/GameDll/ark/ui/ArkButtonPromptCollection.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>
#include <Prey/GameDll/ark/ui/ArkInputLegendHandler.h>
#include <Prey/GameDll/ark/ui/ArkInventoryPreview.h>

struct ArkInteractionInfo;
class CCryName;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerInteraction.h
class ArkPlayerInteraction // Id=801744F Size=1768
{
public:
	ArkEntityGrabber m_remoteItemGrabber;
	ArkPlayerCarry m_playerCarry;
	std::array<ArkInteractionInfo,4> m_interactionInfo;
	std::array<bool,4> m_interactionHidden;
	ArkPlayerTargetSelector m_targetSelector;
	ArkInventoryPreview m_inventoryPreview;
	ArkSimpleTimer m_carryDelay;
	int m_disableInteractionPromptCount;
	unsigned m_usableEntityId;
	bool m_bCanClimb;
	bool m_bHideFailedAbilityInteractions;
	ArkButtonPromptCollection m_buttonPrompts;
	ArkInputLegend m_alternativePrompts;
	ArkInputLegendHandler m_alternativePromptHandler;
	
	ArkPlayerInteraction();
	static EArkInteractionType GetInteractionTypeFromString(const char *_string) { return FGetInteractionTypeFromString(_string); }
	static bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) { return FPopulateInteractionInfo(_pEntity,_interactionArray); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void PreSerialize() { FPreSerialize(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void Reset() { FReset(this); }
	static uint64_t GetEntityHackingRequirement(IEntity const *const _pEntity) { return FGetEntityHackingRequirement(_pEntity); }
	static uint64_t GetEntityCarryRequirement(IEntity const *const _pEntity) { return FGetEntityCarryRequirement(_pEntity); }
	EArkInteractionType GetInteractionType(EArkInteractionMode _mode) const { return FGetInteractionType(this,_mode); }
	bool GetInteractionHidden(EArkInteractionMode _mode) const { return FGetInteractionHidden(this,_mode); }
	bool Interact(EArkInteractionMode _interactMode) { return FInteract(this,_interactMode); }
	void ViewTutorial() { FViewTutorial(this); }
	void StopHoldToUseInteract() { FStopHoldToUseInteract(this); }
	void StopSpecialUseInteract() { FStopSpecialUseInteract(this); }
	bool HasValidInteractionInfo() const { return FHasValidInteractionInfoOv1(this); }
	ArkInteractionTestResult TestInteractionType(IEntity const *const _pEntity, EArkInteractionMode _interactionMode, ArkInteractionInfo const &_interactionInfo) const { return FTestInteractionType(this,_pEntity,_interactionMode,_interactionInfo); }
	void PerformInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity, float _delay) { FPerformInteraction(this,_interaction,_mode,_pEntity,_delay); }
	void ProcessInput(CCryName const &_actionId, const int _activationMode, const float _value) { FProcessInput(this,_actionId,_activationMode,_value); }
	void DisableInteractionPrompt(bool _bDisable) { FDisableInteractionPrompt(this,_bDisable); }
	void TriggerGameStateInteraction(IEntity const *const _pEntity) const { FTriggerGameStateInteraction(this,_pEntity); }
	static bool TestWorldUI(IEntity const *_pEntity, bool &_bHideLine) { return FTestWorldUI(_pEntity,_bHideLine); }
	static IEntity const *GetOwningEntity(IEntity const *_pEntity) { return FGetOwningEntity(_pEntity); }
	static uint64_t GetPromptTutorial(IEntity const *_pEntity) { return FGetPromptTutorial(_pEntity); }
	
#if 0
	static const char *GetStringForInteractionMode(EArkInteractionMode arg0);
	static bool HasValidInteractionInfo(std::array<ArkInteractionInfo,4> const &arg0);
	void SetHideFailedAbilityInteractions(bool arg0);
	ArkPlayerCarry &GetCarry();
	ArkPlayerCarry const &GetCarry() const;
	ArkPlayerTargetSelector &GetTargetSelector();
	ArkPlayerTargetSelector const &GetTargetSelector() const;
	ArkInventoryPreview &GetInventoryPreview();
	ArkInventoryPreview const &GetInventoryPreview() const;
	unsigned GetUsableEntity() const;
	static bool HasInteraction(IEntity const *const arg0);
	ArkEntityGrabber &GetRemoteItemGrabber();
	bool IsInteractionPromptDisabled() const;
	static void ClearInteractionInfo(std::array<ArkInteractionInfo,4> &arg0);
	bool IsPlayerStandingOnEntity(IEntity const *arg0) const;
	bool IsInteractionAllowed(IEntity const *const arg0) const;
#endif
	
	static inline auto FGetInteractionTypeFromString = PreyFunction<EArkInteractionType(const char *_string)>(0x1566550);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x1566EE0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerInteraction *const _this, float _frameTime)>(0x1567FB0);
	static inline auto FPreSerialize = PreyFunction<void(ArkPlayerInteraction *const _this)>(0x1567430);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerInteraction *const _this, TSerialize _ser)>(0x15675D0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerInteraction *const _this)>(0x1567420);
	static inline auto FReset = PreyFunction<void(ArkPlayerInteraction *const _this)>(0x15675A0);
	static inline auto FGetEntityHackingRequirement = PreyFunction<uint64_t(IEntity const *const _pEntity)>(0x1566350);
	static inline auto FGetEntityCarryRequirement = PreyFunction<uint64_t(IEntity const *const _pEntity)>(0x1566220);
	static inline auto FGetInteractionType = PreyFunction<EArkInteractionType(ArkPlayerInteraction const *const _this, EArkInteractionMode _mode)>(0x1566540);
	static inline auto FGetInteractionHidden = PreyFunction<bool(ArkPlayerInteraction const *const _this, EArkInteractionMode _mode)>(0x1566530);
	static inline auto FInteract = PreyFunction<bool(ArkPlayerInteraction *const _this, EArkInteractionMode _interactMode)>(0x1566820);
	static inline auto FViewTutorial = PreyFunction<void(ArkPlayerInteraction *const _this)>(0x1569740);
	static inline auto FStopHoldToUseInteract = PreyFunction<void(ArkPlayerInteraction *const _this)>(0x1567640);
	static inline auto FStopSpecialUseInteract = PreyFunction<void(ArkPlayerInteraction *const _this)>(0x15678D0);
	static inline auto FHasValidInteractionInfoOv1 = PreyFunction<bool(ArkPlayerInteraction const *const _this)>(0x15667F0);
	static inline auto FTestInteractionType = PreyFunction<ArkInteractionTestResult(ArkPlayerInteraction const *const _this, IEntity const *const _pEntity, EArkInteractionMode _interactionMode, ArkInteractionInfo const &_interactionInfo)>(0x15679F0);
	static inline auto FPerformInteraction = PreyFunction<void(ArkPlayerInteraction *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity, float _delay)>(0x1566B10);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerInteraction *const _this, CCryName const &_actionId, const int _activationMode, const float _value)>(0x1567540);
	static inline auto FDisableInteractionPrompt = PreyFunction<void(ArkPlayerInteraction *const _this, bool _bDisable)>(0x1566160);
	static inline auto FTriggerGameStateInteraction = PreyFunction<void(ArkPlayerInteraction const *const _this, IEntity const *const _pEntity)>(0x1567F40);
	static inline auto FTestWorldUI = PreyFunction<bool(IEntity const *_pEntity, bool &_bHideLine)>(0x1567EC0);
	static inline auto FGetOwningEntity = PreyFunction<IEntity const *(IEntity const *_pEntity)>(0x15665B0);
	static inline auto FGetPromptTutorial = PreyFunction<uint64_t(IEntity const *_pEntity)>(0x1566610);
};

