// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_Armored;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffect_Armored
// Header:  Prey/GameDll/ark/npc/gameeffect/armored/ArkNpcGameEffect_Armored.h
class ArkNpcGameEffect_Armored : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>
{ // Size=32 (0x20)
public:
	string m_armoredMaterial;
	string m_armoredSubMaterial;
	float m_armoredDamageScale;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Armored();
	void OnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance_Armored& _gameEffectInstance) const { FOnAttached(this, _npc, _gameEffectInstance); }

#if 0
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12A7940);
	static inline auto FArkNpcGameEffect_Armored = PreyFunction<void(ArkNpcGameEffect_Armored* const _this)>(0x12A78A0);
	static inline auto FOnAttached = PreyFunction<void(const ArkNpcGameEffect_Armored* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Armored& _gameEffectInstance)>(0x12A7A30);
};
#endif // MOONCRASH
