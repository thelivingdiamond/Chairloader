// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class IArkActiveUserManagerListener;

// ArkActiveUserManagerBase
// Header:  Prey/GameDll/ark/ui/ArkActiveUserManagerBase.h
class ArkActiveUserManagerBase
{ // Size=40 (0x28)
public:
	enum class EArkReason
	{
		userSignOut = 0,
		controllerUserInvalid = 1,
		controllerDisconnect = 2,
	};

	std::vector<IArkActiveUserManagerListener*> m_listeners;
	bool m_bListening;
	bool m_bReengagementPhase;
	bool m_bDisconnectQueued;

	ArkActiveUserManagerBase();
	virtual void RegisterActiveUser(unsigned platformUserId);
	virtual void ClearActiveUser();
	virtual bool IsActiveUserLoggedIn() const;
	virtual void EnsureActiveUserValid(const uint64_t exclusiveDeviceId);
	void AddListener(IArkActiveUserManagerListener* _pListener) { FAddListener(this, _pListener); }
	void RemoveListener(const IArkActiveUserManagerListener* _pListener) { FRemoveListener(this, _pListener); }
	void SetListening(bool _bListening) { FSetListening(this, _bListening); }
	virtual void OnUserSignOutStarted(const unsigned _userId);
	virtual void OnUserSignOutCompleted(const unsigned _userId);
	virtual void OnActiveUserControllerRemoved(const unsigned _userId);
	virtual void OnActiveUserControllerInvalid(const unsigned _userId);

#if 0
	bool IsReengaging() const;
	void SetDisconnecting(bool _arg0_);
	void SetReengaging(bool _arg0_);
	const std::vector<IArkActiveUserManagerListener*>& GetListeners();
	bool IsListening() const;
	bool ShouldUnpauseAfterReengagement() const;
	static void NotifyLauncherMenuActiveUserRemoved(ArkActiveUserManagerBase::EArkReason _arg0_);
	static bool PlayerExists();
	static void NotifyModalDialogDisconnect(bool _arg0_);
#endif

	static inline auto FArkActiveUserManagerBaseOv2 = PreyFunction<void(ArkActiveUserManagerBase* const _this)>(0x13D1BD0);
	static inline auto FRegisterActiveUser = PreyFunction<void(ArkActiveUserManagerBase* const _this, unsigned platformUserId)>(0x1333E90);
	static inline auto FClearActiveUser = PreyFunction<void(ArkActiveUserManagerBase* const _this)>(0x1333E90);
	static inline auto FIsActiveUserLoggedIn = PreyFunction<bool(const ArkActiveUserManagerBase* const _this)>(0x1A302A0);
	static inline auto FEnsureActiveUserValid = PreyFunction<void(ArkActiveUserManagerBase* const _this, const uint64_t exclusiveDeviceId)>(0x1333E90);
	static inline auto FAddListener = PreyFunction<void(ArkActiveUserManagerBase* const _this, IArkActiveUserManagerListener* _pListener)>(0x13D1C00);
	static inline auto FRemoveListener = PreyFunction<void(ArkActiveUserManagerBase* const _this, const IArkActiveUserManagerListener* _pListener)>(0x159C1E0);
	static inline auto FSetListening = PreyFunction<void(ArkActiveUserManagerBase* const _this, bool _bListening)>(0x13D1C50);
	static inline auto FOnUserSignOutStarted = PreyFunction<void(ArkActiveUserManagerBase* const _this, const unsigned _userId)>(0x1333E90);
	static inline auto FOnUserSignOutCompleted = PreyFunction<void(ArkActiveUserManagerBase* const _this, const unsigned _userId)>(0x1333E90);
	static inline auto FOnActiveUserControllerRemoved = PreyFunction<void(ArkActiveUserManagerBase* const _this, const unsigned _userId)>(0x1333E90);
	static inline auto FOnActiveUserControllerInvalid = PreyFunction<void(ArkActiveUserManagerBase* const _this, const unsigned _userId)>(0x1333E90);
};
#endif // MOONCRASH
