// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/iplatformos.h>
#include <CryEngine/crysystem/platformos/PlatformOS_Base.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CrySystem/ISystem.h>
#include <_unknown/CListenerSet.h>
#include <_unknown/CryFixedStringT.h>
#include <_unknown/CryFixedWStringT.h>

enum class EArkFirstPartyEnvironment;
enum class EArkFirstPartyEnvironmentQueryResponse;
enum EFileState;
enum ELanguageID;
enum ESystemEvent;
class ICrySizer;
struct ILoadGame;
struct ISaveGame;
struct IStringVerifyEvents;
struct IVirtualKeyboardEvents;
struct SActionEvent;
struct SRichPresenceData;
struct SUserXUID;
class XmlNodeRef;

// CPlatformOS_PC
// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
class CPlatformOS_PC
	: public CPlatformOS_Base
	, public IPlatformOS::IPlatformListener
	, public ISystemEventListener
	, public IGameFrameworkListener
{ // Size=256 (0x100)
public:
	CPlatformOS_Base::CStableFPSWatcher m_fpsWatcher;
	CListenerSet<IPlatformOS::IPlatformListener *> m_listeners;
	std::vector<char> m_encryptionMagic;
	std::vector<unsigned char> m_encryptionKey;
	float m_delayLevelStartIcon;
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
	virtual void PostServiceTask(IPlatformOS::IServiceTask* _task);
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
	virtual EFileState FileExists(const char* _szPath, unsigned _user);
	virtual void MountDLCContent(IPlatformOS::IDLCListener* pCallback, unsigned user, const uint8_t* keyData);
	virtual bool CanRestartTitle() const;
	virtual void RestartTitle(const char* pLoadFrom);
	virtual bool BeginSaveLoad(unsigned user, bool bSave);
	virtual void EndSaveLoad(unsigned user);
	virtual std::shared_ptr<IPlatformOS::ISaveReader> SaveGetReader(const char* fileName, unsigned _userId);
	virtual std::shared_ptr<IPlatformOS::ISaveWriter> SaveGetWriter(const char* fileName, unsigned _userId);
	virtual bool SaveCopyFiles(const char* _szSource, const char* _szDestination, const char* _szPattern, unsigned user);
	virtual std::vector<string> GetSaveFileNamesFromContainer(const char* _containerName, const char* _pattern);
	virtual bool KeyboardStart(unsigned inUserIndex, unsigned flags, const wchar_t* title, const wchar_t* initialInput, int maxInputLength, IVirtualKeyboardEvents* pInCallback);
	virtual bool KeyboardIsRunning();
	virtual bool KeyboardCancel();
	virtual bool StringVerifyStart(const wchar_t* inString, IStringVerifyEvents* pInCallback);
	virtual bool IsVerifyingString();
	virtual void AddListener(IPlatformOS::IPlatformListener* pListener, const char* szName);
	virtual void RemoveListener(IPlatformOS::IPlatformListener* pListener);
	virtual void NotifyListeners(IPlatformOS::SPlatformEvent& event);
	virtual const char* GetSKUId();
	virtual IPlatformOS::EMsgBoxResult DebugMessageBox(const char* body, const char* title, unsigned flags) const;
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual const char* const GetHostName();
	virtual void InitEncryptionKey(const char* pMagic, uint64_t magicLength, const uint8_t* pKey, uint64_t keyLength);
	virtual void GetEncryptionKey(const std::vector<char>* * pMagic, const std::vector<unsigned char>* * pKey);
	virtual EArkFirstPartyEnvironmentQueryResponse QueryFirstPartyEnvironment(EArkFirstPartyEnvironment& _env);
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

#if 0
	bool SendRichPresence(unsigned _arg0_, const string& _arg1_);
	void SaveDirtyFiles();
	bool DecryptAndCheckSigning(const char* _arg0_, int _arg1_, char* * _arg2_, int* _arg3_, const uint8_t* _arg4_);
	bool UseSteamReadWriter() const;
#endif

	static inline auto FCPlatformOS_PC = PreyFunction<void(CPlatformOS_PC* const _this, const uint8_t createParams)>(0xE928C0);
	static inline auto FInitLanguageInfo = PreyFunction<unsigned(CPlatformOS_PC* const _this, unsigned _languagesWithData)>(0xE936D0);
	static inline auto FTick = PreyFunction<void(CPlatformOS_PC* const _this, float realFrameTime)>(0xE945F0);
	static inline auto FPostServiceTask = PreyFunction<void(CPlatformOS_PC* const _this, IPlatformOS::IServiceTask* _task)>(0x5A35F0);
	static inline auto FGetPlatformName = PreyFunction<const char* (const CPlatformOS_PC* const _this)>(0xE93340);
	static inline auto FUserGetMaximumSignedInUsers = PreyFunction<unsigned(const CPlatformOS_PC* const _this)>(0x1948930);
	static inline auto FUserIsSignedIn = PreyFunction<bool(const CPlatformOS_PC* const _this, unsigned userIndex)>(0xE94B80);
	static inline auto FUserDoSignIn = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned userId)>(0xE94980);
	static inline auto FUserSignOut = PreyFunction<void(CPlatformOS_PC* const _this, unsigned userId)>(0x1333E90);
	static inline auto FGetFirstSignedInUser = PreyFunction<unsigned(const CPlatformOS_PC* const _this)>(0xE92FF0);
	static inline auto FUserGetPlayerIndex = PreyFunction<unsigned(const CPlatformOS_PC* const _this, const char* userName)>(0x1CBB0B0);
	static inline auto FUserGetPlayerId = PreyFunction<unsigned(const CPlatformOS_PC* const _this, const char* const userName)>(0x1CBB0B0);
	static inline auto FUserGetName = PreyFunction<bool(const CPlatformOS_PC* const _this, unsigned userIndex, CryFixedStringT<257>& outName)>(0xE949F0);
	static inline auto FUserGetId = PreyFunction<unsigned(const CPlatformOS_PC* const _this, const SUserXUID& __unnamed1)>(0x1CBB0B0);
	static inline auto FUserGetXUID = PreyFunction<bool(const CPlatformOS_PC* const _this, unsigned userId, SUserXUID& __unnamed1)>(0x13B0900);
	static inline auto FUserGetOnlineName = PreyFunction<bool(const CPlatformOS_PC* const _this, unsigned userIndex, CryFixedStringT<257>& outName)>(0xE94B70);
	static inline auto FUserSelectStorageDevice = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned userIndex, bool bForceUI)>(0x1A302A0);
	static inline auto FGetUserProfilePreference = PreyFunction<bool(const CPlatformOS_PC* const _this, unsigned user, IPlatformOS::EUserProfilePreference ePreference, IPlatformOS::SUserProfileVariant& outResult)>(0x13B0900);
	static inline auto FMountSaveFile = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned userIndex)>(0x1A302A0);
	static inline auto FGetUserPairedToDevice = PreyFunction<unsigned(CPlatformOS_PC* const _this, uint64_t __unnamed1)>(0x1CBB0B0);
	static inline auto FGetDevicesPairedToUser = PreyFunction<int(const CPlatformOS_PC* const _this, unsigned userId, std::vector<uint64_t>& outDeviceIds)>(0xE92F60);
	static inline auto FGetFileFinder = PreyFunction<std::shared_ptr<IPlatformOS::IFileFinder>*(CPlatformOS_PC* const _this, std::shared_ptr<IPlatformOS::IFileFinder>* _return_value_, const char* _szPattern, unsigned _user)>(0xE92F90);
	static inline auto FFileExists = PreyFunction<EFileState(CPlatformOS_PC* const _this, const char* _szPath, unsigned _user)>(0xE92F40);
	static inline auto FMountDLCContent = PreyFunction<void(CPlatformOS_PC* const _this, IPlatformOS::IDLCListener* pCallback, unsigned user, const uint8_t* keyData)>(0xE938A0);
	static inline auto FCanRestartTitle = PreyFunction<bool(const CPlatformOS_PC* const _this)>(0x1A302A0);
	static inline auto FRestartTitle = PreyFunction<void(CPlatformOS_PC* const _this, const char* pLoadFrom)>(0xE94000);
	static inline auto FBeginSaveLoad = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned user, bool bSave)>(0xE92DD0);
	static inline auto FEndSaveLoad = PreyFunction<void(CPlatformOS_PC* const _this, unsigned user)>(0xE92EE0);
	static inline auto FSaveGetReader = PreyFunction<std::shared_ptr<IPlatformOS::ISaveReader>*(CPlatformOS_PC* const _this, std::shared_ptr<IPlatformOS::ISaveReader>* _return_value_, const char* fileName, unsigned _userId)>(0xE943F0);
	static inline auto FSaveGetWriter = PreyFunction<std::shared_ptr<IPlatformOS::ISaveWriter>*(CPlatformOS_PC* const _this, std::shared_ptr<IPlatformOS::ISaveWriter>* _return_value_, const char* fileName, unsigned _userId)>(0xE944D0);
	static inline auto FSaveCopyFiles = PreyFunction<bool(CPlatformOS_PC* const _this, const char* _szSource, const char* _szDestination, const char* _szPattern, unsigned user)>(0xE94390);
	static inline auto FGetSaveFileNamesFromContainer = PreyFunction<std::vector<string>*(CPlatformOS_PC* const _this, std::vector<string>* _return_value_, const char* _containerName, const char* _pattern)>(0xE93350);
	static inline auto FKeyboardStart = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned inUserIndex, unsigned flags, const wchar_t* title, const wchar_t* initialInput, int maxInputLength, IVirtualKeyboardEvents* pInCallback)>(0x13B0900);
	static inline auto FKeyboardIsRunning = PreyFunction<bool(CPlatformOS_PC* const _this)>(0x13B0900);
	static inline auto FKeyboardCancel = PreyFunction<bool(CPlatformOS_PC* const _this)>(0x13B0900);
	static inline auto FStringVerifyStart = PreyFunction<bool(CPlatformOS_PC* const _this, const wchar_t* inString, IStringVerifyEvents* pInCallback)>(0x13B0900);
	static inline auto FIsVerifyingString = PreyFunction<bool(CPlatformOS_PC* const _this)>(0x13B0900);
	static inline auto FAddListener = PreyFunction<void(CPlatformOS_PC* const _this, IPlatformOS::IPlatformListener* pListener, const char* szName)>(0xE92D80);
	static inline auto FRemoveListener = PreyFunction<void(CPlatformOS_PC* const _this, IPlatformOS::IPlatformListener* pListener)>(0xE93F80);
	static inline auto FNotifyListeners = PreyFunction<void(CPlatformOS_PC* const _this, IPlatformOS::SPlatformEvent& event)>(0xE93DD0);
	static inline auto FGetSKUId = PreyFunction<const char* (CPlatformOS_PC* const _this)>(0x1CBB0B0);
	static inline auto FDebugMessageBox = PreyFunction<IPlatformOS::EMsgBoxResult(const CPlatformOS_PC* const _this, const char* body, const char* title, unsigned flags)>(0xE92E60);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CPlatformOS_PC* const _this, ICrySizer* pSizer)>(0xE932A0);
	static inline auto FGetHostName = PreyFunction<const char* const (CPlatformOS_PC* const _this)>(0xE93070);
	static inline auto FInitEncryptionKey = PreyFunction<void(CPlatformOS_PC* const _this, const char* pMagic, uint64_t magicLength, const uint8_t* pKey, uint64_t keyLength)>(0xE93630);
	static inline auto FGetEncryptionKey = PreyFunction<void(CPlatformOS_PC* const _this, const std::vector<char>* * pMagic, const std::vector<unsigned char>* * pKey)>(0xE92F70);
	static inline auto FQueryFirstPartyEnvironment = PreyFunction<EArkFirstPartyEnvironmentQueryResponse(CPlatformOS_PC* const _this, EArkFirstPartyEnvironment& _env)>(0xE93F70);
	static inline auto FGetLocalIPAddress = PreyFunction<bool(const CPlatformOS_PC* const _this, char* ipAddress, unsigned& ip, int length)>(0xE93110);
	static inline auto FGetStreamingInstall = PreyFunction<CStreamingInstallBase* (CPlatformOS_PC* const _this)>(0xE93620);
	static inline auto FGetLanguageIDFromName = PreyFunction<ELanguageID(const CPlatformOS_PC* const _this, const char* languageName)>(0xE93100);
	static inline auto FOnPlatformEvent = PreyFunction<void(IPlatformOS::IPlatformListener* const _this, const IPlatformOS::SPlatformEvent& _event)>(0xE93EF0);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0xE93F10);
	static inline auto FOnPostUpdate = PreyFunction<void(IGameFrameworkListener* const _this, float fDeltaTime)>(0x1333E90);
	static inline auto FOnSaveGame = PreyFunction<void(IGameFrameworkListener* const _this, ISaveGame* pSaveGame)>(0x1333E90);
	static inline auto FOnLoadGame = PreyFunction<void(IGameFrameworkListener* const _this, ILoadGame* pLoadGame)>(0x1333E90);
	static inline auto FOnLevelEnd = PreyFunction<void(IGameFrameworkListener* const _this, const char* nextLevel)>(0x1333E90);
	static inline auto FOnActionEvent = PreyFunction<void(IGameFrameworkListener* const _this, const SActionEvent& event)>(0xE93EA0);
	static inline auto FSetRichPresence = PreyFunction<bool(CPlatformOS_PC* const _this, unsigned userId, const SRichPresenceData* richPresenceData)>(0xE945C0);
};

