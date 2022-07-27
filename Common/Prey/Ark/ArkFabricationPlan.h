// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkfabricationplan.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>

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

