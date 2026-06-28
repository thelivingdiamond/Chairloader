// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState.h>

struct ArkNpcDamageEnterStateParams;
struct ArkNpcDamageExitStateParams;
struct ArkNpcDamagePostSerializeStateParams;
struct ArkNpcDamageStateParam;

// ArkNpcDamageState_Undamaged
// Header:  Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState_Undamaged.h
class ArkNpcDamageState_Undamaged : public ArkNpcDamageState
{ // Size=1 (0x1)
public:
	void Enter(const ArkNpcDamageEnterStateParams& _params) const { FEnter(this, _params); }
	void Exit(const ArkNpcDamageExitStateParams& _params) const { FExit(this, _params); }
	void PostSerialize(const ArkNpcDamagePostSerializeStateParams& _params) const { FPostSerialize(this, _params); }

#if 0
	void EnterInternal(const ArkNpcDamageStateParam& _arg0_) const;
#endif

	static inline auto FEnter = PreyFunction<void(const ArkNpcDamageState_Undamaged* const _this, const ArkNpcDamageEnterStateParams& _params)>(0x12A2320);
	static inline auto FExit = PreyFunction<void(const ArkNpcDamageState_Undamaged* const _this, const ArkNpcDamageExitStateParams& _params)>(0x12A22F0);
	static inline auto FPostSerialize = PreyFunction<void(const ArkNpcDamageState_Undamaged* const _this, const ArkNpcDamagePostSerializeStateParams& _params)>(0x12A2320);
};
#endif // MOONCRASH