// IPlatformOS
// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
// Include: Prey/CryCore/Platform/IPlatformOS.h
struct IPlatformOS
{ // Size=8 (0x8)
	enum ECreateFlags
	{
		eCF_EarlyCorruptionDetected = 2,
		eCF_NoDialogs = 4,
	};

	enum class #unnamed_enum_Unknown_User
	{
		Unknown_User = -1,
	};

	enum class #unnamed_enum_MINIMUM_SAVE_ICON_DISPLAY_TIME
	{
		MINIMUM_SAVE_ICON_DISPLAY_TIME = 3,
	};

	enum class #unnamed_enum_USER_MAX_NAME
	{
		USER_MAX_NAME = 257,
	};

	enum EFileOperationCode
	{
		eFOC_Success = 0,
		eFOC_Failure = 1,
		eFOC_ErrorOpenRead = 18,
		eFOC_ErrorRead = 20,
		eFOC_ErrorOpenWrite = 34,
		eFOC_ErrorWrite = 36,
		eFOC_ReadMask = 16,
		eFOC_WriteMask = 32,
		eFOC_OpenMask = 2,
	};

	enum EMsgBoxResult
	{
		eMsgBox_OK = 0,
		eMsgBox_Cancel = 1,
		eMsgBoxNumButtons = 2,
	};

