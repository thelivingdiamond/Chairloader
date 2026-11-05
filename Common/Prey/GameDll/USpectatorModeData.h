// Header file automatically created from a PDB.
#pragma once

// USpectatorModeData
// Header:  _unknown/USpectatorModeData.h
union USpectatorModeData
{ // Size=8 (0x8)
	// USpectatorModeData::SFixed
	// Header:  _unknown/USpectatorModeData.h
	struct SFixed
	{ // Size=4 (0x4)
		unsigned location;
	};

	// USpectatorModeData::SFree
	// Header:  _unknown/USpectatorModeData.h
	struct SFree
	{ // Size=1 (0x1)
		uint8_t _dummy_;
	};

	// USpectatorModeData::SFollow
	// Header:  _unknown/USpectatorModeData.h
	struct SFollow
	{ // Size=8 (0x8)
		unsigned spectatorTarget;
		float invalidTargetTimer;
	};

	// USpectatorModeData::SKiller
	// Header:  _unknown/USpectatorModeData.h
	struct SKiller
	{ // Size=8 (0x8)
		unsigned spectatorTarget;
		float startTime;
	};

	USpectatorModeData::SFixed fixed;
	USpectatorModeData::SFree CryModuleCRTFree;
	USpectatorModeData::SFollow follow;
	USpectatorModeData::SKiller killer;

#if 0
	void Reset();
#endif
};

