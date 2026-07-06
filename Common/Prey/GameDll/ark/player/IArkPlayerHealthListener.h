// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkPlayerHealthListener
// Header:  Prey/GameDll/ark/player/IArkPlayerHealthListener.h
class IArkPlayerHealthListener
{ // Size=8 (0x8)
public:
	virtual void OnHealthChanged();
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkPlayerHealthListener
// Header:  Prey/GameDll/ark/player/IArkPlayerHealthListener.h
class IArkPlayerHealthListener
{ // Size=8 (0x8)
public:
	virtual void OnHealthChanged();
	virtual void OnPlayerDead();

	static inline auto FOnHealthChanged = PreyFunction<void(IArkPlayerHealthListener* const _this)>(0x1333E90);
	static inline auto FOnPlayerDead = PreyFunction<void(IArkPlayerHealthListener* const _this)>(0x1333E90);
};
#endif // !MOONCRASH
