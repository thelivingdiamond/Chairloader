// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_DoppelgangerLink;

// ArkNpcGameEffect_DoppelgangerLink
// Header:  Prey/GameDll/ark/npc/gameeffect/doppelgangerlink/ArkNpcGameEffect_DoppelgangerLink.h
class ArkNpcGameEffect_DoppelgangerLink : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>
{ // Size=8 (0x8)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_DoppelgangerLink();
	void MatchAttention(ArkNpc& _npcSeeingTarget, ArkNpc& _npcToShare, unsigned _targetEntityId) const { FMatchAttention(this, _npcSeeingTarget, _npcToShare, _targetEntityId); }

#if 0
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_, float _arg2_) const;
	void UpdateSharedAttention(ArkNpc& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12AB700);
	static inline auto FArkNpcGameEffect_DoppelgangerLink = PreyFunction<void(ArkNpcGameEffect_DoppelgangerLink* const _this)>(0x12AB6F0);
	static inline auto FMatchAttention = PreyFunction<void(const ArkNpcGameEffect_DoppelgangerLink* const _this, ArkNpc& _npcSeeingTarget, ArkNpc& _npcToShare, unsigned _targetEntityId)>(0x12AB820);
};
#endif // MOONCRASH
