// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/Containers/CryArray.h>
#include <Prey/CryCore/Containers/VectorMap.h>
#include <Prey/CryAction/IPlayerProfileManager.h>
#include <Prey/CryCore/Platform/IPlatformOS.h>
#include <Prey/CryLobby/ICryStats.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/GameDll/ark/iface/ISaveGameEnumerator.h>
#include <Prey/CryAction/IOnlineAttributesListener.h>

class CCrc32;
class CPlayerProfile;
enum ECryLobbyError;
class ICrySizer;
struct ILevelRotationFile;
struct ILoadGame;
class IOnlineAttributesListener;
struct IPlayerProfile;
class IPlayerProfileListener;
struct IResolveAttributeBlockListener;
struct ISaveGame;
class TFlowInputData;

// CPlayerProfileManager
// Header:  CryEngine/cryaction/playerprofiles/PlayerProfileManager.h
class CPlayerProfileManager : public IPlayerProfileManager
{ // Size=49680 (0xC210)
public:
	enum EPlayerProfileSection
	{
		ePPS_Attribute = 0,
		ePPS_Actionmap = 1,
		ePPS_Uuid = 2,
		ePPS_Num = 3,
	};


	// CPlayerProfileManager::SLocalProfileInfo
	// Header:  CryEngine/cryaction/playerprofiles/PlayerProfileManager.h
	struct SLocalProfileInfo
	{ // Size=16 (0x10)
		string m_name;
		int64_t m_lastLoginTime;

	#if 0
		SLocalProfileInfo();
		SLocalProfileInfo(const string& _arg0_);
		SLocalProfileInfo(const char* _arg0_);
		void SetName(const char* _arg0_);
		void SetName(const string& _arg0_);
		void SetLastLoginTime(int64_t _arg0_);
		const string& GetName() const;
		const int64_t& GetLastLoginTime() const;
		int compare(const char* _arg0_) const;
	#endif
	};

	// CPlayerProfileManager::SUserEntry
	// Header:  CryEngine/cryaction/playerprofiles/PlayerProfileManager.h
	struct SUserEntry
	{ // Size=104 (0x68)
		string userId;
		CPlayerProfile* pCurrentProfile;
		CPlayerProfile* pCurrentPreviewProfile;
		unsigned userIndex;
		unsigned platformUserId;
		SUserXUID platformUserXUID;
		bool isLoggedIn;
		bool unknownUser;
		std::vector<CPlayerProfileManager::SLocalProfileInfo> profileDesc;

	#if 0
		SUserEntry(const string& _arg0_, const unsigned _arg1_);
		~SUserEntry();
	#endif
	};

	// CPlayerProfileManager::SSaveGameMetaData
	// Header:  CryEngine/cryaction/playerprofiles/PlayerProfileManager.h
	struct SSaveGameMetaData
	{ // Size=56 (0x38)
		string levelName;
		string gameRules;
		int fileVersion;
		string buildVersion;
		int64_t saveTime;
		int64_t loadTime;
		XmlNodeRef xmlMetaDataNode;

	#if 0
		void CopyTo(ISaveGameEnumerator::SGameMetaData& _arg0_);
	#endif

#ifndef MOONCRASH
		static inline auto FSSaveGameMetaDataOv2 = PreyFunction<void(CPlayerProfileManager::SSaveGameMetaData* const _this)>(0x4BE1B0);
#else // MOONCRASH
		static inline auto FSSaveGameMetaDataOv2 = PreyFunction<void(CPlayerProfileManager::SSaveGameMetaData* const _this)>(0x4D7020);
#endif // !MOONCRASH
	};

	// CPlayerProfileManager::SThumbnail
	// Header:  CryEngine/cryaction/playerprofiles/PlayerProfileManager.h
	struct SThumbnail
	{ // Size=24 (0x18)
		DynArray<unsigned char,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > data;
		int width;
		int height;
		int depth;

	#if 0
		SThumbnail();
		bool IsValid() const;
		void ReleaseData();
	#endif
	};

	// CPlayerProfileManager::SSaveGameInfo
	// Header:  CryEngine/cryaction/playerprofiles/PlayerProfileManager.h
	struct SSaveGameInfo
	{ // Size=64 (0x40)
		string name;
		string humanName;
		string description;
		std::shared_ptr<CPlayerProfileManager::SSaveGameMetaData> pMetadata;
		CPlayerProfileManager::SThumbnail thumbnail;

	#if 0
		void CopyTo(ISaveGameEnumerator::SGameDescription& _arg0_);
	#endif

#ifndef MOONCRASH
		static inline auto FSSaveGameInfoOv2 = PreyFunction<void(CPlayerProfileManager::SSaveGameInfo* const _this)>(0x52CC00);
#else // MOONCRASH
		static inline auto FSSaveGameInfoOv2 = PreyFunction<void(CPlayerProfileManager::SSaveGameInfo* const _this)>(0x545F90);
#endif // !MOONCRASH
	};

