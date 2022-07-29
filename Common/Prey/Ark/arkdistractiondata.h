// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkeventdrivenachievement.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/ui/arkoptionlayout.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkdistractiondata.h
class DistractionPositioning : public ArkReflectedObject // Id=8013ABA Size=36
{
public:
	enum Mode
	{
		EntityPosition = 0,
		EntityCenterBounds = 1,
	};

	enum class MoveSpeed
	{
		Normal = 0,
		Fast = 1,
		Fastest = 2,
	};

	class ArkMinValidStandRadiusProperty : public ArkProperty // Id=8013ABB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionPositioning::ArkMinValidStandRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionPositioning::ArkMinValidStandRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static DistractionPositioning::ArkMinValidStandRadiusProperty s_ArkMinValidStandRadiusProperty;
	float m_MinValidStandRadius;
	
	class ArkMaxValidStandRadiusProperty : public ArkProperty // Id=8013ABC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionPositioning::ArkMaxValidStandRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionPositioning::ArkMaxValidStandRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static DistractionPositioning::ArkMaxValidStandRadiusProperty s_ArkMaxValidStandRadiusProperty;
	float m_MaxValidStandRadius;
	
	class ArkPositionRelativePosXProperty : public ArkProperty // Id=8013ABD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionPositioning::ArkPositionRelativePosXProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionPositioning::ArkPositionRelativePosXProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static DistractionPositioning::ArkPositionRelativePosXProperty s_ArkPositionRelativePosXProperty;
	float m_PositionRelativePosX;
	
	class ArkPositionRelativePosYProperty : public ArkProperty // Id=8013ABE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionPositioning::ArkPositionRelativePosYProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionPositioning::ArkPositionRelativePosYProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static DistractionPositioning::ArkPositionRelativePosYProperty s_ArkPositionRelativePosYProperty;
	float m_PositionRelativePosY;
	
	class ArkPositionRelativePosZProperty : public ArkProperty // Id=8013ABF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionPositioning::ArkPositionRelativePosZProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionPositioning::ArkPositionRelativePosZProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static DistractionPositioning::ArkPositionRelativePosZProperty s_ArkPositionRelativePosZProperty;
	float m_PositionRelativePosZ;
	
	class ArkValidStandAngleProperty : public ArkProperty // Id=8013AC0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionPositioning::ArkValidStandAngleProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionPositioning::ArkValidStandAngleProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static DistractionPositioning::ArkValidStandAngleProperty s_ArkValidStandAngleProperty;
	float m_ValidStandAngle;
	
	class ArkAngleOffsetProperty : public ArkProperty // Id=8013AC1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionPositioning::ArkAngleOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionPositioning::ArkAngleOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static DistractionPositioning::ArkAngleOffsetProperty s_ArkAngleOffsetProperty;
	float m_AngleOffset;
	
	class ArkModeProperty : public ArkProperty // Id=8013AC2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionPositioning::ArkModeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionPositioning::ArkModeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static DistractionPositioning::ArkModeProperty s_ArkModeProperty;
	int m_Mode;
	
	class ArkMoveSpeedProperty : public ArkProperty // Id=8013AC3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionPositioning::ArkMoveSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionPositioning::ArkMoveSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static DistractionPositioning::ArkMoveSpeedProperty s_ArkMoveSpeedProperty;
	int m_MoveSpeed;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetMinValidStandRadius(float arg0);
	const float &GetMinValidStandRadius() const;
	void SetMaxValidStandRadius(float arg0);
	const float &GetMaxValidStandRadius() const;
	void SetPositionRelativePosX(float arg0);
	const float &GetPositionRelativePosX() const;
	void SetPositionRelativePosY(float arg0);
	const float &GetPositionRelativePosY() const;
	void SetPositionRelativePosZ(float arg0);
	const float &GetPositionRelativePosZ() const;
	void SetValidStandAngle(float arg0);
	const float &GetValidStandAngle() const;
	void SetAngleOffset(float arg0);
	const float &GetAngleOffset() const;
	void SetMode(int arg0);
	const int &GetMode() const;
	void SetMoveSpeed(int arg0);
	const int &GetMoveSpeed() const;
	DistractionPositioning::Mode GetPositionMode() const;
	DistractionPositioning::MoveSpeed GetMoveSpeedMode() const;
	Vec3 GetOffset() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1062330);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1062610);
};

