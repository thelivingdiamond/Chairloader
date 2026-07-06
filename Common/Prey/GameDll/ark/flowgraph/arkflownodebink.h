// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/ui/ArkBinkPlayerHandle.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class CCryName;
enum ESystemEvent;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNode_BinkMovie
// Header:  Prey/GameDll/ark/flowgraph/arkflownodebink.h
class ArkFlowNode_BinkMovie
	: public CFlowBaseNode<1>
	, public IActionListener
	, public IArkActiveUserManagerListener
	, public ISystemEventListener
{ // Size=104 (0x68)
public:
	enum EInputs
	{
		eIN_Prepare = 0,
		eIN_Play = 1,
		eIN_Stop = 2,
		eIN_Movie = 3,
		eIN_InstanceId = 4,
		eIN_AutoPlay = 5,
		eIN_Loop = 6,
		eIN_Fullscreen = 7,
		eIN_PauseGame = 8,
		eIN_Skippable = 9,
	};

	enum EOutputs
	{
		eOUT_Prepared = 0,
		eOUT_Played = 1,
		eOUT_Stopped = 2,
		eOUT_Finished = 3,
	};

	IFlowNode::SActivationInfo m_actInfo;
	ArkBinkPlayerHandle m_movieHandle;
	bool m_bSawPlaying;
	bool m_bDisabledPlayerInput;
	bool m_bFailedToLoad;
	int m_playerInputMode;

	virtual ~ArkFlowNode_BinkMovie();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void OnAction(const CCryName& _action, int _activationMode, float _value);
	virtual void OnActiveUserIdChanged(unsigned platformUserId);
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual bool OnActiveUserReengaged();
	virtual void OnActiveUserPostReengaged();
	virtual void OnActiveUserSignedOut();
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* _pActInfo);
	void Prepare(const IFlowNode::SActivationInfo& _actInfo) { FPrepare(this, _actInfo); }
	void UpdatePlayState(const IFlowNode::SActivationInfo& _actInfo, const bool _bPlaying) { FUpdatePlayState(this, _actInfo, _bPlaying); }
	bool DoStopMovie() { return FDoStopMovie(this); }
	void DoCleanupHandle() { FDoCleanupHandle(this); }

#if 0
	ArkFlowNode_BinkMovie(IFlowNode::SActivationInfo* _arg0_);
	void EnablePlayerInputMode(const bool _arg0_);
	bool DoStartMovie();
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNode_BinkMovie* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1510A10);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_BinkMovie* const _this, SFlowNodeConfig& _config)>(0x1510ED0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_BinkMovie* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1511E80);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_BinkMovie* const _this, ICrySizer* _pS)>(0x18AD2D0);
	static inline auto FOnAction = PreyFunction<void(IActionListener* const _this, const CCryName& _action, int _activationMode, float _value)>(0x1511960);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(IArkActiveUserManagerListener* const _this, unsigned platformUserId)>(0x1333E90);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(IArkActiveUserManagerListener* const _this, bool _bControllerDisconnect)>(0x15119A0);
	static inline auto FOnActiveUserReengaged = PreyFunction<bool(IArkActiveUserManagerListener* const _this)>(0x13B0900);
	static inline auto FOnActiveUserPostReengaged = PreyFunction<void(IArkActiveUserManagerListener* const _this)>(0x15119E0);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(IArkActiveUserManagerListener* const _this)>(0x1333E90);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x1511AA0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNode_BinkMovie* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x15121C0);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNode_BinkMovie* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x1511B70);
	static inline auto FPrepare = PreyFunction<void(ArkFlowNode_BinkMovie* const _this, const IFlowNode::SActivationInfo& _actInfo)>(0x1511BA0);
	static inline auto FUpdatePlayState = PreyFunction<void(ArkFlowNode_BinkMovie* const _this, const IFlowNode::SActivationInfo& _actInfo, const bool _bPlaying)>(0x1512240);
	static inline auto FDoStopMovie = PreyFunction<bool(ArkFlowNode_BinkMovie* const _this)>(0x1510E40);
	static inline auto FDoCleanupHandle = PreyFunction<void(ArkFlowNode_BinkMovie* const _this)>(0x1510D60);
};
#endif // MOONCRASH
