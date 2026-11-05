// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/ArkNpcGameEffect.h>

class ArkNpc;
struct ArkNpcGameEffectInstance;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffectTemplate<TGameEffect,TGameEffectInstance>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
// Every instantiation is Size=8 (27 in the base game, 39 in Mooncrash).
// No addresses: they differ per instantiation.
template<typename TGameEffect, typename TGameEffectInstance>
class ArkNpcGameEffectTemplate : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = TGameEffect;
	using GameEffectInstanceType = TGameEffectInstance;

	virtual ~ArkNpcGameEffectTemplate();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
#ifndef MOONCRASH
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
#else
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
#endif
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate();
	void OnAttached(ArkNpc& _arg0_, TGameEffectInstance& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, TGameEffectInstance& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, TGameEffectInstance& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, TGameEffectInstance& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
#ifndef MOONCRASH
	float ModifyDamage(ArkNpc& _arg0_, TGameEffectInstance& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
#else
	float ModifyDamage(ArkNpc& _arg0_, TGameEffectInstance& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
#endif
	void OnTakeDamage(ArkNpc& _arg0_, TGameEffectInstance& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
#ifdef MOONCRASH
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
#endif
	void OnDied(ArkNpc& _arg0_, TGameEffectInstance& _arg1_) const;
	void Update(ArkNpc& _arg0_, TGameEffectInstance& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, TGameEffectInstance& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, TGameEffectInstance& _arg1_) const;
#endif
};
