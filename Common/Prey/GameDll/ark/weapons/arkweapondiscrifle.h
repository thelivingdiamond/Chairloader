// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arksimpletimer.h>
#include <Prey/GameDll/ark/player/IArkPsiScanningComponentListener.h>
#include <Prey/GameDll/ark/weapons/arkweapon.h>

class ArkPsiScanningComponent;
class CCryName;
class ICrySizer;
struct IEntityClass;
struct IGameObject;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweapondiscrifle.h
class CArkWeaponDiscRifle : public CArkWeapon, public IArkPsiScanningComponentListener // Id=801BC01 Size=1288
{
public:
	string m_cancelHintString;
	string m_outOfAmmoString;
	IEntityClass *m_pAmmoClass;
	ArkPsiScanningComponent *m_pPsiScanningComponent;
	ArkSimpleTimer m_targetAcquireTimer;
	ArkSimpleTimer m_targetAcquireTimeOutTimer;
	ArkRandomizedAutoResetTimer m_periodicDialogTimer;
	bool m_bCancelledAttack;
	bool m_bAcquiringTarget;
	
	CArkWeaponDiscRifle();
	virtual void Release();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnLockTargetReticle(const unsigned _targetEntityId);
	virtual void OnUnlockTargetReticle(const unsigned _targetEntityId);
	virtual void OnUpdateTargetReticle(const unsigned _targetEntityId, const bool _bIsInHud, const float _frameTime);
	virtual bool OnActionAttackUse(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual bool OnActionAttackPrimary(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect);
	virtual void OnMalfunctionStart();
	virtual void OnReloadStart();
	virtual bool HasTarget() const;
	virtual float GetTargetLockPercentage() const;
	virtual float GetTargetLockTimeOutElapsedSec() const;
	void TriggerDialogEvent(const char *_concept, unsigned _entityId) { FTriggerDialogEvent(this,_concept,_entityId); }
	virtual bool StartAttack();
	virtual void LoadCachedProperties();
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	virtual void OnAmmoDepleted();
	
#if 0
	void UpdateDialogEventPeriod();
	void AcquireTarget();
#endif
	
	static inline auto FRelease = PreyFunction<void(CArkWeaponDiscRifle *const _this)>(0x138AB50);
	static inline auto FInit = PreyFunction<bool(CArkWeaponDiscRifle *const _this, IGameObject *_pGameObject)>(0x138A100);
	static inline auto FFullSerialize = PreyFunction<void(CArkWeaponDiscRifle *const _this, TSerialize _ser)>(0x1389FB0);
	static inline auto FUpdate = PreyFunction<void(CArkWeaponDiscRifle *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x138B010);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkWeaponDiscRifle const *const _this, ICrySizer *_s)>(0x138A020);
	static inline auto FOnLockTargetReticle = PreyFunction<void(CArkWeaponDiscRifle *const _this, const unsigned _targetEntityId)>(0x138A8E0);
	static inline auto FOnUnlockTargetReticle = PreyFunction<void(CArkWeaponDiscRifle *const _this, const unsigned _targetEntityId)>(0x138AA30);
	static inline auto FOnUpdateTargetReticle = PreyFunction<void(CArkWeaponDiscRifle *const _this, const unsigned _targetEntityId, const bool _bIsInHud, const float _frameTime)>(0x138AA60);
	static inline auto FOnActionAttackUse = PreyFunction<bool(CArkWeaponDiscRifle *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x138A7E0);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeaponDiscRifle *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x138A6F0);
	static inline auto FOnEquip = PreyFunction<void(CArkWeaponDiscRifle *const _this)>(0x138A880);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeaponDiscRifle *const _this, const bool _bUnselect)>(0x138A9D0);
	static inline auto FOnMalfunctionStart = PreyFunction<void(CArkWeaponDiscRifle *const _this)>(0x138A930);
	static inline auto FOnReloadStart = PreyFunction<void(CArkWeaponDiscRifle *const _this)>(0x138A950);
	static inline auto FHasTarget = PreyFunction<bool(CArkWeaponDiscRifle const *const _this)>(0x138A0E0);
	static inline auto FGetTargetLockPercentage = PreyFunction<float(CArkWeaponDiscRifle const *const _this)>(0x138A060);
	static inline auto FGetTargetLockTimeOutElapsedSec = PreyFunction<float(CArkWeaponDiscRifle const *const _this)>(0x138A0C0);
	static inline auto FTriggerDialogEvent = PreyFunction<void(CArkWeaponDiscRifle *const _this, const char *_concept, unsigned _entityId)>(0x138AC30);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeaponDiscRifle *const _this)>(0x138AC00);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkWeaponDiscRifle *const _this)>(0x138A150);
	static inline auto FOnStatChange = PreyFunction<void(CArkWeaponDiscRifle *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x138A970);
	static inline auto FOnAmmoDepleted = PreyFunction<void(CArkWeaponDiscRifle *const _this)>(0x138A850);
};

