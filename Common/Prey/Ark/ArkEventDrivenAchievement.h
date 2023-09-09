// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkEventDrivenAchievement.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkeventdrivenachievement.h
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
		
		static inline auto FSetValue = PreyFunction<void(DistractionLookAt::ArkLookAtRelativePosXProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionLookAt::ArkLookAtRelativePosXProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static DistractionLookAt::ArkLookAtRelativePosXProperty s_ArkLookAtRelativePosXProperty;
	float m_LookAtRelativePosX;
	
	class ArkLookAtRelativePosYProperty : public ArkProperty // Id=8013AB7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionLookAt::ArkLookAtRelativePosYProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionLookAt::ArkLookAtRelativePosYProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static DistractionLookAt::ArkLookAtRelativePosYProperty s_ArkLookAtRelativePosYProperty;
	float m_LookAtRelativePosY;
	
	class ArkLookAtRelativePosZProperty : public ArkProperty // Id=8013AB8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionLookAt::ArkLookAtRelativePosZProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionLookAt::ArkLookAtRelativePosZProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static DistractionLookAt::ArkLookAtRelativePosZProperty s_ArkLookAtRelativePosZProperty;
	float m_LookAtRelativePosZ;
	
	class ArkModeProperty : public ArkProperty // Id=8013AB9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionLookAt::ArkModeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionLookAt::ArkModeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static DistractionLookAt::ArkModeProperty s_ArkModeProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1065B90);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1062570);
};

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
		
		static inline auto FSetValue = PreyFunction<void(ArkMetricComparison::ArkMetricProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMetricComparison::ArkMetricProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkMetricComparison::ArkMetricProperty s_ArkMetricProperty;
	uint64_t m_Metric;
	
	class ArkComparisonTypeProperty : public ArkProperty // Id=8013B88 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMetricComparison::ArkComparisonTypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064F40);
	};

	static ArkMetricComparison::ArkComparisonTypeProperty s_ArkComparisonTypeProperty;
	EArkComparisonType m_ComparisonType;
	
	class ArkValueProperty : public ArkProperty // Id=8013B89 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMetricComparison::ArkValueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMetricComparison::ArkValueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkMetricComparison::ArkValueProperty s_ArkValueProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1065B90);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1065D30);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkEventDrivenAchievement::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEventDrivenAchievement::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkEventDrivenAchievement::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013B8C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEventDrivenAchievement::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEventDrivenAchievement::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkEventDrivenAchievement::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkRewardIDProperty : public ArkProperty // Id=8013B8D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEventDrivenAchievement::ArkRewardIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEventDrivenAchievement::ArkRewardIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkEventDrivenAchievement::ArkRewardIDProperty s_ArkRewardIDProperty;
	unsigned m_RewardID;
	
	class ArkMetricComparisonsProperty : public ArkProperty // Id=8013B8E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEventDrivenAchievement::ArkMetricComparisonsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEventDrivenAchievement::ArkMetricComparisonsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064FE0);
		static inline auto FIsArray = PreyFunction<bool(ArkEventDrivenAchievement::ArkMetricComparisonsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEventDrivenAchievement::ArkMetricComparisonsProperty const *const _this, ArkReflectedObject *_pObject)>(0x107FE50);
	};

	static ArkEventDrivenAchievement::ArkMetricComparisonsProperty s_ArkMetricComparisonsProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1065AF0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1065BA0);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064DE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064E70);
		static inline auto FIsArray = PreyFunction<bool(ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1064EB0);
	};

	static ArkEventDrivenAchievementLibrary::ArkEventDrivenAchievementsProperty s_ArkEventDrivenAchievementsProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1065B30);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1065C40);
	static inline auto FInit = PreyFunction<bool(ArkEventDrivenAchievementLibrary *const _this)>(0x1065DD0);
};

