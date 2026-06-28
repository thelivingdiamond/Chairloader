// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkdistractiondata.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class ArkUtilityButton;

// Header: Exact
// Prey/Ark/arkworkstation.h
class ArkDownload : public ArkReflectedObject // Id=8016B99 Size=40
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016B9A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDownload::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDownload::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkDownload::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016B9B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDownload::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDownload::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkDownload::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=8016B9C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDownload::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDownload::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkDownload::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkDescriptionProperty : public ArkProperty // Id=8016B9D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDownload::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDownload::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkDownload::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkDurationProperty : public ArkProperty // Id=8016B9E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDownload::ArkDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDownload::ArkDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkDownload::ArkDurationProperty s_ArkDurationProperty;
	float m_Duration;
	
	class ArkHiddenProperty : public ArkProperty // Id=8016B9F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDownload::ArkHiddenProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10890B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDownload::ArkHiddenProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328510);
	};

	static ArkDownload::ArkHiddenProperty s_ArkHiddenProperty;
	bool m_Hidden;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetDuration(float arg0);
	const float &GetDuration() const;
	void SetHidden(bool arg0);
	const bool &GetHidden() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x108A7E0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x108AD20);
};

// Header: Exact
// Prey/Ark/arkworkstation.h
class ArkKeypadUtility : public ArkUtility // Id=8016BA8 Size=32
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x108A900);
};

// Header: Exact
// Prey/Ark/arkworkstation.h
class ArkButtonUtility : public ArkUtility // Id=8016BAF Size=72
{
public:
	class ArkDescriptionProperty : public ArkProperty // Id=8016BB0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkButtonUtility::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkButtonUtility::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkButtonUtility::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkNoDefaultButtonProperty : public ArkProperty // Id=8016BB1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkButtonUtility::ArkNoDefaultButtonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13600A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkButtonUtility::ArkNoDefaultButtonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkButtonUtility::ArkNoDefaultButtonProperty s_ArkNoDefaultButtonProperty;
	bool m_NoDefaultButton;
	
	class ArkButtonsProperty : public ArkProperty // Id=8016BB2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkButtonUtility::ArkButtonsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkButtonUtility::ArkButtonsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088D60);
		static inline auto FIsArray = PreyFunction<bool(ArkButtonUtility::ArkButtonsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkButtonUtility::ArkButtonsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1088D80);
	};

	static ArkButtonUtility::ArkButtonsProperty s_ArkButtonsProperty;
	std::vector<ArkUtilityButton> m_Buttons;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetNoDefaultButton(bool arg0);
	const bool &GetNoDefaultButton() const;
	std::vector<ArkUtilityButton> &GetButtons();
	std::vector<ArkUtilityButton> const &GetButtons() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x108A780);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x108AC80);
};

