// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IConsole;

// SGameReleaseConstantCVars
// Header:  Prey/GameDll/gameconstantcvars.h
struct SGameReleaseConstantCVars
{ // Size=1 (0x1)
	static inline auto m_pThis = PreyGlobal<SGameReleaseConstantCVars*>(0x2D83478);

	SGameReleaseConstantCVars();
	void Init(IConsole* pConsole) { FInit(this, pConsole); }

#if 0
	static const SGameReleaseConstantCVars& Get();
#endif

	static inline auto FSGameReleaseConstantCVars = PreyFunction<void(SGameReleaseConstantCVars* const _this)>(0x180C4C0);
	static inline auto FInit = PreyFunction<void(SGameReleaseConstantCVars* const _this, IConsole* pConsole)>(0x1333E90);
};
#endif // MOONCRASH
