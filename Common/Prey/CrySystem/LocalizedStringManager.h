// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CrySystem/ILocalizationManager.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CryCore/Containers/VectorMap.h>

class HuffmanCoder;
class ICrySizer;
struct ISystem;
struct ITempLocStringStorage;
struct IXmlTableReader;
struct SLocalizedInfoEditor;
struct SLocalizedInfoGame;
struct SLocalizedSoundInfoGame;

// Header: Exact
// CryEngine/crysystem/localizedstringmanager.h
class CLocalizedStringsManager : public ILocalizationManager, public ISystemEventListener // Id=800F742 Size=208
{
public:
    struct SLocalizedStringEntry;
	using TLocalizationTagVec = std::vector<string>;
	
	static constexpr const uint64_t LOADING_FIXED_STRING_LENGTH = 1024;
	static constexpr const uint64_t COMPRESSION_FIXED_BUFFER_LENGTH = 3072;
	
	struct SLocalizedStringEntryEditorExtension // Id=800F748 Size=56
	{
		string sfileName;
		string sKey;
		string sOriginalActorLine;
		wstring swTranslatedActorLine;
		string sOriginalText;
		string sOriginalCharacterName;
		unsigned nRow;
		
#if 0
		void GetMemoryUsage(ICrySizer *arg0) const;
#endif
	};

	struct SLanguage // Id=800F749 Size=88
	{
		using TLocalizedStringEntries = std::vector<CLocalizedStringsManager::SLocalizedStringEntry *>;
		using THuffmanCoders = std::vector<HuffmanCoder *>;
		
		ELanguageID languageID;
		string sLanguage;
		VectorMap<unsigned int,CLocalizedStringsManager::SLocalizedStringEntry *,std::less<unsigned int>,std::allocator<std::pair<unsigned int,CLocalizedStringsManager::SLocalizedStringEntry *> > > m_keysMap;
		std::vector<CLocalizedStringsManager::SLocalizedStringEntry *> m_vLocalizedStrings;
		std::vector<HuffmanCoder *> m_vEncoders;
		
		void GetMemoryUsage(ICrySizer *pSizer) const { FGetMemoryUsage(this,pSizer); }
		
		static inline auto FGetMemoryUsage = PreyFunction<void(CLocalizedStringsManager::SLanguage const *const _this, ICrySizer *pSizer)>(0xE548E0);
	};

	struct SLocalizedStringEntry // Id=800F785 Size=64
	{
		enum
		{
			USE_SUBTITLE = 1,
			IS_DIRECTED_RADIO = 2,
			IS_INTERCEPTED = 4,
			IS_COMPRESSED = 8,
		};

		union trans_text // Id=800F74D Size=8
		{
		public:
			wstring *pswUncompressed;
			uint8_t *szCompressed;
		};

		string sCharacterName;
		CLocalizedStringsManager::SLocalizedStringEntry::trans_text TranslatedText;
		string sPrototypeSoundEvent;
		uint16_t fVolume;
		uint16_t fRadioRatio;
		DynArray<SLocalizedAdvancesSoundEntry,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > SoundMoods;
		DynArray<SLocalizedAdvancesSoundEntry,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > EventParameters;
		uint8_t flags;
		int8_t huffmanTreeIndex;
		uint8_t nTagID;
		CLocalizedStringsManager::SLocalizedStringEntryEditorExtension *pEditorExtension;

		~SLocalizedStringEntry();
		wstring GetTranslatedText(CLocalizedStringsManager::SLanguage const *pLanguage) const { return FGetTranslatedText(this,pLanguage); }

#if 0
		void GetMemoryUsage(ICrySizer *arg0) const;
#endif

		static inline auto FBitNotSLocalizedStringEntry = PreyFunction<void(CLocalizedStringsManager::SLocalizedStringEntry *const _this)>(0xE52AC0);
		static inline auto FGetTranslatedText = PreyFunction<wstring(CLocalizedStringsManager::SLocalizedStringEntry const *const _this, CLocalizedStringsManager::SLanguage const *pLanguage)>(0xE54C50);
	};

	using StringsKeyMap = VectorMap<unsigned int,CLocalizedStringsManager::SLocalizedStringEntry *,std::less<unsigned int>,std::allocator<std::pair<unsigned int,CLocalizedStringsManager::SLocalizedStringEntry *> > >;
	
