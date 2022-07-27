// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/GameDll/ark/ui/ArkOptionDropDownBase.h>
#include <Prey/GameDll/ark/ui/arkoptionlayout.h>

class ArkClass;
class ArkOptionMenu;

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class DistractionEvent : public ArkReflectedObject // Id=8013AB3 Size=8
{
public:
	class ArkEventProperty : public ArkProperty // Id=8013AB4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(DistractionEvent::ArkEventProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(DistractionEvent::ArkEventProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static DistractionEvent::ArkEventProperty s_ArkEventProperty;
	string m_Event;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	void SetEvent(string arg0);
	string const &GetEvent() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13644E0);
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkAimAssistPoint : public ArkReflectedObject // Id=80171A1 Size=8
{
public:
	class ArkAttachmentNameProperty : public ArkProperty // Id=80171A2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAimAssistPoint::ArkAttachmentNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAimAssistPoint::ArkAttachmentNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkAimAssistPoint::ArkAttachmentNameProperty s_ArkAttachmentNameProperty;
	string m_AttachmentName;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	void SetAttachmentName(string arg0);
	string const &GetAttachmentName() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13644E0);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutPage::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayoutPage::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkOptionLayoutPage::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkSubPagesProperty : public ArkProperty // Id=801B94D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutPage::ArkSubPagesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13601A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayoutPage::ArkSubPagesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360230);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionLayoutPage::ArkSubPagesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionLayoutPage::ArkSubPagesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1360250);
	};

	static ArkOptionLayoutPage::ArkSubPagesProperty s_ArkSubPagesProperty;
	std::vector<ArkOptionLayoutSubPage> m_SubPages;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetLabel(string arg0);
	string const &GetLabel() const;
	std::vector<ArkOptionLayoutSubPage> &GetSubPages();
	std::vector<ArkOptionLayoutSubPage> const &GetSubPages() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10714D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364C50);
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionLayoutSubPage : public ArkReflectedObject // Id=801B951 Size=64
{
public:
	class ArkLabelProperty : public ArkProperty // Id=801B952 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayoutSubPage::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkOptionLayoutSubPage::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkLabelPS4Property : public ArkProperty // Id=801B953 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkLabelPS4Property const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayoutSubPage::ArkLabelPS4Property const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkOptionLayoutSubPage::ArkLabelPS4Property s_ArkLabelPS4Property;
	string m_LabelPS4;
	
	class ArkAttributesProperty : public ArkProperty // Id=801B954 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkAttributesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FCE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayoutSubPage::ArkAttributesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x135FD20);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionLayoutSubPage::ArkAttributesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionLayoutSubPage::ArkAttributesProperty const *const _this, ArkReflectedObject *_pObject)>(0x135FD40);
	};

	static ArkOptionLayoutSubPage::ArkAttributesProperty s_ArkAttributesProperty;
	std::vector<ArkOptionAttribute> m_Attributes;
	
	class ArkKeybindsProperty : public ArkProperty // Id=801B988 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkKeybindsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13600A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayoutSubPage::ArkKeybindsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkOptionLayoutSubPage::ArkKeybindsProperty s_ArkKeybindsProperty;
	bool m_Keybinds;
	
	class ArkPlatformProperty : public ArkProperty // Id=801B989 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkPlatformProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13600B0);
	};

	static ArkOptionLayoutSubPage::ArkPlatformProperty s_ArkPlatformProperty;
	EArkOptionPlatform m_Platform;
	
	class ArkWriteConfigFileProperty : public ArkProperty // Id=801B98A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkWriteConfigFileProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360100);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayoutSubPage::ArkWriteConfigFileProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkOptionLayoutSubPage::ArkWriteConfigFileProperty s_ArkWriteConfigFileProperty;
	bool m_WriteConfigFile;
	
	class ArkRequiresApplyProperty : public ArkProperty // Id=801B98B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkRequiresApplyProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1056F50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayoutSubPage::ArkRequiresApplyProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F60);
	};

	static ArkOptionLayoutSubPage::ArkRequiresApplyProperty s_ArkRequiresApplyProperty;
	bool m_RequiresApply;
	
	class ArkWarningProperty : public ArkProperty // Id=801B98C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayoutSubPage::ArkWarningProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayoutSubPage::ArkWarningProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkOptionLayoutSubPage::ArkWarningProperty s_ArkWarningProperty;
	string m_Warning;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	const char *GetPlatformLabel() const { return FGetPlatformLabel(this); }
	
