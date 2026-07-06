// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_PlayerControlled;

// ArkNpcGameEffect_PlayerControlled
// Header:  Prey/GameDll/ark/npc/gameeffect/playercontrolled/ArkNpcGameEffect_PlayerControlled.h
class ArkNpcGameEffect_PlayerControlled : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>
{ // Size=8 (0x8)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_PlayerControlled();

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B1660);
	static inline auto FArkNpcGameEffect_PlayerControlled = PreyFunction<void(ArkNpcGameEffect_PlayerControlled* const _this)>(0x12B1650);
};
#endif // MOONCRASH
