// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryfixedstring.h>
#include <CryEngine/crysystem/platformos/PlatformOS_PC.h>
#include <Prey/CryGame/IGameFramework.h>
#include <_unknown/CryFixedArray.h>
#include <_unknown/DLCContents.h>

class CMenuData;
class XmlNodeRef;

// CDLCManager
// Header:  Prey/GameDll/DLCManager.h
class CDLCManager
	: private IPlatformOS::IDLCListener
	, private IPlatformOS::IPlatformListener
	, private IGameWarningsListener
{ // Size=71112 (0x115C8)
public:
	DLCContents m_dlcContents[16];
	CryFixedArray<unsigned int,16> m_itemUnlockDLCids;
	CryFixedStringT<128> m_prevLevelName;
	CryFixedStringT<128> m_dlcWarning;
	unsigned m_loadedDLCs;
	unsigned m_allowedDLCs;
	unsigned m_entitledDLCs;
	unsigned m_warningPriority;
	int m_requiredDLCs;
	bool m_dlcLoaded;
	bool m_allowedDLCUpToDate;
	bool m_allowedDLCCheckFailed;
	bool m_onlineAttributesRead;
	bool m_bContentRemoved;
	bool m_bContentAvailable;
	unsigned m_appliedDLCStat;
	unsigned m_DLCXPToAward;
	bool m_bNewDLCAdded;
	bool m_queueEventEntitlement;
	unsigned m_entitlementTask;

	CDLCManager();
	virtual ~CDLCManager();
	void AddPlaylists() { FAddPlaylists(this); }
	virtual void OnDLCMounted(const XmlNodeRef& rootNode, const char* sDLCRootFolder);
	virtual void OnDLCMountFailed(IPlatformOS::EDLCMountFail reason);
	virtual void OnDLCMountFinished(int nPacksFound);
	virtual void OnPlatformEvent(const IPlatformOS::SPlatformEvent& event);
	virtual bool OnWarningReturn(unsigned id, const char* returnValue);
	virtual void OnWarningRemoved(unsigned id);
	void Update() { FUpdate(this); }
	bool VerifyCRCs(const XmlNodeRef& crcNode, const char* sDLCRootFolder) { return FVerifyCRCs(this, crcNode, sDLCRootFolder); }
	void PopulateDLCContents(const XmlNodeRef& rootNode, int dlcId, const char* name) { FPopulateDLCContents(this, rootNode, dlcId, name); }

#if 0
	void LoadDownloadableContent(unsigned _arg0_);
	void DisableDownloadableContent();
	void PatchMenu(CMenuData& _arg0_);
	bool IsDLCLoaded(int _arg0_) const;
	unsigned GetLoadedDLCs() const;
	unsigned GetSquadCommonDLCs();
	unsigned GetRequiredDLCsForLevel(const char* _arg0_);
	unsigned GetRequiredDLCs();
	static bool MeetsDLCRequirements(unsigned _arg0_, unsigned _arg1_);
	bool IsLevelStandard(const char* _arg0_);
	bool IsGameModeStandard(const char* _arg0_);
	void ActivatePreSaleBonuses(bool _arg0_, bool _arg1_);
	const char* ScoreRewardsFilename(const char* _arg0_);
	void OnlineAttributesRead();
	void SetAppliedEntitlements(unsigned _arg0_);
	void OnDLCRemoved(const char* _arg0_);
	void ProcessDelayedWarnings();
	unsigned GetAppliedDLCBitfield() const;
	unsigned GetDLCXPToAward() const;
	void ClearDLCXPToAward();
	bool IsPIIEntitlementSet() const;
	bool CheckLevels(int _arg0_, const char* _arg1_);
	void ClearDLCContents(int _arg0_);
	bool LevelExists(const char* _arg0_);
	bool IsDLCReallyLoaded(int _arg0_);
	void RequestDLCWarning(const char* _arg0_, unsigned _arg1_, bool _arg2_);
	int DlcIdForLevel(const char* _arg0_);
	void DoDLCUnlocks(XmlNodeRef _arg0_, int _arg1_);
	void AddNewDLCApplied(const int _arg0_);
	bool IsNewDLC(const int _arg0_) const;
	bool IsEntitlementSet(int _arg0_, bool _arg1_) const;
	int SetEntitlement(int _arg0_, bool _arg1_);
#endif

	static inline auto FCDLCManagerOv1 = PreyFunction<void(CDLCManager* const _this)>(0x17D5F30);
	static inline auto FAddPlaylists = PreyFunction<void(CDLCManager* const _this)>(0x1333E90);
	static inline auto FOnDLCMounted = PreyFunction<void(CDLCManager* const _this, const XmlNodeRef& rootNode, const char* sDLCRootFolder)>(0x17D6440);
	static inline auto FOnDLCMountFailed = PreyFunction<void(CDLCManager* const _this, IPlatformOS::EDLCMountFail reason)>(0x17D63A0);
	static inline auto FOnDLCMountFinished = PreyFunction<void(CDLCManager* const _this, int nPacksFound)>(0x17D63C0);
	static inline auto FOnPlatformEvent = PreyFunction<void(IPlatformOS::IPlatformListener* const _this, const IPlatformOS::SPlatformEvent& event)>(0x17D6C30);
	static inline auto FOnWarningReturn = PreyFunction<bool(IGameWarningsListener* const _this, unsigned id, const char* returnValue)>(0x1A302A0);
	static inline auto FOnWarningRemoved = PreyFunction<void(IGameWarningsListener* const _this, unsigned id)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CDLCManager* const _this)>(0x1333E90);
	static inline auto FVerifyCRCs = PreyFunction<bool(CDLCManager* const _this, const XmlNodeRef& crcNode, const char* sDLCRootFolder)>(0x17D7030);
	static inline auto FPopulateDLCContents = PreyFunction<void(CDLCManager* const _this, const XmlNodeRef& rootNode, int dlcId, const char* name)>(0x17D6DC0);
};
#endif // MOONCRASH
