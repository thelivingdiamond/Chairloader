// Header file automatically created from a PDB.

#pragma once

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

