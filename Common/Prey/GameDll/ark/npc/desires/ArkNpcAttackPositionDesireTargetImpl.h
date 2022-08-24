// Header file automatically created from a PDB.

#pragma once
#include<Prey/CryCore/StdAfx.h>

struct IEntity;

// Header: MadeUp
// _unknown/ArkNpcAttackPositionDesireTargetImpl.h
class ArkNpcAttackPositionDesireTargetImpl // Id=80140BB Size=20
{
public:
	unsigned m_entityId;
	float m_tolerance;
	Vec3 m_position;
	
#if 0
	bool operator==(ArkNpcAttackPositionDesireTargetImpl const &arg0) const;
	bool IsValid() const;
	bool HasPosition() const;
	bool IsStatic() const;
	Vec3 GetPosition() const;
	bool HasDirection() const;
	Vec3 GetDirection() const;
	unsigned GetEntityId() const;
	float GetTolerance() const;
	void SetTolerance(float arg0);
	EArkNpcDesireTargetRefreshResult Refresh();
#endif
};

