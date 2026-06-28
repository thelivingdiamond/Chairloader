// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IEntity;

// ArkBlackListItem
// Header:  Prey/GameDll/ark/ArkBlackListItem.h
struct ArkBlackListItem
{ // Size=16 (0x10)
	string m_className;
	string m_archetypeName;

	bool IsEqual(const IEntity& _entity) const { return FIsEqual(this, _entity); }

	static inline auto FIsEqual = PreyFunction<bool(const ArkBlackListItem* const _this, const IEntity& _entity)>(0x14D6E60);
};
#endif // !MOONCRASH
