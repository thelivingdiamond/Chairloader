// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/Ark/arkloreentry.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowertargetingcomponent.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>
#include <Prey/GameDll/ark/ui/arkinputlegend.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicRigidProperties : public ArkReflectedObject // Id=801944E Size=144
{
public:
	class ArkDamageSignalGroupIdProperty : public ArkProperty // Id=801944F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkDamageSignalGroupIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkDamageSignalGroupIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiMimicRigidProperties::ArkDamageSignalGroupIdProperty s_ArkDamageSignalGroupIdProperty;
	uint64_t m_DamageSignalGroupId;
	
	class ArkJumpHeightProperty : public ArkProperty // Id=8019450 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkJumpHeightProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkJumpHeightProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiMimicRigidProperties::ArkJumpHeightProperty s_ArkJumpHeightProperty;
	float m_JumpHeight;
	
	class ArkPenetratingJumpHeightProperty : public ArkProperty // Id=8019451 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkPenetratingJumpHeightProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkPenetratingJumpHeightProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkPsiMimicRigidProperties::ArkPenetratingJumpHeightProperty s_ArkPenetratingJumpHeightProperty;
	float m_PenetratingJumpHeight;
	
	class ArkMoveSpeedProperty : public ArkProperty // Id=8019452 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkMoveSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkMoveSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiMimicRigidProperties::ArkMoveSpeedProperty s_ArkMoveSpeedProperty;
	float m_MoveSpeed;
	
	class ArkSprintSpeedProperty : public ArkProperty // Id=8019453 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkSprintSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkSprintSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkPsiMimicRigidProperties::ArkSprintSpeedProperty s_ArkSprintSpeedProperty;
	float m_SprintSpeed;
	
	class ArkTumbleSpeedProperty : public ArkProperty // Id=8019454 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkTumbleSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkTumbleSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiMimicRigidProperties::ArkTumbleSpeedProperty s_ArkTumbleSpeedProperty;
	float m_TumbleSpeed;
	
	class ArkLiftMaxAngularSpeedProperty : public ArkProperty // Id=8019455 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkLiftMaxAngularSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkLiftMaxAngularSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkPsiMimicRigidProperties::ArkLiftMaxAngularSpeedProperty s_ArkLiftMaxAngularSpeedProperty;
	float m_LiftMaxAngularSpeed;
	
	class ArkTumbleSpeedLinearThresholdProperty : public ArkProperty // Id=8019456 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkTumbleSpeedLinearThresholdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkTumbleSpeedLinearThresholdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiMimicRigidProperties::ArkTumbleSpeedLinearThresholdProperty s_ArkTumbleSpeedLinearThresholdProperty;
	float m_TumbleSpeedLinearThreshold;
	
	class ArkMoveSpeedZeroGProperty : public ArkProperty // Id=8019457 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkMoveSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkMoveSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328510);
	};

	static ArkPsiMimicRigidProperties::ArkMoveSpeedZeroGProperty s_ArkMoveSpeedZeroGProperty;
	float m_MoveSpeedZeroG;
	
	class ArkSprintSpeedZeroGProperty : public ArkProperty // Id=8019458 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkSprintSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkSprintSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkPsiMimicRigidProperties::ArkSprintSpeedZeroGProperty s_ArkSprintSpeedZeroGProperty;
	float m_SprintSpeedZeroG;
	
	class ArkRollSpeedZeroGProperty : public ArkProperty // Id=8019459 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkRollSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkRollSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328680);
	};

	static ArkPsiMimicRigidProperties::ArkRollSpeedZeroGProperty s_ArkRollSpeedZeroGProperty;
	float m_RollSpeedZeroG;
	
	class ArkAirControlScaleProperty : public ArkProperty // Id=801945A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkAirControlScaleProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkAirControlScaleProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkPsiMimicRigidProperties::ArkAirControlScaleProperty s_ArkAirControlScaleProperty;
	float m_AirControlScale;
	
	class ArkNoiseIdProperty : public ArkProperty // Id=801945B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkNoiseIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328520);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkNoiseIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkPsiMimicRigidProperties::ArkNoiseIdProperty s_ArkNoiseIdProperty;
	uint64_t m_NoiseId;
	
	class ArkLoudnessIdProperty : public ArkProperty // Id=801945C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkLoudnessIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105B9E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkLoudnessIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkPsiMimicRigidProperties::ArkLoudnessIdProperty s_ArkLoudnessIdProperty;
	uint64_t m_LoudnessId;
	
	class ArkNoiseIntervalProperty : public ArkProperty // Id=801945D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkNoiseIntervalProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkNoiseIntervalProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
	};

	static ArkPsiMimicRigidProperties::ArkNoiseIntervalProperty s_ArkNoiseIntervalProperty;
	float m_NoiseInterval;
	
	class ArkModalLegendProperty : public ArkProperty // Id=801945E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkModalLegendProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328530);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkModalLegendProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkPsiMimicRigidProperties::ArkModalLegendProperty s_ArkModalLegendProperty;
	ArkInputLegend m_ModalLegend;
	
	class ArkModalLegendZeroGProperty : public ArkProperty // Id=801945F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicRigidProperties::ArkModalLegendZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicRigidProperties::ArkModalLegendZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1082260);
	};

	static ArkPsiMimicRigidProperties::ArkModalLegendZeroGProperty s_ArkModalLegendZeroGProperty;
	ArkInputLegend m_ModalLegendZeroG;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDamageSignalGroupId(uint64_t arg0);
	const uint64_t &GetDamageSignalGroupId() const;
	void SetJumpHeight(float arg0);
	const float &GetJumpHeight() const;
	void SetPenetratingJumpHeight(float arg0);
	const float &GetPenetratingJumpHeight() const;
	void SetMoveSpeed(float arg0);
	const float &GetMoveSpeed() const;
	void SetSprintSpeed(float arg0);
	const float &GetSprintSpeed() const;
	void SetTumbleSpeed(float arg0);
	const float &GetTumbleSpeed() const;
	void SetLiftMaxAngularSpeed(float arg0);
	const float &GetLiftMaxAngularSpeed() const;
	void SetTumbleSpeedLinearThreshold(float arg0);
	const float &GetTumbleSpeedLinearThreshold() const;
	void SetMoveSpeedZeroG(float arg0);
	const float &GetMoveSpeedZeroG() const;
	void SetSprintSpeedZeroG(float arg0);
	const float &GetSprintSpeedZeroG() const;
	void SetRollSpeedZeroG(float arg0);
	const float &GetRollSpeedZeroG() const;
	void SetAirControlScale(float arg0);
	const float &GetAirControlScale() const;
	void SetNoiseId(uint64_t arg0);
	const uint64_t &GetNoiseId() const;
	void SetLoudnessId(uint64_t arg0);
	const uint64_t &GetLoudnessId() const;
	void SetNoiseInterval(float arg0);
	const float &GetNoiseInterval() const;
	void SetModalLegend(ArkInputLegend arg0);
	ArkInputLegend const &GetModalLegend() const;
	void SetModalLegendZeroG(ArkInputLegend arg0);
	ArkInputLegend const &GetModalLegendZeroG() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x132A720);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x132AB80);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicTurretProperties : public ArkReflectedObject // Id=8019460 Size=96
{
public:
	class ArkAimSpeedProperty : public ArkProperty // Id=8019461 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicTurretProperties::ArkAimSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicTurretProperties::ArkAimSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiMimicTurretProperties::ArkAimSpeedProperty s_ArkAimSpeedProperty;
	float m_AimSpeed;
	
	class ArkAimSpeedZeroGProperty : public ArkProperty // Id=8019462 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicTurretProperties::ArkAimSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicTurretProperties::ArkAimSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkPsiMimicTurretProperties::ArkAimSpeedZeroGProperty s_ArkAimSpeedZeroGProperty;
	float m_AimSpeedZeroG;
	
	class ArkMoveSpeedZeroGProperty : public ArkProperty // Id=8019463 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicTurretProperties::ArkMoveSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicTurretProperties::ArkMoveSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiMimicTurretProperties::ArkMoveSpeedZeroGProperty s_ArkMoveSpeedZeroGProperty;
	float m_MoveSpeedZeroG;
	
	class ArkSprintSpeedZeroGProperty : public ArkProperty // Id=8019464 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicTurretProperties::ArkSprintSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicTurretProperties::ArkSprintSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkPsiMimicTurretProperties::ArkSprintSpeedZeroGProperty s_ArkSprintSpeedZeroGProperty;
	float m_SprintSpeedZeroG;
	
	class ArkRollSpeedZeroGProperty : public ArkProperty // Id=8019465 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicTurretProperties::ArkRollSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicTurretProperties::ArkRollSpeedZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiMimicTurretProperties::ArkRollSpeedZeroGProperty s_ArkRollSpeedZeroGProperty;
	float m_RollSpeedZeroG;
	
	class ArkRecoilForceZeroGProperty : public ArkProperty // Id=8019466 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicTurretProperties::ArkRecoilForceZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicTurretProperties::ArkRecoilForceZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkPsiMimicTurretProperties::ArkRecoilForceZeroGProperty s_ArkRecoilForceZeroGProperty;
	float m_RecoilForceZeroG;
	
	class ArkDefaultCameraOffsetProperty : public ArkProperty // Id=8019467 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328BA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetProperty s_ArkDefaultCameraOffsetProperty;
	Vec3 m_DefaultCameraOffset;
	
	class ArkDefaultCameraOffsetZeroGProperty : public ArkProperty // Id=8019468 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328510);
	};

	static ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetZeroGProperty s_ArkDefaultCameraOffsetZeroGProperty;
	Vec3 m_DefaultCameraOffsetZeroG;
	
	class ArkAttackCameraOffsetProperty : public ArkProperty // Id=8019469 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicTurretProperties::ArkAttackCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicTurretProperties::ArkAttackCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkPsiMimicTurretProperties::ArkAttackCameraOffsetProperty s_ArkAttackCameraOffsetProperty;
	Vec3 m_AttackCameraOffset;
	
	class ArkModalLegendProperty : public ArkProperty // Id=801946A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicTurretProperties::ArkModalLegendProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328C30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicTurretProperties::ArkModalLegendProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkPsiMimicTurretProperties::ArkModalLegendProperty s_ArkModalLegendProperty;
	ArkInputLegend m_ModalLegend;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetAimSpeed(float arg0);
	const float &GetAimSpeed() const;
	void SetAimSpeedZeroG(float arg0);
	const float &GetAimSpeedZeroG() const;
	void SetMoveSpeedZeroG(float arg0);
	const float &GetMoveSpeedZeroG() const;
	void SetSprintSpeedZeroG(float arg0);
	const float &GetSprintSpeedZeroG() const;
	void SetRollSpeedZeroG(float arg0);
	const float &GetRollSpeedZeroG() const;
	void SetRecoilForceZeroG(float arg0);
	const float &GetRecoilForceZeroG() const;
	void SetDefaultCameraOffset(Vec3 arg0);
	Vec3 const &GetDefaultCameraOffset() const;
	void SetDefaultCameraOffsetZeroG(Vec3 arg0);
	Vec3 const &GetDefaultCameraOffsetZeroG() const;
	void SetAttackCameraOffset(Vec3 arg0);
	Vec3 const &GetAttackCameraOffset() const;
	void SetModalLegend(ArkInputLegend arg0);
	ArkInputLegend const &GetModalLegend() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x132A7E0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x132ACC0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicOperatorProperties : public ArkReflectedObject // Id=801946B Size=64
{
public:
	class ArkModalLegendProperty : public ArkProperty // Id=801946C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicOperatorProperties::ArkModalLegendProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicOperatorProperties::ArkModalLegendProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiMimicOperatorProperties::ArkModalLegendProperty s_ArkModalLegendProperty;
	ArkInputLegend m_ModalLegend;
	
	class ArkModalLegendZeroGProperty : public ArkProperty // Id=801946D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicOperatorProperties::ArkModalLegendZeroGProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328D70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicOperatorProperties::ArkModalLegendZeroGProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiMimicOperatorProperties::ArkModalLegendZeroGProperty s_ArkModalLegendZeroGProperty;
	ArkInputLegend m_ModalLegendZeroG;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetModalLegend(ArkInputLegend arg0);
	ArkInputLegend const &GetModalLegend() const;
	void SetModalLegendZeroG(ArkInputLegend arg0);
	ArkInputLegend const &GetModalLegendZeroG() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x132A6C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x132AAE0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicMilitaryOperatorProperties : public ArkReflectedObject // Id=801946E Size=84
{
public:
	class ArkLaserDamageProperty : public ArkProperty // Id=801946F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicMilitaryOperatorProperties::ArkLaserDamageProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicMilitaryOperatorProperties::ArkLaserDamageProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiMimicMilitaryOperatorProperties::ArkLaserDamageProperty s_ArkLaserDamageProperty;
	float m_LaserDamage;
	
	class ArkMoveSpeedProperty : public ArkProperty // Id=8019470 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicMilitaryOperatorProperties::ArkMoveSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicMilitaryOperatorProperties::ArkMoveSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkPsiMimicMilitaryOperatorProperties::ArkMoveSpeedProperty s_ArkMoveSpeedProperty;
	float m_MoveSpeed;
	
	class ArkSprintSpeedProperty : public ArkProperty // Id=8019471 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicMilitaryOperatorProperties::ArkSprintSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicMilitaryOperatorProperties::ArkSprintSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiMimicMilitaryOperatorProperties::ArkSprintSpeedProperty s_ArkSprintSpeedProperty;
	float m_SprintSpeed;
	
	class ArkDefaultTurnSpeedProperty : public ArkProperty // Id=8019472 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicMilitaryOperatorProperties::ArkDefaultTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicMilitaryOperatorProperties::ArkDefaultTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkPsiMimicMilitaryOperatorProperties::ArkDefaultTurnSpeedProperty s_ArkDefaultTurnSpeedProperty;
	float m_DefaultTurnSpeed;
	
	class ArkAttackTurnSpeedProperty : public ArkProperty // Id=8019473 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicMilitaryOperatorProperties::ArkAttackTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicMilitaryOperatorProperties::ArkAttackTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiMimicMilitaryOperatorProperties::ArkAttackTurnSpeedProperty s_ArkAttackTurnSpeedProperty;
	float m_AttackTurnSpeed;
	
	class ArkRollSpeedProperty : public ArkProperty // Id=8019474 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicMilitaryOperatorProperties::ArkRollSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicMilitaryOperatorProperties::ArkRollSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkPsiMimicMilitaryOperatorProperties::ArkRollSpeedProperty s_ArkRollSpeedProperty;
	float m_RollSpeed;
	
	class ArkDefaultCameraOffsetProperty : public ArkProperty // Id=8019475 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328BA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraOffsetProperty s_ArkDefaultCameraOffsetProperty;
	Vec3 m_DefaultCameraOffset;
	
	class ArkDefaultCameraZeroGOffsetProperty : public ArkProperty // Id=8019476 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328510);
	};

	static ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraZeroGOffsetProperty s_ArkDefaultCameraZeroGOffsetProperty;
	Vec3 m_DefaultCameraZeroGOffset;
	
	class ArkAttackCameraOffsetProperty : public ArkProperty // Id=8019477 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraOffsetProperty s_ArkAttackCameraOffsetProperty;
	Vec3 m_AttackCameraOffset;
	
	class ArkAttackCameraZeroGOffsetProperty : public ArkProperty // Id=8019478 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066410);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328E30);
	};

	static ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraZeroGOffsetProperty s_ArkAttackCameraZeroGOffsetProperty;
	Vec3 m_AttackCameraZeroGOffset;
	
	class ArkSafeCameraOffsetProperty : public ArkProperty // Id=8019479 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicMilitaryOperatorProperties::ArkSafeCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328ED0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicMilitaryOperatorProperties::ArkSafeCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
	};

	static ArkPsiMimicMilitaryOperatorProperties::ArkSafeCameraOffsetProperty s_ArkSafeCameraOffsetProperty;
	Vec3 m_SafeCameraOffset;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetLaserDamage(float arg0);
	const float &GetLaserDamage() const;
	void SetMoveSpeed(float arg0);
	const float &GetMoveSpeed() const;
	void SetSprintSpeed(float arg0);
	const float &GetSprintSpeed() const;
	void SetDefaultTurnSpeed(float arg0);
	const float &GetDefaultTurnSpeed() const;
	void SetAttackTurnSpeed(float arg0);
	const float &GetAttackTurnSpeed() const;
	void SetRollSpeed(float arg0);
	const float &GetRollSpeed() const;
	void SetDefaultCameraOffset(Vec3 arg0);
	Vec3 const &GetDefaultCameraOffset() const;
	void SetDefaultCameraZeroGOffset(Vec3 arg0);
	Vec3 const &GetDefaultCameraZeroGOffset() const;
	void SetAttackCameraOffset(Vec3 arg0);
	Vec3 const &GetAttackCameraOffset() const;
	void SetAttackCameraZeroGOffset(Vec3 arg0);
	Vec3 const &GetAttackCameraZeroGOffset() const;
	void SetSafeCameraOffset(Vec3 arg0);
	Vec3 const &GetSafeCameraOffset() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x132A680);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x132AA40);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicEngineeringOperatorProperties : public ArkReflectedObject // Id=801947A Size=176
{
public:
	class ArkMoveSpeedProperty : public ArkProperty // Id=801947B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkMoveSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkMoveSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkMoveSpeedProperty s_ArkMoveSpeedProperty;
	float m_MoveSpeed;
	
	class ArkSprintSpeedProperty : public ArkProperty // Id=801947C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkSprintSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkSprintSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkSprintSpeedProperty s_ArkSprintSpeedProperty;
	float m_SprintSpeed;
	
	class ArkDefaultTurnSpeedProperty : public ArkProperty // Id=801947D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkDefaultTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkDefaultTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkDefaultTurnSpeedProperty s_ArkDefaultTurnSpeedProperty;
	float m_DefaultTurnSpeed;
	
	class ArkAttackTurnSpeedProperty : public ArkProperty // Id=801947E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkAttackTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkAttackTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkAttackTurnSpeedProperty s_ArkAttackTurnSpeedProperty;
	float m_AttackTurnSpeed;
	
	class ArkRollSpeedProperty : public ArkProperty // Id=801947F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkRollSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkRollSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkRollSpeedProperty s_ArkRollSpeedProperty;
	float m_RollSpeed;
	
	class ArkAttackSignalPackageIdProperty : public ArkProperty // Id=8019480 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkAttackSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkAttackSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkAttackSignalPackageIdProperty s_ArkAttackSignalPackageIdProperty;
	uint64_t m_AttackSignalPackageId;
	
	class ArkDefaultCameraOffsetProperty : public ArkProperty // Id=8019481 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328420);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraOffsetProperty s_ArkDefaultCameraOffsetProperty;
	Vec3 m_DefaultCameraOffset;
	
	class ArkDefaultCameraZeroGOffsetProperty : public ArkProperty // Id=8019482 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328450);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328680);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraZeroGOffsetProperty s_ArkDefaultCameraZeroGOffsetProperty;
	Vec3 m_DefaultCameraZeroGOffset;
	
	class ArkAttackCameraOffsetProperty : public ArkProperty // Id=8019483 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328690);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraOffsetProperty s_ArkAttackCameraOffsetProperty;
	Vec3 m_AttackCameraOffset;
	
	class ArkAttackCameraZeroGOffsetProperty : public ArkProperty // Id=8019484 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13288E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328490);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraZeroGOffsetProperty s_ArkAttackCameraZeroGOffsetProperty;
	Vec3 m_AttackCameraZeroGOffset;
	
	class ArkSafeCameraOffsetProperty : public ArkProperty // Id=8019485 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkSafeCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13284A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkSafeCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkSafeCameraOffsetProperty s_ArkSafeCameraOffsetProperty;
	Vec3 m_SafeCameraOffset;
	
	class ArkSwitchCameraInputLegendItemProperty : public ArkProperty // Id=8019486 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicEngineeringOperatorProperties::ArkSwitchCameraInputLegendItemProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13284D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicEngineeringOperatorProperties::ArkSwitchCameraInputLegendItemProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086170);
	};

	static ArkPsiMimicEngineeringOperatorProperties::ArkSwitchCameraInputLegendItemProperty s_ArkSwitchCameraInputLegendItemProperty;
	ArkInputLegendItem m_SwitchCameraInputLegendItem;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetMoveSpeed(float arg0);
	const float &GetMoveSpeed() const;
	void SetSprintSpeed(float arg0);
	const float &GetSprintSpeed() const;
	void SetDefaultTurnSpeed(float arg0);
	const float &GetDefaultTurnSpeed() const;
	void SetAttackTurnSpeed(float arg0);
	const float &GetAttackTurnSpeed() const;
	void SetRollSpeed(float arg0);
	const float &GetRollSpeed() const;
	void SetAttackSignalPackageId(uint64_t arg0);
	const uint64_t &GetAttackSignalPackageId() const;
	void SetDefaultCameraOffset(Vec3 arg0);
	Vec3 const &GetDefaultCameraOffset() const;
	void SetDefaultCameraZeroGOffset(Vec3 arg0);
	Vec3 const &GetDefaultCameraZeroGOffset() const;
	void SetAttackCameraOffset(Vec3 arg0);
	Vec3 const &GetAttackCameraOffset() const;
	void SetAttackCameraZeroGOffset(Vec3 arg0);
	Vec3 const &GetAttackCameraZeroGOffset() const;
	void SetSafeCameraOffset(Vec3 arg0);
	Vec3 const &GetSafeCameraOffset() const;
	void SetSwitchCameraInputLegendItem(ArkInputLegendItem arg0);
	ArkInputLegendItem const &GetSwitchCameraInputLegendItem() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x132A5F0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x132A9A0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicScienceOperatorProperties : public ArkReflectedObject // Id=8019487 Size=176
{
public:
	class ArkMoveSpeedProperty : public ArkProperty // Id=8019488 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkMoveSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkMoveSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkMoveSpeedProperty s_ArkMoveSpeedProperty;
	float m_MoveSpeed;
	
	class ArkSprintSpeedProperty : public ArkProperty // Id=8019489 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkSprintSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkSprintSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkSprintSpeedProperty s_ArkSprintSpeedProperty;
	float m_SprintSpeed;
	
	class ArkDefaultTurnSpeedProperty : public ArkProperty // Id=801948A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkDefaultTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkDefaultTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkDefaultTurnSpeedProperty s_ArkDefaultTurnSpeedProperty;
	float m_DefaultTurnSpeed;
	
	class ArkAttackTurnSpeedProperty : public ArkProperty // Id=801948B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkAttackTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkAttackTurnSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkAttackTurnSpeedProperty s_ArkAttackTurnSpeedProperty;
	float m_AttackTurnSpeed;
	
	class ArkRollSpeedProperty : public ArkProperty // Id=801948C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkRollSpeedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkRollSpeedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkRollSpeedProperty s_ArkRollSpeedProperty;
	float m_RollSpeed;
	
	class ArkAttackSignalPackageIdProperty : public ArkProperty // Id=801948D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkAttackSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkAttackSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkAttackSignalPackageIdProperty s_ArkAttackSignalPackageIdProperty;
	uint64_t m_AttackSignalPackageId;
	
	class ArkDefaultCameraOffsetProperty : public ArkProperty // Id=801948E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328420);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraOffsetProperty s_ArkDefaultCameraOffsetProperty;
	Vec3 m_DefaultCameraOffset;
	
	class ArkDefaultCameraZeroGOffsetProperty : public ArkProperty // Id=801948F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328450);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328680);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraZeroGOffsetProperty s_ArkDefaultCameraZeroGOffsetProperty;
	Vec3 m_DefaultCameraZeroGOffset;
	
	class ArkAttackCameraOffsetProperty : public ArkProperty // Id=8019490 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkAttackCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328690);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkAttackCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkAttackCameraOffsetProperty s_ArkAttackCameraOffsetProperty;
	Vec3 m_AttackCameraOffset;
	
	class ArkAttackCameraZeroGOffsetProperty : public ArkProperty // Id=8019491 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkAttackCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13288E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkAttackCameraZeroGOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328490);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkAttackCameraZeroGOffsetProperty s_ArkAttackCameraZeroGOffsetProperty;
	Vec3 m_AttackCameraZeroGOffset;
	
	class ArkSafeCameraOffsetProperty : public ArkProperty // Id=8019492 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkSafeCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13284A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkSafeCameraOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkSafeCameraOffsetProperty s_ArkSafeCameraOffsetProperty;
	Vec3 m_SafeCameraOffset;
	
	class ArkMaxTargetAngleProperty : public ArkProperty // Id=8019493 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkMaxTargetAngleProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328A80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkMaxTargetAngleProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328A90);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkMaxTargetAngleProperty s_ArkMaxTargetAngleProperty;
	float m_MaxTargetAngle;
	
	class ArkMaxTargetDistanceProperty : public ArkProperty // Id=8019494 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkMaxTargetDistanceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328AA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkMaxTargetDistanceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086170);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkMaxTargetDistanceProperty s_ArkMaxTargetDistanceProperty;
	float m_MaxTargetDistance;
	
	class ArkValidTargetMetaTagsProperty : public ArkProperty // Id=8019495 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328AB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328AD0);
		static inline auto FIsArray = PreyFunction<bool(ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1328AF0);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty s_ArkValidTargetMetaTagsProperty;
	std::vector<unsigned __int64> m_ValidTargetMetaTags;
	
	class ArkValidTargetClassesProperty : public ArkProperty // Id=8019496 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328B00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328B60);
		static inline auto FIsArray = PreyFunction<bool(ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1328B90);
	};

	static ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty s_ArkValidTargetClassesProperty;
	std::vector<string> m_ValidTargetClasses;
	std::vector<IEntityClass const *> m_loadedClasses;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	void InitializeValidTargetClasses() { FInitializeValidTargetClasses(this); }
	