#if 0
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetLabelPS4(string arg0);
	string const &GetLabelPS4() const;
	std::vector<ArkOptionAttribute> &GetAttributes();
	std::vector<ArkOptionAttribute> const &GetAttributes() const;
	void SetKeybinds(bool arg0);
	const bool &GetKeybinds() const;
	void SetPlatform(string arg0);
	EArkOptionPlatform const &GetPlatform() const;
	void SetWriteConfigFile(bool arg0);
	const bool &GetWriteConfigFile() const;
	void SetRequiresApply(bool arg0);
	const bool &GetRequiresApply() const;
	void SetWarning(string arg0);
	string const &GetWarning() const;
	bool IsAvailable(EArkOptionPlatform arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364320);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364CF0);
	static inline auto FGetPlatformLabel = PreyFunction<const char *(ArkOptionLayoutSubPage const *const _this)>(0x12E5E70);
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionAttribute : public ArkReflectedObject // Id=801B958 Size=88
{
public:
	class ArkActionProperty : public ArkProperty // Id=801B959 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkActionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkActionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkOptionAttribute::ArkActionProperty s_ArkActionProperty;
	string m_Action;
	
	class ArkLabelProperty : public ArkProperty // Id=801B95A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkOptionAttribute::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkSetOnChangeProperty : public ArkProperty // Id=801B95B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkSetOnChangeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360190);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkSetOnChangeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkOptionAttribute::ArkSetOnChangeProperty s_ArkSetOnChangeProperty;
	bool m_SetOnChange;
	
	class ArkHideOnFrontendProperty : public ArkProperty // Id=801B95C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideOnFrontendProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1061620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkHideOnFrontendProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1061630);
	};

	static ArkOptionAttribute::ArkHideOnFrontendProperty s_ArkHideOnFrontendProperty;
	bool m_HideOnFrontend;
	
	class ArkHideInGameProperty : public ArkProperty // Id=801B95D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideInGameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13602B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkHideInGameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13602C0);
	};

	static ArkOptionAttribute::ArkHideInGameProperty s_ArkHideInGameProperty;
	bool m_HideInGame;
	
	class ArkCloseMenuProperty : public ArkProperty // Id=801B95E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkCloseMenuProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13602D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkCloseMenuProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13602E0);
	};

	static ArkOptionAttribute::ArkCloseMenuProperty s_ArkCloseMenuProperty;
	bool m_CloseMenu;
	
	class ArkDefaultProperty : public ArkProperty // Id=801B95F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkDefaultProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkDefaultProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkOptionAttribute::ArkDefaultProperty s_ArkDefaultProperty;
	string m_Default;
	
	class ArkHideFromProfileProperty : public ArkProperty // Id=801B960 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideFromProfileProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13602F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkHideFromProfileProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkOptionAttribute::ArkHideFromProfileProperty s_ArkHideFromProfileProperty;
	bool m_HideFromProfile;
	
	class ArkHiddenProperty : public ArkProperty // Id=801B961 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHiddenProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360360);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkHiddenProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360370);
	};

	static ArkOptionAttribute::ArkHiddenProperty s_ArkHiddenProperty;
	bool m_Hidden;
	
	class ArkPlatformProperty : public ArkProperty // Id=801B962 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkPlatformProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13603E0);
	};

	static ArkOptionAttribute::ArkPlatformProperty s_ArkPlatformProperty;
	EArkOptionPlatform m_Platform;
	
	class ArkSubactionsProperty : public ArkProperty // Id=801B963 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkSubactionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360450);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkSubactionsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13604B0);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionAttribute::ArkSubactionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionAttribute::ArkSubactionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x13604D0);
	};

	static ArkOptionAttribute::ArkSubactionsProperty s_ArkSubactionsProperty;
	std::vector<ArkOptionSubAction> m_Subactions;
	
	class ArkWidgetProperty : public ArkProperty // Id=801B973 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkWidgetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360700);
	};

	static ArkOptionAttribute::ArkWidgetProperty s_ArkWidgetProperty;
	std::shared_ptr<ArkOptionWidgetBase> m_pWidget;
	
	class ArkWaitForTextureReloadProperty : public ArkProperty // Id=801B978 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkWaitForTextureReloadProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkWaitForTextureReloadProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkOptionAttribute::ArkWaitForTextureReloadProperty s_ArkWaitForTextureReloadProperty;
	bool m_WaitForTextureReload;
	
	class ArkWriteConfigFileProperty : public ArkProperty // Id=801B979 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkWriteConfigFileProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FAA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkWriteConfigFileProperty const *const _this, ArkReflectedObject *const _pObject)>(0x135FAB0);
	};

	static ArkOptionAttribute::ArkWriteConfigFileProperty s_ArkWriteConfigFileProperty;
	bool m_WriteConfigFile;
	
	class ArkHideForSteamControllerProperty : public ArkProperty // Id=801B97A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideForSteamControllerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FAC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkHideForSteamControllerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x135FAD0);
	};

	static ArkOptionAttribute::ArkHideForSteamControllerProperty s_ArkHideForSteamControllerProperty;
	bool m_HideForSteamController;
	
	class ArkHideOnQuasimodoProperty : public ArkProperty // Id=801B97B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideOnQuasimodoProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FAE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkHideOnQuasimodoProperty const *const _this, ArkReflectedObject *const _pObject)>(0x135FAF0);
	};

	static ArkOptionAttribute::ArkHideOnQuasimodoProperty s_ArkHideOnQuasimodoProperty;
	bool m_HideOnQuasimodo;
	
	class ArkHideOnPCProperty : public ArkProperty // Id=801B97C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionAttribute::ArkHideOnPCProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1056FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionAttribute::ArkHideOnPCProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056FD0);
	};

	static ArkOptionAttribute::ArkHideOnPCProperty s_ArkHideOnPCProperty;
	bool m_HideOnPC;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	static EArkOptionPlatform GetEnumFromString(const char *_string) { return FGetEnumFromString(_string); }
	bool IsAvailable(EArkOptionPlatform _platform, const bool _bLevelLoaded) const { return FIsAvailable(this,_platform,_bLevelLoaded); }
	std::pair<string,CCryName> GetActionAsKeyBind() const { return FGetActionAsKeyBindOv1(this); }
	static std::pair<string,CCryName> GetActionAsKeyBind(string const &_action) { return FGetActionAsKeyBindOv0(_action); }
	
