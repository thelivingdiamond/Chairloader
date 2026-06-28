// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeAddEncounter
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeencounters.h
class CArkFlowNodeAddEncounter : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputPorts
	{
		profile_name = 0,
		encounter_name = 1,
	};

	enum class EArkOutputPorts
	{
		out_encounter_name = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CArkFlowNodeAddEncounter(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeAddEncounter* const _this, SFlowNodeConfig& config)>(0x131EEC0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeAddEncounter* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x131F290);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeAddEncounter* const _this, ICrySizer* s)>(0x455F00);
};

// CArkFlowNodeAddEncounterProfile
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeencounters.h
class CArkFlowNodeAddEncounterProfile : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputPorts
	{
		add_profile = 0,
		profile_name = 1,
		target_pop_init = 2,
		enable_debug_log = 3,
	};

	enum class EArkOutputPorts
	{
		out_profile_name = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CArkFlowNodeAddEncounterProfile(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeAddEncounterProfile* const _this, SFlowNodeConfig& config)>(0x131E620);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeAddEncounterProfile* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x131EB40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeAddEncounterProfile* const _this, ICrySizer* s)>(0x455F00);
};

// CArkFlowNodeAddEncounterSpawnInfo
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeencounters.h
class CArkFlowNodeAddEncounterSpawnInfo : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputPorts
	{
		profile_name = 0,
		encounter_name = 1,
		spawn_track = 2,
		doomclock_level = 3,
		spawn_chance_weight = 4,
	};

	enum class EArkOutputPorts
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CArkFlowNodeAddEncounterSpawnInfo(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeAddEncounterSpawnInfo* const _this, SFlowNodeConfig& config)>(0x131F4E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeAddEncounterSpawnInfo* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x131FB70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeAddEncounterSpawnInfo* const _this, ICrySizer* s)>(0x455F00);
};

// CArkFlowNodeAddToEncounter
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeencounters.h
class CArkFlowNodeAddToEncounter : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		k_addInputPortIndex = 0,
		k_profileNameInputPortIndex = 1,
		k_encounterNameInputPortIndex = 2,
	};

	enum class EOutputPortIndex
	{
		k_outInputPortIndex = 0,
		k_errorInputPortIndex = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _configuration);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	CArkFlowNodeAddToEncounter(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeAddToEncounter* const _this, SFlowNodeConfig& _configuration)>(0x1320D00);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeAddToEncounter* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo)>(0x13211C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeAddToEncounter* const _this, ICrySizer* _pSizer)>(0x455F00);
};

// CArkFlowNodeEliminateCurrentPopulation
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeencounters.h
class CArkFlowNodeEliminateCurrentPopulation : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputPorts
	{
		in = 0,
	};

	enum class EArkOutputPorts
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CArkFlowNodeEliminateCurrentPopulation(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeEliminateCurrentPopulation* const _this, SFlowNodeConfig& config)>(0x13206C0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeEliminateCurrentPopulation* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x13208D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeEliminateCurrentPopulation* const _this, ICrySizer* s)>(0x455F00);
};

// CArkFlowNodeRefreshCurrentPopulation
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeencounters.h
class CArkFlowNodeRefreshCurrentPopulation : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputPorts
	{
		in = 0,
	};

	enum class EArkOutputPorts
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CArkFlowNodeRefreshCurrentPopulation(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeRefreshCurrentPopulation* const _this, SFlowNodeConfig& config)>(0x1320450);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeRefreshCurrentPopulation* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x1320660);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeRefreshCurrentPopulation* const _this, ICrySizer* s)>(0x455F00);
};

// CArkFlowNodeSetEncounterProfile
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeencounters.h
class CArkFlowNodeSetEncounterProfile : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputPorts
	{
		in = 0,
		profile_name = 1,
		enable_debug_log = 2,
	};

	enum class EArkOutputPorts
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CArkFlowNodeSetEncounterProfile(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetEncounterProfile* const _this, SFlowNodeConfig& config)>(0x131FD70);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetEncounterProfile* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x13201A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetEncounterProfile* const _this, ICrySizer* s)>(0x455F00);
};

// CArkFlowNodeSetSpawnerActiveForEncounters
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeencounters.h
class CArkFlowNodeSetSpawnerActiveForEncounters : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputPorts
	{
		in = 0,
		set_active = 1,
	};

	enum class EArkOutputPorts
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CArkFlowNodeSetSpawnerActiveForEncounters(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetSpawnerActiveForEncounters* const _this, SFlowNodeConfig& config)>(0x1320930);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetSpawnerActiveForEncounters* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x1320C20);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetSpawnerActiveForEncounters* const _this, ICrySizer* s)>(0x455F00);
};
#endif // MOONCRASH
