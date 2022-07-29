// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class CArkBreakable;

// Header: FromCpp
// Prey/GameDll/ark/signalsystem/ArkBreakableSignalReceiver.h
class ArkBreakableSignalReceiver : public ArkSignalSystem::Receiver // Id=8019357 Size=32
{
public:
	CArkBreakable *m_pBreakable;
	uint64_t m_signalGroupId;
	
	virtual ~ArkBreakableSignalReceiver();
	virtual void Init(const unsigned &_entityId);
	void Reset() { FReset(this); }
	void InitializeSignalGroupId(CArkBreakable &_breakable, const uint64_t _id) { FInitializeSignalGroupId(this,_breakable,_id); }
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	
	static inline auto FBitNotArkBreakableSignalReceiver = PreyFunction<void(ArkBreakableSignalReceiver *const _this)>(0x15CEA80);
	static inline auto FInit = PreyFunction<void(ArkBreakableSignalReceiver *const _this, const unsigned &_entityId)>(0xA13080);
	static inline auto FReset = PreyFunction<void(ArkBreakableSignalReceiver *const _this)>(0x15CED10);
	static inline auto FInitializeSignalGroupId = PreyFunction<void(ArkBreakableSignalReceiver *const _this, CArkBreakable &_breakable, const uint64_t _id)>(0x15CEB30);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkBreakableSignalReceiver *const _this, ArkSignalSystem::Package const &_package)>(0x15CEBF0);
};

