// Header file automatically created from a PDB.
#pragma once

struct SSystemGlobalEnvironment;

// IArkDlcListener
// Header:  _unknown/IArkDlcListener.h
struct IArkDlcListener
{ // Size=8 (0x8)
	virtual void OnDlcStatusChanged(unsigned _dlcId, bool _bUnlocked) = 0;
};

// IArkDlcSystem
// Header:  _unknown/IArkDlcSystem.h
struct IArkDlcSystem
{ // Size=8 (0x8)
	virtual ~IArkDlcSystem() {}
	virtual bool Init() = 0;
	virtual void InitEnv(SSystemGlobalEnvironment* _gEnv) = 0;
	virtual void Update() = 0;
	virtual void RequestRefresh() = 0;
	virtual bool LoadDlcMetadata(const string& _strDlcMetadataFile) = 0;
	virtual const char* GetDlcPlatformId(unsigned _dlcId) const = 0;
	virtual const char* GetFolderPath(unsigned _dlcId) const = 0;
	virtual bool IsUnlocked(unsigned _dlcId) const = 0;
	virtual bool IsDlcUnlockedForFolder(const char* _folderName) const = 0;
	virtual const char* MountDlc(const char* _platformId) = 0;
	virtual const char* MountDlc(unsigned _dlcId) = 0;
	virtual void UnMountDlc(const char* _platformId) = 0;
	virtual void UnMountDlc(unsigned _dlcId) = 0;
	virtual void UnMountAllDlc() = 0;
	virtual void RegisterListener(IArkDlcListener* _pHandler) = 0;
	virtual void UnregisterListener(IArkDlcListener* _pHandler) = 0;
};
