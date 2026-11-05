#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class XmlNodeRef;

// EncounterInfo
// Header:  _unknown/EncounterInfo.h
struct EncounterInfo
{ // Size=16 (0x10)
	unsigned SpawnerID;
	bool bSpawnFirst;
	int SpawnChanceWeight;
	bool bCanRespawn;
	bool bIsActive;
	bool bHasBeenActivated;

#if 0
	EncounterInfo();
	EncounterInfo(unsigned _arg0_, bool _arg1_, int _arg2_, bool _arg3_);
	void Load(const XmlNodeRef& _arg0_);
	void Serialize(TSerialize& _arg0_);
	string GetSpawnerName() const;
	string GetDebugString(bool _arg0_) const;
#endif
};

#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class XmlNodeRef;

// EncounterInfo
// Header:  _unknown/EncounterInfo.h
struct EncounterInfo
{ // Size=24 (0x18)
	unsigned SpawnerID;
	int SpawnChanceWeight;
	bool bIsActive;
	int SpawnTrack;
	int DoomclockLevel;
	bool bHasBeenActivated;

#if 0
	EncounterInfo();
	EncounterInfo(unsigned _arg0_, int _arg1_, int _arg2_, int _arg3_);
	void Load(const XmlNodeRef& _arg0_);
	void Serialize(TSerialize& _arg0_);
	string GetSpawnerName() const;
	string GetDebugString(bool _arg0_) const;
#endif
};

#endif // !MOONCRASH
