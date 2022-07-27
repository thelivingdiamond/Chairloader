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

