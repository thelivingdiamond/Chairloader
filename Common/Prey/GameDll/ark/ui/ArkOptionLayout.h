// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/ui/ArkOptionDropDownBase.h>
#include <Prey/GameDll/ark/ui/ArkOptionDropDownBase.h>

class ArkClass;
class ArkOptionMenu;

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
#ifdef MOONCRASH
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/CryString/CryName.h>
class IArkValueBase;
class DistractionEvent;
class ArkOptionSubAction;
class ArkOption;
class ArkOptionWidgetBase;
class ArkOptionAttribute;
class ArkOptionLayoutSubPage;
class ArkOptionLayoutPage;
class ArkOptionSlider;
class ArkOptionList;
class ArkOptionDataList;
class ArkOptionButton;
class ArkOptionControlMap;
class ArkDifficultyOption;
class ArkOptionToggle;
class ArkOptionLayout;
class ArkOptionDropDownBase;
class ArkOptionDropDown;
class ArkOptionMonitor;
class ArkOptionResolution;
class ArkOptionLanguageBase;
class ArkOptionAudioLanguage;
class ArkOptionTextLanguage;
#endif
class DistractionEvent : public ArkReflectedObject // Id=8013AB3 Size=8
{
public:
	class ArkEventProperty : public ArkProperty // Id=8013AB4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(DistractionEvent::ArkEventProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionEvent::ArkEventProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const DistractionEvent::ArkEventProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const DistractionEvent::ArkEventProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static DistractionEvent::ArkEventProperty s_ArkEventProperty;
#else
	static inline auto s_ArkEventProperty = PreyGlobal<DistractionEvent::ArkEventProperty>(0x2D22CE0);
#endif
	string m_Event;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	void SetEvent(string arg0);
	string const &GetEvent() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13644E0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107ABF0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionSubAction : public ArkReflectedObject // Id=801B967 Size=8
{
public:
	class ArkActionProperty : public ArkProperty // Id=801B968 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionSubAction::ArkActionProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionSubAction::ArkActionProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionSubAction::ArkActionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionSubAction::ArkActionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionSubAction::ArkActionProperty s_ArkActionProperty;
#else
	static inline auto s_ArkActionProperty = PreyGlobal<ArkOptionSubAction::ArkActionProperty>(0x2D55CE8);
#endif
	string m_Action;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetAction(string arg0);
	string const& GetAction() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13644E0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107ABF0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOption : public ArkReflectedObject // Id=801B9A1 Size=56
{
public:
	class ArkLabelProperty : public ArkProperty // Id=801B9A2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOption::ArkLabelProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1360300);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOption::ArkLabelProperty const* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOption::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOption::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
#endif
	};

#ifndef MOONCRASH
	static ArkOption::ArkLabelProperty s_ArkLabelProperty;
#else
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkOption::ArkLabelProperty>(0x2D55D08);
#endif
	string m_Label;

	class ArkValueProperty : public ArkProperty // Id=801B9A3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOption::ArkValueProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1360380);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOption::ArkValueProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1068E60);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOption::ArkValueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108A000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOption::ArkValueProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9CA0);
#endif
	};

#ifndef MOONCRASH
	static ArkOption::ArkValueProperty s_ArkValueProperty;
#else
	static inline auto s_ArkValueProperty = PreyGlobal<ArkOption::ArkValueProperty>(0x2D55D28);
#endif
	string m_Value;

	class ArkHiddenProperty : public ArkProperty // Id=801B9A4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOption::ArkHiddenProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1360430);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOption::ArkHiddenProperty const* const _this, ArkReflectedObject* const _pObject)>(0x15A6360);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOption::ArkHiddenProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443A10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOption::ArkHiddenProperty* const _this, ArkReflectedObject* const _pObject)>(0x108A0C0);
#endif
	};

#ifndef MOONCRASH
	static ArkOption::ArkHiddenProperty s_ArkHiddenProperty;
#else
	static inline auto s_ArkHiddenProperty = PreyGlobal<ArkOption::ArkHiddenProperty>(0x2D55D48);
#endif
	bool m_Hidden;

	class ArkSubactionsProperty : public ArkProperty // Id=801B9A5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOption::ArkSubactionsProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13604E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOption::ArkSubactionsProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1360540);
		static inline auto FIsArray = PreyFunction<bool(ArkOption::ArkSubactionsProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOption::ArkSubactionsProperty const* const _this, ArkReflectedObject* _pObject)>(0x1360580);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOption::ArkSubactionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443BA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOption::ArkSubactionsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1443C90);
		static inline auto FIsArray = PreyFunction<bool(const ArkOption::ArkSubactionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkOption::ArkSubactionsProperty* const _this, ArkReflectedObject* _pObject)>(0x1443D40);
#endif
	};

#ifndef MOONCRASH
	static ArkOption::ArkSubactionsProperty s_ArkSubactionsProperty;
#else
	static inline auto s_ArkSubactionsProperty = PreyGlobal<ArkOption::ArkSubactionsProperty>(0x2D55D68);
#endif
	std::vector<ArkOptionSubAction> m_Subactions;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool IsHidden() const;

