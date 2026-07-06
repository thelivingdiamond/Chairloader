// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeNpcPoltergeistThrow
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcPoltergeistThrow.h
class ArkFlowNodeNpcPoltergeistThrow : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		request = 0,
		itemID = 1,
		targetID = 2,
		cancel = 3,
	};

	enum class EOutputPortIndex
	{
		out = 0,
		requestSucceeded = 1,
		failed = 2,
		canceled = 3,
	};

	virtual ~ArkFlowNodeNpcPoltergeistThrow();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	bool ProcessRequest(IFlowNode::SActivationInfo* _pActInfo) { return FProcessRequest(this, _pActInfo); }
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcPoltergeistThrow(IFlowNode::SActivationInfo* _arg0_);
	bool ProcessCancel(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcPoltergeistThrow* const _this, SFlowNodeConfig& config)>(0x1247110);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcPoltergeistThrow* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1247630);
	static inline auto FProcessRequest = PreyFunction<bool(ArkFlowNodeNpcPoltergeistThrow* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x1247740);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcPoltergeistThrow* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcPoltergeistThrow* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcPoltergeistThrow* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcPoltergeistThrow* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // MOONCRASH
