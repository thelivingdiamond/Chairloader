// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/USpectatorModeData.h>

// SSpectatorInfo
// Header:  _unknown/SSpectatorInfo.h
struct SSpectatorInfo
{ // Size=20 (0x14)
	USpectatorModeData dataU;
	float yawSpeed;
	float pitchSpeed;
	bool rotateSpeedSingleFrame;
	uint8_t mode;
	uint8_t state;

#if 0
	void Reset();
	unsigned* GetOtherEntIdPtrForCurMode();
	unsigned GetOtherEntIdForCurMode();
	void SetOtherEntIdForCurMode(unsigned _arg0_);
#endif
};

