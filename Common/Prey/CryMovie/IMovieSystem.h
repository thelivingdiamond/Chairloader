// Header file automatically created from a PDB.
#pragma once

struct IAnimSequence;
struct SCameraParams;

// IMovieUser
// Header:  _unknown/IMovieUser.h
// Include: Prey/CryMovie/IMovieSystem.h
struct IMovieUser
{ // Size=8 (0x8)
	virtual ~IMovieUser() {}
	virtual void SetActiveCamera(const SCameraParams& params) = 0;
	virtual void BeginCutScene(IAnimSequence* pSeq, unsigned long dwFlags, bool bResetFX) = 0;
	virtual void EndCutScene(IAnimSequence* pSeq, unsigned long dwFlags) = 0;
	virtual void SendGlobalEvent(const char* pszEvent) = 0;
};
