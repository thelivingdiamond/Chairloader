// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/PlayerStateDead.h>
#include <Prey/GameDll/PlayerStateFly.h>
#include <Prey/GameDll/PlayerStateGround.h>
#include <Prey/GameDll/PlayerStateJump.h>
#include <Prey/GameDll/PlayerStateLedge.h>
#include <Prey/GameDll/PlayerStateSwim.h>
#include <Prey/GameDll/state.h>
#include <_unknown/CStateMachineRegistration.h>
#include <_unknown/IPlayerEventListener.h>

class CPlayer;
struct SInputEventData;
struct SPlayerPrePhysicsData;
struct SStateEvent;

// CPlayerStateMovement
// Header:  Prey/GameDll/PlayerStateMovement.h
class CPlayerStateMovement : private CStateHierarchy<CPlayer>
{ // Size=1384 (0x568)
public:
	unsigned m_subStateIndex;
	SStateIndex<CPlayer> State_MovementRoot;
	SStateIndex<CPlayer> State_GroundMovement;
	SStateIndex<CPlayer> State_Dead;
	SStateIndex<CPlayer> State_Fly;
	SStateIndex<CPlayer> State_Ground;
	SStateIndex<CPlayer> State_GroundFall;
	SStateIndex<CPlayer> State_FallTest;
	SStateIndex<CPlayer> State_Jump;
	SStateIndex<CPlayer> State_Fall;
	SStateIndex<CPlayer> State_Slide;
	SStateIndex<CPlayer> State_SlideFall;
	SStateIndex<CPlayer> State_Swim;
	SStateIndex<CPlayer> State_Spectate;
	SStateIndex<CPlayer> State_Intro;
	SStateIndex<CPlayer> State_Ledge;
	SStateIndex<CPlayer> State_Ladder;
	SStateIndex<CPlayer> State_SwimTest;
	SStateIndex<CPlayer> State_NoMovement;
	SStateIndex<CPlayer> State_GroundFallTest;
	SStateIndex<CPlayer> State_SlideFallTest;
	SStateIndex<CPlayer> State_Root;
	CPlayerStateDead m_stateDead;
	CPlayerStateFly m_stateFly;
	CPlayerStateGround m_stateGround;
	CPlayerStateJump m_stateJump;
	CPlayerStateSwim m_stateSwim;
	CPlayerStateSpectate m_stateSpectate;
	CPlayerStateLedge m_statePlayerLedge;

	CPlayerStateMovement(CStateMachineRegistration<CPlayer>& stateMachineReg);
	static CStateHierarchy<CPlayer>* Create(CStateMachineRegistration<CPlayer>& stateMachineReg) { return FCreate(stateMachineReg); }
	static void Delete(CStateHierarchy<CPlayer>* & pState) { FDelete(pState); }
	const SStateIndex<CPlayer> MovementRoot(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FMovementRoot(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> GroundMovement(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FGroundMovement(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Dead(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FDead(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Fly(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FFly(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Ground(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FGround(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> GroundFall(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FGroundFall(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> FallTest(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FFallTest(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Jump(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FJump(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Fall(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FFall(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Slide(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FSlide(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> SlideFall(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FSlideFall(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Swim(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FSwim(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Spectate(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FSpectate(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Intro(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FIntro(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Ledge(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FLedge(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Ladder(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FLadder(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> SwimTest(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FSwimTest(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Root(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FRoot(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> StateGroundInput(CPlayer& player, const SInputEventData& inputEvent) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FStateGroundInput(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, inputEvent); }
	void ProcessSprint(CPlayer& player, const SPlayerPrePhysicsData& prePhysicsEvent) { FProcessSprint(this, player, prePhysicsEvent); }

#if 0
	static unsigned Register();
	static void UnRegister();
	void StateSprintInput(CPlayer& _arg0_, const SInputEventData& _arg1_);
	void OnSpecialMove(CPlayer& _arg0_, IPlayerEventListener::ESpecialMove _arg1_);
	bool IsActionControllerValid(CPlayer& _arg0_) const;
	void CreateWaterEffects();
	void ReleaseWaterEffects();
	void TriggerOutOfWaterEffectIfNeeded(const CPlayer& _arg0_);
	void UpdatePlayerStanceTag(CPlayer& _arg0_);
#endif

	static inline auto FCPlayerStateMovement = PreyFunction<void(CPlayerStateMovement* const _this, CStateMachineRegistration<CPlayer>& stateMachineReg)>(0x18E5170);
	static inline auto FCreate = PreyFunction<CStateHierarchy<CPlayer>* (CStateMachineRegistration<CPlayer>& stateMachineReg)>(0x18E6A50);
	static inline auto FDelete = PreyFunction<void(CStateHierarchy<CPlayer>* & pState)>(0x18E6C30);
	static inline auto FMovementRoot = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E7DC0);
	static inline auto FGroundMovement = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E73E0);
	static inline auto FDead = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E6A80);
	static inline auto FFly = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E6EC0);
	static inline auto FGround = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E7070);
	static inline auto FGroundFall = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E7340);
	static inline auto FFallTest = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E6D30);
	static inline auto FJump = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E7670);
	static inline auto FFall = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E6C60);
	static inline auto FSlide = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E83B0);
	static inline auto FSlideFall = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E8600);
	static inline auto FSwim = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E8950);
	static inline auto FSpectate = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E86A0);
	static inline auto FIntro = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E75F0);
	static inline auto FLedge = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E79A0);
	static inline auto FLadder = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E78B0);
	static inline auto FSwimTest = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E8CE0);
	static inline auto FRoot = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E8110);
	static inline auto FStateGroundInput = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SInputEventData& inputEvent)>(0x18E8900);
	static inline auto FProcessSprint = PreyFunction<void(CPlayerStateMovement* const _this, CPlayer& player, const SPlayerPrePhysicsData& prePhysicsEvent)>(0x18E7FF0);
};
#endif // MOONCRASH
