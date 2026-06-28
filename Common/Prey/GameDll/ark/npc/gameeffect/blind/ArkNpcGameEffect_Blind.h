// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance;
struct ArkNpcGameEffectInstance_Blind;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffect_Blind
// Header:  Prey/GameDll/ark/npc/gameeffect/blind/ArkNpcGameEffect_Blind.h
class ArkNpcGameEffect_Blind : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>
{ // Size=24 (0x18)
public:
	float m_damageSampleTime;
	float m_damageToGetKnownAttention;
	int m_numberOfHitsToGetKnownAttention;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Blind();
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_Blind& _gameEffectInstance, const float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }
	void OnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance_Blind& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const { FOnTakeDamage(this, _npc, _gameEffectInstance, _hitInfo, _package); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12A81D0);
	static inline auto FArkNpcGameEffect_Blind = PreyFunction<void(ArkNpcGameEffect_Blind* const _this)>(0x12A81B0);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_Blind* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Blind& _gameEffectInstance, const float _elapsedTime)>(0x12A8740);
	static inline auto FOnTakeDamage = PreyFunction<void(const ArkNpcGameEffect_Blind* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Blind& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A8350);
};
#endif // MOONCRASH
