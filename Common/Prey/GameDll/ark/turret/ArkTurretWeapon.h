// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/npc/ArkNpcUtils.h>

class ArkTurret;
struct IEntityArchetype;

// Header: FromCpp
// Prey/GameDll/ark/turret/ArkTurretWeapon.h
class ArkTurretWeapon // Id=80152C2 Size=208
{
public:
	QuatT m_worldTM;
	ArkTurret &m_turret;
	IEntityArchetype *m_pAmmoArchetype;
	float m_bulletSpeed;
	ArkSimpleTimer m_shootTimer;
	float m_curShootingTime;
	float m_timeUntilShotsPerSecondMax;
	ArkNpcUtils::Range m_delayPerShotRange;
	int m_numBulletsFired;
	int m_numBulletsPerBurst;
	float m_delayBetweenBursts;
	ArkSimpleTimer m_burstCooldownTimer;
	float m_curBulletHitChance;
	ArkNpcUtils::Range m_bulletHitChanceRange;
	ArkNpcUtils::Range m_distForHitChanceRange;
	ArkNpcUtils::Range m_missSpreadRange;
	ArkNpcUtils::Range m_technoControlledBulletHitChanceRange;
	ArkNpcUtils::Range m_technoControlledDistForHitChanceRange;
	ArkNpcUtils::Range m_technoControlledMissSpreadRange;
	Vec3 m_viewTowardsMissOffset;
	Vec3 m_viewSideMissOffset;
	Vec3 m_viewAwayMissOffset;
	float m_cosAngleConsideredTowards;
	float m_cosAngleConsideredSide;
	float m_missLeadTargetPercentage;
	float m_deactiveTime;
	bool m_bIsActive;
	bool m_bBurstModeActive;
	
	ArkTurretWeapon(ArkTurret &_turret);
	~ArkTurretWeapon() { FBitNotArkTurretWeapon(this); }
	void Reset() { FReset(this); }
	void Release() { FRelease(this); }
	void UpdateTM(QuatT _worldTM) { FUpdateTM(this,_worldTM); }
	void Update(const unsigned _targetEntityID, const float _frameTime) { FUpdate(this,_targetEntityID,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void RapidFire(const unsigned _targetEntityID, const float _frameTime) { FRapidFire(this,_targetEntityID,_frameTime); }
	void FireBullet(const unsigned _targetEntityID) { FFireBullet(this,_targetEntityID); }
	float GetCurrentSpreadAmount() const { return FGetCurrentSpreadAmount(this); }
	Vec3 GetBulletDirToHit(const unsigned _targetEntityID) const { return FGetBulletDirToHit(this,_targetEntityID); }
	Vec3 GetBulletDirToMissPlayer() const { return FGetBulletDirToMissPlayer(this); }
	
#if 0
	void ForceMaxShootSpeed();
	void SetIsActive(bool arg0);
	bool IsActive() const;
	float GetBulletSpeed() const;
	float GetTimeDeactivated() const;
	ArkNpcUtils::Range const &GetBulletHitChanceRange() const;
	ArkNpcUtils::Range const &GetDistForHitChanceRange() const;
	ArkNpcUtils::Range const &GetMissSpreadRangee() const;
	void SetBulletHitChanceRange(ArkNpcUtils::Range const &arg0);
	void SetDistForHitChanceRange(ArkNpcUtils::Range const &arg0);
	void SetMissSpreadRangee(ArkNpcUtils::Range const &arg0);
	void BurstFire(const unsigned arg0, const float arg1);
	Vec3 GetPlayerShotDir(const unsigned arg0, const bool arg1);
	Vec3 GetOtherShotDir(const unsigned arg0, const bool arg1);
	void UpdateHitChance();
	void ResetShootTimer();
#endif
	
	static inline auto FBitNotArkTurretWeapon = PreyFunction<void(ArkTurretWeapon *const _this)>(0xA13080);
	static inline auto FReset = PreyFunction<void(ArkTurretWeapon *const _this)>(0x15EC140);
	static inline auto FRelease = PreyFunction<void(ArkTurretWeapon *const _this)>(0xA13080);
	static inline auto FUpdateTM = PreyFunction<void(ArkTurretWeapon *const _this, QuatT _worldTM)>(0x15ED2A0);
	static inline auto FUpdate = PreyFunction<void(ArkTurretWeapon *const _this, const unsigned _targetEntityID, const float _frameTime)>(0x15ED160);
	static inline auto FSerialize = PreyFunction<void(ArkTurretWeapon *const _this, TSerialize _ser)>(0x15ED020);
	static inline auto FRapidFire = PreyFunction<void(ArkTurretWeapon *const _this, const unsigned _targetEntityID, const float _frameTime)>(0x15EC070);
	static inline auto FFireBullet = PreyFunction<void(ArkTurretWeapon *const _this, const unsigned _targetEntityID)>(0x15EB870);
	static inline auto FGetCurrentSpreadAmount = PreyFunction<float(ArkTurretWeapon const *const _this)>(0x15EBFF0);
	static inline auto FGetBulletDirToHit = PreyFunction<Vec3(ArkTurretWeapon const *const _this, const unsigned _targetEntityID)>(0x15EBAA0);
	static inline auto FGetBulletDirToMissPlayer = PreyFunction<Vec3(ArkTurretWeapon const *const _this)>(0x15EBC20);
};

