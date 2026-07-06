// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>
#include <Prey/Ark/arkgamenoise.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/ui/arkinputlegend.h
class ArkInputLegendItem : public ArkReflectedObject // Id=801349B Size=80
{
public:
	enum class EArkLegendControlScheme
	{
		all = 0,
		keyboard = 1,
		controller = 2,
		last = 3,
	};

	class ArkActionProperty : public ArkProperty // Id=801349C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkActionProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x106EF60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkActionProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	static ArkInputLegendItem::ArkActionProperty s_ArkActionProperty;
	CCryName m_Action;

	class ArkActionMapProperty : public ArkProperty // Id=801349D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkActionMapProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkActionMapProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	static ArkInputLegendItem::ArkActionMapProperty s_ArkActionMapProperty;
	string m_ActionMap;

	class ArkLabelProperty : public ArkProperty // Id=801349E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkLabelProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkLabelProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	static ArkInputLegendItem::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;

	class ArkHoldProperty : public ArkProperty // Id=801349F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkHoldProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10821A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkHoldProperty const* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	static ArkInputLegendItem::ArkHoldProperty s_ArkHoldProperty;
	bool m_Hold;

	class ArkComboStringProperty : public ArkProperty // Id=80134A0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkComboStringProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkComboStringProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	static ArkInputLegendItem::ArkComboStringProperty s_ArkComboStringProperty;
	string m_ComboString;

	class ArkActionListProperty : public ArkProperty // Id=80134A1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkActionListProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x15FBFA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkActionListProperty const* const _this, ArkReflectedObject* const _pObject)>(0x15FC030);
		static inline auto FIsArray = PreyFunction<bool(ArkInputLegendItem::ArkActionListProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkInputLegendItem::ArkActionListProperty const* const _this, ArkReflectedObject* _pObject)>(0x15FC050);
	};

	static ArkInputLegendItem::ArkActionListProperty s_ArkActionListProperty;
	std::vector<ArkInputAction> m_ActionList;

	class ArkControlSchemeProperty : public ArkProperty // Id=80134B2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;

		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkControlSchemeProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x15FBE90);
	};

	static ArkInputLegendItem::ArkControlSchemeProperty s_ArkControlSchemeProperty;
	ArkInputLegendItem::EArkLegendControlScheme m_ControlScheme;
	bool m_enabled;
	wstring m_localizedLabel;

	static ArkInputLegendItem::EArkLegendControlScheme GetEnumFromString(const char* _string) { return FGetEnumFromString(_string); }
	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetEnabled(const bool arg0);
	bool IsEnabled() const;
	static const char* GetStringFromEnum(ArkInputLegendItem::EArkLegendControlScheme arg0);
	wstring const& GetLocalizedLabel() const;
	void SetLocalizedLabel(wstring const& arg0);
	void SetAction(CCryName arg0);
	CCryName const& GetAction() const;
	void SetActionMap(string arg0);
	string const& GetActionMap() const;
	void SetLabel(string arg0);
	string const& GetLabel() const;
	void SetHold(bool arg0);
	const bool& GetHold() const;
	void SetComboString(string arg0);
	string const& GetComboString() const;
	std::vector<ArkInputAction>& GetActionList();
	std::vector<ArkInputAction> const& GetActionList() const;
	void SetControlScheme(string arg0);
	ArkInputLegendItem::EArkLegendControlScheme const& GetControlScheme() const;
#endif

	static inline auto FGetEnumFromString = PreyFunction<ArkInputLegendItem::EArkLegendControlScheme(const char* _string)>(0x1064B80);
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15FC770);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15FC910);
};

// Header: Exact
// Prey/GameDll/ark/ui/ArkInputLegend.h
class ArkInputLegend : public ArkReflectedObject // Id=801349A Size=32
{
public:
	class ArkActionMapProperty : public ArkProperty // Id=80134B3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInputLegend::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputLegend::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkInputLegend::ArkActionMapProperty s_ArkActionMapProperty;
	string m_ActionMap;
	
