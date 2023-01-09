// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicScienceOperatorRotationController.h>
#include <Prey/GameDll/ark/player/psipower/arkplayermimicoperatorcontroller.h>
#include <Prey/GameDll/ark/player/psipower/arkplayermimicoperatormovementcontroller.h>

class ArkNpcAnimAction;
class ArkPsiMimicScienceOperatorProperties;
class CCryName;
struct IAnimatedCharacter;
struct IEntity;

// ArkPlayerMimicScienceOperatorController
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicScienceOperatorController.h
class ArkPlayerMimicScienceOperatorController : public ArkPlayerMimicOperatorController<ArkPlayerMimicScienceOperatorController>, public ArkNpcAnimActionObserver
{ // Size=456 (0x1C8)
public:
	using Properties = ArkPsiMimicScienceOperatorProperties;
	using MovementController = ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController>;
	using RotationController = ArkPlayerMimicScienceOperatorRotationController;

	ArkPlayerMimicOperatorMovementController<ArkPlayerMimicScienceOperatorController> m_movementController;
	ArkPlayerMimicScienceOperatorRotationController m_rotationController;
	_smart_ptr<ArkNpcAnimAction> m_pProbeAttackAnimAction;
	IAnimatedCharacter* m_pAnimatedCharacter;
	const ArkPsiMimicScienceOperatorProperties& m_properties;
	unsigned m_leftLightningArcEntityId;
	unsigned m_rightLightningArcEntityId;
	unsigned m_attackTargetEntityId;
	unsigned m_fallbackTargetEntityId;
	unsigned m_attackTargetProxyEntityId;
	int m_probeAttackFragmentId;
	bool m_bAttacking;

	ArkPlayerMimicScienceOperatorController();
	virtual ~ArkPlayerMimicScienceOperatorController();
	void Initialize_Derived(IEntity& _mimicEntity) { FInitialize_Derived(this, _mimicEntity); }
	void Update_Derived(const float _frameTime, IEntity& _mimicEntity) { FUpdate_Derived(this, _frameTime, _mimicEntity); }
	void ProcessInput(const CCryName& _actionId, const bool _bPressed) { FProcessInput(this, _actionId, _bPressed); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	bool IsAttacking() const { return FIsAttacking(this); }
	float GetMovementSpeed() const { return FGetMovementSpeed(this); }
	const IEntity* GetAttackTarget() const { return FGetAttackTarget(this); }
	const ArkPsiMimicScienceOperatorProperties& GetProperties() const { return FGetProperties(this); }
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);
	void OnLightningCallback(IEntity* _pArcEntity, IEntity* _pTargetEntity, float _strikeTime) { FOnLightningCallback(this, _pArcEntity, _pTargetEntity, _strikeTime); }
	void CleanUp() { FCleanUp(this); }
	void StartProbeAttackAnimation() { FStartProbeAttackAnimation(this); }
	void StopProbeAttackAnimation() { FStopProbeAttackAnimation(this); }
	void UpdateAttackTarget() { FUpdateAttackTarget(this); }

#if 0
	Quat GetMimicTargetRotation() const;
	void SpawnAttackTargetProxy();
	IEntity* GetProxyTarget() const;
#endif

	static inline auto FArkPlayerMimicScienceOperatorController = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this)>(0x12F01B0);
	static inline auto FBitNotArkPlayerMimicScienceOperatorController = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this)>(0x12F0350);
	static inline auto FInitialize_Derived = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this, IEntity& _mimicEntity)>(0x12F0BC0);
	static inline auto FUpdate_Derived = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this, const float _frameTime, IEntity& _mimicEntity)>(0x12F1F00);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this, const CCryName& _actionId, const bool _bPressed)>(0x12F11D0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this, TSerialize _ser)>(0x12F13B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this)>(0x12F11C0);
	static inline auto FIsAttacking = PreyFunction<bool(const ArkPlayerMimicScienceOperatorController* const _this)>(0x12F0D30);
	static inline auto FGetMovementSpeed = PreyFunction<float(const ArkPlayerMimicScienceOperatorController* const _this)>(0x12F0B70);
	static inline auto FGetAttackTarget = PreyFunction<const IEntity* (const ArkPlayerMimicScienceOperatorController* const _this)>(0x12F0AA0);
	static inline auto FGetProperties = PreyFunction<const ArkPsiMimicScienceOperatorProperties& (const ArkPlayerMimicScienceOperatorController* const _this)>(0x12F0BB0);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this, ArkNpcAnimAction& _animAction)>(0x12F1190);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0x12F1000);
	static inline auto FOnLightningCallback = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this, IEntity* _pArcEntity, IEntity* _pTargetEntity, float _strikeTime)>(0x12F0D40);
	static inline auto FCleanUp = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this)>(0x12F0920);
	static inline auto FStartProbeAttackAnimation = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this)>(0x12F1430);
	static inline auto FStopProbeAttackAnimation = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this)>(0x12F1600);
	static inline auto FUpdateAttackTarget = PreyFunction<void(ArkPlayerMimicScienceOperatorController* const _this)>(0x12F16B0);
};