	struct SFileInfo // Id=800F786 Size=2
	{
		bool bDataStripping;
		uint8_t nTagID;
	};

	ISystem *m_pSystem;
	CLocalizedStringsManager::SLanguage *m_pLanguage;
	
	using pairFileName = std::pair<string,CLocalizedStringsManager::SFileInfo>;
	using tmapFilenames = std::map<string,CLocalizedStringsManager::SFileInfo,std::less<string>,std::allocator<std::pair<CryStringT<char> const,CLocalizedStringsManager::SFileInfo>>>;
	
	std::map<string,CLocalizedStringsManager::SFileInfo,std::less<string>,std::allocator<std::pair<CryStringT<char> const,CLocalizedStringsManager::SFileInfo>>> m_loadedTables;
	
	using TStringVec = std::vector<string>;
	
	struct STag // Id=800F7AA Size=56
	{
		std::vector<string> filenames;
		std::vector<string> directories;
		uint8_t id;
		bool loaded;
	};

	using TTagFileNames = std::map<string,CLocalizedStringsManager::STag,std::less<string>,std::allocator<std::pair<CryStringT<char> const,CLocalizedStringsManager::STag>>>;
	
	std::map<string,CLocalizedStringsManager::STag,std::less<string>,std::allocator<std::pair<CryStringT<char> const,CLocalizedStringsManager::STag>>> m_tagFileNames;
	std::vector<string> m_tagLoadRequests;
	std::vector<CLocalizedStringsManager::SLanguage *> m_languages;
	
	using PrototypeSoundEvents = std::set<string,std::less<string>>;
	
	std::set<string,std::less<string>> m_prototypeEvents;
	
//	struct less_strcmp : public std::binary_function<CryStringT<char> const &,CryStringT<char> const &,bool> // Id=800F7D9 Size=1
//	{
//#if 0
//		bool operator()(string const &arg0, string const &arg1) const;
//#endif
//	};

//	using CharacterNameSet = std::set<string,CLocalizedStringsManager::less_strcmp>;
	
	std::set<string> m_characterNameSet;
	DynArray<wchar_t,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_tempWString;
	int m_cvarLocalizationDebug;
	int m_cvarLocalizationEncode;
	unsigned m_availableLocalizations;
	CryCriticalSection m_cs;
	
	using AutoLock = CryAutoLock<CryCriticalSection>;
	
