// Header file automatically created from a PDB.

#pragma once

class XmlNodeRef;

// Header: Override
// Prey/GameDll/ark/iface/IArkInventory.h
class IArkInventory // Id=801521E Size=8
{
public:
	virtual int GetWidth() const = 0;
	virtual int GetMaxWidth() const = 0;
	virtual int GetHeight() const = 0;
	virtual bool Contains(unsigned arg0) const = 0;
	virtual int GetCountOfArchetype(uint64_t arg0) const = 0;
	virtual std::vector<IArkItem *> GetItemsOfArchetype(uint64_t arg0) const = 0;
	virtual unsigned GetNextItem(int arg0, int arg1, unsigned arg2) const = 0;
	virtual std::pair<int,int> GetLocationOfItem(unsigned arg0) const = 0;
	virtual unsigned GetItemAtLocation(int arg0, int arg1, unsigned arg2) const = 0;
	virtual std::vector<unsigned int> GetItemIDs() const = 0;
	virtual std::vector<unsigned int> GetOverlappingItems(const unsigned arg0, const int arg1, const int arg2, const int arg3, const int arg4) const = 0;
	virtual bool AddItem(unsigned arg0) = 0;
	virtual unsigned PlaceItem(unsigned arg0, int arg1, int arg2) = 0;
	virtual bool CanPlaceItem(unsigned arg0, int arg1, int arg2, bool arg3) const = 0;
	virtual bool TryPlaceItem(unsigned arg0, int arg1, int arg2) = 0;
	virtual bool CanPackItem(unsigned arg0) const = 0;
	virtual void RemoveItem(unsigned arg0) = 0;
	virtual void RemoveItem(uint64_t arg0, int arg1) = 0;
	virtual unsigned GetOwnerId() const = 0;
	virtual bool GetTakesTrash() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual void NotifyAdded(unsigned arg0, unsigned arg1) const = 0;
	virtual void NotifyOfItemCountChange(unsigned arg0) const = 0;
	virtual void DoMetricsSnapshot(XmlNodeRef const &arg0) const = 0;
};

