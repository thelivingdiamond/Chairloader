// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryInput/IInput.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;
struct SInputEvent;

// CFlowYesNoGesture
// Header:  Prey/GameDll/nodes/g2flowyesnogesturenode.h
class CFlowYesNoGesture : public CFlowBaseNode<1>, public IInputEventListener
{ // Size=192 (0xC0)
public:
	enum EInputPorts
	{
		EIP_Enable = 0,
		EIP_Disable = 1,
		EIP_Timeout = 2,
		EIP_StickDeadThreshold = 3,
		EIP_StickExtremeThreshold = 4,
		EIP_MinExtremeDuration = 5,
		EIP_MaxExtremeDuration = 6,
		EIP_MinTotalDuration = 7,
		EIP_MaxTotalDuration = 8,
	};

	enum EOutputPorts
	{
		EOP_Yes = 0,
		EOP_No = 1,
		EOP_TimedOut = 2,
	};

	CTimeValue m_activationTime;
	int m_iLastStartDeadX;
	int m_iLastStartDeadY;
	int m_iFirstEndDeadX;
	int m_iFirstEndDeadY;
	int m_iMinStartX;
	int m_iMinEndX;
	int m_iMaxStartX;
	int m_iMaxEndX;
	int m_iMinStartY;
	int m_iMinEndY;
	int m_iMaxStartY;
	int m_iMaxEndY;
	std::vector<Vec2> m_stickHistory;
	std::vector<CTimeValue> m_stickHistoryTime;
	Vec2 m_stick;
	bool m_bActive;
	bool m_bFinished;
	IFlowNode::SActivationInfo m_actInfo;

	CFlowYesNoGesture(IFlowNode::SActivationInfo* pActInfo);
	virtual ~CFlowYesNoGesture();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual bool OnInputEvent(const SInputEvent& event);

#if 0
	void Finish();
	void NeedUpdate(bool _arg0_);
	void Register(bool _arg0_);
	void ResetX();
	void ResetY();
	void Reset();
	float GetDuration(int _arg0_, int _arg1_);
	void Update();
#endif

	static inline auto FCFlowYesNoGestureOv1 = PreyFunction<void(CFlowYesNoGesture* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18AF700);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowYesNoGesture* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18AEC70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowYesNoGesture* const _this, ICrySizer* s)>(0x18AECC0);
	static inline auto FSerialize = PreyFunction<void(CFlowYesNoGesture* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18AECE0);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowYesNoGesture* const _this, SFlowNodeConfig& config)>(0x18AED60);
	static inline auto FProcessEvent = PreyFunction<void(CFlowYesNoGesture* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x1333E90);
	static inline auto FOnInputEvent = PreyFunction<bool(IInputEventListener* const _this, const SInputEvent& event)>(0x13B0900);
};
#endif // MOONCRASH
