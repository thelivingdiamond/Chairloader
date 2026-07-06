// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

struct ArkGlintConfig;

// Header: Override
// Prey/GameDll/ark/iface/IArkGlintConfigManager.h
struct IArkGlintConfigManager // Id=80020BA Size=8
{
	virtual ArkGlintConfig const *ConfigFromId(uint64_t arg0) const = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct ArkGlintConfig;

// IArkGlintConfigManager
// Header:  Prey/GameDll/ark/iface/IArkGlintConfigManager.h
struct IArkGlintConfigManager
{ // Size=8 (0x8)
	virtual const ArkGlintConfig* ConfigFromId(uint64_t _id) const = 0;
};
#endif // !MOONCRASH