#if 0
	void SetLabel(string arg0);
	string const& GetLabel() const;
	void SetValue(string arg0);
	string const& GetValue() const;
	void SetHidden(bool arg0);
	const bool& GetHidden() const;
	std::vector<ArkOptionSubAction>& GetSubactions();
	std::vector<ArkOptionSubAction> const& GetSubactions() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1364060);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1364930);
	static inline auto FIsHidden = PreyFunction<bool(ArkOption const* const _this)>(0x1141F10);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447BA0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x14483A0);
	static inline auto FIsHidden = PreyFunction<bool(const ArkOption* const _this)>(0x9EDD80);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionWidgetBase : public ArkReflectedObject // Id=801B976 Size=8
{
public:
	enum class EArkOptionWidgetType
	{
		none = 0,
		list = 1,
		slider = 2,
		datalist = 3,
		command = 4,
		toggle = 5,
		dropdown = 6,
		controlMap = 7,
	};

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	virtual bool IsAvailable();

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1364630);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13650B0);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionWidgetBase const* const _this)>(0x158AEF0);
	static inline auto FIsAvailable = PreyFunction<bool(ArkOptionWidgetBase* const _this)>(0x1B933B0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1448140);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1448B20);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(const ArkOptionWidgetBase* const _this)>(0x1CBB0B0);
	static inline auto FIsAvailable = PreyFunction<bool(ArkOptionWidgetBase* const _this)>(0x1A302A0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionAttribute : public ArkReflectedObject // Id=801B958 Size=88
{
public:
	class ArkActionProperty : public ArkProperty // Id=801B959 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkActionProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkActionProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkActionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkActionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkActionProperty s_ArkActionProperty;
#else
	static inline auto s_ArkActionProperty = PreyGlobal<ArkOptionAttribute::ArkActionProperty>(0x2D55F48);
#endif
	string m_Action;

	class ArkLabelProperty : public ArkProperty // Id=801B95A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkLabelProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkLabelProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkLabelProperty s_ArkLabelProperty;
#else
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkOptionAttribute::ArkLabelProperty>(0x2D55F68);
#endif
	string m_Label;

	class ArkSetOnChangeProperty : public ArkProperty // Id=801B95B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkSetOnChangeProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1360190);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkSetOnChangeProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkSetOnChangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkSetOnChangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkSetOnChangeProperty s_ArkSetOnChangeProperty;
#else
	static inline auto s_ArkSetOnChangeProperty = PreyGlobal<ArkOptionAttribute::ArkSetOnChangeProperty>(0x2D55F88);
#endif
	bool m_SetOnChange;

	class ArkHideOnFrontendProperty : public ArkProperty // Id=801B95C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideOnFrontendProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1061620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkHideOnFrontendProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1061630);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkHideOnFrontendProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14437D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkHideOnFrontendProperty* const _this, ArkReflectedObject* const _pObject)>(0x14437E0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkHideOnFrontendProperty s_ArkHideOnFrontendProperty;
#else
	static inline auto s_ArkHideOnFrontendProperty = PreyGlobal<ArkOptionAttribute::ArkHideOnFrontendProperty>(0x2D55FC8);
#endif
	bool m_HideOnFrontend;

	class ArkHideInGameProperty : public ArkProperty // Id=801B95D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideInGameProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13602B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkHideInGameProperty const* const _this, ArkReflectedObject* const _pObject)>(0x13602C0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkHideInGameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443900);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkHideInGameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1443910);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkHideInGameProperty s_ArkHideInGameProperty;
#else
	static inline auto s_ArkHideInGameProperty = PreyGlobal<ArkOptionAttribute::ArkHideInGameProperty>(0x2D55FE8);
#endif
	bool m_HideInGame;

	class ArkCloseMenuProperty : public ArkProperty // Id=801B95E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkCloseMenuProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13602D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkCloseMenuProperty const* const _this, ArkReflectedObject* const _pObject)>(0x13602E0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkCloseMenuProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443920);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkCloseMenuProperty* const _this, ArkReflectedObject* const _pObject)>(0x1443930);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkCloseMenuProperty s_ArkCloseMenuProperty;
#else
	static inline auto s_ArkCloseMenuProperty = PreyGlobal<ArkOptionAttribute::ArkCloseMenuProperty>(0x2D55FA8);
#endif
	bool m_CloseMenu;

	class ArkDefaultProperty : public ArkProperty // Id=801B95F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkDefaultProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkDefaultProperty const* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkDefaultProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkDefaultProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkDefaultProperty s_ArkDefaultProperty;
#else
	static inline auto s_ArkDefaultProperty = PreyGlobal<ArkOptionAttribute::ArkDefaultProperty>(0x2D56008);
#endif
	string m_Default;

	class ArkHideFromProfileProperty : public ArkProperty // Id=801B960 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideFromProfileProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13602F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkHideFromProfileProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkHideFromProfileProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084750);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkHideFromProfileProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkHideFromProfileProperty s_ArkHideFromProfileProperty;
#else
	static inline auto s_ArkHideFromProfileProperty = PreyGlobal<ArkOptionAttribute::ArkHideFromProfileProperty>(0x2D56088);
#endif
	bool m_HideFromProfile;

	class ArkHiddenProperty : public ArkProperty // Id=801B961 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHiddenProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1360360);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkHiddenProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1360370);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkHiddenProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1075BE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkHiddenProperty* const _this, ArkReflectedObject* const _pObject)>(0x1075BF0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkHiddenProperty s_ArkHiddenProperty;
#else
	static inline auto s_ArkHiddenProperty = PreyGlobal<ArkOptionAttribute::ArkHiddenProperty>(0x2D560A8);
#endif
	bool m_Hidden;

	class ArkPlatformProperty : public ArkProperty // Id=801B962 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkPlatformProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13603E0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkPlatformProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443940);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkPlatformProperty s_ArkPlatformProperty;
#else
	static inline auto s_ArkPlatformProperty = PreyGlobal<ArkOptionAttribute::ArkPlatformProperty>(0x2D56028);
#endif
	EArkOptionPlatform m_Platform;

	class ArkSubactionsProperty : public ArkProperty // Id=801B963 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkSubactionsProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1360450);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkSubactionsProperty const* const _this, ArkReflectedObject* const _pObject)>(0x13604B0);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionAttribute::ArkSubactionsProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionAttribute::ArkSubactionsProperty const* const _this, ArkReflectedObject* _pObject)>(0x13604D0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkSubactionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443990);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkSubactionsProperty* const _this, ArkReflectedObject* const _pObject)>(0x14439F0);
		static inline auto FIsArray = PreyFunction<bool(const ArkOptionAttribute::ArkSubactionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkOptionAttribute::ArkSubactionsProperty* const _this, ArkReflectedObject* _pObject)>(0x1443A30);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkSubactionsProperty s_ArkSubactionsProperty;
#else
	static inline auto s_ArkSubactionsProperty = PreyGlobal<ArkOptionAttribute::ArkSubactionsProperty>(0x2D56068);
#endif
	std::vector<ArkOptionSubAction> m_Subactions;

	class ArkWidgetProperty : public ArkProperty // Id=801B973 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkWidgetProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1360700);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkWidgetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443C00);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkWidgetProperty s_ArkWidgetProperty;
#else
	static inline auto s_ArkWidgetProperty = PreyGlobal<ArkOptionAttribute::ArkWidgetProperty>(0x2D56048);
#endif
	std::shared_ptr<ArkOptionWidgetBase> m_pWidget;

	class ArkWaitForTextureReloadProperty : public ArkProperty // Id=801B978 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkWaitForTextureReloadProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13D4CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkWaitForTextureReloadProperty const* const _this, ArkReflectedObject* const _pObject)>(0x12FBDE0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkWaitForTextureReloadProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443D70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkWaitForTextureReloadProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkWaitForTextureReloadProperty s_ArkWaitForTextureReloadProperty;
#else
	static inline auto s_ArkWaitForTextureReloadProperty = PreyGlobal<ArkOptionAttribute::ArkWaitForTextureReloadProperty>(0x2D560C8);
#endif
	bool m_WaitForTextureReload;

	class ArkWriteConfigFileProperty : public ArkProperty // Id=801B979 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkWriteConfigFileProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x135FAA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkWriteConfigFileProperty const* const _this, ArkReflectedObject* const _pObject)>(0x135FAB0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkWriteConfigFileProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443D80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkWriteConfigFileProperty* const _this, ArkReflectedObject* const _pObject)>(0x1443D90);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkWriteConfigFileProperty s_ArkWriteConfigFileProperty;
#else
	static inline auto s_ArkWriteConfigFileProperty = PreyGlobal<ArkOptionAttribute::ArkWriteConfigFileProperty>(0x2D560E8);
#endif
	bool m_WriteConfigFile;

	class ArkHideForSteamControllerProperty : public ArkProperty // Id=801B97A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideForSteamControllerProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x135FAC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkHideForSteamControllerProperty const* const _this, ArkReflectedObject* const _pObject)>(0x135FAD0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkHideForSteamControllerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443DA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkHideForSteamControllerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1443DB0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkHideForSteamControllerProperty s_ArkHideForSteamControllerProperty;
#else
	static inline auto s_ArkHideForSteamControllerProperty = PreyGlobal<ArkOptionAttribute::ArkHideForSteamControllerProperty>(0x2D56108);
#endif
	bool m_HideForSteamController;

	class ArkHideOnQuasimodoProperty : public ArkProperty // Id=801B97B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideOnQuasimodoProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x135FAE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkHideOnQuasimodoProperty const* const _this, ArkReflectedObject* const _pObject)>(0x135FAF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkHideOnQuasimodoProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkHideOnQuasimodoProperty* const _this, ArkReflectedObject* const _pObject)>(0x1443DD0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkHideOnQuasimodoProperty s_ArkHideOnQuasimodoProperty;
#else
	static inline auto s_ArkHideOnQuasimodoProperty = PreyGlobal<ArkOptionAttribute::ArkHideOnQuasimodoProperty>(0x2D56128);
#endif
	bool m_HideOnQuasimodo;

	class ArkHideOnPCProperty : public ArkProperty // Id=801B97C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideOnPCProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1056FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionAttribute::ArkHideOnPCProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1056FD0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionAttribute::ArkHideOnPCProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443DE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionAttribute::ArkHideOnPCProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3190);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionAttribute::ArkHideOnPCProperty s_ArkHideOnPCProperty;
#else
	static inline auto s_ArkHideOnPCProperty = PreyGlobal<ArkOptionAttribute::ArkHideOnPCProperty>(0x2D56148);
#endif
	bool m_HideOnPC;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	static EArkOptionPlatform GetEnumFromString(const char* _string) { return FGetEnumFromString(_string); }
	bool IsAvailable(EArkOptionPlatform _platform, const bool _bLevelLoaded) const { return FIsAvailable(this, _platform, _bLevelLoaded); }
#ifndef MOONCRASH
	std::pair<string, CCryName> GetActionAsKeyBind() const { return FGetActionAsKeyBindOv1(this); }
#else
	std::pair<string, CCryName> GetActionAsKeyBind() const { alignas(std::pair<string, CCryName>) std::byte _return_buf_[sizeof(std::pair<string, CCryName>)]; return *FGetActionAsKeyBindOv1(this, reinterpret_cast<std::pair<string, CCryName>*>(_return_buf_)); }
#endif
	static std::pair<string, CCryName> GetActionAsKeyBind(string const& _action) { return FGetActionAsKeyBindOv0(_action); }

#if 0
	void SetAction(string arg0);
	string const& GetAction() const;
	void SetLabel(string arg0);
	string const& GetLabel() const;
	void SetSetOnChange(bool arg0);
	const bool& GetSetOnChange() const;
	void SetHideOnFrontend(bool arg0);
	const bool& GetHideOnFrontend() const;
	void SetHideInGame(bool arg0);
	const bool& GetHideInGame() const;
	void SetCloseMenu(bool arg0);
	const bool& GetCloseMenu() const;
	void SetDefault(string arg0);
	string const& GetDefault() const;
	void SetHideFromProfile(bool arg0);
	const bool& GetHideFromProfile() const;
	void SetHidden(bool arg0);
	const bool& GetHidden() const;
	void SetPlatform(string arg0);
	EArkOptionPlatform const& GetPlatform() const;
	std::vector<ArkOptionSubAction>& GetSubactions();
	std::vector<ArkOptionSubAction> const& GetSubactions() const;
	void SetWidget(ArkReflectedObject* arg0);
	ArkOptionWidgetBase* GetWidget();
	ArkOptionWidgetBase const* GetWidget() const;
	void SetWaitForTextureReload(bool arg0);
	const bool& GetWaitForTextureReload() const;
	void SetWriteConfigFile(bool arg0);
	const bool& GetWriteConfigFile() const;
	void SetHideForSteamController(bool arg0);
	const bool& GetHideForSteamController() const;
	void SetHideOnQuasimodo(bool arg0);
	const bool& GetHideOnQuasimodo() const;
	void SetHideOnPC(bool arg0);
	const bool& GetHideOnPC() const;
	static const char* GetStringFromEnum(EArkOptionPlatform arg0);
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13640D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13649D0);
	static inline auto FGetEnumFromString = PreyFunction<EArkOptionPlatform(const char* _string)>(0x1365150);
	static inline auto FIsAvailable = PreyFunction<bool(ArkOptionAttribute const* const _this, EArkOptionPlatform _platform, const bool _bLevelLoaded)>(0x1365600);
	static inline auto FGetActionAsKeyBindOv1 = PreyFunction<std::pair<string, CCryName>(ArkOptionAttribute const* const _this)>(0x1364680);
	static inline auto FGetActionAsKeyBindOv0 = PreyFunction<std::pair<string, CCryName>(string const& _action)>(0x13646A0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447C10);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1448440);
	static inline auto FGetEnumFromString = PreyFunction<EArkOptionPlatform(const char* _string)>(0x1448BC0);
	static inline auto FIsAvailable = PreyFunction<bool(const ArkOptionAttribute* const _this, const EArkOptionPlatform _platform, const bool _bLevelLoaded)>(0x1449070);
	static inline auto FGetActionAsKeyBindOv1 = PreyFunction<std::pair<string, CCryName>*(const ArkOptionAttribute* const _this, std::pair<string, CCryName>* _return_value_)>(0x1448190);
	static inline auto FGetActionAsKeyBindOv0 = PreyFunction<std::pair<string, CCryName>(const string& _action)>(0x14481B0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionLayoutSubPage : public ArkReflectedObject // Id=801B951 Size=64
{
public:
	class ArkLabelProperty : public ArkProperty // Id=801B952 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkLabelProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionLayoutSubPage::ArkLabelProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionLayoutSubPage::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionLayoutSubPage::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionLayoutSubPage::ArkLabelProperty s_ArkLabelProperty;
#else
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkOptionLayoutSubPage::ArkLabelProperty>(0x2D56168);
#endif
	string m_Label;

	class ArkLabelPS4Property : public ArkProperty // Id=801B953 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkLabelPS4Property const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionLayoutSubPage::ArkLabelPS4Property const* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionLayoutSubPage::ArkLabelPS4Property* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionLayoutSubPage::ArkLabelPS4Property* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionLayoutSubPage::ArkLabelPS4Property s_ArkLabelPS4Property;
#else
	static inline auto s_ArkLabelPS4Property = PreyGlobal<ArkOptionLayoutSubPage::ArkLabelPS4Property>(0x2D56188);
#endif
	string m_LabelPS4;

	class ArkAttributesProperty : public ArkProperty // Id=801B954 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkAttributesProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x135FCE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionLayoutSubPage::ArkAttributesProperty const* const _this, ArkReflectedObject* const _pObject)>(0x135FD20);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionLayoutSubPage::ArkAttributesProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionLayoutSubPage::ArkAttributesProperty const* const _this, ArkReflectedObject* _pObject)>(0x135FD40);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionLayoutSubPage::ArkAttributesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionLayoutSubPage::ArkAttributesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1443FA0);
		static inline auto FIsArray = PreyFunction<bool(const ArkOptionLayoutSubPage::ArkAttributesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkOptionLayoutSubPage::ArkAttributesProperty* const _this, ArkReflectedObject* _pObject)>(0x1443FC0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionLayoutSubPage::ArkAttributesProperty s_ArkAttributesProperty;
#else
	static inline auto s_ArkAttributesProperty = PreyGlobal<ArkOptionLayoutSubPage::ArkAttributesProperty>(0x2D561A8);
#endif
	std::vector<ArkOptionAttribute> m_Attributes;

	class ArkKeybindsProperty : public ArkProperty // Id=801B988 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkKeybindsProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13600A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionLayoutSubPage::ArkKeybindsProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionLayoutSubPage::ArkKeybindsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionLayoutSubPage::ArkKeybindsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionLayoutSubPage::ArkKeybindsProperty s_ArkKeybindsProperty;
#else
	static inline auto s_ArkKeybindsProperty = PreyGlobal<ArkOptionLayoutSubPage::ArkKeybindsProperty>(0x2D561C8);
#endif
	bool m_Keybinds;

	class ArkPlatformProperty : public ArkProperty // Id=801B989 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkPlatformProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13600B0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionLayoutSubPage::ArkPlatformProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14436C0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionLayoutSubPage::ArkPlatformProperty s_ArkPlatformProperty;
#else
	static inline auto s_ArkPlatformProperty = PreyGlobal<ArkOptionLayoutSubPage::ArkPlatformProperty>(0x2D561E8);
#endif
	EArkOptionPlatform m_Platform;

	class ArkWriteConfigFileProperty : public ArkProperty // Id=801B98A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkWriteConfigFileProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1360100);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionLayoutSubPage::ArkWriteConfigFileProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionLayoutSubPage::ArkWriteConfigFileProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1073710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionLayoutSubPage::ArkWriteConfigFileProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionLayoutSubPage::ArkWriteConfigFileProperty s_ArkWriteConfigFileProperty;
#else
	static inline auto s_ArkWriteConfigFileProperty = PreyGlobal<ArkOptionLayoutSubPage::ArkWriteConfigFileProperty>(0x2D56208);
#endif
	bool m_WriteConfigFile;

	class ArkRequiresApplyProperty : public ArkProperty // Id=801B98B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkRequiresApplyProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1056F50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionLayoutSubPage::ArkRequiresApplyProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1056F60);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionLayoutSubPage::ArkRequiresApplyProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1073720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionLayoutSubPage::ArkRequiresApplyProperty* const _this, ArkReflectedObject* const _pObject)>(0x1073730);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionLayoutSubPage::ArkRequiresApplyProperty s_ArkRequiresApplyProperty;
#else
	static inline auto s_ArkRequiresApplyProperty = PreyGlobal<ArkOptionLayoutSubPage::ArkRequiresApplyProperty>(0x2D56228);
#endif
	bool m_RequiresApply;

	class ArkWarningProperty : public ArkProperty // Id=801B98C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkWarningProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkOptionLayoutSubPage::ArkWarningProperty const* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionLayoutSubPage::ArkWarningProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionLayoutSubPage::ArkWarningProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionLayoutSubPage::ArkWarningProperty s_ArkWarningProperty;
#else
	static inline auto s_ArkWarningProperty = PreyGlobal<ArkOptionLayoutSubPage::ArkWarningProperty>(0x2D56248);
#endif
	string m_Warning;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	const char* GetPlatformLabel() const { return FGetPlatformLabel(this); }

#if 0
	void SetLabel(string arg0);
	string const& GetLabel() const;
	void SetLabelPS4(string arg0);
	string const& GetLabelPS4() const;
	std::vector<ArkOptionAttribute>& GetAttributes();
	std::vector<ArkOptionAttribute> const& GetAttributes() const;
	void SetKeybinds(bool arg0);
	const bool& GetKeybinds() const;
	void SetPlatform(string arg0);
	EArkOptionPlatform const& GetPlatform() const;
	void SetWriteConfigFile(bool arg0);
	const bool& GetWriteConfigFile() const;
	void SetRequiresApply(bool arg0);
	const bool& GetRequiresApply() const;
	void SetWarning(string arg0);
	string const& GetWarning() const;
	bool IsAvailable(EArkOptionPlatform arg0) const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1364320);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1364CF0);
	static inline auto FGetPlatformLabel = PreyFunction<const char* (ArkOptionLayoutSubPage const* const _this)>(0x12E5E70);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447E60);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1448760);
	static inline auto FGetPlatformLabel = PreyFunction<const char* (const ArkOptionLayoutSubPage* const _this)>(0x1112EA0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionLayoutPage : public ArkReflectedObject // Id=801B94B Size=32
{
public:
	class ArkLabelProperty : public ArkProperty // Id=801B94C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutPage::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayoutPage::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionLayoutPage::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionLayoutPage::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionLayoutPage::ArkLabelProperty s_ArkLabelProperty;
#else
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkOptionLayoutPage::ArkLabelProperty>(0x2D56268);
#endif
	string m_Label;
	
	class ArkSubPagesProperty : public ArkProperty // Id=801B94D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutPage::ArkSubPagesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13601A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayoutPage::ArkSubPagesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360230);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionLayoutPage::ArkSubPagesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionLayoutPage::ArkSubPagesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1360250);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionLayoutPage::ArkSubPagesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14437F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionLayoutPage::ArkSubPagesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1443880);
		static inline auto FIsArray = PreyFunction<bool(const ArkOptionLayoutPage::ArkSubPagesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkOptionLayoutPage::ArkSubPagesProperty* const _this, ArkReflectedObject* _pObject)>(0x14438A0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionLayoutPage::ArkSubPagesProperty s_ArkSubPagesProperty;
#else
	static inline auto s_ArkSubPagesProperty = PreyGlobal<ArkOptionLayoutPage::ArkSubPagesProperty>(0x2D56288);
#endif
	std::vector<ArkOptionLayoutSubPage> m_SubPages;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetLabel(string arg0);
	string const &GetLabel() const;
	std::vector<ArkOptionLayoutSubPage> &GetSubPages();
	std::vector<ArkOptionLayoutSubPage> const &GetSubPages() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10714D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364C50);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x119EF00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x14486C0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionSlider : public ArkOptionWidgetBase // Id=801B997 Size=32
{
public:
	class ArkMinProperty : public ArkProperty // Id=801B998 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionSlider::ArkMinProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionSlider::ArkMinProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionSlider::ArkMinProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D2F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionSlider::ArkMinProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionSlider::ArkMinProperty s_ArkMinProperty;
#else
	static inline auto s_ArkMinProperty = PreyGlobal<ArkOptionSlider::ArkMinProperty>(0x2D55E08);
#endif
	float m_Min;
	
	class ArkMaxProperty : public ArkProperty // Id=801B999 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionSlider::ArkMaxProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionSlider::ArkMaxProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6320);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionSlider::ArkMaxProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C1F30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionSlider::ArkMaxProperty* const _this, ArkReflectedObject* const _pObject)>(0x1444320);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionSlider::ArkMaxProperty s_ArkMaxProperty;
#else
	static inline auto s_ArkMaxProperty = PreyGlobal<ArkOptionSlider::ArkMaxProperty>(0x2D55E28);
#endif
	float m_Max;
	
	class ArkDecimalsProperty : public ArkProperty // Id=801B99A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionSlider::ArkDecimalsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068E40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionSlider::ArkDecimalsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionSlider::ArkDecimalsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C1F50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionSlider::ArkDecimalsProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9CA0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionSlider::ArkDecimalsProperty s_ArkDecimalsProperty;
#else
	static inline auto s_ArkDecimalsProperty = PreyGlobal<ArkOptionSlider::ArkDecimalsProperty>(0x2D55E48);
#endif
	int m_Decimals;
	
	class ArkUnitProperty : public ArkProperty // Id=801B99B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionSlider::ArkUnitProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221AE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionSlider::ArkUnitProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221B00);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionSlider::ArkUnitProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionSlider::ArkUnitProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C1F70);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionSlider::ArkUnitProperty s_ArkUnitProperty;
#else
	static inline auto s_ArkUnitProperty = PreyGlobal<ArkOptionSlider::ArkUnitProperty>(0x2D55E68);
#endif
	float m_Unit;
	
	class ArkNormalizeProperty : public ArkProperty // Id=801B99C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionSlider::ArkNormalizeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360430);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionSlider::ArkNormalizeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6360);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionSlider::ArkNormalizeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443A10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionSlider::ArkNormalizeProperty* const _this, ArkReflectedObject* const _pObject)>(0x108A0C0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionSlider::ArkNormalizeProperty s_ArkNormalizeProperty;
#else
	static inline auto s_ArkNormalizeProperty = PreyGlobal<ArkOptionSlider::ArkNormalizeProperty>(0x2D55E88);
#endif
	bool m_Normalize;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	
#if 0
	void SetMin(float arg0);
	const float &GetMin() const;
	void SetMax(float arg0);
	const float &GetMax() const;
	void SetDecimals(int arg0);
	const int &GetDecimals() const;
	void SetUnit(float arg0);
	const float &GetUnit() const;
	void SetNormalize(bool arg0);
	const bool &GetNormalize() const;
	float GetRange() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364480);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364ED0);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionSlider const *const _this)>(0x1A42CE0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447FC0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1448940);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(const ArkOptionSlider* const _this)>(0x4FD7F0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionList : public ArkOptionWidgetBase // Id=801B9D8 Size=32
{
public:
	class ArkOptionsProperty : public ArkProperty // Id=801B9D9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionList::ArkOptionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FDA0);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionList::ArkOptionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionList::ArkOptionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x135FE00);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionList::ArkOptionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1444020);
		static inline auto FIsArray = PreyFunction<bool(const ArkOptionList::ArkOptionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkOptionList::ArkOptionsProperty* const _this, ArkReflectedObject* _pObject)>(0x1444080);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionList::ArkOptionsProperty s_ArkOptionsProperty;
#else
	static inline auto s_ArkOptionsProperty = PreyGlobal<ArkOptionList::ArkOptionsProperty>(0x2D55DC8);
#endif
	std::vector<std::shared_ptr<ArkOption>> m_Options;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	
#if 0
	static ArkClass *GetClass();
	std::vector<std::shared_ptr<ArkOption>> &GetOptions();
	std::vector<std::shared_ptr<ArkOption>> const &GetOptions() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364370);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionList const *const _this)>(0x1B1DEA0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447EB0);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(const ArkOptionList* const _this)>(0x1948930);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionDataList : public ArkOptionWidgetBase // Id=801B9E5 Size=40
{
public:
	class ArkPathProperty : public ArkProperty // Id=801B9E6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionDataList::ArkPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360300);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionDataList::ArkPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionDataList::ArkPathProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionDataList::ArkPathProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionDataList::ArkPathProperty s_ArkPathProperty;
#else
	static inline auto s_ArkPathProperty = PreyGlobal<ArkOptionDataList::ArkPathProperty>(0x2D55EA8);
#endif
	string m_Path;
	
	class ArkXPathProperty : public ArkProperty // Id=801B9E7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionDataList::ArkXPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360380);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionDataList::ArkXPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionDataList::ArkXPathProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108A000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionDataList::ArkXPathProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9CA0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionDataList::ArkXPathProperty s_ArkXPathProperty;
#else
	static inline auto s_ArkXPathProperty = PreyGlobal<ArkOptionDataList::ArkXPathProperty>(0x2D55EC8);
#endif
	string m_XPath;
	
	class ArkIDProperty : public ArkProperty // Id=801B9E8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionDataList::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10660B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionDataList::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6360);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionDataList::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108A060);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionDataList::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x108A0C0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionDataList::ArkIDProperty s_ArkIDProperty;
#else
	static inline auto s_ArkIDProperty = PreyGlobal<ArkOptionDataList::ArkIDProperty>(0x2D55EE8);
#endif
	string m_ID;
	
	class ArkLabelProperty : public ArkProperty // Id=801B9E9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionDataList::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionDataList::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360170);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionDataList::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionDataList::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C1FF0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionDataList::ArkLabelProperty s_ArkLabelProperty;
#else
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkOptionDataList::ArkLabelProperty>(0x2D55F08);
#endif
	string m_Label;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	
#if 0
	void SetPath(string arg0);
	string const &GetPath() const;
	void SetXPath(string arg0);
	string const &GetXPath() const;
	void SetID(string arg0);
	string const &GetID() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364260);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364BB0);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionDataList const *const _this)>(0xC36440);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447DA0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1448620);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(const ArkOptionDataList* const _this)>(0x1C657B0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionButton : public ArkOptionWidgetBase // Id=801B9EA Size=16
{
public:
	class ArkMenuProperty : public ArkProperty // Id=801B9EB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionButton::ArkMenuProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360300);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionButton::ArkMenuProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionButton::ArkMenuProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionButton::ArkMenuProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionButton::ArkMenuProperty s_ArkMenuProperty;
#else
	static inline auto s_ArkMenuProperty = PreyGlobal<ArkOptionButton::ArkMenuProperty>(0x2D55F28);
#endif
	string m_Menu;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	
#if 0
	static ArkClass *GetClass();
	void SetMenu(string arg0);
	string const &GetMenu() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13641C0);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionButton const *const _this)>(0x13F8580);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447D00);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(const ArkOptionButton* const _this)>(0x1A2FA50);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionControlMap : public ArkOptionWidgetBase // Id=801B9EC Size=8
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364210);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364B10);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionControlMap const *const _this)>(0x15A4FC0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447D50);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1448580);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(const ArkOptionControlMap* const _this)>(0xA72AA0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
#ifndef MOONCRASH
class ArkDifficultyOption : public ArkOption // Id=801B9C7 Size=56
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool IsHidden() const;
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1363FF0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364890);
	static inline auto FIsHidden = PreyFunction<bool(ArkDifficultyOption const *const _this)>(0x13656B0);
};
#endif

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionToggle : public ArkOptionWidgetBase // Id=801B9E2 Size=120
{
public:
	class ArkOption0Property : public ArkProperty // Id=801B9E3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionToggle::ArkOption0Property const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FE40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionToggle::ArkOption0Property const *const _this, ArkReflectedObject *const _pObject)>(0x1068990);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionToggle::ArkOption0Property* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14440C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionToggle::ArkOption0Property* const _this, ArkReflectedObject* const _pObject)>(0x14441D0);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionToggle::ArkOption0Property s_ArkOption0Property;
#else
	static inline auto s_ArkOption0Property = PreyGlobal<ArkOptionToggle::ArkOption0Property>(0x2D55D88);
#endif
	ArkOption m_Option0;
	
	class ArkOption1Property : public ArkProperty // Id=801B9E4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionToggle::ArkOption1Property const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FF50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionToggle::ArkOption1Property const *const _this, ArkReflectedObject *const _pObject)>(0x1360060);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionToggle::ArkOption1Property* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14441F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionToggle::ArkOption1Property* const _this, ArkReflectedObject* const _pObject)>(0x1444300);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionToggle::ArkOption1Property s_ArkOption1Property;
#else
	static inline auto s_ArkOption1Property = PreyGlobal<ArkOptionToggle::ArkOption1Property>(0x2D55DA8);
#endif
	ArkOption m_Option1;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	
#if 0
	void SetOption0(ArkOption arg0);
	ArkOption const &GetOption0() const;
	void SetOption1(ArkOption arg0);
	ArkOption const &GetOption1() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364590);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1365010);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionToggle const *const _this)>(0x133DF50);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x14480A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1448A80);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(const ArkOptionToggle* const _this)>(0x141A3D0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/ArkOptionLayout.h
class ArkOptionLayout : public ArkReflectedObject // Id=801B9B6 Size=24
{
public:
	class ArkPagesProperty : public ArkProperty // Id=801B9B7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayout::ArkPagesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FB70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayout::ArkPagesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x135FBE0);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionLayout::ArkPagesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionLayout::ArkPagesProperty const *const _this, ArkReflectedObject *_pObject)>(0x135FC00);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionLayout::ArkPagesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443DF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionLayout::ArkPagesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1443E60);
		static inline auto FIsArray = PreyFunction<bool(const ArkOptionLayout::ArkPagesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkOptionLayout::ArkPagesProperty* const _this, ArkReflectedObject* _pObject)>(0x1443E80);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionLayout::ArkPagesProperty s_ArkPagesProperty;
#else
	static inline auto s_ArkPagesProperty = PreyGlobal<ArkOptionLayout::ArkPagesProperty>(0x2D562A8);
#endif
	std::vector<ArkOptionLayoutPage> m_Pages;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	std::vector<ArkOptionLayoutPage> &GetPages();
	std::vector<ArkOptionLayoutPage> const &GetPages() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x16140D0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1077160);
#endif
};

