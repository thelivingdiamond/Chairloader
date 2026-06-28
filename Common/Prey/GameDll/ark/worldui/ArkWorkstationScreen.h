// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/worldui/ArkStationWorldUI.h>
#include <Prey/Ark/ArkWorkstation.h>

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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkWorkstation.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/worldui/ArkStationWorldUI.h>

class ArkUtility;
class ArkUtilityButton;
enum class EArkInteractiveScreenType;
enum class EArkStationType;
enum class EArkStationWorldUIState;
class ICrySizer;
struct SEntityUpdateContext;

// ArkWorkstationScreen
// Header:  Prey/GameDll/ark/worldui/ArkWorkstationScreen.h
class ArkWorkstationScreen : public ArkStationWorldUI
{ // Size=768 (0x300)
public:
	ArkSimpleTimer m_downloadTimer;
	bool m_bIsKasma;
	uint64_t m_workstationId;

	ArkWorkstationScreen();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
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
	void OnFinishDownload(const uint64_t _id) { FOnFinishDownload(this, _id); }
	void ShowDownloadProgressUI() { FShowDownloadProgressUI(this); }
	virtual void SubPageButtonPressed(const string& _buttonName);
	virtual const std::vector<uint64_t>& GetEmails() const;
	virtual const std::vector<std::shared_ptr<ArkUtility>>& GetUtilities() const;
	virtual const char* GetUtilitiesTitle() const;
	virtual const ArkUtility* FindUtility(const uint64_t _id) const;
	virtual const ArkUtilityButton* FindUtilityButton(const uint64_t _id) const;
	virtual uint64_t GetUtilityButtonOwner(const uint64_t _id) const;
	virtual const char* GetStationTitle() const;
	virtual const char* GetLoginPageType() const;
	virtual EArkStationType GetStationType() const;
	virtual bool CanEnterState(EArkStationWorldUIState _state) const;
	std::pair<int, int> CountDownloads(const std::vector<ArkDownload>& _downloads) const { alignas(std::pair<int, int>) std::byte _return_buf_[sizeof(std::pair<int, int>)]; return *FCountDownloads(this, reinterpret_cast<std::pair<int, int>*>(_return_buf_), _downloads); }
	virtual bool CanClosePopup() const;

#if 0
	void OnStartDownload(const uint64_t _arg0_);
	void OnCancelDownload();
	const std::vector<ArkDownload>& GetDownloads() const;
#endif

	static inline auto FArkWorkstationScreenOv2 = PreyFunction<void(ArkWorkstationScreen* const _this)>(0x14B6850);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkWorkstationScreen* const _this, ICrySizer* _s)>(0x14B6D50);
	static inline auto FUpdate = PreyFunction<void(ArkWorkstationScreen* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x14B8250);
	static inline auto FFullSerialize = PreyFunction<void(ArkWorkstationScreen* const _this, TSerialize _ser)>(0x14B6B50);
	static inline auto FPostSerialize = PreyFunction<void(ArkWorkstationScreen* const _this)>(0x14B7830);
	static inline auto FGetInteractiveScreenType = PreyFunction<EArkInteractiveScreenType(const ArkWorkstationScreen* const _this)>(0x14B6CE0);
	static inline auto FLoadProperties = PreyFunction<void(ArkWorkstationScreen* const _this)>(0x14B70C0);
	static inline auto FOnReset = PreyFunction<void(ArkWorkstationScreen* const _this, bool _bEnteringGameMode)>(0x14B77F0);
	static inline auto FOnDownloadHiddenChanged = PreyFunction<void(IArkEmailListener* const _this, const uint64_t _id)>(0x14B7450);
	static inline auto FGetUnlockedState = PreyFunction<EArkStationWorldUIState(const ArkWorkstationScreen* const _this)>(0x14B6EE0);
	static inline auto FEnterChildDefinedState = PreyFunction<void(ArkWorkstationScreen* const _this)>(0x14B6AE0);
	static inline auto FRefreshRootMenu = PreyFunction<void(ArkWorkstationScreen* const _this)>(0x14B7DF0);
	static inline auto FRefreshChildDefinedUI = PreyFunction<void(ArkWorkstationScreen* const _this, bool _bAnimateIn)>(0x14B7960);
	static inline auto FRefreshChildDefinedDetailUI = PreyFunction<void(ArkWorkstationScreen* const _this)>(0x14B7870);
	static inline auto FOnFinishDownload = PreyFunction<void(ArkWorkstationScreen* const _this, const uint64_t _id)>(0x14B7500);
	static inline auto FShowDownloadProgressUI = PreyFunction<void(ArkWorkstationScreen* const _this)>(0x14B7F40);
	static inline auto FSubPageButtonPressed = PreyFunction<void(ArkWorkstationScreen* const _this, const string& _buttonName)>(0x14B8160);
	static inline auto FGetEmails = PreyFunction<const std::vector<uint64_t>& (const ArkWorkstationScreen* const _this)>(0x14B6CA0);
	static inline auto FGetUtilities = PreyFunction<const std::vector<std::shared_ptr<ArkUtility>>& (const ArkWorkstationScreen* const _this)>(0x14B6FC0);
	static inline auto FGetUtilitiesTitle = PreyFunction<const char* (const ArkWorkstationScreen* const _this)>(0x14B7000);
	static inline auto FFindUtility = PreyFunction<const ArkUtility* (const ArkWorkstationScreen* const _this, const uint64_t _id)>(0x14B6AF0);
	static inline auto FFindUtilityButton = PreyFunction<const ArkUtilityButton* (const ArkWorkstationScreen* const _this, const uint64_t _id)>(0x14B6B20);
	static inline auto FGetUtilityButtonOwner = PreyFunction<uint64_t(const ArkWorkstationScreen* const _this, const uint64_t _id)>(0x14B7090);
	static inline auto FGetStationTitle = PreyFunction<const char* (const ArkWorkstationScreen* const _this)>(0x14B6D70);
	static inline auto FGetLoginPageType = PreyFunction<const char* (const ArkWorkstationScreen* const _this)>(0x14B6CF0);
	static inline auto FGetStationType = PreyFunction<EArkStationType(const ArkWorkstationScreen* const _this)>(0x14B6ED0);
	static inline auto FCanEnterState = PreyFunction<bool(const ArkWorkstationScreen* const _this, EArkStationWorldUIState _state)>(0x14B6980);
	static inline auto FCountDownloads = PreyFunction<std::pair<int, int>*(const ArkWorkstationScreen* const _this, std::pair<int, int>* _return_value_, const std::vector<ArkDownload>& _downloads)>(0x14B6A40);
	static inline auto FCanClosePopup = PreyFunction<bool(const ArkWorkstationScreen* const _this)>(0x14B6940);
};
#endif // !MOONCRASH