	enum class #unnamed_enum_KbdFlag_Default
	{
		KbdFlag_Default = 1,
		KbdFlag_GamerTag = 2,
		KbdFlag_Email = 4,
		KbdFlag_Password = 8,
	};

	enum EUserProfilePreference
	{
		EUPP_CONTROLLER_INVERT_Y = 0,
		EUPP_CONTROLLER_SENSITIVITY = 1,
		EUPP_GAME_DIFFICULTY = 2,
		EUPP_AIM_ASSIST = 3,
		EUPP_REGION = 4,
	};

	enum EDLCMountFail
	{
		eDMF_FileCorrupt = 0,
		eDMF_DiskCorrupt = 1,
		eDMF_XmlError = 2,
		eDMF_NoDLCDir = 3,
		eDMF_Unknown = 4,
	};

	enum EZipExtractFail
	{
		eZEF_Success = 0,
		eZEF_Unsupported = 1,
		eZEF_WriteFail = 2,
		eZEF_UnknownError = 3,
	};

	// IPlatformOS::IDLCListener
	// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
	struct IDLCListener
	{ // Size=8 (0x8)
		virtual ~IDLCListener();
		virtual void OnDLCMounted(const XmlNodeRef& rootNode, const char* sDLCRootFolder) = 0;
		virtual void OnDLCMountFailed(IPlatformOS::EDLCMountFail reason) = 0;
		virtual void OnDLCMountFinished(int nPacksFound) = 0;
	};

