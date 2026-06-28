// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_WeaverShield;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffect_WeaverShield
// Header:  Prey/GameDll/ark/npc/gameeffect/weavershield/ArkNpcGameEffect_WeaverShield.h
class ArkNpcGameEffect_WeaverShield : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>
{ // Size=72 (0x48)
public:
	enum class EWeaverShieldState
	{
		Activating = 0,
		Looping = 1,
		Dissolving = 2,
		Burst = 3,
		Off = 4,
	};

	float m_activationCooldown;
	float m_blockDamageTime;
	string m_shieldSkinAttachmentName;
	ArkAudioTrigger m_startAudioTrigger;
	ArkAudioTrigger m_stopAudioTrigger;
	ArkAudioTrigger m_impactAudioTrigger;
	uint64_t m_dissolveOnSignalGroupId;
	uint64_t m_signalModifierId;
	uint64_t m_fearPackageId;
	bool m_bBreakable;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_WeaverShield();
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_WeaverShield& _gameEffectInstance, float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }
	void Serialize(ArkNpc& _npc, ArkNpcGameEffectInstance_WeaverShield& _gameEffectInstance, TSerialize _ser) const { FSerialize(this, _npc, _gameEffectInstance, _ser); }
	void DeactiavteShield(ArkNpc& _npc, ArkNpcGameEffectInstance_WeaverShield& _gameEffectInstance) const { FDeactiavteShield(this, _npc, _gameEffectInstance); }
	void ActivateShield(ArkNpc& _npc, ArkNpcGameEffectInstance_WeaverShield& _gameEffectInstance) const { FActivateShield(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_) const;
	float ModifyDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_, const float _arg2_, HitInfo& _arg3_, const ArkSignalSystem::Package& _arg4_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_) const;
	void SwitchShieldState(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_, ArkNpcGameEffect_WeaverShield::EWeaverShieldState _arg2_) const;
	void UpdateShieldVfx(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_, float _arg2_) const;
	bool TryDeactivateShield(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_) const;
	void DissolveShield(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_) const;
	void BurstShield(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeaverShield& _arg1_) const;
	void SetShieldSkinVisible(ArkNpc& _arg0_, bool _arg1_) const;
	bool IsShieldExpiring(ArkNpcGameEffectInstance_WeaverShield& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1357A90);
	static inline auto FArkNpcGameEffect_WeaverShield = PreyFunction<void(ArkNpcGameEffect_WeaverShield* const _this)>(0x1357880);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_WeaverShield* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_WeaverShield& _gameEffectInstance, float _elapsedTime)>(0x1358110);
	static inline auto FSerialize = PreyFunction<void(const ArkNpcGameEffect_WeaverShield* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_WeaverShield& _gameEffectInstance, TSerialize _ser)>(0x1357F20);
	static inline auto FDeactiavteShield = PreyFunction<void(const ArkNpcGameEffect_WeaverShield* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_WeaverShield& _gameEffectInstance)>(0x1357A10);
	static inline auto FActivateShield = PreyFunction<void(const ArkNpcGameEffect_WeaverShield* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_WeaverShield& _gameEffectInstance)>(0x1357970);
};
#endif // MOONCRASH
