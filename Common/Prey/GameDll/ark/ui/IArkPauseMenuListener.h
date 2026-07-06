// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ui/IArkPauseMenuListener.h
class IArkPauseMenuListener // Id=8015578 Size=8
{
public:
	virtual void OnOptionMenuClosed();
	virtual void OnPauseMenuOpened();
	
	static inline auto FOnOptionMenuClosed = PreyFunction<void(IArkPauseMenuListener *const _this)>(0xA13080);
	static inline auto FOnPauseMenuOpened = PreyFunction<void(IArkPauseMenuListener *const _this)>(0xA13080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkPauseMenuListener
// Header:  Prey/GameDll/ark/ui/IArkPauseMenuListener.h
class IArkPauseMenuListener
{ // Size=8 (0x8)
public:
	virtual void OnOptionMenuClosed();
	virtual void OnPauseMenuOpened();

	static inline auto FOnOptionMenuClosed = PreyFunction<void(IArkPauseMenuListener* const _this)>(0x1333E90);
	static inline auto FOnPauseMenuOpened = PreyFunction<void(IArkPauseMenuListener* const _this)>(0x1333E90);
};
#endif // !MOONCRASH
