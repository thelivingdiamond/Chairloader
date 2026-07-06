// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/state.h>
#include <_unknown/CStateMachineRegistration.h>

class CPlayer;
struct SStateEvent;

// CPlayerStateEntry
// Header:  Prey/GameDll/PlayerStateEntry.h
class CPlayerStateEntry : private CStateHierarchy<CPlayer>
{ // Size=336 (0x150)
public:
	unsigned m_subStateIndex;
	SStateIndex<CPlayer> State_Root;

	static CStateHierarchy<CPlayer>* Create(CStateMachineRegistration<CPlayer>& stateMachineReg) { return FCreate(stateMachineReg); }
	static void Delete(CStateHierarchy<CPlayer>* & pState) { FDelete(pState); }
	const SStateIndex<CPlayer> Root(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FRoot(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }

#if 0
	CPlayerStateEntry(CStateMachineRegistration<CPlayer>& _arg0_);
	static unsigned Register();
	static void UnRegister();
#endif

	static inline auto FCreate = PreyFunction<CStateHierarchy<CPlayer>* (CStateMachineRegistration<CPlayer>& stateMachineReg)>(0x18E1DD0);
	static inline auto FDelete = PreyFunction<void(CStateHierarchy<CPlayer>* & pState)>(0x18E6C30);
	static inline auto FRoot = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateEntry* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E1F70);
};
#endif // MOONCRASH
