// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_MindControl;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffect_MindControl
// Header:  Prey/GameDll/ark/npc/gameeffect/mindcontrol/ArkNpcGameEffect_MindControl.h
class ArkNpcGameEffect_MindControl : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>
{ // Size=40 (0x28)
public:
	uint64_t m_mindControlSingalId;
	uint64_t m_mindControlFactionId;
	uint64_t m_mindControlMetaTag;
	float m_loopEffectDelayTime;
	float m_playerDamageAmountToBreakControl;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_MindControl();
	void StopMindControl(ArkNpc& _npc, ArkNpcGameEffectInstance_MindControl& _gameEffectInstance) const { FStopMindControl(this, _npc, _gameEffectInstance); }
	void InternalStart(ArkNpc& _npc, ArkNpcGameEffectInstance_MindControl& _gameEffectInstance) const { FInternalStart(this, _npc, _gameEffectInstance); }

#if 0
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_) const;
	void OnReceiveSignal(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_, const ArkSignalSystem::Package& _arg2_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_, float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_) const;
	void StartMindControl(ArkNpc& _arg0_, ArkNpcGameEffectInstance_MindControl& _arg1_, float _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B0030);
	static inline auto FArkNpcGameEffect_MindControl = PreyFunction<void(ArkNpcGameEffect_MindControl* const _this)>(0x12AFFB0);
	static inline auto FStopMindControl = PreyFunction<void(const ArkNpcGameEffect_MindControl* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_MindControl& _gameEffectInstance)>(0x12B04E0);
	static inline auto FInternalStart = PreyFunction<void(const ArkNpcGameEffect_MindControl* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_MindControl& _gameEffectInstance)>(0x12B0440);
};
#endif // MOONCRASH
