// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/weapons/arklaser.h>
#include <Prey/GameDll/ark/weapons/arkweapon.h>

struct EventPhysCollision;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IMaterial;
struct IParticleEffect;

// Header: Exact
// Prey/GameDll/ark/weapons/arkweaponinstalaser.h
class CArkWeaponInstalaser : public CArkWeapon // Id=801CD96 Size=1648
{
public:
	CArkLaserBeam::ArkLaserParams m_laserParams;
	int m_damageType;
	int m_chargeType;
	int m_hitTypeId;
	uint64_t m_signalPackageId;
	float m_maxBeamThicknessScaleTime;
	float m_beamHitOffset;
	float m_glowTime;
	float m_idleGlowAmount;
	float m_fireGlowAmount;
	IMaterial *m_pGlowMaterial;
	int m_glowSubMaterial;
	CArkLaserBeam m_laserBeam;
	std::vector<_smart_ptr<CArkLaserBeam>> m_reflectedBeams;
	float m_ammoConsumptionTimer;
	float m_previousDamage;
	float m_previousDamagePerSecond;
	unsigned m_targetEntityId;
	float m_targetHitTimer;
	float m_desiredGlowAmount;
	float m_currentGlowAmount;
	bool m_bIsStoppingAttack;
	bool m_bIsMalfunctioning;
	wstring m_baseDamageKeyword;
	wstring m_finalDamageKeyword;
	uint64_t m_damageSignal;
	IParticleEffect *m_pBeamEnd;
	std::vector<ArkEntityEffect> m_beamEndVfx;
	int m_activeBeamEndIndex;
	float m_beamEndJumpDistanceSq;
	std::vector<unsigned __int64> m_sneakAttackMetaTags;
	unsigned m_instigationEventId;
	ArkEntityEffect m_additionalEndEffect;
	
	CArkWeaponInstalaser();
	virtual ~CArkWeaponInstalaser();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnPreRender();
	virtual bool OnActionAttackPrimary(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual float GetWalkSpeedStat() const;
	virtual float GetZoomedWalkSpeedStat() const;
	virtual float GetCameraSpeedStat() const;
	virtual float GetZoomedCameraSpeedStat() const;
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect);
	virtual void ExitSelectAction();
	void SetUpGlowMaterial() { FSetUpGlowMaterial(this); }
	virtual void OnAttackStopped();
	virtual void OnMalfunctionEvent();
	virtual wstring GetDescription() const;
	virtual CCryName GetReticleName() const;
	virtual void StartReloadAmmo();
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	virtual void SustainedAttack();
	virtual bool StartAttack();
	virtual bool ContinueAttack();
	virtual bool StopAttack();
	virtual _smart_ptr<IAction> ConstructReloadAction(const int _fragmentId) const;
	virtual int GetAmmoCost() const;
	float GetBaseAmmoCost(const float _lastDamage) const { return FGetBaseAmmoCost(this,_lastDamage); }
	virtual int GetBaseDamage() const;
	virtual int GetModifiedDamage(std::vector<unsigned __int64> const &_modifiers) const;
	void TurnOffLaser() { FTurnOffLaser(this); }
	virtual void LightVisibilityUpdated(bool _bVisible);
	void InitLaserBeams() { FInitLaserBeams(this); }
	bool ReflectBeam(const float _thickness, CArkLaserBeam *const _pLaserBeam, EventPhysCollision &_collisionEventInfo, Vec3 &_raycastStart) { return FReflectBeam(this,_thickness,_pLaserBeam,_collisionEventInfo,_raycastStart); }
	void DoDamage(float _frameTime, EventPhysCollision const &_collision, const unsigned &_targetId) { FDoDamage(this,_frameTime,_collision,_targetId); }
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;
	void UpdateBeamEnd(const bool bCollision, Vec3 _collisionPos, Vec3 _collisionNormal) { FUpdateBeamEnd(this,bCollision,_collisionPos,_collisionNormal); }
	
#if 0
	int GetNumReflections() const;
	void TurnOnLaser();
	void UpdateDamageInformation();
	void UpdateTargetInformation(const float arg0, IEntity const *const arg1, const unsigned arg2);
	IMaterial *FindGlowMaterial();
	void UpdateCurrentGlowAmount(const float arg0, const float arg1);
#endif
	
