// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_PoltergeistInvisibility;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
enum class EArkPoltergeistVisibilityState;
struct HitInfo;

// ArkNpcGameEffect_PoltergeistInvisibility
// Header:  Prey/GameDll/ark/npc/gameeffect/poltergeist/ArkNpcGameEffect_PoltergeistInvisibility.h
class ArkNpcGameEffect_PoltergeistInvisibility : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>
{ // Size=64 (0x40)
public:
	float m_visibleTimeAfterHit;
	float m_visibleTimeAfterGloo;
	float m_visibleTimeAfterStun;
	float m_visibleAfterHitCapTime;
	float m_visibleAfterHitCooldown;
	string m_appearAudioTrigger;
	string m_disappearAudioTrigger;
	string m_glitchEffectName;
	uint64_t m_glooSignalId;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_PoltergeistInvisibility();
	void OnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance) const { FOnAttached(this, _npc, _gameEffectInstance); }
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance, float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }
	void AbilityAppear(ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance) const { FAbilityAppear(this, _npc, _gameEffectInstance); }
	void AbilityDisappear(ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance) const { FAbilityDisappear(this, _npc, _gameEffectInstance); }
	bool IsVisible(const ArkNpc& _npc, const ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance) const { return FIsVisible(this, _npc, _gameEffectInstance); }
	void SetVisibilityState(ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance, EArkPoltergeistVisibilityState _state) const { FSetVisibilityState(this, _npc, _gameEffectInstance, _state); }

#if 0
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_) const;
	void SetVisibility(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_, bool _arg2_) const;
	void OnGlooed(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_) const;
	void OnStunned(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_) const;
	void IncrementGlitchCounter(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_) const;
	void DecrementGlitchCounter(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1356400);
	static inline auto FArkNpcGameEffect_PoltergeistInvisibility = PreyFunction<void(ArkNpcGameEffect_PoltergeistInvisibility* const _this)>(0x1356230);
	static inline auto FOnAttached = PreyFunction<void(const ArkNpcGameEffect_PoltergeistInvisibility* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance)>(0x1356720);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_PoltergeistInvisibility* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance, float _elapsedTime)>(0x1356BA0);
	static inline auto FAbilityAppear = PreyFunction<void(const ArkNpcGameEffect_PoltergeistInvisibility* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance)>(0x1356330);
	static inline auto FAbilityDisappear = PreyFunction<void(const ArkNpcGameEffect_PoltergeistInvisibility* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance)>(0x1356390);
	static inline auto FIsVisible = PreyFunction<bool(const ArkNpcGameEffect_PoltergeistInvisibility* const _this, const ArkNpc& _npc, const ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance)>(0x1356700);
	static inline auto FSetVisibilityState = PreyFunction<void(const ArkNpcGameEffect_PoltergeistInvisibility* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistInvisibility& _gameEffectInstance, EArkPoltergeistVisibilityState _state)>(0x1356880);
};
#endif // MOONCRASH
