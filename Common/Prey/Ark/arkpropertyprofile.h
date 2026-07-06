// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkTutorial.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkpropertyprofile.h
class ArkDisruptionProfile : public ArkReflectedObject // Id=80141E2 Size=72
{
public:
	class ArkIDProperty : public ArkProperty // Id=80141E3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkDisruptionProfile::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=80141E4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkDisruptionProfile::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkDisruptThresholdProperty : public ArkProperty // Id=80141E5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkDisruptThresholdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkDisruptThresholdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkDisruptionProfile::ArkDisruptThresholdProperty s_ArkDisruptThresholdProperty;
	float m_DisruptThreshold;
	
	class ArkDisruptMaxAmountProperty : public ArkProperty // Id=80141E6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkDisruptMaxAmountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkDisruptMaxAmountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkDisruptionProfile::ArkDisruptMaxAmountProperty s_ArkDisruptMaxAmountProperty;
	float m_DisruptMaxAmount;
	
	class ArkDisruptDecayRateProperty : public ArkProperty // Id=80141E7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkDisruptDecayRateProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkDisruptDecayRateProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkDisruptionProfile::ArkDisruptDecayRateProperty s_ArkDisruptDecayRateProperty;
	float m_DisruptDecayRate;
	
	class ArkDisruptSparkRateProperty : public ArkProperty // Id=80141E8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkDisruptSparkRateProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkDisruptSparkRateProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkDisruptionProfile::ArkDisruptSparkRateProperty s_ArkDisruptSparkRateProperty;
	float m_DisruptSparkRate;
	
	class ArkDisruptSparkVariationProperty : public ArkProperty // Id=80141E9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkDisruptSparkVariationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkDisruptSparkVariationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkDisruptionProfile::ArkDisruptSparkVariationProperty s_ArkDisruptSparkVariationProperty;
	float m_DisruptSparkVariation;
	
	class ArkDisruptSignalProperty : public ArkProperty // Id=80141EA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkDisruptSignalProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A840);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkDisruptSignalProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkDisruptionProfile::ArkDisruptSignalProperty s_ArkDisruptSignalProperty;
	uint64_t m_DisruptSignal;
	
	class ArkInterferenceThresholdProperty : public ArkProperty // Id=80141EB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkInterferenceThresholdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkInterferenceThresholdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkDisruptionProfile::ArkInterferenceThresholdProperty s_ArkInterferenceThresholdProperty;
	float m_InterferenceThreshold;
	
	class ArkInterferenceMaxAmountProperty : public ArkProperty // Id=80141EC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkInterferenceMaxAmountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A610);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkInterferenceMaxAmountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107A620);
	};

	static ArkDisruptionProfile::ArkInterferenceMaxAmountProperty s_ArkInterferenceMaxAmountProperty;
	float m_InterferenceMaxAmount;
	
	class ArkInterferenceDecayRateProperty : public ArkProperty // Id=80141ED Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkInterferenceDecayRateProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A630);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkInterferenceDecayRateProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkDisruptionProfile::ArkInterferenceDecayRateProperty s_ArkInterferenceDecayRateProperty;
	float m_InterferenceDecayRate;
	
	class ArkInterferenceSignalProperty : public ArkProperty // Id=80141EE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDisruptionProfile::ArkInterferenceSignalProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105B9E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDisruptionProfile::ArkInterferenceSignalProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkDisruptionProfile::ArkInterferenceSignalProperty s_ArkInterferenceSignalProperty;
	uint64_t m_InterferenceSignal;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetDisruptThreshold(float arg0);
	const float &GetDisruptThreshold() const;
	void SetDisruptMaxAmount(float arg0);
	const float &GetDisruptMaxAmount() const;
	void SetDisruptDecayRate(float arg0);
	const float &GetDisruptDecayRate() const;
	void SetDisruptSparkRate(float arg0);
	const float &GetDisruptSparkRate() const;
	void SetDisruptSparkVariation(float arg0);
	const float &GetDisruptSparkVariation() const;
	void SetDisruptSignal(uint64_t arg0);
	const uint64_t &GetDisruptSignal() const;
	void SetInterferenceThreshold(float arg0);
	const float &GetInterferenceThreshold() const;
	void SetInterferenceMaxAmount(float arg0);
	const float &GetInterferenceMaxAmount() const;
	void SetInterferenceDecayRate(float arg0);
	const float &GetInterferenceDecayRate() const;
	void SetInterferenceSignal(uint64_t arg0);
	const uint64_t &GetInterferenceSignal() const;
	void ValidateData();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107B480);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107B5D0);
};

