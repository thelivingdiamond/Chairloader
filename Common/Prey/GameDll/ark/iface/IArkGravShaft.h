// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
//#include <Prey/CryAISystem/INavigationSystem.h>

// Header: Override
// Prey/GameDll/ark/iface/IArkGravShaft.h
class IArkGravShaft // Id=80020BC Size=8
{
public:
	enum class EntityState
	{
		None = 0,
		Traveling = 1,
		Exiting = 2,
		Bouncing = 3,
	};

	virtual bool IsActive() const = 0;
	virtual float GetTravelDirection() const = 0;
	virtual Vec3 GetEnterDirection() const = 0;
	virtual Vec3 GetExitDirection() const = 0;
	virtual IArkGravShaft::EntityState GetEntityState(unsigned arg0) const = 0;
	virtual bool WaitToEnter(unsigned arg0) const = 0;
	virtual void SetWaiting(unsigned arg0, bool arg1) = 0;
	virtual bool GetLinkPositionEnter(TNavigationID<ENavigationIDTag::AgentTypeIDTag> arg0, Vec3 &arg1) const = 0;
	virtual bool GetLinkPositionExit(TNavigationID<ENavigationIDTag::AgentTypeIDTag> arg0, Vec3 &arg1) const = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/TNavigationID.h>

// IArkGravShaft
// Header:  Prey/GameDll/ark/iface/IArkGravShaft.h
class IArkGravShaft
{ // Size=8 (0x8)
public:
	enum class EntityState
	{
		None = 0,
		Traveling = 1,
		Exiting = 2,
		Bouncing = 3,
	};

	virtual bool IsActive() const = 0;
	virtual float GetTravelDirection() const = 0;
	virtual Vec3 GetEnterDirection() const = 0;
	virtual Vec3 GetExitDirection() const = 0;
	virtual IArkGravShaft::EntityState GetEntityState(unsigned _id) const = 0;
	virtual bool WaitToEnter(unsigned _id) const = 0;
	virtual void SetWaiting(unsigned _id, bool _bWaiting) = 0;
	virtual bool GetLinkPositionEnter(TNavigationID<1> _navAgentTypeId, Vec3& _enterPos) const = 0;
	virtual bool GetLinkPositionExit(TNavigationID<1> _navAgentTypeId, Vec3& _exitPos) const = 0;
};
#endif // !MOONCRASH
