#pragma once
#include "Prey/CryCore/StdAfx.h"
#include "Prey/CryAction/IGameRulesSystem.h"



class SDeferredMfxExplosion
{
	unsigned int m_rayId;
	int m_mfxTargetSurfaceId;
	_smart_ptr<IPhysicalEntity> m_pMfxTargetPhysEnt;
	EDeferredMfxExplosionState m_state;
};
class SExplosionContainer
{
	ExplosionInfo m_explosionInfo;
	SDeferredMfxExplosion m_mfxInfo;
};