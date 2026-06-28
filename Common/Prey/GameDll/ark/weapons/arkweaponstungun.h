// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/weapons/arkweapon.h>

class ICrySizer;
struct IEntity;
struct IEntityClass;
struct IGameObject;
struct IMaterial;
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: Exact
// Prey/GameDll/ark/weapons/arkweaponstungun.h
class CArkWeaponStunGun : public CArkWeapon // Id=801BC2F Size=1632
{
public:
	int m_hitTypeId;
	uint64_t m_signalPackageId;
	float m_radiusAOE;
	string m_cancelHintString;
	float m_maxAimAssistRadius;
	float m_maxStrength;
	float m_impulseScale;
	float m_glowTime;
	float m_idleGlowAmount;
	float m_fireGlowAmount;
	IMaterial *m_pGlowMaterial;
	int m_glowSubMaterial;
	IEntityClass *m_pAmmoClass;
	bool m_bMalfunctioning;
	bool m_bCharging;
	bool m_bCancelledAttack;
	ArkSimpleTimer m_chargeTimer;
	float m_desiredGlowAmount;
	float m_currentGlowAmount;
	unsigned m_lightningArcId;
	unsigned m_proxyTargetMarkerId;
	Vec3 m_targetNormal;
	int m_targetPartId;
	ArkEntityAttachmentEffect m_chargingEffect;
	ArkEntityAttachmentEffect m_chargedEffect;
	ArkEntityAttachmentEffect m_firingEffect;
	std::vector<unsigned __int64> m_sneakAttackMetaTags;
	
	CArkWeaponStunGun();
	virtual ~CArkWeaponStunGun();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnPreRender();
	virtual bool OnActionAttackUse(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual bool OnActionAttackPrimary(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	void OnLightningCallback(IEntity *_pArc, IEntity *_pTarget, float _strikeTime) { FOnLightningCallback(this,_pArc,_pTarget,_strikeTime); }
	virtual void ReloadAmmo(const bool _bContinueReload);
	virtual void EnterAttackAction();
	virtual void ExitAttackAction();
	void SetUpGlowMaterial() { FSetUpGlowMaterial(this); }
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect);
	virtual void OnMalfunctionStart();
	virtual void OnMalfunctionEvent();
	virtual bool CanStartAttack();
	virtual bool ForceCancelCharge();
	virtual CCryName GetReticleName() const;
	virtual bool IsCharging() const;
	virtual bool StartAttack();
	virtual void SustainedAttack();
	virtual _smart_ptr<IAction> ConstructReloadAction(const int _fragmentId) const;
	void StartCharging() { FStartCharging(this); }
	virtual void LoadCachedProperties();
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	virtual void LightVisibilityUpdated(bool _bVisible);
	void SetupLightningArc() { FSetupLightningArc(this); }
	
#if 0
	IMaterial *FindGlowMaterial();
	void UpdateCurrentGlowAmount(const float arg0, const float arg1);
#endif
	
	static inline auto FInit = PreyFunction<bool(CArkWeaponStunGun *const _this, IGameObject *_pGameObject)>(0x138D030);
	static inline auto FPostInit = PreyFunction<void(CArkWeaponStunGun *const _this, IGameObject *_pGameObject)>(0x138F310);
	static inline auto FRelease = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138F3D0);
	static inline auto FFullSerialize = PreyFunction<void(CArkWeaponStunGun *const _this, TSerialize _ser)>(0x138CF30);
	static inline auto FPostSerialize = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138F330);
	static inline auto FUpdate = PreyFunction<void(CArkWeaponStunGun *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x138FD50);
	static inline auto FProcessEvent = PreyFunction<void(CArkWeaponStunGun *const _this, SEntityEvent &_event)>(0x138F360);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkWeaponStunGun const *const _this, ICrySizer *_s)>(0x138CFF0);
	static inline auto FOnPreRender = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138E4D0);
	static inline auto FOnActionAttackUse = PreyFunction<bool(CArkWeaponStunGun *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x138E150);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeaponStunGun *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x138DE90);
	static inline auto FOnLightningCallback = PreyFunction<void(CArkWeaponStunGun *const _this, IEntity *_pArc, IEntity *_pTarget, float _strikeTime)>(0x138E190);
	static inline auto FReloadAmmo = PreyFunction<void(CArkWeaponStunGun *const _this, const bool _bContinueReload)>(0x138F440);
	static inline auto FEnterAttackAction = PreyFunction<void(CArkWeaponStunGun *const _this)>(0xA13080);
	static inline auto FExitAttackAction = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138CE20);
	static inline auto FSetUpGlowMaterial = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138F460);
	static inline auto FOnEquip = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138E170);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeaponStunGun *const _this, const bool _bUnselect)>(0x138F250);
	static inline auto FOnMalfunctionStart = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138E4B0);
	static inline auto FOnMalfunctionEvent = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138E4A0);
	static inline auto FCanStartAttack = PreyFunction<bool(CArkWeaponStunGun *const _this)>(0x138CDF0);
	static inline auto FForceCancelCharge = PreyFunction<bool(CArkWeaponStunGun *const _this)>(0x138CE50);
	static inline auto FGetReticleName = PreyFunction<CCryName(CArkWeaponStunGun const *const _this)>(0x138D010);
	static inline auto FIsCharging = PreyFunction<bool(CArkWeaponStunGun const *const _this)>(0x138D080);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeaponStunGun *const _this)>(0x138FAF0);
	static inline auto FSustainedAttack = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138FC90);
	static inline auto FConstructReloadAction = PreyFunction<_smart_ptr<IAction>(CArkWeaponStunGun const *const _this, const int _fragmentId)>(0x16727C0);
	static inline auto FStartCharging = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138FBF0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138D0F0);
	static inline auto FOnStatChange = PreyFunction<void(CArkWeaponStunGun *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x138F1F0);
	static inline auto FLightVisibilityUpdated = PreyFunction<void(CArkWeaponStunGun *const _this, bool _bVisible)>(0x138D0A0);
	static inline auto FSetupLightningArc = PreyFunction<void(CArkWeaponStunGun *const _this)>(0x138F500);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryAction/IGameRulesSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/weapons/ArkWeapon.h>

