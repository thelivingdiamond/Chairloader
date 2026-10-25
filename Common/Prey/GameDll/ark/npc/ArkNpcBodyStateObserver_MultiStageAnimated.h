// Header file automatically created from a PDB.
#pragma once

class ArkNpcBodyState_MultiStageAnimated;

// ArkNpcBodyStateObserver_MultiStageAnimated
// Header:  _unknown/ArkNpcBodyStateObserver_MultiStageAnimated.h
class ArkNpcBodyStateObserver_MultiStageAnimated
{ // Size=8 (0x8)
public:
	virtual void OnNpcBodyStateStateExit_MultiStageAnimated(const ArkNpcBodyState_MultiStageAnimated& _state);

#if 0
	ArkNpcBodyStateObserver_MultiStageAnimated();
	~ArkNpcBodyStateObserver_MultiStageAnimated();
#endif

#ifndef MOONCRASH
	static inline auto FOnNpcBodyStateStateExit_MultiStageAnimated = PreyFunction<void(ArkNpcBodyStateObserver_MultiStageAnimated* const _this, const ArkNpcBodyState_MultiStageAnimated& _state)>(0xA13080);
#else
	static inline auto FOnNpcBodyStateStateExit_MultiStageAnimated = PreyFunction<void(ArkNpcBodyStateObserver_MultiStageAnimated* const _this, const ArkNpcBodyState_MultiStageAnimated& _state)>(0x1333E90);
#endif
};

