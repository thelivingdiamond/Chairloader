// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkability.h>
#include <Prey/Ark/arktraumas.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arktraumas.h
class ArkConditionalStatModifier : public ArkStatModifier // Id=801391E Size=24
{
public:
	class ArkIsActiveInAlternateFormProperty : public ArkProperty // Id=801391F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkConditionalStatModifier::ArkIsActiveInAlternateFormProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1360190);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkConditionalStatModifier::ArkIsActiveInAlternateFormProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	static ArkConditionalStatModifier::ArkIsActiveInAlternateFormProperty s_ArkIsActiveInAlternateFormProperty;
	bool m_IsActiveInAlternateForm;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetIsActiveInAlternateForm(bool arg0);
	const bool& GetIsActiveInAlternateForm() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10852E0);
};

// Header: Exact
// Prey/Ark/arktraumas.h
class ArkConditionalSignalModifier : public ArkSignalModifer // Id=801390E Size=24
{
public:
	class ArkIsActiveInAlternateFormProperty : public ArkProperty // Id=801390F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkConditionalSignalModifier::ArkIsActiveInAlternateFormProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1360190);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkConditionalSignalModifier::ArkIsActiveInAlternateFormProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	static ArkConditionalSignalModifier::ArkIsActiveInAlternateFormProperty s_ArkIsActiveInAlternateFormProperty;
	bool m_IsActiveInAlternateForm;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetIsActiveInAlternateForm(bool arg0);
	const bool& GetIsActiveInAlternateForm() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10852B0);
};

// Header: Exact
// Prey/Ark/arktraumas.h
class ArkTraumaPhase : public ArkReflectedObject // Id=8013905 Size=80
{
public:
	class ArkDamageThresholdProperty : public ArkProperty // Id=8013906 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkTraumaPhase::ArkDamageThresholdProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkTraumaPhase::ArkDamageThresholdProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	static ArkTraumaPhase::ArkDamageThresholdProperty s_ArkDamageThresholdProperty;
	float m_DamageThreshold;

	class ArkDescriptionProperty : public ArkProperty // Id=8013907 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkTraumaPhase::ArkDescriptionProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkTraumaPhase::ArkDescriptionProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	static ArkTraumaPhase::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;

	class ArkAltOxygenDescriptionProperty : public ArkProperty // Id=8013908 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkTraumaPhase::ArkAltOxygenDescriptionProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkTraumaPhase::ArkAltOxygenDescriptionProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	static ArkTraumaPhase::ArkAltOxygenDescriptionProperty s_ArkAltOxygenDescriptionProperty;
	string m_AltOxygenDescription;

	class ArkHudIconProperty : public ArkProperty // Id=8013909 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkTraumaPhase::ArkHudIconProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkTraumaPhase::ArkHudIconProperty const* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	static ArkTraumaPhase::ArkHudIconProperty s_ArkHudIconProperty;
	string m_HudIcon;

	class ArkSignalModifiersProperty : public ArkProperty // Id=801390A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkTraumaPhase::ArkSignalModifiersProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1082200);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkTraumaPhase::ArkSignalModifiersProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1082230);
		static inline auto FIsArray = PreyFunction<bool(ArkTraumaPhase::ArkSignalModifiersProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkTraumaPhase::ArkSignalModifiersProperty const* const _this, ArkReflectedObject* _pObject)>(0x10592F0);
	};

	static ArkTraumaPhase::ArkSignalModifiersProperty s_ArkSignalModifiersProperty;
	std::vector<ArkConditionalSignalModifier> m_SignalModifiers;

	class ArkStatModifiersProperty : public ArkProperty // Id=801391A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkTraumaPhase::ArkStatModifiersProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1081F10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkTraumaPhase::ArkStatModifiersProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1081F80);
		static inline auto FIsArray = PreyFunction<bool(ArkTraumaPhase::ArkStatModifiersProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkTraumaPhase::ArkStatModifiersProperty const* const _this, ArkReflectedObject* _pObject)>(0x1081FA0);
	};

	static ArkTraumaPhase::ArkStatModifiersProperty s_ArkStatModifiersProperty;
	std::vector<ArkConditionalStatModifier> m_StatModifiers;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDamageThreshold(float arg0);
	const float& GetDamageThreshold() const;
	void SetDescription(string arg0);
	string const& GetDescription() const;
	void SetAltOxygenDescription(string arg0);
	string const& GetAltOxygenDescription() const;
	void SetHudIcon(string arg0);
	string const& GetHudIcon() const;
	std::vector<ArkConditionalSignalModifier>& GetSignalModifiers();
	std::vector<ArkConditionalSignalModifier> const& GetSignalModifiers() const;
	std::vector<ArkConditionalStatModifier>& GetStatModifiers();
	std::vector<ArkConditionalStatModifier> const& GetStatModifiers() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10853B0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1085530);
};

