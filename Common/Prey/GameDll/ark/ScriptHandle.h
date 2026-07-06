// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ScriptHandle
// Header:  Prey/GameDll/ark/ScriptHandle.h
union ScriptHandle
{ // Size=8 (0x8)
	uint64_t n;
	void* ptr;

#if 0
	ScriptHandle();
	ScriptHandle(int _arg0_);
	ScriptHandle(void* _arg0_);
#endif
};
#endif // MOONCRASH
