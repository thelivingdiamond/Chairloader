// Header file automatically created from a PDB.
#pragma once

class CCryName;

// IArkStatsListener
// Header:  Prey/GameDll/ark/player/IArkStatsListener.h
class IArkStatsListener
{ // Size=8 (0x8)
public:
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue) = 0;
	virtual void OnStatSerialize(const unsigned _ownerId, const CCryName& _stat64i32, const float _value);

	static inline auto FOnStatSerialize = PreyFunction<void(IArkStatsListener* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _value)>(0xA13080);
};

