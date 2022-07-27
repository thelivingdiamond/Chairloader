// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkGameObjectExtension.h>
#include <Prey/GameDll/ark/environment/arkapextentaclehead.h>
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct IGameObject;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/environment/arkapextentaclehead.h
class ArkApexTentacleHeadSignalReceiver : public ArkSignalSystem::Receiver // Id=8019701 Size=24
{
public:
	ArkApexTentacleHead const &m_tentacleHead;
	
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	virtual ~ArkApexTentacleHeadSignalReceiver();
	
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkApexTentacleHeadSignalReceiver *const _this, ArkSignalSystem::Package const &_package)>(0x11B65A0);
};

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkApexTentacleHead.h
class ArkApexTentacleHead : public CArkGameObjectExtension<ArkApexTentacleHead> // Id=8019702 Size=96
{
public:
	ArkApexTentacleHeadSignalReceiver m_signalReceiver;
	unsigned m_tentacleId;
	
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void Release();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	void Physicalize(const float _radius) { FPhysicalize(this,_radius); }
	virtual ~ArkApexTentacleHead();
	
#if 0
	void SetTentacleId(const unsigned arg0);
	unsigned GetTentacleId() const;
#endif
	
	static inline auto FInit = PreyFunction<bool(ArkApexTentacleHead *const _this, IGameObject *_pGameObject)>(0x11B6560);
	static inline auto FPostInit = PreyFunction<void(ArkApexTentacleHead *const _this, IGameObject *_pGameObject)>(0x11B67D0);
	static inline auto FFullSerialize = PreyFunction<void(ArkApexTentacleHead *const _this, TSerialize _ser)>(0x11B6300);
	static inline auto FRelease = PreyFunction<void(ArkApexTentacleHead *const _this)>(0xA97D40);
	static inline auto FHandleEvent = PreyFunction<void(ArkApexTentacleHead *const _this, SGameObjectEvent const &_event)>(0x11B64E0);
	static inline auto FPhysicalize = PreyFunction<void(ArkApexTentacleHead *const _this, const float _radius)>(0x11B65E0);
};

