// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_Corrupted;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// ArkNpcGameEffect_Corrupted
// Header:  Prey/GameDll/ark/npc/gameeffect/corrupted/ArkNpcGameEffect_Corrupted.h
class ArkNpcGameEffect_Corrupted : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>
{ // Size=120 (0x78)
public:
	uint64_t m_corruptedFactionId;
	uint64_t m_corruptedMetaTag;
	uint64_t m_corruptedContextProfileId;
	uint64_t m_corruptedSignalModifierId;
	uint64_t m_instantKillSignalGroupId;
	uint64_t m_uncorruptOnSignalGroupId;
	uint64_t m_playerDeprogrammingSignalId;
	string m_corruptedExplodeDamageSourceAttachment;
	uint64_t m_corruptedExplodeOnDeathPackageId;
	uint64_t m_corruptedExplodeOnDeathCameraShakeId;
	float m_corruptedExplodeOnDeathRadius;
	float m_corruptedExplodeOnDeathImpulse;
	float m_corruptedExplodeMinimumDistanceScaleAmount;
	string m_corruptedAiTreePath;
	float m_healthMultiplier;
	bool m_bShouldExplodeHeadOnDeath;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Corrupted();
	void OnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance_Corrupted& _gameEffectInstance) const { FOnDetached(this, _npc, _gameEffectInstance); }
	void OnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance_Corrupted& _gameEffectInstance, const ArkSignalSystem::Package& _package) const { FOnReceiveSignal(this, _npc, _gameEffectInstance, _package); }
	void InternalStart(ArkNpc& _npc, ArkNpcGameEffectInstance_Corrupted& _gameEffectInstance) const { FInternalStart(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_, const float _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_) const;
	void SetAbilityContextProfile(ArkNpc& _arg0_, const uint64_t& _arg1_) const;
	void TryFollowCorruptionOwner(ArkNpc& _arg0_) const;
	void UpdateCorruptedTetherEffectTargets(ArkNpc& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12AAAA0);
	static inline auto FArkNpcGameEffect_Corrupted = PreyFunction<void(ArkNpcGameEffect_Corrupted* const _this)>(0x12AA970);
	static inline auto FOnDetached = PreyFunction<void(const ArkNpcGameEffect_Corrupted* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Corrupted& _gameEffectInstance)>(0x12AAFA0);
	static inline auto FOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffect_Corrupted* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Corrupted& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x12AB2D0);
	static inline auto FInternalStart = PreyFunction<void(const ArkNpcGameEffect_Corrupted* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Corrupted& _gameEffectInstance)>(0x12AAE20);
};
#endif // MOONCRASH