#if 0
	void SetAction(string arg0);
	string const &GetAction() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetSetOnChange(bool arg0);
	const bool &GetSetOnChange() const;
	void SetHideOnFrontend(bool arg0);
	const bool &GetHideOnFrontend() const;
	void SetHideInGame(bool arg0);
	const bool &GetHideInGame() const;
	void SetCloseMenu(bool arg0);
	const bool &GetCloseMenu() const;
	void SetDefault(string arg0);
	string const &GetDefault() const;
	void SetHideFromProfile(bool arg0);
	const bool &GetHideFromProfile() const;
	void SetHidden(bool arg0);
	const bool &GetHidden() const;
	void SetPlatform(string arg0);
	EArkOptionPlatform const &GetPlatform() const;
	std::vector<ArkOptionSubAction> &GetSubactions();
	std::vector<ArkOptionSubAction> const &GetSubactions() const;
	void SetWidget(ArkReflectedObject *arg0);
	ArkOptionWidgetBase *GetWidget();
	ArkOptionWidgetBase const *GetWidget() const;
	void SetWaitForTextureReload(bool arg0);
	const bool &GetWaitForTextureReload() const;
	void SetWriteConfigFile(bool arg0);
	const bool &GetWriteConfigFile() const;
	void SetHideForSteamController(bool arg0);
	const bool &GetHideForSteamController() const;
	void SetHideOnQuasimodo(bool arg0);
	const bool &GetHideOnQuasimodo() const;
	void SetHideOnPC(bool arg0);
	const bool &GetHideOnPC() const;
	static const char *GetStringFromEnum(EArkOptionPlatform arg0);
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13640D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x13649D0);
	static inline auto FGetEnumFromString = PreyFunction<EArkOptionPlatform(const char *_string)>(0x1365150);
	static inline auto FIsAvailable = PreyFunction<bool(ArkOptionAttribute const *const _this, EArkOptionPlatform _platform, const bool _bLevelLoaded)>(0x1365600);
	static inline auto FGetActionAsKeyBindOv1 = PreyFunction<std::pair<string,CCryName>(ArkOptionAttribute const *const _this)>(0x1364680);
	static inline auto FGetActionAsKeyBindOv0 = PreyFunction<std::pair<string,CCryName>(string const &_action)>(0x13646A0);
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionSubAction : public ArkReflectedObject // Id=801B967 Size=8
{
public:
	class ArkActionProperty : public ArkProperty // Id=801B968 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionSubAction::ArkActionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionSubAction::ArkActionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkOptionSubAction::ArkActionProperty s_ArkActionProperty;
	string m_Action;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	void SetAction(string arg0);
	string const &GetAction() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13644E0);
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

	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	virtual bool IsAvailable();
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364630);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x13650B0);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionWidgetBase const *const _this)>(0x158AEF0);
	static inline auto FIsAvailable = PreyFunction<bool(ArkOptionWidgetBase *const _this)>(0x1B933B0);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionSlider::ArkMinProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionSlider::ArkMinProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkOptionSlider::ArkMinProperty s_ArkMinProperty;
	float m_Min;
	
	class ArkMaxProperty : public ArkProperty // Id=801B999 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionSlider::ArkMaxProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionSlider::ArkMaxProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6320);
	};

	static ArkOptionSlider::ArkMaxProperty s_ArkMaxProperty;
	float m_Max;
	
	class ArkDecimalsProperty : public ArkProperty // Id=801B99A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionSlider::ArkDecimalsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068E40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionSlider::ArkDecimalsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkOptionSlider::ArkDecimalsProperty s_ArkDecimalsProperty;
	int m_Decimals;
	
	class ArkUnitProperty : public ArkProperty // Id=801B99B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionSlider::ArkUnitProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221AE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionSlider::ArkUnitProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221B00);
	};

	static ArkOptionSlider::ArkUnitProperty s_ArkUnitProperty;
	float m_Unit;
	
	class ArkNormalizeProperty : public ArkProperty // Id=801B99C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionSlider::ArkNormalizeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360430);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionSlider::ArkNormalizeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6360);
	};

	static ArkOptionSlider::ArkNormalizeProperty s_ArkNormalizeProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364480);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364ED0);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionSlider const *const _this)>(0x1A42CE0);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionList::ArkOptionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FDA0);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionList::ArkOptionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionList::ArkOptionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x135FE00);
	};

	static ArkOptionList::ArkOptionsProperty s_ArkOptionsProperty;
	std::vector<std::shared_ptr<ArkOption>> m_Options;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	
