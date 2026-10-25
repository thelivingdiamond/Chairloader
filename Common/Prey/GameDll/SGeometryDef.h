// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/itemstring.h>

class ICrySizer;

// SGeometryDef
// Header:  _unknown/SGeometryDef.h
struct SGeometryDef
{ // Size=56 (0x38)
	SharedString::CSharedString modelPath;
	SharedString::CSharedString material;
	Vec3 pos;
	Ang3 angles;
	float scale;
	int slot;
	bool useCgfStreaming;
	bool useParentMaterial;

#if 0
	SGeometryDef();
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif
};