	// IPlatformOS::SUserProfileVariant
	// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
	struct SUserProfileVariant
	{ // Size=8 (0x8)
		enum EVariantType
		{
			eVT_Invalid = 0,
			eVT_Bool = 1,
			eVT_Int = 2,
			eVT_Float = 3,
		};

		IPlatformOS::SUserProfileVariant::EVariantType m_type;
		union
		{
			bool m_bValue;
			int m_iValue;
			float m_fValue;

		};

	#if 0
		SUserProfileVariant();
		SUserProfileVariant(bool _arg0_);
		SUserProfileVariant(int _arg0_);
		SUserProfileVariant(float _arg0_);
		IPlatformOS::SUserProfileVariant::EVariantType GetType() const;
		bool GetBool() const;
		int GetInt() const;
		float GetFloat() const;
	#endif
	};

	// IPlatformOS::SPlatformEvent
	// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
	struct SPlatformEvent
	{ // Size=16 (0x10)
		enum EEventType
		{
			eET_None = 0,
			eET_PlatformSpecific = 1,
			eET_SignIn = 2,
			eET_StorageMounted = 3,
			eET_StorageRemoved = 4,
			eET_StorageCancelled = 5,
			eET_FileError = 6,
			eET_FileWrite = 7,
			eET_ContentInstalled = 8,
			eET_InstallBegin = 9,
			eET_InstallComplete = 10,
			eET_PostLocalisationBootChecksDone = 11,
			eET_PIIRetrieved = 12,
			eET_SystemMenu = 13,
			eET_ContentRemoved = 14,
		};

