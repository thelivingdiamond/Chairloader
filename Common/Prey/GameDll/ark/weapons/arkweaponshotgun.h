// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/ArkRegularOutcome.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/weapons/arkweapon.h>

class ICrySizer;
struct IEntityArchetype;
struct IGameObject;
struct SEntityUpdateContext;

// Header: Exact
// Prey/GameDll/ark/weapons/arkweaponshotgun.h
class CArkWeaponShotgun : public CArkWeapon // Id=801CD20 Size=1312
{
public:
	float m_pointBlankDistanceFromHit;
	IEntityArchetype *m_pPointBlankAmmoArchetype;
	ArkRegularOutcome m_accuracyOutcome;
	IEntityArchetype *m_pAmmoArchetype;
	float m_weaponDispersion;
	float m_minDispersion;
	float m_maxDispersion;
	bool m_bShowAmmoOnHUD;
	wstring m_baseDmgKeyword;
	wstring m_finalDmgKeyword;
	uint64_t m_damageSignal;
	std::vector<IEntityClass const *> m_overrideTargetClasses;
	
	CArkWeaponShotgun();
	virtual ~CArkWeaponShotgun();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void FullSerialize(TSerialize _ser);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnPreRender();
	virtual bool OnActionAttackPrimary(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect);
	virtual float GetDispersion() const;
	virtual float GetDamageScale(const float _distance) const;
	virtual wstring GetDescription() const;
	virtual CCryName GetReticleName() const;
	virtual bool StartAttack();
	virtual bool ContinueAttack();
	virtual bool StopAttack();
	void UpdateAccuracy() { FUpdateAccuracy(this); }
	virtual void UpdateAmmoCountUI() const;
	virtual bool ShowsAmmoOnHUD() const;
	float GetDispersionMinimum() const { return FGetDispersionMinimum(this); }
	float GetDispersionMaximum() const { return FGetDispersionMaximum(this); }
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	virtual void UpdateDispersion();
	virtual _smart_ptr<IAction> ConstructReloadAction(const int _fragmentId) const;
	virtual int GetBaseDamage() const;
	virtual int GetModifiedDamage(std::vector<unsigned __int64> const &_modifiers) const;
	void SpawnPellets(Vec3 const &_position, Quat const &_rotation, Vec3 const &_aimPoint, const bool _bIsCritical, const bool _bShootStraight, const unsigned _groupId) { FSpawnPellets(this,_position,_rotation,_aimPoint,_bIsCritical,_bShootStraight,_groupId); }
	void HandlePointBlank(Vec3 const &_position, Quat const &_rotation, Vec3 const &_aimPoint, const bool _bIsCritical, const unsigned _groupId) { FHandlePointBlank(this,_position,_rotation,_aimPoint,_bIsCritical,_groupId); }
	virtual void OnJump();
	virtual void OnSlide();
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	virtual void OnCombatFocusChanged(bool _bActive);
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;
	
#if 0
	float GetDispersionNotMoving() const;
	float GetDispersionMoving() const;
	void AddAndClampDispersion(const float arg0, const char *const arg1, const float arg2);
#endif
	