// Header: Exact
// Prey/Ark/arkworkstation.h
class ArkEmail : public ArkReflectedObject // Id=8016BC1 Size=120
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016BC2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkEmail::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016BC3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkEmail::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkSubjectProperty : public ArkProperty // Id=8016BC4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkSubjectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkSubjectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkEmail::ArkSubjectProperty s_ArkSubjectProperty;
	string m_Subject;
	
	class ArkBodyProperty : public ArkProperty // Id=8016BC5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkBodyProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkBodyProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkEmail::ArkBodyProperty s_ArkBodyProperty;
	string m_Body;
	
	class ArkDateProperty : public ArkProperty // Id=8016BC6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkDateProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkDateProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkEmail::ArkDateProperty s_ArkDateProperty;
	string m_Date;
	
	class ArkFromProperty : public ArkProperty // Id=8016BC7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkFromProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A840);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkFromProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkEmail::ArkFromProperty s_ArkFromProperty;
	uint64_t m_From;
	
	class ArkToProperty : public ArkProperty // Id=8016BC8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkToProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkToProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088FA0);
		static inline auto FIsArray = PreyFunction<bool(ArkEmail::ArkToProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEmail::ArkToProperty const *const _this, ArkReflectedObject *_pObject)>(0x1088FC0);
	};

	static ArkEmail::ArkToProperty s_ArkToProperty;
	std::vector<unsigned __int64> m_To;
	
	class ArkCCProperty : public ArkProperty // Id=8016BC9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkCCProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1089030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkCCProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1089050);
		static inline auto FIsArray = PreyFunction<bool(ArkEmail::ArkCCProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEmail::ArkCCProperty const *const _this, ArkReflectedObject *_pObject)>(0x1089070);
	};

	static ArkEmail::ArkCCProperty s_ArkCCProperty;
	std::vector<unsigned __int64> m_CC;
	
	class ArkKeycodeProperty : public ArkProperty // Id=8016BCA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkKeycodeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1089080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkKeycodeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086170);
	};

	static ArkEmail::ArkKeycodeProperty s_ArkKeycodeProperty;
	uint64_t m_Keycode;
	
	class ArkPasswordProperty : public ArkProperty // Id=8016BCB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkPasswordProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1089090);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkPasswordProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4D20);
	};

	static ArkEmail::ArkPasswordProperty s_ArkPasswordProperty;
	uint64_t m_Password;
	
	class ArkSentProperty : public ArkProperty // Id=8016BCC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkSentProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10890A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkSentProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1082260);
	};

	static ArkEmail::ArkSentProperty s_ArkSentProperty;
	bool m_Sent;
	
	class ArkImportantProperty : public ArkProperty // Id=8016BCD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmail::ArkImportantProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10890C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmail::ArkImportantProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10890D0);
	};

	static ArkEmail::ArkImportantProperty s_ArkImportantProperty;
	bool m_Important;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetSubject(string arg0);
	string const &GetSubject() const;
	void SetBody(string arg0);
	string const &GetBody() const;
	void SetDate(string arg0);
	string const &GetDate() const;
	void SetFrom(uint64_t arg0);
	const uint64_t &GetFrom() const;
	std::vector<unsigned __int64> &GetTo();
	std::vector<unsigned __int64> const &GetTo() const;
	std::vector<unsigned __int64> &GetCC();
	std::vector<unsigned __int64> const &GetCC() const;
	void SetKeycode(uint64_t arg0);
	const uint64_t &GetKeycode() const;
	void SetPassword(uint64_t arg0);
	const uint64_t &GetPassword() const;
	void SetSent(bool arg0);
	const bool &GetSent() const;
	void SetImportant(bool arg0);
	const bool &GetImportant() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x108A830);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x108ADC0);
};

// Header: Exact
// Prey/Ark/ArkWorkstation.h
class ArkWorkstation : public ArkReflectedObject // Id=8016BCE Size=120
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016BCF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWorkstation::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWorkstation::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkWorkstation::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016BD0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWorkstation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWorkstation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkWorkstation::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkWorkstationTitleProperty : public ArkProperty // Id=8016BD1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWorkstation::ArkWorkstationTitleProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWorkstation::ArkWorkstationTitleProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkWorkstation::ArkWorkstationTitleProperty s_ArkWorkstationTitleProperty;
	string m_WorkstationTitle;
	
	class ArkUserProperty : public ArkProperty // Id=8016BD2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWorkstation::ArkUserProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWorkstation::ArkUserProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkWorkstation::ArkUserProperty s_ArkUserProperty;
	uint64_t m_User;
	
	class ArkUseEmployeeModeProperty : public ArkProperty // Id=8016BD3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWorkstation::ArkUseEmployeeModeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13602F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWorkstation::ArkUseEmployeeModeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkWorkstation::ArkUseEmployeeModeProperty s_ArkUseEmployeeModeProperty;
	bool m_UseEmployeeMode;
	
	class ArkEmailsProperty : public ArkProperty // Id=8016BD4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWorkstation::ArkEmailsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088B00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWorkstation::ArkEmailsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088B20);
		static inline auto FIsArray = PreyFunction<bool(ArkWorkstation::ArkEmailsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkWorkstation::ArkEmailsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1088B40);
	};

	static ArkWorkstation::ArkEmailsProperty s_ArkEmailsProperty;
	std::vector<unsigned __int64> m_Emails;
	
	class ArkDownloadsProperty : public ArkProperty // Id=8016BD5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWorkstation::ArkDownloadsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088B50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWorkstation::ArkDownloadsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088C30);
		static inline auto FIsArray = PreyFunction<bool(ArkWorkstation::ArkDownloadsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkWorkstation::ArkDownloadsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1088C50);
	};

	static ArkWorkstation::ArkDownloadsProperty s_ArkDownloadsProperty;
	std::vector<ArkDownload> m_Downloads;
	
	class ArkUtilitiesProperty : public ArkProperty // Id=8016BE3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWorkstation::ArkUtilitiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088DB0);
		static inline auto FIsArray = PreyFunction<bool(ArkWorkstation::ArkUtilitiesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkWorkstation::ArkUtilitiesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1088DD0);
	};

	static ArkWorkstation::ArkUtilitiesProperty s_ArkUtilitiesProperty;
	std::vector<std::shared_ptr<ArkUtility>> m_Utilities;
	
	class ArkUtilitiesTitleProperty : public ArkProperty // Id=8016BF4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWorkstation::ArkUtilitiesTitleProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWorkstation::ArkUtilitiesTitleProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1082260);
	};

	static ArkWorkstation::ArkUtilitiesTitleProperty s_ArkUtilitiesTitleProperty;
	string m_UtilitiesTitle;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetWorkstationTitle(string arg0);
	string const &GetWorkstationTitle() const;
	void SetUser(uint64_t arg0);
	const uint64_t &GetUser() const;
	void SetUseEmployeeMode(bool arg0);
	const bool &GetUseEmployeeMode() const;
	std::vector<unsigned __int64> &GetEmails();
	std::vector<unsigned __int64> const &GetEmails() const;
	std::vector<ArkDownload> &GetDownloads();
	std::vector<ArkDownload> const &GetDownloads() const;
	std::vector<std::shared_ptr<ArkUtility>> &GetUtilities();
	std::vector<std::shared_ptr<ArkUtility>> const &GetUtilities() const;
	void SetUtilitiesTitle(string arg0);
	string const &GetUtilitiesTitle() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x108A9C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x108B040);
};

