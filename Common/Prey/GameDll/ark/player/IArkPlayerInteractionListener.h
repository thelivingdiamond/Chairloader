// Header file automatically created from a PDB.

#pragma once

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
struct IEntity;

// Header: Override
// Prey/GameDll/ark/player/IArkPlayerInteractionListener.h
class IArkPlayerInteractionListener // Id=8014060 Size=8
{
public:
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool OnHoldToUseStopped(IEntity *const _pEntity);
	virtual bool OnSpecialUseStopped(IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo) const;
	virtual Vec3 GetInteractionPosition(IEntity const *const _pEntity) const;
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnStopLookingAt(unsigned _targetId);
	virtual void OnInteractionInfoChanged(unsigned _targetId);
	virtual bool HideDisplayName(IEntity const *const _pEntity) const;
	
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0xDD23F0);
	static inline auto FOnHoldToUseStopped = PreyFunction<bool(IArkPlayerInteractionListener *const _this, IEntity *const _pEntity)>(0xDD23F0);
	static inline auto FOnSpecialUseStopped = PreyFunction<bool(IArkPlayerInteractionListener *const _this, IEntity *const _pEntity)>(0xDD23F0);
	static inline auto FTestInteraction = PreyFunction<bool(IArkPlayerInteractionListener const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0xDD23F0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(IArkPlayerInteractionListener const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0xDD23F0);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(IArkPlayerInteractionListener const *const _this, IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo)>(0xDD23F0);
	static inline auto FGetInteractionPosition = PreyFunction<Vec3(IArkPlayerInteractionListener const *const _this, IEntity const *const _pEntity)>(0x610560);
	static inline auto FOnStartLookingAt = PreyFunction<void(IArkPlayerInteractionListener *const _this, unsigned _targetId)>(0xA13080);
	static inline auto FOnStopLookingAt = PreyFunction<void(IArkPlayerInteractionListener *const _this, unsigned _targetId)>(0xA13080);
	static inline auto FOnInteractionInfoChanged = PreyFunction<void(IArkPlayerInteractionListener *const _this, unsigned _targetId)>(0xA13080);
	static inline auto FHideDisplayName = PreyFunction<bool(IArkPlayerInteractionListener const *const _this, IEntity const *const _pEntity)>(0xDD23F0);
};

