// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatiallySortedApexTentacle.h>
#include <Prey/GameDll/ark/spatial/ArkSpatiallySortedEntity.h>
#include <Prey/GameDll/ark/spatial/ArkSpatiallySortedKey.h>
#include <Prey/GameDll/ark/spatial/ArkSpatiallySortedNpc.h>
#include <Prey/GameDll/ark/spatial/ArkSpatiallySortedTurret.h>
#include <Prey/GameDll/ark/spatial/arkspatiallysortedturret.h>
#include <_unknown/ArkSpatiallySorted_ArkSpatiallySortedApexTentacle___ObjectCoordinate.h>
#include <_unknown/ArkSpatiallySorted_ArkSpatiallySortedCystoidNest___ObjectCoordinate.h>
#include <_unknown/ArkSpatiallySorted_ArkSpatiallySortedEntity___ObjectCoordinate.h>
#include <_unknown/ArkSpatiallySorted_ArkSpatiallySortedNpc___ObjectCoordinate.h>
#include <_unknown/ArkSpatiallySorted_ArkSpatiallySortedTurret___ObjectCoordinate.h>

// Header: Exact
// Prey/GameDll/ark/spatial/arkspatiallysorted.h
template <typename T>
class ArkSpatiallySorted // Id=8016150 Size=72
{
public:
	using KeyType = ArkSpatiallySortedKey;
	using ObjectType = T;
	
	struct ObjectCoordinate // Id=8016152 Size=16
	{
		uint64_t m_objectIndex;
		float m_value;
	};

	using ObjectCoordinateVector = std::vector<ObjectCoordinate>;
	using IndexVector = std::vector<size_t>;
	using ObjectVector = std::vector<T>;
	
	ObjectVector m_objects;
	IndexVector m_freeObjectIndexes;
	ObjectCoordinateVector m_objectCoordinates;
	
#if 0
	void RemoveObject(ArkSpatiallySortedKey &arg0);
	bool HasObject(ArkSpatiallySortedKey &arg0) const;
	uint64_t GetObjectCount() const;
	void Refresh();
	void Clear();
	void Shrink();
#endif
};

