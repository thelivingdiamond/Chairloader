// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryString/CryName.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkgamemetrics.h
class ArkGameMetricProperties : public ArkReflectedObject // Id=8013BAE Size=40
{
public:
	class ArkIDProperty : public ArkProperty // Id=8013BAF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMetricProperties::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMetricProperties::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkGameMetricProperties::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013BB0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMetricProperties::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1067250);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMetricProperties::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkGameMetricProperties::ArkNameProperty s_ArkNameProperty;
	CCryName m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=8013BB1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMetricProperties::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMetricProperties::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkGameMetricProperties::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkDefaultValueProperty : public ArkProperty // Id=8013BB2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMetricProperties::ArkDefaultValueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMetricProperties::ArkDefaultValueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkGameMetricProperties::ArkDefaultValueProperty s_ArkDefaultValueProperty;
	float m_DefaultValue;
	
	class ArkVisibilityThresholdProperty : public ArkProperty // Id=8013BB3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMetricProperties::ArkVisibilityThresholdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMetricProperties::ArkVisibilityThresholdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkGameMetricProperties::ArkVisibilityThresholdProperty s_ArkVisibilityThresholdProperty;
	float m_VisibilityThreshold;
	
	class ArkHiddenFromUIProperty : public ArkProperty // Id=8013BB4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMetricProperties::ArkHiddenFromUIProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13602F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMetricProperties::ArkHiddenFromUIProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkGameMetricProperties::ArkHiddenFromUIProperty s_ArkHiddenFromUIProperty;
	bool m_HiddenFromUI;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(CCryName arg0);
	CCryName const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetDefaultValue(float arg0);
	const float &GetDefaultValue() const;
	void SetVisibilityThreshold(float arg0);
	const float &GetVisibilityThreshold() const;
	void SetHiddenFromUI(bool arg0);
	const bool &GetHiddenFromUI() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1067AB0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1067C20);
};

// Header: Exact
// Prey/Ark/arkgamemetrics.h
class ArkGameMetricLibrary : public ArkReflectedLibrary // Id=8013BC2 Size=32
{
public:
	class ArkMetricsProperty : public ArkProperty // Id=8013BC3 Size=32
	{
	public:
		ArkMetricsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameMetricLibrary::ArkMetricsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1067100);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameMetricLibrary::ArkMetricsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10671D0);
		static inline auto FIsArray = PreyFunction<bool(ArkGameMetricLibrary::ArkMetricsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkGameMetricLibrary::ArkMetricsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1067210);
	};

	static ArkGameMetricLibrary::ArkMetricsProperty s_ArkMetricsProperty;
	std::vector<ArkGameMetricProperties> m_Metrics;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	boost::optional<ArkGameMetricProperties const &> Find(const uint64_t _id) const { return FFind(this,_id); }
	
#if 0
	std::vector<ArkGameMetricProperties> &GetMetrics();
	std::vector<ArkGameMetricProperties> const &GetMetrics() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1067A50);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1067B30);
	static inline auto FInit = PreyFunction<bool(ArkGameMetricLibrary *const _this)>(0x1067CC0);
	static inline auto FFind = PreyFunction<boost::optional<ArkGameMetricProperties const &>(ArkGameMetricLibrary const *const _this, const uint64_t _id)>(0x1067AF0);
};