// Header: Override
// Prey/GameDll/ark/ui/ArkOptionDropDownBase.h
class ArkOptionDropDownBase : public ArkOptionWidgetBase // Id=801B99D Size=8
{
public:
	virtual std::vector<ArkOption>& GetDropDownOptions() = 0;
	virtual std::vector<ArkOption> const& GetDropDownOptions() const = 0;
	virtual int GetSelectedIndex(const char* const arg0) const = 0;
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	virtual bool RequiresConfirmation() const;
	virtual void RefreshOptions(ArkOptionMenu const& _optionMenu);
	virtual bool MustRefreshResolutions() const;

#ifndef MOONCRASH
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionDropDownBase const* const _this)>(0x1C4890);
	static inline auto FRequiresConfirmation = PreyFunction<bool(ArkOptionDropDownBase const* const _this)>(0x1B933B0);
	static inline auto FRefreshOptions = PreyFunction<void(ArkOptionDropDownBase* const _this, ArkOptionMenu const& _optionMenu)>(0xA13080);
	static inline auto FMustRefreshResolutions = PreyFunction<bool(ArkOptionDropDownBase const* const _this)>(0xDD23F0);
#else
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(const ArkOptionDropDownBase* const _this)>(0x14B6CE0);
	static inline auto FRequiresConfirmation = PreyFunction<bool(const ArkOptionDropDownBase* const _this)>(0x1A302A0);
	static inline auto FRefreshOptions = PreyFunction<void(ArkOptionDropDownBase* const _this, const ArkOptionMenu& _optionMenu)>(0x1333E90);
	static inline auto FMustRefreshResolutions = PreyFunction<bool(const ArkOptionDropDownBase* const _this)>(0x13B0900);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionDropDown : public ArkOptionDropDownBase // Id=801B9DA Size=32
{
public:
	class ArkOptionsProperty : public ArkProperty // Id=801B9DB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkOptionDropDown::ArkOptionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13605A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionDropDown::ArkOptionsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360670);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionDropDown::ArkOptionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionDropDown::ArkOptionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x13606C0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkOptionDropDown::ArkOptionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443A40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkOptionDropDown::ArkOptionsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1443B10);
		static inline auto FIsArray = PreyFunction<bool(const ArkOptionDropDown::ArkOptionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkOptionDropDown::ArkOptionsProperty* const _this, ArkReflectedObject* _pObject)>(0x1443B60);
#endif
	};

