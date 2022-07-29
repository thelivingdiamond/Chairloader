// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/turret/ArkTurretFsmBase_template_.h>

class ArkTurret;
class IAction;

// Header: FromCpp
// Prey/GameDll/ark/turret/ArkTurretFsm.h
class ArkTurretFsm : public ArkTurretFsmBase_template_<void> // Id=80152AA Size=128
{
public:
	ArkTurret &m_turret;
	unsigned m_targetEntityId;
	ArkSimpleTimer m_uprightToFallenDelayTimer;
	ArkSimpleTimer m_playerLoiterTimer;
	float m_nonHostileApproachDistanceSqrd;
	float m_playerLoiterDistanceSqrd;
	float m_fallenSpazNoShootDelay;
	bool m_bHasFallen;
	
	ArkTurretFsm(ArkTurret &_turret);
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void Initialize() { FInitialize(this); }
	void Reset(bool _bAsPickup) { FReset(this,_bAsPickup); }
	void LoadData() { FLoadData(this); }
	void Serialize(TSerialize &_ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnDisabled() { FOnDisabled(this); }
	void OnUnDisabled() { FOnUnDisabled(this); }
	void StartUndeployed() { FStartUndeployed(this); }
	void StartBeingCarried() { FStartBeingCarried(this); }
	void StopBeingCarried() { FStopBeingCarried(this); }
	bool IsBeingCarried() const { return FIsBeingCarried(this); }
	void OnStartPlayerMimic() { FOnStartPlayerMimic(this); }
	void SetNewTarget(unsigned _entityId) { FSetNewTarget(this,_entityId); }
	ValidTargetResult IsTargetValid() const { return FIsTargetValid(this); }
	void TryStartCombatWith(unsigned _entityId) { FTryStartCombatWith(this,_entityId); }
	ValidTargetResult IsValidTarget(const unsigned _entityID) const { return FIsValidTarget(this,_entityID); }
	
#if 0
	void AnimEvent(const char *const arg0);
	void OnAttentionLevelChanged(const unsigned arg0, EArkAttentionLevel arg1, EArkAttentionLevel arg2, EArkAttentionChangeReason arg3, const bool arg4);
	ArkTurret &GetTurret();
	ArkTurret const &GetTurret() const;
	unsigned GetTargetId() const;
	bool IsInCombat();
	void SetHasFallen(bool arg0);
	void OnFragmentComplete(IAction *arg0);
	const char *GetCurrentStateName() const;
	void UpdateFallenTracker(const float arg0);
	void UpdatePlayerLoiter(const float arg0);
	void OnNonHostileTargetSeen(unsigned arg0);
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkTurretFsm *const _this, const float _frameTime)>(0x15E8FE0);
	static inline auto FInitialize = PreyFunction<void(ArkTurretFsm *const _this)>(0x15E8480);
	static inline auto FReset = PreyFunction<void(ArkTurretFsm *const _this, bool _bAsPickup)>(0x15E8DB0);
	static inline auto FLoadData = PreyFunction<void(ArkTurretFsm *const _this)>(0x15E8600);
	static inline auto FSerialize = PreyFunction<void(ArkTurretFsm *const _this, TSerialize &_ser)>(0x15E8E00);
	static inline auto FPostSerialize = PreyFunction<void(ArkTurretFsm *const _this)>(0x15E8DA0);
	static inline auto FOnDisabled = PreyFunction<void(ArkTurretFsm *const _this)>(0x15E8C60);
	static inline auto FOnUnDisabled = PreyFunction<void(ArkTurretFsm *const _this)>(0x15E8D60);
	static inline auto FStartUndeployed = PreyFunction<void(ArkTurretFsm *const _this)>(0x15E8F80);
	static inline auto FStartBeingCarried = PreyFunction<void(ArkTurretFsm *const _this)>(0x15E8E90);
	static inline auto FStopBeingCarried = PreyFunction<void(ArkTurretFsm *const _this)>(0x15E8F90);
	static inline auto FIsBeingCarried = PreyFunction<bool(ArkTurretFsm const *const _this)>(0x15E84C0);
	static inline auto FOnStartPlayerMimic = PreyFunction<void(ArkTurretFsm *const _this)>(0x15E8C70);
	static inline auto FSetNewTarget = PreyFunction<void(ArkTurretFsm *const _this, unsigned _entityId)>(0x15E8E80);
	static inline auto FIsTargetValid = PreyFunction<ValidTargetResult(ArkTurretFsm const *const _this)>(0x15E84D0);
	static inline auto FTryStartCombatWith = PreyFunction<void(ArkTurretFsm *const _this, unsigned _entityId)>(0x15E8FD0);
	static inline auto FIsValidTarget = PreyFunction<ValidTargetResult(ArkTurretFsm const *const _this, const unsigned _entityID)>(0x15E84E0);
};

