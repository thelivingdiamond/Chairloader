// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CPlayer;
struct IItem;
struct SActorFrameMovementParams;
struct SActorPhysics;
struct SCharacterMoveRequest;
struct SStateEvent;
struct pe_status_living;

// CPlayerStateUtil
// Header:  Prey/GameDll/PlayerStateUtil.h
class CPlayerStateUtil
{ // Size=1 (0x1)
public:
	static void CalculateGroundOrJumpMovement(const CPlayer& player, const SActorFrameMovementParams& movement, const bool bigWeaponRestrict, Vec3& move, bool _bAllowJumpZMove) { FCalculateGroundOrJumpMovement(player, movement, bigWeaponRestrict, move, _bAllowJumpZMove); }
	static bool IsOnGround(CPlayer& player) { return FIsOnGround(player); }
	static void PhySetFly(CPlayer& player) { FPhySetFly(player); }
	static void PhySetNoFly(CPlayer& player, const Vec3& gravity) { FPhySetNoFly(player, gravity); }
	static bool ShouldJump(CPlayer& player, const SActorFrameMovementParams& movement) { return FShouldJump(player, movement); }
	static void RestorePlayerPhysics(CPlayer& player) { FRestorePlayerPhysics(player); }
	static void UpdatePlayerPhysicsStats(CPlayer& player, SActorPhysics& actorPhysics, float frameTime) { FUpdatePlayerPhysicsStats(player, actorPhysics, frameTime); }
	static void ProcessTurning(CPlayer& player, float frameTime) { FProcessTurning(player, frameTime); }
	static void InitializeMoveRequest(SCharacterMoveRequest& frameRequest) { FInitializeMoveRequest(frameRequest); }
	static void FinalizeMovementRequest(CPlayer& player, const SActorFrameMovementParams& movement, SCharacterMoveRequest& request) { FFinalizeMovementRequest(player, movement, request); }
	static bool ShouldSprint(const CPlayer& player, const SActorFrameMovementParams& movement, IItem* pCurrentPlayerItem) { return FShouldSprint(player, movement, pCurrentPlayerItem); }
	static void ApplyFallDamage(CPlayer& player, const float startFallingHeight, const float fHeightofEntity) { FApplyFallDamage(player, startFallingHeight, fHeightofEntity); }
	static void ChangeStance(CPlayer& player, const SStateEvent& event) { FChangeStance(player, event); }

#if 0
	static bool GetPhysicsLivingStat(const CPlayer& _arg0_, pe_status_living* _arg1_);
	static void AdjustMovementForEnvironment(const CPlayer& _arg0_, Vec3& _arg1_, const bool _arg2_, const bool _arg3_);
	static void UpdateRemotePlayersInterpolation(CPlayer& _arg0_, const SActorFrameMovementParams& _arg1_, SCharacterMoveRequest& _arg2_);
	static bool IsMovingForward(const CPlayer& _arg0_, const SActorFrameMovementParams& _arg1_);
	static bool DoesArmorAbsorptFallDamage(CPlayer& _arg0_, const float _arg1_, float& _arg2_);
	static void CancelSneakAndProneInputs(CPlayer& _arg0_);
	CPlayerStateUtil();
	CPlayerStateUtil(const CPlayerStateUtil& _arg0_);
	CPlayerStateUtil& operator=(const CPlayerStateUtil& _arg0_);
#endif

	static inline auto FCalculateGroundOrJumpMovement = PreyFunction<void(const CPlayer& player, const SActorFrameMovementParams& movement, const bool bigWeaponRestrict, Vec3& move, bool _bAllowJumpZMove)>(0x18EB300);
	static inline auto FIsOnGround = PreyFunction<bool(CPlayer& player)>(0x18EB9F0);
	static inline auto FPhySetFly = PreyFunction<void(CPlayer& player)>(0x18EBA00);
	static inline auto FPhySetNoFly = PreyFunction<void(CPlayer& player, const Vec3& gravity)>(0x18EBAF0);
	static inline auto FShouldJump = PreyFunction<bool(CPlayer& player, const SActorFrameMovementParams& movement)>(0x18EBF20);
	static inline auto FRestorePlayerPhysics = PreyFunction<void(CPlayer& player)>(0x18EBE90);
	static inline auto FUpdatePlayerPhysicsStats = PreyFunction<void(CPlayer& player, SActorPhysics& actorPhysics, float frameTime)>(0x18EC0D0);
	static inline auto FProcessTurning = PreyFunction<void(CPlayer& player, float frameTime)>(0x18EBC10);
	static inline auto FInitializeMoveRequest = PreyFunction<void(SCharacterMoveRequest& frameRequest)>(0x18EB960);
	static inline auto FFinalizeMovementRequest = PreyFunction<void(CPlayer& player, const SActorFrameMovementParams& movement, SCharacterMoveRequest& request)>(0x18EB870);
	static inline auto FShouldSprint = PreyFunction<bool(const CPlayer& player, const SActorFrameMovementParams& movement, IItem* pCurrentPlayerItem)>(0x18EBF80);
	static inline auto FApplyFallDamage = PreyFunction<void(CPlayer& player, const float startFallingHeight, const float fHeightofEntity)>(0x18EB100);
	static inline auto FChangeStance = PreyFunction<void(CPlayer& player, const SStateEvent& event)>(0x18EB860);
};
#endif // MOONCRASH
