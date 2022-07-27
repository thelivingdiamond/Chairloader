// Header file automatically created from a PDB.

#pragma once

// Prey/GameDll/ark/ui/IArkPauseMenuListener.h
class IArkPauseMenuListener // Id=8015578 Size=8
{
public:
	virtual void OnOptionMenuClosed();
	virtual void OnPauseMenuOpened();
	
	static inline auto FOnOptionMenuClosed = PreyFunction<void(IArkPauseMenuListener *const _this)>(0xA13080);
	static inline auto FOnPauseMenuOpened = PreyFunction<void(IArkPauseMenuListener *const _this)>(0xA13080);
};

