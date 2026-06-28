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

// ArkFlowNodeNpcEncounterIgnoreDistract
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcIgnoreDistract.h
class ArkFlowNodeNpcEncounterIgnoreDistract : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		k_profileNameInputPortIndex = 0,
		k_encounterNameInputPortIndex = 1,
		k_ignore = 2,
		k_clear = 3,
		k_cancelCurrent = 4,
	};

	enum class EOutputPortIndex
	{
		k_out = 0,
	};

	virtual ~ArkFlowNodeNpcEncounterIgnoreDistract();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcEncounterIgnoreDistract(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcEncounterIgnoreDistract* const _this, SFlowNodeConfig& config)>(0x1519B40);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcEncounterIgnoreDistract* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x151A180);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcEncounterIgnoreDistract* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcEncounterIgnoreDistract* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcEncounterIgnoreDistract* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcEncounterIgnoreDistract* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};

// ArkFlowNodeNpcIgnoreDistract
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcIgnoreDistract.h
class ArkFlowNodeNpcIgnoreDistract : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		ignore = 0,
		clear = 1,
		cancelCurrent = 2,
	};

	enum class EOutputPortIndex
	{
		out = 0,
	};

	virtual ~ArkFlowNodeNpcIgnoreDistract();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcIgnoreDistract(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcIgnoreDistract* const _this, SFlowNodeConfig& config)>(0x15196A0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcIgnoreDistract* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x1519A60);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcIgnoreDistract* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcIgnoreDistract* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcIgnoreDistract* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcIgnoreDistract* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // MOONCRASH