#if 0
	void SetMoveSpeed(float arg0);
	const float &GetMoveSpeed() const;
	void SetSprintSpeed(float arg0);
	const float &GetSprintSpeed() const;
	void SetDefaultTurnSpeed(float arg0);
	const float &GetDefaultTurnSpeed() const;
	void SetAttackTurnSpeed(float arg0);
	const float &GetAttackTurnSpeed() const;
	void SetRollSpeed(float arg0);
	const float &GetRollSpeed() const;
	void SetAttackSignalPackageId(uint64_t arg0);
	const uint64_t &GetAttackSignalPackageId() const;
	void SetDefaultCameraOffset(Vec3 arg0);
	Vec3 const &GetDefaultCameraOffset() const;
	void SetDefaultCameraZeroGOffset(Vec3 arg0);
	Vec3 const &GetDefaultCameraZeroGOffset() const;
	void SetAttackCameraOffset(Vec3 arg0);
	Vec3 const &GetAttackCameraOffset() const;
	void SetAttackCameraZeroGOffset(Vec3 arg0);
	Vec3 const &GetAttackCameraZeroGOffset() const;
	void SetSafeCameraOffset(Vec3 arg0);
	Vec3 const &GetSafeCameraOffset() const;
	void SetMaxTargetAngle(float arg0);
	const float &GetMaxTargetAngle() const;
	void SetMaxTargetDistance(float arg0);
	const float &GetMaxTargetDistance() const;
	std::vector<unsigned __int64> &GetValidTargetMetaTags();
	std::vector<unsigned __int64> const &GetValidTargetMetaTags() const;
	std::vector<string> &GetValidTargetClasses();
	std::vector<string> const &GetValidTargetClasses() const;
	std::vector<IEntityClass const *> const &GetValidLoadedTargetClasses() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x132A770);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x132AC20);
	static inline auto FInitializeValidTargetClasses = PreyFunction<void(ArkPsiMimicScienceOperatorProperties *const _this)>(0x132B210);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiPowerMimicUniqueProperties : public ArkReflectedObject // Id=80194A0 Size=872
{
public:
	class ArkAutoFallbackRangeProperty : public ArkProperty // Id=80194A1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkAutoFallbackRangeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkAutoFallbackRangeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkAutoFallbackRangeProperty s_ArkAutoFallbackRangeProperty;
	float m_AutoFallbackRange;
	
	class ArkForceMorphOutDelaySecProperty : public ArkProperty // Id=80194A2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkForceMorphOutDelaySecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkForceMorphOutDelaySecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkForceMorphOutDelaySecProperty s_ArkForceMorphOutDelaySecProperty;
	float m_ForceMorphOutDelaySec;
	
	class ArkGameNoiseDelaySecProperty : public ArkProperty // Id=80194A3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkGameNoiseDelaySecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkGameNoiseDelaySecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkGameNoiseDelaySecProperty s_ArkGameNoiseDelaySecProperty;
	float m_GameNoiseDelaySec;
	
	class ArkClipOpacityProperty : public ArkProperty // Id=80194A4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkClipOpacityProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkClipOpacityProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkClipOpacityProperty s_ArkClipOpacityProperty;
	float m_ClipOpacity;
	
	class ArkRigidPropertiesProperty : public ArkProperty // Id=80194A5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkRigidPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkRigidPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkRigidPropertiesProperty s_ArkRigidPropertiesProperty;
	ArkPsiMimicRigidProperties m_RigidProperties;
	
	class ArkTurretPropertiesProperty : public ArkProperty // Id=80194A6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkTurretPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkTurretPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D50D0);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkTurretPropertiesProperty s_ArkTurretPropertiesProperty;
	ArkPsiMimicTurretProperties m_TurretProperties;
	
	class ArkOperatorPropertiesProperty : public ArkProperty // Id=80194A7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkOperatorPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1327FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkOperatorPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328020);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkOperatorPropertiesProperty s_ArkOperatorPropertiesProperty;
	ArkPsiMimicOperatorProperties m_OperatorProperties;
	
	class ArkMilitaryOperatorPropertiesProperty : public ArkProperty // Id=80194A8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkMilitaryOperatorPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkMilitaryOperatorPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328200);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkMilitaryOperatorPropertiesProperty s_ArkMilitaryOperatorPropertiesProperty;
	ArkPsiMimicMilitaryOperatorProperties m_MilitaryOperatorProperties;
	
	class ArkEngineeringOperatorPropertiesProperty : public ArkProperty // Id=80194A9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkEngineeringOperatorPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328210);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkEngineeringOperatorPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328260);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkEngineeringOperatorPropertiesProperty s_ArkEngineeringOperatorPropertiesProperty;
	ArkPsiMimicEngineeringOperatorProperties m_EngineeringOperatorProperties;
	
	class ArkScienceOperatorPropertiesProperty : public ArkProperty // Id=80194AA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkScienceOperatorPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328270);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkScienceOperatorPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13282D0);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkScienceOperatorPropertiesProperty s_ArkScienceOperatorPropertiesProperty;
	ArkPsiMimicScienceOperatorProperties m_ScienceOperatorProperties;
	
	class ArkEffectsPropertiesProperty : public ArkProperty // Id=80194AB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkEffectsPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13282E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkEffectsPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328320);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkEffectsPropertiesProperty s_ArkEffectsPropertiesProperty;
	ArkPsiPowerMimicEffectsProperties m_EffectsProperties;
	
	class ArkPlayerSignalModifiersProperty : public ArkProperty // Id=80194AC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328330);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328360);
		static inline auto FIsArray = PreyFunction<bool(ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty const *const _this, ArkReflectedObject *_pObject)>(0x1328390);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty s_ArkPlayerSignalModifiersProperty;
	std::vector<unsigned __int64> m_PlayerSignalModifiers;
	
	class ArkObjectSignalModifiersProperty : public ArkProperty // Id=80194AD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13283A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13283D0);
		static inline auto FIsArray = PreyFunction<bool(ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty const *const _this, ArkReflectedObject *_pObject)>(0x1328400);
	};

	static ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty s_ArkObjectSignalModifiersProperty;
	std::vector<unsigned __int64> m_ObjectSignalModifiers;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetAutoFallbackRange(float arg0);
	const float &GetAutoFallbackRange() const;
	void SetForceMorphOutDelaySec(float arg0);
	const float &GetForceMorphOutDelaySec() const;
	void SetGameNoiseDelaySec(float arg0);
	const float &GetGameNoiseDelaySec() const;
	void SetClipOpacity(float arg0);
	const float &GetClipOpacity() const;
	void SetRigidProperties(ArkPsiMimicRigidProperties arg0);
	ArkPsiMimicRigidProperties const &GetRigidProperties() const;
	void SetTurretProperties(ArkPsiMimicTurretProperties arg0);
	ArkPsiMimicTurretProperties const &GetTurretProperties() const;
	void SetOperatorProperties(ArkPsiMimicOperatorProperties arg0);
	ArkPsiMimicOperatorProperties const &GetOperatorProperties() const;
	void SetMilitaryOperatorProperties(ArkPsiMimicMilitaryOperatorProperties arg0);
	ArkPsiMimicMilitaryOperatorProperties const &GetMilitaryOperatorProperties() const;
	void SetEngineeringOperatorProperties(ArkPsiMimicEngineeringOperatorProperties arg0);
	ArkPsiMimicEngineeringOperatorProperties const &GetEngineeringOperatorProperties() const;
	void SetScienceOperatorProperties(ArkPsiMimicScienceOperatorProperties arg0);
	ArkPsiMimicScienceOperatorProperties const &GetScienceOperatorProperties() const;
	void SetEffectsProperties(ArkPsiPowerMimicEffectsProperties arg0);
	ArkPsiPowerMimicEffectsProperties const &GetEffectsProperties() const;
	std::vector<unsigned __int64> &GetPlayerSignalModifiers();
	std::vector<unsigned __int64> const &GetPlayerSignalModifiers() const;
	std::vector<unsigned __int64> &GetObjectSignalModifiers();
	std::vector<unsigned __int64> const &GetObjectSignalModifiers() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x132A890);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x132AEA0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiPowerMimicLevelProperties : public ArkReflectedObject // Id=80194B5 Size=104
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=80194B6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicLevelProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicLevelProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerMimicLevelProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=80194B7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicLevelProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicLevelProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerMimicLevelProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=80194B8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicLevelProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicLevelProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerMimicLevelProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkPsiCostPerSecProperty : public ArkProperty // Id=80194B9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicLevelProperties::ArkPsiCostPerSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicLevelProperties::ArkPsiCostPerSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkPsiPowerMimicLevelProperties::ArkPsiCostPerSecProperty s_ArkPsiCostPerSecProperty;
	float m_PsiCostPerSec;
	
	class ArkTargetingPropertiesProperty : public ArkProperty // Id=80194BA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicLevelProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13285D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicLevelProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerMimicLevelProperties::ArkTargetingPropertiesProperty s_ArkTargetingPropertiesProperty;
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDisplayName(string arg0);
	string const &GetDisplayName() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetCooldownDurationSec(float arg0);
	const float &GetCooldownDurationSec() const;
	void SetPsiCostPerSec(float arg0);
	const float &GetPsiCostPerSec() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties arg0);
	ArkPsiPowerTargetingComponentProperties const &GetTargetingProperties() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x132A820);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x132AE00);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class MimicPowerProperties : public ArkReflectedLibrary // Id=80194BB Size=1112
{
public:
	using LevelProperties = ArkPsiPowerMimicLevelProperties;
	using UniqueProperties = ArkPsiPowerMimicUniqueProperties;
	
	class ArkCommonProperty : public ArkProperty // Id=80194BC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(MimicPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(MimicPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static MimicPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=80194BD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(MimicPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13286C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(MimicPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static MimicPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	ArkPsiPowerMimicUniqueProperties m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=80194BE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(MimicPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328910);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(MimicPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13289F0);
		static inline auto FIsArray = PreyFunction<bool(MimicPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(MimicPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1328A40);
	};

	static MimicPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerMimicLevelProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(ArkPsiPowerMimicUniqueProperties arg0);
	ArkPsiPowerMimicUniqueProperties const &GetUnique() const;
	std::vector<ArkPsiPowerMimicLevelProperties> &GetLevels();
	std::vector<ArkPsiPowerMimicLevelProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x132A8D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x132AF40);
	static inline auto FInit = PreyFunction<bool(MimicPowerProperties *const _this)>(0x132B030);
};

