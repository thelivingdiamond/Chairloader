// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeRelativeToSun
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeRelativeToSun.h
class CArkFlowNodeRelativeToSun : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class InPorts
	{
		INP_Yawoffset = 0,
		INP_PitchOffset = 1,
		INP_RollOffset = 2,
	};

	enum class OutPorts
	{
		OUTP_Direction = 0,
	};

	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	CArkFlowNodeRelativeToSun(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeRelativeToSun* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1524A90);
	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeRelativeToSun* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x1333E90);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeRelativeToSun* const _this, SFlowNodeConfig& _config)>(0x1524AE0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeRelativeToSun* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1524EC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeRelativeToSun* const _this, ICrySizer* _pSizer)>(0x455F00);
};
#endif // MOONCRASH
