// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/weapons/arkweapon.h>
#include <Prey/GameDll/ark/weapons/ArkWrenchComponent.h>

class ArkNpc;
class CCryName;
struct SEntityUpdateContext;

// ArkWeaponWrench
// Header:  Prey/GameDll/ark/weapons/ArkWeaponWrench.h
class ArkWeaponWrench : public CArkWeapon
{ // Size=1376 (0x560)
public:
	enum class EArkAttackAnim
	{
		none = 0,
		inLR = 1,
		inRL = 2,
		LR = 3,
		RL = 4,
		hitLR = 5,
		hitEnemyLR = 6,
		hitRL = 7,
		hitEnemyRL = 8,
		outLR = 9,
		outRL = 10,
		fatalityRL = 11,
		fatalityLR = 12,
		genericFatality = 13,
	};
	
	ArkSimpleTimer m_cancelTimer;
	ArkWrenchComponent m_wrenchComponent;
	ArkWeaponWrench::EArkAttackAnim m_currentAnim = EArkAttackAnim::none;
	float m_chargeTime = 0.0f;
	float m_maxChargeTime = 0.0f;
	float m_maxChargeDamageBonus = 0.0f;
	bool m_bAttackHeld = false;
	bool m_bCharged = false;
	bool m_bShowingCancelPrompt = false;
	wstring m_quickHitBaseKeyword;
	wstring m_quickHitFinalKeyword;
	wstring m_chargedHitBaseKeyword;
	wstring m_chargedHitFinalKeyword;
	uint64_t m_damageSignal = -1;

	ArkWeaponWrench() : CArkWeapon(true)
	{
		m_cancelTimer.Invalidate();
	}
	
	void OnActionExit() { FOnActionExit(this); }
	void OnHit(const float _dir, const float _damageScale) { FOnHit(this, _dir, _damageScale); }
	void OnFatalityExit(ArkNpc& _npc) { FOnFatalityExit(this, _npc); }
	virtual bool IsEquippable() const { return FIsEquippable(this); }
	virtual bool CanEquipFromInventory() const { return FCanEquipFromInventory(this); }
	virtual unsigned GetEquipId() const { return FGetEquipId(this); }
	virtual string GetUIAmmoCountString() const { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FGetUIAmmoCountString(this, reinterpret_cast<string*>(_return_buf_)); }
	void PlayAnim(const ArkWeaponWrench::EArkAttackAnim _anim, const bool _bInterrupt, ArkNpc* const _pNPC) { FPlayAnim(this, _anim, _bInterrupt, _pNPC); }
	virtual bool ForceCancelCharge() { return FForceCancelCharge(this); }
	virtual void CancelCharge() { FCancelCharge(this); }
	virtual wstring GetDescription() const { alignas(wstring) std::byte _return_buf_[sizeof(wstring)]; return *FGetDescription(this, reinterpret_cast<wstring*>(_return_buf_)); }
	virtual CCryName GetReticleName() const { alignas(CCryName) std::byte _return_buf_[sizeof(CCryName)]; return *FGetReticleName(this, reinterpret_cast<CCryName*>(_return_buf_)); }
	virtual int GetBaseDamage() const { return FGetBaseDamage(this); }
	virtual int GetModifiedDamage(const std::vector<uint64_t>& _modifiers) const { return FGetModifiedDamage(this, _modifiers); }
	virtual bool HasAmmo() const { return FHasAmmo(this); }
	virtual float GetDegradationRate() const { return FGetDegradationRate(this); }
	virtual int GetInventoryAmmoCount() const { return FGetInventoryAmmoCount(this); }
	virtual void ConsumeAmmo() { FConsumeAmmo(this); }
	virtual void LoadCachedProperties() { FLoadCachedProperties(this); }
	virtual void InitializeStats() { FInitializeStats(this); }
	virtual void OnUnequip(const bool _bUnselect) { FOnUnequip(this, _bUnselect); }
	virtual bool OnActionAttackPrimary(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value) { return FOnActionAttackPrimary(this, _entityId, _actionId, _activationMode, _value); }
	virtual bool OnActionAttackUse(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value) { return FOnActionAttackUse(this, _entityId, _actionId, _activationMode, _value); }
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const { alignas(CCryName) std::byte _return_buf_[sizeof(CCryName)]; return *FGetPlayerWeaponSpecificCritChanceStatName(this, reinterpret_cast<CCryName*>(_return_buf_)); }
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot) { FUpdate(this, _ctx, _updateSlot); }
	void EndIntro() { FEndIntro(this); }
	void CloseCancelPrompt() { FCloseCancelPrompt(this); }
	
