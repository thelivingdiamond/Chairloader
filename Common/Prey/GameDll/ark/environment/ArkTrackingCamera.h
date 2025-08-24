// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDisruptable.h>
#include <Prey/GameDll/ark/ArkDisruptableSignalReceiver.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/iface/IArkDisruptableListener.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkTrackingCamera.h
class ArkTrackingCamera : public ArkEnvironmentalObject, public IArkDisruptableListener // Id=801A983 Size=360
{
public:
	std::vector<unsigned int> m_potentialTargets;
	unsigned m_activeTarget;
	ArkDisruptable m_disruptable;
	ArkDisruptableSignalReceiver m_signalReceiver;
	ArkAutoResetTimer m_targetReevaluationTimer;
	float m_currentYaw;
	int m_yawJointId;
	std::shared_ptr<IAnimationOperatorQueue> m_pAimRotationModifier;
	bool m_bEnabled;
	bool m_bRotating;
	float m_areaRadius;
	float m_radiansPerSec;
	ArkAudioTrigger m_triggerStartRotating;
	ArkAudioTrigger m_triggerStopRotating;
	bool m_bStartsEnabled;
	
	ArkTrackingCamera();
	virtual ~ArkTrackingCamera();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	void SetEnabled(bool _bEnabled) { FSetEnabled(this,_bEnabled); }
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual QuatT GetSparkLoc() const;
	void InitArea() { FInitArea(this); }
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	virtual void RegisterForSignals(bool _bRegister);
	
#if 0
	void PickBestTarget();
#endif
	
	static inline auto FInit = PreyFunction<bool(ArkTrackingCamera *const _this, IGameObject *_pGameObject)>(0x1264950);
	static inline auto FPostInit = PreyFunction<void(ArkTrackingCamera *const _this, IGameObject *_pGameObject)>(0x1270BB0);
	static inline auto FFullSerialize = PreyFunction<void(ArkTrackingCamera *const _this, TSerialize _ser)>(0x1270070);
	static inline auto FPostSerialize = PreyFunction<void(ArkTrackingCamera *const _this)>(0x1270DA0);
	static inline auto FUpdate = PreyFunction<void(ArkTrackingCamera *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x1270FA0);
	static inline auto FProcessEvent = PreyFunction<void(ArkTrackingCamera *const _this, SEntityEvent &_event)>(0x1270DE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkTrackingCamera const *const _this, ICrySizer *_s)>(0x1270340);
	static inline auto FSetEnabled = PreyFunction<void(ArkTrackingCamera *const _this, bool _bEnabled)>(0x1270F10);
	static inline auto FOnReset = PreyFunction<void(ArkTrackingCamera *const _this, bool _bEnteringGameMode)>(0x1270B30);
	static inline auto FLoadProperties = PreyFunction<void(ArkTrackingCamera *const _this)>(0x12704A0);
	static inline auto FOnDisruptedChanged = PreyFunction<void(ArkTrackingCamera *const _this, bool _bDisrupted, bool _bWasForced)>(0x1270AD0);
	static inline auto FGetSparkLoc = PreyFunction<QuatT(ArkTrackingCamera const *const _this)>(0x12703A0);
	static inline auto FInitArea = PreyFunction<void(ArkTrackingCamera *const _this)>(0x1270420);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkTrackingCamera *const _this, ArkSignalSystem::Package const &_package)>(0x1270B20);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkTrackingCamera *const _this, bool _bRegister)>(0x1270F00);
};

