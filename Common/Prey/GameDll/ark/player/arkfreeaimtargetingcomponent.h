// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkFreeAimTargetingComponentProperties
// Header:  Prey/GameDll/ark/player/arkfreeaimtargetingcomponent.h
class ArkFreeAimTargetingComponentProperties : public ArkReflectedObject
{ // Size=8 (0x8)
public:
	// ArkFreeAimTargetingComponentProperties::ArkAimAngleDegProperty
	// Header:  Prey/GameDll/ark/player/arkfreeaimtargetingcomponent.h
	class ArkAimAngleDegProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAimAngleDegProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFreeAimTargetingComponentProperties::ArkAimAngleDegProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFreeAimTargetingComponentProperties::ArkAimAngleDegProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkFreeAimTargetingComponentProperties::ArkMaxTargetDistanceProperty
	// Header:  Prey/GameDll/ark/player/arkfreeaimtargetingcomponent.h
	class ArkMaxTargetDistanceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxTargetDistanceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkFreeAimTargetingComponentProperties::ArkMaxTargetDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkFreeAimTargetingComponentProperties::ArkMaxTargetDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	static inline auto s_ArkAimAngleDegProperty = PreyGlobal<ArkFreeAimTargetingComponentProperties::ArkAimAngleDegProperty>(0x2C022D0);
	float m_AimAngleDeg;
	static inline auto s_ArkMaxTargetDistanceProperty = PreyGlobal<ArkFreeAimTargetingComponentProperties::ArkMaxTargetDistanceProperty>(0x2C022F0);
	float m_MaxTargetDistance;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetAimAngleDeg(float _arg0_);
	const float& GetAimAngleDeg() const;
	void SetMaxTargetDistance(float _arg0_);
	const float& GetMaxTargetDistance() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F6430);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x153CB80);
};

