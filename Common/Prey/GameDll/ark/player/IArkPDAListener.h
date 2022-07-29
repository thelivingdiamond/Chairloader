// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/player/IArkPDAListener.h
class IArkPDAListener // Id=8015586 Size=8
{
public:
	virtual void OnPDAOpen();
	virtual void OnPDAOpenComplete();
	virtual void OnPDAClose();
	
	static inline auto FOnPDAOpen = PreyFunction<void(IArkPDAListener *const _this)>(0xA13080);
	static inline auto FOnPDAOpenComplete = PreyFunction<void(IArkPDAListener *const _this)>(0xA13080);
	static inline auto FOnPDAClose = PreyFunction<void(IArkPDAListener *const _this)>(0xA13080);
};

