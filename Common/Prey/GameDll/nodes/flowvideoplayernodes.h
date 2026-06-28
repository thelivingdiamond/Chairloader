// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class CCryName;
struct IActionMapManager;
class ICrySizer;
struct IFlowNode;
struct IUIElement;
struct SFlowNodeConfig;
struct SUIArguments;
struct SUIEventDesc;

// CFlowFlashVideoPlayerNode
// Header:  Prey/GameDll/nodes/flowvideoplayernodes.h
class CFlowFlashVideoPlayerNode
	: public CFlowBaseNode<1>
	, public IUIElementEventListener
	, public IActionListener
{ // Size=104 (0x68)
public:
	enum EInputPorts
	{
		eI_Play = 0,
		eI_Stop = 1,
		eI_Pause = 2,
		eI_Resume = 3,
		eI_InstanceID = 4,
		eI_VideoFile = 5,
		eI_Transparent = 6,
		eI_Loop = 7,
		eI_Skipable = 8,
		eI_AudioChannel = 9,
		eI_SubtitleChannel = 10,
	};

	enum EOutputPorts
	{
		eO_OnPlay = 0,
		eO_OnStop = 1,
		eO_OnPause = 2,
		eO_OnResume = 3,
		eO_OnLooped = 4,
		eO_OnVideoNotFound = 5,
	};

	IUIElement* m_pElement;
	bool m_bPlaying;
	bool m_bSkipable;
	IFlowNode::SActivationInfo m_ActInfo;
	IActionMapManager* m_pActionMapMan;

	CFlowFlashVideoPlayerNode(IFlowNode::SActivationInfo* pActInfo);
	virtual ~CFlowFlashVideoPlayerNode();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void OnUIEvent(IUIElement* pSender, const SUIEventDesc& event, const SUIArguments& args);
	virtual void OnUnload(IUIElement* pSender);
	virtual void OnInstanceDestroyed(IUIElement* pSender, IUIElement* pDeletedInstance);
	void UnloadPlayerNextFrame() { FUnloadPlayerNextFrame(this); }
	virtual void OnAction(const CCryName& action, int activationMode, float value);

#if 0
	bool OnActionSkipVideo(unsigned _arg0_, const CCryName& _arg1_, int _arg2_, float _arg3_);
#endif

	static inline auto FCFlowFlashVideoPlayerNodeOv1 = PreyFunction<void(CFlowFlashVideoPlayerNode* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18AD7B0);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowFlashVideoPlayerNode* const _this, SFlowNodeConfig& config)>(0x18ABA40);
	static inline auto FProcessEvent = PreyFunction<void(CFlowFlashVideoPlayerNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18AC610);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowFlashVideoPlayerNode* const _this, ICrySizer* s)>(0x18AD2D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowFlashVideoPlayerNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18AD740);
	static inline auto FOnUIEvent = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* pSender, const SUIEventDesc& event, const SUIArguments& args)>(0x18AD2F0);
	static inline auto FOnUnload = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* pSender)>(0x18AD4D0);
	static inline auto FOnInstanceDestroyed = PreyFunction<void(IUIElementEventListener* const _this, IUIElement* pSender, IUIElement* pDeletedInstance)>(0x18AD530);
	static inline auto FUnloadPlayerNextFrame = PreyFunction<void(CFlowFlashVideoPlayerNode* const _this)>(0x18AD840);
	static inline auto FOnAction = PreyFunction<void(IActionListener* const _this, const CCryName& action, int activationMode, float value)>(0x18AD590);
};
#endif // MOONCRASH
