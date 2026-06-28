// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/state.h>
#include <_unknown/CStateMachineRegistration.h>

class CPlayer;
struct SStateEvent;

// CPlayerStateLinked
// Header:  Prey/GameDll/PlayerStateLinked.h
class CPlayerStateLinked : public CStateHierarchy<CPlayer>
{ // Size=416 (0x1A0)
public:
	unsigned m_subStateIndex;
	SStateIndex<CPlayer> State_Enter;
	SStateIndex<CPlayer> State_Entity;
	SStateIndex<CPlayer> State_Root;

	CPlayerStateLinked(CStateMachineRegistration<CPlayer>& stateMachineReg);
	static CStateHierarchy<CPlayer>* Create(CStateMachineRegistration<CPlayer>& stateMachineReg) { return FCreate(stateMachineReg); }
	static void Delete(CStateHierarchy<CPlayer>* & pState) { FDelete(pState); }
	const SStateIndex<CPlayer> Enter(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FEnter(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Entity(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FEntity(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }
	const SStateIndex<CPlayer> Root(CPlayer& player, const SStateEvent& event) { alignas(const SStateIndex<CPlayer>) std::byte _return_buf_[sizeof(const SStateIndex<CPlayer>)]; return *FRoot(this, reinterpret_cast<const SStateIndex<CPlayer>*>(_return_buf_), player, event); }

#if 0
	static unsigned Register();
	static void UnRegister();
#endif

	static inline auto FCPlayerStateLinked = PreyFunction<void(CPlayerStateLinked* const _this, CStateMachineRegistration<CPlayer>& stateMachineReg)>(0x18E4BA0);
	static inline auto FCreate = PreyFunction<CStateHierarchy<CPlayer>* (CStateMachineRegistration<CPlayer>& stateMachineReg)>(0x18E4FC0);
	static inline auto FDelete = PreyFunction<void(CStateHierarchy<CPlayer>* & pState)>(0x18E6C30);
	static inline auto FEnter = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateLinked* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E4FF0);
	static inline auto FEntity = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateLinked* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E1870);
	static inline auto FRoot = PreyFunction<const SStateIndex<CPlayer>*(CPlayerStateLinked* const _this, const SStateIndex<CPlayer>* _return_value_, CPlayer& player, const SStateEvent& event)>(0x18E5060);
};
#endif // MOONCRASH
