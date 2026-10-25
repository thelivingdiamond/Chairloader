// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkStubs.h>

// NavSpace
// Header:  _unknown/NavSpace.h
struct NavSpace
{ // Size=8 (0x8)
	enum class EType
	{
		Mesh = 0,
		ArkSpaceGrid = 1,
	};

	NavSpace::EType m_type;
	unsigned m_spaceId;

#if 0
	NavSpace();
	NavSpace(TNavigationID<0> _arg0_);
	NavSpace(TNavigationID<3> _arg0_);
	TNavigationID<0> GetMeshID() const;
	TNavigationID<3> GetSpaceGridID() const;
	bool operator==(const NavSpace& _arg0_) const;
	bool operator!=(const NavSpace& _arg0_) const;
	bool operator<(const NavSpace& _arg0_) const;
	bool operator>(const NavSpace& _arg0_) const;
	bool operator bool() const;
#endif
};

