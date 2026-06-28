// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireTarget.h>
#include <_unknown/ArkDelegate.h>
#include <_unknown/ArkNpcDesireBase.h>

enum class EArkNpcFacingDesirePriority;

// ArkNpcFacingDesire
// Header:  Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h
class ArkNpcFacingDesire : public ArkNpcDesireBase<ArkNpcFacingDesireManager,ArkNpcFacingDesire,enum EArkNpcFacingDesirePriority>
{ // Size=168 (0xA8)
public:
	enum class TurnState
	{
		None = 0,
		TurnLeft = 1,
		TurnRight = 2,
	};

	// ArkNpcFacingDesire::TargetParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h
	class TargetParam
	{ // Size=8 (0x8)
	public:
		const ArkNpcDesireTarget& m_target;

		TargetParam(const ArkNpcDesireTarget& _target);
		bool Set(ArkNpcFacingDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FTargetParam = PreyFunction<void(ArkNpcFacingDesire::TargetParam* const _this, const ArkNpcDesireTarget& _target)>(0x14124F0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcFacingDesire::TargetParam* const _this, ArkNpcFacingDesire& _desire)>(0x16457E0);
	};

	// ArkNpcFacingDesire::MaintainTurnAlignParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h
	class MaintainTurnAlignParam
	{ // Size=8 (0x8)
	public:
		const ArkNpcDesireTarget& m_target;

	#if 0
		MaintainTurnAlignParam(const ArkNpcDesireTarget& _arg0_);
		bool Set(ArkNpcFacingDesire& _arg0_) const;
	#endif
	};

	// ArkNpcFacingDesire::MinSpeedParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h
	class MinSpeedParam
	{ // Size=4 (0x4)
	public:
		const EArkNpcSpeedType m_minSpeed;

		MinSpeedParam(EArkNpcSpeedType _minSpeed);
		bool Set(ArkNpcFacingDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FMinSpeedParam = PreyFunction<void(ArkNpcFacingDesire::MinSpeedParam* const _this, EArkNpcSpeedType _minSpeed)>(0x156BBD0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcFacingDesire::MinSpeedParam* const _this, ArkNpcFacingDesire& _desire)>(0x16457C0);
	};

	using Callback = ArkDelegate<void __cdecl(enum EArkNpcFacingDesireCallbackEvent)>;

	ArkNpcFacingDesire::TurnState m_turnState;
	ArkNpcDesireTarget m_target;
	ArkNpcDesireTarget m_turnAlignTarget;
	float m_resumeAngle;
	EArkNpcSpeedType m_minSpeed;
	ArkDelegate<void __cdecl(enum EArkNpcFacingDesireCallbackEvent)> m_callback;

	ArkNpcFacingDesire(EArkNpcFacingDesirePriority _priority, const char* _dbgSource);
	void SetCallback(ArkDelegate<void __cdecl(enum EArkNpcFacingDesireCallbackEvent)> _callback) { FSetCallback(this, _callback); }
	void SetResumeAngle(float _resumeAngle) { FSetResumeAngle(this, _resumeAngle); }

#if 0
	void ClearCallback();
#endif

	static inline auto FArkNpcFacingDesireOv1 = PreyFunction<void(ArkNpcFacingDesire* const _this, EArkNpcFacingDesirePriority _priority, const char* _dbgSource)>(0x1645690);
	static inline auto FSetCallback = PreyFunction<void(ArkNpcFacingDesire* const _this, ArkDelegate<void __cdecl(enum EArkNpcFacingDesireCallbackEvent)> _callback)>(0x1645840);
	static inline auto FSetResumeAngle = PreyFunction<void(ArkNpcFacingDesire* const _this, float _resumeAngle)>(0x1645860);
};
#endif // !MOONCRASH