// Header: Exact
// Prey/Ark/arkdistractiondata.h
class DistractionAnimation : public ArkReflectedObject // Id=8013AC4 Size=24
{
public:
	enum class Type
	{
		normal = 0,
		multiStage = 1,
	};

	class ArkFragmentProperty : public ArkProperty // Id=8013AC5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionAnimation::ArkFragmentProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionAnimation::ArkFragmentProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static DistractionAnimation::ArkFragmentProperty s_ArkFragmentProperty;
	string m_Fragment;
	
	class ArkLoopMinTimeProperty : public ArkProperty // Id=8013AC6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionAnimation::ArkLoopMinTimeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionAnimation::ArkLoopMinTimeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static DistractionAnimation::ArkLoopMinTimeProperty s_ArkLoopMinTimeProperty;
	float m_LoopMinTime;
	
	class ArkLoopMaxTimeProperty : public ArkProperty // Id=8013AC7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionAnimation::ArkLoopMaxTimeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionAnimation::ArkLoopMaxTimeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static DistractionAnimation::ArkLoopMaxTimeProperty s_ArkLoopMaxTimeProperty;
	float m_LoopMaxTime;
	
	class ArkTypeProperty : public ArkProperty // Id=8013AC8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionAnimation::ArkTypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionAnimation::ArkTypeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static DistractionAnimation::ArkTypeProperty s_ArkTypeProperty;
	int m_Type;
	
	class ArkHoverAddRootMotionProperty : public ArkProperty // Id=8013AC9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionAnimation::ArkHoverAddRootMotionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1061610);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionAnimation::ArkHoverAddRootMotionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static DistractionAnimation::ArkHoverAddRootMotionProperty s_ArkHoverAddRootMotionProperty;
	bool m_HoverAddRootMotion;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetFragment(string arg0);
	string const &GetFragment() const;
	void SetLoopMinTime(float arg0);
	const float &GetLoopMinTime() const;
	void SetLoopMaxTime(float arg0);
	const float &GetLoopMaxTime() const;
	void SetType(int arg0);
	const int &GetType() const;
	void SetHoverAddRootMotion(bool arg0);
	const bool &GetHoverAddRootMotion() const;
	DistractionAnimation::Type GetActionType() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1062300);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10624D0);
};

// Header: Exact
// Prey/Ark/arkdistractiondata.h
class Distraction : public ArkReflectedObject // Id=8013ACA Size=160
{
public:
	class ArkIDProperty : public ArkProperty // Id=8013ACB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static Distraction::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013ACC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static Distraction::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkDebugProperty : public ArkProperty // Id=8013ACD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkDebugProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360190);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkDebugProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static Distraction::ArkDebugProperty s_ArkDebugProperty;
	bool m_Debug;
	
