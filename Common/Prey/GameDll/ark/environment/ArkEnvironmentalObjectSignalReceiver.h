// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

class ArkEnvironmentalObject;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// ArkEnvironmentalObjectSignalReceiver
// Header:  Prey/GameDll/ark/environment/ArkEnvironmentalObjectSignalReceiver.h
class ArkEnvironmentalObjectSignalReceiver : public ArkSignalSystem::Receiver
{ // Size=24 (0x18)
public:
	ArkEnvironmentalObject& m_environmentalObject;

	ArkEnvironmentalObjectSignalReceiver(ArkEnvironmentalObject& _object);
	virtual ~ArkEnvironmentalObjectSignalReceiver();
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);

	static inline auto FArkEnvironmentalObjectSignalReceiverOv1 = PreyFunction<void(ArkEnvironmentalObjectSignalReceiver* const _this, ArkEnvironmentalObject& _object)>(0x14C96A0);
	static inline auto FBitNotArkEnvironmentalObjectSignalReceiver = PreyFunction<void(ArkEnvironmentalObjectSignalReceiver* const _this)>(0x14C96E0);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkEnvironmentalObjectSignalReceiver* const _this, const ArkSignalSystem::Package& _package)>(0x14C9730);
};
#endif // !MOONCRASH
