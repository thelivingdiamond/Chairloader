// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Prey/ArkCommon/reflection/IArkValueBase.h
class IArkValueBase // Id=800201E Size=8
{
public:
	virtual void Set(IArkValueBase const *arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkValueBase
// Header:  Prey/ArkCommon/reflection/IArkValueBase.h
class IArkValueBase
{ // Size=8 (0x8)
public:
	virtual void Set(const IArkValueBase* _v) = 0;
};
#endif // !MOONCRASH