#if 0
	void OnChainEvent();
	void OnChargeEvent();
	void OnDirectionParamSet(const float _arg0_);
	void PlayHit(const ArkWeaponWrench::EArkAttackAnim _arg0_, const ArkWeaponWrench::EArkAttackAnim _arg1_);
#endif
	
	static inline auto FOnActionExit = PreyFunction<void(ArkWeaponWrench* const _this)>(0x1684A60);
	static inline auto FOnHit = PreyFunction<void(ArkWeaponWrench* const _this, const float _dir, const float _damageScale)>(0x1685090);
	static inline auto FOnFatalityExit = PreyFunction<void(ArkWeaponWrench* const _this, ArkNpc& _npc)>(0x1685050);
	static inline auto FIsEquippable = PreyFunction<bool(const CArkItem* const _this)>(0x1683B80);
	static inline auto FCanEquipFromInventory = PreyFunction<bool(const CArkItem* const _this)>(0x1B933B0);
	static inline auto FGetEquipId = PreyFunction<unsigned(const CArkItem* const _this)>(0x1704660);
	static inline auto FGetUIAmmoCountString = PreyFunction<string*(const ArkWeaponWrench* const _this, string* _return_value_)>(0x58EC20);
	static inline auto FPlayAnim = PreyFunction<void(ArkWeaponWrench* const _this, const ArkWeaponWrench::EArkAttackAnim _anim, const bool _bInterrupt, ArkNpc* const _pNPC)>(0x16852F0);
	static inline auto FForceCancelCharge = PreyFunction<bool(ArkWeaponWrench* const _this)>(0x1704640);
	static inline auto FCancelCharge = PreyFunction<void(ArkWeaponWrench* const _this)>(0x1701870);
	static inline auto FGetDescription = PreyFunction<wstring*(const CArkItem* const _this, wstring* _return_value_)>(0x1683190);
	static inline auto FGetReticleName = PreyFunction<CCryName*(const ArkWeaponWrench* const _this, CCryName* _return_value_)>(0x1704DF0);
	static inline auto FGetBaseDamage = PreyFunction<int(const ArkWeaponWrench* const _this)>(0x1683150);
	static inline auto FGetModifiedDamage = PreyFunction<int(const ArkWeaponWrench* const _this, const std::vector<uint64_t>& _modifiers)>(0x1683AE0);
	static inline auto FHasAmmo = PreyFunction<bool(const ArkWeaponWrench* const _this)>(0x1B933B0);
	static inline auto FGetDegradationRate = PreyFunction<float(const ArkWeaponWrench* const _this)>(0xB5F050);
	static inline auto FGetInventoryAmmoCount = PreyFunction<int(const ArkWeaponWrench* const _this)>(0x158AEF0);
	static inline auto FConsumeAmmo = PreyFunction<void(ArkWeaponWrench* const _this)>(0xA13080);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem* const _this)>(0x1683BA0);
	static inline auto FInitializeStats = PreyFunction<void(ArkWeaponWrench* const _this)>(0x1683B20);
	static inline auto FOnUnequip = PreyFunction<void(ArkWeaponWrench* const _this, const bool _bUnselect)>(0x170B9B0);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(ArkWeaponWrench* const _this, unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value)>(0x16844A0);
	static inline auto FOnActionAttackUse = PreyFunction<bool(ArkWeaponWrench* const _this, unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value)>(0x1704640);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName*(const ArkWeaponWrench* const _this, CCryName* _return_value_)>(0x138B920);
	static inline auto FUpdate = PreyFunction<void(CArkItem* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x1685570);
	static inline auto FEndIntro = PreyFunction<void(ArkWeaponWrench* const _this)>(0x1682D00);
	static inline auto FCloseCancelPrompt = PreyFunction<void(ArkWeaponWrench* const _this)>(0x1682BF0);
};
