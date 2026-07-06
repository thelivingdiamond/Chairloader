// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatiallySortedApexTentacle.h>
#include <Prey/GameDll/ark/spatial/ArkSpatiallySortedEntity.h>
#include <Prey/GameDll/ark/spatial/ArkSpatiallySortedNpc.h>
#include <_unknown/ArkSpatiallySortedTurret.h>

class ArkSpatiallySortedKey;

// ArkSpatiallySorted<ArkSpatiallySortedApexTentacle>
// Header:  Prey/GameDll/ark/spatial/arkspatiallysorted.h
class ArkSpatiallySorted<ArkSpatiallySortedApexTentacle>
{ // Size=72 (0x48)
public:
	// ArkSpatiallySorted<ArkSpatiallySortedApexTentacle>::ObjectCoordinate
	// Header:  Prey/GameDll/ark/spatial/arkspatiallysorted.h
	struct ObjectCoordinate
	{ // Size=16 (0x10)
		uint64_t m_objectIndex;
		float m_value;

	#if 0
		ObjectCoordinate(const uint64_t _arg0_, const float _arg1_);
	#endif
	};

	using KeyType = ArkSpatiallySortedKey;
	using ObjectType = ArkSpatiallySortedApexTentacle;
	using ObjectCoordinateVector = std::vector<ArkSpatiallySorted<ArkSpatiallySortedApexTentacle>::ObjectCoordinate>;
	using IndexVector = std::vector<uint64_t>;
	using ObjectVector = std::vector<ArkSpatiallySortedApexTentacle>;

	std::vector<ArkSpatiallySortedApexTentacle> m_objects;
	std::vector<uint64_t> m_freeObjectIndexes;
	std::vector<ArkSpatiallySorted<ArkSpatiallySortedApexTentacle>::ObjectCoordinate> m_objectCoordinates;

	void Refresh() { FRefresh(this); }

#if 0
	void RemoveObject(ArkSpatiallySortedKey& _arg0_);
	bool HasObject(ArkSpatiallySortedKey& _arg0_) const;
	uint64_t GetObjectCount() const;
	void Clear();
	void Shrink();
#endif

	static inline auto FRefresh = PreyFunction<void(ArkSpatiallySorted<ArkSpatiallySortedApexTentacle>* const _this)>(0x14169F0);
};

// ArkSpatiallySorted<ArkSpatiallySortedEntity>
// Header:  Prey/GameDll/ark/spatial/arkspatiallysorted.h
class ArkSpatiallySorted<ArkSpatiallySortedEntity>
{ // Size=72 (0x48)
public:
	// ArkSpatiallySorted<ArkSpatiallySortedEntity>::ObjectCoordinate
	// Header:  Prey/GameDll/ark/spatial/arkspatiallysorted.h
	struct ObjectCoordinate
	{ // Size=16 (0x10)
		uint64_t m_objectIndex;
		float m_value;

	#if 0
		ObjectCoordinate(const uint64_t _arg0_, const float _arg1_);
	#endif
	};

	using KeyType = ArkSpatiallySortedKey;
	using ObjectType = ArkSpatiallySortedEntity;
	using ObjectCoordinateVector = std::vector<ArkSpatiallySorted<ArkSpatiallySortedEntity>::ObjectCoordinate>;
	using IndexVector = std::vector<uint64_t>;
	using ObjectVector = std::vector<ArkSpatiallySortedEntity>;

	std::vector<ArkSpatiallySortedEntity> m_objects;
	std::vector<uint64_t> m_freeObjectIndexes;
	std::vector<ArkSpatiallySorted<ArkSpatiallySortedEntity>::ObjectCoordinate> m_objectCoordinates;

	void RemoveObject(ArkSpatiallySortedKey& _key) { FRemoveObject(this, _key); }
	void Refresh() { FRefresh(this); }

#if 0
	bool HasObject(ArkSpatiallySortedKey& _arg0_) const;
	uint64_t GetObjectCount() const;
	void Clear();
	void Shrink();
#endif

