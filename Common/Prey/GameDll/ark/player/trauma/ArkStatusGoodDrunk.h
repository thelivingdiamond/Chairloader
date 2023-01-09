// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

class CCryName;

// ArkStatusGoodDrunk
// Header:  Prey/GameDll/ark/player/trauma/ArkStatusGoodDrunk.h
class ArkStatusGoodDrunk : public ArkTraumaBase, public IArkStatsListener
{ // Size=304 (0x130)
public:
	ArkStatusGoodDrunk();
	virtual ~ArkStatusGoodDrunk();
	virtual void Serialize(TSerialize _ser);
	virtual void Activate(int _level);
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	virtual bool IsHarmful() const;

	static inline auto FArkStatusGoodDrunkOv1 = PreyFunction<void(ArkStatusGoodDrunk* const _this)>(0x12F6E70);
	static inline auto FSerialize = PreyFunction<void(ArkStatusGoodDrunk* const _this, TSerialize _ser)>(0x12F7060);
	static inline auto FActivate = PreyFunction<void(ArkStatusGoodDrunk* const _this, int _level)>(0x12F6F60);
	static inline auto FOnStatChange = PreyFunction<void(IArkStatsListener* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x12F6FB0);
	static inline auto FIsHarmful = PreyFunction<bool(const ArkStatusGoodDrunk* const _this)>(0xDD23F0);
};

