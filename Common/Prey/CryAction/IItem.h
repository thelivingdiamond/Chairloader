// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>

class CCryName;
class IActionController;
struct IEntityClass;
struct IInventory;
struct IWeapon;
struct SViewParams;

// IItem
// Header:  _unknown/IItem.h
// Include: Prey/CryAction/IItem.h
struct IItem : public IGameObjectExtension
{ // Size=64 (0x40)
	enum eItemBackAttachment
	{
		eIBA_Primary = 0,
		eIBA_Secondary = 1,
		eIBA_Unknown = 2,
	};

	enum eItemHand
	{
		eIH_Right = 0,
		eIH_Left = 1,
		eIH_Last = 2,
	};

	virtual const char* GetType() const = 0;
	virtual unsigned GetOwnerId() const = 0;
	virtual void SetOwnerId(unsigned ownerId) = 0;
	virtual void EnableUpdate(bool enable, int slot) = 0;
	virtual void RequireUpdate(int slot) = 0;
	virtual void ForcePendingActions(uint8_t blockedActions) = 0;
	virtual void OnAction(unsigned actorId, const CCryName& actionId, int activationMode, float value) = 0;
	virtual void OnParentSelect(bool select) = 0;
	virtual void OnAttach(bool attach) = 0;
	virtual void OnPickedUp(unsigned actorId, bool destroyed) = 0;
	virtual void OnHit(float damage, int hitType) = 0;
	virtual void Select(bool select) = 0;
	virtual bool IsSelected() const = 0;
	virtual bool CanSelect() const = 0;
	virtual bool CanDeselect() const = 0;
	virtual void RemoveOwnerAttachedAccessories() = 0;
	virtual void Physicalize(bool enable, bool rigid) = 0;
	virtual bool CanDrop() const = 0;
	virtual void Drop(float impulseScale, bool selectNext, bool byDeath) = 0;
	virtual void UpdateFPView(float frameTime) = 0;
	virtual Vec3 GetMountedAngleLimits() const = 0;
	virtual bool PickUp(unsigned pickerId, bool sound, bool select, bool keepHistory, const char* setup, bool _bDropIfFull) = 0;
	virtual void MountAtEntity(unsigned entityId, const Vec3& pos, const Ang3& angles) = 0;
	virtual bool FilterView(SViewParams& viewParams) = 0;
	virtual void RemoveAllAccessories() = 0;
	virtual void DetachAllAccessories() = 0;
	virtual void AttachAccessory(IEntityClass* pAccessoryClass, bool attach, bool noanim, bool force, bool firstTimeAttached, bool initialLoadoutSetup) = 0;
	virtual void SetCurrentActionController(IActionController* pActionController) = 0;
	virtual void UpdateCurrentActionController() = 0;
	virtual const string GetAttachedAccessoriesString(const char* separator) = 0;
	virtual void SetHand(int hand) = 0;
	virtual void StartUse(unsigned userId) = 0;
	virtual void StopUse(unsigned userId) = 0;
	virtual void SetBusy(bool busy) = 0;
	virtual bool IsBusy() const = 0;
	virtual bool CanUse(unsigned userId) const = 0;
	virtual bool IsUsed() const = 0;
	virtual void Use(unsigned userId) = 0;
	virtual bool AttachToHand(bool attach, bool checkAttachment) = 0;
	virtual bool AttachToBack(bool attach) = 0;
	virtual bool IsModifying() const = 0;
	virtual bool CheckAmmoRestrictions(IInventory* pInventory) = 0;
	virtual void Reset() = 0;
	virtual bool ResetParams() = 0;
	virtual void PreResetParams() = 0;
	virtual bool GivesAmmo() = 0;
	virtual const char* GetDisplayName() const = 0;
	virtual const char* GetIcon() const = 0;
	virtual void GetInventoryDimensions(int& width, int& height) const = 0;
	virtual const char* GetDescription() const = 0;
	virtual void HideItem(bool hide) = 0;
	virtual void SetSubContextID(int subContext) = 0;
	virtual int GetSubContextID() = 0;
	virtual IWeapon* GetIWeapon() = 0;
	virtual const IWeapon* GetIWeapon() const = 0;
	virtual bool IsAccessory() = 0;
	virtual void SerializeLTL(TSerialize ser) = 0;
	virtual Vec3 GetMountedDir() const = 0;
};

