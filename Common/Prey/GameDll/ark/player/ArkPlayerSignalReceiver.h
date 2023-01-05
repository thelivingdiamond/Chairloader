// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkSignalDispositionModifier.h>
#include <Prey/GameDll/ark/signalsystem/ArkPackageSignalRamp.h>
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem

// ArkPlayerSignalReceiver
// Header:  Prey/GameDll/ark/player/ArkPlayerSignalReceiver.h
class ArkPlayerSignalReceiver : public ArkSignalSystem::Receiver
{ // Size=488 (0x1E8)
public:
	// ArkPlayerSignalReceiver::SignalAction
	// Header:  Prey/GameDll/ark/player/ArkPlayerSignalReceiver.h
	struct SignalAction
	{ // Size=16 (0x10)
		const CCryName m_statName;
		const ArkSignalEffect m_action;

	#if 0
		SignalAction(const char* _arg0_, const ArkSignalEffect _arg1_);
	#endif
	};

	std::unordered_map<uint64_t, std::vector<ArkPlayerSignalReceiver::SignalAction>> m_signalActions;
	std::array<bool,13> m_blocksAutoSave;
	ArkSignalSystem::PackageSignalRampContainer m_packageRamps;
	ArkSignalDispositionModifier m_dispositionModifier;
	float m_hitReactDamageThreshold;

	ArkPlayerSignalReceiver();
	virtual ~ArkPlayerSignalReceiver();
	virtual void Init(const unsigned& _entityId);
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);
	virtual ArkSignalSystem::PackageSignalRampContainer* GetPackageSignalRampContainer();

#if 0
	std::vector<uint64_t> GetSignalsForEffect(const ArkSignalEffect& _arg0_) const;
#endif

	static inline auto FArkPlayerSignalReceiverOv1 = PreyFunction<void(ArkPlayerSignalReceiver* const _this)>(0x1574590);
	static inline auto FInit = PreyFunction<void(ArkPlayerSignalReceiver* const _this, const unsigned& _entityId)>(0x1575650);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkPlayerSignalReceiver* const _this, const ArkSignalSystem::Package& _package)>(0x1575690);
	static inline auto FGetPackageSignalRampContainer = PreyFunction<ArkSignalSystem::PackageSignalRampContainer* (ArkPlayerSignalReceiver* const _this)>(0x10BD9E0);
};

