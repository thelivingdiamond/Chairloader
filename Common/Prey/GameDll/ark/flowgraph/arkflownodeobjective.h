// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeCheckLocateCharacterObjectiveTarget
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeobjective.h
class CArkFlowNodeCheckLocateCharacterObjectiveTarget
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		Trigger = 0,
		CharacterId = 1,
	};

	enum class ArkOutputPort
	{
		Out = 0,
		True = 1,
		False = 2,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }
	void OnActivated(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo) { FOnActivated(this, _event, _pActInfo); }

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeCheckLocateCharacterObjectiveTarget* const _this, SFlowNodeConfig& _config)>(0x15CD650);
	static inline auto FOnActivated = PreyFunction<void(CArkFlowNodeCheckLocateCharacterObjectiveTarget* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CEAF0);
};

// CArkFlowNodeEnableBounties
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeobjective.h
class CArkFlowNodeEnableBounties
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		Enable = 0,
		Disable = 1,
	};

	enum class ArkOutputPort
	{
		Out = 0,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }

#if 0
	void OnActivated(IFlowNode::EFlowEvent _arg0_, IFlowNode::SActivationInfo* _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeEnableBounties* const _this, SFlowNodeConfig& _config)>(0x15CD9D0);
};

// CArkFlowNodeGiveLocateCharacterTask
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeobjective.h
class CArkFlowNodeGiveLocateCharacterTask
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		Trigger = 0,
		CharacterId = 1,
	};

	enum class ArkOutputPort
	{
		Out = 0,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }

#if 0
	void OnActivated(IFlowNode::EFlowEvent _arg0_, IFlowNode::SActivationInfo* _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGiveLocateCharacterTask* const _this, SFlowNodeConfig& _config)>(0x15CDC90);
};

// CArkFlowNodeLocateCharacterObjectiveEvent
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeobjective.h
class CArkFlowNodeLocateCharacterObjectiveEvent : public CFlowBaseNode<1>
{ // Size=72 (0x48)
public:
	enum class ArkInputPort
	{
		CharacterId = 0,
	};

	enum class ArkOutputPort
	{
		CharacterId = 0,
		Updated = 1,
		Completed = 2,
	};

	uint64_t m_characterId;
	IFlowNode::SActivationInfo m_activationInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<CArkFlowNodeLocateCharacterObjectiveEvent*>>(0x2D742E8);

	CArkFlowNodeLocateCharacterObjectiveEvent(IFlowNode::SActivationInfo* _pInfo);
	virtual ~CArkFlowNodeLocateCharacterObjectiveEvent();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyUpdated(const uint64_t _characterId) { FNotifyUpdated(_characterId); }
	static void NotifyCompleted(const uint64_t _characterId) { FNotifyCompleted(_characterId); }

#if 0
	void OnUpdated(const uint64_t _arg0_);
	void OnCompleted(const uint64_t _arg0_);
#endif

	static inline auto FCArkFlowNodeLocateCharacterObjectiveEventOv1 = PreyFunction<void(CArkFlowNodeLocateCharacterObjectiveEvent* const _this, IFlowNode::SActivationInfo* _pInfo)>(0x15CD460);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeLocateCharacterObjectiveEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15CD5B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeLocateCharacterObjectiveEvent* const _this, ICrySizer* _pS)>(0x35A360);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeLocateCharacterObjectiveEvent* const _this, SFlowNodeConfig& _config)>(0x15CDFB0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeLocateCharacterObjectiveEvent* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CED30);
	static inline auto FNotifyUpdated = PreyFunction<void(const uint64_t _characterId)>(0x15CE8B0);
	static inline auto FNotifyCompleted = PreyFunction<void(const uint64_t _characterId)>(0x15CE670);
};

// CArkFlowNodeShowObjectiveClue
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeobjective.h
class CArkFlowNodeShowObjectiveClue
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		Show = 0,
		Hide = 1,
		ClueId = 2,
	};

	enum class ArkOutputPort
	{
		Out = 0,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }

#if 0
	void OnActivated(IFlowNode::EFlowEvent _arg0_, IFlowNode::SActivationInfo* _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeShowObjectiveClue* const _this, SFlowNodeConfig& _config)>(0x15CE280);
};
#endif // MOONCRASH