// Header: Exact
// Prey/Ark/arkworkstation.h
class ArkWorkstations : public ArkReflectedLibrary // Id=8016C03 Size=32
{
public:
	class ArkWorkstationsProperty : public ArkProperty // Id=8016C04 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWorkstations::ArkWorkstationsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088990);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWorkstations::ArkWorkstationsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088A50);
		static inline auto FIsArray = PreyFunction<bool(ArkWorkstations::ArkWorkstationsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkWorkstations::ArkWorkstationsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1088A90);
	};

	static ArkWorkstations::ArkWorkstationsProperty s_ArkWorkstationsProperty;
	std::vector<ArkWorkstation> m_Workstations;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkWorkstation const *Find(const uint64_t &_id) const { return FFind(this,_id); }
	ArkDownload const *FindDownload(const uint64_t _id) const { return FFindDownload(this,_id); }
	ArkUtility const *FindUtility(const uint64_t _id) const { return FFindUtility(this,_id); }
	ArkUtilityButton const *FindUtilityButton(const uint64_t _id) const { return FFindUtilityButton(this,_id); }
	uint64_t GetUtilityButtonOwner(const uint64_t _id) const { return FGetUtilityButtonOwner(this,_id); }
	virtual ~ArkWorkstations();
	
#if 0
	std::vector<ArkWorkstation> &GetWorkstations();
	std::vector<ArkWorkstation> const &GetWorkstations() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x108AA20);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x108B0E0);
	static inline auto FInit = PreyFunction<bool(ArkWorkstations *const _this)>(0x108B460);
	static inline auto FFind = PreyFunction<ArkWorkstation const *(ArkWorkstations const *const _this, const uint64_t &_id)>(0x108AA80);
	static inline auto FFindDownload = PreyFunction<ArkDownload const *(ArkWorkstations const *const _this, const uint64_t _id)>(0x108AAB0);
	static inline auto FFindUtility = PreyFunction<ArkUtility const *(ArkWorkstations const *const _this, const uint64_t _id)>(0x108AB00);
	static inline auto FFindUtilityButton = PreyFunction<ArkUtilityButton const *(ArkWorkstations const *const _this, const uint64_t _id)>(0x108AB50);
	static inline auto FGetUtilityButtonOwner = PreyFunction<uint64_t(ArkWorkstations const *const _this, const uint64_t _id)>(0x108B180);
};

// Header: Exact
// Prey/Ark/arkworkstation.h
class ArkEmails : public ArkReflectedLibrary // Id=8016C13 Size=32
{
public:
	class ArkEmailsProperty : public ArkProperty // Id=8016C14 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmails::ArkEmailsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088E00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmails::ArkEmailsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088EC0);
		static inline auto FIsArray = PreyFunction<bool(ArkEmails::ArkEmailsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEmails::ArkEmailsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1088F00);
	};

	static ArkEmails::ArkEmailsProperty s_ArkEmailsProperty;
	std::vector<ArkEmail> m_Emails;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkEmail const *Find(const uint64_t &_id) const { return FFind(this,_id); }
	virtual ~ArkEmails();
	
