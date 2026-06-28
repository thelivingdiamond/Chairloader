// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodePlayerMimicState
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodePlayerMimicState.h
class CArkFlowNodePlayerMimicState : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class ArkInputPort
	{
		Check = 0,
		ArchetypeName = 1,
	};

	enum class ArkOutputPort
	{
		Out = 0,
		True = 1,
		False = 2,
		TargetedEntityId = 3,
		SpawnedEntityId = 4,
	};

	virtual ~CArkFlowNodePlayerMimicState();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodePlayerMimicState(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodePlayerMimicState* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodePlayerMimicState* const _this, SFlowNodeConfig& _config)>(0x15EEBD0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodePlayerMimicState* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15EEFB0);
};
#endif // MOONCRASH
