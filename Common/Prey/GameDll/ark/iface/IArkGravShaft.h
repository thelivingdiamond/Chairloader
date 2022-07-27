// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/INavigationSystem.h>

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
	virtual bool GetLinkPositionEnter(TNavigationID<1> arg0, Vec3 &arg1) const = 0;
	virtual bool GetLinkPositionExit(TNavigationID<1> arg0, Vec3 &arg1) const = 0;
};

