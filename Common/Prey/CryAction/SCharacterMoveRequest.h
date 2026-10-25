// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IAnimationGraph.h>
#include <Prey/CryAction/IAnimatedCharacter.h>

// SCharacterMoveRequest
// Header:  _unknown/SCharacterMoveRequest.h
// Include: Prey/CryAction/IAnimatedCharacter.h
struct SCharacterMoveRequest
{ // Size=76 (0x4C)
	ECharacterMoveType type;
	Vec3 velocity;
	Quat rotation;
	SPredictedCharacterStates prediction;
	bool allowStrafe;
	float proceduralLeaning;
	bool jumping;

#if 0
	SCharacterMoveRequest();
#endif
};

