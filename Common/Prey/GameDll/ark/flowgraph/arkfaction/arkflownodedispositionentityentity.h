// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeClearDispositionEntityEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionentityentity.h
class ArkFlowNodeClearDispositionEntityEntity : public ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeClearDispositionEntityEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeClearDispositionEntityEntity(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeClearDispositionEntityEntity* const _this, SFlowNodeConfig& config)>(0x15B8060);
};

// ArkFlowNodeGetDispositionEntityEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionentityentity.h
class ArkFlowNodeGetDispositionEntityEntity : public ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeGetDispositionEntityEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeGetDispositionEntityEntity(IFlowNode::SActivationInfo* _arg0_);
	EArkDisposition OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeGetDispositionEntityEntity* const _this, SFlowNodeConfig& config)>(0x15B7D10);
};

// ArkFlowNodeSetDispositionEntityEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionentityentity.h
class ArkFlowNodeSetDispositionEntityEntity : public ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeSetDispositionEntityEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeSetDispositionEntityEntity(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const EArkDisposition _arg1_, const bool _arg2_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetDispositionEntityEntity* const _this, SFlowNodeConfig& config)>(0x15B7970);
};
#endif // MOONCRASH
