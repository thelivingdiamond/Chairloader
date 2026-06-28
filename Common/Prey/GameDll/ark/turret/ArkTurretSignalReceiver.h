// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class ArkTurret;

// Header: FromCpp
// Prey/GameDll/ark/turret/ArkTurretSignalReceiver.h
class ArkTurretSignalReceiver : public ArkSignalSystem::Receiver // Id=80152EB Size=72
{
public:
	ArkTurret *const m_pTurret;
	uint64_t m_damageSignalGroup;
	uint64_t m_stunSignalGroup;
	uint64_t m_electricalSignalGroup;
	uint64_t m_mindControlSignalId;
	uint64_t m_gloosignalId;
	int m_shieldJointId;
	float m_shieldDamageScale;
	
	ArkTurretSignalReceiver(ArkTurret &_turret);
	virtual ~ArkTurretSignalReceiver();
	void LoadScriptVariables() { FLoadScriptVariables(this); }
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	void ProcessDamage(ArkSignalSystem::Package const &_package) const { FProcessDamage(this,_package); }
	void SetSignalGroupId(uint64_t &_memberVariable, const uint64_t _newValue) { FSetSignalGroupId(this,_memberVariable,_newValue); }
	
#if 0
	void ProcessMachineMind(const uint64_t &arg0, const float arg1) const;
	void ProcessStun(const uint64_t &arg0, const float arg1) const;
	void ProcessElectrical(const uint64_t &arg0, const float arg1) const;
	void ProcessGloo(const uint64_t &arg0, const float arg1) const;
#endif
	
	static inline auto FBitNotArkTurretSignalReceiver = PreyFunction<void(ArkTurretSignalReceiver *const _this)>(0x15EA940);
	static inline auto FLoadScriptVariables = PreyFunction<void(ArkTurretSignalReceiver *const _this)>(0x15EAB80);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkTurretSignalReceiver *const _this, ArkSignalSystem::Package const &_package)>(0x15EB1B0);
	static inline auto FProcessDamage = PreyFunction<void(ArkTurretSignalReceiver const *const _this, ArkSignalSystem::Package const &_package)>(0x15EB380);
	static inline auto FSetSignalGroupId = PreyFunction<void(ArkTurretSignalReceiver *const _this, uint64_t &_memberVariable, const uint64_t _newValue)>(0x15EB5F0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class ArkTurret;
struct HitInfo;

// ArkTurretSignalReceiver
// Header:  Prey/GameDll/ark/turret/ArkTurretSignalReceiver.h
class ArkTurretSignalReceiver : public ArkSignalSystem::Receiver
{ // Size=72 (0x48)
public:
	ArkTurret* const m_pTurret;
	uint64_t m_damageSignalGroup;
	uint64_t m_stunSignalGroup;
	uint64_t m_electricalSignalGroup;
	uint64_t m_mindControlSignalId;
	uint64_t m_gloosignalId;
	int m_shieldJointId;
	float m_shieldDamageScale;

	ArkTurretSignalReceiver(ArkTurret& _turret);
	virtual ~ArkTurretSignalReceiver();
	void LoadScriptVariables() { FLoadScriptVariables(this); }
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);
	void ProcessDamage(const ArkSignalSystem::Package& _package) const { FProcessDamage(this, _package); }
	void SetSignalGroupId(uint64_t& _memberVariable, const uint64_t _newValue) { FSetSignalGroupId(this, _memberVariable, _newValue); }

#if 0
	void ProcessMachineMind(const uint64_t& _arg0_, const float _arg1_) const;
	void ProcessStun(const uint64_t& _arg0_, const float _arg1_) const;
	void ProcessElectrical(const uint64_t& _arg0_, const float _arg1_) const;
	void ProcessGloo(const uint64_t& _arg0_, const float _arg1_, const HitInfo* _arg2_) const;
#endif

	static inline auto FArkTurretSignalReceiverOv1 = PreyFunction<void(ArkTurretSignalReceiver* const _this, ArkTurret& _turret)>(0x170C900);
	static inline auto FBitNotArkTurretSignalReceiver = PreyFunction<void(ArkTurretSignalReceiver* const _this)>(0x170C950);
	static inline auto FLoadScriptVariables = PreyFunction<void(ArkTurretSignalReceiver* const _this)>(0x170CB90);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkTurretSignalReceiver* const _this, const ArkSignalSystem::Package& _package)>(0x170D1C0);
	static inline auto FProcessDamage = PreyFunction<void(const ArkTurretSignalReceiver* const _this, const ArkSignalSystem::Package& _package)>(0x170D3D0);
	static inline auto FSetSignalGroupId = PreyFunction<void(ArkTurretSignalReceiver* const _this, uint64_t& _memberVariable, const uint64_t _newValue)>(0x170D6C0);
};
#endif // !MOONCRASH
