// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/dialog/arkspeaker.h>

class ArkResponseQuery;
class ArkTurret;
class IArkDialogPlayerExtension;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/turret/ArkTurretDialogSpeaker.h
class ArkTurretDialogSpeaker // Id=80152C4 Size=528
{
public:
	ArkSpeaker<ArkDialogTurret> m_arkSpeaker;
	ArkTurret &m_turret;
	float m_startDelay;
	bool m_bEnabled;
	
	ArkTurretDialogSpeaker(ArkTurret &_turret);
	~ArkTurretDialogSpeaker() { FBitNotArkTurretDialogSpeaker(this); }
	void PostInit() { FPostInit(this); }
	void Release() { FRelease(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void Reset() { FReset(this); }
	void LoadScriptVariables() { FLoadScriptVariables(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void SetPlayerExtension(IArkDialogPlayerExtension *const _pExtension) { FSetPlayerExtension(this,_pExtension); }
	void Stop() { FStop(this); }
	void OnTakeDamage(IEntity const *_pInstigator, float _damage) { FOnTakeDamage(this,_pInstigator,_damage); }
	void OnNewFriendlyTarget(IEntity const &_target) { FOnNewFriendlyTarget(this,_target); }
	void OnNewFriendlyTargetPlayer() { FOnNewFriendlyTargetPlayer(this); }
	void OnNewTarget(IEntity const &_target) { FOnNewTarget(this,_target); }
	void OnNewTargetPlayer() { FOnNewTargetPlayer(this); }
	void OnLostTarget(IEntity const &_target) { FOnLostTarget(this,_target); }
	void OnTargetFactionChangeFriendly(IEntity const &_target) { FOnTargetFactionChangeFriendly(this,_target); }
	void OnTargetDead(IEntity const &_target) { FOnTargetDead(this,_target); }
	void OnDeploy() { FOnDeploy(this); }
	void OnCarried() { FOnCarried(this); }
	void OnTechnoControlled() { FOnTechnoControlled(this); }
	void OnSearching() { FOnSearching(this); }
	void OnSearchingContinued() { FOnSearchingContinued(this); }
	void OnFortified() { FOnFortified(this); }
	void OnBumpedPlayerTouch() { FOnBumpedPlayerTouch(this); }
	void OnSuccessfulHack() { FOnSuccessfulHack(this); }
	void OnFailedHack() { FOnFailedHack(this); }
	void OnFallen() { FOnFallen(this); }
	void OnFallenSpazComplete() { FOnFallenSpazComplete(this); }
	void OnBroken() { FOnBroken(this); }
	void OnBrokenRepeat() { FOnBrokenRepeat(this); }
	void OnRepaired() { FOnRepaired(this); }
	void OnPlayerLoiter() { FOnPlayerLoiter(this); }
	void Speak(ArkResponseQuery &_query, const char *const _pConcept) { FSpeakOv0(this,_query,_pConcept); }
	float GetDistanceTo(IEntity const &_entity) const { return FGetDistanceTo(this,_entity); }
	
#if 0
	void SetEnabled(bool arg0);
	bool IsEnabled() const;
	void OnTargetOutOfRange(IEntity const &arg0);
	void OnDestroyed();
	void Speak(const char *const arg0);
#endif
	
	static inline auto FBitNotArkTurretDialogSpeaker = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1342710);
	static inline auto FPostInit = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1343B60);
	static inline auto FRelease = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(ArkTurretDialogSpeaker *const _this, const float _frameTime)>(0x1343E20);
	static inline auto FReset = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1343B80);
	static inline auto FLoadScriptVariables = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1342810);
	static inline auto FSerialize = PreyFunction<void(ArkTurretDialogSpeaker *const _this, TSerialize _ser)>(0x1343B90);
	static inline auto FPostSerialize = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x12941E0);
	static inline auto FSetPlayerExtension = PreyFunction<void(ArkTurretDialogSpeaker *const _this, IArkDialogPlayerExtension *const _pExtension)>(0x1343BB0);
	static inline auto FStop = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1343E10);
	static inline auto FOnTakeDamage = PreyFunction<void(ArkTurretDialogSpeaker *const _this, IEntity const *_pInstigator, float _damage)>(0x13435E0);
	static inline auto FOnNewFriendlyTarget = PreyFunction<void(ArkTurretDialogSpeaker *const _this, IEntity const &_target)>(0x1342D70);
	static inline auto FOnNewFriendlyTargetPlayer = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1342F10);
	static inline auto FOnNewTarget = PreyFunction<void(ArkTurretDialogSpeaker *const _this, IEntity const &_target)>(0x13430E0);
	static inline auto FOnNewTargetPlayer = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1343280);
	static inline auto FOnLostTarget = PreyFunction<void(ArkTurretDialogSpeaker *const _this, IEntity const &_target)>(0x1342BD0);
	static inline auto FOnTargetFactionChangeFriendly = PreyFunction<void(ArkTurretDialogSpeaker *const _this, IEntity const &_target)>(0x1343980);
	static inline auto FOnTargetDead = PreyFunction<void(ArkTurretDialogSpeaker *const _this, IEntity const &_target)>(0x13437E0);
	static inline auto FOnDeploy = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1342A90);
	static inline auto FOnCarried = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1342A40);
	static inline auto FOnTechnoControlled = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1343B20);
	static inline auto FOnSearching = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x13434C0);
	static inline auto FOnSearchingContinued = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1343500);
	static inline auto FOnFortified = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1342B90);
	static inline auto FOnBumpedPlayerTouch = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1342A00);
	static inline auto FOnSuccessfulHack = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x13435A0);
	static inline auto FOnFailedHack = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1342AD0);
	static inline auto FOnFallen = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1342B10);
	static inline auto FOnFallenSpazComplete = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1342B50);
	static inline auto FOnBroken = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1342980);
	static inline auto FOnBrokenRepeat = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x13429C0);
	static inline auto FOnRepaired = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1343480);
	static inline auto FOnPlayerLoiter = PreyFunction<void(ArkTurretDialogSpeaker *const _this)>(0x1343440);
	static inline auto FSpeakOv0 = PreyFunction<void(ArkTurretDialogSpeaker *const _this, ArkResponseQuery &_query, const char *const _pConcept)>(0x1343BC0);
	static inline auto FGetDistanceTo = PreyFunction<float(ArkTurretDialogSpeaker const *const _this, IEntity const &_entity)>(0x1342780);
};