	class ArkItemsProperty : public ArkProperty // Id=80134B4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInputLegend::ArkItemsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15FBEE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputLegend::ArkItemsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15FBF20);
		static inline auto FIsArray = PreyFunction<bool(ArkInputLegend::ArkItemsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkInputLegend::ArkItemsProperty const *const _this, ArkReflectedObject *_pObject)>(0x15FBF40);
	};

	static ArkInputLegend::ArkItemsProperty s_ArkItemsProperty;
	std::vector<ArkInputLegendItem> m_Items;
	
	ArkInputLegend();
	void ClearItems() { FClearItems(this); }
	void SetActionEnabled(CCryName const &_actionId, bool _bEnabled) { FSetActionEnabled(this,_actionId,_bEnabled); }
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	bool IsEmpty() const;
	void AddItem(ArkInputLegendItem const &arg0);
	void SetActionMap(string arg0);
	string const &GetActionMap() const;
	std::vector<ArkInputLegendItem> &GetItems();
	std::vector<ArkInputLegendItem> const &GetItems() const;
#endif
	
	static inline auto FClearItems = PreyFunction<void(ArkInputLegend *const _this)>(0x1566100);
	static inline auto FSetActionEnabled = PreyFunction<void(ArkInputLegend *const _this, CCryName const &_actionId, bool _bEnabled)>(0x15FC9B0);
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15FC6B0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15FC870);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>

class ArkClass;
class IArkValueBase;

// ArkInputAction
// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
class ArkInputAction : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkInputAction::ArkActionProperty
	// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
	class ArkActionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkActionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInputAction::ArkActionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1093030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputAction::ArkActionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkInputAction::ArkActionMapProperty
	// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
	class ArkActionMapProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkActionMapProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInputAction::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputAction::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	static inline auto s_ArkActionProperty = PreyGlobal<ArkInputAction::ArkActionProperty>(0x2D80130);
	CCryName m_Action;
	static inline auto s_ArkActionMapProperty = PreyGlobal<ArkInputAction::ArkActionMapProperty>(0x2D80150);
	string m_ActionMap;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetAction(CCryName _arg0_);
	const CCryName& GetAction() const;
	void SetActionMap(string _arg0_);
	const string& GetActionMap() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x171D1A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x171D2F0);
};

// ArkInputLegendItem
// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
class ArkInputLegendItem : public ArkReflectedObject
{ // Size=80 (0x50)
public:
	enum class EArkLegendControlScheme
	{
		all = 0,
		keyboard = 1,
		controller = 2,
		last = 3,
	};

