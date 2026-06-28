// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAbility.h>
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAbility.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkSignalModifer.h>

class ArkClass;
class IArkValueBase;

// ArkConditionalSignalModifier
// Header:  Prey/Ark/ArkTraumas.h
class ArkConditionalSignalModifier : public ArkSignalModifer
{ // Size=24 (0x18)
public:
	// ArkConditionalSignalModifier::ArkIsActiveInAlternateFormProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkIsActiveInAlternateFormProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIsActiveInAlternateFormProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkConditionalSignalModifier::ArkIsActiveInAlternateFormProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkConditionalSignalModifier::ArkIsActiveInAlternateFormProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	static inline auto s_ArkIsActiveInAlternateFormProperty = PreyGlobal<ArkConditionalSignalModifier::ArkIsActiveInAlternateFormProperty>(0x2D28990);
	bool m_IsActiveInAlternateForm;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetIsActiveInAlternateForm(bool _arg0_);
	const bool& GetIsActiveInAlternateForm() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B0D20);
};

// ArkConditionalStatModifier
// Header:  Prey/Ark/ArkTraumas.h
class ArkConditionalStatModifier : public ArkStatModifier
{ // Size=24 (0x18)
public:
	// ArkConditionalStatModifier::ArkIsActiveInAlternateFormProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkIsActiveInAlternateFormProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIsActiveInAlternateFormProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkConditionalStatModifier::ArkIsActiveInAlternateFormProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkConditionalStatModifier::ArkIsActiveInAlternateFormProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	static inline auto s_ArkIsActiveInAlternateFormProperty = PreyGlobal<ArkConditionalStatModifier::ArkIsActiveInAlternateFormProperty>(0x2D289B0);
	bool m_IsActiveInAlternateForm;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetIsActiveInAlternateForm(bool _arg0_);
	const bool& GetIsActiveInAlternateForm() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B0D50);
};

// ArkTraumaMaterial
// Header:  Prey/Ark/ArkTraumas.h
class ArkTraumaMaterial : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkTraumaMaterial::ArkPlayableCharacterProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkPlayableCharacterProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlayableCharacterProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTraumaMaterial::ArkPlayableCharacterProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTraumaMaterial::ArkPlayableCharacterProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkTraumaMaterial::ArkMaterialNameProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkMaterialNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaterialNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTraumaMaterial::ArkMaterialNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTraumaMaterial::ArkMaterialNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	static inline auto s_ArkPlayableCharacterProperty = PreyGlobal<ArkTraumaMaterial::ArkPlayableCharacterProperty>(0x2D28A90);
	uint64_t m_PlayableCharacter;
	static inline auto s_ArkMaterialNameProperty = PreyGlobal<ArkTraumaMaterial::ArkMaterialNameProperty>(0x2D28AB0);
	string m_MaterialName;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetPlayableCharacter(uint64_t _arg0_);
	const uint64_t& GetPlayableCharacter() const;
	void SetMaterialName(string _arg0_);
	const string& GetMaterialName() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x171D1A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B0FB0);
};

