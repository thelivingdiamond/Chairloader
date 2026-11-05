#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// INightmareSpawnObserver
// Header:  _unknown/INightmareSpawnObserver.h
struct INightmareSpawnObserver
{ // Size=8 (0x8)
	virtual void OnNightmareSpawnedPassively(unsigned _arg0_) = 0;
	virtual void OnNightmareSpawnedActively(unsigned _arg0_) = 0;
	virtual void OnNightmareDeath() = 0;
	virtual void OnNightmareDissipated() = 0;
};

#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkNpc;

// INightmareSpawnObserver
// Header:  _unknown/INightmareSpawnObserver.h
struct INightmareSpawnObserver
{ // Size=8 (0x8)
	virtual void OnNightmareSpawned(ArkNpc& _nightmare) = 0;
	virtual void OnNightmareKilled(ArkNpc& _nightmare) = 0;
	virtual void OnNightmareDissipated(ArkNpc& _nightmare) = 0;
};

#endif // !MOONCRASH
