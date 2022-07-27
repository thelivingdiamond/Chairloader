// Header file automatically created from a PDB.

#pragma once
#include <_unknown/ArkSpaceObject.h>
#include <_unknown/SHDRParams.h>

// Header: Exact
// Prey/Ark/iarkspacemanager.h
struct ArkSpaceSettings // Id=8002857 Size=240
{
	string spaceMaterial;
	string starMapMesh;
	Ang3 sunAngles;
	float sunSpeed;
	float sunScale;
	float sunIntensity;
	Ang3 starOffsets;
	float starIntensity;
	float starScale;
	float starCountPercentage;
	ArkSpaceObject earth;
	ArkSpaceObject moon;
	SHDRParams hdrParams;
	float hdrMultiplier;
	
	ArkSpaceSettings();
};

