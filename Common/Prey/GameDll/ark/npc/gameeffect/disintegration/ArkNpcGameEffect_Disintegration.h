// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_Disintegration;

// ArkNpcGameEffect_Disintegration
// Header:  Prey/GameDll/ark/npc/gameeffect/disintegration/ArkNpcGameEffect_Disintegration.h
class ArkNpcGameEffect_Disintegration : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>
{ // Size=8 (0x8)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Disintegration();

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_, float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12AB550);
	static inline auto FArkNpcGameEffect_Disintegration = PreyFunction<void(ArkNpcGameEffect_Disintegration* const _this)>(0x12AB540);
};
#endif // MOONCRASH
