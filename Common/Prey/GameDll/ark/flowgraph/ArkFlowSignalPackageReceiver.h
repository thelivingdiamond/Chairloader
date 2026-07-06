// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowSignalPackageReceiver
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowSignalPackageReceiver.h
class ArkFlowSignalPackageReceiver : public CFlowBaseNode<1>
{ // Size=72 (0x48)
public:
	enum class EArkInputs
	{
		packageId = 0,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	IFlowNode::SActivationInfo m_actInfo;
	unsigned m_targetId;

	virtual ~ArkFlowSignalPackageReceiver();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnPackageReception(unsigned _targetEntityId, uint64_t _packageId) { FOnPackageReception(this, _targetEntityId, _packageId); }

#if 0
	ArkFlowSignalPackageReceiver(IFlowNode::SActivationInfo* _arg0_);
	unsigned GetTargetId() const;
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowSignalPackageReceiver* const _this, SFlowNodeConfig& _config)>(0x15F9AE0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowSignalPackageReceiver* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F9F60);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowSignalPackageReceiver* const _this, ICrySizer* _pS)>(0x35A360);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowSignalPackageReceiver* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15F9A00);
	static inline auto FOnPackageReception = PreyFunction<void(ArkFlowSignalPackageReceiver* const _this, unsigned _targetEntityId, uint64_t _packageId)>(0x15F9D60);
};
#endif // MOONCRASH
