// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/weapons/arkweapon.h>

class ICrySizer;
struct IEntityArchetype;
struct SEntityUpdateContext;

// Header: Exact
// Prey/GameDll/ark/weapons/arkweapongrenade.h
class CArkWeaponGrenade : public CArkWeapon // Id=801CD91 Size=1336
{
public:
	float m_proximityRange;
	uint64_t m_packageProximityId;
	string m_cancelHintString;
	string m_deployHintString;
	float m_minSpeed;
	float m_maxSpeed;
	float m_attachDistance;
	IEntityArchetype *m_pAmmoArchetype;
	bool m_bDeployed;
	bool m_bIsProximity;
	int m_proximityPhysicsEntityId;
	int m_proximityPartId;
	bool m_bProximityTerrain;
	Vec3 m_proximityPosition;
	Vec3 m_proximityNormal;
	bool m_bIdling;
	bool m_bCharging;
	bool m_bCancelledAttack;
	bool m_bDeployTutorialEnabled;
	ArkSimpleTimer m_chargeTimer;
	_smart_ptr<IAction> m_pWeaponThrowIdleAction;
	
	CArkWeaponGrenade();
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void FullSerialize(TSerialize _ser);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual bool OnActionAttackUse(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual bool OnActionAttackPrimary(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual void ExitAttackAction();
	virtual bool IsEquippable() const;
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect);
	virtual bool IsProximity() const;
	void FinishDeploying() { FFinishDeploying(this); }
	virtual bool ForceCancelCharge();
	static CArkWeaponGrenade *GetWeaponGrenadeFromEntityId(const unsigned _entityId) { return FGetWeaponGrenadeFromEntityId(_entityId); }
	virtual CCryName GetReticleName() const;
	virtual bool ShowsAmmoOnHUD() const;
	virtual bool CanStartAttack();
	virtual bool StartAttack();
	virtual bool ContinueAttack();
	virtual bool StopAttack();
	void CancelCharging() { FCancelCharging(this); }
	void StartCharging() { FStartCharging(this); }
	virtual void ThrowingIdle();
	virtual void ThrowingCancel(const bool _bCheckIdle);
	virtual void ThrowGrenade();
	virtual void DeployGrenade();
	virtual void ReloadGrenade();
	virtual void StartReloadAmmo();
	virtual void LoadCachedProperties();
	virtual void UpdateAmmoCountUI() const;
	void DisableDeployTutorial() { FDisableDeployTutorial(this); }
	
#if 0
	void EnableDeployTutorial(string arg0);
#endif
	
	static inline auto FUpdate = PreyFunction<void(CArkWeaponGrenade *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x1678DC0);
	static inline auto FFullSerialize = PreyFunction<void(CArkWeaponGrenade *const _this, TSerialize _ser)>(0x1677B30);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkWeaponGrenade const *const _this, ICrySizer *_s)>(0x1677C00);
	static inline auto FOnActionAttackUse = PreyFunction<bool(CArkWeaponGrenade *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x16783C0);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeaponGrenade *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1678290);
	static inline auto FExitAttackAction = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x1677950);
	static inline auto FIsEquippable = PreyFunction<bool(CArkWeaponGrenade const *const _this)>(0x1677CA0);
	static inline auto FOnEquip = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x16783E0);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeaponGrenade *const _this, const bool _bUnselect)>(0x16784A0);
	static inline auto FIsProximity = PreyFunction<bool(CArkWeaponGrenade const *const _this)>(0x1677CF0);
	static inline auto FFinishDeploying = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x1677A70);
	static inline auto FForceCancelCharge = PreyFunction<bool(CArkWeaponGrenade *const _this)>(0x1677AA0);
	static inline auto FGetWeaponGrenadeFromEntityId = PreyFunction<CArkWeaponGrenade *(const unsigned _entityId)>(0x1667720);
	static inline auto FGetReticleName = PreyFunction<CCryName(CArkWeaponGrenade const *const _this)>(0x1677C20);
	static inline auto FShowsAmmoOnHUD = PreyFunction<bool(CArkWeaponGrenade const *const _this)>(0x1B933B0);
	static inline auto FCanStartAttack = PreyFunction<bool(CArkWeaponGrenade *const _this)>(0x1676FB0);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeaponGrenade *const _this)>(0x1678640);
	static inline auto FContinueAttack = PreyFunction<bool(CArkWeaponGrenade *const _this)>(0xDD23F0);
	static inline auto FStopAttack = PreyFunction<bool(CArkWeaponGrenade *const _this)>(0x1678900);
	static inline auto FCancelCharging = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x16770A0);
	static inline auto FStartCharging = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x1678750);
	static inline auto FThrowingIdle = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x1678CE0);
	static inline auto FThrowingCancel = PreyFunction<void(CArkWeaponGrenade *const _this, const bool _bCheckIdle)>(0x1678CC0);
	static inline auto FThrowGrenade = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x1678910);
	static inline auto FDeployGrenade = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x1677170);
	static inline auto FReloadGrenade = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x16785B0);
	static inline auto FStartReloadAmmo = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x1678850);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x1677D00);
	static inline auto FUpdateAmmoCountUI = PreyFunction<void(CArkWeaponGrenade const *const _this)>(0x1679460);
	static inline auto FDisableDeployTutorial = PreyFunction<void(CArkWeaponGrenade *const _this)>(0x1677860);
};

