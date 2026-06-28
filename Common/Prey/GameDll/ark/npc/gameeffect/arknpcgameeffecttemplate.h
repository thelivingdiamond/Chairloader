// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/ArkNpcGameEffect.h>

class ArkNpc;
struct ArkNpcGameEffectInstance;
struct ArkNpcGameEffectInstance_Armored;
struct ArkNpcGameEffectInstance_Blind;
struct ArkNpcGameEffectInstance_ControlCorruptedNpcs;
struct ArkNpcGameEffectInstance_ControlTurrets;
struct ArkNpcGameEffectInstance_CorpseHunger;
struct ArkNpcGameEffectInstance_Corrupted;
struct ArkNpcGameEffectInstance_Disintegration;
struct ArkNpcGameEffectInstance_DoppelgangerLink;
struct ArkNpcGameEffectInstance_EnergizeAura;
struct ArkNpcGameEffectInstance_Energized;
struct ArkNpcGameEffectInstance_EthericFog;
struct ArkNpcGameEffectInstance_ExcreteCystoids;
struct ArkNpcGameEffectInstance_FastTurnOnDamage;
struct ArkNpcGameEffectInstance_Feared;
struct ArkNpcGameEffectInstance_Frenzy;
struct ArkNpcGameEffectInstance_Gloo;
struct ArkNpcGameEffectInstance_Hacked;
struct ArkNpcGameEffectInstance_HitReactionMaterialAnimation;
struct ArkNpcGameEffectInstance_HostileToDamage;
struct ArkNpcGameEffectInstance_Interference;
struct ArkNpcGameEffectInstance_MindControl;
struct ArkNpcGameEffectInstance_NightmareEtherFormDamageAura;
struct ArkNpcGameEffectInstance_OnFire;
struct ArkNpcGameEffectInstance_OperatorArmsRetracted;
struct ArkNpcGameEffectInstance_Pet;
struct ArkNpcGameEffectInstance_PlayerControlled;
struct ArkNpcGameEffectInstance_PlayerProximityPackage;
struct ArkNpcGameEffectInstance_PoltergeistForceAura;
struct ArkNpcGameEffectInstance_PoltergeistInvisibility;
struct ArkNpcGameEffectInstance_PsiSuppression;
struct ArkNpcGameEffectInstance_RaiseFromCorpse;
struct ArkNpcGameEffectInstance_SimplePackageAura;
struct ArkNpcGameEffectInstance_Stun;
struct ArkNpcGameEffectInstance_TelepathShield;
struct ArkNpcGameEffectInstance_ThermalAura;
struct ArkNpcGameEffectInstance_Underground;
struct ArkNpcGameEffectInstance_WeakPoint;
struct ArkNpcGameEffectInstance_WeaverShield;
class ArkNpcGameEffect_Armored;
class ArkNpcGameEffect_Blind;
class ArkNpcGameEffect_ControlCorruptedNpcs;
class ArkNpcGameEffect_ControlTurrets;
class ArkNpcGameEffect_CorpseHunger;
class ArkNpcGameEffect_Corrupted;
class ArkNpcGameEffect_Disintegration;
class ArkNpcGameEffect_DoppelgangerLink;
class ArkNpcGameEffect_EnergizeAura;
class ArkNpcGameEffect_Energized;
class ArkNpcGameEffect_EthericFog;
class ArkNpcGameEffect_ExcreteCystoids;
class ArkNpcGameEffect_FastTurnOnDamage;
class ArkNpcGameEffect_Feared;
class ArkNpcGameEffect_Frenzy;
class ArkNpcGameEffect_Gloo;
class ArkNpcGameEffect_Hacked;
class ArkNpcGameEffect_HitReactionMaterialAnimation;
class ArkNpcGameEffect_HostileToDamage;
class ArkNpcGameEffect_Interference;
class ArkNpcGameEffect_MindControl;
class ArkNpcGameEffect_NightmareEtherFormDamageAura;
class ArkNpcGameEffect_OnFire;
class ArkNpcGameEffect_OperatorArmsRetracted;
class ArkNpcGameEffect_Pet;
class ArkNpcGameEffect_PlayerControlled;
class ArkNpcGameEffect_PlayerProximityPackage;
class ArkNpcGameEffect_PoltergeistForceAura;
class ArkNpcGameEffect_PoltergeistInvisibility;
class ArkNpcGameEffect_PsiSuppression;
class ArkNpcGameEffect_RaiseFromCorpse;
class ArkNpcGameEffect_SimplePackageAura;
class ArkNpcGameEffect_Stun;
class ArkNpcGameEffect_TelepathShield;
class ArkNpcGameEffect_ThermalAura;
class ArkNpcGameEffect_Underground;
class ArkNpcGameEffect_WeakPoint;
class ArkNpcGameEffect_WeaverShield;
class ArkNpcNullGameEffect;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Armored;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Armored;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Armored& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this)>(0x12A7940);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12A7950);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12A7A20);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A79A0);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12A7A20);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Blind;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Blind;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Blind& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this)>(0x12A81D0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12A81E0);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12A82E0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12A82C0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A82D0);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x12A82A0);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12A8340);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12A82F0);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12A82E0);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_ControlCorruptedNpcs;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_ControlCorruptedNpcs;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlCorruptedNpcs& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this)>(0x12A9B20);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12A9B30);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12A9BA0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12A9BF0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12A9C60);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_ControlTurrets;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_ControlTurrets;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ControlTurrets& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this)>(0x134F880);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x134F890);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x134F960);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x134F9A0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x134FA10);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x134FB30);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x134FB10);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x134FAC0);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_CorpseHunger;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_CorpseHunger;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this)>(0x12AA480);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12AA490);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AA4E0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12AA4F0);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12AA530);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12AA510);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Corrupted;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Corrupted;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Corrupted& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this)>(0x12AAAA0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1344D50);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AAAB0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AAC70);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AABA0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x12AAC80);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AABB0);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12AACA0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AAC90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Disintegration;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Disintegration;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Disintegration& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this)>(0x12AB550);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B0680);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AB560);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12AB660);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12AB610);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AB5E0);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_DoppelgangerLink;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_DoppelgangerLink;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_DoppelgangerLink& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this)>(0x12AB700);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1344D50);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AB710);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12AB760);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_EnergizeAura;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_EnergizeAura;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this)>(0x13532E0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1353590);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1353710);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x13535F0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1353720);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1353710);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Energized;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Energized;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Energized& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this)>(0x12AB930);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12AB940);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AB9C0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AB9F0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x12ABA00);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12ABC70);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12ABBA0);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12ABB00);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_EthericFog;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_EthericFog;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EthericFog& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this)>(0x1354500);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B1730);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1354510);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1354560);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x13545C0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x13545A0);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_ExcreteCystoids;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_ExcreteCystoids;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ExcreteCystoids& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ExcreteCystoids& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ExcreteCystoids& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ExcreteCystoids& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ExcreteCystoids& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ExcreteCystoids& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ExcreteCystoids& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ExcreteCystoids& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ExcreteCystoids& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ExcreteCystoids& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this)>(0x1344CE0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1344D00);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1344D90);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1344E00);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1344DE0);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_FastTurnOnDamage;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_FastTurnOnDamage;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_FastTurnOnDamage& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this)>(0x12AC590);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12AC5A0);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AC640);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12AC6A0);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12AC820);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12AC740);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AC710);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Feared;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Feared;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this)>(0x12ACE30);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12ACE40);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12ACEA0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12ACEC0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12ACEF0);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1357770);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12ACFD0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12ACFB0);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Frenzy;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Frenzy;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Frenzy& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this)>(0x12AD6C0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12AD6D0);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AD730);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12AD850);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12AD7D0);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AD790);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Gloo;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Gloo;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Gloo& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this)>(0x12ADAD0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12ADAE0);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12ADBA0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12ADD30);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x12ADEA0);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12ADEB0);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12ADE50);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12ADFF0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12ADF30);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12ADED0);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Hacked;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Hacked;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Hacked& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this)>(0x12AEA20);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1344D50);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AEA30);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AEAE0);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_HitReactionMaterialAnimation;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_HitReactionMaterialAnimation;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HitReactionMaterialAnimation& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this)>(0x12AEB90);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B1730);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AEBA0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12AEBD0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_HostileToDamage;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_HostileToDamage;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_HostileToDamage& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this)>(0x12AF3D0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12AF3E0);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12AF4A0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12AF550);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12AF5B0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12AF560);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Interference;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Interference;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this)>(0x1354C80);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B1730);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1354C90);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1354CD0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1354C90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_MindControl;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_MindControl;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this)>(0x12B0030);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B0040);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B00B0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x12B00D0);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12B0250);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1357770);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12B0380);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12B0290);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B0280);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_NightmareEtherFormDamageAura;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_NightmareEtherFormDamageAura;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_NightmareEtherFormDamageAura& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this)>(0x12B0670);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B0680);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B06D0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1357770);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12B06E0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_OnFire;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_OnFire;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OnFire& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this)>(0x12B0A70);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1344D00);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B0A80);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B0B20);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x12B0B50);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1357770);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12B0CC0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12B0C50);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B0C40);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_OperatorArmsRetracted;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_OperatorArmsRetracted;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this)>(0x12B0E10);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B0E20);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B0EB0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B0E70);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B0EB0);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Pet;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Pet;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this)>(0x12B1000);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B1010);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B1070);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B1080);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12B10F0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B10B0);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_PlayerControlled;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_PlayerControlled;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerControlled& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this)>(0x12B1660);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1344D50);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B1670);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B16A0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B16D0);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_PlayerProximityPackage;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_PlayerProximityPackage;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerProximityPackage& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerProximityPackage& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerProximityPackage& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerProximityPackage& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerProximityPackage& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerProximityPackage& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerProximityPackage& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerProximityPackage& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerProximityPackage& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PlayerProximityPackage& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this)>(0x12B1720);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B1730);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12B1780);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_PoltergeistForceAura;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_PoltergeistForceAura;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistForceAura& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this)>(0x1355450);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1355460);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x13554D0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1355500);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x13555A0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_PoltergeistInvisibility;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_PoltergeistInvisibility;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PoltergeistInvisibility& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this)>(0x1356400);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1356410);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1356470);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1356480);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1356530);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x13565E0);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x13566F0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1356470);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_PsiSuppression;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_PsiSuppression;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PsiSuppression& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PsiSuppression& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PsiSuppression& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PsiSuppression& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PsiSuppression& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PsiSuppression& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PsiSuppression& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PsiSuppression& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PsiSuppression& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_PsiSuppression& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this)>(0x1344CF0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1344D50);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1344DA0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1344DB0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1344DC0);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1344DD0);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_RaiseFromCorpse;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_RaiseFromCorpse;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_RaiseFromCorpse& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this)>(0x12B1A60);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B1730);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B1A70);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x12B1A90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12B1BC0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12B1BA0);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B1B90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_SimplePackageAura;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_SimplePackageAura;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this)>(0x12B1C30);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B0680);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B1C40);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B1CD0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1357770);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12B1E40);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12B1DF0);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B1D70);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Stun;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Stun;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Stun& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this)>(0x12B22C0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B22D0);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B2310);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B2340);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12B24A0);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B2450);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12B2590);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12B2500);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B24D0);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_TelepathShield;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_TelepathShield;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_TelepathShield& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this)>(0x12B3270);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B3280);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B34E0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B3540);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x12B36F0);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12B3310);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12B3900);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12B3890);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B3810);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_ThermalAura;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_ThermalAura;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this)>(0x13576E0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B1730);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1357790);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x13576F0);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1357770);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1357810);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x13577F0);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1357790);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_Underground;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_Underground;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this)>(0x12B3CE0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B3CF0);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B3DE0);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B3E10);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x12B3FD0);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x12B3EE0);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B3E80);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_WeakPoint;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_WeakPoint;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this)>(0x12B51A0);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x12B51B0);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B5230);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x12B5240);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};

// ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcGameEffect_WeaverShield;
	using GameEffectInstanceType = ArkNpcGameEffectInstance_WeaverShield;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this)>(0x1357A90);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1357AA0);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1357C00);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1357C80);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1357CD0);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1357B30);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1357F10);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1357EF0);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1357E00);
};

// ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h
class ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance> : public ArkNpcGameEffect
{ // Size=8 (0x8)
public:
	using GameEffectType = ArkNpcNullGameEffect;
	using GameEffectInstanceType = ArkNpcGameEffectInstance;

	virtual ~ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>();
	virtual const char* DoGetClassName() const;
	virtual std::unique_ptr<ArkNpcGameEffectInstance> DoMakeGameEffectInstance() const;
	virtual void DoOnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReattached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnDetached(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoOnReceiveSignal(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package) const;
	virtual float DoModifyDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnTakeDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const;
	virtual void DoOnDealtDamage(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId) const;
	virtual void DoOnDied(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;
	virtual void DoUpdate(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime) const;
	virtual void DoSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer) const;
	virtual void DoPostSerialize(ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance) const;

#if 0
	ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>();
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_) const;
	void OnReattached(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDealtDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, unsigned _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance& _arg1_) const;
#endif

	static inline auto FDoGetClassName = PreyFunction<const char* (const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this)>(0x1338570);
	static inline auto FDoMakeGameEffectInstance = PreyFunction<std::unique_ptr<ArkNpcGameEffectInstance>*(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, std::unique_ptr<ArkNpcGameEffectInstance>* _return_value_)>(0x1344D50);
	static inline auto FDoOnAttached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReattached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnDetached = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoOnReceiveSignal = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoModifyDamage = PreyFunction<float(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const float _modifiedDamage, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x12A9B90);
	static inline auto FDoOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1333E90);
	static inline auto FDoOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, unsigned _damagedEntityId)>(0x1333E90);
	static inline auto FDoOnDied = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, float _elapsedTime)>(0x1333E90);
	static inline auto FDoSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance, TSerialize _serializer)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(const ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance& _gameEffectInstance)>(0x1333E90);
};
#endif // MOONCRASH
