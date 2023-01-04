// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkEntityGrabber.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/ArkPlayerCarry.h>
#include <Prey/GameDll/ark/player/ArkPlayerTargetSelector.h>
#include <Prey/GameDll/ark/ui/ArkButtonPromptCollection.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>
#include <Prey/GameDll/ark/ui/ArkInputLegendHandler.h>
#include <Prey/GameDll/ark/ui/ArkInventoryPreview.h>
#include <Prey/GameDll/ark/ArkInteractionTestResult.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
class CCryName;
enum class EArkInteractionMode;
enum class EArkInteractionType;
struct IEntity;

// ArkPlayerInteraction
// Header:  Prey/GameDll/ark/player/ArkPlayerInteraction.h
class ArkPlayerInteraction
{ // Size=1768 (0x6E8)
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
	static EArkInteractionType GetInteractionTypeFromString(const char* _string) { return FGetInteractionTypeFromString(_string); }
	static bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo,4>& _interactionArray) { return FPopulateInteractionInfo(_pEntity, _interactionArray); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void PreSerialize() { FPreSerialize(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void Reset() { FReset(this); }
	static uint64_t GetEntityHackingRequirement(const IEntity* const _pEntity) { return FGetEntityHackingRequirement(_pEntity); }
	static uint64_t GetEntityCarryRequirement(const IEntity* const _pEntity) { return FGetEntityCarryRequirement(_pEntity); }
	EArkInteractionType GetInteractionType(EArkInteractionMode _mode) const { return FGetInteractionType(this, _mode); }
	bool GetInteractionHidden(EArkInteractionMode _mode) const { return FGetInteractionHidden(this, _mode); }
	bool Interact(EArkInteractionMode _interactMode) { return FInteract(this, _interactMode); }
	void ViewTutorial() { FViewTutorial(this); }
	void StopHoldToUseInteract() { FStopHoldToUseInteract(this); }
	void StopSpecialUseInteract() { FStopSpecialUseInteract(this); }
	bool HasValidInteractionInfo() const { return FHasValidInteractionInfoOv1(this); }
	ArkInteractionTestResult TestInteractionType(const IEntity* const _pEntity, const EArkInteractionMode _interactionMode, const ArkInteractionInfo& _interactionInfo) const { alignas(ArkInteractionTestResult) std::byte _return_buf_[sizeof(ArkInteractionTestResult)]; return *FTestInteractionType(this, reinterpret_cast<ArkInteractionTestResult*>(_return_buf_), _pEntity, _interactionMode, _interactionInfo); }
	void PerformInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity, float _delay) { FPerformInteraction(this, _interaction, _mode, _pEntity, _delay); }
	void ProcessInput(const CCryName& _actionId, const int _activationMode, const float _value) { FProcessInput(this, _actionId, _activationMode, _value); }
	void DisableInteractionPrompt(bool _bDisable) { FDisableInteractionPrompt(this, _bDisable); }
	void TriggerGameStateInteraction(const IEntity* const _pEntity) const { FTriggerGameStateInteraction(this, _pEntity); }
	static bool TestWorldUI(const IEntity* _pEntity, bool& _bHideLine) { return FTestWorldUI(_pEntity, _bHideLine); }
	static const IEntity* GetOwningEntity(const IEntity* _pEntity) { return FGetOwningEntity(_pEntity); }
	static uint64_t GetPromptTutorial(const IEntity* _pEntity) { return FGetPromptTutorial(_pEntity); }

#if 0
	static const char* GetStringForInteractionMode(EArkInteractionMode _arg0_);
	static bool HasValidInteractionInfo(const std::array<ArkInteractionInfo,4>& _arg0_);
	void SetHideFailedAbilityInteractions(bool _arg0_);
	ArkPlayerCarry& GetCarry();
	const ArkPlayerCarry& GetCarry() const;
	ArkPlayerTargetSelector& GetTargetSelector();
	const ArkPlayerTargetSelector& GetTargetSelector() const;
	ArkInventoryPreview& GetInventoryPreview();
	const ArkInventoryPreview& GetInventoryPreview() const;
	unsigned GetUsableEntity() const;
	static bool HasInteraction(const IEntity* const _arg0_);
	ArkEntityGrabber& GetRemoteItemGrabber();
	bool IsInteractionPromptDisabled() const;
	static void ClearInteractionInfo(std::array<ArkInteractionInfo,4>& _arg0_);
	bool IsPlayerStandingOnEntity(const IEntity* _arg0_) const;
	bool IsInteractionAllowed(const IEntity* const _arg0_) const;
#endif

	static inline auto FArkPlayerInteraction = PreyFunction<void(ArkPlayerInteraction* const _this)>(0x15649C0);
	static inline auto FGetInteractionTypeFromString = PreyFunction<EArkInteractionType(const char* _string)>(0x1566550);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IEntity* const _pEntity, std::array<ArkInteractionInfo,4>& _interactionArray)>(0x1566EE0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerInteraction* const _this, float _frameTime)>(0x1567FB0);
	static inline auto FPreSerialize = PreyFunction<void(ArkPlayerInteraction* const _this)>(0x1567430);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerInteraction* const _this, TSerialize _ser)>(0x15675D0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerInteraction* const _this)>(0x1567420);
	static inline auto FReset = PreyFunction<void(ArkPlayerInteraction* const _this)>(0x15675A0);
	static inline auto FGetEntityHackingRequirement = PreyFunction<uint64_t(const IEntity* const _pEntity)>(0x1566350);
	static inline auto FGetEntityCarryRequirement = PreyFunction<uint64_t(const IEntity* const _pEntity)>(0x1566220);
	static inline auto FGetInteractionType = PreyFunction<EArkInteractionType(const ArkPlayerInteraction* const _this, EArkInteractionMode _mode)>(0x1566540);
	static inline auto FGetInteractionHidden = PreyFunction<bool(const ArkPlayerInteraction* const _this, EArkInteractionMode _mode)>(0x1566530);
	static inline auto FInteract = PreyFunction<bool(ArkPlayerInteraction* const _this, EArkInteractionMode _interactMode)>(0x1566820);
	static inline auto FViewTutorial = PreyFunction<void(ArkPlayerInteraction* const _this)>(0x1569740);
	static inline auto FStopHoldToUseInteract = PreyFunction<void(ArkPlayerInteraction* const _this)>(0x1567640);
	static inline auto FStopSpecialUseInteract = PreyFunction<void(ArkPlayerInteraction* const _this)>(0x15678D0);
	static inline auto FHasValidInteractionInfoOv1 = PreyFunction<bool(const ArkPlayerInteraction* const _this)>(0x15667F0);
	static inline auto FTestInteractionType = PreyFunction<ArkInteractionTestResult*(const ArkPlayerInteraction* const _this, ArkInteractionTestResult* _return_value_, const IEntity* const _pEntity, const EArkInteractionMode _interactionMode, const ArkInteractionInfo& _interactionInfo)>(0x15679F0);
	static inline auto FPerformInteraction = PreyFunction<void(ArkPlayerInteraction* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity, float _delay)>(0x1566B10);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerInteraction* const _this, const CCryName& _actionId, const int _activationMode, const float _value)>(0x1567540);
	static inline auto FDisableInteractionPrompt = PreyFunction<void(ArkPlayerInteraction* const _this, bool _bDisable)>(0x1566160);
	static inline auto FTriggerGameStateInteraction = PreyFunction<void(const ArkPlayerInteraction* const _this, const IEntity* const _pEntity)>(0x1567F40);
	static inline auto FTestWorldUI = PreyFunction<bool(const IEntity* _pEntity, bool& _bHideLine)>(0x1567EC0);
	static inline auto FGetOwningEntity = PreyFunction<const IEntity* (const IEntity* _pEntity)>(0x15665B0);
	static inline auto FGetPromptTutorial = PreyFunction<uint64_t(const IEntity* _pEntity)>(0x1566610);
};

