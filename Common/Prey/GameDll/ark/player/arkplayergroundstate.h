// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/ArkPlayerMovementStates.h>
#include <Prey/GameDll/ark/ArkLatentRaycast.h>

class ArkPlayer;
class ArkPlayerMovementFSM;
class CArkProjectileGoo;
struct IPhysicalEntity;
struct RayCastResult;
class XmlNodeRef;

namespace ArkPlayerMovementStates
{

// ArkPlayerMovementStates::Ground
// Header:  Prey/GameDll/ark/player/arkplayergroundstate.h
class Ground : public ArkPlayerMovementStates::Base
{ // Size=488 (0x1E8)
public:
	enum class Direction
	{
		front = 0,
		back = 1,
		right = 2,
		left = 3,
		_count = 4,
	};

	// ArkPlayerMovementStates::Ground::ArkGroundColliderParameters
	// Header:  Prey/GameDll/ark/player/arkplayergroundstate.h
	struct ArkGroundColliderParameters
	{ // Size=12 (0xC)
		float m_minSlideAngle;
		float m_minFallAngle;
		float m_maxClimbAngle;

	#if 0
		ArkGroundColliderParameters();
		ArkGroundColliderParameters(const float _arg0_, const float _arg1_, const float _arg2_);
	#endif
	};

	std::array<ArkLatentRaycast,4> m_footPositioningRaycasts;
	std::array<bool,4> m_groundProbeResults;
	ArkPlayerMovementStates::Ground::ArkGroundColliderParameters m_groundColliderParams;
	ArkPlayerMovementStates::Ground::ArkGroundColliderParameters m_gooProjectileColliderParams;
	ArkAudioTrigger m_triggerSprintStart;
	ArkAudioTrigger m_triggerSprintFullyAccelerated;
	_smart_ptr<TAction<SAnimationContext> > m_hobbleAnim;
	const CArkProjectileGoo* m_pProjectileGooGroundCollider;
	ArkAutoResetTimer m_sprintBleedTimer;
	ArkSimpleTimer m_sprintAccelerationTimer;
	ArkSimpleTimer m_jumpWindowTimer;
	ArkSimpleTimer m_stumbleSwitchTimer;
	ArkSimpleTimer m_stumbleTimer;
	EStance m_requestedStance;
	int m_sprintZoomHandle;
	float m_leanPitchLimit;
	float m_leanYawLimit;
	float m_leanCancelSpeedSq;
	float m_preLandJumpWindow;
	float m_turnTravelAngle;
	float m_turnTravelSpeed;
	float m_stumbleXAdd;
	float m_stumbleYScale;
	float m_stumbleMinListDuration;
	float m_stumbleMaxListDuration;
	float m_stumbleXMinAdd;
	float m_stumbleXMaxAdd;
	float m_stumbleYMinScale;
	float m_stumbleYMaxScale;
	float m_stumbleDurationMin;
	float m_stumbleDurationMax;
	float m_stumbleBreakDurationMin;
	float m_stumbleBreakDurationMax;
	float m_rotationCatchUpAngleThreshold;
	float m_travelAngle;
	float m_groundProbeDistance;
	bool m_bStumbleRight;
	bool m_bIsStumbling;
	bool m_bCatchUpRotation;
	bool m_bCanLean;
	bool m_bSprinting;

	void LimitRotation(const ArkPlayerMovementFSM& _fsm, Quat& _rotation) const { FLimitRotation(this, _fsm, _rotation); }
	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }
	bool OnSneakButtonPressed(ArkPlayerMovementFSM& _fsm) { return FOnSneakButtonPressed(this, _fsm); }
	static bool ShouldBeSprinting(const ArkPlayerMovementFSM& _fsm) { return FShouldBeSprinting(_fsm); }
	Vec3 GetAdditionalMovementOnGoo(const float _movementLength) { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetAdditionalMovementOnGoo(this, reinterpret_cast<Vec3*>(_return_buf_), _movementLength); }
	float GetLeanInput(const ArkPlayerMovementFSM& _fsm) const { return FGetLeanInput(this, _fsm); }
	Vec2 GetMovementInput(const ArkPlayer& _player) const { alignas(Vec2) std::byte _return_buf_[sizeof(Vec2)]; return *FGetMovementInput(this, reinterpret_cast<Vec2*>(_return_buf_), _player); }
	bool OnGroundProbeCompleteFront(const RayCastResult& _result) { return FOnGroundProbeCompleteFront(this, _result); }
	bool OnGroundProbeCompleteBack(const RayCastResult& _result) { return FOnGroundProbeCompleteBack(this, _result); }
	bool OnGroundProbeCompleteLeft(const RayCastResult& _result) { return FOnGroundProbeCompleteLeft(this, _result); }
	bool OnGroundProbeCompleteRight(const RayCastResult& _result) { return FOnGroundProbeCompleteRight(this, _result); }

#if 0
	Ground();
	void Exit();
	void SetRequestedStance(EStance _arg0_);
	void Serialize(TSerialize _arg0_);
	static bool AllowsJump(const ArkPlayerMovementFSM& _arg0_);
	bool IsSprinting(const ArkPlayerMovementFSM& _arg0_) const;
	void SetMovementParameters(ArkPlayerMovementStates::Ground::ArkGroundColliderParameters _arg0_, ArkPlayerMovementStates::Ground::ArkGroundColliderParameters _arg1_);
	void UpdateProjectileGooGroundCollider(IPhysicalEntity* const _arg0_);
#endif

	static inline auto FLimitRotation = PreyFunction<void(const ArkPlayerMovementStates::Ground* const _this, const ArkPlayerMovementFSM& _fsm, Quat& _rotation)>(0x12359A0);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerMovementStates::Ground* const _this, const XmlNodeRef& _root)>(0x1235EA0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::Ground* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1236530);
	static inline auto FOnSneakButtonPressed = PreyFunction<bool(ArkPlayerMovementStates::Ground* const _this, ArkPlayerMovementFSM& _fsm)>(0x12362C0);
	static inline auto FShouldBeSprinting = PreyFunction<bool(const ArkPlayerMovementFSM& _fsm)>(0x12363B0);
	static inline auto FGetAdditionalMovementOnGoo = PreyFunction<Vec3*(ArkPlayerMovementStates::Ground* const _this, Vec3* _return_value_, const float _movementLength)>(0x12354F0);
	static inline auto FGetLeanInput = PreyFunction<float(const ArkPlayerMovementStates::Ground* const _this, const ArkPlayerMovementFSM& _fsm)>(0x1235970);
	static inline auto FGetMovementInput = PreyFunction<Vec2*(const ArkPlayerMovementStates::Ground* const _this, Vec2* _return_value_, const ArkPlayer& _player)>(0x123BC10);
	static inline auto FOnGroundProbeCompleteFront = PreyFunction<bool(ArkPlayerMovementStates::Ground* const _this, const RayCastResult& _result)>(0x1236260);
	static inline auto FOnGroundProbeCompleteBack = PreyFunction<bool(ArkPlayerMovementStates::Ground* const _this, const RayCastResult& _result)>(0x1236240);
	static inline auto FOnGroundProbeCompleteLeft = PreyFunction<bool(ArkPlayerMovementStates::Ground* const _this, const RayCastResult& _result)>(0x1236280);
	static inline auto FOnGroundProbeCompleteRight = PreyFunction<bool(ArkPlayerMovementStates::Ground* const _this, const RayCastResult& _result)>(0x12362A0);
};


} // namespace ArkPlayerMovementStates

