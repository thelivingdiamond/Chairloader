// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

class CCryName;

// Header: FromCpp
// Prey/GameDll/ark/player/trauma/ArkTraumaDrunk.h
class ArkTraumaDrunk : public ArkTraumaBase, public IArkStatsListener // Id=801B6B9 Size=304
{
public:
	ArkTraumaDrunk();
	virtual ~ArkTraumaDrunk();
	virtual void Activate(int _level);
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	
	static inline auto FActivate = PreyFunction<void(ArkTraumaDrunk *const _this, int _level)>(0x12F6D70);
	static inline auto FOnStatChange = PreyFunction<void(ArkTraumaDrunk *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x12F6DC0);
};

