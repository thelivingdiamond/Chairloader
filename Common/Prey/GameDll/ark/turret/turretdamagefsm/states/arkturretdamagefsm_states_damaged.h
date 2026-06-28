// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_base.h>

namespace ArkTurretDamageFsm
{
struct StateParams;
} // namespace ArkTurretDamageFsm

namespace ArkTurretDamageFsm::States
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_damaged.h
class Damaged : public ArkTurretDamageFsm::States::Base // Id=80152E8 Size=1
{
public:
	void Enter(ArkTurretDamageFsm::StateParams const &_params) const { FEnter(this,_params); }
	void Exit(ArkTurretDamageFsm::StateParams const &_params) const { FExit(this,_params); }
	
	static inline auto FEnter = PreyFunction<void(ArkTurretDamageFsm::States::Damaged const *const _this, ArkTurretDamageFsm::StateParams const &_params)>(0x135AFF0);
	static inline auto FExit = PreyFunction<void(ArkTurretDamageFsm::States::Damaged const *const _this, ArkTurretDamageFsm::StateParams const &_params)>(0x135B030);
};

} // namespace ArkTurretDamageFsm::States
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_base.h>

namespace ArkTurretDamageFsm
{
struct StateParams;
} // namespace ArkTurretDamageFsm

namespace ArkTurretDamageFsm::States
{

// ArkTurretDamageFsm::States::Damaged
// Header:  Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_damaged.h
class Damaged : public ArkTurretDamageFsm::States::Base
{ // Size=1 (0x1)
public:
	void Enter(const ArkTurretDamageFsm::StateParams& _params) const { FEnter(this, _params); }
	void Exit(const ArkTurretDamageFsm::StateParams& _params) const { FExit(this, _params); }

	static inline auto FEnter = PreyFunction<void(const ArkTurretDamageFsm::States::Damaged* const _this, const ArkTurretDamageFsm::StateParams& _params)>(0x143E290);
	static inline auto FExit = PreyFunction<void(const ArkTurretDamageFsm::States::Damaged* const _this, const ArkTurretDamageFsm::StateParams& _params)>(0x143E2E0);
};


} // namespace ArkTurretDamageFsm::States
#endif // !MOONCRASH
