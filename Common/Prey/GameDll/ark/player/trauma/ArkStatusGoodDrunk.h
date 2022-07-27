// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

class CCryName;

// Header: FromCpp
// Prey/GameDll/ark/player/trauma/ArkStatusGoodDrunk.h
class ArkStatusGoodDrunk : public ArkTraumaBase, public IArkStatsListener // Id=801B6BA Size=304
{
public:
	ArkStatusGoodDrunk();
	virtual void Serialize(TSerialize _ser);
	virtual void Activate(int _level);
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	virtual bool IsHarmful() const;
	
	static inline auto FSerialize = PreyFunction<void(ArkStatusGoodDrunk *const _this, TSerialize _ser)>(0x12F7060);
	static inline auto FActivate = PreyFunction<void(ArkStatusGoodDrunk *const _this, int _level)>(0x12F6F60);
	static inline auto FOnStatChange = PreyFunction<void(ArkStatusGoodDrunk *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x12F6FB0);
	static inline auto FIsHarmful = PreyFunction<bool(ArkStatusGoodDrunk const *const _this)>(0xDD23F0);
};

