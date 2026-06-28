// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkConditionResult : public ArkReflectedObject // Id=8013C27 Size=8
{
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual void Execute(uint64_t _parentCondition) const;
	virtual bool IsDelayedResult() const;

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x106AAC0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x106B640);
	static inline auto FExecute = PreyFunction<void(ArkConditionResult const* const _this, uint64_t _parentCondition)>(0xA13080);
	static inline auto FIsDelayedResult = PreyFunction<bool(ArkConditionResult const* const _this)>(0xDD23F0);
};

// Header: Override
// Prey/Ark/arkgamestatecondition.h
class ArkConditionEvaluationData // Id=8013BDB Size=24
{
public:
	EArkConditionTriggerType m_type;
	
	struct EntityIdentifiers // Id=8013BDC Size=16
	{
		uint64_t m_archetypeId;
		unsigned m_entityId;
	};

	union
	{
		uint64_t m_changeId;
		ArkConditionEvaluationData::EntityIdentifiers m_identifiers;
	};
	
#if 0
	bool operator==(ArkConditionEvaluationData const &arg0) const;
	EArkConditionTriggerType GetType() const;
	uint64_t GetChangeId() const;
	uint64_t GetArchetypeId() const;
	unsigned GetEntityId() const;
#endif
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkCondition : public ArkReflectedObject // Id=8013BDD Size=8
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106A9C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106B460);
	static inline auto FEvaluate = PreyFunction<bool(ArkCondition const *const _this, ArkConditionEvaluationData const &_change)>(0xDD23F0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkCondition const *const _this, ArkConditionEvaluationData const &_change)>(0xDD23F0);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkConditionGroup : public ArkCondition // Id=8013BDE Size=40
{
public:
	class ArkAndProperty : public ArkProperty // Id=8013BDF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkConditionGroup::ArkAndProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068DB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkConditionGroup::ArkAndProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkConditionGroup::ArkAndProperty s_ArkAndProperty;
	bool m_And;
	
	class ArkConditionsProperty : public ArkProperty // Id=8013BE0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkConditionGroup::ArkConditionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068DD0);
		static inline auto FIsArray = PreyFunction<bool(ArkConditionGroup::ArkConditionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkConditionGroup::ArkConditionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1068C30);
	};

	static ArkConditionGroup::ArkConditionsProperty s_ArkConditionsProperty;
	std::vector<std::shared_ptr<ArkCondition>> m_Conditions;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	void SetAnd(bool arg0);
	const bool &GetAnd() const;
	std::vector<std::shared_ptr<ArkCondition>> &GetConditions();
	std::vector<std::shared_ptr<ArkCondition>> const &GetConditions() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AA60);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106B5A0);
	static inline auto FEvaluate = PreyFunction<bool(ArkConditionGroup const *const _this, ArkConditionEvaluationData const &_change)>(0x1068E80);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkConditionGroup const *const _this, ArkConditionEvaluationData const &_change)>(0x1068EF0);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkNotCondition : public ArkCondition // Id=8013BF1 Size=48
{
public:
	class ArkConditionGroupProperty : public ArkProperty // Id=8013BF2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNotCondition::ArkConditionGroupProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10688B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNotCondition::ArkConditionGroupProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068990);
	};

	static ArkNotCondition::ArkConditionGroupProperty s_ArkConditionGroupProperty;
	ArkConditionGroup m_ConditionGroup;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
	void SetConditionGroup(ArkConditionGroup arg0);
	ArkConditionGroup const &GetConditionGroup() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B1B0);
	static inline auto FEvaluate = PreyFunction<bool(ArkNotCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106B440);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkNotCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C830);
};

// Header: Exact
// Prey/Ark/ArkGameStateCondition.h
class ArkGameStateCondition : public ArkReflectedObject // Id=8013C49 Size=88
{
public:
	class ArkIDProperty : public ArkProperty // Id=8013C4A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameStateCondition::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameStateCondition::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkGameStateCondition::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013C4B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameStateCondition::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameStateCondition::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkGameStateCondition::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkEnabledProperty : public ArkProperty // Id=8013C4C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameStateCondition::ArkEnabledProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360190);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameStateCondition::ArkEnabledProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkGameStateCondition::ArkEnabledProperty s_ArkEnabledProperty;
	bool m_Enabled;
	
	class ArkConditionGroupProperty : public ArkProperty // Id=8013C4D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameStateCondition::ArkConditionGroupProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068F50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameStateCondition::ArkConditionGroupProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068FC0);
	};

	static ArkGameStateCondition::ArkConditionGroupProperty s_ArkConditionGroupProperty;
	ArkConditionGroup m_ConditionGroup;
	
	class ArkResultsProperty : public ArkProperty // Id=8013C4E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameStateCondition::ArkResultsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068FE0);
		static inline auto FIsArray = PreyFunction<bool(ArkGameStateCondition::ArkResultsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkGameStateCondition::ArkResultsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1069030);
	};

	static ArkGameStateCondition::ArkResultsProperty s_ArkResultsProperty;
	std::vector<std::shared_ptr<ArkConditionResult>> m_Results;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetEnabled(bool arg0);
	const bool &GetEnabled() const;
	void SetConditionGroup(ArkConditionGroup arg0);
	ArkConditionGroup const &GetConditionGroup() const;
	std::vector<std::shared_ptr<ArkConditionResult>> &GetResults();
	std::vector<std::shared_ptr<ArkConditionResult>> const &GetResults() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106ADB0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106B960);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkItemCondition : public ArkCondition // Id=8013BF4 Size=48
{
public:
	class ArkArchetypeProperty : public ArkProperty // Id=8013BF5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkItemCondition::ArkArchetypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360300);
	};

	static ArkItemCondition::ArkArchetypeProperty s_ArkArchetypeProperty;
	string m_Archetype;
	
	class ArkMetaTagsProperty : public ArkProperty // Id=8013BF6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkItemCondition::ArkMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10689B0);
	};

	static ArkItemCondition::ArkMetaTagsProperty s_ArkMetaTagsProperty;
	std::vector<unsigned __int64> m_MetaTags;
	
	class ArkQuantityProperty : public ArkProperty // Id=8013BF7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkItemCondition::ArkQuantityProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068AF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkItemCondition::ArkQuantityProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221B60);
	};

	static ArkItemCondition::ArkQuantityProperty s_ArkQuantityProperty;
	int m_Quantity;
	
	class ArkComparisonTypeProperty : public ArkProperty // Id=8013BF8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkItemCondition::ArkComparisonTypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B10);
	};

	static ArkItemCondition::ArkComparisonTypeProperty s_ArkComparisonTypeProperty;
	EArkComparisonType m_ComparisonType;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	bool EvaluateGainOrLoss(ArkConditionEvaluationData const &_change) const { return FEvaluateGainOrLoss(this,_change); }
	
