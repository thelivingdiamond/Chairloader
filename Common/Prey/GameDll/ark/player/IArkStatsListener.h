// Header file automatically created from a PDB.

#pragma once

class CCryName;

// Prey/GameDll/ark/player/IArkStatsListener.h
class IArkStatsListener // Id=80134D3 Size=8
{
public:
	virtual void OnStatChange(const unsigned arg0, CCryName const &arg1, const float arg2, const float arg3) = 0;
	virtual void OnStatSerialize(const unsigned _ownerId, CCryName const &_stat64i32, const float _value);
	
	static inline auto FOnStatSerialize = PreyFunction<void(IArkStatsListener *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _value)>(0xA13080);
};

