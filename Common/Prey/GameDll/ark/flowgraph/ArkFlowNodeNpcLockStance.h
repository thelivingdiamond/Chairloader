// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EStance;
class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeNpcLockStance
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcLockStance.h
class ArkFlowNodeNpcLockStance : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		k_lockInputPortIndex = 0,
		k_unlockInputPortIndex = 1,
		k_stanceNameInputPortIndex = 2,
	};

	enum class EOutputPortIndex
	{
		k_outOutputPortIndex = 0,
		k_errorOutputPortIndex = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _configuration);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo);
	EStance GetStanceIndexForName(const string& stanceName) { return FGetStanceIndexForName(this, stanceName); }
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcLockStance(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcLockStance* const _this, SFlowNodeConfig& _configuration)>(0x151B160);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcLockStance* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x151B5A0);
	static inline auto FGetStanceIndexForName = PreyFunction<EStance(ArkFlowNodeNpcLockStance* const _this, const string& stanceName)>(0x151B970);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcLockStance* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcLockStance* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcLockStance* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcLockStance* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // MOONCRASH
