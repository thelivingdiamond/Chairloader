// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h
class IArkActiveUserManagerListener // Id=8013CB7 Size=8
{
public:
	virtual void OnActiveUserIdChanged(unsigned arg0) = 0;
	virtual void OnActiveUserDisconnected(bool arg0) = 0;
	virtual bool OnActiveUserReengaged();
	virtual void OnActiveUserPostReengaged();
	virtual void OnActiveUserSignedOut() = 0;
	
#ifndef MOONCRASH
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(IArkActiveUserManagerListener *const _this)>(0xDD23F0);
	static inline auto FOnActiveUserPostReengaged = PreyFunction<void(IArkActiveUserManagerListener *const _this)>(0xA13080);
#else
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(IArkActiveUserManagerListener* const _this)>(0x13B0900);
	static inline auto FOnActiveUserPostReengaged = PreyFunction<void(IArkActiveUserManagerListener* const _this)>(0x1333E90);
#endif
};
