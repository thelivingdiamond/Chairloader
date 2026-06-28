// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct HitInfo;

// IGameRulesKillListener
// Header:  Prey/GameDll/ark/iface/IGameRulesKillListener.h
class IGameRulesKillListener
{ // Size=8 (0x8)
public:
	virtual ~IGameRulesKillListener();
	virtual void OnEntityKilledEarly(const HitInfo& _hitInfo) = 0;
	virtual void OnEntityKilled(const HitInfo& _hitInfo) = 0;
	virtual void OnEntityBroken(const unsigned _brokenEntityId) = 0;
};
#endif // !MOONCRASH