	// ArkInputLegendItem::ArkActionProperty
	// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
	class ArkActionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkActionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkActionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1093030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkActionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkInputLegendItem::ArkActionMapProperty
	// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
	class ArkActionMapProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkActionMapProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkInputLegendItem::ArkLabelProperty
	// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkInputLegendItem::ArkHoldProperty
	// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
	class ArkHoldProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHoldProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkHoldProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkHoldProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkInputLegendItem::ArkComboStringProperty
	// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
	class ArkComboStringProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkComboStringProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkComboStringProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkComboStringProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkInputLegendItem::ArkActionListProperty
	// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
	class ArkActionListProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkActionListProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkActionListProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x171C920);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkActionListProperty* const _this, ArkReflectedObject* const _pObject)>(0x171C9B0);
		static inline auto FIsArray = PreyFunction<bool(const ArkInputLegendItem::ArkActionListProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkInputLegendItem::ArkActionListProperty* const _this, ArkReflectedObject* _pObject)>(0x171C9D0);
	};

	// ArkInputLegendItem::ArkControlSchemeProperty
	// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
	class ArkControlSchemeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkControlSchemeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkControlSchemeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x171CA00);
	};

	static inline auto s_ArkActionProperty = PreyGlobal<ArkInputLegendItem::ArkActionProperty>(0x2D80170);
	CCryName m_Action;
	static inline auto s_ArkActionMapProperty = PreyGlobal<ArkInputLegendItem::ArkActionMapProperty>(0x2D80190);
	string m_ActionMap;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkInputLegendItem::ArkLabelProperty>(0x2D801B0);
	string m_Label;
	static inline auto s_ArkHoldProperty = PreyGlobal<ArkInputLegendItem::ArkHoldProperty>(0x2D801D0);
	bool m_Hold;
	static inline auto s_ArkComboStringProperty = PreyGlobal<ArkInputLegendItem::ArkComboStringProperty>(0x2D801F0);
	string m_ComboString;
	static inline auto s_ArkActionListProperty = PreyGlobal<ArkInputLegendItem::ArkActionListProperty>(0x2D80210);
	std::vector<ArkInputAction> m_ActionList;
	static inline auto s_ArkControlSchemeProperty = PreyGlobal<ArkInputLegendItem::ArkControlSchemeProperty>(0x2D80230);
	ArkInputLegendItem::EArkLegendControlScheme m_ControlScheme;
	bool m_enabled;
	wstring m_localizedLabel;

	static ArkInputLegendItem::EArkLegendControlScheme GetEnumFromString(const char* _string) { return FGetEnumFromString(_string); }
	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkInputLegendItem();
	ArkInputLegendItem(const CCryName& _arg0_, const char* const _arg1_, ArkInputLegendItem::EArkLegendControlScheme _arg2_);
	void SetEnabled(const bool _arg0_);
	bool IsEnabled() const;
	static const char* GetStringFromEnum(ArkInputLegendItem::EArkLegendControlScheme _arg0_);
	const wstring& GetLocalizedLabel() const;
	void SetLocalizedLabel(const wstring& _arg0_);
	void SetAction(CCryName _arg0_);
	const CCryName& GetAction() const;
	void SetActionMap(string _arg0_);
	const string& GetActionMap() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetHold(bool _arg0_);
	const bool& GetHold() const;
	void SetComboString(string _arg0_);
	const string& GetComboString() const;
	std::vector<ArkInputAction>& GetActionList();
	const std::vector<ArkInputAction>& GetActionList() const;
	void SetControlScheme(string _arg0_);
	const ArkInputLegendItem::EArkLegendControlScheme& GetControlScheme() const;
#endif

	static inline auto FGetEnumFromString = PreyFunction<ArkInputLegendItem::EArkLegendControlScheme(const char* _string)>(0x1087A50);
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x171D290);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x171D430);
};

// ArkInputLegend
// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
class ArkInputLegend : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkInputLegend::ArkActionMapProperty
	// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
	class ArkActionMapProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkActionMapProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInputLegend::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegend::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkInputLegend::ArkItemsProperty
	// Header:  Prey/GameDll/ark/ui/ArkInputLegend.h
	class ArkItemsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkItemsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkInputLegend::ArkItemsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x171CA50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegend::ArkItemsProperty* const _this, ArkReflectedObject* const _pObject)>(0x171CA90);
		static inline auto FIsArray = PreyFunction<bool(const ArkInputLegend::ArkItemsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkInputLegend::ArkItemsProperty* const _this, ArkReflectedObject* _pObject)>(0x171CAB0);
	};

	static inline auto s_ArkActionMapProperty = PreyGlobal<ArkInputLegend::ArkActionMapProperty>(0x2D80250);
	string m_ActionMap;
	static inline auto s_ArkItemsProperty = PreyGlobal<ArkInputLegend::ArkItemsProperty>(0x2D80270);
	std::vector<ArkInputLegendItem> m_Items;

	ArkInputLegend();
	void ClearItems() { FClearItems(this); }
	void SetActionEnabled(const CCryName& _actionId, bool _bEnabled) { FSetActionEnabled(this, _actionId, _bEnabled); }
	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	bool IsEmpty() const;
	void AddItem(const ArkInputLegendItem& _arg0_);
	void SetActionMap(string _arg0_);
	const string& GetActionMap() const;
	std::vector<ArkInputLegendItem>& GetItems();
	const std::vector<ArkInputLegendItem>& GetItems() const;
#endif

	static inline auto FArkInputLegendOv2 = PreyFunction<void(ArkInputLegend* const _this)>(0x12C28D0);
	static inline auto FClearItems = PreyFunction<void(ArkInputLegend* const _this)>(0x168C110);
	static inline auto FSetActionEnabled = PreyFunction<void(ArkInputLegend* const _this, const CCryName& _actionId, bool _bEnabled)>(0x171D4D0);
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x171D1D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x171D390);
};
#endif // !MOONCRASH
