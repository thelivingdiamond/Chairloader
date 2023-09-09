// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

class ArkDisruptable;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// Header: FromCpp
// Prey/GameDll/ark/ArkDisruptableSignalReceiver.h
class ArkDisruptableSignalReceiver : public ArkSignalSystem::Receiver // Id=80163C5 Size=24
{
public:
	ArkDisruptable &m_disruptable;

    ArkDisruptableSignalReceiver();
	virtual ~ArkDisruptableSignalReceiver();
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkDisruptableSignalReceiver *const _this, ArkSignalSystem::Package const &_package)>(0x11546D0);
};

