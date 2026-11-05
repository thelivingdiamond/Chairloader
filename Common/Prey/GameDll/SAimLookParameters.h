// Header file automatically created from a PDB.
#pragma once

class XmlNodeRef;

// SAimLookParameters
// Header:  _unknown/SAimLookParameters.h
struct SAimLookParameters
{ // Size=104 (0x68)
	float easeFactorInc;
	float easeFactorDec;
	float strafeScopeFactor;
	float rotateScopeFactor;
	float velocityInterpolationMultiplier;
	float velocityLowPassFilter;
	float accelerationSmoothing;
	float accelerationFrontAugmentation;
	float verticalVelocityScale;
	bool sprintCameraAnimation;
	float blendFactors[16];

#if 0
	SAimLookParameters();
	void Reset();
	void Read(const XmlNodeRef& _arg0_);
#endif
};

