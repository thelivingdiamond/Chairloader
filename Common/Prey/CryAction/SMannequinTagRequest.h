// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequinTagDefs.h>

// SMannequinTagRequest
// Header:  _unknown/SMannequinTagRequest.h
// Include: Prey/CryAction/IMovementController.h
struct SMannequinTagRequest
{ // Size=24 (0x18)
	STagState<12> clearTags;
	STagState<12> setTags;

#if 0
	SMannequinTagRequest();
	SMannequinTagRequest(const STagState<12>& _arg0_, const STagState<12>& _arg1_);
	void Clear();
#endif
};

