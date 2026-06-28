// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkPsiPowerFactionProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfaction.h
class ArkPsiPowerFactionProperties : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfaction.h
	class ArkExecuteAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExecuteAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiPowerFactionProperties::ArkHostileOnlyProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerfaction.h
	class ArkHostileOnlyProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHostileOnlyProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerFactionProperties::ArkHostileOnlyProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16AA640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerFactionProperties::ArkHostileOnlyProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	static inline auto s_ArkExecuteAudioTriggerProperty = PreyGlobal<ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty>(0x2D7DD30);
	string m_ExecuteAudioTrigger;
	static inline auto s_ArkHostileOnlyProperty = PreyGlobal<ArkPsiPowerFactionProperties::ArkHostileOnlyProperty>(0x2D7DD50);
	bool m_HostileOnly;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetExecuteAudioTrigger(string _arg0_);
	const string& GetExecuteAudioTrigger() const;
	void SetHostileOnly(bool _arg0_);
	const bool& GetHostileOnly() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16C5680);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x16AAC40);
};
#endif // !MOONCRASH