	// CPlayerProfileManager::IPlatformImpl
	// Header:  CryEngine/cryaction/playerprofiles/PlayerProfileManager.h
	struct IPlatformImpl
	{ // Size=8 (0x8)
		virtual ~IPlatformImpl();
		virtual bool Initialize(CPlayerProfileManager* pMgr) = 0;
		virtual void Release() = 0;
		virtual bool LoginUser(CPlayerProfileManager::SUserEntry* pEntry) = 0;
		virtual bool LogoutUser(CPlayerProfileManager::SUserEntry* pEntry) = 0;
		virtual bool SaveProfile(CPlayerProfileManager::SUserEntry* pEntry, CPlayerProfile* pProfile, const char* name, bool initialSave, int reason) = 0;
		virtual bool LoadProfile(CPlayerProfileManager::SUserEntry* pEntry, CPlayerProfile* pProfile, const char* name) = 0;
		virtual void RefreshPlatformInfo(CPlayerProfileManager::SUserEntry* __unnamed1) = 0;
		virtual bool GetSaveGames(CPlayerProfileManager::SUserEntry* pEntry, int _slot, std::vector<CPlayerProfileManager::SSaveGameInfo>& outVec, const char* altProfileName) = 0;
		virtual boost::optional<CPlayerProfileManager::SSaveGameInfo> GetSaveGame(CPlayerProfileManager::SUserEntry* pEntry, int _slot, const char* const _name) = 0;
		virtual ISaveGame* CreateSaveGame(CPlayerProfileManager::SUserEntry* pEntry, int _slot) = 0;
		virtual ILoadGame* CreateLoadGame(CPlayerProfileManager::SUserEntry* pEntry, int _slot) = 0;
		virtual bool DeleteSaveGame(CPlayerProfileManager::SUserEntry* pEntry, int _slot, const char* name) = 0;
		virtual XmlNodeRef GetLevelState(CPlayerProfileManager::SUserEntry* const _pEntry, const int _slot, const char* const _levelName) = 0;
		virtual ILevelRotationFile* GetLevelRotationFile(CPlayerProfileManager::SUserEntry* pEntry, const char* name) = 0;
		virtual bool GetSaveGameThumbnail(CPlayerProfileManager::SUserEntry* pEntry, int _slot, const char* saveGameName, CPlayerProfileManager::SThumbnail& thumbnail) = 0;
		virtual void GetMemoryStatistics(ICrySizer* s) = 0;
		virtual bool ResolveAttributeBlock(CPlayerProfileManager::SUserEntry* pEntry, CPlayerProfile* pProfile, const char* attrBlockName, IResolveAttributeBlockListener* pListener, int reason);
		virtual bool ResolveAttributeBlock(CPlayerProfileManager::SUserEntry* pEntry, CPlayerProfile* pProfile, const IPlayerProfileManager::SResolveAttributeRequest& attrBlockNameRequest, IResolveAttributeBlockListener* pListener, int reason);

#ifndef MOONCRASH
		static inline auto FResolveAttributeBlockOv1 = PreyFunction<bool(CPlayerProfileManager::IPlatformImpl* const _this, CPlayerProfileManager::SUserEntry* pEntry, CPlayerProfile* pProfile, const char* attrBlockName, IResolveAttributeBlockListener* pListener, int reason)>(0xDD23F0);
		static inline auto FResolveAttributeBlockOv0 = PreyFunction<bool(CPlayerProfileManager::IPlatformImpl* const _this, CPlayerProfileManager::SUserEntry* pEntry, CPlayerProfile* pProfile, const IPlayerProfileManager::SResolveAttributeRequest& attrBlockNameRequest, IResolveAttributeBlockListener* pListener, int reason)>(0xDD23F0);
#else // MOONCRASH
		static inline auto FResolveAttributeBlockOv1 = PreyFunction<bool(CPlayerProfileManager::IPlatformImpl* const _this, CPlayerProfileManager::SUserEntry* pEntry, CPlayerProfile* pProfile, const char* attrBlockName, IResolveAttributeBlockListener* pListener, int reason)>(0x13B0900);
		static inline auto FResolveAttributeBlockOv0 = PreyFunction<bool(CPlayerProfileManager::IPlatformImpl* const _this, CPlayerProfileManager::SUserEntry* pEntry, CPlayerProfile* pProfile, const IPlayerProfileManager::SResolveAttributeRequest& attrBlockNameRequest, IResolveAttributeBlockListener* pListener, int reason)>(0x13B0900);
#endif // !MOONCRASH
	};

	// CPlayerProfileManager::IProfileXMLSerializer
	// Header:  CryEngine/cryaction/playerprofiles/PlayerProfileManager.h
	struct IProfileXMLSerializer
	{ // Size=8 (0x8)
		virtual ~IProfileXMLSerializer();
		virtual bool IsLoading() = 0;
		virtual void SetSection(CPlayerProfileManager::EPlayerProfileSection section, XmlNodeRef& node) = 0;
		virtual XmlNodeRef CreateNewSection(CPlayerProfileManager::EPlayerProfileSection section, const char* name) = 0;
		virtual XmlNodeRef GetSection(CPlayerProfileManager::EPlayerProfileSection section) = 0;
	};

