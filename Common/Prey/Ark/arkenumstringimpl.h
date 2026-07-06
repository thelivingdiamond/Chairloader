// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/Ark/arkenumstringimpl.h
class ArkComparison // Id=8013B85 Size=1
{
public:
	static EArkComparisonType GetEnumFromString(const char *_string) { return FGetEnumFromString(_string); }
	
#if 0
	static const char *GetStringFromEnum(EArkComparisonType arg0);
#endif
	
	static inline auto FGetEnumFromString = PreyFunction<EArkComparisonType(const char *_string)>(0x1064AA0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

enum class EArkComparisonType;

// ArkComparison
// Header:  Prey/Ark/arkenumstringimpl.h
class ArkComparison
{ // Size=1 (0x1)
public:
	static EArkComparisonType GetEnumFromString(const char* _string) { return FGetEnumFromString(_string); }

#if 0
	static const char* GetStringFromEnum(EArkComparisonType _arg0_);
#endif

	static inline auto FGetEnumFromString = PreyFunction<EArkComparisonType(const char* _string)>(0x10879E0);
};
#endif // !MOONCRASH
