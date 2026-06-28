// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

struct IEntityArchetype;

// Header: Override
// Prey/GameDll/ark/iface/IEntityArchetypeListener.h
class IEntityArchetypeListener // Id=8002125 Size=8
{
public:
	virtual void OnArchetypeCreated(IEntityArchetype *arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IEntityArchetype;

// IEntityArchetypeListener
// Header:  Prey/GameDll/ark/iface/IEntityArchetypeListener.h
class IEntityArchetypeListener
{ // Size=8 (0x8)
public:
	virtual void OnArchetypeCreated(IEntityArchetype* _pArchetype) = 0;
};
#endif // !MOONCRASH
