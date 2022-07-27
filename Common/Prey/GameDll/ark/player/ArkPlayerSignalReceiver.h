// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkSignalDispositionModifier.h>
#include <Prey/GameDll/ark/signalsystem/ArkPackageSignalRamp.h>
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerSignalReceiver.h
class ArkPlayerSignalReceiver : public ArkSignalSystem::Receiver // Id=80138A4 Size=488
{
public:
	struct SignalAction // Id=80138A5 Size=16
	{
		CCryName m_statName;
		ArkSignalEffect m_action;
	};

	std::unordered_map<unsigned __int64,std::vector<ArkPlayerSignalReceiver::SignalAction>> m_signalActions;
	std::array<bool,13> m_blocksAutoSave;
	ArkSignalSystem::PackageSignalRampContainer m_packageRamps;
	ArkSignalDispositionModifier m_dispositionModifier;
	float m_hitReactDamageThreshold;
	
	ArkPlayerSignalReceiver();
	virtual void Init(const unsigned &_entityId);
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	virtual ArkSignalSystem::PackageSignalRampContainer *GetPackageSignalRampContainer();
	
#if 0
	std::vector<unsigned __int64> GetSignalsForEffect(ArkSignalEffect const &arg0) const;
#endif
	
	static inline auto FInit = PreyFunction<void(ArkPlayerSignalReceiver *const _this, const unsigned &_entityId)>(0x1575650);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkPlayerSignalReceiver *const _this, ArkSignalSystem::Package const &_package)>(0x1575690);
	static inline auto FGetPackageSignalRampContainer = PreyFunction<ArkSignalSystem::PackageSignalRampContainer *(ArkPlayerSignalReceiver *const _this)>(0x10BD9E0);
};

