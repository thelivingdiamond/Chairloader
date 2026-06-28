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
class XmlNodeRef;

// ArkFlowNodeNpcRequestCorruptNpc
// Header:  Prey/GameDll/ark/ArkFlowNodeNpcRequestCorruptNpc.h
class ArkFlowNodeNpcRequestCorruptNpc : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		request = 0,
		targetEntityId = 1,
	};

	enum class EOutputPortIndex
	{
		out = 0,
	};

	virtual ~ArkFlowNodeNpcRequestCorruptNpc();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	ArkFlowNodeNpcRequestCorruptNpc(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcRequestCorruptNpc* const _this, SFlowNodeConfig& config)>(0x11B7500);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcRequestCorruptNpc* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x11B77F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcRequestCorruptNpc* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcRequestCorruptNpc* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcRequestCorruptNpc* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcRequestCorruptNpc* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcRequestCorruptNpc* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x11B78F0);
};
#endif // MOONCRASH