#if 0
	std::vector<ArkEmail> &GetEmails();
	std::vector<ArkEmail> const &GetEmails() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x108A8A0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x108AE60);
	static inline auto FInit = PreyFunction<bool(ArkEmails *const _this)>(0x108B2B0);
	static inline auto FFind = PreyFunction<ArkEmail const *(ArkEmails const *const _this, const uint64_t &_id)>(0x108AA80);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkUtility
// Header:  Prey/Ark/ArkWorkstation.h
class ArkUtility : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkUtility::ArkIDProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkUtility::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkUtility::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkUtility::ArkNameProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkUtility::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkUtility::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkUtility::ArkLabelProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkUtility::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkUtility::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkUtility::ArkTypeProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkTypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _arg0_, const IArkValueBase* _arg1_) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _arg0_) const;

	#if 0
		ArkTypeProperty();
	#endif
	};

	// ArkUtility::ArkEnabledProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkEnabledProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEnabledProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkUtility::ArkEnabledProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1080C80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkUtility::ArkEnabledProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
	};

	// ArkUtility::ArkHiddenProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkHiddenProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHiddenProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkUtility::ArkHiddenProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1080C90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkUtility::ArkHiddenProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CA0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkUtility::ArkIDProperty>(0x2D2A1B0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkUtility::ArkNameProperty>(0x2D2A1D0);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkUtility::ArkLabelProperty>(0x2D2A1F0);
	string m_Label;
	static inline auto s_ArkTypeProperty = PreyGlobal<ArkUtility::ArkTypeProperty>(0x0);
	ArkUtilityType m_Type;
	static inline auto s_ArkEnabledProperty = PreyGlobal<ArkUtility::ArkEnabledProperty>(0x2D2A210);
	bool m_Enabled;
	static inline auto s_ArkHiddenProperty = PreyGlobal<ArkUtility::ArkHiddenProperty>(0x2D2A230);
	bool m_Hidden;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkUtility();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetType(ArkUtilityType _arg0_);
	const ArkUtilityType& GetType() const;
	void SetEnabled(bool _arg0_);
	const bool& GetEnabled() const;
	void SetHidden(bool _arg0_);
	const bool& GetHidden() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B9500);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B9AF0);
};

// ArkUtilityButton
// Header:  Prey/Ark/ArkWorkstation.h
class ArkUtilityButton : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkUtilityButton::ArkIDProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkUtilityButton::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkUtilityButton::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkUtilityButton::ArkNameProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkUtilityButton::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkUtilityButton::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkUtilityButton::ArkLabelProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkUtilityButton::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkUtilityButton::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkUtilityButton::ArkEnabledProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkEnabledProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEnabledProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkUtilityButton::ArkEnabledProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkUtilityButton::ArkEnabledProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkUtilityButton::ArkHiddenProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkHiddenProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHiddenProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkUtilityButton::ArkHiddenProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7BE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkUtilityButton::ArkHiddenProperty* const _this, ArkReflectedObject* const _pObject)>(0x10827A0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkUtilityButton::ArkIDProperty>(0x2D2A110);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkUtilityButton::ArkNameProperty>(0x2D2A130);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkUtilityButton::ArkLabelProperty>(0x2D2A150);
	string m_Label;
	static inline auto s_ArkEnabledProperty = PreyGlobal<ArkUtilityButton::ArkEnabledProperty>(0x2D2A170);
	bool m_Enabled;
	static inline auto s_ArkHiddenProperty = PreyGlobal<ArkUtilityButton::ArkHiddenProperty>(0x2D2A190);
	bool m_Hidden;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkUtilityButton();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetEnabled(bool _arg0_);
	const bool& GetEnabled() const;
	void SetHidden(bool _arg0_);
	const bool& GetHidden() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B9540);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B9B90);
};

