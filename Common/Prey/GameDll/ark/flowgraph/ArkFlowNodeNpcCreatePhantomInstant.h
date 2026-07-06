// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNodeNpcCreatePhantomInstant
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcCreatePhantomInstant.h
class ArkFlowNodeNpcCreatePhantomInstant : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		request = 0,
		corpseEntityId = 1,
		archetypeId = 2,
	};

	enum class EOutputPortIndex
	{
		requested = 0,
		completed = 1,
		failed = 2,
		spawnedNpcEntityIdOutputPortIndex = 3,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	bool ProcessRequest(IFlowNode::SActivationInfo* _pActInfo) { return FProcessRequest(this, _pActInfo); }

#if 0
	ArkFlowNodeNpcCreatePhantomInstant(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcCreatePhantomInstant* const _this, SFlowNodeConfig& config)>(0x11DE950);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcCreatePhantomInstant* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo)>(0x11DEDE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcCreatePhantomInstant* const _this, ICrySizer* _pSizer)>(0x455F00);
	static inline auto FProcessRequest = PreyFunction<bool(ArkFlowNodeNpcCreatePhantomInstant* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x11DEE90);
};
#endif // MOONCRASH
