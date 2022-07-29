// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/turret/ATStates.h>

class ArkTurretFsm;

namespace ATStates
{

// Header: FromCpp
// Prey/GameDll/ark/turret/arkturretfsmstates.h
class Undeployed : public ATStates::BaseState // Id=80152AD Size=12
{
public:
	ArkSimpleTimer m_fallenToUprightDelayTimer;
	float m_activePhysicsTime;
	
	Undeployed();
	void Enter(ArkTurretFsm &_fsm) { FEnter(this,_fsm); }
	void Exit(ArkTurretFsm &_fsm) { FExit(this,_fsm); }
	void Update(ArkTurretFsm &_fsm, const float _frameTime) { FUpdate(this,_fsm,_frameTime); }
	void LoadData(ArkTurretFsm &_fsm) { FLoadData(this,_fsm); }
	
#if 0
	const char *GetStateName() const;
#endif
	
	static inline auto FEnter = PreyFunction<void(ATStates::Undeployed *const _this, ArkTurretFsm &_fsm)>(0x15E97B0);
	static inline auto FExit = PreyFunction<void(ATStates::Undeployed *const _this, ArkTurretFsm &_fsm)>(0x15E98E0);
	static inline auto FUpdate = PreyFunction<void(ATStates::Undeployed *const _this, ArkTurretFsm &_fsm, const float _frameTime)>(0x15EA860);
	static inline auto FLoadData = PreyFunction<void(ATStates::Undeployed *const _this, ArkTurretFsm &_fsm)>(0x15E9FD0);
};

} // namespace ATStates

namespace ATStates
{

// Header: FromCpp
// Prey/GameDll/ark/turret/arkturretfsmstates.h
class FallenSpazzing : public ATStates::BaseState // Id=80152AE Size=24
{
public:
	ArkSimpleTimer m_fallenToUprightDelayTimer;
	ArkSimpleTimer m_fallenSpazOutTimer;
	ArkSimpleTimer m_rotateRandomTimer;
	
	FallenSpazzing();
	void Enter(ArkTurretFsm &_fsm) { FEnter(this,_fsm); }
	void Exit(ArkTurretFsm &_fsm) { FExit(this,_fsm); }
	void Update(ArkTurretFsm &_fsm, const float _frameTime) { FUpdate(this,_fsm,_frameTime); }
	void LoadData(ArkTurretFsm &_fsm) { FLoadData(this,_fsm); }
	
#if 0
	const char *GetStateName() const;
	void OnSpazBegin(ArkTurretFsm &arg0);
	void OnSpazComplete(ArkTurretFsm &arg0, bool arg1);
#endif
	
	static inline auto FEnter = PreyFunction<void(ATStates::FallenSpazzing *const _this, ArkTurretFsm &_fsm)>(0x15E9630);
	static inline auto FExit = PreyFunction<void(ATStates::FallenSpazzing *const _this, ArkTurretFsm &_fsm)>(0x15E9870);
	static inline auto FUpdate = PreyFunction<void(ATStates::FallenSpazzing *const _this, ArkTurretFsm &_fsm, const float _frameTime)>(0x15EA360);
	static inline auto FLoadData = PreyFunction<void(ATStates::FallenSpazzing *const _this, ArkTurretFsm &_fsm)>(0x15E9AD0);
};

} // namespace ATStates

namespace ATStates
{

// Header: FromCpp
// Prey/GameDll/ark/turret/arkturretfsmstates.h
class Attacking : public ATStates::BaseState // Id=80152AF Size=20
{
public:
	ArkSimpleTimer m_losingTargetTimer;
	ArkSimpleTimer m_callForHelpPulseTimer;
	bool m_bLosingTarget;
	
	Attacking();
	void Enter(ArkTurretFsm &_fsm) { FEnter(this,_fsm); }
	void Exit(ArkTurretFsm &_fsm) { FExit(this,_fsm); }
	void Update(ArkTurretFsm &_fsm, const float _frameTime) { FUpdate(this,_fsm,_frameTime); }
	void LoadData(ArkTurretFsm &_fsm) { FLoadData(this,_fsm); }
	
#if 0
	const char *GetStateName() const;
	ValidTargetResult UpdateTargetTracking(ArkTurretFsm &arg0, const float arg1);
#endif
	
	static inline auto FEnter = PreyFunction<void(ATStates::Attacking *const _this, ArkTurretFsm &_fsm)>(0x15E9540);
	static inline auto FExit = PreyFunction<void(ATStates::Attacking *const _this, ArkTurretFsm &_fsm)>(0x15E98D0);
	static inline auto FUpdate = PreyFunction<void(ATStates::Attacking *const _this, ArkTurretFsm &_fsm, const float _frameTime)>(0x15EA160);
	static inline auto FLoadData = PreyFunction<void(ATStates::Attacking *const _this, ArkTurretFsm &_fsm)>(0x15E9910);
};

} // namespace ATStates

