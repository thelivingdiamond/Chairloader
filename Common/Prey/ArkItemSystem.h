#pragma once
#include "ChairLoader/PreyFunction.h"
class IArkItem : IGameObjectExtension
{
public:
	virtual bool GiveOwner(const unsigned int) = 0;
	virtual bool PickUp(const unsigned int, bool) = 0;
	virtual void Drop(int, const Vec3_tpl<float>* const) = 0;
	virtual bool CanPlayerCollect() = 0;
	virtual int GetCount() = 0;
	virtual void ResetCount(int) = 0;
	virtual bool IsStackFull() = 0;
	virtual bool Combine(IArkItem*, bool) = 0;
	virtual const char* GetType() = 0;
	virtual const char* GetName() = 0;
	virtual unsigned __int64 GetArchetype() = 0;
	virtual CryStringT<wchar_t>* GetDescription(CryStringT<wchar_t>* result) = 0;
	virtual const char* GetIcon() = 0;
	virtual std::pair<int, int>* GetInventoryDimensions(std::pair<int, int>* result) = 0;
	virtual bool IsStackable() = 0;
	virtual int GetMaxStackSize() = 0;
	virtual bool IsGrenade() = 0;
	virtual bool IsEquippable() = 0;
	virtual bool IsTrash() = 0;
	virtual void SetLootRequirement(unsigned __int64) = 0;
	virtual bool CanLoot() = 0;
	virtual bool CanUse() = 0;
	virtual void Use() = 0;
	virtual void UseFromWorld() = 0;
	virtual void UseFromInventory() = 0;
	virtual void Consume(int) = 0;
	virtual bool CanConsume() = 0;
	virtual bool CanConsumeFromWorld() = 0;
	virtual bool IsWeapon() = 0;
	virtual bool IsEqual(const IArkItem*) = 0;
	virtual bool IsArchetype(const unsigned __int64) = 0;
	virtual bool IsArchetype(const IEntityArchetype*) = 0;
	virtual bool HasMetaTags(const std::vector<unsigned __int64>*) = 0;
	virtual unsigned int GetOwnerId() = 0;


};
// #include "pch.h"
// #include "preyDllObjects.h"
// class ArkItemSystem : public ILevelSystemListener// Size=0xf8 (Id=119458)
// {
//         char* k_defaultArkItemScript;// Offset=0x0 Size=0x8
//         char* k_arkItemConfigFile;// Offset=0x0 Size=0x8
//         char* k_pickupsLibrary;// Offset=0x0 Size=0x8
//         char* k_specialWeaponsLibrary;// Offset=0x0 Size=0x8
//         ArkItemSystem();// Offset=0x0 Size=0x1f6
//         ~ArkItemSystem();// Offset=0x0 Size=0x100
//         struct IArkItemCreator : public IGameObjectExtensionCreatorBase// Size=0x8 (Id=492057)
//         {
//             void IArkItemCreator(struct ArkItemSystem::IArkItemCreator*);
//             void IArkItemCreator(struct ArkItemSystem::IArkItemCreator&);
//             void IArkItemCreator();
//             void ~IArkItemCreator();
//             struct ArkItemSystem::IArkItemCreator& operator=(struct ArkItemSystem::IArkItemCreator*);
//             struct ArkItemSystem::IArkItemCreator& operator=(struct ArkItemSystem::IArkItemCreator&);
//             void __local_vftable_ctor_closure();
//             void* __vecDelDtor(unsigned int);
//         };
//         void Init();// Offset=0x0 Size=0x195
//         void ScanXML(class CryStringT<char>&, bool);// Offset=0x0 Size=0x6b6
//         void LoadEquipmentPacks();// Offset=0x0 Size=0x29
//         void Serialize(class CSerializeWrapper<ISerialize>);// Offset=0x0 Size=0x19
//         void AddItem(unsigned int, struct IArkItem&);// Offset=0x0 Size=0x171
//         void RemoveItem(unsigned int);// Offset=0x0 Size=0x1b
//         IArkItem* GetItem(unsigned int);// Offset=0x0 Size=0xbb
//         CEquipmentManager* GetEquipmentManager();
//         std::vector<CryStringT<char>, std::allocator<CryStringT<char> > >& GetItemClasses();
//         void OnLevelNotFound(char*);// Offset=0x0 Size=0x3
//         void OnLoadingStart(struct ILevelInfo*);// Offset=0x0 Size=0x428
//         void OnLoadingLevelEntitiesStart(struct ILevelInfo*);// Offset=0x0 Size=0x3
//         void OnLoadingComplete(struct ILevel*);// Offset=0x0 Size=0x3
//         void OnLoadingError(struct ILevelInfo*, char*);// Offset=0x0 Size=0x3
//         void OnLoadingProgress(struct ILevelInfo*, int);// Offset=0x0 Size=0x3
//         void OnUnloadComplete(struct ILevel*);// Offset=0x0 Size=0x3
//         IEntityArchetype* GetArchetype(char*, char*);// Offset=0x0 Size=0x229
//         std::vector<IEntityArchetype*, std::allocator<IEntityArchetype*> > GetPickupArchetypes();// Offset=0x0 Size=0xca
//         std::vector<IEntityArchetype*, std::allocator<IEntityArchetype*> > GetArchetypesForClass(char*);// Offset=0x0 Size=0x279
//         std::vector<IEntityArchetype*, std::allocator<IEntityArchetype*> > GetRandomizableArchetypes(unsigned int);// Offset=0x0 Size=0x4c3
//         void RemoveFromRandomizable(unsigned int, unsigned int);// Offset=0x0 Size=0x56
//         void ClearInvalidArchetypes(unsigned int);// Offset=0x0 Size=0x26
//         CryStringT<char> GetAmmoPickupClassName(class CryStringT<char>&);// Offset=0x0 Size=0x1c0
//         std::vector<unsigned int, std::allocator<unsigned int> > GiveArchetype(unsigned int, struct IEntityArchetype*, int);// Offset=0x0 Size=0x546
//         std::vector<unsigned int, std::allocator<unsigned int> > GiveArchetype(unsigned int, unsigned int, int);// Offset=0x0 Size=0x14c
//         std::vector<unsigned int, std::allocator<unsigned int> > GiveArchetype(unsigned int, char*, int);// Offset=0x0 Size=0x87
//         int GiveEntitlementItem(unsigned int, unsigned int, int, unsigned int);// Offset=0x0 Size=0x45e
//         void Reload();// Offset=0x0 Size=0x274
//         void GiveItemCmd(struct IConsoleCmdArgs*);// Offset=0x0 Size=0x134
//         void GiveEquipmentPackCmd(struct IConsoleCmdArgs*);// Offset=0x0 Size=0x5b
//         void ReloadXmlCmd(struct IConsoleCmdArgs*);// Offset=0x0 Size=0x2f
//         std::map<CryStringT<char>, ArkItemSystem::IArkItemCreator*, std::less<CryStringT<char> >, std::allocator<std::pair<CryStringT<char> const, ArkItemSystem::IArkItemCreator*> > > m_creators;// Offset=0x8 Size=0x10
//         std::unordered_map<unsigned int, IArkItem*, std::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<unsigned int const, IArkItem*> > > m_items;// Offset=0x18 Size=0x40
//         std::unique_ptr<CEquipmentManager, std::default_delete<CEquipmentManager> > m_pEquipmentManager;// Offset=0x58 Size=0x8
//         std::vector<CryStringT<char>, std::allocator<CryStringT<char> > > m_classes;// Offset=0x60 Size=0x18
//         std::unordered_map<CryStringT<char>, CryStringT<char>, std::hash<CryStringT<char> >, std::equal_to<CryStringT<char> >, std::allocator<std::pair<CryStringT<char> const, CryStringT<char> > > > m_projectileToPickup;// Offset=0x78 Size=0x40
//         std::unordered_map<unsigned __int64, std::vector<unsigned __int64, std::allocator<unsigned __int64> >, std::hash<unsigned __int64>, std::equal_to<unsigned __int64>, std::allocator<std::pair<unsigned __int64 const, std::vector<unsigned __int64, std::allocator<unsigned __int64> > > > > m_notValidForRandom;// Offset=0xb8 Size=0x40
// };

class ArkItemSystem {
public:
	static inline auto getItem = PreyFunction<IArkItem* (ArkItemSystem* _this, unsigned int)>(0x1441450);
};