	static inline auto FRemoveObject = PreyFunction<void(ArkSpatiallySorted<ArkSpatiallySortedEntity>* const _this, ArkSpatiallySortedKey& _key)>(0x1417990);
	static inline auto FRefresh = PreyFunction<void(ArkSpatiallySorted<ArkSpatiallySortedEntity>* const _this)>(0x1416CA0);
};

// ArkSpatiallySorted<ArkSpatiallySortedNpc>
// Header:  Prey/GameDll/ark/spatial/arkspatiallysorted.h
class ArkSpatiallySorted<ArkSpatiallySortedNpc>
{ // Size=72 (0x48)
public:
	// ArkSpatiallySorted<ArkSpatiallySortedNpc>::ObjectCoordinate
	// Header:  Prey/GameDll/ark/spatial/arkspatiallysorted.h
	struct ObjectCoordinate
	{ // Size=16 (0x10)
		uint64_t m_objectIndex;
		float m_value;

	#if 0
		ObjectCoordinate(const uint64_t _arg0_, const float _arg1_);
	#endif
	};

	using KeyType = ArkSpatiallySortedKey;
	using ObjectType = ArkSpatiallySortedNpc;
	using ObjectCoordinateVector = std::vector<ArkSpatiallySorted<ArkSpatiallySortedNpc>::ObjectCoordinate>;
	using IndexVector = std::vector<uint64_t>;
	using ObjectVector = std::vector<ArkSpatiallySortedNpc>;

	std::vector<ArkSpatiallySortedNpc> m_objects;
	std::vector<uint64_t> m_freeObjectIndexes;
	std::vector<ArkSpatiallySorted<ArkSpatiallySortedNpc>::ObjectCoordinate> m_objectCoordinates;

	void Refresh() { FRefresh(this); }

#if 0
	void RemoveObject(ArkSpatiallySortedKey& _arg0_);
	bool HasObject(ArkSpatiallySortedKey& _arg0_) const;
	uint64_t GetObjectCount() const;
	void Clear();
	void Shrink();
#endif

	static inline auto FRefresh = PreyFunction<void(ArkSpatiallySorted<ArkSpatiallySortedNpc>* const _this)>(0x1416F50);
};

// ArkSpatiallySorted<ArkSpatiallySortedTurret>
// Header:  Prey/GameDll/ark/spatial/arkspatiallysorted.h
class ArkSpatiallySorted<ArkSpatiallySortedTurret>
{ // Size=72 (0x48)
public:
	// ArkSpatiallySorted<ArkSpatiallySortedTurret>::ObjectCoordinate
	// Header:  Prey/GameDll/ark/spatial/arkspatiallysorted.h
	struct ObjectCoordinate
	{ // Size=16 (0x10)
		uint64_t m_objectIndex;
		float m_value;

	#if 0
		ObjectCoordinate(const uint64_t _arg0_, const float _arg1_);
	#endif
	};

	using KeyType = ArkSpatiallySortedKey;
	using ObjectType = ArkSpatiallySortedTurret;
	using ObjectCoordinateVector = std::vector<ArkSpatiallySorted<ArkSpatiallySortedTurret>::ObjectCoordinate>;
	using IndexVector = std::vector<uint64_t>;
	using ObjectVector = std::vector<ArkSpatiallySortedTurret>;

	std::vector<ArkSpatiallySortedTurret> m_objects;
	std::vector<uint64_t> m_freeObjectIndexes;
	std::vector<ArkSpatiallySorted<ArkSpatiallySortedTurret>::ObjectCoordinate> m_objectCoordinates;

	void Refresh() { FRefresh(this); }

#if 0
	void RemoveObject(ArkSpatiallySortedKey& _arg0_);
	bool HasObject(ArkSpatiallySortedKey& _arg0_) const;
	uint64_t GetObjectCount() const;
	void Clear();
	void Shrink();
#endif

	static inline auto FRefresh = PreyFunction<void(ArkSpatiallySorted<ArkSpatiallySortedTurret>* const _this)>(0x1417200);
};
#endif // !MOONCRASH
