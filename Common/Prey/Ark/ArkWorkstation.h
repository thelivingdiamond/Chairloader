// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkdistractiondata.h>
#include <Prey/Ark/arkworkstation.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>

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
	
#if 0
	std::vector<ArkEmail> &GetEmails();
	std::vector<ArkEmail> const &GetEmails() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x108A8A0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x108AE60);
	static inline auto FInit = PreyFunction<bool(ArkEmails *const _this)>(0x108B2B0);
	static inline auto FFind = PreyFunction<ArkEmail const *(ArkEmails const *const _this, const uint64_t &_id)>(0x108AA80);
};

