// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

class ArkCystoid;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// Header: FromCpp
// Prey/GameDll/ark/cystoid/ArkCystoidSignalReceiver.h
class ArkCystoidSignalReceiver : public ArkSignalSystem::Receiver // Id=801541A Size=24
{
public:
	ArkCystoid &m_cystoid;
	
	ArkCystoidSignalReceiver(ArkCystoid &_cystoid);
	virtual ~ArkCystoidSignalReceiver();
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	
	static inline auto FBitNotArkCystoidSignalReceiver = PreyFunction<void(ArkCystoidSignalReceiver *const _this)>(0x14E6790);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkCystoidSignalReceiver *const _this, ArkSignalSystem::Package const &_package)>(0x14E67E0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

class ArkCystoid;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// ArkCystoidSignalReceiver
// Header:  Prey/GameDll/ark/cystoid/ArkCystoidSignalReceiver.h
class ArkCystoidSignalReceiver : public ArkSignalSystem::Receiver
{ // Size=24 (0x18)
public:
	ArkCystoid& m_cystoid;

	ArkCystoidSignalReceiver(ArkCystoid& _cystoid);
	virtual ~ArkCystoidSignalReceiver();
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);

	static inline auto FArkCystoidSignalReceiverOv1 = PreyFunction<void(ArkCystoidSignalReceiver* const _this, ArkCystoid& _cystoid)>(0x1601F30);
	static inline auto FBitNotArkCystoidSignalReceiver = PreyFunction<void(ArkCystoidSignalReceiver* const _this)>(0x1601F70);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkCystoidSignalReceiver* const _this, const ArkSignalSystem::Package& _package)>(0x1601FC0);
};
#endif // !MOONCRASH
