#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CCryName;

// IArkReadyRoomMetaUI
// Header:  _unknown/IArkReadyRoomMetaUI.h
class IArkReadyRoomMetaUI
{ // Size=8 (0x8)
public:
	virtual ~IArkReadyRoomMetaUI();
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void Reset();
	virtual bool ProcessInput(CCryName _actionId, int _activationMode, float _fValue);

	static inline auto FReset = PreyFunction<void(IArkReadyRoomMetaUI* const _this)>(0x1333E90);
	static inline auto FProcessInput = PreyFunction<bool(IArkReadyRoomMetaUI* const _this, CCryName _actionId, int _activationMode, float _fValue)>(0x14624D0);
};

#endif // MOONCRASH
