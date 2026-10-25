// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>
#include <Prey/Ark/arkgamenoise.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/ui/arkinputlegend.h
#ifdef MOONCRASH
#include <Prey/CryString/CryString.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
class IArkValueBase;
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkActionProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x106EF60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkActionProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkActionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1093030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkActionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkInputLegendItem::ArkActionProperty s_ArkActionProperty;
#else
	static inline auto s_ArkActionProperty = PreyGlobal<ArkInputLegendItem::ArkActionProperty>(0x2D80170);
#endif
	CCryName m_Action;

	class ArkActionMapProperty : public ArkProperty // Id=801349D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkActionMapProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkActionMapProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkInputLegendItem::ArkActionMapProperty s_ArkActionMapProperty;
#else
	static inline auto s_ArkActionMapProperty = PreyGlobal<ArkInputLegendItem::ArkActionMapProperty>(0x2D80190);
#endif
	string m_ActionMap;

	class ArkLabelProperty : public ArkProperty // Id=801349E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkLabelProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkLabelProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

#ifndef MOONCRASH
	static ArkInputLegendItem::ArkLabelProperty s_ArkLabelProperty;
#else
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkInputLegendItem::ArkLabelProperty>(0x2D801B0);
#endif
	string m_Label;

	class ArkHoldProperty : public ArkProperty // Id=801349F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkHoldProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10821A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkHoldProperty const* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkHoldProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkHoldProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
	};

#ifndef MOONCRASH
	static ArkInputLegendItem::ArkHoldProperty s_ArkHoldProperty;
#else
	static inline auto s_ArkHoldProperty = PreyGlobal<ArkInputLegendItem::ArkHoldProperty>(0x2D801D0);
#endif
	bool m_Hold;

	class ArkComboStringProperty : public ArkProperty // Id=80134A0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkComboStringProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkComboStringProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkComboStringProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkComboStringProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
#endif
	};

#ifndef MOONCRASH
	static ArkInputLegendItem::ArkComboStringProperty s_ArkComboStringProperty;
#else
	static inline auto s_ArkComboStringProperty = PreyGlobal<ArkInputLegendItem::ArkComboStringProperty>(0x2D801F0);
#endif
	string m_ComboString;

	class ArkActionListProperty : public ArkProperty // Id=80134A1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkActionListProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x15FBFA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkInputLegendItem::ArkActionListProperty const* const _this, ArkReflectedObject* const _pObject)>(0x15FC030);
		static inline auto FIsArray = PreyFunction<bool(ArkInputLegendItem::ArkActionListProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkInputLegendItem::ArkActionListProperty const* const _this, ArkReflectedObject* _pObject)>(0x15FC050);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkActionListProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x171C920);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegendItem::ArkActionListProperty* const _this, ArkReflectedObject* const _pObject)>(0x171C9B0);
		static inline auto FIsArray = PreyFunction<bool(const ArkInputLegendItem::ArkActionListProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkInputLegendItem::ArkActionListProperty* const _this, ArkReflectedObject* _pObject)>(0x171C9D0);
#endif
	};

#ifndef MOONCRASH
	static ArkInputLegendItem::ArkActionListProperty s_ArkActionListProperty;
#else
	static inline auto s_ArkActionListProperty = PreyGlobal<ArkInputLegendItem::ArkActionListProperty>(0x2D80210);
#endif
	std::vector<ArkInputAction> m_ActionList;

	class ArkControlSchemeProperty : public ArkProperty // Id=80134B2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkControlSchemeProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x15FBE90);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkInputLegendItem::ArkControlSchemeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x171CA00);
#endif
	};

#ifndef MOONCRASH
	static ArkInputLegendItem::ArkControlSchemeProperty s_ArkControlSchemeProperty;
#else
	static inline auto s_ArkControlSchemeProperty = PreyGlobal<ArkInputLegendItem::ArkControlSchemeProperty>(0x2D80230);
#endif
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

#ifndef MOONCRASH
	static inline auto FGetEnumFromString = PreyFunction<ArkInputLegendItem::EArkLegendControlScheme(const char* _string)>(0x1064B80);
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15FC770);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15FC910);
#else
	static inline auto FGetEnumFromString = PreyFunction<ArkInputLegendItem::EArkLegendControlScheme(const char* _string)>(0x1087A50);
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x171D290);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x171D430);
#endif
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
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkInputLegend::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputLegend::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkInputLegend::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegend::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkInputLegend::ArkActionMapProperty s_ArkActionMapProperty;
#else
	static inline auto s_ArkActionMapProperty = PreyGlobal<ArkInputLegend::ArkActionMapProperty>(0x2D80250);
#endif
	string m_ActionMap;
	
	class ArkItemsProperty : public ArkProperty // Id=80134B4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkInputLegend::ArkItemsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15FBEE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputLegend::ArkItemsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15FBF20);
		static inline auto FIsArray = PreyFunction<bool(ArkInputLegend::ArkItemsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkInputLegend::ArkItemsProperty const *const _this, ArkReflectedObject *_pObject)>(0x15FBF40);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkInputLegend::ArkItemsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x171CA50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputLegend::ArkItemsProperty* const _this, ArkReflectedObject* const _pObject)>(0x171CA90);
		static inline auto FIsArray = PreyFunction<bool(const ArkInputLegend::ArkItemsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkInputLegend::ArkItemsProperty* const _this, ArkReflectedObject* _pObject)>(0x171CAB0);
#endif
	};

#ifndef MOONCRASH
	static ArkInputLegend::ArkItemsProperty s_ArkItemsProperty;
#else
	static inline auto s_ArkItemsProperty = PreyGlobal<ArkInputLegend::ArkItemsProperty>(0x2D80270);
#endif
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
	
#ifndef MOONCRASH
	static inline auto FClearItems = PreyFunction<void(ArkInputLegend *const _this)>(0x1566100);
	static inline auto FSetActionEnabled = PreyFunction<void(ArkInputLegend *const _this, CCryName const &_actionId, bool _bEnabled)>(0x15FC9B0);
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15FC6B0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15FC870);
#else
	static inline auto FArkInputLegendOv2 = PreyFunction<void(ArkInputLegend* const _this)>(0x12C28D0);
	static inline auto FClearItems = PreyFunction<void(ArkInputLegend* const _this)>(0x168C110);
	static inline auto FSetActionEnabled = PreyFunction<void(ArkInputLegend* const _this, const CCryName& _actionId, bool _bEnabled)>(0x171D4D0);
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x171D1D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x171D390);
#endif
};