	static inline auto FInit = PreyFunction<bool(CArkWeaponShotgun *const _this, IGameObject *_pGameObject)>(0x167B030);
	static inline auto FUpdate = PreyFunction<void(CArkWeaponShotgun *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x167DB10);
	static inline auto FFullSerialize = PreyFunction<void(CArkWeaponShotgun *const _this, TSerialize _ser)>(0x1679EC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkWeaponShotgun const *const _this, ICrySizer *_s)>(0x167A7B0);
	static inline auto FOnPreRender = PreyFunction<void(CArkWeaponShotgun *const _this)>(0x167CFD0);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeaponShotgun *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x167CE60);
	static inline auto FOnEquip = PreyFunction<void(CArkWeaponShotgun *const _this)>(0x167CED0);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeaponShotgun *const _this, const bool _bUnselect)>(0x167D130);
	static inline auto FGetDispersion = PreyFunction<float(CArkWeaponShotgun const *const _this)>(0x167A5A0);
	static inline auto FGetDamageScale = PreyFunction<float(CArkWeaponShotgun const *const _this, const float _distance)>(0x167A030);
	static inline auto FGetDescription = PreyFunction<wstring(CArkWeaponShotgun const *const _this)>(0x167A0B0);
	static inline auto FGetReticleName = PreyFunction<CCryName(CArkWeaponShotgun const *const _this)>(0x167A8F0);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeaponShotgun *const _this)>(0x167D600);
	static inline auto FContinueAttack = PreyFunction<bool(CArkWeaponShotgun *const _this)>(0x1679EB0);
	static inline auto FStopAttack = PreyFunction<bool(CArkWeaponShotgun *const _this)>(0x1678900);
	static inline auto FUpdateAccuracy = PreyFunction<void(CArkWeaponShotgun *const _this)>(0x167DDA0);
	static inline auto FUpdateAmmoCountUI = PreyFunction<void(CArkWeaponShotgun const *const _this)>(0x167DE40);
	static inline auto FShowsAmmoOnHUD = PreyFunction<bool(CArkWeaponShotgun const *const _this)>(0x167D170);
	static inline auto FGetDispersionMinimum = PreyFunction<float(CArkWeaponShotgun const *const _this)>(0x167A6B0);
	static inline auto FGetDispersionMaximum = PreyFunction<float(CArkWeaponShotgun const *const _this)>(0x167A5B0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkWeaponShotgun *const _this)>(0x167C450);
	static inline auto FInitializeStats = PreyFunction<void(CArkWeaponShotgun *const _this)>(0x167B080);
	static inline auto FUpdateDispersion = PreyFunction<void(CArkWeaponShotgun *const _this)>(0x167DFF0);
	static inline auto FConstructReloadAction = PreyFunction<_smart_ptr<IAction>(CArkWeaponShotgun const *const _this, const int _fragmentId)>(0x16727C0);
	static inline auto FGetBaseDamage = PreyFunction<int(CArkWeaponShotgun const *const _this)>(0x1679F50);
	static inline auto FGetModifiedDamage = PreyFunction<int(CArkWeaponShotgun const *const _this, std::vector<unsigned __int64> const &_modifiers)>(0x167A7D0);
	static inline auto FSpawnPellets = PreyFunction<void(CArkWeaponShotgun *const _this, Vec3 const &_position, Quat const &_rotation, Vec3 const &_aimPoint, const bool _bIsCritical, const bool _bShootStraight, const unsigned _groupId)>(0x167D180);
	static inline auto FHandlePointBlank = PreyFunction<void(CArkWeaponShotgun *const _this, Vec3 const &_position, Quat const &_rotation, Vec3 const &_aimPoint, const bool _bIsCritical, const unsigned _groupId)>(0x167AA00);
	static inline auto FOnJump = PreyFunction<void(CArkWeaponShotgun *const _this)>(0x167CF40);
	static inline auto FOnSlide = PreyFunction<void(CArkWeaponShotgun *const _this)>(0x167D050);
	static inline auto FOnStatChange = PreyFunction<void(CArkWeaponShotgun *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x167D0D0);
	static inline auto FOnCombatFocusChanged = PreyFunction<void(CArkWeaponShotgun *const _this, bool _bActive)>(0x167CEB0);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName(CArkWeaponShotgun const *const _this)>(0x167A8D0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/ArkCommon/ArkRegularOutcome.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/weapons/ArkWeapon.h>

class CArkProjectile;
class CCryName;
class IAction;
class ICrySizer;
struct IEntityArchetype;
struct IEntityClass;
struct IGameObject;
struct SEntityUpdateContext;

// CArkWeaponShotgun
// Header:  Prey/GameDll/ark/weapons/ArkWeaponShotgun.h
class CArkWeaponShotgun : public CArkWeapon
{ // Size=1696 (0x6A0)
public:
	std::vector<const IEntityClass*> m_overrideTargetClasses;
	float m_pointBlankDistanceFromHit;
	IEntityArchetype* m_pPointBlankAmmoArchetype;
	ArkRegularOutcome m_accuracyOutcome;
	float m_weaponDispersion;
	float m_minDispersion;
	float m_maxDispersion;
	bool m_bShowAmmoOnHUD;
	wstring m_baseDamageKeyword;
	wstring m_finalDamageKeyword;
	uint64_t m_damageSignal;

	CArkWeaponShotgun();
	virtual ~CArkWeaponShotgun();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void FullSerialize(TSerialize _ser);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual void OnPreRender();
	virtual bool OnActionAttackPrimary(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value);
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect, const bool _bImmediate);
	virtual float GetDispersion() const;
	virtual float GetDamageScale(const float _distance, CArkProjectile* const _pProjectile) const;
	virtual wstring GetDescription() const;
	virtual CCryName GetReticleName() const;
	virtual bool IsTwoHanded() const;
	virtual bool StartAttack();
	virtual bool ContinueAttack();
	virtual bool StopAttack();
	void UpdateAccuracy() { FUpdateAccuracy(this); }
	virtual void UpdateAmmoCountUI() const;
	virtual bool ShowsAmmoOnHUD() const;
	float GetDispersionMinimum() const { return FGetDispersionMinimum(this); }
	float GetDispersionMaximum() const { return FGetDispersionMaximum(this); }
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	virtual void UpdateDispersion();
	virtual _smart_ptr<IAction> ConstructReloadAction(const int _fragmentId) const;
	virtual int GetBaseDamage() const;
	virtual int GetModifiedDamage(const std::vector<uint64_t>& _modifiers, const bool _bIncludeEnchantments) const;
	Vec3 CalculateDispersionPoint(const Vec3& _position, const Quat& _rotation, const Vec3& _aimPoint, const bool _bShootStraight, const float _spreadConeDegrees) { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FCalculateDispersionPoint(this, reinterpret_cast<Vec3*>(_return_buf_), _position, _rotation, _aimPoint, _bShootStraight, _spreadConeDegrees); }
	virtual void SpawnProjectile();
	void SpawnSinglePellet(const Vec3& _position, const Quat& _rotation, const bool _bIsCritical, const unsigned _groupId, const Vec3& _dispersionPoint, const Vec3& _targetAimPoint) { FSpawnSinglePellet(this, _position, _rotation, _bIsCritical, _groupId, _dispersionPoint, _targetAimPoint); }
	virtual void SpawnPellets(const Vec3& _position, const Quat& _rotation, const Vec3& _aimPoint, const bool _bIsCritical, const bool _bShootStraight, const unsigned _groupId);
	void HandlePointBlank(const Vec3& _position, const Quat& _rotation, const Vec3& _aimPoint, const bool _bIsCritical, const unsigned _groupId) { FHandlePointBlank(this, _position, _rotation, _aimPoint, _bIsCritical, _groupId); }
	virtual void OnJump();
	virtual void OnSlide();
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	virtual void OnCombatFocusChanged(bool _bActive);
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;

#if 0
	float GetDispersionNotMoving() const;
	float GetDispersionMoving() const;
	void AddAndClampDispersion(const float _arg0_, const char* const _arg1_, const float _arg2_);
#endif

	static inline auto FCArkWeaponShotgunOv1 = PreyFunction<void(CArkWeaponShotgun* const _this)>(0x179CB90);
	static inline auto FBitNotCArkWeaponShotgun = PreyFunction<void(CArkWeaponShotgun* const _this)>(0x179CCE0);
	static inline auto FInit = PreyFunction<bool(CArkItem* const _this, IGameObject* _pGameObject)>(0x179E810);
	static inline auto FUpdate = PreyFunction<void(CArkItem* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x17A1380);
	static inline auto FFullSerialize = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x179D670);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkItem* const _this, ICrySizer* _s)>(0x179DF50);
	static inline auto FOnPreRender = PreyFunction<void(IGameFrameworkListener* const _this)>(0x17A06E0);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeaponShotgun* const _this, unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value)>(0x17A0510);
	static inline auto FOnEquip = PreyFunction<void(CArkWeaponShotgun* const _this)>(0x17A05E0);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeaponShotgun* const _this, const bool _bUnselect, const bool _bImmediate)>(0x17A0840);
	static inline auto FGetDispersion = PreyFunction<float(const CArkWeaponShotgun* const _this)>(0x148F870);
	static inline auto FGetDamageScale = PreyFunction<float(const CArkWeaponShotgun* const _this, const float _distance, CArkProjectile* const _pProjectile)>(0x179D7E0);
	static inline auto FGetDescription = PreyFunction<wstring*(const CArkItem* const _this, wstring* _return_value_)>(0x179D860);
	static inline auto FGetReticleName = PreyFunction<CCryName*(const CArkWeaponShotgun* const _this, CCryName* _return_value_)>(0x179E0C0);
	static inline auto FIsTwoHanded = PreyFunction<bool(const CArkWeaponShotgun* const _this)>(0x1A302A0);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeaponShotgun* const _this)>(0x17A12F0);
	static inline auto FContinueAttack = PreyFunction<bool(CArkWeaponShotgun* const _this)>(0x179D660);
	static inline auto FStopAttack = PreyFunction<bool(CArkWeaponShotgun* const _this)>(0x17A1370);
	static inline auto FUpdateAccuracy = PreyFunction<void(CArkWeaponShotgun* const _this)>(0x17A1610);
	static inline auto FUpdateAmmoCountUI = PreyFunction<void(const CArkWeaponShotgun* const _this)>(0x17A16B0);
	static inline auto FShowsAmmoOnHUD = PreyFunction<bool(const CArkWeaponShotgun* const _this)>(0x148FA40);
	static inline auto FGetDispersionMinimum = PreyFunction<float(const CArkWeaponShotgun* const _this)>(0x179DE50);
	static inline auto FGetDispersionMaximum = PreyFunction<float(const CArkWeaponShotgun* const _this)>(0x179DD50);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem* const _this)>(0x179FC30);
	static inline auto FInitializeStats = PreyFunction<void(CArkWeaponShotgun* const _this)>(0x179E860);
	static inline auto FUpdateDispersion = PreyFunction<void(CArkWeaponShotgun* const _this)>(0x17A1860);
	static inline auto FConstructReloadAction = PreyFunction<_smart_ptr<IAction>*(const CArkWeaponShotgun* const _this, _smart_ptr<IAction>* _return_value_, const int _fragmentId)>(0x1793B60);
	static inline auto FGetBaseDamage = PreyFunction<int(const CArkWeaponShotgun* const _this)>(0x179D700);
	static inline auto FGetModifiedDamage = PreyFunction<int(const CArkWeaponShotgun* const _this, const std::vector<uint64_t>& _modifiers, const bool _bIncludeEnchantments)>(0x179DF70);
	static inline auto FCalculateDispersionPoint = PreyFunction<Vec3*(CArkWeaponShotgun* const _this, Vec3* _return_value_, const Vec3& _position, const Quat& _rotation, const Vec3& _aimPoint, const bool _bShootStraight, const float _spreadConeDegrees)>(0x179D3E0);
	static inline auto FSpawnProjectile = PreyFunction<void(CArkWeaponShotgun* const _this)>(0x17A0D10);
	static inline auto FSpawnSinglePellet = PreyFunction<void(CArkWeaponShotgun* const _this, const Vec3& _position, const Quat& _rotation, const bool _bIsCritical, const unsigned _groupId, const Vec3& _dispersionPoint, const Vec3& _targetAimPoint)>(0x17A1180);
	static inline auto FSpawnPellets = PreyFunction<void(CArkWeaponShotgun* const _this, const Vec3& _position, const Quat& _rotation, const Vec3& _aimPoint, const bool _bIsCritical, const bool _bShootStraight, const unsigned _groupId)>(0x17A0880);
	static inline auto FHandlePointBlank = PreyFunction<void(CArkWeaponShotgun* const _this, const Vec3& _position, const Quat& _rotation, const Vec3& _aimPoint, const bool _bIsCritical, const unsigned _groupId)>(0x179E1D0);
	static inline auto FOnJump = PreyFunction<void(CArkWeaponShotgun* const _this)>(0x17A0650);
	static inline auto FOnSlide = PreyFunction<void(CArkWeaponShotgun* const _this)>(0x17A0760);
	static inline auto FOnStatChange = PreyFunction<void(IArkStatsListener* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x17A07E0);
	static inline auto FOnCombatFocusChanged = PreyFunction<void(IArkCombatFocusListener* const _this, bool _bActive)>(0x17A05C0);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName*(const CArkWeaponShotgun* const _this, CCryName* _return_value_)>(0x179E0A0);
};
#endif // !MOONCRASH
