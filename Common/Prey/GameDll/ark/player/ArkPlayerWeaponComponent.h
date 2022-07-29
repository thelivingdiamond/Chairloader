// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IArkAbilityListener.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>

class ArkPlayer;
class CArkItem;
class CArkWeapon;
struct IEntity;
struct SEntityEvent;
struct SEntitySpawnParams;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerWeaponComponent.h
class ArkPlayerWeaponComponent : public IArkInventoryListener, public IArkAbilityListener, public IEntityEventListener // Id=80174CE Size=224
{
public:
	std::vector<unsigned int> m_weaponEntityIds;
	std::vector<unsigned int> m_specialWeaponIds;
	ArkPlayer &m_player;
	ArkAudioTrigger m_triggerSneakAttack;
	ArkAudioTrigger m_triggerCriticalHit;
	unsigned m_equippedWeaponId;
	unsigned m_lastEquippedWeaponId;
	unsigned m_backupWeaponId;
	unsigned m_toBeEquippedWeaponId;
	float m_weaponCameraSpeedMultiplierAcceleration;
	float m_weaponCameraSpeedMultiplier;
	float m_aimAssistTargetRangeSq;
	float m_gameLogReportWindow;
	bool m_bIsUnequipping;
	bool m_bCanEquip;
	std::vector<unsigned __int64> m_weaponTypesAcquired;
	
	class GameLogData // Id=80174CF Size=8
	{
	public:
		unsigned m_target;
		ArkTimeRemaining m_timer;
		
#if 0
		bool operator==(const unsigned arg0) const;
#endif
	};

	std::vector<ArkPlayerWeaponComponent::GameLogData> m_sneakAttackData;
	std::vector<ArkPlayerWeaponComponent::GameLogData> m_criticalHitData;
	std::vector<ArkPlayerWeaponComponent::GameLogData> m_mimicHitData;
	
