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

// ArkFlowNodeNpcGodMode
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcGodMode.h
class ArkFlowNodeNpcGodMode : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum INPUTS
	{
		eInputPort_Enable = 0,
		eInputPort_Disable = 1,
	};

	enum OUTPUTS
	{
		eOutputPort_Out = 0,
	};

	virtual ~ArkFlowNodeNpcGodMode();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcGodMode(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcGodMode* const _this, SFlowNodeConfig& config)>(0x15E63D0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcGodMode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E66B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcGodMode* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcGodMode* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcGodMode* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcGodMode* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};

// ArkFlowNodeNpcGodModeAll
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcGodMode.h
class ArkFlowNodeNpcGodModeAll : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		enable = 0,
		disable = 1,
	};

	enum class EOutputPortIndex
	{
		out = 0,
	};

	virtual ~ArkFlowNodeNpcGodModeAll();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcGodModeAll(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcGodModeAll* const _this, SFlowNodeConfig& config)>(0x15E6080);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcGodModeAll* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E6360);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcGodModeAll* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcGodModeAll* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcGodModeAll* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcGodModeAll* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // MOONCRASH
