// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkFabricationPlan.h
class ArkFabricationPlan : public ArkReflectedObject // Id=8013B5A Size=80
{
public:
	class ArkIDProperty : public ArkProperty // Id=8013B5B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlan::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkFabricationPlan::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013B5C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlan::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkFabricationPlan::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkArchetypeProperty : public ArkProperty // Id=8013B5D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkArchetypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
	};

	static ArkFabricationPlan::ArkArchetypeProperty s_ArkArchetypeProperty;
	string m_Archetype;
	
	class ArkDescriptionProperty : public ArkProperty // Id=8013B5E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlan::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkFabricationPlan::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkOrganicCountProperty : public ArkProperty // Id=8013B5F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkOrganicCountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlan::ArkOrganicCountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkFabricationPlan::ArkOrganicCountProperty s_ArkOrganicCountProperty;
	unsigned m_OrganicCount;
	
	class ArkMineralCountProperty : public ArkProperty // Id=8013B60 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkMineralCountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlan::ArkMineralCountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328510);
	};

	static ArkFabricationPlan::ArkMineralCountProperty s_ArkMineralCountProperty;
	unsigned m_MineralCount;
	
	class ArkSyntheticCountProperty : public ArkProperty // Id=8013B61 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkSyntheticCountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlan::ArkSyntheticCountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkFabricationPlan::ArkSyntheticCountProperty s_ArkSyntheticCountProperty;
	unsigned m_SyntheticCount;
	
	class ArkExoticCountProperty : public ArkProperty // Id=8013B62 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkExoticCountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlan::ArkExoticCountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328680);
	};

	static ArkFabricationPlan::ArkExoticCountProperty s_ArkExoticCountProperty;
	unsigned m_ExoticCount;
	
	class ArkPositionOffsetProperty : public ArkProperty // Id=8013B63 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkPositionOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlan::ArkPositionOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkFabricationPlan::ArkPositionOffsetProperty s_ArkPositionOffsetProperty;
	Vec3 m_PositionOffset;
	
	class ArkRotationOffsetProperty : public ArkProperty // Id=8013B64 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkRotationOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066410);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlan::ArkRotationOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328E30);
	};

	static ArkFabricationPlan::ArkRotationOffsetProperty s_ArkRotationOffsetProperty;
	Vec3 m_RotationOffset;
	
	class ArkRawMaterialClassProperty : public ArkProperty // Id=8013B65 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkRawMaterialClassProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066440);
	};

	static ArkFabricationPlan::ArkRawMaterialClassProperty s_ArkRawMaterialClassProperty;
	EArkRawMaterialClass m_RawMaterialClass;
	
	class ArkUseShortAnimationProperty : public ArkProperty // Id=8013B66 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlan::ArkUseShortAnimationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066490);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlan::ArkUseShortAnimationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105BA40);
	};

	static ArkFabricationPlan::ArkUseShortAnimationProperty s_ArkUseShortAnimationProperty;
	bool m_UseShortAnimation;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetArchetype(string arg0);
	uint64_t GetArchetype() const;
	string const &GetArchetypeString() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetOrganicCount(unsigned arg0);
	const unsigned &GetOrganicCount() const;
	void SetMineralCount(unsigned arg0);
	const unsigned &GetMineralCount() const;
	void SetSyntheticCount(unsigned arg0);
	const unsigned &GetSyntheticCount() const;
	void SetExoticCount(unsigned arg0);
	const unsigned &GetExoticCount() const;
	void SetPositionOffset(Vec3 arg0);
	Vec3 const &GetPositionOffset() const;
	void SetRotationOffset(Vec3 arg0);
	Vec3 const &GetRotationOffset() const;
	void SetRawMaterialClass(string arg0);
	EArkRawMaterialClass const &GetRawMaterialClass() const;
	void SetUseShortAnimation(bool arg0);
	const bool &GetUseShortAnimation() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1066AE0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1066BE0);
};

