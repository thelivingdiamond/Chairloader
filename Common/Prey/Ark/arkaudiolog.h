// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

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

