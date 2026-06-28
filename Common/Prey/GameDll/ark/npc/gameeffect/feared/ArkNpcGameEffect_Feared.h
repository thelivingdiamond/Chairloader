// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_Feared;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffect_Feared
// Header:  Prey/GameDll/ark/npc/gameeffect/feared/ArkNpcGameEffect_Feared.h
class ArkNpcGameEffect_Feared : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>
{ // Size=16 (0x10)
public:
	float m_endFearDistance;
	bool m_bFleesFromHostileDamage;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Feared();
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, const float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }
	void PushActivation(ArkNpc& _npc, unsigned _instigator, bool _bManualPop, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, bool _bFromAccumulator, bool _bPlayFearVFX) const { FPushActivation(this, _npc, _instigator, _bManualPop, _gameEffectInstance, _bFromAccumulator, _bPlayFearVFX); }
	void PopActivation(ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, bool _bFromAccumulator) const { FPopActivation(this, _npc, _gameEffectInstance, _bFromAccumulator); }
	void ClearActivation(ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance) const { FClearActivation(this, _npc, _gameEffectInstance); }
	void SetFearFromHostileDamage(ArkNpcGameEffectInstance_Feared& _gameEffectInstance, bool _bFleeFromHostileDamage) const { FSetFearFromHostileDamage(this, _gameEffectInstance, _bFleeFromHostileDamage); }
	bool IsActive(ArkNpcGameEffectInstance_Feared& _gameEffectInstance) const { return FIsActive(this, _gameEffectInstance); }
	void Serialize(ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, TSerialize _serializer) const { FSerialize(this, _npc, _gameEffectInstance, _serializer); }
	void OnFactionSwitchDamage(ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, unsigned _attackerId) const { FOnFactionSwitchDamage(this, _npc, _gameEffectInstance, _attackerId); }
	void OnMindControlled(ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, unsigned _mindControlInstigator) const { FOnMindControlled(this, _npc, _gameEffectInstance, _mindControlInstigator); }
	bool AddInstigator(ArkNpc& _npc, unsigned _instigator, ArkNpcGameEffectInstance_Feared& _gameEffectInstance) const { return FAddInstigator(this, _npc, _instigator, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_) const;
	void SafeActivate(ArkNpc& _arg0_, unsigned _arg1_, ArkNpcGameEffectInstance_Feared& _arg2_) const;
	void SafeDeactivate(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_) const;
	void Activate(ArkNpc& _arg0_, const unsigned _arg1_) const;
	void Refresh(ArkNpc& _arg0_, const unsigned _arg1_) const;
	void Deactivate(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_) const;
	bool RemoveInstigator(ArkNpc& _arg0_, unsigned _arg1_, ArkNpcGameEffectInstance_Feared& _arg2_) const;
	void UpdateInstigators(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Feared& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12ACE30);
	static inline auto FArkNpcGameEffect_Feared = PreyFunction<void(ArkNpcGameEffect_Feared* const _this)>(0x12ACCE0);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_Feared* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, const float _elapsedTime)>(0x12AD450);
	static inline auto FPushActivation = PreyFunction<void(const ArkNpcGameEffect_Feared* const _this, ArkNpc& _npc, unsigned _instigator, bool _bManualPop, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, bool _bFromAccumulator, bool _bPlayFearVFX)>(0x12AD170);
	static inline auto FPopActivation = PreyFunction<void(const ArkNpcGameEffect_Feared* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, bool _bFromAccumulator)>(0x12AD110);
	static inline auto FClearActivation = PreyFunction<void(const ArkNpcGameEffect_Feared* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance)>(0x12ACDF0);
	static inline auto FSetFearFromHostileDamage = PreyFunction<void(const ArkNpcGameEffect_Feared* const _this, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, bool _bFleeFromHostileDamage)>(0x12AD440);
	static inline auto FIsActive = PreyFunction<bool(const ArkNpcGameEffect_Feared* const _this, ArkNpcGameEffectInstance_Feared& _gameEffectInstance)>(0x12ACFE0);
	static inline auto FSerialize = PreyFunction<void(const ArkNpcGameEffect_Feared* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, TSerialize _serializer)>(0x12AD200);
	static inline auto FOnFactionSwitchDamage = PreyFunction<void(const ArkNpcGameEffect_Feared* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, unsigned _attackerId)>(0x12ACFF0);
	static inline auto FOnMindControlled = PreyFunction<void(const ArkNpcGameEffect_Feared* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Feared& _gameEffectInstance, unsigned _mindControlInstigator)>(0x12AD090);
	static inline auto FAddInstigator = PreyFunction<bool(const ArkNpcGameEffect_Feared* const _this, ArkNpc& _npc, unsigned _instigator, ArkNpcGameEffectInstance_Feared& _gameEffectInstance)>(0x12ACD50);
};
#endif // MOONCRASH
