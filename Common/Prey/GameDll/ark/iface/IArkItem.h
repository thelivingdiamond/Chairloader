// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryAction/IGameObject.h>

struct IEntity;
struct IEntityArchetype;

// IArkItem
// Header:  Prey/GameDll/ark/iface/IArkItem.h
struct IArkItem : public IGameObjectExtension
{ // Size=64 (0x40)
	enum class EArkQualityTier
	{
		none = 0,
		common = 1,
		rare = 2,
		legendary = 3,
		special = 4,
		last = 5,
	};

	static IArkItem::EArkQualityTier GetEnumFromString(const char* const _string) { return FGetEnumFromString(_string); }
	virtual bool GiveOwner(const unsigned _pickerId) = 0;
	virtual bool PickUp(const unsigned _pickerId, bool _bScaleOnLerp) = 0;
	virtual IEntity* Drop(int _dropCount, const Vec3* const _altPosition) = 0;
	virtual bool CanPlayerCollect() const = 0;
	virtual int GetCount() const = 0;
	virtual void ResetCount(int _count) = 0;
	virtual bool IsStackFull() const = 0;
	virtual bool Combine(IArkItem& _other, bool _bRemoveOnSuccess) = 0;
	virtual const char* GetType() const = 0;
	virtual const char* GetName() const = 0;
	virtual uint64_t GetArchetype() const = 0;
	virtual wstring GetDescription() const = 0;
	virtual const char* GetIcon() const = 0;
	virtual std::pair<int, int> GetInventoryDimensions() const = 0;
	virtual bool IsStackable() const = 0;
	virtual int GetMaxStackSize() const = 0;
	virtual bool IsGrenade() const = 0;
	virtual bool IsEquippable() const = 0;
	virtual bool IsTrash() const = 0;
	virtual void SetLootRequirement(uint64_t _abilityId) = 0;
	virtual bool CanLoot() const = 0;
	virtual bool CanUse() const = 0;
	virtual void Use() = 0;
	virtual void UseFromWorld() = 0;
	virtual void UseFromInventory() = 0;
	virtual void Consume(int _count) = 0;
	virtual bool CanConsume() const = 0;
	virtual bool CanConsumeFromWorld() const = 0;
	virtual bool IsWeapon() const = 0;
	virtual bool IsEqual(const IArkItem& other) const = 0;
	virtual bool IsArchetype(const IEntityArchetype& _archetype) const = 0;
	virtual bool IsArchetype(const uint64_t _archetypeId) const = 0;
	virtual bool HasMetaTags(const std::vector<uint64_t>& _tags) const = 0;
	virtual bool HasSpawnedPet() const = 0;
	virtual unsigned GetOwnerId() const = 0;

#if 0
	static const char* GetStringFromEnum(const IArkItem::EArkQualityTier _arg0_);
#endif

	static inline auto FGetEnumFromString = PreyFunction<IArkItem::EArkQualityTier(const char* const _string)>(0x1087C10);
};
#endif // !MOONCRASH
