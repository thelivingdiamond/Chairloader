// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_cystoidnest.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_turret.h>
#include <_unknown/ArkSpatialManagerKey_ArkSpatialManagerKeyType_CystoidNest_.h>
#include <_unknown/ArkSpatialManagerKey_ArkSpatialManagerKeyType_Turret_.h>

// Header: Exact
// Prey/GameDll/ark/spatial/arkspatialmanagerentry.h
template <typename T>
class ArkSpatialManagerEntry // Id=80152EF Size=16
{
public:
	using ImplType = T;
	using KeyType = T::KeyType;
	
	T m_impl;
	KeyType m_key;
	
#if 0
	void Reset();
#endif
};

