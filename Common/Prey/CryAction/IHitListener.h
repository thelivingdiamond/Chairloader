// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameRulesSystem.h>

struct ExplosionInfo;
struct HitInfo;

// Header: MadeUp
// _unknown/IHitListener.h
struct IHitListener // Id=8001FA4 Size=8
{
	virtual ~IHitListener();
	virtual void OnHit(HitInfo const &arg0) = 0;
	virtual void OnExplosion(ExplosionInfo const &arg0) = 0;
	virtual void OnServerExplosion(ExplosionInfo const &arg0) = 0;
};

