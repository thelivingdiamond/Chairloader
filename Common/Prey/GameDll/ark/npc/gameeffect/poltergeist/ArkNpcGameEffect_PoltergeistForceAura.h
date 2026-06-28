// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_PoltergeistForceAura;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;
struct IParticleEffect;

// ArkNpcGameEffect_PoltergeistForceAura
// Header:  Prey/GameDll/ark/npc/gameeffect/poltergeist/ArkNpcGameEffect_PoltergeistForceAura.h
class ArkNpcGameEffect_PoltergeistForceAura : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>
{ // Size=80 (0x50)
public:
	float m_radius;
	float m_minForce;
	float m_maxForce;
	float m_minMass;
	float m_maxMass;
	float m_damageAmountForRepelBlast;
	float m_damageSampleTimeForRepelBlast;
	float m_repelBlastRadiusMin;
	float m_repelBlastRadiusMax;
	float m_repelBlastMinScale;
	float m_repelBlastImpulse;
	uint64_t m_repelBlastPackageId;
	uint64_t m_repelBlastCameraShakeId;
	_smart_ptr<IParticleEffect> m_pRepelBlastEffect;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_PoltergeistForceAura();
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistForceAura& _gameEffectInstance, float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1355450);
	static inline auto FArkNpcGameEffect_PoltergeistForceAura = PreyFunction<void(ArkNpcGameEffect_PoltergeistForceAura* const _this)>(0x1355370);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_PoltergeistForceAura* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_PoltergeistForceAura& _gameEffectInstance, float _elapsedTime)>(0x13555B0);
};
#endif // MOONCRASH
