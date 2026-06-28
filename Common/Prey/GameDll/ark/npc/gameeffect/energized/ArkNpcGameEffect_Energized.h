// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_Energized;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// ArkNpcGameEffect_Energized
// Header:  Prey/GameDll/ark/npc/gameeffect/energized/ArkNpcGameEffect_Energized.h
class ArkNpcGameEffect_Energized : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>
{ // Size=56 (0x38)
public:
	uint64_t m_energizingSignalId;
	float m_drainPerSecond;
	float m_delayBeforeDrain;
	uint64_t m_energizedExplosionPackageId;
	uint64_t m_energizedExplosionCameraShakeId;
	float m_energizedExplosionRadius;
	float m_energizedExplosionImpulse;
	float m_energizedNeededForHostility;
	bool m_bGoHostileToEnergize;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Energized();
	void OnEnergizedExplosion(ArkNpc& _npc, ArkNpcGameEffectInstance_Energized& _gameEffectInstance) const { FOnEnergizedExplosion(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_, const float _arg2_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_) const;
	void UpdateMaterialEffect(ArkNpc& _arg0_, float _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12AB930);
	static inline auto FArkNpcGameEffect_Energized = PreyFunction<void(ArkNpcGameEffect_Energized* const _this)>(0x12AB8D0);
	static inline auto FOnEnergizedExplosion = PreyFunction<void(const ArkNpcGameEffect_Energized* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Energized& _gameEffectInstance)>(0x12ABE60);
};
#endif // MOONCRASH
