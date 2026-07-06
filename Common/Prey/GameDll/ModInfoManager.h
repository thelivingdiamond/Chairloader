// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ModInfo.h>

// CModInfoManager
// Header:  Prey/GameDll/ModInfoManager.h
class CModInfoManager
{ // Size=56 (0x38)
public:
	using Mods = std::vector<ModInfo>;

	std::vector<ModInfo> m_mods;
	std::vector<ModInfo> m_modLevels;
	unsigned m_modCheckSum;
	bool m_bRunningMod;

	CModInfoManager();
	void Refresh() { FRefresh(this); }
	const ModInfo* GetActiveMod() const { return FGetActiveMod(this); }
	static unsigned GetDirectoryHash(const char* pPath) { return FGetDirectoryHash(pPath); }

#if 0
	void Free();
	uint64_t GetModCount() const;
	const ModInfo* GetModByIndex(uint64_t _arg0_) const;
	const ModInfo* FindModByDisplayName(const char* _arg0_) const;
	uint64_t GetLevelCount() const;
	const ModInfo* GetLevelByIndex(uint64_t _arg0_) const;
	const char* GetActiveModName() const;
	const char* GetActiveModDisplayName() const;
	bool IsRunningMod() const;
	unsigned GetModCheckSum() const;
	bool LoadMod(const char* _arg0_);
	bool UnloadMod();
#endif

	static inline auto FCModInfoManagerOv2 = PreyFunction<void(CModInfoManager* const _this)>(0x18920F0);
	static inline auto FRefresh = PreyFunction<void(CModInfoManager* const _this)>(0x1893360);
	static inline auto FGetActiveMod = PreyFunction<const ModInfo* (const CModInfoManager* const _this)>(0x1892660);
	static inline auto FGetDirectoryHash = PreyFunction<unsigned(const char* pPath)>(0x1892770);
};
#endif // MOONCRASH
