// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_EthericFog;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffect_EthericFog
// Header:  Prey/GameDll/ark/npc/gameeffect/ethericfog/ArkNpcGameEffect_EthericFog.h
class ArkNpcGameEffect_EthericFog : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>
{ // Size=16 (0x10)
public:
	float m_fogSpawnCooldown;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_EthericFog();
	bool TrySpawnEthericFogEffect(const ArkNpc& _npc, const bool _bIsSmallFragment) const { return FTrySpawnEthericFogEffect(this, _npc, _bIsSmallFragment); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_, float _arg2_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_, TSerialize _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1354500);
	static inline auto FArkNpcGameEffect_EthericFog = PreyFunction<void(ArkNpcGameEffect_EthericFog* const _this)>(0x13544E0);
	static inline auto FTrySpawnEthericFogEffect = PreyFunction<bool(const ArkNpcGameEffect_EthericFog* const _this, const ArkNpc& _npc, const bool _bIsSmallFragment)>(0x13545D0);
};
#endif // MOONCRASH