	class ArkIgnoreNpcFacingCheckProperty : public ArkProperty // Id=8013ACE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkIgnoreNpcFacingCheckProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1061620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkIgnoreNpcFacingCheckProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1061630);
	};

	static Distraction::ArkIgnoreNpcFacingCheckProperty s_ArkIgnoreNpcFacingCheckProperty;
	bool m_IgnoreNpcFacingCheck;
	
	class ArkOnUseCooldownProperty : public ArkProperty // Id=8013ACF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkOnUseCooldownProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkOnUseCooldownProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static Distraction::ArkOnUseCooldownProperty s_ArkOnUseCooldownProperty;
	float m_OnUseCooldown;
	
	class ArkCanBeUsedInZeroGProperty : public ArkProperty // Id=8013AD0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkCanBeUsedInZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkCanBeUsedInZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static Distraction::ArkCanBeUsedInZeroGProperty s_ArkCanBeUsedInZeroGProperty;
	bool m_CanBeUsedInZeroG;
	
	class ArkReusableProperty : public ArkProperty // Id=8013AD1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkReusableProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1061640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkReusableProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1061650);
	};

	static Distraction::ArkReusableProperty s_ArkReusableProperty;
	bool m_Reusable;
	
	class ArkSkipMovementProperty : public ArkProperty // Id=8013AD2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkSkipMovementProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1061660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkSkipMovementProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1061670);
	};

	static Distraction::ArkSkipMovementProperty s_ArkSkipMovementProperty;
	bool m_SkipMovement;
	
	class ArkCanBeSimultaneousProperty : public ArkProperty // Id=8013AD3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkCanBeSimultaneousProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1061680);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkCanBeSimultaneousProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1061690);
	};

	static Distraction::ArkCanBeSimultaneousProperty s_ArkCanBeSimultaneousProperty;
	bool m_CanBeSimultaneous;
	
	class ArkCanRetreatToProperty : public ArkProperty // Id=8013AD4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkCanRetreatToProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10616A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkCanRetreatToProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static Distraction::ArkCanRetreatToProperty s_ArkCanRetreatToProperty;
	bool m_CanRetreatTo;
	
	class ArkTriggersAreaCooldownProperty : public ArkProperty // Id=8013AD5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkTriggersAreaCooldownProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088970);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkTriggersAreaCooldownProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10616B0);
	};

	static Distraction::ArkTriggersAreaCooldownProperty s_ArkTriggersAreaCooldownProperty;
	bool m_TriggersAreaCooldown;
	
	class ArkUsesAreaCooldownProperty : public ArkProperty // Id=8013AD6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkUsesAreaCooldownProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10616C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkUsesAreaCooldownProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10616D0);
	};

	static Distraction::ArkUsesAreaCooldownProperty s_ArkUsesAreaCooldownProperty;
	bool m_UsesAreaCooldown;
	
	class ArkUseableByTagProperty : public ArkProperty // Id=8013AD7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkUseableByTagProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkUseableByTagProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static Distraction::ArkUseableByTagProperty s_ArkUseableByTagProperty;
	uint64_t m_UseableByTag;
	
	class ArkTryDistractRateSecProperty : public ArkProperty // Id=8013AD8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkTryDistractRateSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkTryDistractRateSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static Distraction::ArkTryDistractRateSecProperty s_ArkTryDistractRateSecProperty;
	float m_TryDistractRateSec;
	
	class ArkMaxDistractDistanceProperty : public ArkProperty // Id=8013AD9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkMaxDistractDistanceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkMaxDistractDistanceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328680);
	};

	static Distraction::ArkMaxDistractDistanceProperty s_ArkMaxDistractDistanceProperty;
	float m_MaxDistractDistance;
	
	class ArkMaxDistractDistanceVerticalProperty : public ArkProperty // Id=8013ADA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkMaxDistractDistanceVerticalProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkMaxDistractDistanceVerticalProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static Distraction::ArkMaxDistractDistanceVerticalProperty s_ArkMaxDistractDistanceVerticalProperty;
	float m_MaxDistractDistanceVertical;
	
	class ArkMaxDistractionAngleDegreesOffForwardProperty : public ArkProperty // Id=8013ADB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkMaxDistractionAngleDegreesOffForwardProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A610);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkMaxDistractionAngleDegreesOffForwardProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107A620);
	};

	static Distraction::ArkMaxDistractionAngleDegreesOffForwardProperty s_ArkMaxDistractionAngleDegreesOffForwardProperty;
	float m_MaxDistractionAngleDegreesOffForward;
	
	class ArkMinDurationProperty : public ArkProperty // Id=8013ADC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkMinDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A630);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkMinDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static Distraction::ArkMinDurationProperty s_ArkMinDurationProperty;
	float m_MinDuration;
	
	class ArkMaxDurationProperty : public ArkProperty // Id=8013ADD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkMaxDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkMaxDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328E30);
	};

	static Distraction::ArkMaxDurationProperty s_ArkMaxDurationProperty;
	float m_MaxDuration;
	
	class ArkNpcUseColdownProperty : public ArkProperty // Id=8013ADE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkNpcUseColdownProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A650);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkNpcUseColdownProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static Distraction::ArkNpcUseColdownProperty s_ArkNpcUseColdownProperty;
	float m_NpcUseColdown;
	
	class ArkMinHeightDifferenceProperty : public ArkProperty // Id=8013ADF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkMinHeightDifferenceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkMinHeightDifferenceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328490);
	};

	static Distraction::ArkMinHeightDifferenceProperty s_ArkMinHeightDifferenceProperty;
	float m_MinHeightDifference;
	
	class ArkMaxHeightDifferenceProperty : public ArkProperty // Id=8013AE0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkMaxHeightDifferenceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkMaxHeightDifferenceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
	};

	static Distraction::ArkMaxHeightDifferenceProperty s_ArkMaxHeightDifferenceProperty;
	float m_MaxHeightDifference;
	
	class ArkDistractionLookAtProperty : public ArkProperty // Id=8013AE1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkDistractionLookAtProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10616E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkDistractionLookAtProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105BA40);
	};

	static Distraction::ArkDistractionLookAtProperty s_ArkDistractionLookAtProperty;
	DistractionLookAt m_DistractionLookAt;
	
	class ArkDistractionPositioningProperty : public ArkProperty // Id=8013AE2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkDistractionPositioningProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10616F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkDistractionPositioningProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328A90);
	};

	static Distraction::ArkDistractionPositioningProperty s_ArkDistractionPositioningProperty;
	DistractionPositioning m_DistractionPositioning;
	
	class ArkDistractionAnimationProperty : public ArkProperty // Id=8013AE3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkDistractionAnimationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1061710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkDistractionAnimationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10617E0);
	};

	static Distraction::ArkDistractionAnimationProperty s_ArkDistractionAnimationProperty;
	DistractionAnimation m_DistractionAnimation;
	
	class ArkDistractionEventProperty : public ArkProperty // Id=8013AE4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(Distraction::ArkDistractionEventProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10572B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(Distraction::ArkDistractionEventProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10736E0);
	};

	static Distraction::ArkDistractionEventProperty s_ArkDistractionEventProperty;
	DistractionEvent m_DistractionEvent;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetDebug(bool arg0);
	const bool &GetDebug() const;
	void SetIgnoreNpcFacingCheck(bool arg0);
	const bool &GetIgnoreNpcFacingCheck() const;
	void SetOnUseCooldown(float arg0);
	const float &GetOnUseCooldown() const;
	void SetCanBeUsedInZeroG(bool arg0);
	const bool &GetCanBeUsedInZeroG() const;
	void SetReusable(bool arg0);
	const bool &GetReusable() const;
	void SetSkipMovement(bool arg0);
	const bool &GetSkipMovement() const;
	void SetCanBeSimultaneous(bool arg0);
	const bool &GetCanBeSimultaneous() const;
	void SetCanRetreatTo(bool arg0);
	const bool &GetCanRetreatTo() const;
	void SetTriggersAreaCooldown(bool arg0);
	const bool &GetTriggersAreaCooldown() const;
	void SetUsesAreaCooldown(bool arg0);
	const bool &GetUsesAreaCooldown() const;
	void SetUseableByTag(uint64_t arg0);
	const uint64_t &GetUseableByTag() const;
	void SetTryDistractRateSec(float arg0);
	const float &GetTryDistractRateSec() const;
	void SetMaxDistractDistance(float arg0);
	const float &GetMaxDistractDistance() const;
	void SetMaxDistractDistanceVertical(float arg0);
	const float &GetMaxDistractDistanceVertical() const;
	void SetMaxDistractionAngleDegreesOffForward(float arg0);
	const float &GetMaxDistractionAngleDegreesOffForward() const;
	void SetMinDuration(float arg0);
	const float &GetMinDuration() const;
	void SetMaxDuration(float arg0);
	const float &GetMaxDuration() const;
	void SetNpcUseColdown(float arg0);
	const float &GetNpcUseColdown() const;
	void SetMinHeightDifference(float arg0);
	const float &GetMinHeightDifference() const;
	void SetMaxHeightDifference(float arg0);
	const float &GetMaxHeightDifference() const;
	void SetDistractionLookAt(DistractionLookAt arg0);
	DistractionLookAt const &GetDistractionLookAt() const;
	void SetDistractionPositioning(DistractionPositioning arg0);
	DistractionPositioning const &GetDistractionPositioning() const;
	void SetDistractionAnimation(DistractionAnimation arg0);
	DistractionAnimation const &GetDistractionAnimation() const;
	void SetDistractionEvent(DistractionEvent arg0);
	DistractionEvent const &GetDistractionEvent() const;
	bool GetShouldSkipMovement() const;
	float GetWaitDuration() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10622C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1062430);
};

