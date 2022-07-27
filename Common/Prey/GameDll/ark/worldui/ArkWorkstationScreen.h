// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/worldui/ArkStationWorldUI.h>

class ArkUtility;
class ArkUtilityButton;
class ICrySizer;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/worldui/ArkWorkstationScreen.h
class ArkWorkstationScreen : public ArkStationWorldUI // Id=801BCF0 Size=680
{
public:
	ArkSimpleTimer m_downloadTimer;
	uint64_t m_workstationId;
	
	ArkWorkstationScreen();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkInteractiveScreenType GetInteractiveScreenType() const;
	virtual void LoadProperties();
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void OnDownloadHiddenChanged(const uint64_t _id);
	virtual EArkStationWorldUIState GetUnlockedState() const;
	virtual void EnterChildDefinedState();
	virtual void RefreshRootMenu();
	virtual void RefreshChildDefinedUI(bool _bAnimateIn);
	virtual void RefreshChildDefinedDetailUI();
	void OnFinishDownload(const uint64_t _id) { FOnFinishDownload(this,_id); }
	void ShowDownloadProgressUI() { FShowDownloadProgressUI(this); }
	virtual void SubPageButtonPressed(string const &_buttonName);
	virtual std::vector<unsigned __int64> const &GetEmails() const;
	virtual std::vector<std::shared_ptr<ArkUtility>> const &GetUtilities() const;
	virtual const char *GetUtilitiesTitle() const;
	virtual ArkUtility const *FindUtility(const uint64_t _id) const;
	virtual ArkUtilityButton const *FindUtilityButton(const uint64_t _id) const;
	virtual uint64_t GetUtilityButtonOwner(const uint64_t _id) const;
	virtual const char *GetStationTitle() const;
	virtual const char *GetLoginPageType() const;
	virtual bool IsSecurity() const;
	virtual bool CanEnterState(EArkStationWorldUIState _state) const;
	std::pair<int,int> CountDownloads(std::vector<ArkDownload> const &_downloads) const { return FCountDownloads(this,_downloads); }
	virtual bool CanClosePopup() const;
	virtual ~ArkWorkstationScreen();
	
#if 0
	void OnStartDownload(const uint64_t arg0);
	void OnCancelDownload();
	std::vector<ArkDownload> const &GetDownloads() const;
#endif
	
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkWorkstationScreen const *const _this, ICrySizer *_s)>(0x1389300);
	static inline auto FUpdate = PreyFunction<void(ArkWorkstationScreen *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x13ACBC0);
	static inline auto FFullSerialize = PreyFunction<void(ArkWorkstationScreen *const _this, TSerialize _ser)>(0x13AB640);
	static inline auto FPostSerialize = PreyFunction<void(ArkWorkstationScreen *const _this)>(0x13AC1A0);
	static inline auto FGetInteractiveScreenType = PreyFunction<EArkInteractiveScreenType(ArkWorkstationScreen const *const _this)>(0x1C4890);
	static inline auto FLoadProperties = PreyFunction<void(ArkWorkstationScreen *const _this)>(0x13ABB70);
	static inline auto FOnReset = PreyFunction<void(ArkWorkstationScreen *const _this, bool _bEnteringGameMode)>(0x13AC160);
	static inline auto FOnDownloadHiddenChanged = PreyFunction<void(ArkWorkstationScreen *const _this, const uint64_t _id)>(0x13ABDC0);
	static inline auto FGetUnlockedState = PreyFunction<EArkStationWorldUIState(ArkWorkstationScreen const *const _this)>(0x13AB990);
	static inline auto FEnterChildDefinedState = PreyFunction<void(ArkWorkstationScreen *const _this)>(0x13AB5D0);
	static inline auto FRefreshRootMenu = PreyFunction<void(ArkWorkstationScreen *const _this)>(0x13AC760);
	static inline auto FRefreshChildDefinedUI = PreyFunction<void(ArkWorkstationScreen *const _this, bool _bAnimateIn)>(0x13AC2D0);
	static inline auto FRefreshChildDefinedDetailUI = PreyFunction<void(ArkWorkstationScreen *const _this)>(0x13AC1E0);
	static inline auto FOnFinishDownload = PreyFunction<void(ArkWorkstationScreen *const _this, const uint64_t _id)>(0x13ABE70);
	static inline auto FShowDownloadProgressUI = PreyFunction<void(ArkWorkstationScreen *const _this)>(0x13AC8B0);
	static inline auto FSubPageButtonPressed = PreyFunction<void(ArkWorkstationScreen *const _this, string const &_buttonName)>(0x13ACAD0);
	static inline auto FGetEmails = PreyFunction<std::vector<unsigned __int64> const &(ArkWorkstationScreen const *const _this)>(0x13AB790);
	static inline auto FGetUtilities = PreyFunction<std::vector<std::shared_ptr<ArkUtility>> const &(ArkWorkstationScreen const *const _this)>(0x13ABA70);
	static inline auto FGetUtilitiesTitle = PreyFunction<const char *(ArkWorkstationScreen const *const _this)>(0x13ABAB0);
	static inline auto FFindUtility = PreyFunction<ArkUtility const *(ArkWorkstationScreen const *const _this, const uint64_t _id)>(0x13AB5E0);
	static inline auto FFindUtilityButton = PreyFunction<ArkUtilityButton const *(ArkWorkstationScreen const *const _this, const uint64_t _id)>(0x13AB610);
	static inline auto FGetUtilityButtonOwner = PreyFunction<uint64_t(ArkWorkstationScreen const *const _this, const uint64_t _id)>(0x13ABB40);
	static inline auto FGetStationTitle = PreyFunction<const char *(ArkWorkstationScreen const *const _this)>(0x13AB830);
	static inline auto FGetLoginPageType = PreyFunction<const char *(ArkWorkstationScreen const *const _this)>(0x13AB7D0);
	static inline auto FIsSecurity = PreyFunction<bool(ArkWorkstationScreen const *const _this)>(0xDD23F0);
	static inline auto FCanEnterState = PreyFunction<bool(ArkWorkstationScreen const *const _this, EArkStationWorldUIState _state)>(0x13AB470);
	static inline auto FCountDownloads = PreyFunction<std::pair<int,int>(ArkWorkstationScreen const *const _this, std::vector<ArkDownload> const &_downloads)>(0x13AB530);
	static inline auto FCanClosePopup = PreyFunction<bool(ArkWorkstationScreen const *const _this)>(0x13AB430);
};

