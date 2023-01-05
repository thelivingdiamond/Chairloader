// Header file automatically created from a PDB.
#pragma once

// IArkMetaTagListener
// Header:  Prey/GameDll/ark/player/IArkMetaTagListener.h
class IArkMetaTagListener
{ // Size=8 (0x8)
public:
	virtual void OnMetaTagAdded(unsigned _arg0_, const uint64_t _arg1_);
	virtual void OnMetaTagRemoved(unsigned _arg0_, const uint64_t _arg1_);
	virtual void OnMetaTagsAdded(unsigned _arg0_);
	virtual void OnAllDynamicMetaTagsRemoved(unsigned _arg0_);
};

