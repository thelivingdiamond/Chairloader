// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Header: Override
// Prey/GameDll/ark/iface/IArkMetaTagManager.h
class IArkMetaTagManager // Id=80020BD Size=8
{
public:
	virtual bool DoesEntityHaveTag(IEntity const &arg0, const uint64_t &arg1) const = 0;
	virtual ~IArkMetaTagManager();
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IEntity;

// IArkMetaTagManager
// Header:  Prey/GameDll/ark/iface/IArkMetaTagManager.h
class IArkMetaTagManager
{ // Size=8 (0x8)
public:
	virtual bool DoesEntityHaveTag(const IEntity& _entity, const uint64_t& _tag) const = 0;
	virtual ~IArkMetaTagManager();

#if 0
	IArkMetaTagManager();
#endif
};
#endif // !MOONCRASH