// ArkButtonUtility
// Header:  Prey/Ark/ArkWorkstation.h
class ArkButtonUtility : public ArkUtility
{ // Size=72 (0x48)
public:
	// ArkButtonUtility::ArkDescriptionProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkButtonUtility::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkButtonUtility::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkButtonUtility::ArkNoDefaultButtonProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkNoDefaultButtonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNoDefaultButtonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkButtonUtility::ArkNoDefaultButtonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkButtonUtility::ArkNoDefaultButtonProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkButtonUtility::ArkButtonsProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkButtonsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkButtonsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkButtonUtility::ArkButtonsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7BF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkButtonUtility::ArkButtonsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7CA0);
		static inline auto FIsArray = PreyFunction<bool(const ArkButtonUtility::ArkButtonsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkButtonUtility::ArkButtonsProperty* const _this, ArkReflectedObject* _pObject)>(0x10B7CC0);
	};

	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkButtonUtility::ArkDescriptionProperty>(0x2D2A250);
	string m_Description;
	static inline auto s_ArkNoDefaultButtonProperty = PreyGlobal<ArkButtonUtility::ArkNoDefaultButtonProperty>(0x2D2A270);
	bool m_NoDefaultButton;
	static inline auto s_ArkButtonsProperty = PreyGlobal<ArkButtonUtility::ArkButtonsProperty>(0x2D2A290);
	std::vector<ArkUtilityButton> m_Buttons;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkButtonUtility();
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetNoDefaultButton(bool _arg0_);
	const bool& GetNoDefaultButton() const;
	std::vector<ArkUtilityButton>& GetButtons();
	const std::vector<ArkUtilityButton>& GetButtons() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B9340);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B9870);
};

// ArkKeypadUtility
// Header:  Prey/Ark/ArkWorkstation.h
class ArkKeypadUtility : public ArkUtility
{ // Size=32 (0x20)
public:
	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	ArkKeypadUtility();
	static ArkClass* GetClass();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B94C0);
};

