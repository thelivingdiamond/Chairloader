// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/Ark/arkdistractiondata.h>

class ArkAudioLog;
class ArkClass;

// Header: Exact
// Prey/Ark/arkaudiolog.h
class ArkAudioLogCollection : public ArkReflectedObject // Id=8013555 Size=56
{
public:
	class ArkIDProperty : public ArkProperty // Id=8013556 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLogCollection::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLogCollection::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkAudioLogCollection::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013557 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLogCollection::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLogCollection::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkAudioLogCollection::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkOwnerProperty : public ArkProperty // Id=8013558 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLogCollection::ArkOwnerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1067FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLogCollection::ArkOwnerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkAudioLogCollection::ArkOwnerProperty s_ArkOwnerProperty;
	uint64_t m_Owner;
	
	class ArkPlotCriticalProperty : public ArkProperty // Id=8013559 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLogCollection::ArkPlotCriticalProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLogCollection::ArkPlotCriticalProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkAudioLogCollection::ArkPlotCriticalProperty s_ArkPlotCriticalProperty;
	bool m_PlotCritical;
	
	class ArkLinkedAudioLogsProperty : public ArkProperty // Id=801355A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLogCollection::ArkLinkedAudioLogsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10592B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLogCollection::ArkLinkedAudioLogsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10592D0);
		static inline auto FIsArray = PreyFunction<bool(ArkAudioLogCollection::ArkLinkedAudioLogsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAudioLogCollection::ArkLinkedAudioLogsProperty const *const _this, ArkReflectedObject *_pObject)>(0x10592F0);
	};

	static ArkAudioLogCollection::ArkLinkedAudioLogsProperty s_ArkLinkedAudioLogsProperty;
	std::vector<unsigned __int64> m_LinkedAudioLogs;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetOwner(uint64_t arg0);
	const uint64_t &GetOwner() const;
	void SetPlotCritical(bool arg0);
	const bool &GetPlotCritical() const;
	std::vector<unsigned __int64> &GetLinkedAudioLogs();
	std::vector<unsigned __int64> const &GetLinkedAudioLogs() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105A2C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105A410);
};

// Header: Exact
// Prey/Ark/arkaudiolog.h
class ArkAudioLogLibrary : public ArkReflectedLibrary // Id=8013568 Size=56
{
public:
	class ArkAudioLogsProperty : public ArkProperty // Id=8013569 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLogLibrary::ArkAudioLogsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1059300);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLogLibrary::ArkAudioLogsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1059430);
		static inline auto FIsArray = PreyFunction<bool(ArkAudioLogLibrary::ArkAudioLogsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAudioLogLibrary::ArkAudioLogsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1059470);
	};

	static ArkAudioLogLibrary::ArkAudioLogsProperty s_ArkAudioLogsProperty;
	std::vector<ArkAudioLog> m_AudioLogs;
	
	class ArkAudioLogCollectionsProperty : public ArkProperty // Id=801356A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAudioLogLibrary::ArkAudioLogCollectionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10594E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAudioLogLibrary::ArkAudioLogCollectionsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1059580);
		static inline auto FIsArray = PreyFunction<bool(ArkAudioLogLibrary::ArkAudioLogCollectionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAudioLogLibrary::ArkAudioLogCollectionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x10595C0);
	};

	static ArkAudioLogLibrary::ArkAudioLogCollectionsProperty s_ArkAudioLogCollectionsProperty;
	std::vector<ArkAudioLogCollection> m_AudioLogCollections;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkAudioLogLibrary();
	
#if 0
	std::vector<ArkAudioLog> &GetAudioLogs();
	std::vector<ArkAudioLog> const &GetAudioLogs() const;
	std::vector<ArkAudioLogCollection> &GetAudioLogCollections();
	std::vector<ArkAudioLogCollection> const &GetAudioLogCollections() const;
	ArkAudioLogCollection const *FindAudioLogCollection(const uint64_t arg0) const;
	ArkAudioLogCollection const *FindAudioLogCollection(const char *arg0) const;
	ArkAudioLog const *FindAudioLog(const uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105A310);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105A4B0);
	static inline auto FInit = PreyFunction<bool(ArkAudioLogLibrary *const _this)>(0x105A5A0);
};