// Header: Exact
// Prey/Ark/arktraumas.h
class ArkTrauma : public ArkReflectedObject // Id=80138E9 Size=176
{
public:
	class ArkIDProperty : public ArkProperty // Id=80138EA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkTrauma::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=80138EB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1067250);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkTrauma::ArkNameProperty s_ArkNameProperty;
	CCryName m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=80138EC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1082120);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkTrauma::ArkLabelProperty s_ArkLabelProperty;
	CCryName m_Label;
	
	class ArkSurvivalModeProperty : public ArkProperty // Id=80138ED Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkSurvivalModeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkSurvivalModeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkTrauma::ArkSurvivalModeProperty s_ArkSurvivalModeProperty;
	bool m_SurvivalMode;
	
	class ArkHowToRemoveProperty : public ArkProperty // Id=80138EE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkHowToRemoveProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkHowToRemoveProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkTrauma::ArkHowToRemoveProperty s_ArkHowToRemoveProperty;
	string m_HowToRemove;
	
	class ArkDoesStackProperty : public ArkProperty // Id=80138EF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkDoesStackProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13600A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkDoesStackProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkTrauma::ArkDoesStackProperty s_ArkDoesStackProperty;
	bool m_DoesStack;
	
	class ArkMaxAccumulationProperty : public ArkProperty // Id=80138F0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkMaxAccumulationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkMaxAccumulationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328680);
	};

	static ArkTrauma::ArkMaxAccumulationProperty s_ArkMaxAccumulationProperty;
	float m_MaxAccumulation;
	
	class ArkDrainRateProperty : public ArkProperty // Id=80138F1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkDrainRateProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkDrainRateProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkTrauma::ArkDrainRateProperty s_ArkDrainRateProperty;
	float m_DrainRate;
	
	class ArkRemoveOnDrainProperty : public ArkProperty // Id=80138F2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkRemoveOnDrainProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkRemoveOnDrainProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107A620);
	};

	static ArkTrauma::ArkRemoveOnDrainProperty s_ArkRemoveOnDrainProperty;
	bool m_RemoveOnDrain;
	
	class ArkFillHudIconProperty : public ArkProperty // Id=80138F3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkFillHudIconProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkFillHudIconProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821E0);
	};

	static ArkTrauma::ArkFillHudIconProperty s_ArkFillHudIconProperty;
	bool m_FillHudIcon;
	
	class ArkSuitVOProperty : public ArkProperty // Id=80138F4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkSuitVOProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328520);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkSuitVOProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkTrauma::ArkSuitVOProperty s_ArkSuitVOProperty;
	uint64_t m_SuitVO;
	
	class ArkPlayerMaterialProperty : public ArkProperty // Id=80138F5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkPlayerMaterialProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkPlayerMaterialProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkTrauma::ArkPlayerMaterialProperty s_ArkPlayerMaterialProperty;
	string m_PlayerMaterial;
	
	class ArkPlayerMaterialPriorityProperty : public ArkProperty // Id=80138F6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkPlayerMaterialPriorityProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkPlayerMaterialPriorityProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
	};

	static ArkTrauma::ArkPlayerMaterialPriorityProperty s_ArkPlayerMaterialPriorityProperty;
	int m_PlayerMaterialPriority;
	
	class ArkTraumaSFXProperty : public ArkProperty // Id=80138F7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkTraumaSFXProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkTraumaSFXProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkTrauma::ArkTraumaSFXProperty s_ArkTraumaSFXProperty;
	string m_TraumaSFX;
	
	class ArkTraumaStopSFXProperty : public ArkProperty // Id=80138F8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkTraumaStopSFXProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkTraumaStopSFXProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10860E0);
	};

	static ArkTrauma::ArkTraumaStopSFXProperty s_ArkTraumaStopSFXProperty;
	string m_TraumaStopSFX;
	
	class ArkDurationProperty : public ArkProperty // Id=80138F9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328AA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086170);
	};

	static ArkTrauma::ArkDurationProperty s_ArkDurationProperty;
	float m_Duration;
	
	class ArkPostEffectProperty : public ArkProperty // Id=80138FA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkPostEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1089090);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkPostEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4D20);
	};

	static ArkTrauma::ArkPostEffectProperty s_ArkPostEffectProperty;
	uint64_t m_PostEffect;
	
	class ArkPostEffectParamProperty : public ArkProperty // Id=80138FB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkPostEffectParamProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1082250);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkPostEffectParamProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1082260);
	};

	static ArkTrauma::ArkPostEffectParamProperty s_ArkPostEffectParamProperty;
	uint64_t m_PostEffectParam;
	
	class ArkRepeatMinProperty : public ArkProperty // Id=80138FC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkRepeatMinProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1082270);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkRepeatMinProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4D30);
	};

	static ArkTrauma::ArkRepeatMinProperty s_ArkRepeatMinProperty;
	float m_RepeatMin;
	
	class ArkRepeatMaxProperty : public ArkProperty // Id=80138FD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkRepeatMaxProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1082280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkRepeatMaxProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1082290);
	};

	static ArkTrauma::ArkRepeatMaxProperty s_ArkRepeatMaxProperty;
	float m_RepeatMax;
	
	class ArkTagStateProperty : public ArkProperty // Id=80138FE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkTagStateProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4D40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkTagStateProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10617E0);
	};

	static ArkTrauma::ArkTagStateProperty s_ArkTagStateProperty;
	string m_TagState;
	
	class ArkRemoveSignalProperty : public ArkProperty // Id=80138FF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkRemoveSignalProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkRemoveSignalProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4DB0);
	};

	static ArkTrauma::ArkRemoveSignalProperty s_ArkRemoveSignalProperty;
	uint64_t m_RemoveSignal;
	
	class ArkAccumulateSignalProperty : public ArkProperty // Id=8013900 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkAccumulateSignalProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D5070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkAccumulateSignalProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10822A0);
	};

	static ArkTrauma::ArkAccumulateSignalProperty s_ArkAccumulateSignalProperty;
	uint64_t m_AccumulateSignal;
	
	class ArkPhasesProperty : public ArkProperty // Id=8013901 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTrauma::ArkPhasesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10822B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTrauma::ArkPhasesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10823D0);
		static inline auto FIsArray = PreyFunction<bool(ArkTrauma::ArkPhasesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkTrauma::ArkPhasesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1082400);
	};

	static ArkTrauma::ArkPhasesProperty s_ArkPhasesProperty;
	std::vector<ArkTraumaPhase> m_Phases;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	ArkTraumaPhase const *GetPhase(int _level) const { return FGetPhase(this,_level); }
	ArkTraumaPhase const *GetMaxPhase() const { return FGetMaxPhase(this); }
	int GetLevelFromDamage(float _damage) const { return FGetLevelFromDamage(this,_damage); }
	float GetMaxDamageThreshold() const { return FGetMaxDamageThreshold(this); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(CCryName arg0);
	CCryName const &GetName() const;
	void SetLabel(CCryName arg0);
	CCryName const &GetLabel() const;
	void SetSurvivalMode(bool arg0);
	const bool &GetSurvivalMode() const;
	void SetHowToRemove(string arg0);
	string const &GetHowToRemove() const;
	void SetDoesStack(bool arg0);
	const bool &GetDoesStack() const;
	void SetMaxAccumulation(float arg0);
	const float &GetMaxAccumulation() const;
	void SetDrainRate(float arg0);
	const float &GetDrainRate() const;
	void SetRemoveOnDrain(bool arg0);
	const bool &GetRemoveOnDrain() const;
	void SetFillHudIcon(bool arg0);
	const bool &GetFillHudIcon() const;
	void SetSuitVO(uint64_t arg0);
	const uint64_t &GetSuitVO() const;
	void SetPlayerMaterial(string arg0);
	string const &GetPlayerMaterial() const;
	void SetPlayerMaterialPriority(int arg0);
	const int &GetPlayerMaterialPriority() const;
	void SetTraumaSFX(string arg0);
	string const &GetTraumaSFX() const;
	void SetTraumaStopSFX(string arg0);
	string const &GetTraumaStopSFX() const;
	void SetDuration(float arg0);
	const float &GetDuration() const;
	void SetPostEffect(uint64_t arg0);
	const uint64_t &GetPostEffect() const;
	void SetPostEffectParam(uint64_t arg0);
	const uint64_t &GetPostEffectParam() const;
	void SetRepeatMin(float arg0);
	const float &GetRepeatMin() const;
	void SetRepeatMax(float arg0);
	const float &GetRepeatMax() const;
	void SetTagState(string arg0);
	string const &GetTagState() const;
	void SetRemoveSignal(uint64_t arg0);
	const uint64_t &GetRemoveSignal() const;
	void SetAccumulateSignal(uint64_t arg0);
	const uint64_t &GetAccumulateSignal() const;
	std::vector<ArkTraumaPhase> &GetPhases();
	std::vector<ArkTraumaPhase> const &GetPhases() const;
	void Init();
	int GetNumPhases() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1085310);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1085490);
	static inline auto FGetPhase = PreyFunction<ArkTraumaPhase const *(ArkTrauma const *const _this, int _level)>(0x10857E0);
	static inline auto FGetMaxPhase = PreyFunction<ArkTraumaPhase const *(ArkTrauma const *const _this)>(0x1085780);
	static inline auto FGetLevelFromDamage = PreyFunction<int(ArkTrauma const *const _this, float _damage)>(0x10856C0);
	static inline auto FGetMaxDamageThreshold = PreyFunction<float(ArkTrauma const *const _this)>(0x1085720);
};