// ArkEmail
// Header:  Prey/Ark/ArkWorkstation.h
class ArkEmail : public ArkReflectedObject
{ // Size=120 (0x78)
public:
	// ArkEmail::ArkIDProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkEmail::ArkNameProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkEmail::ArkSubjectProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkSubjectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSubjectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkSubjectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkSubjectProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkEmail::ArkBodyProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkBodyProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBodyProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkBodyProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkBodyProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkEmail::ArkDateProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkDateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkDateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkDateProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkEmail::ArkFromProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkFromProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFromProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkFromProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkFromProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkEmail::ArkToProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkToProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkToProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkToProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7780);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkToProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B77A0);
		static inline auto FIsArray = PreyFunction<bool(const ArkEmail::ArkToProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEmail::ArkToProperty* const _this, ArkReflectedObject* _pObject)>(0x10B77C0);
	};

	// ArkEmail::ArkCCProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkCCProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkCCProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkCCProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B77D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkCCProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B77F0);
		static inline auto FIsArray = PreyFunction<bool(const ArkEmail::ArkCCProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEmail::ArkCCProperty* const _this, ArkReflectedObject* _pObject)>(0x10B7810);
	};

	// ArkEmail::ArkKeycodeProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkKeycodeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkKeycodeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkKeycodeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7820);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkKeycodeProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B80);
	};

	// ArkEmail::ArkPasswordProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkPasswordProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPasswordProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkPasswordProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkPasswordProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7840);
	};

	// ArkEmail::ArkSentProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkSentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkSentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7850);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkSentProperty* const _this, ArkReflectedObject* const _pObject)>(0x1403090);
	};

	// ArkEmail::ArkImportantProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkImportantProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkImportantProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkImportantProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7880);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkImportantProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7890);
	};

	// ArkEmail::ArkResetWithCharacterChangeProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkResetWithCharacterChangeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkResetWithCharacterChangeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkResetWithCharacterChangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B78A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkResetWithCharacterChangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B78B0);
	};

	// ArkEmail::ArkPersistThroughSimResetProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkPersistThroughSimResetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPersistThroughSimResetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmail::ArkPersistThroughSimResetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B78C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmail::ArkPersistThroughSimResetProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B78D0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkEmail::ArkIDProperty>(0x2D2A2B0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkEmail::ArkNameProperty>(0x2D2A2D0);
	string m_Name;
	static inline auto s_ArkSubjectProperty = PreyGlobal<ArkEmail::ArkSubjectProperty>(0x2D2A2F0);
	string m_Subject;
	static inline auto s_ArkBodyProperty = PreyGlobal<ArkEmail::ArkBodyProperty>(0x2D2A310);
	string m_Body;
	static inline auto s_ArkDateProperty = PreyGlobal<ArkEmail::ArkDateProperty>(0x2D2A330);
	string m_Date;
	static inline auto s_ArkFromProperty = PreyGlobal<ArkEmail::ArkFromProperty>(0x2D2A350);
	uint64_t m_From;
	static inline auto s_ArkToProperty = PreyGlobal<ArkEmail::ArkToProperty>(0x2D2A370);
	std::vector<uint64_t> m_To;
	static inline auto s_ArkCCProperty = PreyGlobal<ArkEmail::ArkCCProperty>(0x2D2A390);
	std::vector<uint64_t> m_CC;
	static inline auto s_ArkKeycodeProperty = PreyGlobal<ArkEmail::ArkKeycodeProperty>(0x2D2A3B0);
	uint64_t m_Keycode;
	static inline auto s_ArkPasswordProperty = PreyGlobal<ArkEmail::ArkPasswordProperty>(0x2D2A3D0);
	uint64_t m_Password;
	static inline auto s_ArkSentProperty = PreyGlobal<ArkEmail::ArkSentProperty>(0x2D2A3F0);
	bool m_Sent;
	static inline auto s_ArkImportantProperty = PreyGlobal<ArkEmail::ArkImportantProperty>(0x2D2A410);
	bool m_Important;
	static inline auto s_ArkResetWithCharacterChangeProperty = PreyGlobal<ArkEmail::ArkResetWithCharacterChangeProperty>(0x2D2A430);
	bool m_ResetWithCharacterChange;
	static inline auto s_ArkPersistThroughSimResetProperty = PreyGlobal<ArkEmail::ArkPersistThroughSimResetProperty>(0x2D2A450);
	bool m_PersistThroughSimReset;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkEmail();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetSubject(string _arg0_);
	const string& GetSubject() const;
	void SetBody(string _arg0_);
	const string& GetBody() const;
	void SetDate(string _arg0_);
	const string& GetDate() const;
	void SetFrom(uint64_t _arg0_);
	const uint64_t& GetFrom() const;
	std::vector<uint64_t>& GetTo();
	const std::vector<uint64_t>& GetTo() const;
	std::vector<uint64_t>& GetCC();
	const std::vector<uint64_t>& GetCC() const;
	void SetKeycode(uint64_t _arg0_);
	const uint64_t& GetKeycode() const;
	void SetPassword(uint64_t _arg0_);
	const uint64_t& GetPassword() const;
	void SetSent(bool _arg0_);
	const bool& GetSent() const;
	void SetImportant(bool _arg0_);
	const bool& GetImportant() const;
	void SetResetWithCharacterChange(bool _arg0_);
	const bool& GetResetWithCharacterChange() const;
	void SetPersistThroughSimReset(bool _arg0_);
	const bool& GetPersistThroughSimReset() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B93F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B99B0);
};

// ArkEmails
// Header:  Prey/Ark/ArkWorkstation.h
class ArkEmails : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkEmails::ArkEmailsProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkEmailsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkEmailsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmails::ArkEmailsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmails::ArkEmailsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B76C0);
		static inline auto FIsArray = PreyFunction<bool(const ArkEmails::ArkEmailsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEmails::ArkEmailsProperty* const _this, ArkReflectedObject* _pObject)>(0x10B7700);
	};

	static inline auto s_ArkEmailsProperty = PreyGlobal<ArkEmails::ArkEmailsProperty>(0x2D2A470);
	std::vector<ArkEmail> m_Emails;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkEmail* Find(const uint64_t& _id) const { return FFind(this, _id); }

#if 0
	std::vector<ArkEmail>& GetEmails();
	const std::vector<ArkEmail>& GetEmails() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B9460);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B9A50);
	static inline auto FInit = PreyFunction<bool(ArkEmails* const _this)>(0x10B9EA0);
	static inline auto FFind = PreyFunction<const ArkEmail* (const ArkEmails* const _this, const uint64_t& _id)>(0x10B9640);
};

