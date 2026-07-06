// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowSignalReceiver
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowSignalReceiver.h
class ArkFlowSignalReceiver : public CFlowBaseNode<1>
{ // Size=88 (0x58)
public:
	enum class EArkInputs
	{
		signalId = 0,
	};

	enum class EArkOutputs
	{
		output = 0,
		value = 1,
	};

	IFlowNode::SActivationInfo m_actInfo;
	unsigned m_targetId;
	float m_value;
	bool m_bProcessSignal;
	uint64_t m_signalId;

	virtual ~ArkFlowSignalReceiver();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnSignalReception(unsigned _targetEntityId, uint64_t _signalId, float _value) { FOnSignalReception(this, _targetEntityId, _signalId, _value); }

#if 0
	ArkFlowSignalReceiver(IFlowNode::SActivationInfo* _arg0_);
	unsigned GetTargetId() const;
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowSignalReceiver* const _this, SFlowNodeConfig& _config)>(0x15FA1C0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowSignalReceiver* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15FA4B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowSignalReceiver* const _this, ICrySizer* _pS)>(0xE98E40);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowSignalReceiver* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15FA020);
	static inline auto FOnSignalReception = PreyFunction<void(ArkFlowSignalReceiver* const _this, unsigned _targetEntityId, uint64_t _signalId, float _value)>(0x15FA470);
};
#endif // MOONCRASH