// Header: Exact
// Prey/Ark/ArkTraumas.h
class ArkTraumas : public ArkReflectedLibrary // Id=8016CA9 Size=32
{
public:
	class ArkTraumasProperty : public ArkProperty // Id=8016CAA Size=32
	{
	public:
		ArkTraumasProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTraumas::ArkTraumasProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1082020);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTraumas::ArkTraumasProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1082070);
		static inline auto FIsArray = PreyFunction<bool(ArkTraumas::ArkTraumasProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkTraumas::ArkTraumasProperty const *const _this, ArkReflectedObject *_pObject)>(0x10820B0);
	};

	static ArkTraumas::ArkTraumasProperty s_ArkTraumasProperty;
	std::vector<ArkTrauma> m_Traumas;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkTrauma const *Find(uint64_t _id) const { return FFind(this,_id); }
	virtual ~ArkTraumas();
	
#if 0
	std::vector<ArkTrauma> &GetTraumas();
	std::vector<ArkTrauma> const &GetTraumas() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1085400);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10855D0);
	static inline auto FInit = PreyFunction<bool(ArkTraumas *const _this)>(0x1085830);
	static inline auto FFind = PreyFunction<ArkTrauma const *(ArkTraumas const *const _this, uint64_t _id)>(0x1085460);
};