// Header: Exact
// Prey/Ark/arkfabricationplan.h
class ArkFabricationPlans : public ArkReflectedLibrary // Id=8013B67 Size=128
{
public:
	class ArkSmallRawMaterialModelProperty : public ArkProperty // Id=8013B68 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkSmallRawMaterialModelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360300);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkSmallRawMaterialModelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkFabricationPlans::ArkSmallRawMaterialModelProperty s_ArkSmallRawMaterialModelProperty;
	string m_SmallRawMaterialModel;
	
	class ArkMediumRawMaterialModelProperty : public ArkProperty // Id=8013B69 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkMediumRawMaterialModelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360380);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkMediumRawMaterialModelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkFabricationPlans::ArkMediumRawMaterialModelProperty s_ArkMediumRawMaterialModelProperty;
	string m_MediumRawMaterialModel;
	
	class ArkLargeRawMaterialModelProperty : public ArkProperty // Id=8013B6A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkLargeRawMaterialModelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10660B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkLargeRawMaterialModelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6360);
	};

	static ArkFabricationPlans::ArkLargeRawMaterialModelProperty s_ArkLargeRawMaterialModelProperty;
	string m_LargeRawMaterialModel;
	
	class ArkXLargeRawMaterialModelProperty : public ArkProperty // Id=8013B6B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkXLargeRawMaterialModelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkXLargeRawMaterialModelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360170);
	};

	static ArkFabricationPlans::ArkXLargeRawMaterialModelProperty s_ArkXLargeRawMaterialModelProperty;
	string m_XLargeRawMaterialModel;
	
	class ArkSmallRawMaterialLongAnimProperty : public ArkProperty // Id=8013B6C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkSmallRawMaterialLongAnimProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkSmallRawMaterialLongAnimProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221B60);
	};

	static ArkFabricationPlans::ArkSmallRawMaterialLongAnimProperty s_ArkSmallRawMaterialLongAnimProperty;
	uint64_t m_SmallRawMaterialLongAnim;
	
	class ArkMediumRawMaterialLongAnimProperty : public ArkProperty // Id=8013B6D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkMediumRawMaterialLongAnimProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066130);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkMediumRawMaterialLongAnimProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105A980);
	};

	static ArkFabricationPlans::ArkMediumRawMaterialLongAnimProperty s_ArkMediumRawMaterialLongAnimProperty;
	uint64_t m_MediumRawMaterialLongAnim;
	
	class ArkLargeRawMaterialLongAnimProperty : public ArkProperty // Id=8013B6E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkLargeRawMaterialLongAnimProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066150);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkLargeRawMaterialLongAnimProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221C40);
	};

	static ArkFabricationPlans::ArkLargeRawMaterialLongAnimProperty s_ArkLargeRawMaterialLongAnimProperty;
	uint64_t m_LargeRawMaterialLongAnim;
	
	class ArkXLargeRawMaterialLongAnimProperty : public ArkProperty // Id=8013B6F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkXLargeRawMaterialLongAnimProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066170);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkXLargeRawMaterialLongAnimProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AA60);
	};

	static ArkFabricationPlans::ArkXLargeRawMaterialLongAnimProperty s_ArkXLargeRawMaterialLongAnimProperty;
	uint64_t m_XLargeRawMaterialLongAnim;
	
	class ArkSmallRawMaterialShortAnimProperty : public ArkProperty // Id=8013B70 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkSmallRawMaterialShortAnimProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066190);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkSmallRawMaterialShortAnimProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AA80);
	};

	static ArkFabricationPlans::ArkSmallRawMaterialShortAnimProperty s_ArkSmallRawMaterialShortAnimProperty;
	uint64_t m_SmallRawMaterialShortAnim;
	
	class ArkMediumRawMaterialShortAnimProperty : public ArkProperty // Id=8013B71 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkMediumRawMaterialShortAnimProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10661B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkMediumRawMaterialShortAnimProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221D20);
	};

	static ArkFabricationPlans::ArkMediumRawMaterialShortAnimProperty s_ArkMediumRawMaterialShortAnimProperty;
	uint64_t m_MediumRawMaterialShortAnim;
	
	class ArkLargeRawMaterialShortAnimProperty : public ArkProperty // Id=8013B72 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkLargeRawMaterialShortAnimProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10661D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkLargeRawMaterialShortAnimProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221DA0);
	};

	static ArkFabricationPlans::ArkLargeRawMaterialShortAnimProperty s_ArkLargeRawMaterialShortAnimProperty;
	uint64_t m_LargeRawMaterialShortAnim;
	
	class ArkXLargeRawMaterialShortAnimProperty : public ArkProperty // Id=8013B73 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkXLargeRawMaterialShortAnimProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10661F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkXLargeRawMaterialShortAnimProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1066210);
	};

	static ArkFabricationPlans::ArkXLargeRawMaterialShortAnimProperty s_ArkXLargeRawMaterialShortAnimProperty;
	uint64_t m_XLargeRawMaterialShortAnim;
	
	class ArkFabricationPlansProperty : public ArkProperty // Id=8013B74 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFabricationPlans::ArkFabricationPlansProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066230);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFabricationPlans::ArkFabricationPlansProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1066360);
		static inline auto FIsArray = PreyFunction<bool(ArkFabricationPlans::ArkFabricationPlansProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkFabricationPlans::ArkFabricationPlansProperty const *const _this, ArkReflectedObject *_pObject)>(0x10663A0);
	};

	static ArkFabricationPlans::ArkFabricationPlansProperty s_ArkFabricationPlansProperty;
	std::vector<ArkFabricationPlan> m_FabricationPlans;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkFabricationPlan const *Find(const uint64_t _id) const { return FFind(this,_id); }
	string const &GetRawMaterialModel(EArkRawMaterialClass _class) const { return FGetRawMaterialModel(this,_class); }
	uint64_t GetRawMaterialAnim(EArkRawMaterialClass _class, bool _bLong) const { return FGetRawMaterialAnim(this,_class,_bLong); }
	virtual ~ArkFabricationPlans();
	
