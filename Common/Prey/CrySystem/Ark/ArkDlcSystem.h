// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/Ark/IArkDlcSystem.h>

struct IArkDlcListener;
struct SSystemGlobalEnvironment;

// CArkDlcSystem
// Header:  d:/_perforce/danielle/preybnet/code/preydll/ArkDlcSystem.h
class CArkDlcSystem : public IArkDlcSystem
{ // Size=168 (0xA8)
public:
	// CArkDlcSystem::ArkDlcInfo
	// Header:  d:/_perforce/danielle/preybnet/code/preydll/ArkDlcSystem.h
	struct ArkDlcInfo
	{ // Size=72 (0x48)
		unsigned dlcId;
		string Name;
		bool bUnlocked;
		bool bMounted;
		string mountPoint;
		string folderPath;
		string SteamId;
		string PS4ContentLabel;
		string XB1ProductId;
		unsigned NpServiceLabel;
		
	#if 0
		const char* GetPlatformId() const;
		bool IsValidForPlatform() const;
	#endif
	};

	struct HashHack
	{
		size_t operator()(const string& s) { CryFatalError("HashHack: Not supported"); return 0; }
	};
	
	bool m_bRequestRefresh;
	std::vector<IArkDlcListener*> m_listeners;
	std::unordered_map<unsigned int, string> m_dlcIdMap;
	std::unordered_map<string, CArkDlcSystem::ArkDlcInfo, HashHack> m_dlcPlatformIdMap;
	
	virtual ~CArkDlcSystem() {}
	virtual bool Init() { return FInit(this); }
	virtual void InitEnv(SSystemGlobalEnvironment* _gEnv) { FInitEnv(this, _gEnv); }
	virtual bool LoadDlcMetadata(const string& _strDlcMetadataFile) { return FLoadDlcMetadata(this, _strDlcMetadataFile); }
	virtual void Update() { FUpdate(this); }
	virtual void RequestRefresh() { FRequestRefresh(this); }
	virtual const char* GetDlcPlatformId(unsigned _dlcId) const { return FGetDlcPlatformId(this, _dlcId); }
	virtual const char* GetFolderPath(unsigned _dlcId) const { return FGetFolderPath(this, _dlcId); }
	virtual bool IsUnlocked(unsigned _dlcId) const { return FIsUnlocked(this, _dlcId); }
	virtual bool IsDlcUnlockedForFolder(const char* _folderName) const { return FIsDlcUnlockedForFolder(this, _folderName); }
	virtual const char* MountDlc(const char* _platformId) { return FMountDlcOv2(this, _platformId); }
	virtual const char* MountDlc(unsigned _dlcId) { return FMountDlcOv1(this, _dlcId); }
	virtual const char* MountDlc(CArkDlcSystem::ArkDlcInfo* pDlcInfo) { return FMountDlcOv0(this, pDlcInfo); }
	virtual void UnMountDlc(const char* _platformId) { FUnMountDlcOv2(this, _platformId); }
	virtual void UnMountDlc(unsigned _dlcId) { FUnMountDlcOv1(this, _dlcId); }
	virtual void UnMountDlc(CArkDlcSystem::ArkDlcInfo* pDlcInfo) { FUnMountDlcOv0(this, pDlcInfo); }
	virtual void UnMountAllDlc() { FUnMountAllDlc(this); }
	virtual void RegisterListener(IArkDlcListener* _pHandler) { FRegisterListener(this, _pHandler); }
	virtual void UnregisterListener(IArkDlcListener* _pHandler) { FUnregisterListener(this, _pHandler); }
	virtual void Refresh() { FRefresh(this); }
	void UpdateDlcUnlocked(CArkDlcSystem::ArkDlcInfo* pDlcInfo, bool _bUnlocked) { FUpdateDlcUnlocked(this, pDlcInfo, _bUnlocked); }
	const CArkDlcSystem::ArkDlcInfo* FindDlcInfoByPlatformId(const char* _platformId) const { return FFindDlcInfoByPlatformIdOv1(this, _platformId); }
	CArkDlcSystem::ArkDlcInfo* FindDlcInfoByPlatformId(const char* _platformId) { return FFindDlcInfoByPlatformIdOv0(this, _platformId); }
	const CArkDlcSystem::ArkDlcInfo* FindDlcInfoByDlcId(unsigned _dlcId) const { return FFindDlcInfoByDlcIdOv1(this, _dlcId); }
	CArkDlcSystem::ArkDlcInfo* FindDlcInfoByDlcId(unsigned _dlcId) { return FFindDlcInfoByDlcIdOv0(this, _dlcId); }
	
#if 0
	CArkDlcSystem();
	CArkDlcSystem(const CArkDlcSystem& _arg0_);
#endif
	