// Header: Exact
// Prey/Ark/arkaudiolog.h
class ArkSecurityStation : public ArkReflectedObject // Id=8016C16 Size=112
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016C17 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSecurityStation::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSecurityStation::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkSecurityStation::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016C18 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSecurityStation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSecurityStation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkSecurityStation::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkUserProperty : public ArkProperty // Id=8016C19 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSecurityStation::ArkUserProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1067FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSecurityStation::ArkUserProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkSecurityStation::ArkUserProperty s_ArkUserProperty;
	uint64_t m_User;
	
	class ArkLocationProperty : public ArkProperty // Id=8016C1A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSecurityStation::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSecurityStation::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkSecurityStation::ArkLocationProperty s_ArkLocationProperty;
	uint64_t m_Location;
	
	class ArkEmailsProperty : public ArkProperty // Id=8016C1B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSecurityStation::ArkEmailsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10592B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSecurityStation::ArkEmailsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10592D0);
		static inline auto FIsArray = PreyFunction<bool(ArkSecurityStation::ArkEmailsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkSecurityStation::ArkEmailsProperty const *const _this, ArkReflectedObject *_pObject)>(0x10592F0);
	};

	static ArkSecurityStation::ArkEmailsProperty s_ArkEmailsProperty;
	std::vector<unsigned __int64> m_Emails;
	
	class ArkPersonnelProperty : public ArkProperty // Id=8016C1C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSecurityStation::ArkPersonnelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14691D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSecurityStation::ArkPersonnelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x14691F0);
		static inline auto FIsArray = PreyFunction<bool(ArkSecurityStation::ArkPersonnelProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkSecurityStation::ArkPersonnelProperty const *const _this, ArkReflectedObject *_pObject)>(0x1059650);
	};

	static ArkSecurityStation::ArkPersonnelProperty s_ArkPersonnelProperty;
	std::vector<unsigned __int64> m_Personnel;
	
	class ArkUtilitiesProperty : public ArkProperty // Id=8016C1D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSecurityStation::ArkUtilitiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107D750);
		static inline auto FIsArray = PreyFunction<bool(ArkSecurityStation::ArkUtilitiesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkSecurityStation::ArkUtilitiesProperty const *const _this, ArkReflectedObject *_pObject)>(0x107D770);
	};

	static ArkSecurityStation::ArkUtilitiesProperty s_ArkUtilitiesProperty;
	std::vector<std::shared_ptr<ArkUtility>> m_Utilities;
	
	class ArkPersonnelTitleProperty : public ArkProperty // Id=8016C1E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkSecurityStation::ArkPersonnelTitleProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkSecurityStation::ArkPersonnelTitleProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4D20);
	};

	static ArkSecurityStation::ArkPersonnelTitleProperty s_ArkPersonnelTitleProperty;
	string m_PersonnelTitle;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetUser(uint64_t arg0);
	const uint64_t &GetUser() const;
	void SetLocation(uint64_t arg0);
	const uint64_t &GetLocation() const;
	std::vector<unsigned __int64> &GetEmails();
	std::vector<unsigned __int64> const &GetEmails() const;
	std::vector<unsigned __int64> &GetPersonnel();
	std::vector<unsigned __int64> const &GetPersonnel() const;
	std::vector<std::shared_ptr<ArkUtility>> &GetUtilities();
	std::vector<std::shared_ptr<ArkUtility>> const &GetUtilities() const;
	void SetPersonnelTitle(string arg0);
	string const &GetPersonnelTitle() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107E630);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107E8B0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkAudioLog
// Header:  Prey/Ark/ArkAudioLog.h
class ArkAudioLog : public ArkReflectedObject
{ // Size=88 (0x58)
public:
	// ArkAudioLog::ArkIDProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLog::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLog::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkAudioLog::ArkNameProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLog::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLog::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkAudioLog::ArkLabelProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLog::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLog::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkAudioLog::ArkConversationProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkConversationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkConversationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLog::ArkConversationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLog::ArkConversationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkAudioLog::ArkKeyCodeProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkKeyCodeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkKeyCodeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLog::ArkKeyCodeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1077BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLog::ArkKeyCodeProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkAudioLog::ArkPasswordProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkPasswordProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPasswordProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLog::ArkPasswordProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLog::ArkPasswordProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkAudioLog::ArkDateProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkDateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLog::ArkDateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLog::ArkDateProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkAudioLog::ArkToProperty
	// Header:  Prey/Ark/ArkAudioLog.h
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

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLog::ArkToProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A5800);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLog::ArkToProperty* const _this, ArkReflectedObject* const _pObject)>(0x1073740);
		static inline auto FIsArray = PreyFunction<bool(const ArkAudioLog::ArkToProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkAudioLog::ArkToProperty* const _this, ArkReflectedObject* _pObject)>(0x1077BE0);
	};

	// ArkAudioLog::ArkFromProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkFromProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFromProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLog::ArkFromProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1077BF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLog::ArkFromProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkAudioLog::ArkIDProperty>(0x2D21480);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkAudioLog::ArkNameProperty>(0x2D214A0);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkAudioLog::ArkLabelProperty>(0x2D214C0);
	string m_Label;
	static inline auto s_ArkConversationProperty = PreyGlobal<ArkAudioLog::ArkConversationProperty>(0x2D214E0);
	uint64_t m_Conversation;
	static inline auto s_ArkKeyCodeProperty = PreyGlobal<ArkAudioLog::ArkKeyCodeProperty>(0x2D21500);
	uint64_t m_KeyCode;
	static inline auto s_ArkPasswordProperty = PreyGlobal<ArkAudioLog::ArkPasswordProperty>(0x2D21520);
	uint64_t m_Password;
	static inline auto s_ArkDateProperty = PreyGlobal<ArkAudioLog::ArkDateProperty>(0x2D21540);
	string m_Date;
	static inline auto s_ArkToProperty = PreyGlobal<ArkAudioLog::ArkToProperty>(0x2D21560);
	std::vector<uint64_t> m_To;
	static inline auto s_ArkFromProperty = PreyGlobal<ArkAudioLog::ArkFromProperty>(0x2D21580);
	uint64_t m_From;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkAudioLog();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetConversation(uint64_t _arg0_);
	const uint64_t& GetConversation() const;
	void SetKeyCode(uint64_t _arg0_);
	const uint64_t& GetKeyCode() const;
	void SetPassword(uint64_t _arg0_);
	const uint64_t& GetPassword() const;
	void SetDate(string _arg0_);
	const string& GetDate() const;
	std::vector<uint64_t>& GetTo();
	const std::vector<uint64_t>& GetTo() const;
	void SetFrom(uint64_t _arg0_);
	const uint64_t& GetFrom() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10789F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1078AF0);
};

