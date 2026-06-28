// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CPressureWaveNode
// Header:  Prey/GameDll/nodes/PressureWaveNode.h
class CPressureWaveNode : public CFlowBaseNode<1>
{ // Size=120 (0x78)
public:
	enum INPUTS
	{
		EIP_Trigger = 0,
		EIP_Normal = 1,
		EIP_Speed = 2,
		EIP_Force = 3,
		EIP_Amplitude = 4,
		EIP_Decay = 5,
		EIP_RangeMin = 6,
		EIP_RangeMax = 7,
		EIP_Duration = 8,
		EIP_Stop = 9,
	};

	enum OUTPUTS
	{
		EOP_Time = 0,
	};

	IFlowNode::SActivationInfo m_actInfo;
	CTimeValue m_startTime;
	CTimeValue m_currentTime;
	bool m_triggered;
	Vec3 m_effectCenter;
	std::vector<unsigned int> m_entitiesAffected;

	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual ~CPressureWaveNode();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	void Update(float elapsed) { FUpdate(this, elapsed); }

#if 0
	CPressureWaveNode(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CPressureWaveNode* const _this, ICrySizer* s)>(0x159E480);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CPressureWaveNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18B8080);
	static inline auto FSerialize = PreyFunction<void(CPressureWaveNode* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18B7330);
	static inline auto FGetConfiguration = PreyFunction<void(CPressureWaveNode* const _this, SFlowNodeConfig& config)>(0x18B7450);
	static inline auto FProcessEvent = PreyFunction<void(CPressureWaveNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18B7E70);
	static inline auto FUpdate = PreyFunction<void(CPressureWaveNode* const _this, float elapsed)>(0x18B8210);
};
#endif // MOONCRASH
