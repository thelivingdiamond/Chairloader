// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/weapons/arkweapon.h>

class ICrySizer;
struct IEntityArchetype;
struct IGameObject;
struct IMaterial;

// Header: Exact
// Prey/GameDll/ark/weapons/arkweapongoogun.h
class CArkWeaponGooGun : public CArkWeapon // Id=801CD1F Size=1280
{
public:
	IEntityArchetype *m_pAmmoArchetype;
	float m_ammoConsumptionTimer;
	bool m_bIsStoppingAttack;
	bool m_bSpawnProjectile;
	wstring m_baseDamageKeyword;
	wstring m_finalDamageKeyword;
	uint64_t m_damageSignal;
	bool m_bCurrentlyDisrupted;
	int m_disruptSubMaterial;
	float m_disruptMaxEmittance;
	IMaterial *m_pDisruptMaterial;
	
	CArkWeaponGooGun();
	virtual ~CArkWeaponGooGun();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnPreRender();
	virtual bool OnActionAttackPrimary(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual float GetWalkSpeedStat() const;
	virtual float GetCameraSpeedStat() const;
	virtual wstring GetDescription() const;
	virtual CCryName GetReticleName() const;
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	virtual void SustainedAttack();
	virtual bool StartAttack();
	virtual bool ContinueAttack();
	virtual bool StopAttack();
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect);
	virtual void OnAttackStopped();
	virtual _smart_ptr<IAction> ConstructReloadAction(const int _fragmentId) const;
	virtual int GetAmmoCost() const;
	virtual int GetBaseDamage() const;
	virtual int GetModifiedDamage(std::vector<unsigned __int64> const &_modifiers) const;
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;
	void SetUpDisruptMaterial() { FSetUpDisruptMaterial(this); }
	
#if 0
	void SpawnProjectile();
#endif
	
	static inline auto FInit = PreyFunction<bool(CArkWeaponGooGun *const _this, IGameObject *_pGameObject)>(0x1673650);
	static inline auto FPostInit = PreyFunction<void(CArkWeaponGooGun *const _this, IGameObject *_pGameObject)>(0x1671C30);
	static inline auto FFullSerialize = PreyFunction<void(CArkWeaponGooGun *const _this, TSerialize _ser)>(0x16709E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkWeaponGooGun const *const _this, ICrySizer *_s)>(0x1671040);
	static inline auto FOnPreRender = PreyFunction<void(CArkWeaponGooGun *const _this)>(0x1671930);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeaponGooGun *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1671820);
	static inline auto FGetWalkSpeedStat = PreyFunction<float(CArkWeaponGooGun const *const _this)>(0x1671100);
	static inline auto FGetCameraSpeedStat = PreyFunction<float(CArkWeaponGooGun const *const _this)>(0x1670B10);
	static inline auto FGetDescription = PreyFunction<wstring(CArkWeaponGooGun const *const _this)>(0x1670B50);
	static inline auto FGetReticleName = PreyFunction<CCryName(CArkWeaponGooGun const *const _this)>(0x16710E0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkWeaponGooGun *const _this)>(0x1671310);
	static inline auto FInitializeStats = PreyFunction<void(CArkWeaponGooGun *const _this)>(0x1671140);
	static inline auto FSustainedAttack = PreyFunction<void(CArkWeaponGooGun *const _this)>(0x1671E00);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeaponGooGun *const _this)>(0x1671CE0);
	static inline auto FContinueAttack = PreyFunction<bool(CArkWeaponGooGun *const _this)>(0x1670940);
	static inline auto FStopAttack = PreyFunction<bool(CArkWeaponGooGun *const _this)>(0x1671D60);
	static inline auto FOnEquip = PreyFunction<void(CArkWeaponGooGun *const _this)>(0x1671900);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeaponGooGun *const _this, const bool _bUnselect)>(0x1671BD0);
	static inline auto FOnAttackStopped = PreyFunction<void(CArkWeaponGooGun *const _this)>(0x16718B0);
	static inline auto FConstructReloadAction = PreyFunction<_smart_ptr<IAction>(CArkWeaponGooGun const *const _this, const int _fragmentId)>(0x16727C0);
	static inline auto FGetAmmoCost = PreyFunction<int(CArkWeaponGooGun const *const _this)>(0x1670A50);
	static inline auto FGetBaseDamage = PreyFunction<int(CArkWeaponGooGun const *const _this)>(0x1670AC0);
	static inline auto FGetModifiedDamage = PreyFunction<int(CArkWeaponGooGun const *const _this, std::vector<unsigned __int64> const &_modifiers)>(0x1671060);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName(CArkWeaponGooGun const *const _this)>(0x16710C0);
	static inline auto FSetUpDisruptMaterial = PreyFunction<void(CArkWeaponGooGun *const _this)>(0x1671C40);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/weapons/ArkWeapon.h>

class CCryName;
class IAction;
class ICrySizer;
struct IGameObject;
struct IMaterial;

