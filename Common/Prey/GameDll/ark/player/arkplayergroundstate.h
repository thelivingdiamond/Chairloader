// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arksimpletimer.h>
#include <Prey/GameDll/ark/player/arkplayermovementstates.h>

class ArkPlayer;
class ArkPlayerMovementFSM;
class CArkProjectileGoo;
struct IPhysicalEntity;
struct RayCastResult;
class XmlNodeRef;

namespace ArkPlayerMovementStates
{

// Header: FromCpp
// Prey/GameDll/ark/player/arkplayergroundstate.h
class Ground : public ArkPlayerMovementStates::Base // Id=80173E8 Size=488
{
public:
	struct ArkGroundColliderParameters // Id=80173E9 Size=12
	{
		float m_minSlideAngle;
		float m_minFallAngle;
		float m_maxClimbAngle;
	};

	enum class Direction
	{
		front = 0,
		back = 1,
		right = 2,
		left = 3,
		_count = 4,
	};

	std::array<ArkLatentRaycast,4> m_footPositioningRaycasts;
	std::array<bool,4> m_groundProbeResults;
	ArkPlayerMovementStates::Ground::ArkGroundColliderParameters m_groundColliderParams;
	ArkPlayerMovementStates::Ground::ArkGroundColliderParameters m_gooProjectileColliderParams;
	ArkAudioTrigger m_triggerSprintStart;
	ArkAudioTrigger m_triggerSprintFullyAccelerated;
	_smart_ptr<TAction<SAnimationContext> > m_hobbleAnim;
	CArkProjectileGoo const *m_pProjectileGooGroundCollider;
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
	
	void LimitRotation(ArkPlayerMovementFSM const &_fsm, Quat &_rotation) const { FLimitRotation(this,_fsm,_rotation); }
	void LoadConfig(XmlNodeRef const &_root) { FLoadConfig(this,_root); }
	void Update(ArkPlayerMovementFSM &_fsm, const float _frameTime) { FUpdate(this,_fsm,_frameTime); }
	bool OnSneakButtonPressed(ArkPlayerMovementFSM &_fsm) { return FOnSneakButtonPressed(this,_fsm); }
	static bool ShouldBeSprinting(ArkPlayerMovementFSM const &_fsm) { return FShouldBeSprinting(_fsm); }
	Vec3 GetAdditionalMovementOnGoo(const float _movementLength) { return FGetAdditionalMovementOnGoo(this,_movementLength); }
	float GetLeanInput(ArkPlayerMovementFSM const &_fsm) const { return FGetLeanInput(this,_fsm); }
	Vec2 GetMovementInput(ArkPlayer const &_player) const { return FGetMovementInput(this,_player); }
	bool OnGroundProbeCompleteFront(RayCastResult const &_result) { return FOnGroundProbeCompleteFront(this,_result); }
	bool OnGroundProbeCompleteBack(RayCastResult const &_result) { return FOnGroundProbeCompleteBack(this,_result); }
	bool OnGroundProbeCompleteLeft(RayCastResult const &_result) { return FOnGroundProbeCompleteLeft(this,_result); }
	bool OnGroundProbeCompleteRight(RayCastResult const &_result) { return FOnGroundProbeCompleteRight(this,_result); }
	
#if 0
	void Exit();
	void SetRequestedStance(EStance arg0);
	void Serialize(TSerialize arg0);
	static bool AllowsJump(ArkPlayerMovementFSM const &arg0);
	bool IsSprinting(ArkPlayerMovementFSM const &arg0) const;
	void SetMovementParameters(ArkPlayerMovementStates::Ground::ArkGroundColliderParameters arg0, ArkPlayerMovementStates::Ground::ArkGroundColliderParameters arg1);
	void UpdateProjectileGooGroundCollider(IPhysicalEntity *const arg0);
#endif
	
	static inline auto FLimitRotation = PreyFunction<void(ArkPlayerMovementStates::Ground const *const _this, ArkPlayerMovementFSM const &_fsm, Quat &_rotation)>(0x12359A0);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerMovementStates::Ground *const _this, XmlNodeRef const &_root)>(0x1235EA0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::Ground *const _this, ArkPlayerMovementFSM &_fsm, const float _frameTime)>(0x1236530);
	static inline auto FOnSneakButtonPressed = PreyFunction<bool(ArkPlayerMovementStates::Ground *const _this, ArkPlayerMovementFSM &_fsm)>(0x12362C0);
	static inline auto FShouldBeSprinting = PreyFunction<bool(ArkPlayerMovementFSM const &_fsm)>(0x12363B0);
	static inline auto FGetAdditionalMovementOnGoo = PreyFunction<Vec3(ArkPlayerMovementStates::Ground *const _this, const float _movementLength)>(0x12354F0);
	static inline auto FGetLeanInput = PreyFunction<float(ArkPlayerMovementStates::Ground const *const _this, ArkPlayerMovementFSM const &_fsm)>(0x1235970);
	static inline auto FGetMovementInput = PreyFunction<Vec2(ArkPlayerMovementStates::Ground const *const _this, ArkPlayer const &_player)>(0x123BC10);
	static inline auto FOnGroundProbeCompleteFront = PreyFunction<bool(ArkPlayerMovementStates::Ground *const _this, RayCastResult const &_result)>(0x1236260);
	static inline auto FOnGroundProbeCompleteBack = PreyFunction<bool(ArkPlayerMovementStates::Ground *const _this, RayCastResult const &_result)>(0x1236240);
	static inline auto FOnGroundProbeCompleteLeft = PreyFunction<bool(ArkPlayerMovementStates::Ground *const _this, RayCastResult const &_result)>(0x1236280);
	static inline auto FOnGroundProbeCompleteRight = PreyFunction<bool(ArkPlayerMovementStates::Ground *const _this, RayCastResult const &_result)>(0x12362A0);
};

} // namespace ArkPlayerMovementStates