	CLocalizedStringsManager(ISystem *pSystem);
	virtual ~CLocalizedStringsManager();
	virtual ELanguageID LanguageIDFromName(const char *_szName) const;
	virtual const char *LanguageNameFromID(ELanguageID _id) const;
	virtual unsigned IsLanguageSupported(ELanguageID id) const;
	unsigned IsLanguageSupported(const char *_szName) const { return FIsLanguageSupportedOv0(this,_szName); }
	void SetAvailableLanguages(unsigned _languages) { FSetAvailableLanguages(this,_languages); }
	virtual bool SetLanguage(const char *sLanguage);
	virtual const char *GetLanguage() const;
	virtual ELanguageID GetLanguageID() const;
	virtual bool InitLocalizationData(const char *sFileName, bool bReload);
	virtual bool RequestLoadLocalizationDataByTag(const char *sTag);
	virtual bool LoadLocalizationDataByTag(const char *sTag, bool bReload);
	virtual bool ReleaseLocalizationDataByTag(const char *sTag);
	virtual bool LoadExcelXmlSpreadsheet(const char *sFileName, bool bReload);
	virtual void ReloadData();
	virtual void FreeData();
	virtual bool LocalizeString(string const &sString, wstring &outLocalizedString, bool bEnglish);
	virtual bool LocalizeString(const char *sString, wstring &outLocalizedString, bool bEnglish);
	virtual bool LocalizeLabel(const char *sLabel, wstring &outLocalString, bool bEnglish, ITempLocStringStorage **ppTmpStorage);
	virtual bool GetLocalizedInfoByKey(const char *sKey, SLocalizedInfoGame &outGameInfo);
	virtual bool GetLocalizedInfoByKey(const char *sKey, SLocalizedSoundInfoGame *pOutSoundInfo);
	virtual bool GetLocalizedInfoByKey(const char *_sKey, SLocalizedInfoEditor &outEditorInfo);
	virtual int GetLocalizedStringCount();
	virtual bool GetLocalizedInfoByIndex(int nIndex, SLocalizedInfoGame &outGameInfo);
	virtual bool GetLocalizedInfoByIndex(int nIndex, SLocalizedInfoEditor &outEditorInfo);
	virtual bool GetEnglishString(const char *sKey, string &sLocalizedString);
	virtual bool GetSubtitle(const char *sKeyOrLabel, wstring &outSubtitle, bool bForceSubtitle);
	virtual void FormatStringMessage(string &outString, string const &sString, const char **sParams, int nParams);
	virtual void FormatStringMessage(string &outString, string const &sString, const char *param1, const char *param2, const char *param3, const char *param4);
	virtual void FormatStringMessage(wstring &outString, wstring const &sString, const wchar_t **sParams, int nParams);
	virtual void FormatStringMessage(wstring &outString, wstring const &sString, const wchar_t *param1, const wchar_t *param2, const wchar_t *param3, const wchar_t *param4);
	virtual wchar_t ToUpperCase(wchar_t c);
	virtual wchar_t ToLowerCase(wchar_t c);
	virtual void LocalizeTime(int64_t t, bool bMakeLocalTime, bool bShowSeconds, wstring &outTimeString);
	virtual void LocalizeDate(int64_t t, bool bMakeLocalTime, bool bShort, bool bIncludeWeekday, wstring &outDateString);
	virtual void LocalizeDuration(int seconds, wstring &outDurationString);
	virtual void LocalizeNumber(int number, wstring &outNumberString);
	virtual void LocalizeNumber(float number, int decimals, wstring &outNumberString);
	virtual void OnSystemEvent(ESystemEvent eEvent, uint64_t wparam, uint64_t lparam);
	int GetMemoryUsage(ICrySizer *pSizer) { return FGetMemoryUsage(this,pSizer); }
	void GetLoadedTags(std::vector<string> &tagVec) { FGetLoadedTags(this,tagVec); }
	void FreeLocalizationData() { FFreeLocalizationData(this); }
	void LocalizeLabelAssignOutput(const char *pStr, wstring &regularOut, ITempLocStringStorage **ppTmpOut) { FLocalizeLabelAssignOutputOv1(this,pStr,regularOut,ppTmpOut); }
	void LocalizeLabelAssignOutput(const wchar_t *pStr, wstring &regularOut, ITempLocStringStorage **ppTmpOut) { FLocalizeLabelAssignOutputOv0(this,pStr,regularOut,ppTmpOut); }
	bool DoLoadExcelXmlSpreadsheet(const char *sFileName, uint8_t nTagID, bool bReload, bool isDirectory) { return FDoLoadExcelXmlSpreadsheet(this,sFileName,nTagID,bReload,isDirectory); }
	bool _DoLoadExcelXmlSpreadsheet(IXmlTableReader *const pXmlTableReader, const char *sFileName, uint8_t nTagID, HuffmanCoder *pEncoder) { return F_DoLoadExcelXmlSpreadsheet(this,pXmlTableReader,sFileName,nTagID,pEncoder); }
	void AppendToUnicodeString(wstring &sDest, const char *szSource) { FAppendToUnicodeStringOv0(this,sDest,szSource); }
	void ParseFirstLine(IXmlTableReader *pXmlTableReader, char *nCellIndexToType, std::map<int,string,std::less<int>> &SoundMoodIndex, std::map<int,string,std::less<int>> &EventParameterIndex) { FParseFirstLine(this,pXmlTableReader,nCellIndexToType,SoundMoodIndex,EventParameterIndex); }
	void InternalSetCurrentLanguage(CLocalizedStringsManager::SLanguage *pLanguage) { FInternalSetCurrentLanguage(this,pLanguage); }
	
#if 0
	int CompressWChar(void *arg0, unsigned &arg1, const void *arg2, unsigned arg3, int arg4);
	int UncompressWChar(void *arg0, unsigned &arg1, const void *arg2, unsigned arg3);
	void LocalizedStringsManagerWarning(... arg0);
	void ListAndClearProblemLabels();
	void AppendToUnicodeString(wstring &arg0, CryFixedStringT<1024> const &arg1);
	void AppendToUnicodeString(wstring &arg0, string const &arg1);
	void AddLocalizedString(CLocalizedStringsManager::SLanguage *arg0, CLocalizedStringsManager::SLocalizedStringEntry *arg1, const unsigned arg2);
	void AddControl(int arg0);
#endif
	
