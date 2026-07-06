// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_FastTurnOnDamage;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffect_FastTurnOnDamage
// Header:  Prey/GameDll/ark/npc/gameeffect/fastturnondamage/ArkNpcGameEffect_FastTurnOnDamage.h
class ArkNpcGameEffect_FastTurnOnDamage : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>
{ // Size=32 (0x20)
public:
	float m_fastTurnDamageThreshold;
	float m_fastTurnDamageSampleTime;
	float m_fastTurnDuration;
	float m_fastTurnCooldownDuration;
	float m_fastTurnSpeed;
	float m_fastTurnStopOnReachedTargetThresholdAngle;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_FastTurnOnDamage();
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_FastTurnOnDamage& _gameEffectInstance, const float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_) const;
	void Start(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_, bool _arg2_) const;
	void Stop(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12AC590);
	static inline auto FArkNpcGameEffect_FastTurnOnDamage = PreyFunction<void(ArkNpcGameEffect_FastTurnOnDamage* const _this)>(0x12AC4D0);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_FastTurnOnDamage* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_FastTurnOnDamage& _gameEffectInstance, const float _elapsedTime)>(0x12AC830);
};
#endif // MOONCRASH