#if 0
	static ArkClass *GetClass();
	std::vector<std::shared_ptr<ArkOption>> &GetOptions();
	std::vector<std::shared_ptr<ArkOption>> const &GetOptions() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364370);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionList const *const _this)>(0x1B1DEA0);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionDataList::ArkPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360300);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionDataList::ArkPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkOptionDataList::ArkPathProperty s_ArkPathProperty;
	string m_Path;
	
	class ArkXPathProperty : public ArkProperty // Id=801B9E7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionDataList::ArkXPathProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360380);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionDataList::ArkXPathProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkOptionDataList::ArkXPathProperty s_ArkXPathProperty;
	string m_XPath;
	
	class ArkIDProperty : public ArkProperty // Id=801B9E8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionDataList::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10660B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionDataList::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6360);
	};

	static ArkOptionDataList::ArkIDProperty s_ArkIDProperty;
	string m_ID;
	
	class ArkLabelProperty : public ArkProperty // Id=801B9E9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionDataList::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionDataList::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360170);
	};

	static ArkOptionDataList::ArkLabelProperty s_ArkLabelProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364260);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364BB0);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionDataList const *const _this)>(0xC36440);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionButton::ArkMenuProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360300);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionButton::ArkMenuProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkOptionButton::ArkMenuProperty s_ArkMenuProperty;
	string m_Menu;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	