#if 0
	void SetSmallRawMaterialModel(string arg0);
	string const &GetSmallRawMaterialModel() const;
	void SetMediumRawMaterialModel(string arg0);
	string const &GetMediumRawMaterialModel() const;
	void SetLargeRawMaterialModel(string arg0);
	string const &GetLargeRawMaterialModel() const;
	void SetXLargeRawMaterialModel(string arg0);
	string const &GetXLargeRawMaterialModel() const;
	void SetSmallRawMaterialLongAnim(uint64_t arg0);
	const uint64_t &GetSmallRawMaterialLongAnim() const;
	void SetMediumRawMaterialLongAnim(uint64_t arg0);
	const uint64_t &GetMediumRawMaterialLongAnim() const;
	void SetLargeRawMaterialLongAnim(uint64_t arg0);
	const uint64_t &GetLargeRawMaterialLongAnim() const;
	void SetXLargeRawMaterialLongAnim(uint64_t arg0);
	const uint64_t &GetXLargeRawMaterialLongAnim() const;
	void SetSmallRawMaterialShortAnim(uint64_t arg0);
	const uint64_t &GetSmallRawMaterialShortAnim() const;
	void SetMediumRawMaterialShortAnim(uint64_t arg0);
	const uint64_t &GetMediumRawMaterialShortAnim() const;
	void SetLargeRawMaterialShortAnim(uint64_t arg0);
	const uint64_t &GetLargeRawMaterialShortAnim() const;
	void SetXLargeRawMaterialShortAnim(uint64_t arg0);
	const uint64_t &GetXLargeRawMaterialShortAnim() const;
	std::vector<ArkFabricationPlan> &GetFabricationPlans();
	std::vector<ArkFabricationPlan> const &GetFabricationPlans() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1066B30);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1066C80);
	static inline auto FInit = PreyFunction<bool(ArkFabricationPlans *const _this)>(0x1066E00);
	static inline auto FFind = PreyFunction<ArkFabricationPlan const *(ArkFabricationPlans const *const _this, const uint64_t _id)>(0x1066BB0);
	static inline auto FGetRawMaterialModel = PreyFunction<string const &(ArkFabricationPlans const *const _this, EArkRawMaterialClass _class)>(0x1066DD0);
	static inline auto FGetRawMaterialAnim = PreyFunction<uint64_t(ArkFabricationPlans const *const _this, EArkRawMaterialClass _class, bool _bLong)>(0x1066D70);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/iface/IArkItem.h>

