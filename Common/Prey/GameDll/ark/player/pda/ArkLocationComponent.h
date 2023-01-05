// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

// ArkLocationComponent
// Header:  Prey/GameDll/ark/player/pda/ArkLocationComponent.h
class ArkLocationComponent
{ // Size=48 (0x30)
public:
	// ArkLocationComponent::ArkLocationCooldown
	// Header:  Prey/GameDll/ark/player/pda/ArkLocationComponent.h
	class ArkLocationCooldown
	{ // Size=16 (0x10)
	public:
		uint64_t m_locationId;
		ArkTimeRemaining m_timeRemaining;

	#if 0
		ArkLocationCooldown();
		ArkLocationCooldown(const uint64_t _arg0_, const float _arg1_);
		void Serialize(TSerialize _arg0_);
		bool operator==(const uint64_t _arg0_) const;
	#endif
	};

	std::vector<uint64_t> m_discovered;
	std::vector<ArkLocationComponent::ArkLocationCooldown> m_cooldowns;

	ArkLocationComponent();
	void Discover(const uint64_t _id, bool _bShowPopup) { FDiscover(this, _id, _bShowPopup); }
	bool HasDiscovered(const uint64_t _id) const { return FHasDiscovered(this, _id); }
	void Reset() { FReset(this); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void Serialize(TSerialize ser) { FSerialize(this, ser); }

	static inline auto FArkLocationComponentOv2 = PreyFunction<void(ArkLocationComponent* const _this)>(0x15B5440);
	static inline auto FDiscover = PreyFunction<void(ArkLocationComponent* const _this, const uint64_t _id, bool _bShowPopup)>(0x15B5470);
	static inline auto FHasDiscovered = PreyFunction<bool(const ArkLocationComponent* const _this, const uint64_t _id)>(0x15B57D0);
	static inline auto FReset = PreyFunction<void(ArkLocationComponent* const _this)>(0x15B5800);
	static inline auto FUpdate = PreyFunction<void(ArkLocationComponent* const _this, float _frameTime)>(0x15B59A0);
	static inline auto FSerialize = PreyFunction<void(ArkLocationComponent* const _this, TSerialize ser)>(0x15B5810);
};

