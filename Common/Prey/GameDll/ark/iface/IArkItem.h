// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>

struct IEntityArchetype;

// Header: Override
// Prey/GameDll/ark/iface/IArkItem.h
struct IArkItem : public IGameObjectExtension // Id=8001F57 Size=64
{
	virtual bool GiveOwner(const unsigned arg0) = 0;
	virtual bool PickUp(const unsigned arg0, bool arg1) = 0;
	virtual void Drop(int arg0, Vec3 const *const arg1) = 0;
	virtual bool CanPlayerCollect() const = 0;
	virtual int GetCount() const = 0;
	virtual void ResetCount(int arg0) = 0;
	virtual bool IsStackFull() const = 0;
	virtual bool Combine(IArkItem &arg0, bool arg1) = 0;
	virtual const char *GetType() const = 0;
	virtual const char *GetName() const = 0;
	virtual uint64_t GetArchetype() const = 0;
	virtual wstring GetDescription() const = 0;
	virtual const char *GetIcon() const = 0;
	virtual std::pair<int,int> GetInventoryDimensions() const = 0;
	virtual bool IsStackable() const = 0;
	virtual int GetMaxStackSize() const = 0;
	virtual bool IsGrenade() const = 0;
	virtual bool IsEquippable() const = 0;
	virtual bool IsTrash() const = 0;
	virtual void SetLootRequirement(uint64_t arg0) = 0;
	virtual bool CanLoot() const = 0;
	virtual bool CanUse() const = 0;
	virtual void Use() = 0;
	virtual void UseFromWorld() = 0;
	virtual void UseFromInventory() = 0;
	virtual void Consume(int arg0) = 0;
	virtual bool CanConsume() const = 0;
	virtual bool CanConsumeFromWorld() const = 0;
	virtual bool IsWeapon() const = 0;
	virtual bool IsEqual(IArkItem const &arg0) const = 0;
	virtual bool IsArchetype(IEntityArchetype const &arg0) const = 0;
	virtual bool IsArchetype(const uint64_t arg0) const = 0;
	virtual bool HasMetaTags(std::vector<unsigned __int64> const &arg0) const = 0;
	virtual unsigned GetOwnerId() const = 0;
	virtual ~IArkItem() {}
};

