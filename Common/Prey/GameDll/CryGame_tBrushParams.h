// Header file automatically created from a PDB.
#pragma once

namespace CryGame
{

// CryGame::tBrushParams
// Header:  _unknown/CryGame__tBrushParams.h
struct tBrushParams
{ // Size=128 (0x80)
	string sFilename;
	string sMaterial;
	unsigned dwRenderNodeFlags;
	int nLodRatio;
	int nViewDistRatio;
	Matrix34 mat;
	bool bIsDecal;
	int nProjectionType;
	bool bDeferredDecal;
	int nSortPrio;
	float fDepth;
	int nBinaryDesignerObjectVersion;
	std::vector<char> vBinaryDesignerObject;

#if 0
	tBrushParams();
#endif
};


} // namespace CryGame