#if 0
	static ArkClass *GetClass();
	void SetMenu(string arg0);
	string const &GetMenu() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13641C0);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionButton const *const _this)>(0x13F8580);
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionControlMap : public ArkOptionWidgetBase // Id=801B9EC Size=8
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual ArkOptionWidgetBase::EArkOptionWidgetType GetType() const;
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364210);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364B10);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionControlMap const *const _this)>(0x15A4FC0);
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOption : public ArkReflectedObject // Id=801B9A1 Size=56
{
public:
	class ArkLabelProperty : public ArkProperty // Id=801B9A2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOption::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360300);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOption::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkOption::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkValueProperty : public ArkProperty // Id=801B9A3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOption::ArkValueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360380);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOption::ArkValueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkOption::ArkValueProperty s_ArkValueProperty;
	string m_Value;
	
	class ArkHiddenProperty : public ArkProperty // Id=801B9A4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOption::ArkHiddenProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360430);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOption::ArkHiddenProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6360);
	};

	static ArkOption::ArkHiddenProperty s_ArkHiddenProperty;
	bool m_Hidden;
	
	class ArkSubactionsProperty : public ArkProperty // Id=801B9A5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOption::ArkSubactionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13604E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOption::ArkSubactionsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360540);
		static inline auto FIsArray = PreyFunction<bool(ArkOption::ArkSubactionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOption::ArkSubactionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1360580);
	};

	static ArkOption::ArkSubactionsProperty s_ArkSubactionsProperty;
	std::vector<ArkOptionSubAction> m_Subactions;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool IsHidden() const;
	