// ArkTraumaPhase
// Header:  Prey/Ark/ArkTraumas.h
class ArkTraumaPhase : public ArkReflectedObject
{ // Size=72 (0x48)
public:
	// ArkTraumaPhase::ArkDamageThresholdProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkDamageThresholdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDamageThresholdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTraumaPhase::ArkDamageThresholdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTraumaPhase::ArkDamageThresholdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkTraumaPhase::ArkRemoveOnDrainProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkRemoveOnDrainProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRemoveOnDrainProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTraumaPhase::ArkRemoveOnDrainProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD170);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTraumaPhase::ArkRemoveOnDrainProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
	};

	// ArkTraumaPhase::ArkDescriptionProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTraumaPhase::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTraumaPhase::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkTraumaPhase::ArkHudIconProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkHudIconProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHudIconProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTraumaPhase::ArkHudIconProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTraumaPhase::ArkHudIconProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkTraumaPhase::ArkSignalModifiersProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkSignalModifiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkSignalModifiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTraumaPhase::ArkSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD190);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTraumaPhase::ArkSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x10AD1C0);
		static inline auto FIsArray = PreyFunction<bool(const ArkTraumaPhase::ArkSignalModifiersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkTraumaPhase::ArkSignalModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x10888D0);
	};

	// ArkTraumaPhase::ArkStatModifiersProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkStatModifiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkStatModifiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTraumaPhase::ArkStatModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD3F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTraumaPhase::ArkStatModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x10AD460);
		static inline auto FIsArray = PreyFunction<bool(const ArkTraumaPhase::ArkStatModifiersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkTraumaPhase::ArkStatModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x10AD480);
	};

	static inline auto s_ArkDamageThresholdProperty = PreyGlobal<ArkTraumaPhase::ArkDamageThresholdProperty>(0x2D289D0);
	float m_DamageThreshold;
	static inline auto s_ArkRemoveOnDrainProperty = PreyGlobal<ArkTraumaPhase::ArkRemoveOnDrainProperty>(0x2D289F0);
	bool m_RemoveOnDrain;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkTraumaPhase::ArkDescriptionProperty>(0x2D28A10);
	string m_Description;
	static inline auto s_ArkHudIconProperty = PreyGlobal<ArkTraumaPhase::ArkHudIconProperty>(0x2D28A50);
	string m_HudIcon;
	static inline auto s_ArkSignalModifiersProperty = PreyGlobal<ArkTraumaPhase::ArkSignalModifiersProperty>(0x2D28A30);
	std::vector<ArkConditionalSignalModifier> m_SignalModifiers;
	static inline auto s_ArkStatModifiersProperty = PreyGlobal<ArkTraumaPhase::ArkStatModifiersProperty>(0x2D28A70);
	std::vector<ArkConditionalStatModifier> m_StatModifiers;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDamageThreshold(float _arg0_);
	const float& GetDamageThreshold() const;
	void SetRemoveOnDrain(bool _arg0_);
	const bool& GetRemoveOnDrain() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetHudIcon(string _arg0_);
	const string& GetHudIcon() const;
	std::vector<ArkConditionalSignalModifier>& GetSignalModifiers();
	const std::vector<ArkConditionalSignalModifier>& GetSignalModifiers() const;
	std::vector<ArkConditionalStatModifier>& GetStatModifiers();
	const std::vector<ArkConditionalStatModifier>& GetStatModifiers() const;
	ArkTraumaPhase();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B0E30);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B1050);
};

