// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IEntity;
struct SFlowNodeConfig;

// CArkFlowNode_EntityControl
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeentitycontrol.h
class CArkFlowNode_EntityControl : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eIN_HIDE = 0,
		eIN_SHOW = 1,
		eIN_REMOVE = 2,
	};

	enum EOutputs
	{
		eOUT_HIDDEN = 0,
		eOUT_SHOWN = 1,
		eOUT_REMOVED = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_EntityControl(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_EntityControl* const _this, SFlowNodeConfig& _config)>(0x15D8400);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_EntityControl* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D8D60);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_EntityControl* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_EntityRender
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeentitycontrol.h
class CArkFlowNode_EntityRender : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eIN_Visibility = 0,
	};

	enum EOutputs
	{
		eOUT_MadeInvisible = 0,
		eOUT_MadeVisible = 1,
	};

	virtual void PostSerialize(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	void SetVisible(bool _bVisible, IEntity* _pEntity) { FSetVisible(this, _bVisible, _pEntity); }

#if 0
	CArkFlowNode_EntityRender(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FPostSerialize = PreyFunction<void(CArkFlowNode_EntityRender* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15D8CC0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_EntityRender* const _this, SFlowNodeConfig& _config)>(0x15D87E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_EntityRender* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D9220);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_EntityRender* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FSetVisible = PreyFunction<void(CArkFlowNode_EntityRender* const _this, bool _bVisible, IEntity* _pEntity)>(0x15D9390);
};

// CArkFlowNode_UsePlayerTimer
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeentitycontrol.h
class CArkFlowNode_UsePlayerTimer : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eIN_Enable = 0,
		eIN_Disable = 1,
	};

	enum EOutputs
	{
		eOUT_Output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_UsePlayerTimer(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_UsePlayerTimer* const _this, SFlowNodeConfig& _config)>(0x15D8A00);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_UsePlayerTimer* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D9310);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_UsePlayerTimer* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