#if 0
	void SetArchetype(string arg0);
	uint64_t GetArchetype() const;
	string const &GetArchetypeString() const;
	void SetMetaTags(string arg0);
	std::vector<unsigned __int64> const &GetMetaTags() const;
	void SetQuantity(int arg0);
	const int &GetQuantity() const;
	void SetComparisonType(string arg0);
	EArkComparisonType const &GetComparisonType() const;
	bool TestForReevaluation(ArkConditionEvaluationData const &arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AF80);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106BC30);
	static inline auto FEvaluate = PreyFunction<bool(ArkItemCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C09E0);
	static inline auto FEvaluateGainOrLoss = PreyFunction<bool(ArkItemCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0F40);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkHasItemCondition : public ArkItemCondition // Id=8013BF9 Size=48
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AE70);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkHasItemCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C710);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkGainedItemCondition : public ArkItemCondition // Id=8013BFA Size=48
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AD00);
	static inline auto FEvaluate = PreyFunction<bool(ArkGainedItemCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0740);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkGainedItemCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C680);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkLostItemCondition : public ArkItemCondition // Id=8013BFB Size=48
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B150);
	static inline auto FEvaluate = PreyFunction<bool(ArkLostItemCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0C20);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkLostItemCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C7C0);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkAcquiredChipsetCondition : public ArkCondition // Id=8013BFC Size=8
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106A8D0);
	static inline auto FEvaluate = PreyFunction<bool(ArkAcquiredChipsetCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0530);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkAcquiredChipsetCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0530);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkHealthAmountCondition : public ArkCondition // Id=8013BFD Size=16
{
public:
	class ArkAmountProperty : public ArkProperty // Id=8013BFE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkHealthAmountCondition::ArkAmountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkHealthAmountCondition::ArkAmountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkHealthAmountCondition::ArkAmountProperty s_ArkAmountProperty;
	float m_Amount;
	
	class ArkComparisonTypeProperty : public ArkProperty // Id=8013BFF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkHealthAmountCondition::ArkComparisonTypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068C70);
	};

	static ArkHealthAmountCondition::ArkComparisonTypeProperty s_ArkComparisonTypeProperty;
	EArkComparisonType m_ComparisonType;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	void SetAmount(float arg0);
	const float &GetAmount() const;
	void SetComparisonType(string arg0);
	EArkComparisonType const &GetComparisonType() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AED0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106BAF0);
	static inline auto FEvaluate = PreyFunction<bool(ArkHealthAmountCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0850);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkHealthAmountCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C780);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkPsiAmountCondition : public ArkCondition // Id=8013C00 Size=16
{
public:
	class ArkAmountProperty : public ArkProperty // Id=8013C01 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiAmountCondition::ArkAmountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiAmountCondition::ArkAmountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkPsiAmountCondition::ArkAmountProperty s_ArkAmountProperty;
	float m_Amount;
	
	class ArkComparisonTypeProperty : public ArkProperty // Id=8013C02 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiAmountCondition::ArkComparisonTypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068C70);
	};

	static ArkPsiAmountCondition::ArkComparisonTypeProperty s_ArkComparisonTypeProperty;
	EArkComparisonType m_ComparisonType;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	void SetAmount(float arg0);
	const float &GetAmount() const;
	void SetComparisonType(string arg0);
	EArkComparisonType const &GetComparisonType() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B300);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106BF50);
	static inline auto FEvaluate = PreyFunction<bool(ArkPsiAmountCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0CF0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkPsiAmountCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C890);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkObjectiveCondition : public ArkCondition // Id=8013C03 Size=24
{
public:
	class ArkObjectiveProperty : public ArkProperty // Id=8013C04 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkObjectiveCondition::ArkObjectiveProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkObjectiveCondition::ArkObjectiveProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkObjectiveCondition::ArkObjectiveProperty s_ArkObjectiveProperty;
	uint64_t m_Objective;
	
	class ArkStateProperty : public ArkProperty // Id=8013C05 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkObjectiveCondition::ArkStateProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068CF0);
	};

	static ArkObjectiveCondition::ArkStateProperty s_ArkStateProperty;
	EArkObjectiveState m_State;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	void SetObjective(uint64_t arg0);
	const uint64_t &GetObjective() const;
	void SetState(string arg0);
	EArkObjectiveState const &GetState() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B210);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106BE10);
	static inline auto FEvaluate = PreyFunction<bool(ArkObjectiveCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0C30);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkObjectiveCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C840);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkObjectiveTaskCondition : public ArkCondition // Id=8013C06 Size=24
{
public:
	class ArkTaskProperty : public ArkProperty // Id=8013C07 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkObjectiveTaskCondition::ArkTaskProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkObjectiveTaskCondition::ArkTaskProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkObjectiveTaskCondition::ArkTaskProperty s_ArkTaskProperty;
	uint64_t m_Task;
	
	class ArkStateProperty : public ArkProperty // Id=8013C08 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkObjectiveTaskCondition::ArkStateProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068D50);
	};

	static ArkObjectiveTaskCondition::ArkStateProperty s_ArkStateProperty;
	EArkObjectiveTaskState m_State;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	void SetTask(uint64_t arg0);
	const uint64_t &GetTask() const;
	void SetState(string arg0);
	EArkObjectiveTaskState const &GetState() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B260);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106BEB0);
	static inline auto FEvaluate = PreyFunction<bool(ArkObjectiveTaskCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0C90);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkObjectiveTaskCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C860);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkInteractedWithCondition : public ArkCondition // Id=8013C09 Size=40
{
public:
	class ArkArchetypeProperty : public ArkProperty // Id=8013C0A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInteractedWithCondition::ArkArchetypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360300);
	};

	static ArkInteractedWithCondition::ArkArchetypeProperty s_ArkArchetypeProperty;
	string m_Archetype;
	
	class ArkMetaTagsProperty : public ArkProperty // Id=8013C0B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInteractedWithCondition::ArkMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10689B0);
	};

	static ArkInteractedWithCondition::ArkMetaTagsProperty s_ArkMetaTagsProperty;
	std::vector<unsigned __int64> m_MetaTags;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	void SetArchetype(string arg0);
	uint64_t GetArchetype() const;
	string const &GetArchetypeString() const;
	void SetMetaTags(string arg0);
	std::vector<unsigned __int64> const &GetMetaTags() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AF20);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106BB90);
	static inline auto FEvaluate = PreyFunction<bool(ArkInteractedWithCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0930);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkInteractedWithCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C790);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkLookingAtCondition : public ArkCondition // Id=8013C0C Size=48
{
public:
	class ArkArchetypeProperty : public ArkProperty // Id=8013C0D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLookingAtCondition::ArkArchetypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360300);
	};

	static ArkLookingAtCondition::ArkArchetypeProperty s_ArkArchetypeProperty;
	string m_Archetype;
	
	class ArkMetaTagsProperty : public ArkProperty // Id=8013C0E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLookingAtCondition::ArkMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10689B0);
	};

	static ArkLookingAtCondition::ArkMetaTagsProperty s_ArkMetaTagsProperty;
	std::vector<unsigned __int64> m_MetaTags;
	
	class ArkCheckIsAliveProperty : public ArkProperty // Id=8013C0F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLookingAtCondition::ArkCheckIsAliveProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLookingAtCondition::ArkCheckIsAliveProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221B60);
	};

	static ArkLookingAtCondition::ArkCheckIsAliveProperty s_ArkCheckIsAliveProperty;
	bool m_CheckIsAlive;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	
