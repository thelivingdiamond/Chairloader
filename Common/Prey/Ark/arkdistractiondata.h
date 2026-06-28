// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkEventDrivenAchievement.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/ui/ArkOptionLayout.h>

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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <_unknown/DistractionEvent.h>

class ArkClass;
class IArkValueBase;

// DistractionAnimation
// Header:  Prey/Ark/arkdistractiondata.h
class DistractionAnimation : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	enum class Type
	{
		normal = 0,
		multiStage = 1,
	};

	// DistractionAnimation::ArkFragmentProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkFragmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFragmentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionAnimation::ArkFragmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionAnimation::ArkFragmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// DistractionAnimation::ArkLoopMinTimeProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkLoopMinTimeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLoopMinTimeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionAnimation::ArkLoopMinTimeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionAnimation::ArkLoopMinTimeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// DistractionAnimation::ArkLoopMaxTimeProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkLoopMaxTimeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLoopMaxTimeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionAnimation::ArkLoopMaxTimeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionAnimation::ArkLoopMaxTimeProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
	};

	// DistractionAnimation::ArkTypeProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkTypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionAnimation::ArkTypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionAnimation::ArkTypeProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// DistractionAnimation::ArkHoverAddRootMotionProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkHoverAddRootMotionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHoverAddRootMotionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionAnimation::ArkHoverAddRootMotionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084730);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionAnimation::ArkHoverAddRootMotionProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
	};

	static inline auto s_ArkFragmentProperty = PreyGlobal<DistractionAnimation::ArkFragmentProperty>(0x2D22EA0);
	string m_Fragment;
	static inline auto s_ArkLoopMinTimeProperty = PreyGlobal<DistractionAnimation::ArkLoopMinTimeProperty>(0x2D22EC0);
	float m_LoopMinTime;
	static inline auto s_ArkLoopMaxTimeProperty = PreyGlobal<DistractionAnimation::ArkLoopMaxTimeProperty>(0x2D22EE0);
	float m_LoopMaxTime;
	static inline auto s_ArkTypeProperty = PreyGlobal<DistractionAnimation::ArkTypeProperty>(0x2D22F00);
	int m_Type;
	static inline auto s_ArkHoverAddRootMotionProperty = PreyGlobal<DistractionAnimation::ArkHoverAddRootMotionProperty>(0x2D22F20);
	bool m_HoverAddRootMotion;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	DistractionAnimation();
	void SetFragment(string _arg0_);
	const string& GetFragment() const;
	void SetLoopMinTime(float _arg0_);
	const float& GetLoopMinTime() const;
	void SetLoopMaxTime(float _arg0_);
	const float& GetLoopMaxTime() const;
	void SetType(int _arg0_);
	const int& GetType() const;
	void SetHoverAddRootMotion(bool _arg0_);
	const bool& GetHoverAddRootMotion() const;
	DistractionAnimation::Type GetActionType() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10851C0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1085390);
};

