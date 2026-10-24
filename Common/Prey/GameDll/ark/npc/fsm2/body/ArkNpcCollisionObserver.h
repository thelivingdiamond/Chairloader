// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/arkintrusivelist.h>

class ArkNpc;
struct EventPhysCollision;

// ArkNpcCollisionObserver
// Header:  _unknown/ArkNpcCollisionObserver.h
class ArkNpcCollisionObserver : public ArkIntrusiveListElement<ArkNpcCollisionObserver>
{ // Size=32 (0x20)
public:
	virtual void OnNpcCollision(ArkNpc& _npc, const EventPhysCollision& _collisionEvent) = 0;

#if 0
	ArkNpcCollisionObserver();
	~ArkNpcCollisionObserver();
#endif
};

