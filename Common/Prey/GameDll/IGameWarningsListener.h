// Header file automatically created from a PDB.
#pragma once

// IGameWarningsListener
// Header:  _unknown/IGameWarningsListener.h
// Include: Prey/CryGame/IGameFramework.h
struct IGameWarningsListener
{ // Size=8 (0x8)
	virtual ~IGameWarningsListener();
	virtual bool OnWarningReturn(unsigned id, const char* returnValue);
	virtual void OnWarningRemoved(unsigned id);

#ifndef MOONCRASH
	static inline auto FOnWarningReturn = PreyFunction<bool(IGameWarningsListener* const _this, unsigned id, const char* returnValue)>(0x1B933B0);
	static inline auto FOnWarningRemoved = PreyFunction<void(IGameWarningsListener* const _this, unsigned id)>(0xA13080);
#else
	static inline auto FOnWarningReturn = PreyFunction<bool(IGameWarningsListener* const _this, unsigned id, const char* returnValue)>(0x1A302A0);
	static inline auto FOnWarningRemoved = PreyFunction<void(IGameWarningsListener* const _this, unsigned id)>(0x1333E90);
#endif
};