// DistractionLookAt
// Header:  Prey/Ark/arkdistractiondata.h
class DistractionLookAt : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	enum class Mode
	{
		EntityPosition = 0,
		EntityCenterBounds = 1,
		Disabled = 2,
	};

	// DistractionLookAt::ArkLookAtRelativePosXProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkLookAtRelativePosXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLookAtRelativePosXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionLookAt::ArkLookAtRelativePosXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionLookAt::ArkLookAtRelativePosXProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// DistractionLookAt::ArkLookAtRelativePosYProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkLookAtRelativePosYProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLookAtRelativePosYProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionLookAt::ArkLookAtRelativePosYProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionLookAt::ArkLookAtRelativePosYProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
	};

	// DistractionLookAt::ArkLookAtRelativePosZProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkLookAtRelativePosZProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLookAtRelativePosZProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionLookAt::ArkLookAtRelativePosZProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionLookAt::ArkLookAtRelativePosZProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// DistractionLookAt::ArkModeProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkModeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkModeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionLookAt::ArkModeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionLookAt::ArkModeProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
	};

	static inline auto s_ArkLookAtRelativePosXProperty = PreyGlobal<DistractionLookAt::ArkLookAtRelativePosXProperty>(0x2D22D00);
	float m_LookAtRelativePosX;
	static inline auto s_ArkLookAtRelativePosYProperty = PreyGlobal<DistractionLookAt::ArkLookAtRelativePosYProperty>(0x2D22D20);
	float m_LookAtRelativePosY;
	static inline auto s_ArkLookAtRelativePosZProperty = PreyGlobal<DistractionLookAt::ArkLookAtRelativePosZProperty>(0x2D22D40);
	float m_LookAtRelativePosZ;
	static inline auto s_ArkModeProperty = PreyGlobal<DistractionLookAt::ArkModeProperty>(0x2D22D60);
	int m_Mode;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	DistractionLookAt();
	void SetLookAtRelativePosX(float _arg0_);
	const float& GetLookAtRelativePosX() const;
	void SetLookAtRelativePosY(float _arg0_);
	const float& GetLookAtRelativePosY() const;
	void SetLookAtRelativePosZ(float _arg0_);
	const float& GetLookAtRelativePosZ() const;
	void SetMode(int _arg0_);
	const int& GetMode() const;
	Vec3 GetRelativePos() const;
	DistractionLookAt::Mode GetLookAtMode() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10895D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1085430);
};

// DistractionPositioning
// Header:  Prey/Ark/arkdistractiondata.h
class DistractionPositioning : public ArkReflectedObject
{ // Size=36 (0x24)
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

	// DistractionPositioning::ArkMinValidStandRadiusProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkMinValidStandRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinValidStandRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionPositioning::ArkMinValidStandRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionPositioning::ArkMinValidStandRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// DistractionPositioning::ArkMaxValidStandRadiusProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkMaxValidStandRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxValidStandRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionPositioning::ArkMaxValidStandRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionPositioning::ArkMaxValidStandRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
	};

	// DistractionPositioning::ArkPositionRelativePosXProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkPositionRelativePosXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPositionRelativePosXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionPositioning::ArkPositionRelativePosXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionPositioning::ArkPositionRelativePosXProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// DistractionPositioning::ArkPositionRelativePosYProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkPositionRelativePosYProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPositionRelativePosYProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionPositioning::ArkPositionRelativePosYProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionPositioning::ArkPositionRelativePosYProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
	};

	// DistractionPositioning::ArkPositionRelativePosZProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkPositionRelativePosZProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPositionRelativePosZProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionPositioning::ArkPositionRelativePosZProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionPositioning::ArkPositionRelativePosZProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// DistractionPositioning::ArkValidStandAngleProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkValidStandAngleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkValidStandAngleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionPositioning::ArkValidStandAngleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionPositioning::ArkValidStandAngleProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
	};

	// DistractionPositioning::ArkAngleOffsetProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkAngleOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAngleOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionPositioning::ArkAngleOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionPositioning::ArkAngleOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// DistractionPositioning::ArkModeProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkModeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkModeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionPositioning::ArkModeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionPositioning::ArkModeProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
	};

	// DistractionPositioning::ArkMoveSpeedProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkMoveSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMoveSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const DistractionPositioning::ArkMoveSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionPositioning::ArkMoveSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	static inline auto s_ArkMinValidStandRadiusProperty = PreyGlobal<DistractionPositioning::ArkMinValidStandRadiusProperty>(0x2D22D80);
	float m_MinValidStandRadius;
	static inline auto s_ArkMaxValidStandRadiusProperty = PreyGlobal<DistractionPositioning::ArkMaxValidStandRadiusProperty>(0x2D22DA0);
	float m_MaxValidStandRadius;
	static inline auto s_ArkPositionRelativePosXProperty = PreyGlobal<DistractionPositioning::ArkPositionRelativePosXProperty>(0x2D22DC0);
	float m_PositionRelativePosX;
	static inline auto s_ArkPositionRelativePosYProperty = PreyGlobal<DistractionPositioning::ArkPositionRelativePosYProperty>(0x2D22DE0);
	float m_PositionRelativePosY;
	static inline auto s_ArkPositionRelativePosZProperty = PreyGlobal<DistractionPositioning::ArkPositionRelativePosZProperty>(0x2D22E00);
	float m_PositionRelativePosZ;
	static inline auto s_ArkValidStandAngleProperty = PreyGlobal<DistractionPositioning::ArkValidStandAngleProperty>(0x2D22E20);
	float m_ValidStandAngle;
	static inline auto s_ArkAngleOffsetProperty = PreyGlobal<DistractionPositioning::ArkAngleOffsetProperty>(0x2D22E40);
	float m_AngleOffset;
	static inline auto s_ArkModeProperty = PreyGlobal<DistractionPositioning::ArkModeProperty>(0x2D22E60);
	int m_Mode;
	static inline auto s_ArkMoveSpeedProperty = PreyGlobal<DistractionPositioning::ArkMoveSpeedProperty>(0x2D22E80);
	int m_MoveSpeed;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	DistractionPositioning();
	void SetMinValidStandRadius(float _arg0_);
	const float& GetMinValidStandRadius() const;
	void SetMaxValidStandRadius(float _arg0_);
	const float& GetMaxValidStandRadius() const;
	void SetPositionRelativePosX(float _arg0_);
	const float& GetPositionRelativePosX() const;
	void SetPositionRelativePosY(float _arg0_);
	const float& GetPositionRelativePosY() const;
	void SetPositionRelativePosZ(float _arg0_);
	const float& GetPositionRelativePosZ() const;
	void SetValidStandAngle(float _arg0_);
	const float& GetValidStandAngle() const;
	void SetAngleOffset(float _arg0_);
	const float& GetAngleOffset() const;
	void SetMode(int _arg0_);
	const int& GetMode() const;
	void SetMoveSpeed(int _arg0_);
	const int& GetMoveSpeed() const;
	DistractionPositioning::Mode GetPositionMode() const;
	DistractionPositioning::MoveSpeed GetMoveSpeedMode() const;
	Vec3 GetOffset() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10851F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10854D0);
};

