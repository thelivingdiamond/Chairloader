// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_Frenzy;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffect_Frenzy
// Header:  Prey/GameDll/ark/npc/gameeffect/frenzy/ArkNpcGameEffect_Frenzy.h
class ArkNpcGameEffect_Frenzy : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>
{ // Size=40 (0x28)
public:
	bool m_bExplodesAfterFrenzyDuration;
	float m_frenzyDurationBeforeDeath;
	float m_healthPercentNeededForFrenzy;
	uint64_t m_frenzyAbilityContextId;
	uint64_t m_frenziedContextProfileId;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Frenzy();
	bool IsFrenzied(const ArkNpc& _npc, ArkNpcGameEffectInstance_Frenzy& _gameEffectInstance) const { return FIsFrenzied(this, _npc, _gameEffectInstance); }
	void FinishTransitionToFrenzy(ArkNpc& _npc, ArkNpcGameEffectInstance_Frenzy& _gameEffectInstance) const { FFinishTransitionToFrenzy(this, _npc, _gameEffectInstance); }
	void SetAbilityContextProfile(ArkNpc& _npc, const uint64_t& _contextProfileId) const { FSetAbilityContextProfile(this, _npc, _contextProfileId); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_, float _arg2_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_) const;
	void StartSwitchToFrenzyState(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_) const;
	void InternalStart(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_, bool _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12AD6C0);
	static inline auto FArkNpcGameEffect_Frenzy = PreyFunction<void(ArkNpcGameEffect_Frenzy* const _this)>(0x12AD6A0);
	static inline auto FIsFrenzied = PreyFunction<bool(const ArkNpcGameEffect_Frenzy* const _this, const ArkNpc& _npc, ArkNpcGameEffectInstance_Frenzy& _gameEffectInstance)>(0x12AD9A0);
	static inline auto FFinishTransitionToFrenzy = PreyFunction<void(const ArkNpcGameEffect_Frenzy* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Frenzy& _gameEffectInstance)>(0x12AD990);
	static inline auto FSetAbilityContextProfile = PreyFunction<void(const ArkNpcGameEffect_Frenzy* const _this, ArkNpc& _npc, const uint64_t& _contextProfileId)>(0x12AD9B0);
};
#endif // MOONCRASH
