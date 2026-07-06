// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
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
	virtual ~ArkGameMetricLibrary();
	
#if 0
	std::vector<ArkGameMetricProperties> &GetMetrics();
	std::vector<ArkGameMetricProperties> const &GetMetrics() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1067A50);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1067B30);
	static inline auto FInit = PreyFunction<bool(ArkGameMetricLibrary *const _this)>(0x1067CC0);
	static inline auto FFind = PreyFunction<boost::optional<ArkGameMetricProperties const &>(ArkGameMetricLibrary const *const _this, const uint64_t _id)>(0x1067AF0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>

class ArkClass;
class IArkValueBase;

// ArkGameMetricProperties
// Header:  Prey/Ark/arkgamemetrics.h
class ArkGameMetricProperties : public ArkReflectedObject
{ // Size=48 (0x30)
public:
	// ArkGameMetricProperties::ArkIDProperty
	// Header:  Prey/Ark/arkgamemetrics.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricProperties::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricProperties::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkGameMetricProperties::ArkNameProperty
	// Header:  Prey/Ark/arkgamemetrics.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricProperties::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricProperties::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkGameMetricProperties::ArkLabelProperty
	// Header:  Prey/Ark/arkgamemetrics.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricProperties::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricProperties::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkGameMetricProperties::ArkDefaultValueProperty
	// Header:  Prey/Ark/arkgamemetrics.h
	class ArkDefaultValueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultValueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricProperties::ArkDefaultValueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricProperties::ArkDefaultValueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkGameMetricProperties::ArkVisibilityThresholdProperty
	// Header:  Prey/Ark/arkgamemetrics.h
	class ArkVisibilityThresholdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkVisibilityThresholdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricProperties::ArkVisibilityThresholdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricProperties::ArkVisibilityThresholdProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
	};

	// ArkGameMetricProperties::ArkHiddenFromUIProperty
	// Header:  Prey/Ark/arkgamemetrics.h
	class ArkHiddenFromUIProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHiddenFromUIProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricProperties::ArkHiddenFromUIProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084750);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricProperties::ArkHiddenFromUIProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkGameMetricProperties::ArkCryptoValueProperty
	// Header:  Prey/Ark/arkgamemetrics.h
	class ArkCryptoValueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCryptoValueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricProperties::ArkCryptoValueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricProperties::ArkCryptoValueProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C370);
	};

	// ArkGameMetricProperties::ArkNonLinearCryptoProperty
	// Header:  Prey/Ark/arkgamemetrics.h
	class ArkNonLinearCryptoProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNonLinearCryptoProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricProperties::ArkNonLinearCryptoProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricProperties::ArkNonLinearCryptoProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkGameMetricProperties::ArkResetWithSimulationProperty
	// Header:  Prey/Ark/arkgamemetrics.h
	class ArkResetWithSimulationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkResetWithSimulationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricProperties::ArkResetWithSimulationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084760);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricProperties::ArkResetWithSimulationProperty* const _this, ArkReflectedObject* const _pObject)>(0x108B5E0);
	};

	// ArkGameMetricProperties::ArkApplyDoomCryptoMultiplierProperty
	// Header:  Prey/Ark/arkgamemetrics.h
	class ArkApplyDoomCryptoMultiplierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkApplyDoomCryptoMultiplierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricProperties::ArkApplyDoomCryptoMultiplierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108B5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricProperties::ArkApplyDoomCryptoMultiplierProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084770);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkGameMetricProperties::ArkIDProperty>(0x2D241C0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkGameMetricProperties::ArkNameProperty>(0x2D241E0);
	CCryName m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkGameMetricProperties::ArkLabelProperty>(0x2D24200);
	string m_Label;
	static inline auto s_ArkDefaultValueProperty = PreyGlobal<ArkGameMetricProperties::ArkDefaultValueProperty>(0x2D24220);
	float m_DefaultValue;
	static inline auto s_ArkVisibilityThresholdProperty = PreyGlobal<ArkGameMetricProperties::ArkVisibilityThresholdProperty>(0x2D24240);
	float m_VisibilityThreshold;
	static inline auto s_ArkHiddenFromUIProperty = PreyGlobal<ArkGameMetricProperties::ArkHiddenFromUIProperty>(0x2D24260);
	bool m_HiddenFromUI;
	static inline auto s_ArkCryptoValueProperty = PreyGlobal<ArkGameMetricProperties::ArkCryptoValueProperty>(0x2D24280);
	float m_CryptoValue;
	static inline auto s_ArkNonLinearCryptoProperty = PreyGlobal<ArkGameMetricProperties::ArkNonLinearCryptoProperty>(0x2D242A0);
	bool m_NonLinearCrypto;
	static inline auto s_ArkResetWithSimulationProperty = PreyGlobal<ArkGameMetricProperties::ArkResetWithSimulationProperty>(0x2D242C0);
	bool m_ResetWithSimulation;
	static inline auto s_ArkApplyDoomCryptoMultiplierProperty = PreyGlobal<ArkGameMetricProperties::ArkApplyDoomCryptoMultiplierProperty>(0x2D242E0);
	bool m_ApplyDoomCryptoMultiplier;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(CCryName _arg0_);
	const CCryName& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetDefaultValue(float _arg0_);
	const float& GetDefaultValue() const;
	void SetVisibilityThreshold(float _arg0_);
	const float& GetVisibilityThreshold() const;
	void SetHiddenFromUI(bool _arg0_);
	const bool& GetHiddenFromUI() const;
	void SetCryptoValue(float _arg0_);
	const float& GetCryptoValue() const;
	void SetNonLinearCrypto(bool _arg0_);
	const bool& GetNonLinearCrypto() const;
	void SetResetWithSimulation(bool _arg0_);
	const bool& GetResetWithSimulation() const;
	void SetApplyDoomCryptoMultiplier(bool _arg0_);
	const bool& GetApplyDoomCryptoMultiplier() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108BF90);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108C100);
};