#if 0
	void SetArchetype(string arg0);
	uint64_t GetArchetype() const;
	string const &GetArchetypeString() const;
	void SetMetaTags(string arg0);
	std::vector<unsigned __int64> const &GetMetaTags() const;
	void SetCheckIsAlive(bool arg0);
	const bool &GetCheckIsAlive() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B030);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106BD70);
	static inline auto FEvaluate = PreyFunction<bool(ArkLookingAtCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0B00);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkLookingAtNearCondition : public ArkLookingAtCondition // Id=8013C10 Size=48
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B0F0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkLookingAtNearCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C7B0);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkLookingAtFarCondition : public ArkLookingAtCondition // Id=8013C11 Size=48
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B090);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkLookingAtFarCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C7A0);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkAbilityAcquiredCondition : public ArkCondition // Id=8013C12 Size=16
{
public:
	class ArkAbilityProperty : public ArkProperty // Id=8013C13 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbilityAcquiredCondition::ArkAbilityProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbilityAcquiredCondition::ArkAbilityProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkAbilityAcquiredCondition::ArkAbilityProperty s_ArkAbilityProperty;
	uint64_t m_Ability;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
	void SetAbility(uint64_t arg0);
	const uint64_t &GetAbility() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106A880);
	static inline auto FEvaluate = PreyFunction<bool(ArkAbilityAcquiredCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0500);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkAbilityAcquiredCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C620);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkTutorialOnCooldownCondition : public ArkCondition // Id=8013C14 Size=16
{
public:
	class ArkTutorialProperty : public ArkProperty // Id=8013C15 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTutorialOnCooldownCondition::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTutorialOnCooldownCondition::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkTutorialOnCooldownCondition::ArkTutorialProperty s_ArkTutorialProperty;
	uint64_t m_Tutorial;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
	void SetTutorial(uint64_t arg0);
	const uint64_t &GetTutorial() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B3A0);
	static inline auto FEvaluate = PreyFunction<bool(ArkTutorialOnCooldownCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0E20);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkTutorialOnCooldownCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C8C0);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkConditionExecutedCondition : public ArkCondition // Id=8013C16 Size=24
{
public:
	class ArkGameStateConditionProperty : public ArkProperty // Id=8013C17 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkConditionExecutedCondition::ArkGameStateConditionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkConditionExecutedCondition::ArkGameStateConditionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkConditionExecutedCondition::ArkGameStateConditionProperty s_ArkGameStateConditionProperty;
	uint64_t m_GameStateCondition;
	
	class ArkCountProperty : public ArkProperty // Id=8013C18 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkConditionExecutedCondition::ArkCountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068E40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkConditionExecutedCondition::ArkCountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkConditionExecutedCondition::ArkCountProperty s_ArkCountProperty;
	int m_Count;
	
	class ArkComparisonTypeProperty : public ArkProperty // Id=8013C19 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkConditionExecutedCondition::ArkComparisonTypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10686A0);
	};

	static ArkConditionExecutedCondition::ArkComparisonTypeProperty s_ArkComparisonTypeProperty;
	EArkComparisonType m_ComparisonType;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	void SetGameStateCondition(uint64_t arg0);
	const uint64_t &GetGameStateCondition() const;
	void SetCount(int arg0);
	const int &GetCount() const;
	void SetComparisonType(string arg0);
	EArkComparisonType const &GetComparisonType() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AA10);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106B500);
	static inline auto FEvaluate = PreyFunction<bool(ArkConditionExecutedCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0540);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkConditionExecutedCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C640);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkFlashlightOnCondition : public ArkCondition // Id=8013C1A Size=8
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106ACB0);
	static inline auto FEvaluate = PreyFunction<bool(ArkFlashlightOnCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0710);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkFlashlightOnCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C670);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkWeaponDurabilityCondition : public ArkCondition // Id=8013C1B Size=16
{
public:
	class ArkAmountProperty : public ArkProperty // Id=8013C1C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponDurabilityCondition::ArkAmountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponDurabilityCondition::ArkAmountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkWeaponDurabilityCondition::ArkAmountProperty s_ArkAmountProperty;
	float m_Amount;
	
	class ArkComparisonTypeProperty : public ArkProperty // Id=8013C1D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponDurabilityCondition::ArkComparisonTypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068C70);
	};

	static ArkWeaponDurabilityCondition::ArkComparisonTypeProperty s_ArkComparisonTypeProperty;
	EArkComparisonType m_ComparisonType;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	void SetAmount(float arg0);
	const float &GetAmount() const;
	void SetComparisonType(string arg0);
	EArkComparisonType const &GetComparisonType() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B3F0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106BFF0);
	static inline auto FEvaluate = PreyFunction<bool(ArkWeaponDurabilityCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0E50);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkWeaponDurabilityCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C8E0);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkGameMetricCondition : public ArkCondition // Id=8013C1E Size=24
{
public:
	class ArkGameMetricProperty : public ArkProperty // Id=8013C1F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMetricCondition::ArkGameMetricProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMetricCondition::ArkGameMetricProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkGameMetricCondition::ArkGameMetricProperty s_ArkGameMetricProperty;
	uint64_t m_GameMetric;
	
	class ArkValueProperty : public ArkProperty // Id=8013C20 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMetricCondition::ArkValueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068E40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMetricCondition::ArkValueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkGameMetricCondition::ArkValueProperty s_ArkValueProperty;
	float m_Value;
	
	class ArkComparisonTypeProperty : public ArkProperty // Id=8013C21 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMetricCondition::ArkComparisonTypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10686A0);
	};

	static ArkGameMetricCondition::ArkComparisonTypeProperty s_ArkComparisonTypeProperty;
	EArkComparisonType m_ComparisonType;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	void SetGameMetric(uint64_t arg0);
	const uint64_t &GetGameMetric() const;
	void SetValue(float arg0);
	const float &GetValue() const;
	void SetComparisonType(string arg0);
	EArkComparisonType const &GetComparisonType() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AD60);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106B8C0);
	static inline auto FEvaluate = PreyFunction<bool(ArkGameMetricCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0750);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkGameMetricCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C6F0);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkTraumaActiveCondition : public ArkCondition // Id=8013C22 Size=16
{
public:
	class ArkTraumaProperty : public ArkProperty // Id=8013C23 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTraumaActiveCondition::ArkTraumaProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTraumaActiveCondition::ArkTraumaProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkTraumaActiveCondition::ArkTraumaProperty s_ArkTraumaProperty;
	uint64_t m_Trauma;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
	void SetTrauma(uint64_t arg0);
	const uint64_t &GetTrauma() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B350);
	static inline auto FEvaluate = PreyFunction<bool(ArkTraumaActiveCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C0DE0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkTraumaActiveCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C8A0);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkPlayerInCombatCondition : public ArkCondition // Id=8013C24 Size=8
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106B2B0);
	static inline auto FEvaluate = PreyFunction<bool(ArkPlayerInCombatCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x15514A0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkPlayerInCombatCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C880);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkDifficultyOptionCondition : public ArkCondition // Id=8013C25 Size=16
{
public:
	class ArkDifficultyOptionProperty : public ArkProperty // Id=8013C26 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDifficultyOptionCondition::ArkDifficultyOptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068930);
	};

	static ArkDifficultyOptionCondition::ArkDifficultyOptionProperty s_ArkDifficultyOptionProperty;
	EArkDifficultyOption m_DifficultyOption;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool Evaluate(ArkConditionEvaluationData const &_change) const;
	virtual bool RequiresReevaluation(ArkConditionEvaluationData const &_change) const;
	
#if 0
	static ArkClass *GetClass();
	void SetDifficultyOption(string arg0);
	EArkDifficultyOption const &GetDifficultyOption() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AB70);
	static inline auto FEvaluate = PreyFunction<bool(ArkDifficultyOptionCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x13C06E0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(ArkDifficultyOptionCondition const *const _this, ArkConditionEvaluationData const &_change)>(0x106C660);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkAutoSaveResult : public ArkConditionResult // Id=8013C28 Size=8
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual void Execute(uint64_t _parentCondition) const;
	
#if 0
	static ArkClass *GetClass();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106A920);
	static inline auto FExecute = PreyFunction<void(ArkAutoSaveResult const *const _this, uint64_t _parentCondition)>(0x13C1110);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkDisplayTutorialResult : public ArkConditionResult // Id=8013C29 Size=16
{
public:
	class ArkTutorialProperty : public ArkProperty // Id=8013C2A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisplayTutorialResult::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisplayTutorialResult::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkDisplayTutorialResult::ArkTutorialProperty s_ArkTutorialProperty;
	uint64_t m_Tutorial;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual void Execute(uint64_t _parentCondition) const;
	
#if 0
	static ArkClass *GetClass();
	void SetTutorial(uint64_t arg0);
	const uint64_t &GetTutorial() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AC10);
	static inline auto FExecute = PreyFunction<void(ArkDisplayTutorialResult const *const _this, uint64_t _parentCondition)>(0x13C1230);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkCollectTutorialResult : public ArkConditionResult // Id=8013C2B Size=16
{
public:
	class ArkTutorialProperty : public ArkProperty // Id=8013C2C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCollectTutorialResult::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCollectTutorialResult::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkCollectTutorialResult::ArkTutorialProperty s_ArkTutorialProperty;
	uint64_t m_Tutorial;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual void Execute(uint64_t _parentCondition) const;
	
#if 0
	static ArkClass *GetClass();
	void SetTutorial(uint64_t arg0);
	const uint64_t &GetTutorial() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106A970);
	static inline auto FExecute = PreyFunction<void(ArkCollectTutorialResult const *const _this, uint64_t _parentCondition)>(0x13C1130);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkDisplayPromptTutorialCallbackResult : public ArkConditionResult // Id=8013C2D Size=24
{
public:
	class ArkPromptTutorialProperty : public ArkProperty // Id=8013C2E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisplayPromptTutorialCallbackResult::ArkPromptTutorialProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisplayPromptTutorialCallbackResult::ArkPromptTutorialProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkDisplayPromptTutorialCallbackResult::ArkPromptTutorialProperty s_ArkPromptTutorialProperty;
	uint64_t m_PromptTutorial;
	
	class ArkCardTutorialProperty : public ArkProperty // Id=8013C2F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisplayPromptTutorialCallbackResult::ArkCardTutorialProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068BA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisplayPromptTutorialCallbackResult::ArkCardTutorialProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkDisplayPromptTutorialCallbackResult::ArkCardTutorialProperty s_ArkCardTutorialProperty;
	uint64_t m_CardTutorial;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual void Execute(uint64_t _parentCondition) const;
	void CallbackTriggered() const { FCallbackTriggered(this); }
	
#if 0
	void SetPromptTutorial(uint64_t arg0);
	const uint64_t &GetPromptTutorial() const;
	void SetCardTutorial(uint64_t arg0);
	const uint64_t &GetCardTutorial() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106ABC0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106B780);
	static inline auto FExecute = PreyFunction<void(ArkDisplayPromptTutorialCallbackResult const *const _this, uint64_t _parentCondition)>(0x13C11A0);
	static inline auto FCallbackTriggered = PreyFunction<void(ArkDisplayPromptTutorialCallbackResult const *const _this)>(0x13C04B0);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkEnableGameStateConditionResult : public ArkConditionResult // Id=8013C30 Size=24
{
public:
	class ArkGameStateConditionProperty : public ArkProperty // Id=8013C31 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEnableGameStateConditionResult::ArkGameStateConditionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEnableGameStateConditionResult::ArkGameStateConditionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkEnableGameStateConditionResult::ArkGameStateConditionProperty s_ArkGameStateConditionProperty;
	uint64_t m_GameStateCondition;
	
	class ArkEnableProperty : public ArkProperty // Id=8013C32 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEnableGameStateConditionResult::ArkEnableProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068BC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEnableGameStateConditionResult::ArkEnableProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkEnableGameStateConditionResult::ArkEnableProperty s_ArkEnableProperty;
	bool m_Enable;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual void Execute(uint64_t _parentCondition) const;
	
#if 0
	void SetGameStateCondition(uint64_t arg0);
	const uint64_t &GetGameStateCondition() const;
	void SetEnable(bool arg0);
	const bool &GetEnable() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AC60);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106B820);
	static inline auto FExecute = PreyFunction<void(ArkEnableGameStateConditionResult const *const _this, uint64_t _parentCondition)>(0x13C1280);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkDelayedResult : public ArkConditionResult // Id=8013C33 Size=40
{
public:
	class ArkDelayProperty : public ArkProperty // Id=8013C34 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDelayedResult::ArkDelayProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDelayedResult::ArkDelayProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkDelayedResult::ArkDelayProperty s_ArkDelayProperty;
	float m_Delay;
	
	class ArkResultsProperty : public ArkProperty // Id=8013C35 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDelayedResult::ArkResultsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068BE0);
		static inline auto FIsArray = PreyFunction<bool(ArkDelayedResult::ArkResultsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkDelayedResult::ArkResultsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1068C30);
	};

	static ArkDelayedResult::ArkResultsProperty s_ArkResultsProperty;
	std::vector<std::shared_ptr<ArkConditionResult>> m_Results;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual void Execute(uint64_t _parentCondition) const;
	virtual bool IsDelayedResult() const;
	
