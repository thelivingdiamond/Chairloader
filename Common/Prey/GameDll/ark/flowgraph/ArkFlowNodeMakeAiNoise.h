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

// ArkFlowNodeMakeAiNoise
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeMakeAiNoise.h
class ArkFlowNodeMakeAiNoise : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		type = 0,
		loudness = 1,
		location = 2,
		trigger = 3,
	};

	enum class EOutputPortIndex
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeMakeAiNoise(IFlowNode::SActivationInfo* _arg0_);
	static void DoMakeNoise(const Vec3& _arg0_, const uint64_t _arg1_, const uint64_t _arg2_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeMakeAiNoise* const _this, SFlowNodeConfig& _config)>(0x15148E0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeMakeAiNoise* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1514E60);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeMakeAiNoise* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeMakeAiNoise* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeMakeAiNoise* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeMakeAiNoise* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // MOONCRASH
