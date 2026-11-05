// Header file automatically created from a PDB.
#pragma once

class ArkNpcBodyState_Dissipate;

// ArkNpcBodyStateObserver_Dissipate
// Header:  _unknown/ArkNpcBodyStateObserver_Dissipate.h
class ArkNpcBodyStateObserver_Dissipate
{ // Size=8 (0x8)
public:
#ifndef MOONCRASH
	virtual void OnNpcBodyStateStateExit_Dissipate(const ArkNpcBodyState_Dissipate& _state);
#else
	virtual void OnNpcBodyStateStateExit_Dissipate(const ArkNpcBodyState_Dissipate& _state) = 0;
#endif

#if 0
	ArkNpcBodyStateObserver_Dissipate();
	~ArkNpcBodyStateObserver_Dissipate();
#endif

#ifndef MOONCRASH
	static inline auto FOnNpcBodyStateStateExit_Dissipate = PreyFunction<void(ArkNpcBodyStateObserver_Dissipate* const _this, const ArkNpcBodyState_Dissipate& _state)>(0xA13080);
#endif
};

