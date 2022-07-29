// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class CArkProjectileGoo;

// Header: FromCpp
// Prey/GameDll/ark/weapons/ArkGooSignalReceiver.h
class ArkGooSignalReceiver : public ArkSignalSystem::Receiver // Id=8016043 Size=32
{
public:
	CArkProjectileGoo *m_pOwnerGoo;
	uint64_t m_damageSignalGroup;
	
	virtual ~ArkGooSignalReceiver();
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	void SetDamageSignalGroup(const uint64_t _signalGroupId) { FSetDamageSignalGroup(this,_signalGroupId); }
	
	static inline auto FBitNotArkGooSignalReceiver = PreyFunction<void(ArkGooSignalReceiver *const _this)>(0x1643030);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkGooSignalReceiver *const _this, ArkSignalSystem::Package const &_package)>(0x16430B0);
	static inline auto FSetDamageSignalGroup = PreyFunction<void(ArkGooSignalReceiver *const _this, const uint64_t _signalGroupId)>(0x1643200);
};

