// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkglooeffectutils.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>
#include <Prey/GameDll/ark/weapons/IArkGlooEffectObserver.h>
#include <_unknown/ArkNpcGameEffectInstance.h>

class ArkNpc;
class ArkNpcGameEffect_Gloo;
struct ArkNpcSignalAccumulator;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffectInstance_Gloo
// Header:  Prey/GameDll/ark/npc/gameeffect/glooslow/ArkNpcGameEffect_Gloo.h
struct ArkNpcGameEffectInstance_Gloo : public ArkNpcGameEffectInstance, public IArkGlooEffectObserver
{ // Size=552 (0x228)
	enum class EFrozenType
	{
		normal = 0,
		rigid = 1,
		ragdoll = 2,
	};

	ArkGlooEffectAccumulated m_glooEffects;
	ArkNpc* m_pNpc;
	const ArkNpcGameEffect_Gloo* m_pGameEffect;
	ArkNpcMovementDesire m_gooedMoveDesire;
	unsigned m_glooInstigatorId;
	ArkNpcGameEffectInstance_Gloo::EFrozenType m_frozenType;
	int m_postSerializePoseOptionIndex;
	bool m_bBreakTriggerPlayed;
	bool m_bPostSerializeFrameDelay;
	bool m_bAbilitiesDisabled;

	virtual void OnGlooBroken();
	virtual void OnGlooHardenStart();

#if 0
	ArkNpcGameEffectInstance_Gloo();
#endif

	static inline auto FOnGlooBroken = PreyFunction<void(IArkGlooEffectObserver* const _this)>(0x12AE1F0);
	static inline auto FOnGlooHardenStart = PreyFunction<void(IArkGlooEffectObserver* const _this)>(0x12AE390);
};

// ArkNpcGameEffect_Gloo
// Header:  Prey/GameDll/ark/npc/gameeffect/glooslow/ArkNpcGameEffect_Gloo.h
class ArkNpcGameEffect_Gloo : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>
{ // Size=48 (0x30)
public:
	ArkAudioTrigger m_glooBreakBuildupTrigger;
	ArkAudioTrigger m_glooHitTrigger;
	uint64_t m_glooSignalModifier;
	uint64_t m_glooSignalId;
	float m_glooGrowAccumulationSpeedPerSecond;
	float m_glooLowerThresholdPreBreakSfxTime;
	float m_glooPartialPercentageToCancelAbilities;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Gloo();
	void OnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance_Gloo& _gameEffectInstance, const ArkSignalSystem::Package& _package) const { FOnReceiveSignal(this, _npc, _gameEffectInstance, _package); }
	void SkipSlow(ArkNpc& _npc, ArkNpcGameEffectInstance_Gloo& _gameEffectInstance) const { FSkipSlow(this, _npc, _gameEffectInstance); }
	void InternalStart(ArkNpc& _npc, ArkNpcGameEffectInstance_Gloo& _gameEffectInstance) const { FInternalStart(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_, const float _arg2_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
	ArkNpcSignalAccumulator* GetGlooSignalAccumulator(ArkNpc& _arg0_) const;
	void UpdateAbilityInterruption(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
	void TryEnableAbilities(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
	void TryDisableAbilities(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12ADAD0);
	static inline auto FArkNpcGameEffect_Gloo = PreyFunction<void(ArkNpcGameEffect_Gloo* const _this)>(0x12ADA20);
	static inline auto FOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffect_Gloo* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Gloo& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x12AE720);
	static inline auto FSkipSlow = PreyFunction<void(const ArkNpcGameEffect_Gloo* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Gloo& _gameEffectInstance)>(0x12AE990);
	static inline auto FInternalStart = PreyFunction<void(const ArkNpcGameEffect_Gloo* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Gloo& _gameEffectInstance)>(0x12AE180);
};
#endif // MOONCRASH
