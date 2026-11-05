// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState.h>

struct ArkNpcDamageEnterStateParams;
struct ArkNpcDamageExitStateParams;
struct ArkNpcDamagePostSerializeStateParams;
struct ArkNpcDamageStateParam;

// ArkNpcDamageState_Damaged
// Header:  Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState_Damaged.h
class ArkNpcDamageState_Damaged : public ArkNpcDamageState
{ // Size=1 (0x1)
public:
	void Enter(const ArkNpcDamageEnterStateParams& _params) const { FEnter(this, _params); }
	void Exit(const ArkNpcDamageExitStateParams& _params) const { FExit(this, _params); }
	void PostSerialize(const ArkNpcDamagePostSerializeStateParams& _params) const { FPostSerialize(this, _params); }

#if 0
	void EnterInternal(const ArkNpcDamageStateParam& _arg0_) const;
#endif

#ifndef MOONCRASH
	static inline auto FEnter = PreyFunction<void(const ArkNpcDamageState_Damaged* const _this, const ArkNpcDamageEnterStateParams& _params)>(0x1211B90);
	static inline auto FExit = PreyFunction<void(const ArkNpcDamageState_Damaged* const _this, const ArkNpcDamageExitStateParams& _params)>(0x1211BF0);
	static inline auto FPostSerialize = PreyFunction<void(const ArkNpcDamageState_Damaged* const _this, const ArkNpcDamagePostSerializeStateParams& _params)>(0x1211C40);
#else
	static inline auto FEnter = PreyFunction<void(const ArkNpcDamageState_Damaged* const _this, const ArkNpcDamageEnterStateParams& _params)>(0x12A0FD0);
	static inline auto FExit = PreyFunction<void(const ArkNpcDamageState_Damaged* const _this, const ArkNpcDamageExitStateParams& _params)>(0x12A1030);
	static inline auto FPostSerialize = PreyFunction<void(const ArkNpcDamageState_Damaged* const _this, const ArkNpcDamagePostSerializeStateParams& _params)>(0x12A1080);
#endif
};