// Header: Exact
// Prey/Ark/arkpropertyprofile.h
class ArkLightDisruptionProfile : public ArkReflectedObject // Id=8014216 Size=104
{
public:
	class ArkIDProperty : public ArkProperty // Id=8014217 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkLightDisruptionProfile::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8014218 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkLightDisruptionProfile::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkDisruptionBurstTransitionTimeProperty : public ArkProperty // Id=8014219 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkDisruptionBurstTransitionTimeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkDisruptionBurstTransitionTimeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkLightDisruptionProfile::ArkDisruptionBurstTransitionTimeProperty s_ArkDisruptionBurstTransitionTimeProperty;
	float m_DisruptionBurstTransitionTime;
	
	class ArkDisruptionBurstMultiplierProperty : public ArkProperty // Id=801421A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkDisruptionBurstMultiplierProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkDisruptionBurstMultiplierProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkLightDisruptionProfile::ArkDisruptionBurstMultiplierProperty s_ArkDisruptionBurstMultiplierProperty;
	float m_DisruptionBurstMultiplier;
	
	class ArkInterferenceRampInProperty : public ArkProperty // Id=801421B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceRampInProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceRampInProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkLightDisruptionProfile::ArkInterferenceRampInProperty s_ArkInterferenceRampInProperty;
	float m_InterferenceRampIn;
	
	class ArkInterferenceRampInVariationProperty : public ArkProperty // Id=801421C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceRampInVariationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceRampInVariationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkLightDisruptionProfile::ArkInterferenceRampInVariationProperty s_ArkInterferenceRampInVariationProperty;
	float m_InterferenceRampInVariation;
	
	class ArkInterferenceRampOutProperty : public ArkProperty // Id=801421D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceRampOutProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceRampOutProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkLightDisruptionProfile::ArkInterferenceRampOutProperty s_ArkInterferenceRampOutProperty;
	float m_InterferenceRampOut;
	
