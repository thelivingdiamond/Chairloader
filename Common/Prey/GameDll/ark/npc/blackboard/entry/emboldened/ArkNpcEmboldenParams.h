// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/emboldened/ArkSearchBounds.h>

// ArkNpcEmboldenParams
// Header:  _unknown/ArkNpcEmboldenParams.h
struct ArkNpcEmboldenParams
{ // Size=24 (0x18)
	uint64_t m_allyCount;
	ArkSearchBounds m_searchBounds;
	float m_emboldenedTime;

#if 0
	ArkNpcEmboldenParams();
	ArkNpcEmboldenParams(const uint64_t _arg0_, const ArkSearchBounds& _arg1_, const float _arg2_);
	void Serialize(TSerialize _arg0_);
#endif
};