namespace ATStates
{

// Header: FromCpp
// Prey/GameDll/ark/turret/arkturretfsmstates.h
class Searching : public ATStates::BaseState // Id=80152B0 Size=12
{
public:
	float m_searchAnimDelayMin;
	float m_searchAnimDelayMax;
	float m_searchAnimDelayTimer;
	
	Searching();
	void Enter(ArkTurretFsm &_fsm) { FEnter(this,_fsm); }
	void Exit(ArkTurretFsm &_fsm) { FExit(this,_fsm); }
	void Update(ArkTurretFsm &_fsm, const float _frameTime) { FUpdate(this,_fsm,_frameTime); }
	void LoadData(ArkTurretFsm &_fsm) { FLoadData(this,_fsm); }
	
#if 0
	const char *GetStateName() const;
#endif
	
	static inline auto FEnter = PreyFunction<void(ATStates::Searching *const _this, ArkTurretFsm &_fsm)>(0x15E9760);
	static inline auto FExit = PreyFunction<void(ATStates::Searching *const _this, ArkTurretFsm &_fsm)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(ATStates::Searching *const _this, ArkTurretFsm &_fsm, const float _frameTime)>(0x15EA760);
	static inline auto FLoadData = PreyFunction<void(ATStates::Searching *const _this, ArkTurretFsm &_fsm)>(0x15E9DE0);
};

} // namespace ATStates

namespace ATStates
{

// Header: FromCpp
// Prey/GameDll/ark/turret/arkturretfsmstates.h
class FlowgraphControlled : public ATStates::BaseState // Id=80152B1 Size=1
{
public:
	void Enter(ArkTurretFsm &_fsm) { FEnter(this,_fsm); }
	void Exit(ArkTurretFsm &_fsm) { FExit(this,_fsm); }
	void Update(ArkTurretFsm &_fsm, const float _frameTime) { FUpdate(this,_fsm,_frameTime); }
	
#if 0
	const char *GetStateName() const;
#endif
	
	static inline auto FEnter = PreyFunction<void(ATStates::FlowgraphControlled *const _this, ArkTurretFsm &_fsm)>(0x15E96A0);
	static inline auto FExit = PreyFunction<void(ATStates::FlowgraphControlled *const _this, ArkTurretFsm &_fsm)>(0x15E98D0);
	static inline auto FUpdate = PreyFunction<void(ATStates::FlowgraphControlled *const _this, ArkTurretFsm &_fsm, const float _frameTime)>(0x15EA5B0);
};

} // namespace ATStates

namespace ATStates
{

// Header: FromCpp
// Prey/GameDll/ark/turret/arkturretfsmstates.h
class PlayerControlled : public ATStates::BaseState // Id=80152B2 Size=1
{
public:
	void Enter(ArkTurretFsm &_fsm) { FEnter(this,_fsm); }
	void Exit(ArkTurretFsm &_fsm) { FExit(this,_fsm); }
	void Update(ArkTurretFsm &_fsm, const float _frameTime) { FUpdate(this,_fsm,_frameTime); }
	
#if 0
	const char *GetStateName() const;
#endif
	
	static inline auto FEnter = PreyFunction<void(ATStates::PlayerControlled *const _this, ArkTurretFsm &_fsm)>(0x15E9730);
	static inline auto FExit = PreyFunction<void(ATStates::PlayerControlled *const _this, ArkTurretFsm &_fsm)>(0x15E98D0);
	static inline auto FUpdate = PreyFunction<void(ATStates::PlayerControlled *const _this, ArkTurretFsm &_fsm, const float _frameTime)>(0xA13080);
};

} // namespace ATStates

namespace ATStates
{

// Header: FromCpp
// Prey/GameDll/ark/turret/arkturretfsmstates.h
class PlayerCarried : public ATStates::BaseState // Id=80152B3 Size=1
{
public:
	void Enter(ArkTurretFsm &_fsm) { FEnter(this,_fsm); }
	void Exit(ArkTurretFsm &_fsm) { FExit(this,_fsm); }
	
#if 0
	const char *GetStateName() const;
#endif
	
	static inline auto FEnter = PreyFunction<void(ATStates::PlayerCarried *const _this, ArkTurretFsm &_fsm)>(0x15E96D0);
	static inline auto FExit = PreyFunction<void(ATStates::PlayerCarried *const _this, ArkTurretFsm &_fsm)>(0x15E98B0);
};

} // namespace ATStates

namespace ATStates
{

// Header: FromCpp
// Prey/GameDll/ark/turret/arkturretfsmstates.h
class Disabled : public ATStates::BaseState // Id=80152B4 Size=1
{
public:
	void Enter(ArkTurretFsm &_fsm) { FEnter(this,_fsm); }
	void Exit(ArkTurretFsm &_fsm) { FExit(this,_fsm); }
	
#if 0
	const char *GetStateName() const;
#endif
	
	static inline auto FEnter = PreyFunction<void(ATStates::Disabled *const _this, ArkTurretFsm &_fsm)>(0x15E95F0);
	static inline auto FExit = PreyFunction<void(ATStates::Disabled *const _this, ArkTurretFsm &_fsm)>(0xA13080);
};

} // namespace ATStates

