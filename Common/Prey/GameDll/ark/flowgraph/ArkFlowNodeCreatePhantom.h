// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <_unknown/IArkPsiPowerCreatePhantomListener.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeCreatePhantom
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeCreatePhantom.h
class ArkFlowNodeCreatePhantom : public CFlowBaseNode<1>, public IArkPsiPowerCreatePhantomListener
{ // Size=72 (0x48)
public:
	enum class EArkInputs
	{
		enabled = 0,
		corpseEntityId = 1,
	};

	enum class EArkOutputs
	{
		phantomEntityId = 0,
	};

	IFlowNode::SActivationInfo m_activationInfo;

	ArkFlowNodeCreatePhantom(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowNodeCreatePhantom();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnPhantomCreated(const unsigned _corpseEntityId, const unsigned _phantomEntityId);

	static inline auto FArkFlowNodeCreatePhantomOv1 = PreyFunction<void(ArkFlowNodeCreatePhantom* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x123F7B0);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeCreatePhantom* const _this, SFlowNodeConfig& _config)>(0x123F910);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeCreatePhantom* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x123FCE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeCreatePhantom* const _this, ICrySizer* _pS)>(0x35A360);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeCreatePhantom* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x123F880);
	static inline auto FOnPhantomCreated = PreyFunction<void(IArkPsiPowerCreatePhantomListener* const _this, const unsigned _corpseEntityId, const unsigned _phantomEntityId)>(0x123FBF0);
};
#endif // MOONCRASH
