// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkPsiPowerFactionProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfaction.h
class ArkPsiPowerFactionProperties : public ArkReflectedObject
{ // Size=8 (0x8)
public:
	// ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfaction.h
	class ArkExecuteAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkExecuteAudioTriggerProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FArkExecuteAudioTriggerPropertyOv2 = PreyFunction<void(ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty* const _this)>(0x1583400);
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	static inline auto s_ArkExecuteAudioTriggerProperty = PreyGlobal<ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty>(0x2C03440);
	string m_ExecuteAudioTrigger;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetExecuteAudioTrigger(string _arg0_);
	const string& GetExecuteAudioTrigger() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13644E0);
};

