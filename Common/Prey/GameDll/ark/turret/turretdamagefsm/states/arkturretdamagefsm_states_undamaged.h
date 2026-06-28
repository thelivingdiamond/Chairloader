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
// Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_undamaged.h
class Undamaged : public ArkTurretDamageFsm::States::Base // Id=80152E5 Size=1
{
public:
	void Enter(ArkTurretDamageFsm::StateParams const &_params) const { FEnter(this,_params); }
	void Exit(ArkTurretDamageFsm::StateParams const &_params) const { FExit(this,_params); }
	
	static inline auto FEnter = PreyFunction<void(ArkTurretDamageFsm::States::Undamaged const *const _this, ArkTurretDamageFsm::StateParams const &_params)>(0x135B400);
	static inline auto FExit = PreyFunction<void(ArkTurretDamageFsm::States::Undamaged const *const _this, ArkTurretDamageFsm::StateParams const &_params)>(0x135B420);
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

// ArkTurretDamageFsm::States::Undamaged
// Header:  Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_undamaged.h
class Undamaged : public ArkTurretDamageFsm::States::Base
{ // Size=1 (0x1)
public:
	void Enter(const ArkTurretDamageFsm::StateParams& _params) const { FEnter(this, _params); }
	void Exit(const ArkTurretDamageFsm::StateParams& _params) const { FExit(this, _params); }

	static inline auto FEnter = PreyFunction<void(const ArkTurretDamageFsm::States::Undamaged* const _this, const ArkTurretDamageFsm::StateParams& _params)>(0x143E7B0);
	static inline auto FExit = PreyFunction<void(const ArkTurretDamageFsm::States::Undamaged* const _this, const ArkTurretDamageFsm::StateParams& _params)>(0x143E7E0);
};


} // namespace ArkTurretDamageFsm::States
#endif // !MOONCRASH
