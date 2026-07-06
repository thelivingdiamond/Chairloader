// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkNpcMovementDesireCallbackEvent;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeNpcMovementTrackview
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcMovementTrackview.h
class CArkFlowNodeNpcMovementTrackview : public CFlowBaseNode<1>
{ // Size=640 (0x280)
public:
	enum class EInputPortIndex
	{
		request = 0,
		marker = 1,
		speed = 2,
		continueMoving = 3,
	};

	enum class EOutputPortIndex
	{
		requested = 0,
		blendOut = 1,
		completed = 2,
		failed = 3,
	};

	static inline auto s_kLookStartRemainingTime = PreyGlobal<float>(0x23E3210);
	static inline auto s_kLookStopRemainingTime = PreyGlobal<float>(0x23E3214);
	static inline auto s_kBlendOutRemainingTime = PreyGlobal<float>(0x23E3218);
	static inline auto s_kLookAheadDistMin = PreyGlobal<float>(0x23E321C);
	static inline auto s_kLookAheadDistMax = PreyGlobal<float>(0x23E3220);
	static inline auto s_kTurnStartDistMin = PreyGlobal<float>(0x23E3224);
	static inline auto s_kTurnStartDistMax = PreyGlobal<float>(0x23E3228);
	static inline auto s_kTurnMinSpeed = PreyGlobal<float>(0x23E322C);
	static inline auto s_kTurnMaxSpeed = PreyGlobal<float>(0x23E3230);
	IFlowNode::SActivationInfo m_prevActivationInfo;
	unsigned m_prevActivationEntityId;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcLookDesire m_lookDesire;
	ArkNpcSpeedDesire m_speedDesire;
	bool m_bBlendOutStarted;
	bool m_bMoveCompleted;

	CArkFlowNodeNpcMovementTrackview(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _configuration);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo);
	void SetMovementParams(const IFlowNode::SActivationInfo& _activationInfo) { FSetMovementParams(this, _activationInfo); }
	void RemoveMovementDesire(const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId) { FRemoveMovementDesire(this, _activationInfo, _entityId); }
	void MovementDesireCallback(EArkNpcMovementDesireCallbackEvent _event) { FMovementDesireCallback(this, _event); }
	void UpdateFacing(IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId) { FUpdateFacing(this, _activationInfo, _entityId); }
	void RemoveLookDesire(const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId) { FRemoveLookDesire(this, _activationInfo, _entityId); }
	float GetSpeed(const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId) { return FGetSpeed(this, _activationInfo, _entityId); }

#if 0
	void OnRequestPortActivated(IFlowNode::SActivationInfo& _arg0_);
	void OnMoveParamsPortActivated(IFlowNode::SActivationInfo& _arg0_);
	void AddMovementDesire(const IFlowNode::SActivationInfo& _arg0_, unsigned _arg1_);
	void AddLookDesire(IFlowNode::SActivationInfo& _arg0_, unsigned _arg1_);
#endif

	static inline auto FCArkFlowNodeNpcMovementTrackviewOv1 = PreyFunction<void(CArkFlowNodeNpcMovementTrackview* const _this, IFlowNode::SActivationInfo* _pActivationInfo)>(0x1319650);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeNpcMovementTrackview* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActivationInfo)>(0x13195F0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeNpcMovementTrackview* const _this, SFlowNodeConfig& _configuration)>(0x13197A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeNpcMovementTrackview* const _this, ICrySizer* _pSizer)>(0x1319CC0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeNpcMovementTrackview* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo)>(0x1319E30);
	static inline auto FSetMovementParams = PreyFunction<void(CArkFlowNodeNpcMovementTrackview* const _this, const IFlowNode::SActivationInfo& _activationInfo)>(0x131A110);
	static inline auto FRemoveMovementDesire = PreyFunction<void(CArkFlowNodeNpcMovementTrackview* const _this, const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId)>(0x131A020);
	static inline auto FMovementDesireCallback = PreyFunction<void(CArkFlowNodeNpcMovementTrackview* const _this, EArkNpcMovementDesireCallbackEvent _event)>(0x1319D70);
	static inline auto FUpdateFacing = PreyFunction<void(CArkFlowNodeNpcMovementTrackview* const _this, IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId)>(0x131A540);
	static inline auto FRemoveLookDesire = PreyFunction<void(CArkFlowNodeNpcMovementTrackview* const _this, const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId)>(0x1319FD0);
	static inline auto FGetSpeed = PreyFunction<float(CArkFlowNodeNpcMovementTrackview* const _this, const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId)>(0x1319CE0);
};
#endif // MOONCRASH
