// Header file automatically created from a PDB.
#pragma once

struct IAnimSequence;
class ICrySizer;

// IMovieListener
// Header:  _unknown/IMovieListener.h
// Include: Prey/CryMovie/IMovieSystem.h
struct IMovieListener
{ // Size=8 (0x8)
	enum EMovieEvent
	{
		eMovieEvent_Started = 0,
		eMovieEvent_Stopped = 1,
		eMovieEvent_Aborted = 2,
		eMovieEvent_Updated = 3,
	};

	virtual ~IMovieListener();
	virtual void OnMovieEvent(IMovieListener::EMovieEvent event, IAnimSequence* pSequence) = 0;

#if 0
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif
};