class ArkClass;
class IArkValueBase;

// ArkFabricationPlan
// Header:  Prey/Ark/ArkFabricationPlan.h
class ArkFabricationPlan : public ArkReflectedObject
{ // Size=160 (0xA0)
public:
	// ArkFabricationPlan::ArkIDProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkFabricationPlan::ArkNameProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkFabricationPlan::ArkLabelProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkFabricationPlan::ArkArchetypeProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
	};

	// ArkFabricationPlan::ArkEntitlementProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkEntitlementProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEntitlementProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkEntitlementProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1077BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkEntitlementProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkFabricationPlan::ArkQualityTierProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkQualityTierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkQualityTierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkQualityTierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089E60);
	};

	// ArkFabricationPlan::ArkDescriptionProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkFabricationPlan::ArkOrganicCountProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkOrganicCountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkOrganicCountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkOrganicCountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3150);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkOrganicCountProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkFabricationPlan::ArkMineralCountProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkMineralCountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMineralCountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkMineralCountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089EB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkMineralCountProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3160);
	};

	// ArkFabricationPlan::ArkSyntheticCountProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkSyntheticCountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSyntheticCountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkSyntheticCountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084450);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkSyntheticCountProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	// ArkFabricationPlan::ArkExoticCountProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkExoticCountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExoticCountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkExoticCountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084460);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkExoticCountProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3170);
	};

	// ArkFabricationPlan::ArkPositionOffsetProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkPositionOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPositionOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkPositionOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14029F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkPositionOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EE90);
	};

	// ArkFabricationPlan::ArkRotationOffsetProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkRotationOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRotationOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkRotationOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089EC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkRotationOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3190);
	};

	// ArkFabricationPlan::ArkRawMaterialClassProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkRawMaterialClassProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkRawMaterialClassProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkRawMaterialClassProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089EF0);
	};

	// ArkFabricationPlan::ArkUseShortAnimationProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkUseShortAnimationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUseShortAnimationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkUseShortAnimationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089F40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkUseShortAnimationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1089F50);
	};

	// ArkFabricationPlan::ArkCryptoCostProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkCryptoCostProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCryptoCostProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkCryptoCostProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089F60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkCryptoCostProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7840);
	};

	// ArkFabricationPlan::ArkReadyRoomArchetypeProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkReadyRoomArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkReadyRoomArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkReadyRoomArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0BF0);
	};

	// ArkFabricationPlan::ArkReadyRoomLimitProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkReadyRoomLimitProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReadyRoomLimitProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkReadyRoomLimitProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089F70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkReadyRoomLimitProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BE110);
	};

	// ArkFabricationPlan::ArkSharedLimitPlansProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkSharedLimitPlansProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkSharedLimitPlansProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkSharedLimitPlansProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkSharedLimitPlansProperty* const _this, ArkReflectedObject* const _pObject)>(0x1089FB0);
		static inline auto FIsArray = PreyFunction<bool(const ArkFabricationPlan::ArkSharedLimitPlansProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkFabricationPlan::ArkSharedLimitPlansProperty* const _this, ArkReflectedObject* _pObject)>(0x1089FE0);
	};

	// ArkFabricationPlan::ArkCategoryProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkCategoryProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCategoryProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlan::ArkCategoryProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089FF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlan::ArkCategoryProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6B0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkFabricationPlan::ArkIDProperty>(0x2D23C60);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkFabricationPlan::ArkNameProperty>(0x2D23C80);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkFabricationPlan::ArkLabelProperty>(0x2D23CA0);
	string m_Label;
	static inline auto s_ArkArchetypeProperty = PreyGlobal<ArkFabricationPlan::ArkArchetypeProperty>(0x2D23CC0);
	string m_Archetype;
	static inline auto s_ArkEntitlementProperty = PreyGlobal<ArkFabricationPlan::ArkEntitlementProperty>(0x2D23CE0);
	uint64_t m_Entitlement;
	static inline auto s_ArkQualityTierProperty = PreyGlobal<ArkFabricationPlan::ArkQualityTierProperty>(0x2D23D00);
	IArkItem::EArkQualityTier m_QualityTier;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkFabricationPlan::ArkDescriptionProperty>(0x2D23D20);
	string m_Description;
	static inline auto s_ArkOrganicCountProperty = PreyGlobal<ArkFabricationPlan::ArkOrganicCountProperty>(0x2D23D40);
	unsigned m_OrganicCount;
	static inline auto s_ArkMineralCountProperty = PreyGlobal<ArkFabricationPlan::ArkMineralCountProperty>(0x2D23D60);
	unsigned m_MineralCount;
	static inline auto s_ArkSyntheticCountProperty = PreyGlobal<ArkFabricationPlan::ArkSyntheticCountProperty>(0x2D23D80);
	unsigned m_SyntheticCount;
	static inline auto s_ArkExoticCountProperty = PreyGlobal<ArkFabricationPlan::ArkExoticCountProperty>(0x2D23DA0);
	unsigned m_ExoticCount;
	static inline auto s_ArkPositionOffsetProperty = PreyGlobal<ArkFabricationPlan::ArkPositionOffsetProperty>(0x2D23DC0);
	Vec3 m_PositionOffset;
	static inline auto s_ArkRotationOffsetProperty = PreyGlobal<ArkFabricationPlan::ArkRotationOffsetProperty>(0x2D23DE0);
	Vec3 m_RotationOffset;
	static inline auto s_ArkRawMaterialClassProperty = PreyGlobal<ArkFabricationPlan::ArkRawMaterialClassProperty>(0x2D23E00);
	EArkRawMaterialClass m_RawMaterialClass;
	static inline auto s_ArkUseShortAnimationProperty = PreyGlobal<ArkFabricationPlan::ArkUseShortAnimationProperty>(0x2D23E20);
	bool m_UseShortAnimation;
	static inline auto s_ArkCryptoCostProperty = PreyGlobal<ArkFabricationPlan::ArkCryptoCostProperty>(0x2D23E40);
	int m_CryptoCost;
	static inline auto s_ArkReadyRoomArchetypeProperty = PreyGlobal<ArkFabricationPlan::ArkReadyRoomArchetypeProperty>(0x2D23E60);
	string m_ReadyRoomArchetype;
	static inline auto s_ArkReadyRoomLimitProperty = PreyGlobal<ArkFabricationPlan::ArkReadyRoomLimitProperty>(0x2D23E80);
	unsigned m_ReadyRoomLimit;
	static inline auto s_ArkSharedLimitPlansProperty = PreyGlobal<ArkFabricationPlan::ArkSharedLimitPlansProperty>(0x2D23EA0);
	std::vector<uint64_t> m_SharedLimitPlans;
	static inline auto s_ArkCategoryProperty = PreyGlobal<ArkFabricationPlan::ArkCategoryProperty>(0x2D23EC0);
	uint64_t m_Category;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkFabricationPlan();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetArchetype(string _arg0_);
	uint64_t GetArchetype() const;
	const string& GetArchetypeString() const;
	void SetEntitlement(uint64_t _arg0_);
	const uint64_t& GetEntitlement() const;
	void SetQualityTier(string _arg0_);
	const IArkItem::EArkQualityTier& GetQualityTier() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetOrganicCount(unsigned _arg0_);
	const unsigned& GetOrganicCount() const;
	void SetMineralCount(unsigned _arg0_);
	const unsigned& GetMineralCount() const;
	void SetSyntheticCount(unsigned _arg0_);
	const unsigned& GetSyntheticCount() const;
	void SetExoticCount(unsigned _arg0_);
	const unsigned& GetExoticCount() const;
	void SetPositionOffset(Vec3 _arg0_);
	const Vec3& GetPositionOffset() const;
	void SetRotationOffset(Vec3 _arg0_);
	const Vec3& GetRotationOffset() const;
	void SetRawMaterialClass(string _arg0_);
	const EArkRawMaterialClass& GetRawMaterialClass() const;
	void SetUseShortAnimation(bool _arg0_);
	const bool& GetUseShortAnimation() const;
	void SetCryptoCost(int _arg0_);
	const int& GetCryptoCost() const;
	void SetReadyRoomArchetype(string _arg0_);
	uint64_t GetReadyRoomArchetype() const;
	const string& GetReadyRoomArchetypeString() const;
	void SetReadyRoomLimit(unsigned _arg0_);
	const unsigned& GetReadyRoomLimit() const;
	std::vector<uint64_t>& GetSharedLimitPlans();
	const std::vector<uint64_t>& GetSharedLimitPlans() const;
	void SetCategory(uint64_t _arg0_);
	const uint64_t& GetCategory() const;
	IArkItem::EArkQualityTier GetGuaranteedQualityTier() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108AD80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108AF40);
};

