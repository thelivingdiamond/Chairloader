// Header file automatically created from a PDB.
#pragma once

class ArkNpcBodyState_Animated;

// ArkNpcBodyStateObserver_Animated
// Header:  _unknown/ArkNpcBodyStateObserver_Animated.h
class ArkNpcBodyStateObserver_Animated
{ // Size=8 (0x8)
public:
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);

#if 0
	ArkNpcBodyStateObserver_Animated();
	~ArkNpcBodyStateObserver_Animated();
#endif

#ifndef MOONCRASH
	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0xA13080);
#else
	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1333E90);
#endif
};

