// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/Containers/CryListenerSet.h>
#include <Prey/CryCore/Platform/IPlatformOS.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CrySystem/PlatformOS/PlatformOS_Base.h>
#include <Prey/CrySystem/ISystem.h>

enum class EArkFirstPartyEnvironment;
enum class EArkFirstPartyEnvironmentQueryResponse;
enum EFileState;
enum ELanguageID;
enum ESystemEvent;
struct IConsoleCmdArgs;
class ICrySizer;
struct ILoadGame;
struct ISaveGame;
struct IStringVerifyEvents;
struct IVirtualKeyboardEvents;
struct SActionEvent;
struct SRichPresenceData;
struct SUserPII;
struct SUserXUID;
namespace ZipDir
{
class CacheRW;
class FileEntryTree;
} // namespace ZipDir

// CPlatformOS_PC
// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
class CPlatformOS_PC
	: public CPlatformOS_Base
	, public IPlatformOS::IPlatformListener
	, public ISystemEventListener
	, public IGameFrameworkListener
{ // Size=200 (0xC8)
public:
	CPlatformOS_Base::CStableFPSWatcher m_fpsWatcher;
	CListenerSet<IPlatformOS::IPlatformListener *> m_listeners;
	std::vector<char> m_encryptionMagic;
	std::vector<unsigned char> m_encryptionKey;
	float m_delayLevelStartIcon;
	int m_cachePakStatus;
	unsigned m_cachePakUserId;
	bool m_bSignedIn;
	bool m_bSaving;
	bool m_bAllowMessageBox;
	bool m_bLevelLoad;
	bool m_bSaveDuringLevelLoad;
	CStreamingInstallBase m_streamingInstallObject;
	string m_systemLanguage;
	float m_richPresenceSendTimer;
	unsigned m_richPresenceUserId;
	string m_richPresenceId;
	
	CPlatformOS_PC(const uint8_t createParams);
	virtual unsigned InitLanguageInfo(unsigned _languagesWithData);
	virtual void Tick(float realFrameTime);
	virtual const char* GetPlatformName() const;
	virtual unsigned UserGetMaximumSignedInUsers() const;
	virtual bool UserIsSignedIn(unsigned userIndex) const;
	virtual bool UserDoSignIn(unsigned userId);
	virtual void UserSignOut(unsigned userId);
	virtual unsigned GetFirstSignedInUser() const;
	virtual unsigned UserGetPlayerIndex(const char* userName) const;
	virtual unsigned UserGetPlayerId(const char* const userName) const;
	virtual bool UserGetName(unsigned userIndex, CryFixedStringT<257>& outName) const;
	virtual unsigned UserGetId(const SUserXUID& __unnamed1) const;
	virtual bool UserGetXUID(unsigned userId, SUserXUID& __unnamed1) const;
	virtual bool UserGetOnlineName(unsigned userIndex, CryFixedStringT<257>& outName) const;
	virtual bool UserSelectStorageDevice(unsigned userIndex, bool bForceUI);
	virtual bool GetUserProfilePreference(unsigned user, IPlatformOS::EUserProfilePreference ePreference, IPlatformOS::SUserProfileVariant& outResult) const;
	virtual bool MountSaveFile(unsigned userIndex);
	virtual unsigned GetUserPairedToDevice(uint64_t __unnamed1);
	virtual int GetDevicesPairedToUser(unsigned userId, std::vector<uint64_t>& outDeviceIds) const;
	virtual std::shared_ptr<IPlatformOS::IFileFinder> GetFileFinder(const char* _szPattern, unsigned _user);
	virtual IFileFinder::EFileState FileExists(const char* _szPath, unsigned _user);
	virtual void MountDLCContent(IPlatformOS::IDLCListener* pCallback, unsigned user, const uint8_t* keyData);
	virtual bool CanRestartTitle() const;
	virtual void RestartTitle(const char* pLoadFrom);
	virtual bool BeginSaveLoad(unsigned user, bool bSave);
	virtual void EndSaveLoad(unsigned user);
	virtual std::shared_ptr<IPlatformOS::ISaveReader> SaveGetReader(const char* fileName, unsigned _userId);
	virtual std::shared_ptr<IPlatformOS::ISaveWriter> SaveGetWriter(const char* fileName, unsigned _userId);
	virtual bool SaveCopyFiles(const char* _szSource, const char* _szDestination, const char* _szPattern, unsigned user);
	virtual bool KeyboardStart(unsigned inUserIndex, unsigned flags, const wchar_t* title, const wchar_t* initialInput, int maxInputLength, IVirtualKeyboardEvents* pInCallback);
	virtual bool KeyboardIsRunning();
	virtual bool KeyboardCancel();
	virtual bool StringVerifyStart(const wchar_t* inString, IStringVerifyEvents* pInCallback);
	virtual bool IsVerifyingString();
	virtual void AddListener(IPlatformOS::IPlatformListener* pListener, const char* szName);
	virtual void RemoveListener(IPlatformOS::IPlatformListener* pListener);
	virtual void NotifyListeners(IPlatformOS::SPlatformEvent& event);
	virtual const char* GetSKUId();
	virtual unsigned GetBaseServiceLabelForCurrentSku() const;
	virtual unsigned GetLeadServiceLabelForCurrentSku() const;
	virtual IPlatformOS::EMsgBoxResult DebugMessageBox(const char* body, const char* title, unsigned flags) const;
	virtual bool PostLocalizationBootChecks();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual bool DebugSave(IPlatformOS::SDebugDump& dump);
	virtual bool ConsoleLoadGame(IConsoleCmdArgs* pArgs);
	virtual const char* const GetHostName();
	virtual void InitEncryptionKey(const char* pMagic, uint64_t magicLength, const uint8_t* pKey, uint64_t keyLength);
	virtual void GetEncryptionKey(const std::vector<char>* * pMagic, const std::vector<unsigned char>* * pKey);
	virtual bool IsStoreCompleted();
	virtual bool IsTrial() const;
	virtual void ShowStoreProduct(const char* _productId, unsigned __unnamed1);
	virtual EArkFirstPartyEnvironmentQueryResponse QueryFirstPartyEnvironment(EArkFirstPartyEnvironment& _env);
	virtual EUserPIIStatus GetUserPII(unsigned inUser, SUserPII* pOutPII);
	virtual IPlatformOS::ECDP_Start StartUsingCachePaks(unsigned userId, bool* outWritesOccurred);
	virtual IPlatformOS::ECDP_End EndUsingCachePaks(unsigned userId);
	virtual IPlatformOS::ECDP_Open DoesCachePakExist(const char* const filename, const uint64_t size, uint8_t* md5);
	virtual IPlatformOS::ECDP_Open OpenCachePak(const char* const filename, const char* const bindRoot, const uint64_t size, uint8_t* md5);
	virtual IPlatformOS::ECDP_Close CloseCachePak(const char* const filename);
	virtual IPlatformOS::ECDP_Delete DeleteCachePak(const char* const filename);
	virtual IPlatformOS::ECDP_Write WriteCachePak(const char* const filename, const void* const pData, const uint64_t numBytes);
	virtual IPlatformOS::EZipExtractFail ExtractZips(const char* path);
	virtual void SetOpticalDriveIdle(bool bIdle);
	virtual void AllowOpticalDriveUsage(bool bAllow);
	virtual bool GetLocalIPAddress(char* ipAddress, unsigned& ip, int length) const;
	virtual CStreamingInstallBase* GetStreamingInstall();
	virtual ELanguageID GetLanguageIDFromName(const char* languageName) const;
	virtual void OnPlatformEvent(const IPlatformOS::SPlatformEvent& _event);
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual void OnPostUpdate(float fDeltaTime);
	virtual void OnSaveGame(ISaveGame* pSaveGame);
	virtual void OnLoadGame(ILoadGame* pLoadGame);
	virtual void OnLevelEnd(const char* nextLevel);
	virtual void OnActionEvent(const SActionEvent& event);
	virtual bool SetRichPresence(unsigned userId, const SRichPresenceData* richPresenceData);
	// IPlatformOS::EZipExtractFail RecurseZipContents(ZipDir::FileEntryTree* pSourceDir, const char* currentPath, _smart_ptr<ZipDir::CacheRW> pCache) { return FRecurseZipContents(this, pSourceDir, currentPath, pCache); }
	// bool SxmlMissingFromHDD(ZipDir::FileEntryTree* pZipRoot, const char* userPath, _smart_ptr<ZipDir::CacheRW> pZip) { return FSxmlMissingFromHDD(this, pZipRoot, userPath, pZip); }
	
#if 0
	bool SendRichPresence(unsigned _arg0_, const string& _arg1_);
	void SaveDirtyFiles();
	bool DecryptAndCheckSigning(const char* _arg0_, int _arg1_, char* * _arg2_, int* _arg3_, const uint8_t* _arg4_);
	bool UseSteamReadWriter() const;
#endif
	
	static inline auto FCPlatformOS_PCOv2 = PreyFunction<void(CPlatformOS_PC* const _this, const uint8_t createParams)>(0xE75AD0);
	static inline auto FInitLanguageInfo = PreyFunction<unsigned(CPlatformOS_PC* const _this, unsigned _languagesWithData)>(0xE76C70);
	static inline auto FTick = PreyFunction<void(CPlatformOS_PC* const _this, float realFrameTime)>(0xE78270);
	static inline auto FGetPlatformName = PreyFunction<const char* (const CPlatformOS_PC* const _this)>(0xE76BD0);
	static inline auto FUserGetMaximumSignedInUsers = PreyFunction<unsigned(const CPlatformOS_PC* const _this)>(0x1B1DEA0);
	static inline auto FUserIsSignedIn = PreyFunction<bool(const CPlatformOS_PC* const _this, unsigned userIndex)>(0xE78670);
	static inline auto FUserDoSignIn = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned userId)>(0xE78480);
	static inline auto FUserSignOut = PreyFunction<void(CPlatformOS_PC* const _this, unsigned userId)>(0xA13080);
	static inline auto FGetFirstSignedInUser = PreyFunction<unsigned(const CPlatformOS_PC* const _this)>(0xE768C0);
	static inline auto FUserGetPlayerIndex = PreyFunction<unsigned(const CPlatformOS_PC* const _this, const char* userName)>(0x158AEF0);
	static inline auto FUserGetPlayerId = PreyFunction<unsigned(const CPlatformOS_PC* const _this, const char* const userName)>(0x158AEF0);
	static inline auto FUserGetName = PreyFunction<bool(const CPlatformOS_PC* const _this, unsigned userIndex, CryFixedStringT<257>& outName)>(0xE784F0);
	static inline auto FUserGetId = PreyFunction<unsigned(const CPlatformOS_PC* const _this, const SUserXUID& __unnamed1)>(0x158AEF0);
	static inline auto FUserGetXUID = PreyFunction<bool(const CPlatformOS_PC* const _this, unsigned userId, SUserXUID& __unnamed1)>(0xDD23F0);
	static inline auto FUserGetOnlineName = PreyFunction<bool(const CPlatformOS_PC* const _this, unsigned userIndex, CryFixedStringT<257>& outName)>(0x1B3C9D0);
	static inline auto FUserSelectStorageDevice = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned userIndex, bool bForceUI)>(0x1B933B0);
	static inline auto FGetUserProfilePreference = PreyFunction<bool(const CPlatformOS_PC* const _this, unsigned user, IPlatformOS::EUserProfilePreference ePreference, IPlatformOS::SUserProfileVariant& outResult)>(0xDD23F0);
	static inline auto FMountSaveFile = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned userIndex)>(0x1B933B0);
	static inline auto FGetUserPairedToDevice = PreyFunction<unsigned(CPlatformOS_PC* const _this, uint64_t __unnamed1)>(0x158AEF0);
	static inline auto FGetDevicesPairedToUser = PreyFunction<int(const CPlatformOS_PC* const _this, unsigned userId, std::vector<uint64_t>& outDeviceIds)>(0xE76830);
	static inline auto FGetFileFinder = PreyFunction<std::shared_ptr<IPlatformOS::IFileFinder>*(CPlatformOS_PC* const _this, std::shared_ptr<IPlatformOS::IFileFinder>* _return_value_, const char* _szPattern, unsigned _user)>(0xE76860);
	static inline auto FFileExists = PreyFunction<EFileState(CPlatformOS_PC* const _this, const char* _szPath, unsigned _user)>(0xE76820);
	static inline auto FMountDLCContent = PreyFunction<void(CPlatformOS_PC* const _this, IPlatformOS::IDLCListener* pCallback, unsigned user, const uint8_t* keyData)>(0xE76E40);
	static inline auto FCanRestartTitle = PreyFunction<bool(const CPlatformOS_PC* const _this)>(0x1B933B0);
	static inline auto FRestartTitle = PreyFunction<void(CPlatformOS_PC* const _this, const char* pLoadFrom)>(0xE77960);
	static inline auto FBeginSaveLoad = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned user, bool bSave)>(0xE75EC0);
	static inline auto FEndSaveLoad = PreyFunction<void(CPlatformOS_PC* const _this, unsigned user)>(0xE764D0);
	static inline auto FSaveGetReader = PreyFunction<std::shared_ptr<IPlatformOS::ISaveReader>*(CPlatformOS_PC* const _this, std::shared_ptr<IPlatformOS::ISaveReader>* _return_value_, const char* fileName, unsigned _userId)>(0xE77D10);
	static inline auto FSaveGetWriter = PreyFunction<std::shared_ptr<IPlatformOS::ISaveWriter>*(CPlatformOS_PC* const _this, std::shared_ptr<IPlatformOS::ISaveWriter>* _return_value_, const char* fileName, unsigned _userId)>(0xE77DF0);
	static inline auto FSaveCopyFiles = PreyFunction<bool(CPlatformOS_PC* const _this, const char* _szSource, const char* _szDestination, const char* _szPattern, unsigned user)>(0xE77CF0);
	static inline auto FKeyboardStart = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned inUserIndex, unsigned flags, const wchar_t* title, const wchar_t* initialInput, int maxInputLength, IVirtualKeyboardEvents* pInCallback)>(0xDD23F0);
	static inline auto FKeyboardIsRunning = PreyFunction<bool(CPlatformOS_PC* const _this)>(0xDD23F0);
	static inline auto FKeyboardCancel = PreyFunction<bool(CPlatformOS_PC* const _this)>(0xDD23F0);
	static inline auto FStringVerifyStart = PreyFunction<bool(CPlatformOS_PC* const _this, const wchar_t* inString, IStringVerifyEvents* pInCallback)>(0xDD23F0);
	static inline auto FIsVerifyingString = PreyFunction<bool(CPlatformOS_PC* const _this)>(0xDD23F0);
	static inline auto FAddListener = PreyFunction<void(CPlatformOS_PC* const _this, IPlatformOS::IPlatformListener* pListener, const char* szName)>(0xE75E70);
	static inline auto FRemoveListener = PreyFunction<void(CPlatformOS_PC* const _this, IPlatformOS::IPlatformListener* pListener)>(0xE778F0);
	static inline auto FNotifyListeners = PreyFunction<void(CPlatformOS_PC* const _this, IPlatformOS::SPlatformEvent& event)>(0xE77370);
	static inline auto FGetSKUId = PreyFunction<const char* (CPlatformOS_PC* const _this)>(0x158AEF0);
	static inline auto FGetBaseServiceLabelForCurrentSku = PreyFunction<unsigned(const CPlatformOS_PC* const _this)>(0x158AEF0);
	static inline auto FGetLeadServiceLabelForCurrentSku = PreyFunction<unsigned(const CPlatformOS_PC* const _this)>(0x158AEF0);
	static inline auto FDebugMessageBox = PreyFunction<IPlatformOS::EMsgBoxResult(const CPlatformOS_PC* const _this, const char* body, const char* title, unsigned flags)>(0xE76030);
	static inline auto FPostLocalizationBootChecks = PreyFunction<bool(CPlatformOS_PC* const _this)>(0x1B933B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CPlatformOS_PC* const _this, ICrySizer* pSizer)>(0xE76B30);
	static inline auto FDebugSave = PreyFunction<bool(CPlatformOS_PC* const _this, IPlatformOS::SDebugDump& dump)>(0xDD23F0);
	static inline auto FConsoleLoadGame = PreyFunction<bool(CPlatformOS_PC* const _this, IConsoleCmdArgs* pArgs)>(0xDD23F0);
	static inline auto FGetHostName = PreyFunction<const char* const (CPlatformOS_PC* const _this)>(0xE76940);
	static inline auto FInitEncryptionKey = PreyFunction<void(CPlatformOS_PC* const _this, const char* pMagic, uint64_t magicLength, const uint8_t* pKey, uint64_t keyLength)>(0xE76BE0);
	static inline auto FGetEncryptionKey = PreyFunction<void(CPlatformOS_PC* const _this, const std::vector<char>* * pMagic, const std::vector<unsigned char>* * pKey)>(0xE76840);
	static inline auto FIsStoreCompleted = PreyFunction<bool(CPlatformOS_PC* const _this)>(0x1B933B0);
	static inline auto FIsTrial = PreyFunction<bool(const CPlatformOS_PC* const _this)>(0xDD23F0);
	static inline auto FShowStoreProduct = PreyFunction<void(CPlatformOS_PC* const _this, const char* _productId, unsigned __unnamed1)>(0xA13080);
	static inline auto FQueryFirstPartyEnvironment = PreyFunction<EArkFirstPartyEnvironmentQueryResponse(CPlatformOS_PC* const _this, EArkFirstPartyEnvironment& _env)>(0xE775A0);
	static inline auto FGetUserPII = PreyFunction<EUserPIIStatus(CPlatformOS_PC* const _this, unsigned inUser, SUserPII* pOutPII)>(0x133DF50);
	static inline auto FStartUsingCachePaks = PreyFunction<IPlatformOS::ECDP_Start(CPlatformOS_PC* const _this, unsigned userId, bool* outWritesOccurred)>(0xE77F10);
	static inline auto FEndUsingCachePaks = PreyFunction<IPlatformOS::ECDP_End(CPlatformOS_PC* const _this, unsigned userId)>(0xE76530);
	static inline auto FDoesCachePakExist = PreyFunction<IPlatformOS::ECDP_Open(CPlatformOS_PC* const _this, const char* const filename, const uint64_t size, uint8_t* md5)>(0xE76190);
	static inline auto FOpenCachePak = PreyFunction<IPlatformOS::ECDP_Open(CPlatformOS_PC* const _this, const char* const filename, const char* const bindRoot, const uint64_t size, uint8_t* md5)>(0xE774B0);
	static inline auto FCloseCachePak = PreyFunction<IPlatformOS::ECDP_Close(CPlatformOS_PC* const _this, const char* const filename)>(0xE75F20);
	static inline auto FDeleteCachePak = PreyFunction<IPlatformOS::ECDP_Delete(CPlatformOS_PC* const _this, const char* const filename)>(0xE760B0);
	static inline auto FWriteCachePak = PreyFunction<IPlatformOS::ECDP_Write(CPlatformOS_PC* const _this, const char* const filename, const void* const pData, const uint64_t numBytes)>(0xE78690);
	static inline auto FExtractZips = PreyFunction<IPlatformOS::EZipExtractFail(CPlatformOS_PC* const _this, const char* path)>(0xE765A0);
	static inline auto FSetOpticalDriveIdle = PreyFunction<void(CPlatformOS_PC* const _this, bool bIdle)>(0xA13080);
	static inline auto FAllowOpticalDriveUsage = PreyFunction<void(CPlatformOS_PC* const _this, bool bAllow)>(0xA13080);
	static inline auto FGetLocalIPAddress = PreyFunction<bool(const CPlatformOS_PC* const _this, char* ipAddress, unsigned& ip, int length)>(0xE769A0);
	static inline auto FGetStreamingInstall = PreyFunction<CStreamingInstallBase* (CPlatformOS_PC* const _this)>(0x10BD340);
	static inline auto FGetLanguageIDFromName = PreyFunction<ELanguageID(const CPlatformOS_PC* const _this, const char* languageName)>(0xE76990);
	static inline auto FOnPlatformEvent = PreyFunction<void(IPlatformOS::IPlatformListener* const _this, const IPlatformOS::SPlatformEvent& _event)>(0xE77480);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0xE774A0);
	static inline auto FOnPostUpdate = PreyFunction<void(IGameFrameworkListener* const _this, float fDeltaTime)>(0xA13080);
	static inline auto FOnSaveGame = PreyFunction<void(IGameFrameworkListener* const _this, ISaveGame* pSaveGame)>(0xA13080);
	static inline auto FOnLoadGame = PreyFunction<void(IGameFrameworkListener* const _this, ILoadGame* pLoadGame)>(0xA13080);
	static inline auto FOnLevelEnd = PreyFunction<void(IGameFrameworkListener* const _this, const char* nextLevel)>(0xA13080);
	static inline auto FOnActionEvent = PreyFunction<void(IGameFrameworkListener* const _this, const SActionEvent& event)>(0xE77440);
	static inline auto FSetRichPresence = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned userId, const SRichPresenceData* richPresenceData)>(0xE77EE0);
	static inline auto FRecurseZipContents = PreyFunction<IPlatformOS::EZipExtractFail(CPlatformOS_PC* const _this, ZipDir::FileEntryTree* pSourceDir, const char* currentPath, _smart_ptr<ZipDir::CacheRW> pCache)>(0xE775B0);
	static inline auto FSxmlMissingFromHDD = PreyFunction<bool(CPlatformOS_PC* const _this, ZipDir::FileEntryTree* pZipRoot, const char* userPath, _smart_ptr<ZipDir::CacheRW> pZip)>(0xE77F60);
};


