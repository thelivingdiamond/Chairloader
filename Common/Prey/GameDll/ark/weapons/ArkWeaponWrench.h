// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/weapons/ArkWrenchComponent.h>
#include <Prey/GameDll/ark/weapons/arkweapon.h>

class ArkNpc;
struct SEntityUpdateContext;

// Header: Exact
// Prey/GameDll/ark/weapons/ArkWeaponWrench.h
class ArkWeaponWrench : public CArkWeapon // Id=801BC23 Size=1376
{
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
	ArkWeaponWrench::EArkAttackAnim m_currentAnim;
	float m_chargeTime;
	float m_maxChargeTime;
	float m_maxChargeDamageBonus;
	bool m_bAttackHeld;
	bool m_bCharged;
	bool m_bShowingCancelPrompt;
	wstring m_quickHitBaseKeyword;
	wstring m_quickHitFinalKeyword;
	wstring m_chargedHitBaseKeyword;
	wstring m_chargedHitFinalKeyword;
	uint64_t m_damageSignal;
	
	void OnActionExit() { FOnActionExit(this); }
	void OnHit(const float _dir, const float _damageScale) { FOnHit(this,_dir,_damageScale); }
	void OnFatalityExit(ArkNpc &_npc) { FOnFatalityExit(this,_npc); }
	virtual bool IsEquippable() const;
	virtual bool CanEquipFromInventory() const;
	virtual unsigned GetEquipId() const;
	virtual string GetUIAmmoCountString() const;
	void PlayAnim(ArkWeaponWrench::EArkAttackAnim _anim, const bool _bInterrupt, ArkNpc *const _pNPC) { FPlayAnim(this,_anim,_bInterrupt,_pNPC); }
	virtual bool ForceCancelCharge();
	virtual void CancelCharge();
	virtual wstring GetDescription() const;
	virtual CCryName GetReticleName() const;
	virtual int GetBaseDamage() const;
	virtual int GetModifiedDamage(std::vector<unsigned __int64> const &_modifiers) const;
	virtual bool HasAmmo() const;
	virtual float GetDegradationRate() const;
	virtual int GetInventoryAmmoCount() const;
	virtual void ConsumeAmmo();
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	virtual void OnUnequip(const bool _bUnselect);
	virtual bool OnActionAttackPrimary(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual bool OnActionAttackUse(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	void EndIntro() { FEndIntro(this); }
	void CloseCancelPrompt() { FCloseCancelPrompt(this); }
	
#if 0
	void OnChainEvent();
	void OnChargeEvent();
	void OnDirectionParamSet(const float arg0);
	void PlayHit(ArkWeaponWrench::EArkAttackAnim arg0, ArkWeaponWrench::EArkAttackAnim arg1);
#endif
	
	static inline auto FOnActionExit = PreyFunction<void(ArkWeaponWrench *const _this)>(0x1684A60);
	static inline auto FOnHit = PreyFunction<void(ArkWeaponWrench *const _this, const float _dir, const float _damageScale)>(0x1685090);
	static inline auto FOnFatalityExit = PreyFunction<void(ArkWeaponWrench *const _this, ArkNpc &_npc)>(0x1685050);
	static inline auto FIsEquippable = PreyFunction<bool(ArkWeaponWrench const *const _this)>(0x1683B80);
	static inline auto FCanEquipFromInventory = PreyFunction<bool(ArkWeaponWrench const *const _this)>(0x1B933B0);
	static inline auto FGetEquipId = PreyFunction<unsigned(ArkWeaponWrench const *const _this)>(0x1704660);
	static inline auto FGetUIAmmoCountString = PreyFunction<string(ArkWeaponWrench const *const _this)>(0x58EC20);
	static inline auto FPlayAnim = PreyFunction<void(ArkWeaponWrench *const _this, ArkWeaponWrench::EArkAttackAnim _anim, const bool _bInterrupt, ArkNpc *const _pNPC)>(0x16852F0);
	static inline auto FForceCancelCharge = PreyFunction<bool(ArkWeaponWrench *const _this)>(0x1704640);
	static inline auto FCancelCharge = PreyFunction<void(ArkWeaponWrench *const _this)>(0x1701870);
	static inline auto FGetDescription = PreyFunction<wstring(ArkWeaponWrench const *const _this)>(0x1683190);
	static inline auto FGetReticleName = PreyFunction<CCryName(ArkWeaponWrench const *const _this)>(0x1704DF0);
	static inline auto FGetBaseDamage = PreyFunction<int(ArkWeaponWrench const *const _this)>(0x1683150);
	static inline auto FGetModifiedDamage = PreyFunction<int(ArkWeaponWrench const *const _this, std::vector<unsigned __int64> const &_modifiers)>(0x1683AE0);
	static inline auto FHasAmmo = PreyFunction<bool(ArkWeaponWrench const *const _this)>(0x1B933B0);
	static inline auto FGetDegradationRate = PreyFunction<float(ArkWeaponWrench const *const _this)>(0xB5F050);
	static inline auto FGetInventoryAmmoCount = PreyFunction<int(ArkWeaponWrench const *const _this)>(0x158AEF0);
	static inline auto FConsumeAmmo = PreyFunction<void(ArkWeaponWrench *const _this)>(0xA13080);
	static inline auto FLoadCachedProperties = PreyFunction<void(ArkWeaponWrench *const _this)>(0x1683BA0);
	static inline auto FInitializeStats = PreyFunction<void(ArkWeaponWrench *const _this)>(0x1683B20);
	static inline auto FOnUnequip = PreyFunction<void(ArkWeaponWrench *const _this, const bool _bUnselect)>(0x170B9B0);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(ArkWeaponWrench *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x16844A0);
	static inline auto FOnActionAttackUse = PreyFunction<bool(ArkWeaponWrench *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1704640);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName(ArkWeaponWrench const *const _this)>(0x138B920);
	static inline auto FUpdate = PreyFunction<void(ArkWeaponWrench *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x1685570);
	static inline auto FEndIntro = PreyFunction<void(ArkWeaponWrench *const _this)>(0x1682D00);
	static inline auto FCloseCancelPrompt = PreyFunction<void(ArkWeaponWrench *const _this)>(0x1682BF0);
};

