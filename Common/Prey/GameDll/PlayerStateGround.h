// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CPlayer;
struct SActorFrameMovementParams;

// CPlayerStateGround
// Header:  Prey/GameDll/PlayerStateGround.h
class CPlayerStateGround
{ // Size=1 (0x1)
public:
	bool m_inertiaIsZero;

	CPlayerStateGround();
	void OnEnter(CPlayer& player) { FOnEnter(this, player); }
	void OnPrePhysicsUpdate(CPlayer& player, const SActorFrameMovementParams& movement, float frameTime, const bool isHeavyWeapon, const bool isPlayer) { FOnPrePhysicsUpdate(this, player, movement, frameTime, isHeavyWeapon, isPlayer); }
	void OnExit(CPlayer& player) { FOnExit(this, player); }

#if 0
	void OnUpdate(CPlayer& _arg0_, float _arg1_);
	bool CheckForVaultTrigger(CPlayer& _arg0_, float _arg1_);
#endif

	static inline auto FCPlayerStateGround = PreyFunction<void(CPlayerStateGround* const _this)>(0x18E26C0);
	static inline auto FOnEnter = PreyFunction<void(CPlayerStateGround* const _this, CPlayer& player)>(0x18E26D0);
	static inline auto FOnPrePhysicsUpdate = PreyFunction<void(CPlayerStateGround* const _this, CPlayer& player, const SActorFrameMovementParams& movement, float frameTime, const bool isHeavyWeapon, const bool isPlayer)>(0x18E2710);
	static inline auto FOnExit = PreyFunction<void(CPlayerStateGround* const _this, CPlayer& player)>(0x1333E90);
};
#endif // MOONCRASH