// Distraction
// Header:  Prey/Ark/arkdistractiondata.h
class Distraction : public ArkReflectedObject
{ // Size=176 (0xB0)
public:
	// Distraction::ArkIDProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// Distraction::ArkNameProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// Distraction::ArkDebugProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkDebugProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDebugProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkDebugProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkDebugProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// Distraction::ArkAbilityContextIdProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkAbilityContextIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAbilityContextIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkAbilityContextIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkAbilityContextIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// Distraction::ArkIgnoreNpcFacingCheckProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkIgnoreNpcFacingCheckProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIgnoreNpcFacingCheckProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkIgnoreNpcFacingCheckProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084750);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkIgnoreNpcFacingCheckProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// Distraction::ArkOnUseCooldownProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkOnUseCooldownProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkOnUseCooldownProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkOnUseCooldownProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkOnUseCooldownProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C370);
	};

	// Distraction::ArkCanBeUsedInZeroGProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkCanBeUsedInZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCanBeUsedInZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkCanBeUsedInZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkCanBeUsedInZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// Distraction::ArkReusableProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkReusableProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReusableProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkReusableProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084760);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkReusableProperty* const _this, ArkReflectedObject* const _pObject)>(0x108B5E0);
	};

	// Distraction::ArkSkipMovementProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkSkipMovementProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSkipMovementProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkSkipMovementProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108B5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkSkipMovementProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084770);
	};

	// Distraction::ArkCanBeSimultaneousProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkCanBeSimultaneousProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCanBeSimultaneousProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkCanBeSimultaneousProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084780);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkCanBeSimultaneousProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084790);
	};

	// Distraction::ArkCanRetreatToProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkCanRetreatToProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCanRetreatToProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkCanRetreatToProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084400);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkCanRetreatToProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3130);
	};

	// Distraction::ArkTriggersAreaCooldownProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkTriggersAreaCooldownProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTriggersAreaCooldownProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkTriggersAreaCooldownProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084410);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkTriggersAreaCooldownProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084420);
	};

	// Distraction::ArkUsesAreaCooldownProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkUsesAreaCooldownProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUsesAreaCooldownProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkUsesAreaCooldownProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084430);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkUsesAreaCooldownProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084440);
	};

	// Distraction::ArkUseableByTagProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkUseableByTagProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUseableByTagProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkUseableByTagProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B6480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkUseableByTagProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// Distraction::ArkTryDistractRateSecProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkTryDistractRateSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTryDistractRateSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkTryDistractRateSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3150);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkTryDistractRateSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// Distraction::ArkMaxDistractDistanceProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkMaxDistractDistanceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxDistractDistanceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkMaxDistractDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089EB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkMaxDistractDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3160);
	};

	// Distraction::ArkMaxDistractDistanceVerticalProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkMaxDistractDistanceVerticalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxDistractDistanceVerticalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkMaxDistractDistanceVerticalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084450);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkMaxDistractDistanceVerticalProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	// Distraction::ArkMaxDistractionAngleDegreesOffForwardProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkMaxDistractionAngleDegreesOffForwardProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxDistractionAngleDegreesOffForwardProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkMaxDistractionAngleDegreesOffForwardProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084460);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkMaxDistractionAngleDegreesOffForwardProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3170);
	};

	// Distraction::ArkMinDurationProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkMinDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkMinDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkMinDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EE90);
	};

	// Distraction::ArkMaxDurationProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkMaxDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkMaxDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkMaxDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084470);
	};

	// Distraction::ArkNpcUseColdownProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkNpcUseColdownProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNpcUseColdownProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkNpcUseColdownProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkNpcUseColdownProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
	};

	// Distraction::ArkMinHeightDifferenceProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkMinHeightDifferenceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinHeightDifferenceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkMinHeightDifferenceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084490);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkMinHeightDifferenceProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3190);
	};

	// Distraction::ArkMaxHeightDifferenceProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkMaxHeightDifferenceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxHeightDifferenceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkMaxHeightDifferenceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A31A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkMaxHeightDifferenceProperty* const _this, ArkReflectedObject* const _pObject)>(0x10844A0);
	};

	// Distraction::ArkDistractionLookAtProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkDistractionLookAtProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDistractionLookAtProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkDistractionLookAtProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10844B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkDistractionLookAtProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A31B0);
	};

	// Distraction::ArkDistractionPositioningProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkDistractionPositioningProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDistractionPositioningProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkDistractionPositioningProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10844C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkDistractionPositioningProperty* const _this, ArkReflectedObject* const _pObject)>(0x10844E0);
	};

	// Distraction::ArkDistractionAnimationProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkDistractionAnimationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDistractionAnimationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkDistractionAnimationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10844F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkDistractionAnimationProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6A0);
	};

	// Distraction::ArkDistractionEventProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkDistractionEventProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDistractionEventProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const Distraction::ArkDistractionEventProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10845C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const Distraction::ArkDistractionEventProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084620);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<Distraction::ArkIDProperty>(0x2D22F40);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<Distraction::ArkNameProperty>(0x2D22F60);
	string m_Name;
	static inline auto s_ArkDebugProperty = PreyGlobal<Distraction::ArkDebugProperty>(0x2D22F80);
	bool m_Debug;
	static inline auto s_ArkAbilityContextIdProperty = PreyGlobal<Distraction::ArkAbilityContextIdProperty>(0x2D22FA0);
	uint64_t m_AbilityContextId;
	static inline auto s_ArkIgnoreNpcFacingCheckProperty = PreyGlobal<Distraction::ArkIgnoreNpcFacingCheckProperty>(0x2D22FC0);
	bool m_IgnoreNpcFacingCheck;
	static inline auto s_ArkOnUseCooldownProperty = PreyGlobal<Distraction::ArkOnUseCooldownProperty>(0x2D22FE0);
	float m_OnUseCooldown;
	static inline auto s_ArkCanBeUsedInZeroGProperty = PreyGlobal<Distraction::ArkCanBeUsedInZeroGProperty>(0x2D23000);
	bool m_CanBeUsedInZeroG;
	static inline auto s_ArkReusableProperty = PreyGlobal<Distraction::ArkReusableProperty>(0x2D23020);
	bool m_Reusable;
	static inline auto s_ArkSkipMovementProperty = PreyGlobal<Distraction::ArkSkipMovementProperty>(0x2D23040);
	bool m_SkipMovement;
	static inline auto s_ArkCanBeSimultaneousProperty = PreyGlobal<Distraction::ArkCanBeSimultaneousProperty>(0x2D23060);
	bool m_CanBeSimultaneous;
	static inline auto s_ArkCanRetreatToProperty = PreyGlobal<Distraction::ArkCanRetreatToProperty>(0x2D23080);
	bool m_CanRetreatTo;
	static inline auto s_ArkTriggersAreaCooldownProperty = PreyGlobal<Distraction::ArkTriggersAreaCooldownProperty>(0x2D230A0);
	bool m_TriggersAreaCooldown;
	static inline auto s_ArkUsesAreaCooldownProperty = PreyGlobal<Distraction::ArkUsesAreaCooldownProperty>(0x2D230C0);
	bool m_UsesAreaCooldown;
	static inline auto s_ArkUseableByTagProperty = PreyGlobal<Distraction::ArkUseableByTagProperty>(0x2D230E0);
	uint64_t m_UseableByTag;
	static inline auto s_ArkTryDistractRateSecProperty = PreyGlobal<Distraction::ArkTryDistractRateSecProperty>(0x2D23100);
	float m_TryDistractRateSec;
	static inline auto s_ArkMaxDistractDistanceProperty = PreyGlobal<Distraction::ArkMaxDistractDistanceProperty>(0x2D23120);
	float m_MaxDistractDistance;
	static inline auto s_ArkMaxDistractDistanceVerticalProperty = PreyGlobal<Distraction::ArkMaxDistractDistanceVerticalProperty>(0x2D23140);
	float m_MaxDistractDistanceVertical;
	static inline auto s_ArkMaxDistractionAngleDegreesOffForwardProperty = PreyGlobal<Distraction::ArkMaxDistractionAngleDegreesOffForwardProperty>(0x2D23160);
	float m_MaxDistractionAngleDegreesOffForward;
	static inline auto s_ArkMinDurationProperty = PreyGlobal<Distraction::ArkMinDurationProperty>(0x2D23180);
	float m_MinDuration;
	static inline auto s_ArkMaxDurationProperty = PreyGlobal<Distraction::ArkMaxDurationProperty>(0x2D231A0);
	float m_MaxDuration;
	static inline auto s_ArkNpcUseColdownProperty = PreyGlobal<Distraction::ArkNpcUseColdownProperty>(0x2D231C0);
	float m_NpcUseColdown;
	static inline auto s_ArkMinHeightDifferenceProperty = PreyGlobal<Distraction::ArkMinHeightDifferenceProperty>(0x2D231E0);
	float m_MinHeightDifference;
	static inline auto s_ArkMaxHeightDifferenceProperty = PreyGlobal<Distraction::ArkMaxHeightDifferenceProperty>(0x2D23200);
	float m_MaxHeightDifference;
	static inline auto s_ArkDistractionLookAtProperty = PreyGlobal<Distraction::ArkDistractionLookAtProperty>(0x2D23220);
	DistractionLookAt m_DistractionLookAt;
	static inline auto s_ArkDistractionPositioningProperty = PreyGlobal<Distraction::ArkDistractionPositioningProperty>(0x2D23240);
	DistractionPositioning m_DistractionPositioning;
	static inline auto s_ArkDistractionAnimationProperty = PreyGlobal<Distraction::ArkDistractionAnimationProperty>(0x2D23260);
	DistractionAnimation m_DistractionAnimation;
	static inline auto s_ArkDistractionEventProperty = PreyGlobal<Distraction::ArkDistractionEventProperty>(0x2D23280);
	DistractionEvent m_DistractionEvent;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	Distraction();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetDebug(bool _arg0_);
	const bool& GetDebug() const;
	void SetAbilityContextId(uint64_t _arg0_);
	const uint64_t& GetAbilityContextId() const;
	void SetIgnoreNpcFacingCheck(bool _arg0_);
	const bool& GetIgnoreNpcFacingCheck() const;
	void SetOnUseCooldown(float _arg0_);
	const float& GetOnUseCooldown() const;
	void SetCanBeUsedInZeroG(bool _arg0_);
	const bool& GetCanBeUsedInZeroG() const;
	void SetReusable(bool _arg0_);
	const bool& GetReusable() const;
	void SetSkipMovement(bool _arg0_);
	const bool& GetSkipMovement() const;
	void SetCanBeSimultaneous(bool _arg0_);
	const bool& GetCanBeSimultaneous() const;
	void SetCanRetreatTo(bool _arg0_);
	const bool& GetCanRetreatTo() const;
	void SetTriggersAreaCooldown(bool _arg0_);
	const bool& GetTriggersAreaCooldown() const;
	void SetUsesAreaCooldown(bool _arg0_);
	const bool& GetUsesAreaCooldown() const;
	void SetUseableByTag(uint64_t _arg0_);
	const uint64_t& GetUseableByTag() const;
	void SetTryDistractRateSec(float _arg0_);
	const float& GetTryDistractRateSec() const;
	void SetMaxDistractDistance(float _arg0_);
	const float& GetMaxDistractDistance() const;
	void SetMaxDistractDistanceVertical(float _arg0_);
	const float& GetMaxDistractDistanceVertical() const;
	void SetMaxDistractionAngleDegreesOffForward(float _arg0_);
	const float& GetMaxDistractionAngleDegreesOffForward() const;
	void SetMinDuration(float _arg0_);
	const float& GetMinDuration() const;
	void SetMaxDuration(float _arg0_);
	const float& GetMaxDuration() const;
	void SetNpcUseColdown(float _arg0_);
	const float& GetNpcUseColdown() const;
	void SetMinHeightDifference(float _arg0_);
	const float& GetMinHeightDifference() const;
	void SetMaxHeightDifference(float _arg0_);
	const float& GetMaxHeightDifference() const;
	void SetDistractionLookAt(DistractionLookAt _arg0_);
	const DistractionLookAt& GetDistractionLookAt() const;
	void SetDistractionPositioning(DistractionPositioning _arg0_);
	const DistractionPositioning& GetDistractionPositioning() const;
	void SetDistractionAnimation(DistractionAnimation _arg0_);
	const DistractionAnimation& GetDistractionAnimation() const;
	void SetDistractionEvent(DistractionEvent _arg0_);
	const DistractionEvent& GetDistractionEvent() const;
	bool GetShouldSkipMovement() const;
	float GetWaitDuration() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1085180);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10852F0);
};

