// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

class ArkLaserTripline;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// Header: FromCpp
// Prey/GameDll/ark/ArkLaserTriplineSignalReceiver.h
class ArkLaserTriplineSignalReceiver : public ArkSignalSystem::Receiver // Id=8019368 Size=24
{
public:
	ArkLaserTripline &m_owner;

    ArkLaserTriplineSignalReceiver();
	virtual ~ArkLaserTriplineSignalReceiver();
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	
#ifndef MOONCRASH
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkLaserTriplineSignalReceiver *const _this, ArkSignalSystem::Package const &_package)>(0x1188FA0);
#else
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkLaserTriplineSignalReceiver* const _this, const ArkSignalSystem::Package& _package)>(0x1204220);
#endif
};
