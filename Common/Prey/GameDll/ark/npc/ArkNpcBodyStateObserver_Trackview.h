// Header file automatically created from a PDB.
#pragma once

class ArkNpcBodyState_Trackview;

// ArkNpcBodyStateObserver_Trackview
// Header:  _unknown/ArkNpcBodyStateObserver_Trackview.h
class ArkNpcBodyStateObserver_Trackview
{ // Size=8 (0x8)
public:
	virtual void OnNpcBodyStateStateExit_Trackview(const ArkNpcBodyState_Trackview& _state);

#if 0
	ArkNpcBodyStateObserver_Trackview();
	~ArkNpcBodyStateObserver_Trackview();
#endif

#ifndef MOONCRASH
	static inline auto FOnNpcBodyStateStateExit_Trackview = PreyFunction<void(ArkNpcBodyStateObserver_Trackview* const _this, const ArkNpcBodyState_Trackview& _state)>(0xA13080);
#else
	static inline auto FOnNpcBodyStateStateExit_Trackview = PreyFunction<void(ArkNpcBodyStateObserver_Trackview* const _this, const ArkNpcBodyState_Trackview& _state)>(0x1333E90);
#endif
};

