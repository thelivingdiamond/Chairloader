// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class CCryName;
enum EControlScheme;
class ICrySizer;
struct IFlowNode;
struct IUIElement;
struct SFlowNodeConfig;

// CArkFlowNode_ShowDisclaimer
// Header:  Prey/GameDll/ark/flowgraph/arkflownodedisclaimer.h
class CArkFlowNode_ShowDisclaimer
	: public CFlowBaseNode<1>
	, public IActionListener
	, public IUIElementEventListener
	, public IUIControlSchemeListener
{ // Size=96 (0x60)
public:
	enum class EInputs
	{
		load = 0,
		show = 1,
	};

	enum class EOutputs
	{
		loaded = 0,
		nodata = 1,
		exit = 2,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	string m_disclaimer;

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnAction(const CCryName& action, int activationMode, float value);
	virtual void OnUnload(IUIElement* _pSender);
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	void UpdateInputPrompt() { FUpdateInputPrompt(this); }

#if 0
	CArkFlowNode_ShowDisclaimer(IFlowNode::SActivationInfo* _arg0_);
	void ExitDisclaimer();
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_ShowDisclaimer* const _this, SFlowNodeConfig& _config)>(0x15127C0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_ShowDisclaimer* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1512DD0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_ShowDisclaimer* const _this, ICrySizer* _pS)>(0xA55F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNode_ShowDisclaimer* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1512450);
	static inline auto FOnAction = PreyFunction<void(IActionListener* const _this, const CCryName& action, int activationMode, float value)>(0x1512AD0);
	static inline auto FOnUnload = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* _pSender)>(0x1512D40);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(IUIControlSchemeListener* const _this, const EControlScheme _controlScheme)>(0x1512D20);
	static inline auto FUpdateInputPrompt = PreyFunction<void(CArkFlowNode_ShowDisclaimer* const _this)>(0x1513240);
};
#endif // MOONCRASH
