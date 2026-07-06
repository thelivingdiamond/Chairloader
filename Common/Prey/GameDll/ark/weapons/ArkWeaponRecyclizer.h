// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/weapons/ArkWeapon.h>

class CCryName;
class IAction;
class ICrySizer;
struct IGameObject;

// CArkWeaponRecyclizer
// Header:  Prey/GameDll/ark/weapons/ArkWeaponRecyclizer.h
class CArkWeaponRecyclizer : public CArkWeapon
{ // Size=1680 (0x690)
public:
	float m_gravitationalPullRadius;
	float m_gravitationalPull;
	float m_recyclingImpulse;
	bool m_bIsStoppingAttack;
	bool m_bIsMalfunctioning;
	ArkSimpleTimer m_populateTimer;
	ArkSimpleTimer m_recycleTimer;
	int m_maxScrapAmmo;
	std::vector<uint64_t> m_sneakAttackMetaTags;
	unsigned m_instigationEventId;
	bool m_bScrapMode;

	CArkWeaponRecyclizer();
	virtual ~CArkWeaponRecyclizer();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual void OnPreRender();
	virtual bool OnActionAttackPrimary(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value);
	virtual float GetWalkSpeedStat() const;
	virtual float GetZoomedWalkSpeedStat() const;
	virtual float GetCameraSpeedStat() const;
	virtual float GetZoomedCameraSpeedStat() const;
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect, const bool _bImmediate);
	virtual void ExitSelectAction();
	virtual void OnAttackStopped();
	virtual CCryName GetReticleName() const;
	virtual void StartReloadAmmo();
	virtual int GetWeaponAmmoCount() const;
	virtual int GetInventoryAmmoCount() const;
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	virtual void SustainedAttack();
	virtual bool StartAttack();
	virtual bool ContinueAttack();
	virtual bool StopAttack();
	virtual _smart_ptr<IAction> ConstructReloadAction(const int _fragmentId) const;
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;
	std::pair<Vec3, Vec3> GetMuzzlePosAndDir() const { alignas(std::pair<Vec3, Vec3>) std::byte _return_buf_[sizeof(std::pair<Vec3, Vec3>)]; return *FGetMuzzlePosAndDir(this, reinterpret_cast<std::pair<Vec3, Vec3>*>(_return_buf_)); }

	static inline auto FCArkWeaponRecyclizerOv1 = PreyFunction<void(CArkWeaponRecyclizer* const _this)>(0x148FCD0);
	static inline auto FInit = PreyFunction<bool(CArkItem* const _this, IGameObject* _pGameObject)>(0x14902C0);
	static inline auto FPostInit = PreyFunction<void(CArkItem* const _this, IGameObject* _pGameObject)>(0x1490E50);
	static inline auto FRelease = PreyFunction<void(CArkItem* const _this)>(0x1490F00);
	static inline auto FFullSerialize = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x148FFA0);
	static inline auto FPostSerialize = PreyFunction<void(CArkItem* const _this)>(0x1490E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkItem* const _this, ICrySizer* _s)>(0x1490040);
	static inline auto FOnPreRender = PreyFunction<void(IGameFrameworkListener* const _this)>(0x1490930);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeaponRecyclizer* const _this, unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value)>(0x1490830);
	static inline auto FGetWalkSpeedStat = PreyFunction<float(const CArkWeaponRecyclizer* const _this)>(0x17967B0);
	static inline auto FGetZoomedWalkSpeedStat = PreyFunction<float(const CArkWeaponRecyclizer* const _this)>(0x17967F0);
	static inline auto FGetCameraSpeedStat = PreyFunction<float(const CArkWeaponRecyclizer* const _this)>(0x1490000);
	static inline auto FGetZoomedCameraSpeedStat = PreyFunction<float(const CArkWeaponRecyclizer* const _this)>(0x1490280);
	static inline auto FOnEquip = PreyFunction<void(CArkWeaponRecyclizer* const _this)>(0x1490910);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeaponRecyclizer* const _this, const bool _bUnselect, const bool _bImmediate)>(0x1490E00);
	static inline auto FExitSelectAction = PreyFunction<void(CArkWeaponRecyclizer* const _this)>(0x148FF90);
	static inline auto FOnAttackStopped = PreyFunction<void(CArkWeaponRecyclizer* const _this)>(0x1490900);
	static inline auto FGetReticleName = PreyFunction<CCryName*(const CArkWeaponRecyclizer* const _this, CCryName* _return_value_)>(0x1796790);
	static inline auto FStartReloadAmmo = PreyFunction<void(CArkWeaponRecyclizer* const _this)>(0x1333E90);
	static inline auto FGetWeaponAmmoCount = PreyFunction<int(const CArkWeaponRecyclizer* const _this)>(0x1490250);
	static inline auto FGetInventoryAmmoCount = PreyFunction<int(const CArkWeaponRecyclizer* const _this)>(0x1727910);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem* const _this)>(0x1490320);
	static inline auto FInitializeStats = PreyFunction<void(CArkWeaponRecyclizer* const _this)>(0x1490310);
	static inline auto FSustainedAttack = PreyFunction<void(CArkWeaponRecyclizer* const _this)>(0x14910B0);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeaponRecyclizer* const _this)>(0x1490F10);
	static inline auto FContinueAttack = PreyFunction<bool(CArkWeaponRecyclizer* const _this)>(0x148FEC0);
	static inline auto FStopAttack = PreyFunction<bool(CArkWeaponRecyclizer* const _this)>(0x1490FE0);
	static inline auto FConstructReloadAction = PreyFunction<_smart_ptr<IAction>*(const CArkWeaponRecyclizer* const _this, _smart_ptr<IAction>* _return_value_, const int _fragmentId)>(0x1793B60);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName*(const CArkWeaponRecyclizer* const _this, CCryName* _return_value_)>(0x1796770);
	static inline auto FGetMuzzlePosAndDir = PreyFunction<std::pair<Vec3, Vec3>*(const CArkWeaponRecyclizer* const _this, std::pair<Vec3, Vec3>* _return_value_)>(0x1490060);
};
#endif // MOONCRASH