#ifndef MOONCRASH
	static ArkOptionDropDown::ArkOptionsProperty s_ArkOptionsProperty;
#else
	static inline auto s_ArkOptionsProperty = PreyGlobal<ArkOptionDropDown::ArkOptionsProperty>(0x2D55DE8);
#endif
	std::vector<ArkOption> m_Options;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual std::vector<ArkOption> &GetDropDownOptions();
	virtual std::vector<ArkOption> const &GetDropDownOptions() const;
	virtual int GetSelectedIndex(const char *const _cvarName) const;
	
#if 0
	static ArkClass *GetClass();
	std::vector<ArkOption> &GetOptions();
	std::vector<ArkOption> const &GetOptions() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13642C0);
	static inline auto FGetDropDownOptionsOv1 = PreyFunction<std::vector<ArkOption> &(ArkOptionDropDown *const _this)>(0x5EE7A0);
	static inline auto FGetDropDownOptionsOv0 = PreyFunction<std::vector<ArkOption> const &(ArkOptionDropDown const *const _this)>(0x5EE7A0);
	static inline auto FGetSelectedIndex = PreyFunction<int(ArkOptionDropDown const *const _this, const char *const _cvarName)>(0x13652B0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447E00);
	static inline auto FGetDropDownOptionsOv1 = PreyFunction<std::vector<ArkOption>& (ArkOptionDropDown* const _this)>(0x133BA60);
	static inline auto FGetDropDownOptionsOv0 = PreyFunction<const std::vector<ArkOption>& (const ArkOptionDropDown* const _this)>(0x133BA60);
	static inline auto FGetSelectedIndex = PreyFunction<int(const ArkOptionDropDown* const _this, const char* const _cvarName)>(0x1448D20);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionMonitor : public ArkOptionDropDown // Id=801B9DD Size=32
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	ArkOptionMonitor();
	virtual bool MustRefreshResolutions() const;
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13643D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364D90);
	static inline auto FMustRefreshResolutions = PreyFunction<bool(ArkOptionMonitor const *const _this)>(0x1B933B0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447F10);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1448800);
	static inline auto FArkOptionMonitorOv2 = PreyFunction<void(ArkOptionMonitor* const _this)>(0x1447710);
	static inline auto FMustRefreshResolutions = PreyFunction<bool(const ArkOptionMonitor* const _this)>(0x1A302A0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionResolution : public ArkOptionDropDownBase // Id=801B9DE Size=40
{
public:
	std::vector<ArkOption> m_Resolutions;
	int m_displayIndex;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	static int GetNearestResolution(int _width, int _height, int _displayIndex) { return FGetNearestResolution(_width,_height,_displayIndex); }
	virtual std::vector<ArkOption> &GetDropDownOptions();
	virtual std::vector<ArkOption> const &GetDropDownOptions() const;
	virtual int GetSelectedIndex(const char *const _actionName) const;
	virtual void RefreshOptions(ArkOptionMenu const &_optionMenu);
	void UpdateResolutions(ArkOptionMenu const &_optionMenu) { FUpdateResolutions(this,_optionMenu); }
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364420);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364E30);
	static inline auto FGetNearestResolution = PreyFunction<int(int _width, int _height, int _displayIndex)>(0x13651C0);
	static inline auto FGetDropDownOptionsOv1 = PreyFunction<std::vector<ArkOption> &(ArkOptionResolution *const _this)>(0x5EE7A0);
	static inline auto FGetDropDownOptionsOv0 = PreyFunction<std::vector<ArkOption> const &(ArkOptionResolution const *const _this)>(0x5EE7A0);
	static inline auto FGetSelectedIndex = PreyFunction<int(ArkOptionResolution const *const _this, const char *const _actionName)>(0x13654E0);
	static inline auto FRefreshOptions = PreyFunction<void(ArkOptionResolution *const _this, ArkOptionMenu const &_optionMenu)>(0x13659C0);
	static inline auto FUpdateResolutions = PreyFunction<void(ArkOptionResolution *const _this, ArkOptionMenu const &_optionMenu)>(0x13659D0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447F60);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x14488A0);
	static inline auto FGetNearestResolution = PreyFunction<int(int _width, int _height, int _displayIndex)>(0x1448C30);
	static inline auto FGetDropDownOptionsOv1 = PreyFunction<std::vector<ArkOption>& (ArkOptionResolution* const _this)>(0x133BA60);
	static inline auto FGetDropDownOptionsOv0 = PreyFunction<const std::vector<ArkOption>& (const ArkOptionResolution* const _this)>(0x133BA60);
	static inline auto FGetSelectedIndex = PreyFunction<int(const ArkOptionResolution* const _this, const char* const _actionName)>(0x1448F50);
	static inline auto FRefreshOptions = PreyFunction<void(ArkOptionResolution* const _this, const ArkOptionMenu& _optionMenu)>(0x14493D0);
	static inline auto FUpdateResolutions = PreyFunction<void(ArkOptionResolution* const _this, const ArkOptionMenu& _optionMenu)>(0x14493E0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionLanguageBase : public ArkOptionDropDownBase // Id=801B9DF Size=32
{
public:
	std::vector<ArkOption> m_Languages;
	
	virtual std::vector<ArkOption> &GetDropDownOptions();
	virtual std::vector<ArkOption> const &GetDropDownOptions() const;
	virtual int GetSelectedIndex(const char *const _actionName) const;
	virtual bool IsAvailable();
	virtual bool RequiresConfirmation() const;
	void PopulateLanguages(unsigned _supportedLanguages) { FPopulateLanguages(this,_supportedLanguages); }
	
#ifndef MOONCRASH
	static inline auto FGetDropDownOptionsOv1 = PreyFunction<std::vector<ArkOption> &(ArkOptionLanguageBase *const _this)>(0x5EE7A0);
	static inline auto FGetDropDownOptionsOv0 = PreyFunction<std::vector<ArkOption> const &(ArkOptionLanguageBase const *const _this)>(0x5EE7A0);
	static inline auto FGetSelectedIndex = PreyFunction<int(ArkOptionLanguageBase const *const _this, const char *const _actionName)>(0x1365370);
	static inline auto FIsAvailable = PreyFunction<bool(ArkOptionLanguageBase *const _this)>(0x1365680);
	static inline auto FRequiresConfirmation = PreyFunction<bool(ArkOptionLanguageBase const *const _this)>(0xDD23F0);
	static inline auto FPopulateLanguages = PreyFunction<void(ArkOptionLanguageBase *const _this, unsigned _supportedLanguages)>(0x1365710);
#else
	static inline auto FGetDropDownOptionsOv1 = PreyFunction<std::vector<ArkOption>& (ArkOptionLanguageBase* const _this)>(0x133BA60);
	static inline auto FGetDropDownOptionsOv0 = PreyFunction<const std::vector<ArkOption>& (const ArkOptionLanguageBase* const _this)>(0x133BA60);
	static inline auto FGetSelectedIndex = PreyFunction<int(const ArkOptionLanguageBase* const _this, const char* const _actionName)>(0x1448DE0);
	static inline auto FIsAvailable = PreyFunction<bool(ArkOptionLanguageBase* const _this)>(0x14490F0);
	static inline auto FRequiresConfirmation = PreyFunction<bool(const ArkOptionLanguageBase* const _this)>(0x13B0900);
	static inline auto FPopulateLanguages = PreyFunction<void(ArkOptionLanguageBase* const _this, unsigned _supportedLanguages)>(0x1449120);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionAudioLanguage : public ArkOptionLanguageBase // Id=801B9E0 Size=32
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364140);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364A70);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1447C80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x14484E0);
#endif
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionTextLanguage : public ArkOptionLanguageBase // Id=801B9E1 Size=32
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364510);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364F70);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1448020);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x14489E0);
#endif
};
