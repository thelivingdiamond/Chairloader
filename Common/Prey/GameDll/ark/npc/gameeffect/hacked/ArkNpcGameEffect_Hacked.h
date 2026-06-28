// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_Hacked;

// ArkNpcGameEffect_Hacked
// Header:  Prey/GameDll/ark/npc/gameeffect/hacked/ArkNpcGameEffect_Hacked.h
class ArkNpcGameEffect_Hacked : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>
{ // Size=24 (0x18)
public:
	uint64_t m_hackedFaction;
	uint64_t m_hackedMetaTag;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Hacked();
	void InternalStart(ArkNpc& _npc, ArkNpcGameEffectInstance_Hacked& _gameEffectInstance) const { FInternalStart(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12AEA20);
	static inline auto FArkNpcGameEffect_Hacked = PreyFunction<void(ArkNpcGameEffect_Hacked* const _this)>(0x12AEA10);
	static inline auto FInternalStart = PreyFunction<void(const ArkNpcGameEffect_Hacked* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Hacked& _gameEffectInstance)>(0x12AEAF0);
};
#endif // MOONCRASH
