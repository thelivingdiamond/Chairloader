// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

class CCryName;

// ArkTraumaDrunk
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaDrunk.h
class ArkTraumaDrunk : public ArkTraumaBase, public IArkStatsListener
{ // Size=304 (0x130)
public:
	ArkTraumaDrunk();
	virtual ~ArkTraumaDrunk();
	virtual void Activate(int _level);
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);

	static inline auto FArkTraumaDrunkOv1 = PreyFunction<void(ArkTraumaDrunk* const _this)>(0x12F6BC0);
	static inline auto FActivate = PreyFunction<void(ArkTraumaDrunk* const _this, int _level)>(0x12F6D70);
	static inline auto FOnStatChange = PreyFunction<void(IArkStatsListener* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x12F6DC0);
};

