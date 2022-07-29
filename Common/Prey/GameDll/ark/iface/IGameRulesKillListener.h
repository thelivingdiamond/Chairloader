// Header file automatically created from a PDB.

#pragma once

struct HitInfo;

// Header: Override
// Prey/GameDll/ark/iface/IGameRulesKillListener.h
class IGameRulesKillListener // Id=8014702 Size=8
{
public:
	virtual ~IGameRulesKillListener();
	virtual void OnEntityKilledEarly(HitInfo const &arg0) = 0;
	virtual void OnEntityKilled(HitInfo const &arg0) = 0;
	virtual void OnEntityBroken(const unsigned arg0) = 0;
};