	static inline auto FBitNotCLocalizedStringsManager = PreyFunction<void(CLocalizedStringsManager *const _this)>(0xE528C0);
	static inline auto FLanguageIDFromName = PreyFunction<ELanguageID(CLocalizedStringsManager const *const _this, const char *_szName)>(0xE556A0);
	static inline auto FLanguageNameFromID = PreyFunction<const char *(CLocalizedStringsManager const *const _this, ELanguageID _id)>(0xE55710);
	static inline auto FIsLanguageSupportedOv1 = PreyFunction<unsigned(CLocalizedStringsManager const *const _this, ELanguageID id)>(0xE55680);
	static inline auto FIsLanguageSupportedOv0 = PreyFunction<unsigned(CLocalizedStringsManager const *const _this, const char *_szName)>(0xE55650);
	static inline auto FSetAvailableLanguages = PreyFunction<void(CLocalizedStringsManager *const _this, unsigned _languages)>(0xE582C0);
	static inline auto FSetLanguage = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sLanguage)>(0xE582D0);
	static inline auto FGetLanguage = PreyFunction<const char *(CLocalizedStringsManager const *const _this)>(0xE53C80);
	static inline auto FGetLanguageID = PreyFunction<ELanguageID(CLocalizedStringsManager const *const _this)>(0xE53CA0);
	static inline auto FInitLocalizationData = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sFileName, bool bReload)>(0xE54E00);
	static inline auto FRequestLoadLocalizationDataByTag = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sTag)>(0xE580D0);
	static inline auto FLoadLocalizationDataByTag = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sTag, bool bReload)>(0xE55740);
	static inline auto FReleaseLocalizationDataByTag = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sTag)>(0xE57500);
	static inline auto FLoadExcelXmlSpreadsheet = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sFileName, bool bReload)>(0xE55720);
	static inline auto FReloadData = PreyFunction<void(CLocalizedStringsManager *const _this)>(0xE57DB0);
	static inline auto FFreeData = PreyFunction<void(CLocalizedStringsManager *const _this)>(0xE53830);
	static inline auto FLocalizeStringOv1 = PreyFunction<bool(CLocalizedStringsManager *const _this, string const &sString, wstring &outLocalizedString, bool bEnglish)>(0xE56A40);
	static inline auto FLocalizeStringOv0 = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sString, wstring &outLocalizedString, bool bEnglish)>(0xE56D70);
	static inline auto FLocalizeLabel = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sLabel, wstring &outLocalString, bool bEnglish, ITempLocStringStorage **ppTmpStorage)>(0xE55FC0);
	static inline auto FGetLocalizedInfoByKeyOv2 = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sKey, SLocalizedInfoGame &outGameInfo)>(0xE54060);
	static inline auto FGetLocalizedInfoByKeyOv1 = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sKey, SLocalizedSoundInfoGame *pOutSoundInfo)>(0xE54180);
	static inline auto FGetLocalizedInfoByKeyOv0 = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *_sKey, SLocalizedInfoEditor &outEditorInfo)>(0xE53EF0);
	static inline auto FGetLocalizedStringCount = PreyFunction<int(CLocalizedStringsManager *const _this)>(0xE545E0);
	static inline auto FGetLocalizedInfoByIndexOv1 = PreyFunction<bool(CLocalizedStringsManager *const _this, int nIndex, SLocalizedInfoGame &outGameInfo)>(0xE53E50);
	static inline auto FGetLocalizedInfoByIndexOv0 = PreyFunction<bool(CLocalizedStringsManager *const _this, int nIndex, SLocalizedInfoEditor &outEditorInfo)>(0xE53D60);
	static inline auto FGetEnglishString = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sKey, string &sLocalizedString)>(0xE53AE0);
	static inline auto FGetSubtitle = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sKeyOrLabel, wstring &outSubtitle, bool bForceSubtitle)>(0xE54A80);
	static inline auto FFormatStringMessageOv3 = PreyFunction<void(CLocalizedStringsManager *const _this, string &outString, string const &sString, const char **sParams, int nParams)>(0xE535C0);
	static inline auto FFormatStringMessageOv2 = PreyFunction<void(CLocalizedStringsManager *const _this, string &outString, string const &sString, const char *param1, const char *param2, const char *param3, const char *param4)>(0xE535E0);
	static inline auto FFormatStringMessageOv1 = PreyFunction<void(CLocalizedStringsManager *const _this, wstring &outString, wstring const &sString, const wchar_t **sParams, int nParams)>(0xE53640);
	static inline auto FFormatStringMessageOv0 = PreyFunction<void(CLocalizedStringsManager *const _this, wstring &outString, wstring const &sString, const wchar_t *param1, const wchar_t *param2, const wchar_t *param3, const wchar_t *param4)>(0xE53660);
	static inline auto FToUpperCase = PreyFunction<wchar_t(CLocalizedStringsManager *const _this, wchar_t c)>(0xE584E0);
	static inline auto FToLowerCase = PreyFunction<wchar_t(CLocalizedStringsManager *const _this, wchar_t c)>(0xE58480);
	static inline auto FLocalizeTime = PreyFunction<void(CLocalizedStringsManager *const _this, int64_t t, bool bMakeLocalTime, bool bShowSeconds, wstring &outTimeString)>(0xE56E50);
	static inline auto FLocalizeDate = PreyFunction<void(CLocalizedStringsManager *const _this, int64_t t, bool bMakeLocalTime, bool bShort, bool bIncludeWeekday, wstring &outDateString)>(0xE55C50);
	static inline auto FLocalizeDuration = PreyFunction<void(CLocalizedStringsManager *const _this, int seconds, wstring &outDurationString)>(0xE55E90);
	static inline auto FLocalizeNumberOv1 = PreyFunction<void(CLocalizedStringsManager *const _this, int number, wstring &outNumberString)>(0xE565D0);
	static inline auto FLocalizeNumberOv0 = PreyFunction<void(CLocalizedStringsManager *const _this, float number, int decimals, wstring &outNumberString)>(0xE567B0);
	static inline auto FOnSystemEvent = PreyFunction<void(CLocalizedStringsManager *const _this, ESystemEvent eEvent, uint64_t wparam, uint64_t lparam)>(0xE57020);
	static inline auto FGetMemoryUsage = PreyFunction<int(CLocalizedStringsManager *const _this, ICrySizer *pSizer)>(0xE54600);
	static inline auto FGetLoadedTags = PreyFunction<void(CLocalizedStringsManager *const _this, std::vector<string> &tagVec)>(0xE53CC0);
	static inline auto FFreeLocalizationData = PreyFunction<void(CLocalizedStringsManager *const _this)>(0xE53900);
	static inline auto FLocalizeLabelAssignOutputOv1 = PreyFunction<void(CLocalizedStringsManager *const _this, const char *pStr, wstring &regularOut, ITempLocStringStorage **ppTmpOut)>(0xE563E0);
	static inline auto FLocalizeLabelAssignOutputOv0 = PreyFunction<void(CLocalizedStringsManager *const _this, const wchar_t *pStr, wstring &regularOut, ITempLocStringStorage **ppTmpOut)>(0xE56500);
	static inline auto FDoLoadExcelXmlSpreadsheet = PreyFunction<bool(CLocalizedStringsManager *const _this, const char *sFileName, uint8_t nTagID, bool bReload, bool isDirectory)>(0xE52DB0);
	static inline auto F_DoLoadExcelXmlSpreadsheet = PreyFunction<bool(CLocalizedStringsManager *const _this, IXmlTableReader *const pXmlTableReader, const char *sFileName, uint8_t nTagID, HuffmanCoder *pEncoder)>(0xE589A0);
	static inline auto FAppendToUnicodeStringOv0 = PreyFunction<void(CLocalizedStringsManager *const _this, wstring &sDest, const char *szSource)>(0xE52D10);
	static inline auto FParseFirstLine = PreyFunction<void(CLocalizedStringsManager *const _this, IXmlTableReader *pXmlTableReader, char *nCellIndexToType, std::map<int,string,std::less<int>> &SoundMoodIndex, std::map<int,string,std::less<int>> &EventParameterIndex)>(0xE57170);
	static inline auto FInternalSetCurrentLanguage = PreyFunction<void(CLocalizedStringsManager *const _this, CLocalizedStringsManager::SLanguage *pLanguage)>(0xE555B0);
};

