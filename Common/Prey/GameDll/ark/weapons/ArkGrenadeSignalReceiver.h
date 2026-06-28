// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class CArkProjectileGrenade;

// Header: FromCpp
// Prey/GameDll/ark/weapons/ArkGrenadeSignalReceiver.h
class ArkGrenadeSignalReceiver : public ArkSignalSystem::Receiver // Id=801601E Size=32
{
public:
	CArkProjectileGrenade *m_pOwnerGrenade;
	uint64_t m_damageSignalGroup;
	
	virtual ~ArkGrenadeSignalReceiver();
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	void SetDamageSignalGroup(const uint64_t _signalGroupId) { FSetDamageSignalGroup(this,_signalGroupId); }
	void RegisterForSignals(const bool _bRegister) { FRegisterForSignals(this,_bRegister); }
	
	static inline auto FBitNotArkGrenadeSignalReceiver = PreyFunction<void(ArkGrenadeSignalReceiver *const _this)>(0x16433B0);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkGrenadeSignalReceiver *const _this, ArkSignalSystem::Package const &_package)>(0x1643430);
	static inline auto FSetDamageSignalGroup = PreyFunction<void(ArkGrenadeSignalReceiver *const _this, const uint64_t _signalGroupId)>(0x1447A90);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkGrenadeSignalReceiver *const _this, const bool _bRegister)>(0x16435A0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class CArkProjectileGrenade;

// ArkGrenadeSignalReceiver
// Header:  Prey/GameDll/ark/weapons/ArkGrenadeSignalReceiver.h
class ArkGrenadeSignalReceiver : public ArkSignalSystem::Receiver
{ // Size=32 (0x20)
public:
	CArkProjectileGrenade* m_pOwnerGrenade;
	uint64_t m_damageSignalGroup;

	virtual ~ArkGrenadeSignalReceiver();
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);
	void SetDamageSignalGroup(const uint64_t _signalGroupId) { FSetDamageSignalGroup(this, _signalGroupId); }
	void RegisterForSignals(const bool _bRegister) { FRegisterForSignals(this, _bRegister); }

#if 0
	ArkGrenadeSignalReceiver(CArkProjectileGrenade& _arg0_);
#endif

	static inline auto FBitNotArkGrenadeSignalReceiver = PreyFunction<void(ArkGrenadeSignalReceiver* const _this)>(0x1767180);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkGrenadeSignalReceiver* const _this, const ArkSignalSystem::Package& _package)>(0x1767200);
	static inline auto FSetDamageSignalGroup = PreyFunction<void(ArkGrenadeSignalReceiver* const _this, const uint64_t _signalGroupId)>(0x155D1C0);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkGrenadeSignalReceiver* const _this, const bool _bRegister)>(0x1767390);
};
#endif // !MOONCRASH
