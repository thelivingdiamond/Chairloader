// Header file automatically created from a PDB.
#pragma once

// SVisTableEntry
// Header:  _unknown/SVisTableEntry.h
struct SVisTableEntry
{ // Size=12 (0xC)
	unsigned entityId;
	float heightOffset;
	uint16_t flags;
	uint8_t framesSinceLastCheck;
	uint8_t lastRequestedLatency;

#if 0
	SVisTableEntry();
	void Reset();
#endif
};