class CCryName;
class IAction;
class ICrySizer;
struct IEntity;
struct IEntityClass;
struct IGameObject;
struct IMaterial;
struct SEntityEvent;
struct SEntityUpdateContext;

// CArkWeaponStunGun
// Header:  Prey/GameDll/ark/weapons/ArkWeaponStunGun.h
class CArkWeaponStunGun : public CArkWeapon
{ // Size=2152 (0x868)
public:
	int m_hitTypeId;
	uint64_t m_signalPackageId;
	float m_radiusAOE;
	string m_cancelHintString;
	float m_maxAimAssistRadius;
	float m_maxStrength;
	float m_impulseScale;
	float m_glowTime;
	float m_idleGlowAmount;
	float m_fireGlowAmount;
	IMaterial* m_pGlowMaterial;
	int m_glowSubMaterial;
	IEntityClass* m_pAmmoClass;
	bool m_bMalfunctioning;
	bool m_bCharging;
	bool m_bCancelledAttack;
	ArkSimpleTimer m_chargeTimer;
	float m_desiredGlowAmount;
	float m_currentGlowAmount;
	unsigned m_lightningArcId;
	unsigned m_proxyTargetMarkerId;
	Vec3 m_targetNormal;
	int m_targetPartId;
	ArkEntityAttachmentEffect m_chargingEffect;
	ArkEntityAttachmentEffect m_chargedEffect;
	ArkEntityAttachmentEffect m_firingEffect;
	std::vector<uint64_t> m_sneakAttackMetaTags;
	HitInfo m_hitInfo;
	wstring m_baseDamageKeyword;
	wstring m_finalDamageKeyword;

	CArkWeaponStunGun();
	virtual ~CArkWeaponStunGun();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext& _ctx, int _slot);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual void OnPreRender();
	virtual bool OnActionAttackUse(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value);
	virtual bool OnActionAttackPrimary(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value);
	void OnLightningCallback(IEntity* _pArc, IEntity* _pTarget, float _strikeTime) { FOnLightningCallback(this, _pArc, _pTarget, _strikeTime); }
	virtual void ReloadAmmo(const bool _bContinueReload);
	virtual void EnterAttackAction();
	virtual void ExitAttackAction();
	void SetUpGlowMaterial() { FSetUpGlowMaterial(this); }
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect, const bool _bImmediate);
	virtual void OnMalfunctionStart();
	virtual void OnMalfunctionEvent();
	virtual bool CanStartAttack();
	virtual bool ForceCancelCharge(const bool _bPlayAnim);
	virtual CCryName GetReticleName() const;
	virtual bool IsCharging() const;
	virtual wstring GetDescription() const;
	virtual bool IsTwoHanded() const;
	virtual bool StartAttack();
	virtual void SustainedAttack();
	virtual _smart_ptr<IAction> ConstructReloadAction(const int _fragmentId) const;
	void StartCharging() { FStartCharging(this); }
	virtual void LoadCachedProperties();
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	virtual void LightVisibilityUpdated(bool _bVisible);
	void SetupLightningArc() { FSetupLightningArc(this); }

