// Header file automatically created from a PDB.
#pragma once

// IArkPDAListener
// Header:  Prey/GameDll/ark/player/IArkPDAListener.h
class IArkPDAListener
{ // Size=8 (0x8)
public:
	virtual void OnPDAOpen() = 0;
	virtual void OnPDAOpenComplete() = 0;
	virtual void OnPDAClose() = 0;

	static inline auto FOnPDAOpen = PreyFunction<void(IArkPDAListener* const _this)>(0xA13080);
	static inline auto FOnPDAOpenComplete = PreyFunction<void(IArkPDAListener* const _this)>(0xA13080);
	static inline auto FOnPDAClose = PreyFunction<void(IArkPDAListener* const _this)>(0xA13080);
};

