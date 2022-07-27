// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkGameObjectExtension.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObjectSignalReceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct IGameObject;
struct SEntityEvent;

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkEnvironmentalObject.h
class ArkEnvironmentalObject : public CArkGameObjectExtension<ArkEnvironmentalObject> // Id=801608C Size=88
{
public:
	ArkEnvironmentalObjectSignalReceiver m_signalReceiver;
	
	ArkEnvironmentalObject();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Release();
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual void HandleScriptEvent(const char *_pEvent, SEntityEvent &_event);
	virtual void RegisterForSignals(bool _bRegister);
	void LoadModel() { FLoadModel(this); }
	
	static inline auto FInit = PreyFunction<bool(ArkEnvironmentalObject *const _this, IGameObject *_pGameObject)>(0x13BD170);
	static inline auto FPostInit = PreyFunction<void(ArkEnvironmentalObject *const _this, IGameObject *_pGameObject)>(0x13BD2C0);
	static inline auto FRelease = PreyFunction<void(ArkEnvironmentalObject *const _this)>(0xA97D40);
	static inline auto FProcessEvent = PreyFunction<void(ArkEnvironmentalObject *const _this, SEntityEvent &_event)>(0x13BD2F0);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkEnvironmentalObject *const _this, ArkSignalSystem::Package const &_package)>(0xA13080);
	static inline auto FOnReset = PreyFunction<void(ArkEnvironmentalObject *const _this, bool _bEnteringGameMode)>(0x13BD280);
	static inline auto FLoadProperties = PreyFunction<void(ArkEnvironmentalObject *const _this)>(0xA13080);
	static inline auto FHandleScriptEvent = PreyFunction<void(ArkEnvironmentalObject *const _this, const char *_pEvent, SEntityEvent &_event)>(0xA13080);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkEnvironmentalObject *const _this, bool _bRegister)>(0xA13080);
	static inline auto FLoadModel = PreyFunction<void(ArkEnvironmentalObject *const _this)>(0x13BD1B0);
};