// ArkGameMetricLibrary
// Header:  Prey/Ark/arkgamemetrics.h
class ArkGameMetricLibrary : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkGameMetricLibrary::ArkMetricsProperty
	// Header:  Prey/Ark/arkgamemetrics.h
	class ArkMetricsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkMetricsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkMetricsPropertyOv2 = PreyFunction<void(ArkGameMetricLibrary::ArkMetricsProperty* const _this)>(0x108BC50);
		static inline auto FSetValue = PreyFunction<void(const ArkGameMetricLibrary::ArkMetricsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108B600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameMetricLibrary::ArkMetricsProperty* const _this, ArkReflectedObject* const _pObject)>(0x108B6F0);
		static inline auto FIsArray = PreyFunction<bool(const ArkGameMetricLibrary::ArkMetricsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkGameMetricLibrary::ArkMetricsProperty* const _this, ArkReflectedObject* _pObject)>(0x108B730);
	};

	static inline auto s_ArkMetricsProperty = PreyGlobal<ArkGameMetricLibrary::ArkMetricsProperty>(0x2D24300);
	std::vector<ArkGameMetricProperties> m_Metrics;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	boost::optional<ArkGameMetricProperties const &> Find(const uint64_t _id) const { alignas(boost::optional<ArkGameMetricProperties const &>) std::byte _return_buf_[sizeof(boost::optional<ArkGameMetricProperties const &>)]; return *FFind(this, reinterpret_cast<boost::optional<ArkGameMetricProperties const &>*>(_return_buf_), _id); }

#if 0
	std::vector<ArkGameMetricProperties>& GetMetrics();
	const std::vector<ArkGameMetricProperties>& GetMetrics() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108BF30);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x108C010);
	static inline auto FInit = PreyFunction<bool(ArkGameMetricLibrary* const _this)>(0x108C1A0);
	static inline auto FFind = PreyFunction<boost::optional<ArkGameMetricProperties const &>*(const ArkGameMetricLibrary* const _this, boost::optional<ArkGameMetricProperties const &>* _return_value_, const uint64_t _id)>(0x108BFD0);
};
#endif // !MOONCRASH
