// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkTurret;

namespace ArkTurretDamageFsm
{

// ArkTurretDamageFsm::StateParams
// Header:  Prey/GameDll/ark/turret/turretdamagefsm/arkturretdamagefsm_stateparams.h
struct StateParams
{ // Size=16 (0x10)
	ArkTurret& m_turret;
	const bool m_bTakingDamage;

	StateParams(ArkTurret& _turret, bool _bTakingDamage);

	static inline auto FStateParams = PreyFunction<void(ArkTurretDamageFsm::StateParams* const _this, ArkTurret& _turret, bool _bTakingDamage)>(0x143E240);
};


} // namespace ArkTurretDamageFsm
#endif // MOONCRASH
