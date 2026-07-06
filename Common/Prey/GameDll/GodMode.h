// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CCryActor;
enum EGodModeState;
struct IConsole;

// CGodMode
// Header:  Prey/GameDll/GodMode.h
class CGodMode
{ // Size=60 (0x3C)
public:
	static inline auto m_godModeCVarName = PreyGlobal<const char*>(0x23F04F8);
	static inline auto m_demiGodRevivesAtCheckpointCVarName = PreyGlobal<const char*>(0x23F0500);
	int m_godMode;
	int m_demiGodRevivesAtCheckpoint;
	bool m_hasHitCheckpoint;
	Matrix34 m_lastCheckpointWorldTM;

	static CGodMode& GetInstance() { return FGetInstance(); }
	void RegisterConsoleVars(IConsole* pConsole) { FRegisterConsoleVars(this, pConsole); }
	void UnregisterConsoleVars(IConsole* pConsole) const { FUnregisterConsoleVars(this, pConsole); }
	EGodModeState GetCurrentState() const { return FGetCurrentState(this); }
	void DemiGodDeath() { FDemiGodDeath(this); }
	void ClearCheckpointData() { FClearCheckpointData(this); }
	void SetNewCheckpoint(const Matrix34& rWorldMat) { FSetNewCheckpoint(this, rWorldMat); }

#if 0
	void MoveToNextState();
	bool RespawnIfDead(CCryActor* _arg0_) const;
	const char* GetCurrentStateString() const;
	bool IsGod() const;
	bool IsDemiGod() const;
	bool IsGodModeActive() const;
	CGodMode();
	CGodMode(const CGodMode& _arg0_);
	CGodMode& operator=(const CGodMode& _arg0_);
#endif

	static inline auto FGetInstance = PreyFunction<CGodMode& ()>(0x1862C30);
	static inline auto FRegisterConsoleVars = PreyFunction<void(CGodMode* const _this, IConsole* pConsole)>(0x1862C40);
	static inline auto FUnregisterConsoleVars = PreyFunction<void(const CGodMode* const _this, IConsole* pConsole)>(0x1862D30);
	static inline auto FGetCurrentState = PreyFunction<EGodModeState(const CGodMode* const _this)>(0x12A08E0);
	static inline auto FDemiGodDeath = PreyFunction<void(CGodMode* const _this)>(0x1862BA0);
	static inline auto FClearCheckpointData = PreyFunction<void(CGodMode* const _this)>(0x1862B70);
	static inline auto FSetNewCheckpoint = PreyFunction<void(CGodMode* const _this, const Matrix34& rWorldMat)>(0x1862CE0);
};
#endif // MOONCRASH
