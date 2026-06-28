// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Exact
// Prey/ArkResponseKeyLibrary.h
class ArkResponseKeyLibrary // Id=8013685 Size=624
{
public:
	std::array<std::pair<unsigned __int64,string>,39> m_keynames;
	
	ArkResponseKeyLibrary();
	
#if 0
	uint64_t GetKey(EArkResponseKey arg0) const;
	string const &GetKeyName(EArkResponseKey arg0) const;
	std::array<std::pair<unsigned __int64,string>,39> const &GetKeyNames() const;
	const char *GetKeyNameFromID(const uint64_t arg0) const;
	uint64_t GetKeyIDFromName(string const &arg0) const;
	std::pair<enum EArkResponseKey,char const *> GetKeyAndNameFromID(const uint64_t arg0) const;
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

enum class EArkResponseKey;

// ArkResponseKeyLibrary
// Header:  Prey/Arkresponsekeylibrary.h
class ArkResponseKeyLibrary
{ // Size=656 (0x290)
public:
	std::array<std::pair<uint64_t, string>, 41> m_keynames;

	ArkResponseKeyLibrary();

#if 0
	uint64_t GetKey(const EArkResponseKey _arg0_) const;
	const string& GetKeyName(const EArkResponseKey _arg0_) const;
	const std::array<std::pair<uint64_t, string>, 41>& GetKeyNames() const;
	const char* GetKeyNameFromID(const uint64_t _arg0_) const;
	uint64_t GetKeyIDFromName(const string& _arg0_) const;
	std::pair<enum::EArkResponseKey, const char*> GetKeyAndNameFromID(const uint64_t _arg0_) const;
#endif

	static inline auto FArkResponseKeyLibraryOv2 = PreyFunction<void(ArkResponseKeyLibrary* const _this)>(0x15A90D0);
};
#endif // !MOONCRASH