	class ArkInterferenceRampOutVariationProperty : public ArkProperty // Id=801421E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceRampOutVariationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceRampOutVariationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328510);
	};

	static ArkLightDisruptionProfile::ArkInterferenceRampOutVariationProperty s_ArkInterferenceRampOutVariationProperty;
	float m_InterferenceRampOutVariation;
	
	class ArkInterferenceDarkDurationProperty : public ArkProperty // Id=801421F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceDarkDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceDarkDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkLightDisruptionProfile::ArkInterferenceDarkDurationProperty s_ArkInterferenceDarkDurationProperty;
	float m_InterferenceDarkDuration;
	
	class ArkInterferenceDarkDurationVariationProperty : public ArkProperty // Id=8014220 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceDarkDurationVariationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceDarkDurationVariationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328680);
	};

	static ArkLightDisruptionProfile::ArkInterferenceDarkDurationVariationProperty s_ArkInterferenceDarkDurationVariationProperty;
	float m_InterferenceDarkDurationVariation;
	
	class ArkInterferenceSecondaryDarkDurationProperty : public ArkProperty // Id=8014221 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationProperty s_ArkInterferenceSecondaryDarkDurationProperty;
	float m_InterferenceSecondaryDarkDuration;
	
	class ArkInterferenceSecondaryDarkDurationVariationProperty : public ArkProperty // Id=8014222 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationVariationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A610);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationVariationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107A620);
	};

	static ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationVariationProperty s_ArkInterferenceSecondaryDarkDurationVariationProperty;
	float m_InterferenceSecondaryDarkDurationVariation;
	
	class ArkInterferenceBrightDurationProperty : public ArkProperty // Id=8014223 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceBrightDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A630);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceBrightDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkLightDisruptionProfile::ArkInterferenceBrightDurationProperty s_ArkInterferenceBrightDurationProperty;
	float m_InterferenceBrightDuration;
	
	class ArkInterferenceBrightDurationVariationProperty : public ArkProperty // Id=8014224 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceBrightDurationVariationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceBrightDurationVariationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328E30);
	};

	static ArkLightDisruptionProfile::ArkInterferenceBrightDurationVariationProperty s_ArkInterferenceBrightDurationVariationProperty;
	float m_InterferenceBrightDurationVariation;
	
	class ArkInterferenceMaxBrightnessProperty : public ArkProperty // Id=8014225 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A650);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessProperty s_ArkInterferenceMaxBrightnessProperty;
	float m_InterferenceMaxBrightness;
	
	class ArkInterferenceMaxBrightnessVariationProperty : public ArkProperty // Id=8014226 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessVariationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessVariationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328490);
	};

	static ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessVariationProperty s_ArkInterferenceMaxBrightnessVariationProperty;
	float m_InterferenceMaxBrightnessVariation;
	
	class ArkInterferenceMinBrightnessProperty : public ArkProperty // Id=8014227 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceMinBrightnessProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceMinBrightnessProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
	};

	static ArkLightDisruptionProfile::ArkInterferenceMinBrightnessProperty s_ArkInterferenceMinBrightnessProperty;
	float m_InterferenceMinBrightness;
	
	class ArkInterferenceMinBrightnessVariationProperty : public ArkProperty // Id=8014228 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceMinBrightnessVariationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A680);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceMinBrightnessVariationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105BA40);
	};

	static ArkLightDisruptionProfile::ArkInterferenceMinBrightnessVariationProperty s_ArkInterferenceMinBrightnessVariationProperty;
	float m_InterferenceMinBrightnessVariation;
	
	class ArkInterferenceSecondaryMinBrightnessProperty : public ArkProperty // Id=8014229 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A690);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessProperty s_ArkInterferenceSecondaryMinBrightnessProperty;
	float m_InterferenceSecondaryMinBrightness;
	
	class ArkInterferenceSecondaryMinBrightnessVariationProperty : public ArkProperty // Id=801422A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessVariationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A6A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessVariationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056FD0);
	};

	static ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessVariationProperty s_ArkInterferenceSecondaryMinBrightnessVariationProperty;
	float m_InterferenceSecondaryMinBrightnessVariation;
	
	class ArkInterferencePrimaryDarkWeightProperty : public ArkProperty // Id=801422B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferencePrimaryDarkWeightProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBDF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferencePrimaryDarkWeightProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10860E0);
	};

	static ArkLightDisruptionProfile::ArkInterferencePrimaryDarkWeightProperty s_ArkInterferencePrimaryDarkWeightProperty;
	float m_InterferencePrimaryDarkWeight;
	
	class ArkInterferenceSecondaryDarkWeightProperty : public ArkProperty // Id=801422C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkWeightProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328A80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkWeightProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328A90);
	};

	static ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkWeightProperty s_ArkInterferenceSecondaryDarkWeightProperty;
	float m_InterferenceSecondaryDarkWeight;
	
	class ArkInterferenceVFXThresholdProperty : public ArkProperty // Id=801422D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLightDisruptionProfile::ArkInterferenceVFXThresholdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328AA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLightDisruptionProfile::ArkInterferenceVFXThresholdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086170);
	};

	static ArkLightDisruptionProfile::ArkInterferenceVFXThresholdProperty s_ArkInterferenceVFXThresholdProperty;
	float m_InterferenceVFXThreshold;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	void ValidateData() { FValidateData(this); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetDisruptionBurstTransitionTime(float arg0);
	const float &GetDisruptionBurstTransitionTime() const;
	void SetDisruptionBurstMultiplier(float arg0);
	const float &GetDisruptionBurstMultiplier() const;
	void SetInterferenceRampIn(float arg0);
	const float &GetInterferenceRampIn() const;
	void SetInterferenceRampInVariation(float arg0);
	const float &GetInterferenceRampInVariation() const;
	void SetInterferenceRampOut(float arg0);
	const float &GetInterferenceRampOut() const;
	void SetInterferenceRampOutVariation(float arg0);
	const float &GetInterferenceRampOutVariation() const;
	void SetInterferenceDarkDuration(float arg0);
	const float &GetInterferenceDarkDuration() const;
	void SetInterferenceDarkDurationVariation(float arg0);
	const float &GetInterferenceDarkDurationVariation() const;
	void SetInterferenceSecondaryDarkDuration(float arg0);
	const float &GetInterferenceSecondaryDarkDuration() const;
	void SetInterferenceSecondaryDarkDurationVariation(float arg0);
	const float &GetInterferenceSecondaryDarkDurationVariation() const;
	void SetInterferenceBrightDuration(float arg0);
	const float &GetInterferenceBrightDuration() const;
	void SetInterferenceBrightDurationVariation(float arg0);
	const float &GetInterferenceBrightDurationVariation() const;
	void SetInterferenceMaxBrightness(float arg0);
	const float &GetInterferenceMaxBrightness() const;
	void SetInterferenceMaxBrightnessVariation(float arg0);
	const float &GetInterferenceMaxBrightnessVariation() const;
	void SetInterferenceMinBrightness(float arg0);
	const float &GetInterferenceMinBrightness() const;
	void SetInterferenceMinBrightnessVariation(float arg0);
	const float &GetInterferenceMinBrightnessVariation() const;
	void SetInterferenceSecondaryMinBrightness(float arg0);
	const float &GetInterferenceSecondaryMinBrightness() const;
	void SetInterferenceSecondaryMinBrightnessVariation(float arg0);
	const float &GetInterferenceSecondaryMinBrightnessVariation() const;
	void SetInterferencePrimaryDarkWeight(float arg0);
	const float &GetInterferencePrimaryDarkWeight() const;
	void SetInterferenceSecondaryDarkWeight(float arg0);
	const float &GetInterferenceSecondaryDarkWeight() const;
	void SetInterferenceVFXThreshold(float arg0);
	const float &GetInterferenceVFXThreshold() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107B4D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107B670);
	static inline auto FValidateData = PreyFunction<void(ArkLightDisruptionProfile *const _this)>(0x107BA40);
};

