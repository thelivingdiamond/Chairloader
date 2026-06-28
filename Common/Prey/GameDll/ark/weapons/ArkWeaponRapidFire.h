// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/weapons/ArkWeaponShotgun.h>

class CCryName;
class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;

// CArkWeaponRapidFire
// Header:  Prey/GameDll/ark/weapons/ArkWeaponRapidFire.h
class CArkWeaponRapidFire : public CArkWeaponShotgun
{ // Size=1704 (0x6A8)
public:
	bool m_bIsStoppingAttack;

	CArkWeaponRapidFire();
	virtual ~CArkWeaponRapidFire();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void FullSerialize(TSerialize _ser);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual void OnPreRender();
	virtual bool OnActionAttackPrimary(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value);
	virtual CCryName GetReticleName() const;
	virtual void SustainedAttack();
	virtual bool StartAttack();
	virtual bool ContinueAttack();
	virtual bool StopAttack();
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect, const bool _bImmediate);
	virtual void OnAttackStopped();
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	virtual void SpawnPellets(const Vec3& _position, const Quat& _rotation, const Vec3& _aimPoint, const bool _bIsCritical, const bool _bShootStraight, const unsigned _groupId);
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;

	static inline auto FCArkWeaponRapidFireOv1 = PreyFunction<void(CArkWeaponRapidFire* const _this)>(0x148F5E0);
	static inline auto FInit = PreyFunction<bool(CArkItem* const _this, IGameObject* _pGameObject)>(0x148F8C0);
	static inline auto FUpdate = PreyFunction<void(CArkItem* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x148FCC0);
	static inline auto FFullSerialize = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x148F820);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkItem* const _this, ICrySizer* _s)>(0x148F880);
	static inline auto FOnPreRender = PreyFunction<void(IGameFrameworkListener* const _this)>(0x148F9D0);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeaponRapidFire* const _this, unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value)>(0x148F8F0);
	static inline auto FGetReticleName = PreyFunction<CCryName*(const CArkWeaponRapidFire* const _this, CCryName* _return_value_)>(0x148F8A0);
	static inline auto FSustainedAttack = PreyFunction<void(CArkWeaponRapidFire* const _this)>(0x148FBD0);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeaponRapidFire* const _this)>(0x1794FF0);
	static inline auto FContinueAttack = PreyFunction<bool(CArkWeaponRapidFire* const _this)>(0x148F750);
	static inline auto FStopAttack = PreyFunction<bool(CArkWeaponRapidFire* const _this)>(0x148FB30);
	static inline auto FOnEquip = PreyFunction<void(CArkWeaponRapidFire* const _this)>(0x148F9C0);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeaponRapidFire* const _this, const bool _bUnselect, const bool _bImmediate)>(0x148F9E0);
	static inline auto FOnAttackStopped = PreyFunction<void(CArkWeaponRapidFire* const _this)>(0x1333E90);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem* const _this)>(0x148F8E0);
	static inline auto FInitializeStats = PreyFunction<void(CArkWeaponRapidFire* const _this)>(0x148F8D0);
	static inline auto FSpawnPellets = PreyFunction<void(CArkWeaponRapidFire* const _this, const Vec3& _position, const Quat& _rotation, const Vec3& _aimPoint, const bool _bIsCritical, const bool _bShootStraight, const unsigned _groupId)>(0x148FA50);
	static inline auto FOnStatChange = PreyFunction<void(IArkStatsListener* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x17A07E0);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName*(const CArkWeaponRapidFire* const _this, CCryName* _return_value_)>(0x179E0A0);
};
#endif // MOONCRASH