// Header: Exact
// Prey/Ark/arkdistractiondata.h
class ArkDistractions : public ArkReflectedLibrary // Id=8013AF6 Size=32
{
public:
	class ArkDistractionsProperty : public ArkProperty // Id=8013AF7 Size=32
	{
	public:
		ArkDistractionsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDistractions::ArkDistractionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10617F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDistractions::ArkDistractionsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1061890);
		static inline auto FIsArray = PreyFunction<bool(ArkDistractions::ArkDistractionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkDistractions::ArkDistractionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x10618D0);
	};

	static ArkDistractions::ArkDistractionsProperty s_ArkDistractionsProperty;
	std::vector<Distraction> m_Distractions;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkDistractions();
	
#if 0
	std::vector<Distraction> &GetDistractions();
	std::vector<Distraction> const &GetDistractions() const;
	Distraction const *GetDistractor(const uint64_t &arg0) const;
	Distraction const *GetDistractorByIndex(const int arg0) const;
	bool IsValidIndex(const int arg0) const;
	bool IsValidId(const uint64_t &arg0) const;
	int GetDistractionIndex(const uint64_t &arg0) const;
	uint64_t GetDistractionIDByIndex(const int arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1062260);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1062340);
	static inline auto FInit = PreyFunction<bool(ArkDistractions *const _this)>(0x10626B0);
};

