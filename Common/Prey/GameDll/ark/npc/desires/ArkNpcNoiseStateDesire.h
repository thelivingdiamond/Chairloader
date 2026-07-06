// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireBase.h>
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkNpcDesireBase.h>

enum class EArkNpcNoiseStateDesirePriority;

// ArkNpcNoiseStateDesire
// Header:  Prey/GameDll/ark/npc/desires/ArkNpcNoiseStateDesire.h
class ArkNpcNoiseStateDesire : public ArkNpcDesireBase<ArkNpcNoiseStateDesireManager,ArkNpcNoiseStateDesire,enum EArkNpcNoiseStateDesirePriority>
{ // Size=72 (0x48)
public:
	// ArkNpcNoiseStateDesire::StateParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcNoiseStateDesire.h
	class StateParam
	{ // Size=4 (0x4)
	public:
		EArkNpcNoiseState m_noiseStateType;

		StateParam(EArkNpcNoiseState _noiseStateType);
		bool Set(ArkNpcNoiseStateDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FStateParam = PreyFunction<void(ArkNpcNoiseStateDesire::StateParam* const _this, EArkNpcNoiseState _noiseStateType)>(0x156BBD0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcNoiseStateDesire::StateParam* const _this, ArkNpcNoiseStateDesire& _desire)>(0x12A2500);
	};

	EArkNpcNoiseState m_noiseState;

	ArkNpcNoiseStateDesire(EArkNpcNoiseStateDesirePriority _priority, const char* _dbgSource);

	static inline auto FArkNpcNoiseStateDesireOv1 = PreyFunction<void(ArkNpcNoiseStateDesire* const _this, EArkNpcNoiseStateDesirePriority _priority, const char* _dbgSource)>(0x12A2380);
};
#endif // !MOONCRASH
