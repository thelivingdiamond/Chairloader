// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
//#include <Prey/CryAISystem/MovementStyle.h>
#include <ChairLoader/PreyFunction.h>
#include <Prey/ArkCommon/ArkDelegate.h>
#include <Prey/GameDll/Ark/npc/desires/ArkNpcDesireBase.h>
#include "ArkNpcSpeedDesireManager.h"

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h
class ArkNpcSpeedDesire : public ArkNpcDesireBase<ArkNpcSpeedDesireManager,ArkNpcSpeedDesire,enum EArkNpcSpeedDesirePriority> // Id=8014134 Size=88
{
public:
	using Callback = ArkDelegate<void __cdecl(enum EArkNpcSpeedDesireCallbackEvent)>;
	
	class SpeedParam // Id=8014139 Size=4
	{
	public:
		EArkNpcSpeedType m_speed;
		
//		SpeedParam(EArkNpcSpeedType _speed);
//		SpeedParam(MovementStyle::Speed _moveSpeed);
		bool Set(ArkNpcSpeedDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcSpeedDesire::SpeedParam const *const _this, ArkNpcSpeedDesire &_desire)>(0x1213020);
	};

	class TurnSpeedLiteralParam // Id=801413A Size=4
	{
	public:
		float m_radiansPerSecond;
		
		TurnSpeedLiteralParam(float _radiansPerSecond);
		bool Set(ArkNpcSpeedDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcSpeedDesire::TurnSpeedLiteralParam const *const _this, ArkNpcSpeedDesire &_desire)>(0x1213030);
	};

	EArkNpcSpeedType m_speed;
	float m_turnSpeedLiteral;
	ArkDelegate<void __cdecl(enum EArkNpcSpeedDesireCallbackEvent)> m_callback;
	
	ArkNpcSpeedDesire(EArkNpcSpeedDesirePriority _priority, const char *_dbgSource);
//	static MovementStyle::Speed GetMovementSpeed(EArkNpcSpeedType _speed) { return FGetMovementSpeed(_speed); }
	
#if 0
	void SetCallback(ArkDelegate<void __cdecl(enum EArkNpcSpeedDesireCallbackEvent)> arg0);
	void ClearCallback();
	static ArkNpcSpeedDesire::SpeedParam Normal();
	static ArkNpcSpeedDesire::SpeedParam Fast();
	static ArkNpcSpeedDesire::SpeedParam Fastest();
	static EArkNpcSpeedType GetSpeed(MovementStyle::Speed arg0);
#endif
	
//	static inline auto FGetMovementSpeed = PreyFunction<MovementStyle::Speed(EArkNpcSpeedType _speed)>(0x1213000);
};

