// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

class ArkEnvironmentalObject;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkEnvironmentalObjectSignalReceiver.h
class ArkEnvironmentalObjectSignalReceiver : public ArkSignalSystem::Receiver // Id=8016090 Size=24
{
public:
	ArkEnvironmentalObject &m_environmentalObject;
	
	ArkEnvironmentalObjectSignalReceiver(ArkEnvironmentalObject &_object);
	virtual ~ArkEnvironmentalObjectSignalReceiver();
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	
	static inline auto FBitNotArkEnvironmentalObjectSignalReceiver = PreyFunction<void(ArkEnvironmentalObjectSignalReceiver *const _this)>(0x13BD3C0);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkEnvironmentalObjectSignalReceiver *const _this, ArkSignalSystem::Package const &_package)>(0x13BD410);
};

