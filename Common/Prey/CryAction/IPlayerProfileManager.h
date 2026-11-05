// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/Platform/IPlatformOS.h>
#include <Prey/CryAction/IOnlineAttributesListener.h>

class ICrySizer;
class IOnlineAttributesListener;
struct IPlayerProfile;
class IPlayerProfileListener;
struct IResolveAttributeBlockListener;
struct SCryLobbyUserData;

// IPlayerProfileManager
// Header:  _unknown/IPlayerProfileManager.h
// Include: Prey/CryAction/IPlayerProfiles.h
struct IPlayerProfileManager
{ // Size=8 (0x8)
	enum EProfileOperationResult
	{
		ePOR_Success = 0,
		ePOR_NotInitialized = 1,
		ePOR_NameInUse = 2,
		ePOR_UserNotLoggedIn = 3,
		ePOR_NoSuchProfile = 4,
		ePOR_ProfileInUse = 5,
		ePOR_NoActiveProfile = 6,
		ePOR_DefaultProfile = 7,
		ePOR_LoadingProfile = 8,
		ePOR_Unknown = 255,
	};

	// IPlayerProfileManager::SProfileDescription
	// Header:  _unknown/IPlayerProfileManager.h
	struct SProfileDescription
	{ // Size=16 (0x10)
		const char* name;
		int64_t lastLoginTime;

	#if 0
		SProfileDescription();
	#endif
	};

	// IPlayerProfileManager::SUserInfo
	// Header:  _unknown/IPlayerProfileManager.h
	struct SUserInfo
	{ // Size=56 (0x38)
		const char* userId;
		unsigned platformUserId;
		SUserXUID platformUserXUID;

	#if 0
		SUserInfo();
	#endif
	};

	// IPlayerProfileManager::SResolveAttributeRequest
	// Header:  _unknown/IPlayerProfileManager.h
	struct SResolveAttributeRequest
	{ // Size=72 (0x48)
		enum EResolveAttributeBlockConstants
		{
			eRABC_MaxResolveCountPerRequest = 6,
		};

		const char* attrBlockNames[7];
		const char* containerName;
		const char* attrPathPrefix;

	#if 0
		SResolveAttributeRequest();
	#endif
	};

	virtual ~IPlayerProfileManager();
	virtual bool Initialize() = 0;
	virtual bool Shutdown() = 0;
	virtual void GetMemoryStatistics(ICrySizer* s) = 0;
	virtual int GetUserCount() = 0;
	virtual bool GetUserInfo(int index, IPlayerProfileManager::SUserInfo& outInfo) = 0;
	virtual bool GetUserInfo(const char* userId, IPlayerProfileManager::SUserInfo& outInfo) const = 0;
	virtual void RefreshUserPlatformInfo() = 0;
	virtual bool LoginUser(const char* userId, bool& bOutFirstTime) = 0;
	virtual bool LogoutUser(const char* userId, bool isRemove) = 0;
	virtual int GetProfileCount(const char* userId) = 0;
	virtual bool GetProfileInfo(const char* userId, int index, IPlayerProfileManager::SProfileDescription& outInfo) = 0;
	virtual void SetProfileLastLoginTime(const char* userId, int index, int64_t lastLoginTime) = 0;
	virtual bool CreateProfile(const char* userId, const char* profileName, bool bOverride, IPlayerProfileManager::EProfileOperationResult& result) = 0;
	virtual bool SaveProfile(const char* userId, IPlayerProfileManager::EProfileOperationResult& result, unsigned reason) = 0;
	virtual bool IsLoadingProfile() const = 0;
	virtual bool IsSavingProfile() const = 0;
	virtual IPlayerProfile* ActivateProfile(const char* userId, const char* profileName) = 0;
	virtual IPlayerProfile* GetCurrentProfile(const char* userId) = 0;
	virtual const char* GetCurrentUser() = 0;
	virtual int GetCurrentUserIndex() = 0;
	virtual bool ResetProfile(const char* userId) = 0;
	virtual void ReloadProfile(IPlayerProfile* pProfile, unsigned reason) = 0;
	virtual IPlayerProfile* GetDefaultProfile() = 0;
	virtual const IPlayerProfile* PreviewProfile(const char* userId, const char* profileName) = 0;
	virtual void SetSharedSaveGameFolder(const char* sharedSaveGameFolder) = 0;
	virtual const char* GetSharedSaveGameFolder() = 0;
	virtual void AddListener(IPlayerProfileListener* pListener, bool updateNow) = 0;
	virtual void RemoveListener(IPlayerProfileListener* pListener) = 0;
	virtual void AddOnlineAttributesListener(IOnlineAttributesListener* pListener) = 0;
	virtual void RemoveOnlineAttributesListener(IOnlineAttributesListener* pListener) = 0;
	virtual void EnableOnlineAttributes(bool enable) = 0;
	virtual bool HasEnabledOnlineAttributes() const = 0;
	virtual bool CanProcessOnlineAttributes() const = 0;
	virtual void SetCanProcessOnlineAttributes(bool enable) = 0;
	virtual bool RegisterOnlineAttributes() = 0;
	virtual void GetOnlineAttributesState(const IOnlineAttributesListener::EEvent event, IOnlineAttributesListener::EState& state) const = 0;
	virtual void LoadOnlineAttributes(IPlayerProfile* pProfile) = 0;
	virtual void SaveOnlineAttributes(IPlayerProfile* pProfile) = 0;
	virtual void SetOnlineAttributes(IPlayerProfile* pProfile, const SCryLobbyUserData* pData, const int onlineDataCount) = 0;
	virtual unsigned GetOnlineAttributes(SCryLobbyUserData* pData, unsigned numData) = 0;
	virtual unsigned GetDefaultOnlineAttributes(SCryLobbyUserData* pData, unsigned numData) = 0;
	virtual int GetOnlineAttributesVersion() const = 0;
	virtual int GetOnlineAttributeIndexByName(const char* name) = 0;
	virtual void GetOnlineAttributesDataFormat(SCryLobbyUserData* pData, unsigned numData) = 0;
	virtual unsigned GetOnlineAttributeCount() = 0;
	virtual void ClearOnlineAttributes() = 0;
	virtual void ApplyChecksums(SCryLobbyUserData* pData, unsigned numData) = 0;
	virtual bool ValidChecksums(const SCryLobbyUserData* pData, unsigned numData) = 0;
	virtual bool ResolveAttributeBlock(const char* userId, const char* attrBlockName, IResolveAttributeBlockListener* pListener, int reason) = 0;
	virtual bool ResolveAttributeBlock(const char* userId, const IPlayerProfileManager::SResolveAttributeRequest& attrBlockNameRequest, IResolveAttributeBlockListener* pListener, int reason) = 0;
};