// ArkDownload
// Header:  Prey/Ark/ArkWorkstation.h
class ArkDownload : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkDownload::ArkIDProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDownload::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDownload::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDownload::ArkNameProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDownload::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDownload::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkDownload::ArkLabelProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDownload::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDownload::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkDownload::ArkDescriptionProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDownload::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDownload::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkDownload::ArkDurationProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDownload::ArkDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDownload::ArkDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkDownload::ArkHiddenProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkHiddenProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHiddenProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDownload::ArkHiddenProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7860);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDownload::ArkHiddenProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C370);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkDownload::ArkIDProperty>(0x2D2A050);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkDownload::ArkNameProperty>(0x2D2A070);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkDownload::ArkLabelProperty>(0x2D2A090);
	string m_Label;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkDownload::ArkDescriptionProperty>(0x2D2A0B0);
	string m_Description;
	static inline auto s_ArkDurationProperty = PreyGlobal<ArkDownload::ArkDurationProperty>(0x2D2A0D0);
	float m_Duration;
	static inline auto s_ArkHiddenProperty = PreyGlobal<ArkDownload::ArkHiddenProperty>(0x2D2A0F0);
	bool m_Hidden;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkDownload();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetDuration(float _arg0_);
	const float& GetDuration() const;
	void SetHidden(bool _arg0_);
	const bool& GetHidden() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B93A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B9910);
};

// ArkWorkstation
// Header:  Prey/Ark/ArkWorkstation.h
class ArkWorkstation : public ArkReflectedObject
{ // Size=128 (0x80)
public:
	// ArkWorkstation::ArkIDProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWorkstation::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWorkstation::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkWorkstation::ArkNameProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWorkstation::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWorkstation::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkWorkstation::ArkWorkstationTitleProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkWorkstationTitleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkWorkstationTitleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWorkstation::ArkWorkstationTitleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWorkstation::ArkWorkstationTitleProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkWorkstation::ArkUserProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkUserProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUserProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWorkstation::ArkUserProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWorkstation::ArkUserProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkWorkstation::ArkUseEmployeeModeProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkUseEmployeeModeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUseEmployeeModeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWorkstation::ArkUseEmployeeModeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084750);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWorkstation::ArkUseEmployeeModeProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkWorkstation::ArkEmailsProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkEmailsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkEmailsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWorkstation::ArkEmailsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B78E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWorkstation::ArkEmailsProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C380);
		static inline auto FIsArray = PreyFunction<bool(const ArkWorkstation::ArkEmailsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWorkstation::ArkEmailsProperty* const _this, ArkReflectedObject* _pObject)>(0x10B2750);
	};

	// ArkWorkstation::ArkDownloadsProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkDownloadsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkDownloadsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWorkstation::ArkDownloadsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7A70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWorkstation::ArkDownloadsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7B50);
		static inline auto FIsArray = PreyFunction<bool(const ArkWorkstation::ArkDownloadsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWorkstation::ArkDownloadsProperty* const _this, ArkReflectedObject* _pObject)>(0x10B7B70);
	};

	// ArkWorkstation::ArkUtilitiesProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkUtilitiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkUtilitiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWorkstation::ArkUtilitiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B75B0);
		static inline auto FIsArray = PreyFunction<bool(const ArkWorkstation::ArkUtilitiesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWorkstation::ArkUtilitiesProperty* const _this, ArkReflectedObject* _pObject)>(0x10B75D0);
	};

	// ArkWorkstation::ArkUtilitiesTitleProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkUtilitiesTitleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUtilitiesTitleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWorkstation::ArkUtilitiesTitleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0BF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWorkstation::ArkUtilitiesTitleProperty* const _this, ArkReflectedObject* const _pObject)>(0x1403090);
	};

	// ArkWorkstation::ArkInSatelliteProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkInSatelliteProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInSatelliteProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWorkstation::ArkInSatelliteProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7870);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWorkstation::ArkInSatelliteProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BE110);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkWorkstation::ArkIDProperty>(0x2D2A490);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkWorkstation::ArkNameProperty>(0x2D2A4B0);
	string m_Name;
	static inline auto s_ArkWorkstationTitleProperty = PreyGlobal<ArkWorkstation::ArkWorkstationTitleProperty>(0x2D2A4D0);
	string m_WorkstationTitle;
	static inline auto s_ArkUserProperty = PreyGlobal<ArkWorkstation::ArkUserProperty>(0x2D2A4F0);
	uint64_t m_User;
	static inline auto s_ArkUseEmployeeModeProperty = PreyGlobal<ArkWorkstation::ArkUseEmployeeModeProperty>(0x2D2A510);
	bool m_UseEmployeeMode;
	static inline auto s_ArkEmailsProperty = PreyGlobal<ArkWorkstation::ArkEmailsProperty>(0x2D2A530);
	std::vector<uint64_t> m_Emails;
	static inline auto s_ArkDownloadsProperty = PreyGlobal<ArkWorkstation::ArkDownloadsProperty>(0x2D2A550);
	std::vector<ArkDownload> m_Downloads;
	static inline auto s_ArkUtilitiesProperty = PreyGlobal<ArkWorkstation::ArkUtilitiesProperty>(0x2D2A570);
	std::vector<std::shared_ptr<ArkUtility>> m_Utilities;
	static inline auto s_ArkUtilitiesTitleProperty = PreyGlobal<ArkWorkstation::ArkUtilitiesTitleProperty>(0x2D2A590);
	string m_UtilitiesTitle;
	static inline auto s_ArkInSatelliteProperty = PreyGlobal<ArkWorkstation::ArkInSatelliteProperty>(0x2D2A5B0);
	bool m_InSatellite;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkWorkstation();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetWorkstationTitle(string _arg0_);
	const string& GetWorkstationTitle() const;
	void SetUser(uint64_t _arg0_);
	const uint64_t& GetUser() const;
	void SetUseEmployeeMode(bool _arg0_);
	const bool& GetUseEmployeeMode() const;
	std::vector<uint64_t>& GetEmails();
	const std::vector<uint64_t>& GetEmails() const;
	std::vector<ArkDownload>& GetDownloads();
	const std::vector<ArkDownload>& GetDownloads() const;
	std::vector<std::shared_ptr<ArkUtility>>& GetUtilities();
	const std::vector<std::shared_ptr<ArkUtility>>& GetUtilities() const;
	void SetUtilitiesTitle(string _arg0_);
	const string& GetUtilitiesTitle() const;
	void SetInSatellite(bool _arg0_);
	const bool& GetInSatellite() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B9580);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B9C30);
};

