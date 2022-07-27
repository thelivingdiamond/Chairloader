// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/iface/IArkObjectiveStateListener.h>
#include <Prey/GameDll/ark/player/IArkCharacterStatusListener.h>
#include <Prey/GameDll/ark/worldui/ArkStationWorldUI.h>

class ArkCharacter;
class ArkUtility;
class ArkUtilityButton;
class ICrySizer;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/worldui/ArkSecurityStationScreen.h
class ArkSecurityStationScreen : public ArkStationWorldUI, public IArkCharacterStatusListener, public IArkObjectiveStateListener // Id=801BCC5 Size=688
{
public:
	uint64_t m_securityStationId;
	
	ArkSecurityStationScreen();
	virtual ~ArkSecurityStationScreen();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnSelectPersonnel(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual EArkInteractiveScreenType GetInteractiveScreenType() const;
	virtual void RefreshChildDefinedUI(bool _bAnimateIn);
	virtual void LoadProperties();
	virtual void RefreshRootMenu();
	virtual bool IsSecurity() const;
	virtual const char *GetStationTitle() const;
	virtual const char *GetUtilitiesTitle() const;
	virtual void RefreshChildDefinedDetailUI();
	void ShowRosterDetails(std::vector<unsigned __int64> const &_personnel) { FShowRosterDetails(this,_personnel); }
	virtual bool CanEnterState(EArkStationWorldUIState _state) const;
	virtual void OnCharacterStatusChanged(const uint64_t _characterId);
	virtual void OnCharacterDiscovered(const uint64_t _characterId, bool _bDiscovered);
	virtual void OnTaskActivated(uint64_t _taskId);
	virtual void OnTaskDeactivated(uint64_t _taskId);
	virtual void OnTaskCompleted(uint64_t _taskId);
	virtual void OnTaskFailed(uint64_t _taskId);
	void OnTaskUpdated(uint64_t _taskId) { FOnTaskUpdated(this,_taskId); }
	virtual std::vector<unsigned __int64> const &GetEmails() const;
	virtual std::vector<std::shared_ptr<ArkUtility>> const &GetUtilities() const;
	virtual ArkUtility const *FindUtility(const uint64_t _id) const;
	virtual ArkUtilityButton const *FindUtilityButton(const uint64_t _id) const;
	virtual uint64_t GetUtilityButtonOwner(const uint64_t _id) const;
	std::vector<unsigned __int64> const &GetPersonnel(const uint64_t _locationId) const { return FGetPersonnel(this,_locationId); }
	std::pair<int,int> CountPersonnel(std::vector<unsigned __int64> const &_characterIds) const { return FCountPersonnel(this,_characterIds); }
	void UpdateUIForCharacter(ArkCharacter const *_pCharacter, const char *_functionName) const { FUpdateUIForCharacter(this,_pCharacter,_functionName); }
	
#if 0
	const char *GetPersonnelTitle() const;
#endif
	
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkSecurityStationScreen const *const _this, ICrySizer *_s)>(0x13A4DC0);
	static inline auto FOnSelectPersonnel = PreyFunction<void(ArkSecurityStationScreen *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x13A51D0);
	static inline auto FGetInteractiveScreenType = PreyFunction<EArkInteractiveScreenType(ArkSecurityStationScreen const *const _this)>(0x133DF50);
	static inline auto FRefreshChildDefinedUI = PreyFunction<void(ArkSecurityStationScreen *const _this, bool _bAnimateIn)>(0x13A5380);
	static inline auto FLoadProperties = PreyFunction<void(ArkSecurityStationScreen *const _this)>(0x13A4F00);
	static inline auto FRefreshRootMenu = PreyFunction<void(ArkSecurityStationScreen *const _this)>(0x13A5510);
	static inline auto FIsSecurity = PreyFunction<bool(ArkSecurityStationScreen const *const _this)>(0x1B933B0);
	static inline auto FGetStationTitle = PreyFunction<const char *(ArkSecurityStationScreen const *const _this)>(0x13A4E70);
	static inline auto FGetUtilitiesTitle = PreyFunction<const char *(ArkSecurityStationScreen const *const _this)>(0x13A4EC0);
	static inline auto FRefreshChildDefinedDetailUI = PreyFunction<void(ArkSecurityStationScreen *const _this)>(0x13A5340);
	static inline auto FShowRosterDetails = PreyFunction<void(ArkSecurityStationScreen *const _this, std::vector<unsigned __int64> const &_personnel)>(0x13A56D0);
	static inline auto FCanEnterState = PreyFunction<bool(ArkSecurityStationScreen const *const _this, EArkStationWorldUIState _state)>(0x13A4AC0);
	static inline auto FOnCharacterStatusChanged = PreyFunction<void(ArkSecurityStationScreen *const _this, const uint64_t _characterId)>(0x13A5150);
	static inline auto FOnCharacterDiscovered = PreyFunction<void(ArkSecurityStationScreen *const _this, const uint64_t _characterId, bool _bDiscovered)>(0x13B26F0);
	static inline auto FOnTaskActivated = PreyFunction<void(ArkSecurityStationScreen *const _this, uint64_t _taskId)>(0x13A5280);
	static inline auto FOnTaskDeactivated = PreyFunction<void(ArkSecurityStationScreen *const _this, uint64_t _taskId)>(0x13A5280);
	static inline auto FOnTaskCompleted = PreyFunction<void(ArkSecurityStationScreen *const _this, uint64_t _taskId)>(0x13A5280);
	static inline auto FOnTaskFailed = PreyFunction<void(ArkSecurityStationScreen *const _this, uint64_t _taskId)>(0x13A5280);
	static inline auto FOnTaskUpdated = PreyFunction<void(ArkSecurityStationScreen *const _this, uint64_t _taskId)>(0x13A5290);
	static inline auto FGetEmails = PreyFunction<std::vector<unsigned __int64> const &(ArkSecurityStationScreen const *const _this)>(0x13A4D70);
	static inline auto FGetUtilities = PreyFunction<std::vector<std::shared_ptr<ArkUtility>> const &(ArkSecurityStationScreen const *const _this)>(0x13A4E80);
	static inline auto FFindUtility = PreyFunction<ArkUtility const *(ArkSecurityStationScreen const *const _this, const uint64_t _id)>(0x13A4C60);
	static inline auto FFindUtilityButton = PreyFunction<ArkUtilityButton const *(ArkSecurityStationScreen const *const _this, const uint64_t _id)>(0x13A4C90);
	static inline auto FGetUtilityButtonOwner = PreyFunction<uint64_t(ArkSecurityStationScreen const *const _this, const uint64_t _id)>(0x13A4ED0);
	static inline auto FGetPersonnel = PreyFunction<std::vector<unsigned __int64> const &(ArkSecurityStationScreen const *const _this, const uint64_t _locationId)>(0x13A4DE0);
	static inline auto FCountPersonnel = PreyFunction<std::pair<int,int>(ArkSecurityStationScreen const *const _this, std::vector<unsigned __int64> const &_characterIds)>(0x13A4BA0);
	static inline auto FUpdateUIForCharacter = PreyFunction<void(ArkSecurityStationScreen const *const _this, ArkCharacter const *_pCharacter, const char *_functionName)>(0x13A5900);
};

