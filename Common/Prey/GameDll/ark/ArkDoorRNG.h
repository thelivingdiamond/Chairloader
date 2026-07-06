// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkDoor;

// ArkDoorRNG
// Header:  Prey/GameDll/ark/ArkDoorRNG.h
class ArkDoorRNG
{ // Size=16 (0x10)
public:
	enum class State
	{
		unlocked = 0,
		lockedWithKeycard = 1,
		lockedWithKeycode = 2,
		brokenUnlocked = 3,
		numStates = 4,
	};

	ArkDoorRNG::State m_state;
	bool m_bGiveCorpseKeycard;
	string m_keycardCorpseName;

	void Init(ArkDoor& _door) { FInit(this, _door); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void SpawnCorpses(const ArkDoor& _door) { FSpawnCorpses(this, _door); }
	void OnControllersSpawned(const ArkDoor& _door) { FOnControllersSpawned(this, _door); }

#if 0
	ArkDoorRNG();
#endif

	static inline auto FInit = PreyFunction<void(ArkDoorRNG* const _this, ArkDoor& _door)>(0x11A3CA0);
	static inline auto FSerialize = PreyFunction<void(ArkDoorRNG* const _this, TSerialize _ser)>(0x11A4510);
	static inline auto FSpawnCorpses = PreyFunction<void(ArkDoorRNG* const _this, const ArkDoor& _door)>(0x11A4600);
	static inline auto FOnControllersSpawned = PreyFunction<void(ArkDoorRNG* const _this, const ArkDoor& _door)>(0x11A4500);
};
#endif // MOONCRASH