// ArkFabricationPlanCategory
// Header:  Prey/Ark/ArkFabricationPlan.h
class ArkFabricationPlanCategory : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkFabricationPlanCategory::ArkIDProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlanCategory::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlanCategory::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkFabricationPlanCategory::ArkNameProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlanCategory::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlanCategory::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkFabricationPlanCategory::ArkLabelProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlanCategory::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlanCategory::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkFabricationPlanCategory::ArkIDProperty>(0x2D23C00);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkFabricationPlanCategory::ArkNameProperty>(0x2D23C20);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkFabricationPlanCategory::ArkLabelProperty>(0x2D23C40);
	string m_Label;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkFabricationPlanCategory();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108AE00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108AFE0);
};

// ArkFabricationPlans
// Header:  Prey/Ark/ArkFabricationPlan.h
class ArkFabricationPlans : public ArkReflectedLibrary
{ // Size=152 (0x98)
public:
	// ArkFabricationPlans::ArkSmallRawMaterialModelProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkSmallRawMaterialModelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSmallRawMaterialModelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkSmallRawMaterialModelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkSmallRawMaterialModelProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkFabricationPlans::ArkMediumRawMaterialModelProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkMediumRawMaterialModelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMediumRawMaterialModelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkMediumRawMaterialModelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108A000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkMediumRawMaterialModelProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9CA0);
	};

	// ArkFabricationPlans::ArkLargeRawMaterialModelProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkLargeRawMaterialModelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLargeRawMaterialModelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkLargeRawMaterialModelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108A060);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkLargeRawMaterialModelProperty* const _this, ArkReflectedObject* const _pObject)>(0x108A0C0);
	};

	// ArkFabricationPlans::ArkXLargeRawMaterialModelProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkXLargeRawMaterialModelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkXLargeRawMaterialModelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkXLargeRawMaterialModelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkXLargeRawMaterialModelProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C1FF0);
	};

	// ArkFabricationPlans::ArkSmallRawMaterialLongAnimProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkSmallRawMaterialLongAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSmallRawMaterialLongAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkSmallRawMaterialLongAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089B00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkSmallRawMaterialLongAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B470);
	};

	// ArkFabricationPlans::ArkMediumRawMaterialLongAnimProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkMediumRawMaterialLongAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMediumRawMaterialLongAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkMediumRawMaterialLongAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089B20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkMediumRawMaterialLongAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x1089B40);
	};

	// ArkFabricationPlans::ArkLargeRawMaterialLongAnimProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkLargeRawMaterialLongAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLargeRawMaterialLongAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkLargeRawMaterialLongAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkLargeRawMaterialLongAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x1089B80);
	};

	// ArkFabricationPlans::ArkXLargeRawMaterialLongAnimProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkXLargeRawMaterialLongAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkXLargeRawMaterialLongAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkXLargeRawMaterialLongAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089BA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkXLargeRawMaterialLongAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9E20);
	};

	// ArkFabricationPlans::ArkSmallRawMaterialShortAnimProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkSmallRawMaterialShortAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSmallRawMaterialShortAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkSmallRawMaterialShortAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089BC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkSmallRawMaterialShortAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B590);
	};

	// ArkFabricationPlans::ArkMediumRawMaterialShortAnimProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkMediumRawMaterialShortAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMediumRawMaterialShortAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkMediumRawMaterialShortAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089BE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkMediumRawMaterialShortAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B5D0);
	};

	// ArkFabricationPlans::ArkLargeRawMaterialShortAnimProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkLargeRawMaterialShortAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLargeRawMaterialShortAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkLargeRawMaterialShortAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkLargeRawMaterialShortAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C1BC0);
	};

	// ArkFabricationPlans::ArkXLargeRawMaterialShortAnimProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkXLargeRawMaterialShortAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkXLargeRawMaterialShortAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkXLargeRawMaterialShortAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089C20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkXLargeRawMaterialShortAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C1C90);
	};

	// ArkFabricationPlans::ArkFabricationPlansProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkFabricationPlansProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkFabricationPlansProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkFabricationPlansProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089C40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkFabricationPlansProperty* const _this, ArkReflectedObject* const _pObject)>(0x1089C90);
		static inline auto FIsArray = PreyFunction<bool(const ArkFabricationPlans::ArkFabricationPlansProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkFabricationPlans::ArkFabricationPlansProperty* const _this, ArkReflectedObject* _pObject)>(0x1089CD0);
	};

	// ArkFabricationPlans::ArkCategoriesProperty
	// Header:  Prey/Ark/ArkFabricationPlan.h
	class ArkCategoriesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkCategoriesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFabricationPlans::ArkCategoriesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089D40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFabricationPlans::ArkCategoriesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1089DE0);
		static inline auto FIsArray = PreyFunction<bool(const ArkFabricationPlans::ArkCategoriesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkFabricationPlans::ArkCategoriesProperty* const _this, ArkReflectedObject* _pObject)>(0x1089E20);
	};

	static inline auto s_ArkSmallRawMaterialModelProperty = PreyGlobal<ArkFabricationPlans::ArkSmallRawMaterialModelProperty>(0x2D23EE0);
	string m_SmallRawMaterialModel;
	static inline auto s_ArkMediumRawMaterialModelProperty = PreyGlobal<ArkFabricationPlans::ArkMediumRawMaterialModelProperty>(0x2D23F00);
	string m_MediumRawMaterialModel;
	static inline auto s_ArkLargeRawMaterialModelProperty = PreyGlobal<ArkFabricationPlans::ArkLargeRawMaterialModelProperty>(0x2D23F20);
	string m_LargeRawMaterialModel;
	static inline auto s_ArkXLargeRawMaterialModelProperty = PreyGlobal<ArkFabricationPlans::ArkXLargeRawMaterialModelProperty>(0x2D23F40);
	string m_XLargeRawMaterialModel;
	static inline auto s_ArkSmallRawMaterialLongAnimProperty = PreyGlobal<ArkFabricationPlans::ArkSmallRawMaterialLongAnimProperty>(0x2D23F60);
	uint64_t m_SmallRawMaterialLongAnim;
	static inline auto s_ArkMediumRawMaterialLongAnimProperty = PreyGlobal<ArkFabricationPlans::ArkMediumRawMaterialLongAnimProperty>(0x2D23F80);
	uint64_t m_MediumRawMaterialLongAnim;
	static inline auto s_ArkLargeRawMaterialLongAnimProperty = PreyGlobal<ArkFabricationPlans::ArkLargeRawMaterialLongAnimProperty>(0x2D23FA0);
	uint64_t m_LargeRawMaterialLongAnim;
	static inline auto s_ArkXLargeRawMaterialLongAnimProperty = PreyGlobal<ArkFabricationPlans::ArkXLargeRawMaterialLongAnimProperty>(0x2D23FC0);
	uint64_t m_XLargeRawMaterialLongAnim;
	static inline auto s_ArkSmallRawMaterialShortAnimProperty = PreyGlobal<ArkFabricationPlans::ArkSmallRawMaterialShortAnimProperty>(0x2D23FE0);
	uint64_t m_SmallRawMaterialShortAnim;
	static inline auto s_ArkMediumRawMaterialShortAnimProperty = PreyGlobal<ArkFabricationPlans::ArkMediumRawMaterialShortAnimProperty>(0x2D24000);
	uint64_t m_MediumRawMaterialShortAnim;
	static inline auto s_ArkLargeRawMaterialShortAnimProperty = PreyGlobal<ArkFabricationPlans::ArkLargeRawMaterialShortAnimProperty>(0x2D24020);
	uint64_t m_LargeRawMaterialShortAnim;
	static inline auto s_ArkXLargeRawMaterialShortAnimProperty = PreyGlobal<ArkFabricationPlans::ArkXLargeRawMaterialShortAnimProperty>(0x2D24040);
	uint64_t m_XLargeRawMaterialShortAnim;
	static inline auto s_ArkFabricationPlansProperty = PreyGlobal<ArkFabricationPlans::ArkFabricationPlansProperty>(0x2D24060);
	std::vector<ArkFabricationPlan> m_FabricationPlans;
	static inline auto s_ArkCategoriesProperty = PreyGlobal<ArkFabricationPlans::ArkCategoriesProperty>(0x2D24080);
	std::vector<ArkFabricationPlanCategory> m_Categories;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkFabricationPlan* Find(const uint64_t _id) const { return FFind(this, _id); }
	const ArkFabricationPlanCategory* FindCategory(const uint64_t _id) const { return FFindCategory(this, _id); }
	const string& GetRawMaterialModel(const EArkRawMaterialClass _class) const { return FGetRawMaterialModel(this, _class); }
	uint64_t GetRawMaterialAnim(const EArkRawMaterialClass _class, bool _bLong) const { return FGetRawMaterialAnim(this, _class, _bLong); }