// Header: Exact
// Prey/Ark/arkpropertyprofile.h
class ArkNagTutorial : public ArkTutorial // Id=801694C Size=64
{
public:
	class ArkDurationProperty : public ArkProperty // Id=801694D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNagTutorial::ArkDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A630);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNagTutorial::ArkDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkNagTutorial::ArkDurationProperty s_ArkDurationProperty;
	float m_Duration;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	void SetDuration(float arg0);
	const float &GetDuration() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1086770);
};

// Header: Exact
// Prey/Ark/arkpropertyprofile.h
class ArkPropertyProfileLibrary : public ArkReflectedLibrary // Id=8016B4E Size=56
{
public:
	class ArkDisruptionProfilesProperty : public ArkProperty // Id=8016B4F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A6B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107A770);
		static inline auto FIsArray = PreyFunction<bool(ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty const *const _this, ArkReflectedObject *_pObject)>(0x107A7B0);
	};

	static ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty s_ArkDisruptionProfilesProperty;
	std::vector<ArkDisruptionProfile> m_DisruptionProfiles;
	
	class ArkLightDisruptionProfilesProperty : public ArkProperty // Id=8016B50 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A850);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107A900);
		static inline auto FIsArray = PreyFunction<bool(ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty const *const _this, ArkReflectedObject *_pObject)>(0x107A580);
	};

	static ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty s_ArkLightDisruptionProfilesProperty;
	std::vector<ArkLightDisruptionProfile> m_LightDisruptionProfiles;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkPropertyProfileLibrary();
	
#if 0
	std::vector<ArkDisruptionProfile> &GetDisruptionProfiles();
	std::vector<ArkDisruptionProfile> const &GetDisruptionProfiles() const;
	std::vector<ArkLightDisruptionProfile> &GetLightDisruptionProfiles();
	std::vector<ArkLightDisruptionProfile> const &GetLightDisruptionProfiles() const;
	ArkDisruptionProfile const *FindDisruptionProfile(const uint64_t arg0) const;
	ArkLightDisruptionProfile const *FindLightDisruptionProfile(const uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107B510);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107B710);
	static inline auto FInit = PreyFunction<bool(ArkPropertyProfileLibrary *const _this)>(0x107B800);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkDisruptionProfile
// Header:  Prey/Ark/arkpropertyprofile.h
class ArkDisruptionProfile : public ArkReflectedObject
{ // Size=72 (0x48)
public:
	// ArkDisruptionProfile::ArkIDProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDisruptionProfile::ArkNameProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkDisruptionProfile::ArkDisruptThresholdProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkDisruptThresholdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisruptThresholdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkDisruptThresholdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkDisruptThresholdProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkDisruptionProfile::ArkDisruptMaxAmountProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkDisruptMaxAmountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisruptMaxAmountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkDisruptMaxAmountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkDisruptMaxAmountProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
	};

	// ArkDisruptionProfile::ArkDisruptDecayRateProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkDisruptDecayRateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisruptDecayRateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkDisruptDecayRateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkDisruptDecayRateProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkDisruptionProfile::ArkDisruptSparkRateProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkDisruptSparkRateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisruptSparkRateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkDisruptSparkRateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkDisruptSparkRateProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
	};

	// ArkDisruptionProfile::ArkDisruptSparkVariationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkDisruptSparkVariationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisruptSparkVariationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkDisruptSparkVariationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkDisruptSparkVariationProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkDisruptionProfile::ArkDisruptSignalProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkDisruptSignalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisruptSignalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkDisruptSignalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkDisruptSignalProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkDisruptionProfile::ArkInterferenceThresholdProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceThresholdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceThresholdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkInterferenceThresholdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1080CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkInterferenceThresholdProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkDisruptionProfile::ArkInterferenceMaxAmountProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceMaxAmountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceMaxAmountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkInterferenceMaxAmountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A2F90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkInterferenceMaxAmountProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3140);
	};

	// ArkDisruptionProfile::ArkInterferenceDecayRateProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceDecayRateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceDecayRateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkInterferenceDecayRateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3150);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkInterferenceDecayRateProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkDisruptionProfile::ArkInterferenceSignalProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceSignalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceSignalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDisruptionProfile::ArkInterferenceSignalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107D510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDisruptionProfile::ArkInterferenceSignalProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkDisruptionProfile::ArkIDProperty>(0x2D27570);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkDisruptionProfile::ArkNameProperty>(0x2D27590);
	string m_Name;
	static inline auto s_ArkDisruptThresholdProperty = PreyGlobal<ArkDisruptionProfile::ArkDisruptThresholdProperty>(0x2D275B0);
	float m_DisruptThreshold;
	static inline auto s_ArkDisruptMaxAmountProperty = PreyGlobal<ArkDisruptionProfile::ArkDisruptMaxAmountProperty>(0x2D275D0);
	float m_DisruptMaxAmount;
	static inline auto s_ArkDisruptDecayRateProperty = PreyGlobal<ArkDisruptionProfile::ArkDisruptDecayRateProperty>(0x2D275F0);
	float m_DisruptDecayRate;
	static inline auto s_ArkDisruptSparkRateProperty = PreyGlobal<ArkDisruptionProfile::ArkDisruptSparkRateProperty>(0x2D27610);
	float m_DisruptSparkRate;
	static inline auto s_ArkDisruptSparkVariationProperty = PreyGlobal<ArkDisruptionProfile::ArkDisruptSparkVariationProperty>(0x2D27630);
	float m_DisruptSparkVariation;
	static inline auto s_ArkDisruptSignalProperty = PreyGlobal<ArkDisruptionProfile::ArkDisruptSignalProperty>(0x2D27650);
	uint64_t m_DisruptSignal;
	static inline auto s_ArkInterferenceThresholdProperty = PreyGlobal<ArkDisruptionProfile::ArkInterferenceThresholdProperty>(0x2D27670);
	float m_InterferenceThreshold;
	static inline auto s_ArkInterferenceMaxAmountProperty = PreyGlobal<ArkDisruptionProfile::ArkInterferenceMaxAmountProperty>(0x2D27690);
	float m_InterferenceMaxAmount;
	static inline auto s_ArkInterferenceDecayRateProperty = PreyGlobal<ArkDisruptionProfile::ArkInterferenceDecayRateProperty>(0x2D276B0);
	float m_InterferenceDecayRate;
	static inline auto s_ArkInterferenceSignalProperty = PreyGlobal<ArkDisruptionProfile::ArkInterferenceSignalProperty>(0x2D276D0);
	uint64_t m_InterferenceSignal;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetDisruptThreshold(float _arg0_);
	const float& GetDisruptThreshold() const;
	void SetDisruptMaxAmount(float _arg0_);
	const float& GetDisruptMaxAmount() const;
	void SetDisruptDecayRate(float _arg0_);
	const float& GetDisruptDecayRate() const;
	void SetDisruptSparkRate(float _arg0_);
	const float& GetDisruptSparkRate() const;
	void SetDisruptSparkVariation(float _arg0_);
	const float& GetDisruptSparkVariation() const;
	void SetDisruptSignal(uint64_t _arg0_);
	const uint64_t& GetDisruptSignal() const;
	void SetInterferenceThreshold(float _arg0_);
	const float& GetInterferenceThreshold() const;
	void SetInterferenceMaxAmount(float _arg0_);
	const float& GetInterferenceMaxAmount() const;
	void SetInterferenceDecayRate(float _arg0_);
	const float& GetInterferenceDecayRate() const;
	void SetInterferenceSignal(uint64_t _arg0_);
	const uint64_t& GetInterferenceSignal() const;
	void ValidateData();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A3C20);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A3D70);
};