// ArkWorkstations
// Header:  Prey/Ark/ArkWorkstation.h
class ArkWorkstations : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkWorkstations::ArkWorkstationsProperty
	// Header:  Prey/Ark/ArkWorkstation.h
	class ArkWorkstationsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkWorkstationsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWorkstations::ArkWorkstationsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7900);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWorkstations::ArkWorkstationsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B79C0);
		static inline auto FIsArray = PreyFunction<bool(const ArkWorkstations::ArkWorkstationsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWorkstations::ArkWorkstationsProperty* const _this, ArkReflectedObject* _pObject)>(0x10B7A00);
	};

	static inline auto s_ArkWorkstationsProperty = PreyGlobal<ArkWorkstations::ArkWorkstationsProperty>(0x2D2A5D0);
	std::vector<ArkWorkstation> m_Workstations;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkWorkstation* Find(const uint64_t& _id) const { return FFind(this, _id); }
	const ArkDownload* FindDownload(const uint64_t _id) const { return FFindDownload(this, _id); }
	const ArkUtility* FindUtility(const uint64_t _id) const { return FFindUtility(this, _id); }
	const ArkUtilityButton* FindUtilityButton(const uint64_t _id) const { return FFindUtilityButton(this, _id); }
	uint64_t GetUtilityButtonOwner(const uint64_t _id) const { return FGetUtilityButtonOwner(this, _id); }

#if 0
	std::vector<ArkWorkstation>& GetWorkstations();
	const std::vector<ArkWorkstation>& GetWorkstations() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B95E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B9CD0);
	static inline auto FInit = PreyFunction<bool(ArkWorkstations* const _this)>(0x10BA070);
	static inline auto FFind = PreyFunction<const ArkWorkstation* (const ArkWorkstations* const _this, const uint64_t& _id)>(0x10B9670);
	static inline auto FFindDownload = PreyFunction<const ArkDownload* (const ArkWorkstations* const _this, const uint64_t _id)>(0x10B96A0);
	static inline auto FFindUtility = PreyFunction<const ArkUtility* (const ArkWorkstations* const _this, const uint64_t _id)>(0x10B96F0);
	static inline auto FFindUtilityButton = PreyFunction<const ArkUtilityButton* (const ArkWorkstations* const _this, const uint64_t _id)>(0x10B9740);
	static inline auto FGetUtilityButtonOwner = PreyFunction<uint64_t(const ArkWorkstations* const _this, const uint64_t _id)>(0x10B9D70);
};
#endif // !MOONCRASH