		enum ESignInState
		{
			eSIS_NotSignedIn = 0,
			eSIS_SignedInLocally = 1,
			eSIS_SignedInLive = 2,
		};

		enum EFileWriteType
		{
			eFWT_Checkpoint = 0,
			eFWT_CheckpointLevelStart = 1,
			eFWT_SaveStart = 2,
			eFWT_SaveEnd = 3,
			eFWT_CreatingSave = 4,
		};

		// IPlatformOS::SPlatformEvent::UEventParams
		// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
		union UEventParams
		{ // Size=8 (0x8)
			// IPlatformOS::SPlatformEvent::UEventParams::SSignIn
			// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
			struct SSignIn
			{ // Size=8 (0x8)
				IPlatformOS::SPlatformEvent::ESignInState m_previousSignedInState;
				IPlatformOS::SPlatformEvent::ESignInState m_signedInState;
			};

			// IPlatformOS::SPlatformEvent::UEventParams::SStorageMounted
			// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
			struct SStorageMounted
			{ // Size=2 (0x2)
				bool m_bPhysicalMedia;
				bool m_bOnlyUpdateMediaState;
			};

			// IPlatformOS::SPlatformEvent::UEventParams::SStorageRemoved
			// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
			struct SStorageRemoved
			{ // Size=1 (0x1)
				bool m_bDeviceRemovedIsPrimary;
			};

			// IPlatformOS::SPlatformEvent::UEventParams::SFileError
			// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
			struct SFileError
			{ // Size=8 (0x8)
				IPlatformOS::EFileOperationCode m_errorType;
				bool m_bRetry;
			};

			// IPlatformOS::SPlatformEvent::UEventParams::SFileWrite
			// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
			struct SFileWrite
			{ // Size=4 (0x4)
				IPlatformOS::SPlatformEvent::EFileWriteType m_type;
			};

			// IPlatformOS::SPlatformEvent::UEventParams::SSystemMenu
			// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
			struct SSystemMenu
			{ // Size=2 (0x2)
				bool m_bOpened;
				bool m_bClosed;
			};

			// IPlatformOS::SPlatformEvent::UEventParams::SContentRemoved
			// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
			struct SContentRemoved
			{ // Size=4 (0x4)
				char m_root[4];
			};

			IPlatformOS::SPlatformEvent::UEventParams::SSignIn m_signIn;
			IPlatformOS::SPlatformEvent::UEventParams::SStorageMounted m_storageMounted;
			IPlatformOS::SPlatformEvent::UEventParams::SStorageRemoved m_storageRemoved;
			IPlatformOS::SPlatformEvent::UEventParams::SFileError m_fileError;
			IPlatformOS::SPlatformEvent::UEventParams::SFileWrite m_fileWrite;
			IPlatformOS::SPlatformEvent::UEventParams::SSystemMenu m_systemMenu;
			IPlatformOS::SPlatformEvent::UEventParams::SContentRemoved m_contentRemoved;
		};

		unsigned m_user;
		IPlatformOS::SPlatformEvent::EEventType m_eEventType;
		IPlatformOS::SPlatformEvent::UEventParams m_uParams;

	#if 0
		SPlatformEvent(unsigned _arg0_, IPlatformOS::SPlatformEvent::EEventType _arg1_);
	#endif
	};