// ArkAudioLogCollection
// Header:  Prey/Ark/ArkAudioLog.h
class ArkAudioLogCollection : public ArkReflectedObject
{ // Size=56 (0x38)
public:
	// ArkAudioLogCollection::ArkIDProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLogCollection::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLogCollection::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkAudioLogCollection::ArkNameProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLogCollection::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLogCollection::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkAudioLogCollection::ArkOwnerProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkOwnerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkOwnerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLogCollection::ArkOwnerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086550);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLogCollection::ArkOwnerProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkAudioLogCollection::ArkPlotCriticalProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkPlotCriticalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlotCriticalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLogCollection::ArkPlotCriticalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLogCollection::ArkPlotCriticalProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkAudioLogCollection::ArkLinkedAudioLogsProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkLinkedAudioLogsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkLinkedAudioLogsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLogCollection::ArkLinkedAudioLogsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A7140);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLogCollection::ArkLinkedAudioLogsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A7160);
		static inline auto FIsArray = PreyFunction<bool(const ArkAudioLogCollection::ArkLinkedAudioLogsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkAudioLogCollection::ArkLinkedAudioLogsProperty* const _this, ArkReflectedObject* _pObject)>(0x10A7180);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkAudioLogCollection::ArkIDProperty>(0x2D215A0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkAudioLogCollection::ArkNameProperty>(0x2D215C0);
	string m_Name;
	static inline auto s_ArkOwnerProperty = PreyGlobal<ArkAudioLogCollection::ArkOwnerProperty>(0x2D215E0);
	uint64_t m_Owner;
	static inline auto s_ArkPlotCriticalProperty = PreyGlobal<ArkAudioLogCollection::ArkPlotCriticalProperty>(0x2D21600);
	bool m_PlotCritical;
	static inline auto s_ArkLinkedAudioLogsProperty = PreyGlobal<ArkAudioLogCollection::ArkLinkedAudioLogsProperty>(0x2D21620);
	std::vector<uint64_t> m_LinkedAudioLogs;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkAudioLogCollection();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetOwner(uint64_t _arg0_);
	const uint64_t& GetOwner() const;
	void SetPlotCritical(bool _arg0_);
	const bool& GetPlotCritical() const;
	std::vector<uint64_t>& GetLinkedAudioLogs();
	const std::vector<uint64_t>& GetLinkedAudioLogs() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1078A40);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1078B90);
};

// ArkAudioLogLibrary
// Header:  Prey/Ark/ArkAudioLog.h
class ArkAudioLogLibrary : public ArkReflectedLibrary
{ // Size=56 (0x38)
public:
	// ArkAudioLogLibrary::ArkAudioLogsProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkAudioLogsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkAudioLogsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLogLibrary::ArkAudioLogsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1077C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLogLibrary::ArkAudioLogsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1077D30);
		static inline auto FIsArray = PreyFunction<bool(const ArkAudioLogLibrary::ArkAudioLogsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkAudioLogLibrary::ArkAudioLogsProperty* const _this, ArkReflectedObject* _pObject)>(0x1077D70);
	};

	// ArkAudioLogLibrary::ArkAudioLogCollectionsProperty
	// Header:  Prey/Ark/ArkAudioLog.h
	class ArkAudioLogCollectionsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkAudioLogCollectionsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAudioLogLibrary::ArkAudioLogCollectionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1077A60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAudioLogLibrary::ArkAudioLogCollectionsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1077B00);
		static inline auto FIsArray = PreyFunction<bool(const ArkAudioLogLibrary::ArkAudioLogCollectionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkAudioLogLibrary::ArkAudioLogCollectionsProperty* const _this, ArkReflectedObject* _pObject)>(0x1077B40);
	};

	static inline auto s_ArkAudioLogsProperty = PreyGlobal<ArkAudioLogLibrary::ArkAudioLogsProperty>(0x2D21640);
	std::vector<ArkAudioLog> m_AudioLogs;
	static inline auto s_ArkAudioLogCollectionsProperty = PreyGlobal<ArkAudioLogLibrary::ArkAudioLogCollectionsProperty>(0x2D21660);
	std::vector<ArkAudioLogCollection> m_AudioLogCollections;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	std::vector<ArkAudioLog>& GetAudioLogs();
	const std::vector<ArkAudioLog>& GetAudioLogs() const;
	std::vector<ArkAudioLogCollection>& GetAudioLogCollections();
	const std::vector<ArkAudioLogCollection>& GetAudioLogCollections() const;
	const ArkAudioLogCollection* FindAudioLogCollection(const uint64_t _arg0_) const;
	const ArkAudioLogCollection* FindAudioLogCollection(const char* _arg0_) const;
	const ArkAudioLog* FindAudioLog(const uint64_t _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1078A90);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1078C30);
	static inline auto FInit = PreyFunction<bool(ArkAudioLogLibrary* const _this)>(0x1078D20);
};
#endif // !MOONCRASH
