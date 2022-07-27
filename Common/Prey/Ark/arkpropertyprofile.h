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

