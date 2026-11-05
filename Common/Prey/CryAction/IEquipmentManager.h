// Header file automatically created from a PDB.
#pragma once

struct IEquipmentPackPreCacheCallback;
class XmlNodeRef;

// IEquipmentManager
// Header:  _unknown/IEquipmentManager.h
// Include: Prey/CryAction/IItemSystem.h
struct IEquipmentManager
{ // Size=8 (0x8)
	// IEquipmentManager::IEquipmentPackIterator
	// Header:  _unknown/IEquipmentManager.h
	struct IEquipmentPackIterator
	{ // Size=8 (0x8)
		virtual ~IEquipmentPackIterator();
		virtual void AddRef() = 0;
		virtual void Release() = 0;
		virtual int GetCount() = 0;
		virtual const char* Next() = 0;
	};

	using IEquipmentPackIteratorPtr = _smart_ptr<IEquipmentManager::IEquipmentPackIterator>;

	virtual ~IEquipmentManager();
	virtual void DeleteAllEquipmentPacks() = 0;
	virtual void LoadEquipmentPacks(const XmlNodeRef& rootNode) = 0;
	virtual void LoadEquipmentPacksFromPath(const char* path) = 0;
	virtual bool LoadEquipmentPack(const XmlNodeRef& rootNode, bool bOverrideExisting) = 0;
	virtual bool GiveEquipmentPack(const char* _packName, bool _bAdd, bool _bSelectPrimary) = 0;
	virtual void PreCacheEquipmentPackResources(const char* packName, IEquipmentPackPreCacheCallback& preCacheCallback) = 0;
};

