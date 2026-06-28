// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_OnFire;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// ArkNpcGameEffect_OnFire
// Header:  Prey/GameDll/ark/npc/gameeffect/onfire/ArkNpcGameEffect_OnFire.h
class ArkNpcGameEffect_OnFire : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>
{ // Size=56 (0x38)
public:
	float m_onFireTime;
	float m_damageTickRate;
	uint64_t m_fireDamagePackageId;
	uint64_t m_instigatingSignalGroup;
	bool m_bFleesWhenIgnited;
	uint64_t m_aoePackageId;
	float m_aoeRadiusFromNpc;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_OnFire();
	void ApplyDamageOverTime(ArkNpc& _npc, ArkNpcGameEffectInstance_OnFire& _gameEffectInstance) const { FApplyDamageOverTime(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_, float _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_) const;
	void IgniteNpc(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B0A70);
	static inline auto FArkNpcGameEffect_OnFire = PreyFunction<void(ArkNpcGameEffect_OnFire* const _this)>(0x12B07E0);
	static inline auto FApplyDamageOverTime = PreyFunction<void(const ArkNpcGameEffect_OnFire* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_OnFire& _gameEffectInstance)>(0x12B0840);
};
#endif // MOONCRASH
