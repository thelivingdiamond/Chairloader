// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_CorpseHunger;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;
struct IEntity;

// ArkNpcGameEffect_CorpseHunger
// Header:  Prey/GameDll/ark/npc/gameeffect/corpsehunger/ArkNpcGameEffect_CorpseHunger.h
class ArkNpcGameEffect_CorpseHunger : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>
{ // Size=16 (0x10)
public:
	float m_searchInterval;
	float m_searchIntervalPostDamage;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_CorpseHunger();
	void Fail(ArkNpc& _npc, ArkNpcGameEffectInstance_CorpseHunger& _gameEffectInstance, unsigned _failedToEatGibId) const { FFail(this, _npc, _gameEffectInstance, _failedToEatGibId); }
	IEntity* FindGiblet(ArkNpc& _npc, ArkNpcGameEffectInstance_CorpseHunger& _gameEffectInstance) const { return FFindGiblet(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_, float _arg2_) const;
	void OnTakeDamage(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_, const HitInfo& _arg2_, const ArkSignalSystem::Package& _arg3_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_CorpseHunger& _arg1_, TSerialize _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12AA480);
	static inline auto FArkNpcGameEffect_CorpseHunger = PreyFunction<void(ArkNpcGameEffect_CorpseHunger* const _this)>(0x12AA410);
	static inline auto FFail = PreyFunction<void(const ArkNpcGameEffect_CorpseHunger* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_CorpseHunger& _gameEffectInstance, unsigned _failedToEatGibId)>(0x12AA590);
	static inline auto FFindGiblet = PreyFunction<IEntity* (const ArkNpcGameEffect_CorpseHunger* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_CorpseHunger& _gameEffectInstance)>(0x12AA5B0);
};
#endif // MOONCRASH