// ArkTrauma
// Header:  Prey/Ark/ArkTraumas.h
class ArkTrauma : public ArkReflectedObject
{ // Size=208 (0xD0)
public:
	// ArkTrauma::ArkIDProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkTrauma::ArkNameProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkTrauma::ArkLabelProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD0F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkTrauma::ArkSurvivalModeProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkSurvivalModeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSurvivalModeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkSurvivalModeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkSurvivalModeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkTrauma::ArkHowToRemoveProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkHowToRemoveProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHowToRemoveProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkHowToRemoveProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkHowToRemoveProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkTrauma::ArkDoesStackProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkDoesStackProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDoesStackProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkDoesStackProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkDoesStackProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkTrauma::ArkMaxAccumulationProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkMaxAccumulationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxAccumulationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkMaxAccumulationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3120);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkMaxAccumulationProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3130);
	};

	// ArkTrauma::ArkDrainRateProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkDrainRateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDrainRateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkDrainRateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1080CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkDrainRateProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkTrauma::ArkFillHudIconProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkFillHudIconProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFillHudIconProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkFillHudIconProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD1E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkFillHudIconProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3140);
	};

	// ArkTrauma::ArkSuitVOProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkSuitVOProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSuitVOProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkSuitVOProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD1F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkSuitVOProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkTrauma::ArkPlayerMaterialsProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkPlayerMaterialsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkPlayerMaterialsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkPlayerMaterialsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD200);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkPlayerMaterialsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10AD260);
		static inline auto FIsArray = PreyFunction<bool(const ArkTrauma::ArkPlayerMaterialsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkTrauma::ArkPlayerMaterialsProperty* const _this, ArkReflectedObject* _pObject)>(0x10AD280);
	};

	// ArkTrauma::ArkPlayerMaterialPriorityProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkPlayerMaterialPriorityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlayerMaterialPriorityProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkPlayerMaterialPriorityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A31A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkPlayerMaterialPriorityProperty* const _this, ArkReflectedObject* const _pObject)>(0x10844A0);
	};

	// ArkTrauma::ArkTraumaSFXProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkTraumaSFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTraumaSFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkTraumaSFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD500);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkTraumaSFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B80);
	};

	// ArkTrauma::ArkTraumaStopSFXProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkTraumaStopSFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTraumaStopSFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkTraumaStopSFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0B90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkTraumaStopSFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7840);
	};

	// ArkTrauma::ArkRepeatSFXProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkRepeatSFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRepeatSFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkRepeatSFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0BF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkRepeatSFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x1403090);
	};

	// ArkTrauma::ArkDurationProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089F70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BE110);
	};

	// ArkTrauma::ArkPostEffectProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkPostEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPostEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkPostEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkPostEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x16B7F00);
	};

	// ArkTrauma::ArkRepeatPostEffectProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkRepeatPostEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRepeatPostEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkRepeatPostEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD570);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkRepeatPostEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C570);
	};

	// ArkTrauma::ArkPostEffectParamProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkPostEffectParamProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPostEffectParamProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkPostEffectParamProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13C0750);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkPostEffectParamProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6A0);
	};

	// ArkTrauma::ArkRepeatMinProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkRepeatMinProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRepeatMinProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkRepeatMinProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD580);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkRepeatMinProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6B0);
	};

	// ArkTrauma::ArkRepeatMaxProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkRepeatMaxProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRepeatMaxProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkRepeatMaxProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD590);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkRepeatMaxProperty* const _this, ArkReflectedObject* const _pObject)>(0x10AD5A0);
	};

	// ArkTrauma::ArkTagStateProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkTagStateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTagStateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkTagStateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE210);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkTagStateProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C0760);
	};

	// ArkTrauma::ArkRemoveSignalProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkRemoveSignalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRemoveSignalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkRemoveSignalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD5B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkRemoveSignalProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084620);
	};

	// ArkTrauma::ArkAccumulateSignalProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkAccumulateSignalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAccumulateSignalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkAccumulateSignalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10736D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkAccumulateSignalProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E1000);
	};

	// ArkTrauma::ArkPhasesProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkPhasesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkPhasesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkTrauma::ArkPhasesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTrauma::ArkPhasesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10AD6B0);
		static inline auto FIsArray = PreyFunction<bool(const ArkTrauma::ArkPhasesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkTrauma::ArkPhasesProperty* const _this, ArkReflectedObject* _pObject)>(0x10AD6E0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkTrauma::ArkIDProperty>(0x2D28AD0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkTrauma::ArkNameProperty>(0x2D28AF0);
	CCryName m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkTrauma::ArkLabelProperty>(0x2D28B10);
	CCryName m_Label;
	static inline auto s_ArkSurvivalModeProperty = PreyGlobal<ArkTrauma::ArkSurvivalModeProperty>(0x2D28B30);
	bool m_SurvivalMode;
	static inline auto s_ArkHowToRemoveProperty = PreyGlobal<ArkTrauma::ArkHowToRemoveProperty>(0x2D28B50);
	string m_HowToRemove;
	static inline auto s_ArkDoesStackProperty = PreyGlobal<ArkTrauma::ArkDoesStackProperty>(0x2D28B70);
	bool m_DoesStack;
	static inline auto s_ArkMaxAccumulationProperty = PreyGlobal<ArkTrauma::ArkMaxAccumulationProperty>(0x2D28B90);
	float m_MaxAccumulation;
	static inline auto s_ArkDrainRateProperty = PreyGlobal<ArkTrauma::ArkDrainRateProperty>(0x2D28BB0);
	float m_DrainRate;
	static inline auto s_ArkFillHudIconProperty = PreyGlobal<ArkTrauma::ArkFillHudIconProperty>(0x2D28BD0);
	bool m_FillHudIcon;
	static inline auto s_ArkSuitVOProperty = PreyGlobal<ArkTrauma::ArkSuitVOProperty>(0x2D28BF0);
	uint64_t m_SuitVO;
	static inline auto s_ArkPlayerMaterialsProperty = PreyGlobal<ArkTrauma::ArkPlayerMaterialsProperty>(0x2D28C10);
	std::vector<ArkTraumaMaterial> m_PlayerMaterials;
	static inline auto s_ArkPlayerMaterialPriorityProperty = PreyGlobal<ArkTrauma::ArkPlayerMaterialPriorityProperty>(0x2D28C30);
	int m_PlayerMaterialPriority;
	static inline auto s_ArkTraumaSFXProperty = PreyGlobal<ArkTrauma::ArkTraumaSFXProperty>(0x2D28C50);
	string m_TraumaSFX;
	static inline auto s_ArkTraumaStopSFXProperty = PreyGlobal<ArkTrauma::ArkTraumaStopSFXProperty>(0x2D28C70);
	string m_TraumaStopSFX;
	static inline auto s_ArkRepeatSFXProperty = PreyGlobal<ArkTrauma::ArkRepeatSFXProperty>(0x2D28C90);
	string m_RepeatSFX;
	static inline auto s_ArkDurationProperty = PreyGlobal<ArkTrauma::ArkDurationProperty>(0x2D28CB0);
	float m_Duration;
	static inline auto s_ArkPostEffectProperty = PreyGlobal<ArkTrauma::ArkPostEffectProperty>(0x2D28CD0);
	uint64_t m_PostEffect;
	static inline auto s_ArkRepeatPostEffectProperty = PreyGlobal<ArkTrauma::ArkRepeatPostEffectProperty>(0x2D28CF0);
	uint64_t m_RepeatPostEffect;
	static inline auto s_ArkPostEffectParamProperty = PreyGlobal<ArkTrauma::ArkPostEffectParamProperty>(0x2D28D10);
	uint64_t m_PostEffectParam;
	static inline auto s_ArkRepeatMinProperty = PreyGlobal<ArkTrauma::ArkRepeatMinProperty>(0x2D28D30);
	float m_RepeatMin;
	static inline auto s_ArkRepeatMaxProperty = PreyGlobal<ArkTrauma::ArkRepeatMaxProperty>(0x2D28D50);
	float m_RepeatMax;
	static inline auto s_ArkTagStateProperty = PreyGlobal<ArkTrauma::ArkTagStateProperty>(0x2D28D70);
	string m_TagState;
	static inline auto s_ArkRemoveSignalProperty = PreyGlobal<ArkTrauma::ArkRemoveSignalProperty>(0x2D28D90);
	uint64_t m_RemoveSignal;
	static inline auto s_ArkAccumulateSignalProperty = PreyGlobal<ArkTrauma::ArkAccumulateSignalProperty>(0x2D28DB0);
	uint64_t m_AccumulateSignal;
	static inline auto s_ArkPhasesProperty = PreyGlobal<ArkTrauma::ArkPhasesProperty>(0x2D28DD0);
	std::vector<ArkTraumaPhase> m_Phases;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	int GetNumPhases() const { return FGetNumPhases(this); }
	const ArkTraumaPhase* GetPhase(int _level) const { return FGetPhase(this, _level); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(CCryName _arg0_);
	const CCryName& GetName() const;
	void SetLabel(CCryName _arg0_);
	const CCryName& GetLabel() const;
	void SetSurvivalMode(bool _arg0_);
	const bool& GetSurvivalMode() const;
	void SetHowToRemove(string _arg0_);
	const string& GetHowToRemove() const;
	void SetDoesStack(bool _arg0_);
	const bool& GetDoesStack() const;
	void SetMaxAccumulation(float _arg0_);
	const float& GetMaxAccumulation() const;
	void SetDrainRate(float _arg0_);
	const float& GetDrainRate() const;
	void SetFillHudIcon(bool _arg0_);
	const bool& GetFillHudIcon() const;
	void SetSuitVO(uint64_t _arg0_);
	const uint64_t& GetSuitVO() const;
	std::vector<ArkTraumaMaterial>& GetPlayerMaterials();
	const std::vector<ArkTraumaMaterial>& GetPlayerMaterials() const;
	void SetPlayerMaterialPriority(int _arg0_);
	const int& GetPlayerMaterialPriority() const;
	void SetTraumaSFX(string _arg0_);
	const string& GetTraumaSFX() const;
	void SetTraumaStopSFX(string _arg0_);
	const string& GetTraumaStopSFX() const;
	void SetRepeatSFX(string _arg0_);
	const string& GetRepeatSFX() const;
	void SetDuration(float _arg0_);
	const float& GetDuration() const;
	void SetPostEffect(uint64_t _arg0_);
	const uint64_t& GetPostEffect() const;
	void SetRepeatPostEffect(uint64_t _arg0_);
	const uint64_t& GetRepeatPostEffect() const;
	void SetPostEffectParam(uint64_t _arg0_);
	const uint64_t& GetPostEffectParam() const;
	void SetRepeatMin(float _arg0_);
	const float& GetRepeatMin() const;
	void SetRepeatMax(float _arg0_);
	const float& GetRepeatMax() const;
	void SetTagState(string _arg0_);
	const string& GetTagState() const;
	void SetRemoveSignal(uint64_t _arg0_);
	const uint64_t& GetRemoveSignal() const;
	void SetAccumulateSignal(uint64_t _arg0_);
	const uint64_t& GetAccumulateSignal() const;
	std::vector<ArkTraumaPhase>& GetPhases();
	const std::vector<ArkTraumaPhase>& GetPhases() const;
	ArkTrauma();
	void Init();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B0D80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B0F10);
	static inline auto FGetNumPhases = PreyFunction<int(const ArkTrauma* const _this)>(0x10B11E0);
	static inline auto FGetPhase = PreyFunction<const ArkTraumaPhase* (const ArkTrauma* const _this, int _level)>(0x10B1210);
};

// ArkTraumas
// Header:  Prey/Ark/ArkTraumas.h
class ArkTraumas : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkTraumas::ArkTraumasProperty
	// Header:  Prey/Ark/ArkTraumas.h
	class ArkTraumasProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkTraumasProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkTraumasPropertyOv2 = PreyFunction<void(ArkTraumas::ArkTraumasProperty* const _this)>(0x10B0840);
		static inline auto FSetValue = PreyFunction<void(const ArkTraumas::ArkTraumasProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD2F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkTraumas::ArkTraumasProperty* const _this, ArkReflectedObject* const _pObject)>(0x10AD340);
		static inline auto FIsArray = PreyFunction<bool(const ArkTraumas::ArkTraumasProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkTraumas::ArkTraumasProperty* const _this, ArkReflectedObject* _pObject)>(0x10AD380);
	};

	static inline auto s_ArkTraumasProperty = PreyGlobal<ArkTraumas::ArkTraumasProperty>(0x2D28DF0);
	std::vector<ArkTrauma> m_Traumas;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkTrauma* Find(uint64_t _id) const { return FFind(this, _id); }

#if 0
	std::vector<ArkTrauma>& GetTraumas();
	const std::vector<ArkTrauma>& GetTraumas() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B0E80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B10F0);
	static inline auto FInit = PreyFunction<bool(ArkTraumas* const _this)>(0x10B1260);
	static inline auto FFind = PreyFunction<const ArkTrauma* (const ArkTraumas* const _this, uint64_t _id)>(0x10B0EE0);
};
#endif // !MOONCRASH
