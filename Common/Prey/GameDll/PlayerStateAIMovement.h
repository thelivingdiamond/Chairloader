// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/PlayerStateDead.h>
#include <Prey/GameDll/PlayerStateGround.h>
#include <Prey/GameDll/PlayerStateJump.h>
#include <Prey/GameDll/PlayerStateSwim.h>
#include <Prey/GameDll/ark/player/ArkPlayerStateHover.h>
#include <Prey/GameDll/state.h>
#include <_unknown/CStateMachineRegistration.h>

class CPlayer;
enum class EStance;
struct SInputEventData;
struct SPlayerPrePhysicsData;
struct SStateEvent;

// CPlayerStateAIMovement
// Header:  Prey/GameDll/PlayerStateAIMovement.h
class CPlayerStateAIMovement : private CStateHierarchy<CPlayer>
{ // Size=1024 (0x400)
public:
	unsigned m_subStateIndex;
	SStateIndex<CPlayer> State_MovementRoot;
	SStateIndex<CPlayer> State_Movement;
	SStateIndex<CPlayer> State_Dead;
	SStateIndex<CPlayer> State_Ground;
	SStateIndex<CPlayer> State_Fall;
	SStateIndex<CPlayer> State_Jump;
	SStateIndex<CPlayer> State_Swim;
	SStateIndex<CPlayer> State_SwimTest;
	SStateIndex<CPlayer> State_Hover;
	SStateIndex<CPlayer> State_Inert;
	SStateIndex<CPlayer> State_NoMovement;
	SStateIndex<CPlayer> State_Root;
	CPlayerStateDead m_stateDead;
	CPlayerStateGround m_stateGround;
	CPlayerStateJump m_stateJump;
	CPlayerStateSwim m_stateSwim;
	CArkPlayerStateHover m_stateHover;

	CPlayerStateAIMovement(CStateMachineRegistration<CPlayer>& stateMachineReg);
	static CStateHierarchy<CPlayer>* Create(CStateMachineRegistration<CPlayer>& stateMachineReg) { return FCreate(stateMachineReg); }
	static void Delete(CStateHierarchy<CPlayer>* & pState) { FDelete(pState); }
	const SStateIndex<CPlayer> MovementRoot(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FMovementRoot(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Movement(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FMovement(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Dead(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FDead(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Ground(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FGround(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Fall(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FFall(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Jump(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FJump(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Swim(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FSwim(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> SwimTest(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FSwimTest(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Hover(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FHover(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Inert(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FInert(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Root(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FRoot(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	void ProcessSprint(const CPlayer& player, const SPlayerPrePhysicsData& prePhysicsEvent) { FProcessSprint(this, player, prePhysicsEvent); }
	bool UseHoverMovementState(EStance _stance) { return FUseHoverMovementState(this, _stance); }

#if 0
	static unsigned Register();
	static void UnRegister();
	const SStateIndex<CPlayer> StateGroundInput(CPlayer& _arg0_, const SInputEventData& _arg1_);
	void StateSprintInput(CPlayer& _arg0_, const SInputEventData& _arg1_);
#endif

	static inline auto FCPlayerStateAIMovement = PreyFunction<void(CPlayerStateAIMovement* const _this, CStateMachineRegistration<CPlayer>& stateMachineReg)>(0x18DEB70);
	static inline auto FCreate = PreyFunction<CStateHierarchy<CPlayer>* (CStateMachineRegistration<CPlayer>& stateMachineReg)>(0x18DF980);
	static inline auto FDelete = PreyFunction<void(CStateHierarchy<CPlayer>* & pState)>(0x18E6C30);
	static inline auto FMovementRoot = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAIMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E0940);
	static inline auto FMovement = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAIMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E0780);
	static inline auto FDead = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAIMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18DF9B0);
	static inline auto FGround = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAIMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18DFDD0);
	static inline auto FFall = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAIMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18DFB60);
	static inline auto FJump = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAIMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E0540);
	static inline auto FSwim = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAIMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E0AF0);
	static inline auto FSwimTest = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAIMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E0C80);
	static inline auto FHover = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAIMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E0150);
	static inline auto FInert = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAIMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E0490);
	static inline auto FRoot = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAIMovement* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E0A70);
	static inline auto FProcessSprint = PreyFunction<void(CPlayerStateAIMovement* const _this, const CPlayer& player, const SPlayerPrePhysicsData& prePhysicsEvent)>(0x18E09B0);
	static inline auto FUseHoverMovementState = PreyFunction<bool(CPlayerStateAIMovement* const _this, EStance _stance)>(0x18E0D60);
};
#endif // MOONCRASH
