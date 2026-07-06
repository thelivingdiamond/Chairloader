// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
class ICrySizer;
class XmlNodeRef;

namespace ArkFactionFlow
{

// ArkFactionFlow::ArkFlowNodeFactionBase
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkfactionflowgraphcommon.h
class ArkFlowNodeFactionBase : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EBaseInput
	{
		activate = 0,
		from = 1,
		to = 2,
		last = 3,
	};

	enum class EBaseOutput
	{
		out = 0,
	};

	virtual ~ArkFlowNodeFactionBase();
	unsigned GetPortFaction(IFlowNode::SActivationInfo* _pActInfo, int _port) { return FGetPortFaction(this, _pActInfo, _port); }
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeFactionBase();
	EArkDisposition GetPortDisposition(IFlowNode::SActivationInfo* _arg0_, int _arg1_);
#endif

	static inline auto FGetPortFaction = PreyFunction<unsigned(ArkFactionFlow::ArkFlowNodeFactionBase* const _this, IFlowNode::SActivationInfo* _pActInfo, int _port)>(0x15B4710);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFactionFlow::ArkFlowNodeFactionBase* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFactionFlow::ArkFlowNodeFactionBase* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFactionFlow::ArkFlowNodeFactionBase* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFactionFlow::ArkFlowNodeFactionBase* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};


} // namespace ArkFactionFlow
#endif // MOONCRASH