	using TUserVec = std::vector<CPlayerProfileManager::SUserEntry*>;
	using TSaveGameInfoVec = std::vector<CPlayerProfileManager::SSaveGameInfo>;
	using TOnlineAttributeMap = VectorMap<CryStringT<char>,unsigned int,std::less<CryStringT<char> >,std::allocator<std::pair<CryStringT<char>,unsigned int> > >;
	using TListeners = std::vector<IPlayerProfileListener*>;

#ifndef MOONCRASH
	static inline auto sUseRichSaveGames = PreyGlobal<int>(0x249E330);
	static inline auto sRSFDebugWrite = PreyGlobal<int>(0x249E334);
	static inline auto sRSFDebugWriteOnLoad = PreyGlobal<int>(0x249E338);
	static inline auto sLoadOnlineAttributes = PreyGlobal<int>(0x224A0C8);
	static inline auto FACTORY_DEFAULT_NAME = PreyGlobal<const char*>(0x224A0D0);
	static inline auto PLAYER_DEFAULT_PROFILE_NAME = PreyGlobal<const char*>(0x224A0D8);
	static inline auto PROFILE_UUID = PreyGlobal<const char* const>(0x1CDAE78);
#else // MOONCRASH
	static inline auto sUseRichSaveGames = PreyGlobal<int>(0x260D950);
	static inline auto sRSFDebugWrite = PreyGlobal<int>(0x260D954);
	static inline auto sRSFDebugWriteOnLoad = PreyGlobal<int>(0x260D958);
	static inline auto sLoadOnlineAttributes = PreyGlobal<int>(0x23B7100);
	static inline auto FACTORY_DEFAULT_NAME = PreyGlobal<const char*>(0x23B7108);
	static inline auto PLAYER_DEFAULT_PROFILE_NAME = PreyGlobal<const char*>(0x23B7110);
	static inline auto PROFILE_UUID = PreyGlobal<const char* const>(0x1E12FE0);
#endif // !MOONCRASH
	static constexpr const int k_maxOnlineDataCount = 1500;
	static constexpr const int k_maxOnlineDataBytes = 2976;
	static constexpr const int k_onlineChecksums = 2;
	SCryLobbyUserData m_defaultOnlineData[1500];
	SCryLobbyUserData m_onlineData[1500];
	bool m_onlineOnlyData[1500];
	VectorMap<CryStringT<char>,unsigned int,std::less<CryStringT<char> >,std::allocator<std::pair<CryStringT<char>,unsigned int> > > m_onlineAttributeMap;
	std::vector<IPlayerProfileListener*> m_listeners;
	std::vector<CPlayerProfileManager::SUserEntry*> m_userVec;
	string m_sharedSaveGameFolder;
	string m_curUserID;
	int m_curUserIndex;
	unsigned m_curPlatformUserId;
	unsigned m_exclusiveControllerDeviceIndex;
	unsigned m_onlineDataCount;
	unsigned m_onlineDataByteCount;
	unsigned m_onlineAttributeAutoGeneratedVersion;
	CPlayerProfileManager::IPlatformImpl* m_pImpl;
	CPlayerProfile* m_pDefaultProfile;
	IPlayerProfile* m_pReadingProfile;
	IOnlineAttributesListener::EState m_onlineAttributesState[2];
	IOnlineAttributesListener* m_onlineAttributesListener;
	int m_onlineAttributeDefinedVersion;
	unsigned m_lobbyTaskId;
	bool m_registered;
	bool m_bInitialized;
	bool m_enableOnlineAttributes;
	bool m_allowedToProcessOnlineAttributes;
	bool m_loadingProfile;
	bool m_savingProfile;

