// Header file automatically created from a PDB.

#pragma once

namespace ArkTurretAnimFsm
{
class Fsm;
struct StateParams;
} // namespace ArkTurretAnimFsm
class IAction;

namespace ArkTurretAnimFsm::States
{

// Header: Override
// Prey/GameDll/ark/turret/ArkTurretAnimFsm.h
class Base // Id=80152B8 Size=8
{
public:
	_smart_ptr<IAction> m_pAction;
	
	bool IsDeployed() const { return FIsDeployed(this); }
	bool CanShoot() const { return FCanShoot(this); }
	
#if 0
	void Enter(ArkTurretAnimFsm::StateParams const &arg0);
	void Exit(ArkTurretAnimFsm::Fsm &arg0);
	void Update(ArkTurretAnimFsm::Fsm &arg0, float arg1);
	void AnimComplete(ArkTurretAnimFsm::Fsm &arg0, IAction *arg1);
	void StartFragment(ArkTurretAnimFsm::Fsm &arg0, const char *const arg1);
	bool HasAction() const;
	bool ActionPlaying() const;
#endif
	
	static inline auto FIsDeployed = PreyFunction<bool(ArkTurretAnimFsm::States::Base const *const _this)>(0xDD23F0);
	static inline auto FCanShoot = PreyFunction<bool(ArkTurretAnimFsm::States::Base const *const _this)>(0xDD23F0);
};

} // namespace ArkTurretAnimFsm::States

