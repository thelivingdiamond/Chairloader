#pragma once
#include "Prey/CryCore/StdAfx.h"

struct IArkPlayer
{
public:
	virtual std::pair<Vec3, Vec3> GetReticleViewPositionAndDir() = 0;
	virtual void EnableIdleBreak(const bool) = 0;
	virtual void InhibitRotation(const bool) = 0;
};