	// IPlatformOS::ISaveReader
	// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
	struct ISaveReader
	{ // Size=8 (0x8)
		enum ESeekMode
		{
			ESM_BEGIN = 0,
			ESM_CURRENT = 1,
			ESM_END = 2,
		};

		virtual ~ISaveReader();
		virtual IPlatformOS::EFileOperationCode Seek(long seek, IPlatformOS::ISaveReader::ESeekMode mode) = 0;
		virtual IPlatformOS::EFileOperationCode GetFileCursor(long& fileCursor) = 0;
		virtual IPlatformOS::EFileOperationCode ReadBytes(void* data, uint64_t numBytes) = 0;
		virtual IPlatformOS::EFileOperationCode GetNumBytes(uint64_t& numBytes) = 0;
		virtual IPlatformOS::EFileOperationCode Close() = 0;
		virtual IPlatformOS::EFileOperationCode LastError() const = 0;
		virtual bool IsTheRightOwner() const;
		virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;
		virtual void TouchFile();

		static inline auto FIsTheRightOwner = PreyFunction<bool(const IPlatformOS::ISaveReader* const _this)>(0x1A302A0);
		static inline auto FTouchFile = PreyFunction<void(IPlatformOS::ISaveReader* const _this)>(0x1333E90);
	};

	// IPlatformOS::ISaveWriter
	// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
	struct ISaveWriter
	{ // Size=8 (0x8)
		virtual ~ISaveWriter();
		virtual IPlatformOS::EFileOperationCode AppendBytes(const void* data, uint64_t length) = 0;
		virtual IPlatformOS::EFileOperationCode Close() = 0;
		virtual IPlatformOS::EFileOperationCode LastError() const = 0;
		virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;
	};

	// IPlatformOS::IFileFinder
	// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
	struct IFileFinder
	{ // Size=8 (0x8)
		virtual ~IFileFinder();
		virtual const std::vector<_finddata64i32_t>& GetFoundFiles() const = 0;
	};

	// IPlatformOS::CScopedSaveLoad
	// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
	class CScopedSaveLoad
	{ // Size=8 (0x8)
	public:
		unsigned m_user;
		bool m_allow;

	#if 0
		CScopedSaveLoad(unsigned _arg0_, bool _arg1_);
		~CScopedSaveLoad();
		bool Allowed() const;
	#endif
	};

	// IPlatformOS::IPlatformListener
	// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
	struct IPlatformListener
	{ // Size=8 (0x8)
		virtual ~IPlatformListener();
		virtual void OnPlatformEvent(const IPlatformOS::SPlatformEvent& _event) = 0;
	};

	// IPlatformOS::IServiceTask
	// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
	struct IServiceTask
	{ // Size=8 (0x8)
		virtual ~IServiceTask();
		virtual void OnEnqueued() = 0;
		virtual void Run() = 0;
		virtual void Finish() = 0;
		virtual bool IsPending() const = 0;
		virtual bool IsOwnedByScheduler() const = 0;
	};

	// IPlatformOS::SDebugDump
	// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
	struct SDebugDump
	{ // Size=24 (0x18)
		bool (*OpenFile)(const char*, bool);
		bool (*WriteToFile)(const void*, unsigned, unsigned);
		bool (*CloseFile)();
	};

	// IPlatformOS::IClipCaptureOS
	// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
	struct IClipCaptureOS
	{ // Size=24 (0x18)
		// IPlatformOS::IClipCaptureOS::IListener
		// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
		struct IListener
		{ // Size=8 (0x8)
			enum ECaptureFinishedStatus
			{
				eCFS_Success = 0,
				eCFS_Failure = 1,
			};

			virtual void OnClipCaptureFinished(IPlatformOS::IClipCaptureOS::IListener::ECaptureFinishedStatus _arg0_) = 0;
		};

		// IPlatformOS::IClipCaptureOS::SSpan
		// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
		struct SSpan
		{ // Size=8 (0x8)
			float secondsBefore;
			float secondsAfter;

		#if 0
			SSpan(float _arg0_, float _arg1_);
			float GetDuration() const;
		#endif
		};

