// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMemory/StlDbgAlloc.h>

struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/ArkBlackListItem.h
struct ArkBlackListItem // Id=801AACC Size=16
{
	string m_className;
	string m_archetypeName;
	
	bool IsEqual(IEntity const &_entity) const { return FIsEqual(this,_entity); }
	
	static inline auto FIsEqual = PreyFunction<bool(ArkBlackListItem const *const _this, IEntity const &_entity)>(0x13CAE30);
};

