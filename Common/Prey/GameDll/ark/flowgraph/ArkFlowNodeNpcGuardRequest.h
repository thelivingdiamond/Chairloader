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

// ArkFlowNodeNpcGuardRequest
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcGuardRequest.h
class ArkFlowNodeNpcGuardRequest : public CFlowBaseNode<1>
{ // Size=88 (0x58)
public:
	enum class EInputPortIndex
	{
		request = 0,
		cancel = 1,
		position = 2,
		rotation = 3,
	};

	enum class EOutputPortIndex
	{
		out = 0,
		requested = 1,
		canceled = 2,
		success = 3,
	};

	// ArkFlowNodeNpcGuardRequest::NpcRequest
	// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcGuardRequest.h
	struct NpcRequest
	{ // Size=28 (0x1C)
		unsigned m_id;
		Vec3 m_pos;
		Ang3 m_rot;

	#if 0
		NpcRequest(unsigned _arg0_, const Vec3& _arg1_, const Ang3& _arg2_);
		NpcRequest();
	#endif
	};

	std::vector<ArkFlowNodeNpcGuardRequest::NpcRequest> m_requests;
	IFlowNode::SActivationInfo m_prevActivationInfo;

	virtual ~ArkFlowNodeNpcGuardRequest();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	void StartGuard(const IFlowNode::SActivationInfo& _actInfo) { FStartGuard(this, _actInfo); }
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize _ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcGuardRequest(IFlowNode::SActivationInfo* _arg0_);
	void StopGuard(const IFlowNode::SActivationInfo& _arg0_);
	void OnGuardInPosition();
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcGuardRequest* const _this, SFlowNodeConfig& _config)>(0x12441E0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcGuardRequest* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1244700);
	static inline auto FStartGuard = PreyFunction<void(ArkFlowNodeNpcGuardRequest* const _this, const IFlowNode::SActivationInfo& _actInfo)>(0x1244EE0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcGuardRequest* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1244B80);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcGuardRequest* const _this, ICrySizer* _s)>(0xE98E40);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcGuardRequest* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcGuardRequest* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize _ser)>(0x1244880);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcGuardRequest* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1244A80);
};
#endif // MOONCRASH
