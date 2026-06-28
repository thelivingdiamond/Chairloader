// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeClearRelationshipFactionEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionfactionentity.h
class ArkFlowNodeClearRelationshipFactionEntity : public ArkFlowNodeClearDispositionBase<ArkFlowNodeClearRelationshipFactionEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeClearRelationshipFactionEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeClearRelationshipFactionEntity(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeClearRelationshipFactionEntity* const _this, SFlowNodeConfig& config)>(0x15BA950);
};

// ArkFlowNodeGetDispositionFactionEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionfactionentity.h
class ArkFlowNodeGetDispositionFactionEntity : public ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeGetDispositionFactionEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeGetDispositionFactionEntity(IFlowNode::SActivationInfo* _arg0_);
	EArkDisposition OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeGetDispositionFactionEntity* const _this, SFlowNodeConfig& config)>(0x15BA630);
};

// ArkFlowNodeSetDispositionFactionEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionfactionentity.h
class ArkFlowNodeSetDispositionFactionEntity : public ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeSetDispositionFactionEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeSetDispositionFactionEntity(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const EArkDisposition _arg1_, const bool _arg2_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetDispositionFactionEntity* const _this, SFlowNodeConfig& config)>(0x15BA2D0);
};
#endif // MOONCRASH
