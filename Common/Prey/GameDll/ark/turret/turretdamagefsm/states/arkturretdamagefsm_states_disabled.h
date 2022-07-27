// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_base.h>

class ArkTurret;
namespace ArkTurretDamageFsm
{
struct StateParams;
} // namespace ArkTurretDamageFsm

namespace ArkTurretDamageFsm::States
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_disabled.h
class Disabled : public ArkTurretDamageFsm::States::Base // Id=80152E9 Size=12
{
public:
	ArkSimpleTimer m_disabledSpeakerEventCD;
	float m_flickerDuration;
	
	Disabled();
	void Enter(ArkTurretDamageFsm::StateParams const &_params) { FEnter(this,_params); }
	void Exit(ArkTurretDamageFsm::StateParams const &_params) { FExit(this,_params); }
	void Update(ArkTurret &_turret, float _frameTime) { FUpdate(this,_turret,_frameTime); }
	void OnBrokenChanged(ArkTurret &_turret, bool _bBroken) { FOnBrokenChanged(this,_turret,_bBroken); }
	
	static inline auto FEnter = PreyFunction<void(ArkTurretDamageFsm::States::Disabled *const _this, ArkTurretDamageFsm::StateParams const &_params)>(0x135B090);
	static inline auto FExit = PreyFunction<void(ArkTurretDamageFsm::States::Disabled *const _this, ArkTurretDamageFsm::StateParams const &_params)>(0x135B2C0);
	static inline auto FUpdate = PreyFunction<void(ArkTurretDamageFsm::States::Disabled *const _this, ArkTurret &_turret, float _frameTime)>(0x135B390);
	static inline auto FOnBrokenChanged = PreyFunction<void(ArkTurretDamageFsm::States::Disabled *const _this, ArkTurret &_turret, bool _bBroken)>(0x135B360);
};

} // namespace ArkTurretDamageFsm::States