		// IPlatformOS::IClipCaptureOS::SClipTextInfo
		// Header:  CryEngine/crysystem/platformos/PlatformOS_PC.h
		struct SClipTextInfo
		{ // Size=24 (0x18)
			const char* szGreatestMomentId;
			const wchar_t* wszLocalizedClipName;
			const char* szTitleData;

		#if 0
			SClipTextInfo(const char* _arg0_, const wchar_t* _arg1_, const char* _arg2_);
		#endif
		};

		unsigned minNumClips;
		unsigned maxNumClips;
		float maxTotalClipsTime;

		virtual ~IClipCaptureOS();
		virtual void GetMinMaxClipsPerTitle(unsigned& _arg0_, unsigned& _arg1_) const;
		virtual float GetMaxTotalClipsTimePerTitle() const;
		virtual bool RecordClip(unsigned _arg0_, IPlatformOS::IClipCaptureOS::SClipTextInfo _arg1_, const IPlatformOS::IClipCaptureOS::SSpan& _arg2_, IPlatformOS::IClipCaptureOS::IListener* _arg3_, const bool _arg4_);
	};

	using TUserName = CryFixedStringT<257>;
	using TUserNameW = CryFixedWStringT<257>;
	using ISaveReaderPtr = std::shared_ptr<IPlatformOS::ISaveReader>;
	using ISaveReaderConstPtr = std::shared_ptr<const IPlatformOS::ISaveReader>;
	using ISaveReaderWeakPtr = std::weak_ptr<IPlatformOS::ISaveReader>;
	using ISaveReaderConstWeakPtr = std::weak_ptr<IPlatformOS::ISaveReader const >;
	using ISaveReaderPtrVector = std::vector<std::shared_ptr<IPlatformOS::ISaveReader>>;
	using ISaveWriterPtr = std::shared_ptr<IPlatformOS::ISaveWriter>;
	using ISaveWriterConstPtr = std::shared_ptr<const IPlatformOS::ISaveWriter>;
	using ISaveWriterWeakPtr = std::weak_ptr<IPlatformOS::ISaveWriter>;
	using ISaveWriterConstWeakPtr = std::weak_ptr<IPlatformOS::ISaveWriter const >;
	using ISaveWriterPtrVector = std::vector<std::shared_ptr<IPlatformOS::ISaveWriter>>;
	using IFileFinderPtr = std::shared_ptr<IPlatformOS::IFileFinder>;

