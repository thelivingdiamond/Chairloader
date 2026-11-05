// Header file automatically created from a PDB.
// Moved here from GameDll/ark/dialog/ArkConversation.h: this is the path the game headers use.

#pragma once
#include <Chairloader/PreyFunction.h>

class IArkActiveUserManagerListener;

// Header: Exact
// Prey/GameDll/ark/dialog/arkconversation.h
class ArkActiveUserManagerBase // Id=8013CC6 Size=40
{
public:
	enum class EArkReason
	{
		userSignOut = 0,
		controllerUserInvalid = 1,
		controllerDisconnect = 2,
	};

	std::vector<IArkActiveUserManagerListener *> m_listeners;
	bool m_bListening;
	bool m_bReengagementPhase;
	bool m_bDisconnectQueued;
	
	ArkActiveUserManagerBase();
	virtual void RegisterActiveUser(unsigned platformUserId);
	virtual void ClearActiveUser();
	virtual bool IsActiveUserLoggedIn() const;
	virtual void EnsureActiveUserValid(const uint64_t exclusiveDeviceId);
	void AddListener(IArkActiveUserManagerListener *_pListener) { FAddListener(this,_pListener); }
	void RemoveListener(IArkActiveUserManagerListener const *_pListener) { FRemoveListener(this,_pListener); }
	void SetListening(bool _bListening) { FSetListening(this,_bListening); }
	virtual void OnUserSignOutStarted(const unsigned _userId);
	virtual void OnUserSignOutCompleted(const unsigned _userId);
	virtual void OnActiveUserControllerRemoved(const unsigned _userId);
	virtual void OnActiveUserControllerInvalid(const unsigned _userId);
	
#if 0
	bool IsReengaging() const;
	void SetDisconnecting(bool arg0);
	void SetReengaging(bool arg0);
	std::vector<IArkActiveUserManagerListener *> const &GetListeners();
	bool IsListening() const;
	static void NotifyLauncherMenuActiveUserRemoved(ArkActiveUserManagerBase::EArkReason arg0);
	static bool PlayerExists();
	static void NotifyModalDialogDisconnect(bool arg0);
#endif
	
#ifndef MOONCRASH
	static inline auto FRegisterActiveUser = PreyFunction<void(ArkActiveUserManagerBase *const _this, unsigned platformUserId)>(0xA13080);
	static inline auto FClearActiveUser = PreyFunction<void(ArkActiveUserManagerBase *const _this)>(0xA13080);
	static inline auto FIsActiveUserLoggedIn = PreyFunction<bool(ArkActiveUserManagerBase const *const _this)>(0x1B933B0);
	static inline auto FEnsureActiveUserValid = PreyFunction<void(ArkActiveUserManagerBase *const _this, const uint64_t exclusiveDeviceId)>(0xA13080);
	static inline auto FAddListener = PreyFunction<void(ArkActiveUserManagerBase *const _this, IArkActiveUserManagerListener *_pListener)>(0x12F7620);
	static inline auto FRemoveListener = PreyFunction<void(ArkActiveUserManagerBase *const _this, IArkActiveUserManagerListener const *_pListener)>(0x1484970);
	static inline auto FSetListening = PreyFunction<void(ArkActiveUserManagerBase *const _this, bool _bListening)>(0x12F7670);
	static inline auto FOnUserSignOutStarted = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0xA13080);
	static inline auto FOnUserSignOutCompleted = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0xA13080);
	static inline auto FOnActiveUserControllerRemoved = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0xA13080);
	static inline auto FOnActiveUserControllerInvalid = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0xA13080);
#else
	static inline auto FRegisterActiveUser = PreyFunction<void(ArkActiveUserManagerBase *const _this, unsigned platformUserId)>(0x1333E90);
	static inline auto FClearActiveUser = PreyFunction<void(ArkActiveUserManagerBase *const _this)>(0x1333E90);
	static inline auto FIsActiveUserLoggedIn = PreyFunction<bool(ArkActiveUserManagerBase const *const _this)>(0x1A302A0);
	static inline auto FEnsureActiveUserValid = PreyFunction<void(ArkActiveUserManagerBase *const _this, const uint64_t exclusiveDeviceId)>(0x1333E90);
	static inline auto FAddListener = PreyFunction<void(ArkActiveUserManagerBase *const _this, IArkActiveUserManagerListener *_pListener)>(0x13D1C00);
	static inline auto FRemoveListener = PreyFunction<void(ArkActiveUserManagerBase *const _this, IArkActiveUserManagerListener const *_pListener)>(0x159C1E0);
	static inline auto FSetListening = PreyFunction<void(ArkActiveUserManagerBase *const _this, bool _bListening)>(0x13D1C50);
	static inline auto FOnUserSignOutStarted = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0x1333E90);
	static inline auto FOnUserSignOutCompleted = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0x1333E90);
	static inline auto FOnActiveUserControllerRemoved = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0x1333E90);
	static inline auto FOnActiveUserControllerInvalid = PreyFunction<void(ArkActiveUserManagerBase *const _this, const unsigned _userId)>(0x1333E90);
#endif
};
