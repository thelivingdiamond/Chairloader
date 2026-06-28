// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// IArkFlowNodeGravShaft
// Header:  Prey/GameDll/ark/flowgraph/arkflownodegravshaft.h
class IArkFlowNodeGravShaft
{ // Size=8 (0x8)
public:
	static inline auto s_gravShaftNodes = PreyGlobal<std::vector<IArkFlowNodeGravShaft*>>(0x2D75A80);

	virtual ~IArkFlowNodeGravShaft();
	virtual void OnEnter(const unsigned& _shaftEntityId, const unsigned& _containedEntityId) = 0;
	virtual void OnLeave(const unsigned& _shaftEntityId, const unsigned& _containedEntityId) = 0;
	static void NotifyEnter(const unsigned& _shaftEntityId, const unsigned& _containedEntityId) { FNotifyEnter(_shaftEntityId, _containedEntityId); }
	static void NotifyLeave(const unsigned& _shaftEntityId, const unsigned& _containedEntityId) { FNotifyLeave(_shaftEntityId, _containedEntityId); }

#if 0
	IArkFlowNodeGravShaft();
#endif

	static inline auto FNotifyEnter = PreyFunction<void(const unsigned& _shaftEntityId, const unsigned& _containedEntityId)>(0x15DB730);
	static inline auto FNotifyLeave = PreyFunction<void(const unsigned& _shaftEntityId, const unsigned& _containedEntityId)>(0x15DB7C0);
};

// CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodegravshaft.h
class CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate> : public CFlowBaseNode<0>, public IArkFlowNodeGravShaft
{ // Size=48 (0x30)
public:
	enum class ArkInputPort
	{
		Enable = 0,
		Disable = 1,
	};

	enum class ArkOutputPort
	{
		Out = 0,
		Enter = 1,
		Leave = 2,
		GravShaftEntityId = 3,
		ContainedEntityId = 4,
	};

	std::vector<IFlowNode::SActivationInfo> m_graphActivationInfo;

	CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate>(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual ~CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnEnter(const unsigned& _shaftEntityId, const unsigned& _containedEntityId);
	virtual void OnLeave(const unsigned& _shaftEntityId, const unsigned& _containedEntityId);

	static inline auto FCArkFlowNodeGravShaftLess`anonymous namespace'::EntityPredicateGreaterOv1 = PreyFunction<void(CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate>* const _this, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15DB5B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate>* const _this, ICrySizer* _pS)>(0x4BAFC0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate>* const _this, SFlowNodeConfig& _config)>(0x15DAB60);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGravShaft<`anonymous namespace'::EntityPredicate>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15DA7B0);
	static inline auto FOnEnter = PreyFunction<void(IArkFlowNodeGravShaft* const _this, const unsigned& _shaftEntityId, const unsigned& _containedEntityId)>(0x15DAEF0);
	static inline auto FOnLeave = PreyFunction<void(IArkFlowNodeGravShaft* const _this, const unsigned& _shaftEntityId, const unsigned& _containedEntityId)>(0x15DAFD0);
};

// CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodegravshaft.h
class CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate> : public CFlowBaseNode<0>, public IArkFlowNodeGravShaft
{ // Size=48 (0x30)
public:
	enum class ArkInputPort
	{
		Enable = 0,
		Disable = 1,
	};

	enum class ArkOutputPort
	{
		Out = 0,
		Enter = 1,
		Leave = 2,
		GravShaftEntityId = 3,
		ContainedEntityId = 4,
	};

	std::vector<IFlowNode::SActivationInfo> m_graphActivationInfo;

	CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate>(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual ~CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnEnter(const unsigned& _shaftEntityId, const unsigned& _containedEntityId);
	virtual void OnLeave(const unsigned& _shaftEntityId, const unsigned& _containedEntityId);

	static inline auto FCArkFlowNodeGravShaftLess`anonymous namespace'::PlayerPredicateGreaterOv1 = PreyFunction<void(CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate>* const _this, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15DB630);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate>* const _this, ICrySizer* _pS)>(0x4BAFC0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate>* const _this, SFlowNodeConfig& _config)>(0x15DA420);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGravShaft<`anonymous namespace'::PlayerPredicate>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15DA7B0);
	static inline auto FOnEnter = PreyFunction<void(IArkFlowNodeGravShaft* const _this, const unsigned& _shaftEntityId, const unsigned& _containedEntityId)>(0x15DA860);
	static inline auto FOnLeave = PreyFunction<void(IArkFlowNodeGravShaft* const _this, const unsigned& _shaftEntityId, const unsigned& _containedEntityId)>(0x15DA940);
};
#endif // MOONCRASH
