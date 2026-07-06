// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>

class ArkClass;
class IArkValueBase;

// ArkPsiPowerBlackListEntry
// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
class ArkPsiPowerBlackListEntry : public ArkReflectedObject
{ // Size=4 (0x4)
public:
	// ArkPsiPowerBlackListEntry::ArkPowerProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkPowerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkPowerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerBlackListEntry::ArkPowerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E1150);
	};

	static inline auto s_ArkPowerProperty = PreyGlobal<ArkPsiPowerBlackListEntry::ArkPowerProperty>(0x2D5AF00);
	EArkPsiPowers m_Power;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetPower(string _arg0_);
	const EArkPsiPowers& GetPower() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x14E13B0);
};

// ArkPsiPowerCommonProperties
// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
class ArkPsiPowerCommonProperties : public ArkReflectedObject
{ // Size=208 (0xD0)
public:
	// ArkPsiPowerCommonProperties::ArkDisplayNameProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiPowerCommonProperties::ArkPickerLabelProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkPickerLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPickerLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkPickerLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkPickerLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiPowerCommonProperties::ArkDescriptionProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiPowerCommonProperties::ArkHelpTextProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkHelpTextProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHelpTextProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkHelpTextProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkHelpTextProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiPowerCommonProperties::ArkPsiCostProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkPsiCostProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPsiCostProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkPsiCostProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkPsiCostProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkPsiPowerCommonProperties::ArkNoiseIdProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkNoiseIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNoiseIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkPsiPowerCommonProperties::ArkLoudnessIdProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkLoudnessIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLoudnessIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B6480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkActiveBlacklistProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkActiveBlacklistProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E11A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E11C0);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty* const _this, ArkReflectedObject* _pObject)>(0x1077BE0);
	};

	// ArkPsiPowerCommonProperties::ArkModalLegendProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkModalLegendProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkModalLegendProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkModalLegendProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0E00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkModalLegendProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
	};

	// ArkPsiPowerCommonProperties::ArkTargetingLegendProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkTargetingLegendProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingLegendProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkTargetingLegendProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0EA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkTargetingLegendProperty* const _this, ArkReflectedObject* const _pObject)>(0x1403090);
	};

	// ArkPsiPowerCommonProperties::ArkPostProcessVFXProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkPostProcessVFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPostProcessVFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkPostProcessVFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13C0750);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkPostProcessVFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6A0);
	};

	// ArkPsiPowerCommonProperties::ArkPersistentPostProcessVFXProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkPersistentPostProcessVFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPersistentPostProcessVFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkPersistentPostProcessVFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089FF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkPersistentPostProcessVFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6B0);
	};

	// ArkPsiPowerCommonProperties::ArkTargetHighlightColorProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkTargetHighlightColorProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetHighlightColorProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkTargetHighlightColorProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0F40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkTargetHighlightColorProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C0760);
	};

	// ArkPsiPowerCommonProperties::ArkTargetHighlightColorAlphaProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkTargetHighlightColorAlphaProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetHighlightColorAlphaProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkTargetHighlightColorAlphaProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkTargetHighlightColorAlphaProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0F90);
	};

	// ArkPsiPowerCommonProperties::ArkExecutionPlayerEffectProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkExecutionPlayerEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExecutionPlayerEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkExecutionPlayerEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkExecutionPlayerEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E1000);
	};

	// ArkPsiPowerCommonProperties::ArkExecutionAudioTriggerProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkExecutionAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExecutionAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkExecutionAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E1010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkExecutionAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E1070);
	};

	// ArkPsiPowerCommonProperties::ArkCameraZoomDurationProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkCameraZoomDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCameraZoomDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkCameraZoomDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E1080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkCameraZoomDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E1090);
	};

	// ArkPsiPowerCommonProperties::ArkInterruptsMimicGrabSequenceProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkInterruptsMimicGrabSequenceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterruptsMimicGrabSequenceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkInterruptsMimicGrabSequenceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E10A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkInterruptsMimicGrabSequenceProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E10B0);
	};

	// ArkPsiPowerCommonProperties::ArkCostReductionStatProperty
	// Header:  Prey/Ark/ArkPsiPowerCommonProperties.h
	class ArkCostReductionStatProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCostReductionStatProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCommonProperties::ArkCostReductionStatProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E10C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCommonProperties::ArkCostReductionStatProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E1140);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkDisplayNameProperty>(0x2D5AF20);
	string m_DisplayName;
	static inline auto s_ArkPickerLabelProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkPickerLabelProperty>(0x2D5AF40);
	string m_PickerLabel;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkDescriptionProperty>(0x2D5AF60);
	string m_Description;
	static inline auto s_ArkHelpTextProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkHelpTextProperty>(0x2D5AF80);
	string m_HelpText;
	static inline auto s_ArkPsiCostProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkPsiCostProperty>(0x2D5AFA0);
	float m_PsiCost;
	static inline auto s_ArkNoiseIdProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkNoiseIdProperty>(0x2D5AFC0);
	uint64_t m_NoiseId;
	static inline auto s_ArkLoudnessIdProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkLoudnessIdProperty>(0x2D5AFE0);
	uint64_t m_LoudnessId;
	static inline auto s_ArkActiveBlacklistProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkActiveBlacklistProperty>(0x2D5B000);
	std::vector<ArkPsiPowerBlackListEntry> m_ActiveBlacklist;
	static inline auto s_ArkModalLegendProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkModalLegendProperty>(0x2D5B020);
	ArkInputLegend m_ModalLegend;
	static inline auto s_ArkTargetingLegendProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkTargetingLegendProperty>(0x2D5B040);
	ArkInputLegend m_TargetingLegend;
	static inline auto s_ArkPostProcessVFXProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkPostProcessVFXProperty>(0x2D5B060);
	uint64_t m_PostProcessVFX;
	static inline auto s_ArkPersistentPostProcessVFXProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkPersistentPostProcessVFXProperty>(0x2D5B080);
	uint64_t m_PersistentPostProcessVFX;
	static inline auto s_ArkTargetHighlightColorProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkTargetHighlightColorProperty>(0x2D5B0A0);
	Vec3 m_TargetHighlightColor;
	static inline auto s_ArkTargetHighlightColorAlphaProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkTargetHighlightColorAlphaProperty>(0x2D5B0C0);
	float m_TargetHighlightColorAlpha;
	static inline auto s_ArkExecutionPlayerEffectProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkExecutionPlayerEffectProperty>(0x2D5B0E0);
	string m_ExecutionPlayerEffect;
	static inline auto s_ArkExecutionAudioTriggerProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkExecutionAudioTriggerProperty>(0x2D5B100);
	string m_ExecutionAudioTrigger;
	static inline auto s_ArkCameraZoomDurationProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkCameraZoomDurationProperty>(0x2D5B120);
	float m_CameraZoomDuration;
	static inline auto s_ArkInterruptsMimicGrabSequenceProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkInterruptsMimicGrabSequenceProperty>(0x2D5B140);
	bool m_InterruptsMimicGrabSequence;
	static inline auto s_ArkCostReductionStatProperty = PreyGlobal<ArkPsiPowerCommonProperties::ArkCostReductionStatProperty>(0x2D5B160);
	CCryName m_CostReductionStat;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetPickerLabel(string _arg0_);
	const string& GetPickerLabel() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetHelpText(string _arg0_);
	const string& GetHelpText() const;
	void SetPsiCost(float _arg0_);
	const float& GetPsiCost() const;
	void SetNoiseId(uint64_t _arg0_);
	const uint64_t& GetNoiseId() const;
	void SetLoudnessId(uint64_t _arg0_);
	const uint64_t& GetLoudnessId() const;
	std::vector<ArkPsiPowerBlackListEntry>& GetActiveBlacklist();
	const std::vector<ArkPsiPowerBlackListEntry>& GetActiveBlacklist() const;
	void SetModalLegend(ArkInputLegend _arg0_);
	const ArkInputLegend& GetModalLegend() const;
	void SetTargetingLegend(ArkInputLegend _arg0_);
	const ArkInputLegend& GetTargetingLegend() const;
	void SetPostProcessVFX(uint64_t _arg0_);
	const uint64_t& GetPostProcessVFX() const;
	void SetPersistentPostProcessVFX(uint64_t _arg0_);
	const uint64_t& GetPersistentPostProcessVFX() const;
	void SetTargetHighlightColor(Vec3 _arg0_);
	const Vec3& GetTargetHighlightColor() const;
	void SetTargetHighlightColorAlpha(float _arg0_);
	const float& GetTargetHighlightColorAlpha() const;
	void SetExecutionPlayerEffect(string _arg0_);
	const string& GetExecutionPlayerEffect() const;
	void SetExecutionAudioTrigger(string _arg0_);
	const string& GetExecutionAudioTrigger() const;
	void SetCameraZoomDuration(float _arg0_);
	const float& GetCameraZoomDuration() const;
	void SetInterruptsMimicGrabSequence(bool _arg0_);
	const bool& GetInterruptsMimicGrabSequence() const;
	void SetCostReductionStat(CCryName _arg0_);
	const CCryName& GetCostReductionStat() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x14E13E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x14E1480);
};
#endif // !MOONCRASH