	virtual ~CPlayerProfileManager();
	virtual bool Initialize();
	virtual bool Shutdown();
	virtual int GetUserCount();
	virtual bool GetUserInfo(int index, IPlayerProfileManager::SUserInfo& outInfo);
	virtual bool GetUserInfo(const char* userId, IPlayerProfileManager::SUserInfo& outInfo) const;
	virtual void RefreshUserPlatformInfo();
	virtual const char* GetCurrentUser();
	virtual int GetCurrentUserIndex();
	virtual bool LoginUser(const char* userId, bool& bOutFirstTime);
	virtual bool LogoutUser(const char* userId, bool isRemove);
	virtual int GetProfileCount(const char* userId);
	virtual bool GetProfileInfo(const char* userId, int index, IPlayerProfileManager::SProfileDescription& outInfo);
	virtual bool CreateProfile(const char* userId, const char* profileName, bool bOverride, IPlayerProfileManager::EProfileOperationResult& result);
	virtual bool SaveProfile(const char* userId, IPlayerProfileManager::EProfileOperationResult& result, unsigned reason);
	virtual bool IsLoadingProfile() const;
	virtual bool IsSavingProfile() const;
	virtual IPlayerProfile* ActivateProfile(const char* userId, const char* profileName);
	virtual IPlayerProfile* GetCurrentProfile(const char* userId);
	virtual bool ResetProfile(const char* userId);
	virtual void ReloadProfile(IPlayerProfile* pProfile, unsigned reason);
	virtual IPlayerProfile* GetDefaultProfile();
	virtual const IPlayerProfile* PreviewProfile(const char* userId, const char* profileName);
	virtual void SetSharedSaveGameFolder(const char* sharedSaveGameFolder);
	virtual const char* GetSharedSaveGameFolder();
	virtual void GetMemoryStatistics(ICrySizer* s);
	virtual void AddListener(IPlayerProfileListener* pListener, bool updateNow);
	virtual void RemoveListener(IPlayerProfileListener* pListener);
	virtual void AddOnlineAttributesListener(IOnlineAttributesListener* pListener);
	virtual void RemoveOnlineAttributesListener(IOnlineAttributesListener* pListener);
	virtual void EnableOnlineAttributes(bool enable);
	virtual bool HasEnabledOnlineAttributes() const;
	virtual bool CanProcessOnlineAttributes() const;
	virtual void SetCanProcessOnlineAttributes(bool enable);
	virtual bool RegisterOnlineAttributes();
	virtual void GetOnlineAttributesState(const IOnlineAttributesListener::EEvent event, IOnlineAttributesListener::EState& state) const;
	virtual bool IsOnlineOnlyAttribute(const char* name);
	virtual void LoadOnlineAttributes(IPlayerProfile* pProfile);
	virtual void SaveOnlineAttributes(IPlayerProfile* pProfile);
	virtual int GetOnlineAttributesVersion() const;
	virtual int GetOnlineAttributeIndexByName(const char* name);
	virtual void GetOnlineAttributesDataFormat(SCryLobbyUserData* pData, unsigned numData);
	virtual unsigned GetOnlineAttributeCount();
	virtual void ClearOnlineAttributes();
	virtual void SetProfileLastLoginTime(const char* userId, int index, int64_t lastLoginTime);
	_smart_ptr<ISaveGameEnumerator> CreateSaveGameEnumerator(const char* userId, CPlayerProfile* pProfile, int _slot) { alignas(_smart_ptr<ISaveGameEnumerator>) std::byte _return_buf_[sizeof(_smart_ptr<ISaveGameEnumerator>)]; return *FCreateSaveGameEnumerator(this, reinterpret_cast<_smart_ptr<ISaveGameEnumerator>*>(_return_buf_), userId, pProfile, _slot); }
	ISaveGame* CreateSaveGame(const char* userId, CPlayerProfile* pProfile, int _slot) { return FCreateSaveGame(this, userId, pProfile, _slot); }
	ILoadGame* CreateLoadGame(const char* userId, CPlayerProfile* pProfile, int _slot) { return FCreateLoadGame(this, userId, pProfile, _slot); }
	bool DeleteSaveGame(const char* userId, CPlayerProfile* pProfile, int _slot, const char* name) { return FDeleteSaveGame(this, userId, pProfile, _slot, name); }
	XmlNodeRef GetLevelState(const char* const _userId, const CPlayerProfile* const _pProfile, int _slot, const char* const _levelName) const { alignas(XmlNodeRef) std::byte _return_buf_[sizeof(XmlNodeRef)]; return *FGetLevelState(this, reinterpret_cast<XmlNodeRef*>(_return_buf_), _userId, _pProfile, _slot, _levelName); }
	virtual ILevelRotationFile* GetLevelRotationFile(const char* userId, CPlayerProfile* pProfile, const char* name);
	virtual bool ResolveAttributeBlock(const char* userId, const char* attrBlockName, IResolveAttributeBlockListener* pListener, int reason);
	virtual bool ResolveAttributeBlock(const char* userId, const IPlayerProfileManager::SResolveAttributeRequest& attrBlockNameRequest, IResolveAttributeBlockListener* pListener, int reason);
	virtual void SetOnlineAttributes(IPlayerProfile* pProfile, const SCryLobbyUserData* pData, const int onlineDataCount);
	virtual unsigned GetOnlineAttributes(SCryLobbyUserData* pData, unsigned numData);
	virtual unsigned GetDefaultOnlineAttributes(SCryLobbyUserData* pData, unsigned numData);
	virtual void ApplyChecksums(SCryLobbyUserData* pData, unsigned numData);
	virtual bool ValidChecksums(const SCryLobbyUserData* pData, unsigned numData);
	CPlayerProfileManager::SUserEntry* FindEntry(const char* userId) const { return FFindEntryOv1(this, userId); }
	CPlayerProfileManager::SLocalProfileInfo* GetLocalProfileInfo(CPlayerProfileManager::SUserEntry* pEntry, const char* profileName) const { return FGetLocalProfileInfoOv1(this, pEntry, profileName); }
	bool SetUserData(SCryLobbyUserData* data, const TFlowInputData& value) { return FSetUserData(this, data, value); }
	bool ReadUserData(const SCryLobbyUserData* data, TFlowInputData& val) { return FReadUserData(this, data, val); }
	bool RegisterOnlineAttribute(const char* name, const char* type, const bool onlineOnly, const SCryLobbyUserData& defaultValue, CCrc32& crc) { return FRegisterOnlineAttribute(this, name, type, onlineOnly, defaultValue, crc); }
	void ReadOnlineAttributes(IPlayerProfile* pProfile, const SCryLobbyUserData* pData, const unsigned numData) { FReadOnlineAttributes(this, pProfile, pData, numData); }
	static void ReadUserDataCallback(unsigned taskID, ECryLobbyError error, SCryLobbyUserData* pData, unsigned numData, void* pArg) { FReadUserDataCallback(taskID, error, pData, numData, pArg); }
	static void RegisterUserDataCallback(unsigned taskID, ECryLobbyError error, void* pArg) { FRegisterUserDataCallback(taskID, error, pArg); }
	static void WriteUserDataCallback(unsigned taskID, ECryLobbyError error, void* pArg) { FWriteUserDataCallback(taskID, error, pArg); }
	bool LoadProfile(CPlayerProfileManager::SUserEntry* pEntry, CPlayerProfile* pProfile, const char* name, bool bPreview) { return FLoadProfile(this, pEntry, pProfile, name, bPreview); }

#if 0
	const string& GetSharedSaveGameFolder() const;
	void LoadGamerProfileDefaults(IPlayerProfile* _arg0_);
	bool IsSaveGameFolderShared() const;
	CPlayerProfile* GetDefaultCPlayerProfile() const;
	CPlayerProfileManager::SUserEntry* FindEntry(const char* _arg0_, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CPlayerProfileManager::SUserEntry *> > >& _arg1_);
	CPlayerProfileManager::SLocalProfileInfo* GetLocalProfileInfo(CPlayerProfileManager::SUserEntry* _arg0_, const char* _arg1_, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CPlayerProfileManager::SLocalProfileInfo> > >& _arg2_) const;
	unsigned UserDataSize(const SCryLobbyUserData* _arg0_);
	bool SetUserDataType(SCryLobbyUserData* _arg0_, const char* _arg1_);
	void GetDefaultValue(const char* _arg0_, XmlNodeRef _arg1_, SCryLobbyUserData* _arg2_);
	void SetOnlineAttributesState(const IOnlineAttributesListener::EEvent _arg0_, const IOnlineAttributesListener::EState _arg1_);
	void SendOnlineAttributeState(const IOnlineAttributesListener::EEvent _arg0_, const IOnlineAttributesListener::EState _arg1_);
	int Checksum(const int _arg0_, const SCryLobbyUserData* _arg1_, unsigned _arg2_);
	int ChecksumHash(const int _arg0_, const int _arg1_) const;
	int ChecksumHash(const int _arg0_, const int _arg1_, const int _arg2_, const int _arg3_, const int _arg4_) const;
	int ChecksumConvertValueToInt(const SCryLobbyUserData* _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FCPlayerProfileManagerOv1 = PreyFunction<void(CPlayerProfileManager* const _this, CPlayerProfileManager::IPlatformImpl* pImpl)>(0x534BD0);
	static inline auto FBitNotCPlayerProfileManager = PreyFunction<void(CPlayerProfileManager* const _this)>(0x5350E0);
	static inline auto FInitialize = PreyFunction<bool(CPlayerProfileManager* const _this)>(0x537550);
	static inline auto FShutdown = PreyFunction<bool(CPlayerProfileManager* const _this)>(0x539BC0);
	static inline auto FGetUserCount = PreyFunction<int(CPlayerProfileManager* const _this)>(0x537380);
	static inline auto FGetUserInfoOv1 = PreyFunction<bool(CPlayerProfileManager* const _this, int index, IPlayerProfileManager::SUserInfo& outInfo)>(0x5373A0);
	static inline auto FGetUserInfoOv0 = PreyFunction<bool(const CPlayerProfileManager* const _this, const char* userId, IPlayerProfileManager::SUserInfo& outInfo)>(0x537430);
	static inline auto FRefreshUserPlatformInfo = PreyFunction<void(CPlayerProfileManager* const _this)>(0x538860);
	static inline auto FGetCurrentUser = PreyFunction<const char* (CPlayerProfileManager* const _this)>(0x536AA0);
	static inline auto FGetCurrentUserIndex = PreyFunction<int(CPlayerProfileManager* const _this)>(0x536AB0);
	static inline auto FLoginUser = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, bool& bOutFirstTime)>(0x537A60);
	static inline auto FLogoutUser = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, bool isRemove)>(0x537E50);
	static inline auto FGetProfileCount = PreyFunction<int(CPlayerProfileManager* const _this, const char* userId)>(0x5370B0);
	static inline auto FGetProfileInfo = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, int index, IPlayerProfileManager::SProfileDescription& outInfo)>(0x537120);
	static inline auto FCreateProfile = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, const char* profileName, bool bOverride, IPlayerProfileManager::EProfileOperationResult& result)>(0x535D80);
	static inline auto FSaveProfile = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, IPlayerProfileManager::EProfileOperationResult& result, unsigned reason)>(0x539740);
	static inline auto FIsLoadingProfile = PreyFunction<bool(const CPlayerProfileManager* const _this)>(0x537630);
	static inline auto FIsSavingProfile = PreyFunction<bool(const CPlayerProfileManager* const _this)>(0x5377E0);
	static inline auto FActivateProfile = PreyFunction<IPlayerProfile* (CPlayerProfileManager* const _this, const char* userId, const char* profileName)>(0x5357B0);
	static inline auto FGetCurrentProfile = PreyFunction<IPlayerProfile* (CPlayerProfileManager* const _this, const char* userId)>(0x536A30);
	static inline auto FResetProfile = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId)>(0x539250);
	static inline auto FReloadProfile = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfile* pProfile, unsigned reason)>(0x539150);
	static inline auto FGetDefaultProfile = PreyFunction<IPlayerProfile* (CPlayerProfileManager* const _this)>(0x536B10);
	static inline auto FPreviewProfile = PreyFunction<const IPlayerProfile* (CPlayerProfileManager* const _this, const char* userId, const char* profileName)>(0x538020);
	static inline auto FSetSharedSaveGameFolder = PreyFunction<void(CPlayerProfileManager* const _this, const char* sharedSaveGameFolder)>(0x5399A0);
	static inline auto FGetSharedSaveGameFolderOv1 = PreyFunction<const char* (CPlayerProfileManager* const _this)>(0x5371B0);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CPlayerProfileManager* const _this, ICrySizer* s)>(0x536DC0);
	static inline auto FAddListener = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfileListener* pListener, bool updateNow)>(0x535960);
	static inline auto FRemoveListener = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfileListener* pListener)>(0x5391E0);
	static inline auto FAddOnlineAttributesListener = PreyFunction<void(CPlayerProfileManager* const _this, IOnlineAttributesListener* pListener)>(0x535A30);
	static inline auto FRemoveOnlineAttributesListener = PreyFunction<void(CPlayerProfileManager* const _this, IOnlineAttributesListener* pListener)>(0x539230);
	static inline auto FEnableOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, bool enable)>(0x5369A0);
	static inline auto FHasEnabledOnlineAttributes = PreyFunction<bool(const CPlayerProfileManager* const _this)>(0x537540);
	static inline auto FCanProcessOnlineAttributes = PreyFunction<bool(const CPlayerProfileManager* const _this)>(0x535C60);
	static inline auto FSetCanProcessOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, bool enable)>(0x539900);
	static inline auto FRegisterOnlineAttributes = PreyFunction<bool(CPlayerProfileManager* const _this)>(0x538BE0);
	static inline auto FGetOnlineAttributesState = PreyFunction<void(const CPlayerProfileManager* const _this, const IOnlineAttributesListener::EEvent event, IOnlineAttributesListener::EState& state)>(0x537090);
	static inline auto FIsOnlineOnlyAttribute = PreyFunction<bool(CPlayerProfileManager* const _this, const char* name)>(0x537640);
	static inline auto FLoadOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfile* pProfile)>(0x5377F0);
	static inline auto FSaveOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfile* pProfile)>(0x5394B0);
	static inline auto FGetOnlineAttributesVersion = PreyFunction<int(const CPlayerProfileManager* const _this)>(0x5370A0);
	static inline auto FGetOnlineAttributeIndexByName = PreyFunction<int(CPlayerProfileManager* const _this, const char* name)>(0x536E90);
	static inline auto FGetOnlineAttributesDataFormat = PreyFunction<void(CPlayerProfileManager* const _this, SCryLobbyUserData* pData, unsigned numData)>(0x537040);
	static inline auto FGetOnlineAttributeCount = PreyFunction<unsigned(CPlayerProfileManager* const _this)>(0x536E80);
	static inline auto FClearOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this)>(0x535C70);
	static inline auto FSetProfileLastLoginTime = PreyFunction<void(CPlayerProfileManager* const _this, const char* userId, int index, int64_t lastLoginTime)>(0x539920);
	static inline auto FCreateSaveGameEnumerator = PreyFunction<_smart_ptr<ISaveGameEnumerator>*(CPlayerProfileManager* const _this, _smart_ptr<ISaveGameEnumerator>* _return_value_, const char* userId, CPlayerProfile* pProfile, int _slot)>(0x536020);
	static inline auto FCreateSaveGame = PreyFunction<ISaveGame* (CPlayerProfileManager* const _this, const char* userId, CPlayerProfile* pProfile, int _slot)>(0x535FA0);
	static inline auto FCreateLoadGame = PreyFunction<ILoadGame* (CPlayerProfileManager* const _this, const char* userId, CPlayerProfile* pProfile, int _slot)>(0x535D00);
	static inline auto FDeleteSaveGame = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, CPlayerProfile* pProfile, int _slot, const char* name)>(0x5362A0);
	static inline auto FGetLevelState = PreyFunction<XmlNodeRef*(const CPlayerProfileManager* const _this, XmlNodeRef* _return_value_, const char* const _userId, const CPlayerProfile* const _pProfile, int _slot, const char* const _levelName)>(0x536C80);
	static inline auto FGetLevelRotationFile = PreyFunction<ILevelRotationFile* (CPlayerProfileManager* const _this, const char* userId, CPlayerProfile* pProfile, const char* name)>(0x536C00);
	static inline auto FResolveAttributeBlockOv1 = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, const char* attrBlockName, IResolveAttributeBlockListener* pListener, int reason)>(0x5392E0);
	static inline auto FResolveAttributeBlockOv0 = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, const IPlayerProfileManager::SResolveAttributeRequest& attrBlockNameRequest, IResolveAttributeBlockListener* pListener, int reason)>(0x5393C0);
	static inline auto FSetOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfile* pProfile, const SCryLobbyUserData* pData, const int onlineDataCount)>(0x539910);
	static inline auto FGetOnlineAttributes = PreyFunction<unsigned(CPlayerProfileManager* const _this, SCryLobbyUserData* pData, unsigned numData)>(0x536FF0);
	static inline auto FGetDefaultOnlineAttributes = PreyFunction<unsigned(CPlayerProfileManager* const _this, SCryLobbyUserData* pData, unsigned numData)>(0x536AC0);
	static inline auto FApplyChecksums = PreyFunction<void(CPlayerProfileManager* const _this, SCryLobbyUserData* pData, unsigned numData)>(0x535A40);
	static inline auto FValidChecksums = PreyFunction<bool(CPlayerProfileManager* const _this, const SCryLobbyUserData* pData, unsigned numData)>(0x53A320);
	static inline auto FFindEntryOv1 = PreyFunction<CPlayerProfileManager::SUserEntry* (const CPlayerProfileManager* const _this, const char* userId)>(0x5369B0);
	static inline auto FGetLocalProfileInfoOv1 = PreyFunction<CPlayerProfileManager::SLocalProfileInfo* (const CPlayerProfileManager* const _this, CPlayerProfileManager::SUserEntry* pEntry, const char* profileName)>(0x536D60);
	static inline auto FSetUserData = PreyFunction<bool(CPlayerProfileManager* const _this, SCryLobbyUserData* data, const TFlowInputData& value)>(0x539A30);
	static inline auto FReadUserData = PreyFunction<bool(CPlayerProfileManager* const _this, const SCryLobbyUserData* data, TFlowInputData& val)>(0x538530);
	static inline auto FRegisterOnlineAttribute = PreyFunction<bool(CPlayerProfileManager* const _this, const char* name, const char* type, const bool onlineOnly, const SCryLobbyUserData& defaultValue, CCrc32& crc)>(0x5388F0);
	static inline auto FReadOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfile* pProfile, const SCryLobbyUserData* pData, const unsigned numData)>(0x5381A0);
	static inline auto FReadUserDataCallback = PreyFunction<void(unsigned taskID, ECryLobbyError error, SCryLobbyUserData* pData, unsigned numData, void* pArg)>(0x5386D0);
	static inline auto FRegisterUserDataCallback = PreyFunction<void(unsigned taskID, ECryLobbyError error, void* pArg)>(0x5390C0);
	static inline auto FWriteUserDataCallback = PreyFunction<void(unsigned taskID, ECryLobbyError error, void* pArg)>(0xA13080);
	static inline auto FLoadProfile = PreyFunction<bool(CPlayerProfileManager* const _this, CPlayerProfileManager::SUserEntry* pEntry, CPlayerProfile* pProfile, const char* name, bool bPreview)>(0x537980);