#if 0
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetValue(string arg0);
	string const &GetValue() const;
	void SetHidden(bool arg0);
	const bool &GetHidden() const;
	std::vector<ArkOptionSubAction> &GetSubactions();
	std::vector<ArkOptionSubAction> const &GetSubactions() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364060);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364930);
	static inline auto FIsHidden = PreyFunction<bool(ArkOption const *const _this)>(0x1141F10);
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
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
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionToggle::ArkOption0Property const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FE40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionToggle::ArkOption0Property const *const _this, ArkReflectedObject *const _pObject)>(0x1068990);
	};

	static ArkOptionToggle::ArkOption0Property s_ArkOption0Property;
	ArkOption m_Option0;
	
	class ArkOption1Property : public ArkProperty // Id=801B9E4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionToggle::ArkOption1Property const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FF50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionToggle::ArkOption1Property const *const _this, ArkReflectedObject *const _pObject)>(0x1360060);
	};

	static ArkOptionToggle::ArkOption1Property s_ArkOption1Property;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364590);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1365010);
	static inline auto FGetType = PreyFunction<ArkOptionWidgetBase::EArkOptionWidgetType(ArkOptionToggle const *const _this)>(0x133DF50);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionLayout::ArkPagesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FB70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionLayout::ArkPagesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x135FBE0);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionLayout::ArkPagesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionLayout::ArkPagesProperty const *const _this, ArkReflectedObject *_pObject)>(0x135FC00);
	};

	static ArkOptionLayout::ArkPagesProperty s_ArkPagesProperty;
	std::vector<ArkOptionLayoutPage> m_Pages;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	std::vector<ArkOptionLayoutPage> &GetPages();
	std::vector<ArkOptionLayoutPage> const &GetPages() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x16140D0);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkOptionDropDown::ArkOptionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13605A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkOptionDropDown::ArkOptionsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360670);
		static inline auto FIsArray = PreyFunction<bool(ArkOptionDropDown::ArkOptionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkOptionDropDown::ArkOptionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x13606C0);
	};

	static ArkOptionDropDown::ArkOptionsProperty s_ArkOptionsProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13642C0);
	static inline auto FGetDropDownOptionsOv1 = PreyFunction<std::vector<ArkOption> &(ArkOptionDropDown *const _this)>(0x5EE7A0);
	static inline auto FGetDropDownOptionsOv0 = PreyFunction<std::vector<ArkOption> const &(ArkOptionDropDown const *const _this)>(0x5EE7A0);
	static inline auto FGetSelectedIndex = PreyFunction<int(ArkOptionDropDown const *const _this, const char *const _cvarName)>(0x13652B0);
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13643D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364D90);
	static inline auto FMustRefreshResolutions = PreyFunction<bool(ArkOptionMonitor const *const _this)>(0x1B933B0);
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364420);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364E30);
	static inline auto FGetNearestResolution = PreyFunction<int(int _width, int _height, int _displayIndex)>(0x13651C0);
	static inline auto FGetDropDownOptionsOv1 = PreyFunction<std::vector<ArkOption> &(ArkOptionResolution *const _this)>(0x5EE7A0);
	static inline auto FGetDropDownOptionsOv0 = PreyFunction<std::vector<ArkOption> const &(ArkOptionResolution const *const _this)>(0x5EE7A0);
	static inline auto FGetSelectedIndex = PreyFunction<int(ArkOptionResolution const *const _this, const char *const _actionName)>(0x13654E0);
	static inline auto FRefreshOptions = PreyFunction<void(ArkOptionResolution *const _this, ArkOptionMenu const &_optionMenu)>(0x13659C0);
	static inline auto FUpdateResolutions = PreyFunction<void(ArkOptionResolution *const _this, ArkOptionMenu const &_optionMenu)>(0x13659D0);
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
	
	static inline auto FGetDropDownOptionsOv1 = PreyFunction<std::vector<ArkOption> &(ArkOptionLanguageBase *const _this)>(0x5EE7A0);
	static inline auto FGetDropDownOptionsOv0 = PreyFunction<std::vector<ArkOption> const &(ArkOptionLanguageBase const *const _this)>(0x5EE7A0);
	static inline auto FGetSelectedIndex = PreyFunction<int(ArkOptionLanguageBase const *const _this, const char *const _actionName)>(0x1365370);
	static inline auto FIsAvailable = PreyFunction<bool(ArkOptionLanguageBase *const _this)>(0x1365680);
	static inline auto FRequiresConfirmation = PreyFunction<bool(ArkOptionLanguageBase const *const _this)>(0xDD23F0);
	static inline auto FPopulateLanguages = PreyFunction<void(ArkOptionLanguageBase *const _this, unsigned _supportedLanguages)>(0x1365710);
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionAudioLanguage : public ArkOptionLanguageBase // Id=801B9E0 Size=32
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364140);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364A70);
};

// Header: Exact
// Prey/GameDll/ark/ui/arkoptionlayout.h
class ArkOptionTextLanguage : public ArkOptionLanguageBase // Id=801B9E1 Size=32
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1364510);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1364F70);
};

