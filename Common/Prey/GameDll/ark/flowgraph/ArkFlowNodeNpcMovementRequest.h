// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/MovementStyle.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkNpcFacingDesireCallbackEvent;
enum class EArkNpcMovementDesireCallbackEvent;
class ICrySizer;
struct IEntity;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeNpcMovementRequest
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcMovementRequest.h
class CArkFlowNodeNpcMovementRequest : public CFlowBaseNode<1>
{ // Size=832 (0x340)
public:
	enum class EInputPortIndex
	{
		request = 0,
		destination = 1,
		speed = 2,
		rotationEnabled = 3,
		rotation = 4,
		rotationStartBeforeArrivalTime = 5,
		overrideOffNavMesh = 6,
		useExactPosition = 7,
		stopDistance = 8,
		continueMoving = 9,
		ambientPriority = 10,
		cancel = 11,
	};

	enum class EOutputPortIndex
	{
		requested = 0,
		completed = 1,
		failed = 2,
		canceled = 3,
		rotationStarted = 4,
		rotationFailed = 5,
	};

	enum class ESerializePriority
	{
		Invalid = 0,
		Ambient = 1,
		High = 2,
	};

	static inline auto sk_navmeshRadiusHoriz = PreyGlobal<const float>(0x1F9009C);
	static inline auto sk_navmeshRadiusUp = PreyGlobal<const float>(0x1F900A0);
	static inline auto sk_navmeshRadiusDown = PreyGlobal<const float>(0x1F900A4);
	IFlowNode::SActivationInfo m_prevActivationInfo;
	unsigned m_prevActivationEntityId;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcMovementDesire m_ambientMovementDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcSpeedDesire m_speedDesire;
	bool m_bMoveCompleted;
	bool m_bFaceCompleted;
	CArkFlowNodeNpcMovementRequest::ESerializePriority m_serializePriority;

	CArkFlowNodeNpcMovementRequest(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _configuration);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* _pActivationInfo, TSerialize _serialize);
	virtual void PostSerialize(IFlowNode::SActivationInfo* _pActivationInfo);
	static float GetSpeed(IEntity* _pEntity, MovementStyle::Speed _speed) { return FGetSpeedOv1(_pEntity, _speed); }
	void SetMovementParams(const IFlowNode::SActivationInfo& _activationInfo) { FSetMovementParams(this, _activationInfo); }
	void AddMovementDesire(const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId) { FAddMovementDesire(this, _activationInfo, _entityId); }
	void RemoveMovementDesire(const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId) { FRemoveMovementDesire(this, _activationInfo, _entityId); }
	void MovementDesireCallback(EArkNpcMovementDesireCallbackEvent _event) { FMovementDesireCallback(this, _event); }
	void SetFacingParams(const IFlowNode::SActivationInfo& _activationInfo) { FSetFacingParams(this, _activationInfo); }
	void RemoveFacingDesire(const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId) { FRemoveFacingDesire(this, _activationInfo, _entityId); }
	void FacingDesireCallback(EArkNpcFacingDesireCallbackEvent _event) { FFacingDesireCallback(this, _event); }
	bool NeedsFacing(const IFlowNode::SActivationInfo& _activationInfo) { return FNeedsFacing(this, _activationInfo); }
	void UpdateFacing(IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId, bool _bForce) { FUpdateFacing(this, _activationInfo, _entityId, _bForce); }

#if 0
	float GetSpeed(const IFlowNode::SActivationInfo& _arg0_);
	void OnRequestPortActivated(IFlowNode::SActivationInfo& _arg0_);
	void OnMovementPortActivated(IFlowNode::SActivationInfo& _arg0_);
	void OnFacingPortActivated(IFlowNode::SActivationInfo& _arg0_);
	void OnCancelPortActivated(IFlowNode::SActivationInfo& _arg0_);
	void AddFacingDesire(IFlowNode::SActivationInfo& _arg0_, unsigned _arg1_);
#endif

	static inline auto FCArkFlowNodeNpcMovementRequestOv1 = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15E7090);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeNpcMovementRequest* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15E6F70);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, SFlowNodeConfig& _configuration)>(0x15E7430);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeNpcMovementRequest* const _this, ICrySizer* _pSizer)>(0x15E80B0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15E8550);
	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, IFlowNode::SActivationInfo* _pActivationInfo, TSerialize _serialize)>(0x15E87E0);
	static inline auto FPostSerialize = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15E84F0);
	static inline auto FGetSpeedOv1 = PreyFunction<float(IEntity* _pEntity, MovementStyle::Speed _speed)>(0x15E80D0);
	static inline auto FSetMovementParams = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, const IFlowNode::SActivationInfo& _activationInfo)>(0x15E8B60);
	static inline auto FAddMovementDesire = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId)>(0x15E7270);
	static inline auto FRemoveMovementDesire = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId)>(0x15E8760);
	static inline auto FMovementDesireCallback = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, EArkNpcMovementDesireCallbackEvent _event)>(0x15E8300);
	static inline auto FSetFacingParams = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, const IFlowNode::SActivationInfo& _activationInfo)>(0x15E88C0);
	static inline auto FRemoveFacingDesire = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, const IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId)>(0x15E8710);
	static inline auto FFacingDesireCallback = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, EArkNpcFacingDesireCallbackEvent _event)>(0x15E7380);
	static inline auto FNeedsFacing = PreyFunction<bool(CArkFlowNodeNpcMovementRequest* const _this, const IFlowNode::SActivationInfo& _activationInfo)>(0x15E8490);
	static inline auto FUpdateFacing = PreyFunction<void(CArkFlowNodeNpcMovementRequest* const _this, IFlowNode::SActivationInfo& _activationInfo, unsigned _entityId, bool _bForce)>(0x15E9370);
};
#endif // MOONCRASH
