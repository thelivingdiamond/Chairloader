#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkDoomClockListener
// Header:  _unknown/IArkDoomClockListener.h
class IArkDoomClockListener
{ // Size=8 (0x8)
public:
	virtual void OnDoomClockEnabled(bool _bEnabled);
	virtual void OnDoomClockIncrement(int _level) = 0;
	virtual void OnDoomClockPreIncrement(int _level) = 0;

	static inline auto FOnDoomClockEnabled = PreyFunction<void(IArkDoomClockListener* const _this, bool _bEnabled)>(0x1333E90);
};

#endif // MOONCRASH
