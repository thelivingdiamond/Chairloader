// Header file automatically created from a PDB.

#pragma once
#ifdef MOONCRASH
#include <Prey/Ark/arkdistractiondata.h>   // Mooncrash dumps DistractionLookAt there
#endif
#include <Prey/Ark/ArkEventDrivenAchievement.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkeventdrivenachievement.h
#ifdef MOONCRASH
#include <Prey/ArkCommon/reflection/ArkProperty.h>
class IArkValueBase;
class DistractionLookAt;
class ArkMetricComparison;
class ArkEventDrivenAchievement;
class ArkEventDrivenAchievementLibrary;
#endif
#ifndef MOONCRASH
class DistractionLookAt : public ArkReflectedObject // Id=8013AB5 Size=16
{
public:
	enum class Mode
	{
		EntityPosition = 0,
		EntityCenterBounds = 1,
		Disabled = 2,
	};

	class ArkLookAtRelativePosXProperty : public ArkProperty // Id=8013AB6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(DistractionLookAt::ArkLookAtRelativePosXProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionLookAt::ArkLookAtRelativePosXProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const DistractionLookAt::ArkLookAtRelativePosXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionLookAt::ArkLookAtRelativePosXProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static DistractionLookAt::ArkLookAtRelativePosXProperty s_ArkLookAtRelativePosXProperty;
#else
	static inline auto s_ArkLookAtRelativePosXProperty = PreyGlobal<DistractionLookAt::ArkLookAtRelativePosXProperty>(0x2D22D00);
#endif
	float m_LookAtRelativePosX;
	
	class ArkLookAtRelativePosYProperty : public ArkProperty // Id=8013AB7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(DistractionLookAt::ArkLookAtRelativePosYProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionLookAt::ArkLookAtRelativePosYProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
#else
		static inline auto FSetValue = PreyFunction<void(const DistractionLookAt::ArkLookAtRelativePosYProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionLookAt::ArkLookAtRelativePosYProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
#endif
	};

#ifndef MOONCRASH
	static DistractionLookAt::ArkLookAtRelativePosYProperty s_ArkLookAtRelativePosYProperty;
#else
	static inline auto s_ArkLookAtRelativePosYProperty = PreyGlobal<DistractionLookAt::ArkLookAtRelativePosYProperty>(0x2D22D20);
#endif
	float m_LookAtRelativePosY;
	
	class ArkLookAtRelativePosZProperty : public ArkProperty // Id=8013AB8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(DistractionLookAt::ArkLookAtRelativePosZProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionLookAt::ArkLookAtRelativePosZProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const DistractionLookAt::ArkLookAtRelativePosZProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionLookAt::ArkLookAtRelativePosZProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static DistractionLookAt::ArkLookAtRelativePosZProperty s_ArkLookAtRelativePosZProperty;
#else
	static inline auto s_ArkLookAtRelativePosZProperty = PreyGlobal<DistractionLookAt::ArkLookAtRelativePosZProperty>(0x2D22D40);
#endif
	float m_LookAtRelativePosZ;
	
	class ArkModeProperty : public ArkProperty // Id=8013AB9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(DistractionLookAt::ArkModeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionLookAt::ArkModeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
#else
		static inline auto FSetValue = PreyFunction<void(const DistractionLookAt::ArkModeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionLookAt::ArkModeProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
#endif
	};

#ifndef MOONCRASH
	static DistractionLookAt::ArkModeProperty s_ArkModeProperty;
#else
	static inline auto s_ArkModeProperty = PreyGlobal<DistractionLookAt::ArkModeProperty>(0x2D22D60);
#endif
	int m_Mode;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetLookAtRelativePosX(float arg0);
	const float &GetLookAtRelativePosX() const;
	void SetLookAtRelativePosY(float arg0);
	const float &GetLookAtRelativePosY() const;
	void SetLookAtRelativePosZ(float arg0);
	const float &GetLookAtRelativePosZ() const;
	void SetMode(int arg0);
	const int &GetMode() const;
	Vec3 GetRelativePos() const;
	DistractionLookAt::Mode GetLookAtMode() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1065B90);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1062570);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10895D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1085430);
#endif
};
#endif

// Header: Exact
// Prey/Ark/arkeventdrivenachievement.h
class ArkMetricComparison : public ArkReflectedObject // Id=8013B86 Size=16
{
public:
	class ArkMetricProperty : public ArkProperty // Id=8013B87 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMetricComparison::ArkMetricProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMetricComparison::ArkMetricProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMetricComparison::ArkMetricProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMetricComparison::ArkMetricProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkMetricComparison::ArkMetricProperty s_ArkMetricProperty;
#else
	static inline auto s_ArkMetricProperty = PreyGlobal<ArkMetricComparison::ArkMetricProperty>(0x2D239E0);
#endif
	uint64_t m_Metric;
	
	class ArkComparisonTypeProperty : public ArkProperty // Id=8013B88 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMetricComparison::ArkComparisonTypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064F40);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMetricComparison::ArkComparisonTypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1088820);
#endif
	};

#ifndef MOONCRASH
	static ArkMetricComparison::ArkComparisonTypeProperty s_ArkComparisonTypeProperty;
#else
	static inline auto s_ArkComparisonTypeProperty = PreyGlobal<ArkMetricComparison::ArkComparisonTypeProperty>(0x2D23A00);
#endif
	EArkComparisonType m_ComparisonType;
	
	class ArkValueProperty : public ArkProperty // Id=8013B89 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMetricComparison::ArkValueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMetricComparison::ArkValueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMetricComparison::ArkValueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMetricComparison::ArkValueProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
#endif
	};

