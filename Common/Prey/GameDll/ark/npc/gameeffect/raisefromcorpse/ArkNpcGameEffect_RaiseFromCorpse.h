// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_RaiseFromCorpse;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// ArkNpcGameEffect_RaiseFromCorpse
// Header:  Prey/GameDll/ark/npc/gameeffect/raisefromcorpse/ArkNpcGameEffect_RaiseFromCorpse.h
class ArkNpcGameEffect_RaiseFromCorpse : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>
{ // Size=24 (0x18)
public:
	float m_minRagdollTime;
	float m_maxRagdollTime;
	uint64_t m_breakOutSignalGroupId;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_RaiseFromCorpse();

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_, float _arg2_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B1A60);
	static inline auto FArkNpcGameEffect_RaiseFromCorpse = PreyFunction<void(ArkNpcGameEffect_RaiseFromCorpse* const _this)>(0x12B1A40);
};
#endif // MOONCRASH
