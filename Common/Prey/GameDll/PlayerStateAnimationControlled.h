// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/state.h>
#include <_unknown/CStateMachineRegistration.h>

class CPlayer;
struct SStateEvent;

// CPlayerStateAnimationControlled
// Header:  Prey/GameDll/PlayerStateAnimationControlled.h
class CPlayerStateAnimationControlled : public CStateHierarchy<CPlayer>
{ // Size=496 (0x1F0)
public:
	unsigned m_subStateIndex;
	SStateIndex<CPlayer> State_EntryChoice;
	SStateIndex<CPlayer> State_InteractiveAction;
	SStateIndex<CPlayer> State_StealthKill;
	SStateIndex<CPlayer> State_CutScene;
	SStateIndex<CPlayer> State_Root;

	CPlayerStateAnimationControlled(CStateMachineRegistration<CPlayer>& stateMachineReg);
	static CStateHierarchy<CPlayer>* Create(CStateMachineRegistration<CPlayer>& stateMachineReg) { return FCreate(stateMachineReg); }
	static void Delete(CStateHierarchy<CPlayer>* & pState) { FDelete(pState); }
	const SStateIndex<CPlayer> EntryChoice(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FEntryChoice(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> InteractiveAction(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FInteractiveAction(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> StealthKill(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FStealthKill(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> CutScene(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FCutScene(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Root(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FRoot(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }

#if 0
	static unsigned Register();
	static void UnRegister();
#endif

	static inline auto FCPlayerStateAnimationControlled = PreyFunction<void(CPlayerStateAnimationControlled* const _this, CStateMachineRegistration<CPlayer>& stateMachineReg)>(0x18E0D90);
	static inline auto FCreate = PreyFunction<CStateHierarchy<CPlayer>* (CStateMachineRegistration<CPlayer>& stateMachineReg)>(0x18E13F0);
	static inline auto FDelete = PreyFunction<void(CStateHierarchy<CPlayer>* & pState)>(0x18E6C30);
	static inline auto FEntryChoice = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAnimationControlled* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E14D0);
	static inline auto FInteractiveAction = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAnimationControlled* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E1590);
	static inline auto FStealthKill = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAnimationControlled* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E18B0);
	static inline auto FCutScene = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAnimationControlled* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E1420);
	static inline auto FRoot = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateAnimationControlled* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E1870);
};
#endif // MOONCRASH
