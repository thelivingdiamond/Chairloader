// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/turret/ArkTurretAnimFsm.h>

namespace ArkTurretAnimFsm
{
class Fsm;
struct StateParams;
} // namespace ArkTurretAnimFsm
class IAction;

namespace ArkTurretAnimFsm::States
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretanimfsm/arkturretanimfsm_states.h
class Undeployed : public ArkTurretAnimFsm::States::Base // Id=80152BA Size=8
{
public:
	void Enter(ArkTurretAnimFsm::StateParams const &_params) { FEnter(this,_params); }
	void Update(ArkTurretAnimFsm::Fsm &_fsm, float _frameTime) { FUpdate(this,_fsm,_frameTime); }
	void Exit(ArkTurretAnimFsm::Fsm &_fsm) { FExit(this,_fsm); }
	
	static inline auto FEnter = PreyFunction<void(ArkTurretAnimFsm::States::Undeployed *const _this, ArkTurretAnimFsm::StateParams const &_params)>(0x1347AA0);
	static inline auto FUpdate = PreyFunction<void(ArkTurretAnimFsm::States::Undeployed *const _this, ArkTurretAnimFsm::Fsm &_fsm, float _frameTime)>(0x1347CF0);
	static inline auto FExit = PreyFunction<void(ArkTurretAnimFsm::States::Undeployed *const _this, ArkTurretAnimFsm::Fsm &_fsm)>(0x1347B40);
};

} // namespace ArkTurretAnimFsm::States

namespace ArkTurretAnimFsm::States
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretanimfsm/arkturretanimfsm_states.h
class Deploying : public ArkTurretAnimFsm::States::Base // Id=80152BB Size=8
{
public:
	void Enter(ArkTurretAnimFsm::StateParams const &_params) { FEnter(this,_params); }
	void AnimComplete(ArkTurretAnimFsm::Fsm &_fsm, IAction *_pCompletedAction) { FAnimComplete(this,_fsm,_pCompletedAction); }
	
	static inline auto FEnter = PreyFunction<void(ArkTurretAnimFsm::States::Deploying *const _this, ArkTurretAnimFsm::StateParams const &_params)>(0x13478D0);
	static inline auto FAnimComplete = PreyFunction<void(ArkTurretAnimFsm::States::Deploying *const _this, ArkTurretAnimFsm::Fsm &_fsm, IAction *_pCompletedAction)>(0x1347640);
};

} // namespace ArkTurretAnimFsm::States

namespace ArkTurretAnimFsm::States
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretanimfsm/arkturretanimfsm_states.h
class Deployed : public ArkTurretAnimFsm::States::Base // Id=80152BC Size=8
{
public:
	void Enter(ArkTurretAnimFsm::StateParams const &_params) { FEnter(this,_params); }
	void Update(ArkTurretAnimFsm::Fsm &_fsm, float _frameTime) { FUpdate(this,_fsm,_frameTime); }
	
#if 0
	bool IsDeployed() const;
	bool CanShoot() const;
#endif
	
	static inline auto FEnter = PreyFunction<void(ArkTurretAnimFsm::States::Deployed *const _this, ArkTurretAnimFsm::StateParams const &_params)>(0x1347850);
	static inline auto FUpdate = PreyFunction<void(ArkTurretAnimFsm::States::Deployed *const _this, ArkTurretAnimFsm::Fsm &_fsm, float _frameTime)>(0x1347BC0);
};

} // namespace ArkTurretAnimFsm::States

namespace ArkTurretAnimFsm::States
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretanimfsm/arkturretanimfsm_states.h
class UnDeploying : public ArkTurretAnimFsm::States::Base // Id=80152BD Size=8
{
public:
	void Enter(ArkTurretAnimFsm::StateParams const &_params) { FEnter(this,_params); }
	void AnimComplete(ArkTurretAnimFsm::Fsm &_fsm, IAction *_pCompletedAction) { FAnimComplete(this,_fsm,_pCompletedAction); }
	
	static inline auto FEnter = PreyFunction<void(ArkTurretAnimFsm::States::UnDeploying *const _this, ArkTurretAnimFsm::StateParams const &_params)>(0x1347A40);
	static inline auto FAnimComplete = PreyFunction<void(ArkTurretAnimFsm::States::UnDeploying *const _this, ArkTurretAnimFsm::Fsm &_fsm, IAction *_pCompletedAction)>(0x13476E0);
};

} // namespace ArkTurretAnimFsm::States

namespace ArkTurretAnimFsm::States
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretanimfsm/arkturretanimfsm_states.h
class Destroyed : public ArkTurretAnimFsm::States::Base // Id=80152BE Size=8
{
public:
	void Enter(ArkTurretAnimFsm::StateParams const &_params) { FEnter(this,_params); }
	
	static inline auto FEnter = PreyFunction<void(ArkTurretAnimFsm::States::Destroyed *const _this, ArkTurretAnimFsm::StateParams const &_params)>(0x1347940);
};

} // namespace ArkTurretAnimFsm::States

namespace ArkTurretAnimFsm::States
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretanimfsm/arkturretanimfsm_states.h
class Broken : public ArkTurretAnimFsm::States::Base // Id=80152BF Size=8
{
public:
	void Enter(ArkTurretAnimFsm::StateParams const &_params) { FEnter(this,_params); }
	void Update(ArkTurretAnimFsm::Fsm &_fsm, float _frameTime) { FUpdate(this,_fsm,_frameTime); }
	
#if 0
	bool IsDeployed() const;
#endif
	
	static inline auto FEnter = PreyFunction<void(ArkTurretAnimFsm::States::Broken *const _this, ArkTurretAnimFsm::StateParams const &_params)>(0x13477F0);
	static inline auto FUpdate = PreyFunction<void(ArkTurretAnimFsm::States::Broken *const _this, ArkTurretAnimFsm::Fsm &_fsm, float _frameTime)>(0x1347B70);
};

} // namespace ArkTurretAnimFsm::States

namespace ArkTurretAnimFsm::States
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretanimfsm/arkturretanimfsm_states.h
class Search : public ArkTurretAnimFsm::States::Base // Id=80152C0 Size=8
{
public:
	void Enter(ArkTurretAnimFsm::StateParams const &_params) { FEnter(this,_params); }
	void Update(ArkTurretAnimFsm::Fsm &_fsm, float _frameTime) { FUpdate(this,_fsm,_frameTime); }
	void AnimComplete(ArkTurretAnimFsm::Fsm &_fsm, IAction *_pCompletedAction) { FAnimComplete(this,_fsm,_pCompletedAction); }
	
#if 0
	bool IsDeployed() const;
#endif
	
	static inline auto FEnter = PreyFunction<void(ArkTurretAnimFsm::States::Search *const _this, ArkTurretAnimFsm::StateParams const &_params)>(0x13479A0);
	static inline auto FUpdate = PreyFunction<void(ArkTurretAnimFsm::States::Search *const _this, ArkTurretAnimFsm::Fsm &_fsm, float _frameTime)>(0x1347C00);
	static inline auto FAnimComplete = PreyFunction<void(ArkTurretAnimFsm::States::Search *const _this, ArkTurretAnimFsm::Fsm &_fsm, IAction *_pCompletedAction)>(0x13476B0);
};

} // namespace ArkTurretAnimFsm::States

