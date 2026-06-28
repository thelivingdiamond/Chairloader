// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeClearDispositionFactionEntitiesToEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodefactionentitiestoentity.h
class ArkFlowNodeClearDispositionFactionEntitiesToEntity : public ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeClearDispositionFactionEntitiesToEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeClearDispositionFactionEntitiesToEntity(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeClearDispositionFactionEntitiesToEntity* const _this, SFlowNodeConfig& config)>(0x15B8990);
};

// ArkFlowNodeSetDispositionFactionEntitiesToEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodefactionentitiestoentity.h
class ArkFlowNodeSetDispositionFactionEntitiesToEntity : public ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeSetDispositionFactionEntitiesToEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeSetDispositionFactionEntitiesToEntity(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const EArkDisposition _arg1_, const bool _arg2_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetDispositionFactionEntitiesToEntity* const _this, SFlowNodeConfig& config)>(0x15B85E0);
};
#endif // MOONCRASH