	static inline auto FInit = PreyFunction<bool(CArkWeaponInstalaser *const _this, IGameObject *_pGameObject)>(0x1673650);
	static inline auto FPostInit = PreyFunction<void(CArkWeaponInstalaser *const _this, IGameObject *_pGameObject)>(0x1675B10);
	static inline auto FRelease = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1675F70);
	static inline auto FFullSerialize = PreyFunction<void(CArkWeaponInstalaser *const _this, TSerialize _ser)>(0x1672D20);
	static inline auto FPostSerialize = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1675B40);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkWeaponInstalaser const *const _this, ICrySizer *_s)>(0x16734B0);
	static inline auto FOnPreRender = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1674F60);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeaponInstalaser *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1674E10);
	static inline auto FGetWalkSpeedStat = PreyFunction<float(CArkWeaponInstalaser const *const _this)>(0x1673590);
	static inline auto FGetZoomedWalkSpeedStat = PreyFunction<float(CArkWeaponInstalaser const *const _this)>(0x1673610);
	static inline auto FGetCameraSpeedStat = PreyFunction<float(CArkWeaponInstalaser const *const _this)>(0x1672F80);
	static inline auto FGetZoomedCameraSpeedStat = PreyFunction<float(CArkWeaponInstalaser const *const _this)>(0x16735D0);
	static inline auto FOnEquip = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1674F20);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeaponInstalaser *const _this, const bool _bUnselect)>(0x1675AB0);
	static inline auto FExitSelectAction = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1672D10);
	static inline auto FSetUpGlowMaterial = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1675FA0);
	static inline auto FOnAttackStopped = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1674EA0);
	static inline auto FOnMalfunctionEvent = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1674F50);
	static inline auto FGetDescription = PreyFunction<wstring(CArkWeaponInstalaser const *const _this)>(0x1672FC0);
	static inline auto FGetReticleName = PreyFunction<CCryName(CArkWeaponInstalaser const *const _this)>(0x1673570);
	static inline auto FStartReloadAmmo = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x16760C0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1674020);
	static inline auto FInitializeStats = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1673770);
	static inline auto FSustainedAttack = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x16761C0);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeaponInstalaser *const _this)>(0x1676040);
	static inline auto FContinueAttack = PreyFunction<bool(CArkWeaponInstalaser *const _this)>(0x1672820);
	static inline auto FStopAttack = PreyFunction<bool(CArkWeaponInstalaser *const _this)>(0x1676100);
	static inline auto FConstructReloadAction = PreyFunction<_smart_ptr<IAction>(CArkWeaponInstalaser const *const _this, const int _fragmentId)>(0x16727C0);
	static inline auto FGetAmmoCost = PreyFunction<int(CArkWeaponInstalaser const *const _this)>(0x1672DE0);
	static inline auto FGetBaseAmmoCost = PreyFunction<float(CArkWeaponInstalaser const *const _this, const float _lastDamage)>(0x1672E50);
	static inline auto FGetBaseDamage = PreyFunction<int(CArkWeaponInstalaser const *const _this)>(0x1672F10);
	static inline auto FGetModifiedDamage = PreyFunction<int(CArkWeaponInstalaser const *const _this, std::vector<unsigned __int64> const &_modifiers)>(0x16734D0);
	static inline auto FTurnOffLaser = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1676300);
	static inline auto FLightVisibilityUpdated = PreyFunction<void(CArkWeaponInstalaser *const _this, bool _bVisible)>(0x1673FF0);
	static inline auto FInitLaserBeams = PreyFunction<void(CArkWeaponInstalaser *const _this)>(0x1673660);
	static inline auto FReflectBeam = PreyFunction<bool(CArkWeaponInstalaser *const _this, const float _thickness, CArkLaserBeam *const _pLaserBeam, EventPhysCollision &_collisionEventInfo, Vec3 &_raycastStart)>(0x1675B80);
	static inline auto FDoDamage = PreyFunction<void(CArkWeaponInstalaser *const _this, float _frameTime, EventPhysCollision const &_collision, const unsigned &_targetId)>(0x1672A20);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName(CArkWeaponInstalaser const *const _this)>(0x1673550);
	static inline auto FUpdateBeamEnd = PreyFunction<void(CArkWeaponInstalaser *const _this, const bool bCollision, Vec3 _collisionPos, Vec3 _collisionNormal)>(0x16763E0);
};