// Header: Exact
// Prey/Ark/arkdistractiondata.h
class ArkUtility : public ArkReflectedObject // Id=8016BA0 Size=32
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016BA1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkUtility::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkUtility::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkUtility::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016BA2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkUtility::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkUtility::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkUtility::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=8016BA3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkUtility::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkUtility::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkUtility::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkTypeProperty : public ArkProperty // Id=8016BA4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const arg0, IArkValueBase const *arg1) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const arg0) const;
	};

	static ArkUtility::ArkTypeProperty s_ArkTypeProperty;
	ArkUtilityType m_Type;
	
	class ArkEnabledProperty : public ArkProperty // Id=8016BA5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkUtility::ArkEnabledProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10616A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkUtility::ArkEnabledProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkUtility::ArkEnabledProperty s_ArkEnabledProperty;
	bool m_Enabled;
	
	class ArkHiddenProperty : public ArkProperty // Id=8016BA6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkUtility::ArkHiddenProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088970);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkUtility::ArkHiddenProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10616B0);
	};

	static ArkUtility::ArkHiddenProperty s_ArkHiddenProperty;
	bool m_Hidden;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetType(ArkUtilityType arg0);
	ArkUtilityType const &GetType() const;
	void SetEnabled(bool arg0);
	const bool &GetEnabled() const;
	void SetHidden(bool arg0);
	const bool &GetHidden() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x108A940);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x108AF00);
};

// Header: Exact
// Prey/Ark/arkdistractiondata.h
class ArkUtilityButton : public ArkReflectedObject // Id=8016BA9 Size=32
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016BAA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkUtilityButton::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkUtilityButton::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkUtilityButton::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016BAB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkUtilityButton::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkUtilityButton::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkUtilityButton::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=8016BAC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkUtilityButton::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkUtilityButton::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkUtilityButton::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkEnabledProperty : public ArkProperty // Id=8016BAD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkUtilityButton::ArkEnabledProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkUtilityButton::ArkEnabledProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkUtilityButton::ArkEnabledProperty s_ArkEnabledProperty;
	bool m_Enabled;
	
	class ArkHiddenProperty : public ArkProperty // Id=8016BAE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkUtilityButton::ArkHiddenProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1061640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkUtilityButton::ArkHiddenProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1061650);
	};

	static ArkUtilityButton::ArkHiddenProperty s_ArkHiddenProperty;
	bool m_Hidden;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetEnabled(bool arg0);
	const bool &GetEnabled() const;
	void SetHidden(bool arg0);
	const bool &GetHidden() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x108A980);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x108AFA0);
};

// Header: Exact
// Prey/Ark/arkdistractiondata.h
class ArkStationAirlock : public ArkReflectedObject // Id=8016C3B Size=24
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016C3C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStationAirlock::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStationAirlock::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkStationAirlock::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkLocationProperty : public ArkProperty // Id=8016C3D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStationAirlock::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107F050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStationAirlock::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkStationAirlock::ArkLocationProperty s_ArkLocationProperty;
	uint64_t m_Location;
	
	class ArkStartsLockedProperty : public ArkProperty // Id=8016C3E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStationAirlock::ArkStartsLockedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360190);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStationAirlock::ArkStartsLockedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkStationAirlock::ArkStartsLockedProperty s_ArkStartsLockedProperty;
	bool m_StartsLocked;
	
	class ArkStartsHiddenProperty : public ArkProperty // Id=8016C3F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStationAirlock::ArkStartsHiddenProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1061620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStationAirlock::ArkStartsHiddenProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1061630);
	};

	static ArkStationAirlock::ArkStartsHiddenProperty s_ArkStartsHiddenProperty;
	bool m_StartsHidden;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetLocation(uint64_t arg0);
	const uint64_t &GetLocation() const;
	void SetStartsLocked(bool arg0);
	const bool &GetStartsLocked() const;
	void SetStartsHidden(bool arg0);
	const bool &GetStartsHidden() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107F840);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107FA00);
};

