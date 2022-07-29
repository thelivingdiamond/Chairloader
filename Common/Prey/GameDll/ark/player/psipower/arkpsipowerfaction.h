// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

struct ActionParams;
struct ActionParamsExcept;
struct AkPBIModValues;
class AkRTPCKey;
struct AkSoundParamsEx;
class ArkClass;
struct CounterParameters;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerfaction.h
class ArkPsiPowerFactionProperties : public ArkReflectedObject // Id=801C0F5 Size=8
{
public:
	class ArkExecuteAudioTriggerProperty : public ArkProperty // Id=801C0F6 Size=32
	{
	public:
		ArkExecuteAudioTriggerProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty s_ArkExecuteAudioTriggerProperty;
	string m_ExecuteAudioTrigger;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	void SetExecuteAudioTrigger(string arg0);
	string const &GetExecuteAudioTrigger() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13644E0);
};

