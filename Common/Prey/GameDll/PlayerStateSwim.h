// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CPlayer;
struct IItemParamsNode;
struct SActorFrameMovementParams;

// CPlayerStateSwim
// Header:  Prey/GameDll/PlayerStateSwim.h
class CPlayerStateSwim
{ // Size=32 (0x20)
public:
	// CPlayerStateSwim::CSwimmingParams
	// Header:  Prey/GameDll/PlayerStateSwim.h
	struct CSwimmingParams
	{ // Size=28 (0x1C)
		float m_swimSpeedSprintSpeedMul;
		float m_swimUpSprintSpeedMul;
		float m_swimSprintSpeedMul;
		float m_stateSwim_animCameraFactor;
		float m_swimDolphinJumpDepth;
		float m_swimDolphinJumpThresholdSpeed;
		float m_swimDolphinJumpSpeedModification;

	#if 0
		CSwimmingParams();
		void SetParamsFromXml(const IItemParamsNode* _arg0_);
	#endif
	};

	Vec3 m_gravity;
	float m_lastWaterLevel;
	float m_lastWaterLevelTime;
	float m_verticalVelDueToSurfaceMovement;
	float m_headUnderWaterTimer;
	bool m_onSurface;
	bool m_enduranceSwimSoundPlaying;
	static inline auto s_swimParams = PreyGlobal<CPlayerStateSwim::CSwimmingParams>(0x23F1070);

	CPlayerStateSwim();
	void OnEnter(CPlayer& player) { FOnEnter(this, player); }
	bool OnPrePhysicsUpdate(CPlayer& player, const SActorFrameMovementParams& movement, float frameTime) { return FOnPrePhysicsUpdate(this, player, movement, frameTime); }
	void OnUpdate(CPlayer& player, float frameTime) { FOnUpdate(this, player, frameTime); }
	void OnExit(CPlayer& player) { FOnExit(this, player); }
	bool DetectJump(CPlayer& player, const SActorFrameMovementParams& movement, float frameTime, float* pVerticalSpeedModifier) const { return FDetectJump(this, player, movement, frameTime, pVerticalSpeedModifier); }

#if 0
	static void SetParamsFromXml(const IItemParamsNode* _arg0_);
	CPlayerStateSwim(const CPlayerStateSwim& _arg0_);
	static void UpdateSoundListener(CPlayer& _arg0_);
	void PlayEnduranceSound(const unsigned _arg0_);
	void StopEnduranceSound(const unsigned _arg0_);
	static CPlayerStateSwim::CSwimmingParams& GetSwimParams();
	CPlayerStateSwim& operator=(const CPlayerStateSwim& _arg0_);
#endif

	static inline auto FCPlayerStateSwimOv1 = PreyFunction<void(CPlayerStateSwim* const _this)>(0x18E8DC0);
	static inline auto FOnEnter = PreyFunction<void(CPlayerStateSwim* const _this, CPlayer& player)>(0x18E8E40);
	static inline auto FOnPrePhysicsUpdate = PreyFunction<bool(CPlayerStateSwim* const _this, CPlayer& player, const SActorFrameMovementParams& movement, float frameTime)>(0x18E8FF0);
	static inline auto FOnUpdate = PreyFunction<void(CPlayerStateSwim* const _this, CPlayer& player, float frameTime)>(0x1333E90);
	static inline auto FOnExit = PreyFunction<void(CPlayerStateSwim* const _this, CPlayer& player)>(0x18E8F80);
	static inline auto FDetectJump = PreyFunction<bool(const CPlayerStateSwim* const _this, CPlayer& player, const SActorFrameMovementParams& movement, float frameTime, float* pVerticalSpeedModifier)>(0x18E8DE0);
};
#endif // MOONCRASH
