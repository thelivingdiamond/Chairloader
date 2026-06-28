// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
//#include <Prey/CryAISystem/MovementStyle.h>
#include <Chairloader/PreyFunction.h>
#include <Prey/ArkCommon/ArkDelegate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireBase.h>
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/MovementStyle.h>
#include <_unknown/ArkDelegate.h>
#include <_unknown/ArkNpcDesireBase.h>

enum class EArkNpcSpeedDesirePriority;

// ArkNpcSpeedDesire
// Header:  Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h
class ArkNpcSpeedDesire : public ArkNpcDesireBase<ArkNpcSpeedDesireManager,ArkNpcSpeedDesire,enum EArkNpcSpeedDesirePriority>
{ // Size=88 (0x58)
public:
	// ArkNpcSpeedDesire::SpeedParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h
	class SpeedParam
	{ // Size=4 (0x4)
	public:
		const EArkNpcSpeedType m_speed;

		SpeedParam(EArkNpcSpeedType _speed);
		SpeedParam(MovementStyle::Speed _moveSpeed);
		bool Set(ArkNpcSpeedDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FSpeedParamOv1 = PreyFunction<void(ArkNpcSpeedDesire::SpeedParam* const _this, EArkNpcSpeedType _speed)>(0x156BBD0);
		static inline auto FSpeedParamOv0 = PreyFunction<void(ArkNpcSpeedDesire::SpeedParam* const _this, MovementStyle::Speed _moveSpeed)>(0x12A24B0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcSpeedDesire::SpeedParam* const _this, ArkNpcSpeedDesire& _desire)>(0x12A2500);
	};

	// ArkNpcSpeedDesire::TurnSpeedLiteralParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h
	class TurnSpeedLiteralParam
	{ // Size=4 (0x4)
	public:
		float m_radiansPerSecond;

		TurnSpeedLiteralParam(float _radiansPerSecond);
		bool Set(ArkNpcSpeedDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FTurnSpeedLiteralParam = PreyFunction<void(ArkNpcSpeedDesire::TurnSpeedLiteralParam* const _this, float _radiansPerSecond)>(0x1646AB0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcSpeedDesire::TurnSpeedLiteralParam* const _this, ArkNpcSpeedDesire& _desire)>(0x12A2510);
	};

	using Callback = ArkDelegate<void __cdecl(enum EArkNpcSpeedDesireCallbackEvent)>;

	EArkNpcSpeedType m_speed;
	float m_turnSpeedLiteral;
	ArkDelegate<void __cdecl(enum EArkNpcSpeedDesireCallbackEvent)> m_callback;

	ArkNpcSpeedDesire(EArkNpcSpeedDesirePriority _priority, const char* _dbgSource);
	static MovementStyle::Speed GetMovementSpeed(EArkNpcSpeedType _speed) { return FGetMovementSpeed(_speed); }

#if 0
	void SetCallback(ArkDelegate<void __cdecl(enum EArkNpcSpeedDesireCallbackEvent)> _arg0_);
	void ClearCallback();
	static ArkNpcSpeedDesire::SpeedParam Normal();
	static ArkNpcSpeedDesire::SpeedParam Fast();
	static ArkNpcSpeedDesire::SpeedParam Fastest();
	static EArkNpcSpeedType GetSpeed(MovementStyle::Speed _arg0_);
#endif

	static inline auto FArkNpcSpeedDesireOv1 = PreyFunction<void(ArkNpcSpeedDesire* const _this, EArkNpcSpeedDesirePriority _priority, const char* _dbgSource)>(0x12A2470);
	static inline auto FGetMovementSpeed = PreyFunction<MovementStyle::Speed(EArkNpcSpeedType _speed)>(0x12A24E0);
};
#endif // !MOONCRASH
