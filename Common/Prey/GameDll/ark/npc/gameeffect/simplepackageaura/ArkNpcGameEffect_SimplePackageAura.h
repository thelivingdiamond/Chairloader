// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

enum class ArkCharacterEffectType;
class ArkNpc;
struct ArkNpcGameEffectInstance_SimplePackageAura;

// ArkNpcGameEffect_SimplePackageAura
// Header:  Prey/GameDll/ark/npc/gameeffect/simplepackageaura/ArkNpcGameEffect_SimplePackageAura.h
class ArkNpcGameEffect_SimplePackageAura : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>
{ // Size=56 (0x38)
public:
	enum class VisualEffectType
	{
		Thermal = 0,
		Electric = 1,
		NONE = 2,
	};

	uint64_t m_auraPackageId;
	uint64_t m_auraInboundModifierId;
	bool m_bAuraPersistsForever;
	float m_auraDurationTime;
	float m_auraTickRate;
	float m_auraRadius;
	unsigned m_characterEffectType;
	float m_defaultEffectRadius;
	bool m_bStoppedByGoo;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_SimplePackageAura();

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_, float _arg2_) const;
	void OnDied(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_) const;
	void ApplyPackageTick(ArkNpc& _arg0_, ArkNpcGameEffectInstance_SimplePackageAura& _arg1_) const;
	ArkCharacterEffectType GetCharacterEffectType() const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B1C30);
	static inline auto FArkNpcGameEffect_SimplePackageAura = PreyFunction<void(ArkNpcGameEffect_SimplePackageAura* const _this)>(0x12B1C00);
};
#endif // MOONCRASH