// ArkLightDisruptionProfile
// Header:  Prey/Ark/arkpropertyprofile.h
class ArkLightDisruptionProfile : public ArkReflectedObject
{ // Size=104 (0x68)
public:
	// ArkLightDisruptionProfile::ArkIDProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkLightDisruptionProfile::ArkNameProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkLightDisruptionProfile::ArkDisruptionBurstTransitionTimeProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkDisruptionBurstTransitionTimeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisruptionBurstTransitionTimeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkDisruptionBurstTransitionTimeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkDisruptionBurstTransitionTimeProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkLightDisruptionProfile::ArkDisruptionBurstMultiplierProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkDisruptionBurstMultiplierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisruptionBurstMultiplierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkDisruptionBurstMultiplierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkDisruptionBurstMultiplierProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
	};

	// ArkLightDisruptionProfile::ArkInterferenceRampInProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceRampInProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceRampInProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceRampInProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceRampInProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkLightDisruptionProfile::ArkInterferenceRampInVariationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceRampInVariationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceRampInVariationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceRampInVariationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceRampInVariationProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
	};

	// ArkLightDisruptionProfile::ArkInterferenceRampOutProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceRampOutProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceRampOutProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceRampOutProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceRampOutProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkLightDisruptionProfile::ArkInterferenceRampOutVariationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceRampOutVariationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceRampOutVariationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceRampOutVariationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceRampOutVariationProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C370);
	};

	// ArkLightDisruptionProfile::ArkInterferenceDarkDurationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceDarkDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceDarkDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceDarkDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceDarkDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkLightDisruptionProfile::ArkInterferenceDarkDurationVariationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceDarkDurationVariationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceDarkDurationVariationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceDarkDurationVariationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3120);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceDarkDurationVariationProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3130);
	};

	// ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceSecondaryDarkDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceSecondaryDarkDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1080CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationVariationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceSecondaryDarkDurationVariationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceSecondaryDarkDurationVariationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationVariationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A2F90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationVariationProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3140);
	};

	// ArkLightDisruptionProfile::ArkInterferenceBrightDurationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceBrightDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceBrightDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceBrightDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3150);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceBrightDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkLightDisruptionProfile::ArkInterferenceBrightDurationVariationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceBrightDurationVariationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceBrightDurationVariationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceBrightDurationVariationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089EB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceBrightDurationVariationProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3160);
	};

	// ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceMaxBrightnessProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceMaxBrightnessProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084450);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	// ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessVariationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceMaxBrightnessVariationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceMaxBrightnessVariationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessVariationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084460);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessVariationProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3170);
	};

	// ArkLightDisruptionProfile::ArkInterferenceMinBrightnessProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceMinBrightnessProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceMinBrightnessProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceMinBrightnessProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceMinBrightnessProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EE90);
	};

	// ArkLightDisruptionProfile::ArkInterferenceMinBrightnessVariationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceMinBrightnessVariationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceMinBrightnessVariationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceMinBrightnessVariationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceMinBrightnessVariationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084470);
	};

	// ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceSecondaryMinBrightnessProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceSecondaryMinBrightnessProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
	};

	// ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessVariationProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceSecondaryMinBrightnessVariationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceSecondaryMinBrightnessVariationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessVariationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084490);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessVariationProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3190);
	};

	// ArkLightDisruptionProfile::ArkInterferencePrimaryDarkWeightProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferencePrimaryDarkWeightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferencePrimaryDarkWeightProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferencePrimaryDarkWeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A31A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferencePrimaryDarkWeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x10844A0);
	};

	// ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkWeightProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceSecondaryDarkWeightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceSecondaryDarkWeightProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkWeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D69A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkWeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A31B0);
	};

	// ArkLightDisruptionProfile::ArkInterferenceVFXThresholdProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkInterferenceVFXThresholdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInterferenceVFXThresholdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLightDisruptionProfile::ArkInterferenceVFXThresholdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14034E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLightDisruptionProfile::ArkInterferenceVFXThresholdProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B80);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkLightDisruptionProfile::ArkIDProperty>(0x2D276F0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkLightDisruptionProfile::ArkNameProperty>(0x2D27710);
	string m_Name;
	static inline auto s_ArkDisruptionBurstTransitionTimeProperty = PreyGlobal<ArkLightDisruptionProfile::ArkDisruptionBurstTransitionTimeProperty>(0x2D27730);
	float m_DisruptionBurstTransitionTime;
	static inline auto s_ArkDisruptionBurstMultiplierProperty = PreyGlobal<ArkLightDisruptionProfile::ArkDisruptionBurstMultiplierProperty>(0x2D27750);
	float m_DisruptionBurstMultiplier;
	static inline auto s_ArkInterferenceRampInProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceRampInProperty>(0x2D27770);
	float m_InterferenceRampIn;
	static inline auto s_ArkInterferenceRampInVariationProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceRampInVariationProperty>(0x2D27790);
	float m_InterferenceRampInVariation;
	static inline auto s_ArkInterferenceRampOutProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceRampOutProperty>(0x2D277B0);
	float m_InterferenceRampOut;
	static inline auto s_ArkInterferenceRampOutVariationProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceRampOutVariationProperty>(0x2D277D0);
	float m_InterferenceRampOutVariation;
	static inline auto s_ArkInterferenceDarkDurationProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceDarkDurationProperty>(0x2D277F0);
	float m_InterferenceDarkDuration;
	static inline auto s_ArkInterferenceDarkDurationVariationProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceDarkDurationVariationProperty>(0x2D27810);
	float m_InterferenceDarkDurationVariation;
	static inline auto s_ArkInterferenceSecondaryDarkDurationProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationProperty>(0x2D27830);
	float m_InterferenceSecondaryDarkDuration;
	static inline auto s_ArkInterferenceSecondaryDarkDurationVariationProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkDurationVariationProperty>(0x2D27850);
	float m_InterferenceSecondaryDarkDurationVariation;
	static inline auto s_ArkInterferenceBrightDurationProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceBrightDurationProperty>(0x2D27870);
	float m_InterferenceBrightDuration;
	static inline auto s_ArkInterferenceBrightDurationVariationProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceBrightDurationVariationProperty>(0x2D27890);
	float m_InterferenceBrightDurationVariation;
	static inline auto s_ArkInterferenceMaxBrightnessProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessProperty>(0x2D278B0);
	float m_InterferenceMaxBrightness;
	static inline auto s_ArkInterferenceMaxBrightnessVariationProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceMaxBrightnessVariationProperty>(0x2D278D0);
	float m_InterferenceMaxBrightnessVariation;
	static inline auto s_ArkInterferenceMinBrightnessProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceMinBrightnessProperty>(0x2D278F0);
	float m_InterferenceMinBrightness;
	static inline auto s_ArkInterferenceMinBrightnessVariationProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceMinBrightnessVariationProperty>(0x2D27910);
	float m_InterferenceMinBrightnessVariation;
	static inline auto s_ArkInterferenceSecondaryMinBrightnessProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessProperty>(0x2D27930);
	float m_InterferenceSecondaryMinBrightness;
	static inline auto s_ArkInterferenceSecondaryMinBrightnessVariationProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceSecondaryMinBrightnessVariationProperty>(0x2D27950);
	float m_InterferenceSecondaryMinBrightnessVariation;
	static inline auto s_ArkInterferencePrimaryDarkWeightProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferencePrimaryDarkWeightProperty>(0x2D27970);
	float m_InterferencePrimaryDarkWeight;
	static inline auto s_ArkInterferenceSecondaryDarkWeightProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceSecondaryDarkWeightProperty>(0x2D27990);
	float m_InterferenceSecondaryDarkWeight;
	static inline auto s_ArkInterferenceVFXThresholdProperty = PreyGlobal<ArkLightDisruptionProfile::ArkInterferenceVFXThresholdProperty>(0x2D279B0);
	float m_InterferenceVFXThreshold;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	void ValidateData() { FValidateData(this); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetDisruptionBurstTransitionTime(float _arg0_);
	const float& GetDisruptionBurstTransitionTime() const;
	void SetDisruptionBurstMultiplier(float _arg0_);
	const float& GetDisruptionBurstMultiplier() const;
	void SetInterferenceRampIn(float _arg0_);
	const float& GetInterferenceRampIn() const;
	void SetInterferenceRampInVariation(float _arg0_);
	const float& GetInterferenceRampInVariation() const;
	void SetInterferenceRampOut(float _arg0_);
	const float& GetInterferenceRampOut() const;
	void SetInterferenceRampOutVariation(float _arg0_);
	const float& GetInterferenceRampOutVariation() const;
	void SetInterferenceDarkDuration(float _arg0_);
	const float& GetInterferenceDarkDuration() const;
	void SetInterferenceDarkDurationVariation(float _arg0_);
	const float& GetInterferenceDarkDurationVariation() const;
	void SetInterferenceSecondaryDarkDuration(float _arg0_);
	const float& GetInterferenceSecondaryDarkDuration() const;
	void SetInterferenceSecondaryDarkDurationVariation(float _arg0_);
	const float& GetInterferenceSecondaryDarkDurationVariation() const;
	void SetInterferenceBrightDuration(float _arg0_);
	const float& GetInterferenceBrightDuration() const;
	void SetInterferenceBrightDurationVariation(float _arg0_);
	const float& GetInterferenceBrightDurationVariation() const;
	void SetInterferenceMaxBrightness(float _arg0_);
	const float& GetInterferenceMaxBrightness() const;
	void SetInterferenceMaxBrightnessVariation(float _arg0_);
	const float& GetInterferenceMaxBrightnessVariation() const;
	void SetInterferenceMinBrightness(float _arg0_);
	const float& GetInterferenceMinBrightness() const;
	void SetInterferenceMinBrightnessVariation(float _arg0_);
	const float& GetInterferenceMinBrightnessVariation() const;
	void SetInterferenceSecondaryMinBrightness(float _arg0_);
	const float& GetInterferenceSecondaryMinBrightness() const;
	void SetInterferenceSecondaryMinBrightnessVariation(float _arg0_);
	const float& GetInterferenceSecondaryMinBrightnessVariation() const;
	void SetInterferencePrimaryDarkWeight(float _arg0_);
	const float& GetInterferencePrimaryDarkWeight() const;
	void SetInterferenceSecondaryDarkWeight(float _arg0_);
	const float& GetInterferenceSecondaryDarkWeight() const;
	void SetInterferenceVFXThreshold(float _arg0_);
	const float& GetInterferenceVFXThreshold() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A3C70);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A3E10);
	static inline auto FValidateData = PreyFunction<void(ArkLightDisruptionProfile* const _this)>(0x10A41E0);
};

