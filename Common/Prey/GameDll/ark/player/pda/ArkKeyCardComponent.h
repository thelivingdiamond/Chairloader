// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/player/pda/ArkKeyCardComponent.h
class ArkKeyCardComponent // Id=8016F49 Size=24
{
public:
	std::vector<unsigned __int64> m_collected;
	
	ArkKeyCardComponent();
	void Collect(const uint64_t _id) { FCollect(this,_id); }
	bool HasKeyCard(const uint64_t _id) const { return FHasKeyCard(this,_id); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	
#if 0
	void CollectAll();
	std::vector<unsigned __int64> const &GetCollected() const;
#endif
	
	static inline auto FCollect = PreyFunction<void(ArkKeyCardComponent *const _this, const uint64_t _id)>(0x15B4C30);
	static inline auto FHasKeyCard = PreyFunction<bool(ArkKeyCardComponent const *const _this, const uint64_t _id)>(0x15B57D0);
	static inline auto FReset = PreyFunction<void(ArkKeyCardComponent *const _this)>(0x2A3380);
	static inline auto FSerialize = PreyFunction<void(ArkKeyCardComponent *const _this, TSerialize ser)>(0x15B4DE0);
};

