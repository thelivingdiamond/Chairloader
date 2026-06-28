// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IEntity;
struct IFlowGraph;
struct IFlowNode;
struct SEntityEvent;
struct SFlowNodeConfig;

// CFlowEntityElectricConnector
// Header:  Prey/GameDll/nodes/g2flowentityelectricconnector.h
class CFlowEntityElectricConnector : public CFlowBaseNode<1>, private IEntityEventListener
{ // Size=96 (0x60)
public:
	enum EInputPorts
	{
		eIP_Emitter = 0,
		eIP_Receiver = 1,
		eIP_Disabled = 2,
	};

	enum EOutputPorts
	{
		eOP_Flow = 0,
		eOP_Last = 1,
	};

	IFlowNode::SActivationInfo m_actInfo;
	uint16_t m_nodeID;
	IFlowGraph* m_pGraph;
	unsigned m_entityId;
	int m_flow;

	virtual ~CFlowEntityElectricConnector();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	const char* GetConnectorTypeLinkName(int flow) { return FGetConnectorTypeLinkName(this, flow); }
	void UnmarkElectricConnector(unsigned eid) { FUnmarkElectricConnector(this, eid); }
	void MarkElectricConnector(unsigned eid) { FMarkElectricConnector(this, eid); }
	virtual void OnEntityEvent(IEntity* pEntity, SEntityEvent& event);
	void UnregisterEvents() { FUnregisterEvents(this); }

#if 0
	CFlowEntityElectricConnector(IFlowNode::SActivationInfo* _arg0_);
	void RegisterEvents();
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowEntityElectricConnector* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18AD880);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowEntityElectricConnector* const _this, ICrySizer* s)>(0xA55F00);
	static inline auto FSerialize = PreyFunction<void(CFlowEntityElectricConnector* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18AD910);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowEntityElectricConnector* const _this, SFlowNodeConfig& config)>(0x18AD990);
	static inline auto FProcessEvent = PreyFunction<void(CFlowEntityElectricConnector* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18ADD70);
	static inline auto FGetConnectorTypeLinkName = PreyFunction<const char* (CFlowEntityElectricConnector* const _this, int flow)>(0x18AE150);
	static inline auto FUnmarkElectricConnector = PreyFunction<void(CFlowEntityElectricConnector* const _this, unsigned eid)>(0x18AE1D0);
	static inline auto FMarkElectricConnector = PreyFunction<void(CFlowEntityElectricConnector* const _this, unsigned eid)>(0x18AE180);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* pEntity, SEntityEvent& event)>(0x18ADF30);
	static inline auto FUnregisterEvents = PreyFunction<void(CFlowEntityElectricConnector* const _this)>(0x18AE2C0);
};
#endif // MOONCRASH