#if 0
	void SetDelay(float arg0);
	const float &GetDelay() const;
	std::vector<std::shared_ptr<ArkConditionResult>> &GetResults();
	std::vector<std::shared_ptr<ArkConditionResult>> const &GetResults() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AB10);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106B6E0);
	static inline auto FExecute = PreyFunction<void(ArkDelayedResult const *const _this, uint64_t _parentCondition)>(0x13C1160);
	static inline auto FIsDelayedResult = PreyFunction<bool(ArkDelayedResult const *const _this)>(0x1B933B0);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkLockTipResult : public ArkConditionResult // Id=8013C46 Size=24
{
public:
	class ArkTipLockProperty : public ArkProperty // Id=8013C47 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLockTipResult::ArkTipLockProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLockTipResult::ArkTipLockProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkLockTipResult::ArkTipLockProperty s_ArkTipLockProperty;
	uint64_t m_TipLock;
	
	class ArkLockedProperty : public ArkProperty // Id=8013C48 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLockTipResult::ArkLockedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068BC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLockTipResult::ArkLockedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkLockTipResult::ArkLockedProperty s_ArkLockedProperty;
	bool m_Locked;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual void Execute(uint64_t _parentCondition) const;
	
#if 0
	void SetTipLock(uint64_t arg0);
	const uint64_t &GetTipLock() const;
	void SetLocked(bool arg0);
	const bool &GetLocked() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AFE0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106BCD0);
	static inline auto FExecute = PreyFunction<void(ArkLockTipResult const *const _this, uint64_t _parentCondition)>(0x13C1320);
};

// Header: Exact
// Prey/Ark/arkgamestatecondition.h
class ArkGameStateConditionLibrary : public ArkReflectedLibrary // Id=8013C5C Size=32
{
public:
	class ArkGameStateConditionsProperty : public ArkProperty // Id=8013C5D Size=32
	{
	public:
		ArkGameStateConditionsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameStateConditionLibrary::ArkGameStateConditionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068700);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameStateConditionLibrary::ArkGameStateConditionsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10687D0);
		static inline auto FIsArray = PreyFunction<bool(ArkGameStateConditionLibrary::ArkGameStateConditionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkGameStateConditionLibrary::ArkGameStateConditionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1068810);
	};

	static ArkGameStateConditionLibrary::ArkGameStateConditionsProperty s_ArkGameStateConditionsProperty;
	std::vector<ArkGameStateCondition> m_GameStateConditions;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkGameStateConditionLibrary();
	
#if 0
	std::vector<ArkGameStateCondition> &GetGameStateConditions();
	std::vector<ArkGameStateCondition> const &GetGameStateConditions() const;
	ArkGameStateCondition const *FindCondition(const uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AE10);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106BA00);
	static inline auto FInit = PreyFunction<bool(ArkGameStateConditionLibrary *const _this)>(0x106C090);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class ArkConditionEvaluationData;
class IArkValueBase;

// ArkCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkCondition : public ArkReflectedObject
{ // Size=8 (0x8)
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkCondition();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E770);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F210);
	static inline auto FEvaluate = PreyFunction<bool(const ArkCondition* const _this, const ArkConditionEvaluationData& _change)>(0x13B0900);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkCondition* const _this, const ArkConditionEvaluationData& _change)>(0x13B0900);
};

// ArkConditionGroup
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkConditionGroup : public ArkCondition
{ // Size=40 (0x28)
public:
	// ArkConditionGroup::ArkAndProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkAndProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAndProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkConditionGroup::ArkAndProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CBD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkConditionGroup::ArkAndProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkConditionGroup::ArkConditionsProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkConditionsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkConditionsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkConditionGroup::ArkConditionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CBF0);
		static inline auto FIsArray = PreyFunction<bool(const ArkConditionGroup::ArkConditionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkConditionGroup::ArkConditionsProperty* const _this, ArkReflectedObject* _pObject)>(0x108CC40);
	};

	static inline auto s_ArkAndProperty = PreyGlobal<ArkConditionGroup::ArkAndProperty>(0x2D24530);
	bool m_And;
	static inline auto s_ArkConditionsProperty = PreyGlobal<ArkConditionGroup::ArkConditionsProperty>(0x2D24550);
	std::vector<std::shared_ptr<ArkCondition>> m_Conditions;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkConditionGroup();
	void SetAnd(bool _arg0_);
	const bool& GetAnd() const;
	std::vector<std::shared_ptr<ArkCondition>>& GetConditions();
	const std::vector<std::shared_ptr<ArkCondition>>& GetConditions() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E810);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F350);
	static inline auto FEvaluate = PreyFunction<bool(const ArkConditionGroup* const _this, const ArkConditionEvaluationData& _change)>(0x108CDF0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkConditionGroup* const _this, const ArkConditionEvaluationData& _change)>(0x108CE60);
};

// ArkGameStateCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkGameStateCondition : public ArkReflectedObject
{ // Size=88 (0x58)
public:
	// ArkGameStateCondition::ArkIDProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameStateCondition::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameStateCondition::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkGameStateCondition::ArkNameProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameStateCondition::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameStateCondition::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkGameStateCondition::ArkEnabledProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkEnabledProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEnabledProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameStateCondition::ArkEnabledProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameStateCondition::ArkEnabledProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkGameStateCondition::ArkConditionGroupProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkConditionGroupProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkConditionGroupProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameStateCondition::ArkConditionGroupProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameStateCondition::ArkConditionGroupProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CFC0);
	};

	// ArkGameStateCondition::ArkResultsProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkResultsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkResultsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameStateCondition::ArkResultsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D040);
		static inline auto FIsArray = PreyFunction<bool(const ArkGameStateCondition::ArkResultsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkGameStateCondition::ArkResultsProperty* const _this, ArkReflectedObject* _pObject)>(0x108D090);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkGameStateCondition::ArkIDProperty>(0x2D24AB0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkGameStateCondition::ArkNameProperty>(0x2D24AD0);
	string m_Name;
	static inline auto s_ArkEnabledProperty = PreyGlobal<ArkGameStateCondition::ArkEnabledProperty>(0x2D24AF0);
	bool m_Enabled;
	static inline auto s_ArkConditionGroupProperty = PreyGlobal<ArkGameStateCondition::ArkConditionGroupProperty>(0x2D24B10);
	ArkConditionGroup m_ConditionGroup;
	static inline auto s_ArkResultsProperty = PreyGlobal<ArkGameStateCondition::ArkResultsProperty>(0x2D24B30);
	std::vector<std::shared_ptr<ArkConditionResult>> m_Results;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkGameStateCondition();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetEnabled(bool _arg0_);
	const bool& GetEnabled() const;
	void SetConditionGroup(ArkConditionGroup _arg0_);
	const ArkConditionGroup& GetConditionGroup() const;
	std::vector<std::shared_ptr<ArkConditionResult>>& GetResults();
	const std::vector<std::shared_ptr<ArkConditionResult>>& GetResults() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EB60);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F7B0);
};

// ArkItemCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkItemCondition : public ArkCondition
{ // Size=48 (0x30)
public:
	// ArkItemCondition::ArkArchetypeProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkItemCondition::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443660);
	};

	// ArkItemCondition::ArkMetaTagsProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkMetaTagsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkMetaTagsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkItemCondition::ArkMetaTagsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CC80);
	};

	// ArkItemCondition::ArkQuantityProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkQuantityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkQuantityProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkItemCondition::ArkQuantityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D310);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkItemCondition::ArkQuantityProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B470);
	};

	// ArkItemCondition::ArkComparisonTypeProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkComparisonTypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkComparisonTypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkItemCondition::ArkComparisonTypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D330);
	};

	static inline auto s_ArkArchetypeProperty = PreyGlobal<ArkItemCondition::ArkArchetypeProperty>(0x2D24590);
	string m_Archetype;
	static inline auto s_ArkMetaTagsProperty = PreyGlobal<ArkItemCondition::ArkMetaTagsProperty>(0x2D245B0);
	std::vector<uint64_t> m_MetaTags;
	static inline auto s_ArkQuantityProperty = PreyGlobal<ArkItemCondition::ArkQuantityProperty>(0x2D245D0);
	int m_Quantity;
	static inline auto s_ArkComparisonTypeProperty = PreyGlobal<ArkItemCondition::ArkComparisonTypeProperty>(0x2D245F0);
	EArkComparisonType m_ComparisonType;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	bool EvaluateGainOrLoss(const ArkConditionEvaluationData& _change) const { return FEvaluateGainOrLoss(this, _change); }

#if 0
	ArkItemCondition();
	void SetArchetype(string _arg0_);
	uint64_t GetArchetype() const;
	const string& GetArchetypeString() const;
	void SetMetaTags(string _arg0_);
	const std::vector<uint64_t>& GetMetaTags() const;
	void SetQuantity(int _arg0_);
	const int& GetQuantity() const;
	void SetComparisonType(string _arg0_);
	const EArkComparisonType& GetComparisonType() const;
	bool TestForReevaluation(const ArkConditionEvaluationData& _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108ED30);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108FA80);
	static inline auto FEvaluate = PreyFunction<bool(const ArkItemCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CCAE0);
	static inline auto FEvaluateGainOrLoss = PreyFunction<bool(const ArkItemCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CD030);
};

// ArkLookingAtCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkLookingAtCondition : public ArkCondition
{ // Size=48 (0x30)
public:
	// ArkLookingAtCondition::ArkArchetypeProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLookingAtCondition::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443660);
	};

	// ArkLookingAtCondition::ArkMetaTagsProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkMetaTagsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkMetaTagsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLookingAtCondition::ArkMetaTagsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CC80);
	};

	// ArkLookingAtCondition::ArkCheckIsAliveProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkCheckIsAliveProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCheckIsAliveProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLookingAtCondition::ArkCheckIsAliveProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CDC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLookingAtCondition::ArkCheckIsAliveProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B470);
	};

	static inline auto s_ArkArchetypeProperty = PreyGlobal<ArkLookingAtCondition::ArkArchetypeProperty>(0x2D24750);
	string m_Archetype;
	static inline auto s_ArkMetaTagsProperty = PreyGlobal<ArkLookingAtCondition::ArkMetaTagsProperty>(0x2D24770);
	std::vector<uint64_t> m_MetaTags;
	static inline auto s_ArkCheckIsAliveProperty = PreyGlobal<ArkLookingAtCondition::ArkCheckIsAliveProperty>(0x2D24790);
	bool m_CheckIsAlive;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkLookingAtCondition();
	void SetArchetype(string _arg0_);
	uint64_t GetArchetype() const;
	const string& GetArchetypeString() const;
	void SetMetaTags(string _arg0_);
	const std::vector<uint64_t>& GetMetaTags() const;
	void SetCheckIsAlive(bool _arg0_);
	const bool& GetCheckIsAlive() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EDE0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108FBC0);
	static inline auto FEvaluate = PreyFunction<bool(const ArkLookingAtCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CCBF0);
};

// ArkAbilityAcquiredCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkAbilityAcquiredCondition : public ArkCondition
{ // Size=16 (0x10)
public:
	// ArkAbilityAcquiredCondition::ArkAbilityProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkAbilityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAbilityProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbilityAcquiredCondition::ArkAbilityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityAcquiredCondition::ArkAbilityProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	static inline auto s_ArkAbilityProperty = PreyGlobal<ArkAbilityAcquiredCondition::ArkAbilityProperty>(0x2D247B0);
	uint64_t m_Ability;

	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkAbilityAcquiredCondition();
	static ArkClass* GetClass();
	void SetAbility(uint64_t _arg0_);
	const uint64_t& GetAbility() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E630);
	static inline auto FEvaluate = PreyFunction<bool(const ArkAbilityAcquiredCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CC5C0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkAbilityAcquiredCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090420);
};

// ArkAcquiredChipsetCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkAcquiredChipsetCondition : public ArkCondition
{ // Size=8 (0x8)
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkAcquiredChipsetCondition();
	static ArkClass* GetClass();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E680);
	static inline auto FEvaluate = PreyFunction<bool(const ArkAcquiredChipsetCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090440);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkAcquiredChipsetCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090440);
};

// ArkConditionExecutedCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkConditionExecutedCondition : public ArkCondition
{ // Size=24 (0x18)
public:
	// ArkConditionExecutedCondition::ArkGameStateConditionProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkGameStateConditionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkGameStateConditionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkConditionExecutedCondition::ArkGameStateConditionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkConditionExecutedCondition::ArkGameStateConditionProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkConditionExecutedCondition::ArkCountProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkCountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkConditionExecutedCondition::ArkCountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C1F50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkConditionExecutedCondition::ArkCountProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9CA0);
	};

	// ArkConditionExecutedCondition::ArkComparisonTypeProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkComparisonTypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkComparisonTypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkConditionExecutedCondition::ArkComparisonTypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CFE0);
	};

	static inline auto s_ArkGameStateConditionProperty = PreyGlobal<ArkConditionExecutedCondition::ArkGameStateConditionProperty>(0x2D247F0);
	uint64_t m_GameStateCondition;
	static inline auto s_ArkCountProperty = PreyGlobal<ArkConditionExecutedCondition::ArkCountProperty>(0x2D24810);
	int m_Count;
	static inline auto s_ArkComparisonTypeProperty = PreyGlobal<ArkConditionExecutedCondition::ArkComparisonTypeProperty>(0x2D24830);
	EArkComparisonType m_ComparisonType;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkConditionExecutedCondition();
	void SetGameStateCondition(uint64_t _arg0_);
	const uint64_t& GetGameStateCondition() const;
	void SetCount(int _arg0_);
	const int& GetCount() const;
	void SetComparisonType(string _arg0_);
	const EArkComparisonType& GetComparisonType() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E7C0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F2B0);
	static inline auto FEvaluate = PreyFunction<bool(const ArkConditionExecutedCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CC5F0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkConditionExecutedCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090450);
};

// ArkDoomClockLevelCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkDoomClockLevelCondition : public ArkCondition
{ // Size=16 (0x10)
public:
	// ArkDoomClockLevelCondition::ArkLevelProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkLevelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLevelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockLevelCondition::ArkLevelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D2F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockLevelCondition::ArkLevelProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkDoomClockLevelCondition::ArkComparisonTypeProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkComparisonTypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkComparisonTypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockLevelCondition::ArkComparisonTypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CEC0);
	};

	static inline auto s_ArkLevelProperty = PreyGlobal<ArkDoomClockLevelCondition::ArkLevelProperty>(0x2D24910);
	int m_Level;
	static inline auto s_ArkComparisonTypeProperty = PreyGlobal<ArkDoomClockLevelCondition::ArkComparisonTypeProperty>(0x2D24930);
	EArkComparisonType m_ComparisonType;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkDoomClockLevelCondition();
	void SetLevel(int _arg0_);
	const int& GetLevel() const;
	void SetComparisonType(string _arg0_);
	const EArkComparisonType& GetComparisonType() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E9C0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F5D0);
	static inline auto FEvaluate = PreyFunction<bool(const ArkDoomClockLevelCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CC790);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkDoomClockLevelCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090470);
};

// ArkFlashlightOnCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkFlashlightOnCondition : public ArkCondition
{ // Size=8 (0x8)
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkFlashlightOnCondition();
	static ArkClass* GetClass();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EA60);
	static inline auto FEvaluate = PreyFunction<bool(const ArkFlashlightOnCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CC810);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkFlashlightOnCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090480);
};

// ArkGainedItemCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkGainedItemCondition : public ArkItemCondition
{ // Size=48 (0x30)
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkGainedItemCondition();
	static ArkClass* GetClass();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EAB0);
	static inline auto FEvaluate = PreyFunction<bool(const ArkGainedItemCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CC840);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkGainedItemCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090490);
};

// ArkGameMetricCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkGameMetricCondition : public ArkCondition
{ // Size=24 (0x18)
public:
	// ArkGameMetricCondition::ArkGameMetricProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkGameMetricProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkGameMetricProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricCondition::ArkGameMetricProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricCondition::ArkGameMetricProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkGameMetricCondition::ArkValueProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkValueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkValueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricCondition::ArkValueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C1F50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricCondition::ArkValueProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9CA0);
	};

	// ArkGameMetricCondition::ArkComparisonTypeProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkComparisonTypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkComparisonTypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricCondition::ArkComparisonTypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CFE0);
	};

	static inline auto s_ArkGameMetricProperty = PreyGlobal<ArkGameMetricCondition::ArkGameMetricProperty>(0x2D24890);
	uint64_t m_GameMetric;
	static inline auto s_ArkValueProperty = PreyGlobal<ArkGameMetricCondition::ArkValueProperty>(0x2D248B0);
	float m_Value;
	static inline auto s_ArkComparisonTypeProperty = PreyGlobal<ArkGameMetricCondition::ArkComparisonTypeProperty>(0x2D248D0);
	EArkComparisonType m_ComparisonType;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkGameMetricCondition();
	void SetGameMetric(uint64_t _arg0_);
	const uint64_t& GetGameMetric() const;
	void SetValue(float _arg0_);
	const float& GetValue() const;
	void SetComparisonType(string _arg0_);
	const EArkComparisonType& GetComparisonType() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EB10);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F710);
	static inline auto FEvaluate = PreyFunction<bool(const ArkGameMetricCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CC850);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkGameMetricCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090500);
};

// ArkGameStateConditionLibrary
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkGameStateConditionLibrary : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkGameStateConditionLibrary::ArkGameStateConditionsProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkGameStateConditionsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkGameStateConditionsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkGameStateConditionsPropertyOv2 = PreyFunction<void(ArkGameStateConditionLibrary::ArkGameStateConditionsProperty* const _this)>(0x108E310);
		static inline auto FSetValue = PreyFunction<void(const ArkGameStateConditionLibrary::ArkGameStateConditionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D0C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameStateConditionLibrary::ArkGameStateConditionsProperty* const _this, ArkReflectedObject* const _pObject)>(0x108D190);
		static inline auto FIsArray = PreyFunction<bool(const ArkGameStateConditionLibrary::ArkGameStateConditionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkGameStateConditionLibrary::ArkGameStateConditionsProperty* const _this, ArkReflectedObject* _pObject)>(0x108D1D0);
	};

	static inline auto s_ArkGameStateConditionsProperty = PreyGlobal<ArkGameStateConditionLibrary::ArkGameStateConditionsProperty>(0x2D24B50);
	std::vector<ArkGameStateCondition> m_GameStateConditions;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	std::vector<ArkGameStateCondition>& GetGameStateConditions();
	const std::vector<ArkGameStateCondition>& GetGameStateConditions() const;
	const ArkGameStateCondition* FindCondition(const uint64_t _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EBC0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F850);
	static inline auto FInit = PreyFunction<bool(ArkGameStateConditionLibrary* const _this)>(0x108FEE0);
};

// ArkHasItemCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkHasItemCondition : public ArkItemCondition
{ // Size=48 (0x30)
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkHasItemCondition();
	static ArkClass* GetClass();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EC20);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkHasItemCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090520);
};

// ArkHealthAmountCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkHealthAmountCondition : public ArkCondition
{ // Size=16 (0x10)
public:
	// ArkHealthAmountCondition::ArkAmountProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkAmountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAmountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkHealthAmountCondition::ArkAmountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D2F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkHealthAmountCondition::ArkAmountProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkHealthAmountCondition::ArkComparisonTypeProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkComparisonTypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkComparisonTypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkHealthAmountCondition::ArkComparisonTypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CEC0);
	};

	static inline auto s_ArkAmountProperty = PreyGlobal<ArkHealthAmountCondition::ArkAmountProperty>(0x2D24610);
	float m_Amount;
	static inline auto s_ArkComparisonTypeProperty = PreyGlobal<ArkHealthAmountCondition::ArkComparisonTypeProperty>(0x2D24630);
	EArkComparisonType m_ComparisonType;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkHealthAmountCondition();
	void SetAmount(float _arg0_);
	const float& GetAmount() const;
	void SetComparisonType(string _arg0_);
	const EArkComparisonType& GetComparisonType() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EC80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F940);
	static inline auto FEvaluate = PreyFunction<bool(const ArkHealthAmountCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CC950);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkHealthAmountCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090590);
};

// ArkInteractedWithCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkInteractedWithCondition : public ArkCondition
{ // Size=40 (0x28)
public:
	// ArkInteractedWithCondition::ArkArchetypeProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInteractedWithCondition::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443660);
	};

	// ArkInteractedWithCondition::ArkMetaTagsProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkMetaTagsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkMetaTagsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInteractedWithCondition::ArkMetaTagsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CC80);
	};

	static inline auto s_ArkArchetypeProperty = PreyGlobal<ArkInteractedWithCondition::ArkArchetypeProperty>(0x2D24710);
	string m_Archetype;
	static inline auto s_ArkMetaTagsProperty = PreyGlobal<ArkInteractedWithCondition::ArkMetaTagsProperty>(0x2D24730);
	std::vector<uint64_t> m_MetaTags;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkInteractedWithCondition();
	void SetArchetype(string _arg0_);
	uint64_t GetArchetype() const;
	const string& GetArchetypeString() const;
	void SetMetaTags(string _arg0_);
	const std::vector<uint64_t>& GetMetaTags() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108ECD0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F9E0);
	static inline auto FEvaluate = PreyFunction<bool(const ArkInteractedWithCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CCA30);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkInteractedWithCondition* const _this, const ArkConditionEvaluationData& _change)>(0x10905A0);
};

// ArkLookingAtFarCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkLookingAtFarCondition : public ArkLookingAtCondition
{ // Size=48 (0x30)
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkLookingAtFarCondition();
	static ArkClass* GetClass();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EE40);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkLookingAtFarCondition* const _this, const ArkConditionEvaluationData& _change)>(0x10905B0);
};

// ArkLookingAtNearCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkLookingAtNearCondition : public ArkLookingAtCondition
{ // Size=48 (0x30)
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkLookingAtNearCondition();
	static ArkClass* GetClass();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EEA0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkLookingAtNearCondition* const _this, const ArkConditionEvaluationData& _change)>(0x10905C0);
};

// ArkLostItemCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkLostItemCondition : public ArkItemCondition
{ // Size=48 (0x30)
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkLostItemCondition();
	static ArkClass* GetClass();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EF00);
	static inline auto FEvaluate = PreyFunction<bool(const ArkLostItemCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CCD10);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkLostItemCondition* const _this, const ArkConditionEvaluationData& _change)>(0x10905D0);
};

// ArkNotCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkNotCondition : public ArkCondition
{ // Size=48 (0x30)
public:
	// ArkNotCondition::ArkConditionGroupProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkConditionGroupProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkConditionGroupProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNotCondition::ArkConditionGroupProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D270);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNotCondition::ArkConditionGroupProperty* const _this, ArkReflectedObject* const _pObject)>(0x14441D0);
	};

	static inline auto s_ArkConditionGroupProperty = PreyGlobal<ArkNotCondition::ArkConditionGroupProperty>(0x2D24570);
	ArkConditionGroup m_ConditionGroup;

	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkNotCondition();
	static ArkClass* GetClass();
	void SetConditionGroup(ArkConditionGroup _arg0_);
	const ArkConditionGroup& GetConditionGroup() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EF60);
	static inline auto FEvaluate = PreyFunction<bool(const ArkNotCondition* const _this, const ArkConditionEvaluationData& _change)>(0x108F1F0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkNotCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090640);
};

// ArkObjectiveCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkObjectiveCondition : public ArkCondition
{ // Size=24 (0x18)
public:
	// ArkObjectiveCondition::ArkObjectiveProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkObjectiveProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkObjectiveProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkObjectiveCondition::ArkObjectiveProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkObjectiveCondition::ArkObjectiveProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkObjectiveCondition::ArkStateProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkStateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkStateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkObjectiveCondition::ArkStateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CB10);
	};

	static inline auto s_ArkObjectiveProperty = PreyGlobal<ArkObjectiveCondition::ArkObjectiveProperty>(0x2D24690);
	uint64_t m_Objective;
	static inline auto s_ArkStateProperty = PreyGlobal<ArkObjectiveCondition::ArkStateProperty>(0x2D246B0);
	EArkObjectiveState m_State;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkObjectiveCondition();
	void SetObjective(uint64_t _arg0_);
	const uint64_t& GetObjective() const;
	void SetState(string _arg0_);
	const EArkObjectiveState& GetState() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EFC0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108FC60);
	static inline auto FEvaluate = PreyFunction<bool(const ArkObjectiveCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CCD20);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkObjectiveCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090650);
};

// ArkObjectiveTaskCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkObjectiveTaskCondition : public ArkCondition
{ // Size=24 (0x18)
public:
	// ArkObjectiveTaskCondition::ArkTaskProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkTaskProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTaskProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkObjectiveTaskCondition::ArkTaskProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkObjectiveTaskCondition::ArkTaskProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkObjectiveTaskCondition::ArkStateProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkStateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkStateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkObjectiveTaskCondition::ArkStateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CB70);
	};

	static inline auto s_ArkTaskProperty = PreyGlobal<ArkObjectiveTaskCondition::ArkTaskProperty>(0x2D246D0);
	uint64_t m_Task;
	static inline auto s_ArkStateProperty = PreyGlobal<ArkObjectiveTaskCondition::ArkStateProperty>(0x2D246F0);
	EArkObjectiveTaskState m_State;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkObjectiveTaskCondition();
	void SetTask(uint64_t _arg0_);
	const uint64_t& GetTask() const;
	void SetState(string _arg0_);
	const EArkObjectiveTaskState& GetState() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108F010);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108FD00);
	static inline auto FEvaluate = PreyFunction<bool(const ArkObjectiveTaskCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CCD80);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkObjectiveTaskCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090670);
};

// ArkPlayerInCombatCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkPlayerInCombatCondition : public ArkCondition
{ // Size=8 (0x8)
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkPlayerInCombatCondition();
	static ArkClass* GetClass();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108F060);
	static inline auto FEvaluate = PreyFunction<bool(const ArkPlayerInCombatCondition* const _this, const ArkConditionEvaluationData& _change)>(0x16768F0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkPlayerInCombatCondition* const _this, const ArkConditionEvaluationData& _change)>(0x1090690);
};

// ArkPsiAmountCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkPsiAmountCondition : public ArkCondition
{ // Size=16 (0x10)
public:
	// ArkPsiAmountCondition::ArkAmountProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkAmountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAmountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiAmountCondition::ArkAmountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D2F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiAmountCondition::ArkAmountProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkPsiAmountCondition::ArkComparisonTypeProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkComparisonTypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkComparisonTypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiAmountCondition::ArkComparisonTypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CEC0);
	};

	static inline auto s_ArkAmountProperty = PreyGlobal<ArkPsiAmountCondition::ArkAmountProperty>(0x2D24650);
	float m_Amount;
	static inline auto s_ArkComparisonTypeProperty = PreyGlobal<ArkPsiAmountCondition::ArkComparisonTypeProperty>(0x2D24670);
	EArkComparisonType m_ComparisonType;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkPsiAmountCondition();
	void SetAmount(float _arg0_);
	const float& GetAmount() const;
	void SetComparisonType(string _arg0_);
	const EArkComparisonType& GetComparisonType() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108F0B0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108FDA0);
	static inline auto FEvaluate = PreyFunction<bool(const ArkPsiAmountCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CCDE0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkPsiAmountCondition* const _this, const ArkConditionEvaluationData& _change)>(0x10906A0);
};

// ArkTraumaActiveCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkTraumaActiveCondition : public ArkCondition
{ // Size=16 (0x10)
public:
	// ArkTraumaActiveCondition::ArkTraumaProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkTraumaProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTraumaProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTraumaActiveCondition::ArkTraumaProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTraumaActiveCondition::ArkTraumaProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	static inline auto s_ArkTraumaProperty = PreyGlobal<ArkTraumaActiveCondition::ArkTraumaProperty>(0x2D248F0);
	uint64_t m_Trauma;

	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkTraumaActiveCondition();
	static ArkClass* GetClass();
	void SetTrauma(uint64_t _arg0_);
	const uint64_t& GetTrauma() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108F100);
	static inline auto FEvaluate = PreyFunction<bool(const ArkTraumaActiveCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CCED0);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkTraumaActiveCondition* const _this, const ArkConditionEvaluationData& _change)>(0x10906B0);
};

// ArkTutorialOnCooldownCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkTutorialOnCooldownCondition : public ArkCondition
{ // Size=16 (0x10)
public:
	// ArkTutorialOnCooldownCondition::ArkTutorialProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkTutorialProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTutorialProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTutorialOnCooldownCondition::ArkTutorialProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTutorialOnCooldownCondition::ArkTutorialProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	static inline auto s_ArkTutorialProperty = PreyGlobal<ArkTutorialOnCooldownCondition::ArkTutorialProperty>(0x2D247D0);
	uint64_t m_Tutorial;

	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkTutorialOnCooldownCondition();
	static ArkClass* GetClass();
	void SetTutorial(uint64_t _arg0_);
	const uint64_t& GetTutorial() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108F150);
	static inline auto FEvaluate = PreyFunction<bool(const ArkTutorialOnCooldownCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CCF10);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkTutorialOnCooldownCondition* const _this, const ArkConditionEvaluationData& _change)>(0x10906D0);
};

// ArkWeaponDurabilityCondition
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkWeaponDurabilityCondition : public ArkCondition
{ // Size=16 (0x10)
public:
	// ArkWeaponDurabilityCondition::ArkAmountProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkAmountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAmountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponDurabilityCondition::ArkAmountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D2F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponDurabilityCondition::ArkAmountProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkWeaponDurabilityCondition::ArkComparisonTypeProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkComparisonTypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkComparisonTypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponDurabilityCondition::ArkComparisonTypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CEC0);
	};

	static inline auto s_ArkAmountProperty = PreyGlobal<ArkWeaponDurabilityCondition::ArkAmountProperty>(0x2D24850);
	float m_Amount;
	static inline auto s_ArkComparisonTypeProperty = PreyGlobal<ArkWeaponDurabilityCondition::ArkComparisonTypeProperty>(0x2D24870);
	EArkComparisonType m_ComparisonType;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Evaluate(const ArkConditionEvaluationData& _change) const;
	virtual bool RequiresReevaluation(const ArkConditionEvaluationData& _change) const;

#if 0
	ArkWeaponDurabilityCondition();
	void SetAmount(float _arg0_);
	const float& GetAmount() const;
	void SetComparisonType(string _arg0_);
	const EArkComparisonType& GetComparisonType() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108F1A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108FE40);
	static inline auto FEvaluate = PreyFunction<bool(const ArkWeaponDurabilityCondition* const _this, const ArkConditionEvaluationData& _change)>(0x14CCF40);
	static inline auto FRequiresReevaluation = PreyFunction<bool(const ArkWeaponDurabilityCondition* const _this, const ArkConditionEvaluationData& _change)>(0x10906F0);
};

// ArkConditionResult
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkConditionResult : public ArkReflectedObject
{ // Size=8 (0x8)
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual void Execute(uint64_t _parentCondition) const;
	virtual bool IsDelayedResult() const;

#if 0
	ArkConditionResult();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E870);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F3F0);
	static inline auto FExecute = PreyFunction<void(const ArkConditionResult* const _this, uint64_t _parentCondition)>(0x1333E90);
	static inline auto FIsDelayedResult = PreyFunction<bool(const ArkConditionResult* const _this)>(0x13B0900);
};

// ArkCollectTutorialResult
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkCollectTutorialResult : public ArkConditionResult
{ // Size=16 (0x10)
public:
	// ArkCollectTutorialResult::ArkTutorialProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkTutorialProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTutorialProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCollectTutorialResult::ArkTutorialProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCollectTutorialResult::ArkTutorialProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	static inline auto s_ArkTutorialProperty = PreyGlobal<ArkCollectTutorialResult::ArkTutorialProperty>(0x2D24970);
	uint64_t m_Tutorial;

	static ArkReflectedObject* Create() { return FCreate(); }
	virtual void Execute(uint64_t _parentCondition) const;

#if 0
	ArkCollectTutorialResult();
	static ArkClass* GetClass();
	void SetTutorial(uint64_t _arg0_);
	const uint64_t& GetTutorial() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E6D0);
	static inline auto FExecute = PreyFunction<void(const ArkCollectTutorialResult* const _this, uint64_t _parentCondition)>(0x14CD1F0);
};

// ArkCompleteChecklistEntryResult
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkCompleteChecklistEntryResult : public ArkConditionResult
{ // Size=16 (0x10)
public:
	// ArkCompleteChecklistEntryResult::ArkChecklistEntryProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkChecklistEntryProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkChecklistEntryProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCompleteChecklistEntryResult::ArkChecklistEntryProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCompleteChecklistEntryResult::ArkChecklistEntryProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	static inline auto s_ArkChecklistEntryProperty = PreyGlobal<ArkCompleteChecklistEntryResult::ArkChecklistEntryProperty>(0x2D24A90);
	uint64_t m_ChecklistEntry;

	static ArkReflectedObject* Create() { return FCreate(); }
	virtual void Execute(uint64_t _parentCondition) const;

#if 0
	ArkCompleteChecklistEntryResult();
	static ArkClass* GetClass();
	void SetChecklistEntry(uint64_t _arg0_);
	const uint64_t& GetChecklistEntry() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E720);
	static inline auto FExecute = PreyFunction<void(const ArkCompleteChecklistEntryResult* const _this, uint64_t _parentCondition)>(0x14CD220);
};

