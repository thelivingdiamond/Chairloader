// Header file automatically created from a PDB.
#pragma once

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
enum class EArkInteractionMode;
enum class EArkInteractionType;
struct IEntity;

// IArkPlayerInteractionListener
// Header:  Prey/GameDll/ark/player/IArkPlayerInteractionListener.h
class IArkPlayerInteractionListener
{ // Size=8 (0x8)
public:
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity) { return false; }
	virtual bool OnHoldToUseStopped(IEntity* const _pEntity) { return false; }
	virtual bool OnSpecialUseStopped(IEntity* const _pEntity) { return false; }
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result) const { return false; }
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo,4>& _interactionArray) const { return false; }
	virtual bool PopulateRemoteManipulationInteraction(const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo) const { return false; }
	virtual Vec3 GetInteractionPosition(const IEntity* const _pEntity) const { return Vec3(ZERO); }
	virtual void OnStartLookingAt(unsigned _targetId) {}
	virtual void OnStopLookingAt(unsigned _targetId) {}
	virtual void OnInteractionInfoChanged(unsigned _targetId) {}
	virtual bool HideDisplayName(const IEntity* const _pEntity) const { return false; }

	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0xDD23F0);
	static inline auto FOnHoldToUseStopped = PreyFunction<bool(IArkPlayerInteractionListener* const _this, IEntity* const _pEntity)>(0xDD23F0);
	static inline auto FOnSpecialUseStopped = PreyFunction<bool(IArkPlayerInteractionListener* const _this, IEntity* const _pEntity)>(0xDD23F0);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0xDD23F0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo,4>& _interactionArray)>(0xDD23F0);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo)>(0xDD23F0);
	static inline auto FGetInteractionPosition = PreyFunction<Vec3*(const IArkPlayerInteractionListener* const _this, Vec3* _return_value_, const IEntity* const _pEntity)>(0x610560);
	static inline auto FOnStartLookingAt = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetId)>(0xA13080);
	static inline auto FOnStopLookingAt = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetId)>(0xA13080);
	static inline auto FOnInteractionInfoChanged = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetId)>(0xA13080);
	static inline auto FHideDisplayName = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity)>(0xDD23F0);
};

