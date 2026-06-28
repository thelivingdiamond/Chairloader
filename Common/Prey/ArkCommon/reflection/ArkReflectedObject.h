// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include "ArkProperty.h"

class ArkClass;

// Header: Exact
// Prey/ArkCommon/reflection/ArkReflectedObject.h
class ArkReflectedObject // Id=800200D Size=1
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x2A07F0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x2A0B00);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkClass;

// ArkReflectedObject
// Header:  Prey/ArkCommon/reflection/ArkReflectedObject.h
class ArkReflectedObject
{ // Size=1 (0x1)
public:
	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x2B8CA0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x2B8FB0);
};
#endif // !MOONCRASH
