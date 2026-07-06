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

// ArkFlowNodeNpcEncounterPatrolRequest
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcPatrolRequest.h
class ArkFlowNodeNpcEncounterPatrolRequest : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		k_profileNameInputPortIndex = 0,
		k_encounterNameInputPortIndex = 1,
		k_request = 2,
		k_speed = 3,
		k_patrol = 4,
		k_pointIndex = 5,
		k_overrideOffNavMesh = 6,
		k_cancel = 7,
	};

	enum class EOutputPortIndex
	{
		k_requested = 0,
		k_failed = 1,
		k_canceled = 2,
	};

	virtual ~ArkFlowNodeNpcEncounterPatrolRequest();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	bool SetPatrol(IFlowNode::SActivationInfo* _pActInfo, bool _bUpdateOnly) { return FSetPatrol(this, _pActInfo, _bUpdateOnly); }
	void ProcessCancel(IFlowNode::SActivationInfo* _pActInfo) { FProcessCancel(this, _pActInfo); }
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcEncounterPatrolRequest(IFlowNode::SActivationInfo* _arg0_);
	void ProcessRequest(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcEncounterPatrolRequest* const _this, SFlowNodeConfig& config)>(0x15E9ED0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcEncounterPatrolRequest* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15EA860);
	static inline auto FSetPatrol = PreyFunction<bool(ArkFlowNodeNpcEncounterPatrolRequest* const _this, IFlowNode::SActivationInfo* _pActInfo, bool _bUpdateOnly)>(0x15EAD40);
	static inline auto FProcessCancel = PreyFunction<void(ArkFlowNodeNpcEncounterPatrolRequest* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15EAB70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcEncounterPatrolRequest* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcEncounterPatrolRequest* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcEncounterPatrolRequest* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcEncounterPatrolRequest* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};

// ArkFlowNodeNpcPatrolRequest
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcPatrolRequest.h
class ArkFlowNodeNpcPatrolRequest : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		request = 0,
		speed = 1,
		patrol = 2,
		pointIndex = 3,
		overrideOffNavMesh = 4,
		cancel = 5,
	};

	enum class EOutputPortIndex
	{
		requested = 0,
		failed = 1,
		canceled = 2,
	};

	virtual ~ArkFlowNodeNpcPatrolRequest();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	bool SetPatrol(IFlowNode::SActivationInfo* _pActInfo, bool _bUpdateOnly) { return FSetPatrol(this, _pActInfo, _bUpdateOnly); }
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcPatrolRequest(IFlowNode::SActivationInfo* _arg0_);
	void ProcessRequest(IFlowNode::SActivationInfo* _arg0_);
	void ProcessCancel(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcPatrolRequest* const _this, SFlowNodeConfig& config)>(0x15E96B0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcPatrolRequest* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E9DC0);
	static inline auto FSetPatrol = PreyFunction<bool(ArkFlowNodeNpcPatrolRequest* const _this, IFlowNode::SActivationInfo* _pActInfo, bool _bUpdateOnly)>(0x15EB110);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcPatrolRequest* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcPatrolRequest* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcPatrolRequest* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcPatrolRequest* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // MOONCRASH
