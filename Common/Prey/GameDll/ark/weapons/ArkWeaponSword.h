// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/weapons/ArkWeaponWrench.h>
#include <_unknown/TArkAudioSwitch.h>

class CArkProjectile;
class CCryName;
struct IEntity;
struct IGameObject;
struct SEntityUpdateContext;

// ArkWeaponSword
// Header:  Prey/GameDll/ark/weapons/ArkWeaponSword.h
class ArkWeaponSword : public ArkWeaponWrench
{ // Size=2624 (0xA40)
public:
	enum class EAudioHasEnoughPsi
	{
		no = 0,
		yes = 1,
		count = 2,
	};

	int m_psiCost;
	float m_minSpeed;
	float m_maxSpeed;
	float m_maxDamageMultiplier;
	float m_projectileAimRange;
	uint64_t m_nullifiedModifierId;
	bool m_bIsExhausted;
	bool m_bCanFireProjectile;
	bool m_bCanConsumePsi;
	ArkSimpleTimer m_minChargeTimer;
	ArkSimpleTimer m_maxChargeTimer;
	ArkSimpleTimer m_resetUITimer;
	ArkEntityAttachmentEffect m_chargingEffect;
	ArkEntityAttachmentEffect m_minChargedEffect;
	ArkEntityAttachmentEffect m_maxChargedEffect;
	ArkEntityAttachmentEffect m_exhaustedChargingEffect;
	ArkEntityAttachmentEffect m_exhaustedMinChargedEffect;
	ArkEntityAttachmentEffect m_exhaustedMaxChargedEffect;
	ArkEntityAttachmentEffect m_hitEffect;
	string m_noPsiEffectAttachmentName;
	ArkFireAndForgetEffect m_noPsiEffect;
	ArkEntityAttachmentEffect m_bladeEffect;
	ArkAudioTrigger m_cancelEffectsTrigger;
	TArkAudioSwitch<enum ArkWeaponSword::EAudioHasEnoughPsi> m_hasEnoughPsi;

	ArkWeaponSword();
	virtual ~ArkWeaponSword();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void FullSerialize(TSerialize _ser);
	virtual void OnUnequip(const bool _bUnselect, const bool _bImmediate);
	virtual bool ForceCancelCharge(const bool _bPlayAnim);
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	virtual CCryName GetReticleName() const;
	virtual bool CanCollideWithEntity(const IEntity* const _pEntity) const;
	virtual float CalculateFatigue(const bool _bIsCharged, const bool _bIsExhausted) const;
	virtual void OnFireEvent();
	virtual void CancelCharge();
	virtual float GetDamageScale(const float _distance, CArkProjectile* const _pProjectile) const;
	void OnActualHit(const float _dir, const float _damageScale) { FOnActualHit(this, _dir, _damageScale); }
	virtual void OnHit(const float _dir, const float _damageScale);
	virtual float GetAimRange(const bool _bProjectile) const;
	virtual void ActivateBlade(const bool _activate);
	virtual void StartChargingEffect();
	virtual bool OnActionAttackPrimary(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value);
	virtual bool OnActionAttackUse(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value);
	void SpawnProjectile() { FSpawnProjectile(this); }
	void StartMaxEffect() { FStartMaxEffect(this); }
	void StartMinEffect() { FStartMinEffect(this); }
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;

#if 0
	void TurnOffAllEffects(const bool _arg0_);
	void UpdateCanFireProjectile();
#endif

	static inline auto FArkWeaponSwordOv1 = PreyFunction<void(ArkWeaponSword* const _this)>(0x1496860);
	static inline auto FInit = PreyFunction<bool(CArkItem* const _this, IGameObject* _pGameObject)>(0x14972D0);
	static inline auto FUpdate = PreyFunction<void(CArkItem* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x1498FF0);
	static inline auto FFullSerialize = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x14971C0);
	static inline auto FOnUnequip = PreyFunction<void(ArkWeaponSword* const _this, const bool _bUnselect, const bool _bImmediate)>(0x14986B0);
	static inline auto FForceCancelCharge = PreyFunction<bool(ArkWeaponSword* const _this, const bool _bPlayAnim)>(0x14970D0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem* const _this)>(0x14976D0);
	static inline auto FInitializeStats = PreyFunction<void(ArkWeaponSword* const _this)>(0x1497350);
	static inline auto FOnStatChange = PreyFunction<void(IArkStatsListener* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x1498640);
	static inline auto FGetReticleName = PreyFunction<CCryName*(const ArkWeaponSword* const _this, CCryName* _return_value_)>(0x1497280);
	static inline auto FCanCollideWithEntity = PreyFunction<bool(const ArkWeaponSword* const _this, const IEntity* const _pEntity)>(0x1496F10);
	static inline auto FCalculateFatigue = PreyFunction<float(const ArkWeaponSword* const _this, const bool _bIsCharged, const bool _bIsExhausted)>(0x1496E90);
	static inline auto FOnFireEvent = PreyFunction<void(ArkWeaponSword* const _this)>(0x1498420);
	static inline auto FCancelCharge = PreyFunction<void(ArkWeaponSword* const _this)>(0x1497030);
	static inline auto FGetDamageScale = PreyFunction<float(const ArkWeaponSword* const _this, const float _distance, CArkProjectile* const _pProjectile)>(0x1497240);
	static inline auto FOnActualHit = PreyFunction<void(ArkWeaponSword* const _this, const float _dir, const float _damageScale)>(0x14983B0);
	static inline auto FOnHit = PreyFunction<void(ArkWeaponSword* const _this, const float _dir, const float _damageScale)>(0x1498480);
	static inline auto FGetAimRange = PreyFunction<float(const ArkWeaponSword* const _this, const bool _bProjectile)>(0x1497220);
	static inline auto FActivateBlade = PreyFunction<void(ArkWeaponSword* const _this, const bool _activate)>(0x1496E60);
	static inline auto FStartChargingEffect = PreyFunction<void(ArkWeaponSword* const _this)>(0x1498F60);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(ArkWeaponSword* const _this, unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value)>(0x1498100);
	static inline auto FOnActionAttackUse = PreyFunction<bool(ArkWeaponSword* const _this, unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value)>(0x1498320);
	static inline auto FSpawnProjectile = PreyFunction<void(ArkWeaponSword* const _this)>(0x14987C0);
	static inline auto FStartMaxEffect = PreyFunction<void(ArkWeaponSword* const _this)>(0x1498F90);
	static inline auto FStartMinEffect = PreyFunction<void(ArkWeaponSword* const _this)>(0x1498FC0);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName*(const ArkWeaponSword* const _this, CCryName* _return_value_)>(0x1497260);
};
#endif // MOONCRASH
