// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkAimAssistPoint
// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
class ArkAimAssistPoint : public ArkReflectedObject
{ // Size=8 (0x8)
public:
	// ArkAimAssistPoint::ArkAttachmentNameProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkAttachmentNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttachmentNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistPoint::ArkAttachmentNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistPoint::ArkAttachmentNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	static inline auto s_ArkAttachmentNameProperty = PreyGlobal<ArkAimAssistPoint::ArkAttachmentNameProperty>(0x2BD9630);
	string m_AttachmentName;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetAttachmentName(string _arg0_);
	const string& GetAttachmentName() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13644E0);
};

// ArkAimAssistShape
// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
class ArkAimAssistShape : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkAimAssistShape::ArkPointsProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkPointsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkPointsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistShape::ArkPointsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12EC8C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistShape::ArkPointsProperty* const _this, ArkReflectedObject* const _pObject)>(0x12EC920);
		static inline auto FIsArray = PreyFunction<bool(const ArkAimAssistShape::ArkPointsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkAimAssistShape::ArkPointsProperty* const _this, ArkReflectedObject* _pObject)>(0x13EF480);
	};

	// ArkAimAssistShape::ArkInnerRadiusProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkInnerRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInnerRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistShape::ArkInnerRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistShape::ArkInnerRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkAimAssistShape::ArkOuterRadiusProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkOuterRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkOuterRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistShape::ArkOuterRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistShape::ArkOuterRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D570);
	};

	static inline auto s_ArkPointsProperty = PreyGlobal<ArkAimAssistShape::ArkPointsProperty>(0x2BD9650);
	std::vector<ArkAimAssistPoint> m_Points;
	static inline auto s_ArkInnerRadiusProperty = PreyGlobal<ArkAimAssistShape::ArkInnerRadiusProperty>(0x2BD9670);
	float m_InnerRadius;
	static inline auto s_ArkOuterRadiusProperty = PreyGlobal<ArkAimAssistShape::ArkOuterRadiusProperty>(0x2BD9690);
	float m_OuterRadius;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkAimAssistShape();
	std::vector<ArkAimAssistPoint>& GetPoints();
	const std::vector<ArkAimAssistPoint>& GetPoints() const;
	void SetInnerRadius(float _arg0_);
	const float& GetInnerRadius() const;
	void SetOuterRadius(float _arg0_);
	const float& GetOuterRadius() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12ED3E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12ED560);
};

// ArkAimAssistEntity
// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
class ArkAimAssistEntity : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkAimAssistEntity::ArkNameProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistEntity::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistEntity::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkAimAssistEntity::ArkShapeProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkShapeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkShapeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistEntity::ArkShapeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12EC6F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistEntity::ArkShapeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	static inline auto s_ArkNameProperty = PreyGlobal<ArkAimAssistEntity::ArkNameProperty>(0x2BD96D0);
	string m_Name;
	static inline auto s_ArkShapeProperty = PreyGlobal<ArkAimAssistEntity::ArkShapeProperty>(0x2BD96B0);
	ArkAimAssistShape m_Shape;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetShape(ArkAimAssistShape _arg0_);
	const ArkAimAssistShape& GetShape() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12ED390);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12ED4C0);
};

// ArkAimAssistConfig
// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
class ArkAimAssistConfig : public ArkReflectedObject
{ // Size=48 (0x30)
public:
	// ArkAimAssistConfig::ArkMagnetismProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkMagnetismProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMagnetismProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistConfig::ArkMagnetismProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistConfig::ArkMagnetismProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkAimAssistConfig::ArkSprintMagnetismProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkSprintMagnetismProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSprintMagnetismProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistConfig::ArkSprintMagnetismProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistConfig::ArkSprintMagnetismProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	// ArkAimAssistConfig::ArkCenteringProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkCenteringProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCenteringProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistConfig::ArkCenteringProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistConfig::ArkCenteringProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkAimAssistConfig::ArkSprintCenteringProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkSprintCenteringProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSprintCenteringProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistConfig::ArkSprintCenteringProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistConfig::ArkSprintCenteringProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkAimAssistConfig::ArkAimAssistDeadZoneProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkAimAssistDeadZoneProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAimAssistDeadZoneProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistConfig::ArkAimAssistDeadZoneProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistConfig::ArkAimAssistDeadZoneProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkAimAssistConfig::ArkEntitiesProperty
	// Header:  Prey/GameDll/ark/player/ArkAimAssistConfig.h
	class ArkEntitiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkEntitiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAimAssistConfig::ArkEntitiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12EC780);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAimAssistConfig::ArkEntitiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x12EC820);
		static inline auto FIsArray = PreyFunction<bool(const ArkAimAssistConfig::ArkEntitiesProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkAimAssistConfig::ArkEntitiesProperty* const _this, ArkReflectedObject* _pObject)>(0x12EC840);
	};

	static inline auto s_ArkMagnetismProperty = PreyGlobal<ArkAimAssistConfig::ArkMagnetismProperty>(0x2BD96F0);
	float m_Magnetism;
	static inline auto s_ArkSprintMagnetismProperty = PreyGlobal<ArkAimAssistConfig::ArkSprintMagnetismProperty>(0x2BD9710);
	float m_SprintMagnetism;
	static inline auto s_ArkCenteringProperty = PreyGlobal<ArkAimAssistConfig::ArkCenteringProperty>(0x2BD9730);
	float m_Centering;
	static inline auto s_ArkSprintCenteringProperty = PreyGlobal<ArkAimAssistConfig::ArkSprintCenteringProperty>(0x2BD9750);
	float m_SprintCentering;
	static inline auto s_ArkAimAssistDeadZoneProperty = PreyGlobal<ArkAimAssistConfig::ArkAimAssistDeadZoneProperty>(0x2BD9770);
	float m_AimAssistDeadZone;
	static inline auto s_ArkEntitiesProperty = PreyGlobal<ArkAimAssistConfig::ArkEntitiesProperty>(0x2BD9790);
	std::vector<ArkAimAssistEntity> m_Entities;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	ArkAimAssistConfig();
	void Init() { FInit(this); }

#if 0
	void SetMagnetism(float _arg0_);
	const float& GetMagnetism() const;
	void SetSprintMagnetism(float _arg0_);
	const float& GetSprintMagnetism() const;
	void SetCentering(float _arg0_);
	const float& GetCentering() const;
	void SetSprintCentering(float _arg0_);
	const float& GetSprintCentering() const;
	void SetAimAssistDeadZone(float _arg0_);
	const float& GetAimAssistDeadZone() const;
	std::vector<ArkAimAssistEntity>& GetEntities();
	const std::vector<ArkAimAssistEntity>& GetEntities() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12ED350);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12ED420);
	static inline auto FArkAimAssistConfigOv2 = PreyFunction<void(ArkAimAssistConfig* const _this)>(0x12ED330);
	static inline auto FInit = PreyFunction<void(ArkAimAssistConfig* const _this)>(0x12ED600);
};

