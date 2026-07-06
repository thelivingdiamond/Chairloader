// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;
class TArkPostEffectValue;

// ArkFlowNode_PostEffect
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeposteffect.h
class ArkFlowNode_PostEffect : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eIN_Enable = 0,
		eIN_Disable = 1,
		eIN_PostEffect = 2,
	};

	enum EOutputs
	{
		eOUT_Enabled = 0,
		eOUT_Disabled = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNode_PostEffect(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_PostEffect* const _this, SFlowNodeConfig& _config)>(0x1527FD0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_PostEffect* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1528A00);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_PostEffect* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowNode_PostEffectParameter
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeposteffect.h
class ArkFlowNode_PostEffectParameter : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eIN_PostEffectParam = 0,
		eIN_Value = 1,
		eIN_Reset = 2,
	};

	enum EOutputs
	{
		eOUT_Value = 0,
		eOUT_Reset = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	void GetPortValueConverted(TArkPostEffectValue& _value, IFlowNode::SActivationInfo* _pActInfo, int _port) const { FGetPortValueConverted(this, _value, _pActInfo, _port); }
	void ActivateOutputConverted(IFlowNode::SActivationInfo* _pActInfo, int _port, TArkPostEffectValue _value) const { FActivateOutputConverted(this, _pActInfo, _port, _value); }

#if 0
	ArkFlowNode_PostEffectParameter(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_PostEffectParameter* const _this, SFlowNodeConfig& _config)>(0x15283F0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_PostEffectParameter* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1528B30);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_PostEffectParameter* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FGetPortValueConverted = PreyFunction<void(const ArkFlowNode_PostEffectParameter* const _this, TArkPostEffectValue& _value, IFlowNode::SActivationInfo* _pActInfo, int _port)>(0x1528840);
	static inline auto FActivateOutputConverted = PreyFunction<void(const ArkFlowNode_PostEffectParameter* const _this, IFlowNode::SActivationInfo* _pActInfo, int _port, TArkPostEffectValue _value)>(0x1527B10);
};
#endif // MOONCRASH