	virtual const char* GetPlatformName() const = 0;
	static IPlatformOS* Create(const uint8_t createParams) { return FCreate(createParams); }
	virtual ~IPlatformOS();
	virtual unsigned InitLanguageInfo(unsigned _languagesWithData) = 0;
	virtual void Tick(float realFrameTime) = 0;
	virtual void PostServiceTask(IPlatformOS::IServiceTask* _task) = 0;
	virtual void PostMainThreadTask(IPlatformOS::IServiceTask* _arg0_) = 0;
	virtual unsigned UserGetMaximumSignedInUsers() const = 0;
	virtual bool UserIsSignedIn(unsigned userIndex) const = 0;
	virtual bool UserDoSignIn(unsigned userId) = 0;
	virtual void UserSignOut(unsigned userId) = 0;
	virtual unsigned UserGetPlayerId(const char* _arg0_) const = 0;
	virtual bool UserGetName(unsigned userIndex, CryFixedStringT<257>& outName) const = 0;
	virtual unsigned UserGetId(const SUserXUID& __unnamed1) const = 0;
	virtual bool UserGetXUID(unsigned userId, SUserXUID& __unnamed1) const = 0;
	virtual bool UserGetOnlineName(unsigned userIndex, CryFixedStringT<257>& outName) const = 0;
	virtual unsigned GetUserPairedToDevice(uint64_t __unnamed1) = 0;
	virtual int GetDevicesPairedToUser(unsigned userId, std::vector<uint64_t>& outDeviceIds) const = 0;
	virtual bool UserSelectStorageDevice(unsigned userIndex, bool bForceUI) = 0;
	virtual bool GetUserProfilePreference(unsigned user, IPlatformOS::EUserProfilePreference ePreference, IPlatformOS::SUserProfileVariant& outResult) const = 0;
	virtual bool UsePlatformSavingAPI() const = 0;
	virtual bool BeginSaveLoad(unsigned user, bool bSave) = 0;
	virtual void EndSaveLoad(unsigned user) = 0;
	virtual std::shared_ptr<IPlatformOS::ISaveReader> SaveGetReader(const char* fileName, unsigned _userId) = 0;
	virtual std::shared_ptr<IPlatformOS::ISaveWriter> SaveGetWriter(const char* fileName, unsigned _userId) = 0;
	virtual bool SaveCopyFiles(const char* _szSource, const char* _szDestination, const char* _szPattern, unsigned user) = 0;
	virtual std::vector<string> GetSaveFileNamesFromContainer(const char* _containerName, const char* _pattern) = 0;
	virtual std::shared_ptr<IPlatformOS::IFileFinder> GetFileFinder(const char* _szPattern, unsigned _user) = 0;
	virtual EFileState FileExists(const char* _szPath, unsigned _user) = 0;
	virtual void MountDLCContent(IPlatformOS::IDLCListener* pCallback, unsigned user, const uint8_t* keyData) = 0;
	virtual bool CanRestartTitle() const = 0;
	virtual void RestartTitle(const char* pLoadFrom) = 0;
	virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;
	virtual unsigned GetFirstSignedInUser() const = 0;
	virtual bool KeyboardStart(unsigned inUserIndex, unsigned flags, const wchar_t* title, const wchar_t* initialInput, int maxInputLength, IVirtualKeyboardEvents* pInCallback) = 0;
	virtual bool KeyboardIsRunning() = 0;
	virtual bool KeyboardCancel() = 0;
	virtual bool StringVerifyStart(const wchar_t* inString, IStringVerifyEvents* pInCallback) = 0;
	virtual bool IsVerifyingString() = 0;
	virtual void AddListener(IPlatformOS::IPlatformListener* pListener, const char* szName) = 0;
	virtual void RemoveListener(IPlatformOS::IPlatformListener* pListener) = 0;
	virtual void NotifyListeners(IPlatformOS::SPlatformEvent& event) = 0;
	virtual const char* GetSKUId() = 0;
	virtual ELanguageID GetLanguageIDFromName(const char* languageName) const = 0;
	virtual ELanguageID GetSystemLanguageID() const = 0;
	virtual unsigned GetNumSystemSupportedLanguages() const = 0;
	virtual unsigned GetSystemSupportedLanguages() const = 0;
	virtual IPlatformOS::EMsgBoxResult DebugMessageBox(const char* body, const char* title, unsigned flags) const = 0;
	virtual bool GetLocalIPAddress(char* ipAddress, unsigned& ip, int length) const = 0;
	virtual const char* const GetHostName() = 0;
	virtual bool SwapConfirmCancel() const = 0;
	virtual void InitEncryptionKey(const char* pMagic, uint64_t magicLength, const uint8_t* pKey, uint64_t keyLength) = 0;
	virtual void GetEncryptionKey(const std::vector<char>* * pMagic, const std::vector<unsigned char>* * pKey) = 0;
	virtual EArkFirstPartyEnvironmentQueryResponse QueryFirstPartyEnvironment(EArkFirstPartyEnvironment& _env) = 0;
	virtual bool CanSafelyQuit() const;
	virtual void HandleArchiveVerificationFailure();
	virtual IPlatformOS::IClipCaptureOS* GetClipCapture();
	virtual CStreamingInstallBase* GetStreamingInstall() = 0;
	virtual bool SetRichPresence(unsigned userId, const SRichPresenceData* richPresenceData) = 0;

#if 0
	char* UIPToText(unsigned _arg0_, char* _arg1_, int _arg2_) const;
	unsigned TextToUIP(const char* _arg0_) const;
	const char* GetCampaignSaveDirectoryName() const;
#endif

	static inline auto FCreate = PreyFunction<IPlatformOS* (const uint8_t createParams)>(0xE92E30);
	static inline auto FCanSafelyQuit = PreyFunction<bool(const IPlatformOS* const _this)>(0x1A302A0);
	static inline auto FHandleArchiveVerificationFailure = PreyFunction<void(IPlatformOS* const _this)>(0x1333E90);
	static inline auto FGetClipCapture = PreyFunction<IPlatformOS::IClipCaptureOS* (IPlatformOS* const _this)>(0x1CBB0B0);
};
#endif // !MOONCRASH
