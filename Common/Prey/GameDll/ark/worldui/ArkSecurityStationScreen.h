// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IArkObjectiveStateListener.h>
#include <Prey/GameDll/ark/player/IArkCharacterStatusListener.h>
#include <Prey/GameDll/ark/worldui/ArkStationWorldUI.h>

class ArkCharacter;
class ArkSecurityStation;
class ArkUtility;
class ArkUtilityButton;
enum class EArkInteractiveScreenType;
enum class EArkStationType;
enum class EArkStationWorldUIState;
class ICrySizer;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// ArkSecurityStationScreen
// Header:  Prey/GameDll/ark/worldui/ArkSecurityStationScreen.h
class ArkSecurityStationScreen
	: public ArkStationWorldUI
	, public IArkCharacterStatusListener
	, public IArkObjectiveStateListener
{ // Size=776 (0x308)
public:
	uint64_t m_securityStationId;
	uint64_t m_locationOverride;

	ArkSecurityStationScreen();
	virtual ~ArkSecurityStationScreen();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual void FullSerialize(TSerialize _ser);
	virtual void OnSelectPersonnel(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	virtual EArkInteractiveScreenType GetInteractiveScreenType() const;
	void OverrideLocation(const uint64_t _locationId) { FOverrideLocation(this, _locationId); }
	virtual void RefreshChildDefinedUI(bool _bAnimateIn);
	virtual void LoadProperties();
	virtual void RefreshRootMenu();
	virtual EArkStationType GetStationType() const;
	virtual const char* GetStationTitle() const;
	virtual const char* GetUtilitiesTitle() const;
	virtual void RefreshChildDefinedDetailUI();
	void ShowRosterDetails(const std::vector<uint64_t>& _personnel) { FShowRosterDetails(this, _personnel); }
	virtual bool CanEnterState(EArkStationWorldUIState _state) const;
	virtual void OnCharacterStatusChanged(const uint64_t _characterId);
	virtual void OnCharacterDiscovered(const uint64_t _characterId, bool _bDiscovered);
	virtual void OnTaskActivated(uint64_t _taskId);
	virtual void OnTaskDeactivated(uint64_t _taskId);
	virtual void OnTaskCompleted(uint64_t _taskId);
	virtual void OnTaskFailed(uint64_t _taskId);
	void OnTaskUpdated(uint64_t _taskId) { FOnTaskUpdated(this, _taskId); }
	virtual const std::vector<uint64_t>& GetEmails() const;
	virtual const std::vector<std::shared_ptr<ArkUtility>>& GetUtilities() const;
	virtual const ArkUtility* FindUtility(const uint64_t _id) const;
	virtual const ArkUtilityButton* FindUtilityButton(const uint64_t _id) const;
	virtual uint64_t GetUtilityButtonOwner(const uint64_t _id) const;
	const std::vector<uint64_t>& GetPersonnel(const uint64_t _locationId) const { return FGetPersonnel(this, _locationId); }
	std::pair<int, int> CountPersonnel(const std::vector<uint64_t>& _characterIds) const { alignas(std::pair<int, int>) std::byte _return_buf_[sizeof(std::pair<int, int>)]; return *FCountPersonnel(this, reinterpret_cast<std::pair<int, int>*>(_return_buf_), _characterIds); }
	void UpdateUIForCharacter(const ArkCharacter* _pCharacter, const char* _functionName) const { FUpdateUIForCharacter(this, _pCharacter, _functionName); }

#if 0
	const char* GetPersonnelTitle() const;
	uint64_t GetLocation(const ArkSecurityStation* _arg0_) const;
#endif

	static inline auto FArkSecurityStationScreenOv1 = PreyFunction<void(ArkSecurityStationScreen* const _this)>(0x14AE940);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkSecurityStationScreen* const _this, ICrySizer* _s)>(0x14AF2C0);
	static inline auto FFullSerialize = PreyFunction<void(ArkSecurityStationScreen* const _this, TSerialize _ser)>(0x14AF170);
	static inline auto FOnSelectPersonnel = PreyFunction<void(ArkSecurityStationScreen* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14AF680);
	static inline auto FGetInteractiveScreenType = PreyFunction<EArkInteractiveScreenType(const ArkSecurityStationScreen* const _this)>(0x141A3D0);
	static inline auto FOverrideLocation = PreyFunction<void(ArkSecurityStationScreen* const _this, const uint64_t _locationId)>(0x14AF980);
	static inline auto FRefreshChildDefinedUI = PreyFunction<void(ArkSecurityStationScreen* const _this, bool _bAnimateIn)>(0x14AF9E0);
	static inline auto FLoadProperties = PreyFunction<void(ArkSecurityStationScreen* const _this)>(0x14AF400);
	static inline auto FRefreshRootMenu = PreyFunction<void(ArkSecurityStationScreen* const _this)>(0x14AFB90);
	static inline auto FGetStationType = PreyFunction<EArkStationType(const ArkSecurityStationScreen* const _this)>(0x1948930);
	static inline auto FGetStationTitle = PreyFunction<const char* (const ArkSecurityStationScreen* const _this)>(0x14AF370);
	static inline auto FGetUtilitiesTitle = PreyFunction<const char* (const ArkSecurityStationScreen* const _this)>(0x14AF3C0);
	static inline auto FRefreshChildDefinedDetailUI = PreyFunction<void(ArkSecurityStationScreen* const _this)>(0x14AF9A0);
	static inline auto FShowRosterDetails = PreyFunction<void(ArkSecurityStationScreen* const _this, const std::vector<uint64_t>& _personnel)>(0x14AFD70);
	static inline auto FCanEnterState = PreyFunction<bool(const ArkSecurityStationScreen* const _this, EArkStationWorldUIState _state)>(0x14AEF60);
	static inline auto FOnCharacterStatusChanged = PreyFunction<void(IArkCharacterStatusListener* const _this, const uint64_t _characterId)>(0x14AF600);
	static inline auto FOnCharacterDiscovered = PreyFunction<void(IArkCharacterStatusListener* const _this, const uint64_t _characterId, bool _bDiscovered)>(0x14BE950);
	static inline auto FOnTaskActivated = PreyFunction<void(IArkObjectiveStateListener* const _this, uint64_t _taskId)>(0x14AF7C0);
	static inline auto FOnTaskDeactivated = PreyFunction<void(IArkObjectiveStateListener* const _this, uint64_t _taskId)>(0x14AF7C0);
	static inline auto FOnTaskCompleted = PreyFunction<void(IArkObjectiveStateListener* const _this, uint64_t _taskId)>(0x14AF7C0);
	static inline auto FOnTaskFailed = PreyFunction<void(IArkObjectiveStateListener* const _this, uint64_t _taskId)>(0x14AF7C0);
	static inline auto FOnTaskUpdated = PreyFunction<void(ArkSecurityStationScreen* const _this, uint64_t _taskId)>(0x14AF7D0);
	static inline auto FGetEmails = PreyFunction<const std::vector<uint64_t>& (const ArkSecurityStationScreen* const _this)>(0x14AF270);
	static inline auto FGetUtilities = PreyFunction<const std::vector<std::shared_ptr<ArkUtility>>& (const ArkSecurityStationScreen* const _this)>(0x14AF380);
	static inline auto FFindUtility = PreyFunction<const ArkUtility* (const ArkSecurityStationScreen* const _this, const uint64_t _id)>(0x14AF110);
	static inline auto FFindUtilityButton = PreyFunction<const ArkUtilityButton* (const ArkSecurityStationScreen* const _this, const uint64_t _id)>(0x14AF140);
	static inline auto FGetUtilityButtonOwner = PreyFunction<uint64_t(const ArkSecurityStationScreen* const _this, const uint64_t _id)>(0x14AF3D0);
	static inline auto FGetPersonnel = PreyFunction<const std::vector<uint64_t>& (const ArkSecurityStationScreen* const _this, const uint64_t _locationId)>(0x14AF2E0);
	static inline auto FCountPersonnel = PreyFunction<std::pair<int, int>*(const ArkSecurityStationScreen* const _this, std::pair<int, int>* _return_value_, const std::vector<uint64_t>& _characterIds)>(0x14AF050);
	static inline auto FUpdateUIForCharacter = PreyFunction<void(const ArkSecurityStationScreen* const _this, const ArkCharacter* _pCharacter, const char* _functionName)>(0x14AFFA0);
};
#endif // !MOONCRASH
