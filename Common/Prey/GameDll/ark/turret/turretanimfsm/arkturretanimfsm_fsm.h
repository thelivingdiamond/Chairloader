// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkTurretAnimFsmBase_template__void_.h>

class ArkTurret;
class IAction;

namespace ArkTurretAnimFsm
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretanimfsm/arkturretanimfsm_fsm.h
class Fsm : public ArkTurretAnimFsmBase_template_<void> // Id=80152B6 Size=80
{
public:
	ArkTurret &m_turret;
	EArkTurretAnimStateId m_requestStateId;
	
	Fsm(ArkTurret &_turret);
	void RequestHidden() { FRequestHidden(this); }
	void RequestDeployed() { FRequestDeployed(this); }
	void RequestBroken() { FRequestBroken(this); }
	void RequestSearching() { FRequestSearching(this); }
	void ClearRequest() { FClearRequest(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	bool IsDeployed() const { return FIsDeployed(this); }
	bool CanShoot() const { return FCanShoot(this); }
	void Initialize() { FInitialize(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void OnFragmentComplete(IAction *_pCompletedAction) { FOnFragmentComplete(this,_pCompletedAction); }
	
#if 0
	void OnDestroy();
	EArkTurretAnimStateId GetRequestedState() const;
	bool IsSearching() const;
	ArkTurret &GetTurret();
#endif
	
	static inline auto FRequestHidden = PreyFunction<void(ArkTurretAnimFsm::Fsm *const _this)>(0x1347120);
	static inline auto FRequestDeployed = PreyFunction<void(ArkTurretAnimFsm::Fsm *const _this)>(0x1347110);
	static inline auto FRequestBroken = PreyFunction<void(ArkTurretAnimFsm::Fsm *const _this)>(0x1347100);
	static inline auto FRequestSearching = PreyFunction<void(ArkTurretAnimFsm::Fsm *const _this)>(0x1347130);
	static inline auto FClearRequest = PreyFunction<void(ArkTurretAnimFsm::Fsm *const _this)>(0x1346FE0);
	static inline auto FUpdate = PreyFunction<void(ArkTurretAnimFsm::Fsm *const _this, const float _frameTime)>(0x1347280);
	static inline auto FIsDeployed = PreyFunction<bool(ArkTurretAnimFsm::Fsm const *const _this)>(0x1347020);
	static inline auto FCanShoot = PreyFunction<bool(ArkTurretAnimFsm::Fsm const *const _this)>(0x1346F60);
	static inline auto FInitialize = PreyFunction<void(ArkTurretAnimFsm::Fsm *const _this)>(0x1346FF0);
	static inline auto FReset = PreyFunction<void(ArkTurretAnimFsm::Fsm *const _this)>(0x1347140);
	static inline auto FSerialize = PreyFunction<void(ArkTurretAnimFsm::Fsm *const _this, TSerialize _ser)>(0x13471D0);
	static inline auto FOnFragmentComplete = PreyFunction<void(ArkTurretAnimFsm::Fsm *const _this, IAction *_pCompletedAction)>(0x1347090);
};

} // namespace ArkTurretAnimFsm