// ArkDelayedResult
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkDelayedResult : public ArkConditionResult
{ // Size=40 (0x28)
public:
	// ArkDelayedResult::ArkDelayProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkDelayProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDelayProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDelayedResult::ArkDelayProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D2F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDelayedResult::ArkDelayProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkDelayedResult::ArkResultsProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkResultsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkResultsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDelayedResult::ArkResultsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D3D0);
		static inline auto FIsArray = PreyFunction<bool(const ArkDelayedResult::ArkResultsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkDelayedResult::ArkResultsProperty* const _this, ArkReflectedObject* _pObject)>(0x108CC40);
	};

	static inline auto s_ArkDelayProperty = PreyGlobal<ArkDelayedResult::ArkDelayProperty>(0x2D24A10);
	float m_Delay;
	static inline auto s_ArkResultsProperty = PreyGlobal<ArkDelayedResult::ArkResultsProperty>(0x2D24A30);
	std::vector<std::shared_ptr<ArkConditionResult>> m_Results;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual void Execute(uint64_t _parentCondition) const;
	virtual bool IsDelayedResult() const;

#if 0
	ArkDelayedResult();
	void SetDelay(float _arg0_);
	const float& GetDelay() const;
	std::vector<std::shared_ptr<ArkConditionResult>>& GetResults();
	const std::vector<std::shared_ptr<ArkConditionResult>>& GetResults() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E8C0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F490);
	static inline auto FExecute = PreyFunction<void(const ArkDelayedResult* const _this, uint64_t _parentCondition)>(0x14CD260);
	static inline auto FIsDelayedResult = PreyFunction<bool(const ArkDelayedResult* const _this)>(0x1A302A0);
};

// ArkDisplayPromptTutorialCallbackResult
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkDisplayPromptTutorialCallbackResult : public ArkConditionResult
{ // Size=24 (0x18)
public:
	// ArkDisplayPromptTutorialCallbackResult::ArkPromptTutorialProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkPromptTutorialProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPromptTutorialProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisplayPromptTutorialCallbackResult::ArkPromptTutorialProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisplayPromptTutorialCallbackResult::ArkPromptTutorialProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkDisplayPromptTutorialCallbackResult::ArkCardTutorialProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkCardTutorialProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCardTutorialProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisplayPromptTutorialCallbackResult::ArkCardTutorialProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D390);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisplayPromptTutorialCallbackResult::ArkCardTutorialProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9CA0);
	};

	static inline auto s_ArkPromptTutorialProperty = PreyGlobal<ArkDisplayPromptTutorialCallbackResult::ArkPromptTutorialProperty>(0x2D24990);
	uint64_t m_PromptTutorial;
	static inline auto s_ArkCardTutorialProperty = PreyGlobal<ArkDisplayPromptTutorialCallbackResult::ArkCardTutorialProperty>(0x2D249B0);
	uint64_t m_CardTutorial;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual void Execute(uint64_t _parentCondition) const;
	void CallbackTriggered() const { FCallbackTriggered(this); }

#if 0
	ArkDisplayPromptTutorialCallbackResult();
	void SetPromptTutorial(uint64_t _arg0_);
	const uint64_t& GetPromptTutorial() const;
	void SetCardTutorial(uint64_t _arg0_);
	const uint64_t& GetCardTutorial() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E920);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F530);
	static inline auto FExecute = PreyFunction<void(const ArkDisplayPromptTutorialCallbackResult* const _this, uint64_t _parentCondition)>(0x14CD2A0);
	static inline auto FCallbackTriggered = PreyFunction<void(const ArkDisplayPromptTutorialCallbackResult* const _this)>(0x14CC570);
};

// ArkDisplayTutorialResult
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkDisplayTutorialResult : public ArkConditionResult
{ // Size=16 (0x10)
public:
	// ArkDisplayTutorialResult::ArkTutorialProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkTutorialProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTutorialProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisplayTutorialResult::ArkTutorialProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisplayTutorialResult::ArkTutorialProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	static inline auto s_ArkTutorialProperty = PreyGlobal<ArkDisplayTutorialResult::ArkTutorialProperty>(0x2D24950);
	uint64_t m_Tutorial;

	static ArkReflectedObject* Create() { return FCreate(); }
	virtual void Execute(uint64_t _parentCondition) const;

#if 0
	ArkDisplayTutorialResult();
	static ArkClass* GetClass();
	void SetTutorial(uint64_t _arg0_);
	const uint64_t& GetTutorial() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108E970);
	static inline auto FExecute = PreyFunction<void(const ArkDisplayTutorialResult* const _this, uint64_t _parentCondition)>(0x14CD330);
};

// ArkEnableGameStateConditionResult
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkEnableGameStateConditionResult : public ArkConditionResult
{ // Size=24 (0x18)
public:
	// ArkEnableGameStateConditionResult::ArkGameStateConditionProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkGameStateConditionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkGameStateConditionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEnableGameStateConditionResult::ArkGameStateConditionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEnableGameStateConditionResult::ArkGameStateConditionProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkEnableGameStateConditionResult::ArkEnableProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkEnableProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEnableProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEnableGameStateConditionResult::ArkEnableProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D3B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEnableGameStateConditionResult::ArkEnableProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9CA0);
	};

	static inline auto s_ArkGameStateConditionProperty = PreyGlobal<ArkEnableGameStateConditionResult::ArkGameStateConditionProperty>(0x2D249D0);
	uint64_t m_GameStateCondition;
	static inline auto s_ArkEnableProperty = PreyGlobal<ArkEnableGameStateConditionResult::ArkEnableProperty>(0x2D249F0);
	bool m_Enable;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual void Execute(uint64_t _parentCondition) const;

#if 0
	ArkEnableGameStateConditionResult();
	void SetGameStateCondition(uint64_t _arg0_);
	const uint64_t& GetGameStateCondition() const;
	void SetEnable(bool _arg0_);
	const bool& GetEnable() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108EA10);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108F670);
	static inline auto FExecute = PreyFunction<void(const ArkEnableGameStateConditionResult* const _this, uint64_t _parentCondition)>(0x14CD380);
};

// ArkLockTipResult
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkLockTipResult : public ArkConditionResult
{ // Size=24 (0x18)
public:
	// ArkLockTipResult::ArkTipLockProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkTipLockProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTipLockProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLockTipResult::ArkTipLockProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLockTipResult::ArkTipLockProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkLockTipResult::ArkLockedProperty
	// Header:  Prey/Ark/ArkGameStateCondition.h
	class ArkLockedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLockedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLockTipResult::ArkLockedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D3B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLockTipResult::ArkLockedProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9CA0);
	};

	static inline auto s_ArkTipLockProperty = PreyGlobal<ArkLockTipResult::ArkTipLockProperty>(0x2D24A50);
	uint64_t m_TipLock;
	static inline auto s_ArkLockedProperty = PreyGlobal<ArkLockTipResult::ArkLockedProperty>(0x2D24A70);
	bool m_Locked;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual void Execute(uint64_t _parentCondition) const;

#if 0
	ArkLockTipResult();
	void SetTipLock(uint64_t _arg0_);
	const uint64_t& GetTipLock() const;
	void SetLocked(bool _arg0_);
	const bool& GetLocked() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108ED90);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108FB20);
	static inline auto FExecute = PreyFunction<void(const ArkLockTipResult* const _this, uint64_t _parentCondition)>(0x14CD420);
};

// ArkConditionEvaluationData
// Header:  Prey/Ark/ArkGameStateCondition.h
class ArkConditionEvaluationData
{ // Size=24 (0x18)
public:
	// ArkConditionEvaluationData::EntityIdentifiers
	// Header:  Prey/Ark/ArkGameStateCondition.h
	struct EntityIdentifiers
	{ // Size=16 (0x10)
		uint64_t m_archetypeId;
		unsigned m_entityId;
	};

	EArkConditionTriggerType m_type;
	union
	{
		uint64_t m_changeId;
		ArkConditionEvaluationData::EntityIdentifiers m_identifiers;

	};

#if 0
	ArkConditionEvaluationData(EArkConditionTriggerType _arg0_);
	ArkConditionEvaluationData(EArkConditionTriggerType _arg0_, const uint64_t _arg1_);
	ArkConditionEvaluationData(EArkConditionTriggerType _arg0_, const unsigned _arg1_);
	ArkConditionEvaluationData(EArkConditionTriggerType _arg0_, const uint64_t _arg1_, const unsigned _arg2_);
	bool operator==(const ArkConditionEvaluationData& _arg0_) const;
	EArkConditionTriggerType GetType() const;
	uint64_t GetChangeId() const;
	uint64_t GetArchetypeId() const;
	unsigned GetEntityId() const;
#endif
};
#endif // !MOONCRASH
