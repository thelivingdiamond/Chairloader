// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IGameRulesSystem.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/signalsystem/arksignalmanager.h>
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>
#include <_unknown/SignalReceiverConfig.h>

class ArkNpcPlayer;

// ArkNpcSignalReceiver
// Header:  Prey/GameDll/ark/npc/ArkNpcSignalReceiver.h
class ArkNpcSignalReceiver : public ArkSignalSystem::Receiver
{ // Size=64 (0x40)
public:
	// ArkNpcSignalReceiver::SignalAccumulator
	// Header:  Prey/GameDll/ark/npc/ArkNpcSignalReceiver.h
	struct SignalAccumulator
	{ // Size=32 (0x20)
		// ArkNpcSignalReceiver::SignalAccumulator::SAItem
		// Header:  Prey/GameDll/ark/npc/ArkNpcSignalReceiver.h
		struct SAItem
		{ // Size=176 (0xB0)
			HitInfo hitInfo;
			ArkSignalSystem::Package package;
			unsigned instigatorId;

		#if 0
			SAItem(const HitInfo& _arg0_, const ArkSignalSystem::Package& _arg1_, unsigned _arg2_);
		#endif
		};

		std::vector<ArkNpcSignalReceiver::SignalAccumulator::SAItem> hits;
		float accumulatedValue;

	#if 0
		SignalAccumulator();
	#endif
	};

	static inline auto s_SignalDataMapLibrary = PreyGlobal<std::unordered_map<unsigned int, SignalReceiverConfig>>(0x2D7CAA0);
	ArkNpcPlayer* m_pOwnerArkNpcPlayer;
	unsigned m_configIdCRC;
	ArkNpcSignalReceiver::SignalAccumulator m_shotgunSignalAccumulator;

	ArkNpcSignalReceiver(ArkNpcPlayer& _ownerNpc);
	virtual ~ArkNpcSignalReceiver();
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);
	void Initialize(const char* _pConfigFile) { FInitialize(this, _pConfigFile); }
	void Update() { FUpdate(this); }
	const SignalReceiverConfig* GetConfig() const { return FGetConfig(this); }
	static void Precache(const char* _pConfigFile) { FPrecache(_pConfigFile); }
	static void ClearPrecache() { FClearPrecache(); }
	static unsigned LoadConfig(const string& _configFile) { return FLoadConfig(_configFile); }
	static void LoadConfig_Recursive(const string& _configFile, std::vector<CCryNameCRC>& _loadedFiles, SignalReceiverConfig& _cachedConfig) { FLoadConfig_Recursive(_configFile, _loadedFiles, _cachedConfig); }
	bool ProcessDamage(const ArkSignalSystem::Package& _package) { return FProcessDamage(this, _package); }
	void ProcessDialog(const ArkSignalSystem::Package& _package, bool _bKilled) const { FProcessDialog(this, _package, _bKilled); }
	float GetDispositionFactor(const unsigned _instigatorId, const unsigned _ownerId, const std::vector<ArkSignalSystem::Package::Value>& _values) const { return FGetDispositionFactor(this, _instigatorId, _ownerId, _values); }
	bool DoDamage(const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package, const unsigned _instigatorId, const bool _bContainedDamagingSignal) const { return FDoDamage(this, _hitInfo, _package, _instigatorId, _bContainedDamagingSignal); }
	void ProcessMisc(const ArkSignalSystem::Package& _package) { FProcessMisc(this, _package); }

#if 0
	string GetCurrentDataMapID() const;
#endif

	static inline auto FArkNpcSignalReceiverOv1 = PreyFunction<void(ArkNpcSignalReceiver* const _this, ArkNpcPlayer& _ownerNpc)>(0x1637790);
	static inline auto FBitNotArkNpcSignalReceiver = PreyFunction<void(ArkNpcSignalReceiver* const _this)>(0x1637B70);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkNpcSignalReceiver* const _this, const ArkSignalSystem::Package& _package)>(0x1639830);
	static inline auto FInitialize = PreyFunction<void(ArkNpcSignalReceiver* const _this, const char* _pConfigFile)>(0x1638A40);
	static inline auto FUpdate = PreyFunction<void(ArkNpcSignalReceiver* const _this)>(0x163A460);
	static inline auto FGetConfig = PreyFunction<const SignalReceiverConfig* (const ArkNpcSignalReceiver* const _this)>(0x1638920);
	static inline auto FPrecache = PreyFunction<void(const char* _pConfigFile)>(0x1639890);
	static inline auto FClearPrecache = PreyFunction<void()>(0x1638000);
	static inline auto FLoadConfig = PreyFunction<unsigned(const string& _configFile)>(0x1638B20);
	static inline auto FLoadConfig_Recursive = PreyFunction<void(const string& _configFile, std::vector<CCryNameCRC>& _loadedFiles, SignalReceiverConfig& _cachedConfig)>(0x1638F60);
	static inline auto FProcessDamage = PreyFunction<bool(ArkNpcSignalReceiver* const _this, const ArkSignalSystem::Package& _package)>(0x1639950);
	static inline auto FProcessDialog = PreyFunction<void(const ArkNpcSignalReceiver* const _this, const ArkSignalSystem::Package& _package, bool _bKilled)>(0x1639ED0);
	static inline auto FGetDispositionFactor = PreyFunction<float(const ArkNpcSignalReceiver* const _this, const unsigned _instigatorId, const unsigned _ownerId, const std::vector<ArkSignalSystem::Package::Value>& _values)>(0x16389C0);
	static inline auto FDoDamage = PreyFunction<bool(const ArkNpcSignalReceiver* const _this, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package, const unsigned _instigatorId, const bool _bContainedDamagingSignal)>(0x1638080);
	static inline auto FProcessMisc = PreyFunction<void(ArkNpcSignalReceiver* const _this, const ArkSignalSystem::Package& _package)>(0x163A200);
};
#endif // MOONCRASH