#if 0
	void SetSmallRawMaterialModel(string _arg0_);
	const string& GetSmallRawMaterialModel() const;
	void SetMediumRawMaterialModel(string _arg0_);
	const string& GetMediumRawMaterialModel() const;
	void SetLargeRawMaterialModel(string _arg0_);
	const string& GetLargeRawMaterialModel() const;
	void SetXLargeRawMaterialModel(string _arg0_);
	const string& GetXLargeRawMaterialModel() const;
	void SetSmallRawMaterialLongAnim(uint64_t _arg0_);
	const uint64_t& GetSmallRawMaterialLongAnim() const;
	void SetMediumRawMaterialLongAnim(uint64_t _arg0_);
	const uint64_t& GetMediumRawMaterialLongAnim() const;
	void SetLargeRawMaterialLongAnim(uint64_t _arg0_);
	const uint64_t& GetLargeRawMaterialLongAnim() const;
	void SetXLargeRawMaterialLongAnim(uint64_t _arg0_);
	const uint64_t& GetXLargeRawMaterialLongAnim() const;
	void SetSmallRawMaterialShortAnim(uint64_t _arg0_);
	const uint64_t& GetSmallRawMaterialShortAnim() const;
	void SetMediumRawMaterialShortAnim(uint64_t _arg0_);
	const uint64_t& GetMediumRawMaterialShortAnim() const;
	void SetLargeRawMaterialShortAnim(uint64_t _arg0_);
	const uint64_t& GetLargeRawMaterialShortAnim() const;
	void SetXLargeRawMaterialShortAnim(uint64_t _arg0_);
	const uint64_t& GetXLargeRawMaterialShortAnim() const;
	std::vector<ArkFabricationPlan>& GetFabricationPlans();
	const std::vector<ArkFabricationPlan>& GetFabricationPlans() const;
	std::vector<ArkFabricationPlanCategory>& GetCategories();
	const std::vector<ArkFabricationPlanCategory>& GetCategories() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108AE40);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108B080);
	static inline auto FInit = PreyFunction<bool(ArkFabricationPlans* const _this)>(0x108B200);
	static inline auto FFind = PreyFunction<const ArkFabricationPlan* (const ArkFabricationPlans* const _this, const uint64_t _id)>(0x108AEE0);
	static inline auto FFindCategory = PreyFunction<const ArkFabricationPlanCategory* (const ArkFabricationPlans* const _this, const uint64_t _id)>(0x108AF10);
	static inline auto FGetRawMaterialModel = PreyFunction<const string& (const ArkFabricationPlans* const _this, const EArkRawMaterialClass _class)>(0x108B1D0);
	static inline auto FGetRawMaterialAnim = PreyFunction<uint64_t(const ArkFabricationPlans* const _this, const EArkRawMaterialClass _class, bool _bLong)>(0x108B170);
};
#endif // !MOONCRASH