// ArkPropertyProfileLibrary
// Header:  Prey/Ark/arkpropertyprofile.h
class ArkPropertyProfileLibrary : public ArkReflectedLibrary
{ // Size=56 (0x38)
public:
	// ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkDisruptionProfilesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkDisruptionProfilesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A2E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A2ED0);
		static inline auto FIsArray = PreyFunction<bool(const ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty* const _this, ArkReflectedObject* _pObject)>(0x10A2F10);
	};

	// ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty
	// Header:  Prey/Ark/arkpropertyprofile.h
	class ArkLightDisruptionProfilesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkLightDisruptionProfilesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A2FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3050);
		static inline auto FIsArray = PreyFunction<bool(const ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty* const _this, ArkReflectedObject* _pObject)>(0x10A3090);
	};

	static inline auto s_ArkDisruptionProfilesProperty = PreyGlobal<ArkPropertyProfileLibrary::ArkDisruptionProfilesProperty>(0x2D279D0);
	std::vector<ArkDisruptionProfile> m_DisruptionProfiles;
	static inline auto s_ArkLightDisruptionProfilesProperty = PreyGlobal<ArkPropertyProfileLibrary::ArkLightDisruptionProfilesProperty>(0x2D279F0);
	std::vector<ArkLightDisruptionProfile> m_LightDisruptionProfiles;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	std::vector<ArkDisruptionProfile>& GetDisruptionProfiles();
	const std::vector<ArkDisruptionProfile>& GetDisruptionProfiles() const;
	std::vector<ArkLightDisruptionProfile>& GetLightDisruptionProfiles();
	const std::vector<ArkLightDisruptionProfile>& GetLightDisruptionProfiles() const;
	const ArkDisruptionProfile* FindDisruptionProfile(const uint64_t _arg0_) const;
	const ArkLightDisruptionProfile* FindLightDisruptionProfile(const uint64_t _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A3CB0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A3EB0);
	static inline auto FInit = PreyFunction<bool(ArkPropertyProfileLibrary* const _this)>(0x10A3FA0);
};
#endif // !MOONCRASH
