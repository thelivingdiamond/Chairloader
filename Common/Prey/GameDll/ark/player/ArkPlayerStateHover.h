// Header file automatically created from a PDB.
#pragma once

class ArkNpc;
class CPlayer;
enum class EStance;
struct IEntity;
struct SActorFrameMovementParams;

// CArkPlayerStateHover
// Header:  Prey/GameDll/ark/player/ArkPlayerStateHover.h
class CArkPlayerStateHover
{ // Size=160 (0xA0)
public:
	Vec3 m_lastPos;
	Vec3 m_lastVelReq;
	float m_lastVelAddTime;
	bool m_bPropertyInit;
	bool m_bSpawned;
	bool m_bHoverEnabled;
	bool m_bBobEnabled;
	bool m_bOversteerEnabled;
	bool m_bHasHoverHeight;
	bool m_bWasHoverAdjustFast;
	float m_matchTargetHeightDist;
	float m_hoverHeight;
	float m_lockHoverHeight;
	float m_vertAccel;
	float m_vertBobTimer;
	float m_vertVel;
	float m_vertVelTarget;
	float m_defaultAirControl;
	float m_defaultAirResistance;
	float m_defaultGravity;
	float m_corruptGravityOnInterval;
	float m_corruptGravityOnTimer;
	float m_corruptGravityOnVelZ;
	float m_corruptLockRollInterval;
	float m_corruptLockRollTimer;
	int m_oldCornerSmooth;
	float m_bobTimeMin;
	float m_bobTimeMax;
	float m_bobVelMinZ;
	float m_bobVelMaxZ;
	float m_bobVelAccelStartMult;
	float m_bobVelDecelEndMult;
	float m_bobAdjustFastHeightDelta;
	float m_bobAdjustFastSpeed;
	float m_psiLiftSpeedMult;
	unsigned m_startEffectId;
	unsigned m_turnEffectId;
	unsigned m_stopEffectId;
	unsigned m_speedEffectId;
	unsigned m_speedPercentEffectId;
	unsigned m_corruptGravityEffectId;

	CArkPlayerStateHover();
	void OnInit(CPlayer& _player) { FOnInit(this, _player); }
	void OnEnter(CPlayer& _player) { FOnEnter(this, _player); }
	void OnPrePhysicsUpdate(CPlayer& _player, const SActorFrameMovementParams& _movement, float _frameTime) { FOnPrePhysicsUpdate(this, _player, _movement, _frameTime); }
	void OnExit(CPlayer& _player) { FOnExit(this, _player); }
	void Spawn(CPlayer& _player) { FSpawn(this, _player); }
	void UpdateHoverHeight(IEntity* _pPlayerEntity, const Vec3& _desiredVel) { FUpdateHoverHeight(this, _pPlayerEntity, _desiredVel); }
	void AddHoverVelocityZ(const Vec3& _curPos, Vec3& _curVel) { FAddHoverVelocityZ(this, _curPos, _curVel); }
	void UpdateCorrupted(CPlayer& _player, Vec3& _curVel) { FUpdateCorrupted(this, _player, _curVel); }
	EStance GetTargetStance(IEntity* _pTargetEntity) { return FGetTargetStance(this, _pTargetEntity); }
	void SetHoverPhysics(CPlayer& _player, bool _bOn) { FSetHoverPhysics(this, _player, _bOn); }
	void UpdateMotorSounds(CPlayer& _player, const Vec3& _newVel) { FUpdateMotorSounds(this, _player, _newVel); }
	bool GetFloorPos(ArkNpc* _pNpc, Vec3& _outPos, const Vec3& _testPos) { return FGetFloorPos(this, _pNpc, _outPos, _testPos); }

#if 0
	void OnUpdate(CPlayer& _arg0_, float _arg1_);
	bool IsHoverPermanent();
	void SetBobEnabled(bool _arg0_);
	void SetOversteerEnabled(bool _arg0_);
	bool IsSpawned() const;
	void AddOversteerVelocity(float _arg0_, Vec3& _arg1_);
	bool GetCeilingPos(ArkNpc* _arg0_, Vec3& _arg1_, const Vec3& _arg2_);
	void SetHoverPos(CPlayer& _arg0_);
#endif

	static inline auto FCArkPlayerStateHoverOv2 = PreyFunction<void(CArkPlayerStateHover* const _this)>(0x15764A0);
	static inline auto FOnInit = PreyFunction<void(CArkPlayerStateHover* const _this, CPlayer& _player)>(0x1576D90);
	static inline auto FOnEnter = PreyFunction<void(CArkPlayerStateHover* const _this, CPlayer& _player)>(0x1576B50);
	static inline auto FOnPrePhysicsUpdate = PreyFunction<void(CArkPlayerStateHover* const _this, CPlayer& _player, const SActorFrameMovementParams& _movement, float _frameTime)>(0x1577570);
	static inline auto FOnExit = PreyFunction<void(CArkPlayerStateHover* const _this, CPlayer& _player)>(0x1576D40);
	static inline auto FSpawn = PreyFunction<void(CArkPlayerStateHover* const _this, CPlayer& _player)>(0x1577D40);
	static inline auto FUpdateHoverHeight = PreyFunction<void(CArkPlayerStateHover* const _this, IEntity* _pPlayerEntity, const Vec3& _desiredVel)>(0x1578360);
	static inline auto FAddHoverVelocityZ = PreyFunction<void(CArkPlayerStateHover* const _this, const Vec3& _curPos, Vec3& _curVel)>(0x1576550);
	static inline auto FUpdateCorrupted = PreyFunction<void(CArkPlayerStateHover* const _this, CPlayer& _player, Vec3& _curVel)>(0x1577FC0);
	static inline auto FGetTargetStance = PreyFunction<EStance(CArkPlayerStateHover* const _this, IEntity* _pTargetEntity)>(0x15769C0);
	static inline auto FSetHoverPhysics = PreyFunction<void(CArkPlayerStateHover* const _this, CPlayer& _player, bool _bOn)>(0x1577BE0);
	static inline auto FUpdateMotorSounds = PreyFunction<void(CArkPlayerStateHover* const _this, CPlayer& _player, const Vec3& _newVel)>(0x15787D0);
	static inline auto FGetFloorPos = PreyFunction<bool(CArkPlayerStateHover* const _this, ArkNpc* _pNpc, Vec3& _outPos, const Vec3& _testPos)>(0x15768C0);
};

