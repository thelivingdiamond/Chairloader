// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/GameDll/ark/player/arkaimassistconfig.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/player/ArkAimAssistConfig.h
class ArkAimAssistConfig : public ArkReflectedObject // Id=801718F Size=48
{
public:
	class ArkMagnetismProperty : public ArkProperty // Id=8017190 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistConfig::ArkMagnetismProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistConfig::ArkMagnetismProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkAimAssistConfig::ArkMagnetismProperty s_ArkMagnetismProperty;
	float m_Magnetism;
	
	class ArkSprintMagnetismProperty : public ArkProperty // Id=8017191 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistConfig::ArkSprintMagnetismProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistConfig::ArkSprintMagnetismProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkAimAssistConfig::ArkSprintMagnetismProperty s_ArkSprintMagnetismProperty;
	float m_SprintMagnetism;
	
	class ArkCenteringProperty : public ArkProperty // Id=8017192 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistConfig::ArkCenteringProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistConfig::ArkCenteringProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkAimAssistConfig::ArkCenteringProperty s_ArkCenteringProperty;
	float m_Centering;
	
	class ArkSprintCenteringProperty : public ArkProperty // Id=8017193 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistConfig::ArkSprintCenteringProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistConfig::ArkSprintCenteringProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkAimAssistConfig::ArkSprintCenteringProperty s_ArkSprintCenteringProperty;
	float m_SprintCentering;
	
	class ArkAimAssistDeadZoneProperty : public ArkProperty // Id=8017194 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistConfig::ArkAimAssistDeadZoneProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistConfig::ArkAimAssistDeadZoneProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkAimAssistConfig::ArkAimAssistDeadZoneProperty s_ArkAimAssistDeadZoneProperty;
	float m_AimAssistDeadZone;
	
	class ArkEntitiesProperty : public ArkProperty // Id=8017195 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistConfig::ArkEntitiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12EC780);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistConfig::ArkEntitiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12EC820);
		static inline auto FIsArray = PreyFunction<bool(ArkAimAssistConfig::ArkEntitiesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAimAssistConfig::ArkEntitiesProperty const *const _this, ArkReflectedObject *_pObject)>(0x12EC840);
	};

	static ArkAimAssistConfig::ArkEntitiesProperty s_ArkEntitiesProperty;
	std::vector<ArkAimAssistEntity> m_Entities;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	ArkAimAssistConfig();
	void Init() { FInit(this); }
	
#if 0
	void SetMagnetism(float arg0);
	const float &GetMagnetism() const;
	void SetSprintMagnetism(float arg0);
	const float &GetSprintMagnetism() const;
	void SetCentering(float arg0);
	const float &GetCentering() const;
	void SetSprintCentering(float arg0);
	const float &GetSprintCentering() const;
	void SetAimAssistDeadZone(float arg0);
	const float &GetAimAssistDeadZone() const;
	std::vector<ArkAimAssistEntity> &GetEntities();
	std::vector<ArkAimAssistEntity> const &GetEntities() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12ED350);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12ED420);
	static inline auto FInit = PreyFunction<void(ArkAimAssistConfig *const _this)>(0x12ED600);
};

// Header: Exact
// Prey/GameDll/ark/player/arkaimassistconfig.h
class ArkAimAssistShape : public ArkReflectedObject // Id=801719C Size=32
{
public:
	class ArkPointsProperty : public ArkProperty // Id=801719D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistShape::ArkPointsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12EC8C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistShape::ArkPointsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12EC920);
		static inline auto FIsArray = PreyFunction<bool(ArkAimAssistShape::ArkPointsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAimAssistShape::ArkPointsProperty const *const _this, ArkReflectedObject *_pObject)>(0x13EF480);
	};

	static ArkAimAssistShape::ArkPointsProperty s_ArkPointsProperty;
	std::vector<ArkAimAssistPoint> m_Points;
	
	class ArkInnerRadiusProperty : public ArkProperty // Id=80171AD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistShape::ArkInnerRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistShape::ArkInnerRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkAimAssistShape::ArkInnerRadiusProperty s_ArkInnerRadiusProperty;
	float m_InnerRadius;
	
	class ArkOuterRadiusProperty : public ArkProperty // Id=80171AE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistShape::ArkOuterRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistShape::ArkOuterRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkAimAssistShape::ArkOuterRadiusProperty s_ArkOuterRadiusProperty;
	float m_OuterRadius;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	std::vector<ArkAimAssistPoint> &GetPoints();
	std::vector<ArkAimAssistPoint> const &GetPoints() const;
	void SetInnerRadius(float arg0);
	const float &GetInnerRadius() const;
	void SetOuterRadius(float arg0);
	const float &GetOuterRadius() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12ED3E0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12ED560);
};

// Header: Exact
// Prey/GameDll/ark/player/arkaimassistconfig.h
class ArkAimAssistEntity : public ArkReflectedObject // Id=8017199 Size=40
{
public:
	class ArkNameProperty : public ArkProperty // Id=801719A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistEntity::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistEntity::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkAimAssistEntity::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkShapeProperty : public ArkProperty // Id=801719B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistEntity::ArkShapeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12EC6F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistEntity::ArkShapeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkAimAssistEntity::ArkShapeProperty s_ArkShapeProperty;
	ArkAimAssistShape m_Shape;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetName(string arg0);
	string const &GetName() const;
	void SetShape(ArkAimAssistShape arg0);
	ArkAimAssistShape const &GetShape() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12ED390);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12ED4C0);
};

