// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

struct SFlowNodeConfig;

// ArkFlowNodeEndHostilityEntityEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeendhostility.h
class ArkFlowNodeEndHostilityEntityEntity : public ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeEndHostilityEntityEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeEndHostilityEntityEntity(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeEndHostilityEntityEntity* const _this, SFlowNodeConfig& config)>(0x15B42B0);
};

// ArkFlowNodeEndHostilityEntityFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeendhostility.h
class ArkFlowNodeEndHostilityEntityFaction : public ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeEndHostilityEntityFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeEndHostilityEntityFaction(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeEndHostilityEntityFaction* const _this, SFlowNodeConfig& config)>(0x15B3F20);
};

// ArkFlowNodeEndHostilityFactionEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeendhostility.h
class ArkFlowNodeEndHostilityFactionEntity : public ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeEndHostilityFactionEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeEndHostilityFactionEntity(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeEndHostilityFactionEntity* const _this, SFlowNodeConfig& config)>(0x15B3BC0);
};

// ArkFlowNodeEndHostilityFactionFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeendhostility.h
class ArkFlowNodeEndHostilityFactionFaction : public ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeEndHostilityFactionFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeEndHostilityFactionFaction(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeEndHostilityFactionFaction* const _this, SFlowNodeConfig& config)>(0x15B3860);
};
#endif // MOONCRASH
