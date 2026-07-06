// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/weapons/ArkWrenchComponent.h>
#include <Prey/GameDll/ark/weapons/arkweapon.h>

class ArkNpc;

// Header: Exact
// Prey/GameDll/ark/weapons/ArkWeaponDoubleWrench.h
class ArkWeaponDoubleWrench : public CArkWeapon // Id=801BC22 Size=1312
{
public:
	static const uint64_t k_doubleWrenchAbilityRequirement;
	
	enum class EArkAttackAnim
	{
		none = 0,
		a = 1,
		b = 2,
		c = 3,
		d = 4,
		e = 5,
		f = 6,
		g = 7,
		hitA = 8,
		hitB = 9,
		hitC = 10,
		hitD = 11,
		hitE = 12,
		hitF = 13,
		hitG = 14,
		hitEnemyA = 15,
		hitEnemyB = 16,
		hitEnemyC = 17,
		hitEnemyD = 18,
		hitEnemyE = 19,
		hitEnemyF = 20,
		hitEnemyG = 21,
		fatality = 22,
		genericFatality = 23,
	};

	ArkWrenchComponent m_wrenchComponent;
	ArkWeaponDoubleWrench::EArkAttackAnim m_currentAnim;
	
	void OnActionExit() { FOnActionExit(this); }
	void OnHit(const float _dir, const float _damageScale) { FOnHit(this,_dir,_damageScale); }
	void OnFatalityExit(ArkNpc &_npc) { FOnFatalityExit(this,_npc); }
	void PlayAnim(ArkWeaponDoubleWrench::EArkAttackAnim _anim, bool _bInterrupt, ArkNpc *const _pNPC) { FPlayAnim(this,_anim,_bInterrupt,_pNPC); }
	virtual bool HasAmmo() const;
	virtual float GetDegradationRate() const;
	virtual int GetInventoryAmmoCount() const;
	virtual void ConsumeAmmo();
	virtual bool IsEquippable() const;
	virtual string GetUIAmmoCountString() const;
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	virtual void OnUnequip(const bool _bUnselect);
	virtual bool OnActionAttackPrimary(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;
	virtual ~ArkWeaponDoubleWrench();
	
#if 0
	void OnChainEvent();
	void OnChargeEvent();
	void OnDirectionParamSet(const float arg0);
#endif
	
	static inline auto FOnActionExit = PreyFunction<void(ArkWeaponDoubleWrench *const _this)>(0x138BFE0);
	static inline auto FOnHit = PreyFunction<void(ArkWeaponDoubleWrench *const _this, const float _dir, const float _damageScale)>(0x138C380);
	static inline auto FOnFatalityExit = PreyFunction<void(ArkWeaponDoubleWrench *const _this, ArkNpc &_npc)>(0x138C340);
	static inline auto FPlayAnim = PreyFunction<void(ArkWeaponDoubleWrench *const _this, ArkWeaponDoubleWrench::EArkAttackAnim _anim, bool _bInterrupt, ArkNpc *const _pNPC)>(0x138C6F0);
	static inline auto FHasAmmo = PreyFunction<bool(ArkWeaponDoubleWrench const *const _this)>(0x1B933B0);
	static inline auto FGetDegradationRate = PreyFunction<float(ArkWeaponDoubleWrench const *const _this)>(0xB5F050);
	static inline auto FGetInventoryAmmoCount = PreyFunction<int(ArkWeaponDoubleWrench const *const _this)>(0x158AEF0);
	static inline auto FConsumeAmmo = PreyFunction<void(ArkWeaponDoubleWrench *const _this)>(0xA13080);
	static inline auto FIsEquippable = PreyFunction<bool(ArkWeaponDoubleWrench const *const _this)>(0x138B940);
	static inline auto FGetUIAmmoCountString = PreyFunction<string(ArkWeaponDoubleWrench const *const _this)>(0x1704E10);
	static inline auto FLoadCachedProperties = PreyFunction<void(ArkWeaponDoubleWrench *const _this)>(0x170B950);
	static inline auto FInitializeStats = PreyFunction<void(ArkWeaponDoubleWrench *const _this)>(0x170B8F0);
	static inline auto FOnUnequip = PreyFunction<void(ArkWeaponDoubleWrench *const _this, const bool _bUnselect)>(0x170B990);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(ArkWeaponDoubleWrench *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x138B950);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName(ArkWeaponDoubleWrench const *const _this)>(0x138B920);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/weapons/ArkWeapon.h>
#include <Prey/GameDll/ark/weapons/ArkWrenchComponent.h>

class ArkNpc;
class CCryName;

// ArkWeaponDoubleWrench
// Header:  Prey/GameDll/ark/weapons/ArkWeaponDoubleWrench.h
class ArkWeaponDoubleWrench : public CArkWeapon
{ // Size=1704 (0x6A8)
public:
	enum class EArkAttackAnim
	{
		none = 0,
		a = 1,
		b = 2,
		c = 3,
		d = 4,
		e = 5,
		f = 6,
		g = 7,
		hitA = 8,
		hitB = 9,
		hitC = 10,
		hitD = 11,
		hitE = 12,
		hitF = 13,
		hitG = 14,
		hitEnemyA = 15,
		hitEnemyB = 16,
		hitEnemyC = 17,
		hitEnemyD = 18,
		hitEnemyE = 19,
		hitEnemyF = 20,
		hitEnemyG = 21,
		fatality = 22,
		genericFatality = 23,
	};

	static inline auto k_doubleWrenchAbilityRequirement = PreyGlobal<const uint64_t>(0x1F6F648);
	ArkWrenchComponent m_wrenchComponent;
	ArkWeaponDoubleWrench::EArkAttackAnim m_currentAnim;

	void OnActionExit() { FOnActionExit(this); }
	void OnHit(const float _dir, const float _damageScale) { FOnHit(this, _dir, _damageScale); }
	void PlayAnim(const ArkWeaponDoubleWrench::EArkAttackAnim _anim, bool _bInterrupt, ArkNpc* const _pNPC) { FPlayAnim(this, _anim, _bInterrupt, _pNPC); }
	virtual bool HasAmmo() const;
	virtual float GetDegradationRate() const;
	virtual int GetInventoryAmmoCount() const;
	virtual void ConsumeAmmo();
	virtual bool IsEquippable() const;
	virtual string GetUIAmmoCountString() const;
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	virtual void OnUnequip(const bool _bUnselect, const bool _bImmediate);
	virtual bool OnActionAttackPrimary(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value);
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;

#if 0
	ArkWeaponDoubleWrench();
	void OnChainEvent();
	void OnChargeEvent();
	void OnFireEvent();
	void OnDirectionParamSet(const float _arg0_);
	void OnFatalityExit(ArkNpc& _arg0_);
	void StartChargingEffect();
#endif

	static inline auto FOnActionExit = PreyFunction<void(ArkWeaponDoubleWrench* const _this)>(0x148EEA0);
	static inline auto FOnHit = PreyFunction<void(ArkWeaponDoubleWrench* const _this, const float _dir, const float _damageScale)>(0x149CD00);
	static inline auto FPlayAnim = PreyFunction<void(ArkWeaponDoubleWrench* const _this, const ArkWeaponDoubleWrench::EArkAttackAnim _anim, bool _bInterrupt, ArkNpc* const _pNPC)>(0x148F210);
	static inline auto FHasAmmo = PreyFunction<bool(const ArkWeaponDoubleWrench* const _this)>(0x1A302A0);
	static inline auto FGetDegradationRate = PreyFunction<float(const ArkWeaponDoubleWrench* const _this)>(0x714650);
	static inline auto FGetInventoryAmmoCount = PreyFunction<int(const ArkWeaponDoubleWrench* const _this)>(0x1CBB0B0);
	static inline auto FConsumeAmmo = PreyFunction<void(ArkWeaponDoubleWrench* const _this)>(0x1333E90);
	static inline auto FIsEquippable = PreyFunction<bool(const CArkItem* const _this)>(0x148EC60);
	static inline auto FGetUIAmmoCountString = PreyFunction<string*(const ArkWeaponDoubleWrench* const _this, string* _return_value_)>(0xB84E0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem* const _this)>(0x1832290);
	static inline auto FInitializeStats = PreyFunction<void(ArkWeaponDoubleWrench* const _this)>(0x1832230);
	static inline auto FOnUnequip = PreyFunction<void(ArkWeaponDoubleWrench* const _this, const bool _bUnselect, const bool _bImmediate)>(0x18322D0);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(ArkWeaponDoubleWrench* const _this, unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value)>(0x148EC70);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName*(const ArkWeaponDoubleWrench* const _this, CCryName* _return_value_)>(0x17A7AF0);
};
#endif // !MOONCRASH
