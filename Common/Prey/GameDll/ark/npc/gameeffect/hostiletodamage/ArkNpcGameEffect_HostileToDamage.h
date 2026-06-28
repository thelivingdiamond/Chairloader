// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_HostileToDamage;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffect_HostileToDamage
// Header:  Prey/GameDll/ark/npc/gameeffect/hostiletodamage/ArkNpcGameEffect_HostileToDamage.h
class ArkNpcGameEffect_HostileToDamage : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>
{ // Size=24 (0x18)
public:
	float m_hostilityDamageThreshold;
	float m_hostilityDamageSampleTime;
	float m_qBeamSignalDamageEquivalent;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_HostileToDamage();
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_HostileToDamage& _gameEffectInstance, const float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }
	void OnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance_HostileToDamage& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const { FOnTakeDamage(this, _npc, _gameEffectInstance, _hitInfo, _package); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_) const;
	void ClearHostility(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12AF3D0);
	static inline auto FArkNpcGameEffect_HostileToDamage = PreyFunction<void(ArkNpcGameEffect_HostileToDamage* const _this)>(0x12AF2F0);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_HostileToDamage* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_HostileToDamage& _gameEffectInstance, const float _elapsedTime)>(0x12AF830);
	static inline auto FOnTakeDamage = PreyFunction<void(const ArkNpcGameEffect_HostileToDamage* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_HostileToDamage& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12AF5C0);
};
#endif // MOONCRASH
