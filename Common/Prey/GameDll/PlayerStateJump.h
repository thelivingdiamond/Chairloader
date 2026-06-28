// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/IPlayerEventListener.h>

class CPlayer;
class CPlayerJump;
struct SActorFrameMovementParams;

// CPlayerStateJump
// Header:  Prey/GameDll/PlayerStateJump.h
class CPlayerStateJump
{ // Size=40 (0x28)
public:
	enum class EJumpState
	{
		JState_None = 0,
		JState_Jump = 1,
		JState_Falling = 2,
		JState_Total = 3,
	};

	CPlayerStateJump::EJumpState m_jumpState;
	float m_jumpLock;
	float m_startFallingHeight;
	float m_expectedJumpEndHeight;
	bool m_firstPrePhysicsUpdate;
	bool m_bSprintJump;
	CPlayerJump* m_jumpAction;
	int m_continueJumpStartCounter;

	CPlayerStateJump();
	~CPlayerStateJump();
	void OnEnter(CPlayer& player) { FOnEnter(this, player); }
	bool OnPrePhysicsUpdate(CPlayer& player, const bool isHeavyWeapon, const SActorFrameMovementParams& movement, float frameTime) { return FOnPrePhysicsUpdate(this, player, isHeavyWeapon, movement, frameTime); }
	void OnExit(CPlayer& player, const bool isHeavyWeapon) { FOnExit(this, player, isHeavyWeapon); }
	void OnJump(CPlayer& player, const bool isHeavyWeapon, const float fVerticalSpeedModifier) { FOnJump(this, player, isHeavyWeapon, fVerticalSpeedModifier); }
	void OnFall(CPlayer& player) { FOnFall(this, player); }
	void SetJumpState(CPlayer& player, CPlayerStateJump::EJumpState jumpState) { FSetJumpState(this, player, jumpState); }
	void StartJump(CPlayer& player, const bool isHeavyWeapon, const float fVerticalSpeedModifier) { FStartJump(this, player, isHeavyWeapon, fVerticalSpeedModifier); }
	bool UpdateCommon(CPlayer& player, const bool isHeavyWeapon, const SActorFrameMovementParams& movement, float frameTime, Vec3* pDesiredVel) { return FUpdateCommonOv0(this, player, isHeavyWeapon, movement, frameTime, pDesiredVel); }
	void GetDesiredVelocity(const Vec3& move, const CPlayer& player, Vec3* pDesiredVel) const { FGetDesiredVelocity(this, move, player, pDesiredVel); }
	void FinalizeVelocity(CPlayer& player, const Vec3& newVelocity) { FFinalizeVelocity(this, player, newVelocity); }
	void Land(CPlayer& player, const bool isHeavyWeapon, float frameTime) { FLand(this, player, isHeavyWeapon, frameTime); }
	void Landed(CPlayer& player, const bool isHeavyWeapon, float fallSpeed) { FLanded(this, player, isHeavyWeapon, fallSpeed); }
	const Vec3 CalculateInAirJumpExtraVelocity(const CPlayer& player, const Vec3& desiredVelocity) const { alignas(const Vec3) std::byte _return_buf_[sizeof(const Vec3)]; return *FCalculateInAirJumpExtraVelocity(this, reinterpret_cast<const Vec3*>(_return_buf_), player, desiredVelocity); }

#if 0
	void OnFullSerialize(TSerialize _arg0_, CPlayer& _arg1_);
	CPlayerStateJump::EJumpState GetJumpState() const;
	const float GetExpectedJumpEndHeight() const;
	const float GetStartFallingHeight() const;
	bool GetSprintJump() const;
	bool IsJumping() const;
	void OnRevive();
	void OnMPWeaponSelect(CPlayer& _arg0_);
	void UpdateJumping(CPlayer& _arg0_, const bool _arg1_, const SActorFrameMovementParams& _arg2_, float _arg3_);
	void UpdateFalling(CPlayer& _arg0_, const bool _arg1_, const SActorFrameMovementParams& _arg2_, float _arg3_);
	bool UpdateCommon(CPlayer& _arg0_, const bool _arg1_, const Vec3& _arg2_, float _arg3_, Vec3* _arg4_);
	void OnSpecialMove(CPlayer& _arg0_, IPlayerEventListener::ESpecialMove _arg1_);
#endif

	static inline auto FCPlayerStateJump = PreyFunction<void(CPlayerStateJump* const _this)>(0x18E2FE0);
	static inline auto FBitNotCPlayerStateJump = PreyFunction<void(CPlayerStateJump* const _this)>(0x1333E90);
	static inline auto FOnEnter = PreyFunction<void(CPlayerStateJump* const _this, CPlayer& player)>(0x18E3BD0);
	static inline auto FOnPrePhysicsUpdate = PreyFunction<bool(CPlayerStateJump* const _this, CPlayer& player, const bool isHeavyWeapon, const SActorFrameMovementParams& movement, float frameTime)>(0x18E3DD0);
	static inline auto FOnExit = PreyFunction<void(CPlayerStateJump* const _this, CPlayer& player, const bool isHeavyWeapon)>(0x18E3BF0);
	static inline auto FOnJump = PreyFunction<void(CPlayerStateJump* const _this, CPlayer& player, const bool isHeavyWeapon, const float fVerticalSpeedModifier)>(0x18E3DB0);
	static inline auto FOnFall = PreyFunction<void(CPlayerStateJump* const _this, CPlayer& player)>(0x18E3DA0);
	static inline auto FSetJumpState = PreyFunction<void(CPlayerStateJump* const _this, CPlayer& player, CPlayerStateJump::EJumpState jumpState)>(0x18E4070);
	static inline auto FStartJump = PreyFunction<void(CPlayerStateJump* const _this, CPlayer& player, const bool isHeavyWeapon, const float fVerticalSpeedModifier)>(0x18E41D0);
	static inline auto FUpdateCommonOv0 = PreyFunction<bool(CPlayerStateJump* const _this, CPlayer& player, const bool isHeavyWeapon, const SActorFrameMovementParams& movement, float frameTime, Vec3* pDesiredVel)>(0x18E4810);
	static inline auto FGetDesiredVelocity = PreyFunction<void(const CPlayerStateJump* const _this, const Vec3& move, const CPlayer& player, Vec3* pDesiredVel)>(0x18E3260);
	static inline auto FFinalizeVelocity = PreyFunction<void(CPlayerStateJump* const _this, CPlayer& player, const Vec3& newVelocity)>(0x18E31B0);
	static inline auto FLand = PreyFunction<void(CPlayerStateJump* const _this, CPlayer& player, const bool isHeavyWeapon, float frameTime)>(0x18E36F0);
	static inline auto FLanded = PreyFunction<void(CPlayerStateJump* const _this, CPlayer& player, const bool isHeavyWeapon, float fallSpeed)>(0x18E3810);
	static inline auto FCalculateInAirJumpExtraVelocity = PreyFunction<const Vec3*(const CPlayerStateJump* const _this, const Vec3* _return_value_, const CPlayer& player, const Vec3& desiredVelocity)>(0x18E3000);
};
#endif // MOONCRASH