	static inline auto FInit = PreyFunction<bool(CArkDlcSystem* const _this)>(0x1B933B0);
	static inline auto FInitEnv = PreyFunction<void(CArkDlcSystem* const _this, SSystemGlobalEnvironment* _gEnv)>(0xA13080);
	static inline auto FLoadDlcMetadata = PreyFunction<bool(CArkDlcSystem* const _this, const string& _strDlcMetadataFile)>(0x94FA0);
	static inline auto FUpdate = PreyFunction<void(CArkDlcSystem* const _this)>(0x95790);
	static inline auto FRequestRefresh = PreyFunction<void(CArkDlcSystem* const _this)>(0x9D070);
	static inline auto FGetDlcPlatformId = PreyFunction<const char* (const CArkDlcSystem* const _this, unsigned _dlcId)>(0x94EF0);
	static inline auto FGetFolderPath = PreyFunction<const char* (const CArkDlcSystem* const _this, unsigned _dlcId)>(0x94F10);
	static inline auto FIsUnlocked = PreyFunction<bool(const CArkDlcSystem* const _this, unsigned _dlcId)>(0x94F80);
	static inline auto FIsDlcUnlockedForFolder = PreyFunction<bool(const CArkDlcSystem* const _this, const char* _folderName)>(0x94F30);
	static inline auto FMountDlcOv2 = PreyFunction<const char* (CArkDlcSystem* const _this, const char* _platformId)>(0x95620);
	static inline auto FMountDlcOv1 = PreyFunction<const char* (CArkDlcSystem* const _this, unsigned _dlcId)>(0x955F0);
	static inline auto FMountDlcOv0 = PreyFunction<const char* (CArkDlcSystem* const _this, CArkDlcSystem::ArkDlcInfo* pDlcInfo)>(0x158AEF0);
	static inline auto FUnMountDlcOv2 = PreyFunction<void(CArkDlcSystem* const _this, const char* _platformId)>(0x95720);
	static inline auto FUnMountDlcOv1 = PreyFunction<void(CArkDlcSystem* const _this, unsigned _dlcId)>(0x956F0);
	static inline auto FUnMountDlcOv0 = PreyFunction<void(CArkDlcSystem* const _this, CArkDlcSystem::ArkDlcInfo* pDlcInfo)>(0xA13080);
	static inline auto FUnMountAllDlc = PreyFunction<void(CArkDlcSystem* const _this)>(0x956A0);
	static inline auto FRegisterListener = PreyFunction<void(CArkDlcSystem* const _this, IArkDlcListener* _pHandler)>(0x95650);
	static inline auto FUnregisterListener = PreyFunction<void(CArkDlcSystem* const _this, IArkDlcListener* _pHandler)>(0x95750);
	static inline auto FRefresh = PreyFunction<void(CArkDlcSystem* const _this)>(0x96320);
	static inline auto FUpdateDlcUnlocked = PreyFunction<void(CArkDlcSystem* const _this, CArkDlcSystem::ArkDlcInfo* pDlcInfo, bool _bUnlocked)>(0x957B0);
	static inline auto FFindDlcInfoByPlatformIdOv1 = PreyFunction<const CArkDlcSystem::ArkDlcInfo* (const CArkDlcSystem* const _this, const char* _platformId)>(0x94C50);
	static inline auto FFindDlcInfoByPlatformIdOv0 = PreyFunction<CArkDlcSystem::ArkDlcInfo* (CArkDlcSystem* const _this, const char* _platformId)>(0x94A60);
	static inline auto FFindDlcInfoByDlcIdOv1 = PreyFunction<const CArkDlcSystem::ArkDlcInfo* (const CArkDlcSystem* const _this, unsigned _dlcId)>(0x949A0);
	static inline auto FFindDlcInfoByDlcIdOv0 = PreyFunction<CArkDlcSystem::ArkDlcInfo* (CArkDlcSystem* const _this, unsigned _dlcId)>(0x948E0);
};
