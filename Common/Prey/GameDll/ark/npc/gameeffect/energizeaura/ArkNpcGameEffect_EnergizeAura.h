// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkBlackListItem.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>
#include <_unknown/ArkNpcGameEffectInstance.h>

class ArkNpc;
struct IEntity;

// ArkNpcGameEffectInstance_EnergizeAura
// Header:  Prey/GameDll/ark/npc/gameeffect/energizeaura/ArkNpcGameEffect_EnergizeAura.h
struct ArkNpcGameEffectInstance_EnergizeAura : public ArkNpcGameEffectInstance
{ // Size=80 (0x50)
	unsigned m_SourceNpcId;
	uint64_t m_signalPackageId;
	float m_accumElaspedTime;
	std::vector<unsigned int> m_lightningArcIds;
	std::vector<unsigned int> m_ambientArcIds;

	void OnLightningCallback(IEntity* const _pArc, IEntity* const _pTarget, float _strikeTime) { FOnLightningCallback(this, _pArc, _pTarget, _strikeTime); }

#if 0
	ArkNpcGameEffectInstance_EnergizeAura();
#endif

	static inline auto FOnLightningCallback = PreyFunction<void(ArkNpcGameEffectInstance_EnergizeAura* const _this, IEntity* const _pArc, IEntity* const _pTarget, float _strikeTime)>(0x1353B50);
};

// ArkNpcGameEffect_EnergizeAura
// Header:  Prey/GameDll/ark/npc/gameeffect/energizeaura/ArkNpcGameEffect_EnergizeAura.h
class ArkNpcGameEffect_EnergizeAura : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>
{ // Size=88 (0x58)
public:
	uint64_t m_signalPackageId;
	float m_signalRadius;
	float m_signalFrequency;
	string m_lightningMaterial;
	Vec3 m_sourceOffset;
	Vec3 m_sourceOffsetVariation;
	uint64_t m_modifierId;
	std::vector<ArkBlackListItem> m_blackList;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_EnergizeAura();
	void OnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance_EnergizeAura& _gameEffectInstance) const { FOnAttached(this, _npc, _gameEffectInstance); }
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_EnergizeAura& _gameEffectInstance, float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }
	uint64_t GetSignalPackageId() const { return FGetSignalPackageId(this); }
	void CreateLightningArcs(ArkNpc& _npc, ArkNpcGameEffectInstance_EnergizeAura& _gameEffectInstance, unsigned numArcs, bool bAmbientArcs) const { FCreateLightningArcs(this, _npc, _gameEffectInstance, numArcs, bAmbientArcs); }
	bool GetRandomDestPosition(IEntity* _pCastingEntity, const Vec3& _sourcePos, Vec3& _result) const { return FGetRandomDestPosition(this, _pCastingEntity, _sourcePos, _result); }

#if 0
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_EnergizeAura& _arg1_) const;
	Vec3 GetRandomVariation(const Vec3& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x13532E0);
	static inline auto FArkNpcGameEffect_EnergizeAura = PreyFunction<void(ArkNpcGameEffect_EnergizeAura* const _this)>(0x1352DA0);
	static inline auto FOnAttached = PreyFunction<void(const ArkNpcGameEffect_EnergizeAura* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_EnergizeAura& _gameEffectInstance)>(0x1353A90);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_EnergizeAura* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_EnergizeAura& _gameEffectInstance, float _elapsedTime)>(0x1353E60);
	static inline auto FGetSignalPackageId = PreyFunction<uint64_t(const ArkNpcGameEffect_EnergizeAura* const _this)>(0x12DC700);
	static inline auto FCreateLightningArcs = PreyFunction<void(const ArkNpcGameEffect_EnergizeAura* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_EnergizeAura& _gameEffectInstance, unsigned numArcs, bool bAmbientArcs)>(0x13532F0);
	static inline auto FGetRandomDestPosition = PreyFunction<bool(const ArkNpcGameEffect_EnergizeAura* const _this, IEntity* _pCastingEntity, const Vec3& _sourcePos, Vec3& _result)>(0x13537E0);
};
#endif // MOONCRASH