	virtual ~ArkPlayerWeaponComponent();
	void Init() { FInit(this); }
	unsigned GetEquippedOrToEquipWeaponId() const { return FGetEquippedOrToEquipWeaponId(this); }
	std::vector<unsigned int> GetFavoritedWeapons() const { return FGetFavoritedWeapons(this); }
	CArkWeapon *GetEquippedWeapon() const { return FGetEquippedWeapon(this); }
	float GetInputRotationScale(const float _frameTime) { return FGetInputRotationScale(this,_frameTime); }
	void RemoveWeapons() { FRemoveWeapons(this); }
	void UnequipWeapon(const bool _bUnselect, const bool _bToReequip) { FUnequipWeapon(this,_bUnselect,_bToReequip); }
	void SneakAttackAgainstTarget(unsigned _targetId, float _scale) { FSneakAttackAgainstTarget(this,_targetId,_scale); }
	void CriticalHitAgainstTarget(unsigned _targetId) { FCriticalHitAgainstTarget(this,_targetId); }
	void MimicHit(unsigned _targetId) { FMimicHit(this,_targetId); }
	CArkWeapon *GetGrenadeWeapon(CArkItem const &_ammoPickupItem) const { return FGetGrenadeWeapon(this,_ammoPickupItem); }
	bool CanWeaponBeEquipped(unsigned _weaponId) const { return FCanWeaponBeEquipped(this,_weaponId); }
	bool Equip(const unsigned _itemId) { return FEquip(this,_itemId); }
	bool EquipWeapon(const unsigned _newWeaponId) { return FEquipWeaponOv0(this,_newWeaponId); }
	bool IsEquipped(const unsigned _itemId) const { return FIsEquipped(this,_itemId); }
	void GiveGrenadeWeapon(string const &_archetypeName) { FGiveGrenadeWeapon(this,_archetypeName); }
	void GiveSpecialWeapons() { FGiveSpecialWeapons(this); }
	unsigned SpawnWeapon(SEntitySpawnParams &_params) { return FSpawnWeapon(this,_params); }
	unsigned FindWeapon(const uint64_t _archetypeId) const { return FFindWeapon(this,_archetypeId); }
	static bool IsWrench(unsigned _itemId) { return FIsWrench(_itemId); }
	bool ShouldConsiderWeaponAsDoubleWrench(const unsigned _itemId) const { return FShouldConsiderWeaponAsDoubleWrench(this,_itemId); }
	CArkWeapon *GetDoubleWrench() const { return FGetDoubleWrench(this); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Serialize(TSerialize &_ser) { FSerialize(this,_ser); }
	void SerializeForLevelTransition(TSerialize &_ser) { FSerializeForLevelTransition(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void HideWeapon() const { FHideWeapon(this); }
	void ShowWeapon() const { FShowWeapon(this); }
	void SetCanEquip(const bool _bCanEquip) { FSetCanEquip(this,_bCanEquip); }
	bool HasWeaponArchetypeBeenAcquired(uint64_t _weaponArchId) const { return FHasWeaponArchetypeBeenAcquired(this,_weaponArchId); }
	void AddToAcquiredWeaponTypes(uint64_t _weaponArchId) { FAddToAcquiredWeaponTypes(this,_weaponArchId); }
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	virtual void OnItemAdded(unsigned _entityId, unsigned _originalId);
	virtual void OnItemRemoved(unsigned _entityId);
	virtual void OnAbilityAdded(uint64_t _abilityId);
	bool CanEquip() const { return FCanEquip(this); }
	void OnDoubleWrenchEnabled() { FOnDoubleWrenchEnabled(this); }
	void RestoreVitalsOnSneakAttack() { FRestoreVitalsOnSneakAttack(this); }
	void EnsureSpecialWeapons() { FEnsureSpecialWeapons(this); }
	
#if 0
	unsigned GetEquippedWeaponId() const;
	unsigned GetWeaponToEquipId() const;
	void SetWeaponToEquip(const unsigned arg0);
	std::vector<unsigned int> GetWeaponEntityIds() const;
	void Reset();
	CArkWeapon *GetLastEquippedWeapon() const;
	void LoadConfig(XmlNodeRef const &arg0);
	void SetWeaponUnequipped();
	void ReequipLastWeapon();
	void QuickswapWeapons();
	bool EquipWeapon(CArkWeapon const *arg0);
	float GetAimAssistTargetRangeSq() const;
	bool EquipGrenade(CArkItem const &arg0);
	bool IsSpecialWeapon(unsigned arg0) const;
#endif
	
	static inline auto FBitNotArkPlayerWeaponComponent = PreyFunction<void(ArkPlayerWeaponComponent *const _this)>(0x1247520);
	static inline auto FInit = PreyFunction<void(ArkPlayerWeaponComponent *const _this)>(0x1248D30);
	static inline auto FGetEquippedOrToEquipWeaponId = PreyFunction<unsigned(ArkPlayerWeaponComponent const *const _this)>(0x12484B0);
	static inline auto FGetFavoritedWeapons = PreyFunction<std::vector<unsigned int>(ArkPlayerWeaponComponent const *const _this)>(0x1248510);
	static inline auto FGetEquippedWeapon = PreyFunction<CArkWeapon *(ArkPlayerWeaponComponent const *const _this)>(0x1248500);
	static inline auto FGetInputRotationScale = PreyFunction<float(ArkPlayerWeaponComponent *const _this, const float _frameTime)>(0x12487D0);
	static inline auto FRemoveWeapons = PreyFunction<void(ArkPlayerWeaponComponent *const _this)>(0x1249AC0);
	static inline auto FUnequipWeapon = PreyFunction<void(ArkPlayerWeaponComponent *const _this, const bool _bUnselect, const bool _bToReequip)>(0x124AC30);
	static inline auto FSneakAttackAgainstTarget = PreyFunction<void(ArkPlayerWeaponComponent *const _this, unsigned _targetId, float _scale)>(0x124A840);
	static inline auto FCriticalHitAgainstTarget = PreyFunction<void(ArkPlayerWeaponComponent *const _this, unsigned _targetId)>(0x1247850);
	static inline auto FMimicHit = PreyFunction<void(ArkPlayerWeaponComponent *const _this, unsigned _targetId)>(0x1248EA0);
	static inline auto FGetGrenadeWeapon = PreyFunction<CArkWeapon *(ArkPlayerWeaponComponent const *const _this, CArkItem const &_ammoPickupItem)>(0x12486A0);
	static inline auto FCanWeaponBeEquipped = PreyFunction<bool(ArkPlayerWeaponComponent const *const _this, unsigned _weaponId)>(0x1247810);
	static inline auto FEquip = PreyFunction<bool(ArkPlayerWeaponComponent *const _this, const unsigned _itemId)>(0x12480A0);
	static inline auto FEquipWeaponOv0 = PreyFunction<bool(ArkPlayerWeaponComponent *const _this, const unsigned _newWeaponId)>(0x1248150);
	static inline auto FIsEquipped = PreyFunction<bool(ArkPlayerWeaponComponent const *const _this, const unsigned _itemId)>(0x1248D80);
	static inline auto FGiveGrenadeWeapon = PreyFunction<void(ArkPlayerWeaponComponent *const _this, string const &_archetypeName)>(0x1248840);
	static inline auto FGiveSpecialWeapons = PreyFunction<void(ArkPlayerWeaponComponent *const _this)>(0x1248950);
	static inline auto FSpawnWeapon = PreyFunction<unsigned(ArkPlayerWeaponComponent *const _this, SEntitySpawnParams &_params)>(0x124AB60);
	static inline auto FFindWeapon = PreyFunction<unsigned(ArkPlayerWeaponComponent const *const _this, const uint64_t _archetypeId)>(0x1248310);
	static inline auto FIsWrench = PreyFunction<bool(unsigned _itemId)>(0x1248E40);
	static inline auto FShouldConsiderWeaponAsDoubleWrench = PreyFunction<bool(ArkPlayerWeaponComponent const *const _this, const unsigned _itemId)>(0x124A740);
	static inline auto FGetDoubleWrench = PreyFunction<CArkWeapon *(ArkPlayerWeaponComponent const *const _this)>(0x1248420);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerWeaponComponent *const _this, float _frameTime)>(0x124ACA0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerWeaponComponent *const _this, TSerialize &_ser)>(0x1249CE0);
	static inline auto FSerializeForLevelTransition = PreyFunction<void(ArkPlayerWeaponComponent *const _this, TSerialize &_ser)>(0x1249E30);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerWeaponComponent *const _this)>(0x12499B0);
	static inline auto FHideWeapon = PreyFunction<void(ArkPlayerWeaponComponent const *const _this)>(0x1248CF0);
	static inline auto FShowWeapon = PreyFunction<void(ArkPlayerWeaponComponent const *const _this)>(0x124A800);
	static inline auto FSetCanEquip = PreyFunction<void(ArkPlayerWeaponComponent *const _this, const bool _bCanEquip)>(0x124A730);
	static inline auto FHasWeaponArchetypeBeenAcquired = PreyFunction<bool(ArkPlayerWeaponComponent const *const _this, uint64_t _weaponArchId)>(0x1248CC0);
	static inline auto FAddToAcquiredWeaponTypes = PreyFunction<void(ArkPlayerWeaponComponent *const _this, uint64_t _weaponArchId)>(0x12476E0);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkPlayerWeaponComponent *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x1249500);
	static inline auto FOnItemAdded = PreyFunction<void(ArkPlayerWeaponComponent *const _this, unsigned _entityId, unsigned _originalId)>(0x12495F0);
	static inline auto FOnItemRemoved = PreyFunction<void(ArkPlayerWeaponComponent *const _this, unsigned _entityId)>(0x1249770);
	static inline auto FOnAbilityAdded = PreyFunction<void(ArkPlayerWeaponComponent *const _this, uint64_t _abilityId)>(0x1249410);
	static inline auto FCanEquip = PreyFunction<bool(ArkPlayerWeaponComponent const *const _this)>(0x1247730);
	static inline auto FOnDoubleWrenchEnabled = PreyFunction<void(ArkPlayerWeaponComponent *const _this)>(0x1249430);
	static inline auto FRestoreVitalsOnSneakAttack = PreyFunction<void(ArkPlayerWeaponComponent *const _this)>(0x1249C50);
	static inline auto FEnsureSpecialWeapons = PreyFunction<void(ArkPlayerWeaponComponent *const _this)>(0x1247C90);
};

