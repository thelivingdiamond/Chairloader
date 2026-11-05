// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

enum EEntityFlags;
struct IActor;
struct IArkItem;
struct ICharacterInstance;
struct IEntity;
struct IEquipmentManager;
struct IItem;
struct IItemParamsNode;
struct IItemSystemListener;
enum IItemSystemQuery;
struct IStatObj;

// IItemSystem
// Header:  _unknown/IItemSystem.h
// Include: Prey/CryAction/IItemSystem.h
struct IItemSystem
{ // Size=8 (0x8)
	virtual ~IItemSystem();
	virtual void Reset() = 0;
	virtual void Reload() = 0;
	virtual void PreReload() = 0;
	virtual void PostReload() = 0;
	virtual void Scan(const char* folderName) = 0;
	virtual IItemParamsNode* CreateParams() = 0;
	virtual const IItemParamsNode* GetItemParams(const char* itemName) const = 0;
	virtual const char* GetItemParamsDescriptionFile(const char* itemName) const = 0;
	virtual int GetItemParamsCount() const = 0;
	virtual const char* GetItemParamName(int index) const = 0;
	virtual uint8_t GetItemPriority(const char* itemName) const = 0;
	virtual const char* GetItemCategory(const char* itemName) const = 0;
	virtual uint8_t GetItemUniqueId(const char* itemName) const = 0;
	virtual std::pair<int, int> GetItemInventoryDimensions(unsigned _id) const = 0;
	virtual bool IsItemClass(const char* name) const = 0;
	virtual const char* GetFirstItemClass() = 0;
	virtual const char* GetNextItemClass() = 0;
	virtual void RegisterForCollection(unsigned itemId) = 0;
	virtual void UnregisterForCollection(unsigned itemId) = 0;
	virtual void AddItem(unsigned itemId, IItem* pItem) = 0;
	virtual void RemoveItem(unsigned itemId, const char* itemName) = 0;
	virtual IItem* GetItem(unsigned itemId) const = 0;
	virtual void AddArkItem(unsigned itemId, IArkItem* pArkItem) = 0;
	virtual void RemoveArkItem(unsigned itemId, const char* itemName) = 0;
	virtual IArkItem* GetArkItem(unsigned itemId) const = 0;
	virtual void SetConfiguration(const char* name) = 0;
	virtual const char* GetConfiguration() const = 0;
	virtual void* Query(IItemSystemQuery query, const void* param) = 0;
	virtual ICharacterInstance* GetCachedCharacter(const char* fileName) = 0;
	virtual IStatObj* GetCachedObject(const char* fileName) = 0;
	virtual void CacheObject(const char* fileName, bool useCgfStreaming) = 0;
	virtual void CacheGeometry(const IItemParamsNode* geometry) = 0;
	virtual void CacheItemGeometry(const char* className) = 0;
	virtual void ClearGeometryCache() = 0;
	virtual void CacheItemSound(const char* className) = 0;
	virtual void ClearSoundCache() = 0;
	virtual void Serialize(TSerialize ser) = 0;
	virtual IEntity* SpawnEntity(const char* itemClass, EEntityFlags entityFlags) = 0;
	virtual unsigned GiveItem(unsigned _ownerId, const char* item, bool sound, bool select, bool keepHistory, const char* setup, EEntityFlags entityFlags) = 0;
	virtual unsigned GiveStackable(unsigned _ownerId, const char* _itemClass, const char* _arkType, int _count) = 0;
	virtual void SetActorItem(IActor* pActor, unsigned itemId, bool keepHistory) = 0;
	virtual void SetActorItem(IActor* pActor, const char* name, bool keepHistory) = 0;
	virtual void DropActorItem(IActor* pActor, unsigned itemId) = 0;
	virtual void SetActorAccessory(IActor* pActor, unsigned itemId, bool keepHistory) = 0;
	virtual void DropActorAccessory(IActor* pActor, unsigned itemId) = 0;
	virtual void RegisterListener(IItemSystemListener* pListener) = 0;
	virtual void UnregisterListener(IItemSystemListener* pListener) = 0;
	virtual IEquipmentManager* GetIEquipmentManager() = 0;
	virtual unsigned GetItemSocketCount(const char* item) const = 0;
	virtual const char* GetItemSocketName(const char* item, int idx) const = 0;
	virtual bool IsCompatible(const char* item, const char* attachment) const = 0;
	virtual bool GetItemSocketCompatibility(const char* item, const char* socket) const = 0;
	virtual bool CanSocketBeEmpty(const char* item, const char* socket) const = 0;
};

