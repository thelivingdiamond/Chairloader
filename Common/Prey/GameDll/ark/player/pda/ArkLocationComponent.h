// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/player/pda/ArkLocationComponent.h
class   ArkLocationComponent // Id=8016F1C Size=48
{
public:
	std::vector<unsigned __int64> m_discovered;
	
	class ArkLocationCooldown // Id=8016F1D Size=16
	{
	public:
		uint64_t m_locationId;
		ArkTimeRemaining m_timeRemaining;
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(const uint64_t arg0) const;
#endif
	};

	std::vector<ArkLocationComponent::ArkLocationCooldown> m_cooldowns;
	
	ArkLocationComponent();
	void Discover(const uint64_t _id, bool _bShowPopup) { FDiscover(this,_id,_bShowPopup); }
	bool HasDiscovered(const uint64_t _id) const { return FHasDiscovered(this,_id); }
	void Reset() { FReset(this); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	
	static inline auto FDiscover = PreyFunction<void(ArkLocationComponent *const _this, const uint64_t _id, bool _bShowPopup)>(0x15B5470);
	static inline auto FHasDiscovered = PreyFunction<bool(ArkLocationComponent const *const _this, const uint64_t _id)>(0x15B57D0);
	static inline auto FReset = PreyFunction<void(ArkLocationComponent *const _this)>(0x15B5800);
	static inline auto FUpdate = PreyFunction<void(ArkLocationComponent *const _this, float _frameTime)>(0x15B59A0);
	static inline auto FSerialize = PreyFunction<void(ArkLocationComponent *const _this, TSerialize ser)>(0x15B5810);
};

