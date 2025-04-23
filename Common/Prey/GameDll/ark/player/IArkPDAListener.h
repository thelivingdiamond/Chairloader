// Header file automatically created from a PDB.
#pragma once

// IArkPDAListener
// Header:  Prey/GameDll/ark/player/IArkPDAListener.h
class IArkPDAListener
{ // Size=8 (0x8)
public:
	virtual void OnPDAOpen() { FOnPDAOpen(this); }
	virtual void OnPDAOpenComplete() { FOnPDAOpenComplete(this); }
	virtual void OnPDAClose() { FOnPDAClose(this); }

	static inline auto FOnPDAOpen = PreyFunction<void(IArkPDAListener* const _this)>(0xA13080);
	static inline auto FOnPDAOpenComplete = PreyFunction<void(IArkPDAListener* const _this)>(0xA13080);
	static inline auto FOnPDAClose = PreyFunction<void(IArkPDAListener* const _this)>(0xA13080);
};

