// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <ChairLoader/PreyFunction.h>
#include <Prey/GameDll/Ark/npc/desires/ArkNpcDesireBase.h>
#include "ArkNpcNoiseStateDesireManager.h"

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/ArkNpcNoiseStateDesire.h
class ArkNpcNoiseStateDesire : public ArkNpcDesireBase<ArkNpcNoiseStateDesireManager,ArkNpcNoiseStateDesire,enum EArkNpcNoiseStateDesirePriority> // Id=8014148 Size=72
{
public:
	class StateParam // Id=801414C Size=4
	{
	public:
		EArkNpcNoiseState m_noiseStateType;
		
		StateParam(EArkNpcNoiseState _noiseStateType);
		bool Set(ArkNpcNoiseStateDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcNoiseStateDesire::StateParam const *const _this, ArkNpcNoiseStateDesire &_desire)>(0x1213020);
	};

	EArkNpcNoiseState m_noiseState;
	
	ArkNpcNoiseStateDesire(EArkNpcNoiseStateDesirePriority _priority, const char *_dbgSource);
};

