// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowEnablePlayerSimulationReset
// Header:  Prey/GameDll/ark/ui/readyroom/ArkFlowReadyRoom.h
class ArkFlowEnablePlayerSimulationReset : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		enable = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowEnablePlayerSimulationReset(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowEnablePlayerSimulationReset* const _this, SFlowNodeConfig& _config)>(0x14690F0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowEnablePlayerSimulationReset* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x146A140);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowEnablePlayerSimulationReset* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowForceSatellite
// Header:  Prey/GameDll/ark/ui/readyroom/ArkFlowReadyRoom.h
class ArkFlowForceSatellite : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowForceSatellite(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowForceSatellite* const _this, SFlowNodeConfig& _config)>(0x14693C0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowForceSatellite* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x146A210);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowForceSatellite* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowReadyRoom
// Header:  Prey/GameDll/ark/ui/readyroom/ArkFlowReadyRoom.h
class ArkFlowReadyRoom : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		scorecard = 1,
		position = 2,
		rotation = 3,
		lightEntity = 4,
		cameraPosition = 5,
		cameraRotation = 6,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowReadyRoom(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowReadyRoom* const _this, SFlowNodeConfig& _config)>(0x14695B0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowReadyRoom* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x146A270);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowReadyRoom* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowReadyRoomListener
// Header:  Prey/GameDll/ark/ui/readyroom/ArkFlowReadyRoom.h
class ArkFlowReadyRoomListener : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkOutputs
	{
		onLaunch = 0,
		onReturnToSatellite = 1,
		onResetSimulation = 2,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowReadyRoomListener*>>(0x2D569C8);

	ArkFlowReadyRoomListener(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowReadyRoomListener();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyReadyRoomEvent(ArkFlowReadyRoomListener::EArkOutputs _event) { FNotifyReadyRoomEvent(_event); }
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	void OnReadyRoomEvent(ArkFlowReadyRoomListener::EArkOutputs _arg0_);
#endif

	static inline auto FArkFlowReadyRoomListenerOv1 = PreyFunction<void(ArkFlowReadyRoomListener* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x1468E30);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowReadyRoomListener* const _this, SFlowNodeConfig& _rConfig)>(0x1469CF0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowReadyRoomListener* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FNotifyReadyRoomEvent = PreyFunction<void(ArkFlowReadyRoomListener::EArkOutputs _event)>(0x1469FE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowReadyRoomListener* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowReadyRoomListener* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1468FF0);
};

// ArkFlowReadyRoomRequest
// Header:  Prey/GameDll/ark/ui/readyroom/ArkFlowReadyRoom.h
class ArkFlowReadyRoomRequest : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkOutputs
	{
		request = 0,
		scorecard = 1,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowReadyRoomRequest*>>(0x2D569E0);

	ArkFlowReadyRoomRequest(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowReadyRoomRequest();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyRequestReadyRoom(bool _bScorecard) { FNotifyRequestReadyRoom(_bScorecard); }
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	void OnRequestReadyRoom(bool _arg0_);
#endif

	static inline auto FArkFlowReadyRoomRequestOv1 = PreyFunction<void(ArkFlowReadyRoomRequest* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x1468E80);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowReadyRoomRequest* const _this, SFlowNodeConfig& _rConfig)>(0x1469E80);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowReadyRoomRequest* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FNotifyRequestReadyRoom = PreyFunction<void(bool _bScorecard)>(0x146A070);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowReadyRoomRequest* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowReadyRoomRequest* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1469070);
};
#endif // MOONCRASH
