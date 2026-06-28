// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_PsiSuppression;

// ArkNpcGameEffect_PsiSuppression
// Header:  Prey/GameDll/ark/npc/gameeffect/psisuppression/ArkNpcGameEffect_PsiSuppression.h
class ArkNpcGameEffect_PsiSuppression : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>
{ // Size=8 (0x8)
public:
	static const char* ClassName() { return FClassName(); }
	void OnDied(ArkNpc& _npc, ArkNpcGameEffectInstance_PsiSuppression& _gameEffectInstance) const { FOnDied(this, _npc, _gameEffectInstance); }
	void OnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance_PsiSuppression& _gameEffectInstance) const { FOnAttached(this, _npc, _gameEffectInstance); }
	void OnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance_PsiSuppression& _gameEffectInstance) const { FOnDetached(this, _npc, _gameEffectInstance); }
	void PostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance_PsiSuppression& _gameEffectInstance) const { FPostSerialize(this, _npc, _gameEffectInstance); }

	static inline auto FClassName = PreyFunction<const char* ()>(0x1356FF0);
	static inline auto FOnDied = PreyFunction<void(const ArkNpcGameEffect_PsiSuppression* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_PsiSuppression& _gameEffectInstance)>(0x1357770);
	static inline auto FOnAttached = PreyFunction<void(const ArkNpcGameEffect_PsiSuppression* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_PsiSuppression& _gameEffectInstance)>(0x1357000);
	static inline auto FOnDetached = PreyFunction<void(const ArkNpcGameEffect_PsiSuppression* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_PsiSuppression& _gameEffectInstance)>(0x1357070);
	static inline auto FPostSerialize = PreyFunction<void(const ArkNpcGameEffect_PsiSuppression* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_PsiSuppression& _gameEffectInstance)>(0x1357090);
};
#endif // MOONCRASH
