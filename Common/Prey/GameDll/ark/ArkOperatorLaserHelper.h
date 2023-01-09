// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/weapons/arklaser.h>

class ArkNpc;
struct EventPhysCollision;

// ArkOperatorLaserHelper
// Header:  Prey/GameDll/ark/ArkOperatorLaserHelper.h
class ArkOperatorLaserHelper
{ // Size=608 (0x260)
public:
	enum class Stage
	{
		Off = 0,
		Charging = 1,
		On = 2,
	};

	CArkLaserBeam m_laserBeam;
	CArkLaserBeam::ArkLaserParams params;
	string m_laserMatEffectName;
	Vec3 m_laserTarget;
	Vec3 m_beamCollisionPoint;
	uint64_t m_laserAttackPackageId;
	float m_laserDamagePerSecond;
	int m_laserHitTypeId;
	static constexpr const int k_beamEndVfxCount = 4;
	std::array<ArkLooseEffect, 4> m_beamEndVfx;
	int m_currentBeamEndEffectIndex;
	float m_beamEndJumpDistSq;
	ArkSimpleTimer m_materialEffectCooldown;
	float m_chargeTimer;
	float m_maxLaserLength;
	ArkOperatorLaserHelper::Stage m_stage;

	ArkOperatorLaserHelper();
	~ArkOperatorLaserHelper();
	void InitializeLaserHelper(ArkNpc& _npc, float _laserDamagePerSecond) { FInitializeLaserHelper(this, _npc, _laserDamagePerSecond); }
	void StartChargingLaser(ArkNpc& _npc, float _chargeDuration) { FStartChargingLaser(this, _npc, _chargeDuration); }
	void TurnOffLaser(ArkNpc& _npc) { FTurnOffLaser(this, _npc); }
	void UpdateLaser(ArkNpc& _npc, float _elapsedTime) { FUpdateLaser(this, _npc, _elapsedTime); }
	QuatT GetLaserAttachmentTM(const ArkNpc& _npc) const { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FGetLaserAttachmentTM(this, reinterpret_cast<QuatT*>(_return_buf_), _npc); }
	const Vec3& GetBeamCollisionPoint() const { return FGetBeamCollisionPoint(this); }
	void DoMilitaryOperatorLaserDamage(ArkNpc& _npc, const float _frameTime, const EventPhysCollision& _collision) { FDoMilitaryOperatorLaserDamage(this, _npc, _frameTime, _collision); }

#if 0
	bool IsLaserOn() const;
	bool IsLaserCharging() const;
	void TurnOnLaser(ArkNpc& _arg0_);
	void SetLaserTarget(const Vec3& _arg0_);
	void SetLaserDirection(const ArkNpc& _arg0_, const Vec3& _arg1_);
	void UpdateBeamEndParticleEffect(ArkNpc& _arg0_, bool _arg1_, const Vec3& _arg2_, const Vec3& _arg3_);
	void UpdateBeamEndMaterialEffect(ArkNpc& _arg0_, const EventPhysCollision& _arg1_);
#endif

	static inline auto FArkOperatorLaserHelperOv1 = PreyFunction<void(ArkOperatorLaserHelper* const _this)>(0x1280CB0);
	static inline auto FBitNotArkOperatorLaserHelper = PreyFunction<void(ArkOperatorLaserHelper* const _this)>(0x1280DE0);
	static inline auto FInitializeLaserHelper = PreyFunction<void(ArkOperatorLaserHelper* const _this, ArkNpc& _npc, float _laserDamagePerSecond)>(0x1281510);
	static inline auto FStartChargingLaser = PreyFunction<void(ArkOperatorLaserHelper* const _this, ArkNpc& _npc, float _chargeDuration)>(0x1281630);
	static inline auto FTurnOffLaser = PreyFunction<void(ArkOperatorLaserHelper* const _this, ArkNpc& _npc)>(0x1281690);
	static inline auto FUpdateLaser = PreyFunction<void(ArkOperatorLaserHelper* const _this, ArkNpc& _npc, float _elapsedTime)>(0x1281700);
	static inline auto FGetLaserAttachmentTM = PreyFunction<QuatT*(const ArkOperatorLaserHelper* const _this, QuatT* _return_value_, const ArkNpc& _npc)>(0x1281250);
	static inline auto FGetBeamCollisionPoint = PreyFunction<const Vec3& (const ArkOperatorLaserHelper* const _this)>(0x10BD5B0);
	static inline auto FDoMilitaryOperatorLaserDamage = PreyFunction<void(ArkOperatorLaserHelper* const _this, ArkNpc& _npc, const float _frameTime, const EventPhysCollision& _collision)>(0x1280F70);
};

