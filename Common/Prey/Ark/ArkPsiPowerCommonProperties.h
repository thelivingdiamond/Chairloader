// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkpsipowercommonproperties.h
class ArkPsiPowerBlackListEntry : public ArkReflectedObject // Id=8017533 Size=4
{
public:
	class ArkPowerProperty : public ArkProperty // Id=8017534 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerBlackListEntry::ArkPowerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4ED0);
	};

	static ArkPsiPowerBlackListEntry::ArkPowerProperty s_ArkPowerProperty;
	EArkPsiPowers m_Power;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	void SetPower(string arg0);
	EArkPsiPowers const &GetPower() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13D5470);
};

// Header: Exact
// Prey/Ark/ArkPsiPowerCommonProperties.h
class ArkPsiPowerCommonProperties : public ArkReflectedObject // Id=8017535 Size=208
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=8017536 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerCommonProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkPickerLabelProperty : public ArkProperty // Id=8017537 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkPickerLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkPickerLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerCommonProperties::ArkPickerLabelProperty s_ArkPickerLabelProperty;
	string m_PickerLabel;
	
	class ArkDescriptionProperty : public ArkProperty // Id=8017538 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerCommonProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkHelpTextProperty : public ArkProperty // Id=8017539 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkHelpTextProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkHelpTextProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerCommonProperties::ArkHelpTextProperty s_ArkHelpTextProperty;
	string m_HelpText;
	
	class ArkPsiCostProperty : public ArkProperty // Id=801753A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkPsiCostProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkPsiCostProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerCommonProperties::ArkPsiCostProperty s_ArkPsiCostProperty;
	float m_PsiCost;
	
	class ArkNoiseIdProperty : public ArkProperty // Id=801753B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkNoiseIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A840);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkNoiseIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkPsiPowerCommonProperties::ArkNoiseIdProperty s_ArkNoiseIdProperty;
	uint64_t m_NoiseId;
	
	class ArkLoudnessIdProperty : public ArkProperty // Id=801753C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkLoudnessIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105B9D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkLoudnessIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkPsiPowerCommonProperties::ArkLoudnessIdProperty s_ArkLoudnessIdProperty;
	uint64_t m_LoudnessId;
	
	class ArkActiveBlacklistProperty : public ArkProperty // Id=801753D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4FB0);
		static inline auto FIsArray = PreyFunction<bool(ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty const *const _this, ArkReflectedObject *_pObject)>(0x1059650);
	};

	static ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty s_ArkActiveBlacklistProperty;
	std::vector<ArkPsiPowerBlackListEntry> m_ActiveBlacklist;
	
	class ArkModalLegendProperty : public ArkProperty // Id=801754B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkModalLegendProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328530);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkModalLegendProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkPsiPowerCommonProperties::ArkModalLegendProperty s_ArkModalLegendProperty;
	ArkInputLegend m_ModalLegend;
	
	class ArkTargetingLegendProperty : public ArkProperty // Id=801754C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkTargetingLegendProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkTargetingLegendProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1082260);
	};

	static ArkPsiPowerCommonProperties::ArkTargetingLegendProperty s_ArkTargetingLegendProperty;
	ArkInputLegend m_TargetingLegend;
	
	class ArkPostProcessVFXProperty : public ArkProperty // Id=801754D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkPostProcessVFXProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D5070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkPostProcessVFXProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10822A0);
	};

	static ArkPsiPowerCommonProperties::ArkPostProcessVFXProperty s_ArkPostProcessVFXProperty;
	uint64_t m_PostProcessVFX;
	
	class ArkPersistentPostProcessVFXProperty : public ArkProperty // Id=801754E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkPersistentPostProcessVFXProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D5080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkPersistentPostProcessVFXProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10736E0);
	};

	static ArkPsiPowerCommonProperties::ArkPersistentPostProcessVFXProperty s_ArkPersistentPostProcessVFXProperty;
	uint64_t m_PersistentPostProcessVFX;
	
	class ArkTargetHighlightColorProperty : public ArkProperty // Id=801754F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkTargetHighlightColorProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D5090);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkTargetHighlightColorProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D50D0);
	};

	static ArkPsiPowerCommonProperties::ArkTargetHighlightColorProperty s_ArkTargetHighlightColorProperty;
	Vec3 m_TargetHighlightColor;
	
	class ArkTargetHighlightColorAlphaProperty : public ArkProperty // Id=8017550 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkTargetHighlightColorAlphaProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D50E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkTargetHighlightColorAlphaProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D50F0);
	};

	static ArkPsiPowerCommonProperties::ArkTargetHighlightColorAlphaProperty s_ArkTargetHighlightColorAlphaProperty;
	float m_TargetHighlightColorAlpha;
	
	class ArkExecutionPlayerEffectProperty : public ArkProperty // Id=8017551 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkExecutionPlayerEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D5100);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkExecutionPlayerEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1073730);
	};

	static ArkPsiPowerCommonProperties::ArkExecutionPlayerEffectProperty s_ArkExecutionPlayerEffectProperty;
	string m_ExecutionPlayerEffect;
	
	class ArkExecutionAudioTriggerProperty : public ArkProperty // Id=8017552 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkExecutionAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D5160);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkExecutionAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D51C0);
	};

	static ArkPsiPowerCommonProperties::ArkExecutionAudioTriggerProperty s_ArkExecutionAudioTriggerProperty;
	string m_ExecutionAudioTrigger;
	
	class ArkCameraZoomDurationProperty : public ArkProperty // Id=8017553 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkCameraZoomDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D51D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkCameraZoomDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D51E0);
	};

	static ArkPsiPowerCommonProperties::ArkCameraZoomDurationProperty s_ArkCameraZoomDurationProperty;
	float m_CameraZoomDuration;
	
	class ArkInterruptsMimicGrabSequenceProperty : public ArkProperty // Id=8017554 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkInterruptsMimicGrabSequenceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D51F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkInterruptsMimicGrabSequenceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D5200);
	};

	static ArkPsiPowerCommonProperties::ArkInterruptsMimicGrabSequenceProperty s_ArkInterruptsMimicGrabSequenceProperty;
	bool m_InterruptsMimicGrabSequence;
	
	class ArkCostReductionStatProperty : public ArkProperty // Id=8017555 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCommonProperties::ArkCostReductionStatProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D5210);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCommonProperties::ArkCostReductionStatProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D5290);
	};

	static ArkPsiPowerCommonProperties::ArkCostReductionStatProperty s_ArkCostReductionStatProperty;
	CCryName m_CostReductionStat;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDisplayName(string arg0);
	string const &GetDisplayName() const;
	void SetPickerLabel(string arg0);
	string const &GetPickerLabel() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetHelpText(string arg0);
	string const &GetHelpText() const;
	void SetPsiCost(float arg0);
	const float &GetPsiCost() const;
	void SetNoiseId(uint64_t arg0);
	const uint64_t &GetNoiseId() const;
	void SetLoudnessId(uint64_t arg0);
	const uint64_t &GetLoudnessId() const;
	std::vector<ArkPsiPowerBlackListEntry> &GetActiveBlacklist();
	std::vector<ArkPsiPowerBlackListEntry> const &GetActiveBlacklist() const;
	void SetModalLegend(ArkInputLegend arg0);
	ArkInputLegend const &GetModalLegend() const;
	void SetTargetingLegend(ArkInputLegend arg0);
	ArkInputLegend const &GetTargetingLegend() const;
	void SetPostProcessVFX(uint64_t arg0);
	const uint64_t &GetPostProcessVFX() const;
	void SetPersistentPostProcessVFX(uint64_t arg0);
	const uint64_t &GetPersistentPostProcessVFX() const;
	void SetTargetHighlightColor(Vec3 arg0);
	Vec3 const &GetTargetHighlightColor() const;
	void SetTargetHighlightColorAlpha(float arg0);
	const float &GetTargetHighlightColorAlpha() const;
	void SetExecutionPlayerEffect(string arg0);
	string const &GetExecutionPlayerEffect() const;
	void SetExecutionAudioTrigger(string arg0);
	string const &GetExecutionAudioTrigger() const;
	void SetCameraZoomDuration(float arg0);
	const float &GetCameraZoomDuration() const;
	void SetInterruptsMimicGrabSequence(bool arg0);
	const bool &GetInterruptsMimicGrabSequence() const;
	void SetCostReductionStat(CCryName arg0);
	CCryName const &GetCostReductionStat() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13D54A0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x13D5540);
};

