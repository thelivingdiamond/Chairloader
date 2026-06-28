// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_HitReactionMaterialAnimation;

// ArkNpcGameEffect_HitReactionMaterialAnimation
// Header:  Prey/GameDll/ark/npc/gameeffect/hitreactionmaterialanimation/ArkNpcGameEffect_HitReactionMaterialAnimation.h
class ArkNpcGameEffect_HitReactionMaterialAnimation : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>
{ // Size=16 (0x10)
public:
	ArkMaterialAnimationType m_materialAnimationType;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_HitReactionMaterialAnimation();

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_, const float _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12AEB90);
	static inline auto FArkNpcGameEffect_HitReactionMaterialAnimation = PreyFunction<void(ArkNpcGameEffect_HitReactionMaterialAnimation* const _this)>(0x12AEB80);
};
#endif // MOONCRASH
