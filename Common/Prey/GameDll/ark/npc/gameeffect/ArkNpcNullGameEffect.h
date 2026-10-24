// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

// ArkNpcNullGameEffect
// Header:  Prey/GameDll/ark/npc/gameeffect/ArkNpcNullGameEffect.h
class ArkNpcNullGameEffect : public ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>
{ // Size=8 (0x8)
public:
	static const char* ClassName() { return FClassName(); }

#if 0
	ArkNpcNullGameEffect();
#endif

#ifndef MOONCRASH
	static inline auto FClassName = PreyFunction<const char* ()>(0x1218230);
#else
	static inline auto FClassName = PreyFunction<const char* ()>(0x12A7890);
#endif
};

