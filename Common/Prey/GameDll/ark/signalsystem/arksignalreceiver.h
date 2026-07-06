// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

namespace ArkSignalSystem
{
class Package;
class PackageSignalRampContainer;
} // namespace ArkSignalSystem

namespace ArkSignalSystem
{

// Header: FromCpp
// Prey/GameDll/ark/signalsystem/arksignalreceiver.h
class Receiver // Id=80136A9 Size=16
{
public:
	unsigned m_entityId;
	
	Receiver();
	virtual ~Receiver();
	virtual void Init(const unsigned &_entityId);
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &arg0) = 0;
	virtual ArkSignalSystem::PackageSignalRampContainer *GetPackageSignalRampContainer();
	virtual void OnKilled(unsigned _killerId) const;
	
	static inline auto FBitNotReceiver = PreyFunction<void(ArkSignalSystem::Receiver *const _this)>(0x15DEE00);
	static inline auto FInit = PreyFunction<void(ArkSignalSystem::Receiver *const _this, const unsigned &_entityId)>(0x15DEEC0);
	static inline auto FGetPackageSignalRampContainer = PreyFunction<ArkSignalSystem::PackageSignalRampContainer *(ArkSignalSystem::Receiver *const _this)>(0x158AEF0);
	static inline auto FOnKilled = PreyFunction<void(ArkSignalSystem::Receiver const *const _this, unsigned _killerId)>(0x15DEF20);
};

} // namespace ArkSignalSystem
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

namespace ArkSignalSystem
{
class Package;
class PackageSignalRampContainer;
} // namespace ArkSignalSystem

namespace ArkSignalSystem
{

// ArkSignalSystem::Receiver
// Header:  Prey/GameDll/ark/signalsystem/arksignalreceiver.h
class Receiver
{ // Size=16 (0x10)
public:
	unsigned m_entityId;

	Receiver();
	virtual ~Receiver();
	virtual void Init(const unsigned& _entityId);
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package) = 0;
	virtual ArkSignalSystem::PackageSignalRampContainer* GetPackageSignalRampContainer();
	virtual void OnKilled(unsigned _killerId) const;

	static inline auto FReceiverOv1 = PreyFunction<void(ArkSignalSystem::Receiver* const _this)>(0x1706D90);
	static inline auto FBitNotReceiver = PreyFunction<void(ArkSignalSystem::Receiver* const _this)>(0x1706DB0);
	static inline auto FInit = PreyFunction<void(ArkSignalSystem::Receiver* const _this, const unsigned& _entityId)>(0x1706E70);
	static inline auto FGetPackageSignalRampContainer = PreyFunction<ArkSignalSystem::PackageSignalRampContainer* (ArkSignalSystem::Receiver* const _this)>(0x1CBB0B0);
	static inline auto FOnKilled = PreyFunction<void(const ArkSignalSystem::Receiver* const _this, unsigned _killerId)>(0x1706ED0);
};


} // namespace ArkSignalSystem
#endif // !MOONCRASH
