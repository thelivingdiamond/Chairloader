// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

namespace ArkFlowNodePlayerAnimation
{
class Action;
} // namespace ArkFlowNodePlayerAnimation
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodePlayerAnimation
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodePlayerAnimation.h
class ArkFlowNodePlayerAnimation : public CFlowBaseNode<1>
{ // Size=72 (0x48)
public:
	enum class EInputs
	{
		trigger = 0,
		fragment = 1,
		tags = 2,
		priority = 3,
	};

	enum class EOutput
	{
		done = 0,
	};

	// ArkFlowNodePlayerAnimation::Action
	// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodePlayerAnimation.h
	class Action : public TAction<SAnimationContext>
	{ // Size=136 (0x88)
	public:
		ArkFlowNodePlayerAnimation* m_pFlowNode;

		virtual void Exit();

	#if 0
		Action(const int _arg0_, const int _arg1_, ArkFlowNodePlayerAnimation* _arg2_);
		void ClearNode();
	#endif

		static inline auto FExit = PreyFunction<void(ArkFlowNodePlayerAnimation::Action* const _this)>(0x124B900);
	};

	IFlowNode::SActivationInfo m_actInfo;
	_smart_ptr<ArkFlowNodePlayerAnimation::Action> m_pAction;

	virtual ~ArkFlowNodePlayerAnimation();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;

#if 0
	ArkFlowNodePlayerAnimation(IFlowNode::SActivationInfo* _arg0_);
	void NotifyCompleted();
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodePlayerAnimation* const _this, SFlowNodeConfig& _config)>(0x124BA00);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodePlayerAnimation* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x124BF50);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodePlayerAnimation* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x124B6D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodePlayerAnimation* const _this, ICrySizer* _s)>(0x2D0150);
};
#endif // MOONCRASH
