// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeSpawnProjectile
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeweapon.h
class CArkFlowNodeSpawnProjectile : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		owner = 1,
		position = 2,
		direction = 3,
		ammoArchetype = 4,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSpawnProjectile(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSpawnProjectile* const _this, SFlowNodeConfig& _rConfig)>(0x152BE60);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSpawnProjectile* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x152C440);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSpawnProjectile* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeSpawnProjectile* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x152BE10);
};
#endif // MOONCRASH
