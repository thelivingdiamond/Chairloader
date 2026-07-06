// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_NightmareEtherFormDamageAura;

// ArkNpcGameEffect_NightmareEtherFormDamageAura
// Header:  Prey/GameDll/ark/npc/gameeffect/nightmareetherformdamageaura/ArkNpcGameEffect_NightmareEtherFormDamageAura.h
class ArkNpcGameEffect_NightmareEtherFormDamageAura : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>
{ // Size=24 (0x18)
public:
	uint64_t m_auraPackageId;
	float m_auraTickRate;
	float m_auraRadius;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_NightmareEtherFormDamageAura();

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_, float _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_) const;
	void ApplyPackageTick(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B0670);
	static inline auto FArkNpcGameEffect_NightmareEtherFormDamageAura = PreyFunction<void(ArkNpcGameEffect_NightmareEtherFormDamageAura* const _this)>(0x12B0650);
};
#endif // MOONCRASH
