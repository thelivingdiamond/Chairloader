// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>
#include <_unknown/ArkNpcGameEffectInstance.h>

class ArkNpc;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffectInstance_Stun
// Header:  Prey/GameDll/ark/npc/gameeffect/stun/ArkNpcGameEffect_Stun.h
struct ArkNpcGameEffectInstance_Stun : public ArkNpcGameEffectInstance
{ // Size=664 (0x298)
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcLookDesire m_lookDesire;
	ArkNpcMovementDesire m_movementDesire;
	float m_stunVfxDurationTimer;
	float m_stunDuration;
	bool m_bRagdolledForDuration;
	bool m_bWaitingToStartAnim;
	unsigned m_instigatorId;

	ArkNpcGameEffectInstance_Stun();

	static inline auto FArkNpcGameEffectInstance_StunOv1 = PreyFunction<void(ArkNpcGameEffectInstance_Stun* const _this)>(0x12B1FC0);
};

// ArkNpcGameEffect_Stun
// Header:  Prey/GameDll/ark/npc/gameeffect/stun/ArkNpcGameEffect_Stun.h
class ArkNpcGameEffect_Stun : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>
{ // Size=24 (0x18)
public:
	uint64_t m_stunSignalModifierId;
	float m_stunVfxDuration;
	bool m_bStunUnconscious;
	bool m_bStunLastsForever;
	bool m_bStopOnAnyDamage;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Stun();
	void StartStun(ArkNpc& _npc, ArkNpcGameEffectInstance_Stun& _gameEffectInstance, unsigned _instigatorId, float _duration) const { FStartStun(this, _npc, _gameEffectInstance, _instigatorId, _duration); }
	void RefreshStun(ArkNpc& _npc, ArkNpcGameEffectInstance_Stun& _gameEffectInstance, float _duration) const { FRefreshStun(this, _npc, _gameEffectInstance, _duration); }
	void InternalStart(ArkNpc& _npc, ArkNpcGameEffectInstance_Stun& _gameEffectInstance, unsigned _instigatorId, float _duration) const { FInternalStart(this, _npc, _gameEffectInstance, _instigatorId, _duration); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_, float _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_) const;
	void StopStun(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_) const;
	void TryMakeHumansHostile(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B22C0);
	static inline auto FArkNpcGameEffect_Stun = PreyFunction<void(ArkNpcGameEffect_Stun* const _this)>(0x12B2230);
	static inline auto FStartStun = PreyFunction<void(const ArkNpcGameEffect_Stun* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Stun& _gameEffectInstance, unsigned _instigatorId, float _duration)>(0x12B2860);
	static inline auto FRefreshStun = PreyFunction<void(const ArkNpcGameEffect_Stun* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Stun& _gameEffectInstance, float _duration)>(0x12B2800);
	static inline auto FInternalStart = PreyFunction<void(const ArkNpcGameEffect_Stun* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Stun& _gameEffectInstance, unsigned _instigatorId, float _duration)>(0x12B2680);
};
#endif // MOONCRASH