#else // MOONCRASH
	static inline auto FCPlayerProfileManagerOv1 = PreyFunction<void(CPlayerProfileManager* const _this, CPlayerProfileManager::IPlatformImpl* pImpl)>(0x54E010);
	static inline auto FBitNotCPlayerProfileManager = PreyFunction<void(CPlayerProfileManager* const _this)>(0x54E5F0);
	static inline auto FInitialize = PreyFunction<bool(CPlayerProfileManager* const _this)>(0x550A20);
	static inline auto FShutdown = PreyFunction<bool(CPlayerProfileManager* const _this)>(0x5530B0);
	static inline auto FGetUserCount = PreyFunction<int(CPlayerProfileManager* const _this)>(0x550850);
	static inline auto FGetUserInfoOv1 = PreyFunction<bool(CPlayerProfileManager* const _this, int index, IPlayerProfileManager::SUserInfo& outInfo)>(0x550870);
	static inline auto FGetUserInfoOv0 = PreyFunction<bool(const CPlayerProfileManager* const _this, const char* userId, IPlayerProfileManager::SUserInfo& outInfo)>(0x550900);
	static inline auto FRefreshUserPlatformInfo = PreyFunction<void(CPlayerProfileManager* const _this)>(0x551D30);
	static inline auto FGetCurrentUser = PreyFunction<const char* (CPlayerProfileManager* const _this)>(0x54FF80);
	static inline auto FGetCurrentUserIndex = PreyFunction<int(CPlayerProfileManager* const _this)>(0x54FF90);
	static inline auto FLoginUser = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, bool& bOutFirstTime)>(0x550F30);
	static inline auto FLogoutUser = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, bool isRemove)>(0x551320);
	static inline auto FGetProfileCount = PreyFunction<int(CPlayerProfileManager* const _this, const char* userId)>(0x550590);
	static inline auto FGetProfileInfo = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, int index, IPlayerProfileManager::SProfileDescription& outInfo)>(0x550600);
	static inline auto FCreateProfile = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, const char* profileName, bool bOverride, IPlayerProfileManager::EProfileOperationResult& result)>(0x54F260);
	static inline auto FSaveProfile = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, IPlayerProfileManager::EProfileOperationResult& result, unsigned reason)>(0x552C30);
	static inline auto FIsLoadingProfile = PreyFunction<bool(const CPlayerProfileManager* const _this)>(0x550B00);
	static inline auto FIsSavingProfile = PreyFunction<bool(const CPlayerProfileManager* const _this)>(0x550CB0);
	static inline auto FActivateProfile = PreyFunction<IPlayerProfile* (CPlayerProfileManager* const _this, const char* userId, const char* profileName)>(0x54EC90);
	static inline auto FGetCurrentProfile = PreyFunction<IPlayerProfile* (CPlayerProfileManager* const _this, const char* userId)>(0x54FF10);
	static inline auto FResetProfile = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId)>(0x552740);
	static inline auto FReloadProfile = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfile* pProfile, unsigned reason)>(0x552640);
	static inline auto FGetDefaultProfile = PreyFunction<IPlayerProfile* (CPlayerProfileManager* const _this)>(0x54FFF0);
	static inline auto FPreviewProfile = PreyFunction<const IPlayerProfile* (CPlayerProfileManager* const _this, const char* userId, const char* profileName)>(0x5514F0);
	static inline auto FSetSharedSaveGameFolder = PreyFunction<void(CPlayerProfileManager* const _this, const char* sharedSaveGameFolder)>(0x552E90);
	static inline auto FGetSharedSaveGameFolderOv1 = PreyFunction<const char* (CPlayerProfileManager* const _this)>(0x550690);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CPlayerProfileManager* const _this, ICrySizer* s)>(0x5502A0);
	static inline auto FAddListener = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfileListener* pListener, bool updateNow)>(0x54EE40);
	static inline auto FRemoveListener = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfileListener* pListener)>(0x5526D0);
	static inline auto FAddOnlineAttributesListener = PreyFunction<void(CPlayerProfileManager* const _this, IOnlineAttributesListener* pListener)>(0x54EF10);
	static inline auto FRemoveOnlineAttributesListener = PreyFunction<void(CPlayerProfileManager* const _this, IOnlineAttributesListener* pListener)>(0x552720);
	static inline auto FEnableOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, bool enable)>(0x54FE80);
	static inline auto FHasEnabledOnlineAttributes = PreyFunction<bool(const CPlayerProfileManager* const _this)>(0x550A10);
	static inline auto FCanProcessOnlineAttributes = PreyFunction<bool(const CPlayerProfileManager* const _this)>(0x54F140);
	static inline auto FSetCanProcessOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, bool enable)>(0x552DF0);
	static inline auto FRegisterOnlineAttributes = PreyFunction<bool(CPlayerProfileManager* const _this)>(0x5520B0);
	static inline auto FGetOnlineAttributesState = PreyFunction<void(const CPlayerProfileManager* const _this, const IOnlineAttributesListener::EEvent event, IOnlineAttributesListener::EState& state)>(0x550570);
	static inline auto FIsOnlineOnlyAttribute = PreyFunction<bool(CPlayerProfileManager* const _this, const char* name)>(0x550B10);
	static inline auto FLoadOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfile* pProfile)>(0x550CC0);
	static inline auto FSaveOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfile* pProfile)>(0x5529A0);
	static inline auto FGetOnlineAttributesVersion = PreyFunction<int(const CPlayerProfileManager* const _this)>(0x550580);
	static inline auto FGetOnlineAttributeIndexByName = PreyFunction<int(CPlayerProfileManager* const _this, const char* name)>(0x550370);
	static inline auto FGetOnlineAttributesDataFormat = PreyFunction<void(CPlayerProfileManager* const _this, SCryLobbyUserData* pData, unsigned numData)>(0x550520);
	static inline auto FGetOnlineAttributeCount = PreyFunction<unsigned(CPlayerProfileManager* const _this)>(0x550360);
	static inline auto FClearOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this)>(0x54F150);
	static inline auto FSetProfileLastLoginTime = PreyFunction<void(CPlayerProfileManager* const _this, const char* userId, int index, int64_t lastLoginTime)>(0x552E10);
	static inline auto FCreateSaveGameEnumerator = PreyFunction<_smart_ptr<ISaveGameEnumerator>*(CPlayerProfileManager* const _this, _smart_ptr<ISaveGameEnumerator>* _return_value_, const char* userId, CPlayerProfile* pProfile, int _slot)>(0x54F500);
	static inline auto FCreateSaveGame = PreyFunction<ISaveGame* (CPlayerProfileManager* const _this, const char* userId, CPlayerProfile* pProfile, int _slot)>(0x54F480);
	static inline auto FCreateLoadGame = PreyFunction<ILoadGame* (CPlayerProfileManager* const _this, const char* userId, CPlayerProfile* pProfile, int _slot)>(0x54F1E0);
	static inline auto FDeleteSaveGame = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, CPlayerProfile* pProfile, int _slot, const char* name)>(0x54F780);
	static inline auto FGetLevelState = PreyFunction<XmlNodeRef*(const CPlayerProfileManager* const _this, XmlNodeRef* _return_value_, const char* const _userId, const CPlayerProfile* const _pProfile, int _slot, const char* const _levelName)>(0x550160);
	static inline auto FGetLevelRotationFile = PreyFunction<ILevelRotationFile* (CPlayerProfileManager* const _this, const char* userId, CPlayerProfile* pProfile, const char* name)>(0x5500E0);
	static inline auto FResolveAttributeBlockOv1 = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, const char* attrBlockName, IResolveAttributeBlockListener* pListener, int reason)>(0x5527D0);
	static inline auto FResolveAttributeBlockOv0 = PreyFunction<bool(CPlayerProfileManager* const _this, const char* userId, const IPlayerProfileManager::SResolveAttributeRequest& attrBlockNameRequest, IResolveAttributeBlockListener* pListener, int reason)>(0x5528B0);
	static inline auto FSetOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfile* pProfile, const SCryLobbyUserData* pData, const int onlineDataCount)>(0x552E00);
	static inline auto FGetOnlineAttributes = PreyFunction<unsigned(CPlayerProfileManager* const _this, SCryLobbyUserData* pData, unsigned numData)>(0x5504D0);
	static inline auto FGetDefaultOnlineAttributes = PreyFunction<unsigned(CPlayerProfileManager* const _this, SCryLobbyUserData* pData, unsigned numData)>(0x54FFA0);
	static inline auto FApplyChecksums = PreyFunction<void(CPlayerProfileManager* const _this, SCryLobbyUserData* pData, unsigned numData)>(0x54EF20);
	static inline auto FValidChecksums = PreyFunction<bool(CPlayerProfileManager* const _this, const SCryLobbyUserData* pData, unsigned numData)>(0x553810);
	static inline auto FFindEntryOv1 = PreyFunction<CPlayerProfileManager::SUserEntry* (const CPlayerProfileManager* const _this, const char* userId)>(0x54FE90);
	static inline auto FGetLocalProfileInfoOv1 = PreyFunction<CPlayerProfileManager::SLocalProfileInfo* (const CPlayerProfileManager* const _this, CPlayerProfileManager::SUserEntry* pEntry, const char* profileName)>(0x550240);
	static inline auto FSetUserData = PreyFunction<bool(CPlayerProfileManager* const _this, SCryLobbyUserData* data, const TFlowInputData& value)>(0x552F20);
	static inline auto FReadUserData = PreyFunction<bool(CPlayerProfileManager* const _this, const SCryLobbyUserData* data, TFlowInputData& val)>(0x551A00);
	static inline auto FRegisterOnlineAttribute = PreyFunction<bool(CPlayerProfileManager* const _this, const char* name, const char* type, const bool onlineOnly, const SCryLobbyUserData& defaultValue, CCrc32& crc)>(0x551DC0);
	static inline auto FReadOnlineAttributes = PreyFunction<void(CPlayerProfileManager* const _this, IPlayerProfile* pProfile, const SCryLobbyUserData* pData, const unsigned numData)>(0x551670);
	static inline auto FReadUserDataCallback = PreyFunction<void(unsigned taskID, ECryLobbyError error, SCryLobbyUserData* pData, unsigned numData, void* pArg)>(0x551BA0);
	static inline auto FRegisterUserDataCallback = PreyFunction<void(unsigned taskID, ECryLobbyError error, void* pArg)>(0x552590);
	static inline auto FWriteUserDataCallback = PreyFunction<void(unsigned taskID, ECryLobbyError error, void* pArg)>(0x1333E90);
	static inline auto FLoadProfile = PreyFunction<bool(CPlayerProfileManager* const _this, CPlayerProfileManager::SUserEntry* pEntry, CPlayerProfile* pProfile, const char* name, bool bPreview)>(0x550E50);
#endif // !MOONCRASH
};

static_assert(sizeof(CPlayerProfileManager) == 49680);
static_assert(sizeof(CPlayerProfileManager::SUserEntry) == 104);
static_assert(sizeof(CPlayerProfileManager::SSaveGameMetaData) == 56);
static_assert(sizeof(CPlayerProfileManager::SSaveGameInfo) == 64);
