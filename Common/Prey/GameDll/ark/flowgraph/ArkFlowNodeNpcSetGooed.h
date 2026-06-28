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

// CArkFlowNodeNpcSetGooed
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcSetGooed.h
class CArkFlowNodeNpcSetGooed : public CFlowBaseNode<1>
{ // Size=32 (0x20)
public:
	enum class InPorts
	{
		setGooed = 0,
		clearGooed = 1,
		refreshGooed = 2,
		immediate = 3,
		gooDuration = 4,
		gooSlowDuration = 5,
	};

	enum class OutPorts
	{
		out = 0,
		cleared = 1,
		elapsedDuration = 2,
	};

	float m_slowTimer;
	float m_frozenTimer;
	float m_gooAccumulationPerSecondForSlow;

	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	void UpdateGlooSignal(IFlowNode::SActivationInfo* _pActInfo) { FUpdateGlooSignal(this, _pActInfo); }
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActivationInfo);

#if 0
	CArkFlowNodeNpcSetGooed(IFlowNode::SActivationInfo* _arg0_);
	void ResetTimers();
#endif

	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeNpcSetGooed* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x151F0B0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeNpcSetGooed* const _this, SFlowNodeConfig& _config)>(0x151F120);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeNpcSetGooed* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x151F7E0);
	static inline auto FUpdateGlooSignal = PreyFunction<void(CArkFlowNodeNpcSetGooed* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x151FB40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeNpcSetGooed* const _this, ICrySizer* _pSizer)>(0x189F2B0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeNpcSetGooed* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActivationInfo)>(0x151FAF0);
};
#endif // MOONCRASH
