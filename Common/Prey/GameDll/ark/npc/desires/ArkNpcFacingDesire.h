// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>
#include <Prey/ArkCommon/ArkDelegate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireTarget.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireBase.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesireManager.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
//#include "Prey/ArkEnums.h"

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h
class ArkNpcFacingDesire : public ArkNpcDesireBase<ArkNpcFacingDesireManager,ArkNpcFacingDesire,enum EArkNpcFacingDesirePriority> // Id=80140FB Size=168
{
public:
	using Callback = ArkDelegate<void __cdecl(enum EArkNpcFacingDesireCallbackEvent)>;
	
	class TargetParam // Id=8014100 Size=8
	{
	public:
		ArkNpcDesireTarget const &m_target;
		
		TargetParam(ArkNpcDesireTarget const &_target);
		bool Set(ArkNpcFacingDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcFacingDesire::TargetParam const *const _this, ArkNpcFacingDesire &_desire)>(0x1525E50);
	};

	class MaintainTurnAlignParam // Id=8014101 Size=8
	{
	public:
		ArkNpcDesireTarget const &m_target;
		
#if 0
		bool Set(ArkNpcFacingDesire &arg0) const;
#endif
	};

	class MinSpeedParam // Id=8014102 Size=4
	{
	public:
		EArkNpcSpeedType m_minSpeed;
		
		MinSpeedParam(EArkNpcSpeedType _minSpeed);
		bool Set(ArkNpcFacingDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcFacingDesire::MinSpeedParam const *const _this, ArkNpcFacingDesire &_desire)>(0x1525E30);
	};

	enum class TurnState
	{
		None = 0,
		TurnLeft = 1,
		TurnRight = 2,
	};

	ArkNpcFacingDesire::TurnState m_turnState;
	ArkNpcDesireTarget m_target;
	ArkNpcDesireTarget m_turnAlignTarget;
	float m_resumeAngle;
	EArkNpcSpeedType m_minSpeed;
	ArkDelegate<void __cdecl(enum EArkNpcFacingDesireCallbackEvent)> m_callback;
	
	ArkNpcFacingDesire(EArkNpcFacingDesirePriority _priority, const char *_dbgSource);
	void SetCallback(ArkDelegate<void __cdecl(enum EArkNpcFacingDesireCallbackEvent)> _callback) { FSetCallback(this,_callback); }
	void SetResumeAngle(float _resumeAngle) { FSetResumeAngle(this,_resumeAngle); }
	
#if 0
	void ClearCallback();
#endif
	
	static inline auto FSetCallback = PreyFunction<void(ArkNpcFacingDesire *const _this, ArkDelegate<void __cdecl(enum EArkNpcFacingDesireCallbackEvent)> _callback)>(0x1525EB0);
	static inline auto FSetResumeAngle = PreyFunction<void(ArkNpcFacingDesire *const _this, float _resumeAngle)>(0x1525ED0);
};

