// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/Ark/iarkspacemanager.h
struct SHDRParams // Id=8002610 Size=60
{
	float shoulderScale;
	float midtonesScale;
	float toeScale;
	float whitepoint;
	float saturation;
	Vec3 colorBalance;
	float sceneKey;
	float minExposure;
	float maxExposure;
	float evMin;
	float evMax;
	float evAutoCompensation;
	float bloomAmount;
};

// Header: Override
// Prey/Ark/iarkspacemanager.h
struct ArkSpaceObject // Id=8002858 Size=56
{
	string name;
	string mesh;
	Ang3 offsets;
	Ang3 orientation;
	float radius;
	float distanceToSurface;
	float scale;
	float rotationSpeed;
};

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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkSpaceObject
// Header:  Prey/Ark/iarkspacemanager.h
struct ArkSpaceObject
{ // Size=56 (0x38)
	string name;
	string mesh;
	Ang3 offsets;
	Ang3 orientation;
	float radius;
	float distanceToSurface;
	float scale;
	float rotationSpeed;

#if 0
	ArkSpaceObject();
#endif
};

// SHDRParams
// Header:  Prey/Ark/iarkspacemanager.h
struct SHDRParams
{ // Size=60 (0x3C)
	float shoulderScale;
	float midtonesScale;
	float toeScale;
	float whitepoint;
	float saturation;
	Vec3 colorBalance;
	float sceneKey;
	float minExposure;
	float maxExposure;
	float evMin;
	float evMax;
	float evAutoCompensation;
	float bloomAmount;
};
#endif // !MOONCRASH