#ifndef MOONCRASH
	static ArkMetricComparison::ArkValueProperty s_ArkValueProperty;
#else
	static inline auto s_ArkValueProperty = PreyGlobal<ArkMetricComparison::ArkValueProperty>(0x2D23A20);
#endif
	unsigned m_Value;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetMetric(uint64_t arg0);
	const uint64_t &GetMetric() const;
	void SetComparisonType(string arg0);
	EArkComparisonType const &GetComparisonType() const;
	void SetValue(unsigned arg0);
	const unsigned &GetValue() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1065B90);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1065D30);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10895D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1089770);
#endif
};

// Header: Exact
// Prey/Ark/ArkEventDrivenAchievement.h
class ArkEventDrivenAchievement : public ArkReflectedObject // Id=8013B8A Size=48
{
public:
	class ArkIDProperty : public ArkProperty // Id=8013B8B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEventDrivenAchievement::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEventDrivenAchievement::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEventDrivenAchievement::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEventDrivenAchievement::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkEventDrivenAchievement::ArkIDProperty s_ArkIDProperty;
#else
	static inline auto s_ArkIDProperty = PreyGlobal<ArkEventDrivenAchievement::ArkIDProperty>(0x2D23A40);
#endif
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013B8C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEventDrivenAchievement::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEventDrivenAchievement::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEventDrivenAchievement::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEventDrivenAchievement::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkEventDrivenAchievement::ArkNameProperty s_ArkNameProperty;
#else
	static inline auto s_ArkNameProperty = PreyGlobal<ArkEventDrivenAchievement::ArkNameProperty>(0x2D23A60);
#endif
	string m_Name;
	
	class ArkRewardIDProperty : public ArkProperty // Id=8013B8D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEventDrivenAchievement::ArkRewardIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEventDrivenAchievement::ArkRewardIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEventDrivenAchievement::ArkRewardIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEventDrivenAchievement::ArkRewardIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

#ifndef MOONCRASH
	static ArkEventDrivenAchievement::ArkRewardIDProperty s_ArkRewardIDProperty;
#else
	static inline auto s_ArkRewardIDProperty = PreyGlobal<ArkEventDrivenAchievement::ArkRewardIDProperty>(0x2D23A80);
#endif
	unsigned m_RewardID;
	
	class ArkMetricComparisonsProperty : public ArkProperty // Id=8013B8E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEventDrivenAchievement::ArkMetricComparisonsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEventDrivenAchievement::ArkMetricComparisonsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064FE0);
		static inline auto FIsArray = PreyFunction<bool(ArkEventDrivenAchievement::ArkMetricComparisonsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEventDrivenAchievement::ArkMetricComparisonsProperty const *const _this, ArkReflectedObject *_pObject)>(0x107FE50);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEventDrivenAchievement::ArkMetricComparisonsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1088880);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEventDrivenAchievement::ArkMetricComparisonsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10888B0);
		static inline auto FIsArray = PreyFunction<bool(const ArkEventDrivenAchievement::ArkMetricComparisonsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEventDrivenAchievement::ArkMetricComparisonsProperty* const _this, ArkReflectedObject* _pObject)>(0x10888D0);
#endif
	};

#ifndef MOONCRASH
	static ArkEventDrivenAchievement::ArkMetricComparisonsProperty s_ArkMetricComparisonsProperty;
#else
	static inline auto s_ArkMetricComparisonsProperty = PreyGlobal<ArkEventDrivenAchievement::ArkMetricComparisonsProperty>(0x2D23AA0);
#endif
	std::vector<ArkMetricComparison> m_MetricComparisons;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetRewardID(unsigned arg0);
	const unsigned &GetRewardID() const;
	std::vector<ArkMetricComparison> &GetMetricComparisons();
	std::vector<ArkMetricComparison> const &GetMetricComparisons() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1065AF0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1065BA0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1089530);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10895E0);
#endif
};

// Header: Exact
// Prey/Ark/arkeventdrivenachievement.h
class ArkEventDrivenAchievementLibrary : public ArkReflectedLibrary // Id=8013BAA Size=32
{
public:
	class ArkEventDrivenAchievementsProperty : public ArkProperty // Id=8013BAB Size=32
	{
	public:
		ArkEventDrivenAchievementsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064DE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064E70);
		static inline auto FIsArray = PreyFunction<bool(ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1064EB0);
#else
		static inline auto FArkEventDrivenAchievementsPropertyOv2 = PreyFunction<void(ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty* const _this)>(0x1089210);
		static inline auto FSetValue = PreyFunction<void(const ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10888E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088970);
		static inline auto FIsArray = PreyFunction<bool(const ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty* const _this, ArkReflectedObject* _pObject)>(0x10889B0);
#endif
	};

#ifndef MOONCRASH
	static ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty s_ArkEventDrivenAchievementsProperty;
#else
	static inline auto s_ArkEventDrivenAchievementsProperty = PreyGlobal<ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty>(0x2D23AC0);
#endif
	std::vector<ArkEventDrivenAchievement> m_EventDrivenAchievements;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkEventDrivenAchievementLibrary();
	
#if 0
	std::vector<ArkEventDrivenAchievement> &GetEventDrivenAchievements();
	std::vector<ArkEventDrivenAchievement> const &GetEventDrivenAchievements() const;
	ArkEventDrivenAchievement const *Find(const uint64_t arg0) const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1065B30);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1065C40);
	static inline auto FInit = PreyFunction<bool(ArkEventDrivenAchievementLibrary *const _this)>(0x1065DD0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1089570);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1089680);
	static inline auto FInit = PreyFunction<bool(ArkEventDrivenAchievementLibrary* const _this)>(0x1089810);
#endif
};