// CArkWeaponGooGun
// Header:  Prey/GameDll/ark/weapons/ArkWeaponGooGun.h
class CArkWeaponGooGun : public CArkWeapon
{ // Size=1664 (0x680)
public:
	float m_ammoConsumptionTimer;
	bool m_bIsStoppingAttack;
	bool m_bSpawnProjectile;
	wstring m_baseDamageKeyword;
	wstring m_finalDamageKeyword;
	uint64_t m_damageSignal;
	bool m_bCurrentlyDisrupted;
	int m_disruptSubMaterial;
	float m_disruptMaxEmittance;
	IMaterial* m_pDisruptMaterial;

	CArkWeaponGooGun();
	virtual ~CArkWeaponGooGun();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual void OnPreRender();
	virtual bool OnActionAttackPrimary(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value);
	virtual float GetWalkSpeedStat() const;
	virtual float GetCameraSpeedStat() const;
	virtual wstring GetDescription() const;
	virtual CCryName GetReticleName() const;
	virtual bool IsTwoHanded() const;
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	virtual void SustainedAttack();
	virtual bool StartAttack();
	virtual bool ContinueAttack();
	virtual bool StopAttack();
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect, const bool _bImmediate);
	virtual void OnAttackStopped();
	virtual _smart_ptr<IAction> ConstructReloadAction(const int _fragmentId) const;
	virtual int GetAmmoCost() const;
	virtual int GetBaseDamage() const;
	virtual int GetModifiedDamage(const std::vector<uint64_t>& _modifiers, const bool _bIncludeEnchantments) const;
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;
	void SetUpDisruptMaterial() { FSetUpDisruptMaterial(this); }

#if 0
	void SpawnProjectile();
#endif

	static inline auto FCArkWeaponGooGunOv1 = PreyFunction<void(CArkWeaponGooGun* const _this)>(0x1793970);
	static inline auto FInit = PreyFunction<bool(CArkItem* const _this, IGameObject* _pGameObject)>(0x1794400);
	static inline auto FPostInit = PreyFunction<void(CArkItem* const _this, IGameObject* _pGameObject)>(0x1794F40);
	static inline auto FFullSerialize = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x1793C60);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkItem* const _this, ICrySizer* _s)>(0x17942C0);
	static inline auto FOnPreRender = PreyFunction<void(IGameFrameworkListener* const _this)>(0x1794C20);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeaponGooGun* const _this, unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value)>(0x1794AD0);
	static inline auto FGetWalkSpeedStat = PreyFunction<float(const CArkWeaponGooGun* const _this)>(0x17943C0);
	static inline auto FGetCameraSpeedStat = PreyFunction<float(const CArkWeaponGooGun* const _this)>(0x1793D90);
	static inline auto FGetDescription = PreyFunction<wstring*(const CArkItem* const _this, wstring* _return_value_)>(0x1793DD0);
	static inline auto FGetReticleName = PreyFunction<CCryName*(const CArkWeaponGooGun* const _this, CCryName* _return_value_)>(0x17943A0);
	static inline auto FIsTwoHanded = PreyFunction<bool(const CArkWeaponGooGun* const _this)>(0x1A302A0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem* const _this)>(0x17945E0);
	static inline auto FInitializeStats = PreyFunction<void(CArkWeaponGooGun* const _this)>(0x1794410);
	static inline auto FSustainedAttack = PreyFunction<void(CArkWeaponGooGun* const _this)>(0x1795070);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeaponGooGun* const _this)>(0x1794FF0);
	static inline auto FContinueAttack = PreyFunction<bool(CArkWeaponGooGun* const _this)>(0x1793BC0);
	static inline auto FStopAttack = PreyFunction<bool(CArkWeaponGooGun* const _this)>(0x148FB30);
	static inline auto FOnEquip = PreyFunction<void(CArkWeaponGooGun* const _this)>(0x1794BF0);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeaponGooGun* const _this, const bool _bUnselect, const bool _bImmediate)>(0x1794ED0);
	static inline auto FOnAttackStopped = PreyFunction<void(CArkWeaponGooGun* const _this)>(0x1794BA0);
	static inline auto FConstructReloadAction = PreyFunction<_smart_ptr<IAction>*(const CArkWeaponGooGun* const _this, _smart_ptr<IAction>* _return_value_, const int _fragmentId)>(0x1793B60);
	static inline auto FGetAmmoCost = PreyFunction<int(const CArkWeaponGooGun* const _this)>(0x1793CD0);
	static inline auto FGetBaseDamage = PreyFunction<int(const CArkWeaponGooGun* const _this)>(0x1793D40);
	static inline auto FGetModifiedDamage = PreyFunction<int(const CArkWeaponGooGun* const _this, const std::vector<uint64_t>& _modifiers, const bool _bIncludeEnchantments)>(0x17942E0);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName*(const CArkWeaponGooGun* const _this, CCryName* _return_value_)>(0x1794380);
	static inline auto FSetUpDisruptMaterial = PreyFunction<void(CArkWeaponGooGun* const _this)>(0x1794F50);
};
#endif // !MOONCRASH
