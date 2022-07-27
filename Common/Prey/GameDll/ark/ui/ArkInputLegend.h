// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ui/arkinputlegend.h>

class ArkClass;

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
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkActionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106EF60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputLegendItem::ArkActionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkInputLegendItem::ArkActionProperty s_ArkActionProperty;
	CCryName m_Action;
	
	class ArkActionMapProperty : public ArkProperty // Id=801349D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputLegendItem::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkInputLegendItem::ArkActionMapProperty s_ArkActionMapProperty;
	string m_ActionMap;
	
	class ArkLabelProperty : public ArkProperty // Id=801349E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputLegendItem::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkInputLegendItem::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkHoldProperty : public ArkProperty // Id=801349F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkHoldProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputLegendItem::ArkHoldProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkInputLegendItem::ArkHoldProperty s_ArkHoldProperty;
	bool m_Hold;
	
	class ArkComboStringProperty : public ArkProperty // Id=80134A0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkComboStringProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputLegendItem::ArkComboStringProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkInputLegendItem::ArkComboStringProperty s_ArkComboStringProperty;
	string m_ComboString;
	
	class ArkActionListProperty : public ArkProperty // Id=80134A1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkActionListProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15FBFA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputLegendItem::ArkActionListProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15FC030);
		static inline auto FIsArray = PreyFunction<bool(ArkInputLegendItem::ArkActionListProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkInputLegendItem::ArkActionListProperty const *const _this, ArkReflectedObject *_pObject)>(0x15FC050);
	};

	static ArkInputLegendItem::ArkActionListProperty s_ArkActionListProperty;
	std::vector<ArkInputAction> m_ActionList;
	
	class ArkControlSchemeProperty : public ArkProperty // Id=80134B2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInputLegendItem::ArkControlSchemeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15FBE90);
	};

	static ArkInputLegendItem::ArkControlSchemeProperty s_ArkControlSchemeProperty;
	ArkInputLegendItem::EArkLegendControlScheme m_ControlScheme;
	bool m_enabled;
	wstring m_localizedLabel;
	
	static ArkInputLegendItem::EArkLegendControlScheme GetEnumFromString(const char *_string) { return FGetEnumFromString(_string); }
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetEnabled(const bool arg0);
	bool IsEnabled() const;
	static const char *GetStringFromEnum(ArkInputLegendItem::EArkLegendControlScheme arg0);
	wstring const &GetLocalizedLabel() const;
	void SetLocalizedLabel(wstring const &arg0);
	void SetAction(CCryName arg0);
	CCryName const &GetAction() const;
	void SetActionMap(string arg0);
	string const &GetActionMap() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetHold(bool arg0);
	const bool &GetHold() const;
	void SetComboString(string arg0);
	string const &GetComboString() const;
	std::vector<ArkInputAction> &GetActionList();
	std::vector<ArkInputAction> const &GetActionList() const;
	void SetControlScheme(string arg0);
	ArkInputLegendItem::EArkLegendControlScheme const &GetControlScheme() const;
#endif
	
	static inline auto FGetEnumFromString = PreyFunction<ArkInputLegendItem::EArkLegendControlScheme(const char *_string)>(0x1064B80);
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15FC770);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15FC910);
};