// ArkDistractions
// Header:  Prey/Ark/arkdistractiondata.h
class ArkDistractions : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkDistractions::ArkDistractionsProperty
	// Header:  Prey/Ark/arkdistractiondata.h
	class ArkDistractionsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkDistractionsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkDistractionsPropertyOv2 = PreyFunction<void(ArkDistractions::ArkDistractionsProperty* const _this)>(0x1084C60);
		static inline auto FSetValue = PreyFunction<void(const ArkDistractions::ArkDistractionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084630);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDistractions::ArkDistractionsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10846D0);
		static inline auto FIsArray = PreyFunction<bool(const ArkDistractions::ArkDistractionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkDistractions::ArkDistractionsProperty* const _this, ArkReflectedObject* _pObject)>(0x1084710);
	};

	static inline auto s_ArkDistractionsProperty = PreyGlobal<ArkDistractions::ArkDistractionsProperty>(0x2D232A0);
	std::vector<Distraction> m_Distractions;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	std::vector<Distraction>& GetDistractions();
	const std::vector<Distraction>& GetDistractions() const;
	const Distraction* GetDistractor(const uint64_t& _arg0_) const;
	const Distraction* GetDistractorByIndex(const int _arg0_) const;
	bool IsValidIndex(const int _arg0_) const;
	bool IsValidId(const uint64_t& _arg0_) const;
	int GetDistractionIndex(const uint64_t& _arg0_) const;
	uint64_t GetDistractionIDByIndex(const int _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1085120);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1085200);
	static inline auto FInit = PreyFunction<bool(ArkDistractions* const _this)>(0x1085570);
};
#endif // !MOONCRASH
