// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>

class ArkClass;
class IArkValueBase;
struct IEntityClass;

// ArkPsiMimicEngineeringOperatorProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicEngineeringOperatorProperties : public ArkReflectedObject
{ // Size=176 (0xB0)
public:
	// ArkPsiMimicEngineeringOperatorProperties::ArkMoveSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMoveSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMoveSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkMoveSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkMoveSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiMimicEngineeringOperatorProperties::ArkSprintSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkSprintSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSprintSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkSprintSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkSprintSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	// ArkPsiMimicEngineeringOperatorProperties::ArkDefaultTurnSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDefaultTurnSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultTurnSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkDefaultTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkDefaultTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiMimicEngineeringOperatorProperties::ArkAttackTurnSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackTurnSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackTurnSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkAttackTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkAttackTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkPsiMimicEngineeringOperatorProperties::ArkRollSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkRollSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRollSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkRollSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkRollSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiMimicEngineeringOperatorProperties::ArkAttackSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkAttackSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkAttackSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDefaultCameraOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultCameraOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328420);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	// ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraZeroGOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDefaultCameraZeroGOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultCameraZeroGOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328450);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328680);
	};

	// ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackCameraOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackCameraOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328690);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
	};

	// ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraZeroGOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackCameraZeroGOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackCameraZeroGOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13288E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328490);
	};

	// ArkPsiMimicEngineeringOperatorProperties::ArkSafeCameraOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkSafeCameraOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSafeCameraOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkSafeCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13284A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkSafeCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBDE0);
	};

	// ArkPsiMimicEngineeringOperatorProperties::ArkSwitchCameraInputLegendItemProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkSwitchCameraInputLegendItemProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSwitchCameraInputLegendItemProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicEngineeringOperatorProperties::ArkSwitchCameraInputLegendItemProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13284D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicEngineeringOperatorProperties::ArkSwitchCameraInputLegendItemProperty* const _this, ArkReflectedObject* const _pObject)>(0x1086170);
	};

	static inline auto s_ArkMoveSpeedProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkMoveSpeedProperty>(0x2BDAF88);
	float m_MoveSpeed;
	static inline auto s_ArkSprintSpeedProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkSprintSpeedProperty>(0x2BDAFA8);
	float m_SprintSpeed;
	static inline auto s_ArkDefaultTurnSpeedProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkDefaultTurnSpeedProperty>(0x2BDAFC8);
	float m_DefaultTurnSpeed;
	static inline auto s_ArkAttackTurnSpeedProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkAttackTurnSpeedProperty>(0x2BDAFE8);
	float m_AttackTurnSpeed;
	static inline auto s_ArkRollSpeedProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkRollSpeedProperty>(0x2BDB008);
	float m_RollSpeed;
	static inline auto s_ArkAttackSignalPackageIdProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkAttackSignalPackageIdProperty>(0x2BDB028);
	uint64_t m_AttackSignalPackageId;
	static inline auto s_ArkDefaultCameraOffsetProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraOffsetProperty>(0x2BDB048);
	Vec3 m_DefaultCameraOffset;
	static inline auto s_ArkDefaultCameraZeroGOffsetProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkDefaultCameraZeroGOffsetProperty>(0x2BDB068);
	Vec3 m_DefaultCameraZeroGOffset;
	static inline auto s_ArkAttackCameraOffsetProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraOffsetProperty>(0x2BDB088);
	Vec3 m_AttackCameraOffset;
	static inline auto s_ArkAttackCameraZeroGOffsetProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkAttackCameraZeroGOffsetProperty>(0x2BDB0A8);
	Vec3 m_AttackCameraZeroGOffset;
	static inline auto s_ArkSafeCameraOffsetProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkSafeCameraOffsetProperty>(0x2BDB0C8);
	Vec3 m_SafeCameraOffset;
	static inline auto s_ArkSwitchCameraInputLegendItemProperty = PreyGlobal<ArkPsiMimicEngineeringOperatorProperties::ArkSwitchCameraInputLegendItemProperty>(0x2BDB0E8);
	ArkInputLegendItem m_SwitchCameraInputLegendItem;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetMoveSpeed(float _arg0_);
	const float& GetMoveSpeed() const;
	void SetSprintSpeed(float _arg0_);
	const float& GetSprintSpeed() const;
	void SetDefaultTurnSpeed(float _arg0_);
	const float& GetDefaultTurnSpeed() const;
	void SetAttackTurnSpeed(float _arg0_);
	const float& GetAttackTurnSpeed() const;
	void SetRollSpeed(float _arg0_);
	const float& GetRollSpeed() const;
	void SetAttackSignalPackageId(uint64_t _arg0_);
	const uint64_t& GetAttackSignalPackageId() const;
	void SetDefaultCameraOffset(Vec3 _arg0_);
	const Vec3& GetDefaultCameraOffset() const;
	void SetDefaultCameraZeroGOffset(Vec3 _arg0_);
	const Vec3& GetDefaultCameraZeroGOffset() const;
	void SetAttackCameraOffset(Vec3 _arg0_);
	const Vec3& GetAttackCameraOffset() const;
	void SetAttackCameraZeroGOffset(Vec3 _arg0_);
	const Vec3& GetAttackCameraZeroGOffset() const;
	void SetSafeCameraOffset(Vec3 _arg0_);
	const Vec3& GetSafeCameraOffset() const;
	void SetSwitchCameraInputLegendItem(ArkInputLegendItem _arg0_);
	const ArkInputLegendItem& GetSwitchCameraInputLegendItem() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x132A5F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x132A9A0);
};

// ArkPsiMimicMilitaryOperatorProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicMilitaryOperatorProperties : public ArkReflectedObject
{ // Size=84 (0x54)
public:
	// ArkPsiMimicMilitaryOperatorProperties::ArkLaserDamageProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkLaserDamageProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLaserDamageProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicMilitaryOperatorProperties::ArkLaserDamageProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicMilitaryOperatorProperties::ArkLaserDamageProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiMimicMilitaryOperatorProperties::ArkMoveSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMoveSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMoveSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicMilitaryOperatorProperties::ArkMoveSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicMilitaryOperatorProperties::ArkMoveSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	// ArkPsiMimicMilitaryOperatorProperties::ArkSprintSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkSprintSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSprintSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicMilitaryOperatorProperties::ArkSprintSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicMilitaryOperatorProperties::ArkSprintSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiMimicMilitaryOperatorProperties::ArkDefaultTurnSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDefaultTurnSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultTurnSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicMilitaryOperatorProperties::ArkDefaultTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicMilitaryOperatorProperties::ArkDefaultTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkPsiMimicMilitaryOperatorProperties::ArkAttackTurnSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackTurnSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackTurnSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicMilitaryOperatorProperties::ArkAttackTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicMilitaryOperatorProperties::ArkAttackTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiMimicMilitaryOperatorProperties::ArkRollSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkRollSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRollSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicMilitaryOperatorProperties::ArkRollSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicMilitaryOperatorProperties::ArkRollSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
	};

	// ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDefaultCameraOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultCameraOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328BA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraZeroGOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDefaultCameraZeroGOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultCameraZeroGOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328510);
	};

	// ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackCameraOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackCameraOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
	};

	// ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraZeroGOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackCameraZeroGOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackCameraZeroGOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1066410);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328E30);
	};

	// ArkPsiMimicMilitaryOperatorProperties::ArkSafeCameraOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkSafeCameraOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSafeCameraOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicMilitaryOperatorProperties::ArkSafeCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328ED0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicMilitaryOperatorProperties::ArkSafeCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBD70);
	};

	static inline auto s_ArkLaserDamageProperty = PreyGlobal<ArkPsiMimicMilitaryOperatorProperties::ArkLaserDamageProperty>(0x2BDAE28);
	float m_LaserDamage;
	static inline auto s_ArkMoveSpeedProperty = PreyGlobal<ArkPsiMimicMilitaryOperatorProperties::ArkMoveSpeedProperty>(0x2BDAE48);
	float m_MoveSpeed;
	static inline auto s_ArkSprintSpeedProperty = PreyGlobal<ArkPsiMimicMilitaryOperatorProperties::ArkSprintSpeedProperty>(0x2BDAE68);
	float m_SprintSpeed;
	static inline auto s_ArkDefaultTurnSpeedProperty = PreyGlobal<ArkPsiMimicMilitaryOperatorProperties::ArkDefaultTurnSpeedProperty>(0x2BDAE88);
	float m_DefaultTurnSpeed;
	static inline auto s_ArkAttackTurnSpeedProperty = PreyGlobal<ArkPsiMimicMilitaryOperatorProperties::ArkAttackTurnSpeedProperty>(0x2BDAEA8);
	float m_AttackTurnSpeed;
	static inline auto s_ArkRollSpeedProperty = PreyGlobal<ArkPsiMimicMilitaryOperatorProperties::ArkRollSpeedProperty>(0x2BDAEC8);
	float m_RollSpeed;
	static inline auto s_ArkDefaultCameraOffsetProperty = PreyGlobal<ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraOffsetProperty>(0x2BDAEE8);
	Vec3 m_DefaultCameraOffset;
	static inline auto s_ArkDefaultCameraZeroGOffsetProperty = PreyGlobal<ArkPsiMimicMilitaryOperatorProperties::ArkDefaultCameraZeroGOffsetProperty>(0x2BDAF08);
	Vec3 m_DefaultCameraZeroGOffset;
	static inline auto s_ArkAttackCameraOffsetProperty = PreyGlobal<ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraOffsetProperty>(0x2BDAF28);
	Vec3 m_AttackCameraOffset;
	static inline auto s_ArkAttackCameraZeroGOffsetProperty = PreyGlobal<ArkPsiMimicMilitaryOperatorProperties::ArkAttackCameraZeroGOffsetProperty>(0x2BDAF48);
	Vec3 m_AttackCameraZeroGOffset;
	static inline auto s_ArkSafeCameraOffsetProperty = PreyGlobal<ArkPsiMimicMilitaryOperatorProperties::ArkSafeCameraOffsetProperty>(0x2BDAF68);
	Vec3 m_SafeCameraOffset;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetLaserDamage(float _arg0_);
	const float& GetLaserDamage() const;
	void SetMoveSpeed(float _arg0_);
	const float& GetMoveSpeed() const;
	void SetSprintSpeed(float _arg0_);
	const float& GetSprintSpeed() const;
	void SetDefaultTurnSpeed(float _arg0_);
	const float& GetDefaultTurnSpeed() const;
	void SetAttackTurnSpeed(float _arg0_);
	const float& GetAttackTurnSpeed() const;
	void SetRollSpeed(float _arg0_);
	const float& GetRollSpeed() const;
	void SetDefaultCameraOffset(Vec3 _arg0_);
	const Vec3& GetDefaultCameraOffset() const;
	void SetDefaultCameraZeroGOffset(Vec3 _arg0_);
	const Vec3& GetDefaultCameraZeroGOffset() const;
	void SetAttackCameraOffset(Vec3 _arg0_);
	const Vec3& GetAttackCameraOffset() const;
	void SetAttackCameraZeroGOffset(Vec3 _arg0_);
	const Vec3& GetAttackCameraZeroGOffset() const;
	void SetSafeCameraOffset(Vec3 _arg0_);
	const Vec3& GetSafeCameraOffset() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x132A680);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x132AA40);
};

// ArkPsiMimicOperatorProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicOperatorProperties : public ArkReflectedObject
{ // Size=64 (0x40)
public:
	// ArkPsiMimicOperatorProperties::ArkModalLegendProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkModalLegendProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkModalLegendProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicOperatorProperties::ArkModalLegendProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicOperatorProperties::ArkModalLegendProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiMimicOperatorProperties::ArkModalLegendZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkModalLegendZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkModalLegendZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicOperatorProperties::ArkModalLegendZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328D70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicOperatorProperties::ArkModalLegendZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	static inline auto s_ArkModalLegendProperty = PreyGlobal<ArkPsiMimicOperatorProperties::ArkModalLegendProperty>(0x2BDADE8);
	ArkInputLegend m_ModalLegend;
	static inline auto s_ArkModalLegendZeroGProperty = PreyGlobal<ArkPsiMimicOperatorProperties::ArkModalLegendZeroGProperty>(0x2BDAE08);
	ArkInputLegend m_ModalLegendZeroG;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetModalLegend(ArkInputLegend _arg0_);
	const ArkInputLegend& GetModalLegend() const;
	void SetModalLegendZeroG(ArkInputLegend _arg0_);
	const ArkInputLegend& GetModalLegendZeroG() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x132A6C0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x132AAE0);
};

// ArkPsiMimicRigidProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicRigidProperties : public ArkReflectedObject
{ // Size=144 (0x90)
public:
	// ArkPsiMimicRigidProperties::ArkDamageSignalGroupIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDamageSignalGroupIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDamageSignalGroupIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkDamageSignalGroupIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkDamageSignalGroupIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiMimicRigidProperties::ArkJumpHeightProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkJumpHeightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkJumpHeightProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkJumpHeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkJumpHeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiMimicRigidProperties::ArkPenetratingJumpHeightProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkPenetratingJumpHeightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPenetratingJumpHeightProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkPenetratingJumpHeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkPenetratingJumpHeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkPsiMimicRigidProperties::ArkMoveSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMoveSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMoveSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkMoveSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkMoveSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiMimicRigidProperties::ArkSprintSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkSprintSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSprintSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkSprintSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkSprintSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
	};

	// ArkPsiMimicRigidProperties::ArkTumbleSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkTumbleSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTumbleSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkTumbleSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkTumbleSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiMimicRigidProperties::ArkLiftMaxAngularSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkLiftMaxAngularSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLiftMaxAngularSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkLiftMaxAngularSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkLiftMaxAngularSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D570);
	};

	// ArkPsiMimicRigidProperties::ArkTumbleSpeedLinearThresholdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkTumbleSpeedLinearThresholdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTumbleSpeedLinearThresholdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkTumbleSpeedLinearThresholdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkTumbleSpeedLinearThresholdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	// ArkPsiMimicRigidProperties::ArkMoveSpeedZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMoveSpeedZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMoveSpeedZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkMoveSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkMoveSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328510);
	};

	// ArkPsiMimicRigidProperties::ArkSprintSpeedZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkSprintSpeedZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSprintSpeedZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkSprintSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkSprintSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
	};

	// ArkPsiMimicRigidProperties::ArkRollSpeedZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkRollSpeedZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRollSpeedZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkRollSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10821B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkRollSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328680);
	};

	// ArkPsiMimicRigidProperties::ArkAirControlScaleProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAirControlScaleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAirControlScaleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkAirControlScaleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBD60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkAirControlScaleProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
	};

	// ArkPsiMimicRigidProperties::ArkNoiseIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkNoiseIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNoiseIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328520);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
	};

	// ArkPsiMimicRigidProperties::ArkLoudnessIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkLoudnessIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLoudnessIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x105B9E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1591850);
	};

	// ArkPsiMimicRigidProperties::ArkNoiseIntervalProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkNoiseIntervalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNoiseIntervalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkNoiseIntervalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkNoiseIntervalProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBD70);
	};

	// ArkPsiMimicRigidProperties::ArkModalLegendProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkModalLegendProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkModalLegendProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkModalLegendProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328530);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkModalLegendProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBDE0);
	};

	// ArkPsiMimicRigidProperties::ArkModalLegendZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkModalLegendZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkModalLegendZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicRigidProperties::ArkModalLegendZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicRigidProperties::ArkModalLegendZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082260);
	};

	static inline auto s_ArkDamageSignalGroupIdProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkDamageSignalGroupIdProperty>(0x2BDAA88);
	uint64_t m_DamageSignalGroupId;
	static inline auto s_ArkJumpHeightProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkJumpHeightProperty>(0x2BDAAA8);
	float m_JumpHeight;
	static inline auto s_ArkPenetratingJumpHeightProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkPenetratingJumpHeightProperty>(0x2BDAAC8);
	float m_PenetratingJumpHeight;
	static inline auto s_ArkMoveSpeedProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkMoveSpeedProperty>(0x2BDAAE8);
	float m_MoveSpeed;
	static inline auto s_ArkSprintSpeedProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkSprintSpeedProperty>(0x2BDAB08);
	float m_SprintSpeed;
	static inline auto s_ArkTumbleSpeedProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkTumbleSpeedProperty>(0x2BDAB28);
	float m_TumbleSpeed;
	static inline auto s_ArkLiftMaxAngularSpeedProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkLiftMaxAngularSpeedProperty>(0x2BDAB48);
	float m_LiftMaxAngularSpeed;
	static inline auto s_ArkTumbleSpeedLinearThresholdProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkTumbleSpeedLinearThresholdProperty>(0x2BDAB68);
	float m_TumbleSpeedLinearThreshold;
	static inline auto s_ArkMoveSpeedZeroGProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkMoveSpeedZeroGProperty>(0x2BDAB88);
	float m_MoveSpeedZeroG;
	static inline auto s_ArkSprintSpeedZeroGProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkSprintSpeedZeroGProperty>(0x2BDABA8);
	float m_SprintSpeedZeroG;
	static inline auto s_ArkRollSpeedZeroGProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkRollSpeedZeroGProperty>(0x2BDABC8);
	float m_RollSpeedZeroG;
	static inline auto s_ArkAirControlScaleProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkAirControlScaleProperty>(0x2BDABE8);
	float m_AirControlScale;
	static inline auto s_ArkNoiseIdProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkNoiseIdProperty>(0x2BDAC08);
	uint64_t m_NoiseId;
	static inline auto s_ArkLoudnessIdProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkLoudnessIdProperty>(0x2BDAC28);
	uint64_t m_LoudnessId;
	static inline auto s_ArkNoiseIntervalProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkNoiseIntervalProperty>(0x2BDAC48);
	float m_NoiseInterval;
	static inline auto s_ArkModalLegendProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkModalLegendProperty>(0x2BDAC68);
	ArkInputLegend m_ModalLegend;
	static inline auto s_ArkModalLegendZeroGProperty = PreyGlobal<ArkPsiMimicRigidProperties::ArkModalLegendZeroGProperty>(0x2BDAC88);
	ArkInputLegend m_ModalLegendZeroG;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDamageSignalGroupId(uint64_t _arg0_);
	const uint64_t& GetDamageSignalGroupId() const;
	void SetJumpHeight(float _arg0_);
	const float& GetJumpHeight() const;
	void SetPenetratingJumpHeight(float _arg0_);
	const float& GetPenetratingJumpHeight() const;
	void SetMoveSpeed(float _arg0_);
	const float& GetMoveSpeed() const;
	void SetSprintSpeed(float _arg0_);
	const float& GetSprintSpeed() const;
	void SetTumbleSpeed(float _arg0_);
	const float& GetTumbleSpeed() const;
	void SetLiftMaxAngularSpeed(float _arg0_);
	const float& GetLiftMaxAngularSpeed() const;
	void SetTumbleSpeedLinearThreshold(float _arg0_);
	const float& GetTumbleSpeedLinearThreshold() const;
	void SetMoveSpeedZeroG(float _arg0_);
	const float& GetMoveSpeedZeroG() const;
	void SetSprintSpeedZeroG(float _arg0_);
	const float& GetSprintSpeedZeroG() const;
	void SetRollSpeedZeroG(float _arg0_);
	const float& GetRollSpeedZeroG() const;
	void SetAirControlScale(float _arg0_);
	const float& GetAirControlScale() const;
	void SetNoiseId(uint64_t _arg0_);
	const uint64_t& GetNoiseId() const;
	void SetLoudnessId(uint64_t _arg0_);
	const uint64_t& GetLoudnessId() const;
	void SetNoiseInterval(float _arg0_);
	const float& GetNoiseInterval() const;
	void SetModalLegend(ArkInputLegend _arg0_);
	const ArkInputLegend& GetModalLegend() const;
	void SetModalLegendZeroG(ArkInputLegend _arg0_);
	const ArkInputLegend& GetModalLegendZeroG() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x132A720);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x132AB80);
};

// ArkPsiMimicScienceOperatorProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicScienceOperatorProperties : public ArkReflectedObject
{ // Size=176 (0xB0)
public:
	// ArkPsiMimicScienceOperatorProperties::ArkMoveSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMoveSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMoveSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkMoveSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkMoveSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkSprintSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkSprintSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSprintSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkSprintSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkSprintSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkDefaultTurnSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDefaultTurnSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultTurnSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkDefaultTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkDefaultTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkAttackTurnSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackTurnSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackTurnSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkAttackTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkAttackTurnSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkRollSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkRollSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRollSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkRollSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkRollSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkAttackSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkAttackSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkAttackSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDefaultCameraOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultCameraOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328420);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraZeroGOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDefaultCameraZeroGOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultCameraZeroGOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328450);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328680);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkAttackCameraOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackCameraOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackCameraOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkAttackCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328690);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkAttackCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkAttackCameraZeroGOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackCameraZeroGOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackCameraZeroGOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkAttackCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13288E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkAttackCameraZeroGOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328490);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkSafeCameraOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkSafeCameraOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSafeCameraOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkSafeCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13284A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkSafeCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBDE0);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkMaxTargetAngleProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMaxTargetAngleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxTargetAngleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkMaxTargetAngleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328A80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkMaxTargetAngleProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328A90);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkMaxTargetDistanceProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMaxTargetDistanceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxTargetDistanceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkMaxTargetDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328AA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkMaxTargetDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1086170);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkValidTargetMetaTagsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkValidTargetMetaTagsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328AB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328AD0);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* _pObject)>(0x1328AF0);
	};

	// ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkValidTargetClassesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkValidTargetClassesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328B00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328B60);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* _pObject)>(0x1328B90);
	};

	static inline auto s_ArkMoveSpeedProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkMoveSpeedProperty>(0x2BDB108);
	float m_MoveSpeed;
	static inline auto s_ArkSprintSpeedProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkSprintSpeedProperty>(0x2BDB128);
	float m_SprintSpeed;
	static inline auto s_ArkDefaultTurnSpeedProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkDefaultTurnSpeedProperty>(0x2BDB148);
	float m_DefaultTurnSpeed;
	static inline auto s_ArkAttackTurnSpeedProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkAttackTurnSpeedProperty>(0x2BDB168);
	float m_AttackTurnSpeed;
	static inline auto s_ArkRollSpeedProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkRollSpeedProperty>(0x2BDB188);
	float m_RollSpeed;
	static inline auto s_ArkAttackSignalPackageIdProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkAttackSignalPackageIdProperty>(0x2BDB1A8);
	uint64_t m_AttackSignalPackageId;
	static inline auto s_ArkDefaultCameraOffsetProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraOffsetProperty>(0x2BDB1C8);
	Vec3 m_DefaultCameraOffset;
	static inline auto s_ArkDefaultCameraZeroGOffsetProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkDefaultCameraZeroGOffsetProperty>(0x2BDB1E8);
	Vec3 m_DefaultCameraZeroGOffset;
	static inline auto s_ArkAttackCameraOffsetProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkAttackCameraOffsetProperty>(0x2BDB208);
	Vec3 m_AttackCameraOffset;
	static inline auto s_ArkAttackCameraZeroGOffsetProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkAttackCameraZeroGOffsetProperty>(0x2BDB228);
	Vec3 m_AttackCameraZeroGOffset;
	static inline auto s_ArkSafeCameraOffsetProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkSafeCameraOffsetProperty>(0x2BDB248);
	Vec3 m_SafeCameraOffset;
	static inline auto s_ArkMaxTargetAngleProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkMaxTargetAngleProperty>(0x2BDB268);
	float m_MaxTargetAngle;
	static inline auto s_ArkMaxTargetDistanceProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkMaxTargetDistanceProperty>(0x2BDB288);
	float m_MaxTargetDistance;
	static inline auto s_ArkValidTargetMetaTagsProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkValidTargetMetaTagsProperty>(0x2BDB2A8);
	std::vector<uint64_t> m_ValidTargetMetaTags;
	static inline auto s_ArkValidTargetClassesProperty = PreyGlobal<ArkPsiMimicScienceOperatorProperties::ArkValidTargetClassesProperty>(0x2BDB2C8);
	std::vector<string> m_ValidTargetClasses;
	std::vector<const IEntityClass*> m_loadedClasses;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	void InitializeValidTargetClasses() { FInitializeValidTargetClasses(this); }

#if 0
	void SetMoveSpeed(float _arg0_);
	const float& GetMoveSpeed() const;
	void SetSprintSpeed(float _arg0_);
	const float& GetSprintSpeed() const;
	void SetDefaultTurnSpeed(float _arg0_);
	const float& GetDefaultTurnSpeed() const;
	void SetAttackTurnSpeed(float _arg0_);
	const float& GetAttackTurnSpeed() const;
	void SetRollSpeed(float _arg0_);
	const float& GetRollSpeed() const;
	void SetAttackSignalPackageId(uint64_t _arg0_);
	const uint64_t& GetAttackSignalPackageId() const;
	void SetDefaultCameraOffset(Vec3 _arg0_);
	const Vec3& GetDefaultCameraOffset() const;
	void SetDefaultCameraZeroGOffset(Vec3 _arg0_);
	const Vec3& GetDefaultCameraZeroGOffset() const;
	void SetAttackCameraOffset(Vec3 _arg0_);
	const Vec3& GetAttackCameraOffset() const;
	void SetAttackCameraZeroGOffset(Vec3 _arg0_);
	const Vec3& GetAttackCameraZeroGOffset() const;
	void SetSafeCameraOffset(Vec3 _arg0_);
	const Vec3& GetSafeCameraOffset() const;
	void SetMaxTargetAngle(float _arg0_);
	const float& GetMaxTargetAngle() const;
	void SetMaxTargetDistance(float _arg0_);
	const float& GetMaxTargetDistance() const;
	std::vector<uint64_t>& GetValidTargetMetaTags();
	const std::vector<uint64_t>& GetValidTargetMetaTags() const;
	std::vector<string>& GetValidTargetClasses();
	const std::vector<string>& GetValidTargetClasses() const;
	const std::vector<const IEntityClass*>& GetValidLoadedTargetClasses() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x132A770);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x132AC20);
	static inline auto FInitializeValidTargetClasses = PreyFunction<void(ArkPsiMimicScienceOperatorProperties* const _this)>(0x132B210);
};

// ArkPsiMimicTurretProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiMimicTurretProperties : public ArkReflectedObject
{ // Size=96 (0x60)
public:
	// ArkPsiMimicTurretProperties::ArkAimSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAimSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAimSpeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicTurretProperties::ArkAimSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicTurretProperties::ArkAimSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiMimicTurretProperties::ArkAimSpeedZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAimSpeedZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAimSpeedZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicTurretProperties::ArkAimSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicTurretProperties::ArkAimSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	// ArkPsiMimicTurretProperties::ArkMoveSpeedZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMoveSpeedZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMoveSpeedZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicTurretProperties::ArkMoveSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicTurretProperties::ArkMoveSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiMimicTurretProperties::ArkSprintSpeedZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkSprintSpeedZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSprintSpeedZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicTurretProperties::ArkSprintSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicTurretProperties::ArkSprintSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkPsiMimicTurretProperties::ArkRollSpeedZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkRollSpeedZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRollSpeedZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicTurretProperties::ArkRollSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicTurretProperties::ArkRollSpeedZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiMimicTurretProperties::ArkRecoilForceZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkRecoilForceZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRecoilForceZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicTurretProperties::ArkRecoilForceZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicTurretProperties::ArkRecoilForceZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
	};

	// ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDefaultCameraOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultCameraOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328BA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDefaultCameraOffsetZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultCameraOffsetZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328510);
	};

	// ArkPsiMimicTurretProperties::ArkAttackCameraOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAttackCameraOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttackCameraOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicTurretProperties::ArkAttackCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicTurretProperties::ArkAttackCameraOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
	};

	// ArkPsiMimicTurretProperties::ArkModalLegendProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkModalLegendProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkModalLegendProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiMimicTurretProperties::ArkModalLegendProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328C30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiMimicTurretProperties::ArkModalLegendProperty* const _this, ArkReflectedObject* const _pObject)>(0x1591850);
	};

	static inline auto s_ArkAimSpeedProperty = PreyGlobal<ArkPsiMimicTurretProperties::ArkAimSpeedProperty>(0x2BDACA8);
	float m_AimSpeed;
	static inline auto s_ArkAimSpeedZeroGProperty = PreyGlobal<ArkPsiMimicTurretProperties::ArkAimSpeedZeroGProperty>(0x2BDACC8);
	float m_AimSpeedZeroG;
	static inline auto s_ArkMoveSpeedZeroGProperty = PreyGlobal<ArkPsiMimicTurretProperties::ArkMoveSpeedZeroGProperty>(0x2BDACE8);
	float m_MoveSpeedZeroG;
	static inline auto s_ArkSprintSpeedZeroGProperty = PreyGlobal<ArkPsiMimicTurretProperties::ArkSprintSpeedZeroGProperty>(0x2BDAD08);
	float m_SprintSpeedZeroG;
	static inline auto s_ArkRollSpeedZeroGProperty = PreyGlobal<ArkPsiMimicTurretProperties::ArkRollSpeedZeroGProperty>(0x2BDAD28);
	float m_RollSpeedZeroG;
	static inline auto s_ArkRecoilForceZeroGProperty = PreyGlobal<ArkPsiMimicTurretProperties::ArkRecoilForceZeroGProperty>(0x2BDAD48);
	float m_RecoilForceZeroG;
	static inline auto s_ArkDefaultCameraOffsetProperty = PreyGlobal<ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetProperty>(0x2BDAD68);
	Vec3 m_DefaultCameraOffset;
	static inline auto s_ArkDefaultCameraOffsetZeroGProperty = PreyGlobal<ArkPsiMimicTurretProperties::ArkDefaultCameraOffsetZeroGProperty>(0x2BDAD88);
	Vec3 m_DefaultCameraOffsetZeroG;
	static inline auto s_ArkAttackCameraOffsetProperty = PreyGlobal<ArkPsiMimicTurretProperties::ArkAttackCameraOffsetProperty>(0x2BDADA8);
	Vec3 m_AttackCameraOffset;
	static inline auto s_ArkModalLegendProperty = PreyGlobal<ArkPsiMimicTurretProperties::ArkModalLegendProperty>(0x2BDADC8);
	ArkInputLegend m_ModalLegend;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetAimSpeed(float _arg0_);
	const float& GetAimSpeed() const;
	void SetAimSpeedZeroG(float _arg0_);
	const float& GetAimSpeedZeroG() const;
	void SetMoveSpeedZeroG(float _arg0_);
	const float& GetMoveSpeedZeroG() const;
	void SetSprintSpeedZeroG(float _arg0_);
	const float& GetSprintSpeedZeroG() const;
	void SetRollSpeedZeroG(float _arg0_);
	const float& GetRollSpeedZeroG() const;
	void SetRecoilForceZeroG(float _arg0_);
	const float& GetRecoilForceZeroG() const;
	void SetDefaultCameraOffset(Vec3 _arg0_);
	const Vec3& GetDefaultCameraOffset() const;
	void SetDefaultCameraOffsetZeroG(Vec3 _arg0_);
	const Vec3& GetDefaultCameraOffsetZeroG() const;
	void SetAttackCameraOffset(Vec3 _arg0_);
	const Vec3& GetAttackCameraOffset() const;
	void SetModalLegend(ArkInputLegend _arg0_);
	const ArkInputLegend& GetModalLegend() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x132A7E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x132ACC0);
};

// ArkPsiPowerMimicEffectsProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiPowerMimicEffectsProperties : public ArkReflectedObject
{ // Size=64 (0x40)
public:
	// ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMorphEffectDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMorphEffectDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkJumpAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkJumpAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMorphInAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMorphInAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMorphOutAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMorphOutAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMovementParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMovementParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	// ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkPersistentParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPersistentParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
	};

	// ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMorphOutParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMorphOutParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
	};

	// ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkObjectMorphInParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkObjectMorphInParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
	};

	static inline auto s_ArkMorphEffectDurationSecProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty>(0x2BDB2E8);
	float m_MorphEffectDurationSec;
	static inline auto s_ArkJumpAudioTriggerProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty>(0x2BDB308);
	string m_JumpAudioTrigger;
	static inline auto s_ArkMorphInAudioTriggerProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty>(0x2BDB328);
	string m_MorphInAudioTrigger;
	static inline auto s_ArkMorphOutAudioTriggerProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty>(0x2BDB348);
	string m_MorphOutAudioTrigger;
	static inline auto s_ArkMovementParticleEffectProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty>(0x2BDB368);
	string m_MovementParticleEffect;
	static inline auto s_ArkPersistentParticleEffectProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty>(0x2BDB388);
	string m_PersistentParticleEffect;
	static inline auto s_ArkMorphOutParticleEffectProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty>(0x2BDB3A8);
	string m_MorphOutParticleEffect;
	static inline auto s_ArkObjectMorphInParticleEffectProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty>(0x2BDB3C8);
	string m_ObjectMorphInParticleEffect;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetMorphEffectDurationSec(float _arg0_);
	const float& GetMorphEffectDurationSec() const;
	void SetJumpAudioTrigger(string _arg0_);
	const string& GetJumpAudioTrigger() const;
	void SetMorphInAudioTrigger(string _arg0_);
	const string& GetMorphInAudioTrigger() const;
	void SetMorphOutAudioTrigger(string _arg0_);
	const string& GetMorphOutAudioTrigger() const;
	void SetMovementParticleEffect(string _arg0_);
	const string& GetMovementParticleEffect() const;
	void SetPersistentParticleEffect(string _arg0_);
	const string& GetPersistentParticleEffect() const;
	void SetMorphOutParticleEffect(string _arg0_);
	const string& GetMorphOutParticleEffect() const;
	void SetObjectMorphInParticleEffect(string _arg0_);
	const string& GetObjectMorphInParticleEffect() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1072C50);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x132AD60);
};

// ArkPsiPowerMimicLevelProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiPowerMimicLevelProperties : public ArkReflectedObject
{ // Size=104 (0x68)
public:
	// ArkPsiPowerMimicLevelProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerMimicLevelProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerMimicLevelProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerMimicLevelProperties::ArkPsiCostPerSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkPsiCostPerSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPsiCostPerSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicLevelProperties::ArkPsiCostPerSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicLevelProperties::ArkPsiCostPerSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
	};

	// ArkPsiPowerMimicLevelProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicLevelProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13285D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicLevelProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerMimicLevelProperties::ArkDisplayNameProperty>(0x2BDB588);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerMimicLevelProperties::ArkDescriptionProperty>(0x2BDB5A8);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerMimicLevelProperties::ArkCooldownDurationSecProperty>(0x2BDB5C8);
	float m_CooldownDurationSec;
	static inline auto s_ArkPsiCostPerSecProperty = PreyGlobal<ArkPsiPowerMimicLevelProperties::ArkPsiCostPerSecProperty>(0x2BDB5E8);
	float m_PsiCostPerSec;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerMimicLevelProperties::ArkTargetingPropertiesProperty>(0x2BDB608);
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetCooldownDurationSec(float _arg0_);
	const float& GetCooldownDurationSec() const;
	void SetPsiCostPerSec(float _arg0_);
	const float& GetPsiCostPerSec() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x132A820);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x132AE00);
};

// ArkPsiPowerMimicUniqueProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class ArkPsiPowerMimicUniqueProperties : public ArkReflectedObject
{ // Size=872 (0x368)
public:
	// ArkPsiPowerMimicUniqueProperties::ArkAutoFallbackRangeProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkAutoFallbackRangeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAutoFallbackRangeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkAutoFallbackRangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkAutoFallbackRangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkForceMorphOutDelaySecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkForceMorphOutDelaySecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkForceMorphOutDelaySecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkForceMorphOutDelaySecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkForceMorphOutDelaySecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkGameNoiseDelaySecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkGameNoiseDelaySecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkGameNoiseDelaySecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkGameNoiseDelaySecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkGameNoiseDelaySecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkClipOpacityProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkClipOpacityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkClipOpacityProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkClipOpacityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkClipOpacityProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkRigidPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkRigidPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRigidPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkRigidPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkRigidPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkTurretPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkTurretPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTurretPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkTurretPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkTurretPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x13D50D0);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkOperatorPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkOperatorPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkOperatorPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkOperatorPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1327FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkOperatorPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328020);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkMilitaryOperatorPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkMilitaryOperatorPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMilitaryOperatorPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkMilitaryOperatorPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkMilitaryOperatorPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328200);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkEngineeringOperatorPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkEngineeringOperatorPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEngineeringOperatorPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkEngineeringOperatorPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328210);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkEngineeringOperatorPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328260);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkScienceOperatorPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkScienceOperatorPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkScienceOperatorPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkScienceOperatorPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328270);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkScienceOperatorPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x13282D0);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkEffectsPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkEffectsPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEffectsPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkEffectsPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13282E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkEffectsPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328320);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkPlayerSignalModifiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkPlayerSignalModifiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328330);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328360);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x1328390);
	};

	// ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkObjectSignalModifiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkObjectSignalModifiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13283A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x13283D0);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x1328400);
	};

	static inline auto s_ArkAutoFallbackRangeProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkAutoFallbackRangeProperty>(0x2BDB3E8);
	float m_AutoFallbackRange;
	static inline auto s_ArkForceMorphOutDelaySecProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkForceMorphOutDelaySecProperty>(0x2BDB408);
	float m_ForceMorphOutDelaySec;
	static inline auto s_ArkGameNoiseDelaySecProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkGameNoiseDelaySecProperty>(0x2BDB428);
	float m_GameNoiseDelaySec;
	static inline auto s_ArkClipOpacityProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkClipOpacityProperty>(0x2BDB448);
	float m_ClipOpacity;
	static inline auto s_ArkRigidPropertiesProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkRigidPropertiesProperty>(0x2BDB468);
	ArkPsiMimicRigidProperties m_RigidProperties;
	static inline auto s_ArkTurretPropertiesProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkTurretPropertiesProperty>(0x2BDB488);
	ArkPsiMimicTurretProperties m_TurretProperties;
	static inline auto s_ArkOperatorPropertiesProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkOperatorPropertiesProperty>(0x2BDB4A8);
	ArkPsiMimicOperatorProperties m_OperatorProperties;
	static inline auto s_ArkMilitaryOperatorPropertiesProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkMilitaryOperatorPropertiesProperty>(0x2BDB4C8);
	ArkPsiMimicMilitaryOperatorProperties m_MilitaryOperatorProperties;
	static inline auto s_ArkEngineeringOperatorPropertiesProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkEngineeringOperatorPropertiesProperty>(0x2BDB4E8);
	ArkPsiMimicEngineeringOperatorProperties m_EngineeringOperatorProperties;
	static inline auto s_ArkScienceOperatorPropertiesProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkScienceOperatorPropertiesProperty>(0x2BDB508);
	ArkPsiMimicScienceOperatorProperties m_ScienceOperatorProperties;
	static inline auto s_ArkEffectsPropertiesProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkEffectsPropertiesProperty>(0x2BDB528);
	ArkPsiPowerMimicEffectsProperties m_EffectsProperties;
	static inline auto s_ArkPlayerSignalModifiersProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkPlayerSignalModifiersProperty>(0x2BDB548);
	std::vector<uint64_t> m_PlayerSignalModifiers;
	static inline auto s_ArkObjectSignalModifiersProperty = PreyGlobal<ArkPsiPowerMimicUniqueProperties::ArkObjectSignalModifiersProperty>(0x2BDB568);
	std::vector<uint64_t> m_ObjectSignalModifiers;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetAutoFallbackRange(float _arg0_);
	const float& GetAutoFallbackRange() const;
	void SetForceMorphOutDelaySec(float _arg0_);
	const float& GetForceMorphOutDelaySec() const;
	void SetGameNoiseDelaySec(float _arg0_);
	const float& GetGameNoiseDelaySec() const;
	void SetClipOpacity(float _arg0_);
	const float& GetClipOpacity() const;
	void SetRigidProperties(ArkPsiMimicRigidProperties _arg0_);
	const ArkPsiMimicRigidProperties& GetRigidProperties() const;
	void SetTurretProperties(ArkPsiMimicTurretProperties _arg0_);
	const ArkPsiMimicTurretProperties& GetTurretProperties() const;
	void SetOperatorProperties(ArkPsiMimicOperatorProperties _arg0_);
	const ArkPsiMimicOperatorProperties& GetOperatorProperties() const;
	void SetMilitaryOperatorProperties(ArkPsiMimicMilitaryOperatorProperties _arg0_);
	const ArkPsiMimicMilitaryOperatorProperties& GetMilitaryOperatorProperties() const;
	void SetEngineeringOperatorProperties(ArkPsiMimicEngineeringOperatorProperties _arg0_);
	const ArkPsiMimicEngineeringOperatorProperties& GetEngineeringOperatorProperties() const;
	void SetScienceOperatorProperties(ArkPsiMimicScienceOperatorProperties _arg0_);
	const ArkPsiMimicScienceOperatorProperties& GetScienceOperatorProperties() const;
	void SetEffectsProperties(ArkPsiPowerMimicEffectsProperties _arg0_);
	const ArkPsiPowerMimicEffectsProperties& GetEffectsProperties() const;
	std::vector<uint64_t>& GetPlayerSignalModifiers();
	const std::vector<uint64_t>& GetPlayerSignalModifiers() const;
	std::vector<uint64_t>& GetObjectSignalModifiers();
	const std::vector<uint64_t>& GetObjectSignalModifiers() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x132A890);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x132AEA0);
};

// MimicPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
class MimicPowerProperties : public ArkReflectedLibrary
{ // Size=1112 (0x458)
public:
	// MimicPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const MimicPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const MimicPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// MimicPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const MimicPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13286C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const MimicPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// MimicPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h
	class ArkLevelsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkLevelsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const MimicPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328910);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const MimicPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13289F0);
		static inline auto FIsArray = PreyFunction<bool(const MimicPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const MimicPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x1328A40);
	};

	using LevelProperties = ArkPsiPowerMimicLevelProperties;
	using UniqueProperties = ArkPsiPowerMimicUniqueProperties;

	static inline auto s_ArkCommonProperty = PreyGlobal<MimicPowerProperties::ArkCommonProperty>(0x2BDB628);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<MimicPowerProperties::ArkUniqueProperty>(0x2BDB648);
	ArkPsiPowerMimicUniqueProperties m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<MimicPowerProperties::ArkLevelsProperty>(0x2BDB668);
	std::vector<ArkPsiPowerMimicLevelProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(ArkPsiPowerMimicUniqueProperties _arg0_);
	const ArkPsiPowerMimicUniqueProperties& GetUnique() const;
	std::vector<ArkPsiPowerMimicLevelProperties>& GetLevels();
	const std::vector<ArkPsiPowerMimicLevelProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x132A8D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x132AF40);
	static inline auto FInit = PreyFunction<bool(MimicPowerProperties* const _this)>(0x132B030);
};

