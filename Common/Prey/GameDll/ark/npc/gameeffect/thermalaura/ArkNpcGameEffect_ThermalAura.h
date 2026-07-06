// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_ThermalAura;

// ArkNpcGameEffect_ThermalAura
// Header:  Prey/GameDll/ark/npc/gameeffect/thermalaura/ArkNpcGameEffect_ThermalAura.h
class ArkNpcGameEffect_ThermalAura : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>
{ // Size=40 (0x28)
public:
	enum class VisualEffectType
	{
		Thermal = 0,
		Electric = 1,
		NONE = 2,
	};

	uint64_t m_auraPackageId;
	uint64_t m_auraInboundModifierId;
	float m_auraTickRate;
	float m_auraRadius;
	unsigned m_characterEffectType;
	float m_defaultEffectRadius;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_ThermalAura();
	void ApplyPackageTick(ArkNpc& _npc, ArkNpcGameEffectInstance_ThermalAura& _gameEffectInstance) const { FApplyPackageTick(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_, float _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_ThermalAura& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x13576E0);
	static inline auto FArkNpcGameEffect_ThermalAura = PreyFunction<void(ArkNpcGameEffect_ThermalAura* const _this)>(0x13572F0);
	static inline auto FApplyPackageTick = PreyFunction<void(const ArkNpcGameEffect_ThermalAura* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_ThermalAura& _gameEffectInstance)>(0x1357320);
};
#endif // MOONCRASH
