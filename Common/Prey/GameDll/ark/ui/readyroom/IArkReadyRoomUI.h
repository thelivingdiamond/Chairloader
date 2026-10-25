#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CCryName;
enum class EArkCanAdvanceResult;

// IArkReadyRoomUI
// Header:  _unknown/IArkReadyRoomUI.h
class IArkReadyRoomUI
{ // Size=8 (0x8)
public:
	enum class EPurchaseState
	{
		header = -1,
		canPurchase = 0,
		cannotPurchase = 1,
		insufficientFunds = 2,
	};

	virtual ~IArkReadyRoomUI();
	virtual unsigned SetupInputPrompts(unsigned _startingIndex);
	virtual bool IsAvailable() const;
	virtual EArkCanAdvanceResult CanAdvance() const;
	virtual void Open() = 0;
	virtual bool ProcessInput(CCryName _actionId, int _activationMode, float _fValue);
	virtual void Close(bool _bImmediate, bool _bExitReadyRoom) = 0;
	virtual void Reset();
	virtual void Cleanup();
	virtual void OnLaunch();
	virtual const char* GetLabel() const;
	virtual void OnControlSchemeChanged() const;

	static inline auto FSetupInputPrompts = PreyFunction<unsigned(IArkReadyRoomUI* const _this, unsigned _startingIndex)>(0xAB5620);
	static inline auto FIsAvailable = PreyFunction<bool(const IArkReadyRoomUI* const _this)>(0x1A302A0);
	static inline auto FCanAdvance = PreyFunction<EArkCanAdvanceResult(const IArkReadyRoomUI* const _this)>(0x1CBB0B0);
	static inline auto FProcessInput = PreyFunction<bool(IArkReadyRoomUI* const _this, CCryName _actionId, int _activationMode, float _fValue)>(0x14624D0);
	static inline auto FReset = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x1333E90);
	static inline auto FCleanup = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x1333E90);
	static inline auto FOnLaunch = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x1333E90);
	static inline auto FGetLabel = PreyFunction<const char* (const IArkReadyRoomUI* const _this)>(0x1CBB0B0);
	static inline auto FOnControlSchemeChanged = PreyFunction<void(const IArkReadyRoomUI* const _this)>(0x1333E90);
};

#endif // MOONCRASH
