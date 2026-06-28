// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_OperatorScienceZap;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;
struct IEntity;
struct IEntityArchetype;
struct IMaterial;

// ArkNpcAbilityInstance_OperatorScienceZap
// Header:  Prey/GameDll/ark/npc/ability/operatorsciencezap/ArkNpcAbility_OperatorScienceZap.h
class ArkNpcAbilityInstance_OperatorScienceZap
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcBodyStateObserver_Busy
	, public ArkNpcAnimActionObserver
{ // Size=136 (0x88)
public:
	const ArkNpcAbility_OperatorScienceZap* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	_smart_ptr<IMaterial> m_pArcMaterial;
	std::array<unsigned int, 2> m_lightningArcEntityIds;
	std::array<unsigned int, 2> m_lightningArcAttachmentCrcs;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	IEntityArchetype* m_pArcLightningArchetype;
	float m_chargeTimer;

	virtual ~ArkNpcAbilityInstance_OperatorScienceZap();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	void OnLightningCallback(IEntity* const _pArc, IEntity* const _pTarget, float _strikeTime) { FOnLightningCallback(this, _pArc, _pTarget, _strikeTime); }

#if 0
	ArkNpcAbilityInstance_OperatorScienceZap();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x125A370);
	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x125A380);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x125A170);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x125A330);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0x125A180);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x125A330);
	static inline auto FOnLightningCallback = PreyFunction<void(ArkNpcAbilityInstance_OperatorScienceZap* const _this, IEntity* const _pArc, IEntity* const _pTarget, float _strikeTime)>(0x1259D10);
};

// ArkNpcAbility_OperatorScienceZap
// Header:  Prey/GameDll/ark/npc/ability/operatorsciencezap/ArkNpcAbility_OperatorScienceZap.h
class ArkNpcAbility_OperatorScienceZap : public ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>
{ // Size=56 (0x38)
public:
	uint64_t m_damageSignalPackageId;
	float m_chargeDuration;
	float m_maxDistanceToZapTarget;
	string m_arcMaterialName;
	string m_lightningArchetype;
	string m_lightningAttachmentName0;
	string m_lightningAttachmentName1;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_OperatorScienceZap();
	void OnAttack(ArkNpc& _npc, ArkNpcAbilityInstance_OperatorScienceZap& _abilityInstance, int _lightningIndex) const { FOnAttack(this, _npc, _abilityInstance, _lightningIndex); }
	void Exit(ArkNpcAbilityInstance_OperatorScienceZap& _abilityInstance) const { FExit(this, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_OperatorScienceZap& _abilityInstance) const { FDone(this, _abilityInstance); }
	IEntity* GetLightningArcEntity(ArkNpc& _npc, ArkNpcAbilityInstance_OperatorScienceZap& _abilityInstance, int _index) const { return FGetLightningArcEntity(this, _npc, _abilityInstance, _index); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorScienceZap& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorScienceZap& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_OperatorScienceZap& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_OperatorScienceZap& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_OperatorScienceZap& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorScienceZap& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_OperatorScienceZap& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_OperatorScienceZap& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_OperatorScienceZap& _arg0_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_OperatorScienceZap& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_OperatorScienceZap& _arg0_, EActionFailure _arg1_) const;
	uint64_t GetDamagePackage() const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1259290);
	static inline auto FArkNpcAbility_OperatorScienceZap = PreyFunction<void(ArkNpcAbility_OperatorScienceZap* const _this)>(0x1259090);
	static inline auto FOnAttack = PreyFunction<void(const ArkNpcAbility_OperatorScienceZap* const _this, ArkNpc& _npc, ArkNpcAbilityInstance_OperatorScienceZap& _abilityInstance, int _lightningIndex)>(0x1259C30);
	static inline auto FExit = PreyFunction<void(const ArkNpcAbility_OperatorScienceZap* const _this, ArkNpcAbilityInstance_OperatorScienceZap& _abilityInstance)>(0x1259920);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_OperatorScienceZap* const _this, ArkNpcAbilityInstance_OperatorScienceZap& _abilityInstance)>(0x1259890);
	static inline auto FGetLightningArcEntity = PreyFunction<IEntity* (const ArkNpcAbility_OperatorScienceZap* const _this, ArkNpc& _npc, ArkNpcAbilityInstance_OperatorScienceZap& _abilityInstance, int _index)>(0x1259A10);
};
#endif // MOONCRASH
