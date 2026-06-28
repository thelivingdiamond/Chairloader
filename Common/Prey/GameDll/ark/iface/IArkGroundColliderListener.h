// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Header: Override
// Prey/GameDll/ark/iface/IArkGroundColliderListener.h
class IArkGroundColliderListener // Id=801560D Size=8
{
public:
	virtual void OnGroundEntityChanged(IEntity const *arg0, IEntity const *arg1, IEntity const *arg2) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IEntity;

// IArkGroundColliderListener
// Header:  Prey/GameDll/ark/iface/IArkGroundColliderListener.h
class IArkGroundColliderListener
{ // Size=8 (0x8)
public:
	virtual void OnGroundEntityChanged(const IEntity* _pOwner, const IEntity* _pOldEntity, const IEntity* _pNewEntity) = 0;
};
#endif // !MOONCRASH
