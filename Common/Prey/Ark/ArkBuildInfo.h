// Header file automatically created from a PDB.

#pragma once

// Header: Exact
// Prey/Ark/ArkBuildInfo.h
class ArkBuildInfo // Id=800243A Size=144
{
public:
	bool m_isLocalBuild;
	std::map<string,string,std::less<string>,std::allocator<std::pair<CryStringT<char> const,string>>> m_buildInfo;
	string k_buildIDKey;
	string k_branchKey;
	string k_changeListKey;
	string m_Description;
	string m_FullInfo;
	std::mutex m_buildInfoMutex;
	
	ArkBuildInfo();
	string GetBuildInfo(string const &_key) const { return FGetBuildInfo(this,_key); }
	const void IterateBuildInfoEntries(std::function<void __cdecl(char const *,char const *)> OnEntry) const { FIterateBuildInfoEntries(this,OnEntry); }
	void AddRuntimeBuildInfo(const char *key, const char *value) { FAddRuntimeBuildInfo(this,key,value); }
	
#if 0
	const bool ValidateCurrentBranch() const;
	string GetChangelist() const;
	string GetBuildID() const;
	string GetArkClientBranch() const;
	string GetBranch() const;
	bool IsLocalBuild() const;
	int GetDanielleToolsVersion() const;
	string const &GetDescription() const;
	string const &GetFullInfo() const;
	const void DumpBuildInfoToFile(const char *arg0) const;
	string parseBranchFromFile();
#endif
	
	static inline auto FGetBuildInfo = PreyFunction<string(ArkBuildInfo const *const _this, string const &_key)>(0x4BF080);
	static inline auto FIterateBuildInfoEntries = PreyFunction<const void(ArkBuildInfo const *const _this, std::function<void __cdecl(char const *,char const *)> OnEntry)>(0x5C2DF0);
	static inline auto FAddRuntimeBuildInfo = PreyFunction<void(ArkBuildInfo *const _this, const char *key, const char *value)>(0xDCB310);
};

