// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/turret/ArkTurretDamageFsm.h>
#include <_unknown/ArkTurretDamageFsmBase_template__void_.h>

class ArkSafeScriptTable;
class ArkTurret;

namespace ArkTurretDamageFsm
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretdamagefsm/arkturretdamagefsm_fsm.h
class Fsm : protected ArkTurretDamageFsmBase_template_<void> // Id=80152E2 Size=56
{
public:
	ArkTurretDamageFsm::Config m_config;
	
	void Initiate(ArkTurret &_turret) { FInitiate(this,_turret); }
	void Reset(ArkTurret &_turret) { FReset(this,_turret); }
	void Update(ArkTurret &_turret, float _frameTime) { FUpdate(this,_turret,_frameTime); }
	void OnHealthChange(ArkTurret &_turret, float _turretNewHealth, bool _bFromDamage) { FOnHealthChange(this,_turret,_turretNewHealth,_bFromDamage); }
	bool IsDisabled() const { return FIsDisabled(this); }
	void Serialize(ArkTurret &_turret, TSerialize _ser) { FSerialize(this,_turret,_ser); }
	void OnBrokenChanged(ArkTurret &_turret, bool _bBroken) { FOnBrokenChanged(this,_turret,_bBroken); }
	float GetBrokenHeathThreashold() const { return FGetBrokenHeathThreashold(this); }
	
#if 0
	void Terminate(ArkTurret &arg0);
	void LoadScriptVariables(ArkSafeScriptTable arg0);
#endif
	
	static inline auto FInitiate = PreyFunction<void(ArkTurretDamageFsm::Fsm *const _this, ArkTurret &_turret)>(0x135AA60);
	static inline auto FReset = PreyFunction<void(ArkTurretDamageFsm::Fsm *const _this, ArkTurret &_turret)>(0x135ADF0);
	static inline auto FUpdate = PreyFunction<void(ArkTurretDamageFsm::Fsm *const _this, ArkTurret &_turret, float _frameTime)>(0x135AF90);
	static inline auto FOnHealthChange = PreyFunction<void(ArkTurretDamageFsm::Fsm *const _this, ArkTurret &_turret, float _turretNewHealth, bool _bFromDamage)>(0x135AD10);
	static inline auto FIsDisabled = PreyFunction<bool(ArkTurretDamageFsm::Fsm const *const _this)>(0x1211660);
	static inline auto FSerialize = PreyFunction<void(ArkTurretDamageFsm::Fsm *const _this, ArkTurret &_turret, TSerialize _ser)>(0x135AE70);
	static inline auto FOnBrokenChanged = PreyFunction<void(ArkTurretDamageFsm::Fsm *const _this, ArkTurret &_turret, bool _bBroken)>(0x135ACF0);
	static inline auto FGetBrokenHeathThreashold = PreyFunction<float(ArkTurretDamageFsm::Fsm const *const _this)>(0x855D80);
};

} // namespace ArkTurretDamageFsm

