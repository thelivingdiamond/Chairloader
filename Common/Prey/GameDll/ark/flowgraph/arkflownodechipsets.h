// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeChipsetInstalled
// Header:  Prey/GameDll/ark/flowgraph/arkflownodechipsets.h
class ArkFlowNodeChipsetInstalled : public CFlowBaseNode<1>
{ // Size=72 (0x48)
public:
	enum class EArkInputs
	{
		active = 0,
		trigger = 1,
		archetype = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
		falseTrigger = 1,
		trueTrigger = 2,
	};

	IFlowNode::SActivationInfo m_activationInfo;
	std::pair<bool, bool> m_bFireOnPDAClose;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowNodeChipsetInstalled*>>(0x2D41AD0);

	ArkFlowNodeChipsetInstalled(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowNodeChipsetInstalled();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyChipsetInstalled(uint64_t _archetypeId, bool _bInstalled) { FNotifyChipsetInstalled(_archetypeId, _bInstalled); }
	static void NotifyPDAClosed() { FNotifyPDAClosed(); }

#if 0
	void OnChipsetInstallChange(uint64_t _arg0_, bool _arg1_);
	void OnPDAClosed();
#endif

	static inline auto FArkFlowNodeChipsetInstalledOv1 = PreyFunction<void(ArkFlowNodeChipsetInstalled* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x123EDA0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeChipsetInstalled* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x123EEC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeChipsetInstalled* const _this, ICrySizer* _pS)>(0x35A360);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeChipsetInstalled* const _this, SFlowNodeConfig& _config)>(0x123EF10);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeChipsetInstalled* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x123F650);
	static inline auto FNotifyChipsetInstalled = PreyFunction<void(uint64_t _archetypeId, bool _bInstalled)>(0x123F370);
	static inline auto FNotifyPDAClosed = PreyFunction<void()>(0x123F570);
};
#endif // MOONCRASH
