// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSignalDispositionModifier.h>
#include <Prey/GameDll/ark/npc/SignalReceiverData.h>

// SignalReceiverConfig
// Header:  _unknown/SignalReceiverConfig.h
struct SignalReceiverConfig
{ // Size=680 (0x2A8)
	// SignalReceiverConfig::SignalAccumulatorConfig
	// Header:  _unknown/SignalReceiverConfig.h
	struct SignalAccumulatorConfig
	{ // Size=16 (0x10)
		uint64_t signalId;
		float threshold;

	#if 0
		SignalAccumulatorConfig();
	#endif
	};

	string m_configID;
	std::map<uint64_t, SignalReceiverData> m_dataMap;
	ArkSignalDispositionModifier m_dispositionModifier;
	ArkSignalDispositionModifier m_playerDispositionModifier;
	SignalReceiverConfig::SignalAccumulatorConfig m_shotgunAccumulatorConfig;

#if 0
	SignalReceiverConfig();
	SignalReceiverConfig(const string& _arg0_);
#endif
};

