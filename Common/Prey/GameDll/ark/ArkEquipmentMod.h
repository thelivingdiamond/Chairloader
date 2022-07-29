// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/arkitem.h>

class ArkEquipmentModComponent;
class IArkInventory;
struct IGameObject;
struct SEntityEvent;

// Header: FromCpp
// Prey/GameDll/ark/ArkEquipmentMod.h
class ArkEquipmentMod : public CArkItem // Id=80173B5 Size=416
{
public:
	ArkAudioTrigger m_installFailed;
	bool m_bIsNew;
	std::vector<unsigned int> m_activeStatMods;
	std::vector<unsigned __int64> m_exclusiveInstalls;
	
	ArkEquipmentMod();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void LoadCachedProperties();
	virtual bool PickUp(const unsigned _pickerId, bool _bScaleOnLerp);
	virtual bool GiveOwner(IArkInventory *_pInventory);
	virtual void OnInventoryTransfer(IArkInventory const &_source, IArkInventory const &_target);
	virtual bool CanPlayerCollect() const;
	void OnInstalled() { FOnInstalled(this); }
	void OnRemoved() { FOnRemoved(this); }
	void Activate() const { FActivate(this); }
	void Deactivate() const { FDeactivate(this); }
	uint64_t GetSignalPackage() const { return FGetSignalPackage(this); }
	bool IsSuitMod() const { return FIsSuitMod(this); }
	static ArkEquipmentMod *GetEquipmentModFromEntityId(unsigned _modId) { return FGetEquipmentModFromEntityId(_modId); }
	void AddModifiers(const char *const _inbound, const char *const _outbound) const { FAddModifiers(this,_inbound,_outbound); }
	void RemoveModifiers(const char *const _inbound, const char *const _outbound) const { FRemoveModifiers(this,_inbound,_outbound); }
	void ClearActiveStatMods() { FClearActiveStatMods(this); }
	void SetupActiveStatMods() { FSetupActiveStatMods(this); }
	virtual ~ArkEquipmentMod();
	
#if 0
	std::vector<unsigned __int64> const &GetExclusives() const;
	bool IsNew() const;
	void MarkSeen();
	ArkEquipmentModComponent &GetChipsetComponent() const;
#endif
	
	static inline auto FInit = PreyFunction<bool(ArkEquipmentMod *const _this, IGameObject *_pGameObject)>(0x115CE20);
	static inline auto FRelease = PreyFunction<void(ArkEquipmentMod *const _this)>(0x115D6C0);
	static inline auto FFullSerialize = PreyFunction<void(ArkEquipmentMod *const _this, TSerialize _ser)>(0x115C910);
	static inline auto FPostSerialize = PreyFunction<void(ArkEquipmentMod *const _this)>(0x115D630);
	static inline auto FProcessEvent = PreyFunction<void(ArkEquipmentMod *const _this, SEntityEvent &_event)>(0x115D6B0);
	static inline auto FLoadCachedProperties = PreyFunction<void(ArkEquipmentMod *const _this)>(0x115CFE0);
	static inline auto FPickUp = PreyFunction<bool(ArkEquipmentMod *const _this, const unsigned _pickerId, bool _bScaleOnLerp)>(0x115D570);
	static inline auto FGiveOwner = PreyFunction<bool(ArkEquipmentMod *const _this, IArkInventory *_pInventory)>(0x115CC50);
	static inline auto FOnInventoryTransfer = PreyFunction<void(ArkEquipmentMod *const _this, IArkInventory const &_source, IArkInventory const &_target)>(0x115D470);
	static inline auto FCanPlayerCollect = PreyFunction<bool(ArkEquipmentMod const *const _this)>(0x1B933B0);
	static inline auto FOnInstalled = PreyFunction<void(ArkEquipmentMod *const _this)>(0x115D430);
	static inline auto FOnRemoved = PreyFunction<void(ArkEquipmentMod *const _this)>(0x115D510);
	static inline auto FActivate = PreyFunction<void(ArkEquipmentMod const *const _this)>(0x115C440);
	static inline auto FDeactivate = PreyFunction<void(ArkEquipmentMod const *const _this)>(0x115C8F0);
	static inline auto FGetSignalPackage = PreyFunction<uint64_t(ArkEquipmentMod const *const _this)>(0x115CB40);
	static inline auto FIsSuitMod = PreyFunction<bool(ArkEquipmentMod const *const _this)>(0x115CF20);
	static inline auto FGetEquipmentModFromEntityId = PreyFunction<ArkEquipmentMod *(unsigned _modId)>(0x115CAA0);
	static inline auto FAddModifiers = PreyFunction<void(ArkEquipmentMod const *const _this, const char *const _inbound, const char *const _outbound)>(0x115C460);
	static inline auto FRemoveModifiers = PreyFunction<void(ArkEquipmentMod const *const _this, const char *const _inbound, const char *const _outbound)>(0x115D720);
	static inline auto FClearActiveStatMods = PreyFunction<void(ArkEquipmentMod *const _this)>(0x115C840);
	static inline auto FSetupActiveStatMods = PreyFunction<void(ArkEquipmentMod *const _this)>(0x115DB00);
};

