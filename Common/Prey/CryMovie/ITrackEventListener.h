// Header file automatically created from a PDB.
#pragma once

struct IAnimSequence;
class ICrySizer;

// ITrackEventListener
// Header:  _unknown/ITrackEventListener.h
// Include: Prey/CryMovie/IMovieSystem.h
struct ITrackEventListener
{ // Size=8 (0x8)
	enum ETrackEventReason
	{
		eTrackEventReason_Added = 0,
		eTrackEventReason_Removed = 1,
		eTrackEventReason_Renamed = 2,
		eTrackEventReason_Triggered = 3,
		eTrackEventReason_MovedUp = 4,
		eTrackEventReason_MovedDown = 5,
	};

	virtual ~ITrackEventListener();
	virtual void OnTrackEvent(IAnimSequence* pSequence, int reason, const char* event, void* pUserData) = 0;
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;

#ifndef MOONCRASH
	static inline auto FGetMemoryUsage = PreyFunction<void(const ITrackEventListener* const _this, ICrySizer* pSizer)>(0xA13080);
#else
	static inline auto FGetMemoryUsage = PreyFunction<void(const ITrackEventListener* const _this, ICrySizer* pSizer)>(0x1333E90);
#endif
};

