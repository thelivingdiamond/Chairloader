// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkgamestatecondition.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>

class ArkClass;
class ArkConditionEvaluationData;

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
class ArkConditionResult : public ArkReflectedObject // Id=8013C27 Size=8
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual void Execute(uint64_t _parentCondition) const;
	virtual bool IsDelayedResult() const;
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AAC0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106B640);
	static inline auto FExecute = PreyFunction<void(ArkConditionResult const *const _this, uint64_t _parentCondition)>(0xA13080);
	static inline auto FIsDelayedResult = PreyFunction<bool(ArkConditionResult const *const _this)>(0xDD23F0);
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
	
#if 0
	std::vector<ArkGameStateCondition> &GetGameStateConditions();
	std::vector<ArkGameStateCondition> const &GetGameStateConditions() const;
	ArkGameStateCondition const *FindCondition(const uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106AE10);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106BA00);
	static inline auto FInit = PreyFunction<bool(ArkGameStateConditionLibrary *const _this)>(0x106C090);
};