#if 0
	IMaterial* FindGlowMaterial();
	void UpdateCurrentGlowAmount(const float _arg0_, const float _arg1_);
#endif

	static inline auto FCArkWeaponStunGunOv1 = PreyFunction<void(CArkWeaponStunGun* const _this)>(0x14929F0);
	static inline auto FInit = PreyFunction<bool(CArkItem* const _this, IGameObject* _pGameObject)>(0x1493550);
	static inline auto FPostInit = PreyFunction<void(CArkItem* const _this, IGameObject* _pGameObject)>(0x1495C60);
	static inline auto FRelease = PreyFunction<void(CArkItem* const _this)>(0x1495D30);
	static inline auto FFullSerialize = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x1492F50);
	static inline auto FPostSerialize = PreyFunction<void(CArkItem* const _this)>(0x1495C90);
	static inline auto FUpdate = PreyFunction<void(CArkItem* const _this, SEntityUpdateContext& _ctx, int _slot)>(0x14966B0);
	static inline auto FProcessEvent = PreyFunction<void(CArkItem* const _this, SEntityEvent& _event)>(0x1495CC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkItem* const _this, ICrySizer* _s)>(0x1493510);
	static inline auto FOnPreRender = PreyFunction<void(IGameFrameworkListener* const _this)>(0x1494C30);
	static inline auto FOnActionAttackUse = PreyFunction<bool(CArkWeaponStunGun* const _this, unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value)>(0x1494850);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeaponStunGun* const _this, unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value)>(0x1494570);
	static inline auto FOnLightningCallback = PreyFunction<void(CArkWeaponStunGun* const _this, IEntity* _pArc, IEntity* _pTarget, float _strikeTime)>(0x14948A0);
	static inline auto FReloadAmmo = PreyFunction<void(CArkWeaponStunGun* const _this, const bool _bContinueReload)>(0x1495DA0);
	static inline auto FEnterAttackAction = PreyFunction<void(CArkWeaponStunGun* const _this)>(0x1333E90);
	static inline auto FExitAttackAction = PreyFunction<void(CArkWeaponStunGun* const _this)>(0x1492E10);
	static inline auto FSetUpGlowMaterial = PreyFunction<void(CArkWeaponStunGun* const _this)>(0x1495DC0);
	static inline auto FOnEquip = PreyFunction<void(CArkWeaponStunGun* const _this)>(0x1494870);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeaponStunGun* const _this, const bool _bUnselect, const bool _bImmediate)>(0x1495B90);
	static inline auto FOnMalfunctionStart = PreyFunction<void(CArkWeaponStunGun* const _this)>(0x1494C10);
	static inline auto FOnMalfunctionEvent = PreyFunction<void(CArkWeaponStunGun* const _this)>(0x1494C00);
	static inline auto FCanStartAttack = PreyFunction<bool(CArkWeaponStunGun* const _this)>(0x1492DE0);
	static inline auto FForceCancelCharge = PreyFunction<bool(CArkWeaponStunGun* const _this, const bool _bPlayAnim)>(0x1492E40);
	static inline auto FGetReticleName = PreyFunction<CCryName*(const CArkWeaponStunGun* const _this, CCryName* _return_value_)>(0x1493530);
	static inline auto FIsCharging = PreyFunction<bool(const CArkWeaponStunGun* const _this)>(0x14935B0);
	static inline auto FGetDescription = PreyFunction<wstring*(const CArkItem* const _this, wstring* _return_value_)>(0x1493020);
	static inline auto FIsTwoHanded = PreyFunction<bool(const CArkWeaponStunGun* const _this)>(0x1A302A0);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeaponStunGun* const _this)>(0x1496450);
	static inline auto FSustainedAttack = PreyFunction<void(CArkWeaponStunGun* const _this)>(0x14965F0);
	static inline auto FConstructReloadAction = PreyFunction<_smart_ptr<IAction>*(const CArkWeaponStunGun* const _this, _smart_ptr<IAction>* _return_value_, const int _fragmentId)>(0x1793B60);
	static inline auto FStartCharging = PreyFunction<void(CArkWeaponStunGun* const _this)>(0x1496550);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem* const _this)>(0x1493620);
	static inline auto FOnStatChange = PreyFunction<void(IArkStatsListener* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x1495B30);
	static inline auto FLightVisibilityUpdated = PreyFunction<void(IArkPlayerLightOwner* const _this, bool _bVisible)>(0x14935D0);
	static inline auto FSetupLightningArc = PreyFunction<void(CArkWeaponStunGun* const _this)>(0x1495E60);
};
#endif // !MOONCRASH
