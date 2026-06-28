// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkOverlappingGooHandler.h>
#include <Prey/GameDll/ark/weapons/IArkOverlappingGooListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeOverlappingGooHandler
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeOverlappingGooHandler.h
class CArkFlowNodeOverlappingGooHandler : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EInPorts
	{
		IN_START = 0,
		IN_STOP = 1,
	};

	enum class EOutPorts
	{
		OUT_STARTED = 0,
		OUT_STOPPED = 1,
	};

	// CArkFlowNodeOverlappingGooHandler::CArkOverlappingGooListener
	// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeOverlappingGooHandler.h
	class CArkOverlappingGooListener : public IArkOverlappingGooListener
	{ // Size=8 (0x8)
	public:
		virtual void OnGooStatusChanged(bool _bHasGoo);

	#if 0
		CArkOverlappingGooListener();
	#endif

		static inline auto FOnGooStatusChanged = PreyFunction<void(CArkFlowNodeOverlappingGooHandler::CArkOverlappingGooListener* const _this, bool _bHasGoo)>(0x1333E90);
	};

	bool m_bActive;
	unsigned m_entityId;
	CArkFlowNodeOverlappingGooHandler::CArkOverlappingGooListener m_gooListener;
	ArkOverlappingGooHandler m_gooHandler;

	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CArkFlowNodeOverlappingGooHandler(IFlowNode::SActivationInfo* _arg0_);
	void Start(IFlowNode::SActivationInfo* _arg0_);
	void Stop(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeOverlappingGooHandler* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1249D30);
	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeOverlappingGooHandler* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x1249DB0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeOverlappingGooHandler* const _this, SFlowNodeConfig& config)>(0x1249E70);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeOverlappingGooHandler* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x124A180);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeOverlappingGooHandler* const _this, ICrySizer* s)>(0x182A3D0);
};
#endif // MOONCRASH
